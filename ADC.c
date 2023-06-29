#include "msp.h"
#include "DCO.h"
#include "UART.h"
#include "ADC.h"

void ADC14_init(void)
{
  ADC14->CTL0 &= ~ADC14_CTL0_ENC; // ADC14 disabled
  
  ADC14->CTL0 = ADC14_CTL0_SSEL__HSMCLK // Select HSMCLK for ADC14
              | ADC14_CTL0_SHP // Sample and hold pulse mode select
              | ADC14_CTL0_SHT0_0 // Sample time of 4 clocks, registers 0-7, 24-31
              | ADC14_CTL0_CONSEQ_0 // Select single conversion
              | ADC14_CTL0_ON; // ADC14 on
  
  ADC14->CTL1 = (MEM_REG<<ADC14_CTL1_CSTARTADD_OFS) // Start conversions at memory register 2;
              | ADC14_CTL1_RES__14BIT // ADC 14-bit resolution
              | ADC14_CTL1_BATMAP;
  
  ADC14->MCTL[2] = ADC14_MCTLN_INCH_0 // Input channel = 0, P5.5
                 | ADC14_MCTLN_VRSEL_0; // Select 3.3V = AVCC
  
  ADC14->CTL0 |= ADC14_CTL0_ENC | ADC14_CTL0_SC; // ADC enabled, start sample and conversion
  
  PORT_ADC->SEL0 |= ANALOG_PIN; // Configure analog pin, P5.5
  PORT_ADC->SEL1 |= ANALOG_PIN;
  
  ADC14->IER0 = ADC14_IER0_IE2; // Enable interrupt for memory control register 2
  NVIC->ISER[0] = 1 << (ADC14_IRQn);
  __enable_irq();
}
