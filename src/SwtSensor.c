/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SwtSensor.c
 *
 * Code generated for Simulink model 'SwtSensor'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Thu Dec  5 23:51:57 2019
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "SwtSensor.h"

/* Model step function */
void SwtSensorMain(void)
{
  DigitalLevel rtb_SwtSignal_Read_o1;
  SignalQuality rtb_SwtSignal_Read_o2;

  /* Outputs for Atomic SubSystem: '<Root>/SwtSensorMain_sys' */
  /* FunctionCaller: '<S1>/SwtSignal_Read' */
  Rte_Call_SwtSignal_Read(&rtb_SwtSignal_Read_o1, &rtb_SwtSignal_Read_o2);

  /* Outport: '<Root>/SwtSts_status' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  Rte_IWrite_SwtSensorMain_SwtSts_status(rtb_SwtSignal_Read_o1 != 0);

  /* End of Outputs for SubSystem: '<Root>/SwtSensorMain_sys' */
}

/* Model initialize function */
void SwtSensor_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
