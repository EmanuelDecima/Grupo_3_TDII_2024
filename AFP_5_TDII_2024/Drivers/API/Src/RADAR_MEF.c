/*
 * RADAR_MEF.c
 *
 *  Created on: Feb 14, 2025
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agustin
 */

#include "RADAR_MEF.h"

typedef enum {
	INICIO,
	MOVER_SERVO,
	MEDIR_DISTANCIA,
	VERIFICAR_ANGULO,
	ALERTA
} MefState_t;

MefState_t MEF_Actual;	//Variable de estado global

//Servomotor
uint8_t motor_angle;
bool sentido_giro;	// 0 = horario ; 1 = Antihorario

//HCSR04
distance_t distancia;
distance_t umbral;

void MEF_Init(){
	MEF_Actual = INICIO;
}

void MEF_Update(){
	switch(MEF_Actual){
	case INICIO:
		motor_angle = 0;
		sentido_giro = 0;
		umbral = 7;		//¿Consultar al usuario?
		distancia = 0;
		MEF_Actual = MOVER_SERVO;
		break;

	case MOVER_SERVO:
		if(sentido_giro){
			motor_angle--;		//Periodo: 1min:38s ; Giro muy lento ¿Aumentar?
		}else{
			motor_angle++;
		}
		MEF_Actual = MEDIR_DISTANCIA;
		break;

	case MEDIR_DISTANCIA:
		distancia = HCSR04_GetMeasure();
		if(distancia < umbral){
			MEF_Actual = ALERTA;
		}else{
			MEF_Actual = VERIFICAR_ANGULO;
		}
		break;

	case VERIFICAR_ANGULO:
		if(motor_angle == 180){
			sentido_giro = 1;
		}
		if(motor_angle == 0){
			sentido_giro = 0;
		}
		if(motor_angle > 180 || motor_angle < 0){
			Error_Handler();	//Reemplazar por una rutina de errores
		}
		MEF_Actual = MOVER_SERVO;
		break;

	case ALERTA:
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, 1);		//Crear Procedimiento para ALARMA
		HC05_SendString("ALARMA:OBJETO DETECTADO \n");
		HAL_Delay(500);
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, 0);
		HC05_SendString("ALARMA:OBJETO DETECTADO \n");
		HAL_Delay(500);
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, 1);
		HC05_SendString("ALARMA:OBJETO DETECTADO \n");
		HAL_Delay(500);
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, 0);

		MEF_Actual = MEDIR_DISTANCIA;
		break;

	default:
		MEF_Actual = INICIO;
		break;

	}
}


