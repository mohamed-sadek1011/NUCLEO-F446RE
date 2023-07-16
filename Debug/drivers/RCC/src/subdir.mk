################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/RCC/src/rcc.c 

OBJS += \
./drivers/RCC/src/rcc.o 

C_DEPS += \
./drivers/RCC/src/rcc.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/RCC/src/%.o drivers/RCC/src/%.su drivers/RCC/src/%.cyclo: ../drivers/RCC/src/%.c drivers/RCC/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -I"D:/Code/ST WS/NUCLEO-F446RE/drivers/GPIO/inc" -I"D:/Code/ST WS/NUCLEO-F446RE/drivers/RCC/inc" -I"D:/Code/ST WS/NUCLEO-F446RE/drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drivers-2f-RCC-2f-src

clean-drivers-2f-RCC-2f-src:
	-$(RM) ./drivers/RCC/src/rcc.cyclo ./drivers/RCC/src/rcc.d ./drivers/RCC/src/rcc.o ./drivers/RCC/src/rcc.su

.PHONY: clean-drivers-2f-RCC-2f-src

