//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: okayestcontroller.h
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
#ifndef RTW_HEADER_okayestcontroller_h_
#define RTW_HEADER_okayestcontroller_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "okayestcontroller_types.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block states (default storage) for system '<Root>/Dead Man's Switch'
struct DW_DeadMansSwitch_okayestcont_T {
  real_T sinceLastMsg;                 // '<S2>/timeout set to 0 output'
  boolean_T sinceLastMsg_not_empty;    // '<S2>/timeout set to 0 output'
};

// Block signals (default storage)
struct B_okayestcontroller_T {
  SL_Bus_okayestcontroller_std_msgs_Float64 In1;// '<S15>/In1'
  SL_Bus_okayestcontroller_std_msgs_Float64 In1_p;// '<S14>/In1'
  SL_Bus_okayestcontroller_std_msgs_Float64 In1_j;// '<S13>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_okayestcontroller_T {
  ros_slroscpp_internal_block_P_T obj; // '<S6>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_f;// '<S9>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_j;// '<S8>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_ji;// '<S7>/SourceBlock'
  DW_DeadMansSwitch_okayestcont_T DeadMnsSwitch2;// '<Root>/Dead Mn's Switch2'
  DW_DeadMansSwitch_okayestcont_T DeadMansSwitch1;// '<Root>/Dead Man's Switch1' 
  DW_DeadMansSwitch_okayestcont_T DeadMansSwitch;// '<Root>/Dead Man's Switch'
};

// Parameters (default storage)
struct P_okayestcontroller_T_ {
  real_T DeadMansSwitch_stepSize;     // Mask Parameter: DeadMansSwitch_stepSize
                                         //  Referenced by: '<Root>/Dead Man's Switch'

  real_T DeadMnsSwitch2_stepSize;     // Mask Parameter: DeadMnsSwitch2_stepSize
                                         //  Referenced by: '<Root>/Dead Mn's Switch2'

  real_T DeadMansSwitch1_stepSize;   // Mask Parameter: DeadMansSwitch1_stepSize
                                        //  Referenced by: '<Root>/Dead Man's Switch1'

  real_T DeadMansSwitch_timeout;       // Mask Parameter: DeadMansSwitch_timeout
                                          //  Referenced by: '<Root>/Dead Man's Switch'

  real_T DeadMnsSwitch2_timeout;       // Mask Parameter: DeadMnsSwitch2_timeout
                                          //  Referenced by: '<Root>/Dead Mn's Switch2'

  real_T DeadMansSwitch1_timeout;     // Mask Parameter: DeadMansSwitch1_timeout
                                         //  Referenced by: '<Root>/Dead Man's Switch1'

  SL_Bus_okayestcontroller_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S1>/Constant'

  SL_Bus_okayestcontroller_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S13>/Out1'

  SL_Bus_okayestcontroller_std_msgs_Float64 Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                                //  Referenced by: '<S7>/Constant'

  SL_Bus_okayestcontroller_std_msgs_Float64 Out1_Y0_l;// Computed Parameter: Out1_Y0_l
                                                         //  Referenced by: '<S14>/Out1'

  SL_Bus_okayestcontroller_std_msgs_Float64 Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                //  Referenced by: '<S8>/Constant'

  SL_Bus_okayestcontroller_std_msgs_Float64 Out1_Y0_o;// Computed Parameter: Out1_Y0_o
                                                         //  Referenced by: '<S15>/Out1'

  SL_Bus_okayestcontroller_std_msgs_Float64 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                //  Referenced by: '<S9>/Constant'

  real_T Saturation_UpperSat;          // Expression: 1.5
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -3
                                          //  Referenced by: '<Root>/Saturation'

};

// Real-time Model Data Structure
struct tag_RTM_okayestcontroller_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_okayestcontroller_T okayestcontroller_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_okayestcontroller_T okayestcontroller_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_okayestcontroller_T okayestcontroller_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void okayestcontroller_initialize(void);
  extern void okayestcontroller_step(void);
  extern void okayestcontroller_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_okayestcontroller_T *const okayestcontroller_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'okayestcontroller'
//  '<S1>'   : 'okayestcontroller/Blank Message'
//  '<S2>'   : 'okayestcontroller/Dead Man's Switch'
//  '<S3>'   : 'okayestcontroller/Dead Man's Switch1'
//  '<S4>'   : 'okayestcontroller/Dead Mn's Switch2'
//  '<S5>'   : 'okayestcontroller/MATLAB Function4'
//  '<S6>'   : 'okayestcontroller/Publish'
//  '<S7>'   : 'okayestcontroller/Subscribe1'
//  '<S8>'   : 'okayestcontroller/Subscribe2'
//  '<S9>'   : 'okayestcontroller/Subscribe3'
//  '<S10>'  : 'okayestcontroller/Dead Man's Switch/timeout set to 0 output'
//  '<S11>'  : 'okayestcontroller/Dead Man's Switch1/timeout set to 0 output'
//  '<S12>'  : 'okayestcontroller/Dead Mn's Switch2/timeout set to 0 output'
//  '<S13>'  : 'okayestcontroller/Subscribe1/Enabled Subsystem'
//  '<S14>'  : 'okayestcontroller/Subscribe2/Enabled Subsystem'
//  '<S15>'  : 'okayestcontroller/Subscribe3/Enabled Subsystem'

#endif                                 // RTW_HEADER_okayestcontroller_h_

//
// File trailer for generated code.
//
// [EOF]
//
