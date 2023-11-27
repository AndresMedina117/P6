/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/* [] END OF FILE */

#include "project.h"

void Teclado_Start(void){
    Teclado_Row_Write(0b1111);
    Teclado_Column_Write(0b0000);
    }

uint8 Teclado_AsignarTecla(void)
{
    uint8 Teclado_Key[4][4] = {
		{1,2,3,'A'},//Row 1
		{4,5,6,'B'},//Row 2
		{7,8,9,'C'},//Row 3
		{'*',0,'#','D'}//Row 4
  	};
    
	uint8 Button;
	uint8 fila,columna;
    fila = (Teclado_Status_Reg_Read() & 0b11); //Row extract
    //Search for row
    Teclado_Column_Write(0b1111);
    Teclado_Row_Write(0b0000);
     CyDelayUs(10);
    
    columna = ((Teclado_Status_Reg_Read() & 0b1100) >> 2);
    //Back to normal
    Teclado_Row_Write(0b1111);
    Teclado_Column_Write(0b0000);
    CyDelayUs(10);
	Button=Teclado_Key[fila][columna];//Assign Character
	return Button;
}
