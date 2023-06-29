// ADC Code

#ifndef ADC_H_
#define ADC_H_

#define PORT_ADC P5 // Analog pin = P5.5
#define ANALOG_PIN BIT5
#define MEM_REG 2 // Memory register 2 used for ADC14
#define DEF_MAX -50000 // Max comparator value in for loop to calculate max of array
#define DEF_MIN 50000 // Min comparator value in for loop to calculate min of array
#define ARRAY_LENGTH 20 // 20 samples in array
#define EMPTY_ARRAY {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} // Initialize an empty array
#define SLOPE 203 // Calculated from array values
#define INTERCEPT 75031 // Calculated from array values
#define CAL 10000 // Value used to calibrate voltages
#define ZERO 0
#define MAX 330
#define PLUS2 2 // Calibration value
#define PLUS3 3 // Calibration value

void ADC14_init(void);

#endif /* ADC_H_ */
