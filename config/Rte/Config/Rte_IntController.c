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

#include "Rte_IntController.h"

/** === Runnable Prototypes =======================================================================
 */

/** ------ RedLiIntControllerInstance -----------------------------------------------------------------------
 */
void Rte_RedLiIntControllerInstance_IntControllerMain(void); /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required] */

/** === Inter-Runnable Variable Buffers ===========================================================
 */

/** === Inter-Runnable Variable Functions =========================================================
 */

/** === Implicit Buffer Instances =================================================================
 */
/*lint -e765 AUTOSAR API SWS_MemMap_00003 */
#define IntController_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <IntController_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_IntensityStatusImpl ImplDE_RedLiIntControllerInstance_IntControllerMain_IntSts_status; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*//*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define IntController_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <IntController_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Per Instance Memories =====================================================================
 */

/** === Component Data Structure Instances ========================================================
 */
#define IntController_START_SEC_CONST_UNSPECIFIED
#include <IntController_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_CDS_IntController IntController_RedLiIntControllerInstance = {
    .IntControllerMain_IntSts_status = &ImplDE_RedLiIntControllerInstance_IntControllerMain_IntSts_status
}; /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define IntController_STOP_SEC_CONST_UNSPECIFIED
#include <IntController_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define IntController_START_SEC_CONST_UNSPECIFIED
#include <IntController_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_Instance Rte_Inst_IntController = &IntController_RedLiIntControllerInstance;
/*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define IntController_STOP_SEC_CONST_UNSPECIFIED
#include <IntController_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Runnables =================================================================================
 */

/** ------ RedLiIntControllerInstance -----------------------------------------------------------------------
 */

#define IntController_START_SEC_CODE
#include <IntController_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_RedLiIntControllerInstance_IntControllerMain(void) {

    /* PRE */
    Rte_Read_IntController_RedLiIntControllerInstance_IntSts_status(&ImplDE_RedLiIntControllerInstance_IntControllerMain_IntSts_status.value); /*lint !e534 AUTOSAR API */

    /* MAIN */

    IntControllerMain();

    /* POST */

} /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define IntController_STOP_SEC_CODE
#include <IntController_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */   

