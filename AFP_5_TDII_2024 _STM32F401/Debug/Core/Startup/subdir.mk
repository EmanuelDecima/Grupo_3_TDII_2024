################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f401ccux.s 

OBJS += \
./Core/Startup/startup_stm32f401ccux.o 

S_DEPS += \
./Core/Startup/startup_stm32f401ccux.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/Users/Estudiante.DESKTOP-5OVK98J/STM32CubeIDE/workspace_1.16.0/Grupo_3_TDII_2024/AFP_5_TDII_2024 _STM32F401/Drivers/API" -I"C:/Users/Estudiante.DESKTOP-5OVK98J/STM32CubeIDE/workspace_1.16.0/Grupo_3_TDII_2024/AFP_5_TDII_2024 _STM32F401/Drivers/API/Src" -I"C:/Users/Estudiante.DESKTOP-5OVK98J/STM32CubeIDE/workspace_1.16.0/Grupo_3_TDII_2024/AFP_5_TDII_2024 _STM32F401/Drivers/API/Inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f401ccux.d ./Core/Startup/startup_stm32f401ccux.o

.PHONY: clean-Core-2f-Startup

