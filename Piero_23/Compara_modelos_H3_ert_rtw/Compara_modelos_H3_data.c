/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Compara_modelos_H3_data.c
 *
 * Code generated for Simulink model 'Compara_modelos_H3'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 30 01:09:28 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Compara_modelos_H3.h"

/* Block parameters (default storage) */
P_Compara_modelos_H3_T Compara_modelos_H3_P = {
  /* Expression: -1
   * Referenced by: '<S3>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S3>/Encoder1'
   */
  -1.0,

  /* Computed Parameter: Rizq_A
   * Referenced by: '<S1>/Rizq'
   */
  -27.194314718577452,

  /* Computed Parameter: Rizq_C
   * Referenced by: '<S1>/Rizq'
   */
  0.054674910172062,

  /* Computed Parameter: Rder_A
   * Referenced by: '<S1>/Rder'
   */
  -26.985640492506871,

  /* Computed Parameter: Rder_C
   * Referenced by: '<S1>/Rder'
   */
  0.055034780864486,

  /* Expression: [0.205 0.205]
   * Referenced by: '<Root>/Constant'
   */
  { 0.205, 0.205 },

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S5>/Constant'
   */
  0,

  /* Computed Parameter: Saturation4_UpperSat
   * Referenced by: '<S4>/Saturation4'
   */
  0,

  /* Computed Parameter: Saturation4_LowerSat
   * Referenced by: '<S4>/Saturation4'
   */
  -4177920,

  /* Computed Parameter: Saturation5_UpperSat
   * Referenced by: '<S4>/Saturation5'
   */
  4177920,

  /* Computed Parameter: Saturation5_LowerSat
   * Referenced by: '<S4>/Saturation5'
   */
  0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S3>/Gain'
   */
  1199060867,

  /* Computed Parameter: Constant_Value_p
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

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<S4>/Saturation3'
   */
  0,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<S4>/Saturation3'
   */
  -255,

  /* Computed Parameter: Gain_Gain_f
   * Referenced by: '<S4>/Gain'
   */
  16740
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
