/*
 * API_debounce.c
 *
 *  Created on: Nov 6, 2024
 *      Author: Grupo 3_TD2	Enrique Emanuel Decima, Castro Oscar Martin, Ortiz Nicolas Agustin
 */

#include "main.h"
#include "API_debounce.h"
#include "API_Delay.h"

typedef enum {
	BUTTON_UP ,
	BUTTON_FALLING ,
	BUTTON_DOWN ,
	BUTTON_RISING
} debounceState_t;

delay_t debounce_timer;		//Delay del antirrebote
debounceState_t estado_btn;	//Instancicion de la maquina de estado
bool_t lectura_btn;			//Lectura del boton a devolver al usuario


/*
 * @brief Inicializacion de la MEF, establece la duracion del antirebote
 * @param None
 * @retval None
 */
void debounceFSM_Init(){
	delayInit(&debounce_timer, 40);
	estado_btn = BUTTON_UP;
	lectura_btn = false;
	writeLedOff_GPIO(LD1_Pin);
	writeLedOff_GPIO(LD2_Pin);
	writeLedOff_GPIO(LD3_Pin);
}

/*
 * @brief Actualizacion de los estados
 * @param None
 * @retval None
 */
void debounceFSM_Update(){
	switch(estado_btn){
	case BUTTON_UP:
		if(readButton_GPIO()){
			estado_btn = BUTTON_FALLING;
		}
		break;
	case BUTTON_FALLING:
		if(delayRead(&debounce_timer)){
			if(readButton_GPIO()){
				lectura_btn = true;
				estado_btn = BUTTON_DOWN;
			}else{
				estado_btn = BUTTON_UP;
			}
		}
		break;
	case BUTTON_DOWN:
		if(!readButton_GPIO()){
			estado_btn = BUTTON_RISING;
		}
		break;
	case BUTTON_RISING:
		if(delayRead(&debounce_timer)){
			if(!readButton_GPIO()){
				estado_btn = BUTTON_UP;
			}else{
				estado_btn = BUTTON_DOWN;
			}
		}
		break;
	default:
		Error_Handler();
		break;
	}
}

/*
 * @brief Devuelve la lectura del boton
 * @param None
 * @retval bool_t :	true-> boton pulsado ; false -> boton soltado
 */
bool_t readKey(){
	if(lectura_btn){
		lectura_btn = false;
		return true;
	}else{
		return false;
	}
}
