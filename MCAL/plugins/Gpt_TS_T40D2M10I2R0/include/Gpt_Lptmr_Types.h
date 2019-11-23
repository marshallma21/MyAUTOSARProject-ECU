/**
*   @file    Gpt_Lptmr_Types.h
*   @version 1.0.2
*
*   @brief   AUTOSAR Gpt - LPTMR driver header file.
*   @details LPTMR driver defines which need to be exported to external application
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.2
*   Build Version        : S32K14xS32K14X_MCAL_1_0_2_RTM_ASR_REL_4_2_REV_0002_20190426
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2019 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef GPT_LPTMR_TYPES_H
#define GPT_LPTMR_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Lptmr_Types.h
* @{
*/
#define GPT_LPTMR_TYPES_VENDOR_ID                       43
#define GPT_LPTMR_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define GPT_LPTMR_TYPES_AR_RELEASE_MINOR_VERSION        2
#define GPT_LPTMR_TYPES_AR_RELEASE_REVISION_VERSION     2
#define GPT_LPTMR_TYPES_SW_MAJOR_VERSION                1
#define GPT_LPTMR_TYPES_SW_MINOR_VERSION                0
#define GPT_LPTMR_TYPES_SW_PATCH_VERSION                2
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @{
* @brief LPTMR Channels defines
*/
#define LPTMR_0_CH_0                  ((uint8)0)
/** @} */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*GPT_LPTMR_TYPES_H*/

/** @} */
