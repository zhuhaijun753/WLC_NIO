################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/interrupt.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/interrupt.c \
../Sources/main.c \

OBJS_OS_FORMAT += \
./Sources/interrupt.o \
./Sources/main.o \

C_DEPS_QUOTED += \
"./Sources/interrupt.d" \
"./Sources/main.d" \

OBJS += \
./Sources/interrupt.o \
./Sources/main.o \

OBJS_QUOTED += \
"./Sources/interrupt.o" \
"./Sources/main.o" \

C_DEPS += \
./Sources/interrupt.d \
./Sources/main.d \


# Each subdirectory must supply rules for building sources it contributes
Sources/interrupt.o: ../Sources/interrupt.c
	@echo 'Building file: $<'
	@echo 'Executing target #54 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/interrupt.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/interrupt.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #55 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/main.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


