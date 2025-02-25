################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/API/Src/RADAR_Delay.c \
../Drivers/API/Src/RADAR_GPIO.c \
../Drivers/API/Src/RADAR_HC05.c \
../Drivers/API/Src/RADAR_HCSR04.c \
../Drivers/API/Src/RADAR_LCD.c \
../Drivers/API/Src/RADAR_MEF.c \
../Drivers/API/Src/RADAR_SECUENCIAS.c \
../Drivers/API/Src/RADAR_Servo.c 

OBJS += \
./Drivers/API/Src/RADAR_Delay.o \
./Drivers/API/Src/RADAR_GPIO.o \
./Drivers/API/Src/RADAR_HC05.o \
./Drivers/API/Src/RADAR_HCSR04.o \
./Drivers/API/Src/RADAR_LCD.o \
./Drivers/API/Src/RADAR_MEF.o \
./Drivers/API/Src/RADAR_SECUENCIAS.o \
./Drivers/API/Src/RADAR_Servo.o 

C_DEPS += \
./Drivers/API/Src/RADAR_Delay.d \
./Drivers/API/Src/RADAR_GPIO.d \
./Drivers/API/Src/RADAR_HC05.d \
./Drivers/API/Src/RADAR_HCSR04.d \
./Drivers/API/Src/RADAR_LCD.d \
./Drivers/API/Src/RADAR_MEF.d \
./Drivers/API/Src/RADAR_SECUENCIAS.d \
./Drivers/API/Src/RADAR_Servo.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/API/Src/%.o Drivers/API/Src/%.su Drivers/API/Src/%.cyclo: ../Drivers/API/Src/%.c Drivers/API/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/EmanuelDecima/Desktop/Proyecto FinalTDII/Grupo_3_TDII_2024/AFP_5_TDII_2024 _STM32F401/Drivers/API" -I"C:/Users/EmanuelDecima/Desktop/Proyecto FinalTDII/Grupo_3_TDII_2024/AFP_5_TDII_2024 _STM32F401/Drivers/API/Src" -I"C:/Users/EmanuelDecima/Desktop/Proyecto FinalTDII/Grupo_3_TDII_2024/AFP_5_TDII_2024 _STM32F401/Drivers/API/Inc" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-API-2f-Src

clean-Drivers-2f-API-2f-Src:
	-$(RM) ./Drivers/API/Src/RADAR_Delay.cyclo ./Drivers/API/Src/RADAR_Delay.d ./Drivers/API/Src/RADAR_Delay.o ./Drivers/API/Src/RADAR_Delay.su ./Drivers/API/Src/RADAR_GPIO.cyclo ./Drivers/API/Src/RADAR_GPIO.d ./Drivers/API/Src/RADAR_GPIO.o ./Drivers/API/Src/RADAR_GPIO.su ./Drivers/API/Src/RADAR_HC05.cyclo ./Drivers/API/Src/RADAR_HC05.d ./Drivers/API/Src/RADAR_HC05.o ./Drivers/API/Src/RADAR_HC05.su ./Drivers/API/Src/RADAR_HCSR04.cyclo ./Drivers/API/Src/RADAR_HCSR04.d ./Drivers/API/Src/RADAR_HCSR04.o ./Drivers/API/Src/RADAR_HCSR04.su ./Drivers/API/Src/RADAR_LCD.cyclo ./Drivers/API/Src/RADAR_LCD.d ./Drivers/API/Src/RADAR_LCD.o ./Drivers/API/Src/RADAR_LCD.su ./Drivers/API/Src/RADAR_MEF.cyclo ./Drivers/API/Src/RADAR_MEF.d ./Drivers/API/Src/RADAR_MEF.o ./Drivers/API/Src/RADAR_MEF.su ./Drivers/API/Src/RADAR_SECUENCIAS.cyclo ./Drivers/API/Src/RADAR_SECUENCIAS.d ./Drivers/API/Src/RADAR_SECUENCIAS.o ./Drivers/API/Src/RADAR_SECUENCIAS.su ./Drivers/API/Src/RADAR_Servo.cyclo ./Drivers/API/Src/RADAR_Servo.d ./Drivers/API/Src/RADAR_Servo.o ./Drivers/API/Src/RADAR_Servo.su

.PHONY: clean-Drivers-2f-API-2f-Src

