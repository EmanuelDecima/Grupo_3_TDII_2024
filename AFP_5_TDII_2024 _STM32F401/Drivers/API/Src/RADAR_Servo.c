/*
 * RADAR_Servo.c
 *
 *  Created on: Feb 21, 2025
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agustin
 */
#include "main.h"
#include "RADAR_Servo.h"

/*
 * @brief Inicializa el Timer 3 Canal 1 como Salida PWM (Modulacion por ancho de pulso)
 * 		  Esto permite setear un angulo especifico al servomotor
 * @param None
 * @retval None
 */
void Servo_Init(){
	  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

/*
 * @brief Mediante un calculo especifico, calcula el duty cicle de la señal PWM para
 * 		  un determinado angulo del servomotor y modifica la salida del Timer 3 Canal 1
 * @param None
 * @retval None
 */
void Servo_SetAngle(TIM_HandleTypeDef *htim, uint32_t channel, uint8_t angle){
	 	 uint32_t pulse_length = 450 + (angle * (2350 - 450) / 180);
	    __HAL_TIM_SET_COMPARE(htim, channel, pulse_length);
}
