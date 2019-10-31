/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LEDActuator.c
 *
 * Code generated for Simulink model 'LEDActuator'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Sun Dec  8 00:39:51 2019
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "LEDActuator.h"

/* Model step function */
void LEDActuatorMain(void)
{
  DigitalLevel tmp;

  /* Outputs for Atomic SubSystem: '<Root>/LEDActuatorMain_sys' */
  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/DigitalLevel.IOHWAB_HIGH '
   *  Constant: '<S1>/DigitalLevel.IOHWAB_LOW '
   *  Inport: '<Root>/LightSts_status'
   */
  if (Rte_IRead_LEDActuatorMain_LightSts_status()) {
    tmp = IOHWAB_HIGH;
  } else {
    tmp = IOHWAB_LOW;
  }

  /* End of Switch: '<S1>/Switch' */

  /* FunctionCaller: '<S1>/LEDSignal_Write' */
  Rte_Call_LEDSignal_Write(tmp);

  /* End of Outputs for SubSystem: '<Root>/LEDActuatorMain_sys' */
}

/* Model initialize function */
void LEDActuator_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
