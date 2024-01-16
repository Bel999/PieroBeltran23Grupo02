/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: H4_Giro360P.c
 *
 * Code generated for Simulink model 'H4_Giro360P'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Dec 21 15:55:48 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "H4_Giro360P.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "H4_Giro360P_private.h"

/* Block signals (default storage) */
B_H4_Giro360P_T H4_Giro360P_B;

/* Block states (default storage) */
DW_H4_Giro360P_T H4_Giro360P_DW;

/* Real-time model */
static RT_MODEL_H4_Giro360P_T H4_Giro360P_M_;
RT_MODEL_H4_Giro360P_T *const H4_Giro360P_M = &H4_Giro360P_M_;

/* Model step function */
void H4_Giro360P_step(void)
{
  real_T Diff;
  real_T Gain;
  real_T Gain_tmp;
  real_T rtb_TSamp_idx_0;
  real_T tmp;
  int16_T rtb_DataTypeConversion_idx_0;
  int16_T rtb_DataTypeConversion_idx_1;
  int16_T y;

  /* Gain: '<S42>/Proportional Gain' incorporates:
   *  Constant: '<Root>/Constant2'
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Sum: '<Root>/Sum'
   */
  rtb_TSamp_idx_0 = (H4_Giro360P_P.Constant2_Value -
                     H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE) *
    H4_Giro360P_P.PIDController_P;

  /* Saturate: '<S44>/Saturation' */
  if (rtb_TSamp_idx_0 > H4_Giro360P_P.PIDController_UpperSaturationLi) {
    rtb_TSamp_idx_0 = H4_Giro360P_P.PIDController_UpperSaturationLi;
  } else if (rtb_TSamp_idx_0 < H4_Giro360P_P.PIDController_LowerSaturationLi) {
    rtb_TSamp_idx_0 = H4_Giro360P_P.PIDController_LowerSaturationLi;
  }

  /* Product: '<S3>/Matrix Multiply' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S3>/Constant'
   *  Saturate: '<S44>/Saturation'
   */
  H4_Giro360P_B.MatrixMultiply[0] = H4_Giro360P_P.Constant_Value[0] *
    H4_Giro360P_P.Constant1_Value + H4_Giro360P_P.Constant_Value[2] *
    rtb_TSamp_idx_0;
  H4_Giro360P_B.MatrixMultiply[1] = H4_Giro360P_P.Constant_Value[1] *
    H4_Giro360P_P.Constant1_Value + H4_Giro360P_P.Constant_Value[3] *
    rtb_TSamp_idx_0;

  /* Memory: '<S2>/Memory' */
  rtb_TSamp_idx_0 = H4_Giro360P_DW.Memory_PreviousInput[0];
  H4_Giro360P_B.Memory[0] = rtb_TSamp_idx_0;

  /* Sum: '<S2>/Sum' */
  H4_Giro360P_B.error[0] = H4_Giro360P_B.MatrixMultiply[0] - rtb_TSamp_idx_0;

  /* Memory: '<S2>/Memory' */
  rtb_TSamp_idx_0 = H4_Giro360P_DW.Memory_PreviousInput[1];
  H4_Giro360P_B.Memory[1] = rtb_TSamp_idx_0;

  /* Sum: '<S2>/Sum' */
  H4_Giro360P_B.error[1] = H4_Giro360P_B.MatrixMultiply[1] - rtb_TSamp_idx_0;

  /* Sum: '<S146>/Sum' incorporates:
   *  DiscreteIntegrator: '<S137>/Integrator'
   *  Gain: '<S142>/Proportional Gain'
   */
  H4_Giro360P_B.Saturation = H4_Giro360P_P.PIDController2_P *
    H4_Giro360P_B.error[0] + H4_Giro360P_DW.Integrator_DSTATE;

  /* Saturate: '<S144>/Saturation' */
  if (H4_Giro360P_B.Saturation > H4_Giro360P_P.PIDController2_UpperSaturationL)
  {
    /* Sum: '<S146>/Sum' incorporates:
     *  Saturate: '<S144>/Saturation'
     */
    H4_Giro360P_B.Saturation = H4_Giro360P_P.PIDController2_UpperSaturationL;
  } else if (H4_Giro360P_B.Saturation <
             H4_Giro360P_P.PIDController2_LowerSaturationL) {
    /* Sum: '<S146>/Sum' incorporates:
     *  Saturate: '<S144>/Saturation'
     */
    H4_Giro360P_B.Saturation = H4_Giro360P_P.PIDController2_LowerSaturationL;
  }

  /* End of Saturate: '<S144>/Saturation' */

  /* Sum: '<S98>/Sum' incorporates:
   *  DiscreteIntegrator: '<S89>/Integrator'
   *  Gain: '<S94>/Proportional Gain'
   */
  H4_Giro360P_B.Saturation_e = H4_Giro360P_P.PIDController1_P *
    H4_Giro360P_B.error[1] + H4_Giro360P_DW.Integrator_DSTATE_h;

  /* Saturate: '<S96>/Saturation' */
  if (H4_Giro360P_B.Saturation_e > H4_Giro360P_P.PIDController1_UpperSaturationL)
  {
    /* Sum: '<S98>/Sum' incorporates:
     *  Saturate: '<S96>/Saturation'
     */
    H4_Giro360P_B.Saturation_e = H4_Giro360P_P.PIDController1_UpperSaturationL;
  } else if (H4_Giro360P_B.Saturation_e <
             H4_Giro360P_P.PIDController1_LowerSaturationL) {
    /* Sum: '<S98>/Sum' incorporates:
     *  Saturate: '<S96>/Saturation'
     */
    H4_Giro360P_B.Saturation_e = H4_Giro360P_P.PIDController1_LowerSaturationL;
  }

  /* End of Saturate: '<S96>/Saturation' */

  /* SignalConversion generated from: '<S2>/Subsystem Reference' */
  H4_Giro360P_B.pwm[0] = H4_Giro360P_B.Saturation;
  H4_Giro360P_B.pwm[1] = H4_Giro360P_B.Saturation_e;

  /* DataTypeConversion: '<S55>/Data Type Conversion' */
  Gain_tmp = floor(H4_Giro360P_B.pwm[0]);
  if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
    Gain_tmp = 0.0;
  } else {
    Gain_tmp = fmod(Gain_tmp, 65536.0);
  }

  rtb_DataTypeConversion_idx_0 = Gain_tmp < 0.0 ? -(int16_T)(uint16_T)-Gain_tmp :
    (int16_T)(uint16_T)Gain_tmp;
  Gain_tmp = floor(H4_Giro360P_B.pwm[1]);
  if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
    Gain_tmp = 0.0;
  } else {
    Gain_tmp = fmod(Gain_tmp, 65536.0);
  }

  rtb_DataTypeConversion_idx_1 = Gain_tmp < 0.0 ? -(int16_T)(uint16_T)-Gain_tmp :
    (int16_T)(uint16_T)Gain_tmp;

  /* End of DataTypeConversion: '<S55>/Data Type Conversion' */

  /* MATLABSystem: '<S156>/Adelante_der' */
  H4_Giro360P_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

  /* Saturate: '<S156>/Saturation2' */
  if (rtb_DataTypeConversion_idx_1 > H4_Giro360P_P.Saturation2_UpperSat) {
    y = H4_Giro360P_P.Saturation2_UpperSat;
  } else if (rtb_DataTypeConversion_idx_1 < H4_Giro360P_P.Saturation2_LowerSat)
  {
    y = H4_Giro360P_P.Saturation2_LowerSat;
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
  MW_PWM_SetDutyCycle(H4_Giro360P_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

  /* MATLABSystem: '<S156>/Adelante_izq' */
  H4_Giro360P_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

  /* Saturate: '<S156>/Saturation4' */
  if (rtb_DataTypeConversion_idx_0 > H4_Giro360P_P.Saturation4_UpperSat) {
    y = H4_Giro360P_P.Saturation4_UpperSat;
  } else if (rtb_DataTypeConversion_idx_0 < H4_Giro360P_P.Saturation4_LowerSat)
  {
    y = H4_Giro360P_P.Saturation4_LowerSat;
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
  MW_PWM_SetDutyCycle(H4_Giro360P_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

  /* MATLABSystem: '<S156>/Atras_der' */
  H4_Giro360P_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

  /* Saturate: '<S156>/Saturation3' */
  if (rtb_DataTypeConversion_idx_1 > H4_Giro360P_P.Saturation3_UpperSat) {
    y = H4_Giro360P_P.Saturation3_UpperSat;
  } else if (rtb_DataTypeConversion_idx_1 < H4_Giro360P_P.Saturation3_LowerSat)
  {
    y = H4_Giro360P_P.Saturation3_LowerSat;
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
  MW_PWM_SetDutyCycle(H4_Giro360P_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

  /* MATLABSystem: '<S156>/Atras_izq' */
  H4_Giro360P_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

  /* Saturate: '<S156>/Saturation5' */
  if (rtb_DataTypeConversion_idx_0 > H4_Giro360P_P.Saturation5_UpperSat) {
    y = H4_Giro360P_P.Saturation5_UpperSat;
  } else if (rtb_DataTypeConversion_idx_0 < H4_Giro360P_P.Saturation5_LowerSat)
  {
    y = H4_Giro360P_P.Saturation5_LowerSat;
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
  MW_PWM_SetDutyCycle(H4_Giro360P_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

  /* MATLABSystem: '<S156>/Digital Output' incorporates:
   *  Constant: '<S158>/Constant'
   *  RelationalOperator: '<S158>/Compare'
   */
  writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
    H4_Giro360P_P.Constant_Value_c));

  /* MATLABSystem: '<S156>/Digital Output1' incorporates:
   *  Constant: '<S159>/Constant'
   *  RelationalOperator: '<S159>/Compare'
   */
  writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
    H4_Giro360P_P.Constant_Value_d));

  /* DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  H4_Giro360P_B.DiscreteTimeIntegrator[0] =
    H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE_k[0];
  H4_Giro360P_B.DiscreteTimeIntegrator[1] =
    H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE_k[1];
  H4_Giro360P_B.DiscreteTimeIntegrator[2] =
    H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE_k[2];

  /* MATLABSystem: '<S155>/Encoder' */
  if (H4_Giro360P_DW.obj_p.SampleTime != H4_Giro360P_P.Encoder_SampleTime) {
    H4_Giro360P_DW.obj_p.SampleTime = H4_Giro360P_P.Encoder_SampleTime;
  }

  if (H4_Giro360P_DW.obj_p.TunablePropsChanged) {
    H4_Giro360P_DW.obj_p.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<S155>/Encoder' */
  MW_EncoderRead(H4_Giro360P_DW.obj_p.Index, &H4_Giro360P_B.Encoder);

  /* MATLABSystem: '<S155>/Encoder1' */
  if (H4_Giro360P_DW.obj.SampleTime != H4_Giro360P_P.Encoder1_SampleTime) {
    H4_Giro360P_DW.obj.SampleTime = H4_Giro360P_P.Encoder1_SampleTime;
  }

  if (H4_Giro360P_DW.obj.TunablePropsChanged) {
    H4_Giro360P_DW.obj.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<S155>/Encoder1' */
  MW_EncoderRead(H4_Giro360P_DW.obj.Index, &H4_Giro360P_B.Encoder1);

  /* SignalConversion generated from: '<S155>/Gain' */
  H4_Giro360P_B.TmpSignalConversionAtGainInport[0] = H4_Giro360P_B.Encoder;
  H4_Giro360P_B.TmpSignalConversionAtGainInport[1] = H4_Giro360P_B.Encoder1;

  /* Gain: '<S155>/Gain' */
  Gain_tmp = (real_T)H4_Giro360P_P.Gain_Gain * 1.1368683772161603E-13;

  /* Gain: '<S155>/Gain' */
  Gain = Gain_tmp * (real_T)H4_Giro360P_B.TmpSignalConversionAtGainInport[0];
  H4_Giro360P_B.Gain[0] = Gain;

  /* SampleTimeMath: '<S157>/TSamp'
   *
   * About '<S157>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Gain *= H4_Giro360P_P.TSamp_WtEt;
  rtb_TSamp_idx_0 = Gain;

  /* Sum: '<S157>/Diff' incorporates:
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
  Diff = Gain - H4_Giro360P_DW.UD_DSTATE[0];
  H4_Giro360P_B.Diff[0] = Diff;

  /* Gain: '<S154>/Gain1' */
  H4_Giro360P_B.Gain1[0] = H4_Giro360P_P.Gain1_Gain[0] * Diff;

  /* Gain: '<S155>/Gain' */
  Gain = Gain_tmp * (real_T)H4_Giro360P_B.TmpSignalConversionAtGainInport[1];
  H4_Giro360P_B.Gain[1] = Gain;

  /* SampleTimeMath: '<S157>/TSamp'
   *
   * About '<S157>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  Gain *= H4_Giro360P_P.TSamp_WtEt;

  /* Sum: '<S157>/Diff' incorporates:
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
  Diff = Gain - H4_Giro360P_DW.UD_DSTATE[1];
  H4_Giro360P_B.Diff[1] = Diff;

  /* Gain: '<S154>/Gain1' */
  H4_Giro360P_B.Gain1[1] = H4_Giro360P_P.Gain1_Gain[1] * Diff;

  /* Product: '<S4>/Matrix Multiply' incorporates:
   *  Constant: '<S4>/Constant'
   */
  H4_Giro360P_B.MatrixMultiply_d[0] = H4_Giro360P_P.Constant_Value_b[0] *
    H4_Giro360P_B.Gain1[0] + H4_Giro360P_B.Gain1[1] *
    H4_Giro360P_P.Constant_Value_b[2];
  H4_Giro360P_B.MatrixMultiply_d[1] = H4_Giro360P_B.Gain1[0] *
    H4_Giro360P_P.Constant_Value_b[1] + H4_Giro360P_B.Gain1[1] *
    H4_Giro360P_P.Constant_Value_b[3];

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE +=
    H4_Giro360P_P.DiscreteTimeIntegrator_gainval *
    H4_Giro360P_B.MatrixMultiply_d[1];

  /* Update for DiscreteIntegrator: '<S137>/Integrator' incorporates:
   *  Gain: '<S134>/Integral Gain'
   */
  H4_Giro360P_DW.Integrator_DSTATE += H4_Giro360P_P.PIDController2_I *
    H4_Giro360P_B.error[0] * H4_Giro360P_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S89>/Integrator' incorporates:
   *  Gain: '<S86>/Integral Gain'
   */
  H4_Giro360P_DW.Integrator_DSTATE_h += H4_Giro360P_P.PIDController1_I *
    H4_Giro360P_B.error[1] * H4_Giro360P_P.Integrator_gainval_d;

  /* Update for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' incorporates:
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   *  Trigonometry: '<S5>/Cos'
   *  Trigonometry: '<S5>/Sin'
   */
  Gain_tmp = H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE_k[0];
  Diff = H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE_k[1];
  tmp = H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE_k[2];
  H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE_k[0] = cos
    (H4_Giro360P_B.DiscreteTimeIntegrator[2]) * H4_Giro360P_B.MatrixMultiply_d[0]
    * H4_Giro360P_P.DiscreteTimeIntegrator_gainva_b + Gain_tmp;
  H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
    H4_Giro360P_B.MatrixMultiply_d[0] * sin
    (H4_Giro360P_B.DiscreteTimeIntegrator[2]) *
    H4_Giro360P_P.DiscreteTimeIntegrator_gainva_b + Diff;
  H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE_k[2] =
    H4_Giro360P_P.DiscreteTimeIntegrator_gainva_b *
    H4_Giro360P_B.MatrixMultiply_d[1] + tmp;

  /* Update for Memory: '<S2>/Memory' */
  H4_Giro360P_DW.Memory_PreviousInput[0] = H4_Giro360P_B.Gain1[0];

  /* Update for UnitDelay: '<S157>/UD'
   *
   * Block description for '<S157>/UD':
   *
   *  Store in Global RAM
   */
  H4_Giro360P_DW.UD_DSTATE[0] = rtb_TSamp_idx_0;

  /* Update for Memory: '<S2>/Memory' */
  H4_Giro360P_DW.Memory_PreviousInput[1] = H4_Giro360P_B.Gain1[1];

  /* Update for UnitDelay: '<S157>/UD' incorporates:
   *  SampleTimeMath: '<S157>/TSamp'
   *
   * About '<S157>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S157>/UD':
   *
   *  Store in Global RAM
   */
  H4_Giro360P_DW.UD_DSTATE[1] = Gain;

  {                                    /* Sample time: [0.01s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  H4_Giro360P_M->Timing.taskTime0 =
    ((time_T)(++H4_Giro360P_M->Timing.clockTick0)) *
    H4_Giro360P_M->Timing.stepSize0;
}

/* Model initialize function */
void H4_Giro360P_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(H4_Giro360P_M, 10.0);
  H4_Giro360P_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  H4_Giro360P_M->Sizes.checksums[0] = (273385891U);
  H4_Giro360P_M->Sizes.checksums[1] = (599877994U);
  H4_Giro360P_M->Sizes.checksums[2] = (429107147U);
  H4_Giro360P_M->Sizes.checksums[3] = (1820045565U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    H4_Giro360P_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(H4_Giro360P_M->extModeInfo,
      &H4_Giro360P_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(H4_Giro360P_M->extModeInfo,
                        H4_Giro360P_M->Sizes.checksums);
    rteiSetTPtr(H4_Giro360P_M->extModeInfo, rtmGetTPtr(H4_Giro360P_M));
  }

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE =
    H4_Giro360P_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Memory: '<S2>/Memory' */
  H4_Giro360P_DW.Memory_PreviousInput[0] = H4_Giro360P_P.Memory_InitialCondition;
  H4_Giro360P_DW.Memory_PreviousInput[1] = H4_Giro360P_P.Memory_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S137>/Integrator' */
  H4_Giro360P_DW.Integrator_DSTATE =
    H4_Giro360P_P.PIDController2_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S89>/Integrator' */
  H4_Giro360P_DW.Integrator_DSTATE_h =
    H4_Giro360P_P.PIDController1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Discrete-Time Integrator' */
  H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
    H4_Giro360P_P.DiscreteTimeIntegrator_IC_c;
  H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
    H4_Giro360P_P.DiscreteTimeIntegrator_IC_c;
  H4_Giro360P_DW.DiscreteTimeIntegrator_DSTATE_k[2] =
    H4_Giro360P_P.DiscreteTimeIntegrator_IC_c;

  /* InitializeConditions for UnitDelay: '<S157>/UD'
   *
   * Block description for '<S157>/UD':
   *
   *  Store in Global RAM
   */
  H4_Giro360P_DW.UD_DSTATE[0] = H4_Giro360P_P.DiscreteDerivative_ICPrevScaled;
  H4_Giro360P_DW.UD_DSTATE[1] = H4_Giro360P_P.DiscreteDerivative_ICPrevScaled;

  /* Start for MATLABSystem: '<S156>/Adelante_der' */
  H4_Giro360P_DW.obj_b.matlabCodegenIsDeleted = false;
  H4_Giro360P_DW.obj_b.isInitialized = 1L;
  H4_Giro360P_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0, 0.0);
  H4_Giro360P_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S156>/Adelante_izq' */
  H4_Giro360P_DW.obj_j.matlabCodegenIsDeleted = false;
  H4_Giro360P_DW.obj_j.isInitialized = 1L;
  H4_Giro360P_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  H4_Giro360P_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S156>/Atras_der' */
  H4_Giro360P_DW.obj_e.matlabCodegenIsDeleted = false;
  H4_Giro360P_DW.obj_e.isInitialized = 1L;
  H4_Giro360P_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  H4_Giro360P_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S156>/Atras_izq' */
  H4_Giro360P_DW.obj_g.matlabCodegenIsDeleted = false;
  H4_Giro360P_DW.obj_g.isInitialized = 1L;
  H4_Giro360P_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
  H4_Giro360P_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S156>/Digital Output' */
  H4_Giro360P_DW.obj_pi.matlabCodegenIsDeleted = false;
  H4_Giro360P_DW.obj_pi.isInitialized = 1L;
  digitalIOSetup(8, 1);
  H4_Giro360P_DW.obj_pi.isSetupComplete = true;

  /* Start for MATLABSystem: '<S156>/Digital Output1' */
  H4_Giro360P_DW.obj_m.matlabCodegenIsDeleted = false;
  H4_Giro360P_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(13, 1);
  H4_Giro360P_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S155>/Encoder' */
  H4_Giro360P_DW.obj_p.Index = 0U;
  H4_Giro360P_DW.obj_p.matlabCodegenIsDeleted = false;
  H4_Giro360P_DW.obj_p.SampleTime = H4_Giro360P_P.Encoder_SampleTime;
  H4_Giro360P_DW.obj_p.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &H4_Giro360P_DW.obj_p.Index);
  H4_Giro360P_DW.obj_p.isSetupComplete = true;
  H4_Giro360P_DW.obj_p.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S155>/Encoder' */
  MW_EncoderReset(H4_Giro360P_DW.obj_p.Index);

  /* Start for MATLABSystem: '<S155>/Encoder1' */
  H4_Giro360P_DW.obj.Index = 0U;
  H4_Giro360P_DW.obj.matlabCodegenIsDeleted = false;
  H4_Giro360P_DW.obj.SampleTime = H4_Giro360P_P.Encoder1_SampleTime;
  H4_Giro360P_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &H4_Giro360P_DW.obj.Index);
  H4_Giro360P_DW.obj.isSetupComplete = true;
  H4_Giro360P_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S155>/Encoder1' */
  MW_EncoderReset(H4_Giro360P_DW.obj.Index);
}

/* Model terminate function */
void H4_Giro360P_terminate(void)
{
  /* Terminate for MATLABSystem: '<S156>/Adelante_der' */
  if (!H4_Giro360P_DW.obj_b.matlabCodegenIsDeleted) {
    H4_Giro360P_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((H4_Giro360P_DW.obj_b.isInitialized == 1L) &&
        H4_Giro360P_DW.obj_b.isSetupComplete) {
      H4_Giro360P_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle(H4_Giro360P_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      H4_Giro360P_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_Close(H4_Giro360P_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S156>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S156>/Adelante_izq' */
  if (!H4_Giro360P_DW.obj_j.matlabCodegenIsDeleted) {
    H4_Giro360P_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((H4_Giro360P_DW.obj_j.isInitialized == 1L) &&
        H4_Giro360P_DW.obj_j.isSetupComplete) {
      H4_Giro360P_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(H4_Giro360P_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      H4_Giro360P_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(H4_Giro360P_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S156>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S156>/Atras_der' */
  if (!H4_Giro360P_DW.obj_e.matlabCodegenIsDeleted) {
    H4_Giro360P_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((H4_Giro360P_DW.obj_e.isInitialized == 1L) &&
        H4_Giro360P_DW.obj_e.isSetupComplete) {
      H4_Giro360P_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(H4_Giro360P_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      H4_Giro360P_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(H4_Giro360P_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S156>/Atras_der' */

  /* Terminate for MATLABSystem: '<S156>/Atras_izq' */
  if (!H4_Giro360P_DW.obj_g.matlabCodegenIsDeleted) {
    H4_Giro360P_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((H4_Giro360P_DW.obj_g.isInitialized == 1L) &&
        H4_Giro360P_DW.obj_g.isSetupComplete) {
      H4_Giro360P_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(H4_Giro360P_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      H4_Giro360P_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(H4_Giro360P_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S156>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S156>/Digital Output' */
  if (!H4_Giro360P_DW.obj_pi.matlabCodegenIsDeleted) {
    H4_Giro360P_DW.obj_pi.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S156>/Digital Output' */

  /* Terminate for MATLABSystem: '<S156>/Digital Output1' */
  if (!H4_Giro360P_DW.obj_m.matlabCodegenIsDeleted) {
    H4_Giro360P_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S156>/Digital Output1' */
  /* Terminate for MATLABSystem: '<S155>/Encoder' */
  if (!H4_Giro360P_DW.obj_p.matlabCodegenIsDeleted) {
    H4_Giro360P_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((H4_Giro360P_DW.obj_p.isInitialized == 1L) &&
        H4_Giro360P_DW.obj_p.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S155>/Encoder' */

  /* Terminate for MATLABSystem: '<S155>/Encoder1' */
  if (!H4_Giro360P_DW.obj.matlabCodegenIsDeleted) {
    H4_Giro360P_DW.obj.matlabCodegenIsDeleted = true;
    if ((H4_Giro360P_DW.obj.isInitialized == 1L) &&
        H4_Giro360P_DW.obj.isSetupComplete) {
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
