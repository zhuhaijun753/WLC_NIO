################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/app/systemIdConfig.c" \
"../Sources/app/systemPing.c" \
"../Sources/app/systemPowerTrans.c" \
"../Sources/app/systemSafe.c" \
"../Sources/app/systemSelection.c" \
"../Sources/app/systemStatusCharge.c" \
"../Sources/app/systemStatusFault.c" \
"../Sources/app/systemStatusNfc.c" \
"../Sources/app/systemStatusPause.c" \
"../Sources/app/systemStatusStandby.c" \
"../Sources/app/systemTask.c" \
"../Sources/app/systemTerminate.c" \
"../Sources/app/systemTimers.c" \

C_SRCS += \
../Sources/app/systemIdConfig.c \
../Sources/app/systemPing.c \
../Sources/app/systemPowerTrans.c \
../Sources/app/systemSafe.c \
../Sources/app/systemSelection.c \
../Sources/app/systemStatusCharge.c \
../Sources/app/systemStatusFault.c \
../Sources/app/systemStatusNfc.c \
../Sources/app/systemStatusPause.c \
../Sources/app/systemStatusStandby.c \
../Sources/app/systemTask.c \
../Sources/app/systemTerminate.c \
../Sources/app/systemTimers.c \

OBJS_OS_FORMAT += \
./Sources/app/systemIdConfig.o \
./Sources/app/systemPing.o \
./Sources/app/systemPowerTrans.o \
./Sources/app/systemSafe.o \
./Sources/app/systemSelection.o \
./Sources/app/systemStatusCharge.o \
./Sources/app/systemStatusFault.o \
./Sources/app/systemStatusNfc.o \
./Sources/app/systemStatusPause.o \
./Sources/app/systemStatusStandby.o \
./Sources/app/systemTask.o \
./Sources/app/systemTerminate.o \
./Sources/app/systemTimers.o \

C_DEPS_QUOTED += \
"./Sources/app/systemIdConfig.d" \
"./Sources/app/systemPing.d" \
"./Sources/app/systemPowerTrans.d" \
"./Sources/app/systemSafe.d" \
"./Sources/app/systemSelection.d" \
"./Sources/app/systemStatusCharge.d" \
"./Sources/app/systemStatusFault.d" \
"./Sources/app/systemStatusNfc.d" \
"./Sources/app/systemStatusPause.d" \
"./Sources/app/systemStatusStandby.d" \
"./Sources/app/systemTask.d" \
"./Sources/app/systemTerminate.d" \
"./Sources/app/systemTimers.d" \

OBJS += \
./Sources/app/systemIdConfig.o \
./Sources/app/systemPing.o \
./Sources/app/systemPowerTrans.o \
./Sources/app/systemSafe.o \
./Sources/app/systemSelection.o \
./Sources/app/systemStatusCharge.o \
./Sources/app/systemStatusFault.o \
./Sources/app/systemStatusNfc.o \
./Sources/app/systemStatusPause.o \
./Sources/app/systemStatusStandby.o \
./Sources/app/systemTask.o \
./Sources/app/systemTerminate.o \
./Sources/app/systemTimers.o \

OBJS_QUOTED += \
"./Sources/app/systemIdConfig.o" \
"./Sources/app/systemPing.o" \
"./Sources/app/systemPowerTrans.o" \
"./Sources/app/systemSafe.o" \
"./Sources/app/systemSelection.o" \
"./Sources/app/systemStatusCharge.o" \
"./Sources/app/systemStatusFault.o" \
"./Sources/app/systemStatusNfc.o" \
"./Sources/app/systemStatusPause.o" \
"./Sources/app/systemStatusStandby.o" \
"./Sources/app/systemTask.o" \
"./Sources/app/systemTerminate.o" \
"./Sources/app/systemTimers.o" \

C_DEPS += \
./Sources/app/systemIdConfig.d \
./Sources/app/systemPing.d \
./Sources/app/systemPowerTrans.d \
./Sources/app/systemSafe.d \
./Sources/app/systemSelection.d \
./Sources/app/systemStatusCharge.d \
./Sources/app/systemStatusFault.d \
./Sources/app/systemStatusNfc.d \
./Sources/app/systemStatusPause.d \
./Sources/app/systemStatusStandby.d \
./Sources/app/systemTask.d \
./Sources/app/systemTerminate.d \
./Sources/app/systemTimers.d \


# Each subdirectory must supply rules for building sources it contributes
Sources/app/systemIdConfig.o: ../Sources/app/systemIdConfig.c
	@echo 'Building file: $<'
	@echo 'Executing target #174 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemIdConfig.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemIdConfig.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/systemPing.o: ../Sources/app/systemPing.c
	@echo 'Building file: $<'
	@echo 'Executing target #175 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemPing.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemPing.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/systemPowerTrans.o: ../Sources/app/systemPowerTrans.c
	@echo 'Building file: $<'
	@echo 'Executing target #176 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemPowerTrans.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemPowerTrans.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/systemSafe.o: ../Sources/app/systemSafe.c
	@echo 'Building file: $<'
	@echo 'Executing target #177 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemSafe.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemSafe.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/systemSelection.o: ../Sources/app/systemSelection.c
	@echo 'Building file: $<'
	@echo 'Executing target #178 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemSelection.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemSelection.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/systemStatusCharge.o: ../Sources/app/systemStatusCharge.c
	@echo 'Building file: $<'
	@echo 'Executing target #179 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemStatusCharge.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemStatusCharge.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/systemStatusFault.o: ../Sources/app/systemStatusFault.c
	@echo 'Building file: $<'
	@echo 'Executing target #180 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemStatusFault.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemStatusFault.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/systemStatusNfc.o: ../Sources/app/systemStatusNfc.c
	@echo 'Building file: $<'
	@echo 'Executing target #181 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemStatusNfc.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemStatusNfc.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/systemStatusPause.o: ../Sources/app/systemStatusPause.c
	@echo 'Building file: $<'
	@echo 'Executing target #182 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemStatusPause.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemStatusPause.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/systemStatusStandby.o: ../Sources/app/systemStatusStandby.c
	@echo 'Building file: $<'
	@echo 'Executing target #183 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemStatusStandby.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemStatusStandby.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/systemTask.o: ../Sources/app/systemTask.c
	@echo 'Building file: $<'
	@echo 'Executing target #184 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemTask.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemTask.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/systemTerminate.o: ../Sources/app/systemTerminate.c
	@echo 'Building file: $<'
	@echo 'Executing target #185 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemTerminate.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemTerminate.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Sources/app/systemTimers.o: ../Sources/app/systemTimers.c
	@echo 'Building file: $<'
	@echo 'Executing target #186 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@Sources/app/systemTimers.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "Sources/app/systemTimers.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


