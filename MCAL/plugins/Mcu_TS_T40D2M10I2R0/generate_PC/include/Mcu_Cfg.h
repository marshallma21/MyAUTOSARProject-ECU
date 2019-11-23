/**
*  @file    Mcu_Cfg.h
*  @implements Mcu_Cfg.h_Artifact
*  @version 1.0.2
*
*   @brief   AUTOSAR Mcu - Configuration file for the driver.
*   @details Precompile parameters and extern configuration.
*
*  @addtogroup MCU
*  @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : MC
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


#ifndef MCU_CFG_H
#define MCU_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_CFG_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_CFG_H_REF_2
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to braced initialiser,
* a constant, a parenthesised expression, a type qualifier, a storage class specifier, or
* a do-while-zero construct
*
* @section Mcu_CFG_H_REF_3
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
* @section Mcu_CFG_H_REF_5
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_CFG_H_REF_6
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_CFG_VENDOR_ID                        43
#define MCU_CFG_AR_RELEASE_MAJOR_VERSION         4
#define MCU_CFG_AR_RELEASE_MINOR_VERSION         2
#define MCU_CFG_AR_RELEASE_REVISION_VERSION      2
#define MCU_CFG_SW_MAJOR_VERSION                 1
#define MCU_CFG_SW_MINOR_VERSION                 0
#define MCU_CFG_SW_PATCH_VERSION                 2
#define MCU_MODULE_ID                            101

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_CFG_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_CFG_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_Cfg.h and Mcal.h are different"
    #endif
#endif

[!INCLUDE "Mcu_VersionCheck_Inc.m"!][!//
/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
/**
* @brief      Specifies the InstanceId of this module instance.
*/
#define MCU_INSTANCE_ID                 ((uint8)0x0U)

/**
@{
* @brief            Service Ids for MCU APIs.
*/
#define MCU_INIT_ID                     ((uint8)0x00U)
#define MCU_INITRAMSECTION_ID           ((uint8)0x01U)
#define MCU_INITCLOCK_ID                ((uint8)0x02U)
#define MCU_DISTRIBUTEPLLCLOCK_ID       ((uint8)0x03U)
#define MCU_GETPLLSTATUS_ID             ((uint8)0x04U)
#define MCU_GETRESETREASON_ID           ((uint8)0x05U)
#define MCU_GETRESETRAWVALUE_ID         ((uint8)0x06U)
#define MCU_PERFORMRESET_ID             ((uint8)0x07U)
#define MCU_SETMODE_ID                  ((uint8)0x08U)
#define MCU_GETVERSIONINFO_ID           ((uint8)0x09U)
#define MCU_GETRAMSTATE_ID              ((uint8)0x0AU)

#define MCU_GETPERIPHERALSTATE_ID       ((uint8)0x0CU)
#define MCU_GETMIDRSTRUCTURE_ID         ((uint8)0x14U)
#define MCU_DISABLECMU_ID               ((uint8)0x17U)
#define MCU_SRAMRETENCONFIG_ID          ((uint8)0x18U)
/**@}*/

/**
@{
* @brief            Default error values are of type uint8.
*                   The following errors and exceptions shall be detectable by the MCU module depending on its
*                   build version (default/production mode).
*
*/
#define MCU_E_PARAM_CONFIG              ((uint8)0x0AU)
#define MCU_E_PARAM_CLOCK               ((uint8)0x0BU)
#define MCU_E_PARAM_MODE                ((uint8)0x0CU)
#define MCU_E_PARAM_RAMSECTION          ((uint8)0x0DU)
#define MCU_E_PLL_NOT_LOCKED            ((uint8)0x0EU)
#define MCU_E_UNINIT                    ((uint8)0x0FU)
#define MCU_E_PARAM_POINTER             ((uint8)0x10U)
#define MCU_E_INIT_FAILED               ((uint8)0x11U)
#define MCU_E_ALLREADY_INITIALIZED      ((uint8)0x13U)
#define MCU_E_CMU_INDEX_OUT_OF_RANGE    ((uint8)0x22U)
/**@}*/

/**
@{
* @brief            Error ISR values are of type uint8.
*                   The following error codes are reported by the error ISR.
*/
#define MCU_E_ISR_CLOCK_FAILURE                 ((uint8)0x01U)
#define MCU_E_ISR_PLL_LOCK_FAILURE              ((uint8)0x02U)
#define MCU_E_ISR_VOLTAGE_ERROR                 ((uint8)0x06U)
#define MCU_E_ISR_RESET_ALT_FAILURE             ((uint8)0x08U)
/**@}*/

#define MCU_HSRUN_MODE_NOT_SUPPORT [!IF "ecu:get('MCU.HsrunSystemClkSource.Exist') = 'false'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Pre-processor switch to enable/disable the field CGCGPIO of regester SIM_PLATCGC
*                   This bit is available in S32K11X variants only
*/
#define MCU_PLATGC_GPIO_CLK_SUPPORT [!IF "ecu:get('MCU.HsrunSystemClkSource.Exist') = 'false'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Pre-processor switch for enabling the development error detection and reporting to the DET.
*                   The detection of development errors is configurable (ON / OFF) at pre-compile time.
*/
#define MCU_DEV_ERROR_DETECT   [!IF "McuGeneralConfiguration/McuDevErrorDetect = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the System Integration Module (SIM) initialization has to be disabled from the MCU driver.
*/
#define MCU_DISABLE_SIM_INIT   [!IF "McuGeneralConfiguration/McuDisableSimInit = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the Reset Control Module (RMC) initialization has to be disabled from the MCU driver.
*/
#define MCU_DISABLE_RCM_INIT   [!IF "McuGeneralConfiguration/McuDisableRcmInit = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the Power Management Controller (PMC) initialization has to be disabled from the MCU driver.
*/
#define MCU_DISABLE_PMC_INIT   [!IF "McuGeneralConfiguration/McuDisablePmcInit = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            If this parameter is set to TRUE, the System Mode Controller (SMC) initialization has to be disabled from the MCU driver.
*/
#define MCU_DISABLE_SMC_INIT   [!IF "McuGeneralConfiguration/McuDisableSmcInit = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Pre-processor switch to enable/disable the API to read out the modules version information.
*/
#define MCU_VERSION_INFO_API   [!IF "McuGeneralConfiguration/McuVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            Pre-processor switch to enable/disable the API Mcu_GetRamState.
*/
#define MCU_GET_RAM_STATE_API   [!IF "McuGeneralConfiguration/McuGetRamStateApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            If this parameter is set to FALSE, the clock initialization has to be disabled from the MCU driver.
*/
#define MCU_INIT_CLOCK   [!IF "McuGeneralConfiguration/McuInitClock = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            This parameter shall be set True, if the H/W does not have a PLL or the PLL circuitry is enabled after the power on without S/W intervention.
*/
#define MCU_NO_PLL   [!IF "McuGeneralConfiguration/McuNoPll = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            Number of available CMU units.
*/
#define MCU_CMU_UNITS   ((uint8)[!"ecu:get('MCU.CMU.UNITS')"!]U)


/**
* @brief            define for interrupt CMU, PMC, SCG peripheral
*/
#define MCU_CMU_PMC_SCG_INTERRUPT  [!IF "num:i(ecu:get('MCU.CMU.UNITS')) > num:i(0)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            Support for Low Power mode.
*                   If this parameter has been configured to 'TRUE', the function 'Mcu_SetMode()' shall not be impacted and behave as specified.
* @requirements     PR-MCAL-3184
*/
#define MCU_ENTER_LOW_POWER_MODE   [!IF "McuGeneralConfiguration/McuEnterLowPowerMode = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            The function Mcu_PerformReset is only available if the runtime parameter McuPerformResetApi is set to TRUE.
*/
#define MCU_PERFORM_RESET_API   [!IF "McuGeneralConfiguration/McuPerformResetApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/**
* @brief            Timeout representing the number of loops for preventing to lock inside am infinite while/for.
*/
#define MCU_TIMEOUT_LOOPS   ((uint32)[!"McuGeneralConfiguration/McuTimeout"!]U)


/**
* @brief            The user callout reset is/isn't available (STD_ON/STD_OFF) - called by MCU right before Mcu_PerformReset().
*/
#define MCU_RESET_CALLOUT_USED   [!IF "node:exists(McuGeneralConfiguration/McuCalloutBeforePerformReset)"!][!IF "McuGeneralConfiguration/McuCalloutBeforePerformReset"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!ELSE!](STD_OFF)[!ENDIF!]


[!IF "node:fallback(McuGeneralConfiguration/McuPerformResetApi, 'true') = 'true'"!][!IF "node:fallback(McuGeneralConfiguration/McuCalloutBeforePerformReset, 'true') = 'true'"!]
#if (MCU_RESET_CALLOUT_USED == STD_ON)
/**
* @brief            The callout reset procedure configured by the user.
*/
#define MCU_RESET_CALLOUT   ([!"normalize-space(McuGeneralConfiguration/McuPerformResetCallout)"!])
#endif /* (MCU_RESET_CALLOUT_USED == STD_ON) */
[!ENDIF!][!ENDIF!]


[!IF "node:exists(McuGeneralConfiguration/McuCmuNotification)"!]
/**
* @brief            The callout configured by the user for CMU notifications.
*/
/** @violates @ref Mcu_CFG_H_REF_6 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MCU_CMU_FCCU_NOTIFICATION(u8IndexCmu) ([!"normalize-space(McuGeneralConfiguration/McuCmuNotification)"!](u8IndexCmu))
[!ENDIF!]


[!IF "node:exists(McuGeneralConfiguration/McuErrorIsrNotification)"!]
/**
* @brief            The callout configured by the user for CMU notifications.
*/
/** @violates @ref Mcu_CFG_H_REF_6 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for configurable callbacks.*/
#define MCU_ERROR_ISR_NOTIFICATION(u8ErrorCode) ([!"normalize-space(McuGeneralConfiguration/McuErrorIsrNotification)"!](u8ErrorCode))
[!ENDIF!]

/**
* @brief            ISR Mcu_VoltageError_ISR is/isn't available (STD_ON/STD_OFF)
*/
#define MCU_VOLTAGE_ERROR_ISR_USED   [!IF "McuModuleConfiguration/McuInterruptEvents/McuVoltageErrorEvent = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            ISR Mcu_VoltageError_ISR is/isn't available (STD_ON/STD_OFF)
*/
#define MCU_TEMPERATURE_ERROR_ISR_USED   (STD_OFF)

/**
* @brief            ISR Mcu_ResetAlternate_ISR is/isn't available (STD_ON/STD_OFF)
*/
#define MCU_RESET_ALTERNATE_ISR_USED            [!IF "McuModuleConfiguration/McuInterruptEvents/McuAlternateResetEvent = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API Mcu_GetPeripheral_State() for getting infos about peripheral state from MC_ME module.
*/
#define MCU_GET_PERIPH_STATE_API   [!IF "McuDebugConfiguration/McuGetPeriphStateApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API Mcu_GetSystem_State() for getting infos system platform configuration.
*/
#define MCU_GET_SYSTEM_STATE_API   (STD_OFF)

/**
* @brief            Enable the usage of Non-Autosar API Mcu_GetPowerMode_State() for getting infos system platform configuration.
*/
#define MCU_POWERMODE_STATE_API    (STD_OFF)

/**
* @brief            Enable the usage of Non-Autosar API Mcu_GetPowerDomain_Status. Get PMU state: operable or not.
*/
#define MCU_GET_POWER_DOMAIN_API    (STD_OFF)

/**
* @brief            ISR Mcu_PllDigPll0_LossOfLock_ISR is/isn't available (STD_ON/STD_OFF)
*/
#define MCU_SPLL_ISR_USED [!IF "McuModuleConfiguration/McuClockSettingConfig/*/McuSystemPll/McuSPLLClockMonitorResetEnable = 'false'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API Mcu_SscmGetMemConfig(). Get SSCM_MEMCONFIG.
*/
#define MCU_GET_MEM_CONFIG_API   (STD_OFF)

/**
* @brief            Enable the usage of Non-Autosar API Mcu_SscmGetStatus(). Get SSCM_STATUS.
*/
#define MCU_SSCM_GET_STATUS_API   (STD_OFF)

/**
* @brief            Enable the usage of Non-Autosar API Mcu_SscmGetUops(). Get SSCM_UOPS.
*/
#define MCU_SSCM_GET_UOPS_API     (STD_OFF)

/**
* @brief            Enable the usage of Non-Autosar API  Mcu_GetMidrStructure(). Returns .
*/
#define MCU_GET_MIDR_API    [!IF "McuDebugConfiguration/McuGetMidrStructureApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API  Mcu_EmiosConfigureGpren(). Returns.
*/
#define MCU_EMIOS_CONFIGURE_GPREN_API    (STD_OFF)

/**
* @brief            Enable the usage of Non-Autosar API  Mcu_Disable_CMU().
*/
#define MCU_DISABLE_CMU_API    [!IF "McuDebugConfiguration/McuDisableCmuApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar Peripheral CMU.
*/
#define MCU_ENABLE_CMU_PERIPHERAL    [!IF "McuDebugConfiguration/McuEnablePeripheralCMU = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable the usage of Non-Autosar API  Mcu_SRAMRetentionConfig().
*/
#define MCU_SRAM_RETEN_CONFIG_API    [!IF "McuDebugConfiguration/McuSRAMRetentionConfigApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Enable/Disable the API for reporting the Dem Error.
*/
#define MCU_DISABLE_DEM_REPORT_ERROR_STATUS     [!IF "(McuDebugConfiguration/McuDisableDemReportErrorStatus='true') or (num:i(count(McuModuleConfiguration/McuDemEventParameterRefs[node:exists(.)]))=0)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief           This define controls the availability of the Low Power Subsystem
*/
#define MCU_LPU_SUPPORT        (STD_OFF)

/**
* @brief            Maximum number of MCU Clock configurations.
*/[!NOCODE!]
[!VAR "MaxNoOfClkCfgs" = "0"!]
[!IF "$MaxNoOfClkCfgs < num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))"!]
    [!VAR "MaxNoOfClkCfgs" = "num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))"!]
[!ENDIF!]
[!ENDNOCODE!]
#define MCU_MAX_CLKCONFIGS   ((uint32)[!"num:i($MaxNoOfClkCfgs)"!]U)


/**
* @brief            Maximum number of MCU Mode configurations.
*/[!NOCODE!]
[!VAR "MaxNoOfModeCfgs" = "0"!]
[!IF "$MaxNoOfModeCfgs < num:i(count(McuModuleConfiguration/McuModeSettingConf/*))"!]
    [!VAR "MaxNoOfModeCfgs" = "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))"!]
[!ENDIF!]
[!ENDNOCODE!]
#define MCU_MAX_MODECONFIGS   ((uint32)[!"num:i($MaxNoOfModeCfgs)"!]U)


/**
* @brief            Maximum number of MCU Ram configurations.
*/[!NOCODE!]
[!VAR "MaxNoOfRamCfgs" = "0"!]
[!IF "$MaxNoOfRamCfgs < num:i(McuModuleConfiguration/McuRamSectors)"!]
    [!VAR "MaxNoOfRamCfgs" = "num:i(McuModuleConfiguration/McuRamSectors)"!]
[!ENDIF!]
[!ENDNOCODE!]
#define MCU_MAX_RAMCONFIGS   ((uint32)[!"num:i($MaxNoOfRamCfgs)"!]U)
[!NOCODE!]
    [!IF "$MaxNoOfRamCfgs = 0"!]
    [!CODE!]#define MCU_MAX_NORAMCONFIGS[!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!]

[!CODE!]
/**
* @brief            Pre-compile Support.
*/
#define MCU_PRECOMPILE_SUPPORT   [!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ENDCODE!]


/**
* @brief Defines the maximum value of the registers - these values is hardware/platform dependent.
*/
/* This define specifies the number of PCC registers */
#define MCU_NUMBER_OF_PCC_REGISTERS_U32         ((uint32)[!"num:i(count(ecu:list('MCU.PerSource.List')))"!]U)
/* This define specifies the number of SOSC registers */
#define MCU_NUMBER_OF_SOSC_REGISTERS_U32        ((uint32)3U)
/* This define specifies the number of ROSC registers */
#define MCU_NUMBER_OF_ROSC_REGISTERS_U32        ((uint32)2U)
/* This define specifies the number of SIRC registers */
#define MCU_NUMBER_OF_SIRC_REGISTERS_U32        ((uint32)3U)
/* This define specifies the number of FIRC registers */
#define MCU_NUMBER_OF_FIRC_REGISTERS_U32        ((uint32)3U)
/* This define specifies the number of SPLL registers */
#define MCU_NUMBER_OF_SPLL_REGISTERS_U32        ((uint32)3U)

/**
* @brief            Enable/Disable the clocks under Mcu control
*/
/* This define Enable/Disable the SOSC clock under Mcu control */
#define MCU_SOSC_UNDER_MCU_CONTROL              [!IF "count(McuModuleConfiguration/*/McuClockSettingConfig/*/McuSystemOSCClockConfig/McuSOSCUnderMcuControl[. = 'true']) >= 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/* This define Enable/Disable the SIRC clock under Mcu control */
#define MCU_SIRC_UNDER_MCU_CONTROL              [!IF "count(McuModuleConfiguration/*/McuClockSettingConfig/*/McuSIRCClockConfig/McuSIRCUnderMcuControl[. = 'true']) >= 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/* This define Enable/Disable the FIRC clock under Mcu control */
#define MCU_FIRC_UNDER_MCU_CONTROL              [!IF "count(McuModuleConfiguration/*/McuClockSettingConfig/*/McuFIRCClockConfig/McuFIRCUnderMcuControl[. = 'true']) >= 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
/* This define Enable/Disable the SPLL clock under Mcu control */
#define MCU_SPLL_UNDER_MCU_CONTROL              [!IF "count(McuModuleConfiguration/*/McuClockSettingConfig/*/McuSystemPll/McuSystemPllUnderMcuControl[. = 'true']) >= 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief            Support for User mode.
*                   If this parameter has been configured to 'TRUE' the Mcu driver can be executed from both supervisor and user mode.
*/
#define MCU_ENABLE_USER_MODE_SUPPORT  [!IF "McuGeneralConfiguration/McuEnableUserModeSupport = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** check the driver user mode is enabled only when the MCAL_ENABLE_USER_MODE_SUPPORT is enabled */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
#error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Mcu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
#endif /* (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/** precompiles are defined for IPVs that are protected  */
#define MCU_PMC_REG_PROT_AVAILABLE           [!IF "(ecu:get('MCU.PMC.REG_PROT.AVAILABLE') = 'true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief  The function Mcu_GetResetRawValue shall return an implementation specific value which does
*         not correspond to a valid value of the reset status register and is not equal to 0 if this
*         function is called prior to calling of the function Mcu_Init, and if supported by the
*         hardware.
*
*/
#define MCU_RAW_RESET_DEFAULT      ((uint32)0xFFFFFFFFU)

/** @brief This is the corresponding bit of Stop Acknowledge Error reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_SACKERR      ((uint32)0x00002000U)                                                              
/** @brief This is the corresponding bit of MDM-AP System Reset Request in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_MDM_AP       ((uint32)0x00000800U)                                                              
/** @brief This is the corresponding bit of Software reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_SW           ((uint32)0x00000400U)                                                              
/** @brief This is the corresponding bit of Stop Core Lockup reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_LOCKUP       ((uint32)0x00000200U)                                                              
/** @brief This is the corresponding bit of JTAG generated reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_JTAG         ((uint32)0x00000100U)                                                              
/** @brief This is the corresponding bit of Power-on reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_POR          ((uint32)0x00000080U)
/** @brief This is the corresponding bit of external pin reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_PIN          ((uint32)0x00000040U)
/** @brief This is the corresponding bit of watchdog reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_WDOG         ((uint32)0x00000020U)
/** @brief This is the corresponding bit of CMU Loss-of-Lock reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_CMU_LOC      ((uint32)0x00000010U)
/** @brief This is the corresponding bit of Loss-of-Lock reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_LOL          ((uint32)0x00000008U)
/** @brief This is the corresponding bit of Loss-of-Clock reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_LOC          ((uint32)0x00000004U)
/** @brief This is the corresponding bit of Low-Voltage Detect reset or High-Voltage Detect reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_LVD          ((uint32)0x00000002U)

[!MACRO "McuExportDriverConfiguration"!]
[!NOCODE!][!//
[!VAR "configName" = "as:name(McuModuleConfiguration)"!][!//
[!CODE!][!//
/**
* @brief            Pre-Compile structure from Mcu_Cfg.c file.
*/
/** @violates @ref Mcu_CFG_H_REF_2 MISRA 2004 Required Rule 19.4, This is not a macro, it can not be included in () or {} */
#define MCU_CONF_PB \
[!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern CONST(Mcu_ConfigType, MCU_CONST) [!"$configName"!]_[!"."!];[!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern CONST(Mcu_ConfigType, MCU_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
    [!CALL "McuExportDriverConfiguration"!]
[!ENDIF!]

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief            The Mcu_ModeType specifies the identification (ID) for a MCU mode, configured via configuration structure.
* @details          The type shall be uint8, uint16 or uint32.
*
* @implements     Mcu_ModeType_typedef
*
*/
typedef uint32 Mcu_ModeType;


/**
* @brief            The Mcu_RamSectionType specifies the identification (ID) for a RAM section, configured via the configuration structure.
*                   The type shall be uint8, uint16 or uint32, based on best performance.
* @implements Mcu_RamSectionType_typedef
*/
typedef uint32 Mcu_RamSectionType;

/**
* @brief            The Mcu_RamIndexType specifies the variable for indexinf RAM sections.
*                   The type shall be uint8, uint16 or uint32, based on best performance.
*
*/
typedef uint32 Mcu_RamIndexType;

/**
* @brief            The Mcu_RamSizeType specifies the RAM section size.
*                   The type shall be uint8, uint16 or uint32, based on best performance.
*
*/
typedef uint32 Mcu_RamSizeType;

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief          Defines the identification (ID) for clock setting configured via the configuration structure.
* @details        The type shall be uint8, uint16 or uint32, depending on uC platform.
*
* @implements Mcu_ClockType_typedef
*/
typedef uint32 Mcu_ClockType;
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/**
* @brief            Definition of a RAM section within the configuration structure.
*                   The definitions for each RAM section within the structure Mcu_ConfigType shall contain:
*                   - RAM section base address
*                   - Section size
*                   - Data pre-setting to be initialized
*
*/
typedef struct
{
    VAR( Mcu_RamSectionType, MCU_VAR) Mcu_RamSectorId;   /**< @brief The ID for Ram Sector configuration. */
    VAR( uint8, MCU_VAR) (*Mcu_pu8RamBaseAddr)[1U];   /**< @brief RAM section base address. */
    VAR( Mcu_RamSizeType, MCU_VAR) Mcu_RamSize;   /**< @brief RAM section size. */
    VAR( uint8, MCU_VAR) Mcu_u8RamDefaultValue;   /**< @brief RAM default value for initialization. */

} Mcu_RamConfigType;



/**
* @brief            The type Mcu_RawResetType specifies the reset reason in raw register format, read from a reset status register.
* @details          The type shall be uint8, uint16 or uint32 based on best performance.
*
* @implements Mcu_RawResetType_typedef
*
*/
typedef uint32 Mcu_RawResetType;   /**< @brief Destructive and Functional Reset Events Log. */

/**
* @brief            DEM error reporting configuration.
* @details          This structure contains information DEM error reporting
*/
typedef struct
{
    VAR( Mcal_DemErrorType, MCU_VAR) Mcu_E_TimeoutFailureCfg;

} Mcu_DemConfigType;

/*==================================================================================================
                                       CONSTANTS
==================================================================================================*/
/**
* @brief            Create defines with the IDs assigned to Mcu Clock configurations.
*                   These IDs will be transmitted as input parameters for Mcu_InitClock() API.
*/
[!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
#define [!"name(.)"!]   ((Mcu_ClockType)[!"num:i( num:i(McuClockSettingId))"!]U)
#define McuConf_McuClockSettingConfig_[!"name(.)"!]   ((Mcu_ClockType)[!"num:i( num:i(McuClockSettingId))"!]U)
[!ENDLOOP!]

/**
* @brief            Create defines with the IDs assigned to Mcu Mode configurations.
*                   These IDs will be transmitted as input parameters for Mcu_SetMode() API.
*/
[!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
#define [!"name(.)"!]   ((Mcu_ModeType)[!"num:i( num:i(McuMode))"!]U)
#define McuConf_McuModeSettingConf_[!"name(.)"!]   ((Mcu_ModeType)[!"num:i( num:i(McuMode))"!]U)
[!ENDLOOP!]

/**
* @brief            Create defines with the IDs assigned to Mcu RAM Section configurations.
*                   These IDs will be transmitted as input parameters for Mcu_InitRamSection() API.
*/
[!LOOP "McuModuleConfiguration/McuRamSectorSettingConf/*"!]
#define [!"name(.)"!]   ((Mcu_RamSectionType)[!"num:i(McuRamSectorId)"!]U)
#define McuConf_McuRamSectorSettingConf_[!"name(.)"!]   ((Mcu_RamSectionType)[!"num:i(McuRamSectorId)"!]U)
[!ENDLOOP!]
/**
* @brief            Create defines with the values assigned to Mcu Reset Reason configurations.
*                   These values can be  retrieved from Mcu_GetResetReason Api.
*/
[!LOOP "McuPublishedInformation/McuResetReasonConf/*"!]
#define McuConf_McuResetReasonConf_[!"name(.)"!]   ((uint8)[!"num:i(McuResetReason)"!]U)
[!ENDLOOP!]
/*==================================================================================================
                                             ENUMS
==================================================================================================*/
/**
* @brief            Type of parameter value of the function Mcu_SRAMRetentionConfig.
* @details          The type of Mcu_SRAMRetenConfigType is an enumeration with the following values:
*                       MCU_SRAML_RETEN, MCU_SRAMU_RETEN, MCU_SRAMLU_RETEN, MCU_NO_SRAMLU_RETEN.
*/
typedef enum
{
    MCU_SRAML_RETEN = (uint32)0x00100000U,   /**< @brief SRAML will be retain only. */
    MCU_SRAMU_RETEN = (uint32)0x00200000U,   /**< @brief SRAMU will be retain only. */
    MCU_SRAMLU_RETEN = (uint32)0x00000000U,   /**< @brief Both SRAML and SRAMU will be retain. */
    MCU_NO_SRAMLU_RETEN = (uint32)0x00300000U,   /**< @brief Both SRAML and SRAMU will not be retain. */
} Mcu_SRAMRetenConfigType;

/**
* @brief            Type of the return value of the function Mcu_GetPllStatus.
* @details          The type of Mcu_PllStatusType is an enumeration with the following values:
*                       MCU_PLL_LOCKED, MCU_PLL_UNLOCKED, MCU_PLL_STATUS_UNDEFINED.
*
* @implements     Mcu_PllStatusType_enumeration
*
*/
typedef enum
{
    MCU_PLL_LOCKED = 0x33U,   /**< @brief PLL is locked. */
    MCU_PLL_UNLOCKED = 0xCCU,   /**< @brief PLL is unlocked. */
    MCU_PLL_STATUS_UNDEFINED = 0x5AU   /**< @brief PLL Status is unknown. */

} Mcu_PllStatusType;


/**
* @brief            The type Mcu_ResetType, represents the different reset that a specified MCU can have.
* @details          The MCU module shall provide at least the values MCU_POWER_ON_RESET and MCU_RESET_UNDEFINED for the enumeration Mcu_ResetType.
*
* @implements Mcu_ResetType_enumeration
*/
typedef enum
{
    MCU_STOP_ACKNOWLEDGE_ERROR_RESET = McuConf_McuResetReasonConf_MCU_STOP_ACKNOWLEDGE_ERROR_RESET,          /**< @brief Stop Acknowledge Error reset . RCM_SRS[SACKERR]. */
    MCU_MDM_AP_SYSTEM_RESET = McuConf_McuResetReasonConf_MCU_MDM_AP_SYSTEM_RESET,                            /**< @brief MDM-AP System Reset Request . RCM_SRS[MDM_AP]. */
    MCU_SW_RESET = McuConf_McuResetReasonConf_MCU_SW_RESET,                                                  /**< @brief Software reset . RCM_SRS[SW]. */
    MCU_CORE_LOCKUP_RESET = McuConf_McuResetReasonConf_MCU_CORE_LOCKUP_RESET,                                /**< @brief Core Lockup reset . RCM_SRS[LOCKUP]. */
    MCU_JTAG_RESET = McuConf_McuResetReasonConf_MCU_JTAG_RESET,                                              /**< @brief JTAG generated reset . RCM_SRS[JTAG]. */
    MCU_POWER_ON_RESET = McuConf_McuResetReasonConf_MCU_POWER_ON_RESET,                                      /**< @brief Power-on reset. RCM_SRS[POR]. */
    MCU_EXTERNAL_PIN_RESET = McuConf_McuResetReasonConf_MCU_EXTERNAL_PIN_RESET,                              /**< @brief External Reset Pin. RCM_SRS[PIN]. */
    MCU_WATCHDOG_RESET = McuConf_McuResetReasonConf_MCU_WATCHDOG_RESET,                                      /**< @brief Watchdog reset. RCM_SRS[Watchdog]. */
    MCU_CMU_LOSS_OF_CLOCK_RESET = McuConf_McuResetReasonConf_MCU_CMU_LOSS_OF_CLOCK_RESET,                    /**< @brief CMU Loss-of-Clock Reset. RCM_SRS[CMU_LOC]. */
    MCU_LOSS_OF_LOCK_RESET = McuConf_McuResetReasonConf_MCU_LOSS_OF_LOCK_RESET,                              /**< @brief Loss-of-Lock Reset. RCM_SRS[LOL]. */
    MCU_LOSS_OF_CLOCK_RESET = McuConf_McuResetReasonConf_MCU_LOSS_OF_CLOCK_RESET,                            /**< @brief Loss-of-Clock Reset. RCM_SRS[LOC]. */
    MCU_LOW_OR_HIGH_VOLTAGE_DETECT_RESET = McuConf_McuResetReasonConf_MCU_LOW_OR_HIGH_VOLTAGE_DETECT_RESET,  /**< @brief Low-Voltage Detect Reset or High-Voltage Detect Reset. RCM_SRS[LVD]. */
    MCU_NO_RESET_REASON = McuConf_McuResetReasonConf_MCU_NO_RESET_REASON,                                    /**< @brief No reset reason found */
    MCU_MULTIPLE_RESET_REASON = McuConf_McuResetReasonConf_MCU_MULTIPLE_RESET_REASON,                        /**< @brief More than one reset events are logged except "Power on event" */
    MCU_RESET_UNDEFINED = McuConf_McuResetReasonConf_MCU_RESET_UNDEFINED                                     /**< @brief Undefined reset source. */

} Mcu_ResetType;

#if (MCU_GET_RAM_STATE_API == STD_ON)
/**
* @brief            Ram State of the micro controller.
* @details          This is the Ram State data type returned by the function Mcu_GetRamState() of the Mcu module.
*/
typedef enum
{
    MCU_RAMSTATE_INVALID = 0U,   /**< @brief RAM content is not valid or unknown (default). */
    MCU_RAMSTATE_VALID   /**< @brief RAM content is valid. */

} Mcu_RamStateType;
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Mcu_CFG_H_REF_5 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include' MemMap.h*/
/** @violates @ref Mcu_CFG_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"
/**
* @brief            Local copy of the pointer to the configuration data
*/
/** @violates @ref Mcu_CFG_H_REF_3 MISRA 2004 Required Rule 8.7, these object are used trough the entire MCU code*/
extern P2CONST(Mcu_DemConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pDemCfgPtr;

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Mcu_CFG_H_REF_5 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include' MemMap.h*/
/** @violates @ref Mcu_CFG_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"
#endif

extern CONST( Mcu_DemConfigType, MCU_CONST) Mcu_Dem_Config;
[!IF "node:fallback(McuGeneralConfiguration/McuPerformResetApi, 'true') = 'true'"!][!IF "McuGeneralConfiguration/McuCalloutBeforePerformReset = 'true'"!]
/**
* @brief            Export the callout reset procedure configured by the user.
*/
/** @violates @ref Mcu_CFG_H_REF_3 MISRA 2004 Required Rule 8.7, these object are used trough the entire MCU code*/
extern FUNC(void, MCU_CODE) MCU_RESET_CALLOUT(void);
[!ENDIF!][!ENDIF!]


[!IF "node:exists(McuGeneralConfiguration/McuCmuNotification)"!]
/**
* @brief            The callout configured by the user for CMU notifications.
*/
/** @violates @ref Mcu_CFG_H_REF_3 MISRA 2004 Required Rule 8.7, these object are used trough the entire MCU code*/
extern FUNC(void, MCU_CODE) MCU_CMU_FCCU_NOTIFICATION(VAR (uint8, AUTOMATIC) u8IndexCmu);
[!ENDIF!]

/**
* @brief            ISR Mcu_CmuClockFail_ISR is always available
*/
#define MCU_CMU_ERROR_ISR_USED [!IF "node:exists(McuGeneralConfiguration/McuCmuNotification)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!IF "node:exists(McuGeneralConfiguration/McuErrorIsrNotification)"!]
/**
* @brief            The callout configured by the user for error ISR notifications.
*/
/** @violates @ref Mcu_CFG_H_REF_3 MISRA 2004 Required Rule 8.7, these object are used trough the entire MCU code*/
extern FUNC(void, MCU_CODE) MCU_ERROR_ISR_NOTIFICATION(VAR (uint8, AUTOMATIC) u8ErrorCode);
[!ENDIF!]

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* #ifndef MCU_CFG_H */

/** @} */

