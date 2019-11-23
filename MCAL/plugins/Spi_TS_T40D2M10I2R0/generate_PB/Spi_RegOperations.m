[!NOCODE!][!//
/**   
  @file    Spi_RegOperations.m
  @version 1.0.2

  @brief   AUTOSAR Spi - File used by the C generation templates.
  @details This file contains macros used by the C generation templates.
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPSPI,FLEXIO
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
[!//============================FILE VERSION CHECKS=====================================================
[!MACRO "Spi_FileVersionCheck"!]
[!CODE!][!//
/* Check if current file and SPI header file are of the same vendor */
#if (SPI_VENDOR_ID_PBCFG_C != SPI_VENDOR_ID)
    #error "Spi_PBCfg.c and Spi.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_PBCFG_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_PBCFG_C != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_PBCFG_C != SPI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif

/* Check if current file and Reg_eSys_LPspi.h file are of the same vendor */
#if (SPI_VENDOR_ID_PBCFG_C != REG_ESYS_LPSPI_VENDOR_ID_REGFLEX)
    #error "Spi_PBCfg.c and Reg_eSys_LPspi.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_LPspi.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != REG_ESYS_LPSPI_AR_RELEASE_MAJOR_VERSION_REGFLEX) || \
     (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C    != REG_ESYS_LPSPI_AR_RELEASE_MINOR_VERSION_REGFLEX) || \
     (SPI_AR_RELEASE_REVISION_VERSION_PBCFG_C != REG_ESYS_LPSPI_AR_RELEASE_REVISION_VERSION_REGFLEX))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Reg_eSys_LPspi.h are different"
#endif
/* Check if current file and Reg_eSys_LPspi.h file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_PBCFG_C != REG_ESYS_LPSPI_SW_MAJOR_VERSION_REGFLEX) || \
     (SPI_SW_MINOR_VERSION_PBCFG_C != REG_ESYS_LPSPI_SW_MINOR_VERSION_REGFLEX) || \
     (SPI_SW_PATCH_VERSION_PBCFG_C != REG_ESYS_LPSPI_SW_PATCH_VERSION_REGFLEX))
    #error "Software Version Numbers of Spi_PBCfg.c and Reg_eSys_LPspi.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Check if current file and Dem.h file are of the same Autosar version */
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MAJOR_VERSION) || \
        (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Spi_PBCfg.c and Dem.h are different"
    #endif
    #endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
#endif  
[!ENDCODE!][!//
[!ENDMACRO!][!//
[!//====================================================================================================
[!MACRO "Spi_CheckHwTypeAssignedInOneSequence"!]
[!LOOP "SpiDriver/SpiSequence/*"!]
    [!VAR "Exist_LPSPI" = "0"!]
    [!VAR "Exist_FLEXIO" = "0"!]
    [!LOOP "SpiJobAssignment/*"!]
        [!SELECT "node:ref(node:current())"!] [!//
            [!SELECT "node:ref(SpiDeviceAssignment)"!] [!//
            [!VAR "CSIB_number"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
            [!IF "contains((substring-before((node:value(../../../SpiGeneral/SpiPhyUnit/*[num:i($CSIB_number)]/SpiPhyUnitMapping)),'_')),'LPSPI')"!][!//
                [!VAR "Exist_LPSPI" = "1"!]
            [!ENDIF!]
            [!IF "contains((substring-before((node:value(../../../SpiGeneral/SpiPhyUnit/*[num:i($CSIB_number)]/SpiPhyUnitMapping)),'_')),'FLEXIOSPI')"!][!//
                [!VAR "Exist_FLEXIO" = "1"!]
            [!ENDIF!]
            [!ENDSELECT!] [!//
        [!ENDSELECT!] [!//
        [!ENDLOOP!] [!//
    [!IF "$Exist_LPSPI = 1"!]
    [!IF "$Exist_FLEXIO = 1"!]
        [!ERROR!]Jobs have assigned for a sequense need to same HW Type (only FLEXIO or only LPSPI)[!ENDERROR!]
    [!ENDIF!]
    [!ENDIF!]    
    [!ENDLOOP!] [!//
[!ENDMACRO!][!//
[!//====================================================================================================
[!//
[!//===================Check Dual Clock Support============================================
[!MACRO "Spi_CheckDualClockSupport"!]
[!VAR "DualClockSupport"= "'false'"!]
[!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
[!IF "(node:exists(SpiPhyUnitAlternateClockRef))"!][!//
[!VAR "DualClockSupport"= "'true'"!]
[!ENDIF!][!//
[!ENDLOOP!][!//

[!VAR "DualClockEnabled" = "'false'"!][!//
[!ENDMACRO!][!//
[!//======================================================================================
[!//
[!//===================Check configuration of sequences for Slave=========================
[!MACRO "Spi_CheckSequenceConfigForSlave"!]
[!VAR "Spislavesupported" = "0"!][!//
[!VAR "Spislavesupported1" = "0"!][!//
[!LOOP "SpiDriver/SpiSequence/*"!]
    [!LOOP "SpiJobAssignment/*"!]
        [!SELECT "node:ref(node:current())"!] [!//
            [!SELECT "node:ref(SpiDeviceAssignment)"!] [!//
                [!IF "SpiSlaveMode = 'true'"!] [!//
                    [!VAR "Spislavesupported" = "1"!][!//
                    [!VAR "Spislavesupported1" = "1"!][!//
                [!ENDIF!] [!//
            [!ENDSELECT!] [!//
            [!IF "$Spislavesupported1=1"!] [!//
                [!IF "(count(SpiChannelList/*))!=1"!]
                    [!ERROR "Channel error(In slave mode only one channel needs to be configured)"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDSELECT!] [!//
    [!ENDLOOP!] [!//
    [!IF "$Spislavesupported1=1"!] [!//
        [!IF "count(SpiJobAssignment/*)!=1"!]
        [!ERROR "Job error(In slave mode only one Job needs to be configured)"!]
        [!ENDIF!]
    [!ENDIF!]
[!VAR "Spislavesupported1" = "0"!][!//
[!ENDLOOP!] [!//
[!ENDMACRO!][!//
[!//======================================================================================= 
[!//
[!//=======================Check configuration of External Devices========================= 
[!MACRO "Spi_CheckExternalDeviceConfig"!]
[!VAR "spiPath" = "node:path(.)"!][!//
[!LOOP "SpiDriver/SpiSequence/*"!]
    [!LOOP "SpiJobAssignment/*"!]
        [!SELECT "node:ref(node:current())"!] [!//
            [!SELECT "node:ref(SpiDeviceAssignment)"!] [!//
                [!IF "SpiSlaveMode = 'true'"!] [!//
                    [!VAR "varSpiSlaveunit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
                    [!IF "node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$varSpiSlaveunit,']/SpiPhyUnitMode')) != 'SPI_SLAVE' "!][!//
                        [!ERROR!]As the device [!"@name"!] selected to slave mode, hardware unit mapped to this Device has to be in slave mode.[!ENDERROR!][!//
                    [!ENDIF!] [!//
                [!ENDIF!] [!//
                [!IF "SpiSlaveMode = 'false'"!] [!//
                    [!VAR "varSpiSlaveunit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
                    [!IF "node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$varSpiSlaveunit,']/SpiPhyUnitMode')) != 'SPI_MASTER' "!][!//
                        [!ERROR!]As the device [!"@name"!] is not selected to slave mode, hardware unit mapped to this Device has to be in Master mode.[!ENDERROR!][!//
                    [!ENDIF!] [!//
                [!ENDIF!] [!//
            [!ENDSELECT!] [!//
        [!ENDSELECT!] [!//
    [!ENDLOOP!] [!//
[!ENDLOOP!] [!//
[!ENDMACRO!][!//
[!//=======================================================================================
[!//
[!//=======================================================================================
[!MACRO "DetermineOptimalTimeSettings_LPSPI"!]
  [!VAR "OptimalAbsoluteTimeError" = "1000000"!]
  [!VAR "OptimalRelativeTimeError" = "0"!]
  [!VAR "OptimalTime" = "0"!]
  [!VAR "OptimalPrescaler" = "0"!]
  [!IF "$DesiredTime > 0.0"!]
    [!FOR "Prescaler_Count" = "0" TO "255"!]
        [!VAR "CalculatedTime" = "($Prescaler_Count + 1) * 1000 * ($OptimalPRESCALE div $BusClock)"!]
        [!VAR "RelativeTimeError" = "($CalculatedTime div $DesiredTime) - 1 "!]
        [!VAR "AbsoluteTimeError" = "$RelativeTimeError"!]
        [!IF "$AbsoluteTimeError < 0"!][!VAR "AbsoluteTimeError" = "$AbsoluteTimeError * (-1)"!][!ENDIF!]
        [!IF "$AbsoluteTimeError < $OptimalAbsoluteTimeError"!]
          [!VAR "OptimalAbsoluteTimeError" = "$AbsoluteTimeError"!]
          [!VAR "OptimalRelativeTimeError" = "$RelativeTimeError"!]
          [!VAR "OptimalTime" = "$CalculatedTime"!]
          [!VAR "OptimalPrescaler" = "$Prescaler_Count"!]
        [!ENDIF!]
    [!ENDFOR!]
  [!ELSE!]
    [!VAR "OptimalRelativeTimeError" = "1000 * ($OptimalPRESCALE div $BusClock)"!]
    [!VAR "OptimalTime" = "$OptimalRelativeTimeError"!]
    [!VAR "OptimalPrescaler" = "0"!]
  [!ENDIF!]
[!ENDMACRO!]
[!//===================================================================================================
[!MACRO "DetermineOptimalBaudrateSettings_LPSPI"!]
  [!VAR "OptimalAbsoluteBaudrateError" = "1000000"!]
  [!VAR "OptimalRelativeBaudrateError" = "0"!]
  [!VAR "OptimalBaudrate" = "0"!]
  [!VAR "OptimalPrescaler" = "0"!]
  [!VAR "OptimalSckDivider" = "0"!]
    [!FOR "Prescaler_Count" = "0" TO "7"!]
      [!IF "$Prescaler_Count = 0"!]
        [!VAR "Prescaler" = "1"!]
      [!ELSE!]
        [!VAR "Prescaler" = "$Prescaler*2"!]
      [!ENDIF!]
      [!VAR "SckDivider" = "0"!]
      [!FOR "SckDivider" = "0" TO "255"!]
        [!VAR "CalculatedBaudrate" = "1000000 * $BusClock div ($Prescaler * ($SckDivider+2))"!]
        [!// DesiredBaudrate is always positive
        [!VAR "RelativeBaudrateError" = "($CalculatedBaudrate div $DesiredBaudrate) - 1 "!]
        [!VAR "AbsoluteBaudrateError" = "$RelativeBaudrateError"!]
        [!IF "$AbsoluteBaudrateError < 0"!][!VAR "AbsoluteBaudrateError" = "$AbsoluteBaudrateError * (-1)"!][!ENDIF!]
        [!IF "$AbsoluteBaudrateError < $OptimalAbsoluteBaudrateError"!]
          [!VAR "OptimalAbsoluteBaudrateError" = "$AbsoluteBaudrateError"!]
          [!VAR "OptimalRelativeBaudrateError" = "$RelativeBaudrateError"!]
          [!VAR "OptimalBaudrate" = "$CalculatedBaudrate"!]
          [!VAR "OptimalPrescaler" = "$Prescaler"!]
          [!VAR "OptimalSckDivider" = "$SckDivider"!]
        [!ENDIF!]
      [!ENDFOR!]
    [!ENDFOR!]
[!ENDMACRO!]
[!//===================================================================================================
[!MACRO "DetermineOptimalBaudrateSettings_FLEXIO"!]
[!VAR "DesiredBaudrate" = "SpiBaudrate"!]
[!VAR "BusClock" = "$BusClockNormal * 1000000"!]
[!VAR "OptimalPrescaler" = "($BusClock div ($DesiredBaudrate * 2)) - 1"!]
[!IF "$DualClockEnabled = 'true'"!][!//
[!VAR "DesiredBaudrateAlternate" = "SpiBaudrateAlternate"!]
[!VAR "BusClockAlternate_1" = "$BusClockAlternate * 1000000"!]
[!VAR "OptimalPrescalerAlternate" = "($BusClockAlternate_1 div ($DesiredBaudrateAlternate * 2)) - 1"!]
[!ENDIF!]
[!ENDMACRO!]
[!//===================================================================================================
[!MACRO "GenerateExternalDeviceInfo_LPSPI"!]
[!NOCODE!][!//
  [!//
  [!VAR "BusClock" = "$BusClockNormal"!][!//
  [!VAR "DesiredBaudrate" = "SpiBaudrate"!]
  [!CALL "DetermineOptimalBaudrateSettings_LPSPI"!]
  [!VAR "OptimalPRESCALE" = "$OptimalPrescaler"!]
  [!VAR "OptimalSCKDIV" = "$OptimalSckDivider"!]
  [!VAR "OptimalBaudrateNormal" = "$OptimalBaudrate"!]
  [!VAR "OptimalRelativeBaudrateErrorNormal" = "$OptimalRelativeBaudrateError"!]
  [!//
  [!VAR "DesiredTime" = "num:i(SpiTimeCs2Clk * 1000000000)"!]
  [!CALL "DetermineOptimalTimeSettings_LPSPI"!]
  [!VAR "OptimalPCSSCK" = "$OptimalPrescaler"!]
  [!VAR "OptimalTimeCs2Clk" = "$OptimalTime"!]
  [!VAR "OptimalTimeCs2ClkError" = "$OptimalRelativeTimeError"!]
  [!//
  [!VAR "DesiredTime" = "num:i(SpiTimeClk2Cs * 1000000000)"!]
  [!CALL "DetermineOptimalTimeSettings_LPSPI"!]
  [!VAR "OptimalSCKPCS" = "$OptimalPrescaler"!]
  [!VAR "OptimalTimeClk2Cs" = "$OptimalTime"!]
  [!VAR "OptimalTimeClk2CsError" = "$OptimalRelativeTimeError"!]
  [!//
  [!VAR "DesiredTime" = "num:i(SpiTimeCs2Cs * 1000000000)"!]
  [!CALL "DetermineOptimalTimeSettings_LPSPI"!]
  [!VAR "OptimalDBT" = "$OptimalPrescaler"!]
  [!VAR "OptimalTimeCs2Cs" = "$OptimalTime"!]
  [!VAR "OptimalTimeCs2CsError" = "$OptimalRelativeTimeError"!]
  [!//
  [!IF "$DualClockEnabled = 'true'"!][!//
    [!VAR "BusClock" = "$BusClockAlternate"!][!//
    [!VAR "DesiredBaudrate" = "SpiBaudrateAlternate"!]
    [!CALL "DetermineOptimalBaudrateSettings_LPSPI"!]
    [!VAR "OptimalPRESCALEAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalSCKDIVAlternate" = "$OptimalSckDivider"!]
    [!VAR "OptimalBaudrateAlternate" = "$OptimalBaudrate"!]
    [!VAR "OptimalRelativeBaudrateErrorAlternate" = "$OptimalRelativeBaudrateError"!]
    [!//
    [!VAR "DesiredTime" = "num:i(SpiTimeCs2Clk * 1000000000)"!]
    [!CALL "DetermineOptimalTimeSettings_LPSPI"!]
    [!VAR "OptimalPCSSCKAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalTimeCs2ClkAlternate" = "$OptimalTime"!]
    [!VAR "OptimalTimeCs2ClkErrorAlternate" = "$OptimalRelativeTimeError"!]
    [!//
    [!VAR "DesiredTime" = "num:i(SpiTimeClk2Cs * 1000000000)"!]
    [!CALL "DetermineOptimalTimeSettings_LPSPI"!]
    [!VAR "OptimalSCKPCSAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalTimeClk2CsAlternate" = "$OptimalTime"!]
    [!VAR "OptimalTimeClk2CsErrorAlternate" = "$OptimalRelativeTimeError"!]
    [!//
    [!VAR "DesiredTime" = "num:i(SpiTimeCs2Cs * 1000000000)"!]
    [!CALL "DetermineOptimalTimeSettings_LPSPI"!]
    [!VAR "OptimalDBTAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalTimeCs2CsAlternate" = "$OptimalTime"!]
    [!VAR "OptimalTimeCs2CsErrorAlternate" = "$OptimalRelativeTimeError"!]
    [!//
  [!ENDIF!][!// "$DualClockEnabled = 'true'"
  [!//  
[!ENDNOCODE!][!//
[!IF "$DualClockSupport = 'true'"!][!//
          { /* TCR register configuration */
            /* Normal Mode */
[!ENDIF!][!//
            (uint32)([!IF "SpiShiftClockIdleLevel = 'LOW'"!]LPSPI_TCR_CPOL_LOW_U32[!//
[!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]LPSPI_TCR_CPOL_HIGH_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
[!ENDIF!] | /* Clock Polarity (Idle State) */
                [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    LPSPI_TCR_CPHA_LEADING_U32[!//
[!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    LPSPI_TCR_CPHA_TRAILING_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
[!ENDIF!] | /* Clock Phase */  
            LPSPI_TCR_PRESCALE_[!"num:i($OptimalPRESCALE)"!]_U32 /* Baudrate: Should=[!"SpiBaudrate"!], Is=[!"num:i($OptimalBaudrateNormal)"!], Error=[!"round(10000*$OptimalRelativeBaudrateErrorNormal) div 100"!]% */
          | [!IF "SpiByteSwap = 'TRUE'"!] LPSPI_TCR_BYSW_EN_U32 [!ELSE!] LPSPI_TCR_BYSW_DIS_U32 [!ENDIF!]
          | [!IF "SpiEnableCs = 'true'"!]
            [!IF "node:exists(SpiCsSelection)"!][!//
                [!IF "SpiCsSelection = 'CS_VIA_PERIPHERAL_ENGINE'"!][!//
                    (uint32)(LPSPI_TCR_[!"SpiCsIdentifier"!]_EN_U32 | /* Chip Select Pin Via Peripheral Engine*/
                    [!IF "SpiCsContinous = 'FALSE'"!][!WS "12"!]    LPSPI_TCR_CONT_DIS_U32)/* Disable continuous chip select */
                    [!ELSEIF "SpiCsContinous = 'TRUE'"!][!WS "12"!]  LPSPI_TCR_CONT_EN_U32)/* Enable continuous chip select */
                    [!ELSE!][!ERROR "Illegal value for SpiCsContinous"!][!//
                    [!ENDIF!][!//
                [!ELSEIF "SpiCsSelection = 'CS_VIA_GPIO'"!][!//
                    0x00000000u /* Chip Select Via GPIO */
                [!ENDIF!][!//
            [!ELSE!][!WS "8"!]0x00000000u /* Chip Select Via GPIO */
            [!ENDIF!][!//
            [!ELSE!][!WS "8"!]0x00000000u
            [!ENDIF!]
) & LPSPI_TCR_RESERVED_MASK_U32,
[!IF "$DualClockSupport = 'true'"!][!//
[!AUTOSPACING!][!IF "$DualClockEnabled = 'true'"!][!//
            /* Alternate Mode */
            (uint32)([!IF "SpiShiftClockIdleLevel = 'LOW'"!]LPSPI_TCR_CPOL_LOW_U32[!//
[!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]LPSPI_TCR_CPOL_HIGH_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
[!ENDIF!] | /* Clock Polarity (Idle State) */
            [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    LPSPI_TCR_CPHA_LEADING_U32[!//
[!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    LPSPI_TCR_CPHA_TRAILING_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
[!ENDIF!] | /* Clock Phase */ 
            LPSPI_TCR_PRESCALE_[!"num:i($OptimalPRESCALEAlternate)"!]_U32 /* Baudrate: Should=[!"SpiBaudrate"!], Is=[!"num:i($OptimalBaudrateAlternate)"!], Error=[!"round(10000*$OptimalRelativeBaudrateErrorAlternate) div 100"!]% */
          | [!IF "SpiByteSwap = 'TRUE'"!] LPSPI_TCR_BYSW_EN_U32 [!ELSE!] LPSPI_TCR_BYSW_DIS_U32 [!ENDIF!]
          | [!IF "SpiEnableCs = 'true'"!]
            [!IF "node:exists(SpiCsSelection)"!]
                [!IF "SpiCsSelection = 'CS_VIA_PERIPHERAL_ENGINE'"!][!//
                    (uint32)(LPSPI_TCR_[!"SpiCsIdentifier"!]_EN_U32 | /* Chip Select Pin Via Peripheral Engine*/
                    [!IF "SpiCsContinous = 'FALSE'"!][!WS "12"!]    LPSPI_TCR_CONT_DIS_U32)/* Disable continuous chip select */
                    [!ELSEIF "SpiCsContinous = 'TRUE'"!][!WS "12"!]    LPSPI_TCR_CONT_EN_U32)/* Enable continuous chip select */
                    [!ELSE!][!ERROR "Illegal value for SpiCsContinous"!][!//
                    [!ENDIF!][!//
                [!ELSEIF "SpiCsSelection = 'CS_VIA_GPIO'"!][!//
                    0x00000000u/* Chip Select Via GPIO */
                [!ENDIF!][!//
            [!ELSE!][!WS "8"!]0x00000000u /* Chip Select Via GPIO */
            [!ENDIF!][!//
            [!ELSE!][!WS "8"!]0x00000000u
            [!ENDIF!]
    [!ELSE!][!//
            /*SpiHwUnit is not enable Alternate Mode, Set TCR is the same configuration as Normal Mode to use*/
            /* Normal Mode */
(uint32)([!IF "SpiShiftClockIdleLevel = 'LOW'"!]LPSPI_TCR_CPOL_LOW_U32[!//
[!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]LPSPI_TCR_CPOL_HIGH_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
[!ENDIF!] | /* Clock Polarity (Idle State) */
                [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    LPSPI_TCR_CPHA_LEADING_U32[!//
[!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    LPSPI_TCR_CPHA_TRAILING_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
[!ENDIF!] | /* Clock Phase */  
            LPSPI_TCR_PRESCALE_[!"num:i($OptimalPRESCALE)"!]_U32 /* Baudrate: Should=[!"SpiBaudrate"!], Is=[!"num:i($OptimalBaudrateNormal)"!], Error=[!"round(10000*$OptimalRelativeBaudrateErrorNormal) div 100"!]% */
          | [!IF "SpiByteSwap = 'TRUE'"!] LPSPI_TCR_BYSW_EN_U32 [!ELSE!] LPSPI_TCR_BYSW_DIS_U32 [!ENDIF!]
          | [!IF "SpiEnableCs = 'true'"!]
            [!IF "node:exists(SpiCsSelection)"!]
                [!IF "SpiCsSelection = 'CS_VIA_PERIPHERAL_ENGINE'"!][!//
                    (uint32)(LPSPI_TCR_[!"SpiCsIdentifier"!]_EN_U32 | /* Chip Select Pin Via Peripheral Engine*/
                    [!IF "SpiCsContinous = 'FALSE'"!][!WS "12"!]    LPSPI_TCR_CONT_DIS_U32)/* Disable continuous chip select */
                    [!ELSEIF "SpiCsContinous = 'TRUE'"!][!WS "12"!]  LPSPI_TCR_CONT_EN_U32)/* Enable continuous chip select */
                    [!ELSE!][!ERROR "Illegal value for SpiCsContinous"!][!//
                    [!ENDIF!][!//
                [!ELSEIF "SpiCsSelection = 'CS_VIA_GPIO'"!][!//
                    0x00000000u /* Chip Select Via GPIO */
                [!ENDIF!][!//
            [!ELSE!][!WS "8"!]0x00000000u /* Chip Select Via GPIO */
            [!ENDIF!][!//
            [!ELSE!][!WS "8"!]0x00000000u
            [!ENDIF!]
    [!ENDIF!][!//
            )  & LPSPI_TCR_RESERVED_MASK_U32
},
[!ENDIF!][!//
[!IF "$DualClockSupport = 'true'"!][!//
     { /* CCR register configuration */
            /* Normal Mode */
[!ENDIF!][!//
            ( ((uint32)([!"num:i($OptimalSCKPCS)"!]) << 24u) | /* TimeClk2Cs: Should=[!"num:i(SpiTimeClk2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeClk2Cs)"!], Error=[!"round(10000*$OptimalTimeClk2CsError) div 100"!]% */
            ((uint32)([!"num:i($OptimalPCSSCK)"!]) << 16u) | /* TimeCs2Clk: Should=[!"num:i(SpiTimeCs2Clk * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2Clk)"!], Error=[!"round(10000*$OptimalTimeCs2ClkError) div 100"!]% */
            ((uint32)([!"num:i($OptimalDBT)"!]) << 8u) | /* TimeCs2Cs: Should=[!"num:i(SpiTimeCs2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2Cs)"!], Error=[!"round(10000*$OptimalTimeCs2CsError) div 100"!]% */
            ((uint32)([!"num:i($OptimalSCKDIV)"!]))
            ),
[!IF "$DualClockSupport = 'true'"!][!//
[!IF "$DualClockEnabled = 'true'"!][!//
            /* Alternate Mode */
            ( ((uint32)([!"num:i($OptimalSCKPCSAlternate)"!]) << 24u) | /* TimeClk2Cs: Should=[!"num:i(SpiTimeClk2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeClk2CsAlternate)"!], Error=[!"round(10000*$OptimalTimeClk2CsErrorAlternate) div 100"!]% */
            ((uint32)([!"num:i($OptimalPCSSCKAlternate)"!]) << 16u) | /* TimeCs2Clk: Should=[!"num:i(SpiTimeCs2Clk * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2ClkAlternate)"!], Error=[!"round(10000*$OptimalTimeCs2ClkErrorAlternate) div 100"!]% */
            ((uint32)([!"num:i($OptimalDBTAlternate)"!]) << 8u) | /* TimeCs2Cs: Should=[!"num:i(SpiTimeCs2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2CsAlternate)"!], Error=[!"round(10000*$OptimalTimeCs2CsErrorAlternate) div 100"!]% */
            ((uint32)([!"num:i($OptimalSCKDIVAlternate)"!]))
            )
    [!ELSE!]
            /*SpiHwUnit is not enable Alternate Mode, Set CCR is the same configuration as Normal Mode to use*/
            /* Normal Mode */
            ( ((uint32)([!"num:i($OptimalSCKPCS)"!]) << 24u) | /* TimeClk2Cs: Should=[!"num:i(SpiTimeClk2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeClk2Cs)"!], Error=[!"round(10000*$OptimalTimeClk2CsError) div 100"!]% */
            ((uint32)([!"num:i($OptimalPCSSCK)"!]) << 16u) | /* TimeCs2Clk: Should=[!"num:i(SpiTimeCs2Clk * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2Clk)"!], Error=[!"round(10000*$OptimalTimeCs2ClkError) div 100"!]% */
            ((uint32)([!"num:i($OptimalDBT)"!]) << 8u) | /* TimeCs2Cs: Should=[!"num:i(SpiTimeCs2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2Cs)"!], Error=[!"round(10000*$OptimalTimeCs2CsError) div 100"!]% */
            ((uint32)([!"num:i($OptimalSCKDIV)"!]))
            )
    [!ENDIF!]
      },
[!ENDIF!][!//
[!IF "$DualClockSupport = 'true'"!][!//
[!AUTOSPACING!][!IF "$DualClockEnabled = 'true'"!][!//
        (uint8)TRUE,
    [!ELSE!][!WS "8"!](uint8)FALSE,
    [!ENDIF!]
[!ENDIF!]
/* CFG1 register configuration */
[!IF "SpiCsPolarity = 'HIGH'"!][!//
    [!WS "8"!]    LPSPI_CFGR1_[!"SpiCsIdentifier"!]_IDLELOW_U32[!//
[!ELSE!][!WS "8"!](uint32)0u[!//
[!ENDIF!][!WS "2"!]/* Chip select polarity */
     | LPSPI_CFGR1_PINCFG_[!"node:value(SpiPinConfig)"!]_U32 | LPSPI_CFGR1_MATCFG_DIS_U32 | LPSPI_CFGR1_MASTER_EN_U32
[!ENDMACRO!]
[!//===================================================================================================
[!MACRO "GenerateExternalDeviceInfo_FLEXIO"!]
  [!CALL "DetermineOptimalBaudrateSettings_FLEXIO"!][!//
  [!VAR "OptimalPRESCALE" = "$OptimalPrescaler"!][!//
  [!IF "$DualClockEnabled = 'true'"!][!//
  [!VAR "OptimalPRESCALEAlternate" = "$OptimalPrescalerAlternate"!][!//  
  [!ENDIF!]
  [!VAR "CS_Continuons" = "0"!]
  [!IF "SpiShiftClockIdleLevel = 'LOW'"!](uint8)SPI_FLEXIO_CPOL_LOW_U8[!//
  [!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!](uint8)SPI_FLEXIO_CPOL_HIGH_U8[!//
  [!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
  [!ENDIF!], /* Clock Polarity (Idle State) */
  [!IF "SpiDataShiftEdge = 'LEADING'"!](uint8)SPI_FLEXIO_CPHA_LEADING_U8[!//
  [!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!](uint8)SPI_FLEXIO_CPHA_TRAILING_U8[!//
  [!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
  [!ENDIF!], /* Clock Phase */
  [!IF "$DualClockSupport = 'true'"!][!//
  {
  (uint32)[!"num:inttohex($OptimalPRESCALE)"!]u, /* Normal clock */
  [!IF "$DualClockEnabled = 'true'"!][!// 
  (uint32)[!"num:inttohex($OptimalPRESCALEAlternate)"!]u /* Alternate Clock */
  [!ELSE!]
  (uint32)[!"num:inttohex($OptimalPRESCALE)"!]u  /* Normal clock */
  [!ENDIF!]
  }
  [!ELSE!]
  (uint32)[!"num:inttohex($OptimalPRESCALE)"!]u /* Normal clock */
  [!ENDIF!]
  [!IF "SpiCsContinous = 'TRUE'"!]
    [!VAR "CS_Continuons" = "1"!]
  [!ELSE!] 
    [!VAR "CS_Continuons" = "0"!]
  [!ENDIF!]
 [!VAR "CSIB_number"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
[!SELECT "(../../../SpiGeneral/SpiPhyUnit/*[num:i($CSIB_number)])"!][!//
,(uint32)0u /* Shifter config for TX */
, [!IF "node:value(SpiPhyUnitMapping) = 'FLEXIOSPI_0'"!]SPI_FLEXIO_SHIFTCLT_TIMSEL0_U32[!ELSE!]SPI_FLEXIO_SHIFTCLT_TIMSEL2_U32[!ENDIF!][!//
 | SPI_FLEXIO_PINSEL[!"(substring-after((node:value(SpiFlexioTxPinSelect)),'PIN_'))"!]_U32[!//
 | SPI_FLEXIO_PINCFG_OUT_U32 [!//
 | SPI_FLEXIO_SHIFTCLT_SMOD_TX_U32 /* Shifter control for TX */
,(uint32)0u /* Shifter config for RX */
, [!IF "node:value(SpiPhyUnitMapping) = 'FLEXIOSPI_0'"!]SPI_FLEXIO_SHIFTCLT_TIMSEL0_U32[!ELSE!]SPI_FLEXIO_SHIFTCLT_TIMSEL2_U32[!ENDIF!][!//
 | SPI_FLEXIO_PINSEL[!"(substring-after((node:value(SpiFlexioRxPinSelect)),'PIN_'))"!]_U32[!//
 | SPI_FLEXIO_PINCFG_IN_U32 [!//
 | SPI_FLEXIO_SHIFTCLT_SMOD_RX_U32 /* Shifter control for RX */
,(uint32)0u /* Timer compare for CLK */
[!IF "$CS_Continuons = 1"!],(uint32)SPI_FLEXIO_TIMCFG_CS_CONTINUOS_U32 /* Timer config for CLK */
[!ELSE!] ,(uint32)SPI_FLEXIO_TIMCFG_CS_NON_CONTINUOS_U32 /* Timer config for CLK */
[!ENDIF!]
, SPI_FLEXIO_PINSEL[!"(substring-after((node:value(SpiFlexioClkPinSelect)),'PIN_'))"!]_U32[!//
 | SPI_FLEXIO_TIMCTL_TRGSRC_U32 [!//
 | SPI_FLEXIO_TIMCTL_TMOD_8_COUNTER_BAUD_U32 [!//
 | SPI_FLEXIO_TIMCTL_TRGPOL_LOW_U32 [!//
 | SPI_FLEXIO_PINCFG_OUT_U32 /* Timer control for CLK */
,(uint32)0u /* Timer compare for CS */
,(uint32)0u /* Timer config for CS */
, SPI_FLEXIO_PINSEL[!"(substring-after((node:value(SpiFlexioCsPinSelect)),'PIN_'))"!]_U32[!//
 | SPI_FLEXIO_TIMCTL_TMOD_16_COUNTER_U32 [!//
 | SPI_FLEXIO_TIMCTL_PINPOL_LOW_U32 [!//
 | SPI_FLEXIO_PINCFG_OUT_U32 /* Timer control for CS */
[!ENDSELECT!][!//
[!ENDMACRO!]
[!//
[!//===================================================================================================
[!MACRO "GenerateSlaveDeviceInfo_LPSPI"!]
    [!IF "$DualClockSupport = 'true'"!][!//
          {
          /* Normal Mode */
    [!ENDIF!][!//
        (uint32)(([!IF "SpiShiftClockIdleLevel = 'LOW'"!]LPSPI_TCR_CPOL_LOW_U32[!//
    [!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]LPSPI_TCR_CPOL_HIGH_U32[!//
    [!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
    [!ENDIF!] | /* Clock Polarity (Idle State) */
                    [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    LPSPI_TCR_CPHA_LEADING_U32[!//
    [!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    LPSPI_TCR_CPHA_TRAILING_U32[!//
    [!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
    [!ENDIF!] | (uint32)0u | [!IF "SpiByteSwap = 'TRUE'"!] LPSPI_TCR_BYSW_EN_U32 [!ELSE!] LPSPI_TCR_BYSW_DIS_U32 [!ENDIF!] ) & LPSPI_TCR_RESERVED_MASK_U32),
    [!IF "$DualClockSupport = 'true'"!][!//
    [!IF "$DualClockEnabled = 'true'"!][!//
        /* Alternate Mode */
                (uint32)(([!IF "SpiShiftClockIdleLevel = 'LOW'"!]LPSPI_TCR_CPOL_LOW_U32[!//
        [!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]LPSPI_TCR_CPOL_HIGH_U32[!//
        [!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
        [!ENDIF!] | /* Clock Polarity (Idle State) */
                        [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    LPSPI_TCR_CPHA_LEADING_U32[!//
        [!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    LPSPI_TCR_CPHA_TRAILING_U32[!//
        [!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
        [!ENDIF!] | (uint32)0u | [!IF "SpiByteSwap = 'TRUE'"!] LPSPI_TCR_BYSW_EN_U32 [!ELSE!] LPSPI_TCR_BYSW_DIS_U32 [!ENDIF!]
    [!ELSE!]
         /*SpiHwUnit is not enable Alternate Mode, Set TCR is the same configuration as Normal Mode to use*/
         /* Normal Mode */
        (uint32)(([!IF "SpiShiftClockIdleLevel = 'LOW'"!]LPSPI_TCR_CPOL_LOW_U32[!//
        [!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]LPSPI_TCR_CPOL_HIGH_U32[!//
        [!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
        [!ENDIF!] | /* Clock Polarity (Idle State) */
                        [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    LPSPI_TCR_CPHA_LEADING_U32[!//
        [!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    LPSPI_TCR_CPHA_TRAILING_U32[!//
        [!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
        [!ENDIF!] | (uint32)0u | [!IF "SpiByteSwap = 'TRUE'"!] LPSPI_TCR_BYSW_EN_U32 [!ELSE!] LPSPI_TCR_BYSW_DIS_U32 [!ENDIF!]
    [!ENDIF!]
        ) & LPSPI_TCR_RESERVED_MASK_U32)
     },
    [!ENDIF!][!//
     [!IF "$DualClockSupport = 'true'"!][!//
          {
          /* Normal Mode */
    [!ENDIF!][!//
    (uint32)[!WS "8"!]0x00000000u,
    [!IF "$DualClockSupport = 'true'"!][!//
        /* Alternate Mode */
    (uint32)[!WS "8"!]0x00000000u
        },
    [!IF "$DualClockSupport = 'true'"!][!//
    [!AUTOSPACING!][!IF "$DualClockEnabled = 'true'"!][!//
            (uint8)TRUE,
        [!ELSE!][!WS "8"!](uint8)FALSE,
        [!ENDIF!]
    [!ENDIF!]
    [!ENDIF!][!//
    [!IF "SpiCsPolarity = 'HIGH'"!][!//
        [!WS "8"!]    LPSPI_CFGR1_[!"SpiCsIdentifier"!]_IDLELOW_U32[!//
    [!ELSE!][!//
    [!WS "8"!](uint32)0u[!//
    [!ENDIF!][!WS "2"!]/* Chip select polarity */
    | LPSPI_CFGR1_AUTOPCS_MASK_U32 | LPSPI_CFGR1_PINCFG_[!"node:value(SpiPinConfig)"!]_U32 | LPSPI_CFGR1_MATCFG_DIS_U32
    [!ENDMACRO!]
[!//===================================================================================================
[!MACRO "GenerateSlaveDeviceInfo_FLEXIO"!]
  [!IF "SpiShiftClockIdleLevel = 'LOW'"!](uint8)SPI_FLEXIO_CPOL_LOW_U8[!//
  [!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!](uint8)SPI_FLEXIO_CPOL_HIGH_U8[!//
  [!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
  [!ENDIF!], /* Clock Polarity (Idle State) */
  [!IF "SpiDataShiftEdge = 'LEADING'"!](uint8)SPI_FLEXIO_CPHA_LEADING_U8[!//
  [!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!](uint8)SPI_FLEXIO_CPHA_TRAILING_U8[!//
  [!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
  [!ENDIF!], /* Clock Phase */
 [!VAR "CSIB_number"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
[!SELECT "(../../../SpiGeneral/SpiPhyUnit/*[num:i($CSIB_number)])"!][!//
(uint32) 0u /* Not use for Slave mode */
,(uint32) 0u /* Shifter config for TX */
, [!IF "node:value(SpiPhyUnitMapping) = 'FLEXIOSPI_0'"!]SPI_FLEXIO_SHIFTCLT_TIMSEL0_U32[!ELSE!]SPI_FLEXIO_SHIFTCLT_TIMSEL2_U32[!ENDIF!][!//
 | SPI_FLEXIO_PINSEL[!"substring-after((node:value(SpiFlexioTxPinSelect)),'PIN_')"!]_U32[!//
 | SPI_FLEXIO_PINCFG_OUT_U32 [!//
 | SPI_FLEXIO_SHIFTCLT_SMOD_TX_U32 /* Shifter control for TX */
,(uint32) 0u /* Shifter config for RX */
, [!IF "node:value(SpiPhyUnitMapping) = 'FLEXIOSPI_0'"!]SPI_FLEXIO_SHIFTCLT_TIMSEL0_U32[!ELSE!]SPI_FLEXIO_SHIFTCLT_TIMSEL2_U32[!ENDIF!][!//
 | SPI_FLEXIO_PINSEL[!"substring-after((node:value(SpiFlexioRxPinSelect)),'PIN_')"!]_U32[!//
 | SPI_FLEXIO_PINCFG_IN_U32 [!//
 | SPI_FLEXIO_SHIFTCLT_SMOD_RX_U32 /* Shifter control for RX */
,(uint32) 0u /* Timer compare for CLKAndCS */
,(uint32) 0u /* Timer config for CLKAndCS */
, SPI_FLEXIO_PINSEL[!"substring-after((node:value(SpiFlexioClkPinSelectSlave)),'PIN_')"!]_U32[!//
 | ((uint32)[!"num:inttohex((substring-after((node:value(SpiFlexioCsPinSelectSlave)),'PIN_'))*2)"!]u << 24)[!//
 | SPI_FLEXIO_TIMCTL_TRGSRC_U32 [!//
 | SPI_FLEXIO_TIMCTL_TMOD_16_COUNTER_U32 [!//
 | SPI_FLEXIO_PINCFG_IN_U32 /* Timer control for CLKAndCS */
,(uint32) 0u /* Not use for Slave mode */ 
,(uint32) 0u /* Not use for Slave mode */ 
,(uint32) 0u /* Not use for Slave mode */ 
[!ENDSELECT!][!//
[!ENDMACRO!]
[!//===================================================================================================
[!//
[!//=================Check repeat of Job, Seq, External device==========================================
[!MACRO "Spi_CheckRepeatOfJobSeqExternalDevice"!]
[!NOCODE!][!//
[!//Check repeat of SpiJobs
[!VAR "OuterLoopCounter" = "0"!][!//
[!VAR "InnerLoopCounter" = "0"!][!//
[!LOOP "SpiDriver/SpiJob/*"!][!//
[!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!VAR "Matchcounter" = "0"!]
    [!VAR "Name" = "node:name(.)"!]
    [!LOOP "../*"!]
    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
      [!IF "($Name = node:name(.))"!]
          [!VAR "Matchcounter" = "$Matchcounter + 1"!]
       [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$Matchcounter = 1"!]
    [!ELSE!][!//
        [!ERROR!]SpiJob Symbolic name "[!"@name"!]" for the two or more SpiJobs is repeated.[!ENDERROR!]
    [!ENDIF!][!//
[!ENDLOOP!][!//

[!//Check repeat of SpiSequences
[!VAR "OuterLoopCounter" = "0"!][!//
[!VAR "InnerLoopCounter" = "0"!][!//
[!LOOP "SpiDriver/SpiSequence/*"!][!//
[!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!VAR "Matchcounter" = "0"!]
    [!VAR "Name" = "node:name(.)"!]
    [!LOOP "../*"!]
    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
      [!IF "($Name = node:name(.))"!]
          [!VAR "Matchcounter" = "$Matchcounter + 1"!]
       [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$Matchcounter = 1"!]
    [!ELSE!][!//
        [!ERROR!]SpiSequences Symbolic name "[!"@name"!]" for the two or more SpiSequences is repeated.[!ENDERROR!]
    [!ENDIF!][!//
[!ENDLOOP!][!//

[!//Check repeat of SpiExternalDevices
[!VAR "OuterLoopCounter" = "0"!][!//
[!VAR "InnerLoopCounter" = "0"!][!//
[!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
[!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!VAR "Matchcounter" = "0"!]
    [!VAR "Name" = "node:name(.)"!]
    [!LOOP "../*"!]
    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
      [!IF "($Name = node:name(.))"!]
          [!VAR "Matchcounter" = "$Matchcounter + 1"!]
       [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$Matchcounter = 1"!]
    [!ELSE!][!//
        [!ERROR!]SpiExternalDevice Symbolic name "[!"@name"!]" for the two or more SpiExternalDevices is repeated.[!ENDERROR!]
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!]
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//
[!//=========Check repeat of SpiPhyTxDmaChannel, SpiPhyTxDmaChannelAux, SpiPhyRxDmaChannel============
[!MACRO "Spi_CheckRepeatOfDmaChannels"!]
[!NOCODE!][!//
[!IF "ecu:get('SpiDMAPresent') = 'TRUE'"!]
    [!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
        [!VAR "Unit_Name"="@name"!]
        [!IF "(SpiPhyUnitAsyncMethod = 'DMA')"!]
            [!VAR "Spi_PhyTxDmaChannel1"="SpiPhyTxDmaChannel"!]
            [!VAR "Spi_PhyRxDmaChannel"="SpiPhyRxDmaChannel"!]

            [!IF "($Spi_PhyTxDmaChannel1 = $Spi_PhyRxDmaChannel)"!]
                [!ERROR!]
                        SpiPhyTxDmaChannel ([!"$Spi_PhyTxDmaChannel1"!]) and SpiPhyRxDmaChannel ([!"$Spi_PhyRxDmaChannel"!]) values in [!"@name"!] are repeated. Please select different values for SpiPhyTxDmaChannel and SpiPhyRxDmaChannel.
                [!ENDERROR!]
            [!ENDIF!]

            [!LOOP "../../SpiPhyUnit/*"!]
                [!IF "(SpiPhyUnitAsyncMethod = 'DMA')"!]
                    [!IF "($Spi_PhyTxDmaChannel1 = SpiPhyRxDmaChannel)"!]
                        [!ERROR!]
                            SpiPhyTxDmaChannel ([!"$Spi_PhyTxDmaChannel1"!]) in [!"$Unit_Name"!] container and SpiPhyRxDmaChannel ([!"SpiPhyRxDmaChannel"!]) in [!"@name"!] are repeated. Please select different values for SpiPhyTxDmaChannel and SpiPhyRxDmaChannel.
                        [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!][!//
        [!ENDIF!]
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//============Check the number of sequences, Jobs, Channels =======================================
[!MACRO "Spi_CheckNumberOfSequenceJobChannel"!]
[!NOCODE!][!//
[!// Calculate the maximum number of elements (sequences, jobs, channels) in configuration.
[!VAR "SpiMaxSequencesCount" = "0"!][!//
[!VAR "SpiMaxJobsCount" = "0"!][!//
[!VAR "SpiMaxChannelsCount" = "0"!][!//
[!VAR "SpiMaxOneJobSequences" = "0"!][!//
[!VAR "SpiMaxOneJobSeqChannels" = "0"!][!//
[!VAR "SpiMaxSequencesAllowed" = "256"!][!//
[!VAR "SpiMaxJobsAllowed" = "65536"!][!//
[!VAR "SpiMaxChannelsAllowed" = "256"!][!//

[!VAR "TmpCounter" = "num:i(count(SpiDriver/SpiSequence/*))"!]
[!IF "$SpiMaxSequencesCount < $TmpCounter"!]
    [!VAR "SpiMaxSequencesCount" = "$TmpCounter"!]
[!ENDIF!]
[!VAR "TmpCounter" = "num:i(count(SpiDriver/SpiJob/*))"!]
[!IF "$SpiMaxJobsCount < $TmpCounter"!]
    [!VAR "SpiMaxJobsCount" = "$TmpCounter"!]
[!ENDIF!]
[!VAR "TmpCounter" = "num:i(count(SpiDriver/SpiChannel/*))"!]
[!IF "$SpiMaxChannelsCount < $TmpCounter"!]
    [!VAR "SpiMaxChannelsCount" = "$TmpCounter"!]
[!ENDIF!]
[!VAR "TmpCounter" = "num:i(count(SpiDriver/SpiSequence/*[count(SpiJobAssignment/*) = 1]))"!]
[!IF "$SpiMaxOneJobSequences < $TmpCounter"!]
    [!VAR "SpiMaxOneJobSequences" = "$TmpCounter"!]
[!ENDIF!]
[!VAR "TmpCounter" = "num:i(count(node:refs(SpiDriver/SpiSequence/*[count(SpiJobAssignment/*) = 1]/SpiJobAssignment/*)/SpiChannelList/*/SpiChannelAssignment))"!]
[!IF "$SpiMaxOneJobSeqChannels < $TmpCounter"!]
    [!VAR "SpiMaxOneJobSeqChannels" = "$TmpCounter"!]
[!ENDIF!]
    
[!IF "(node:value(SpiNonAUTOSAR/SpiAllowBigSizeCollections) = 'false')"!]
    [!IF "$SpiMaxSequencesCount > $SpiMaxSequencesAllowed"!]
        [!ERROR!]
            The number of sequences defined exceeds the maximum number allowed ([!"num:i($SpiMaxSequencesAllowed)"!]).
        [!ENDERROR!]
    [!ENDIF!]
    [!IF "$SpiMaxChannelsCount > $SpiMaxChannelsAllowed"!]
        [!ERROR!]
            The number of channels defined exceeds the maximum number allowed ([!"num:i($SpiMaxChannelsAllowed)"!]).
        [!ENDERROR!]
    [!ENDIF!]
    [!IF "$SpiMaxJobsCount > $SpiMaxJobsAllowed"!]
        [!ERROR!]
            The number of jobs defined exceeds the maximum number allowed ([!"num:i($SpiMaxJobsAllowed)"!]).
        [!ENDERROR!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//================= List Of Notification Functions =================================================
[!MACRO "Spi_ListOfNotificationFunctions"!]
[!NOCODE!][!//
/* Job start Notifications */
[!LOOP "SpiDriver/SpiJob/*"!][!//
[!VAR "WhiteSpaceInstartJobNotification"="normalize-space(SpiJobStartNotification)"!]
[!IF "(string-length($WhiteSpaceInstartJobNotification)>0) and (SpiJobStartNotification!='NULL_PTR') and (SpiJobStartNotification!='NULL')"!][!//
[!CODE!][!//
/*
* @violates @ref Spi_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void [!"SpiJobStartNotification"!](void); /* start job Notification for Job '[!"name(.)"!]' */
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//

/* Job End Notifications */
[!LOOP "SpiDriver/SpiJob/*"!][!//
[!VAR "WhiteSpaceInJobEndNotification"="normalize-space(SpiJobEndNotification)"!]
[!IF "(string-length($WhiteSpaceInJobEndNotification)>0) and (SpiJobEndNotification!='NULL_PTR') and (SpiJobEndNotification!='NULL')"!][!//
[!CODE!][!//
/*
* @violates @ref Spi_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void [!"SpiJobEndNotification"!](void); /* End Notification for Job '[!"name(.)"!]' */
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
/* Sequence End Notifications */
[!NOCODE!]
[!LOOP "SpiDriver/SpiSequence/*"!][!//
[!VAR "WhiteSpaceInSeqEndNotification"="normalize-space(SpiSeqEndNotification)"!]
[!IF "(string-length($WhiteSpaceInSeqEndNotification)>0)  and (SpiSeqEndNotification!='NULL_PTR') and (SpiSeqEndNotification!='NULL')"!][!//
[!CODE!][!//
/*
* @violates @ref Spi_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void [!"SpiSeqEndNotification"!](void); /* End Notification for Sequence '[!"name(.)"!]' */
[!ENDCODE!][!//
[!ENDIF!]
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//==================================================================================================
[!MACRO "Spi_CheckChannelAttributes"!]
[!NOCODE!][!//
[!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!][!//
    [!VAR "InnerLoopCounter" = "0"!][!//
    [!VAR "Matchcounter" = "0"!][!//
    [!VAR "TempChannel_FirstSpiChannelId" = "0"!][!//
    [!VAR "TempChannel_FirstSpiChannelType" = "SpiChannelType"!][!//
    [!VAR "TempChannel_FirstSpiDataWidth" = "SpiDataWidth"!][!//
    [!VAR "TempChannel_FirstSpiEbMaxLength" = "SpiEbMaxLength"!][!//
    [!VAR "TempChannel_FirstSpiIbNBuffers" = "SpiChannelType"!][!//
    [!VAR "TempChannel_FirstSpiTransferStart" = "SpiTransferStart"!][!//
    [!VAR "Name" = "node:name(.)"!][!//
    [!LOOP "../*"!][!//
    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!][!//
    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!][!//
      [!IF "($Name = node:name(.))"!][!//
         [!VAR "Matchcounter" = "$Matchcounter + 1"!][!//
         [!IF "$Matchcounter = 1"!][!//
         [!VAR "TempChannel_FirstSpiChannelId" = "SpiChannelId"!][!//
         [!VAR "TempChannel_FirstSpiChannelType" = "SpiChannelType"!][!//
         [!VAR "TempChannel_FirstSpiDataWidth" = "SpiDataWidth"!][!//
         [!VAR "TempChannel_FirstSpiEbMaxLength" = "SpiEbMaxLength"!][!//
         [!VAR "TempChannel_FirstSpiIbNBuffers" = "SpiIbNBuffers"!][!//
         [!VAR "TempChannel_FirstSpiTransferStart" = "SpiTransferStart"!][!//
         [!ENDIF!][!//
         [!IF "($Matchcounter > 1) and (SpiChannelType = 'IB')"!][!//
         [!IF "($TempChannel_FirstSpiChannelId != SpiChannelId) or ($TempChannel_FirstSpiChannelType != SpiChannelType) or
         ($TempChannel_FirstSpiDataWidth != SpiDataWidth) or ($TempChannel_FirstSpiIbNBuffers != SpiIbNBuffers) or($TempChannel_FirstSpiTransferStart != SpiTransferStart) "!][!//
         [!ERROR!]If the same symbolic channel name [!"node:name(.)"!] is used for more than one channel, all channel attributes shall be identical.[!ENDERROR!]
         [!ENDIF!][!//
         [!ENDIF!][!//
         [!IF "($Matchcounter > 1) and (SpiChannelType = 'EB')"!][!//
         [!IF "($TempChannel_FirstSpiChannelId != SpiChannelId) or ($TempChannel_FirstSpiChannelType != SpiChannelType) or
         ($TempChannel_FirstSpiDataWidth != SpiDataWidth) or ($TempChannel_FirstSpiEbMaxLength != SpiEbMaxLength) or ($TempChannel_FirstSpiTransferStart != SpiTransferStart) "!][!//
         [!ERROR!]If the same symbolic channel name [!"node:name(.)"!] is used for more than one channel, all channel attributes shall be identical.[!ENDERROR!]
         [!ENDIF!][!//
         [!ENDIF!][!//
      [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//===================Buffers Descriptors for EB Channels and Allocate Buffers for IB Channels=======
[!MACRO "Spi_BuffersDescriptorForEBchannel"!]
/*  Buffers Descriptors for EB Channels (if any) */
[!NOCODE!][!//
[!VAR "OuterLoopCounter" = "0"!][!//
[!VAR "InnerLoopCounter" = "0"!][!//
[!LOOP "SpiDriver/SpiChannel/*"!][!//
[!CALL "Spi_CheckChannelAttributes"!][!//
[!IF "$Matchcounter = 1"!]
[!CODE!][!//
[!IF "SpiChannelType = 'EB'"!][!//
[!IF "num:i(SpiDataWidth) > 8"!][!//
VAR_ALIGN(static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PB[!"name(.)"!], 4)
[!ELSE!][!//
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PB[!"name(.)"!];
[!ENDIF!][!//
[!ELSEIF "SpiChannelType = 'IB'"!][!//
/* Allocate Buffers for IB Channels (if any) */
[!IF "num:i(SpiDataWidth) > 8"!][!//
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PB[!"name(.)"!][[!"SpiIbNBuffers"!]], 4)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PB[!"name(.)"!][[!"SpiIbNBuffers"!]], 4)
[!ELSE!][!//
static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PB[!"name(.)"!][[!"SpiIbNBuffers"!]];
static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PB[!"name(.)"!][[!"SpiIbNBuffers"!]];
[!ENDIF!][!//
[!ELSE!][!//
[!ENDIF!][!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//=================Buffers Descriptors for IB Channels==============================================
[!MACRO "Spi_BuffersDescriptorForIBchannel"!]
/*  Buffers Descriptors for IB Channels (if any) */
[!NOCODE!][!//
[!VAR "OuterLoopCounter" = "0"!][!//
[!VAR "InnerLoopCounter" = "0"!][!//
[!LOOP "SpiDriver/SpiChannel/*"!][!//
[!CALL "Spi_CheckChannelAttributes"!][!//
[!IF "$Matchcounter = 1"!]
[!IF "SpiChannelType = 'IB'"!][!//
[!CODE!][!//
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PB[!"name(.)"!] =
{
    BufferTX_PB[!"name(.)"!],
    BufferRX_PB[!"name(.)"!]
};
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//==================================================================================================
[!// POSTBUILD FLASH from here onward! */
[!//=================Channel Configuration============================================================
[!MACRO "Spi_ChannelConfiguration"!]
[!VAR "idx" = "1"!][!//
[!VAR "LoopVar"="0"!][!//
[!VAR "count" = "count(SpiDriver/SpiChannel/*)"!][!//
/* SpiChannelConfig_PB[!"@index"!] Channel Configuration of [!"name(.)"!]*/
static CONST(Spi_ChannelConfigType, SPI_CONST) SpiChannelConfig_PB[!"@index"!][[!"num:i($count)"!]] =
{
[!FOR "x" = "0" TO "num:i(count(SpiDriver/SpiChannel/*))"!][!//
[!LOOP "SpiDriver/SpiChannel/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "SpiChannelId = $Loop"!][!//
    {
        /* [!"name(.)"!]*/
        [!"SpiChannelType"!],
[!IF "node:exists(SpiDefaultData)"!][!//
        (uint32)[!"SpiDefaultData"!]U,
[!ELSE!][!//
        (uint32)0x55u,
[!ENDIF!][!//    
[!IF "SpiChannelType = 'IB'"!][!//
        [!"SpiIbNBuffers"!]U,
[!ENDIF!][!//
[!IF "SpiChannelType = 'EB'"!][!//
        [!"SpiEbMaxLength"!]U,
[!ENDIF!][!//
        &Buffer_PB[!"name(.)"!],
        &Spi_aSpiChannelState[[!"SpiChannelId"!]]
    }[!IF "$idx!=$count"!],[!ENDIF!]
[!VAR "idx" = "$idx + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!CR!][!ENDFOR!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//==================Channel Assignment of Jobs =====================================================
[!MACRO "Spi_ChannelAssignmentOfJobs"!]
/* Channel to Job Assignment */
[!/* Retrieves all Channel assignments */!]
[!LOOP "SpiDriver/SpiJob/*"!][!//
static CONST(Spi_ChannelType, SPI_CONST) [!"name(.)"!]_ChannelAssignment_PB[[!"num:i(count(SpiChannelList/*))"!]] = {[!//
[!LOOP "SpiChannelList/*"!][!//
[!IF "@index > 0"!],[!ENDIF!][!//
SpiConf_SpiChannel_[!"name(node:ref(SpiChannelAssignment))"!][!//
[!ENDLOOP!]};
[!ENDLOOP!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//========Configuration of Jobs=====================================================================
[!MACRO "Spi_JobConfiguration"!]
[!VAR "spiPath" = "node:path(.)"!][!//
[!VAR "idx" = "1"!][!//
[!VAR "LoopVar"="0"!][!//
[!VAR "count" = "count(SpiDriver/SpiJob/*)"!][!//
[!CODE!][!//
/* SpiJobConfig_PB[!"@index"!] Job Configuration of [!"name(.)"!]*/
static CONST(Spi_JobConfigType, SPI_CONST) SpiJobConfig_PB[!"@index"!][[!"num:i($count)"!]] =
{
[!ENDCODE!][!//
[!FOR "x" = "0" TO "num:i(count(SpiDriver/SpiJob/*))"!][!//
[!LOOP "SpiDriver/SpiJob/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "SpiJobId = $Loop"!][!//
[!CODE!][!//
    {
[!ENDCODE!][!//
[!VAR "WhiteSpaceInJobEndNotification1"="normalize-space(SpiJobEndNotification)"!]
[!VAR "WhiteSpaceInstartJobNotification1"="normalize-space(SpiJobStartNotification)"!]
[!CODE!][!//
        /* [!"name(.)"!] */
        (Spi_ChannelType)[!"num:i(count(SpiChannelList/*))"!]u,
        [!"name(.)"!]_ChannelAssignment_PB, /* List of Channels */
[!IF "(string-length($WhiteSpaceInJobEndNotification1)>0) and (SpiJobEndNotification!='NULL_PTR') and (SpiJobEndNotification!='NULL')"!][!//
        &[!"SpiJobEndNotification"!][!//
[!ELSE!][!//
        NULL_PTR[!//
[!ENDIF!], /* End Notification */
[!IF "(string-length($WhiteSpaceInstartJobNotification1)>0) and (SpiJobStartNotification!='NULL_PTR') and (SpiJobStartNotification!='NULL')"!][!//
        &[!"SpiJobStartNotification"!][!//
[!ELSE!][!//
        NULL_PTR[!//
[!ENDIF!], /* Start Notification */
        (sint8)[!"SpiJobPriority"!], /* Priority */
        &Spi_aSpiJobState[[!"SpiJobId"!]], /* JobState instance */
        [!"node:value(node:ref(SpiDeviceAssignment)/SpiHwUnit)"!], /* HWUnit index */
[!VAR "varSpiHwUnit"="string(substring-after(node:value(node:ref(SpiDeviceAssignment)/SpiHwUnit),'CSIB')+1)"!][!//
        [!"node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$varSpiHwUnit,']/SpiPhyUnitMapping'))"!]_OFFSET, /* LPspi device HW unit offset */
        /* External Device Settings */
[!ENDCODE!][!//
        [!SELECT "node:ref(SpiDeviceAssignment)"!]
        [!WS "4"!]SPI_[!"name(.)"!], /* External Device */
        &SpiExternalDeviceAttrsPB0[SPI_[!"name(.)"!]]
        
        [!ENDSELECT!]
    }[!IF "$idx!=$count"!],[!ENDIF!]
[!VAR "idx" = "$idx + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!CR!][!ENDFOR!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//============Job Assignment of Sequences ==========================================================
[!MACRO "Spi_JobAssignmentOfSequences"!]
/* Job to Sequence Assignment */
[!LOOP "SpiDriver/SpiSequence/*"!][!//
static CONST(Spi_JobType, SPI_CONST) [!"name(.)"!]_JobAssignment_PB[[!"num:i(count(SpiJobAssignment/*))"!]] = {[!//
[!LOOP "SpiJobAssignment/*"!][!//
[!/* Check if reference node has the name "Job". We need to avoid the name "Job" */!][!//
[!/* driver shall run into problems if a name "Job" is founded */!][!//
[!IF "name(node:ref(.)) = 'Job'"!][!//
Job_default[!//
[!ELSE!][!//
[!IF "@index > 0"!],[!ENDIF!][!//
SpiConf_SpiJob_[!"name(node:ref(.))"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
};
[!ENDLOOP!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//==============Configuration of Sequences =========================================================
[!MACRO "Spi_SequenceConfiguration"!]
[!VAR "spiPath" = "node:path(.)"!][!//
[!VAR "idx" = "1"!][!//
[!VAR "LoopVar"="0"!][!//
[!VAR "count" = "count(SpiDriver/SpiSequence/*)"!][!//
/* SpiSequenceConfig_PB[!"@index"!] Sequence Configuration of [!"name(.)"!]*/
static CONST(Spi_SequenceConfigType, SPI_CONST) SpiSequenceConfig_PB[!"@index"!][[!"num:i($count)"!]] =
{
[!FOR "x" = "0" TO "num:i(count(SpiDriver/SpiSequence/*))"!][!//
[!LOOP "SpiDriver/SpiSequence/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "SpiSequenceId = $Loop"!][!//
    {  /* [!"name(.)"!] */
[!SELECT "SpiJobAssignment/*[1]"!][!//
[!SELECT "node:ref(node:current())"!][!//
[!SELECT "node:ref(SpiDeviceAssignment)"!][!//
[!VAR "CSIB_number"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
        [!"substring-before(node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number,']/SpiPhyUnitMapping')),'_')"!], /* HW type of sequences */ [!//
[!ENDSELECT!][!//
[!ENDSELECT!][!//
[!ENDSELECT!][!//
[!VAR "WhiteSpaceInSeqEndNotification1"="normalize-space(SpiSeqEndNotification)"!]
        (Spi_JobType)[!"num:i(count(SpiJobAssignment/*))"!]u,
        [!"name(.)"!]_JobAssignment_PB, /* List of Jobs */
[!IF "(string-length($WhiteSpaceInSeqEndNotification1)>0) and (SpiSeqEndNotification!='NULL_PTR') and (SpiSeqEndNotification!='NULL')"!][!//
        &[!"SpiSeqEndNotification"!][!//
[!ELSE!][!//
        NULL_PTR[!//
[!ENDIF!], /* End Notification */
        [!WS "8"!][!IF "SpiInterruptibleSequence"!](uint8)TRUE[!ELSE!](uint8)FALSE[!ENDIF!] /* Interruptible */
    }[!IF "$idx!=$count"!],[!ENDIF!]
[!VAR "idx" = "$idx + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!CR!][!ENDFOR!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!MACRO "Spi_CheckTypeOfIPV"!]
[!VAR "spiPath" = "node:path(.)"!][!//
[!VAR "Exist_LPSPI" = "0"!]
[!VAR "Exist_FLEXIO" = "0"!]
[!LOOP "SpiDriver/SpiExternalDevice/*"!]
    [!VAR "CSIB_number"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!]
    [!IF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number,']/SpiPhyUnitMapping'))),'_')),'LPSPI')"!]
        [!VAR "Exist_LPSPI" = "1"!]
    [!ELSEIF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number,']/SpiPhyUnitMapping'))),'_')),'FLEXIOSPI')"!]
        [!VAR "Exist_FLEXIO" = "1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDMACRO!][!//
[!//===================Attribute Configuration of Channels ===========================================
[!MACRO "Spi_AttributeConfigurationOfChannels_LPSPI"!]
[!VAR "idx" = "1"!][!//
[!VAR "LoopVar"="0"!][!//
[!VAR "count" = "count(SpiDriver/SpiChannel/*)"!][!//
/* LPspiChannelAttributesConfig_PB[!"@index"!] Channel Attribute Configuration of [!"name(.)"!]*/
/*
* @violates @ref Spi_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
static CONST(Spi_Ipw_LPspiChannelAttributesConfigType, SPI_CONST) LPspiChannelAttributesConfig_PB[!"@index"!][[!"num:i($count)"!]] =
{
[!FOR "x" = "0" TO "num:i(count(SpiDriver/SpiChannel/*))"!][!//
[!LOOP "SpiDriver/SpiChannel/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "SpiChannelId = $Loop"!][!//
{ 
    /* Channel attribution on TCR register */
    (uint32)(LPSPI_TCR_[!"SpiTransferStart"!]_U32 | LPSPI_TCR_WIDTH_1_U32 | ((uint32)([!"num:i(SpiDataWidth)-1"!]))),
    /* FCR register attribution */
[!IF "num:i(SpiDataWidth) <= 8"!][!//
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_8[!//
    [!ELSEIF "(num:i(SpiDataWidth) > 8) and (num:i(SpiDataWidth) <= 16)"!][!//
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_16[!//
    [!ELSEIF "num:i(SpiDataWidth) > 16"!][!//
    (uint32)(((uint32)(0) << 16) | ((uint32)(0))),SPI_DATA_WIDTH_32[!//
[!ENDIF!][!//
}
[!IF "$idx!=$count"!],[!ENDIF!]
[!VAR "idx" = "$idx + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!CR!][!ENDFOR!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!MACRO "Spi_AttributeConfigurationOfChannels_FLEXIO"!]
[!VAR "idx" = "1"!][!//
[!VAR "LoopVar"="0"!][!//
[!VAR "count" = "count(SpiDriver/SpiChannel/*)"!][!//
/* FlexIOChannelAttributesConfig_PB[!"@index"!] Channel Attribute Configuration of [!"name(.)"!]*/
/*
* @violates @ref Spi_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
static CONST(Spi_Ipw_FlexIOChannelAttributesConfigType, SPI_CONST) FlexIOChannelAttributesConfig_PB[!"@index"!][[!"num:i($count)"!]] =
{
[!FOR "x" = "0" TO "num:i(count(SpiDriver/SpiChannel/*))"!][!//
[!LOOP "SpiDriver/SpiChannel/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "SpiChannelId = $Loop"!][!//
{ 
    /* Channel attribution on TCR register */
    (uint8)SPI_FLEXIO_[!"SpiTransferStart"!]_U8,
    /* The number of bits data in a frame tranfer */
    [!VAR "SpiDataWidth_value" = "(SpiDataWidth * 2) - 1"!][!//
    (uint32)[!"num:i($SpiDataWidth_value)"!]u, 
    /* Data width */
[!IF "num:i(SpiDataWidth) <= 8"!][!//
    (uint32)SPI_FLEXIO_DATA_WIDTH_8
    [!ELSEIF "(num:i(SpiDataWidth) > 8) and (num:i(SpiDataWidth) <= 16)"!][!//
    (uint32)SPI_FLEXIO_DATA_WIDTH_16
    [!ELSEIF "num:i(SpiDataWidth) > 16"!][!//
    (uint32)SPI_FLEXIO_DATA_WIDTH_32
[!ENDIF!][!//
}
[!IF "$idx!=$count"!],[!ENDIF!]
[!VAR "idx" = "$idx + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!CR!][!ENDFOR!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!MACRO "Spi_AttributeConfigurationOfChannels_Getnumberofarray"!]
[!VAR "spiPath" = "node:path(.)"!][!//
[!VAR "Number_LPspi" = "0"!][!//
[!VAR "Number_FlexIO" = "0"!][!//
    [!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
        [!VAR "CSIB_number1"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
        [!IF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number1,']/SpiPhyUnitMapping'))),'_')),'LPSPI')"!][!//
            [!VAR "Number_LPspi" = "$Number_LPspi + 1"!][!//
        [!ELSEIF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number1,']/SpiPhyUnitMapping'))),'_')),'FLEXIOSPI')"!][!//
            [!VAR "Number_FlexIO" = "$Number_FlexIO + 1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDMACRO!]
[!//==================================================================================================
[!MACRO "Spi_AttributeConfigurationOfChannels"!]
[!CALL "Spi_CheckTypeOfIPV"!]
[!IF "$Exist_LPSPI = 1"!]
[!IF "$Exist_FLEXIO = 0"!]
    [!CALL "Spi_AttributeConfigurationOfChannels_LPSPI"!]
[!ENDIF!]
[!ENDIF!]
[!IF "$Exist_LPSPI = 1"!]
[!IF "$Exist_FLEXIO = 1"!]
    [!CALL "Spi_AttributeConfigurationOfChannels_LPSPI"!]
    [!CALL "Spi_AttributeConfigurationOfChannels_FLEXIO"!]
[!ENDIF!]
[!ENDIF!]
[!IF "$Exist_LPSPI = 0"!]
[!IF "$Exist_FLEXIO = 1"!]
    [!CALL "Spi_AttributeConfigurationOfChannels_FLEXIO"!]
[!ENDIF!]
[!ENDIF!]
[!ENDMACRO!][!//
[!//==================================================================================================
[!//==================Attribute Configuration of External Devices ====================================
[!MACRO "Spi_AttributeConfigurationOfExternalDevices_LPSPI"!]
[!CALL "Spi_AttributeConfigurationOfChannels_Getnumberofarray"!]
[!VAR "var"= "1"!][!VAR "deviceattribute"= "num:i($Number_LPspi)-1"!][!//
[!VAR "spiPath" = "node:path(.)"!][!//
/* LPspiDeviceAttributesConfig_PB[!"@index"!] Device Attribute Configuration of [!"name(.)"!]*/
static VAR(Spi_Ipw_LPspiDeviceAttributesConfigType, SPI_VAR) LPspiDeviceAttributesConfig_PB[!"@index"!][[!"num:i($Number_LPspi)"!]] =
{
[!AUTOSPACING!][!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
        [!VAR "CSIB_number"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
        [!IF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number,']/SpiPhyUnitMapping'))),'_')),'LPSPI')"!]
        {
        [!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
        [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitClockRef)"!][!//
            [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!][!//
        [!ENDSELECT!][!//
        [!VAR "BusClockNormal" = "string($SpiPeriphFrequency div 1000000)"!][!//
        [!IF "(node:exists(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef))"!][!//
            [!VAR "DualClockEnabled" = "'true'"!][!//
            [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef)"!][!//
                [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!][!//
            [!ENDSELECT!][!//
            [!VAR "BusClockAlternate" = "string($SpiPeriphFrequency div 1000000)"!][!//
        [!ELSE!]
            [!VAR "DualClockEnabled" = "'false'"!][!//
        [!ENDIF!][!//
        /* [!"name(.)"!] */
            [!IF "SpiSlaveMode = 'false'"!]
                [!CALL "GenerateExternalDeviceInfo_LPSPI"!]
            [!ELSE!]
                [!CALL "GenerateSlaveDeviceInfo_LPSPI"!]
            [!ENDIF!]
        }
        [!IF "$deviceattribute>=$var"!],[!ENDIF!][!VAR "var"= "$var+1"!][!//
        [!ENDIF!]
[!CR!][!ENDLOOP!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!MACRO "Spi_AttributeConfigurationOfExternalDevices_FLEXIO"!]
[!CALL "Spi_AttributeConfigurationOfChannels_Getnumberofarray"!]
[!VAR "var"= "1"!][!VAR "deviceattribute"= "num:i($Number_FlexIO)-1"!][!//
[!VAR "spiPath" = "node:path(.)"!][!//
/* FlexIODeviceAttributesConfig_PB[!"@index"!] Device Attribute Configuration of [!"name(.)"!]*/
static VAR(Spi_Ipw_FlexIODeviceAttributesConfigType, SPI_VAR) FlexIODeviceAttributesConfig_PB[!"@index"!][[!"num:i($Number_FlexIO)"!]] =
{
[!AUTOSPACING!][!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
        [!VAR "CSIB_number"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
        [!IF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number,']/SpiPhyUnitMapping'))),'_')),'FLEXIOSPI')"!][!//
        {
        /* [!"name(.)"!] */
        [!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
        [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitClockRef)"!][!//
            [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!][!//
        [!ENDSELECT!][!//
        [!VAR "BusClockNormal" = "string($SpiPeriphFrequency div 1000000)"!][!//
        [!IF "(node:exists(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef))"!][!//
            [!VAR "DualClockEnabled" = "'true'"!][!//
            [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef)"!][!//
                [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!][!//
            [!ENDSELECT!][!//
            [!VAR "BusClockAlternate" = "string($SpiPeriphFrequency div 1000000)"!][!//
        [!ELSE!]
            [!VAR "DualClockEnabled" = "'false'"!][!//
        [!ENDIF!][!//
            [!IF "SpiSlaveMode = 'false'"!]
                [!CALL "GenerateExternalDeviceInfo_FLEXIO"!]
            [!ELSE!]
                [!CALL "GenerateSlaveDeviceInfo_FLEXIO"!]
            [!ENDIF!]
        }
        [!IF "$deviceattribute>=$var"!],[!ENDIF!][!VAR "var"= "$var+1"!][!//
        [!ENDIF!]
[!CR!][!ENDLOOP!][!//
};
[!ENDMACRO!][!//
[!//=================================================================================================================================
[!MACRO "Spi_AttributeConfigurationOfExternalDevicesForJobconfig"!]
[!VAR "var"= "1"!][!VAR "deviceattribute"= "num:i(count(SpiDriver/SpiExternalDevice/*)-1)"!][!//
[!VAR "spiPath" = "node:path(.)"!][!//

/* DSpiDeviceAttributesConfig_PB[!"@index"!] Device Attribute Configuration of [!"name(.)"!]*/
static VAR(Spi_Ipw_DeviceAttributesConfigType, SPI_VAR) SpiExternalDeviceAttrsPB[!"@index"!][[!"num:i(count(SpiDriver/SpiExternalDevice/*))"!]] =
{
[!AUTOSPACING!][!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
        [!VAR "CSIB_number"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!]
        [!IF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number,']/SpiPhyUnitMapping'))),'_')),'LPSPI')"!]
        {
        &LPspiDeviceAttributesConfigArray_PB0[SPI_[!"name(.)"!]],
        NULL_PTR
        }[!IF "$deviceattribute>=$var"!],[!ENDIF!][!VAR "var"= "$var+1"!][!//
        [!ELSEIF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number,']/SpiPhyUnitMapping'))),'_')),'FLEXIOSPI')"!]
        {
        NULL_PTR,
        &FlexIODeviceAttributesConfigArray_PB0[SPI_[!"name(.)"!]]
        }[!IF "$deviceattribute>=$var"!],[!ENDIF!][!VAR "var"= "$var+1"!][!//
        [!ENDIF!][!//
[!CR!][!ENDLOOP!][!//
};
[!ENDMACRO!][!//
[!//=================================================================================================================================
[!MACRO "Spi_AttributeConfigurationOfExternalDevices_ALL_IPV_LPspi"!]
[!VAR "var"= "1"!][!VAR "deviceattribute"= "num:i(count(SpiDriver/SpiExternalDevice/*))-1"!][!//
[!VAR "spiPath" = "node:path(.)"!][!//
[!VAR "LPspi_Count" = "0"!][!//

/* DeviceAttributesConfig_PB[!"@index"!] Device Attribute Configuration of [!"name(.)"!]*/
static P2CONST(Spi_Ipw_LPspiDeviceAttributesConfigType, SPI_VAR, SPI_APPL_CONST) LPspiDeviceAttributesConfigArray_PB[!"@index"!][[!"num:i(count(SpiDriver/SpiExternalDevice/*))"!]] =
{
[!AUTOSPACING!][!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
[!VAR "CSIB_number"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
        [!IF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number,']/SpiPhyUnitMapping'))),'_')),'LPSPI')"!][!//
        &LPspiDeviceAttributesConfig_PB0[[!"num:i($LPspi_Count)"!]][!IF "$deviceattribute>=$var"!],[!ENDIF!][!VAR "var"= "$var+1"!][!//
        [!VAR "LPspi_Count" = "$LPspi_Count + 1"!][!//
        [!ELSEIF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number,']/SpiPhyUnitMapping'))),'_')),'FLEXIOSPI')"!][!//
        NULL_PTR[!IF "$deviceattribute>=$var"!],[!ENDIF!][!VAR "var"= "$var+1"!][!//
        [!ENDIF!][!//
[!CR!][!ENDLOOP!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!MACRO "Spi_AttributeConfigurationOfExternalDevices_ALL_IPV_FLEXIO"!]
[!VAR "var"= "1"!][!VAR "deviceattribute"= "num:i(count(SpiDriver/SpiExternalDevice/*))-1"!][!//
[!VAR "spiPath" = "node:path(.)"!][!//
[!VAR "FlexIO_Count" = "0"!][!//

/* DeviceAttributesConfig_PB[!"@index"!] Device Attribute Configuration of [!"name(.)"!]*/
static P2CONST(Spi_Ipw_FlexIODeviceAttributesConfigType, SPI_VAR, SPI_APPL_CONST) FlexIODeviceAttributesConfigArray_PB[!"@index"!][[!"num:i(count(SpiDriver/SpiExternalDevice/*))"!]] =
{
[!AUTOSPACING!][!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
[!VAR "CSIB_number"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
        [!IF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number,']/SpiPhyUnitMapping'))),'_')),'LPSPI')"!][!//
        NULL_PTR[!IF "$deviceattribute>=$var"!],[!ENDIF!][!VAR "var"= "$var+1"!][!//
        [!ELSEIF "contains((substring-before((node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$CSIB_number,']/SpiPhyUnitMapping'))),'_')),'FLEXIOSPI')"!][!//
        &FlexIODeviceAttributesConfig_PB0[[!"num:i($FlexIO_Count)"!]][!IF "$deviceattribute>=$var"!],[!ENDIF!][!VAR "var"= "$var+1"!][!//
        [!VAR "FlexIO_Count" = "$FlexIO_Count + 1"!][!//
        [!ENDIF!][!//
[!CR!][!ENDLOOP!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!MACRO "Spi_AttributeConfigurationOfExternalDevices_ALL_IPV"!]
    [!CALL "Spi_AttributeConfigurationOfExternalDevices_ALL_IPV_LPspi"!]
    [!CALL "Spi_AttributeConfigurationOfExternalDevices_ALL_IPV_FLEXIO"!]
[!ENDMACRO!][!//
[!//==================================================================================================
[!MACRO "Spi_AttributeConfigurationOfExternalDevices"!]
    [!CALL "Spi_CheckTypeOfIPV"!]
    [!IF "$Exist_LPSPI = 1"!]
        [!CALL "Spi_AttributeConfigurationOfExternalDevices_LPSPI"!]
        [!ENDIF!]
    [!IF "$Exist_FLEXIO = 1"!]
        [!CALL "Spi_AttributeConfigurationOfExternalDevices_FLEXIO"!]
    [!ENDIF!]
[!ENDMACRO!][!//
[!//=================Link to Attribute Configuration of Channels and Devices =========================
[!MACRO "Spi_LinkToAttributeConfiguration"!]
[!CALL "Spi_CheckTypeOfIPV"!]
/* SpiAttributesConfig_PB[!"@index"!] Attribute Configuration of [!"@name"!] */
static CONST(Spi_AttributesConfigType, SPI_CONST) SpiAttributesConfig_PB[!"@index"!] = {
[!IF "$Exist_LPSPI = 1"!][!//
    LPspiChannelAttributesConfig_PB[!"@index"!],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!IF "$Exist_FLEXIO = 1"!][!//    
    FlexIOChannelAttributesConfig_PB[!"@index"!],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
    LPspiDeviceAttributesConfigArray_PB[!"@index"!],
    FlexIODeviceAttributesConfigArray_PB[!"@index"!]
};
[!ENDMACRO!][!//

[!//=================================================================================================
[!//
[!//=============Array of LPspi Unit configurations===================================================
[!MACRO "Spi_HWUnitConfiguration"!]
/* Array of LPspi Unit configurations */
static CONST(Spi_HWUnitConfigType, SPI_CONST) HWUnitConfig_PB[SPI_MAX_HWUNIT] =
{
[!VAR "var"= "1"!][!VAR "numdevices"= "num:i(count(SpiGeneral/SpiPhyUnit/*))-1"!][!//
[!AUTOSPACING!][!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
[!VAR "unit"="./SpiPhyUnitMapping"!]
[!VAR "unit_index"="substring-after($unit,'_')"!]
[!VAR "HWUnit_type"="substring-before($unit,'_')"!]
[!VAR "unit_NrCTAR"="0"!]
    { [!"SpiPhyUnitMapping"!]_OFFSET[!//
,  [!"$HWUnit_type"!][!//
, (uint8)0u[!//
[!IF "SpiPhyUnitMode = 'SPI_SLAVE'"!][!//
, SPI_SLAVE [!//
[!ELSE!][!//
, SPI_MASTER [!//
[!ENDIF!][!//
[!IF "SpiPhyUnitSync = 'true'"!][!//
, SPI_PHYUNIT_SYNC_U32[!//
[!IF "ecu:get('SpiDMAPresent') = 'TRUE' and ../../SpiGlobalDmaEnable = 'true' and ../../SpiLevelDelivered >0"!][!//
, (uint16)FALSE
, 0u
, 0u
, 0u
[!ENDIF!][!//
[!ELSE!][!//
, SPI_PHYUNIT_ASYNC_U32[!//
[!IF "ecu:get('SpiDMAPresent') = 'TRUE' and ../../SpiGlobalDmaEnable = 'true' and ../../SpiLevelDelivered >0"!][!//
[!IF "SpiPhyUnitAsyncMethod = 'DMA'"!][!//
, (uint16)TRUE
, [!"node:value(node:ref(SpiPhyTxDmaChannel)/MclDMAChannelId)"!]u
, 0u
, [!"node:value(node:ref(SpiPhyRxDmaChannel)/MclDMAChannelId)"!]u
[!ELSE!][!//
, (uint16)FALSE
, 0u
, 0u
, 0u
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "ecu:get('SpiFlexIOSupport') = 'TRUE'"!][!//
[!IF "(contains((substring-before((node:value(SpiPhyUnitMapping)),'_')),'FLEXIOSPI'))"!][!//
[!IF "node:value(SpiPhyUnitMapping) = 'FLEXIOSPI_0'"!][!//
, Spi_FlexIO_Physical_Shifter_0[!//
, Spi_FlexIO_Physical_Shifter_1[!//
[!ELSEIF "node:value(SpiPhyUnitMapping) = 'FLEXIOSPI_1'"!][!//
, Spi_FlexIO_Physical_Shifter_2[!//
, Spi_FlexIO_Physical_Shifter_3[!//
[!ENDIF!][!//
[!IF "SpiPhyUnitMode = 'SPI_MASTER'"!][!//
[!IF "node:value(SpiPhyUnitMapping) = 'FLEXIOSPI_0'"!][!//
, Spi_FlexIO_Timer_0[!//
, Spi_FlexIO_Timer_1[!//
[!ELSEIF "node:value(SpiPhyUnitMapping) = 'FLEXIOSPI_1'"!][!//
, Spi_FlexIO_Timer_2[!//
, Spi_FlexIO_Timer_3[!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "node:value(SpiPhyUnitMapping) = 'FLEXIOSPI_0'"!][!//
, Spi_FlexIO_Timer_0[!//
, Spi_FlexIO_Timer_0[!//
[!ELSEIF "node:value(SpiPhyUnitMapping) = 'FLEXIOSPI_1'"!][!//
, Spi_FlexIO_Timer_2[!//
, Spi_FlexIO_Timer_2[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ELSE!][!//
, 0u[!//
, 0u[!//
, 0u[!//
, 0u[!//
[!ENDIF!][!//
[!ENDIF!][!//
 }[!IF "$numdevices>=$var"!],[!ENDIF!][!VAR "var"= "$var+1"!][!//
[!CR!][!ENDLOOP!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//==================Spi Configuration===============================================================
[!MACRO "Spi_ConfigurationInfo"!]
[!NOCODE!]
[!VAR "SpiDemErrorEnable" = "'false'"!]
[!IF "SpiNonAUTOSAR/SpiDisableDemReportErrorStatus ='false'"!][!//
    [!IF "node:exists(SpiDemEventParameterRefs)"!]
        [!VAR "SpiDemErrorEnable" = "'true'"!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]

/* @violates @ref Spi[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_4 MISRA 2004 Required Rule 8.10, external linkage ... */
/* [!"@name"!] Configuration */
CONST(Spi_ConfigType, SPI_CONST) [!//
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime') and (variant:size() <= 1)"!]Spi_PBCfgVariantPredefined[!//
[!ELSE!][!"as:name(SpiDriver)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!] =
{
    [!"num:i(count(SpiDriver/SpiExternalDevice/*))"!]u,
    [!"num:i(num:i(count(SpiDriver/SpiChannel/*)) - 1)"!]u,
    [!"num:i(num:i(count(SpiDriver/SpiJob/*)) - 1)"!]u,
    [!"num:i(num:i(count(SpiDriver/SpiSequence/*)) - 1)"!]u,
    SpiChannelConfig_PB[!"@index"!],
    SpiJobConfig_PB[!"@index"!],
    SpiSequenceConfig_PB[!"@index"!],
    &SpiAttributesConfig_PB[!"@index"!],
    HWUnitConfig_PB,
    /**
    * @brief   DEM error parameters
    */
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
[!IF "$SpiDemErrorEnable"!][!//
[!IF "node:exists(SpiDemEventParameterRefs/SPI_E_HARDWARE_ERROR)"!][!//
[!IF "node:exists(node:ref(SpiDemEventParameterRefs/SPI_E_HARDWARE_ERROR))"!][!//
    { (uint32)STD_ON, (uint32)DemConf_DemEventParameter_[!"node:name(node:ref(SpiDemEventParameterRefs/SPI_E_HARDWARE_ERROR))"!]} /* SPI_E_HARDWARE_ERROR parameters*/ [!//
[!ELSE!][!//
    [!ERROR "Invalid reference for SPI_E_HARDWARE_ERROR"!][!//
[!ENDIF!][!//
[!ELSE!][!//
    { (uint32)STD_OFF, (uint32)0U} /* SPI_E_HARDWARE_ERROR parameters*/[!//
[!ENDIF!][!//
[!ELSE!][!//
    { (uint32)STD_OFF, (uint32)0U}/* SPI_E_HARDWARE_ERROR parameters*/ [!//
[!ENDIF!][!CR!][!//
#endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//=================== Export Driver Configuration ==================================================
[!MACRO "Spi_ExportDriverConfiguration"!][!//
[!NOCODE!][!//
[!VAR "configName" = "as:name(SpiDriver)"!][!//
[!CODE!][!//
#define SPI_CONF_PB \
[!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern CONST(Spi_ConfigType, SPI_CONST) [!"$configName"!]_[!"."!];[!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern CONST(Spi_ConfigType, SPI_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!ENDNOCODE!][!//

