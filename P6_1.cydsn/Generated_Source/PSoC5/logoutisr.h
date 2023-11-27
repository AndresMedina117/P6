/*******************************************************************************
* File Name: logoutisr.h
* Version 1.71
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_logoutisr_H)
#define CY_ISR_logoutisr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void logoutisr_Start(void);
void logoutisr_StartEx(cyisraddress address);
void logoutisr_Stop(void);

CY_ISR_PROTO(logoutisr_Interrupt);

void logoutisr_SetVector(cyisraddress address);
cyisraddress logoutisr_GetVector(void);

void logoutisr_SetPriority(uint8 priority);
uint8 logoutisr_GetPriority(void);

void logoutisr_Enable(void);
uint8 logoutisr_GetState(void);
void logoutisr_Disable(void);

void logoutisr_SetPending(void);
void logoutisr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the logoutisr ISR. */
#define logoutisr_INTC_VECTOR            ((reg32 *) logoutisr__INTC_VECT)

/* Address of the logoutisr ISR priority. */
#define logoutisr_INTC_PRIOR             ((reg8 *) logoutisr__INTC_PRIOR_REG)

/* Priority of the logoutisr interrupt. */
#define logoutisr_INTC_PRIOR_NUMBER      logoutisr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable logoutisr interrupt. */
#define logoutisr_INTC_SET_EN            ((reg32 *) logoutisr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the logoutisr interrupt. */
#define logoutisr_INTC_CLR_EN            ((reg32 *) logoutisr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the logoutisr interrupt state to pending. */
#define logoutisr_INTC_SET_PD            ((reg32 *) logoutisr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the logoutisr interrupt. */
#define logoutisr_INTC_CLR_PD            ((reg32 *) logoutisr__INTC_CLR_PD_REG)


#endif /* CY_ISR_logoutisr_H */


/* [] END OF FILE */
