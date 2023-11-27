/*******************************************************************************
* File Name: UanMS.h
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
#if !defined(CY_ISR_UanMS_H)
#define CY_ISR_UanMS_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void UanMS_Start(void);
void UanMS_StartEx(cyisraddress address);
void UanMS_Stop(void);

CY_ISR_PROTO(UanMS_Interrupt);

void UanMS_SetVector(cyisraddress address);
cyisraddress UanMS_GetVector(void);

void UanMS_SetPriority(uint8 priority);
uint8 UanMS_GetPriority(void);

void UanMS_Enable(void);
uint8 UanMS_GetState(void);
void UanMS_Disable(void);

void UanMS_SetPending(void);
void UanMS_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the UanMS ISR. */
#define UanMS_INTC_VECTOR            ((reg32 *) UanMS__INTC_VECT)

/* Address of the UanMS ISR priority. */
#define UanMS_INTC_PRIOR             ((reg8 *) UanMS__INTC_PRIOR_REG)

/* Priority of the UanMS interrupt. */
#define UanMS_INTC_PRIOR_NUMBER      UanMS__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable UanMS interrupt. */
#define UanMS_INTC_SET_EN            ((reg32 *) UanMS__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the UanMS interrupt. */
#define UanMS_INTC_CLR_EN            ((reg32 *) UanMS__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the UanMS interrupt state to pending. */
#define UanMS_INTC_SET_PD            ((reg32 *) UanMS__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the UanMS interrupt. */
#define UanMS_INTC_CLR_PD            ((reg32 *) UanMS__INTC_CLR_PD_REG)


#endif /* CY_ISR_UanMS_H */


/* [] END OF FILE */
