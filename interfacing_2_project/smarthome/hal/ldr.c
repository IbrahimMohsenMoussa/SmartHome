/*
 * ldr.c
 *
 *  Created on: 9 Oct 2024
 *      Author: MSI
 */
#include"../common/std_types.h"
#include"../common/common_macros.h"
#include "../mcal/adc.h"
uint16 LDR_getLightIntensity(void) {
	uint16 l_val = ADC_readChannel(0);
	int l_inten = MAP(((int)l_val), 0, 200, 0, 100);
	return l_inten;
}
void LDR_init() {
	ADC_init();
}
