################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/AVR/DIO/subdir.mk
-include HAL/SEG/subdir.mk
-include APP/subdir.mk
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
Cots.lss \
Cots.lss \

FLASH_IMAGE += \
Cots.hex \
Cots.hex \

SIZEDUMMY += \
sizedummy \
sizedummy \


# All Target
all: Cots.elf secondary-outputs

# Tool invocations
Cots.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Cots.map -mmcu=atmega32 -o "Cots.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Cots.lss: Cots.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Cots.elf  >"Cots.lss"
	@echo 'Finished building: $@'
	@echo ' '

Cots.hex: Cots.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Cots.elf  "Cots.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Cots.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Cots.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Cots.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
