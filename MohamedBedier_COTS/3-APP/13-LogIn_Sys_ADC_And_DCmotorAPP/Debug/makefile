################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
LogIn_Sys_ADC_And_DCmotorAPP.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: LogIn_Sys_ADC_And_DCmotorAPP.elf secondary-outputs

# Tool invocations
LogIn_Sys_ADC_And_DCmotorAPP.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LogIn_Sys_ADC_And_DCmotorAPP.map -mmcu=atmega32 -o "LogIn_Sys_ADC_And_DCmotorAPP.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LogIn_Sys_ADC_And_DCmotorAPP.lss: LogIn_Sys_ADC_And_DCmotorAPP.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LogIn_Sys_ADC_And_DCmotorAPP.elf  >"LogIn_Sys_ADC_And_DCmotorAPP.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LogIn_Sys_ADC_And_DCmotorAPP.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LogIn_Sys_ADC_And_DCmotorAPP.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LogIn_Sys_ADC_And_DCmotorAPP.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
