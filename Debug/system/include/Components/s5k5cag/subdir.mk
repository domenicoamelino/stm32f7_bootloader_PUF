################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/include/Components/s5k5cag/s5k5cag.c 

OBJS += \
./system/include/Components/s5k5cag/s5k5cag.o 

C_DEPS += \
./system/include/Components/s5k5cag/s5k5cag.d 


# Each subdirectory must supply rules for building sources it contributes
system/include/Components/s5k5cag/%.o: ../system/include/Components/s5k5cag/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DSTM32F746xx -DTRACE -DOS_USE_TRACE_ITM -I"../include" -I"/Users/domenicoamelino/Documents/devstm32f7/workspace/stm32f7_techday/system/include/BSP" -I"/Users/domenicoamelino/Documents/devstm32f7/workspace/stm32f7_techday/system/include/Components" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f7xx" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


