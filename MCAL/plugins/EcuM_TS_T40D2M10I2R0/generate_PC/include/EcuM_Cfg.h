/**
*   @file    EcuM_Cfg.h
*   @version 1.0.2
*
*   @brief   AUTOSAR EcuM - module configuration parameters file
*   @details This file contains the generated configuration parameters for the AUTOSAR EcuM.
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup ECUM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : 
*   Dependencies         : 
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
#ifndef ECUM_CFG_H
#define ECUM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ECUM_CFG_VENDOR_ID 43
#define ECUM_CFG_MODULE_ID 10

#define ECUM_CFG_AR_RELEASE_MAJOR_VERSION 4
#define ECUM_CFG_AR_RELEASE_MINOR_VERSION 2
#define ECUM_CFG_AR_RELEASE_REVISION_VERSION 2
#define ECUM_CFG_SW_MAJOR_VERSION 1
#define ECUM_CFG_SW_MINOR_VERSION 0
#define ECUM_CFG_SW_PATCH_VERSION 2

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
 *                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/* ========= user defined wakeup sources ========= */
[!LOOP "EcuMConfiguration"!]
[!LOOP "EcuMCommonConfiguration/EcuMWakeupSource/*"!]
#if (defined EcuMConf_EcuMWakeupSource_[!"node:name('.')"!]) /* to prevent double declaration */
#error EcuMConf_EcuMWakeupSource_[!"node:name('.')"!] already defined
#endif
/** @brief Identifier for wakeup source [!"node:name('.')"!]*/
#define EcuMConf_EcuMWakeupSource_[!"node:name('.')"!] ((uint32)((uint32)1U<<[!"node:value('./EcuMWakeupSourceId')"!]))
[!ENDLOOP!]
[!ENDLOOP!]

/* ======== Sleep modes ======== */
[!LOOP "EcuMConfiguration"!]
[!LOOP "EcuMCommonConfiguration/EcuMSleepMode/*"!]
#if (defined EcuMConf_EcuMSleepMode_[!"node:name('.')"!]) /* to prevent double declaration */
#error EcuMConf_EcuMSleepMode_[!"node:name('.')"!] already defined
#endif
/** @brief Identifier for wakeup source [!"node:name('.')"!]*/
#define EcuMConf_EcuMSleepMode_[!"node:name('.')"!] [!"num:inttohex(node:value('./EcuMSleepModeId'))"!]U
[!ENDLOOP!]
[!ENDLOOP!]
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uint32 EcuM_WakeupSourceType; /**< @brief variable type for ECU Manager wakeup sources*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* ECUM_CFG_H */

/** @} */
