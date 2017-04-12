################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/PUF_extraction.c \
../src/Spongent.c \
../src/_write.c \
../src/diskio.c \
../src/ff.c \
../src/ff_gen_drv.c \
../src/hex-loader.c \
../src/main.c \
../src/present.c \
../src/sd_diskio.c \
../src/sdram_diskio.c \
../src/sram_diskio.c \
../src/stm32_ub_graphic2d.c \
../src/stm32_ub_i2c3.c \
../src/stm32_ub_lcd_480x272.c \
../src/stm32_ub_sdram.c \
../src/stm32_ub_system.c \
../src/stm32_ub_touch_480x272.c \
../src/stm32f7xx_it.c \
../src/types.c 

OBJS += \
./src/PUF_extraction.o \
./src/Spongent.o \
./src/_write.o \
./src/diskio.o \
./src/ff.o \
./src/ff_gen_drv.o \
./src/hex-loader.o \
./src/main.o \
./src/present.o \
./src/sd_diskio.o \
./src/sdram_diskio.o \
./src/sram_diskio.o \
./src/stm32_ub_graphic2d.o \
./src/stm32_ub_i2c3.o \
./src/stm32_ub_lcd_480x272.o \
./src/stm32_ub_sdram.o \
./src/stm32_ub_system.o \
./src/stm32_ub_touch_480x272.o \
./src/stm32f7xx_it.o \
./src/types.o 

C_DEPS += \
./src/PUF_extraction.d \
./src/Spongent.d \
./src/_write.d \
./src/diskio.d \
./src/ff.d \
./src/ff_gen_drv.d \
./src/hex-loader.d \
./src/main.d \
./src/present.d \
./src/sd_diskio.d \
./src/sdram_diskio.d \
./src/sram_diskio.d \
./src/stm32_ub_graphic2d.d \
./src/stm32_ub_i2c3.d \
./src/stm32_ub_lcd_480x272.d \
./src/stm32_ub_sdram.d \
./src/stm32_ub_system.d \
./src/stm32_ub_touch_480x272.d \
./src/stm32f7xx_it.d \
./src/types.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DSTM32F746xx -DTRACE -DOS_USE_TRACE_ITM -I"../include" -I"/Users/domenicoamelino/Documents/devstm32f7/workspace/stm32f7_techday/system/include/BSP" -I"/Users/domenicoamelino/Documents/devstm32f7/workspace/stm32f7_techday/system/include/Components" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f7xx" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


