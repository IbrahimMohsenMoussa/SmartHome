/**
 * @file pushbutton.h
 * @brief Header file for managing pushbutton inputs.
 *
 * This file provides function declarations for initializing and handling
 * pushbuttons used in the stopwatch project, enabling user interaction
 * to control the stopwatch functionalities.
 */

#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
#include"../mcal/gpio.h"
#include"../common/std_types.h"


typedef struct {
	uint8 pin;
	uint8 state;
	uint8 pullup;
	uint8 debounce_time;

} pushbutton;
void Pushbutton_init(  pushbutton * const a_button);
uint8 Pushbutton_pressed( pushbutton * consta_button);
#endif /* PUSHBUTTON_H_ */
