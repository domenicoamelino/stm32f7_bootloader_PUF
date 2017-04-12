################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/rm/common.c \
../src/rm/list.c \
../src/rm/matrix.c \
../src/rm/memory_vector.c \
../src/rm/monomial.c \
../src/rm/reedmuller.c \
../src/rm/rm_decoder.c \
../src/rm/rm_encoder.c \
../src/rm/utils.c \
../src/rm/vector.c 

OBJS += \
./src/rm/common.o \
./src/rm/list.o \
./src/rm/matrix.o \
./src/rm/memory_vector.o \
./src/rm/monomial.o \
./src/rm/reedmuller.o \
./src/rm/rm_decoder.o \
./src/rm/rm_encoder.o \
./src/rm/utils.o \
./src/rm/vector.o 

C_DEPS += \
./src/rm/common.d \
./src/rm/list.d \
./src/rm/matrix.d \
./src/rm/memory_vector.d \
./src/rm/monomial.d \
./src/rm/reedmuller.d \
./src/rm/rm_decoder.d \
./src/rm/rm_encoder.d \
./src/rm/utils.d \
./src/rm/vector.d 


# Each subdirectory must supply rules for building sources it contributes
src/rm/%.o: ../src/rm/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DSTM32F746xx -DTRACE -DOS_USE_TRACE_ITM -I"../include" -I"/Users/domenicoamelino/Documents/devstm32f7/workspace/stm32f7_techday/system/include/BSP" -I"/Users/domenicoamelino/Documents/devstm32f7/workspace/stm32f7_techday/system/include/Components" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f7xx" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


