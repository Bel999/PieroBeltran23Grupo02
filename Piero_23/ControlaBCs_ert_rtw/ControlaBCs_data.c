/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlaBCs_data.c
 *
 * Code generated for Simulink model 'ControlaBCs'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Dec 17 23:20:50 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ControlaBCs.h"

/* Block parameters (default storage) */
P_ControlaBCs_T ControlaBCs_P = {
  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S38>/Integral Gain'
   */
  3489.94967524206,

  /* Mask Parameter: PIDController2_I
   * Referenced by: '<S86>/Integral Gain'
   */
  3540.08522015397,

  /* Mask Parameter: PIDController2_InitialCondition
   * Referenced by: '<S89>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S41>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController2_LowerSaturationL
   * Referenced by: '<S96>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by: '<S48>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController2_P
   * Referenced by: '<S94>/Proportional Gain'
   */
  130.177401298353,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S46>/Proportional Gain'
   */
  129.32617538617,

  /* Mask Parameter: PIDController2_UpperSaturationL
   * Referenced by: '<S96>/Saturation'
   */
  255.0,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by: '<S48>/Saturation'
   */
  255.0,

  /* Expression: -1
   * Referenced by: '<S4>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S4>/Encoder1'
   */
  -1.0,

  /* Expression: [.205 .205]
   * Referenced by: '<Root>/Constant'
   */
  { 0.205, 0.205 },

  /* Expression: 0
   * Referenced by: '<Root>/Memory'
   */
  0.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S4>/Gain'
   */
  1217758088,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S6>/Constant'
   */
  0,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S7>/Constant'
   */
  0,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<S5>/Saturation2'
   */
  255,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<S5>/Saturation2'
   */
  0,

  /* Computed Parameter: Saturation4_UpperSat
   * Referenced by: '<S5>/Saturation4'
   */
  0,

  /* Computed Parameter: Saturation4_LowerSat
   * Referenced by: '<S5>/Saturation4'
   */
  -255,

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<S5>/Saturation3'
   */
  0,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<S5>/Saturation3'
   */
  -255,

  /* Computed Parameter: Saturation5_UpperSat
   * Referenced by: '<S5>/Saturation5'
   */
  255,

  /* Computed Parameter: Saturation5_LowerSat
   * Referenced by: '<S5>/Saturation5'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
