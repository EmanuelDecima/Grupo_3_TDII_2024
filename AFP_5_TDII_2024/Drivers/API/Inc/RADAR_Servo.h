/*
 * RADAR_Servo.h
 *
 *  Created on: Feb 21, 2025
 *      Author: Oscar
 */

#ifndef API_INC_RADAR_SERVO_H_
#define API_INC_RADAR_SERVO_H_

extern TIM_HandleTypeDef htim2;

void Servo_Init();
void Set_Servo_Angle(TIM_HandleTypeDef *htim, uint32_t channel, uint8_t angle);

#endif /* API_INC_RADAR_SERVO_H_ */
