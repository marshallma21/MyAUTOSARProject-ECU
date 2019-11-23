/**
*   @file    Gpt_Cfg.h
*   @version 1.0.2
*
*   @brief   AUTOSAR Gpt  - Gpt driver configuration header file.
*   @details GPT driver header file, containing C and XPath constructs for generating Gpt
*            configuration header file.
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

#ifndef GPT_CFG_H
#define GPT_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*
* @section GPT_CFG_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_CFG_H_REF_3
* Violates MISRA 2004 Required Rule 19.4, Braces not used for some macros
* Braces are not used for macros which expand to multiple statements separated by ";" character.
*
* @section GPT_CFG_H_REF_4
* Violates MISRA 2004 Required Rule 8.7, Some global variables used by a single driver function shall be
* exported to user application.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "Gpt_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//
/** @violates @ref GPT_CFG_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_CFG                    43
#define GPT_AR_RELEASE_MAJOR_VERSION_CFG     4
#define GPT_AR_RELEASE_MINOR_VERSION_CFG     2
#define GPT_AR_RELEASE_REVISION_VERSION_CFG  2
#define GPT_SW_MAJOR_VERSION_CFG             1
#define GPT_SW_MINOR_VERSION_CFG             0
#define GPT_SW_PATCH_VERSION_CFG             2

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if this header file and Mcal.h file are of the same Autosar version */
    #if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_Cfg.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief Gpt Dev error detect switch
*
*/
#define GPT_DEV_ERROR_DETECT ([!IF "GptDriverConfiguration/GptDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Report Wakeup Source switch
*/
#define GPT_REPORT_WAKEUP_SOURCE ([!IF "GptDriverConfiguration/GptReportWakeupSource"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief GPT_VERSION_INFO_API switch
*
*/
#define GPT_VERSION_INFO_API ([!IF "GptConfigurationOfOptApiServices/GptVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief GPT_DEINIT_API switch
*
*/
#define GPT_DEINIT_API ([!IF "GptConfigurationOfOptApiServices/GptDeinitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief GPT_TIME_ELAPSED_API switch
*
*/
#define GPT_TIME_ELAPSED_API ([!IF "GptConfigurationOfOptApiServices/GptTimeElapsedApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief GPT_TIME_REMAINING_API switch
*
*/
#define GPT_TIME_REMAINING_API ([!IF "GptConfigurationOfOptApiServices/GptTimeRemainingApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief GPT_ENABLE_DISABLE_NOTIFICATION_API switch
*
*/
#define GPT_ENABLE_DISABLE_NOTIFICATION_API ([!IF "GptConfigurationOfOptApiServices/GptEnableDisableNotificationApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief GPT_WAKEUP_FUNCTIONALITY_API switch
*
*/
#define GPT_WAKEUP_FUNCTIONALITY_API ([!IF "GptConfigurationOfOptApiServices/GptWakeupFunctionalityApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief GPT_PREDEFTIMER_FUNCTIONALITY_API switch
*
*/
#define GPT_PREDEFTIMER_FUNCTIONALITY_API ([!IF "GptConfigurationOfOptApiServices/GptPredefTimerFunctionalityApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Enable/disable support for changing timeout value during timer running
*
*/
#define GPT_CHANGE_NEXT_TIMEOUT_VALUE            ([!IF "GptNonAUTOSAR/GptChangeNextTimeoutValueApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Support for GPT Standby wakeup.
*        The driver shall NOT CLEAR the interrupt flag, the interrupt enable bit and also should not disable the counter, during init *(Gpt_SRtc_Init()) the flag is already set.
*
*/

[!IF "node:exists(GptNonAUTOSAR/GptStandbyWakeupSupport)"!][!//
#define GPT_STANDBY_WAKEUP_SUPPORT    ([!IF "GptNonAUTOSAR/GptStandbyWakeupSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!]
#define GPT_STANDBY_WAKEUP_SUPPORT    (STD_OFF)
[!ENDIF!]


/**
* @brief Enable/disable API for Dual Mode support.
*/
#define GPT_SET_CLOCK_MODE           ([!IF "GptNonAUTOSAR/GptEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief   Enables or disables the access to a hardware register from user mode
*            USER_MODE_SOFT_LOCKING:        All reads to hw registers will be done via REG_PROT, user mode access
*            SUPERVISOR_MODE_SOFT_LOCKING:  Locks the access to the registers only for supervisor mode
*
*
*/
#define GPT_USER_MODE_SOFT_LOCKING       ([!IF "GptDriverConfiguration/GptRegisterLockingMode ='USER_MODE_SOFT_LOCKING'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief   Enables or disables support external trigger sources
*
*/
#define GPT_LPIT_ENABLE_EXT_TRIGGERS     ([!IF "GptNonAUTOSAR/GptEnableTriggers"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!MACRO "GENERATE_ISR_USE","IPVType"!][!//
[!NOCODE!]
[!VAR "ModuleIdx"="0"!]
[!LOOP "GptHwConfiguration/*"!]
    [!IF "GptIsrEnable = 'true' and contains(GptIsrHwId, $IPVType)"!]
        [!NOCODE!]
        [!CODE!]
#define GPT_[!"GptIsrHwId"!]_ISR_USED
        [!ENDCODE!]
        [!ENDNOCODE!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "CheckFreeze" , "ModuleType"!]
    [!SELECT "GptChannelConfigSet"!]
       [!VAR "MacNumChannels" = "0"!][!//
       [!VAR "MacFreezeEnabledChannels" = "0"!][!//
       [!LOOP "GptChannelConfigSet/GptChannelConfiguration/*/GptHwChannel[contains(., $ModuleType)]/.."!]
           [!IF "GptFreezeEnable"!] [!VAR "MacFreezeEnabledChannels" = "$MacFreezeEnabledChannels + 1"!][!ENDIF!][!//
           [!VAR "MacNumChannels" = "$MacNumChannels + 1"!][!//
       [!ENDLOOP!]

       [!IF "not($MacNumChannels = $MacFreezeEnabledChannels) and not($MacFreezeEnabledChannels = 0)"!]
           [!ERROR!][!//
               Module [!"$ModuleType"!] has channels configured with different values for FreezeEnable. Please select the same value for FreezeEnable accross all [!"$ModuleType"!] channels
           [!ENDERROR!][!//
       [!ENDIF!]
    [!ENDSELECT!]
[!ENDMACRO!]

[!NOCODE!]
[!//Ftm channels have a generic FreezeEnable bit. Check that FreezeEnable is consistent.
[!CALL "CheckFreeze","ModuleType"="string('FTM_0')"!]
[!CALL "CheckFreeze","ModuleType"="string('FTM_1')"!]
[!CALL "CheckFreeze","ModuleType"="string('FTM_2')"!]
[!CALL "CheckFreeze","ModuleType"="string('FTM_3')"!]
[!CALL "CheckFreeze","ModuleType"="string('FTM_4')"!]
[!CALL "CheckFreeze","ModuleType"="string('FTM_5')"!]
[!CALL "CheckFreeze","ModuleType"="string('FTM_6')"!]
[!CALL "CheckFreeze","ModuleType"="string('FTM_7')"!]
[!CALL "CheckFreeze","ModuleType"="string('LPIT')"!]
[!ENDNOCODE!]

[!NOCODE!][!//
[!CODE!][!//

[!IF "node:exists(GptNonAUTOSAR/GptEnableUserModeSupport)"!][!//
#define GPT_ENABLE_USER_MODE_SUPPORT    ([!IF "GptNonAUTOSAR/GptEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!IF "GptNonAUTOSAR/GptEnableUserModeSupport"!]
#define GPT_SRTC_SUPERVISER_BIT_AVAILABLE
[!ENDIF!]
[!ELSE!]
#define GPT_ENABLE_USER_MODE_SUPPORT    (STD_OFF)
[!ENDIF!]

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef GPT_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == GPT_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Gpt in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == GPT_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef GPT_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

[!ENDCODE!][!//
[!ENDNOCODE!][!//


[!NOCODE!][!//
[!VAR "MacFtmUsed"="0"!]
[!VAR "MacLPitUsed"="0"!]
[!VAR "MacLptmrUsed"="0"!]
[!VAR "MacSRtcUsed"="0"!]
    // Loop on all channels inside the same Configuration Set
    [!LOOP "GptHwConfiguration/*"!][!//
        [!IF "node:value(GptModuleIsUsed) = 'true' and contains(GptIsrHwId, 'FTM')"!][!//
            [!VAR "MacFtmUsed"="1"!]
        [!ELSEIF "node:value(GptModuleIsUsed) = 'true' and contains(GptIsrHwId, 'LPIT')"!][!//
            [!VAR "MacLPitUsed"="1"!]
        [!ELSEIF "node:value(GptModuleIsUsed) = 'true' and contains(GptIsrHwId, 'LPTMR')"!][!//
            [!VAR "MacLptmrUsed"="1"!]
        [!ELSEIF "node:value(GptModuleIsUsed) = 'true' and contains(GptIsrHwId, 'SRTC')"!][!//
            [!VAR "MacSRtcUsed"="1"!]
        [!ENDIF!][!//

    [!ENDLOOP!][!//
    [!LOOP "GptPredefTimerConfiguration/*"!][!//
        [!IF "contains(GptPredefTimer_1us_16Bit/GptHwChannel, 'FTM')"!][!//
            [!VAR "MacFtmUsed"="1"!]
        [!ENDIF!][!//
        [!IF "contains(GptPredefTimer_1us_16Bit/GptHwChannel, 'LPTMR')"!][!//
            [!VAR "MacLptmrUsed"="1"!]
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//


/**
* @brief These defines indicate that at least one chennel from each module is used in all configurations.
*
*/
#define GPT_SRTC_USED ([!IF "$MacSRtcUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_LPTMR_USED ([!IF "$MacLptmrUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_LPIT_USED ([!IF "$MacLPitUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define GPT_FTM_USED ([!IF "$MacFtmUsed=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @{
* @brief Symbolic names of channels
*/
[!VAR "AlreadyParsedNames"!][!ENDVAR!][!//
[!LOOP "GptChannelConfigSet/GptChannelConfiguration/*"!]
    [!IF "contains($AlreadyParsedNames, concat(node:name(.),'|')) = false()"!][!//
        /** @violates @ref GPT_CFG_H_REF_2 Identifier clash */
        #define [!"node:name(.)"!] ([!"GptChannelId"!]U)
        [!VAR "AlreadyParsedNames"="concat($AlreadyParsedNames,node:name(.),'|')"!][!//
    [!ENDIF!]
[!ENDLOOP!]
/*@}*/

/**
* @brief This define is a reserved logical channel name representing a not existing/configured
*        hardware channel.
*
*/
#define GPT_CHN_NOT_USED    (255U)

/**
* @brief   Single Interrupt.
*
*/
#define GPT_FTM_MODULE_SINGLE_INTERRUPT [!IF "ecu:get('Gpt.GptConfig.Gpt_FTM_ModuleSingleInterrupt')='STD_ON'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
#define GPT_LPIT_MODULE_SINGLE_INTERRUPT [!IF "ecu:get('Gpt.GptConfig.Gpt_LPIT_ModuleSingleInterrupt')='STD_ON'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @{
* @brief IRQ Defines
*/
[!CALL "GENERATE_ISR_USE","IPVType"="string('LPIT')"!]
[!CALL "GENERATE_ISR_USE","IPVType"="string('FTM')"!]
[!CALL "GENERATE_ISR_USE","IPVType"="string('LPTMR')"!]
[!CALL "GENERATE_ISR_USE","IPVType"="string('SRTC')"!]

/**
* @{
* @brief Defines for HW IPs will be used by GPT driver
*/
[!NOCODE!][!//
[!VAR "AlreadyParsedModule"!][!ENDVAR!][!//
[!LOOP "GptHwConfiguration/*"!][!//
[!IF "(GptModuleIsUsed = 'true')"!][!//
[!IF "contains($AlreadyParsedModule, concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])) = false()"!][!//
[!CODE!][!//
[!VAR "ModuleUsed"="concat(text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2])"!][!//
#define GPT_[!"$ModuleUsed"!]_USED
[!ENDCODE!][!//
[!VAR "AlreadyParsedModule"="concat($AlreadyParsedModule,text:split(GptIsrHwId,'_')[1], '_', text:split(GptIsrHwId,'_')[2],'|')"!][!//
[!ENDIF!][!//
[!ENDIF!]//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//

[!CODE!][!//
[!IF "(IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime' ) and (variant:size()<=1)"!][!//
#define GPT_PRECOMPILE_SUPPORT  (STD_ON)
[!ELSE!][!//
#define GPT_PRECOMPILE_SUPPORT  (STD_OFF)
[!ENDIF!][!//
[!ENDCODE!][!//

/**
* @brief The maxiumum number of HW channels. This is used to allocate memory space for channel runtime info.
*/
#define GPT_HW_CHANNEL_NUM   ([!"num:i(count(GptChannelConfigSet/GptChannelConfiguration/*))"!]U)

[!// Calculate the number of timer HW channels and HW modules
[!NOCODE!][!//
    [!INCLUDE "Gpt_PluginMacros.m"!]
[!ENDNOCODE!][!//

/**
* @brief The number of LPIT HW channels
*/
[!// Calculate the number of LPIT HW channels and HW modules
[!NOCODE!][!//
    [!CALL "CalculateModulesNumber","ModuleType"="string('LPIT')"!]
[!ENDNOCODE!][!//

#define GPT_LPIT_MODULES_NUM      ([!"num:i($OutModulesNumber)"!]U)

#define GPT_LPIT_CHAN_NUM         ([!"num:i($OutModulesNumber*4)"!]U)

[!// Calculate the number of Lptmr HW channels and HW modules
[!NOCODE!][!//
    [!CALL "CalculateModulesNumber","ModuleType"="string('LPTMR')"!]
[!ENDNOCODE!][!//

#define GPT_LPTMR_MODULES_NUM      ([!"num:i($OutModulesNumber)"!]U)

#define GPT_LPTMR_CHAN_NUM         ([!"num:i($OutModulesNumber*1)"!]U)


[!// Calculate the number of SRTC HW channels and HW modules
[!NOCODE!][!//
    [!CALL "CalculateModulesNumber","ModuleType"="string('SRTC')"!]
[!ENDNOCODE!][!//

#define GPT_SRTC_MODULES_NUM      ([!"num:i($OutModulesNumber)"!]U)

#define GPT_SRTC_CHAN_NUM         ([!"num:i($OutModulesNumber*1)"!]U)


[!// Calculate the number of Ftm HW channels
[!NOCODE!][!//
    [!CALL "CalculateModulesNumber","ModuleType"="string('FTM')"!]
[!ENDNOCODE!][!//


/**
* @brief The number of Ftm HW modules
*/
#define GPT_FTM_MODULES_NUM_U8   ([!"num:i($OutModulesNumber)"!]U)

/**
* @brief The number of Ftm HW channels
*/
#define GPT_FTM_MODULE_CHAN_NUM_U8      ([!"num:i($OutModulesNumber*8)"!]U)

/**
* @brief The total number of indexes used by the hardware to logic channel map
*/
#define GPT_CHANNEL_IDX_NUM    (GPT_FTM_MODULE_CHAN_NUM_U8 + GPT_LPIT_CHAN_NUM + GPT_LPTMR_CHAN_NUM + GPT_SRTC_CHAN_NUM)

/**
@{
@brief ID for peripheral. This ID need to match the order in the hardware to logic channels mapping table
*      because it is used as a base index.
*/
#define GPT_FTM_MODULE                         0U                                                           /** @brief index where the FTM channels start*/
#define GPT_LPIT_MODULE                       (GPT_FTM_MODULE_CHAN_NUM_U8)                                            /** @brief index where the LPIT channels start*/
#define GPT_LPTMR_MODULE                      (GPT_FTM_MODULE_CHAN_NUM_U8 + GPT_LPIT_CHAN_NUM)                        /** @brief index where the LPTMR channels start*/
#define GPT_SRTC_MODULE                       (GPT_FTM_MODULE_CHAN_NUM_U8 + GPT_LPIT_CHAN_NUM + GPT_LPTMR_CHAN_NUM)   /** @brief index where the SRTC channels start*/
/** @} */

#define GPT_HW_PREDEFTIMER_NUM                              (4U) /** @brief number for channels predef timer supported by the platform */

/**
*   @brief export configuration Gpt driver
*/

[!MACRO "GptExportDriverConfiguration"!]
[!NOCODE!][!//
[!VAR "configName" = "as:name(GptChannelConfigSet)"!][!//
[!CODE!][!//
/**
 * @violates @ref GPT_CFG_H_REF_3 MISRA 2004 Required Rule 19.4 C macros shall only expand to...
 */
#define GPT_CONF_PB \
[!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern CONST(Gpt_ConfigType, GPT_CONST) [!"$configName"!]_[!"."!];[!IF "$variantIndex < $variantNumber"!] \[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern CONST(Gpt_ConfigType, GPT_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
    [!CALL "GptExportDriverConfiguration"!]
[!ENDIF!]

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @brief Predef Timer type. Indicates the type of predef timer.
* @implements   Gpt_PredefTimerType_enumeration
*/
typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT = 0x0U,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;
#endif
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

#endif  /* GPT_CFG_H */

/** @} */
