/*
 * RADAR_SECUENCIAS.c
 *
 *  Created on: Feb 23, 2025
 *      Author: Estudiante
 */
#include "main.h"
#include "RADAR_SECUENCIAS.h"

/*
 * @brief Secuencia al Encender el dispositivo
 * @param None
 * @retval None
 */
void Secuencia_Inicio(){
	//Salidas Digitales
	HAL_GPIO_WritePin(LED_ALARM_GPIO_Port, LED_ALARM_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_ON_GPIO_Port, LED_ON_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);

	//Mensaje por LCD
	LCD_Clear();
	LCD_PutCur(0, 0);
	LCD_SendString("SISTEMA");
	LCD_PutCur(1, 0);
	LCD_SendString("ACTIVADO");

	//Mensaje por Bluetooth
	HC05_SendString("SISTEMA ACTIVADO\n");
	HAL_Delay(3000);
	LCD_Clear();
}

/*
 * @brief Secuencia al detectar un objeto cercano
 * @param None
 * @retval None
 */
void Mensaje_Alerta(){
	//Salidas Digitales
	HAL_GPIO_WritePin(LED_ALARM_GPIO_Port, LED_ALARM_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_SET);
	//Mensaje por LCD
	LCD_Clear();
	LCD_PutCur(0, 0);
	LCD_SendString("ALARMA");
	LCD_PutCur(1, 0);
	LCD_SendString("ACTIVADA!");
	//Mensaje por Bluetooth
	HC05_SendString("ALARMA ACTIVADA: OBJETO DETECTADO\n");
	//BUZZER
	HAL_Delay(500);
	LCD_Clear();
	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
	HAL_Delay(500);
}
