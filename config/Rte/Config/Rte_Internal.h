#ifndef RTE_INTERNAL_H_
#define RTE_INTERNAL_H_

#include <Rte_Fifo.h>
#include <Rte_DataHandleType.h>
#include <Os.h>

#include <Queue.h>
extern boolean RteInitialized;

/** --- PORT STATUS TYPES ------------------------------------------------------------------- */

/** --- SERVER REQUEST TYPES ---------------------------------------------------------------- */

/** --- SERVER RESPONSE TYPES --------------------------------------------------------------- */

typedef enum {
    RTE_NO_REQUEST_PENDING = 0, RTE_REQUEST_PENDING = 1, RTE_RESPONSE_RECEIVED = 2
} Rte_ResponseStatusType;

/** --- SERVER RETURN SIGNAL IDS ------------------------------------------------------------ */

/** --- SERVER ACTIVATIONS ------------------------------------------------------------------ */

/** --- MODE MACHINE TYPES ------------------------------------------------------------------ */

/** --- MODE MACHINE TRANSITION DEFINES ----------------------------------------------------- */

/** --- MODE MACHINE VALUE DEFINES ---------------------------------------------------------- */

/** --- EXCLUSIVE AREA TYPES ---------------------------------------------------------------- */
typedef struct {
    boolean entered;
} ExclusiveAreaType;

/** --- EXPORTED FUNCTIONS ------------------------------------------------------------------ */
/** === IntController ======================================================================= */
/** --- RedLiIntControllerInstance -------------------------------------------------------------------- */

/** ------ DutySignal */
Std_ReturnType Rte_Call_IntController_RedLiIntControllerInstance_DutySignal_Set(/*IN*/DutyCycle DutyValue, /*OUT*/SignalQuality * Quality);

/** ------ IntSts */
Std_ReturnType Rte_Read_IntController_RedLiIntControllerInstance_IntSts_status(/*OUT*/IntensityStatusImpl * data);

/** === IoHwAb ======================================================================= */
/** --- IoHwAbInstance -------------------------------------------------------------------- */

/** ------ Analog_POT */
Std_ReturnType Rte_Call_IoHwAb_IoHwAbInstance_Analog_POT_Read(/*OUT*/AnalogValue * Value, /*OUT*/SignalQuality * Quality);

/** ------ Digital_BlueLED */
Std_ReturnType Rte_Call_IoHwAb_IoHwAbInstance_Digital_BlueLED_Write(/*IN*/DigitalLevel Level);

/** ------ Digital_Swt */
Std_ReturnType Rte_Call_IoHwAb_IoHwAbInstance_Digital_Swt_Read(/*OUT*/DigitalLevel * Level, /*OUT*/SignalQuality * Quality);

/** ------ Pwm_RedLEDDuty */
Std_ReturnType Rte_Call_IoHwAb_IoHwAbInstance_Pwm_RedLEDDuty_Set(/*IN*/DutyCycle DutyValue, /*OUT*/SignalQuality * Quality);

/** === LEDActuator ======================================================================= */
/** --- BlueLiActuatorInstance -------------------------------------------------------------------- */

/** ------ LEDSignal */
Std_ReturnType Rte_Call_LEDActuator_BlueLiActuatorInstance_LEDSignal_Write(/*IN*/DigitalLevel Level);

/** ------ LightSts */
Std_ReturnType Rte_Read_LEDActuator_BlueLiActuatorInstance_LightSts_status(/*OUT*/LEDStatusImpl * data);

/** === LightManager ======================================================================= */
/** --- LightManagerInstance -------------------------------------------------------------------- */

/** ------ BlueLiSts */
Std_ReturnType Rte_Write_LightManager_LightManagerInstance_BlueLiSts_status(/*IN*/LEDStatusImpl data);

/** ------ BtnPressed */
Std_ReturnType Rte_Read_LightManager_LightManagerInstance_BtnPressed_status(/*OUT*/SwitchStatusImpl * data);

/** ------ IntReq */
Std_ReturnType Rte_Read_LightManager_LightManagerInstance_IntReq_message(/*OUT*/IntImpl * data);

/** ------ LEDSts */
Std_ReturnType Rte_Write_LightManager_LightManagerInstance_LEDSts_message(/*IN*/IntImpl data);

/** ------ RedLiIntSts */
Std_ReturnType Rte_Write_LightManager_LightManagerInstance_RedLiIntSts_status(/*IN*/IntensityStatusImpl data);

/** === PotSensor ======================================================================= */
/** --- PotSensorInstance -------------------------------------------------------------------- */

/** ------ POTSignal */
Std_ReturnType Rte_Call_PotSensor_PotSensorInstance_POTSignal_Read(/*OUT*/AnalogValue * Value, /*OUT*/SignalQuality * Quality);

/** ------ POTSts */
Std_ReturnType Rte_Write_PotSensor_PotSensorInstance_POTSts_message(/*IN*/IntImpl data);

/** === SwtSensor ======================================================================= */
/** --- SwtSensorInstance -------------------------------------------------------------------- */

/** ------ SwtSignal */
Std_ReturnType Rte_Call_SwtSensor_SwtSensorInstance_SwtSignal_Read(/*OUT*/DigitalLevel * Level, /*OUT*/SignalQuality * Quality);

/** ------ SwtSts */
Std_ReturnType Rte_Write_SwtSensor_SwtSensorInstance_SwtSts_status(/*IN*/SwitchStatusImpl data);

/** --- SERVER ACTIVATIONS ------------------------------------------------------------------ */
/*lint -e451 AUTOSAR API SWS_MemMap_00003 */

extern int compare_uint16(void *a, void *b, size_t s);

#endif /* RTE_INTERNAL_H_ */

