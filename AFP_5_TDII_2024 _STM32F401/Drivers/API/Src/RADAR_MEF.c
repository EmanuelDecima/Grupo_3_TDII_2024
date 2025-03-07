/*
 * RADAR_MEF.c
 *
 *  Created on: Feb 14, 2025
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agustin
 */

#include "RADAR_MEF.h"

#define VEL_MOTOR 3

typedef enum {
	INICIO,
	MOVER_SERVO,
	MEDIR_DISTANCIA,
	VERIFICAR_ANGULO,
	ALERTA
} MefState_t;

MefState_t MEF_Actual;	//Variable de estado global
bool alarm_on;

//Servomotor
uint8_t motor_angle;
bool sentido_giro;	// 0 = horario ; 1 = Antihorario

//HCSR04
uint8_t distancia;
uint8_t umbral;	//Predefinido en el estado "INICIO"

void MEF_Init(){
	MEF_Actual = INICIO;
}


uint8_t MEF_GetDistance(){
	return distancia;
}

uint8_t MEF_GetAngle(){
	return motor_angle;
}

bool MEF_GetAlarmState(){
	return alarm_on;
}

void MEF_Update(){
	switch(MEF_Actual){
	case INICIO:

		//Valores Iniciales de Variables
		motor_angle = 0;
		sentido_giro = 0;
		umbral = 7;
		distancia = 10;
		alarm_on = 0;

		Servo_SetAngle(&htim3, TIM_CHANNEL_1, motor_angle);
		Secuencia_Inicio();

		MEF_Actual = MOVER_SERVO;
		break;

	case MOVER_SERVO:
		if(sentido_giro){
			motor_angle = motor_angle - VEL_MOTOR;
		}else{
			motor_angle = motor_angle + VEL_MOTOR;
		}
		Servo_SetAngle(&htim3, TIM_CHANNEL_1, motor_angle);

		MEF_Actual = MEDIR_DISTANCIA;
		break;

	case MEDIR_DISTANCIA:
		distancia = HCSR04_GetMeasure();
		if(distancia < umbral){
			MEF_Actual = ALERTA;
		}else{
			alarm_on = 0;
			HAL_GPIO_WritePin(LED_ALARM_GPIO_Port, LED_ALARM_Pin, 0);
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
			Error_Handler();
		}
		MEF_Actual = MOVER_SERVO;
		break;

	case ALERTA:
		alarm_on = 1;
		Mensaje_Alerta();
		MEF_Actual = MEDIR_DISTANCIA;
		break;

	default:
		MEF_Actual = INICIO;
		break;

	}
}
