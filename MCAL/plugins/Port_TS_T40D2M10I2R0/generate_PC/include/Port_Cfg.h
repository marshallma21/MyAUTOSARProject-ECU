[!CODE!][!//
/**
* @file    Port_Cfg.h
* @implements Port_Cfg.h_Artifact
*
* @version 1.0.2
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver precompile configuration.
*
* @addtogroup Port
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

#ifndef PORT_CFG_H
#define PORT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_CFG_H_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linkershall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers. 
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section PORT_CFG_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_CFG_H_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section PORT_CFG_H_REF_4
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function.
* These objects are used in various parts of the code.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*=================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Port_EnvCfg.h"
#include "Port_Port_Ci_Types.h"
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
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @details The integration of incompatible files shall be avoided.
*/
#define PORT_VENDOR_ID_CFG_H                       43
/**
* @violates @ref PORT_CFG_H_REF_1 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_H        4
/**
* @violates @ref PORT_CFG_H_REF_1 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_H        2
/**
* @violates @ref PORT_CFG_H_REF_1 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_H     2
#define PORT_SW_MAJOR_VERSION_CFG_H                1
#define PORT_SW_MINOR_VERSION_CFG_H                0
#define PORT_SW_PATCH_VERSION_CFG_H                2

/*=================================================================================================
*                               FILE VERSION CHECKS
=================================================================================================*/

/* Check if Port_Cfg.h and Port_Port_Ci_Types.h file are of the same vendor */
#if (PORT_VENDOR_ID_CFG_H != PORT_PORT_CI_VENDOR_ID_TYPES_H)
    #error "Port_Cfg.h and Port_Port_Ci_Types.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Port_Port_Ci_Types.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_H != PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_TYPES_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_H != PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_TYPES_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_H != PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_TYPES_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_Port_Ci_Types.h are different"
#endif
/* Check if Port_Cfg.h and Port_Port_Ci_Types.h file are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_H != PORT_PORT_CI_SW_MAJOR_VERSION_TYPES_H) || \
     (PORT_SW_MINOR_VERSION_CFG_H != PORT_PORT_CI_SW_MINOR_VERSION_TYPES_H) || \
     (PORT_SW_PATCH_VERSION_CFG_H != PORT_PORT_CI_SW_PATCH_VERSION_TYPES_H) \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_Port_Ci_Types.h are different"
#endif

/* Check if Port_Cfg.h file and Port_EnvCfg header file are of the same vendor */
#if (PORT_VENDOR_ID_CFG_H != PORT_ENVCFG_VENDOR_ID)
    #error "Port_Cfg.h and Port_EnvCfg.h have different vendor IDs"
#endif

#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_H != PORT_ENVCFG_AR_RELEASE_MAJOR_VERSION)      || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_H != PORT_ENVCFG_AR_RELEASE_MINOR_VERSION)      || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_H != PORT_ENVCFG_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_EnvCfg.h are different"
#endif
/* Check if Port_Cfg.h and PORT header file are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_H != PORT_ENVCFG_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_H != PORT_ENVCFG_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_H != PORT_ENVCFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_EnvCfg.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/
/**
* @brief       Ensure better readability of the configuration
* @note 
*
* @violates @ref PORT_CFG_H_REF_3 Function-like macro defined.
*/
#define SHL_PAD_U16(x)                      ((uint16)(((uint16)1) << (x)))

/** @brief Port Alternate 0 Mode */
#define PORT_ALT0_FUNC_MODE             ((Port_PinModeType)0)
/** @brief Port GPIO Mode */
#define PORT_GPIO_MODE                  ((Port_PinModeType)1)
/** @brief Port Alternate 2 Mode */
#define PORT_ALT2_FUNC_MODE             ((Port_PinModeType)2)
/** @brief Port Alternate 3 Mode */
#define PORT_ALT3_FUNC_MODE             ((Port_PinModeType)3)
/** @brief Port Alternate 4 Mode */
#define PORT_ALT4_FUNC_MODE             ((Port_PinModeType)4)
/** @brief Port Alternate 5 Mode */
#define PORT_ALT5_FUNC_MODE             ((Port_PinModeType)5)
/** @brief Port Alternate 6 Mode */
#define PORT_ALT6_FUNC_MODE             ((Port_PinModeType)6)
/** @brief Port Alternate 7 Mode */
#define PORT_ALT7_FUNC_MODE             ((Port_PinModeType)7)

[!IF "((ecu:get('PortFamily'))=118)"!][!//
[!IF "((ecu:get('PortPackage'))='Port_48LQFP')"!][!//
    [!"$PinAbstractionModes_1"!][!//
[!ELSEIF "((ecu:get('PortPackage'))='Port_64LQFP')"!][!//
    [!"$PinAbstractionModes_2"!][!//
[!ENDIF!]
[!ELSE!]
[!IF "((ecu:get('PortPackage'))='Port_48LQFP')"!][!//
    [!"$PinAbstractionModes_1"!][!//
[!ELSEIF "((ecu:get('PortPackage'))='Port_64LQFP')"!][!//
    [!"$PinAbstractionModes_2"!][!//
[!ELSEIF "((ecu:get('PortPackage'))='Port_100LQFP')"!][!//
    [!"$PinAbstractionModes_3"!][!//
[!ELSEIF "((ecu:get('PortPackage'))='Port_100MAPBGA')"!][!//
    [!"$PinAbstractionModes_4"!][!//
[!ELSEIF "((ecu:get('PortPackage'))='Port_144LQFP')"!][!//
    [!"$PinAbstractionModes_5"!][!//
[!ELSEIF "((ecu:get('PortPackage'))='Port_176LQFP')"!][!//
    [!"$PinAbstractionModes_6"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

/**
* @brief Enable/Disable Development Error Detection
*
* @implements   PORT_DEV_ERROR_DETECT_define
*/
#define PORT_DEV_ERROR_DETECT           [!IF "PortGeneral/PortDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief Use/remove Port_SetPinDirection function from the compiled driver
*
* @implements   PORT_SET_PIN_DIRECTION_API_define
*/
[!IF "node:exists(PortGeneral/PortSetPinDirectionApi)"!][!//
#define PORT_SET_PIN_DIRECTION_API      [!IF "PortGeneral/PortSetPinDirectionApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ELSE!][!//
#define PORT_SET_PIN_DIRECTION_API      (STD_OFF)
[!ENDIF!][!//

[!IF "ecu:has('PortSet2PinsDirectionApiAvailable') and ecu:get('PortSet2PinsDirectionApiAvailable') = 'true'"!][!//
/**
* @brief Use/remove Port_Set2PinsDirection function from the compiled driver
*
* PORT_SET_2_PINS_DIRECTION_API_define
*/
[!/**/!][!IF "PortGeneral/PortSet2PinsDirectionApi"!][!//
#define PORT_SET_2_PINS_DIRECTION_API   (STD_ON)[!/*
    */!][!ELSE!][!//
#define PORT_SET_2_PINS_DIRECTION_API   (STD_OFF)[!/*
    */!][!ENDIF!][!//
[!ENDIF!][!//


/**
* @brief Use/remove Port_SetPinMode function from the compiled driver
*
* @implements   PORT_SET_PIN_MODE_API_define
*/
[!IF "node:exists(PortGeneral/PortSetPinModeApi)"!][!//
#define PORT_SET_PIN_MODE_API           [!IF "PortGeneral/PortSetPinModeApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ELSE!][!//
#define PORT_SET_PIN_MODE_API           (STD_OFF)
[!ENDIF!][!//

/**
* @brief Enable/Disable Port_SetPinMode function updating the output level of the pins configured at runtime as GPIO
*/
#define PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL           [!IF "PortGeneral/PortSetPinModeDoesNotTouchGpioLevel"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the PORT driver code can be executed from both supervisor and user mode.
*/
[!IF "PortGeneral/PortEnableUserModeSupport"!]
#define PORT_ENABLE_USER_MODE_SUPPORT   (STD_ON)

/**
* @brief Support for REG_PROT in PORT_CI IP.
*        If the current platform implements REG_PROT for PORT_CI IP, this parameter will be defined, and will enable REG_PROT configuration for PORT_CI IP in PORT drvier
*/
#define PORT_PORT_CI_REG_PROT_AVAILABLE
[!ELSE!]
#define PORT_ENABLE_USER_MODE_SUPPORT   (STD_OFF)
[!ENDIF!]

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef PORT_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Port in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef PORT_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/**
* @brief Use/remove Port_GetVersionInfo function from the compiled driver
*
* @implements   PORT_VERSION_INFO_API_define
*/
#define PORT_VERSION_INFO_API           [!IF "PortGeneral/PortVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!NOCODE!][!//
[!SELECT "PortConfigSet"!]
    [!VAR "OuterLoopCounter" = "0"!][!//
    [!VAR "InnerLoopCounter" = "0"!][!//
    [!LOOP "PortContainer/*"!][!//
        [!LOOP "PortPin/*"!][!//
            [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
            [!VAR "InnerLoopCounter" = "0"!]
            [!VAR "MatchCounter" = "0"!]
            [!VAR "Id" = "PortPinPcr"!]
            [!VAR "Name" = "node:name(.)"!]
            [!LOOP "../../../../PortContainer/*"!][!//
                [!LOOP "PortPin/*"!][!//
                    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
                    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                        [!IF "($Id = PortPinPcr)"!]
                            [!VAR "MatchCounter" = "$MatchCounter + 1"!]
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDLOOP!][!//
            [!IF "$MatchCounter = 1"!]
            [!ELSE!]
                [!ERROR!][!//
                    Error in PortPin list: [!"PortPinPcr is repeated for two or more ports."!][!//
                [!ENDERROR!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!LOOP "PortContainer/*"!][!//
        [!LOOP "PortPin/*"!][!//
            [!VAR "PortPinPcrVar" = "PortPinPcr"!][!//
            [!IF "($PortPinPcrVar>ecu:get('PortMaxPinNumber'))"!][!//
                [!ERROR!][!//
                [!"name(.)"!] [!"': PortPinPcr '"!] [!"string($PortPinPcrVar)"!] [!"concat('- Physical pin numbers greater then ',ecu:get('PortMaxPinNumber'),' are not available in this package')"!][!//
                [!ENDERROR!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
    [!// Check if the PCRs in UnTouchedPins are unique
    [!VAR "OuterLoopCounter" = "0"!][!//
    [!VAR "InnerLoopCounter" = "0"!][!//
    [!LOOP "UnTouchedPortPin/*"!][!//
        [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
        [!VAR "InnerLoopCounter" = "0"!]
        [!VAR "MatchCounter" = "0"!]
        [!VAR "OuterPortPinPcr" = "./PortPinPcr"!]
        [!LOOP "../../UnTouchedPortPin/*"!][!//
            [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
            [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                [!IF "($OuterPortPinPcr = ./PortPinPcr)"!]
                    [!VAR "MatchCounter" = "$MatchCounter + 1"!]
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!IF "$MatchCounter > 1"!]
            [!ERROR!][!//
                Error in UnTouchedPortPin list: [!"name(.)"!] with [!"'PortPin Pcr'"!] set to [!"string($OuterPortPinPcr)"!] [!"Pcr is repeated for two or more ports."!][!//
            [!ENDERROR!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!// Check if the configured PCRs in UnTouchedPortPin list are in range
    [!LOOP "UnTouchedPortPin/*"!][!//
        [!VAR "PortPinPcrVar" = "PortPinPcr"!][!//
        [!IF "($PortPinPcrVar > ecu:get('PortMaxPinNumber'))"!][!//
            [!ERROR!][!//
                Error in UnTouchedPortPin list: [!"name(.)"!] [!"': PortPinPcr '"!] [!"string($PortPinPcrVar)"!] [!"concat('- Physical pin numbers greater then ',ecu:get('PortMaxPinNumber'),' are not available in this package')"!][!//
            [!ENDERROR!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!// Check if the configured PCRs are not available
    [!VAR "resourceName" = "'PortNotAvailablePins'"!][!//
    [!LOOP "UnTouchedPortPin/*"!][!//
        [!VAR "PortPinPcrVar" = "PortPinPcr"!][!//
        [!IF "contains(concat(',',string(ecu:get($resourceName)),','), concat(',',$PortPinPcrVar,','))"!][!//
            [!ERROR!][!//
                Error in UnTouchedPortPin list: [!"name(.)"!] with [!"'PortPin Pcr'"!] set to [!"string($PortPinPcrVar)"!] [!"Pcr not available in this package."!][!//
            [!ENDERROR!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!// Check if there is no PCR that appears both in list of configured pins and in the list of UnTouchedPortPins
    [!LOOP "PortContainer/*"!][!//
        [!VAR "PortContainerName" = "name(.)"!]
        [!LOOP "PortPin/*"!][!//
            [!VAR "MatchCounter" = "0"!]
            [!VAR "ConfiguredPortPinPcr" = "./PortPinPcr"!]
            [!LOOP "../../../../UnTouchedPortPin/*"!][!//
                [!IF "($ConfiguredPortPinPcr = ./PortPinPcr)"!]
                    [!ERROR!][!//
                    Error: PCR [!"string($ConfiguredPortPinPcr)"!] appears in the UnTouchedPortPin list and also in the list of configured pins in Port container [!"string($PortContainerName)"!]. Please remove it from one of the 2 lists[!//
                    [!ENDERROR!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
    [!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//

/**
* @brief Port Pin symbolic names
* @details Get All Symbolic Names from configuration tool
*
*/
[!NOCODE!]
    [!VAR "OutConfigLoopCounter" = "0"!][!//
    [!VAR "ConfigSetIndex"="0"!]
    [!SELECT "PortConfigSet"!][!//
        [!VAR "ConfigSetName" = "as:name(.)"!][!//
        [!VAR "OutConfigLoopCounter" = "$OutConfigLoopCounter + 1"!][!//
        [!VAR "OutPinLoopCounter" = "0"!][!//
        [!LOOP "PortContainer/*"!][!//
            [!VAR "ContName" = "node:name(.)"!][!//
            [!LOOP "PortPin/*"!][!//
                [!VAR "OutPinLoopCounter" = "$OutPinLoopCounter + 1"!][!//
                [!VAR "Name" = "node:name(.)"!][!//
                [!VAR "MatchCounter" = "0"!][!//
                [!VAR "InConfigLoopCounter" = "0"!][!//
                [!VAR "MatchConfigSet" = "0"!][!//
                [!SELECT "../../../../../PortConfigSet"!][!//
                    [!VAR "InConfigLoopCounter" = "$InConfigLoopCounter + 1"!][!//
                    [!VAR "InPinLoopCounter" = "0"!][!//
                    [!LOOP "PortContainer/*"!][!//
                        [!VAR "ContNameNew" = "node:name(.)"!][!//
                        [!LOOP "PortPin/*"!][!//
                            [!VAR "InPinLoopCounter" = "$InPinLoopCounter + 1"!][!//
                            [!IF "$InConfigLoopCounter < $OutConfigLoopCounter"!][!//
                                [!IF "($ContName = $ContNameNew)"!][!//
                                    [!IF "($Name = node:name(.))"!][!//
                                        [!IF "$InPinLoopCounter = $OutPinLoopCounter"!][!//
                                            [!IF "$MatchConfigSet = $ConfigSetIndex"!][!//
                                                [!VAR "MatchCounter" = "$MatchCounter + 1"!][!//
                                            [!ENDIF!][!//
                                        [!ELSE!][!//
                                            [!ERROR!][!//
                                                [!"concat('- The same Abstract Name ',($Name),' is used for different index values')"!][!//
                                            [!ENDERROR!][!//
                                        [!ENDIF!][!//
                                    [!ENDIF!][!//
                                [!ENDIF!][!//
                            [!ENDIF!][!//
                        [!ENDLOOP!][!//
                    [!ENDLOOP!][!//
                    [!VAR "$MatchConfigSet" = "$MatchConfigSet+1"!][!//
                [!ENDSELECT!][!//
                [!IF "$MatchCounter = 0"!][!//
                    [!VAR "PortPinIdVar"="PortPinId"!][!//
[!CODE!][!//
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define [!"$ConfigSetName"!]_[!"$ContName"!]_[!"node:name(.)"!]  [!"num:i($PortPinIdVar - 1)"!]
[!ENDCODE!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
    [!ENDSELECT!][!//
[!ENDNOCODE!]

/**
* @brief Number of available pad modes options
* @details Platform constant
*/
#define PAD_MODE_OPTIONS_U8         ((uint8)[!"ecu:get('PortPadModeNumber')"!])
/**
* @brief Number of pad 16 blocks
* @details Platform constant
*/
#define PAD_16BLOCK_NO_U8           ((uint8)[!"ecu:get('PortPin16BlocksNo')"!])
/**
 * @brief The last supported pin number
 */
#define PORT_MAX_PIN_PACKAGE_U16    ((uint16)[!"ecu:get('PortMaxPinNumber')"!])

/**
* @brief The maximum number of configured pins
*/
#define PORT_MAX_CONFIGURED_PADS_U16                        ((uint16)[!"num:i(count(PortConfigSet/PortContainer/*/PortPin/*))"!])

/**
 * @brief Number of UnUsed pin array
*/
[!NOCODE!]
    [!SELECT "PortConfigSet"!][!//
        [!VAR "MaxNoOfPins" = "num:i(ecu:get('PortMaxPinNumber')+1)"!][!//
        [!VAR "UnimplementedPadsNumber" = "num:i(count(ecu:list('PortUnimplementedPAD')))"!][!//
        [!VAR "UserPadsNumber" = "num:i(count(PortContainer/*/PortPin/*))"!][!//
        [!VAR "NoOfUntouchedPortPin" = "num:i(count(UnTouchedPortPin/*))"!][!//
        [!LOOP "PortContainer/*/PortPin/*"!][!//
            [!IF "contains(concat(',',string(ecu:get('PortUnimplementedPAD')),','),concat(',',PortPinPcr,','))"!][!//
                [!VAR "UnimplementedPadsNumber"= "$UnimplementedPadsNumber - 1"!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!VAR "DefaultPinNumber" = "$UnimplementedPadsNumber + $UserPadsNumber"!][!//
        [!VAR "NoOfUnusedPins" = "num:i($MaxNoOfPins - $DefaultPinNumber - $NoOfUntouchedPortPin)"!][!//
[!CODE!][!//
#define PORT_MAX_UNUSED_PADS_U16   ([!"$NoOfUnusedPins"!]U)
[!ENDCODE!][!//
    [!ENDSELECT!][!//
[!ENDNOCODE!][!//

[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' and variant:size()<=1"!][!//
/**
* @brief Port driver Pre-Compile configuration switch
*/
#define PORT_PRECOMPILE_SUPPORT     (STD_ON)
[!ELSE!][!//
/**
* @brief Port driver Post-build configuration switch
*/
#define PORT_PRECOMPILE_SUPPORT     (STD_OFF)
[!ENDIF!][!//

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/**
* @brief   Structure needed by @p Port_Init().
* @details The structure @p Port_ConfigType is a type for the external data
*          structure containing the initialization data for the PORT Driver.
* @note    The user must use the symbolic names defined in the configuration
*          tool.
*
* @implements Port_ConfigType_struct
*
* @api
*/
typedef struct
{
    VAR(uint16, AUTOMATIC) u16NumPins;                                                           /**< @brief Number of used pads (to be configured) */
    VAR(uint16, AUTOMATIC) u16NumUnusedPins;                                                     /**< @brief Number of unused pads */
    P2CONST(uint16, AUTOMATIC, PORT_APPL_CONST) pau16UnusedPads;                                  /**< @brief Unused pad id's array */
    P2CONST(Port_Port_Ci_UnUsedPinConfigType, AUTOMATIC, PORT_APPL_CONST) pUnusedPadConfig;      /**< @brief Unused pad configuration */
    P2CONST(Port_Port_Ci_PinConfigType,       AUTOMATIC, PORT_APPL_CONST) pUsedPadConfig;        /**< @brief Used pads data configuration */
    VAR(uint8, AUTOMATIC)  u8NumDigitalFilterPorts;                                              /**< @brief Number of configured digital filter ports */
    P2CONST(Port_DigitalFilter_ConfigType, AUTOMATIC, PORT_APPL_CONST) pDigitalFilterConfig;     /**< @brief Digital filter ports configuration */
} Port_ConfigType;

/*=================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/

#define PORT_START_SEC_CONST_16
/** @violates @ref PORT_CFG_H_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief External declaration of the Port pin description array
*/
/** @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed from within a single function. */
extern CONST(uint16, PORT_CONST) Port_au16PinDescription[[!"ecu:get('PortPadModeNumber')"!]][[!"ecu:get('PortPin16BlocksNo')"!]];

#endif

#define PORT_STOP_SEC_CONST_16
/** @violates @ref PORT_CFG_H_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref PORT_CFG_H_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

[!MACRO "PortExportDriverConfiguration"!][!//
[!NOCODE!][!//
[!VAR "configName" = "as:name(PortConfigSet)"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
[!CODE!][!//
/** @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope */
extern CONST(Port_ConfigType, PORT_CONST) [!"$configName"!]_[!"."!];[!CR!][!//
[!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ELSE!][!//
[!CODE!][!//
/** @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope */
extern CONST(Port_ConfigType, PORT_CONST) [!"$configName"!];[!CR!][!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//
[!CALL "PortExportDriverConfiguration"!][!//
[!ENDIF!]

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref PORT_CFG_H_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* PORT_CFG_H */

/** @} */

/* End of File */
[!NOCODE!][!//
[!ENDNOCODE!][!//
[!ENDCODE!][!//
