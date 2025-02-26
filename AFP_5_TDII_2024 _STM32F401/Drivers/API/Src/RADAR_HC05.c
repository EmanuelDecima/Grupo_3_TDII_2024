/*
 * RADAR_HC05.c
 *
 *  Created on: Feb 14, 2025
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agustin
 */


#include "RADAR_HC05.h"

/*
 * @brief Funcion para enviar una cadena de caracteres por Bluetooth
 * @param char* message
 * @retval None
 */
void HC05_SendString(char* message){
	HAL_UART_Transmit(&huart1, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
}

/*
 * @brief Funcion para enviar un dato numerico por Bluetooth
 * @param uint8_t data
 * @retval None
 */
void HC05_SendData(uint8_t data){
	char str[10];
	sprintf(str, "%d", data);
	HAL_UART_Transmit(&huart1, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);
}
