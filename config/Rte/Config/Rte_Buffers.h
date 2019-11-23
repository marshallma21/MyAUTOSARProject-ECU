#ifndef RTE_BUFFERS_H_
#define RTE_BUFFERS_H_

#include <Rte_Internal.h>

/*lint -e9003 variable not declared in block acceptable */

void Rte_Internal_Init_Buffers(void);

/** === IntController Data =============================================================== */

extern IntensityStatusImpl Rte_Buffer_RedLiIntControllerInstance_IntSts_status;

/** === IoHwAb Data =============================================================== */

/** === LEDActuator Data =============================================================== */

extern LEDStatusImpl Rte_Buffer_BlueLiActuatorInstance_LightSts_status;

/** === LightManager Data =============================================================== */

extern SwitchStatusImpl Rte_Buffer_LightManagerInstance_BtnPressed_status;

/** === PotSensor Data =============================================================== */

/** === SwtSensor Data =============================================================== */

/** --- RTE Transformer Buffers ------------------------------------------------------------- */

/** --- EXTERNALS --------------------------------------------------------------------------- */
extern Std_ReturnType Rte_IoHwAbInstance_AnalogRead(/*IN*/IoHwAb_SignalType_ portDefArg1, /*OUT*/AnalogValue * Value, /*OUT*/SignalQuality * Quality);
extern Std_ReturnType Rte_IoHwAbInstance_DigitalRead(/*IN*/IoHwAb_SignalType_ portDefArg1, /*OUT*/DigitalLevel * Level, /*OUT*/
        SignalQuality * Quality);
extern Std_ReturnType Rte_IoHwAbInstance_DigitalWrite(/*IN*/IoHwAb_SignalType_ portDefArg1, /*IN*/DigitalLevel Level);
extern Std_ReturnType Rte_IoHwAbInstance_PwmSetDuty(/*IN*/IoHwAb_SignalType_ portDefArg1, /*IN*/DutyCycle DutyValue, /*OUT*/SignalQuality * Quality);

#endif /* RTE_BUFFERS_H_ */

