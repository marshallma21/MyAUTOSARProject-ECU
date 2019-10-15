/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: LightManager.c
 *
 * Code generated for Simulink model 'LightManager'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Mon Dec  9 00:02:44 2019
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "LightManager.h"

/* Named constants for Chart: '<S7>/Debounce' */
#define IN_BtnNotPressed               ((uint8)1U)
#define IN_BtnPressed                  ((uint8)2U)
#include "solver_zc.h"
#include "zero_crossing_types.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;
extern ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, float64
  currValue);

/* Detect zero crossings events. */
ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState* prevZc, float64 currValue)
{
  slZcEventType zcsDir;
  slZcEventType tempEv;
  ZCEventType zcEvent = NO_ZCEVENT;    /* assume */

  /* zcEvent matrix */
  static const slZcEventType eventMatrix[4][4] = {
    /*          ZER              POS              NEG              UNK */
    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_Z2P, SL_ZCS_EVENT_Z2N, SL_ZCS_EVENT_NUL },/* ZER */

    { SL_ZCS_EVENT_P2Z, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_P2N, SL_ZCS_EVENT_NUL },/* POS */

    { SL_ZCS_EVENT_N2Z, SL_ZCS_EVENT_N2P, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL },/* NEG */

    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL }/* UNK */
  };

  /* get prevZcEvent and prevZcSign from prevZc */
  slZcEventType prevEv = (slZcEventType)(((uint8)(*prevZc)) >> 2);
  slZcSignalSignType prevSign = (slZcSignalSignType)(((uint8)(*prevZc)) & (uint8)
    0x03);

  /* get current zcSignal sign from current zcSignal value */
  slZcSignalSignType currSign = (slZcSignalSignType)((currValue) > 0.0 ?
    SL_ZCS_SIGN_POS :
    ((currValue) < 0.0 ? SL_ZCS_SIGN_NEG : SL_ZCS_SIGN_ZERO));

  /* get current zcEvent based on prev and current zcSignal value */
  slZcEventType currEv = eventMatrix[prevSign][currSign];

  /* get slZcEventType from ZCDirection */
  switch (zcDir) {
   case ANY_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL;
    break;

   case FALLING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_DN;
    break;

   case RISING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_UP;
    break;

   default:
    zcsDir = SL_ZCS_EVENT_NUL;
    break;
  }

  /*had event, check if double zc happend remove double detection. */
  if (slZcHadEvent(currEv, zcsDir)) {
    currEv = (slZcEventType)(slZcUnAliasEvents(prevEv, currEv));
  } else {
    currEv = SL_ZCS_EVENT_NUL;
  }

  /* Update prevZc */
  tempEv = (slZcEventType)(currEv << 2);/* shift left by 2 bits */
  *prevZc = (ZCSigState)((currSign) | (tempEv));
  if ((currEv & SL_ZCS_EVENT_ALL_DN) != 0) {
    zcEvent = FALLING_ZCEVENT;
  } else if ((currEv & SL_ZCS_EVENT_ALL_UP) != 0) {
    zcEvent = RISING_ZCEVENT;
  } else {
    zcEvent = NO_ZCEVENT;
  }

  return zcEvent;
}                                      /* rt_ZCFcn */

/* Model step function for TID1 */
void TimeToggleLEDMain(void)           /* Explicit Task: TimeToggleLED */
{
  IntImpl rtb_DataTypeConversion2;
  sint32 rtb_DataTypeConversion;
  sint32 rtb_y;
  ZCEventType zcEvent;
  uint16 rtb_Add1;
  boolean rtb_RelationalOperator;

  /* RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_TimeToggleLED_at_outport_1' incorporates:
   *  SubSystem: '<Root>/TimeToggleLED_sys'
   */
  /* Outport: '<Root>/BlueLiSts_status' incorporates:
   *  DataStoreRead: '<S3>/Data Store Read1'
   */
  Rte_IWrite_TimeToggleLED_BlueLiSts_status(rtDW.LEDSts);

  /* DataTypeConversion: '<S3>/Data Type Conversion2' incorporates:
   *  DataStoreRead: '<S3>/Data Store Read'
   */
  rtb_DataTypeConversion2 = rtDW.LEDSts;

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/BtnPressed_status'
   */
  rtb_DataTypeConversion = Rte_IRead_TimeToggleLED_BtnPressed_status();

  /* Chart: '<S7>/Debounce' */
  rtDW.chartAbsoluteTimeCounter++;
  rtb_RelationalOperator = (rtb_DataTypeConversion == 0);
  if ((!rtb_RelationalOperator) || (!rtDW.condWasTrueAtLastTimeStep_1)) {
    rtDW.durationLastReferenceTick_1 = rtDW.chartAbsoluteTimeCounter;
  }

  rtDW.condWasTrueAtLastTimeStep_1 = rtb_RelationalOperator;
  rtb_RelationalOperator = (rtb_DataTypeConversion > 0);
  if ((!rtb_RelationalOperator) || (!rtDW.condWasTrueAtLastTimeStep_1_p)) {
    rtDW.durationLastReferenceTick_1_p = rtDW.chartAbsoluteTimeCounter;
  }

  rtDW.condWasTrueAtLastTimeStep_1_p = rtb_RelationalOperator;
  if (rtDW.is_active_c3_LightManager == 0U) {
    rtDW.chartAbsoluteTimeCounter = 0;
    rtDW.is_active_c3_LightManager = 1U;
    rtDW.durationLastReferenceTick_1_p = rtDW.chartAbsoluteTimeCounter;
    rtDW.is_c3_LightManager = IN_BtnNotPressed;
    rtb_y = 0;
    rtDW.condWasTrueAtLastTimeStep_1_p = (rtb_DataTypeConversion > 0);
  } else if (rtDW.is_c3_LightManager == IN_BtnNotPressed) {
    rtb_RelationalOperator = (rtb_DataTypeConversion > 0);
    if ((!rtb_RelationalOperator) || (!rtDW.condWasTrueAtLastTimeStep_1_p)) {
      rtDW.durationLastReferenceTick_1_p = rtDW.chartAbsoluteTimeCounter;
    }

    rtDW.condWasTrueAtLastTimeStep_1_p = rtb_RelationalOperator;
    if (rtDW.chartAbsoluteTimeCounter - rtDW.durationLastReferenceTick_1_p > 10)
    {
      rtDW.durationLastReferenceTick_1 = rtDW.chartAbsoluteTimeCounter;
      rtDW.is_c3_LightManager = IN_BtnPressed;
      rtb_y = 1;
      rtDW.condWasTrueAtLastTimeStep_1 = (rtb_DataTypeConversion == 0);
    } else {
      rtb_y = 0;
    }
  } else {
    /* case IN_BtnPressed: */
    rtb_RelationalOperator = (rtb_DataTypeConversion == 0);
    if ((!rtb_RelationalOperator) || (!rtDW.condWasTrueAtLastTimeStep_1)) {
      rtDW.durationLastReferenceTick_1 = rtDW.chartAbsoluteTimeCounter;
    }

    rtDW.condWasTrueAtLastTimeStep_1 = rtb_RelationalOperator;
    if (rtDW.chartAbsoluteTimeCounter - rtDW.durationLastReferenceTick_1 < 1) {
      rtDW.durationLastReferenceTick_1_p = rtDW.chartAbsoluteTimeCounter;
      rtDW.is_c3_LightManager = IN_BtnNotPressed;
      rtb_y = 0;
      rtDW.condWasTrueAtLastTimeStep_1_p = (rtb_DataTypeConversion > 0);
    } else {
      rtb_y = 1;
    }
  }

  /* End of Chart: '<S7>/Debounce' */

  /* Outputs for Triggered SubSystem: '<S7>/UpdateToggleEnable' incorporates:
   *  TriggerPort: '<S10>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&rtPrevZCX.UpdateToggleEnable_Trig_ZCE,
                     ((float64)rtb_y));
  if (zcEvent != NO_ZCEVENT) {
    /* DataStoreWrite: '<S10>/Data Store Write' incorporates:
     *  DataStoreRead: '<S10>/Data Store Read'
     *  S-Function (sfix_bitop): '<S10>/Bitwise Operator'
     */
    rtDW.LEDToggleEnable = !rtDW.LEDToggleEnable;

    /* DataStoreWrite: '<S10>/Data Store Write1' incorporates:
     *  Constant: '<S10>/Constant'
     */
    rtDW.LEDSts = true;
  }

  /* End of Outputs for SubSystem: '<S7>/UpdateToggleEnable' */

  /* Outputs for Enabled SubSystem: '<S3>/ToggleLED' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* DataStoreRead: '<S3>/Data Store Read2' */
  if (rtDW.LEDToggleEnable) {
    /* Sum: '<S6>/Add1' incorporates:
     *  Constant: '<S6>/Constant'
     *  DataStoreRead: '<S6>/Data Store Read'
     */
    rtb_Add1 = (uint16)(rtDW.counter_period + 1U);

    /* DataStoreWrite: '<S6>/Data Store Write' */
    rtDW.counter_period = rtb_Add1;

    /* RelationalOperator: '<S6>/Relational Operator' incorporates:
     *  Constant: '<S6>/Constant2'
     */
    rtb_RelationalOperator = (rtb_Add1 > 50);

    /* Outputs for Triggered SubSystem: '<S6>/Enabled and Triggered Subsystem' incorporates:
     *  TriggerPort: '<S8>/Trigger'
     */
    if (rtb_RelationalOperator && (rtPrevZCX.EnabledandTriggeredSubsystem_Tr !=
         POS_ZCSIG)) {
      /* DataStoreWrite: '<S8>/Data Store Write' incorporates:
       *  Constant: '<S8>/Constant'
       */
      rtDW.counter_period = 0U;

      /* DataStoreWrite: '<S8>/Data Store Write1' incorporates:
       *  DataStoreRead: '<S8>/Data Store Read1'
       *  Logic: '<S8>/Logical Operator'
       */
      rtDW.LEDSts = !rtDW.LEDSts;
    }

    rtPrevZCX.EnabledandTriggeredSubsystem_Tr = rtb_RelationalOperator;

    /* End of Outputs for SubSystem: '<S6>/Enabled and Triggered Subsystem' */
  }

  /* End of DataStoreRead: '<S3>/Data Store Read2' */
  /* End of Outputs for SubSystem: '<S3>/ToggleLED' */
  /* End of Outputs for RootInportFunctionCallGenerator: '<Root>/RootFcnCall_InsertedFor_TimeToggleLED_at_outport_1' */

  /* Outport: '<Root>/LEDSts_message' */
  Rte_IWrite_TimeToggleLED_LEDSts_message(rtb_DataTypeConversion2);
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
  rtPrevZCX.EnabledandTriggeredSubsystem_Tr = POS_ZCSIG;
  rtPrevZCX.UpdateToggleEnable_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
