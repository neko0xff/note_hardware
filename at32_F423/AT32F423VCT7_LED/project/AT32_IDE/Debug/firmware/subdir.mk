################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_crm.c \
/home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_debug.c \
/home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_exint.c \
/home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_flash.c \
/home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_gpio.c \
/home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_misc.c \
/home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_pwc.c \
/home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_scfg.c \
/home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_tmr.c \
/home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_usart.c 

OBJS += \
./firmware/at32f423_crm.o \
./firmware/at32f423_debug.o \
./firmware/at32f423_exint.o \
./firmware/at32f423_flash.o \
./firmware/at32f423_gpio.o \
./firmware/at32f423_misc.o \
./firmware/at32f423_pwc.o \
./firmware/at32f423_scfg.o \
./firmware/at32f423_tmr.o \
./firmware/at32f423_usart.o 

C_DEPS += \
./firmware/at32f423_crm.d \
./firmware/at32f423_debug.d \
./firmware/at32f423_exint.d \
./firmware/at32f423_flash.d \
./firmware/at32f423_gpio.d \
./firmware/at32f423_misc.d \
./firmware/at32f423_pwc.d \
./firmware/at32f423_scfg.d \
./firmware/at32f423_tmr.d \
./firmware/at32f423_usart.d 


# Each subdirectory must supply rules for building sources it contributes
firmware/at32f423_crm.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_crm.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_debug.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_debug.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_exint.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_exint.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_flash.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_flash.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_gpio.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_gpio.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_misc.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_misc.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_pwc.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_pwc.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_scfg.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_scfg.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_tmr.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_tmr.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_usart.o: /home/user/at32ide-workspace/AT32F423VCT7_LED/libraries/drivers/src/at32f423_usart.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


