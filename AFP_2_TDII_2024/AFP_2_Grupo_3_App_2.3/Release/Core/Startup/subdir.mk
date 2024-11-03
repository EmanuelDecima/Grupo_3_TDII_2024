################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f429zitx.s 

OBJS += \
./Core/Startup/startup_stm32f429zitx.o 

S_DEPS += \
./Core/Startup/startup_stm32f429zitx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -c -I"C:/Users/Estudiante.DESKTOP-5OVK98J/STM32CubeIDE/workspace_1.16.0/Grupo_3_TDII_2024/AFP_2_TDII_2024/AFP_2_Grupo_3_App_2.3/Drivers/API" -I"C:/Users/Estudiante.DESKTOP-5OVK98J/STM32CubeIDE/workspace_1.16.0/Grupo_3_TDII_2024/AFP_2_TDII_2024/AFP_2_Grupo_3_App_2.3/Drivers" -I"C:/Users/Estudiante.DESKTOP-5OVK98J/STM32CubeIDE/workspace_1.16.0/Grupo_3_TDII_2024/AFP_2_TDII_2024/AFP_2_Grupo_3_App_2.3/Drivers/API/Inc" -I"C:/Users/Estudiante.DESKTOP-5OVK98J/STM32CubeIDE/workspace_1.16.0/Grupo_3_TDII_2024/AFP_2_TDII_2024/AFP_2_Grupo_3_App_2.3/Drivers/API/Src" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f429zitx.d ./Core/Startup/startup_stm32f429zitx.o

.PHONY: clean-Core-2f-Startup

