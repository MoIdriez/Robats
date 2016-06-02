################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/googletest/codegear/gtest_all.cc \
../external/googletest/codegear/gtest_link.cc 

OBJS += \
./external/googletest/codegear/gtest_all.o \
./external/googletest/codegear/gtest_link.o 

CC_DEPS += \
./external/googletest/codegear/gtest_all.d \
./external/googletest/codegear/gtest_link.d 


# Each subdirectory must supply rules for building sources it contributes
external/googletest/codegear/%.o: ../external/googletest/codegear/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/midries/Projects/robats/TestEngine/external" -I"/home/midries/Projects/robats/TestEngine/external/googletest/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


