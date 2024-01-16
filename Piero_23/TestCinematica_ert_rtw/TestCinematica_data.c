/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestCinematica_data.c
 *
 * Code generated for Simulink model 'TestCinematica'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 30 15:08:29 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TestCinematica.h"

/* Block parameters (default storage) */
P_TestCinematica_T TestCinematica_P = {
  /* Mask Parameter: PIDController_I
   * Referenced by: '<S37>/Integral Gain'
   */
  3540.08522015397,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S85>/Integral Gain'
   */
  3489.94967524206,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S40>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S88>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S47>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by: '<S95>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S45>/Proportional Gain'
   */
  130.177401298353,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S93>/Proportional Gain'
   */
  129.32617538617,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S47>/Saturation'
   */
  255.0,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by: '<S95>/Saturation'
   */
  255.0,

  /* Expression: -1
   * Referenced by: '<S106>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S106>/Encoder1'
   */
  -1.0,

  /* Expression: [1 -d/2; 1 d/2]
   * Referenced by: '<S2>/Constant'
   */
  { 1.0, 1.0, -0.0975, 0.0975 },

  /* Expression: [0.25 2*pi/10]
   * Referenced by: '<Root>/Constant'
   */
  { 0.25, 0.62831853071795862 },

  /* Expression: 0
   * Referenced by: '<S1>/Memory'
   */
  0.0,

  /* Expression: [1/2 1/2; -1/d 1/d]
   * Referenced by: '<S3>/Constant'
   */
  { 0.5, -5.1282051282051277, 0.5, 5.1282051282051277 },

  /* Expression: 0
   * Referenced by: '<S4>/Integrator'
   */
  0.0,

  /* Computed Parameter: Constant_Value_bh
   * Referenced by: '<S108>/Constant'
   */
  0,

  /* Computed Parameter: Saturation4_UpperSat
   * Referenced by: '<S107>/Saturation4'
   */
  0,

  /* Computed Parameter: Saturation4_LowerSat
   * Referenced by: '<S107>/Saturation4'
   */
  -4177920,

  /* Computed Parameter: Saturation5_UpperSat
   * Referenced by: '<S107>/Saturation5'
   */
  4177920,

  /* Computed Parameter: Saturation5_LowerSat
   * Referenced by: '<S107>/Saturation5'
   */
  0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S106>/Gain'
   */
  1199060867,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S109>/Constant'
   */
  0,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<S107>/Saturation2'
   */
  255,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<S107>/Saturation2'
   */
  0,

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<S107>/Saturation3'
   */
  0,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<S107>/Saturation3'
   */
  -255,

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<S107>/Gain'
   */
  16740
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
