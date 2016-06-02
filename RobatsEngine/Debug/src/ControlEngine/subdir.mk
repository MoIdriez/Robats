################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ControlEngine/AutoFlight.cpp \
../src/ControlEngine/GamePad.cpp 

OBJS += \
./src/ControlEngine/AutoFlight.o \
./src/ControlEngine/GamePad.o 

CPP_DEPS += \
./src/ControlEngine/AutoFlight.d \
./src/ControlEngine/GamePad.d 


# Each subdirectory must supply rules for building sources it contributes
src/ControlEngine/%.o: ../src/ControlEngine/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


