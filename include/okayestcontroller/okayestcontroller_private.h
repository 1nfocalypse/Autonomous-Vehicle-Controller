//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: okayestcontroller_private.h
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
#ifndef RTW_HEADER_okayestcontroller_private_h_
#define RTW_HEADER_okayestcontroller_private_h_
#include "rtwtypes.h"
#include "okayestcontroller.h"
#include "okayestcontroller_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

extern void okayestcontrolle_DeadMansSwitch(boolean_T rtu_IsNew, real_T
  rtu_value, real_T *rty_safeValue, boolean_T *rty_timedOut, real_T rtp_stepSize,
  real_T rtp_timeout, DW_DeadMansSwitch_okayestcont_T *localDW);

#endif                               // RTW_HEADER_okayestcontroller_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
