/**
 * @file flame_sensor.h
 * @brief Driver for the flame sensor module using polling technique.
 *
 * This file provides functions to initialize the flame sensor and read the sensor value using GPIO_ARR.
 *
 * @date 10 Oct 2024
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "../common/std_types.h"
#define FLAME_PIN GPIO_PD2
/**
 * @brief Initializes the flame sensor pin.
 *
 * This function configures the pin connected to the flame sensor as an input .
 *.
 *
 *
 */
void FlameSensor_init(void);

/**
 * @brief Reads the value from the flame sensor.
 *
 * This function reads the current logic level from the sensor pin .
 *
 *
 * @return The value from the flame sensor (HIGH if flame is detected, LOW if no flame is detected).
 */
uint8 FlameSensor_getValue(void);

#endif /* FLAME_SENSOR_H_ */
