/*
 * API_Delay.h
 *
 *  Created on: Nov 3, 2024
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agustín
 */

#ifndef API_INC_RADAR_DELAY_H_
#define API_INC_RADAR_DELAY_H_

/*	Includes	*/
#include <stdint.h>
#include <stdbool.h>

/*	Typedefs 	*/
typedef uint32_t tick_t;
typedef bool bool_t;
typedef struct{
	tick_t startTime;
	tick_t duration;
	bool_t running;
} delay_t;

/*	Declaracion de Funciones	*/
void SystemClock_Config(void);
void delayInit(delay_t* delay, tick_t duration);
bool_t delayRead(delay_t* delay);
void delayWrite(delay_t* delay, tick_t duration);

#endif /* API_INC_RADAR_DELAY_H_ */
