/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled_data.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Dec 17 23:26:18 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"

/* Block parameters (default storage) */
P_untitled_T untitled_P = {
  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S33>/Integral Gain'
   */
  3435.31990354285,

  /* Mask Parameter: PIDController2_I
   * Referenced by: '<S81>/Integral Gain'
   */
  3504.82179305701,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S36>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialCondition
   * Referenced by: '<S84>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by: '<S43>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController2_LowerSaturationL
   * Referenced by: '<S91>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S41>/Proportional Gain'
   */
  130.792133824527,

  /* Mask Parameter: PIDController2_P
   * Referenced by: '<S89>/Proportional Gain'
   */
  130.691428953154,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by: '<S43>/Saturation'
   */
  255.0,

  /* Mask Parameter: PIDController2_UpperSaturationL
   * Referenced by: '<S91>/Saturation'
   */
  255.0,

  /* Expression: -1
   * Referenced by: '<S102>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S102>/Encoder1'
   */
  -1.0,

  /* Expression: [.205 .205]
   * Referenced by: '<Root>/Constant1'
   */
  { 0.205, 0.205 },

  /* Expression: 0
   * Referenced by: '<Root>/Memory1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S36>/Integrator'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval_k
   * Referenced by: '<S84>/Integrator'
   */
  1.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S102>/Gain'
   */
  1217758088,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S104>/Constant'
   */
  0,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S105>/Constant'
   */
  0,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<S103>/Saturation2'
   */
  255,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<S103>/Saturation2'
   */
  0,

  /* Computed Parameter: Saturation4_UpperSat
   * Referenced by: '<S103>/Saturation4'
   */
  0,

  /* Computed Parameter: Saturation4_LowerSat
   * Referenced by: '<S103>/Saturation4'
   */
  -255,

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<S103>/Saturation3'
   */
  0,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<S103>/Saturation3'
   */
  -255,

  /* Computed Parameter: Saturation5_UpperSat
   * Referenced by: '<S103>/Saturation5'
   */
  255,

  /* Computed Parameter: Saturation5_LowerSat
   * Referenced by: '<S103>/Saturation5'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
