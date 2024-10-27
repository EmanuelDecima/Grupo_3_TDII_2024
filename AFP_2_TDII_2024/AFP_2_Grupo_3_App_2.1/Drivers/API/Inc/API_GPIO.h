/*
 * API_GPIO.h
 * Created on: Oct 18, 2024
 * Author: agust
 */

#ifndef API_INC_API_GPIO_H_
#define API_INC_API_GPIO_H_

#include <stdint.h>

/* Definición del tipo led_t */
typedef uint16_t led_t;

/* Declaración de las funciones del driver */
void MX_GPIO_Init(void);            // Función para inicializar los pines GPIO
void toggleLed_GPIO(led_t led);     // Función para alternar el estado de un LED
void delay_ms(uint16_t ms);         // Función para realizar un retardo en milisegundos

#endif /* API_INC_API_GPIO_H_ */
