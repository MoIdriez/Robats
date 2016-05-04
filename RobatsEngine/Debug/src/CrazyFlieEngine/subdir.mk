################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CrazyFlieEngine/CCRTPPacket.cpp \
../src/CrazyFlieEngine/CCrazyRadio.cpp \
../src/CrazyFlieEngine/CCrazyflie.cpp \
../src/CrazyFlieEngine/CTOC.cpp 

OBJS += \
./src/CrazyFlieEngine/CCRTPPacket.o \
./src/CrazyFlieEngine/CCrazyRadio.o \
./src/CrazyFlieEngine/CCrazyflie.o \
./src/CrazyFlieEngine/CTOC.o 

CPP_DEPS += \
./src/CrazyFlieEngine/CCRTPPacket.d \
./src/CrazyFlieEngine/CCrazyRadio.d \
./src/CrazyFlieEngine/CCrazyflie.d \
./src/CrazyFlieEngine/CTOC.d 


# Each subdirectory must supply rules for building sources it contributes
src/CrazyFlieEngine/%.o: ../src/CrazyFlieEngine/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


