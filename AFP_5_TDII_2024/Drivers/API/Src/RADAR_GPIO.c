/*
 * API_GPIO.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agusti­n
 */

/*	Includes	*/

#include "RADAR_GPIO.h"
#include "main.h"

/*	Variables	*/

led_t LDx;

/*	Implementacion de Funciones	*/

/*
 * @brief Funcion para encender el Led
 * @param led_t LDx
 * @retval None
 */

void writeLedOn_GPIO(led_t LDx){
	HAL_GPIO_WritePin(GPIOB, LDx, GPIO_PIN_SET);
}


/*
 * @brief Funcion para apagar el Led
 * @param led_t LDx
 * @retval None
 */
void writeLedOff_GPIO(led_t LDx){
	HAL_GPIO_WritePin(GPIOB, LDx, GPIO_PIN_RESET);
}

/*
 * @brief Funcion para cambiar el estado del Led
 * @param led_t LDx
 * @retval None
 */
void toggleLed_GPIO(led_t LDx){
	HAL_GPIO_TogglePin(GPIOB, LDx);
}

/*
 * @brief Funcion para leer el Boton
 * @param None
 * @retval buttonStatus_t Button Status: True -> Presionado, False -> Sin presionar
 */
buttonStatus_t readButton_GPIO(void){
	return HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin);
}
