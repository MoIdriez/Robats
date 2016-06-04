################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CrazyEngine/CCRTPPacket.cpp \
../src/CrazyEngine/CCrazyRadio.cpp \
../src/CrazyEngine/CCrazyflie.cpp \
../src/CrazyEngine/CTOC.cpp \
../src/CrazyEngine/CrazyEngine.cpp 

OBJS += \
./src/CrazyEngine/CCRTPPacket.o \
./src/CrazyEngine/CCrazyRadio.o \
./src/CrazyEngine/CCrazyflie.o \
./src/CrazyEngine/CTOC.o \
./src/CrazyEngine/CrazyEngine.o 

CPP_DEPS += \
./src/CrazyEngine/CCRTPPacket.d \
./src/CrazyEngine/CCrazyRadio.d \
./src/CrazyEngine/CCrazyflie.d \
./src/CrazyEngine/CTOC.d \
./src/CrazyEngine/CrazyEngine.d 


# Each subdirectory must supply rules for building sources it contributes
src/CrazyEngine/%.o: ../src/CrazyEngine/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/midries/Projects/robats/Robats/include" -O3 -Wall -c -fmessage-length=0 -std=c++11 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


