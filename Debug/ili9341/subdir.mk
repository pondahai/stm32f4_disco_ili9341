################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ili9341/fonts.c \
../ili9341/ili9341.c 

OBJS += \
./ili9341/fonts.o \
./ili9341/ili9341.o 

C_DEPS += \
./ili9341/fonts.d \
./ili9341/ili9341.d 


# Each subdirectory must supply rules for building sources it contributes
ili9341/%.o: ../ili9341/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F407xx -I"/Users/test/Dropbox/ili9341_stm32f407_test/Inc" -I"/Users/test/Dropbox/ili9341_stm32f407_test/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/Users/test/Dropbox/ili9341_stm32f407_test/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/Users/test/Dropbox/ili9341_stm32f407_test/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"/Users/test/Dropbox/ili9341_stm32f407_test/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"/Users/test/Dropbox/ili9341_stm32f407_test/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/Users/test/Dropbox/ili9341_stm32f407_test/Drivers/CMSIS/Include" -I"/Users/test/Dropbox/ili9341_stm32f407_test/ili9341"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


