################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/cmsis/cm4/device_support/system_at32f423.c 

OBJS += \
./cmsis/system_at32f423.o 

C_DEPS += \
./cmsis/system_at32f423.d 


# Each subdirectory must supply rules for building sources it contributes
cmsis/system_at32f423.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/cmsis/cm4/device_support/system_at32f423.c cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


