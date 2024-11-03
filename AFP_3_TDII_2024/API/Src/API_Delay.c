/*
 * API_Delay.c
 *
 *  Created on: Nov 3, 2024
 *      Author: Estudiante
 */

#include "main.h"
#include "API_Delay.h"

void delayInit(delay_t * delay, tick_t duration){
	delay->duration = duration;
	delay->running = false;
}

bool_t delayRead(delay_t* delay){
	if(delay->running){
		if ((HAL_GetTick() - delay->startTime) >= delay->duration){
			delay->running = false;
			return true;
		}else{
			return false;
		}
	}else{
		delay->startTime = HAL_GetTick();
		delay->running = true;
		return false;
	}
}

void delayWrite(delay_t* delay, tick_t duration){
	delay->duration = duration;
}
