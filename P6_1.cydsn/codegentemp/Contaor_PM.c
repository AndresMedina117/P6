/*******************************************************************************
* File Name: Contaor_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Contaor.h"

static Contaor_backupStruct Contaor_backup;


/*******************************************************************************
* Function Name: Contaor_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Contaor_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Contaor_SaveConfig(void) 
{
    #if (!Contaor_UsingFixedFunction)

        Contaor_backup.CounterUdb = Contaor_ReadCounter();

        #if(!Contaor_ControlRegRemoved)
            Contaor_backup.CounterControlRegister = Contaor_ReadControlRegister();
        #endif /* (!Contaor_ControlRegRemoved) */

    #endif /* (!Contaor_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Contaor_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Contaor_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Contaor_RestoreConfig(void) 
{      
    #if (!Contaor_UsingFixedFunction)

       Contaor_WriteCounter(Contaor_backup.CounterUdb);

        #if(!Contaor_ControlRegRemoved)
            Contaor_WriteControlRegister(Contaor_backup.CounterControlRegister);
        #endif /* (!Contaor_ControlRegRemoved) */

    #endif /* (!Contaor_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Contaor_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Contaor_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Contaor_Sleep(void) 
{
    #if(!Contaor_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Contaor_CTRL_ENABLE == (Contaor_CONTROL & Contaor_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Contaor_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Contaor_backup.CounterEnableState = 0u;
        }
    #else
        Contaor_backup.CounterEnableState = 1u;
        if(Contaor_backup.CounterEnableState != 0u)
        {
            Contaor_backup.CounterEnableState = 0u;
        }
    #endif /* (!Contaor_ControlRegRemoved) */
    
    Contaor_Stop();
    Contaor_SaveConfig();
}


/*******************************************************************************
* Function Name: Contaor_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Contaor_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Contaor_Wakeup(void) 
{
    Contaor_RestoreConfig();
    #if(!Contaor_ControlRegRemoved)
        if(Contaor_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Contaor_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Contaor_ControlRegRemoved) */
    
}


/* [] END OF FILE */
