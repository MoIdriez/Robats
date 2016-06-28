################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CrazyControl/AutoFlight.cpp \
../src/CrazyControl/Balance.cpp \
../src/CrazyControl/GamePad.cpp \
../src/CrazyControl/PID.cpp \
../src/CrazyControl/RunAverage.cpp 

OBJS += \
./src/CrazyControl/AutoFlight.o \
./src/CrazyControl/Balance.o \
./src/CrazyControl/GamePad.o \
./src/CrazyControl/PID.o \
./src/CrazyControl/RunAverage.o 

CPP_DEPS += \
./src/CrazyControl/AutoFlight.d \
./src/CrazyControl/Balance.d \
./src/CrazyControl/GamePad.d \
./src/CrazyControl/PID.d \
./src/CrazyControl/RunAverage.d 


# Each subdirectory must supply rules for building sources it contributes
src/CrazyControl/%.o: ../src/CrazyControl/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/midries/Projects/robats/Robats/include" -O3 -Wall -c -fmessage-length=0 -std=c++11 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


