# Smart Home Automation Using ATmega32

This project is a **Smart Home Automation System** based on the **ATmega32 microcontroller**. It automates the control of lighting, fan speed, and fire alerts using various sensors such as the **LM35 temperature sensor**, **LDR (Light Dependent Resistor)**, and **Flame Sensor**. The system uses a **16x2 LCD display** to provide real-time feedback, and a **DC motor** to control the fan speed based on environmental conditions.

## Project Overview

The system is capable of:
- **Lighting Control**: Adjusts three LEDs based on light intensity detected by the LDR.
- **Fan Speed Control**: Automatically adjusts fan speed using a PWM-controlled motor based on the room temperature.
- **Fire Detection**: Detects fire using a flame sensor and triggers an alarm.
- **LCD Display**: Displays real-time system information, such as fan status, temperature, and light intensity.

### Features:
1. **Automatic Lighting Control**:
   - **<15% Light Intensity**: All LEDs ON.
   - **16% - 50%**: Two LEDs ON.
   - **51% - 70%**: One LED ON.
   - **>70%**: All LEDs OFF.
   
2. **Automatic Fan Speed Control**:
   - **≥ 40°C**: Fan at 100% speed.
   - **35°C - 39°C**: Fan at 75% speed.
   - **30°C - 34°C**: Fan at 50% speed.
   - **25°C - 29°C**: Fan at 25% speed.
   - **< 25°C**: Fan OFF.
   
3. **Fire Detection and Alert**:
   - Detects fire and displays "Critical Alert!" on the LCD.
   - Triggers an alarm (buzzer) until the flame is no longer detected.

4. **LCD Display**:
   - **First Row**: Displays fan status ("FAN is ON" or "FAN is OFF").
   - **Second Row**: Displays temperature (`Temp= xxx°C`) and light intensity (`LDR= xx%`).

## Hardware Components
- **Microcontroller**: ATmega32
- **Temperature Sensor**: LM35
- **Light Sensor**: LDR (Light Dependent Resistor)
- **Fire Sensor**: Flame Sensor
- **Motor Control**: DC motor with H-Bridge for speed control
- **16x2 LCD Display**
- **LEDs**: Red, Green, Blue
- **Buzzer** for alerts

## Software Components
- **ADC Driver**: Reads analog data from the LM35 and LDR sensors.
- **GPIO Driver**: Manages the microcontroller's GPIO pins for controlling sensors, LEDs, and the motor.
- **TImer0  Driver**:for cnfigruation in fast PWM mode.
- **LCD Driver**: Manages the 16x2 LCD display to show system information.
- **Fire Sensor Driver**: Polls the flame sensor for fire detection.
- **DC Motor Driver**: Controls the motor direction and speed.

## System Requirements
- **Microcontroller**: ATmega32
- **System Frequency**: 16 MHz
- **Language**: C

## Simulation & Demo

You can find the following resources in this repository:
- **Proteus Simulation File**: A Proteus simulation of the Smart Home Automation system is included.
- **Video Demo**: A full demo of the system can be watched .

