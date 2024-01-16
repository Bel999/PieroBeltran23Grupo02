/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestCinematicaz_data.c
 *
 * Code generated for Simulink model 'TestCinematicaz'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Dec 18 12:52:32 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TestCinematicaz.h"

/* Block parameters (default storage) */
P_TestCinematicaz_T TestCinematicaz_P = {
  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S37>/Integral Gain'
   */
  3435.31990354285,

  /* Mask Parameter: PIDController2_I
   * Referenced by: '<S85>/Integral Gain'
   */
  3504.82179305701,

  /* Mask Parameter: PIDController2_InitialCondition
   * Referenced by: '<S88>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S40>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController2_LowerSaturationL
   * Referenced by: '<S95>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by: '<S47>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController2_P
   * Referenced by: '<S93>/Proportional Gain'
   */
  130.691428953154,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S45>/Proportional Gain'
   */
  130.792133824527,

  /* Mask Parameter: PIDController2_UpperSaturationL
   * Referenced by: '<S95>/Saturation'
   */
  255.0,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by: '<S47>/Saturation'
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
   * Referenced by: '<S1>/Constant'
   */
  { 1.0, 1.0, -0.0975, 0.0975 },

  /* Expression: [0.25 2*pi/10]
   * Referenced by: '<Root>/Constant'
   */
  { 0.25, 0.62831853071795862 },

  /* Expression: 0
   * Referenced by: '<S3>/Memory1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S88>/Integrator'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval_k
   * Referenced by: '<S40>/Integrator'
   */
  1.0,

  /* Expression: [1/2 1/2; -1/d 1/d]
   * Referenced by: '<S2>/Constant'
   */
  { 0.5, -5.1282051282051277, 0.5, 5.1282051282051277 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S106>/Gain'
   */
  1217758088,

  /* Computed Parameter: Constant_Value_k
   * Referenced by: '<S108>/Constant'
   */
  0,

  /* Computed Parameter: Constant_Value_jh
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

  /* Computed Parameter: Saturation4_UpperSat
   * Referenced by: '<S107>/Saturation4'
   */
  0,

  /* Computed Parameter: Saturation4_LowerSat
   * Referenced by: '<S107>/Saturation4'
   */
  -255,

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<S107>/Saturation3'
   */
  0,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<S107>/Saturation3'
   */
  -255,

  /* Computed Parameter: Saturation5_UpperSat
   * Referenced by: '<S107>/Saturation5'
   */
  255,

  /* Computed Parameter: Saturation5_LowerSat
   * Referenced by: '<S107>/Saturation5'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
