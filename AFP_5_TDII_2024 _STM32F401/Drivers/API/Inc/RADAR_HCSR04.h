/*
 * RADAR_HCSR04.h
 *
 *  Created on: Feb 17, 2025
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agustin
 */

#ifndef API_INC_RADAR_HCSR04_H_
#define API_INC_RADAR_HCSR04_H_

#include "Headers.h"

extern TIM_HandleTypeDef htim1;

void HCSR04_Init();
uint8_t HCSR04_GetMeasure();

#endif /* API_INC_RADAR_HCSR04_H_ */
