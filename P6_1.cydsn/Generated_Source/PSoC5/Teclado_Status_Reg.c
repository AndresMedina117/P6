/*******************************************************************************
* File Name: Teclado_Status_Reg.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Teclado_Status_Reg.h"

#if !defined(Teclado_Status_Reg_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: Teclado_Status_Reg_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 Teclado_Status_Reg_Read(void) 
{ 
    return Teclado_Status_Reg_Status;
}


/*******************************************************************************
* Function Name: Teclado_Status_Reg_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Teclado_Status_Reg_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Teclado_Status_Reg_Status_Aux_Ctrl |= Teclado_Status_Reg_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Teclado_Status_Reg_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Teclado_Status_Reg_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Teclado_Status_Reg_Status_Aux_Ctrl &= (uint8)(~Teclado_Status_Reg_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Teclado_Status_Reg_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void Teclado_Status_Reg_WriteMask(uint8 mask) 
{
    #if(Teclado_Status_Reg_INPUTS < 8u)
    	mask &= ((uint8)(1u << Teclado_Status_Reg_INPUTS) - 1u);
	#endif /* End Teclado_Status_Reg_INPUTS < 8u */
    Teclado_Status_Reg_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: Teclado_Status_Reg_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 Teclado_Status_Reg_ReadMask(void) 
{
    return Teclado_Status_Reg_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
