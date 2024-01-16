/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: H4_Circuloen10.c
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
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "H4_Circuloen10_private.h"

/* Block states (default storage) */
DW_H4_Circuloen10_T H4_Circuloen10_DW;

/* Real-time model */
static RT_MODEL_H4_Circuloen10_T H4_Circuloen10_M_;
RT_MODEL_H4_Circuloen10_T *const H4_Circuloen10_M = &H4_Circuloen10_M_;

/* Model step function */
void H4_Circuloen10_step(void)
{
  real_T rtb_FilterCoefficient;
  real_T rtb_Gain_idx_0;
  real_T rtb_Gain_idx_1;
  real_T rtb_Sum_p;
  real_T rtb_TSamp_idx_0;
  real_T rtb_TSamp_idx_1;
  int32_T rtb_Encoder1_0;
  int32_T rtb_Encoder_0;
  int16_T rtb_DataTypeConversion_idx_0;
  int16_T rtb_DataTypeConversion_idx_1;
  int16_T y;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Memory: '<Root>/Memory'
   */
  rtb_Sum_p = H4_Circuloen10_P.Constant2_Value -
    H4_Circuloen10_DW.Memory_PreviousInput;

  /* Gain: '<S40>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S32>/Filter'
   *  Gain: '<S31>/Derivative Gain'
   *  Sum: '<S32>/SumD'
   */
  rtb_FilterCoefficient = (H4_Circuloen10_P.PIDController_D * rtb_Sum_p -
    H4_Circuloen10_DW.Filter_DSTATE) * H4_Circuloen10_P.PIDController_N;

  /* SignalConversion generated from: '<S3>/Matrix Multiply' incorporates:
   *  DiscreteIntegrator: '<S37>/Integrator'
   *  Gain: '<S42>/Proportional Gain'
   *  Sum: '<S46>/Sum'
   */
  rtb_Gain_idx_1 = (H4_Circuloen10_P.PIDController_P * rtb_Sum_p +
                    H4_Circuloen10_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S3>/Constant'
   *  Memory: '<S2>/Memory'
   *  Product: '<S3>/Matrix Multiply'
   */
  rtb_Gain_idx_0 = (H4_Circuloen10_P.Constant_Value[0] *
                    H4_Circuloen10_P.Constant1_Value +
                    H4_Circuloen10_P.Constant_Value[2] * rtb_Gain_idx_1) -
    H4_Circuloen10_DW.Memory_PreviousInput_f[0];
  rtb_Gain_idx_1 = (H4_Circuloen10_P.Constant_Value[1] *
                    H4_Circuloen10_P.Constant1_Value +
                    H4_Circuloen10_P.Constant_Value[3] * rtb_Gain_idx_1) -
    H4_Circuloen10_DW.Memory_PreviousInput_f[1];

  /* Sum: '<S146>/Sum' incorporates:
   *  DiscreteIntegrator: '<S137>/Integrator'
   *  Gain: '<S142>/Proportional Gain'
   */
  rtb_TSamp_idx_0 = H4_Circuloen10_P.PIDController2_P * rtb_Gain_idx_0 +
    H4_Circuloen10_DW.Integrator_DSTATE_he;

  /* Saturate: '<S144>/Saturation' */
  if (rtb_TSamp_idx_0 > H4_Circuloen10_P.PIDController2_UpperSaturationL) {
    rtb_TSamp_idx_0 = H4_Circuloen10_P.PIDController2_UpperSaturationL;
  } else if (rtb_TSamp_idx_0 < H4_Circuloen10_P.PIDController2_LowerSaturationL)
  {
    rtb_TSamp_idx_0 = H4_Circuloen10_P.PIDController2_LowerSaturationL;
  }

  /* DataTypeConversion: '<S55>/Data Type Conversion' incorporates:
   *  Saturate: '<S144>/Saturation'
   */
  rtb_TSamp_idx_0 = floor(rtb_TSamp_idx_0);
  if (rtIsNaN(rtb_TSamp_idx_0) || rtIsInf(rtb_TSamp_idx_0)) {
    rtb_TSamp_idx_0 = 0.0;
  } else {
    rtb_TSamp_idx_0 = fmod(rtb_TSamp_idx_0, 65536.0);
  }

  rtb_DataTypeConversion_idx_0 = rtb_TSamp_idx_0 < 0.0 ? -(int16_T)(uint16_T)
    -rtb_TSamp_idx_0 : (int16_T)(uint16_T)rtb_TSamp_idx_0;

  /* Sum: '<S98>/Sum' incorporates:
   *  DiscreteIntegrator: '<S89>/Integrator'
   *  Gain: '<S94>/Proportional Gain'
   */
  rtb_TSamp_idx_0 = H4_Circuloen10_P.PIDController1_P * rtb_Gain_idx_1 +
    H4_Circuloen10_DW.Integrator_DSTATE_h;

  /* Saturate: '<S96>/Saturation' */
  if (rtb_TSamp_idx_0 > H4_Circuloen10_P.PIDController1_UpperSaturationL) {
    rtb_TSamp_idx_0 = H4_Circuloen10_P.PIDController1_UpperSaturationL;
  } else if (rtb_TSamp_idx_0 < H4_Circuloen10_P.PIDController1_LowerSaturationL)
  {
    rtb_TSamp_idx_0 = H4_Circuloen10_P.PIDController1_LowerSaturationL;
  }

  /* DataTypeConversion: '<S55>/Data Type Conversion' incorporates:
   *  Saturate: '<S96>/Saturation'
   */
  rtb_TSamp_idx_0 = floor(rtb_TSamp_idx_0);
  if (rtIsNaN(rtb_TSamp_idx_0) || rtIsInf(rtb_TSamp_idx_0)) {
    rtb_TSamp_idx_0 = 0.0;
  } else {
    rtb_TSamp_idx_0 = fmod(rtb_TSamp_idx_0, 65536.0);
  }

  rtb_DataTypeConversion_idx_1 = rtb_TSamp_idx_0 < 0.0 ? -(int16_T)(uint16_T)
    -rtb_TSamp_idx_0 : (int16_T)(uint16_T)rtb_TSamp_idx_0;

  /* MATLABSystem: '<S156>/Adelante_der' */
  H4_Circuloen10_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

  /* Saturate: '<S156>/Saturation2' */
  if (rtb_DataTypeConversion_idx_1 > H4_Circuloen10_P.Saturation2_UpperSat) {
    y = H4_Circuloen10_P.Saturation2_UpperSat;
  } else if (rtb_DataTypeConversion_idx_1 <
             H4_Circuloen10_P.Saturation2_LowerSat) {
    y = H4_Circuloen10_P.Saturation2_LowerSat;
  } else {
    y = rtb_DataTypeConversion_idx_1;
  }

  /* End of Saturate: '<S156>/Saturation2' */

  /* Start for MATLABSystem: '<S156>/Adelante_der' */
  if (y > 255) {
    y = 255;
  }

  if (y < 0) {
    y = 0;
  }

  /* MATLABSystem: '<S156>/Adelante_der' */
  MW_PWM_SetDutyCycle(H4_Circuloen10_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)y);

  /* MATLABSystem: '<S156>/Adelante_izq' */
  H4_Circuloen10_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

  /* Saturate: '<S156>/Saturation4' */
  if (rtb_DataTypeConversion_idx_0 > H4_Circuloen10_P.Saturation4_UpperSat) {
    y = H4_Circuloen10_P.Saturation4_UpperSat;
  } else if (rtb_DataTypeConversion_idx_0 <
             H4_Circuloen10_P.Saturation4_LowerSat) {
    y = H4_Circuloen10_P.Saturation4_LowerSat;
  } else {
    y = rtb_DataTypeConversion_idx_0;
  }

  /* End of Saturate: '<S156>/Saturation4' */

  /* Abs: '<S156>/Abs2' */
  if (y < 0) {
    y = -y;
  }

  /* End of Abs: '<S156>/Abs2' */

  /* Start for MATLABSystem: '<S156>/Adelante_izq' */
  if (y > 255) {
    y = 255;
  }

  if (y < 0) {
    y = 0;
  }

  /* MATLABSystem: '<S156>/Adelante_izq' */
  MW_PWM_SetDutyCycle(H4_Circuloen10_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)y);

  /* MATLABSystem: '<S156>/Atras_der' */
  H4_Circuloen10_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

  /* Saturate: '<S156>/Saturation3' */
  if (rtb_DataTypeConversion_idx_1 > H4_Circuloen10_P.Saturation3_UpperSat) {
    y = H4_Circuloen10_P.Saturation3_UpperSat;
  } else if (rtb_DataTypeConversion_idx_1 <
             H4_Circuloen10_P.Saturation3_LowerSat) {
    y = H4_Circuloen10_P.Saturation3_LowerSat;
  } else {
    y = rtb_DataTypeConversion_idx_1;
  }

  /* End of Saturate: '<S156>/Saturation3' */

  /* Abs: '<S156>/Abs1' */
  if (y < 0) {
    y = -y;
  }

  /* End of Abs: '<S156>/Abs1' */

  /* Start for MATLABSystem: '<S156>/Atras_der' */
  if (y > 255) {
    y = 255;
  }

  if (y < 0) {
    y = 0;
  }

  /* MATLABSystem: '<S156>/Atras_der' */
  MW_PWM_SetDutyCycle(H4_Circuloen10_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)y);

  /* MATLABSystem: '<S156>/Atras_izq' */
  H4_Circuloen10_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

  /* Saturate: '<S156>/Saturation5' */
  if (rtb_DataTypeConversion_idx_0 > H4_Circuloen10_P.Saturation5_UpperSat) {
    y = H4_Circuloen10_P.Saturation5_UpperSat;
  } else if (rtb_DataTypeConversion_idx_0 <
             H4_Circuloen10_P.Saturation5_LowerSat) {
    y = H4_Circuloen10_P.Saturation5_LowerSat;
  } else {
    y = rtb_DataTypeConversion_idx_0;
  }

  /* End of Saturate: '<S156>/Saturation5' */

  /* Start for MATLABSystem: '<S156>/Atras_izq' */
  if (y > 255) {
    y = 255;
  }

  if (y < 0) {
    y = 0;
  }

  /* MATLABSystem: '<S156>/Atras_izq' */
  MW_PWM_SetDutyCycle(H4_Circuloen10_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)y);

  /* MATLABSystem: '<S156>/Digital Output' incorporates:
   *  Constant: '<S158>/Constant'
   *  RelationalOperator: '<S158>/Compare'
   */
  writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
    H4_Circuloen10_P.Constant_Value_c));

  /* MATLABSystem: '<S156>/Digital Output1' incorporates:
   *  Constant: '<S159>/Constant'
   *  RelationalOperator: '<S159>/Compare'
   */
  writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
    H4_Circuloen10_P.Constant_Value_d));

  /* MATLABSystem: '<S155>/Encoder' */
  if (H4_Circuloen10_DW.obj_p.SampleTime != H4_Circuloen10_P.Encoder_SampleTime)
  {
    H4_Circuloen10_DW.obj_p.SampleTime = H4_Circuloen10_P.Encoder_SampleTime;
  }

  if (H4_Circuloen10_DW.obj_p.TunablePropsChanged) {
    H4_Circuloen10_DW.obj_p.TunablePropsChanged = false;
  }

  MW_EncoderRead(H4_Circuloen10_DW.obj_p.Index, &rtb_Encoder_0);

  /* MATLABSystem: '<S155>/Encoder1' */
  if (H4_Circuloen10_DW.obj.SampleTime != H4_Circuloen10_P.Encoder1_SampleTime)
  {
    H4_Circuloen10_DW.obj.SampleTime = H4_Circuloen10_P.Encoder1_SampleTime;
  }

  if (H4_Circuloen10_DW.obj.TunablePropsChanged) {
    H4_Circuloen10_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(H4_Circuloen10_DW.obj.Index, &rtb_Encoder1_0);

  /* Gain: '<S155>/Gain' */
  rtb_TSamp_idx_1 = (real_T)H4_Circuloen10_P.Gain_Gain * 1.1368683772161603E-13;

  /* SampleTimeMath: '<S157>/TSamp' incorporates:
   *  Gain: '<S155>/Gain'
   *  MATLABSystem: '<S155>/Encoder'
   *  MATLABSystem: '<S155>/Encoder1'
   *
   * About '<S157>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_idx_0 = rtb_TSamp_idx_1 * (real_T)rtb_Encoder_0 *
    H4_Circuloen10_P.TSamp_WtEt;
  rtb_TSamp_idx_1 = rtb_TSamp_idx_1 * (real_T)rtb_Encoder1_0 *
    H4_Circuloen10_P.TSamp_WtEt;

  /* Gain: '<S154>/Gain1' incorporates:
   *  Sum: '<S157>/Diff'
   *  UnitDelay: '<S157>/UD'
   *
   * Block description for '<S157>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S157>/UD':
   *
   *  Store in Global RAM
   */
  H4_Circuloen10_DW.Memory_PreviousInput_f[0] = (rtb_TSamp_idx_0 -
    H4_Circuloen10_DW.UD_DSTATE[0]) * H4_Circuloen10_P.Gain1_Gain[0];
  H4_Circuloen10_DW.Memory_PreviousInput_f[1] = (rtb_TSamp_idx_1 -
    H4_Circuloen10_DW.UD_DSTATE[1]) * H4_Circuloen10_P.Gain1_Gain[1];

  /* Update for DiscreteIntegrator: '<S37>/Integrator' incorporates:
   *  Gain: '<S34>/Integral Gain'
   */
  H4_Circuloen10_DW.Integrator_DSTATE += H4_Circuloen10_P.PIDController_I *
    rtb_Sum_p * H4_Circuloen10_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S32>/Filter' */
  H4_Circuloen10_DW.Filter_DSTATE += H4_Circuloen10_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S89>/Integrator' incorporates:
   *  Gain: '<S86>/Integral Gain'
   */
  H4_Circuloen10_DW.Integrator_DSTATE_h += H4_Circuloen10_P.PIDController1_I *
    rtb_Gain_idx_1 * H4_Circuloen10_P.Integrator_gainval_d;

  /* Update for DiscreteIntegrator: '<S137>/Integrator' incorporates:
   *  Gain: '<S134>/Integral Gain'
   */
  H4_Circuloen10_DW.Integrator_DSTATE_he += H4_Circuloen10_P.PIDController2_I *
    rtb_Gain_idx_0 * H4_Circuloen10_P.Integrator_gainval_i;

  /* Update for UnitDelay: '<S157>/UD'
   *
   * Block description for '<S157>/UD':
   *
   *  Store in Global RAM
   */
  H4_Circuloen10_DW.UD_DSTATE[0] = rtb_TSamp_idx_0;
  H4_Circuloen10_DW.UD_DSTATE[1] = rtb_TSamp_idx_1;

  /* Update for Memory: '<Root>/Memory' incorporates:
   *  Constant: '<S4>/Constant'
   *  Product: '<S4>/Matrix Multiply'
   */
  H4_Circuloen10_DW.Memory_PreviousInput =
    H4_Circuloen10_DW.Memory_PreviousInput_f[0] *
    H4_Circuloen10_P.Constant_Value_b[1] +
    H4_Circuloen10_DW.Memory_PreviousInput_f[1] *
    H4_Circuloen10_P.Constant_Value_b[3];
}

/* Model initialize function */
void H4_Circuloen10_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for DiscreteIntegrator: '<S37>/Integrator' */
  H4_Circuloen10_DW.Integrator_DSTATE =
    H4_Circuloen10_P.PIDController_InitialConditio_k;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  H4_Circuloen10_DW.Memory_PreviousInput =
    H4_Circuloen10_P.Memory_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/Filter' */
  H4_Circuloen10_DW.Filter_DSTATE =
    H4_Circuloen10_P.PIDController_InitialConditionF;

  /* InitializeConditions for DiscreteIntegrator: '<S89>/Integrator' */
  H4_Circuloen10_DW.Integrator_DSTATE_h =
    H4_Circuloen10_P.PIDController1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S137>/Integrator' */
  H4_Circuloen10_DW.Integrator_DSTATE_he =
    H4_Circuloen10_P.PIDController2_InitialCondition;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  H4_Circuloen10_DW.Memory_PreviousInput_f[0] =
    H4_Circuloen10_P.Memory_InitialCondition_h;

  /* InitializeConditions for UnitDelay: '<S157>/UD'
   *
   * Block description for '<S157>/UD':
   *
   *  Store in Global RAM
   */
  H4_Circuloen10_DW.UD_DSTATE[0] =
    H4_Circuloen10_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  H4_Circuloen10_DW.Memory_PreviousInput_f[1] =
    H4_Circuloen10_P.Memory_InitialCondition_h;

  /* InitializeConditions for UnitDelay: '<S157>/UD'
   *
   * Block description for '<S157>/UD':
   *
   *  Store in Global RAM
   */
  H4_Circuloen10_DW.UD_DSTATE[1] =
    H4_Circuloen10_P.DiscreteDerivative_ICPrevScaled;

  /* Start for MATLABSystem: '<S156>/Adelante_der' */
  H4_Circuloen10_DW.obj_b.matlabCodegenIsDeleted = false;
  H4_Circuloen10_DW.obj_b.isInitialized = 1L;
  H4_Circuloen10_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0,
    0.0);
  H4_Circuloen10_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S156>/Adelante_izq' */
  H4_Circuloen10_DW.obj_j.matlabCodegenIsDeleted = false;
  H4_Circuloen10_DW.obj_j.isInitialized = 1L;
  H4_Circuloen10_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  H4_Circuloen10_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S156>/Atras_der' */
  H4_Circuloen10_DW.obj_e.matlabCodegenIsDeleted = false;
  H4_Circuloen10_DW.obj_e.isInitialized = 1L;
  H4_Circuloen10_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  H4_Circuloen10_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S156>/Atras_izq' */
  H4_Circuloen10_DW.obj_g.matlabCodegenIsDeleted = false;
  H4_Circuloen10_DW.obj_g.isInitialized = 1L;
  H4_Circuloen10_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0,
    0.0);
  H4_Circuloen10_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S156>/Digital Output' */
  H4_Circuloen10_DW.obj_pi.matlabCodegenIsDeleted = false;
  H4_Circuloen10_DW.obj_pi.isInitialized = 1L;
  digitalIOSetup(8, 1);
  H4_Circuloen10_DW.obj_pi.isSetupComplete = true;

  /* Start for MATLABSystem: '<S156>/Digital Output1' */
  H4_Circuloen10_DW.obj_m.matlabCodegenIsDeleted = false;
  H4_Circuloen10_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(13, 1);
  H4_Circuloen10_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S155>/Encoder' */
  H4_Circuloen10_DW.obj_p.Index = 0U;
  H4_Circuloen10_DW.obj_p.matlabCodegenIsDeleted = false;
  H4_Circuloen10_DW.obj_p.SampleTime = H4_Circuloen10_P.Encoder_SampleTime;
  H4_Circuloen10_DW.obj_p.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &H4_Circuloen10_DW.obj_p.Index);
  H4_Circuloen10_DW.obj_p.isSetupComplete = true;
  H4_Circuloen10_DW.obj_p.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S155>/Encoder' */
  MW_EncoderReset(H4_Circuloen10_DW.obj_p.Index);

  /* Start for MATLABSystem: '<S155>/Encoder1' */
  H4_Circuloen10_DW.obj.Index = 0U;
  H4_Circuloen10_DW.obj.matlabCodegenIsDeleted = false;
  H4_Circuloen10_DW.obj.SampleTime = H4_Circuloen10_P.Encoder1_SampleTime;
  H4_Circuloen10_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &H4_Circuloen10_DW.obj.Index);
  H4_Circuloen10_DW.obj.isSetupComplete = true;
  H4_Circuloen10_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S155>/Encoder1' */
  MW_EncoderReset(H4_Circuloen10_DW.obj.Index);
}

/* Model terminate function */
void H4_Circuloen10_terminate(void)
{
  /* Terminate for MATLABSystem: '<S156>/Adelante_der' */
  if (!H4_Circuloen10_DW.obj_b.matlabCodegenIsDeleted) {
    H4_Circuloen10_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((H4_Circuloen10_DW.obj_b.isInitialized == 1L) &&
        H4_Circuloen10_DW.obj_b.isSetupComplete) {
      H4_Circuloen10_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle(H4_Circuloen10_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      H4_Circuloen10_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_Close(H4_Circuloen10_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S156>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S156>/Adelante_izq' */
  if (!H4_Circuloen10_DW.obj_j.matlabCodegenIsDeleted) {
    H4_Circuloen10_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((H4_Circuloen10_DW.obj_j.isInitialized == 1L) &&
        H4_Circuloen10_DW.obj_j.isSetupComplete) {
      H4_Circuloen10_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(H4_Circuloen10_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      H4_Circuloen10_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(H4_Circuloen10_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S156>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S156>/Atras_der' */
  if (!H4_Circuloen10_DW.obj_e.matlabCodegenIsDeleted) {
    H4_Circuloen10_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((H4_Circuloen10_DW.obj_e.isInitialized == 1L) &&
        H4_Circuloen10_DW.obj_e.isSetupComplete) {
      H4_Circuloen10_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(H4_Circuloen10_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      H4_Circuloen10_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(H4_Circuloen10_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S156>/Atras_der' */

  /* Terminate for MATLABSystem: '<S156>/Atras_izq' */
  if (!H4_Circuloen10_DW.obj_g.matlabCodegenIsDeleted) {
    H4_Circuloen10_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((H4_Circuloen10_DW.obj_g.isInitialized == 1L) &&
        H4_Circuloen10_DW.obj_g.isSetupComplete) {
      H4_Circuloen10_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(H4_Circuloen10_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      H4_Circuloen10_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(H4_Circuloen10_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S156>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S156>/Digital Output' */
  if (!H4_Circuloen10_DW.obj_pi.matlabCodegenIsDeleted) {
    H4_Circuloen10_DW.obj_pi.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S156>/Digital Output' */

  /* Terminate for MATLABSystem: '<S156>/Digital Output1' */
  if (!H4_Circuloen10_DW.obj_m.matlabCodegenIsDeleted) {
    H4_Circuloen10_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S156>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S155>/Encoder' */
  if (!H4_Circuloen10_DW.obj_p.matlabCodegenIsDeleted) {
    H4_Circuloen10_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((H4_Circuloen10_DW.obj_p.isInitialized == 1L) &&
        H4_Circuloen10_DW.obj_p.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S155>/Encoder' */

  /* Terminate for MATLABSystem: '<S155>/Encoder1' */
  if (!H4_Circuloen10_DW.obj.matlabCodegenIsDeleted) {
    H4_Circuloen10_DW.obj.matlabCodegenIsDeleted = true;
    if ((H4_Circuloen10_DW.obj.isInitialized == 1L) &&
        H4_Circuloen10_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S155>/Encoder1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
