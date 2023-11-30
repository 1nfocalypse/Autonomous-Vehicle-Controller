//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: okayestcontroller.h
//
// Code generated for Simulink model 'okayestcontroller'.
//
// Model version                  : 8.6
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Nov 29 23:36:51 2023
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
#include "coder_array.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_okayestcontroller_T {
  coder::array<real_T,2> mesh_data;
  coder::array<real_T,2> sec_mesh;
  coder::array<real_T,2> pp_coefs;
  coder::array<real_T,2> dvdf;
  coder::array<real_T,2> sec_mesh_m;
  real_T md[101];
  real_T dx[100];
  coder::array<real_T,2> y;            // '<Root>/mesh gen'
  real_T y_g;                          // '<Root>/iterator'
  real_T set_tmp;
  real_T r;
  real_T dzdxdx;
  SL_Bus_okayestcontroller_std_msgs_Float64 In1;// '<S9>/In1'
  SL_Bus_okayestcontroller_std_msgs_Float64 In1_j;// '<S8>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_okayestcontroller_T {
  ros_slroscpp_internal_block_P_T obj; // '<S2>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_f;// '<S4>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_j;// '<S3>/SourceBlock'
  real_T Memory_PreviousInput;         // '<Root>/Memory'
};

// Parameters (default storage)
struct P_okayestcontroller_T_ {
  SL_Bus_okayestcontroller_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S1>/Constant'

  SL_Bus_okayestcontroller_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S8>/Out1'

  SL_Bus_okayestcontroller_std_msgs_Float64 Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                                //  Referenced by: '<S3>/Constant'

  SL_Bus_okayestcontroller_std_msgs_Float64 Out1_Y0_o;// Computed Parameter: Out1_Y0_o
                                                         //  Referenced by: '<S9>/Out1'

  SL_Bus_okayestcontroller_std_msgs_Float64 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                //  Referenced by: '<S4>/Constant'

  real_T Memory_InitialCondition;      // Expression: 1
                                          //  Referenced by: '<Root>/Memory'

  real_T Saturation_UpperSat;          // Expression: 1.5
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -3
                                          //  Referenced by: '<Root>/Saturation'

};

// Real-time Model Data Structure
struct tag_RTM_okayestcontroller_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
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
//  '<S2>'   : 'okayestcontroller/Publish'
//  '<S3>'   : 'okayestcontroller/Subscribe1'
//  '<S4>'   : 'okayestcontroller/Subscribe3'
//  '<S5>'   : 'okayestcontroller/accel_handler'
//  '<S6>'   : 'okayestcontroller/iterator'
//  '<S7>'   : 'okayestcontroller/mesh gen'
//  '<S8>'   : 'okayestcontroller/Subscribe1/Enabled Subsystem'
//  '<S9>'   : 'okayestcontroller/Subscribe3/Enabled Subsystem'

#endif                                 // RTW_HEADER_okayestcontroller_h_

//
// File trailer for generated code.
//
// [EOF]
//
