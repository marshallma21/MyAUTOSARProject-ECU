/**
*   @file    Adc_CfgDefines.h
*   @version 1.0.2
*
*   @brief   AUTOSAR Adc - Module configuration interface for Adc driver.
*   @details Contains the module configuration interface for Adc driver.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ADC12BSARV2
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

#ifndef ADC_CFG_DEFINES_H
#define ADC_CFG_DEFINES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_CfgDefines_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7,
* A function shall be used in preference to a function-like macro.
* Middle layer between AUTOSAR and hardware needs a way to map HLD
* functions to IPV functions.
*
* @section Adc_CfgDefines_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated. 
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "Adc_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//
[!NOCODE!][!//
[!INCLUDE "Adc_RegOperations.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_CFG_DEFINES                       43
/** @violates @ref Adc_CfgDefines_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES        4
#define ADC_AR_RELEASE_MINOR_VERSION_CFG_DEFINES        2
/** @violates @ref Adc_CfgDefines_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_REVISION_VERSION_CFG_DEFINES     2
#define ADC_SW_MAJOR_VERSION_CFG_DEFINES                1
#define ADC_SW_MINOR_VERSION_CFG_DEFINES                0
#define ADC_SW_PATCH_VERSION_CFG_DEFINES                2

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
* @brief          Specifies if Current channel is used 
*/
#define ADC_CURRENT_CHANNEL_USED

[!FOR "x" = "0" TO "ecu:get('Adc.AdcConfigSet.AdcHwUnit')-1"!][!//
/**
* @brief          ADC unit [!"$x"!] available
*/
#define ADC_UNIT_[!"$x"!]  [!"$x"!]U

[!ENDFOR!][!//

/**
* @brief          Number of SC1n registers available
*/
#define ADC_NUM_SC1n_REGISTER      [!"ecu:get('Adc.AdcConfigSet.AdcScRegister')"!]U

/**
* @brief          Specifies if the alias SC and Rn register supported
*/
#define ADC_USE_ALIAS_REGISTERS    [!IF "ecu:get('Adc.AdcConfigSet.AdcUseAliasRegisters') = 'TRUE'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!NOCODE!][!//
[!VAR "ScOffSet" = "0"!]
[!VAR "RnOffSet" = "72"!]
[!VAR "AdchMask" = "ecu:get('Adc.AdchMask')"!]
[!IF "ecu:get('Adc.AdcConfigSet.AdcUseAliasRegisters') = 'TRUE'"!]
[!VAR "ScOffSet" = "264"!]
[!VAR "RnOffSet" = "392"!]
[!ENDIF!]
[!ENDNOCODE!][!//
#define ADC_SC1_OFFSET_ADDR32     ([!"num:inttohex(num:i($ScOffSet))"!]UL)

#define ADC_Rn_OFFSET_ADDR32      ([!"num:inttohex(num:i($RnOffSet))"!]UL)

#define ADC_ADCH_MASK_U32         ([!"num:inttohex(num:i($AdchMask))"!]UL)

[!NOCODE!][!//
[!VAR "temp" = "num:i(ecu:get('Adc.AdcConfigSet.AdcScRegisterUsed'))"!][!//
[!VAR "PreviousMask" = "0"!][!//
[!FOR "index" = "0" TO "$temp"!][!//
  [!IF "$temp = 1"!]
    [!BREAK!]
  [!ELSE!]
    [!VAR "temp" = "bit:shr($temp,1)"!][!//
    [!VAR "PreviousMask" = "$PreviousMask + 1"!][!//  
  [!ENDIF!]
[!ENDFOR!][!//
[!ENDNOCODE!][!//
/**
* @brief          The mask to calculale the previous channnel index
*/
#define ADC_PRE_CHANNEL_SHIFT_MASK      [!"num:i($PreviousMask)"!]U
/**
* @brief          Number of SC1n registers used
*/
#define ADC_NUM_SC1n_REGISTER_USED [!"ecu:get('Adc.AdcConfigSet.AdcScRegisterUsed')"!]U
/**
* @brief          PDB support 8 delay register
*/
#define ADC_PDB_NUM_DELAY_REGISTER   8U

/**
* @brief          MHT functionality not activated.
*/
#define ADC_MULTIPLE_HARDWARE_TRIGGERS      (STD_OFF)

/** 
* @brief           Adds/removes ((STD_ON)/(STD_OFF)) the services Adc_EnableHardwareTrigger() and Adc_DisableHardwareTrigger() from the code.
*/
#define ADC_HW_TRIGGER_API                  [!IF "AdcGeneral/AdcHwTriggerApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief           Set mode api enabled/disabled ((STD_ON)/(STD_OFF)).
*/
#define ADC_SET_MODE_API                    (STD_OFF)

/** 
* @brief           Enables or disables limit checking feature in the ADC driver.
*/
#define ADC_ENABLE_LIMIT_CHECK              [!IF "AdcGeneral/AdcEnableLimitCheck"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief           Group notification mechanism is/isn't ((STD_ON)/(STD_OFF)) available at runtime.
*/
#define ADC_GRP_NOTIF_CAPABILITY            [!IF "AdcGeneral/AdcGrpNotifCapability"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief           Type of prioritization mechanism ADC_PRIORITY_HW, ADC_PRIORITY_HW_SW and ADC_PRIORITY_NONE.
*/
#define ADC_PRIORITY_HW                     0U
#define ADC_PRIORITY_HW_SW                  1U
#define ADC_PRIORITY_NONE                   2U

/** 
* @brief           Priority implementation.
*/
#define ADC_PRIORITY_IMPLEMENTATION         ([!"AdcGeneral/AdcPriorityImplementation"!])

/** 
* @brief           Type of alignment mechanism ADC_ALIGN_RIGHT, ADC_ALIGN_LEFT.
*/
#define ADC_ALIGN_RIGHT                     0U
#define ADC_ALIGN_LEFT                      1U

/** 
* @brief           Result Alignment.
*/
#define ADC_RESULT_ALIGNMENT                ([!"AdcGeneral/AdcResultAlignment"!])

/** 
* @brief           Adc transfer type.
*/
#define ADC_DMA                             0U
#define ADC_INTERRUPT                       1U

/** 
* @brief         This is a timeout value which is used to wait till
*                  - the conversion is not aborted.
*                  - ADC hardware is not entered in power down state.
*                  - ADC hardware is not entered in idle state.
*/
#define ADC_TIMEOUT_COUNTER                 ([!"num:inttohex(AdcGeneral/AdcTimeout,8)"!]UL)

/** 
* @brief         This is a timeout value which is used to wait till Dma transfering finish
*/
#define ADC_DMA_TRANSFER_TIMEOUT                 ([!"num:inttohex(AdcGeneral/AdcDmaTimeout,8)"!]UL)

/** 
* @brief           Specifies for reducing the number of interrupts for streaming groups
*/
#define ADC_ENABLE_DOUBLE_BUFFERING  [!IF "NonAutosar/AdcEnableDoubleBufferingOptimization"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief           Specifies to optimize converstions for hw triggered, one shot group.
*/
#define ADC_OPTIMIZE_ONESHOT_HW_TRIGGER      [!IF "NonAutosar/AdcOptimizeOneShotHwTriggerConversions"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!IF "NonAutosar/AdcEnableDmaTrasferMode  = 'true'"!][!//
/** 
* @brief           Active DMA.
*/
#define ADC_DMA_SUPPORTED
[!ENDIF!][!//

/**
 * @brief   Max number of ADCDig Hw units
 */
#define ADC_MAX_HW_UNITS                    [!"ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!]U

/**
 * @brief   Define the number of maximum channels
 */
#define ADC_PDB_CHANNELS_U8                 [!"ecu:get('Adc.AdcConfigSet.AdcPdbChannels')"!]U

/**
* @brief          Number PDB module.
*/ 
#define ADC_PDB_NUM_MODULES                 [!"ecu:get('Adc.AdcConfigSet.PdbHwUnit')"!]U

/** 
* @brief           Add/Remove non autosar Adc_EnableChannel() and Adc_DisableChannel() api.
*/
#define ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API        (STD_OFF)

/** 
* @brief           Get injected conversion status api enabled/disabled (STD_ON/STD_OFF).
*/
#define ADC_GET_INJECTED_CONVERSION_STATUS_API      (STD_OFF)

/** 
* @brief          Add/Remove non autosar Adc_SetClockMode().
*/
#define ADC_DUAL_CLOCK_MODE                         [!IF "NonAutosar/AdcEnableDualClockMode"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_Calibration() from the code.
*/
#define ADC_CALIBRATION                             [!IF "NonAutosar/AdcEnableCalibration"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_SetChannel() from the code.
*/
#define ADC_SETCHANNEL_API                          [!IF "NonAutosar/AdcEnableSetChannel"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief          Extra group notification mechanism is/isn't ((STD_ON)/(STD_OFF)) available at runtime.
*/
#define ADC_ENABLE_INITIAL_NOTIFICATION             [!IF "NonAutosar/AdcEnableInitialNotification"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]


/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_SelfTest() from the code.
*/
#define ADC_SELF_TEST                               (STD_OFF)

/** 
* @brief           ADC Configure Threshold enabled/disabled (STD_ON/STD_OFF).
*/
#define ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API    (STD_OFF)

/**
* @brief  Switch to enable/disable the API for the PR-MCAL-3312, PR-MCAL-3313, PR-MCAL-3314, PR-MCAL-3315 and PR-MCAL-3316.
*/
#define CTUV2_ENABLE_TRIGGER_CONFIGURATION_APIS   (STD_OFF)

/** 
* @brief          This switch is used to enable the hardware trigger non autosar API.
*/
#define ADC_ENABLE_CTUTRIG_NONAUTO_API              (STD_OFF)

/** 
* @brief  Switch to enable/disable the API for the CPR-MCAL-726, CPR-MCAL-727, CPR-MCAL-728.
*/
#define ADC_ENABLE_CTU_CONTROL_MODE_API             (STD_OFF)
[!NOCODE!][!//
[!VAR "AdcDisableDemReport" = "0"!]
[!IF "node:exists(AdcDemEventParameterRefs)"!]
  [!IF "NonAutosar/AdcDisableDemReportErrorStatus = 'true'"!]
    [!VAR "AdcDisableDemReport" = "1"!]
  [!ENDIF!]
[!ELSE!]
  [!VAR "AdcDisableDemReport" = "1"!]
[!ENDIF!]
[!ENDNOCODE!][!//
/** 
* @brief  Switch to enable/disable the production error reporting.
*/
#define ADC_DISABLE_DEM_REPORT_ERROR_STATUS         [!IF "$AdcDisableDemReport = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief IRQ definition
*/
[!FOR "x" = "0" TO "ecu:get('Adc.AdcConfigSet.AdcHwUnit')-1"!][!//
[!IF "AdcInterrupt/*[AdcInterruptSource=concat(concat('ADC',string($x)),'_COCO')]/AdcInterruptEnable='true'"!][!//
#define ADC_UNIT_[!"$x"!]_ISR_USED
[!ENDIF!][!//
[!ENDFOR!][!//

[!VAR "maxUnitCfg"="ecu:get('Adc.AdcConfigSet.AdcHwUnit')-1"!][!//
[!FOR "Unit" = "0" TO "num:i($maxUnitCfg)"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*[AdcHwUnitId = concat('ADC', $Unit)]"!][!//
[!IF "node:exists(AdcPdbSettings/AdcPdbChannelSequenceErrorEnable) and AdcPdbSettings/AdcPdbChannelSequenceErrorEnable = 'true'"!]
#define ADC_UNIT_[!"$Unit"!]_PDB_ERR_ISR_USED
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//

[!NOCODE!][!//
[!VAR "maxGrp" = "num:i(count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*))"!]
[!VAR "tempVal" = "0"!][!//
[!VAR "maxGrpPerUnit" = "0"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
 [!VAR "tempVal" = "num:i(count(AdcGroup/*))"!]
  [!IF "num:i($tempVal) > num:i($maxGrpPerUnit)"!][!VAR "maxGrpPerUnit" = "$tempVal"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//

/** 
* @brief           max queue depth configured across all configset.
*/
#define ADC_QUEUE_MAX_DEPTH_MAX             [!"num:i(AdcGeneral/AdcPriorityQueueMaxDepth )"!]U

/** 
* @brief           max number of groups configured across all configset.
*/
#define ADC_MAX_GROUPS                      [!"num:i($maxGrp)"!]U

/** 
* @brief           Define the HW queue size depending on the MHT groups existence.
* @details         If there are MHT groups in the configuration the HW queue size will be the total number of MHT
*                  groups defined. If there are no MHT groups in the current configuration, then only one hardware
*                  group can be added to the HW queue, thus the queue size will be only 1.
*/

#define ADC_HW_QUEUE                        (1U)

#define ADC_USER_MODE_REG_PROT_ENABLED      (STD_OFF)

[!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
/**
* @brief          Configuration Precompile variant.
* @details        Configuration Precompile variant.
*/
#define ADC_PRECOMPILE_SUPPORT
[!ENDIF!][!//

/** 
* @brief          Development error detection enabled/disabled ((STD_ON)/(STD_OFF)).
*/
#define ADC_DEV_ERROR_DETECT                [!IF "AdcGeneral/AdcDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_GetVersionInfo() from the code.
*/
#define ADC_VERSION_INFO_API                [!IF "AdcGeneral/AdcVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_DeInit() from the code.
*/
#define ADC_DEINIT_API                      [!IF "AdcGeneral/AdcDeInitApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the services Adc_StartGroupConversion()and Adc_StopGroupConversion() from the code.
*/
#define ADC_ENABLE_START_STOP_GROUP_API     [!IF "AdcGeneral/AdcEnableStartStopGroupApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief          Add/Remove the services Adc_ReadGroup() from the code.
*/
#define ADC_READ_GROUP_API                  [!IF "AdcGeneral/AdcReadGroupApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief           This switch is used to enable the non autosar ADC performance optimization feature.
*/
#define ADC_BYPASS_CONSISTENCY_LOOP         [!IF "NonAutosar/AdcBypassConsistencyLoop"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!IF "NonAutosar/AdcContinuousWithoutInterrupt"!]
/** 
* @brief           This switch is used to enable the non autosar ADC performance optimization feature.
*/
#define ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED
[!ENDIF!][!//

/** 
* @brief          Add/Remove One time setting of Conversion time regsisters from Init() function.
*/
#define ADC_SET_ADC_CONV_TIME_ONCE          [!IF "NonAutosar/AdcConvTimeOnce"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief   Switch to enable that power state mode is supported
*
*/
#define ADC_POWER_STATE_SUPPORTED           (STD_OFF)

/** 
* @brief           This switch is used to enable the queue.
*/
[!IF "AdcGeneral/AdcPriorityImplementation = 'ADC_PRIORITY_NONE'"!][!//
#define ADC_ENABLE_QUEUING                  [!IF "AdcGeneral/AdcEnableQueuing = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ELSE!][!//
#define ADC_ENABLE_QUEUING                  (STD_ON)
[!ENDIF!][!//

/** 
* @brief           Symbolic names of ADC Hardware units.
*/
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
#define  [!"name(.)"!]                      ([!"AdcLogicalUnitId"!])
[!ENDLOOP!][!//

/** 
* @brief           ADC Hardware unit macro for register access.
*
* @violates @ref Adc_CfgDefines_h_REF_1 Use of function like macro.
*/
#define ADC_HW_UNITS(unit)                  (Adc_pCfgPtr->Misc.au8Adc_HwUnit[(unit)])

/**
* @brief          Adc channel id.
* @violates @ref Adc_CfgDefines_h_REF_1 Use of function like macro.
*/
#define ADC_ID_CHANNEL_U8(Id)               (Id)

/**
* @brief          Maximum boundary for the Adc_QueueIndexType.
*/
#define ADC_QUEUE_INDEX_TYPE_MAXIMUM          65535U

/**
* @brief          Specifies if Software Normal injected conversions are supported / used.
*/
#define ADC_SOFTWARE_INJECTED_CONVERSIONS_USED     (STD_OFF)

/** 
* @brief           Normal hardware triggering used
*/
#define ADC_HARDWARE_NORMAL_CONVERSIONS_USED       [!IF "NonAutosar/AdcUseHardwareNormalGroups"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/** 
* @brief           AUTOSAR Symbolic names of channels on all HW units.
*/
/* ADC099 */
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcChannel/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcChannel/*"!][!//
[!IF "$x = AdcLogicalChannelId"!]
#define [!"name(.)"!]                       [!"AdcLogicalChannelId"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//


[!IF "NonAutosar/AdcEnableGroupDependentChannelNames = 'true'"!][!//
[!VAR "already_parsed_names"!][!ENDVAR!][!//
/** 
* @brief           Non autosar symbolic names of channels on all HW units.
*/
/* ADC099 */
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "$x = AdcGroupId"!][!//
[!VAR "Groupname" = "name(.)"!][!//
[!VAR "index" = "0"!][!//
[!LOOP "AdcGroupDefinition/*"!][!//
[!VAR "CurrAdcChannel" = "."!][!//
[!VAR "CurrAdcChannel1" = "substring-after(substring-after(substring-after(substring-after(substring-after($CurrAdcChannel,'/'),'/'),'/'),'/'),'/')"!][!//
[!LOOP "../../../../AdcChannel/*"!][!//
[!IF "@name = $CurrAdcChannel1"!][!//
[!IF "contains($already_parsed_names, concat($Groupname, '_', node:name(.), '|')) = false()"!][!//
/** @violates @ref Adc_CfgDefines_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define [!"$Groupname"!]_[!"name(.)"!]      [!"num:i($index)"!]
[!VAR "already_parsed_names"="concat($already_parsed_names, $Groupname, '_', node:name(.), '|')"!][!//
[!VAR "index" = "$index + 1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

/** 
* @brief           Symbolic names of groups.
*/
/* ADC099 */
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "$x = AdcGroupId"!]
#define [!"name(.)"!]                       [!"AdcGroupId"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!]

/** 
* @brief           Symbolic names of groups - ecuc 2108 compliant.
*/
/* ADC099 */
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "$x = AdcGroupId"!]
/** @violates @ref Adc_CfgDefines_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define AdcConf_AdcGroup_[!"name(.)"!]                       [!"AdcGroupId"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!]

/** 
* @brief           Active CMR register
*/
#define ADC_CMR_REGISTER_NOT_SUPPORTED

/** 
* @brief           PDB is supported
*/
#define ADC_PDB_SUPPORTED

/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the Adc driver code can be executed from both supervisor and user mode.
*/
[!IF "NonAutosar/AdcEnableUserModeSupport"!]
#define ADC_ENABLE_USER_MODE_SUPPORT   (STD_ON)
[!IF "ecu:has('AdcAdc12bsarRegProtAvailable')"!]
[!IF "ecu:get('AdcAdc12bsarRegProtAvailable') = 'TRUE'"!]
/**
* @brief Support for REG_PROT in ADCDIG IP.
*        If the current platform implements REG_PROT for ADCDIG IP, this parameter will be defined, and will enable REG_PROT configuration for ADCDIG IP in ADC drvier
*/
#define ADC_ADC12BSARV2_REG_PROT_AVAILABLE
[!ENDIF!]
[!ENDIF!]
[!IF "ecu:has('AdcPdbRegProtAvailable')"!]
[!IF "ecu:get('AdcPdbRegProtAvailable') = 'TRUE'"!]
/**
* @brief Support for REG_PROT in PDB IP.
*        If the current platform implements REG_PROT for PDB IP, this parameter will be defined, and will enable REG_PROT configuration for PDB IP in ADC drvier
*/
#define ADC_PDB_REG_PROT_AVAILABLE
[!ENDIF!]
[!ENDIF!]
[!ELSE!]
#define ADC_ENABLE_USER_MODE_SUPPORT   (STD_OFF)
[!ENDIF!]

[!NOCODE!][!//
[!VAR "moreThanOneChannel" = "false()"!][!//
[!FOR "Unit" = "0" TO "count(AdcConfigSet/AdcHwUnit/*)"!][!//
    [!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
        [!IF "$Unit = substring-after(string(AdcHwUnitId),'ADC')"!][!//
            [!IF "'ADC_DMA' = string(AdcTransferType)"!][!//
                [!VAR "errorFlagCoco" = "true()"!][!//
                [!VAR "errorFlagNotUse" = "true()"!][!//
                [!VAR "groupDBMO" = "0"!][!//
                [!LOOP "AdcGroup/*"!][!//
                /* Count number of group DBMO */
                    [!IF "count(AdcGroupDefinition/*) > 1 and AdcEnableDoubleBuffering = 'true'"!][!//
                        [!VAR "groupDBMO" = "$groupDBMO + 1"!][!//
                        [!VAR "moreThanOneChannel" = "true()"!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
                /* Check if 2 notifications have the same name are configured in both 2 DMA channels for each ADC HW unit */
                [!IF "($groupDBMO > 0) and ($groupDBMO < count(AdcGroup/*))"!][!//
                    [!LOOP "node:refs('ASPathDataOfSchema:/TS_T40D2M10I2R0/Mcl')/MclConfigSet/*[1]/DMAChannel/*[MclDMAChannelEnable = 'true']"!][!//
                        [!VAR "temp"="node:value(string(concat('DmaSource',string(num:i(num:i(substring-after(DmaHwChannel,'eDMA_')) div 16)))))"!][!//
                        [!VAR "temp2"="node:value(MclDmaTransferCompletionNotif)"!][!//
                        /* Check notification is configured for DMA channel that has ADCx_COCO DMA source */
                        [!IF "$temp = concat('ADC',$Unit,'_COCO')"!][!//
                            [!IF "$temp2 = concat('Adc_Adc12bsarv2_DmaTransferComplete',$Unit)"!][!//
                                [!VAR "errorFlagCoco" = "false()"!][!//
                            [!ENDIF!][!//
                        /* Check notification is configured for DMA channel that has NOT_USED DMA source */
                        [!ELSEIF "$temp = 'NOT_USED'"!][!//
                            [!IF "$temp2 = concat('Adc_Adc12bsarv2_DmaTransferComplete',$Unit)"!][!//
                                [!VAR "errorFlagNotUse" = "false()"!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDLOOP!][!//
                [!ELSE!][!//
                    [!VAR "errorFlagCoco" = "false()"!][!//
                    [!VAR "errorFlagNotUse" = "false()"!][!//
                    /* There is no DBMO group, so only normal DMA group or double buffering with 1 channel */
                    [!IF "$groupDBMO = 0"!][!//
                        [!LOOP "node:refs('ASPathDataOfSchema:/TS_T40D2M10I2R0/Mcl')/MclConfigSet/*[1]/DMAChannel/*[MclDMAChannelEnable = 'true']"!][!//
                            [!VAR "temp"="node:value(string(concat('DmaSource',string(num:i(num:i(substring-after(DmaHwChannel,'eDMA_')) div 16)))))"!][!//
                            [!VAR "temp2"="node:value(MclDmaTransferCompletionNotif)"!][!//
                            /* Only one notification need to be configured for DMA channel which has ADCx_COCO DMA source */
                            /* Check notification is configured for DMA channel that has ADCx_COCO DMA source */
                            [!IF "$temp = concat('ADC',$Unit,'_COCO')"!][!//
                                [!IF "$temp2 != concat('Adc_Adc12bsarv2_DmaTransferComplete',$Unit)"!][!//
                                    [!ERROR!][!//
                                    [!"'Adc_Adc12bsarv2_DmaTransferComplete'"!][!"string($Unit)"!][!"' must be configured in '"!][!"name(.)"!][!//
                                    [!ENDERROR!][!//
                                [!ENDIF!][!//
                            [!ENDIF!][!//
                        [!ENDLOOP!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
                [!IF "$errorFlagCoco = 'true' or $errorFlagNotUse = 'true'"!][!//
                    [!ERROR!][!//
                    [!"'If hardware unit'"!] [!"string($Unit)"!] [!"'has at least one group configured as double buffering enable more than one channel (DBMO) and other groups are not in DBMO, 2 DMA channels which are configured for DBMO groups must have the same notification name and not NULL_PTR'"!][!//
                    [!ENDERROR!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!IF "$moreThanOneChannel = 'true'"!][!//
/**
* @brief Double buffering with more than one channel.
*/
#define ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL      (STD_ON)
[!ENDIF!][!//

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef ADC_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == ADC_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running  ADC in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == ADC_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifndef ADC_ENABLE_USER_MODE_SUPPORT */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT*/
/*==================================================================================================
*                                             ENUMS
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

#endif /* ADC_CFG_DEFINES_H */

/** @} */
