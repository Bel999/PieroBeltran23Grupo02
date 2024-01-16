/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Evita_Paredes_Sist_Completo_data.c
 *
 * Code generated for Simulink model 'Evita_Paredes_Sist_Completo'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Nov 12 16:46:18 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Evita_Paredes_Sist_Completo.h"

/* Block parameters (default storage) */
P_Evita_Paredes_Sist_Completo_T Evita_Paredes_Sist_Completo_P = {
  /* Mask Parameter: CompareToConstant3_const
   * Referenced by: '<S9>/Constant'
   */
  26214400U,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S6>/Constant'
   */
  26214400U,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S7>/Constant'
   */
  26214400U,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S8>/Constant'
   */
  26214400U,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S10>/Constant'
   */
  10485760U,

  /* Mask Parameter: CompareToConstant5_const
   * Referenced by: '<S11>/Constant'
   */
  10485760U,

  /* Mask Parameter: BitwiseOperator_BitMask
   * Referenced by: '<S4>/Bitwise Operator'
   */
  1U,

  /* Mask Parameter: BitwiseOperator1_BitMask
   * Referenced by: '<S4>/Bitwise Operator1'
   */
  2U,

  /* Mask Parameter: BitwiseOperator2_BitMask
   * Referenced by: '<S4>/Bitwise Operator2'
   */
  4U,

  /* Mask Parameter: BitwiseOperator3_BitMask
   * Referenced by: '<S4>/Bitwise Operator3'
   */
  8U,

  /* Expression: 0.1
   * Referenced by: '<S3>/Sonar Derecho'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S3>/Sonar Izquierdo'
   */
  0.1,

  /* Expression: 1
   * Referenced by: '<S4>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S4>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<S4>/Pulse Generator'
   */
  2.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<S4>/Pulse Generator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S2>/Gain'
   */
  3221225472U,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S12>/Constant'
   */
  0,

  /* Computed Parameter: Constant_Value_b
   * Referenced by: '<S13>/Constant'
   */
  0,

  /* Computed Parameter: Saturation_UpperSat
   * Referenced by: '<S2>/Saturation'
   */
  80,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S2>/Saturation'
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
  0,

  /* Computed Parameter: Gain_Gain_f
   * Referenced by: '<S3>/Gain'
   */
  51250U,

  /* Computed Parameter: TmpRTBAtSwitchInport2_InitialCo
   * Referenced by:
   */
  false,

  /* Computed Parameter: TmpRTBAtAND1Inport1_InitialCond
   * Referenced by:
   */
  false,

  /* Computed Parameter: TmpRTBAtANDInport1_InitialCondi
   * Referenced by:
   */
  false,

  /* Computed Parameter: TmpRTBAtAND2Inport1_InitialCond
   * Referenced by:
   */
  false
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
