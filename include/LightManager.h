/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LightManager.h
 *
 * Code generated for Simulink model 'LightManager'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Sat Dec  7 21:11:20 2019
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_LightManager_h_
#define RTW_HEADER_LightManager_h_
#ifndef LightManager_COMMON_INCLUDES_
# define LightManager_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "Rte_LightManager.h"
#endif                                 /* LightManager_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct tag_DW {
  float64 Add1;                        /* '<S4>/Add1' */
  float64 IntStep;                     /* '<Root>/Data Store Memory4' */
  float64 IntSts;                      /* '<Root>/Data Store Memory6' */
  sint32 chartAbsoluteTimeCounter;     /* '<S7>/Debounce' */
  sint32 durationLastReferenceTick_1;  /* '<S7>/Debounce' */
  sint32 durationLastReferenceTick_1_p;/* '<S7>/Debounce' */
  uint16 counter_period;               /* '<S6>/Data Store Memory' */
  uint8 IntReq;                        /* '<Root>/Data Store Memory' */
  uint8 PotValue;                      /* '<Root>/Data Store Memory2' */
  uint8 IntStepCounter;                /* '<Root>/Data Store Memory5' */
  uint8 is_active_c3_LightManager;     /* '<S7>/Debounce' */
  uint8 is_c3_LightManager;            /* '<S7>/Debounce' */
  boolean LEDToggleEnable;             /* '<Root>/Data Store Memory1' */
  boolean LEDSts;                      /* '<Root>/Data Store Memory3' */
  boolean condWasTrueAtLastTimeStep_1; /* '<S7>/Debounce' */
  boolean condWasTrueAtLastTimeStep_1_p;/* '<S7>/Debounce' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct tag_PrevZCX {
  ZCSigState UpdateToggleEnable_Trig_ZCE;/* '<S7>/UpdateToggleEnable' */
  ZCSigState EnabledandTriggeredSubsystem_Tr;
                                    /* '<S6>/Enabled and Triggered Subsystem' */
} PrevZCX;

/* Block signals and states (default storage) */
extern DW rtDW;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LightManager'
 * '<S1>'   : 'LightManager/LightManager_Init'
 * '<S2>'   : 'LightManager/RedLiDimming_sys'
 * '<S3>'   : 'LightManager/TimeToggleLED_sys'
 * '<S4>'   : 'LightManager/RedLiDimming_sys/If Action Subsystem'
 * '<S5>'   : 'LightManager/RedLiDimming_sys/If Action Subsystem1'
 * '<S6>'   : 'LightManager/TimeToggleLED_sys/ToggleLED'
 * '<S7>'   : 'LightManager/TimeToggleLED_sys/UpdateLEDToggleEnable'
 * '<S8>'   : 'LightManager/TimeToggleLED_sys/ToggleLED/Enabled and Triggered Subsystem'
 * '<S9>'   : 'LightManager/TimeToggleLED_sys/UpdateLEDToggleEnable/Debounce'
 * '<S10>'  : 'LightManager/TimeToggleLED_sys/UpdateLEDToggleEnable/UpdateToggleEnable'
 */
#endif                                 /* RTW_HEADER_LightManager_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
