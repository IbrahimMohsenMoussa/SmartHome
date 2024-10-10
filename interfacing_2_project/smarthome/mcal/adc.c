#include "adc.h"
#include "../mcal/atmega32_regs.h"
#include "../common/common_macros.h"
/**
 * @brief Initializes the ADC with internal 2.56V reference and prescaler of F_CPU/128.
 */
void ADC_init(void) {
	ADMUX_REG.byte=0;
    ADMUX_REG.bits.refs0 = 1;
    ADMUX_REG.bits.refs1 = 1;
    ADCSRA_REG.bits.aden = 1;
    ADCSRA_REG.bits.adif = 1;
    ADCSRA_REG.bits.adie = 0;
    ADCSRA_REG.bits.adps0=1;
    ADCSRA_REG.bits.adps1=1;
    ADCSRA_REG.bits.adps2=1;
    SET_BIT(ADCSRA_REG.byte, (0x07));


    // 3. Enable the ADC (ADEN bit in ADCSRA)

}

/**
 * @brief Reads the analog value from the specified ADC channel.
 *
 * This function performs an analog-to-digital conversion on the given channel
 * and returns a 10-bit result.
 *
 * @param channel_num The ADC channel to read from (0-7).
 * @return The 10-bit digital result from the ADC conversion.
 */
uint16 ADC_readChannel(uint8 a_adcChannel) {

	ADMUX_REG.byte = (ADMUX_REG.byte & 0xE0) | (a_adcChannel);
	ADCSRA_REG.bits.adsc=LOGIC_HIGH;

		while (ADCSRA_REG.bits.adif == LOGIC_LOW)
			;
		ADCSRA_REG.bits.adif = LOGIC_HIGH;
		return ADC_REG.value;
}
