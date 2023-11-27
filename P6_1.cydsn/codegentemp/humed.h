/*******************************************************************************
* File Name: humed.h  
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

#if !defined(CY_PINS_humed_H) /* Pins humed_H */
#define CY_PINS_humed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "humed_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 humed__PORT == 15 && ((humed__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    humed_Write(uint8 value);
void    humed_SetDriveMode(uint8 mode);
uint8   humed_ReadDataReg(void);
uint8   humed_Read(void);
void    humed_SetInterruptMode(uint16 position, uint16 mode);
uint8   humed_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the humed_SetDriveMode() function.
     *  @{
     */
        #define humed_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define humed_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define humed_DM_RES_UP          PIN_DM_RES_UP
        #define humed_DM_RES_DWN         PIN_DM_RES_DWN
        #define humed_DM_OD_LO           PIN_DM_OD_LO
        #define humed_DM_OD_HI           PIN_DM_OD_HI
        #define humed_DM_STRONG          PIN_DM_STRONG
        #define humed_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define humed_MASK               humed__MASK
#define humed_SHIFT              humed__SHIFT
#define humed_WIDTH              1u

/* Interrupt constants */
#if defined(humed__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in humed_SetInterruptMode() function.
     *  @{
     */
        #define humed_INTR_NONE      (uint16)(0x0000u)
        #define humed_INTR_RISING    (uint16)(0x0001u)
        #define humed_INTR_FALLING   (uint16)(0x0002u)
        #define humed_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define humed_INTR_MASK      (0x01u) 
#endif /* (humed__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define humed_PS                     (* (reg8 *) humed__PS)
/* Data Register */
#define humed_DR                     (* (reg8 *) humed__DR)
/* Port Number */
#define humed_PRT_NUM                (* (reg8 *) humed__PRT) 
/* Connect to Analog Globals */                                                  
#define humed_AG                     (* (reg8 *) humed__AG)                       
/* Analog MUX bux enable */
#define humed_AMUX                   (* (reg8 *) humed__AMUX) 
/* Bidirectional Enable */                                                        
#define humed_BIE                    (* (reg8 *) humed__BIE)
/* Bit-mask for Aliased Register Access */
#define humed_BIT_MASK               (* (reg8 *) humed__BIT_MASK)
/* Bypass Enable */
#define humed_BYP                    (* (reg8 *) humed__BYP)
/* Port wide control signals */                                                   
#define humed_CTL                    (* (reg8 *) humed__CTL)
/* Drive Modes */
#define humed_DM0                    (* (reg8 *) humed__DM0) 
#define humed_DM1                    (* (reg8 *) humed__DM1)
#define humed_DM2                    (* (reg8 *) humed__DM2) 
/* Input Buffer Disable Override */
#define humed_INP_DIS                (* (reg8 *) humed__INP_DIS)
/* LCD Common or Segment Drive */
#define humed_LCD_COM_SEG            (* (reg8 *) humed__LCD_COM_SEG)
/* Enable Segment LCD */
#define humed_LCD_EN                 (* (reg8 *) humed__LCD_EN)
/* Slew Rate Control */
#define humed_SLW                    (* (reg8 *) humed__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define humed_PRTDSI__CAPS_SEL       (* (reg8 *) humed__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define humed_PRTDSI__DBL_SYNC_IN    (* (reg8 *) humed__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define humed_PRTDSI__OE_SEL0        (* (reg8 *) humed__PRTDSI__OE_SEL0) 
#define humed_PRTDSI__OE_SEL1        (* (reg8 *) humed__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define humed_PRTDSI__OUT_SEL0       (* (reg8 *) humed__PRTDSI__OUT_SEL0) 
#define humed_PRTDSI__OUT_SEL1       (* (reg8 *) humed__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define humed_PRTDSI__SYNC_OUT       (* (reg8 *) humed__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(humed__SIO_CFG)
    #define humed_SIO_HYST_EN        (* (reg8 *) humed__SIO_HYST_EN)
    #define humed_SIO_REG_HIFREQ     (* (reg8 *) humed__SIO_REG_HIFREQ)
    #define humed_SIO_CFG            (* (reg8 *) humed__SIO_CFG)
    #define humed_SIO_DIFF           (* (reg8 *) humed__SIO_DIFF)
#endif /* (humed__SIO_CFG) */

/* Interrupt Registers */
#if defined(humed__INTSTAT)
    #define humed_INTSTAT            (* (reg8 *) humed__INTSTAT)
    #define humed_SNAP               (* (reg8 *) humed__SNAP)
    
	#define humed_0_INTTYPE_REG 		(* (reg8 *) humed__0__INTTYPE)
#endif /* (humed__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_humed_H */


/* [] END OF FILE */
