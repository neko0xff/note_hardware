################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/user/at32ide-workspace/AT32F423VCT7_LED/project/src/at32f423_int.c \
/home/user/at32ide-workspace/AT32F423VCT7_LED/project/src/at32f423_wk_config.c \
/home/user/at32ide-workspace/AT32F423VCT7_LED/project/src/main.c 

OBJS += \
./user/at32f423_int.o \
./user/at32f423_wk_config.o \
./user/main.o 

C_DEPS += \
./user/at32f423_int.d \
./user/at32f423_wk_config.d \
./user/main.d 


# Each subdirectory must supply rules for building sources it contributes
user/at32f423_int.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/project/src/at32f423_int.c user/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

user/at32f423_wk_config.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/project/src/at32f423_wk_config.c user/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

user/main.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/project/src/main.c user/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


