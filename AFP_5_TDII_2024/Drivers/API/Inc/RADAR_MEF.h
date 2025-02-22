/*
 * RADAR_MEF.h
 *
 *  Created on: Feb 14, 2025
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agustin
 */

#ifndef API_INC_RADAR_MEF_H_
#define API_INC_RADAR_MEF_H_

#include <stdbool.h>
#include "main.h"
#include "RADAR_HC05.h"
#include "RADAR_Delay.h"
#include "RADAR_GPIO.h"
#include "RADAR_HCSR04.h"
#include "RADAR_Servo.h"

void MEF_Init();
void MEF_Update();

#endif /* API_INC_RADAR_MEF_H_ */
