/*
 * main.c
 *
 *  Created on: 3 Oct 2024
 *      Author: MSI
 */

#include"../hal/lm35_sensor.h"
#include"../hal/lcd.h"
#include"../hal/ldr.h"
#include"../hal/led.h"
#include"../hal/dcMotor.h"
#include"../hal/flameSensor.h"
#include"../hal/buzzer.h"
uint8 lightIntensity;
uint8 g_temperature;
boolean fan;

int main() {

	LED_init();
	LDR_init();
	LCD_init();
	DcMotor_init();
	FlameSensor_init();
	Buzzer_init();
	for (;;) {
		lightIntensity = LDR_getLightIntensity();
		LCD_displayString("LDR=");
		LCD_intgerToString(lightIntensity);
		LCD_sendChar('%');
		LCD_moveCursor(0, 0);

		if (lightIntensity <= 15) {
			LED_on(LED_BLUE_1);
			LED_on(LED_GREEN_2);
			LED_on(LED_RED_3);
		} else if (lightIntensity >= 16 && lightIntensity <= 50) {
			LED_off(LED_BLUE_1);
			LED_on(LED_GREEN_2);
			LED_on(LED_RED_3);
		} else if (lightIntensity >= 51 && lightIntensity <= 70) {
			LED_off(LED_BLUE_1);
			LED_off(LED_GREEN_2);
			LED_on(LED_RED_3);
		} else {
			LED_off(LED_BLUE_1);
			LED_off(LED_GREEN_2);
			LED_off(LED_RED_3);
		}
		g_temperature = LM35_getTemperature();
		if (g_temperature >= 40) {
			fan = TRUE;
			DcMotor_rotate(CW, 100);
		} else if (g_temperature >= 35 && g_temperature < 40) {
			fan = TRUE;
			DcMotor_rotate(CW, 75);
		} else if (g_temperature >= 30 && g_temperature < 35) {
			fan = TRUE;
			DcMotor_rotate(CW, 50);
		} else if (g_temperature >= 25 && g_temperature < 30) {
			fan = TRUE;
			DcMotor_rotate(CW, 25);
		} else {
			fan = FALSE;
			DcMotor_rotate(STOP, 0);
		}
		if (FlameSensor_getValue()) {
			Buzzer_on();
			LCD_moveCursor(0, 0);
			LCD_displayString(" CRITICAL ALERT");
			LCD_moveCursor(1, 0);
			LCD_displayString("      FIRE      ");
		} else {
			Buzzer_off();
			LCD_moveCursor(0, 0);
			if (fan == TRUE) {
				LCD_displayString("FAN is ON ");
			} else {
				LCD_displayString("FAN is OFF");
			}

			LCD_moveCursor(1, 0);
			LCD_displayString("Temp=");
			LCD_intgerToString(g_temperature);
			LCD_displayString("C");

			LCD_moveCursor(1, 9);
			LCD_displayString("LDR=");
			LCD_intgerToString(lightIntensity);
			LCD_displayString("%");
		}

	}
}

