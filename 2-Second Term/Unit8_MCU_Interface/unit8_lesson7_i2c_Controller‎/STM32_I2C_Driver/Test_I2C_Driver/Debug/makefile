################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32F103Cx_Drivers/Implementation/subdir.mk
-include HAL/Implementation/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Test_I2C_Driver.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Test_I2C_Driver.list \

OBJCOPY_BIN += \
Test_I2C_Driver.bin \


# All Target
all: Test_I2C_Driver.elf secondary-outputs

# Tool invocations
Test_I2C_Driver.elf: $(OBJS) $(USER_OBJS) D:\amer\ khaled\Materials\Device\ Drivers\APP\ Layer\STM32_I2C_Driver\Test_I2C_Driver\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "Test_I2C_Driver.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\amer khaled\Materials\Device Drivers\APP Layer\STM32_I2C_Driver\Test_I2C_Driver\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Test_I2C_Driver.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Test_I2C_Driver.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Test_I2C_Driver.list"
	@echo 'Finished building: $@'
	@echo ' '

Test_I2C_Driver.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Test_I2C_Driver.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
