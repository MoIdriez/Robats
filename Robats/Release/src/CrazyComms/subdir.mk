################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CrazyComms/CrazyServer.cpp 

OBJS += \
./src/CrazyComms/CrazyServer.o 

CPP_DEPS += \
./src/CrazyComms/CrazyServer.d 


# Each subdirectory must supply rules for building sources it contributes
src/CrazyComms/%.o: ../src/CrazyComms/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/midries/Projects/robats/Robats/include" -O3 -Wall -c -fmessage-length=0 -std=c++11 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


