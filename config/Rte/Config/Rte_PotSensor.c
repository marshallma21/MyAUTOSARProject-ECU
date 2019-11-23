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

#include "Rte_PotSensor.h"

/** === Runnable Prototypes =======================================================================
 */

/** ------ PotSensorInstance -----------------------------------------------------------------------
 */
void Rte_PotSensorInstance_PotSensorMain(void); /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required] */

/** === Inter-Runnable Variable Buffers ===========================================================
 */

/** === Inter-Runnable Variable Functions =========================================================
 */

/** === Implicit Buffer Instances =================================================================
 */
/*lint -e765 AUTOSAR API SWS_MemMap_00003 */
#define PotSensor_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <PotSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
Rte_DE_IntImpl ImplDE_PotSensorInstance_PotSensorMain_POTSts_message; /*lint -e621 MISRA:OTHER:Ignore misidentified symbol clash [MISRA 2012 Rule 5.5, required]*//*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define PotSensor_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <PotSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Per Instance Memories =====================================================================
 */

/** === Component Data Structure Instances ========================================================
 */
#define PotSensor_START_SEC_CONST_UNSPECIFIED
#include <PotSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_CDS_PotSensor PotSensor_PotSensorInstance = {
    .PotSensorMain_POTSts_message = &ImplDE_PotSensorInstance_PotSensorMain_POTSts_message
}; /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define PotSensor_STOP_SEC_CONST_UNSPECIFIED
#include <PotSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

#define PotSensor_START_SEC_CONST_UNSPECIFIED
#include <PotSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
const Rte_Instance Rte_Inst_PotSensor = &PotSensor_PotSensorInstance;
/*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define PotSensor_STOP_SEC_CONST_UNSPECIFIED
#include <PotSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === Runnables =================================================================================
 */

/** ------ PotSensorInstance -----------------------------------------------------------------------
 */

#define PotSensor_START_SEC_CODE
#include <PotSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_PotSensorInstance_PotSensorMain(void) {

    /* PRE */

    /* MAIN */

    PotSensorMain();

    /* POST */

    Rte_Write_PotSensor_PotSensorInstance_POTSts_message(ImplDE_PotSensorInstance_PotSensorMain_POTSts_message.value); /*lint !e534 AUTOSAR API */

} /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define PotSensor_STOP_SEC_CODE
#include <PotSensor_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */   

