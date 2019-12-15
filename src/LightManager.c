/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LightManager.c
 *
 * Code generated for Simulink model 'LightManager'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Sun Dec 15 14:07:05 2019
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "LightManager.h"

/* Block signals and states (default storage) */
DW rtDW;

/* Model step function for TID1 */
void TimeToggleLEDMain(void)           /* Explicit Task: TimeToggleLED */
{
  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_TimeToggleLED_at_outport_1' incorporates:
   *  SubSystem: '<Root>/TimeToggleLED_sys'
   */
  /* S-Function (sfix_bitop): '<S6>/Bitwise NOT' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write1'
   *  Inport: '<Root>/BtnPressed_status'
   */
  rtDW.LEDSts = !Rte_IRead_TimeToggleLED_BtnPressed_status();

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_TimeToggleLED_at_outport_1' */

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_TimeToggleLED_at_outport_1' incorporates:
   *  SubSystem: '<Root>/TimeToggleLED_sys'
   */
  /* Outport: '<Root>/BlueLiSts_status' incorporates:
   *  DataStoreRead: '<S3>/Data Store Read1'
   */
  Rte_IWrite_TimeToggleLED_BlueLiSts_status(rtDW.LEDSts);

  /* Outport: '<Root>/LEDSts_message' incorporates:
   *  DataStoreRead: '<S3>/Data Store Read'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  S-Function (sfix_bitop): '<S3>/Bitwise NOT1'
   */
  Rte_IWrite_TimeToggleLED_LEDSts_message((uint8)!rtDW.LEDSts);

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_TimeToggleLED_at_outport_1' */
}

/* Model step function for TID2 */
void RedLiDimmingMain(void)            /* Explicit Task: RedLiDimming */
{
  IntImpl tmp;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_RedLiDimming_at_outport_1' incorporates:
   *  SubSystem: '<Root>/RedLiDimming_sys'
   */
  /* If: '<S2>/If' incorporates:
   *  Constant: '<S2>/Constant'
   *  DataStoreRead: '<S2>/Data Store Read2'
   */
  if (rtDW.IntStepCounter < 20) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Sum: '<S4>/Add1' incorporates:
     *  DataStoreRead: '<S4>/Data Store Read'
     *  DataStoreRead: '<S4>/Data Store Read1'
     */
    rtDW.Add1 = rtDW.IntSts + rtDW.IntStep;

    /* DataStoreWrite: '<S4>/Data Store Write' */
    rtDW.IntSts = rtDW.Add1;

    /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
     *  Constant: '<S4>/Constant'
     *  DataStoreRead: '<S4>/Data Store Read2'
     *  Sum: '<S4>/Add'
     */
    rtDW.IntStepCounter++;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  }

  /* End of If: '<S2>/If' */

  /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S5>/Action Port'
   */
  /* If: '<S2>/If1' incorporates:
   *  DataStoreRead: '<S2>/Data Store Read'
   *  DataStoreWrite: '<S5>/Data Store Write'
   *  Inport: '<Root>/IntReq_message'
   */
  tmp = Rte_IRead_RedLiDimming_IntReq_message();

  /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
  if (rtDW.IntReq != tmp) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    rtDW.IntReq = tmp;

    /* Product: '<S5>/Divide' incorporates:
     *  Constant: '<S5>/Constant1'
     *  DataStoreRead: '<S5>/Data Store Read'
     *  DataStoreRead: '<S5>/Data Store Read1'
     *  DataStoreWrite: '<S5>/Data Store Write2'
     *  Sum: '<S5>/Add'
     */
    rtDW.IntStep = ((float64)rtDW.IntReq - rtDW.IntSts) / 20.0;

    /* DataStoreWrite: '<S5>/Data Store Write1' incorporates:
     *  Constant: '<S5>/Constant'
     */
    rtDW.IntStepCounter = 0U;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
  }

  /* End of If: '<S2>/If1' */
  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_RedLiDimming_at_outport_1' */

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_RedLiDimming_at_outport_1' incorporates:
   *  SubSystem: '<Root>/RedLiDimming_sys'
   */
  /* Outport: '<Root>/RedLiIntSts_status' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion1'
   */
  Rte_IWrite_RedLiDimming_RedLiIntSts_status((IntensityStatusImpl)rtDW.Add1);

  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_RedLiDimming_at_outport_1' */
}

/* Model initialize function */
void LightManager_Init(void)
{
  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  rtDW.LEDSts = true;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
