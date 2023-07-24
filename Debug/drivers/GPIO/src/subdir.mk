################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/GPIO/src/gpio.c 

OBJS += \
./drivers/GPIO/src/gpio.o 

C_DEPS += \
./drivers/GPIO/src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/GPIO/src/%.o drivers/GPIO/src/%.su drivers/GPIO/src/%.cyclo: ../drivers/GPIO/src/%.c drivers/GPIO/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"D:/Workspace/NUCLEO-F446RE/drivers/USART/inc" -I"D:/Workspace/NUCLEO-F446RE/drivers/TIM/inc" -I"D:/Workspace/NUCLEO-F446RE/drivers/GPIO/inc" -I"D:/Workspace/NUCLEO-F446RE/drivers/RCC/inc" -I"D:/Workspace/NUCLEO-F446RE/drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drivers-2f-GPIO-2f-src

clean-drivers-2f-GPIO-2f-src:
	-$(RM) ./drivers/GPIO/src/gpio.cyclo ./drivers/GPIO/src/gpio.d ./drivers/GPIO/src/gpio.o ./drivers/GPIO/src/gpio.su

.PHONY: clean-drivers-2f-GPIO-2f-src

