################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/API_Delay.c \
../Drivers/API/Src/API_GPIO.c 

OBJS += \
./Drivers/API/Src/API_Delay.o \
./Drivers/API/Src/API_GPIO.o 

C_DEPS += \
./Drivers/API/Src/API_Delay.d \
./Drivers/API/Src/API_GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su Drivers/API/Src/%.cyclo: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Estudiante.DESKTOP-5OVK98J/STM32CubeIDE/workspace_1.16.0/Grupo_3_TDII_2024/AFP_3_TDII_2024/AFP_3_Grupo_3_App_3.1/Drivers/API/Inc" -I"C:/Users/Estudiante.DESKTOP-5OVK98J/STM32CubeIDE/workspace_1.16.0/Grupo_3_TDII_2024/AFP_3_TDII_2024/AFP_3_Grupo_3_App_3.1/Drivers/API/Src" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/API_Delay.cyclo ./Drivers/API/Src/API_Delay.d ./Drivers/API/Src/API_Delay.o ./Drivers/API/Src/API_Delay.su ./Drivers/API/Src/API_GPIO.cyclo ./Drivers/API/Src/API_GPIO.d ./Drivers/API/Src/API_GPIO.o ./Drivers/API/Src/API_GPIO.su

.PHONY: clean-Drivers-2f-API-2f-Src

