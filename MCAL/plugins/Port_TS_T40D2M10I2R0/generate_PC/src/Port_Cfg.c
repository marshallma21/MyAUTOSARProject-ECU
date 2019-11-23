[!CODE!][!//
/**
* @file    Port_Cfg.c
*
* @version 1.0.2
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver precompile configuration.
*
* @addtogroup  Port
* @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : PORT_CI
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_CFG_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*
* @section PORT_CFG_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_CFG_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character signifiance and case sensitivity are supported for external identifiers.
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"
[!NOCODE!][!//
[!INCLUDE "Port_VersionCheck_Inc.m"!][!//
[!/* Include package file in order to get valid Pins */!][!//
[!IF "((ecu:get('PortFamily'))=142)"!][!//
    [!INCLUDE "Port_S32K142_Resource.m"!][!//
[!ELSEIF "((ecu:get('PortFamily'))=144)"!][!//
    [!INCLUDE "Port_S32K144_Resource.m"!][!//
[!ELSEIF "((ecu:get('PortFamily'))=146)"!][!//
    [!INCLUDE "Port_S32K146_Resource.m"!][!//
[!ELSEIF "((ecu:get('PortFamily'))=148)"!][!//
    [!INCLUDE "Port_S32K148_Resource.m"!][!//
[!ELSEIF "((ecu:get('PortFamily'))=118)"!][!//
    [!INCLUDE "Port_S32K118_Resource.m"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module's description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_CFG_C                       43
/** @violates @ref PORT_CFG_REF_3 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_C        4
/** @violates @ref PORT_CFG_REF_3 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_C        2
/** @violates @ref PORT_CFG_REF_3 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_C     2
#define PORT_SW_MAJOR_VERSION_CFG_C                1
#define PORT_SW_MINOR_VERSION_CFG_C                0
#define PORT_SW_PATCH_VERSION_CFG_C                2

/*=================================================================================================
                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if Port_Cfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_CFG_C != PORT_VENDOR_ID)
    #error "Port_Cfg.c and Port.h have different vendor ids"
#endif

/* Check if Port_Cfg.c and Port.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_C != PORT_AR_RELEASE_MAJOR_VERSION)     || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_C != PORT_AR_RELEASE_MINOR_VERSION)     || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_C != PORT_AR_RELEASE_REVISION_VERSION)  \
    )
   #error "AutoSar Version Numbers of Port_Cfg.c and Port.h are different"
#endif

/* Check if Port_Cfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Cfg.c and Port.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/

#define PORT_START_SEC_CONST_16
/** @violates @ref PORT_CFG_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref PORT_CFG_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief Port Pin description data
*/
CONST (uint16, PORT_CONST) Port_au16PinDescription[[!"ecu:get('PortPadModeNumber')"!]][[!"ecu:get('PortPin16BlocksNo')"!]] =
{
[!IF "((ecu:get('PortFamily'))=118)"!][!//
    [!IF "((ecu:get('PortPackage'))='Port_48LQFP')"!][!//
        [!"$CHECK_1"!]
    [!ELSEIF "((ecu:get('PortPackage'))='Port_64LQFP')"!][!//
        [!"$CHECK_2"!]
    [!ENDIF!]
[!ELSE!]
    [!IF "((ecu:get('PortPackage'))='Port_48LQFP')"!][!//
        [!"$CHECK_1"!]
    [!ELSEIF "((ecu:get('PortPackage'))='Port_64LQFP')"!][!//
        [!"$CHECK_2"!]
    [!ELSEIF "((ecu:get('PortPackage'))='Port_100LQFP')"!][!//
        [!"$CHECK_3"!]
    [!ELSEIF "((ecu:get('PortPackage'))='Port_100MAPBGA')"!][!//
        [!"$CHECK_4"!]
    [!ELSEIF "((ecu:get('PortPackage'))='Port_144LQFP')"!][!//
        [!"$CHECK_5"!]
    [!ELSEIF "((ecu:get('PortPackage'))='Port_176LQFP')"!][!//
        [!"$CHECK_6"!]
    [!ENDIF!][!//
[!ENDIF!][!//
};
#endif

#define PORT_STOP_SEC_CONST_16
/** @violates @ref PORT_CFG_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref PORT_CFG_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"
/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
[!NOCODE!][!//
[!ENDNOCODE!][!//
[!ENDCODE!][!//
