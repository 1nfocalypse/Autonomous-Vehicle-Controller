//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: okayestcontroller.cpp
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
#include "okayestcontroller.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "okayestcontroller_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Block signals (default storage)
B_okayestcontroller_T okayestcontroller_B;

// Block states (default storage)
DW_okayestcontroller_T okayestcontroller_DW;

// Real-time model
RT_MODEL_okayestcontroller_T okayestcontroller_M_ = RT_MODEL_okayestcontroller_T
  ();
RT_MODEL_okayestcontroller_T *const okayestcontroller_M = &okayestcontroller_M_;

// Forward declaration for local functions
static real_T okayestcontroller_ppval(const real_T pp_breaks[101], const coder::
  array<real_T, 2U> &pp_coefs, real_T x);
static void rate_scheduler(void);

//
//         This function updates active task flag for each subrate.
//         The function is called at model base rate, hence the
//         generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (okayestcontroller_M->Timing.TaskCounters.TID[1])++;
  if ((okayestcontroller_M->Timing.TaskCounters.TID[1]) > 1) {// Sample time: [0.1s, 0.0s] 
    okayestcontroller_M->Timing.TaskCounters.TID[1] = 0;
  }
}

// Function for MATLAB Function: '<Root>/mesh gen'
static real_T okayestcontroller_ppval(const real_T pp_breaks[101], const coder::
  array<real_T, 2U> &pp_coefs, real_T x)
{
  real_T v;
  if (rtIsNaN(x)) {
    v = (rtNaN);
  } else {
    int32_T high_i;
    int32_T low_i;
    int32_T low_ip1;
    low_i = 0;
    low_ip1 = 2;
    high_i = 101;
    while (high_i > low_ip1) {
      int32_T mid_i;
      mid_i = ((low_i + high_i) + 1) >> 1;
      if (x >= pp_breaks[mid_i - 1]) {
        low_i = mid_i - 1;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    real_T xloc;
    xloc = x - pp_breaks[low_i];
    v = ((pp_coefs[low_i] * xloc + pp_coefs[low_i + 100]) * xloc +
         pp_coefs[low_i + 200]) * xloc + pp_coefs[low_i + 300];
  }

  return v;
}

// Model step function
void okayestcontroller_step(void)
{
  SL_Bus_okayestcontroller_std_msgs_Float64 b_varargout_2;
  SL_Bus_okayestcontroller_std_msgs_Float64 rtb_BusAssignment;
  real_T xtmp;
  int32_T cpage;
  int32_T j2;
  int32_T yoffset;
  boolean_T has_endslopes;
  static const real_T d[101] = { 0.0, 0.1, 0.2, 0.30000000000000004, 0.4, 0.5,
    0.60000000000000009, 0.70000000000000007, 0.8, 0.9, 1.0, 1.1,
    1.2000000000000002, 1.3, 1.4000000000000001, 1.5, 1.6, 1.7000000000000002,
    1.8, 1.9000000000000001, 2.0, 2.1, 2.2, 2.3000000000000003,
    2.4000000000000004, 2.5, 2.6, 2.7, 2.8000000000000003, 2.9000000000000004,
    3.0, 3.1, 3.2, 3.3000000000000003, 3.4000000000000004, 3.5, 3.6, 3.7,
    3.8000000000000003, 3.9000000000000004, 4.0, 4.1000000000000005, 4.2, 4.3,
    4.4, 4.5, 4.6000000000000005, 4.7, 4.8000000000000007, 4.9, 5.0, 5.1,
    5.1999999999999993, 5.3, 5.3999999999999995, 5.5, 5.6, 5.7, 5.8,
    5.8999999999999995, 6.0, 6.1, 6.1999999999999993, 6.3, 6.4, 6.5, 6.6,
    6.6999999999999993, 6.8, 6.9, 7.0, 7.1, 7.1999999999999993, 7.3, 7.4, 7.5,
    7.6, 7.6999999999999993, 7.8, 7.9, 8.0, 8.1, 8.2, 8.3, 8.4, 8.5, 8.6, 8.7,
    8.8, 8.9, 9.0, 9.1, 9.2, 9.3, 9.4, 9.5, 9.6, 9.7, 9.8, 9.9, 10.0 };

  if (okayestcontroller_M->Timing.TaskCounters.TID[1] == 0) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S3>/SourceBlock'
    has_endslopes = Sub_okayestcontroller_142.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S8>/Enable'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    if (has_endslopes) {
      // SignalConversion generated from: '<S8>/In1'
      okayestcontroller_B.In1_j = b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
    // MATLABSystem: '<S4>/SourceBlock'
    has_endslopes = Sub_okayestcontroller_144.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S9>/Enable'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    if (has_endslopes) {
      // SignalConversion generated from: '<S9>/In1'
      okayestcontroller_B.In1 = b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe3'

    // MATLAB Function: '<Root>/mesh gen'
    okayestcontroller_B.mesh_data.set_size(1, 1000);
    for (yoffset = 0; yoffset < 1000; yoffset++) {
      okayestcontroller_B.mesh_data[yoffset] = 0.0;
    }

    if (okayestcontroller_B.In1.Data > okayestcontroller_B.In1_j.Data) {
      okayestcontroller_B.set_tmp = okayestcontroller_B.In1.Data -
        okayestcontroller_B.In1_j.Data;
      xtmp = okayestcontroller_B.set_tmp / 2.0;
      okayestcontroller_B.mesh_data.set_size(1, 1);
      okayestcontroller_B.mesh_data[0] = xtmp;
      for (j2 = 0; j2 < 50; j2++) {
        xtmp /= 1.1;
        cpage = okayestcontroller_B.mesh_data.size(1);
        okayestcontroller_B.sec_mesh.set_size(1,
          okayestcontroller_B.mesh_data.size(1) + 1);
        okayestcontroller_B.sec_mesh[0] = xtmp;
        for (yoffset = 0; yoffset < cpage; yoffset++) {
          okayestcontroller_B.sec_mesh[yoffset + 1] =
            okayestcontroller_B.mesh_data[yoffset];
        }

        okayestcontroller_B.mesh_data.set_size(1,
          okayestcontroller_B.sec_mesh.size(1));
        cpage = okayestcontroller_B.sec_mesh.size(1);
        for (yoffset = 0; yoffset < cpage; yoffset++) {
          okayestcontroller_B.mesh_data[yoffset] =
            okayestcontroller_B.sec_mesh[yoffset];
        }
      }

      okayestcontroller_B.sec_mesh.set_size(1, 0);
      for (j2 = 0; j2 < 50; j2++) {
        cpage = okayestcontroller_B.sec_mesh.size(1);
        okayestcontroller_B.sec_mesh_m.set_size(1,
          okayestcontroller_B.sec_mesh.size(1) + 1);
        okayestcontroller_B.sec_mesh_m[0] = okayestcontroller_B.set_tmp -
          okayestcontroller_B.mesh_data[j2];
        for (yoffset = 0; yoffset < cpage; yoffset++) {
          okayestcontroller_B.sec_mesh_m[yoffset + 1] =
            okayestcontroller_B.sec_mesh[yoffset];
        }

        okayestcontroller_B.sec_mesh.set_size(1,
          okayestcontroller_B.sec_mesh_m.size(1));
        cpage = okayestcontroller_B.sec_mesh_m.size(1);
        for (yoffset = 0; yoffset < cpage; yoffset++) {
          okayestcontroller_B.sec_mesh[yoffset] =
            okayestcontroller_B.sec_mesh_m[yoffset];
        }
      }

      yoffset = okayestcontroller_B.mesh_data.size(1);
      cpage = okayestcontroller_B.sec_mesh.size(1);
      okayestcontroller_B.mesh_data.set_size(okayestcontroller_B.mesh_data.size
        (0), okayestcontroller_B.mesh_data.size(1) +
        okayestcontroller_B.sec_mesh.size(1));
      for (j2 = 0; j2 < cpage; j2++) {
        okayestcontroller_B.mesh_data[yoffset + j2] =
          okayestcontroller_B.sec_mesh[j2];
      }
    } else if (okayestcontroller_B.In1.Data < okayestcontroller_B.In1_j.Data) {
      okayestcontroller_B.set_tmp = okayestcontroller_B.In1_j.Data -
        okayestcontroller_B.In1.Data;
      xtmp = okayestcontroller_B.set_tmp / 2.0;
      okayestcontroller_B.mesh_data.set_size(1, 1);
      okayestcontroller_B.mesh_data[0] = xtmp;
      for (cpage = 0; cpage < 50; cpage++) {
        xtmp /= 1.1;
        yoffset = okayestcontroller_B.mesh_data.size(1);
        okayestcontroller_B.mesh_data.set_size
          (okayestcontroller_B.mesh_data.size(0),
           okayestcontroller_B.mesh_data.size(1) + 1);
        okayestcontroller_B.mesh_data[yoffset] = xtmp;
      }

      okayestcontroller_B.sec_mesh.set_size(1, 0);
      cpage = okayestcontroller_B.mesh_data.size(1) >> 1;
      for (yoffset = 0; yoffset < cpage; yoffset++) {
        j2 = (okayestcontroller_B.mesh_data.size(1) - yoffset) - 1;
        xtmp = okayestcontroller_B.mesh_data[yoffset];
        okayestcontroller_B.mesh_data[yoffset] =
          okayestcontroller_B.mesh_data[j2];
        okayestcontroller_B.mesh_data[j2] = xtmp;
      }

      for (j2 = 0; j2 < 50; j2++) {
        yoffset = okayestcontroller_B.sec_mesh.size(1);
        okayestcontroller_B.sec_mesh.set_size(okayestcontroller_B.sec_mesh.size
          (0), okayestcontroller_B.sec_mesh.size(1) + 1);
        okayestcontroller_B.sec_mesh[yoffset] = okayestcontroller_B.set_tmp -
          okayestcontroller_B.mesh_data[j2];
      }

      for (yoffset = 0; yoffset < cpage; yoffset++) {
        j2 = (okayestcontroller_B.mesh_data.size(1) - yoffset) - 1;
        okayestcontroller_B.set_tmp = okayestcontroller_B.mesh_data[yoffset];
        okayestcontroller_B.mesh_data[yoffset] =
          okayestcontroller_B.mesh_data[j2];
        okayestcontroller_B.mesh_data[j2] = okayestcontroller_B.set_tmp;
      }

      okayestcontroller_B.sec_mesh_m.set_size(1,
        okayestcontroller_B.sec_mesh.size(1) +
        okayestcontroller_B.mesh_data.size(1));
      cpage = okayestcontroller_B.sec_mesh.size(1);
      for (yoffset = 0; yoffset < cpage; yoffset++) {
        okayestcontroller_B.sec_mesh_m[yoffset] =
          okayestcontroller_B.sec_mesh[yoffset];
      }

      cpage = okayestcontroller_B.mesh_data.size(1);
      for (yoffset = 0; yoffset < cpage; yoffset++) {
        okayestcontroller_B.sec_mesh_m[yoffset +
          okayestcontroller_B.sec_mesh.size(1)] =
          okayestcontroller_B.mesh_data[yoffset];
      }

      okayestcontroller_B.mesh_data.set_size(1,
        okayestcontroller_B.sec_mesh_m.size(1));
      cpage = okayestcontroller_B.sec_mesh_m.size(1);
      for (yoffset = 0; yoffset < cpage; yoffset++) {
        okayestcontroller_B.mesh_data[yoffset] =
          okayestcontroller_B.sec_mesh_m[yoffset];
      }
    }

    has_endslopes = (okayestcontroller_B.mesh_data.size(1) == 103);
    if (has_endslopes) {
      okayestcontroller_B.dvdf.set_size(okayestcontroller_B.dvdf.size(0),
        okayestcontroller_B.mesh_data.size(1) - 3);
      okayestcontroller_B.sec_mesh.set_size(okayestcontroller_B.sec_mesh.size(0),
        okayestcontroller_B.mesh_data.size(1) - 2);
      yoffset = 1;
    } else {
      okayestcontroller_B.dvdf.set_size(okayestcontroller_B.dvdf.size(0),
        okayestcontroller_B.mesh_data.size(1) - 1);
      okayestcontroller_B.sec_mesh.set_size(okayestcontroller_B.sec_mesh.size(0),
        okayestcontroller_B.mesh_data.size(1));
      yoffset = 0;
    }

    okayestcontroller_B.sec_mesh.set_size(1, okayestcontroller_B.sec_mesh.size(1));
    okayestcontroller_B.dvdf.set_size(1, okayestcontroller_B.dvdf.size(1));
    for (cpage = 0; cpage < 100; cpage++) {
      okayestcontroller_B.set_tmp = d[cpage + 1] - d[cpage];
      okayestcontroller_B.dx[cpage] = okayestcontroller_B.set_tmp;
      j2 = yoffset + cpage;
      okayestcontroller_B.dvdf[cpage] = (okayestcontroller_B.mesh_data[j2 + 1] -
        okayestcontroller_B.mesh_data[j2]) / okayestcontroller_B.set_tmp;
    }

    for (cpage = 0; cpage < 99; cpage++) {
      okayestcontroller_B.sec_mesh[cpage + 1] = (okayestcontroller_B.dx[cpage +
        1] * okayestcontroller_B.dvdf[cpage] + okayestcontroller_B.dvdf[cpage +
        1] * okayestcontroller_B.dx[cpage]) * 3.0;
    }

    if (has_endslopes) {
      okayestcontroller_B.set_tmp = 0.0;
      xtmp = 0.0;
      okayestcontroller_B.sec_mesh[0] = okayestcontroller_B.mesh_data[0] *
        okayestcontroller_B.dx[1];
      okayestcontroller_B.sec_mesh[100] = okayestcontroller_B.dx[98] *
        okayestcontroller_B.mesh_data[102];
    } else {
      okayestcontroller_B.set_tmp = 0.2;
      xtmp = 0.19999999999999929;
      okayestcontroller_B.sec_mesh[0] = ((okayestcontroller_B.dx[0] + 0.4) *
        okayestcontroller_B.dx[1] * okayestcontroller_B.dvdf[0] +
        okayestcontroller_B.dx[0] * okayestcontroller_B.dx[0] *
        okayestcontroller_B.dvdf[1]) / 0.2;
      okayestcontroller_B.sec_mesh[100] = ((okayestcontroller_B.dx[99] +
        0.39999999999999858) * okayestcontroller_B.dx[98] *
        okayestcontroller_B.dvdf[99] + okayestcontroller_B.dx[99] *
        okayestcontroller_B.dx[99] * okayestcontroller_B.dvdf[98]) /
        0.19999999999999929;
    }

    okayestcontroller_B.md[0] = okayestcontroller_B.dx[1];
    okayestcontroller_B.md[100] = okayestcontroller_B.dx[98];
    for (cpage = 0; cpage < 99; cpage++) {
      okayestcontroller_B.md[cpage + 1] = (okayestcontroller_B.dx[cpage + 1] +
        okayestcontroller_B.dx[cpage]) * 2.0;
    }

    okayestcontroller_B.r = okayestcontroller_B.dx[1] / okayestcontroller_B.md[0];
    okayestcontroller_B.md[1] -= okayestcontroller_B.r *
      okayestcontroller_B.set_tmp;
    okayestcontroller_B.sec_mesh[1] = okayestcontroller_B.sec_mesh[1] -
      okayestcontroller_B.r * okayestcontroller_B.sec_mesh[0];
    for (cpage = 0; cpage < 98; cpage++) {
      okayestcontroller_B.r = okayestcontroller_B.dx[cpage + 2] /
        okayestcontroller_B.md[cpage + 1];
      okayestcontroller_B.md[cpage + 2] -= okayestcontroller_B.r *
        okayestcontroller_B.dx[cpage];
      okayestcontroller_B.sec_mesh[cpage + 2] =
        okayestcontroller_B.sec_mesh[cpage + 2] -
        okayestcontroller_B.sec_mesh[cpage + 1] * okayestcontroller_B.r;
    }

    okayestcontroller_B.r = xtmp / okayestcontroller_B.md[99];
    okayestcontroller_B.md[100] -= okayestcontroller_B.r *
      okayestcontroller_B.dx[98];
    okayestcontroller_B.sec_mesh[100] = okayestcontroller_B.sec_mesh[100] -
      okayestcontroller_B.r * okayestcontroller_B.sec_mesh[99];
    okayestcontroller_B.sec_mesh[100] = okayestcontroller_B.sec_mesh[100] /
      okayestcontroller_B.md[100];
    for (cpage = 98; cpage >= 0; cpage--) {
      okayestcontroller_B.sec_mesh[cpage + 1] =
        (okayestcontroller_B.sec_mesh[cpage + 1] -
         okayestcontroller_B.sec_mesh[cpage + 2] * okayestcontroller_B.dx[cpage])
        / okayestcontroller_B.md[cpage + 1];
    }

    okayestcontroller_B.sec_mesh[0] = (okayestcontroller_B.sec_mesh[0] -
      okayestcontroller_B.set_tmp * okayestcontroller_B.sec_mesh[1]) /
      okayestcontroller_B.md[0];
    cpage = okayestcontroller_B.sec_mesh.size(1) - 1;
    okayestcontroller_B.pp_coefs.set_size(okayestcontroller_B.sec_mesh.size(1) -
      1, 4);
    for (j2 = 0; j2 < 100; j2++) {
      okayestcontroller_B.dzdxdx = okayestcontroller_B.dvdf[j2];
      okayestcontroller_B.set_tmp = okayestcontroller_B.dx[j2];
      xtmp = okayestcontroller_B.sec_mesh[j2];
      okayestcontroller_B.r = (okayestcontroller_B.dzdxdx - xtmp) /
        okayestcontroller_B.set_tmp;
      okayestcontroller_B.dzdxdx = (okayestcontroller_B.sec_mesh[j2 + 1] -
        okayestcontroller_B.dzdxdx) / okayestcontroller_B.set_tmp;
      okayestcontroller_B.pp_coefs[j2] = (okayestcontroller_B.dzdxdx -
        okayestcontroller_B.r) / okayestcontroller_B.set_tmp;
      okayestcontroller_B.pp_coefs[cpage + j2] = 2.0 * okayestcontroller_B.r -
        okayestcontroller_B.dzdxdx;
      okayestcontroller_B.pp_coefs[(cpage << 1) + j2] = xtmp;
      okayestcontroller_B.pp_coefs[3 * cpage + j2] =
        okayestcontroller_B.mesh_data[yoffset + j2];
    }

    okayestcontroller_B.sec_mesh.set_size(1, 0);
    okayestcontroller_B.set_tmp = 0.0;
    cpage = okayestcontroller_B.mesh_data.size(1);
    for (j2 = 0; j2 < cpage; j2++) {
      yoffset = okayestcontroller_B.sec_mesh.size(1);
      okayestcontroller_B.sec_mesh.set_size(1, okayestcontroller_B.sec_mesh.size
        (1) + 1);
      okayestcontroller_B.sec_mesh[yoffset] = (okayestcontroller_ppval(d,
        okayestcontroller_B.pp_coefs, okayestcontroller_B.set_tmp + 0.1) -
        okayestcontroller_ppval(d, okayestcontroller_B.pp_coefs,
        okayestcontroller_B.set_tmp)) / 0.1;
      okayestcontroller_B.set_tmp += 0.1;
    }

    okayestcontroller_B.y.set_size(1, okayestcontroller_B.sec_mesh.size(1));
    cpage = okayestcontroller_B.sec_mesh.size(1);
    for (yoffset = 0; yoffset < cpage; yoffset++) {
      okayestcontroller_B.y[okayestcontroller_B.y.size(0) * yoffset] =
        okayestcontroller_B.sec_mesh[yoffset];
    }

    // End of MATLAB Function: '<Root>/mesh gen'
  }

  // MATLAB Function: '<Root>/accel_handler' incorporates:
  //   Memory: '<Root>/Memory'

  okayestcontroller_B.set_tmp = okayestcontroller_B.y[static_cast<int32_T>
    (okayestcontroller_DW.Memory_PreviousInput) - 1];

  // Saturate: '<Root>/Saturation'
  if (okayestcontroller_B.set_tmp > okayestcontroller_P.Saturation_UpperSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = okayestcontroller_P.Saturation_UpperSat;
  } else if (okayestcontroller_B.set_tmp <
             okayestcontroller_P.Saturation_LowerSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = okayestcontroller_P.Saturation_LowerSat;
  } else {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = okayestcontroller_B.set_tmp;
  }

  // End of Saturate: '<Root>/Saturation'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S2>/SinkBlock'
  Pub_okayestcontroller_136.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (okayestcontroller_M->Timing.TaskCounters.TID[1] == 0) {
    // MATLAB Function: '<Root>/iterator' incorporates:
    //   Memory: '<Root>/Memory'

    okayestcontroller_B.y_g = okayestcontroller_DW.Memory_PreviousInput;
    if ((okayestcontroller_B.set_tmp != 0.0) &&
        (okayestcontroller_DW.Memory_PreviousInput < 100.0)) {
      okayestcontroller_B.y_g = okayestcontroller_DW.Memory_PreviousInput + 1.0;
    }

    // End of MATLAB Function: '<Root>/iterator'
  }

  // Update for Memory: '<Root>/Memory'
  okayestcontroller_DW.Memory_PreviousInput = okayestcontroller_B.y_g;
  rate_scheduler();
}

// Model initialize function
void okayestcontroller_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic[17];
    char_T b_zeroDelimTopic_0[15];
    char_T b_zeroDelimTopic_1[10];
    static const char_T b_zeroDelimTopic_2[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_3[15] = "/new_set_speed";
    static const char_T b_zeroDelimTopic_4[10] = "cmd_accel";

    // InitializeConditions for Memory: '<Root>/Memory'
    okayestcontroller_DW.Memory_PreviousInput =
      okayestcontroller_P.Memory_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S8>/In1' incorporates:
    //   Outport: '<S8>/Out1'

    okayestcontroller_B.In1_j = okayestcontroller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    okayestcontroller_DW.obj_j.matlabCodegenIsDeleted = false;
    okayestcontroller_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_okayestcontroller_142.createSubscriber(&b_zeroDelimTopic[0], 1);
    okayestcontroller_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S9>/In1' incorporates:
    //   Outport: '<S9>/Out1'

    okayestcontroller_B.In1 = okayestcontroller_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    okayestcontroller_DW.obj_f.matlabCodegenIsDeleted = false;
    okayestcontroller_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_okayestcontroller_144.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    okayestcontroller_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S2>/SinkBlock'
    okayestcontroller_DW.obj.matlabCodegenIsDeleted = false;
    okayestcontroller_DW.obj.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_4[i];
    }

    Pub_okayestcontroller_136.createPublisher(&b_zeroDelimTopic_1[0], 1);
    okayestcontroller_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void okayestcontroller_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!okayestcontroller_DW.obj_j.matlabCodegenIsDeleted) {
    okayestcontroller_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!okayestcontroller_DW.obj_f.matlabCodegenIsDeleted) {
    okayestcontroller_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  if (!okayestcontroller_DW.obj.matlabCodegenIsDeleted) {
    okayestcontroller_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
