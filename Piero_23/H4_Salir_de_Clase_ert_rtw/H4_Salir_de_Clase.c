/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: H4_Salir_de_Clase.c
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
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "H4_Salir_de_Clase_private.h"

/* Block signals (default storage) */
B_H4_Salir_de_Clase_T H4_Salir_de_Clase_B;

/* Block states (default storage) */
DW_H4_Salir_de_Clase_T H4_Salir_de_Clase_DW;

/* Real-time model */
static RT_MODEL_H4_Salir_de_Clase_T H4_Salir_de_Clase_M_;
RT_MODEL_H4_Salir_de_Clase_T *const H4_Salir_de_Clase_M = &H4_Salir_de_Clase_M_;

/* Model step function */
void H4_Salir_de_Clase_step(void)
{
  /* local block i/o variables */
  real_T rtb_V;
  real_T rtb_IntegralGain;
  real_T rtb_IntegralGain_a;
  real_T rtb_IntegralGain_j;
  real_T error_idx_1;
  real_T u0;
  int32_T rtb_Encoder1_0;
  int32_T rtb_Encoder_0;
  int16_T rtb_DataTypeConversion_idx_0;
  int16_T rtb_DataTypeConversion_idx_1;
  int16_T y;

  /* FromWorkspace: '<S2>/From Workspace' */
  {
    real_T t = H4_Salir_de_Clase_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      H4_Salir_de_Clase_DW.FromWorkspace_PWORK.TimePtr;
    real_T *pDataValues = (real_T *)
      H4_Salir_de_Clase_DW.FromWorkspace_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      rtb_V = 0.0;
    } else if (t == pTimeValues[7]) {
      rtb_V = pDataValues[7];
    } else if (t > pTimeValues[7]) {
      rtb_V = 0.0;
    } else {
      int_T currTimeIndex = H4_Salir_de_Clase_DW.FromWorkspace_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      rtb_V = pDataValues[currTimeIndex];
      H4_Salir_de_Clase_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;
    }
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   */
  H4_Salir_de_Clase_B.Sum = rtb_V -
    H4_Salir_de_Clase_DW.DiscreteTimeIntegrator_DSTATE;

  /* FromWorkspace: '<S2>/fromWS_Signal 1' */
  {
    real_T t = H4_Salir_de_Clase_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      H4_Salir_de_Clase_DW.fromWS_Signal1_PWORK.TimePtr;
    real_T *pDataValues = (real_T *)
      H4_Salir_de_Clase_DW.fromWS_Signal1_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      rtb_V = 0.0;
    } else if (t == pTimeValues[3]) {
      rtb_V = pDataValues[3];
    } else if (t > pTimeValues[3]) {
      rtb_V = 0.0;
    } else {
      int_T currTimeIndex = H4_Salir_de_Clase_DW.fromWS_Signal1_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      rtb_V = pDataValues[currTimeIndex];
      H4_Salir_de_Clase_DW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;
    }
  }

  /* SignalConversion generated from: '<S4>/Matrix Multiply' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  Gain: '<S43>/Proportional Gain'
   *  Sum: '<S47>/Sum'
   */
  error_idx_1 = H4_Salir_de_Clase_P.PIDController_P * H4_Salir_de_Clase_B.Sum +
    H4_Salir_de_Clase_DW.Integrator_DSTATE;

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S4>/Constant'
   *  Memory: '<S3>/Memory'
   *  Product: '<S4>/Matrix Multiply'
   *  SignalConversion generated from: '<S4>/Matrix Multiply'
   */
  H4_Salir_de_Clase_B.error_idx_0 = (H4_Salir_de_Clase_P.Constant_Value[0] *
    rtb_V + H4_Salir_de_Clase_P.Constant_Value[2] * error_idx_1) -
    H4_Salir_de_Clase_DW.Memory_PreviousInput[0];
  error_idx_1 = (H4_Salir_de_Clase_P.Constant_Value[1] * rtb_V +
                 H4_Salir_de_Clase_P.Constant_Value[3] * error_idx_1) -
    H4_Salir_de_Clase_DW.Memory_PreviousInput[1];

  /* Sum: '<S147>/Sum' incorporates:
   *  DiscreteIntegrator: '<S138>/Integrator'
   *  Gain: '<S143>/Proportional Gain'
   */
  u0 = H4_Salir_de_Clase_P.PIDController2_P * H4_Salir_de_Clase_B.error_idx_0 +
    H4_Salir_de_Clase_DW.Integrator_DSTATE_he;

  /* Saturate: '<S145>/Saturation' */
  if (u0 > H4_Salir_de_Clase_P.PIDController2_UpperSaturationL) {
    u0 = H4_Salir_de_Clase_P.PIDController2_UpperSaturationL;
  } else if (u0 < H4_Salir_de_Clase_P.PIDController2_LowerSaturationL) {
    u0 = H4_Salir_de_Clase_P.PIDController2_LowerSaturationL;
  }

  /* DataTypeConversion: '<S56>/Data Type Conversion' incorporates:
   *  Saturate: '<S145>/Saturation'
   */
  u0 = floor(u0);
  if (rtIsNaN(u0) || rtIsInf(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 65536.0);
  }

  rtb_DataTypeConversion_idx_0 = u0 < 0.0 ? -(int16_T)(uint16_T)-u0 : (int16_T)
    (uint16_T)u0;

  /* Sum: '<S99>/Sum' incorporates:
   *  DiscreteIntegrator: '<S90>/Integrator'
   *  Gain: '<S95>/Proportional Gain'
   */
  u0 = H4_Salir_de_Clase_P.PIDController1_P * error_idx_1 +
    H4_Salir_de_Clase_DW.Integrator_DSTATE_h;

  /* Saturate: '<S97>/Saturation' */
  if (u0 > H4_Salir_de_Clase_P.PIDController1_UpperSaturationL) {
    u0 = H4_Salir_de_Clase_P.PIDController1_UpperSaturationL;
  } else if (u0 < H4_Salir_de_Clase_P.PIDController1_LowerSaturationL) {
    u0 = H4_Salir_de_Clase_P.PIDController1_LowerSaturationL;
  }

  /* DataTypeConversion: '<S56>/Data Type Conversion' incorporates:
   *  Saturate: '<S97>/Saturation'
   */
  u0 = floor(u0);
  if (rtIsNaN(u0) || rtIsInf(u0)) {
    u0 = 0.0;
  } else {
    u0 = fmod(u0, 65536.0);
  }

  rtb_DataTypeConversion_idx_1 = u0 < 0.0 ? -(int16_T)(uint16_T)-u0 : (int16_T)
    (uint16_T)u0;

  /* MATLABSystem: '<S157>/Adelante_der' */
  H4_Salir_de_Clase_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

  /* Saturate: '<S157>/Saturation2' */
  if (rtb_DataTypeConversion_idx_1 > H4_Salir_de_Clase_P.Saturation2_UpperSat) {
    y = H4_Salir_de_Clase_P.Saturation2_UpperSat;
  } else if (rtb_DataTypeConversion_idx_1 <
             H4_Salir_de_Clase_P.Saturation2_LowerSat) {
    y = H4_Salir_de_Clase_P.Saturation2_LowerSat;
  } else {
    y = rtb_DataTypeConversion_idx_1;
  }

  /* End of Saturate: '<S157>/Saturation2' */

  /* Start for MATLABSystem: '<S157>/Adelante_der' */
  if (y > 255) {
    y = 255;
  }

  if (y < 0) {
    y = 0;
  }

  /* MATLABSystem: '<S157>/Adelante_der' */
  MW_PWM_SetDutyCycle(H4_Salir_de_Clase_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)y);

  /* MATLABSystem: '<S157>/Adelante_izq' */
  H4_Salir_de_Clase_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

  /* Saturate: '<S157>/Saturation4' */
  if (rtb_DataTypeConversion_idx_0 > H4_Salir_de_Clase_P.Saturation4_UpperSat) {
    y = H4_Salir_de_Clase_P.Saturation4_UpperSat;
  } else if (rtb_DataTypeConversion_idx_0 <
             H4_Salir_de_Clase_P.Saturation4_LowerSat) {
    y = H4_Salir_de_Clase_P.Saturation4_LowerSat;
  } else {
    y = rtb_DataTypeConversion_idx_0;
  }

  /* End of Saturate: '<S157>/Saturation4' */

  /* Abs: '<S157>/Abs2' */
  if (y < 0) {
    y = -y;
  }

  /* End of Abs: '<S157>/Abs2' */

  /* Start for MATLABSystem: '<S157>/Adelante_izq' */
  if (y > 255) {
    y = 255;
  }

  if (y < 0) {
    y = 0;
  }

  /* MATLABSystem: '<S157>/Adelante_izq' */
  MW_PWM_SetDutyCycle(H4_Salir_de_Clase_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)y);

  /* MATLABSystem: '<S157>/Atras_der' */
  H4_Salir_de_Clase_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

  /* Saturate: '<S157>/Saturation3' */
  if (rtb_DataTypeConversion_idx_1 > H4_Salir_de_Clase_P.Saturation3_UpperSat) {
    y = H4_Salir_de_Clase_P.Saturation3_UpperSat;
  } else if (rtb_DataTypeConversion_idx_1 <
             H4_Salir_de_Clase_P.Saturation3_LowerSat) {
    y = H4_Salir_de_Clase_P.Saturation3_LowerSat;
  } else {
    y = rtb_DataTypeConversion_idx_1;
  }

  /* End of Saturate: '<S157>/Saturation3' */

  /* Abs: '<S157>/Abs1' */
  if (y < 0) {
    y = -y;
  }

  /* End of Abs: '<S157>/Abs1' */

  /* Start for MATLABSystem: '<S157>/Atras_der' */
  if (y > 255) {
    y = 255;
  }

  if (y < 0) {
    y = 0;
  }

  /* MATLABSystem: '<S157>/Atras_der' */
  MW_PWM_SetDutyCycle(H4_Salir_de_Clase_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)y);

  /* MATLABSystem: '<S157>/Atras_izq' */
  H4_Salir_de_Clase_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

  /* Saturate: '<S157>/Saturation5' */
  if (rtb_DataTypeConversion_idx_0 > H4_Salir_de_Clase_P.Saturation5_UpperSat) {
    y = H4_Salir_de_Clase_P.Saturation5_UpperSat;
  } else if (rtb_DataTypeConversion_idx_0 <
             H4_Salir_de_Clase_P.Saturation5_LowerSat) {
    y = H4_Salir_de_Clase_P.Saturation5_LowerSat;
  } else {
    y = rtb_DataTypeConversion_idx_0;
  }

  /* End of Saturate: '<S157>/Saturation5' */

  /* Start for MATLABSystem: '<S157>/Atras_izq' */
  if (y > 255) {
    y = 255;
  }

  if (y < 0) {
    y = 0;
  }

  /* MATLABSystem: '<S157>/Atras_izq' */
  MW_PWM_SetDutyCycle(H4_Salir_de_Clase_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                      (real_T)y);

  /* MATLABSystem: '<S157>/Digital Output' incorporates:
   *  Constant: '<S159>/Constant'
   *  RelationalOperator: '<S159>/Compare'
   */
  writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
    H4_Salir_de_Clase_P.Constant_Value_c));

  /* MATLABSystem: '<S157>/Digital Output1' incorporates:
   *  Constant: '<S160>/Constant'
   *  RelationalOperator: '<S160>/Compare'
   */
  writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
    H4_Salir_de_Clase_P.Constant_Value_d));

  /* Gain: '<S87>/Integral Gain' */
  rtb_IntegralGain = H4_Salir_de_Clase_P.PIDController1_I * error_idx_1;

  /* Gain: '<S135>/Integral Gain' */
  rtb_IntegralGain_a = H4_Salir_de_Clase_P.PIDController2_I *
    H4_Salir_de_Clase_B.error_idx_0;

  /* Gain: '<S35>/Integral Gain' */
  rtb_IntegralGain_j = H4_Salir_de_Clase_P.PIDController_I *
    H4_Salir_de_Clase_B.Sum;

  /* MATLABSystem: '<S156>/Encoder' */
  if (H4_Salir_de_Clase_DW.obj_p.SampleTime !=
      H4_Salir_de_Clase_P.Encoder_SampleTime) {
    H4_Salir_de_Clase_DW.obj_p.SampleTime =
      H4_Salir_de_Clase_P.Encoder_SampleTime;
  }

  if (H4_Salir_de_Clase_DW.obj_p.TunablePropsChanged) {
    H4_Salir_de_Clase_DW.obj_p.TunablePropsChanged = false;
  }

  MW_EncoderRead(H4_Salir_de_Clase_DW.obj_p.Index, &rtb_Encoder_0);

  /* MATLABSystem: '<S156>/Encoder1' */
  if (H4_Salir_de_Clase_DW.obj.SampleTime !=
      H4_Salir_de_Clase_P.Encoder1_SampleTime) {
    H4_Salir_de_Clase_DW.obj.SampleTime =
      H4_Salir_de_Clase_P.Encoder1_SampleTime;
  }

  if (H4_Salir_de_Clase_DW.obj.TunablePropsChanged) {
    H4_Salir_de_Clase_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(H4_Salir_de_Clase_DW.obj.Index, &rtb_Encoder1_0);

  /* Gain: '<S156>/Gain' */
  H4_Salir_de_Clase_B.Sum = (real_T)H4_Salir_de_Clase_P.Gain_Gain *
    1.1368683772161603E-13;

  /* SampleTimeMath: '<S158>/TSamp' incorporates:
   *  Gain: '<S156>/Gain'
   *  MATLABSystem: '<S156>/Encoder'
   *  MATLABSystem: '<S156>/Encoder1'
   *
   * About '<S158>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  H4_Salir_de_Clase_B.TSamp[0] = H4_Salir_de_Clase_B.Sum * (real_T)rtb_Encoder_0
    * H4_Salir_de_Clase_P.TSamp_WtEt;
  H4_Salir_de_Clase_B.TSamp[1] = H4_Salir_de_Clase_B.Sum * (real_T)
    rtb_Encoder1_0 * H4_Salir_de_Clase_P.TSamp_WtEt;

  /* Gain: '<S155>/Gain1' incorporates:
   *  Sum: '<S158>/Diff'
   *  UnitDelay: '<S158>/UD'
   *
   * Block description for '<S158>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S158>/UD':
   *
   *  Store in Global RAM
   */
  H4_Salir_de_Clase_B.Gain1[0] = (H4_Salir_de_Clase_B.TSamp[0] -
    H4_Salir_de_Clase_DW.UD_DSTATE[0]) * H4_Salir_de_Clase_P.Gain1_Gain[0];
  H4_Salir_de_Clase_B.Gain1[1] = (H4_Salir_de_Clase_B.TSamp[1] -
    H4_Salir_de_Clase_DW.UD_DSTATE[1]) * H4_Salir_de_Clase_P.Gain1_Gain[1];

  /* Product: '<S5>/Matrix Multiply' incorporates:
   *  Constant: '<S5>/Constant'
   */
  H4_Salir_de_Clase_B.MatrixMultiply[0] = H4_Salir_de_Clase_P.Constant_Value_b[0]
    * H4_Salir_de_Clase_B.Gain1[0] + H4_Salir_de_Clase_B.Gain1[1] *
    H4_Salir_de_Clase_P.Constant_Value_b[2];
  H4_Salir_de_Clase_B.MatrixMultiply[1] = H4_Salir_de_Clase_B.Gain1[0] *
    H4_Salir_de_Clase_P.Constant_Value_b[1] + H4_Salir_de_Clase_B.Gain1[1] *
    H4_Salir_de_Clase_P.Constant_Value_b[3];

  /* Update for DiscreteIntegrator: '<S38>/Integrator' */
  H4_Salir_de_Clase_DW.Integrator_DSTATE +=
    H4_Salir_de_Clase_P.Integrator_gainval * rtb_IntegralGain_j;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  H4_Salir_de_Clase_DW.DiscreteTimeIntegrator_DSTATE +=
    H4_Salir_de_Clase_P.DiscreteTimeIntegrator_gainval *
    H4_Salir_de_Clase_B.MatrixMultiply[1];

  /* Update for DiscreteIntegrator: '<S90>/Integrator' */
  H4_Salir_de_Clase_DW.Integrator_DSTATE_h +=
    H4_Salir_de_Clase_P.Integrator_gainval_d * rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S138>/Integrator' */
  H4_Salir_de_Clase_DW.Integrator_DSTATE_he +=
    H4_Salir_de_Clase_P.Integrator_gainval_i * rtb_IntegralGain_a;

  /* Update for Memory: '<S3>/Memory' */
  H4_Salir_de_Clase_DW.Memory_PreviousInput[0] = H4_Salir_de_Clase_B.Gain1[0];

  /* Update for UnitDelay: '<S158>/UD'
   *
   * Block description for '<S158>/UD':
   *
   *  Store in Global RAM
   */
  H4_Salir_de_Clase_DW.UD_DSTATE[0] = H4_Salir_de_Clase_B.TSamp[0];

  /* Update for Memory: '<S3>/Memory' */
  H4_Salir_de_Clase_DW.Memory_PreviousInput[1] = H4_Salir_de_Clase_B.Gain1[1];

  /* Update for UnitDelay: '<S158>/UD'
   *
   * Block description for '<S158>/UD':
   *
   *  Store in Global RAM
   */
  H4_Salir_de_Clase_DW.UD_DSTATE[1] = H4_Salir_de_Clase_B.TSamp[1];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  H4_Salir_de_Clase_M->Timing.t[0] =
    ((time_T)(++H4_Salir_de_Clase_M->Timing.clockTick0)) *
    H4_Salir_de_Clase_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    H4_Salir_de_Clase_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void H4_Salir_de_Clase_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&H4_Salir_de_Clase_M->solverInfo,
                          &H4_Salir_de_Clase_M->Timing.simTimeStep);
    rtsiSetTPtr(&H4_Salir_de_Clase_M->solverInfo, &rtmGetTPtr
                (H4_Salir_de_Clase_M));
    rtsiSetStepSizePtr(&H4_Salir_de_Clase_M->solverInfo,
                       &H4_Salir_de_Clase_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&H4_Salir_de_Clase_M->solverInfo, (&rtmGetErrorStatus
      (H4_Salir_de_Clase_M)));
    rtsiSetRTModelPtr(&H4_Salir_de_Clase_M->solverInfo, H4_Salir_de_Clase_M);
  }

  rtsiSetSimTimeStep(&H4_Salir_de_Clase_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&H4_Salir_de_Clase_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(H4_Salir_de_Clase_M, &H4_Salir_de_Clase_M->Timing.tArray[0]);
  H4_Salir_de_Clase_M->Timing.stepSize0 = 0.01;

  /* Start for FromWorkspace: '<S2>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 15.0, 15.0, 64.0, 64.0, 64.8, 64.8,
      101.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 1.5707963267948966,
      1.5707963267948966, 0.0, 0.0, 1.5707963267948966, 1.5707963267948966 } ;

    H4_Salir_de_Clase_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    H4_Salir_de_Clase_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    H4_Salir_de_Clase_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<S2>/fromWS_Signal 1' */
  {
    static real_T pTimeValues0[] = { 0.0, 96.0, 96.0, 100.0 } ;

    static real_T pDataValues0[] = { 0.4, 0.4, 0.0, 0.0 } ;

    H4_Salir_de_Clase_DW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
    H4_Salir_de_Clase_DW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
    H4_Salir_de_Clase_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator' */
  H4_Salir_de_Clase_DW.Integrator_DSTATE =
    H4_Salir_de_Clase_P.PIDController_InitialConditionF;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  H4_Salir_de_Clase_DW.DiscreteTimeIntegrator_DSTATE =
    H4_Salir_de_Clase_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S90>/Integrator' */
  H4_Salir_de_Clase_DW.Integrator_DSTATE_h =
    H4_Salir_de_Clase_P.PIDController1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator' */
  H4_Salir_de_Clase_DW.Integrator_DSTATE_he =
    H4_Salir_de_Clase_P.PIDController2_InitialCondition;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  H4_Salir_de_Clase_DW.Memory_PreviousInput[0] =
    H4_Salir_de_Clase_P.Memory_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S158>/UD'
   *
   * Block description for '<S158>/UD':
   *
   *  Store in Global RAM
   */
  H4_Salir_de_Clase_DW.UD_DSTATE[0] =
    H4_Salir_de_Clase_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  H4_Salir_de_Clase_DW.Memory_PreviousInput[1] =
    H4_Salir_de_Clase_P.Memory_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S158>/UD'
   *
   * Block description for '<S158>/UD':
   *
   *  Store in Global RAM
   */
  H4_Salir_de_Clase_DW.UD_DSTATE[1] =
    H4_Salir_de_Clase_P.DiscreteDerivative_ICPrevScaled;

  /* Start for MATLABSystem: '<S157>/Adelante_der' */
  H4_Salir_de_Clase_DW.obj_b.matlabCodegenIsDeleted = false;
  H4_Salir_de_Clase_DW.obj_b.isInitialized = 1L;
  H4_Salir_de_Clase_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0,
    0.0);
  H4_Salir_de_Clase_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S157>/Adelante_izq' */
  H4_Salir_de_Clase_DW.obj_j.matlabCodegenIsDeleted = false;
  H4_Salir_de_Clase_DW.obj_j.isInitialized = 1L;
  H4_Salir_de_Clase_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0,
    0.0);
  H4_Salir_de_Clase_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S157>/Atras_der' */
  H4_Salir_de_Clase_DW.obj_e.matlabCodegenIsDeleted = false;
  H4_Salir_de_Clase_DW.obj_e.isInitialized = 1L;
  H4_Salir_de_Clase_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  H4_Salir_de_Clase_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S157>/Atras_izq' */
  H4_Salir_de_Clase_DW.obj_g.matlabCodegenIsDeleted = false;
  H4_Salir_de_Clase_DW.obj_g.isInitialized = 1L;
  H4_Salir_de_Clase_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0,
    0.0);
  H4_Salir_de_Clase_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S157>/Digital Output' */
  H4_Salir_de_Clase_DW.obj_pi.matlabCodegenIsDeleted = false;
  H4_Salir_de_Clase_DW.obj_pi.isInitialized = 1L;
  digitalIOSetup(8, 1);
  H4_Salir_de_Clase_DW.obj_pi.isSetupComplete = true;

  /* Start for MATLABSystem: '<S157>/Digital Output1' */
  H4_Salir_de_Clase_DW.obj_m.matlabCodegenIsDeleted = false;
  H4_Salir_de_Clase_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(13, 1);
  H4_Salir_de_Clase_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S156>/Encoder' */
  H4_Salir_de_Clase_DW.obj_p.Index = 0U;
  H4_Salir_de_Clase_DW.obj_p.matlabCodegenIsDeleted = false;
  H4_Salir_de_Clase_DW.obj_p.SampleTime = H4_Salir_de_Clase_P.Encoder_SampleTime;
  H4_Salir_de_Clase_DW.obj_p.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &H4_Salir_de_Clase_DW.obj_p.Index);
  H4_Salir_de_Clase_DW.obj_p.isSetupComplete = true;
  H4_Salir_de_Clase_DW.obj_p.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S156>/Encoder' */
  MW_EncoderReset(H4_Salir_de_Clase_DW.obj_p.Index);

  /* Start for MATLABSystem: '<S156>/Encoder1' */
  H4_Salir_de_Clase_DW.obj.Index = 0U;
  H4_Salir_de_Clase_DW.obj.matlabCodegenIsDeleted = false;
  H4_Salir_de_Clase_DW.obj.SampleTime = H4_Salir_de_Clase_P.Encoder1_SampleTime;
  H4_Salir_de_Clase_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &H4_Salir_de_Clase_DW.obj.Index);
  H4_Salir_de_Clase_DW.obj.isSetupComplete = true;
  H4_Salir_de_Clase_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S156>/Encoder1' */
  MW_EncoderReset(H4_Salir_de_Clase_DW.obj.Index);
}

/* Model terminate function */
void H4_Salir_de_Clase_terminate(void)
{
  /* Terminate for MATLABSystem: '<S157>/Adelante_der' */
  if (!H4_Salir_de_Clase_DW.obj_b.matlabCodegenIsDeleted) {
    H4_Salir_de_Clase_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((H4_Salir_de_Clase_DW.obj_b.isInitialized == 1L) &&
        H4_Salir_de_Clase_DW.obj_b.isSetupComplete) {
      H4_Salir_de_Clase_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_SetDutyCycle(H4_Salir_de_Clase_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      H4_Salir_de_Clase_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_Close(H4_Salir_de_Clase_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S157>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S157>/Adelante_izq' */
  if (!H4_Salir_de_Clase_DW.obj_j.matlabCodegenIsDeleted) {
    H4_Salir_de_Clase_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((H4_Salir_de_Clase_DW.obj_j.isInitialized == 1L) &&
        H4_Salir_de_Clase_DW.obj_j.isSetupComplete) {
      H4_Salir_de_Clase_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);
      MW_PWM_SetDutyCycle(H4_Salir_de_Clase_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      H4_Salir_de_Clase_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);
      MW_PWM_Close(H4_Salir_de_Clase_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S157>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S157>/Atras_der' */
  if (!H4_Salir_de_Clase_DW.obj_e.matlabCodegenIsDeleted) {
    H4_Salir_de_Clase_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((H4_Salir_de_Clase_DW.obj_e.isInitialized == 1L) &&
        H4_Salir_de_Clase_DW.obj_e.isSetupComplete) {
      H4_Salir_de_Clase_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_SetDutyCycle(H4_Salir_de_Clase_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      H4_Salir_de_Clase_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_Close(H4_Salir_de_Clase_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S157>/Atras_der' */

  /* Terminate for MATLABSystem: '<S157>/Atras_izq' */
  if (!H4_Salir_de_Clase_DW.obj_g.matlabCodegenIsDeleted) {
    H4_Salir_de_Clase_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((H4_Salir_de_Clase_DW.obj_g.isInitialized == 1L) &&
        H4_Salir_de_Clase_DW.obj_g.isSetupComplete) {
      H4_Salir_de_Clase_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_SetDutyCycle(H4_Salir_de_Clase_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      H4_Salir_de_Clase_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_Close(H4_Salir_de_Clase_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S157>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S157>/Digital Output' */
  if (!H4_Salir_de_Clase_DW.obj_pi.matlabCodegenIsDeleted) {
    H4_Salir_de_Clase_DW.obj_pi.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S157>/Digital Output' */

  /* Terminate for MATLABSystem: '<S157>/Digital Output1' */
  if (!H4_Salir_de_Clase_DW.obj_m.matlabCodegenIsDeleted) {
    H4_Salir_de_Clase_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S157>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S156>/Encoder' */
  if (!H4_Salir_de_Clase_DW.obj_p.matlabCodegenIsDeleted) {
    H4_Salir_de_Clase_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((H4_Salir_de_Clase_DW.obj_p.isInitialized == 1L) &&
        H4_Salir_de_Clase_DW.obj_p.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S156>/Encoder' */

  /* Terminate for MATLABSystem: '<S156>/Encoder1' */
  if (!H4_Salir_de_Clase_DW.obj.matlabCodegenIsDeleted) {
    H4_Salir_de_Clase_DW.obj.matlabCodegenIsDeleted = true;
    if ((H4_Salir_de_Clase_DW.obj.isInitialized == 1L) &&
        H4_Salir_de_Clase_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S156>/Encoder1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
