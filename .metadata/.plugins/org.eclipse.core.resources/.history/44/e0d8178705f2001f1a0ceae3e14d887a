/*
 * RADAR_LCD.c
 *
 *  Created on: Feb 22, 2025
 *      Author: EmanuelDecima
 */

#include "main.h"
#include "RADAR_LCD.h"

extern I2C_HandleTypeDef hi2c1;

#define SLAVE_ADDRESS_LCD 0x4E /* La direccion es de 7 bits segguida del bit R/W*
								* la direccion por defecto es 0x27 -> %010 0111
							    * si le agregamos un 0 en la posicion del LSB que
							    * corresponde a Write (W* = 0) se forma el valor
							    * 0100 1110 -> 0X4E Esto es para un driver PCF8574 */
/*NOTA si tenemos un driver PCF7584A, su direccion por defecto es 0x3F -> % 111 1111,
 * a la que si le agregamos un 0 en el LSB que corresponde a Write (W* = 0) tendremos
 * el valor % 1111 1110-> 0xFE */

/*Declaration of variables ********************************************************/


/*** Function definition **********************************************************/
void LCD_SendCmd (char cmd)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void LCD_SendData (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=0
	data_t[1] = data_u|0x09;  //en=0, rs=0
	data_t[2] = data_l|0x0D;  //en=1, rs=0
	data_t[3] = data_l|0x09;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void LCD_Clear (void)
{
	LCD_SendCmd(0x80);
	for (int i=0; i<70; i++)
	{
		LCD_SendData(' ');
	}
}

void LCD_PutCur(int row, int col)
{
    switch (row)
    {
        case 0:
            col |= 0x80;
            break;
        case 1:
            col |= 0xC0;
            break;
    }

    LCD_SendCmd(col);
}


void LCD_Init (void)
{
	// 4 bit initialisation
	HAL_Delay(50);  // wait for >40ms
	LCD_SendCmd(0x30);
	HAL_Delay(5);  // wait for >4.1ms
	LCD_SendCmd(0x30);
	HAL_Delay(1);  // wait for >100us
	LCD_SendCmd(0x30);
	HAL_Delay(10);
	LCD_SendCmd(0x20);  // 4bit mode
	HAL_Delay(10);

  // display initialisation
	LCD_SendCmd(0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	HAL_Delay(1);
	LCD_SendCmd(0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
	HAL_Delay(1);
	LCD_SendCmd(0x01);  // clear display
	HAL_Delay(1);
	HAL_Delay(1);
	LCD_SendCmd(0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	HAL_Delay(1);
	LCD_SendCmd(0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
}

void LCD_SendString (char *str)
{
	while (*str) LCD_SendData(*str++);
}

/*** Convertir entero a caracter ***/
void EnteroCad(int n, char cad[])
{
	int nroDig = 0;
	int aux = n;
	while(aux > 0)
	{
		aux = aux/10;
		nroDig++;
	}
	cad[nroDig] = '\0';
	aux = n;
	int pos = nroDig - 1, dig;
	while(pos >= 0)
	{
		dig = aux/10;
		aux = aux/10;
		cad[pos] = dig + '0';
		pos--;
	}
}

