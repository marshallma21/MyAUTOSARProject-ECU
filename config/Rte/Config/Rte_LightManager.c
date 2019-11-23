/** === HEADER ====================================================================================
 */

#include <Rte.h>

#include <Os.h>
#if ((OS_AR_RELEASE_MAJOR_VERSION != RTE_AR_RELEASE_MAJOR_VERSION) || (OS_AR_RELEASE_MINOR_VERSION != RTE_AR_RELEASE_MINOR_VERSION))
#error Os version mismatch
#endif

#include <Com.h>
#if ((COM_AR_RELEASE_MAJOR_VERSION != RTE_AR_RELEASE_MAJOR_VERSION) || (COM_AR_RELEASE_MINOR_VERSION != RTE_AR_RELEASE_MINOR_VERSION))
#error Com version mismatch
#endif

#include <Rte_Hook.h>
#include <Rte_Internal.h>
#include <Rte_Calprms.h>

#include "Rte_LightManager.h"

/** === Runnable Prototypes =======================================================================
 */

/** ------ LightManagerInstance -----------------------------------------------------------------------
 */
void Rte_LightManagerInstance_RedLiDimming(void); /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required] */
void Rte_LightManagerInstance_TimeToggleLED(void); /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required] */

/** === Inter-Runnable Variable Buffers ===========================================================
 */

/** === Inter-Runnable Variable Functions =========================================================
 */

/** === Implicit Buffer Instances =================================================================
 */
/*lint -e765 AUTOSAR API SWS_MemMap_00003 */
#define LightManager_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_IntImpl ImplDE_LightManagerInstance_RedLiDimming_IntReq_message; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*//*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define LightManager_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define LightManager_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_IntensityStatusImpl ImplDE_LightManagerInstance_RedLiDimming_RedLiIntSts_status; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*//*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define LightManager_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define LightManager_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_LEDStatusImpl ImplDE_LightManagerInstance_TimeToggleLED_BlueLiSts_status; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*//*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define LightManager_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define LightManager_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_SwitchStatusImpl ImplDE_LightManagerInstance_TimeToggleLED_BtnPressed_status; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*//*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define LightManager_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define LightManager_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_IntImpl ImplDE_LightManagerInstance_TimeToggleLED_LEDSts_message; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*//*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define LightManager_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Per Instance Memories =====================================================================
 */

/** === Component Data Structure Instances ========================================================
 */
#define LightManager_START_SEC_CONST_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_CDS_LightManager LightManager_LightManagerInstance = {
    .RedLiDimming_IntReq_message = &ImplDE_LightManagerInstance_RedLiDimming_IntReq_message,
    .RedLiDimming_RedLiIntSts_status = &ImplDE_LightManagerInstance_RedLiDimming_RedLiIntSts_status,
    .TimeToggleLED_BtnPressed_status = &ImplDE_LightManagerInstance_TimeToggleLED_BtnPressed_status,
    .TimeToggleLED_BlueLiSts_status = &ImplDE_LightManagerInstance_TimeToggleLED_BlueLiSts_status,
    .TimeToggleLED_LEDSts_message = &ImplDE_LightManagerInstance_TimeToggleLED_LEDSts_message
}; /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define LightManager_STOP_SEC_CONST_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define LightManager_START_SEC_CONST_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_Instance Rte_Inst_LightManager = &LightManager_LightManagerInstance;
/*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define LightManager_STOP_SEC_CONST_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Runnables =================================================================================
 */

/** ------ LightManagerInstance -----------------------------------------------------------------------
 */

#define LightManager_START_SEC_CODE
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_LightManagerInstance_RedLiDimming(void) {

    /* PRE */
    Rte_Read_LightManager_LightManagerInstance_IntReq_message(&ImplDE_LightManagerInstance_RedLiDimming_IntReq_message.value); /*lint !e534 AUTOSAR API */

    /* MAIN */

    RedLiDimmingMain();

    /* POST */

    Rte_Write_LightManager_LightManagerInstance_RedLiIntSts_status(ImplDE_LightManagerInstance_RedLiDimming_RedLiIntSts_status.value); /*lint !e534 AUTOSAR API */

} /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define LightManager_STOP_SEC_CODE
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define LightManager_START_SEC_CODE
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_LightManagerInstance_TimeToggleLED(void) {

    /* PRE */
    Rte_Read_LightManager_LightManagerInstance_BtnPressed_status(&ImplDE_LightManagerInstance_TimeToggleLED_BtnPressed_status.value); /*lint !e534 AUTOSAR API */

    /* MAIN */

    TimeToggleLEDMain();

    /* POST */

    Rte_Write_LightManager_LightManagerInstance_BlueLiSts_status(ImplDE_LightManagerInstance_TimeToggleLED_BlueLiSts_status.value); /*lint !e534 AUTOSAR API */

    Rte_Write_LightManager_LightManagerInstance_LEDSts_message(ImplDE_LightManagerInstance_TimeToggleLED_LEDSts_message.value); /*lint !e534 AUTOSAR API */

} /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define LightManager_STOP_SEC_CODE
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */   

