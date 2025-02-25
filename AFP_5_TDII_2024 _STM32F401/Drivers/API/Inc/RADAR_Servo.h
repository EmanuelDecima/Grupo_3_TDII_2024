/*
 * RADAR_Servo.h
 *
 *  Created on: Feb 21, 2025
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agustin
 */

#ifndef API_INC_RADAR_SERVO_H_
#define API_INC_RADAR_SERVO_H_

#include "Headers.h"

extern TIM_HandleTypeDef htim3;

void Servo_Init();
void Set_Servo_Angle(TIM_HandleTypeDef *htim, uint32_t channel, uint8_t angle);

#endif /* API_INC_RADAR_SERVO_H_ */
