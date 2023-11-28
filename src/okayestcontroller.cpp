//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: okayestcontroller.cpp
//
// Code generated for Simulink model 'okayestcontroller'.
//
// Model version                  : 8.3
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Nov 16 10:20:33 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "okayestcontroller.h"
#include "rtwtypes.h"
#include "okayestcontroller_private.h"
#include "okayestcontroller_types.h"

// Block signals (default storage)
B_okayestcontroller_T okayestcontroller_B;

// Block states (default storage)
DW_okayestcontroller_T okayestcontroller_DW;

// Real-time model
RT_MODEL_okayestcontroller_T okayestcontroller_M_ = RT_MODEL_okayestcontroller_T
  ();
RT_MODEL_okayestcontroller_T *const okayestcontroller_M = &okayestcontroller_M_;

//
// Output and update for atomic system:
//    '<Root>/Dead Man's Switch'
//    '<Root>/Dead Man's Switch1'
//    '<Root>/Dead Mn's Switch2'
//
void okayestcontrolle_DeadMansSwitch(boolean_T rtu_IsNew, real_T rtu_value,
  real_T *rty_safeValue, boolean_T *rty_timedOut, real_T rtp_stepSize, real_T
  rtp_timeout, DW_DeadMansSwitch_okayestcont_T *localDW)
{
  boolean_T timedOut;

  // MATLAB Function: '<S2>/timeout set to 0 output' incorporates:
  //   Constant: '<S2>/Simulate step size'
  //   Constant: '<S2>/Timeout in seconds'

  if (!localDW->sinceLastMsg_not_empty) {
    localDW->sinceLastMsg = rtp_timeout / rtp_stepSize + 1.0;
    localDW->sinceLastMsg_not_empty = true;
  }

  *rty_safeValue = 0.0;
  if (rtu_IsNew) {
    localDW->sinceLastMsg = 0.0;
  } else {
    localDW->sinceLastMsg++;
  }

  timedOut = !(localDW->sinceLastMsg < rtp_timeout / rtp_stepSize);
  if (!timedOut) {
    *rty_safeValue = rtu_value;
  }

  *rty_timedOut = timedOut;

  // End of MATLAB Function: '<S2>/timeout set to 0 output'
}

// Model step function
void okayestcontroller_step(void)
{
  SL_Bus_okayestcontroller_std_msgs_Float64 b_varargout_2;
  SL_Bus_okayestcontroller_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_a;
  real_T rtb_safeValue;
  real_T rtb_safeValue_i;
  real_T rtb_y;
  boolean_T b_varargout_1;
  boolean_T rtb_timedOut_k;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S7>/SourceBlock'
  b_varargout_1 = Sub_okayestcontroller_142.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  // Start for MATLABSystem: '<S7>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S13>/In1'
    okayestcontroller_B.In1_j = b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch'
  // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch'
  okayestcontrolle_DeadMansSwitch(b_varargout_1, okayestcontroller_B.In1_j.Data,
    &rtb_safeValue_i, &rtb_timedOut_k,
    okayestcontroller_P.DeadMansSwitch_stepSize,
    okayestcontroller_P.DeadMansSwitch_timeout,
    &okayestcontroller_DW.DeadMansSwitch);

  // End of Start for MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<Root>/Dead Man's Switch'
  // End of Outputs for SubSystem: '<Root>/Dead Man's Switch'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
  // MATLABSystem: '<S9>/SourceBlock'
  b_varargout_1 = Sub_okayestcontroller_144.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S15>/Enable'

  // Start for MATLABSystem: '<S9>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S15>/In1'
    okayestcontroller_B.In1 = b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/Dead Mn's Switch2'
  // Outputs for Atomic SubSystem: '<Root>/Dead Mn's Switch2'
  okayestcontrolle_DeadMansSwitch(b_varargout_1, okayestcontroller_B.In1.Data,
    &rtb_a, &rtb_timedOut_k, okayestcontroller_P.DeadMnsSwitch2_stepSize,
    okayestcontroller_P.DeadMnsSwitch2_timeout,
    &okayestcontroller_DW.DeadMnsSwitch2);

  // End of Start for MATLABSystem: '<S9>/SourceBlock'
  // End of Outputs for SubSystem: '<Root>/Dead Mn's Switch2'
  // End of Outputs for SubSystem: '<Root>/Dead Mn's Switch2'
  // End of Outputs for SubSystem: '<Root>/Subscribe3'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // MATLABSystem: '<S8>/SourceBlock'
  b_varargout_1 = Sub_okayestcontroller_143.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  // Start for MATLABSystem: '<S8>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S14>/In1'
    okayestcontroller_B.In1_p = b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch1'
  // Outputs for Atomic SubSystem: '<Root>/Dead Man's Switch1'
  okayestcontrolle_DeadMansSwitch(b_varargout_1, okayestcontroller_B.In1_p.Data,
    &rtb_safeValue, &rtb_timedOut_k,
    okayestcontroller_P.DeadMansSwitch1_stepSize,
    okayestcontroller_P.DeadMansSwitch1_timeout,
    &okayestcontroller_DW.DeadMansSwitch1);

  // End of Start for MATLABSystem: '<S8>/SourceBlock'
  // End of Outputs for SubSystem: '<Root>/Dead Man's Switch1'
  // End of Outputs for SubSystem: '<Root>/Dead Man's Switch1'
  // End of Outputs for SubSystem: '<Root>/Subscribe2'

  // MATLAB Function: '<Root>/MATLAB Function4'
  rtb_y = 0.0;
  if ((rtb_a != rtb_safeValue_i) && (!(rtb_safeValue / rtb_safeValue_i < 2.0)))
  {
    if (rtb_a > rtb_safeValue_i) {
      rtb_y = (rtb_a - rtb_safeValue_i) / 10.0;
    } else if (rtb_a < rtb_safeValue_i) {
      rtb_y = (rtb_a - rtb_safeValue_i) / 10.0;
    }
  }

  // End of MATLAB Function: '<Root>/MATLAB Function4'

  // Saturate: '<Root>/Saturation'
  if (rtb_y > okayestcontroller_P.Saturation_UpperSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = okayestcontroller_P.Saturation_UpperSat;
  } else if (rtb_y < okayestcontroller_P.Saturation_LowerSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = okayestcontroller_P.Saturation_LowerSat;
  } else {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = rtb_y;
  }

  // End of Saturate: '<Root>/Saturation'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_okayestcontroller_136.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
}

// Model initialize function
void okayestcontroller_initialize(void)
{
  {
    int32_T i;
    char_T b_zeroDelimTopic[17];
    char_T b_zeroDelimTopic_0[15];
    char_T b_zeroDelimTopic_1[11];
    char_T b_zeroDelimTopic_2[10];
    static const char_T b_zeroDelimTopic_3[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_4[15] = "/new_set_speed";
    static const char_T b_zeroDelimTopic_5[11] = "/lead_dist";
    static const char_T b_zeroDelimTopic_6[10] = "cmd_accel";

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
    //   Outport: '<S13>/Out1'

    okayestcontroller_B.In1_j = okayestcontroller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    okayestcontroller_DW.obj_ji.matlabCodegenIsDeleted = false;
    okayestcontroller_DW.obj_ji.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_3[i];
    }

    Sub_okayestcontroller_142.createSubscriber(&b_zeroDelimTopic[0], 1);
    okayestcontroller_DW.obj_ji.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S15>/In1' incorporates:
    //   Outport: '<S15>/Out1'

    okayestcontroller_B.In1 = okayestcontroller_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // Start for MATLABSystem: '<S9>/SourceBlock'
    okayestcontroller_DW.obj_f.matlabCodegenIsDeleted = false;
    okayestcontroller_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_4[i];
    }

    Sub_okayestcontroller_144.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    okayestcontroller_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S14>/In1' incorporates:
    //   Outport: '<S14>/Out1'

    okayestcontroller_B.In1_p = okayestcontroller_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    okayestcontroller_DW.obj_j.matlabCodegenIsDeleted = false;
    okayestcontroller_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_5[i];
    }

    Sub_okayestcontroller_143.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    okayestcontroller_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    okayestcontroller_DW.obj.matlabCodegenIsDeleted = false;
    okayestcontroller_DW.obj.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic_2[i] = b_zeroDelimTopic_6[i];
    }

    Pub_okayestcontroller_136.createPublisher(&b_zeroDelimTopic_2[0], 1);
    okayestcontroller_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void okayestcontroller_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!okayestcontroller_DW.obj_ji.matlabCodegenIsDeleted) {
    okayestcontroller_DW.obj_ji.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!okayestcontroller_DW.obj_f.matlabCodegenIsDeleted) {
    okayestcontroller_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!okayestcontroller_DW.obj_j.matlabCodegenIsDeleted) {
    okayestcontroller_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  if (!okayestcontroller_DW.obj.matlabCodegenIsDeleted) {
    okayestcontroller_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
