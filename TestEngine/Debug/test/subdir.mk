################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/CSVCrazyFlie.cpp \
../test/PrintGamePad.cpp \
../test/SimpleBalance.cpp \
../test/SimpleFly.cpp \
../test/SimpleHover.cpp \
../test/hover.cpp \
../test/main.cpp 

OBJS += \
./test/CSVCrazyFlie.o \
./test/PrintGamePad.o \
./test/SimpleBalance.o \
./test/SimpleFly.o \
./test/SimpleHover.o \
./test/hover.o \
./test/main.o 

CPP_DEPS += \
./test/CSVCrazyFlie.d \
./test/PrintGamePad.d \
./test/SimpleBalance.d \
./test/SimpleFly.d \
./test/SimpleHover.d \
./test/hover.d \
./test/main.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/midries/Projects/robats/TestEngine/external/include" -I"/home/midries/Projects/robats/Robats/include" -I"/home/midries/Projects/robats/Robats" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


