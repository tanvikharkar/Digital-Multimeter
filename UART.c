#include "msp.h"
#include "DCO.h"
#include "UART.h"

void UART_init(void)
{
  EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SWRST; // Initialize software reset
  
  EUSCI_A0->CTLW0 = (EUSCI_A_CTLW0_SWRST | EUSCI_A_CTLW0_SSEL__SMCLK); // Select SMCLK as BRCLK source
  EUSCI_A0->BRW = BRW_VAL; // Configure clock prescaler of baud rate generator
  EUSCI_A0->MCTLW = (EUSCI_A_MCTLW_OS16 // Enable oversampling
                  | (BRF_VAL<<EUSCI_A_MCTLW_BRF_OFS) // 1st modulation
                  | (BRS_VAL<<EUSCI_A_MCTLW_BRS_OFS)); // 2nd modulation
  
  PUART->SEL0 |= (RX|TX); // Configure UART pins
  PUART->SEL1 &= ~(RX|TX);
  
  EUSCI_A0->CTLW0 &= ~EUSCI_A_CTLW0_SWRST; // Clear software reset
  
  EUSCI_A0->IE |= EUSCI_A_IE_RXIE; // Enable RX to trigger interrupt
  NVIC->ISER[0] = 1 << (EUSCIA0_IRQn); // Enable UART interrupt
  __enable_irq(); // Enable global interrupts
}

void UART_print(char write_string[])
{
  int i = 0; // Integer for checking characters in string
  while (write_string[i] != NULL) // Write string until null character reached
  {
    while(!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG));
    EUSCI_A0->TXBUF = write_string[i];
    i++;
  }
}

void UART_esc_code(char write_string[])
{
  int i = 0; // Integer for checking characters in string
  while(!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG));
  EUSCI_A0->TXBUF = 0x1B; // Send '0x1B' to enable escape commands
  while (write_string[i] != NULL) // Write string until null character reached
  {
    while(!(EUSCI_A0->IFG & EUSCI_A_IFG_TXIFG));
    EUSCI_A0->TXBUF = write_string[i];
    i++;
  }
}
