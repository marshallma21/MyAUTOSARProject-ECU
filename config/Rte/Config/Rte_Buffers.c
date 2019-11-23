#include <Rte_Buffers.h>
#include <Rte_IntController_Type.h>
#include <Rte_IoHwAb_Type.h>
#include <Rte_LEDActuator_Type.h>
#include <Rte_LightManager_Type.h>
#include <Rte_PotSensor_Type.h>
#include <Rte_SwtSensor_Type.h>

/*lint -e451 AUTOSAR API SWS_MemMap_00003 */
/** === IntController Data =============================================================== */

#define IntController_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <IntController_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

IntensityStatusImpl Rte_Buffer_RedLiIntControllerInstance_IntSts_status; /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define IntController_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <IntController_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === IoHwAb Data =============================================================== */

/** === LEDActuator Data =============================================================== */

#define LEDActuator_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <LEDActuator_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

LEDStatusImpl Rte_Buffer_BlueLiActuatorInstance_LightSts_status; /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define LEDActuator_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <LEDActuator_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === LightManager Data =============================================================== */

#define LightManager_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

SwitchStatusImpl Rte_Buffer_LightManagerInstance_BtnPressed_status; /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define LightManager_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <LightManager_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

/** === PotSensor Data =============================================================== */

/** === SwtSensor Data =============================================================== */

/** --- RTE Transformer Buffers ------------------------------------------------------------- */

#define Rte_START_SEC_CODE
#include <Rte_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
void Rte_Internal_Init_Buffers(void) {
    // Init communication buffers

    // Init mode machine queues

} /*!e9003 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */
#define Rte_STOP_SEC_CODE
#include <Rte_MemMap.h> /*lint !e415 Autosar specified way to group code into memory sections, Req SWS_MemMap_00003 */

