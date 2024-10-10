#include "flameSensor.h"
#include "../mcal/gpio.h"

/**
 * @brief Initializes the flame sensor pin .
 *
 * Configures the flame sensor pin as an input pin with GPIO_ARR_setPinDirection().
 */
void FlameSensor_init() {

    GPIO_ARR_setPinDirection(GPIO_PD2, PIN_INPUT);
}

/**
 * @brief Reads the value from the flame sensor.
 *
 * Reads the digital value from the flame sensor pin and returns the result.
 * The pin value is either HIGH (flame detected) or LOW (no flame detected).
 *
 * @return The state of the flame sensor pin (HIGH or LOW).
 */
uint8 FlameSensor_getValue() {

    return GPIO_ARR_readPin(GPIO_PD2);
}
