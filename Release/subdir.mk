################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AbstractCommunication.cpp \
../Debug.cpp \
../GlobalReceiver.cpp \
../SerialCom.cpp \
../main.cpp 

OBJS += \
./AbstractCommunication.o \
./Debug.o \
./GlobalReceiver.o \
./SerialCom.o \
./main.o 

CPP_DEPS += \
./AbstractCommunication.d \
./Debug.d \
./GlobalReceiver.d \
./SerialCom.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/home/chris/Software/arduino-1.0.5/hardware/arduino/cores/arduino -I/home/chris/Software/arduino-1.0.5/hardware/arduino/variants/mega -I"/home/chris/Workspace/PlusPonics/code/ArduinoCore" -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega2560 -DF_CPU=1600000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


