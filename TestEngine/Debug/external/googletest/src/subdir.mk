################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/googletest/src/gtest-all.cc \
../external/googletest/src/gtest-death-test.cc \
../external/googletest/src/gtest-filepath.cc \
../external/googletest/src/gtest-port.cc \
../external/googletest/src/gtest-printers.cc \
../external/googletest/src/gtest-test-part.cc \
../external/googletest/src/gtest-typed-test.cc \
../external/googletest/src/gtest.cc \
../external/googletest/src/gtest_main.cc 

OBJS += \
./external/googletest/src/gtest-all.o \
./external/googletest/src/gtest-death-test.o \
./external/googletest/src/gtest-filepath.o \
./external/googletest/src/gtest-port.o \
./external/googletest/src/gtest-printers.o \
./external/googletest/src/gtest-test-part.o \
./external/googletest/src/gtest-typed-test.o \
./external/googletest/src/gtest.o \
./external/googletest/src/gtest_main.o 

CC_DEPS += \
./external/googletest/src/gtest-all.d \
./external/googletest/src/gtest-death-test.d \
./external/googletest/src/gtest-filepath.d \
./external/googletest/src/gtest-port.d \
./external/googletest/src/gtest-printers.d \
./external/googletest/src/gtest-test-part.d \
./external/googletest/src/gtest-typed-test.d \
./external/googletest/src/gtest.d \
./external/googletest/src/gtest_main.d 


# Each subdirectory must supply rules for building sources it contributes
external/googletest/src/%.o: ../external/googletest/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/midries/Projects/robats/TestEngine/external" -I"/home/midries/Projects/robats/TestEngine/external/googletest/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


