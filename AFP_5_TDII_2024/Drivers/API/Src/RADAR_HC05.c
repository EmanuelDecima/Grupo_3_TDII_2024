/*
 * RADAR_HC05.c
 *
 *  Created on: Feb 14, 2025
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agusti­n
 */


#include "RADAR_HC05.h"


extern UART_HandleTypeDef huart2;

void HC05_SendString(char* message){
	HAL_UART_Transmit(&huart2, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
}

char HC05_ReceiveChar(uint8_t* pBuffer){
	HAL_UART_Receive(&huart2, pBuffer, 1, HAL_MAX_DELAY);
	return *pBuffer;
}

void HC05_SendData(uint8_t data){
	char str[10];
	sprintf(str, "%d", data);
	HAL_UART_Transmit(&huart2, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);
}
