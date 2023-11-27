/*******************************************************************************
* File Name: tempe.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_tempe_H) /* Pins tempe_H */
#define CY_PINS_tempe_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "tempe_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 tempe__PORT == 15 && ((tempe__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    tempe_Write(uint8 value);
void    tempe_SetDriveMode(uint8 mode);
uint8   tempe_ReadDataReg(void);
uint8   tempe_Read(void);
void    tempe_SetInterruptMode(uint16 position, uint16 mode);
uint8   tempe_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the tempe_SetDriveMode() function.
     *  @{
     */
        #define tempe_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define tempe_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define tempe_DM_RES_UP          PIN_DM_RES_UP
        #define tempe_DM_RES_DWN         PIN_DM_RES_DWN
        #define tempe_DM_OD_LO           PIN_DM_OD_LO
        #define tempe_DM_OD_HI           PIN_DM_OD_HI
        #define tempe_DM_STRONG          PIN_DM_STRONG
        #define tempe_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define tempe_MASK               tempe__MASK
#define tempe_SHIFT              tempe__SHIFT
#define tempe_WIDTH              1u

/* Interrupt constants */
#if defined(tempe__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in tempe_SetInterruptMode() function.
     *  @{
     */
        #define tempe_INTR_NONE      (uint16)(0x0000u)
        #define tempe_INTR_RISING    (uint16)(0x0001u)
        #define tempe_INTR_FALLING   (uint16)(0x0002u)
        #define tempe_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define tempe_INTR_MASK      (0x01u) 
#endif /* (tempe__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define tempe_PS                     (* (reg8 *) tempe__PS)
/* Data Register */
#define tempe_DR                     (* (reg8 *) tempe__DR)
/* Port Number */
#define tempe_PRT_NUM                (* (reg8 *) tempe__PRT) 
/* Connect to Analog Globals */                                                  
#define tempe_AG                     (* (reg8 *) tempe__AG)                       
/* Analog MUX bux enable */
#define tempe_AMUX                   (* (reg8 *) tempe__AMUX) 
/* Bidirectional Enable */                                                        
#define tempe_BIE                    (* (reg8 *) tempe__BIE)
/* Bit-mask for Aliased Register Access */
#define tempe_BIT_MASK               (* (reg8 *) tempe__BIT_MASK)
/* Bypass Enable */
#define tempe_BYP                    (* (reg8 *) tempe__BYP)
/* Port wide control signals */                                                   
#define tempe_CTL                    (* (reg8 *) tempe__CTL)
/* Drive Modes */
#define tempe_DM0                    (* (reg8 *) tempe__DM0) 
#define tempe_DM1                    (* (reg8 *) tempe__DM1)
#define tempe_DM2                    (* (reg8 *) tempe__DM2) 
/* Input Buffer Disable Override */
#define tempe_INP_DIS                (* (reg8 *) tempe__INP_DIS)
/* LCD Common or Segment Drive */
#define tempe_LCD_COM_SEG            (* (reg8 *) tempe__LCD_COM_SEG)
/* Enable Segment LCD */
#define tempe_LCD_EN                 (* (reg8 *) tempe__LCD_EN)
/* Slew Rate Control */
#define tempe_SLW                    (* (reg8 *) tempe__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define tempe_PRTDSI__CAPS_SEL       (* (reg8 *) tempe__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define tempe_PRTDSI__DBL_SYNC_IN    (* (reg8 *) tempe__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define tempe_PRTDSI__OE_SEL0        (* (reg8 *) tempe__PRTDSI__OE_SEL0) 
#define tempe_PRTDSI__OE_SEL1        (* (reg8 *) tempe__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define tempe_PRTDSI__OUT_SEL0       (* (reg8 *) tempe__PRTDSI__OUT_SEL0) 
#define tempe_PRTDSI__OUT_SEL1       (* (reg8 *) tempe__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define tempe_PRTDSI__SYNC_OUT       (* (reg8 *) tempe__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(tempe__SIO_CFG)
    #define tempe_SIO_HYST_EN        (* (reg8 *) tempe__SIO_HYST_EN)
    #define tempe_SIO_REG_HIFREQ     (* (reg8 *) tempe__SIO_REG_HIFREQ)
    #define tempe_SIO_CFG            (* (reg8 *) tempe__SIO_CFG)
    #define tempe_SIO_DIFF           (* (reg8 *) tempe__SIO_DIFF)
#endif /* (tempe__SIO_CFG) */

/* Interrupt Registers */
#if defined(tempe__INTSTAT)
    #define tempe_INTSTAT            (* (reg8 *) tempe__INTSTAT)
    #define tempe_SNAP               (* (reg8 *) tempe__SNAP)
    
	#define tempe_0_INTTYPE_REG 		(* (reg8 *) tempe__0__INTTYPE)
#endif /* (tempe__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_tempe_H */


/* [] END OF FILE */
