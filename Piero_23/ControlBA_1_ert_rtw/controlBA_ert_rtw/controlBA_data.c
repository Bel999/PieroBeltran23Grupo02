/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controlBA_data.c
 *
 * Code generated for Simulink model 'controlBA'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Nov 15 00:33:25 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controlBA.h"

/* Block parameters (default storage) */
P_controlBA_T controlBA_P = {
  /* Expression: -1
   * Referenced by: '<S3>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S3>/Encoder1'
   */
  -1.0,

  /* Expression: [0.205 0.205]
   * Referenced by: '<Root>/Constant'
   */
  { 0.205, 0.205 },

  /* Expression: pi*0.065/1498
   * Referenced by: '<S3>/Gain'
   */
  0.00013631743823987755,

  /* Expression: [-255 -200 -150 -100 -50 0 50 100 150 200 255]
   * Referenced by: '<S1>/CRIzq1'
   */
  { -255.0, -200.0, -150.0, -100.0, -50.0, 0.0, 50.0, 100.0, 150.0, 200.0, 255.0
  },

  /* Expression: [-0.46346914768219 -0.368067800998688 -0.272638410329819 -0.190837785601616 -0.054527681320906 0 0.109050162136555 0.204469054937363 0.299901068210602 0.381690621376038 0.43621701002121]
   * Referenced by: '<S1>/CRIzq1'
   */
  { -0.46346914768219, -0.368067800998688, -0.272638410329819,
    -0.190837785601616, -0.054527681320906, 0.0, 0.109050162136555,
    0.204469054937363, 0.299901068210602, 0.381690621376038, 0.43621701002121 },

  /* Expression: [-255 -200 -150 -100 -50 0 50 100 150 200 255]
   * Referenced by: '<S1>/CRDere1'
   */
  { -255.0, -200.0, -150.0, -100.0, -50.0, 0.0, 50.0, 100.0, 150.0, 200.0, 255.0
  },

  /* Expression: [-0.449837893247604 -0.368067800998688 -0.272644370794296 -0.177214965224266 -0.081791520118713 0 0.122681431472301 0.218100324273109 0.313526690006256 0.395322233438492 0.449848592281342]
   * Referenced by: '<S1>/CRDere1'
   */
  { -0.449837893247604, -0.368067800998688, -0.272644370794296,
    -0.177214965224266, -0.081791520118713, 0.0, 0.122681431472301,
    0.218100324273109, 0.313526690006256, 0.395322233438492, 0.449848592281342 },

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S5>/Constant'
   */
  0,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S6>/Constant'
   */
  0,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<S4>/Saturation2'
   */
  255,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<S4>/Saturation2'
   */
  0,

  /* Computed Parameter: Saturation4_UpperSat
   * Referenced by: '<S4>/Saturation4'
   */
  0,

  /* Computed Parameter: Saturation4_LowerSat
   * Referenced by: '<S4>/Saturation4'
   */
  -255,

  /* Computed Parameter: Saturation3_UpperSat
   * Referenced by: '<S4>/Saturation3'
   */
  0,

  /* Computed Parameter: Saturation3_LowerSat
   * Referenced by: '<S4>/Saturation3'
   */
  -255,

  /* Computed Parameter: Saturation5_UpperSat
   * Referenced by: '<S4>/Saturation5'
   */
  255,

  /* Computed Parameter: Saturation5_LowerSat
   * Referenced by: '<S4>/Saturation5'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
