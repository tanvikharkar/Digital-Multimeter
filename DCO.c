#include "msp.h"
#include "DCO.h"

void set_DCO(int frequency)
{
  CS->KEY = CS_KEY_VAL; // Unlock CS Registers
  CS->CTL0 = 0;
  
  if(frequency == FREQ_1_5_MHz)
  {
    CS->CTL0 = CS_CTL0_DCORSEL_0; // Set DCO to 1.5MHz
  }
  
  else if(frequency == FREQ_3_MHz)
  {
    CS->CTL0 = CS_CTL0_DCORSEL_1; // Set DCO to 3MHz
  }
  
  else if(frequency == FREQ_6_MHz)
  {
    CS->CTL0 = CS_CTL0_DCORSEL_2; // Set DCO to 6MHz
  }
  
  else if(frequency == FREQ_12_MHz)
  {
    CS->CTL0 = CS_CTL0_DCORSEL_3; // Set DCO to 12MHz
  }
  
  else if(frequency == FREQ_24_MHz)
  {
    CS->CTL0 = CS_CTL0_DCORSEL_4; // Set DCO to 24MHz
  }
  
  CS->CTL1 |= (CS_CTL1_SELS__DCOCLK) ; // Write DCO to SMCLK
  CS->KEY = 0; // Lock CS Registers
}
