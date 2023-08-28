################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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
Lab1_CortexM3_EXTI.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Lab1_CortexM3_EXTI.list \

OBJCOPY_BIN += \
Lab1_CortexM3_EXTI.bin \


# All Target
all: Lab1_CortexM3_EXTI.elf secondary-outputs

# Tool invocations
Lab1_CortexM3_EXTI.elf: $(OBJS) $(USER_OBJS) D:\amer\ khaled\GitHub\Master-Embedded-System\1-First\ Term\Unit6_MCU_Fundamentals\Lesson4_Interrupt\Lab\ 1\CODE\Lab1_CortexM3_EXTI\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "Lab1_CortexM3_EXTI.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\amer khaled\GitHub\Master-Embedded-System\1-First Term\Unit6_MCU_Fundamentals\Lesson4_Interrupt\Lab 1\CODE\Lab1_CortexM3_EXTI\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Lab1_CortexM3_EXTI.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Lab1_CortexM3_EXTI.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Lab1_CortexM3_EXTI.list"
	@echo 'Finished building: $@'
	@echo ' '

Lab1_CortexM3_EXTI.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Lab1_CortexM3_EXTI.bin"
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
