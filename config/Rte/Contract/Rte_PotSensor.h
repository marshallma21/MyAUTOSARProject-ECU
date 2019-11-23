/**
 * Application Header File
 *
 * @req SWS_Rte_01003
 */

/** === HEADER ====================================================================================
 */
/*lint -e18 -e452 LINT:OTHER:Duplicate declarations hidden behind ifdef */

/** --- Normal include guard ----------------------------------------------------------------------
 */
#ifndef RTE_POTSENSOR_H_
#define RTE_POTSENSOR_H_

/** --- C++ guard ---------------------------------------------------------------------------------
 * @req SWS_Rte_03709
 */
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** --- Duplicate application include guard -------------------------------------------------------
 * @req SWS_Rte_01006
 */
#ifdef RTE_APPLICATION_HEADER_FILE
#error Multiple application header files included.
#endif
#define RTE_APPLICATION_HEADER_FILE

/** --- Single runnable API -----------------------------------------------------------------------
 * @req SWS_Rte_02751
 */
#if defined(RTE_RUNNABLEAPI_PotSensorMain)
#define RTE_RUNNABLEAPI
#endif

/** --- Includes ----------------------------------------------------------------------------------
 * @req SWS_Rte_02751
 * @req SWS_Rte_07131
 */
#include <Rte_DataHandleType.h>
#include <Rte_PotSensor_Type.h>

/** --- Application Errors ------------------------------------------------------------------------
 * @req SWS_Rte_02575
 * @req SWS_Rte_02576
 * @req SWS_Rte_07143
 */
#define RTE_E_AnalogServiceRead_E_NOT_OK 1U
#define RTE_E_AnalogServiceRead_E_OK 0U

/** --- Initial Values ----------------------------------------------------------------------------
 * @SWS_Rte_05078
 */

/** --- PIM DATA TYPES ------------------------------------------------------------------------------ */

/** --- Condition Value Macros -------------------------------------------------------
 * @req SWS_Rte_03854
 */

/** === BODY ======================================================================================
 */

/** @req SWS_Rte_03731
 *  @req SWS_Rte_07137
 *  @req SWS_Rte_07138
 *  !req SWS_Rte_06523
 *  @req SWS_Rte_03730
 *  @req SWS_Rte_07677
 *  @req SWS_Rte_02620
 *  @req SWS_Rte_02621
 *  @req SWS_Rte_01055
 *  @req SWS_Rte_03726 */

/** @req SWS_Rte_01343
 *  @req SWS_Rte_01342
 *  !req SWS_Rte_06524
 *  @req SWS_Rte_01053
 */

extern Std_ReturnType Rte_Call_PotSensor_PotSensorInstance_POTSignal_Read(/*OUT*/AnalogValue * Value, /*OUT*/SignalQuality * Quality);

/** @req SWS_Rte_07132
 *  @req SWS_Rte_03714 
 *  @req SWS_Rte_03725 
 *  @req SWS_Rte_03752
 *  @req SWS_Rte_02623
 */
typedef struct {
    Rte_DE_IntImpl * const PotSensorMain_POTSts_message;
} Rte_CDS_PotSensor;

/** --- Instance handle type ---------------------------------------------------------------------- */
typedef Rte_CDS_PotSensor const * const Rte_Instance;

/** --- Singleton instance handle -----------------------------------------------------------------
 *  @req SWS_Rte_03793
 */
extern const Rte_Instance Rte_Inst_PotSensor;
#define self (Rte_Inst_PotSensor)

/** --- Calibration API --------------------------------------------------------------------------- */

/** --- Per Instance Memory API ------------------------------------------------------------------- */

/** --- Indirect port API ------------------------------------------------------------------------- */

/** --- Single Runnable APIs ---------------------------------------------------------------------- */
#if defined(RTE_RUNNABLEAPI)
/** --- PotSensorMain */
#if defined(RTE_RUNNABLEAPI_PotSensorMain)

void PotSensorMain(void);

static inline void Rte_IWrite_PotSensorMain_POTSts_message(/*IN*/IntImpl value) {
    self->PotSensorMain_POTSts_message->value = value;
}

static inline Std_ReturnType Rte_Call_POTSignal_Read(/*OUT*/AnalogValue * Value, /*OUT*/SignalQuality * Quality) {
    return Rte_Call_PotSensor_PotSensorInstance_POTSignal_Read(Value, Quality);
}

#endif
#endif

/** --- All Runnable APIs ------------------------------------------------------------------------- */
#if !defined(RTE_RUNNABLEAPI)
void PotSensorMain(void);

static inline void Rte_IWrite_PotSensorMain_POTSts_message(/*IN*/IntImpl value) {
    self->PotSensorMain_POTSts_message->value = value;
}

static inline Std_ReturnType Rte_Call_POTSignal_Read(/*OUT*/AnalogValue * Value, /*OUT*/SignalQuality * Quality) {
    return Rte_Call_PotSensor_PotSensorInstance_POTSignal_Read(Value, Quality);
}
#endif

/** === FOOTER ====================================================================================
 */

/** @req SWS_Rte_03710 */
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_POTSENSOR_H_ */
