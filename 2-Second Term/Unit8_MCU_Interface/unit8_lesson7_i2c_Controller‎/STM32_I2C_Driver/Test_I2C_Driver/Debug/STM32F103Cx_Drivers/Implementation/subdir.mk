################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103Cx_Drivers/Implementation/STM32_GPIO.c \
../STM32F103Cx_Drivers/Implementation/STM32_I2C.c \
../STM32F103Cx_Drivers/Implementation/STM32_RCC.c \
../STM32F103Cx_Drivers/Implementation/STM32_SPI.c \
../STM32F103Cx_Drivers/Implementation/STM32_USART.c \
../STM32F103Cx_Drivers/Implementation/STM32f10C8_EXTI.c 

OBJS += \
./STM32F103Cx_Drivers/Implementation/STM32_GPIO.o \
./STM32F103Cx_Drivers/Implementation/STM32_I2C.o \
./STM32F103Cx_Drivers/Implementation/STM32_RCC.o \
./STM32F103Cx_Drivers/Implementation/STM32_SPI.o \
./STM32F103Cx_Drivers/Implementation/STM32_USART.o \
./STM32F103Cx_Drivers/Implementation/STM32f10C8_EXTI.o 

C_DEPS += \
./STM32F103Cx_Drivers/Implementation/STM32_GPIO.d \
./STM32F103Cx_Drivers/Implementation/STM32_I2C.d \
./STM32F103Cx_Drivers/Implementation/STM32_RCC.d \
./STM32F103Cx_Drivers/Implementation/STM32_SPI.d \
./STM32F103Cx_Drivers/Implementation/STM32_USART.d \
./STM32F103Cx_Drivers/Implementation/STM32f10C8_EXTI.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103Cx_Drivers/Implementation/STM32_GPIO.o: ../STM32F103Cx_Drivers/Implementation/STM32_GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/STM32F103Cx_Drivers/interface" -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/HAL/Interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103Cx_Drivers/Implementation/STM32_GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103Cx_Drivers/Implementation/STM32_I2C.o: ../STM32F103Cx_Drivers/Implementation/STM32_I2C.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/STM32F103Cx_Drivers/interface" -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/HAL/Interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103Cx_Drivers/Implementation/STM32_I2C.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103Cx_Drivers/Implementation/STM32_RCC.o: ../STM32F103Cx_Drivers/Implementation/STM32_RCC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/STM32F103Cx_Drivers/interface" -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/HAL/Interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103Cx_Drivers/Implementation/STM32_RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103Cx_Drivers/Implementation/STM32_SPI.o: ../STM32F103Cx_Drivers/Implementation/STM32_SPI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/STM32F103Cx_Drivers/interface" -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/HAL/Interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103Cx_Drivers/Implementation/STM32_SPI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103Cx_Drivers/Implementation/STM32_USART.o: ../STM32F103Cx_Drivers/Implementation/STM32_USART.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/STM32F103Cx_Drivers/interface" -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/HAL/Interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103Cx_Drivers/Implementation/STM32_USART.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103Cx_Drivers/Implementation/STM32f10C8_EXTI.o: ../STM32F103Cx_Drivers/Implementation/STM32f10C8_EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/STM32F103Cx_Drivers/interface" -I"D:/amer khaled/Materials/Device Drivers/APP Layer/STM32_I2C_Driver/Test_I2C_Driver/HAL/Interface" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103Cx_Drivers/Implementation/STM32f10C8_EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

