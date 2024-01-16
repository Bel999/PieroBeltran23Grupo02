/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ComparaModelos_data.c
 *
 * Code generated for Simulink model 'ComparaModelos'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 30 13:19:10 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ComparaModelos.h"

/* Block parameters (default storage) */
P_ComparaModelos_T ComparaModelos_P = {
  /* Mask Parameter: PIDController_I
   * Referenced by: '<S33>/Integral Gain'
   */
  3646.16120596108,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S81>/Integral Gain'
   */
  3478.80758688549,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S36>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S84>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S41>/Proportional Gain'
   */
  134.078069026327,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S89>/Proportional Gain'
   */
  128.913285858509,

  /* Mask Parameter: PIDController_LowerSaturationLi
   * Referenced by: '<S43>/Saturation'
   */
  -255,

  /* Mask Parameter: PIDController1_LowerSaturationL
   * Referenced by: '<S91>/Saturation'
   */
  -255,

  /* Mask Parameter: PIDController_UpperSaturationLi
   * Referenced by: '<S43>/Saturation'
   */
  255,

  /* Mask Parameter: PIDController1_UpperSaturationL
   * Referenced by: '<S91>/Saturation'
   */
  255,

  /* Expression: 0.5
   * Referenced by: '<S102>/Encoder'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S102>/Encoder1'
   */
  0.5,

  /* Expression: [0.205 0.205]
   * Referenced by: '<Root>/Constant'
   */
  { 0.205, 0.205 },

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Memory'
   */
  0.0,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S104>/Constant'
   */
  0,

  /* Computed Parameter: Saturation4_UpperSat
   * Referenced by: '<S103>/Saturation4'
   */
  0,

  /* Computed Parameter: Saturation4_LowerSat
   * Referenced by: '<S103>/Saturation4'
   */
  -4177920,

  /* Computed Parameter: Saturation5_UpperSat
   * Referenced by: '<S103>/Saturation5'
   */
  4177920,

  /* Computed Parameter: Saturation5_LowerSat
   * Referenced by: '<S103>/Saturation5'
   */
  0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S102>/Gain'
   */
  1199060867,

  /* Computed Parameter: Constant_Value_n
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

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<S103>/Saturation3'
   */
  0,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<S103>/Saturation3'
   */
  -255,

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<S103>/Gain'
   */
  16740
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
