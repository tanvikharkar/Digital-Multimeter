// DCO Code

#ifndef DCO_H_
#define DCO_H_

#define CS_KEY_VAL 0x695A

#define CYCLES 3000000
#define FREQ_1_5_MHz CS_CTL0_DCORSEL_0
#define FREQ_3_MHz CS_CTL0_DCORSEL_1
#define FREQ_6_MHz CS_CTL0_DCORSEL_2
#define FREQ_12_MHz CS_CTL0_DCORSEL_3
#define FREQ_24_MHz CS_CTL0_DCORSEL_4

// function prototypes
void set_DCO(int);

#endif /* DCO_H_ */
