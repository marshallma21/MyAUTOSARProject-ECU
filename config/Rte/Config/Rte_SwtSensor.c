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

#include "Rte_SwtSensor.h"

/** === Runnable Prototypes =======================================================================
 */

/** ------ SwtSensorInstance -----------------------------------------------------------------------
 */
void Rte_SwtSensorInstance_SwtSensorMain(void); /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required] */

/** === Inter-Runnable Variable Buffers ===========================================================
 */

/** === Inter-Runnable Variable Functions =========================================================
 */

/** === Implicit Buffer Instances =================================================================
 */
/*lint -e765 AUTOSAR API SWS_MemMap_00003 */
#define SwtSensor_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <SwtSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_SwitchStatusImpl ImplDE_SwtSensorInstance_SwtSensorMain_SwtSts_status; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*//*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define SwtSensor_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <SwtSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Per Instance Memories =====================================================================
 */

/** === Component Data Structure Instances ========================================================
 */
#define SwtSensor_START_SEC_CONST_UNSPECIFIED
#include <SwtSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_CDS_SwtSensor SwtSensor_SwtSensorInstance = {
    .SwtSensorMain_SwtSts_status = &ImplDE_SwtSensorInstance_SwtSensorMain_SwtSts_status
}; /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define SwtSensor_STOP_SEC_CONST_UNSPECIFIED
#include <SwtSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define SwtSensor_START_SEC_CONST_UNSPECIFIED
#include <SwtSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_Instance Rte_Inst_SwtSensor = &SwtSensor_SwtSensorInstance;
/*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define SwtSensor_STOP_SEC_CONST_UNSPECIFIED
#include <SwtSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Runnables =================================================================================
 */

/** ------ SwtSensorInstance -----------------------------------------------------------------------
 */

#define SwtSensor_START_SEC_CODE
#include <SwtSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_SwtSensorInstance_SwtSensorMain(void) {

    /* PRE */

    /* MAIN */

    SwtSensorMain();

    /* POST */

    Rte_Write_SwtSensor_SwtSensorInstance_SwtSts_status(ImplDE_SwtSensorInstance_SwtSensorMain_SwtSts_status.value); /*lint !e534 AUTOSAR API */

} /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define SwtSensor_STOP_SEC_CODE
#include <SwtSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */   

