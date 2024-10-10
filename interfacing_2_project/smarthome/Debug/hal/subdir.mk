################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/buzzer.c \
../hal/dcMotor.c \
../hal/flameSensor.c \
../hal/lcd.c \
../hal/ldr.c \
../hal/led.c \
../hal/lm35_sensor.c \
../hal/pushbutton.c 

OBJS += \
./hal/buzzer.o \
./hal/dcMotor.o \
./hal/flameSensor.o \
./hal/lcd.o \
./hal/ldr.o \
./hal/led.o \
./hal/lm35_sensor.o \
./hal/pushbutton.o 

C_DEPS += \
./hal/buzzer.d \
./hal/dcMotor.d \
./hal/flameSensor.d \
./hal/lcd.d \
./hal/ldr.d \
./hal/led.d \
./hal/lm35_sensor.d \
./hal/pushbutton.d 


# Each subdirectory must supply rules for building sources it contributes
hal/%.o: ../hal/%.c hal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


