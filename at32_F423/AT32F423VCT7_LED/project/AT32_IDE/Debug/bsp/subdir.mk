################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../bsp/at32f423_board.c 

OBJS += \
./bsp/at32f423_board.o 

C_DEPS += \
./bsp/at32f423_board.d 


# Each subdirectory must supply rules for building sources it contributes
bsp/%.o: ../bsp/%.c bsp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423VCT7 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


