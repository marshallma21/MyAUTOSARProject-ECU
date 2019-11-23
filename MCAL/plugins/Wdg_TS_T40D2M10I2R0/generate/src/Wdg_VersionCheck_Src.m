[!NOCODE!][!//
/**
  @file    Wdg_VersionCheck_Src.m
  @version 1.0.2

  @brief   AUTOSAR Wdg - version check macro.
  @details Version checks.
  
  Project AUTOSAR 4.2 MCAL
  Patform ARM
  Peripheral Wdog
  Dependencies none
  
  ARVersion 4.2.2
  ARRevision ASR_REL_4_2_REV_0002
  ARConfVariant
  SWVersion 1.0.2
  BuildVersion S32K14xS32K14X_MCAL_1_0_2_RTM_ASR_REL_4_2_REV_0002_20190426

  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2019 NXP
  All Rights Reserved.
*/
/*==================================================================================================
==================================================================================================*/
[!VAR "WdgArReleaseMajorVersionTemplate"="4"!][!//
[!VAR "WdgArReleaseMinorVersionTemplate"="2"!][!//
[!VAR "WdgArReleasePatchVersionTemplate"="2"!][!//
[!VAR "WdgSwMajorVersionTemplate"="1"!][!//     
[!VAR "WdgSwMinorVersionTemplate"="0"!][!//
[!VAR "WdgSwPatchVersionTemplate"="2"!][!//   

[!ENDNOCODE!][!//
[!SELECT "CommonPublishedInformation"!][!//
[!IF "not(num:i(ArReleaseMajorVersion) = num:i($WdgArReleaseMajorVersionTemplate))"!]
    [!ERROR!]
        "AUTOSAR major version number of the Basic Software Module Description file (Wdg.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Wdg_Cfg.c version [!"num:i($WdgArReleaseMajorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArReleaseMinorVersion)  = num:i($WdgArReleaseMinorVersionTemplate))"!]
    [!ERROR!]
        "AUTOSAR minor version number of the Basic Software Module Description file (Wdg.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Wdg_Cfg.c version [!"num:i($WdgArReleaseMinorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArReleaseRevisionVersion)  = num:i($WdgArReleasePatchVersionTemplate))"!]
    [!ERROR!]
        "AUTOSAR patch version number of the Basic Software Module Description file (Wdg.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Wdg_Cfg.c version [!"num:i($WdgArReleasePatchVersionTemplate)"!]) are different
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMajorVersion) = num:i($WdgSwMajorVersionTemplate))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Wdg.epd version [!"SwMajorVersion"!]) and the Code template file (Wdg_Cfg.c version [!"num:i($WdgSwMajorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMinorVersion) = num:i($WdgSwMinorVersionTemplate))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Wdg.epd version [!"SwMinorVersion"!]) and the Code template file (Wdg_Cfg.c version [!"num:i($WdgSwMinorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwPatchVersion) = num:i($WdgSwPatchVersionTemplate))"!]
    [!ERROR!]
        "The software patch number of the Basic Software Module Description file (Wdg.epd version [!"SwPatchVersion"!]) and the Code template file (Wdg_Cfg.c version [!"num:i($WdgSwPatchVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!NOCODE!][!//

[!ENDNOCODE!][!//
