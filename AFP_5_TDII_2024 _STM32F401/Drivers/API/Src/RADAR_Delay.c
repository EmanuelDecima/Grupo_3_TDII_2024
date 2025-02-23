/*
 * API_Delay.c
 *
 *  Created on: Nov 3, 2024
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agustin
 */

#include "RADAR_Delay.h"
#include "main.h"


/*
 * @brief Inicializacion del delay, establece la duracion
 * @param delay_t delay, tick_t duration
 * @retval None
 */
void delayInit(delay_t * delay, tick_t duration){
	delay->duration = duration;
	delay->running = false;
}

/*
 * @brief Revisa si ya paso el tiempo correspondiente al delay
 * @param delay_t delay
 * @retval 	false -> No transcurrio el tiempo del delay
 * 			true -> Ya transcurrio el tiempo del delay
 */
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

/*
 * @brief Reescribe el tiempo de duracion
 * @param delay_t delay, tick_t duration
 * @retval None
 */
void delayWrite(delay_t* delay, tick_t duration){
	delay->duration = duration;
}
