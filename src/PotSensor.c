/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PotSensor.c
 *
 * Code generated for Simulink model 'PotSensor'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Thu Dec  5 23:43:46 2019
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "PotSensor.h"

/* Model step function */
void PotSensorMain(void)
{
  AnalogValue rtb_POTSignal_Read_o1;
  SignalQuality rtb_POTSignal_Read_o2;

  /* Outputs for Atomic SubSystem: '<Root>/PotSensorMain_sys' */
  /* FunctionCaller: '<S1>/POTSignal_Read' */
  Rte_Call_POTSignal_Read(&rtb_POTSignal_Read_o1, &rtb_POTSignal_Read_o2);

  /* Outport: '<Root>/POTSts_message' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  Rte_IWrite_PotSensorMain_POTSts_message((uint8)rtb_POTSignal_Read_o1);

  /* End of Outputs for SubSystem: '<Root>/PotSensorMain_sys' */
}

/* Model initialize function */
void PotSensor_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
