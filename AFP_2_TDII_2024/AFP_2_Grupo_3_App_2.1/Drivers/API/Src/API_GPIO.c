/*
 * API_GPIO.c
 * Created on: Oct 18, 2024
 * Author: agust
 */

#include "API_GPIO.h"
#include "main.h"  // Se incluye el archivo de HAL para utilizar las funciones de GPIO

/* Inicialización de GPIO */
void MX_GPIO_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* Habilitar relojes de los puertos GPIO */
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /* Configurar los pines de los LEDs como salida */
    GPIO_InitStruct.Pin = LD1_Pin | LD2_Pin | LD3_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

/* Alternar el estado de un LED */
void toggleLed_GPIO(led_t led) {
    HAL_GPIO_TogglePin(GPIOB, led);
}

/* Agregar un retardo en milisegundos */
void delay_ms(uint16_t ms) {
    HAL_Delay(ms);  // Utiliza la función HAL_Delay para retardos
}
