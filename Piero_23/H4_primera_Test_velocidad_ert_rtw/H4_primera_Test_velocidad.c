/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: H4_primera_Test_velocidad.c
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
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "H4_primera_Test_velocidad_private.h"

/* Block signals (default storage) */
B_H4_primera_Test_velocidad_T H4_primera_Test_velocidad_B;

/* Block states (default storage) */
DW_H4_primera_Test_velocidad_T H4_primera_Test_velocidad_DW;

/* Real-time model */
static RT_MODEL_H4_primera_Test_velo_T H4_primera_Test_velocidad_M_;
RT_MODEL_H4_primera_Test_velo_T *const H4_primera_Test_velocidad_M =
  &H4_primera_Test_velocidad_M_;

/* Model step function */
void H4_primera_Test_velocidad_step(void)
{
  /* local block i/o variables */
  real_T rtb_IntegralGain;
  real_T rtb_IntegralGain_j;

  {
    real_T (*lastU)[2];
    real_T rtb_error_idx_0;
    real_T rtb_error_idx_1;
    real_T u0;
    int32_T rtb_Encoder1_0;
    int32_T rtb_Encoder_0;
    int16_T rtb_DataTypeConversion_idx_0;
    int16_T rtb_DataTypeConversion_idx_1;
    int16_T y;

    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<Root>/Constant'
     *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
     */
    rtb_error_idx_0 = H4_primera_Test_velocidad_P.Constant_Value[0] -
      H4_primera_Test_velocidad_DW.DiscreteTimeIntegrator_DSTATE[0];
    rtb_error_idx_1 = H4_primera_Test_velocidad_P.Constant_Value[1] -
      H4_primera_Test_velocidad_DW.DiscreteTimeIntegrator_DSTATE[1];

    /* Sum: '<S96>/Sum' incorporates:
     *  DiscreteIntegrator: '<S87>/Integrator'
     *  Gain: '<S92>/Proportional Gain'
     */
    u0 = H4_primera_Test_velocidad_P.PIDController2_P * rtb_error_idx_0 +
      H4_primera_Test_velocidad_DW.Integrator_DSTATE_g;

    /* Saturate: '<S94>/Saturation' */
    if (u0 > H4_primera_Test_velocidad_P.PIDController2_UpperSaturationL) {
      u0 = H4_primera_Test_velocidad_P.PIDController2_UpperSaturationL;
    } else if (u0 < H4_primera_Test_velocidad_P.PIDController2_LowerSaturationL)
    {
      u0 = H4_primera_Test_velocidad_P.PIDController2_LowerSaturationL;
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  Saturate: '<S94>/Saturation'
     */
    u0 = floor(u0);
    if (rtIsNaN(u0) || rtIsInf(u0)) {
      u0 = 0.0;
    } else {
      u0 = fmod(u0, 65536.0);
    }

    rtb_DataTypeConversion_idx_0 = u0 < 0.0 ? -(int16_T)(uint16_T)-u0 : (int16_T)
      (uint16_T)u0;

    /* Sum: '<S48>/Sum' incorporates:
     *  DiscreteIntegrator: '<S39>/Integrator'
     *  Gain: '<S44>/Proportional Gain'
     */
    u0 = H4_primera_Test_velocidad_P.PIDController1_P * rtb_error_idx_1 +
      H4_primera_Test_velocidad_DW.Integrator_DSTATE;

    /* Saturate: '<S46>/Saturation' */
    if (u0 > H4_primera_Test_velocidad_P.PIDController1_UpperSaturationL) {
      u0 = H4_primera_Test_velocidad_P.PIDController1_UpperSaturationL;
    } else if (u0 < H4_primera_Test_velocidad_P.PIDController1_LowerSaturationL)
    {
      u0 = H4_primera_Test_velocidad_P.PIDController1_LowerSaturationL;
    }

    /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
     *  Saturate: '<S46>/Saturation'
     */
    u0 = floor(u0);
    if (rtIsNaN(u0) || rtIsInf(u0)) {
      u0 = 0.0;
    } else {
      u0 = fmod(u0, 65536.0);
    }

    rtb_DataTypeConversion_idx_1 = u0 < 0.0 ? -(int16_T)(uint16_T)-u0 : (int16_T)
      (uint16_T)u0;

    /* MATLABSystem: '<S106>/Adelante_der' */
    H4_primera_Test_velocidad_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(12UL);

    /* Saturate: '<S106>/Saturation2' */
    if (rtb_DataTypeConversion_idx_1 >
        H4_primera_Test_velocidad_P.Saturation2_UpperSat) {
      y = H4_primera_Test_velocidad_P.Saturation2_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               H4_primera_Test_velocidad_P.Saturation2_LowerSat) {
      y = H4_primera_Test_velocidad_P.Saturation2_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
    }

    /* End of Saturate: '<S106>/Saturation2' */

    /* Start for MATLABSystem: '<S106>/Adelante_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S106>/Adelante_der' */
    MW_PWM_SetDutyCycle
      (H4_primera_Test_velocidad_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

    /* MATLABSystem: '<S106>/Adelante_izq' */
    H4_primera_Test_velocidad_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(9UL);

    /* Saturate: '<S106>/Saturation4' */
    if (rtb_DataTypeConversion_idx_0 >
        H4_primera_Test_velocidad_P.Saturation4_UpperSat) {
      y = H4_primera_Test_velocidad_P.Saturation4_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               H4_primera_Test_velocidad_P.Saturation4_LowerSat) {
      y = H4_primera_Test_velocidad_P.Saturation4_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_0;
    }

    /* End of Saturate: '<S106>/Saturation4' */

    /* Abs: '<S106>/Abs2' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S106>/Abs2' */

    /* Start for MATLABSystem: '<S106>/Adelante_izq' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S106>/Adelante_izq' */
    MW_PWM_SetDutyCycle
      (H4_primera_Test_velocidad_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

    /* MATLABSystem: '<S106>/Atras_der' */
    H4_primera_Test_velocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(11UL);

    /* Saturate: '<S106>/Saturation3' */
    if (rtb_DataTypeConversion_idx_1 >
        H4_primera_Test_velocidad_P.Saturation3_UpperSat) {
      y = H4_primera_Test_velocidad_P.Saturation3_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               H4_primera_Test_velocidad_P.Saturation3_LowerSat) {
      y = H4_primera_Test_velocidad_P.Saturation3_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
    }

    /* End of Saturate: '<S106>/Saturation3' */

    /* Abs: '<S106>/Abs1' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S106>/Abs1' */

    /* Start for MATLABSystem: '<S106>/Atras_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S106>/Atras_der' */
    MW_PWM_SetDutyCycle
      (H4_primera_Test_velocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

    /* MATLABSystem: '<S106>/Atras_izq' */
    H4_primera_Test_velocidad_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(10UL);

    /* Saturate: '<S106>/Saturation5' */
    if (rtb_DataTypeConversion_idx_0 >
        H4_primera_Test_velocidad_P.Saturation5_UpperSat) {
      y = H4_primera_Test_velocidad_P.Saturation5_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               H4_primera_Test_velocidad_P.Saturation5_LowerSat) {
      y = H4_primera_Test_velocidad_P.Saturation5_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_0;
    }

    /* End of Saturate: '<S106>/Saturation5' */

    /* Start for MATLABSystem: '<S106>/Atras_izq' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S106>/Atras_izq' */
    MW_PWM_SetDutyCycle
      (H4_primera_Test_velocidad_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

    /* MATLABSystem: '<S106>/Digital Output' incorporates:
     *  Constant: '<S108>/Constant'
     *  RelationalOperator: '<S108>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
      H4_primera_Test_velocidad_P.Constant_Value_k));

    /* MATLABSystem: '<S106>/Digital Output1' incorporates:
     *  Constant: '<S109>/Constant'
     *  RelationalOperator: '<S109>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
      H4_primera_Test_velocidad_P.Constant_Value_j));

    /* Gain: '<S36>/Integral Gain' */
    rtb_IntegralGain = H4_primera_Test_velocidad_P.PIDController1_I *
      rtb_error_idx_1;

    /* Gain: '<S84>/Integral Gain' */
    rtb_IntegralGain_j = H4_primera_Test_velocidad_P.PIDController2_I *
      rtb_error_idx_0;

    /* MATLABSystem: '<S105>/Encoder' */
    if (H4_primera_Test_velocidad_DW.obj_d.SampleTime !=
        H4_primera_Test_velocidad_P.Encoder_SampleTime) {
      H4_primera_Test_velocidad_DW.obj_d.SampleTime =
        H4_primera_Test_velocidad_P.Encoder_SampleTime;
    }

    if (H4_primera_Test_velocidad_DW.obj_d.TunablePropsChanged) {
      H4_primera_Test_velocidad_DW.obj_d.TunablePropsChanged = false;
    }

    MW_EncoderRead(H4_primera_Test_velocidad_DW.obj_d.Index, &rtb_Encoder_0);

    /* MATLABSystem: '<S105>/Encoder1' */
    if (H4_primera_Test_velocidad_DW.obj.SampleTime !=
        H4_primera_Test_velocidad_P.Encoder1_SampleTime) {
      H4_primera_Test_velocidad_DW.obj.SampleTime =
        H4_primera_Test_velocidad_P.Encoder1_SampleTime;
    }

    if (H4_primera_Test_velocidad_DW.obj.TunablePropsChanged) {
      H4_primera_Test_velocidad_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(H4_primera_Test_velocidad_DW.obj.Index, &rtb_Encoder1_0);

    /* Gain: '<S105>/Gain' */
    u0 = (real_T)H4_primera_Test_velocidad_P.Gain_Gain * 1.1368683772161603E-13;

    /* Gain: '<S105>/Gain' incorporates:
     *  MATLABSystem: '<S105>/Encoder'
     *  MATLABSystem: '<S105>/Encoder1'
     */
    H4_primera_Test_velocidad_B.Gain[0] = u0 * (real_T)rtb_Encoder_0;
    H4_primera_Test_velocidad_B.Gain[1] = u0 * (real_T)rtb_Encoder1_0;

    /* Derivative: '<S105>/Derivative' */
    u0 = H4_primera_Test_velocidad_M->Timing.t[0];
    if ((H4_primera_Test_velocidad_DW.TimeStampA >= u0) &&
        (H4_primera_Test_velocidad_DW.TimeStampB >= u0)) {
      H4_primera_Test_velocidad_B.Gain1[0] = 0.0;
      H4_primera_Test_velocidad_B.Gain1[1] = 0.0;
    } else {
      rtb_error_idx_0 = H4_primera_Test_velocidad_DW.TimeStampA;
      lastU = &H4_primera_Test_velocidad_DW.LastUAtTimeA;
      if (H4_primera_Test_velocidad_DW.TimeStampA <
          H4_primera_Test_velocidad_DW.TimeStampB) {
        if (H4_primera_Test_velocidad_DW.TimeStampB < u0) {
          rtb_error_idx_0 = H4_primera_Test_velocidad_DW.TimeStampB;
          lastU = &H4_primera_Test_velocidad_DW.LastUAtTimeB;
        }
      } else if (H4_primera_Test_velocidad_DW.TimeStampA >= u0) {
        rtb_error_idx_0 = H4_primera_Test_velocidad_DW.TimeStampB;
        lastU = &H4_primera_Test_velocidad_DW.LastUAtTimeB;
      }

      u0 -= rtb_error_idx_0;
      H4_primera_Test_velocidad_B.Gain1[0] = (H4_primera_Test_velocidad_B.Gain[0]
        - (*lastU)[0]) / u0;
      H4_primera_Test_velocidad_B.Gain1[1] = (H4_primera_Test_velocidad_B.Gain[1]
        - (*lastU)[1]) / u0;
    }

    /* End of Derivative: '<S105>/Derivative' */

    /* Gain: '<S104>/Gain1' incorporates:
     *  Derivative: '<S105>/Derivative'
     */
    H4_primera_Test_velocidad_B.Gain1[0] *=
      H4_primera_Test_velocidad_P.Gain1_Gain[0];
    H4_primera_Test_velocidad_B.Gain1[1] *=
      H4_primera_Test_velocidad_P.Gain1_Gain[1];
  }

  {
    real_T (*lastU)[2];

    /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
    H4_primera_Test_velocidad_DW.DiscreteTimeIntegrator_DSTATE[0] +=
      H4_primera_Test_velocidad_P.DiscreteTimeIntegrator_gainval *
      H4_primera_Test_velocidad_B.Gain1[0];
    H4_primera_Test_velocidad_DW.DiscreteTimeIntegrator_DSTATE[1] +=
      H4_primera_Test_velocidad_P.DiscreteTimeIntegrator_gainval *
      H4_primera_Test_velocidad_B.Gain1[1];

    /* Update for DiscreteIntegrator: '<S39>/Integrator' */
    H4_primera_Test_velocidad_DW.Integrator_DSTATE +=
      H4_primera_Test_velocidad_P.Integrator_gainval * rtb_IntegralGain;

    /* Update for DiscreteIntegrator: '<S87>/Integrator' */
    H4_primera_Test_velocidad_DW.Integrator_DSTATE_g +=
      H4_primera_Test_velocidad_P.Integrator_gainval_o * rtb_IntegralGain_j;

    /* Update for Derivative: '<S105>/Derivative' */
    if (H4_primera_Test_velocidad_DW.TimeStampA == (rtInf)) {
      H4_primera_Test_velocidad_DW.TimeStampA =
        H4_primera_Test_velocidad_M->Timing.t[0];
      lastU = &H4_primera_Test_velocidad_DW.LastUAtTimeA;
    } else if (H4_primera_Test_velocidad_DW.TimeStampB == (rtInf)) {
      H4_primera_Test_velocidad_DW.TimeStampB =
        H4_primera_Test_velocidad_M->Timing.t[0];
      lastU = &H4_primera_Test_velocidad_DW.LastUAtTimeB;
    } else if (H4_primera_Test_velocidad_DW.TimeStampA <
               H4_primera_Test_velocidad_DW.TimeStampB) {
      H4_primera_Test_velocidad_DW.TimeStampA =
        H4_primera_Test_velocidad_M->Timing.t[0];
      lastU = &H4_primera_Test_velocidad_DW.LastUAtTimeA;
    } else {
      H4_primera_Test_velocidad_DW.TimeStampB =
        H4_primera_Test_velocidad_M->Timing.t[0];
      lastU = &H4_primera_Test_velocidad_DW.LastUAtTimeB;
    }

    (*lastU)[0] = H4_primera_Test_velocidad_B.Gain[0];
    (*lastU)[1] = H4_primera_Test_velocidad_B.Gain[1];

    /* End of Update for Derivative: '<S105>/Derivative' */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  H4_primera_Test_velocidad_M->Timing.t[0] =
    ((time_T)(++H4_primera_Test_velocidad_M->Timing.clockTick0)) *
    H4_primera_Test_velocidad_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    H4_primera_Test_velocidad_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void H4_primera_Test_velocidad_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&H4_primera_Test_velocidad_M->solverInfo,
                          &H4_primera_Test_velocidad_M->Timing.simTimeStep);
    rtsiSetTPtr(&H4_primera_Test_velocidad_M->solverInfo, &rtmGetTPtr
                (H4_primera_Test_velocidad_M));
    rtsiSetStepSizePtr(&H4_primera_Test_velocidad_M->solverInfo,
                       &H4_primera_Test_velocidad_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&H4_primera_Test_velocidad_M->solverInfo,
                          (&rtmGetErrorStatus(H4_primera_Test_velocidad_M)));
    rtsiSetRTModelPtr(&H4_primera_Test_velocidad_M->solverInfo,
                      H4_primera_Test_velocidad_M);
  }

  rtsiSetSimTimeStep(&H4_primera_Test_velocidad_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&H4_primera_Test_velocidad_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(H4_primera_Test_velocidad_M,
             &H4_primera_Test_velocidad_M->Timing.tArray[0]);
  H4_primera_Test_velocidad_M->Timing.stepSize0 = 0.01;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  H4_primera_Test_velocidad_DW.DiscreteTimeIntegrator_DSTATE[0] =
    H4_primera_Test_velocidad_P.DiscreteTimeIntegrator_IC;
  H4_primera_Test_velocidad_DW.DiscreteTimeIntegrator_DSTATE[1] =
    H4_primera_Test_velocidad_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Integrator' */
  H4_primera_Test_velocidad_DW.Integrator_DSTATE =
    H4_primera_Test_velocidad_P.PIDController1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S87>/Integrator' */
  H4_primera_Test_velocidad_DW.Integrator_DSTATE_g =
    H4_primera_Test_velocidad_P.PIDController2_InitialCondition;

  /* InitializeConditions for Derivative: '<S105>/Derivative' */
  H4_primera_Test_velocidad_DW.TimeStampA = (rtInf);
  H4_primera_Test_velocidad_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<S106>/Adelante_der' */
  H4_primera_Test_velocidad_DW.obj_m5.matlabCodegenIsDeleted = false;
  H4_primera_Test_velocidad_DW.obj_m5.isInitialized = 1L;
  H4_primera_Test_velocidad_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (12UL, 0.0, 0.0);
  H4_primera_Test_velocidad_DW.obj_m5.isSetupComplete = true;

  /* Start for MATLABSystem: '<S106>/Adelante_izq' */
  H4_primera_Test_velocidad_DW.obj_dx.matlabCodegenIsDeleted = false;
  H4_primera_Test_velocidad_DW.obj_dx.isInitialized = 1L;
  H4_primera_Test_velocidad_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (9UL, 0.0, 0.0);
  H4_primera_Test_velocidad_DW.obj_dx.isSetupComplete = true;

  /* Start for MATLABSystem: '<S106>/Atras_der' */
  H4_primera_Test_velocidad_DW.obj_b.matlabCodegenIsDeleted = false;
  H4_primera_Test_velocidad_DW.obj_b.isInitialized = 1L;
  H4_primera_Test_velocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (11UL, 0.0, 0.0);
  H4_primera_Test_velocidad_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S106>/Atras_izq' */
  H4_primera_Test_velocidad_DW.obj_m.matlabCodegenIsDeleted = false;
  H4_primera_Test_velocidad_DW.obj_m.isInitialized = 1L;
  H4_primera_Test_velocidad_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (10UL, 0.0, 0.0);
  H4_primera_Test_velocidad_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S106>/Digital Output' */
  H4_primera_Test_velocidad_DW.obj_bt.matlabCodegenIsDeleted = false;
  H4_primera_Test_velocidad_DW.obj_bt.isInitialized = 1L;
  digitalIOSetup(8, 1);
  H4_primera_Test_velocidad_DW.obj_bt.isSetupComplete = true;

  /* Start for MATLABSystem: '<S106>/Digital Output1' */
  H4_primera_Test_velocidad_DW.obj_l.matlabCodegenIsDeleted = false;
  H4_primera_Test_velocidad_DW.obj_l.isInitialized = 1L;
  digitalIOSetup(13, 1);
  H4_primera_Test_velocidad_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S105>/Encoder' */
  H4_primera_Test_velocidad_DW.obj_d.Index = 0U;
  H4_primera_Test_velocidad_DW.obj_d.matlabCodegenIsDeleted = false;
  H4_primera_Test_velocidad_DW.obj_d.SampleTime =
    H4_primera_Test_velocidad_P.Encoder_SampleTime;
  H4_primera_Test_velocidad_DW.obj_d.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &H4_primera_Test_velocidad_DW.obj_d.Index);
  H4_primera_Test_velocidad_DW.obj_d.isSetupComplete = true;
  H4_primera_Test_velocidad_DW.obj_d.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S105>/Encoder' */
  MW_EncoderReset(H4_primera_Test_velocidad_DW.obj_d.Index);

  /* Start for MATLABSystem: '<S105>/Encoder1' */
  H4_primera_Test_velocidad_DW.obj.Index = 0U;
  H4_primera_Test_velocidad_DW.obj.matlabCodegenIsDeleted = false;
  H4_primera_Test_velocidad_DW.obj.SampleTime =
    H4_primera_Test_velocidad_P.Encoder1_SampleTime;
  H4_primera_Test_velocidad_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &H4_primera_Test_velocidad_DW.obj.Index);
  H4_primera_Test_velocidad_DW.obj.isSetupComplete = true;
  H4_primera_Test_velocidad_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S105>/Encoder1' */
  MW_EncoderReset(H4_primera_Test_velocidad_DW.obj.Index);
}

/* Model terminate function */
void H4_primera_Test_velocidad_terminate(void)
{
  /* Terminate for MATLABSystem: '<S106>/Adelante_der' */
  if (!H4_primera_Test_velocidad_DW.obj_m5.matlabCodegenIsDeleted) {
    H4_primera_Test_velocidad_DW.obj_m5.matlabCodegenIsDeleted = true;
    if ((H4_primera_Test_velocidad_DW.obj_m5.isInitialized == 1L) &&
        H4_primera_Test_velocidad_DW.obj_m5.isSetupComplete) {
      H4_primera_Test_velocidad_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle
        (H4_primera_Test_velocidad_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      H4_primera_Test_velocidad_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(12UL);
      MW_PWM_Close
        (H4_primera_Test_velocidad_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S106>/Adelante_izq' */
  if (!H4_primera_Test_velocidad_DW.obj_dx.matlabCodegenIsDeleted) {
    H4_primera_Test_velocidad_DW.obj_dx.matlabCodegenIsDeleted = true;
    if ((H4_primera_Test_velocidad_DW.obj_dx.isInitialized == 1L) &&
        H4_primera_Test_velocidad_DW.obj_dx.isSetupComplete) {
      H4_primera_Test_velocidad_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle
        (H4_primera_Test_velocidad_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      H4_primera_Test_velocidad_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_Close
        (H4_primera_Test_velocidad_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S106>/Atras_der' */
  if (!H4_primera_Test_velocidad_DW.obj_b.matlabCodegenIsDeleted) {
    H4_primera_Test_velocidad_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((H4_primera_Test_velocidad_DW.obj_b.isInitialized == 1L) &&
        H4_primera_Test_velocidad_DW.obj_b.isSetupComplete) {
      H4_primera_Test_velocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle
        (H4_primera_Test_velocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      H4_primera_Test_velocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_Close(H4_primera_Test_velocidad_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/Atras_der' */

  /* Terminate for MATLABSystem: '<S106>/Atras_izq' */
  if (!H4_primera_Test_velocidad_DW.obj_m.matlabCodegenIsDeleted) {
    H4_primera_Test_velocidad_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((H4_primera_Test_velocidad_DW.obj_m.isInitialized == 1L) &&
        H4_primera_Test_velocidad_DW.obj_m.isSetupComplete) {
      H4_primera_Test_velocidad_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle
        (H4_primera_Test_velocidad_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      H4_primera_Test_velocidad_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(10UL);
      MW_PWM_Close(H4_primera_Test_velocidad_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S106>/Digital Output' */
  if (!H4_primera_Test_velocidad_DW.obj_bt.matlabCodegenIsDeleted) {
    H4_primera_Test_velocidad_DW.obj_bt.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S106>/Digital Output' */

  /* Terminate for MATLABSystem: '<S106>/Digital Output1' */
  if (!H4_primera_Test_velocidad_DW.obj_l.matlabCodegenIsDeleted) {
    H4_primera_Test_velocidad_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S106>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S105>/Encoder' */
  if (!H4_primera_Test_velocidad_DW.obj_d.matlabCodegenIsDeleted) {
    H4_primera_Test_velocidad_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((H4_primera_Test_velocidad_DW.obj_d.isInitialized == 1L) &&
        H4_primera_Test_velocidad_DW.obj_d.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S105>/Encoder' */

  /* Terminate for MATLABSystem: '<S105>/Encoder1' */
  if (!H4_primera_Test_velocidad_DW.obj.matlabCodegenIsDeleted) {
    H4_primera_Test_velocidad_DW.obj.matlabCodegenIsDeleted = true;
    if ((H4_primera_Test_velocidad_DW.obj.isInitialized == 1L) &&
        H4_primera_Test_velocidad_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S105>/Encoder1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
