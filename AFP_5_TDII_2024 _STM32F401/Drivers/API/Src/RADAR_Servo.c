/*
 * RADAR_Servo.c
 *
 *  Created on: Feb 21, 2025
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agustin
 */
#include "main.h"
#include "RADAR_Servo.h"

void Servo_Init(){
	  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

void Servo_SetAngle(TIM_HandleTypeDef *htim, uint32_t channel, uint8_t angle){
	 	 uint32_t pulse_length = 450 + (angle * (2350 - 450) / 180);
	    __HAL_TIM_SET_COMPARE(htim, channel, pulse_length);
}



