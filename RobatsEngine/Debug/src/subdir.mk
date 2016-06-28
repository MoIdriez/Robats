################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CSVHover.cpp \
../src/Hover.cpp \
../src/Main.cpp \
../src/RobatsEngine.cpp 

OBJS += \
./src/CSVHover.o \
./src/Hover.o \
./src/Main.o \
./src/RobatsEngine.o 

CPP_DEPS += \
./src/CSVHover.d \
./src/Hover.d \
./src/Main.d \
./src/RobatsEngine.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/midries/Projects/robats/Robats/include" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


