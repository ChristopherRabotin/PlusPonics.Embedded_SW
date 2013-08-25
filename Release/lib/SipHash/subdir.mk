################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lib/SipHash/SipHash_2_4.cpp 

C_SRCS += \
../lib/SipHash/HexConversionUtils.c 

S_UPPER_SRCS += \
../lib/SipHash/siphash_2_4_asm.S 

OBJS += \
./lib/SipHash/HexConversionUtils.o \
./lib/SipHash/SipHash_2_4.o \
./lib/SipHash/siphash_2_4_asm.o 

C_DEPS += \
./lib/SipHash/HexConversionUtils.d 

S_UPPER_DEPS += \
./lib/SipHash/siphash_2_4_asm.d 

CPP_DEPS += \
./lib/SipHash/SipHash_2_4.d 


# Each subdirectory must supply rules for building sources it contributes
lib/SipHash/%.o: ../lib/SipHash/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I/home/chris/Software/arduino-1.0.5/hardware/arduino/cores/arduino -I"/home/chris/Workspace/PlusPonics/code/ArduinoCore" -I/home/chris/Software/arduino-1.0.5/hardware/arduino/variants/mega -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega2560 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/SipHash/%.o: ../lib/SipHash/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/chris/Software/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/chris/Software/arduino-1.0.5/hardware/arduino/variants/mega -I"/home/chris/Workspace/PlusPonics/code/ArduinoCore" -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega2560 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/SipHash/%.o: ../lib/SipHash/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Assembler'
	avr-gcc -x assembler-with-cpp -mmcu=atmega2560 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


