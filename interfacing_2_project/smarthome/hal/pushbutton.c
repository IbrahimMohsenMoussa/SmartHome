/*
 * pushbutton.c
 *
 *  Created on: 10 Sept 2024
 *      Author: MSI
 */
#include"pushbutton.h"
void Pushbutton_init( pushbutton * const a_button) {


	(a_button->pullup == PIN_INPUT_PULLUP) ?
			GPIO_ARR_setPinDirection(a_button->pin, PIN_INPUT_PULLUP) :

			GPIO_ARR_setPinDirection(a_button->pin, PIN_INPUT);

	a_button->state = 0;

}
uint8 Pushbutton_pressed( pushbutton *const a_button) {
	uint8 l_val = 0;

	if (!GPIO_ARR_readPin(a_button->pin)) {
		if (!a_button->state) {
			l_val = 1;
			a_button->state = 1;
		}
	} else {
		l_val = 0;
		a_button->state = 0;

	}
	return l_val;
}

