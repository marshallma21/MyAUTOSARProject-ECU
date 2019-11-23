/**
*   @file    Os_counter_api.c
*   @version 1.0.2
*
*   @brief   AUTOSAR Os - Os module interface
*   @details AUTOSAR Os module interface.- Stub Version
*   This file contains sample code only. It is not part of the production code deliverables.
*
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
#include "Os.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
StatusType GetCounterValue (CounterType ctrId, TickRefType tickRef)
{
    return;
}

StatusType GetElapsedValue (CounterType ctrId, TickRefType valueRef, TickRefType tickRef)
{
    return;
}

#ifdef __cplusplus
}
#endif

/** @} */

