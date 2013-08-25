################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lib/SipHash/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Embedded_SW.lss \

FLASH_IMAGE += \
Embedded_SW.hex \

EEPROM_IMAGE += \
Embedded_SW.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Embedded_SW.elf secondary-outputs

# Tool invocations
Embedded_SW.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ --cref -s -Os -o"Embedded_SW.elf" $(OBJS) $(USER_OBJS) $(LIBS) -lm -Wl,-Map,Embedded_SW.map,--cref -L"/home/chris/Workspace/PlusPonics/code/ArduinoCore/Release" -mmcu=atmega2560
	@echo 'Finished building target: $@'
	@echo ' '

Embedded_SW.lss: Embedded_SW.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Embedded_SW.elf  >"Embedded_SW.lss"
	@echo 'Finished building: $@'
	@echo ' '

Embedded_SW.hex: Embedded_SW.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Embedded_SW.elf  "Embedded_SW.hex"
	@echo 'Finished building: $@'
	@echo ' '

Embedded_SW.eep: Embedded_SW.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Embedded_SW.elf  "Embedded_SW.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Embedded_SW.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega2560 Embedded_SW.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(CPP_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) Embedded_SW.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
