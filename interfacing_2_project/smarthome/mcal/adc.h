/**
 * @file adc.h
 * @brief Header file for the ADC driver for AVR microcontrollers.
 *
 * This driver is responsible for initializing the ADC and reading analog values
 * from sensors such as the LM35 and LDR.
 *
 * @date 10 Oct 2024
 */

#ifndef ADC_H_
#define ADC_H_

#include "../common/std_types.h"
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
/**
 * @brief Initializes the ADC with the following configurations:
 *        - Reference Voltage: Internal 2.56V.
 *        - Prescaler: F_CPU/128.
 *
 * This function must be called once at the beginning to set up the ADC before reading any channels.
 */
void ADC_init(void);

/**
 * @brief Reads the analog value from the specified ADC channel.
 *
 * This function performs an analog-to-digital conversion for the given channel
 * and returns a 10-bit digital result.
 *
 * @param channel_num The ADC channel number (0-7) to read from.
 * @return The 10-bit digital result of the ADC conversion.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
