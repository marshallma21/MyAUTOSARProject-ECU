/**
*   @file    CanIf_Types.h
*   @version 1.0.2
*
*   @brief   AUTOSAR CanIf - CanIf module interface
*   @details AUTOSAR CanIf module interface.- Stub Version
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup CANIF_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : generic
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
#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"

/**
* @brief          CanIf_ControllerModeType
* @details        Operating modes of the CAN Controller and CAN Driver
*
*/
typedef enum
    {
        CANIF_CS_UNINIT = 0U,    /**< @brief UNINIT mode */
        CANIF_CS_SLEEP,         /**< @brief SLEEP mode */
        CANIF_CS_STARTED,        /**< @brief STARTED mode */
        CANIF_CS_STOPPED        /**< @brief STOPPED mode */
    } CanIf_ControllerModeType;
      
#ifdef __cplusplus
}
#endif

#endif 
