/*
 * API_GPIO.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agusti­n
 */

/*	Includes	*/

#include "main.h"
#include "API_GPIO.h"

/*	Variables	*/

led_t LDx;

/*	Implementacion de Funciones	*/

void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(USB_PowerSwitchOn_GPIO_Port, USB_PowerSwitchOn_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : USER_Btn_Pin */
  GPIO_InitStruct.Pin = USER_Btn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_Btn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD1_Pin LD3_Pin LD2_Pin */
  GPIO_InitStruct.Pin = LD1_Pin|LD3_Pin|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_PowerSwitchOn_Pin */
  GPIO_InitStruct.Pin = USB_PowerSwitchOn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(USB_PowerSwitchOn_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_OverCurrent_Pin */
  GPIO_InitStruct.Pin = USB_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_OverCurrent_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}


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
