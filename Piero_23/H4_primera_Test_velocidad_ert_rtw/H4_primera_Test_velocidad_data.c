/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: H4_primera_Test_velocidad_data.c
 *
 * Code generated for Simulink model 'H4_primera_Test_velocidad'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Dec 19 22:03:41 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "H4_primera_Test_velocidad.h"

/* Block parameters (default storage) */
P_H4_primera_Test_velocidad_T H4_primera_Test_velocidad_P = {
  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S36>/Integral Gain'
   */
  3.84096189689401,

  /* Mask Parameter: PIDController2_I
   * Referenced by: '<S84>/Integral Gain'
   */
  3.93378266743256,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S39>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialCondition
   * Referenced by: '<S87>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by: '<S46>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController2_LowerSaturationL
   * Referenced by: '<S94>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S44>/Proportional Gain'
   */
  334.257306348711,

  /* Mask Parameter: PIDController2_P
   * Referenced by: '<S92>/Proportional Gain'
   */
  340.087321376942,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by: '<S46>/Saturation'
   */
  255.0,

  /* Mask Parameter: PIDController2_UpperSaturationL
   * Referenced by: '<S94>/Saturation'
   */
  255.0,

  /* Expression: -1
   * Referenced by: '<S105>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S105>/Encoder1'
   */
  -1.0,

  /* Expression: [1.1 1.1]
   * Referenced by: '<Root>/Constant'
   */
  { 1.1, 1.1 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S2>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S39>/Integrator'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_o
   * Referenced by: '<S87>/Integrator'
   */
  0.01,

  /* Expression: [1 1]
   * Referenced by: '<S104>/Gain1'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S105>/Gain'
   */
  1217758088,

  /* Computed Parameter: Constant_Value_k
   * Referenced by: '<S108>/Constant'
   */
  0,

  /* Computed Parameter: Constant_Value_j
   * Referenced by: '<S109>/Constant'
   */
  0,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<S106>/Saturation2'
   */
  255,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<S106>/Saturation2'
   */
  0,

  /* Computed Parameter: Saturation4_UpperSat
   * Referenced by: '<S106>/Saturation4'
   */
  0,

  /* Computed Parameter: Saturation4_LowerSat
   * Referenced by: '<S106>/Saturation4'
   */
  -255,

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<S106>/Saturation3'
   */
  0,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<S106>/Saturation3'
   */
  -255,

  /* Computed Parameter: Saturation5_UpperSat
   * Referenced by: '<S106>/Saturation5'
   */
  255,

  /* Computed Parameter: Saturation5_LowerSat
   * Referenced by: '<S106>/Saturation5'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
