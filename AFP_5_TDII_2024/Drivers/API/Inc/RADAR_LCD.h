/*
 * RADAR_LCD.h
 *
 *  Created on: Feb 22, 2025
 *      Author: EmanuelDecima
 */

#ifndef API_INC_RADAR_LCD_H_
#define API_INC_RADAR_LCD_H_

#include "main.h"
/* Exported types ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/

void LCD_Init (void);   // initialize lcd
void LCD_SendCmd (char cmd);  // send command to the lcd
void LCD_SendData (char data);  // send data to the lcd
void LCD_SendString (char *str);  // send string to the lcd
void LCD_PutCur(int row, int col);  // put cursor at the entered position row (0 or 1), col (0-15);
void LCD_Clear (void);
void EnteroCad(int n, char cad[]);



#endif /* API_INC_RADAR_LCD_H_ */
