################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../external/googletest/samples/sample1.cc \
../external/googletest/samples/sample10_unittest.cc \
../external/googletest/samples/sample1_unittest.cc \
../external/googletest/samples/sample2.cc \
../external/googletest/samples/sample2_unittest.cc \
../external/googletest/samples/sample3_unittest.cc \
../external/googletest/samples/sample4.cc \
../external/googletest/samples/sample4_unittest.cc \
../external/googletest/samples/sample5_unittest.cc \
../external/googletest/samples/sample6_unittest.cc \
../external/googletest/samples/sample7_unittest.cc \
../external/googletest/samples/sample8_unittest.cc \
../external/googletest/samples/sample9_unittest.cc 

OBJS += \
./external/googletest/samples/sample1.o \
./external/googletest/samples/sample10_unittest.o \
./external/googletest/samples/sample1_unittest.o \
./external/googletest/samples/sample2.o \
./external/googletest/samples/sample2_unittest.o \
./external/googletest/samples/sample3_unittest.o \
./external/googletest/samples/sample4.o \
./external/googletest/samples/sample4_unittest.o \
./external/googletest/samples/sample5_unittest.o \
./external/googletest/samples/sample6_unittest.o \
./external/googletest/samples/sample7_unittest.o \
./external/googletest/samples/sample8_unittest.o \
./external/googletest/samples/sample9_unittest.o 

CC_DEPS += \
./external/googletest/samples/sample1.d \
./external/googletest/samples/sample10_unittest.d \
./external/googletest/samples/sample1_unittest.d \
./external/googletest/samples/sample2.d \
./external/googletest/samples/sample2_unittest.d \
./external/googletest/samples/sample3_unittest.d \
./external/googletest/samples/sample4.d \
./external/googletest/samples/sample4_unittest.d \
./external/googletest/samples/sample5_unittest.d \
./external/googletest/samples/sample6_unittest.d \
./external/googletest/samples/sample7_unittest.d \
./external/googletest/samples/sample8_unittest.d \
./external/googletest/samples/sample9_unittest.d 


# Each subdirectory must supply rules for building sources it contributes
external/googletest/samples/%.o: ../external/googletest/samples/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/midries/Projects/robats/TestEngine/external" -I"/home/midries/Projects/robats/TestEngine/external/googletest/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


