[!CODE!][!//
/**
*   @file    Dio_Cfg.h
*   @version 1.0.2
*
*   @brief   AUTOSAR Dio configuration header.
*   @details This file is the Autosar DIO driver configuration header. This
*            file is automatically generated, do not modify manually.
*
*   @addtogroup DIO_CFG
*   @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : GPIO
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

#ifndef DIO_CFG_H
#define DIO_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Dio_Cfg_H_REF_1
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external
*          identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers.
* 
* @section Dio_Cfg_H_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file, 
*          Precautions shall be taken in order to prevent the contents of a header file 
*          being included twice. This violation is not fixed since the inclusion of MemMap.h is as per 
*          Autosar requirement MEMMAP003.
*
* @section Dio_Cfg_H_REF_3
*          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope 
*          if they are only accessed from within a single function. 
*          These objects are used in various parts of the code.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not
*          rely on the significance of more than 31 characters. The used compilers use more than
*          31 chars for identifiers.
**/


/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
/** @violates @ref Dio_Cfg_H_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Dio_EnvCfg.h"

/**
 *     @file       Dio_Cfg.h
 *     @implements Dio_Cfg.h_Artifact
 * */
[!NOCODE!][!//
[!INCLUDE "Dio_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define DIO_VENDOR_ID_CFG                   43
/** @violates @ref Dio_Cfg_H_REF_1 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define DIO_AR_RELEASE_MAJOR_VERSION_CFG    4
/** @violates @ref Dio_Cfg_H_REF_1 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define DIO_AR_RELEASE_MINOR_VERSION_CFG    2
/** @violates @ref Dio_Cfg_H_REF_1 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define DIO_AR_RELEASE_REVISION_VERSION_CFG 2
#define DIO_SW_MAJOR_VERSION_CFG            1
#define DIO_SW_MINOR_VERSION_CFG            0
#define DIO_SW_PATCH_VERSION_CFG            2

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Dio_EnvCfg.h version check start */
#if ((DIO_AR_RELEASE_MAJOR_VERSION_CFG != DIO_ENVCFG_AR_RELEASE_MAJOR_VERSION) ||   \
     (DIO_AR_RELEASE_MINOR_VERSION_CFG != DIO_ENVCFG_AR_RELEASE_MINOR_VERSION) ||   \
     (DIO_AR_RELEASE_REVISION_VERSION_CFG != DIO_ENVCFG_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AUTOSAR Version Numbers of Dio_Cfg.h and Dio_EnvCfg.h are different"
#endif

#if ((DIO_SW_MAJOR_VERSION_CFG != DIO_ENVCFG_SW_MAJOR_VERSION) || \
     (DIO_SW_MINOR_VERSION_CFG != DIO_ENVCFG_SW_MINOR_VERSION) || \
     (DIO_SW_PATCH_VERSION_CFG != DIO_ENVCFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Dio_Cfg.h and Dio_EnvCfg.h are different"
#endif

#if ((DIO_VENDOR_ID_CFG != DIO_ENVCFG_VENDOR_ID))
    #error "VENDOR ID for Dio_Cfg.h and Dio_EnvCfg.h is different"
#endif
/* Dio_EnvCfg.h version check end */
/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/

/**
* @brief          Enable or Disable Development Error Detection.
*
* @implements     DIO_DEV_ERROR_DETECT_define
* @api
*/
#define DIO_DEV_ERROR_DETECT    ([!IF "DioGeneral/DioDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief          Function @p Dio_GetVersionInfo() enable switch.
*
* @implements     DIO_VERSION_INFO_API_define
* @api
*/
#define DIO_VERSION_INFO_API    ([!IF "DioGeneral/DioVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief          Function @p Dio_FlipChannel() enable switch.
*
* @api
*/
#define DIO_FLIP_CHANNEL_API    ([!IF "DioGeneral/DioFlipChannelApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief          Function @p Dio_MaskedWritePort() enable switch.
*
* @api
*/
#define DIO_MASKEDWRITEPORT_API ([!IF "DioGeneral/DioMaskedWritePortApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief          Reversed port functionality enable switch.
*
* @implements     DIO_REVERSEPORTBITS_define
* @api
*/
#define DIO_REVERSEPORTBITS     ([!IF "DioGeneral/DioReversePortBits"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief          Undefined pins masking enable switch.
*
* @api
*/
#define DIO_READZERO_UNDEFINEDPORTS ([!IF "DioGeneral/DioReadZeroForUndefinedPortPins"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!NOCODE!]
[!VAR "NumPortsForWrite"="count(ecu:list('Dio.AvailablePortPinsForWrite'))"!]
[!VAR "NumPortsForRead"="count(ecu:list('Dio.AvailablePortPinsForRead'))"!]
[!IF "$NumPortsForWrite != $NumPortsForRead"!]
    [!ERROR!]The number ports in Dio.AvailablePortPinsForWrite and Dio.AvailablePortPinsForRead were not same value in resource file[!ENDERROR!]
[!ENDIF!]
[!ENDNOCODE!]
/**
* @brief          Number of implemented ports.
*
* @note           Used for channel, port and channel group validation.
*
* @api
*/
#define DIO_NUM_PORTS_U16               ((uint16)[!"num:inttohex(count(ecu:list('Dio.AvailablePortPinsForWrite')))"!])

/**
* @brief          Number channel in a port.
*
* @note           Used for channel, port and channel group validation.
*
* @api
*/
#define DIO_NUM_CHANNELS_PER_PORT_U16   ((uint16)(sizeof(Dio_PortLevelType) * 0x8U))

/**
* @brief          Number of channels available on the implemented ports.
*
* @note           Used for channel validation.
*
* @api
*/
#define DIO_NUM_CHANNELS_U16            ((uint16)(DIO_NUM_PORTS_U16 * DIO_NUM_CHANNELS_PER_PORT_U16))

/**
* @brief          Mask representing no available channels on a port.
*
* @note           Used for channel validation.
*
* @api
*/
#define DIO_NO_AVAILABLE_CHANNELS_U16   ((Dio_PortLevelType)0x0U)

/**
* @brief          Mask representing the maximum valid offset for a channel group.
*
* @note           Used for channel group validation.
*
* @api
*/
#define DIO_MAX_VALID_OFFSET_U8           ((uint8)0x1F)

/**
* @brief          Define to state if the current platform supports configuring the pins
*                 as input-output in the same time.
*
* @note           Used by Dio_FlipChannel() function.
*
* @api
*/
#define DIO_INOUT_CONFIG_SUPPORTED        ([!IF "((ecu:get('Dio.InOutConfigSupported'))='TRUE')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])[!//

/**
*   @brief   Enables or disables the access to a hardware register from user mode
*            USER_MODE_SOFT_LOCKING:        All reads to hw registers will be done via REG_PROT, user mode access
*            SUPERVISOR_MODE_SOFT_LOCKING:  Locks the access to the registers only for supervisor mode
*
*   @note    Currently, no register protection mechanism is used for Dio driver.
*/
#define DIO_USER_MODE_SOFT_LOCKING      (STD_OFF)

[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile'"!][!//
/**
* @brief          Dio driver Pre-Compile configuration switch.
*
* @api
*/
#define DIO_PRECOMPILE_SUPPORT

[!ELSEIF "IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime'"!][!//
/**
* @brief          Dio driver Link-Time configuration switch.
*
* @api
*/
#define DIO_LINKTIME_SUPPORT
[!ENDIF!][!//

/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the Dio driver code can be executed from both supervisor and user mode.
*
*/
[!IF "DioGeneral/DioEnableUserModeSupport"!]
#define DIO_ENABLE_USER_MODE_SUPPORT   (STD_ON)

/**
* @brief Support for REG_PROT in GPIO IP.
*        If the current platform implements REG_PROT for GPIO IP, this parameter will be defined, and will enable REG_PROT configuration for GPIO IP in DIO drvier
*/
#define DIO_GPIO_REG_PROT_AVAILABLE
[!ELSE!]
#define DIO_ENABLE_USER_MODE_SUPPORT   (STD_OFF)
[!ENDIF!]

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef DIO_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == DIO_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Dio in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == DIO_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef DIO_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/
[!SELECT "DioConfig"!][!//

/**
* @brief          Symbolic name for the configuration Dio_ConfigPC.
*
*/
#define Dio_ConfigPC    ([!"as:name(.)"!])  

/* ========== [!"as:name(.)"!] ========== */

[!VAR "ConfigName"="as:name(.)"!][!//
[!VAR "ChannelGroupdIdx"="0"!][!//
[!LOOP "DioPort/*"!][!/*
    */!][!VAR "PortId" = "DioPortId"!][!//
/* ---------- [!"node:name(.)"!] ---------- */

/**
* @brief          Symbolic name for the port [!"node:name(.)"!].
*
*/
#define DioConf_DioPort_[!"node:name(.)"!]  ((uint8)[!"num:inttohex($PortId,2)"!]U)

[!LOOP "DioChannel/*"!][!/*
    */!][!VAR "PortChannelId" = "DioChannelId"!][!/*
    */!][!VAR "ChannelId" = "32*$PortId + $PortChannelId"!][!//
/**
* @brief          Symbolic name for the channel [!"node:name(.)"!].
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define  DioConf_DioChannel_[!"node:name(.)"!] ((uint16)[!"num:inttohex($ChannelId,4)"!]U)

[!ENDLOOP!][!//
[!LOOP "DioChannelGroup/*"!][!//


/**
* @brief        Symbolic name for the channel group [!"node:name(.)"!].
*
*/


/** @violates @ref Dio_Cfg_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define DioConf_DioChannelGroup_[!"node:name(.)"!]    \
                (&[!"$ConfigName"!]_aChannelGroupList[[!"num:dectoint($ChannelGroupdIdx)"!]])[!//

[!VAR "ChannelGroupdIdx" = "$ChannelGroupdIdx + 1"!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/

/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/**
* @brief          Type of a DIO port representation.
*
* @implements     Dio_PortType_typedef
*
* @api
*/
typedef uint8 Dio_PortType;

/**
* @brief          Type of a DIO channel representation.
*
* @implements     Dio_ChannelType_typedef
*
* @api
*/
typedef uint16 Dio_ChannelType;

/**
* @brief          Type of a DIO port levels representation.
*
* @implements     Dio_PortLevelType_typedef
*
* @api
*/
typedef uint32 Dio_PortLevelType;

/**
* @brief          Type of a DIO channel levels representation.
*
* @implements     Dio_LevelType_typedef
*
* @api
*/
typedef uint8 Dio_LevelType;

/**
* @brief          Type of a DIO channel group representation.
*
* @implements     Dio_ChannelGroupType_struct
*
* @api
*/
typedef struct
{
    VAR(Dio_PortType, AUTOMATIC)      port;      /**< @brief Port identifier.  */
    VAR(uint8, AUTOMATIC)             u8offset;    /**< @brief Bit offset within the port. */
    VAR(Dio_PortLevelType, AUTOMATIC) mask;      /**< @brief Group mask. */
} Dio_ChannelGroupType;

/**
* @brief          Type of a DIO configuration structure.
*
* @note           In this implementation there is no need for a configuration
*                 structure there is only a dummy field, it is recommended
*                 to initialize this field to zero.
*
* @implements     Dio_ConfigType_struct
*
* @api
*/
typedef struct
{                                                                       
    VAR(uint8, AUTOMATIC) u8NumChannelGroups; /**< @brief Number of channel groups in configuration */
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroupList;  /**< @brief 
                                               Pointer to list of channel groups in configuration */
} Dio_ConfigType;

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/

#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Dio_Cfg_H_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Dio_MemMap.h"

/**
* @brief Array of bitmaps of output pins available per port
*/
/** @violates @ref Dio_Cfg_H_REF_3 Objects shall be defined at block scope if they are only accessed from within a single function. */
extern CONST(Dio_PortLevelType, DIO_CONST) Dio_aAvailablePinsForWrite[DIO_NUM_PORTS_U16];

/**
* @brief Array of bitmaps of input pins available per port
*/
/** @violates @ref Dio_Cfg_H_REF_3 Objects shall be defined at block scope if they are only accessed from within a single function. */
extern CONST(Dio_PortLevelType, DIO_CONST) Dio_aAvailablePinsForRead[DIO_NUM_PORTS_U16];

[!SELECT "DioConfig"!][!//
/**
* @brief          List of channel groups in configuration [!"node:name(.)"!].
*/

[!VAR "numChannelGroupsInConfig" = "count(DioPort/*/DioChannelGroup/*)"!][!//
[!IF "$numChannelGroupsInConfig != 0"!][!//
extern CONST(Dio_ChannelGroupType, DIO_CONST) [!"as:name(.)"!]_aChannelGroupList[[!"num:dectoint($numChannelGroupsInConfig)"!]];
[!ENDIF!]
[!ENDSELECT!][!//
[!LOOP "DioConfig/*/DioPort/*"!][!/*
    */!][!VAR "crt_name"="node:name(.)"!][!/*
    */!][!VAR "n"="0"!][!/*
    */!][!LOOP "../../DioPort/*"!][!/*
        */!][!IF "$crt_name=node:name(.)"!][!VAR "n"="$n+1"!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
    */!][!IF "$n > 1"!][!ERROR "Port name duplicated. Port names must be unique even across configurations"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!LOOP "DioConfig/DioPort/*/DioChannelGroup/*"!][!/*
    */!][!VAR "crt_name"="node:name(.)"!][!/*
    */!][!VAR "n"="0"!][!/*
    */!][!LOOP "../../../../DioPort/*/DioChannelGroup/*"!][!/*
        */!][!IF "$crt_name=node:name(.)"!][!VAR "n"="$n+1"!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
    */!][!IF "$n > 1"!][!ERROR "ChannelGroup name duplicated. Channel group names must be unique even across ports and configurations"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!LOOP "DioConfig/DioPort/*/DioChannel/*"!][!/*
    */!][!VAR "crt_name"="node:name(.)"!][!/*
    */!][!VAR "n"="0"!][!/*
    */!][!LOOP "../../../../DioPort/*/DioChannel/*"!][!/*
        */!][!IF "$crt_name=node:name(.)"!][!VAR "n"="$n+1"!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
    */!][!IF "$n > 1"!][!ERROR "Channel name duplicated. Channel names must be unique even across ports and configurations"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!//

#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Dio_Cfg_H_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Dio_MemMap.h"
/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* DIO_CFG_H */

/** @} */
[!ENDCODE!][!//
