/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: H4_Salir_de_Clase_data.c
 *
 * Code generated for Simulink model 'H4_Salir_de_Clase'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Dec 20 12:04:38 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "H4_Salir_de_Clase.h"

/* Block parameters (default storage) */
P_H4_Salir_de_Clase_T H4_Salir_de_Clase_P = {
  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S87>/Integral Gain'
   */
  3.84096189689401,

  /* Mask Parameter: PIDController2_I
   * Referenced by: '<S135>/Integral Gain'
   */
  3.84682949403465,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S35>/Integral Gain'
   */
  0.247257832491171,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S158>/UD'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S38>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S90>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialCondition
   * Referenced by: '<S138>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by: '<S97>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController2_LowerSaturationL
   * Referenced by: '<S145>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S43>/Proportional Gain'
   */
  5.97692288114371,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S95>/Proportional Gain'
   */
  334.257306348711,

  /* Mask Parameter: PIDController2_P
   * Referenced by: '<S143>/Proportional Gain'
   */
  336.306510536845,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by: '<S97>/Saturation'
   */
  255.0,

  /* Mask Parameter: PIDController2_UpperSaturationL
   * Referenced by: '<S145>/Saturation'
   */
  255.0,

  /* Expression: -1
   * Referenced by: '<S156>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S156>/Encoder1'
   */
  -1.0,

  /* Expression: [1 -d/2; 1 d/2]
   * Referenced by: '<S4>/Constant'
   */
  { 1.0, 1.0, -0.0975, 0.0975 },

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S38>/Integrator'
   */
  0.01,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Memory'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_d
   * Referenced by: '<S90>/Integrator'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_i
   * Referenced by: '<S138>/Integrator'
   */
  0.01,

  /* Expression: [1/2 1/2; -1/d 1/d]
   * Referenced by: '<S5>/Constant'
   */
  { 0.5, -5.1282051282051277, 0.5, 5.1282051282051277 },

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S158>/TSamp'
   */
  100.0,

  /* Expression: [1.0045 1]
   * Referenced by: '<S155>/Gain1'
   */
  { 1.0045, 1.0 },

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S156>/Gain'
   */
  1217758088,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<S159>/Constant'
   */
  0,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S160>/Constant'
   */
  0,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<S157>/Saturation2'
   */
  255,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<S157>/Saturation2'
   */
  0,

  /* Computed Parameter: Saturation4_UpperSat
   * Referenced by: '<S157>/Saturation4'
   */
  0,

  /* Computed Parameter: Saturation4_LowerSat
   * Referenced by: '<S157>/Saturation4'
   */
  -255,

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<S157>/Saturation3'
   */
  0,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<S157>/Saturation3'
   */
  -255,

  /* Computed Parameter: Saturation5_UpperSat
   * Referenced by: '<S157>/Saturation5'
   */
  255,

  /* Computed Parameter: Saturation5_LowerSat
   * Referenced by: '<S157>/Saturation5'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
