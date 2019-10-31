/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: IntController.c
 *
 * Code generated for Simulink model 'IntController'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Fri Dec  6 01:18:54 2019
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "IntController.h"

/* Model step function */
void IntControllerMain(void)
{
  SignalQuality rtb_DutySignal_Set_o1;

  /* Outputs for Atomic SubSystem: '<Root>/IntControllerMain_sys' */
  /* FunctionCaller: '<S1>/DutySignal_Set' incorporates:
   *  Constant: '<S1>/Constant'
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Inport: '<Root>/IntSts_status'
   *  Product: '<S1>/Product'
   */
  Rte_Call_DutySignal_Set((uint32)(Rte_IRead_IntControllerMain_IntSts_status() *
    257.0), &rtb_DutySignal_Set_o1);

  /* End of Outputs for SubSystem: '<Root>/IntControllerMain_sys' */
}

/* Model initialize function */
void IntController_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
