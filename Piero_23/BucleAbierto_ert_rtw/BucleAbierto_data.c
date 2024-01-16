/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BucleAbierto_data.c
 *
 * Code generated for Simulink model 'BucleAbierto'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 30 01:15:24 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BucleAbierto.h"

/* Block parameters (default storage) */
P_BucleAbierto_T BucleAbierto_P = {
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S30>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S33>/Integral Gain'
   */
  3540.08522015397,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S81>/Integral Gain'
   */
  3489.94967524206,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S31>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_c
   * Referenced by: '<S36>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S84>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S43>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by: '<S91>/Saturation'
   */
  -255.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S39>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S41>/Proportional Gain'
   */
  130.177401298353,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S89>/Proportional Gain'
   */
  129.32617538617,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S43>/Saturation'
   */
  255.0,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by: '<S91>/Saturation'
   */
  255.0,

  /* Expression: [.205 .205]
   * Referenced by: '<Root>/Constant'
   */
  { 0.205, 0.205 },

  /* Computed Parameter: Rizq_A
   * Referenced by: '<S101>/Rizq'
   */
  -27.194314718577452,

  /* Computed Parameter: Rizq_C
   * Referenced by: '<S101>/Rizq'
   */
  0.054674910172062,

  /* Computed Parameter: Rder_A
   * Referenced by: '<S101>/Rder'
   */
  -26.985640492506871,

  /* Computed Parameter: Rder_C
   * Referenced by: '<S101>/Rder'
   */
  0.055034780864486,

  /* Expression: 0
   * Referenced by: '<Root>/Memory1'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
