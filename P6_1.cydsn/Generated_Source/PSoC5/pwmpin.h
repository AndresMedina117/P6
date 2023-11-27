/*******************************************************************************
* File Name: pwmpin.h  
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

#if !defined(CY_PINS_pwmpin_H) /* Pins pwmpin_H */
#define CY_PINS_pwmpin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pwmpin_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pwmpin__PORT == 15 && ((pwmpin__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pwmpin_Write(uint8 value);
void    pwmpin_SetDriveMode(uint8 mode);
uint8   pwmpin_ReadDataReg(void);
uint8   pwmpin_Read(void);
void    pwmpin_SetInterruptMode(uint16 position, uint16 mode);
uint8   pwmpin_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pwmpin_SetDriveMode() function.
     *  @{
     */
        #define pwmpin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pwmpin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pwmpin_DM_RES_UP          PIN_DM_RES_UP
        #define pwmpin_DM_RES_DWN         PIN_DM_RES_DWN
        #define pwmpin_DM_OD_LO           PIN_DM_OD_LO
        #define pwmpin_DM_OD_HI           PIN_DM_OD_HI
        #define pwmpin_DM_STRONG          PIN_DM_STRONG
        #define pwmpin_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pwmpin_MASK               pwmpin__MASK
#define pwmpin_SHIFT              pwmpin__SHIFT
#define pwmpin_WIDTH              1u

/* Interrupt constants */
#if defined(pwmpin__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pwmpin_SetInterruptMode() function.
     *  @{
     */
        #define pwmpin_INTR_NONE      (uint16)(0x0000u)
        #define pwmpin_INTR_RISING    (uint16)(0x0001u)
        #define pwmpin_INTR_FALLING   (uint16)(0x0002u)
        #define pwmpin_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pwmpin_INTR_MASK      (0x01u) 
#endif /* (pwmpin__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pwmpin_PS                     (* (reg8 *) pwmpin__PS)
/* Data Register */
#define pwmpin_DR                     (* (reg8 *) pwmpin__DR)
/* Port Number */
#define pwmpin_PRT_NUM                (* (reg8 *) pwmpin__PRT) 
/* Connect to Analog Globals */                                                  
#define pwmpin_AG                     (* (reg8 *) pwmpin__AG)                       
/* Analog MUX bux enable */
#define pwmpin_AMUX                   (* (reg8 *) pwmpin__AMUX) 
/* Bidirectional Enable */                                                        
#define pwmpin_BIE                    (* (reg8 *) pwmpin__BIE)
/* Bit-mask for Aliased Register Access */
#define pwmpin_BIT_MASK               (* (reg8 *) pwmpin__BIT_MASK)
/* Bypass Enable */
#define pwmpin_BYP                    (* (reg8 *) pwmpin__BYP)
/* Port wide control signals */                                                   
#define pwmpin_CTL                    (* (reg8 *) pwmpin__CTL)
/* Drive Modes */
#define pwmpin_DM0                    (* (reg8 *) pwmpin__DM0) 
#define pwmpin_DM1                    (* (reg8 *) pwmpin__DM1)
#define pwmpin_DM2                    (* (reg8 *) pwmpin__DM2) 
/* Input Buffer Disable Override */
#define pwmpin_INP_DIS                (* (reg8 *) pwmpin__INP_DIS)
/* LCD Common or Segment Drive */
#define pwmpin_LCD_COM_SEG            (* (reg8 *) pwmpin__LCD_COM_SEG)
/* Enable Segment LCD */
#define pwmpin_LCD_EN                 (* (reg8 *) pwmpin__LCD_EN)
/* Slew Rate Control */
#define pwmpin_SLW                    (* (reg8 *) pwmpin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pwmpin_PRTDSI__CAPS_SEL       (* (reg8 *) pwmpin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pwmpin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pwmpin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pwmpin_PRTDSI__OE_SEL0        (* (reg8 *) pwmpin__PRTDSI__OE_SEL0) 
#define pwmpin_PRTDSI__OE_SEL1        (* (reg8 *) pwmpin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pwmpin_PRTDSI__OUT_SEL0       (* (reg8 *) pwmpin__PRTDSI__OUT_SEL0) 
#define pwmpin_PRTDSI__OUT_SEL1       (* (reg8 *) pwmpin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pwmpin_PRTDSI__SYNC_OUT       (* (reg8 *) pwmpin__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pwmpin__SIO_CFG)
    #define pwmpin_SIO_HYST_EN        (* (reg8 *) pwmpin__SIO_HYST_EN)
    #define pwmpin_SIO_REG_HIFREQ     (* (reg8 *) pwmpin__SIO_REG_HIFREQ)
    #define pwmpin_SIO_CFG            (* (reg8 *) pwmpin__SIO_CFG)
    #define pwmpin_SIO_DIFF           (* (reg8 *) pwmpin__SIO_DIFF)
#endif /* (pwmpin__SIO_CFG) */

/* Interrupt Registers */
#if defined(pwmpin__INTSTAT)
    #define pwmpin_INTSTAT            (* (reg8 *) pwmpin__INTSTAT)
    #define pwmpin_SNAP               (* (reg8 *) pwmpin__SNAP)
    
	#define pwmpin_0_INTTYPE_REG 		(* (reg8 *) pwmpin__0__INTTYPE)
#endif /* (pwmpin__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pwmpin_H */


/* [] END OF FILE */
