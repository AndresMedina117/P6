/*******************************************************************************
* File Name: unlog.h  
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

#if !defined(CY_PINS_unlog_H) /* Pins unlog_H */
#define CY_PINS_unlog_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "unlog_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 unlog__PORT == 15 && ((unlog__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    unlog_Write(uint8 value);
void    unlog_SetDriveMode(uint8 mode);
uint8   unlog_ReadDataReg(void);
uint8   unlog_Read(void);
void    unlog_SetInterruptMode(uint16 position, uint16 mode);
uint8   unlog_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the unlog_SetDriveMode() function.
     *  @{
     */
        #define unlog_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define unlog_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define unlog_DM_RES_UP          PIN_DM_RES_UP
        #define unlog_DM_RES_DWN         PIN_DM_RES_DWN
        #define unlog_DM_OD_LO           PIN_DM_OD_LO
        #define unlog_DM_OD_HI           PIN_DM_OD_HI
        #define unlog_DM_STRONG          PIN_DM_STRONG
        #define unlog_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define unlog_MASK               unlog__MASK
#define unlog_SHIFT              unlog__SHIFT
#define unlog_WIDTH              1u

/* Interrupt constants */
#if defined(unlog__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in unlog_SetInterruptMode() function.
     *  @{
     */
        #define unlog_INTR_NONE      (uint16)(0x0000u)
        #define unlog_INTR_RISING    (uint16)(0x0001u)
        #define unlog_INTR_FALLING   (uint16)(0x0002u)
        #define unlog_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define unlog_INTR_MASK      (0x01u) 
#endif /* (unlog__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define unlog_PS                     (* (reg8 *) unlog__PS)
/* Data Register */
#define unlog_DR                     (* (reg8 *) unlog__DR)
/* Port Number */
#define unlog_PRT_NUM                (* (reg8 *) unlog__PRT) 
/* Connect to Analog Globals */                                                  
#define unlog_AG                     (* (reg8 *) unlog__AG)                       
/* Analog MUX bux enable */
#define unlog_AMUX                   (* (reg8 *) unlog__AMUX) 
/* Bidirectional Enable */                                                        
#define unlog_BIE                    (* (reg8 *) unlog__BIE)
/* Bit-mask for Aliased Register Access */
#define unlog_BIT_MASK               (* (reg8 *) unlog__BIT_MASK)
/* Bypass Enable */
#define unlog_BYP                    (* (reg8 *) unlog__BYP)
/* Port wide control signals */                                                   
#define unlog_CTL                    (* (reg8 *) unlog__CTL)
/* Drive Modes */
#define unlog_DM0                    (* (reg8 *) unlog__DM0) 
#define unlog_DM1                    (* (reg8 *) unlog__DM1)
#define unlog_DM2                    (* (reg8 *) unlog__DM2) 
/* Input Buffer Disable Override */
#define unlog_INP_DIS                (* (reg8 *) unlog__INP_DIS)
/* LCD Common or Segment Drive */
#define unlog_LCD_COM_SEG            (* (reg8 *) unlog__LCD_COM_SEG)
/* Enable Segment LCD */
#define unlog_LCD_EN                 (* (reg8 *) unlog__LCD_EN)
/* Slew Rate Control */
#define unlog_SLW                    (* (reg8 *) unlog__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define unlog_PRTDSI__CAPS_SEL       (* (reg8 *) unlog__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define unlog_PRTDSI__DBL_SYNC_IN    (* (reg8 *) unlog__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define unlog_PRTDSI__OE_SEL0        (* (reg8 *) unlog__PRTDSI__OE_SEL0) 
#define unlog_PRTDSI__OE_SEL1        (* (reg8 *) unlog__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define unlog_PRTDSI__OUT_SEL0       (* (reg8 *) unlog__PRTDSI__OUT_SEL0) 
#define unlog_PRTDSI__OUT_SEL1       (* (reg8 *) unlog__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define unlog_PRTDSI__SYNC_OUT       (* (reg8 *) unlog__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(unlog__SIO_CFG)
    #define unlog_SIO_HYST_EN        (* (reg8 *) unlog__SIO_HYST_EN)
    #define unlog_SIO_REG_HIFREQ     (* (reg8 *) unlog__SIO_REG_HIFREQ)
    #define unlog_SIO_CFG            (* (reg8 *) unlog__SIO_CFG)
    #define unlog_SIO_DIFF           (* (reg8 *) unlog__SIO_DIFF)
#endif /* (unlog__SIO_CFG) */

/* Interrupt Registers */
#if defined(unlog__INTSTAT)
    #define unlog_INTSTAT            (* (reg8 *) unlog__INTSTAT)
    #define unlog_SNAP               (* (reg8 *) unlog__SNAP)
    
	#define unlog_0_INTTYPE_REG 		(* (reg8 *) unlog__0__INTTYPE)
#endif /* (unlog__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_unlog_H */


/* [] END OF FILE */
