################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Implementation/I2C_Slave_EEPROM.c 

OBJS += \
./HAL/Implementation/I2C_Slave_EEPROM.o 

C_DEPS += \
./HAL/Implementation/I2C_Slave_EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Implementation/I2C_Slave_EEPROM.o: ../HAL/Implementation/I2C_Slave_EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/STM32F103Cx_Drivers/interface" -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/HAL/Interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Implementation/I2C_Slave_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

