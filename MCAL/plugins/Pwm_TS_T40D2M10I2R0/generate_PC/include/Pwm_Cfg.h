[!AUTOSPACING!]
[!CODE!]
/**
*   @file       Pwm_Cfg.h
*   @version    1.0.2
*
*   @brief      AUTOSAR Pwm - Pwm configuration file.
*   @details    Precompile parameters and extern configuration.
*
*   @addtogroup PWM_MODULE
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

[!NOCODE!]
    /* Below there are a couple of macros implementing methods for working with arrays 
       on top of strings. The arrays can store a variable number of integer entries,
       each integer being stored in decimal format using max 2 digits (0-99) */
    [!MACRO "ArrayDeclare", "Size"!]
        [!VAR "OutMyArray" = "''"!]
        [!FOR "i" = "1" TO "$Size"!]
            [!VAR "OutMyArray" = "concat($OutMyArray, '00')"!]
        [!ENDFOR!]
    [!ENDMACRO!]

    [!MACRO "ArraySetElement", "Index", "Value"!]
        [!IF "$Value < 10"!]
            [!VAR "MacSetElement" = "concat('0',string(num:i($Value)))"!]
        [!ELSE!] 
            [!VAR "MacSetElement" = "string(num:i($Value))"!]
        [!ENDIF!]  
        [!IF "$Index = 0"!]
            [!VAR "OutMyArray" = "concat($MacSetElement, substring($OutMyArray,3))"!]
        [!ELSE!] 
            [!VAR "OutMyArray" = "concat(substring($OutMyArray,1,$Index*2), $MacSetElement, substring($OutMyArray,$Index*2+3))"!]
        [!ENDIF!]
    [!ENDMACRO!]

    [!MACRO "ArrayGetElement", "Index"!]
        [!VAR "OutGetElement" = "number(substring($OutMyArray,$Index*2+1,2))"!]
    [!ENDMACRO!]

    /*Macro check define FlexIO pin used */
    [!MACRO "ArraySetElementFlexIO", "Index", "Value"!]
        [!VAR "MacSetElement" = "string(num:i($Value))"!]
        [!IF "$Index = 0"!]
            [!VAR "OutMyArray" = "concat($MacSetElement, substring($OutMyArray,2))"!]
        [!ELSE!]
            [!VAR "OutMyArray" = "concat(substring($OutMyArray,1,$Index), $MacSetElement, substring($OutMyArray,$Index+2))"!]   
        [!ENDIF!]   
    [!ENDMACRO!]

    /*Macro check define FlexIO pin used */
    [!MACRO "ArrayGetElementFlexIO", "Index"!]
        [!VAR "OutGetElementFlexIO" = "number(substring($OutMyArray,$Index,1))"!]
    [!ENDMACRO!]

    /* Variable storing number of Ftm Modules available on the current platform */
    [!VAR "numFtmModules" = "ecu:get('Pwm.PwmChannelConfigSet.Num_Ftm_Hw_Modules')"!]

     /* Variable storing number of FlexIO Modules available on the current platform */
    [!VAR "numFlexIOModules" = "ecu:get('Pwm.Num_FlexIO_Hw_Modules')"!]
    [!VAR "numFlexIOChannelsPerModule" = "ecu:get('Pwm.Num_FlexIO_Hw_Timers')"!]
    [!VAR "numFlexIOChannels" = "($numFlexIOModules * $numFlexIOChannelsPerModule)"!]

    /* Variable indicate related module is using or not */
    [!VAR "CheckFlexIO" = "0"!]
    [!VAR "CheckFtm" = "0"!]


    [!LOOP "PwmGeneral/PwmHwConfiguration/*"!]
        [!IF "(contains(PwmInterruptHwId,'FLEXIO')) and (PwmChannelIsUsed = 'true')"!]
            [!VAR "CheckFlexIO" = "$CheckFlexIO + 1"!]
        [!ELSEIF "(contains(PwmInterruptHwId,'FTM')) and (PwmChannelIsUsed = 'true')"!]
            [!VAR "CheckFtm" = "$CheckFtm + 1"!]
        [!ENDIF!]
    [!ENDLOOP!]


    /* Variable storing number of typical channels in related modules */
    [!VAR "NumPwmChannelsUsingFlexIO" = "0"!]
    [!VAR "NumPwmChannelsUsingFtm" = "0"!]

    [!SELECT "PwmChannelConfigSet"!]
        [!LOOP "PwmChannel/*"!]
            [!IF "contains(PwmHwIP,'FlexIO')"!]
                [!VAR "NumPwmChannelsUsingFlexIO" = "$NumPwmChannelsUsingFlexIO + 1"!]
            [!ENDIF!]
            [!IF "contains(PwmHwIP,'FTM')"!]
                [!VAR "NumPwmChannelsUsingFtm" = "$NumPwmChannelsUsingFtm + 1"!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDSELECT!]

[!ENDNOCODE!]

#ifndef PWM_CFG_H
#define PWM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Cfg_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_Cfg_H_REF_3
* Violates MISRA 2004 Required Rule 19.4, C macros should only extend to braced initializer,
* a constant, a paranthesised expression, a type qualifier, a storage class specifier or 
* a  do-while-zero construct. 
* Macro used to define external constant in order to reduce code complexity.*
*
* @section Pwm_Cfg_H_REF_4
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they
* are accessed from within a sigle function.
* These symbols are used in the entire driver.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "Pwm_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//
/** @violates @ref Pwm_Cfg_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Pwm_EnvCfg.h"
#include "Pwm_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Pwm_Cfg.h
*/
#define PWM_CFG_VENDOR_ID                         43
#define PWM_CFG_MODULE_ID                         121

#define PWM_CFG_AR_RELEASE_MAJOR_VERSION          4
#define PWM_CFG_AR_RELEASE_MINOR_VERSION          2
#define PWM_CFG_AR_RELEASE_REVISION_VERSION       2
#define PWM_CFG_SW_MAJOR_VERSION                  1
#define PWM_CFG_SW_MINOR_VERSION                  0
#define PWM_CFG_SW_PATCH_VERSION                  2
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (PWM_CFG_VENDOR_ID != PWM_CFG_ENV_VENDOR_ID)
    #error "Pwm_Cfg.h and Pwm_CfgEnv.h have different vendor ids"
#endif
/* Check if current file and Pwm_CfgEnv header file are of the same Autosar version */
#if (( PWM_CFG_AR_RELEASE_MAJOR_VERSION != PWM_CFG_ENV_AR_RELEASE_MAJOR_VERSION) || \
     ( PWM_CFG_AR_RELEASE_MINOR_VERSION != PWM_CFG_ENV_AR_RELEASE_MINOR_VERSION) || \
     ( PWM_CFG_AR_RELEASE_REVISION_VERSION !=  PWM_CFG_ENV_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Pwm_Cfg.h and Pwm_CfgEnv.h are different"
#endif
/* Check if current file and Pwm_CfgEnv header file are of the same software version */
#if ((PWM_CFG_SW_MAJOR_VERSION != PWM_CFG_ENV_SW_MAJOR_VERSION) || \
     (PWM_CFG_SW_MINOR_VERSION != PWM_CFG_ENV_SW_MINOR_VERSION) || \
     (PWM_CFG_SW_PATCH_VERSION != PWM_CFG_ENV_SW_PATCH_VERSION))
     #error "Software Version Numbers of Pwm_Cfg.h and Pwm_CfgEnv.h are different"
#endif

#if (PWM_CFG_VENDOR_ID != PWM_TYPES_VENDOR_ID)
    #error "Pwm_Cfg.h and Pwm_Types.h have different vendor ids"
#endif
/* Check if current file and Pwm_Types header file are of the same Autosar version */
#if (( PWM_CFG_AR_RELEASE_MAJOR_VERSION != PWM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( PWM_CFG_AR_RELEASE_MINOR_VERSION != PWM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( PWM_CFG_AR_RELEASE_REVISION_VERSION !=  PWM_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Pwm_Cfg.h and Pwm_Types.h are different"
#endif
/* Check if current file and Pwm_Types header file are of the same software version */
#if ((PWM_CFG_SW_MAJOR_VERSION != PWM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_CFG_SW_MINOR_VERSION != PWM_TYPES_SW_MINOR_VERSION) || \
     (PWM_CFG_SW_PATCH_VERSION != PWM_TYPES_SW_PATCH_VERSION))
     #error "Software Version Numbers of Pwm_Cfg.h and Pwm_Types.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       PLATFORM SPECIFIC DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          API service ID
*/
#define PWM_PROCESSNOTIFICATION_ID        (0x0AU)

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

[!VAR "DutySynchronous" = "0"!]
[!IF "(PwmGeneral/PwmMultiChannelSynch  = 'true') and ((PwmConfigurationOfOptApiServices/PwmSetDutyCycle_NoUpdate = 'false') and (PwmConfigurationOfOptApiServices/PwmSetPeriodAndDuty_NoUpdate = 'false') and (PwmConfigurationOfOptApiServices/PwmSetPhaseShift = 'false'))"!]
  [!ERROR "Please enable PwmSetDutyCycle_NoUpdate or PwmSetPeriodAndDuty_NoUpdate or PwmSetPhaseShift before enabling PwmMultiChannelSynch API "!] 
[!ELSE!]
   [!IF "(PwmGeneral/PwmMultiChannelSynch  = 'true')"!]
      [!VAR "DutySynchronous" = "1"!]
   [!ENDIF!]
[!ENDIF!]

/**
* @brief      Pwm Pre Compile Switch
*/
/**
 *   @brief Pre-compile configuration constants 
 */
[!IF " (IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' ) and (variant:size()<=1)"!]
#define PWM_PRECOMPILE_SUPPORT          (STD_ON)
[!ELSE!]
#define PWM_PRECOMPILE_SUPPORT          (STD_OFF)
[!ENDIF!]


/**
* @brief      Switch to indicate that Pwm_DeInit API is supported
*
*/
#define PWM_DE_INIT_API                       ([!IF "PwmConfigurationOfOptApiServices/PwmDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that Pwm_GetOutputState API is supported
*
*/
#define PWM_GET_OUTPUT_STATE_API              ([!IF "PwmConfigurationOfOptApiServices/PwmGetOutputState"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that Pwm_SetDutyCycle API is supported
*
*/
#define PWM_SET_DUTY_CYCLE_API                ([!IF "PwmConfigurationOfOptApiServices/PwmSetDutyCycle"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that Pwm_SetOutputToIdle API is supported
*
*/
#define PWM_SET_OUTPUT_TO_IDLE_API            ([!IF "PwmConfigurationOfOptApiServices/PwmSetOutputToIdle"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that Pwm_SetPeriodAndDuty API is supported
*
*/
#define PWM_SET_PERIOD_AND_DUTY_API           ([!IF "PwmConfigurationOfOptApiServices/PwmSetPeriodAndDuty"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that Pwm_GetVersionInfo API is supported
*
*/
#define PWM_VERSION_INFO_API                  ([!IF "PwmConfigurationOfOptApiServices/PwmVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that Pwm_GetChannelState API is supported
*
*/
#define PWM_GET_CHANNEL_STATE_API             ([!IF "PwmConfigurationOfOptApiServices/PwmGetChannelStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that Pwm_ForceOutputToZero API is supported
*
*/
#define PWM_FORCE_OUTPUT_TO_ZERO_API          ([!IF "PwmConfigurationOfOptApiServices/PwmForceOutputToZeroApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch for enabling the development error detection.
*
*/
#define PWM_DEV_ERROR_DETECT                  ([!IF "PwmGeneral/PwmDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch for enabling the update of the duty cycle parameter at the end of 
*             the current period
*
*/
#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD       ([!IF "PwmGeneral/PwmDutycycleUpdatedEndperiod"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch for enabling the update of the period parameter at the end of the current period
*
*/
#define PWM_DUTY_PERIOD_UPDATED_ENDPERIOD     ([!IF "PwmGeneral/PwmPeriodUpdatedEndperiod"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that the notifications are supported
*
*/
#define PWM_NOTIFICATION_SUPPORTED            ([!IF "PwmGeneral/PwmNotificationSupported"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that the Reload notifications are supported
*
*/
#define PWM_RELOAD_NOTIF_SUPPORTED            (STD_OFF)

/**
* @brief      Switch for enabling the fault functionality
*
*/
#define PWM_FAULT_SUPPORTED                   ([!IF "PwmGeneral/PwmFaultSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


/**
* @brief      Switch to indicate that Pwm_SetChannelOutput API is supported
*
*/
#define PWM_SET_CHANNEL_OUTPUT_API            (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_SetTriggerDelay API is supported
*
*/
#define PWM_SET_TRIGGER_DELAY_API             (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_BufferTransferEnableDisable API is supported
*
*/
#define PWM_BUFFER_TRANSFER_EN_DIS_API        (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_SetCounterBus API is supported
*
*/
#define PWM_SET_COUNTER_BUS_API               (STD_OFF)

/**
* @brief      Switch for enabling the dual clock functionality (Pwm_SetClockMode API)
*
*/
#define PWM_SET_CLOCK_MODE_API                ([!IF "PwmGeneral/PwmEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch for enabling Pwm_SetPhaseShift API
*
*/
#define PWM_SET_PHASE_SHIFT_API               ([!IF "PwmConfigurationOfOptApiServices/PwmSetPhaseShift"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/**
* @brief      Switch for enabling Pwm_SetPhaseShift_NoUpdate API
*
*/
#define PWM_SET_PHASE_SHIFT_NO_UPDATE_API     ([!IF "(PwmConfigurationOfOptApiServices/PwmSetPhaseShiftNoUpdate = 'true') and (PwmGeneral/PwmMultiChannelSynch = 'true' )"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch for enabling Pwm_EnableTrigger API
*
*/
#define PWM_ENABLE_TRIGEER_API                ([!IF "PwmConfigurationOfOptApiServices/PwmEnableTrigger"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch for enabling Pwm_DisableTrigger API
*
*/
#define PWM_DISABLE_TRIGEER_API               ([!IF "PwmConfigurationOfOptApiServices/PwmDisableTrigger"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch for enabling Pwm_SwResetCounter API
*
*/
#define PWM_RESET_COUNTER_API                 ([!IF "PwmConfigurationOfOptApiServices/PwmSwResetCounter"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch for enabling MaskOutput API
*
*/
#define PWM_ENABLE_MASKING_OPERATIONS         ([!IF "PwmGeneral/EnableMaskingOperations"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that Pwm_SyncUpdate API is supported
*
*/
#define PWM_SYNC_UPDATE_API                   ([!IF "$DutySynchronous = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that the notifications are supported
*
*/
#define PWM_UPDATE_DUTY_SYNCHRONOUS           ([!IF "$DutySynchronous = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that PwmSetDutyCycle_NoUpdate API is supported
*
*/
#define PWM_SET_DUTY_CYCLE_NO_UPDATE_API      ([!IF "(PwmConfigurationOfOptApiServices/PwmSetDutyCycle_NoUpdate = 'true') and (PwmGeneral/PwmMultiChannelSynch = 'true' )"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


/**
* @brief      Switch to indicate that PwmSetPeriodAndDuty_NoUpdate API is supported
*
*/
#define PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API  ([!IF "(PwmConfigurationOfOptApiServices/PwmSetPeriodAndDuty_NoUpdate = 'true') and (PwmGeneral/PwmMultiChannelSynch = 'true' )"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


/**
* @brief Support for User mode.
*        If this parameter has been configured to 'TRUE' the Pwm driver code can be executed from both supervisor and user mode.
*
*/  
[!IF "node:exists(PwmGeneral/PwmEnableUserModeSupport)"!][!//
#define PWM_ENABLE_USER_MODE_SUPPORT         ([!IF "PwmGeneral/PwmEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!]
#define PWM_ENABLE_USER_MODE_SUPPORT         (STD_OFF)
[!ENDIF!]

/* @brief common interrupt */
#define PWM_FTM_MODULE_SINGLE_INTERRUPT      ([!IF "ecu:get('Pwm.PwmConfig.Pwm_FTM_ModuleSingleInterrupt')='STD_ON'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Specifies the InstanceId of this module instance.
* @details    Specifies the InstanceId of this module instance.
*             If only one instance is present it shall have the Id 0.
*             Not used in the current implementation
*
*/
#define PWM_INDEX                             ([!"PwmGeneral/PwmIndex "!]U)


/**
* @brief      Switch to indicate that platform-specific validations of the notification function are supported
*
*/
#define PWM_NOTIFICATON_PLAUSABILITY          (STD_ON)

/**
* @brief      Switch to indicate that platform-specific validation of the offset (phase shift) of duty-cycle is supported
*
*/
#define PWM_OFFSET_PLAUSABILITY               (STD_OFF)

/**
* @brief      Switch to indicate that platform-specific validation of the period is supported
*
*/
#define PWM_MAX_PERIOD_PLAUSABILITY           (STD_ON)

/**
* @brief      Switch to indicate that platform-specific validation of the period is supported
*
*/
#define PWM_SETOUTPUTTOIDLE_PLAUSABILITY      (STD_ON)

/**
* @brief      Switch for enabling external trigger generation
*
*/
#define PWM_FTM_ENABLE_EXT_TRIGGERS           ([!IF "PwmGeneral/PwmFtmEnableExtTrigger"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch for enabling phase shift feature
*
*/
#define PWM_ENABLE_PHASE_SHIFT                ([!IF "PwmGeneral/PwmEnablePhaseShift"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      FTM is not supported
*
*/
#define PWM_ALLOW_SUBMODULE_SYNC              (STD_OFF)

/**
* @brief Symbolic Names for configured channels - legacy
*/
[!LOOP "PwmChannelConfigSet/PwmChannel/*"!]
#define [!"node:name(.)"!]         ((Pwm_ChannelType)[!"PwmChannelId"!]U)
[!ENDLOOP!]

/** 
* @brief           Symbolic Names for configured channels - ecuc 2108 compliant.
*/

[!LOOP "PwmChannelConfigSet/PwmChannel/*"!]
#define  PwmConf_PwmChannelConfigSet_[!"node:name(.)"!]         ((Pwm_ChannelType)[!"PwmChannelId"!]U)
[!ENDLOOP!]


/**
* @brief        Define to indicate FlexIO is used
*
*/
#define PWM_FLEXIO_USED                         ([!IF "$CheckFlexIO != 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])    


/**
* @brief        Define to indicate Ftm is used
*
*/
#define PWM_FTM_USED                            ([!IF "$CheckFtm != 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


[!IF "($CheckFlexIO != 0)"!]
/** @brief   Macros used to enable timer for FlexIO module */
    [!NOCODE!]
        /* Loop through all Pwm channels using FlexIO */
        /* Array of boolean flags stating that a define for a given FlexIO channel has already been created */
        [!CALL "ArrayDeclare", "Size" = "$numFlexIOModules * 4"!]
        [!VAR "check_0_1" = "0"!]
        [!VAR "check_2_3" = "0"!]
        [!LOOP "PwmChannelConfigSet/PwmChannel/*"!]
            [!IF "contains(PwmHwIP,'FlexIO')"!]
                [!VAR "FlexIOMod" = "substring-after(node:ref(PwmFlexIOChannel)/../../PwmFlexIOHardWareModule,'FlexIO_')"!]
                [!VAR "FlexIOCh"  = "substring-after(node:ref(PwmFlexIOChannel)/PwmFlexIOTimer,'Timer_')"!]
                /* If Pwm channel notification is enabled, create define to state that FlexIO channel
                ISR is used. There is no need to keep a flag to state that the FlexIO channel has already
                been processed because no FlexIO channel should be used by more than one Pwm channel */
                [!CALL "ArrayGetElement", "Index" = "num:i($FlexIOCh)"!]
                [!IF "num:i($OutGetElement) = 0"!]
                    [!IF "(($FlexIOCh = 0) or ($FlexIOCh = 1)) and ($check_0_1 = 0)"!]
                       [!VAR "check_0_1" = "1"!]
                       [!CODE!]
#define PWM_FLEXIO_[!"$FlexIOMod"!]_CH_0_1_USED
                       [!ENDCODE!]
                    [!ENDIF!]
                    
                    [!IF "(($FlexIOCh = 2) or ($FlexIOCh = 3)) and ($check_2_3 = 0) "!]
                       [!VAR "check_2_3" = "1"!]
                        [!CODE!]
#define PWM_FLEXIO_[!"$FlexIOMod"!]_CH_2_3_USED
                        [!ENDCODE!]
                    [!ENDIF!]
                    /* Set flag stating that this FlexIO Submodule ISR define has been created */
                    [!CALL "ArraySetElement", "Index" = "num:i($FlexIOCh)", "Value" = "1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDNOCODE!]
[!ENDIF!]

[!IF "$CheckFlexIO != 0"!]
/** @brief   Macros used to avoid conflic FlexIO pin with orther module */
    [!CALL "ArrayDeclare", "Size" = "$numFlexIOModules * 4"!]
    [!LOOP "PwmChannelConfigSet/PwmChannel/*"!]
        [!IF "contains(PwmHwIP,'FlexIO')"!]
            [!VAR "FlexIOMod" = "substring-after(node:ref(PwmFlexIOChannel)/../../PwmFlexIOHardWareModule,'FlexIO_')"!]
            [!VAR "FlexIOPin" = "substring-after(node:ref(PwmFlexIOChannel)/PwmFlexIOChannelId,'Channel_')"!]
            [!CALL "ArrayGetElementFlexIO", "Index" = "num:i($FlexIOPin) + 1"!]
                [!IF "num:i($OutGetElementFlexIO) = 0"!]
                    [!CODE!]
#define PWM_FLEXIO_[!"$FlexIOMod"!]_PIN_[!"$FlexIOPin"!]_USED
                    [!ENDCODE!]
                [!ENDIF!]
            [!CALL "ArraySetElementFlexIO", "Index" = "num:i($FlexIOPin)", "Value" = "1"!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDIF!]


[!NOCODE!]
    [!VAR "FlexIOInterruptUsed" = "0"!]

    [!IF "(PwmGeneral/PwmNotificationSupported = 'true') and ($CheckFlexIO != 0)"!]
        [!LOOP "PwmGeneral/PwmHwConfiguration/*"!]
            [!IF "(contains(PwmInterruptHwId, 'FLEXIO')) and (PwmInterruptEnable = 'true')"!]        
                [!VAR "FlexIOInterruptUsed" = "1"!]
            [!ENDIF!] 
        [!ENDLOOP!]
    [!ENDIF!]

    [!IF "$FlexIOInterruptUsed != 0"!]
        [!CODE!]
/**
* @brief        Macros used to enable ISR for FlexIO module
*
*/
        [!ENDCODE!]
        [!NOCODE!]
            /* Loop through all Pwm channels using FlexIO */
            /* Array of boolean flags stating that a define for a given FlexIO channel has already been created */
            [!CALL "ArrayDeclare", "Size" = "$numFlexIOModules * 4"!]
            [!VAR "check_0_1" = "0"!]
            [!VAR "check_2_3" = "0"!]
            [!LOOP "PwmChannelConfigSet/PwmChannel/*"!]
                [!IF "contains(PwmHwIP,'FlexIO')"!]
                    [!VAR "FlexIOMod" = "substring-after(node:ref(PwmFlexIOChannel)/../../PwmFlexIOHardWareModule,'FlexIO_')"!]
                    [!VAR "FlexIOCh"  = "substring-after(node:ref(PwmFlexIOChannel)/PwmFlexIOTimer,'Timer_')"!]
                    /* If Pwm channel notification is enabled, create define to state that FlexIO channel
                    ISR is used. There is no need to keep a flag to state that the FlexIO channel has already
                    been processed because no FlexIO channel should be used by more than one Pwm channel */
                    [!CALL "ArrayGetElement", "Index" = "num:i($FlexIOCh)"!]
                    [!IF "num:i($OutGetElement) = 0"!]
                        [!IF "(($FlexIOCh = 0) or ($FlexIOCh = 1)) and ($check_0_1 = 0)"!]
                           [!VAR "check_0_1" = "1"!]
                           [!CODE!]
#define PWM_FLEXIO_[!"$FlexIOMod"!]_CH_0_1_ISR_USED
                           [!ENDCODE!]
                        [!ENDIF!]
                        
                        [!IF "(($FlexIOCh = 2) or ($FlexIOCh = 3)) and ($check_2_3 = 0) "!]
                           [!VAR "check_2_3" = "1"!]
                            [!CODE!]
#define PWM_FLEXIO_[!"$FlexIOMod"!]_CH_2_3_ISR_USED
                            [!ENDCODE!]
                        [!ENDIF!]
                     /* Set flag stating that this FlexIO Submodule ISR define has been created */
                        [!CALL "ArraySetElement", "Index" = "num:i($FlexIOCh)", "Value" = "1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
        [!ENDNOCODE!]   
    [!ENDIF!]    
[!ENDNOCODE!]


/** @brief Macros used to lock for Pwm mode Ftm modules in current configuration */
[!FOR "i" = "0" TO "7"!]
[!VAR "FtmModuleUsed" = "'false'"!]
[!LOOP "PwmGeneral/PwmHwConfiguration/*"!]
    [!IF "PwmChannelIsUsed = 'true' and contains(PwmInterruptHwId, concat('FTM_',$i)) and not(contains(PwmInterruptHwId, 'FAULT')) and not(contains(PwmInterruptHwId, 'TOF'))"!]
        [!VAR "FtmModuleUsed" = "'true'"!]
    [!ENDIF!]
[!ENDLOOP!]
[!IF "$FtmModuleUsed = 'true'"!]
#define PWM_FTM_[!"$i"!]_USED
[!ENDIF!]
[!ENDFOR!]

[!IF "PwmGeneral/PwmNotificationSupported"!]
/**
* @brief ISRs configured for Pwm channels FTM module
*
@{
*/
[!IF "ecu:get('Pwm.PwmConfig.Pwm_FTM_ModuleSingleInterrupt')='STD_OFF'"!]
    [!FOR "ModuleIdx" = "0" TO "7"!]
    [!FOR "ChannelIdx" = "0" TO "3"!]
    [!VAR "ChannelIsrUsed" = "'false'"!]
    [!LOOP "PwmGeneral/PwmHwConfiguration/*"!]
        [!IF "PwmInterruptEnable = 'true' and contains(PwmInterruptHwId, concat('FTM_',$ModuleIdx)) and (contains(PwmInterruptHwId, concat('CH_',num:i($ChannelIdx)*2)) or contains(PwmInterruptHwId, concat('CH_',num:i($ChannelIdx)*2 + 1)))"!]
            [!VAR "ChannelIsrUsed" = "'true'"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$ChannelIsrUsed = 'true'"!] 
#define PWM_FTM_[!"$ModuleIdx"!]_CH_[!"num:i($ChannelIdx*2)"!]_CH_[!"num:i($ChannelIdx*2+1)"!]_ISR_USED
    [!ENDIF!]
    [!ENDFOR!]
    [!ENDFOR!]
[!ELSE!]
    [!FOR "ModuleIdx" = "0" TO "7"!]
    [!VAR "ChannelIsrUsed" = "'false'"!]
    [!LOOP "PwmGeneral/PwmHwConfiguration/*"!]
        [!IF "PwmInterruptEnable = 'true' and contains(PwmInterruptHwId, concat('FTM_',$ModuleIdx))"!]
            [!VAR "ChannelIsrUsed" = "'true'"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$ChannelIsrUsed = 'true'"!]
#define PWM_FTM_[!"$ModuleIdx"!]_ISR_USED
    [!ENDIF!]
    [!ENDFOR!]
[!ENDIF!]


/**
* @brief ISRs configured for OVF
*
@{
*/
[!FOR "i" = "0" TO "7"!]
[!VAR "FtmModuleOvfUsed" = "'false'"!]
[!LOOP "PwmGeneral/PwmHwConfiguration/*"!]
    [!IF "PwmInterruptEnable = 'true' and contains(PwmInterruptHwId, concat('FTM_',$i)) and contains(PwmInterruptHwId,'TOF')"!]
        [!VAR "FtmModuleOvfUsed" = "'true'"!]
    [!ENDIF!]
[!ENDLOOP!]
[!IF "$FtmModuleOvfUsed = 'true'"!]
#define PWM_FTM_[!"$i"!]_OVF_ISR_USED
[!ENDIF!]
[!ENDFOR!]
[!ENDIF!]


[!IF "PwmGeneral/PwmFaultSupport = 'true'"!]
/**
* @brief      Macros used to enable Ftm Fault ISR code
*
*/
[!FOR "i" = "0" TO "7"!]
[!VAR "FtmModuleFaultUsed" = "'false'"!]
[!LOOP "PwmGeneral/PwmHwConfiguration/*"!]
    [!IF "PwmInterruptEnable = 'true' and contains(PwmInterruptHwId, concat('FTM_',$i)) and contains(PwmInterruptHwId,'FAULT')"!]
        [!VAR "FtmModuleFaultUsed" = "'true'"!]
    [!ENDIF!]
[!ENDLOOP!]
[!IF "$FtmModuleFaultUsed = 'true'"!]
#define PWM_FTM_[!"$i"!]_FAULT_ISR_USED
[!ENDIF!]
[!ENDFOR!]

[!ENDIF!]


[!NOCODE!]
    [!IF "$CheckFlexIO != 0"!]
       [!CODE!]
/* @brief This define specifies the number of FlexIO modules available on the current platform */
#define PWM_FLEXIO_MODULE_NO            ([!"num:i($numFlexIOModules)"!]U)

/* @brief maximum number of FlexIO hardware channels */
#define PWM_FLEXIO_CHANNELS_MAX_U8      ([!"num:i($numFlexIOChannels)"!]U)
       [!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!]

[!NOCODE!]
    [!IF "$CheckFtm != 0"!]
       [!CODE!]
/*@brief This define specifies the number of fault channels per module */
#define PWM_FTM_MODULE_FAULT_NO         (4U)

/* @brief maximum number of FTM modules configurable on this platform */
#define PWM_FTM_MODULE_NO               ([!"ecu:get('Pwm.PwmChannelConfigSet.Num_Ftm_Hw_Modules')"!]U)

/* @brief This define specifies the number of channels per each module */
#define PWM_FTM_MODULE_CHANNELS_NO      (8U)

/* @brief maximum number of FTM hardware channels */
#define PWM_FTM_CHANNELS_NO             (PWM_FTM_MODULE_CHANNELS_NO * PWM_FTM_MODULE_NO)
       [!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!]

/* @brief maximum number of hardware channels and modules configurable on this platform = modules * channels */
#define PWM_HW_CHANNELS_NO_U8           ((uint8)0U[!IF "$CheckFlexIO != 0"!] + PWM_FLEXIO_CHANNELS_MAX_U8[!ENDIF!][!IF "$CheckFtm != 0"!] + PWM_FTM_CHANNELS_NO[!ENDIF!])

#define PWM_HW_MODULES_CFG_U8           ((uint8)0U[!IF "$CheckFtm != 0"!] + PWM_FTM_MODULE_NO[!ENDIF!])

/** @brief Symbolic Name for period det error */
#if ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
    #define PWM_E_PERIODVALUE           (0x1AU)
#endif

/** @brief Defines the maximum value of the period - this value is hardware/platform dependent */
#define PWM_MAX_PERIOD                  (0xFFFFU)

[!NOCODE!]
    [!IF "$CheckFlexIO != 0"!]
        [!CODE!]
/** @brief Maximum number of FlexIO channels configured */     
#define PWM_FLEXIO_CHANNEL_NO              ([!IF "$NumPwmChannelsUsingFlexIO != 0"!][!"num:i($NumPwmChannelsUsingFlexIO)"!]U[!ELSE!]1U[!ENDIF!])
        [!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!]

[!NOCODE!]
    [!IF "$CheckFtm != 0"!]
        [!CODE!]
/** @brief Maximum number of FTM channels configured */
#define PWM_FTM_CHANNELS_MAX_U8            ([!IF "$NumPwmChannelsUsingFtm != 0"!][!"num:i($NumPwmChannelsUsingFtm)"!]U[!ELSE!]1U[!ENDIF!])
        [!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!]

[!NOCODE!]
    [!IF "(PwmGeneral/PwmNotificationSupported = 'true') and ($CheckFlexIO != 0)"!]
        [!CODE!]
/**
* @brief        First entries in the array of hardware to logic mapping are taken by the FlexIO channels
*
*/
#define IDX_FIRST_FLEXIO_CH_IN_HW_REVERSE_MAP   (0U)
        [!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!]
[!NOCODE!]
    [!IF "(PwmGeneral/PwmNotificationSupported = 'true') and ($CheckFtm != 0)"!]
        [!CODE!]

/**
* @brief        First entries in the array of hardware to logic mapping are taken by the eMIOS channels
*
*/
#define IDX_FIRST_FTM_CH_IN_HW_REVERSE_MAP    (0U[!IF "$CheckFlexIO != 0"!] + PWM_FLEXIO_CHANNELS_MAX_U8[!ENDIF!])
        [!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!]


/**
* @brief   Switch to enable that power state mode is supported
*
*/
[!IF "node:exists(PwmGeneral/PwmLowPowerStatesSupport)"!]
#define PWM_POWER_STATE_SUPPORTED  ([!IF "PwmGeneral/PwmLowPowerStatesSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!]
#define PWM_POWER_STATE_SUPPORTED  (STD_OFF)
[!ENDIF!]
[!IF "node:exists(PwmGeneral/PwmPowerStateAsynchTransitionMode)"!]
#define PWM_POWER_STATE_ASYNCH_MODE_SUPPORTED  ([!IF "PwmGeneral/PwmPowerStateAsynchTransitionMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!]
#define PWM_POWER_STATE_ASYNCH_MODE_SUPPORTED  (STD_OFF)
[!ENDIF!]

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
[!NOCODE!][!//
[!VAR "configName" = "as:name(PwmChannelConfigSet)"!][!//
/* @violates @ref Pwm_Cfg_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
[!CODE!][!//
/* @violates @ref Pwm_Cfg_H_REF_3 MISRA 2004 Required Rule 19.4, C macros should only extend to braced initializer */
#define PWM_CONF_PB \
[!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern CONST(Pwm_ConfigType, PWM_CONST) [!"$configName"!]_[!"."!];[!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern CONST(Pwm_ConfigType, PWM_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDIF!]

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief      Pwm Period type (the value of the period is platform dependent and thus configurable)
* @implements Pwm_PeriodType_typedef
*/
typedef uint16 Pwm_PeriodType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif    /*PWM_CFG_H*/

/** @} */

[!ENDCODE!]
