[!AUTOSPACING!]
[!CODE!][!//
/**
*   @file CDD_Mcl_Cfg.h
*   @version 1.0.2
*
*   @brief   AUTOSAR Mcl - contains the configuration data of the MCL driver
*   @details Contains the configuration data of the MCL driver
*
*   @addtogroup MCL_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
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
[!INCLUDE "CDD_Mcl_PluginMacro.m"!][!//

[!NOCODE!]
[!VAR "totalNumeDmaChannels" = "ecu:get('Mcl.eDMA.ChannelNumber')"!]
[!VAR "numeDmaChannelsPerInstance" = "ecu:get('Mcl.eDMA.ChannelNumberPerDmaInstance')"!]
[!VAR "numeDmaChannelsPerGroup" = "ecu:get('Mcl.eDMA.ChannelNumberPerGroup')"!]
[!VAR "numeDmaInstances" = "num:i($totalNumeDmaChannels div $numeDmaChannelsPerInstance)"!]
[!VAR "numeDmaMuxInstances" = "ecu:get('Mcl.DmaMux.DmaMuxInstances')"!]
[!VAR "ChCfgAddressesLittleEndianOrder" = "ecu:get('Mcl.DmaMux.ChCfgAddressesLittleEndianOrder')"!]
[!VAR "CombinedErrorIsr"                  = "num:i(ecu:get('Mcl.eDMA.CombinedErrorIsr'))"!][!//
[!VAR "CombinedTrCompletionIsr"           = "num:i(ecu:get('Mcl.eDMA.CombinedTrCompletionIsr'))"!][!//
[!VAR "TrCompletionMixedIsr"              = "num:i(ecu:get('Mcl.eDMA.CombinedTrComplMixedIsr'))"!][!//
[!VAR "GroupCompletionIsr"              = "num:i(ecu:get('Mcl.eDMA.CombinedGroupCompletionIsr'))"!][!//
[!VAR "EccErrorReportingEnabled"          = "num:i(ecu:get('Mcl.eDMA.EccErrorReportingEnabled'))"!][!//
[!VAR "EnableInitDMA_DCHMID"              = "num:i(ecu:get('Mcl.eDMA.EnableInitDMA_DCHMID'))"!][!//
[!ENDNOCODE!]


#ifndef CDD_MCL_CFG_H
#define CDD_MCL_CFG_H

#ifdef __cplusplus
extern "C"{
#endif 
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_Cfg_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
*          contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
*          significance and case sensitivity are supported for external identifiers.
*          This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Mcl_Cfg_h_REF_3
*          Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, 
*          a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
*          do-while-zero construct. 
*          This is used to abstract the export of configuration sets or for a function define.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Mcl_Cfg_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "Mcl_EnvCfg.h"
#include "Mcal.h"

[!NOCODE!]
[!VAR "MclDisableDemReport" = "0"!]
[!IF "node:exists(MclDemEventParameterRefs)"!]
      [!IF "MclGeneral/MclDisableDemReportErrorStatus = 'true'"!]
        [!VAR "MclDisableDemReport" = "1"!]
      [!ENDIF!]
[!ELSE!]
  [!VAR "MclDisableDemReport" = "1"!]
[!ENDIF!]
[!ENDNOCODE!]
[!IF "$MclDisableDemReport=0"!]
#include "Dem.h"
[!ENDIF!]
[!INCLUDE "CDD_Mcl_Cfg_h_checks.m"!][!//
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_VENDOR_ID_CFG                       43

#define MCL_AR_RELEASE_MAJOR_VERSION_CFG        4
#define MCL_AR_RELEASE_MINOR_VERSION_CFG        2
#define MCL_AR_RELEASE_REVISION_VERSION_CFG     2

#define MCL_SW_MAJOR_VERSION_CFG                1
#define MCL_SW_MINOR_VERSION_CFG                0
#define MCL_SW_PATCH_VERSION_CFG                2
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (MCL_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Mcal.h are different"
    #endif
#endif

/* Check if header file and Dem.h file are of the same Autosar version */
[!IF "$MclDisableDemReport=0"!]
 #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Dem header file are of the same Autosar version */
     #if (( MCL_AR_RELEASE_MAJOR_VERSION_CFG != DEM_AR_RELEASE_MAJOR_VERSION) || \
          ( MCL_AR_RELEASE_MINOR_VERSION_CFG != DEM_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Dem.h are different"
     #endif
 #endif
[!ENDIF!]

#if (MCL_VENDOR_ID_CFG != MCL_ENVCFG_VENDOR_ID)
    #error "CDD_Mcl_Cfg.h and Mcl_EnvCfg.h have different vendor ids"
#endif
/* Check if current file and Mcl_CfgEnv header file are of the same Autosar version */
#if (( MCL_AR_RELEASE_MAJOR_VERSION_CFG != MCL_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     ( MCL_AR_RELEASE_MINOR_VERSION_CFG != MCL_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     ( MCL_AR_RELEASE_REVISION_VERSION_CFG !=  MCL_ENVCFG_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Mcl_EnvCfg.h are different"
#endif
/* Check if current file and Mcl_CfgEnv header file are of the same software version */
#if ((MCL_SW_MAJOR_VERSION_CFG != MCL_ENVCFG_SW_MAJOR_VERSION) || \
     (MCL_SW_MINOR_VERSION_CFG != MCL_ENVCFG_SW_MINOR_VERSION) || \
     (MCL_SW_PATCH_VERSION_CFG != MCL_ENVCFG_SW_PATCH_VERSION))
     #error "Software Version Numbers of CDD_Mcl_Cfg.h and Mcl_EnvCfg.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
 [!VAR "mclFeatureEnabled" = "0"!][!//
    
[!IF "(IMPLEMENTATION_CONFIG_VARIANT ='VariantPreCompile') and (variant:size()<=1)"!]
/* Mcl Pre Compile Switch */
#define MCL_PRECOMPILE_SUPPORT (STD_ON)
[!ELSE!]
#define MCL_PRECOMPILE_SUPPORT (STD_OFF)
[!ENDIF!]




/**
*   @brief  Switches the Development Error Detection and Notification on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*   
*/
#define MCL_DEV_ERROR_DETECT                  ([!IF "MclGeneral/MclDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_GetVersionInfo() from the code.
*        STD_ON: Mcl_GetVersionInfo() can be used. STD_OFF: Mcl_GetVersionInfo() can not be used.
*   
*/
#define MCL_GET_VERSION_INFO_API              ([!IF "MclGeneral/Mcl_VersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_DeInit() from the code.
*        STD_ON: Mcl_DeInit() can be used. STD_OFF: Mcl_DeInit() can not be used.
*   
*/
#define MCL_DEINIT_API                        ([!IF "MclGeneral/Mcl_DeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      Switch to indicate that Mcl_SelectCommonTimebase API is supported
*           STD_ON: Mcl_SelectCommonTimebase() can be used. STD_OFF: Mcl_SelectCommonTimebase() can not be used.
*
*/
#define MCL_SELECT_COMMON_TIMEBASE_API        ([!IF "MclGeneral/Mcl_CommonTimebaseSupported"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief   Switches DMA features initialization on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*
*/
#define MCL_ENABLE_DMA              ([!IF "MclGeneral/EnableDMA"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!IF "MclGeneral/EnableDMA"!][!VAR "mclFeatureEnabled"="1"!][!ENDIF!]

/**
*   @brief  Switches the TRGMUX initialization by MCL on or off
*        STD_ON: Enabled. STD_OFF: Disabled.
*   
*/
#define MCL_ENABLE_TRGMUX                   ([!IF "MclGeneral/MclEnableTrgMux"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!IF "MclGeneral/MclEnableTrgMux"!][!VAR "mclFeatureEnabled"="1"!][!ENDIF!]
/**
* @brief define number of trigger mux registers
*/
#define MCL_NUM_TRGMUX_REG                  ([!"num:i(ecu:get('Mcl.MclConfigSet.TrgMux0.MaximumIndexRegs'))"!]U)
#define MCL_NUM_REG_MISSING_SEL_FIELD       ([!"num:i(ecu:get('Mcl.MclConfigSet.TrgMux0.NumberRegMissingSelField'))"!]U)
#define MCL_MAXIMUM_BIT_FIELD_TRIGGER_VALUE  (0x[!"num:hextoint(ecu:get('Mcl.MclConfigSet.TrgMux0.MaximumValueTrigger'))"!]U)

[!LOOP "ecu:list('Mcl.MclConfigSet.TrgMux0.ListOfReg')"!]
#define MCL_TRGMUX_[!"node:current()"!]_AVAILABLE
[!ENDLOOP!]



/*********************************** FLEXIO SECTION ********************************/
#define MCL_ENABLE_FLEXIO             ([!IF "MclGeneral/EnableFlexioSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!IF "MclGeneral/EnableFlexioSupport"!][!VAR "mclFeatureEnabled"="1"!][!ENDIF!]

[!IF "$mclFeatureEnabled=0"!][!//
   [!ERROR!] [!//
         "At least one MCL feature must be enabled(DMA, Crossbar, TriggerMux, Gtm , Flexio). "[!//
   [!ENDERROR!][!//
[!ENDIF!][!//
[!IF "MclGeneral/EnableDMA"!][!//
/**
* @brief      This define specifies enable or disable initialization of DCHMID register in DMA
*
*/
#define MCL_DMA_ENABLE_INIT_DCHMID ([!IF "$EnableInitDMA_DCHMID=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]) 
/**
* @brief      This define specifies the number of eDma Channels available for one eDma instance
*
*/
#define MCL_DMA_NB_CHANNELS                      ([!"num:inttohex($numeDmaChannelsPerInstance)"!]U)
/**
* @brief      This define specifies the number of eDma instances
*
*/
#define MCL_DMA_NB_CONTROLLERS                   ([!"num:inttohex($numeDmaInstances)"!]U)
/**
* @brief      This define specifies the number of eDma Mux instances
*
*/
#define MCL_DMAMUX_NB_MODULES                    ([!"num:inttohex($numeDmaMuxInstances)"!]U)

/**
* @brief      This define specifies the access to registers of dmamux is Little Endian or not
*
*/
#define MCL_DMAMUX_CHCFG_LITTLE_ENDIAN        ([!IF "$ChCfgAddressesLittleEndianOrder=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      The defines bellow specify the DMAMUX sources
*
*/
[!FOR "idx_DmaMux" = "0" TO "$numeDmaMuxInstances - 1"!][!/*
        */!][!NOCODE!]
        [!VAR "indexNode" = "0"!]
        [!VAR "DmaMuxInstanceXSources" = "concat('Mcl.MclConfigSet.DmaMux' , string($idx_DmaMux), '.Sources')"!]
        [!ENDNOCODE!]
        
/** @brief DMA Channel Sources for DmaMux Instance [!"$idx_DmaMux"!] */
    [!LOOP "ecu:list($DmaMuxInstanceXSources)"!]
        [!IF "contains(node:current(),'RESERVED')"!][!ELSE!]#define MCL_DMA_MUX_[!"num:i($idx_DmaMux)"!]_[!"node:current()"!] ([!"num:i($indexNode)"!]U)
        [!ENDIF!]
        [!NOCODE!]
        [!VAR "indexNode" = "$indexNode + 1"!]
        [!ENDNOCODE!]
    [!ENDLOOP!][!/*
*/!][!ENDFOR!]

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_DmaGetChannelErrorStatus() from the code.
*        STD_ON: Mcl_DmaGetChannelErrorStatusApi() can be used. STD_OFF: Mcl_DmaGetChannelErrorStatusApi() can not be used.
*   
*/
#define MCL_DMA_GET_CH_ERR_STATUS_API            ([!IF "MclGeneral/Mcl_DmaGetChannelErrorStatusApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes the service Mcl_DmaGetGlobalErrorStatusApi() from the code.
*        STD_ON: Mcl_DmaGetGlobalErrorStatusApi() can be used. STD_OFF: Mcl_DmaGetGlobalErrorStatusApi() can not be used.
*   
*/
#define MCL_DMA_GET_GLOBAL_ERR_STATUS_API            ([!IF "MclGeneral/Mcl_DmaGetGlobalErrorStatusApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      This define specifies the number of eTimer channels available
*             on the current platform
*
*/
#define MCL_EDMA_CHANNELS_NO            ([!"num:i($totalNumeDmaChannels)"!]U)

/**
* @brief      This define specifies the number of eTimer channels in a group of channels available
*             on the current platform
*
*/
#define MCL_EDMA_CHANNELS_IN_GROUP            ([!"num:i($numeDmaChannelsPerGroup)"!]U)

/**
* @brief      This define specifies the number of eTimer channels in a group of channels available
*             on the current platform
*
*/
#define MCL_DMA_ERROR_INTERRUPTS_USED            ([!IF "MclGeneral/MclErrorChecking"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      This define specifies if there is only one transfer completion ISR for all DMA channels within a DMA instance
*             or if there is a transfer completion ISR for each channel
*
*/
#define MCL_DMA_COMBINED_TR_COMPLETION_ISR ([!IF "$CombinedTrCompletionIsr=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      This define specifies if there is one transfer completion ISR for each group of DMA channels within a DMA instance
*
*/
#define MCL_DMA_COMBINED_GROUP_COMPLETION_ISR ([!IF "$GroupCompletionIsr=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#if (MCL_DMA_COMBINED_GROUP_COMPLETION_ISR == STD_ON)
[!IF "ecu:get('Mcl.eDMA.PriorityGroup0Exists')='true'"!]
[!CODE!]#define MCL_DMA_GROUP0_ISR_USED[!ENDCODE!]
[!ENDIF!]

[!IF "ecu:get('Mcl.eDMA.PriorityGroup1Exists')='true'"!]
[!CODE!]#define MCL_DMA_GROUP1_ISR_USED[!ENDCODE!]
[!ENDIF!]

#endif

/**
* @brief      This define specifies if there is only one error ISR for all DMA instances
*             or if there is an error ISR for each DMA instance
*
*/
#define MCL_DMA_COMBINED_ERROR_ISR ([!IF "$CombinedErrorIsr=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/**
* @brief      This define specifies if there is Ecc error reporting available          
*
*/
#define MCL_DMA_ECC_REPORTING_ENABLED ([!IF "$EccErrorReportingEnabled=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** 
* @brief  Switch to globaly enable/disable the production error reporting.
*/
#define MCL_DISABLE_DEM_REPORT_ERROR_STATUS  ([!IF "$MclDisableDemReport=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


[!VAR "NotificationUsed" = "num:i(0)"!]
[!VAR "isMixedIsrCase" = "num:i(0)"!]
[!VAR "isSeparatedIsrCase" = "num:i(0)"!]
[!NOCODE!]
    [!LOOP "MclGeneral/MclIsrAvailable/*"!]
        [!IF "MclIsrEnabled"!] 
            [!VAR "hwCh" = "num:i(substring-after(node:value(MclIsrName),'eDMA_'))"!]
                [!IF "$CombinedTrCompletionIsr=0 "!]
                    [!IF "(($TrCompletionMixedIsr=0) or ($hwCh < 96))"!]
                        [!CODE!]
#define MCL_DMA_CH_[!"$hwCh"!]_ISR_USED [!CR!]
                    [!ENDCODE!]
                    [!VAR "isSeparatedIsrCase" = "num:i(1)"!]
                [!ELSE!]
                    [!VAR "isMixedIsrCase" = "num:i(1)"!]
                [!ENDIF!]
            [!ENDIF!] /* combined transfer ISR*/
            [!VAR "NotificationUsed" = "num:i(1)"!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]

/**
* @brief      This define specifies if there is only one transfer completion ISR for a DMA channel within a DMA instance
*             or if there is a transfer completion ISR for each channel
*
*/
#define MCL_DMA_TR_SEPARATED_ISR ([!IF "$isSeparatedIsrCase=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief      This define specifies if inside a DMA instance some channels have the same transfer completion ISR assigned,
*             and other channels have their own transfer completion ISR.
*
*/
#define MCL_DMA_TR_COMPLETION_MIXED_ISR ([!IF "$isMixedIsrCase=1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/** Define to specify if least one transfer completion interrupt and notification is used, 
*      needed for removing at precompile time the code for ISR handling for the transfer 
*      completion notification processing. This define is needed in both combined transfer
*      completion interrupt and single channel mode. */
#define MCL_DMA_NOTIFICATION_SUPPORTED              ([!IF "$NotificationUsed = "1""!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Transfer size options available */
[!NOCODE!]
    [!LOOP "ecu:list('Mcl.eDMA.TransferSizeInBytes')"!]
        [!CODE!]
#define MCL_TRANSFER_SIZE_[!"num:i(node:current())"!]_BYTE [!CR!]
        [!ENDCODE!]      
    [!ENDLOOP!]
[!ENDNOCODE!]

[!ENDIF!][!//"MclGeneral/EnableDMA"


/**
* @brief      This define specifies the number of FTM modules present on the derivative. It's used for the
*             Mcl_SelectCommonTimebase API
*
*/
#define MCL_FTM_CHANNEL_NO            ((uint32)[!"num:i(ecu:get('Mcl.Ftm.NumberOfModules'))"!]UL)



/**
* @brief            Support for User mode.
*                   STD_ON: the Mcl driver can be executed from both supervisor and user mode. 
*                   STD_OFF: the Mcl driver can be executed only from supervisor mode. 
*/
#define MCL_ENABLE_USER_MODE_SUPPORT     ([!IF "MclGeneral/MclEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define MCL_DMAMUX_USER_MODE_SUPPORT     ([!IF "node:containsValue(ecu:list('Mcl.Ipv.UserMode.Available'),'DMA_MUX')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define MCL_AXBS_USER_MODE_SUPPORT     ([!IF "node:containsValue(ecu:list('Mcl.Ipv.UserMode.Available'),'AXBS')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define MCL_LMEM_USER_MODE_SUPPORT     ([!IF "node:containsValue(ecu:list('Mcl.Ipv.UserMode.Available'),'LMEM')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define MCL_TRGMUX_USER_MODE_SUPPORT     ([!IF "node:containsValue(ecu:list('Mcl.Ipv.UserMode.Available'),'TRGMUX')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/**
* @brief            Protected Register in User mode
*                   Macro use to enable if IP hw need to configure Reg_Prot to access from user mode
*/

#define MCL_DMAMUX_REG_PROT_AVAILABLE ([!IF "node:containsValue(ecu:list('Mcl.Ipv.RegProt.Available'),'DMA_MUX')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == MCL_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Mcl in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == MCL_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */


/*********************************** CACHE SECTION ***********************************/
/* Enable LMEM cache functionality */
#define MCL_LMEM_ENABLE_CACHE_API           ([!IF "MclGeneral/MclLmem/MclLmemEnableCacheApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Enable the use of cache invalidate and flush calls in other drivers */
#define MCL_SYNCRONIZE_CACHE                ([!IF "MclGeneral/MclLmem/MclSynchronizeCache"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* LMEM Cache operations timeout value */
#define MCL_LMEM_CACHE_TIMEOUT_VALUE        ([!"MclGeneral/MclLmem/MclLmemCacheTimeout"!]UL)

/* LMEM Enable also Write Buffer alongside with Cache enable */
#define MCL_LMEM_CACHE_ENABLE_WRITE_BUFFER  ([!IF "MclGeneral/MclLmem/MclLmemEnableWriteBuffer"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* PS Cache instance hardware availability */
#define MCL_LMEM_CACHE_PS_AVAILABLE         ([!"ecu:get('Mcl.Lmem.CachePSAvailable')"!])

/* PC cache total size, expressed in bytes */
#define MCL_LMEM_CACHE_PC_SIZE              ((uint32)[!"num:i(ecu:get('Mcl.Lmem.CachePCSize'))"!]UL)

/* PS cache total size, expressed in bytes */
#define MCL_LMEM_CACHE_PS_SIZE              ((uint32)[!"num:i(ecu:get('Mcl.Lmem.CachePSSize'))"!]UL)

/* Cache line size, expressed in bytes */
#define MCL_LMEM_CACHE_LINE_SIZE            ((uint32)[!"num:i(ecu:get('Mcl.Lmem.CacheLineSize'))"!]UL)

/*********************************** CACHE SECTION ***********************************/



/** Variant aware structure [!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!].c file. */
[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
    [!CALL "MclExportDriverConfiguration"!]
[!ELSE!]
/**Variant aware structure pre-compiled.c file */
 /** @violates @ref Mcl_Cfg_h_REF_3 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */ 
#define MCL_INIT_CONFIG_PC_DEFINE extern CONST(Mcl_ConfigType, MCL_CONST) Mcl_Init_PBCfgVariantPredefined;
[!ENDIF!]

/*==================================================================================================
                                             ENUMS
==================================================================================================*/
[!IF "MclGeneral/EnableDMA"!][!//
#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief            DEM error reporting configuration.
* @details          This structure contains information DEM error reporting
*/
typedef struct
{
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Bus;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Descriptor;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Priority;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Unrecognized;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Inconsistency;
} Mcl_DemConfigType;

extern CONST( Mcl_DemConfigType, MCL_CONST) Mcl_Dem_Config;

#endif

[!ENDIF!]

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif    /* CDD_MCL_CFG_H */
/**@}*/

[!ENDCODE!]

