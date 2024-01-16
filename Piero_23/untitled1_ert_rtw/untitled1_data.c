/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1_data.c
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Nov 14 19:52:17 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"

/* Block parameters (default storage) */
P_untitled1_T untitled1_P = {
  /* Expression: 0.1
   * Referenced by: '<S3>/Encoder'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S3>/Encoder1'
   */
  0.1,

  /* Expression: [0.205 0.205]
   * Referenced by: '<Root>/Constant'
   */
  { 0.205, 0.205 },

  /* Expression: [-255 -200 -150 -100 -50 0 50 100 150 200 255]
   * Referenced by: '<S1>/CRIzq1'
   */
  { -255.0, -200.0, -150.0, -100.0, -50.0, 0.0, 50.0, 100.0, 150.0, 200.0, 255.0
  },

  /* Expression: [-0.455300360918045 -0.374873638153076 -0.276723057031631 -0.175849363207817 -0.043621104210615 0.029990104958415 0.141770377755165 0.244007378816605 0.339430898427963 0.430762141942978 0.448484838008881]
   * Referenced by: '<S1>/CRIzq1'
   */
  { -0.455300360918045, -0.374873638153076, -0.276723057031631,
    -0.175849363207817, -0.043621104210615, 0.029990104958415, 0.141770377755165,
    0.244007378816605, 0.339430898427963, 0.430762141942978, 0.448484838008881 },

  /* Expression: [-255 -200 -150 -100 -50 0 50 100 150 200 255]
   * Referenced by: '<S1>/CRDere1'
   */
  { -255.0, -200.0, -150.0, -100.0, -50.0, 0.0, 50.0, 100.0, 150.0, 200.0, 255.0
  },

  /* Expression: [-0.443032205104828 -0.363968372344971 -0.268544733524323 -0.171759888529778 -0.044984862208366 0.031352669000626 0.143133535981178 0.245370522141457 0.347609847784042 0.441668003797531 0.458026975393295]
   * Referenced by: '<S1>/CRDere1'
   */
  { -0.443032205104828, -0.363968372344971, -0.268544733524323,
    -0.171759888529778, -0.044984862208366, 0.031352669000626, 0.143133535981178,
    0.245370522141457, 0.347609847784042, 0.441668003797531, 0.458026975393295 },

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S5>/Constant'
   */
  0,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S6>/Constant'
   */
  0,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<S4>/Saturation2'
   */
  255,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<S4>/Saturation2'
   */
  0,

  /* Computed Parameter: Saturation4_UpperSat
   * Referenced by: '<S4>/Saturation4'
   */
  0,

  /* Computed Parameter: Saturation4_LowerSat
   * Referenced by: '<S4>/Saturation4'
   */
  -255,

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<S4>/Saturation3'
   */
  0,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<S4>/Saturation3'
   */
  -255,

  /* Computed Parameter: Saturation5_UpperSat
   * Referenced by: '<S4>/Saturation5'
   */
  255,

  /* Computed Parameter: Saturation5_LowerSat
   * Referenced by: '<S4>/Saturation5'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
