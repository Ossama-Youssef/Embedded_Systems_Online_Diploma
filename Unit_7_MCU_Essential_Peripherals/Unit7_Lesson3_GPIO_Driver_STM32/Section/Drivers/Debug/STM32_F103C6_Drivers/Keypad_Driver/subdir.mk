################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/Keypad_Driver/Keypad.c 

OBJS += \
./STM32_F103C6_Drivers/Keypad_Driver/Keypad.o 

C_DEPS += \
./STM32_F103C6_Drivers/Keypad_Driver/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/Keypad_Driver/Keypad.o: ../STM32_F103C6_Drivers/Keypad_Driver/Keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.4/Drivers/STM32_F103C6_Drivers/Keypad_Driver" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.4/Drivers/STM32_F103C6_Drivers/LCD_Driver" -I"C:/Users/Dell/STM32CubeIDE/workspace_1.4.4/Drivers/STM32_F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/Keypad_Driver/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
