/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestCinematica.c
 *
 * Code generated for Simulink model 'TestCinematica'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 30 15:08:29 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TestCinematica.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "TestCinematica_private.h"
#include "zero_crossing_types.h"

/* Block signals (default storage) */
B_TestCinematica_T TestCinematica_B;

/* Continuous states */
X_TestCinematica_T TestCinematica_X;

/* Disabled State Vector */
XDis_TestCinematica_T TestCinematica_XDis;

/* Block states (default storage) */
DW_TestCinematica_T TestCinematica_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_TestCinematica_T TestCinematica_PrevZCX;

/* Real-time model */
static RT_MODEL_TestCinematica_T TestCinematica_M_;
RT_MODEL_TestCinematica_T *const TestCinematica_M = &TestCinematica_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  TestCinematica_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  TestCinematica_step();
  TestCinematica_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  TestCinematica_step();
  TestCinematica_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void TestCinematica_step(void)
{
  if (rtmIsMajorTimeStep(TestCinematica_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&TestCinematica_M->solverInfo,
                          ((TestCinematica_M->Timing.clockTick0+1)*
      TestCinematica_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(TestCinematica_M)) {
    TestCinematica_M->Timing.t[0] = rtsiGetT(&TestCinematica_M->solverInfo);
  }

  {
    real_T (*lastU)[2];
    real_T lastTime;
    real_T u0;
    int32_T rtb_Gain;
    int32_T rtb_Saturation4;
    int16_T rtb_DataTypeConversion_idx_1;
    int16_T y;
    ZCEventType zcEvent;
    if (rtmIsMajorTimeStep(TestCinematica_M)) {
      /* Constant: '<Root>/Constant' */
      TestCinematica_B.rel[0] = TestCinematica_P.Constant_Value_j[0];
      TestCinematica_B.rel[1] = TestCinematica_P.Constant_Value_j[1];

      /* Sum: '<S1>/Sum' incorporates:
       *  Constant: '<S2>/Constant'
       *  Memory: '<S1>/Memory'
       *  Product: '<S2>/Matrix Multiply'
       */
      TestCinematica_B.error[0] = (TestCinematica_P.Constant_Value[0] *
        TestCinematica_B.rel[0] + TestCinematica_B.rel[1] *
        TestCinematica_P.Constant_Value[2]) -
        TestCinematica_DW.Memory_PreviousInput[0];
      TestCinematica_B.error[1] = (TestCinematica_B.rel[0] *
        TestCinematica_P.Constant_Value[1] + TestCinematica_B.rel[1] *
        TestCinematica_P.Constant_Value[3]) -
        TestCinematica_DW.Memory_PreviousInput[1];

      /* Gain: '<S45>/Proportional Gain' */
      TestCinematica_B.ProportionalGain = TestCinematica_P.PIDController_P *
        TestCinematica_B.error[0];
    }

    /* Integrator: '<S40>/Integrator' */
    if (rtsiIsModeUpdateTimeStep(&TestCinematica_M->solverInfo)) {
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &TestCinematica_PrevZCX.Integrator_Reset_ZCE,
                         (0.0));

      /* evaluate zero-crossings */
      if (zcEvent != NO_ZCEVENT) {
        TestCinematica_X.Integrator_CSTATE =
          TestCinematica_P.PIDController_InitialConditionF;
      }
    }

    /* Sum: '<S49>/Sum' incorporates:
     *  Integrator: '<S40>/Integrator'
     */
    TestCinematica_B.Saturation = TestCinematica_B.ProportionalGain +
      TestCinematica_X.Integrator_CSTATE;

    /* Saturate: '<S47>/Saturation' */
    if (TestCinematica_B.Saturation >
        TestCinematica_P.PIDController_UpperSaturationLi) {
      /* Sum: '<S49>/Sum' incorporates:
       *  Saturate: '<S47>/Saturation'
       */
      TestCinematica_B.Saturation =
        TestCinematica_P.PIDController_UpperSaturationLi;
    } else if (TestCinematica_B.Saturation <
               TestCinematica_P.PIDController_LowerSaturationLi) {
      /* Sum: '<S49>/Sum' incorporates:
       *  Saturate: '<S47>/Saturation'
       */
      TestCinematica_B.Saturation =
        TestCinematica_P.PIDController_LowerSaturationLi;
    }

    /* End of Saturate: '<S47>/Saturation' */
    if (rtmIsMajorTimeStep(TestCinematica_M)) {
      /* Gain: '<S93>/Proportional Gain' */
      TestCinematica_B.ProportionalGain_c = TestCinematica_P.PIDController1_P *
        TestCinematica_B.error[1];
    }

    /* Sum: '<S97>/Sum' incorporates:
     *  Integrator: '<S88>/Integrator'
     */
    TestCinematica_B.Saturation_g = TestCinematica_B.ProportionalGain_c +
      TestCinematica_X.Integrator_CSTATE_h;

    /* Saturate: '<S95>/Saturation' */
    if (TestCinematica_B.Saturation_g >
        TestCinematica_P.PIDController1_UpperSaturationL) {
      /* Sum: '<S97>/Sum' incorporates:
       *  Saturate: '<S95>/Saturation'
       */
      TestCinematica_B.Saturation_g =
        TestCinematica_P.PIDController1_UpperSaturationL;
    } else if (TestCinematica_B.Saturation_g <
               TestCinematica_P.PIDController1_LowerSaturationL) {
      /* Sum: '<S97>/Sum' incorporates:
       *  Saturate: '<S95>/Saturation'
       */
      TestCinematica_B.Saturation_g =
        TestCinematica_P.PIDController1_LowerSaturationL;
    }

    /* End of Saturate: '<S95>/Saturation' */
    if (rtmIsMajorTimeStep(TestCinematica_M)) {
      /* SignalConversion generated from: '<S1>/Controlador' */
      TestCinematica_B.pwm[0] = TestCinematica_B.Saturation;
      TestCinematica_B.pwm[1] = TestCinematica_B.Saturation_g;
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    u0 = floor(TestCinematica_B.Saturation);
    if (rtIsNaN(u0) || rtIsInf(u0)) {
      u0 = 0.0;
    } else {
      u0 = fmod(u0, 65536.0);
    }

    lastTime = floor(TestCinematica_B.Saturation_g);
    if (rtIsNaN(lastTime) || rtIsInf(lastTime)) {
      lastTime = 0.0;
    } else {
      lastTime = fmod(lastTime, 65536.0);
    }

    rtb_DataTypeConversion_idx_1 = lastTime < 0.0 ? -(int16_T)(uint16_T)
      -lastTime : (int16_T)(uint16_T)lastTime;

    /* MATLABSystem: '<S107>/Adelante_der' */
    TestCinematica_DW.obj_ht.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

    /* Saturate: '<S107>/Saturation2' */
    if (rtb_DataTypeConversion_idx_1 > TestCinematica_P.Saturation2_UpperSat) {
      y = TestCinematica_P.Saturation2_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               TestCinematica_P.Saturation2_LowerSat) {
      y = TestCinematica_P.Saturation2_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
    }

    /* End of Saturate: '<S107>/Saturation2' */

    /* Start for MATLABSystem: '<S107>/Adelante_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S107>/Adelante_der' */
    MW_PWM_SetDutyCycle(TestCinematica_DW.obj_ht.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* Gain: '<S107>/Gain' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     */
    rtb_Gain = (int32_T)(u0 < 0.0 ? -(int16_T)(uint16_T)-u0 : (int16_T)(uint16_T)
                         u0) * TestCinematica_P.Gain_Gain_o;

    /* MATLABSystem: '<S107>/Digital Output' incorporates:
     *  Constant: '<S108>/Constant'
     *  Gain: '<S107>/Gain'
     *  RelationalOperator: '<S108>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_Gain != TestCinematica_P.Constant_Value_bh));

    /* Saturate: '<S107>/Saturation4' incorporates:
     *  Gain: '<S107>/Gain'
     */
    if (rtb_Gain > TestCinematica_P.Saturation4_UpperSat) {
      rtb_Saturation4 = TestCinematica_P.Saturation4_UpperSat;
    } else if (rtb_Gain < TestCinematica_P.Saturation4_LowerSat) {
      rtb_Saturation4 = TestCinematica_P.Saturation4_LowerSat;
    } else {
      rtb_Saturation4 = rtb_Gain;
    }

    /* End of Saturate: '<S107>/Saturation4' */

    /* MATLABSystem: '<S107>/Adelante_izq' */
    TestCinematica_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* Abs: '<S107>/Abs2' incorporates:
     *  Saturate: '<S107>/Saturation4'
     */
    if (rtb_Saturation4 < 0L) {
      rtb_Saturation4 = -rtb_Saturation4;
    }

    /* Start for MATLABSystem: '<S107>/Adelante_izq' incorporates:
     *  Abs: '<S107>/Abs2'
     */
    u0 = (real_T)rtb_Saturation4 * 6.103515625E-5;
    if (!(u0 <= 255.0)) {
      u0 = 255.0;
    }

    if (!(u0 >= 0.0)) {
      u0 = 0.0;
    }

    /* MATLABSystem: '<S107>/Adelante_izq' */
    MW_PWM_SetDutyCycle(TestCinematica_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, u0);

    /* MATLABSystem: '<S107>/Atras_izq' */
    TestCinematica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Saturate: '<S107>/Saturation5' incorporates:
     *  Gain: '<S107>/Gain'
     */
    if (rtb_Gain > TestCinematica_P.Saturation5_UpperSat) {
      rtb_Gain = TestCinematica_P.Saturation5_UpperSat;
    } else if (rtb_Gain < TestCinematica_P.Saturation5_LowerSat) {
      rtb_Gain = TestCinematica_P.Saturation5_LowerSat;
    }

    /* Start for MATLABSystem: '<S107>/Atras_izq' incorporates:
     *  Saturate: '<S107>/Saturation5'
     */
    u0 = (real_T)rtb_Gain * 6.103515625E-5;
    if (!(u0 <= 255.0)) {
      u0 = 255.0;
    }

    if (!(u0 >= 0.0)) {
      u0 = 0.0;
    }

    /* MATLABSystem: '<S107>/Atras_izq' */
    MW_PWM_SetDutyCycle(TestCinematica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, u0);

    /* MATLABSystem: '<S107>/Atras_der' */
    TestCinematica_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* Saturate: '<S107>/Saturation3' */
    if (rtb_DataTypeConversion_idx_1 > TestCinematica_P.Saturation3_UpperSat) {
      y = TestCinematica_P.Saturation3_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               TestCinematica_P.Saturation3_LowerSat) {
      y = TestCinematica_P.Saturation3_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
    }

    /* End of Saturate: '<S107>/Saturation3' */

    /* Abs: '<S107>/Abs1' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S107>/Abs1' */

    /* Start for MATLABSystem: '<S107>/Atras_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S107>/Atras_der' */
    MW_PWM_SetDutyCycle(TestCinematica_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S107>/Digital Output1' incorporates:
     *  Constant: '<S109>/Constant'
     *  RelationalOperator: '<S109>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
      TestCinematica_P.Constant_Value_a));

    /* Integrator: '<S4>/Integrator' */
    TestCinematica_B.Integrator[0] = TestCinematica_X.Integrator_CSTATE_n[0];
    TestCinematica_B.Integrator[1] = TestCinematica_X.Integrator_CSTATE_n[1];
    TestCinematica_B.Integrator[2] = TestCinematica_X.Integrator_CSTATE_n[2];
    if (rtmIsMajorTimeStep(TestCinematica_M)) {
      /* Gain: '<S37>/Integral Gain' */
      TestCinematica_B.IntegralGain = TestCinematica_P.PIDController_I *
        TestCinematica_B.error[0];

      /* Gain: '<S85>/Integral Gain' */
      TestCinematica_B.IntegralGain_c = TestCinematica_P.PIDController1_I *
        TestCinematica_B.error[1];
    }

    /* MATLABSystem: '<S106>/Encoder' */
    if (TestCinematica_DW.obj_d.SampleTime !=
        TestCinematica_P.Encoder_SampleTime) {
      TestCinematica_DW.obj_d.SampleTime = TestCinematica_P.Encoder_SampleTime;
    }

    if (TestCinematica_DW.obj_d.TunablePropsChanged) {
      TestCinematica_DW.obj_d.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S106>/Encoder' */
    MW_EncoderRead(TestCinematica_DW.obj_d.Index, &TestCinematica_B.Encoder);

    /* MATLABSystem: '<S106>/Encoder1' */
    if (TestCinematica_DW.obj.SampleTime != TestCinematica_P.Encoder1_SampleTime)
    {
      TestCinematica_DW.obj.SampleTime = TestCinematica_P.Encoder1_SampleTime;
    }

    if (TestCinematica_DW.obj.TunablePropsChanged) {
      TestCinematica_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S106>/Encoder1' */
    MW_EncoderRead(TestCinematica_DW.obj.Index, &TestCinematica_B.Encoder1);

    /* Gain: '<S106>/Gain' */
    u0 = (real_T)TestCinematica_P.Gain_Gain * 1.1368683772161603E-13;

    /* Gain: '<S106>/Gain' incorporates:
     *  SignalConversion generated from: '<S106>/Gain'
     */
    TestCinematica_B.Gain[0] = u0 * (real_T)TestCinematica_B.Encoder;
    TestCinematica_B.Gain[1] = u0 * (real_T)TestCinematica_B.Encoder1;

    /* Derivative: '<S106>/Derivative' */
    u0 = TestCinematica_M->Timing.t[0];
    if ((TestCinematica_DW.TimeStampA >= u0) && (TestCinematica_DW.TimeStampB >=
         u0)) {
      /* Derivative: '<S106>/Derivative' */
      TestCinematica_B.Derivative[0] = 0.0;
      TestCinematica_B.Derivative[1] = 0.0;
    } else {
      lastTime = TestCinematica_DW.TimeStampA;
      lastU = &TestCinematica_DW.LastUAtTimeA;
      if (TestCinematica_DW.TimeStampA < TestCinematica_DW.TimeStampB) {
        if (TestCinematica_DW.TimeStampB < u0) {
          lastTime = TestCinematica_DW.TimeStampB;
          lastU = &TestCinematica_DW.LastUAtTimeB;
        }
      } else if (TestCinematica_DW.TimeStampA >= u0) {
        lastTime = TestCinematica_DW.TimeStampB;
        lastU = &TestCinematica_DW.LastUAtTimeB;
      }

      u0 -= lastTime;

      /* Derivative: '<S106>/Derivative' */
      TestCinematica_B.Derivative[0] = (TestCinematica_B.Gain[0] - (*lastU)[0]) /
        u0;
      TestCinematica_B.Derivative[1] = (TestCinematica_B.Gain[1] - (*lastU)[1]) /
        u0;
    }

    /* End of Derivative: '<S106>/Derivative' */

    /* Product: '<S3>/Matrix Multiply' incorporates:
     *  Constant: '<S3>/Constant'
     */
    u0 = TestCinematica_P.Constant_Value_b[0] * TestCinematica_B.Derivative[0] +
      TestCinematica_B.Derivative[1] * TestCinematica_P.Constant_Value_b[2];

    /* SignalConversion generated from: '<S4>/Integrator' incorporates:
     *  Constant: '<S3>/Constant'
     *  Product: '<S3>/Matrix Multiply'
     *  Product: '<S4>/Product'
     *  Product: '<S4>/Product1'
     *  Trigonometry: '<S4>/Cos'
     *  Trigonometry: '<S4>/Sin'
     */
    TestCinematica_B.TmpSignalConversionAtIntegrator[0] = cos
      (TestCinematica_B.Integrator[2]) * u0;
    TestCinematica_B.TmpSignalConversionAtIntegrator[1] = u0 * sin
      (TestCinematica_B.Integrator[2]);
    TestCinematica_B.TmpSignalConversionAtIntegrator[2] =
      TestCinematica_B.Derivative[0] * TestCinematica_P.Constant_Value_b[1] +
      TestCinematica_B.Derivative[1] * TestCinematica_P.Constant_Value_b[3];
    if (rtmIsMajorTimeStep(TestCinematica_M)) {
      /* SignalConversion generated from: '<S106>/Mux' */
      TestCinematica_B.TmpSignalConversionAtTAQSigLogg[0] =
        TestCinematica_B.Encoder;
      TestCinematica_B.TmpSignalConversionAtTAQSigLogg[1] =
        TestCinematica_B.Encoder1;
    }
  }

  if (rtmIsMajorTimeStep(TestCinematica_M)) {
    real_T (*lastU)[2];
    if (rtmIsMajorTimeStep(TestCinematica_M)) {
      /* Update for Memory: '<S1>/Memory' */
      TestCinematica_DW.Memory_PreviousInput[0] = TestCinematica_B.Derivative[0];
      TestCinematica_DW.Memory_PreviousInput[1] = TestCinematica_B.Derivative[1];
    }

    /* Update for Derivative: '<S106>/Derivative' */
    if (TestCinematica_DW.TimeStampA == (rtInf)) {
      TestCinematica_DW.TimeStampA = TestCinematica_M->Timing.t[0];
      lastU = &TestCinematica_DW.LastUAtTimeA;
    } else if (TestCinematica_DW.TimeStampB == (rtInf)) {
      TestCinematica_DW.TimeStampB = TestCinematica_M->Timing.t[0];
      lastU = &TestCinematica_DW.LastUAtTimeB;
    } else if (TestCinematica_DW.TimeStampA < TestCinematica_DW.TimeStampB) {
      TestCinematica_DW.TimeStampA = TestCinematica_M->Timing.t[0];
      lastU = &TestCinematica_DW.LastUAtTimeA;
    } else {
      TestCinematica_DW.TimeStampB = TestCinematica_M->Timing.t[0];
      lastU = &TestCinematica_DW.LastUAtTimeB;
    }

    (*lastU)[0] = TestCinematica_B.Gain[0];
    (*lastU)[1] = TestCinematica_B.Gain[1];

    /* End of Update for Derivative: '<S106>/Derivative' */
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((TestCinematica_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(TestCinematica_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((TestCinematica_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(TestCinematica_M)) {
    rt_ertODEUpdateContinuousStates(&TestCinematica_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++TestCinematica_M->Timing.clockTick0;
    TestCinematica_M->Timing.t[0] = rtsiGetSolverStopTime
      (&TestCinematica_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      TestCinematica_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void TestCinematica_derivatives(void)
{
  XDot_TestCinematica_T *_rtXdot;
  _rtXdot = ((XDot_TestCinematica_T *) TestCinematica_M->derivs);

  /* Derivatives for Integrator: '<S40>/Integrator' */
  _rtXdot->Integrator_CSTATE = TestCinematica_B.IntegralGain;

  /* Derivatives for Integrator: '<S88>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = TestCinematica_B.IntegralGain_c;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE_n[0] =
    TestCinematica_B.TmpSignalConversionAtIntegrator[0];
  _rtXdot->Integrator_CSTATE_n[1] =
    TestCinematica_B.TmpSignalConversionAtIntegrator[1];
  _rtXdot->Integrator_CSTATE_n[2] =
    TestCinematica_B.TmpSignalConversionAtIntegrator[2];
}

/* Model initialize function */
void TestCinematica_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TestCinematica_M->solverInfo,
                          &TestCinematica_M->Timing.simTimeStep);
    rtsiSetTPtr(&TestCinematica_M->solverInfo, &rtmGetTPtr(TestCinematica_M));
    rtsiSetStepSizePtr(&TestCinematica_M->solverInfo,
                       &TestCinematica_M->Timing.stepSize0);
    rtsiSetdXPtr(&TestCinematica_M->solverInfo, &TestCinematica_M->derivs);
    rtsiSetContStatesPtr(&TestCinematica_M->solverInfo, (real_T **)
                         &TestCinematica_M->contStates);
    rtsiSetNumContStatesPtr(&TestCinematica_M->solverInfo,
      &TestCinematica_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&TestCinematica_M->solverInfo,
      &TestCinematica_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&TestCinematica_M->solverInfo,
      &TestCinematica_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&TestCinematica_M->solverInfo,
      &TestCinematica_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&TestCinematica_M->solverInfo, (boolean_T**)
      &TestCinematica_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&TestCinematica_M->solverInfo, (&rtmGetErrorStatus
      (TestCinematica_M)));
    rtsiSetRTModelPtr(&TestCinematica_M->solverInfo, TestCinematica_M);
  }

  rtsiSetSimTimeStep(&TestCinematica_M->solverInfo, MAJOR_TIME_STEP);
  TestCinematica_M->intgData.y = TestCinematica_M->odeY;
  TestCinematica_M->intgData.f[0] = TestCinematica_M->odeF[0];
  TestCinematica_M->intgData.f[1] = TestCinematica_M->odeF[1];
  TestCinematica_M->intgData.f[2] = TestCinematica_M->odeF[2];
  TestCinematica_M->contStates = ((X_TestCinematica_T *) &TestCinematica_X);
  TestCinematica_M->contStateDisabled = ((XDis_TestCinematica_T *)
    &TestCinematica_XDis);
  TestCinematica_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&TestCinematica_M->solverInfo, (void *)
                    &TestCinematica_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&TestCinematica_M->solverInfo, false);
  rtsiSetSolverName(&TestCinematica_M->solverInfo,"ode3");
  rtmSetTPtr(TestCinematica_M, &TestCinematica_M->Timing.tArray[0]);
  rtmSetTFinal(TestCinematica_M, -1);
  TestCinematica_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  TestCinematica_M->Sizes.checksums[0] = (3882150403U);
  TestCinematica_M->Sizes.checksums[1] = (2432760369U);
  TestCinematica_M->Sizes.checksums[2] = (17109570U);
  TestCinematica_M->Sizes.checksums[3] = (3357337002U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    TestCinematica_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(TestCinematica_M->extModeInfo,
      &TestCinematica_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TestCinematica_M->extModeInfo,
                        TestCinematica_M->Sizes.checksums);
    rteiSetTPtr(TestCinematica_M->extModeInfo, rtmGetTPtr(TestCinematica_M));
  }

  TestCinematica_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Memory: '<S1>/Memory' */
  TestCinematica_DW.Memory_PreviousInput[0] =
    TestCinematica_P.Memory_InitialCondition;
  TestCinematica_DW.Memory_PreviousInput[1] =
    TestCinematica_P.Memory_InitialCondition;

  /* InitializeConditions for Integrator: '<S40>/Integrator' */
  TestCinematica_X.Integrator_CSTATE =
    TestCinematica_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S88>/Integrator' */
  TestCinematica_X.Integrator_CSTATE_h =
    TestCinematica_P.PIDController1_InitialCondition;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  TestCinematica_X.Integrator_CSTATE_n[0] = TestCinematica_P.Integrator_IC;
  TestCinematica_X.Integrator_CSTATE_n[1] = TestCinematica_P.Integrator_IC;
  TestCinematica_X.Integrator_CSTATE_n[2] = TestCinematica_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S106>/Derivative' */
  TestCinematica_DW.TimeStampA = (rtInf);
  TestCinematica_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<S107>/Adelante_der' */
  TestCinematica_DW.obj_ht.matlabCodegenIsDeleted = false;
  TestCinematica_DW.obj_ht.isInitialized = 1L;
  TestCinematica_DW.obj_ht.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0,
    0.0);
  TestCinematica_DW.obj_ht.isSetupComplete = true;

  /* Start for MATLABSystem: '<S107>/Digital Output' */
  TestCinematica_DW.obj_n.matlabCodegenIsDeleted = false;
  TestCinematica_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(8, 1);
  TestCinematica_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S107>/Adelante_izq' */
  TestCinematica_DW.obj_f.matlabCodegenIsDeleted = false;
  TestCinematica_DW.obj_f.isInitialized = 1L;
  TestCinematica_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  TestCinematica_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S107>/Atras_izq' */
  TestCinematica_DW.obj_g.matlabCodegenIsDeleted = false;
  TestCinematica_DW.obj_g.isInitialized = 1L;
  TestCinematica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0,
    0.0);
  TestCinematica_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S107>/Atras_der' */
  TestCinematica_DW.obj_h.matlabCodegenIsDeleted = false;
  TestCinematica_DW.obj_h.isInitialized = 1L;
  TestCinematica_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  TestCinematica_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S107>/Digital Output1' */
  TestCinematica_DW.obj_a.matlabCodegenIsDeleted = false;
  TestCinematica_DW.obj_a.isInitialized = 1L;
  digitalIOSetup(13, 1);
  TestCinematica_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S106>/Encoder' */
  TestCinematica_DW.obj_d.Index = 0U;
  TestCinematica_DW.obj_d.matlabCodegenIsDeleted = false;
  TestCinematica_DW.obj_d.SampleTime = TestCinematica_P.Encoder_SampleTime;
  TestCinematica_DW.obj_d.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &TestCinematica_DW.obj_d.Index);
  TestCinematica_DW.obj_d.isSetupComplete = true;
  TestCinematica_DW.obj_d.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S106>/Encoder' */
  MW_EncoderReset(TestCinematica_DW.obj_d.Index);

  /* Start for MATLABSystem: '<S106>/Encoder1' */
  TestCinematica_DW.obj.Index = 0U;
  TestCinematica_DW.obj.matlabCodegenIsDeleted = false;
  TestCinematica_DW.obj.SampleTime = TestCinematica_P.Encoder1_SampleTime;
  TestCinematica_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &TestCinematica_DW.obj.Index);
  TestCinematica_DW.obj.isSetupComplete = true;
  TestCinematica_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S106>/Encoder1' */
  MW_EncoderReset(TestCinematica_DW.obj.Index);
}

/* Model terminate function */
void TestCinematica_terminate(void)
{
  /* Terminate for MATLABSystem: '<S107>/Adelante_der' */
  if (!TestCinematica_DW.obj_ht.matlabCodegenIsDeleted) {
    TestCinematica_DW.obj_ht.matlabCodegenIsDeleted = true;
    if ((TestCinematica_DW.obj_ht.isInitialized == 1L) &&
        TestCinematica_DW.obj_ht.isSetupComplete) {
      TestCinematica_DW.obj_ht.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_SetDutyCycle(TestCinematica_DW.obj_ht.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      TestCinematica_DW.obj_ht.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_Close(TestCinematica_DW.obj_ht.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S107>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S107>/Digital Output' */
  if (!TestCinematica_DW.obj_n.matlabCodegenIsDeleted) {
    TestCinematica_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S107>/Digital Output' */

  /* Terminate for MATLABSystem: '<S107>/Adelante_izq' */
  if (!TestCinematica_DW.obj_f.matlabCodegenIsDeleted) {
    TestCinematica_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((TestCinematica_DW.obj_f.isInitialized == 1L) &&
        TestCinematica_DW.obj_f.isSetupComplete) {
      TestCinematica_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(TestCinematica_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      TestCinematica_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(TestCinematica_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S107>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S107>/Atras_izq' */
  if (!TestCinematica_DW.obj_g.matlabCodegenIsDeleted) {
    TestCinematica_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((TestCinematica_DW.obj_g.isInitialized == 1L) &&
        TestCinematica_DW.obj_g.isSetupComplete) {
      TestCinematica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(TestCinematica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      TestCinematica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(TestCinematica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S107>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S107>/Atras_der' */
  if (!TestCinematica_DW.obj_h.matlabCodegenIsDeleted) {
    TestCinematica_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((TestCinematica_DW.obj_h.isInitialized == 1L) &&
        TestCinematica_DW.obj_h.isSetupComplete) {
      TestCinematica_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(TestCinematica_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      TestCinematica_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(TestCinematica_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S107>/Atras_der' */

  /* Terminate for MATLABSystem: '<S107>/Digital Output1' */
  if (!TestCinematica_DW.obj_a.matlabCodegenIsDeleted) {
    TestCinematica_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S107>/Digital Output1' */
  /* Terminate for MATLABSystem: '<S106>/Encoder' */
  if (!TestCinematica_DW.obj_d.matlabCodegenIsDeleted) {
    TestCinematica_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((TestCinematica_DW.obj_d.isInitialized == 1L) &&
        TestCinematica_DW.obj_d.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/Encoder' */

  /* Terminate for MATLABSystem: '<S106>/Encoder1' */
  if (!TestCinematica_DW.obj.matlabCodegenIsDeleted) {
    TestCinematica_DW.obj.matlabCodegenIsDeleted = true;
    if ((TestCinematica_DW.obj.isInitialized == 1L) &&
        TestCinematica_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/Encoder1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
