/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: H4_Circuloen10_data.c
 *
 * Code generated for Simulink model 'H4_Circuloen10'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Dec 21 14:42:21 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "H4_Circuloen10.h"

/* Block parameters (default storage) */
P_H4_Circuloen10_T H4_Circuloen10_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S31>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S86>/Integral Gain'
   */
  3.84096189689401,

  /* Mask Parameter: PIDController2_I
   * Referenced by: '<S134>/Integral Gain'
   */
  3.84682949403465,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S34>/Integral Gain'
   */
  26.7375156359397,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S157>/UD'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S32>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_k
   * Referenced by: '<S37>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S89>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController2_InitialCondition
   * Referenced by: '<S137>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by: '<S96>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController2_LowerSaturationL
   * Referenced by: '<S144>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S40>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S42>/Proportional Gain'
   */
  0.662948225062813,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S94>/Proportional Gain'
   */
  334.257306348711,

  /* Mask Parameter: PIDController2_P
   * Referenced by: '<S142>/Proportional Gain'
   */
  336.306510536845,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by: '<S96>/Saturation'
   */
  255.0,

  /* Mask Parameter: PIDController2_UpperSaturationL
   * Referenced by: '<S144>/Saturation'
   */
  255.0,

  /* Expression: -1
   * Referenced by: '<S155>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S155>/Encoder1'
   */
  -1.0,

  /* Expression: [1 -d/2; 1 d/2]
   * Referenced by: '<S3>/Constant'
   */
  { 1.0, 1.0, -0.0975, 0.0975 },

  /* Expression: [0.3]
   * Referenced by: '<Root>/Constant1'
   */
  0.3,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S37>/Integrator'
   */
  0.01,

  /* Expression: [2*pi/10]
   * Referenced by: '<Root>/Constant2'
   */
  0.62831853071795862,

  /* Expression: 0
   * Referenced by: '<Root>/Memory'
   */
  0.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S32>/Filter'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S2>/Memory'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_d
   * Referenced by: '<S89>/Integrator'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_i
   * Referenced by: '<S137>/Integrator'
   */
  0.01,

  /* Expression: [1/2 1/2; -1/d 1/d]
   * Referenced by: '<S4>/Constant'
   */
  { 0.5, -5.1282051282051277, 0.5, 5.1282051282051277 },

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S157>/TSamp'
   */
  100.0,

  /* Expression: [1.0045 1]
   * Referenced by: '<S154>/Gain1'
   */
  { 1.0045, 1.0 },

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S155>/Gain'
   */
  1217758088,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<S158>/Constant'
   */
  0,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S159>/Constant'
   */
  0,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<S156>/Saturation2'
   */
  255,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<S156>/Saturation2'
   */
  0,

  /* Computed Parameter: Saturation4_UpperSat
   * Referenced by: '<S156>/Saturation4'
   */
  0,

  /* Computed Parameter: Saturation4_LowerSat
   * Referenced by: '<S156>/Saturation4'
   */
  -255,

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<S156>/Saturation3'
   */
  0,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<S156>/Saturation3'
   */
  -255,

  /* Computed Parameter: Saturation5_UpperSat
   * Referenced by: '<S156>/Saturation5'
   */
  255,

  /* Computed Parameter: Saturation5_LowerSat
   * Referenced by: '<S156>/Saturation5'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
