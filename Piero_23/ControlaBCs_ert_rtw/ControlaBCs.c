/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlaBCs.c
 *
 * Code generated for Simulink model 'ControlaBCs'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Dec 17 23:20:50 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ControlaBCs.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "ControlaBCs_private.h"

/* Block signals (default storage) */
B_ControlaBCs_T ControlaBCs_B;

/* Continuous states */
X_ControlaBCs_T ControlaBCs_X;

/* Disabled State Vector */
XDis_ControlaBCs_T ControlaBCs_XDis;

/* Block states (default storage) */
DW_ControlaBCs_T ControlaBCs_DW;

/* Real-time model */
static RT_MODEL_ControlaBCs_T ControlaBCs_M_;
RT_MODEL_ControlaBCs_T *const ControlaBCs_M = &ControlaBCs_M_;

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
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ControlaBCs_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ControlaBCs_step();
  ControlaBCs_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ControlaBCs_step();
  ControlaBCs_derivatives();

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
void ControlaBCs_step(void)
{
  if (rtmIsMajorTimeStep(ControlaBCs_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&ControlaBCs_M->solverInfo,
                          ((ControlaBCs_M->Timing.clockTick0+1)*
      ControlaBCs_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ControlaBCs_M)) {
    ControlaBCs_M->Timing.t[0] = rtsiGetT(&ControlaBCs_M->solverInfo);
  }

  {
    real_T (*lastU)[2];
    real_T Gain_tmp;
    real_T lastTime;
    real_T rtb_error_idx_0;
    real_T rtb_error_idx_1;
    int16_T rtb_DataTypeConversion_idx_0;
    int16_T rtb_DataTypeConversion_idx_1;
    int16_T y;

    /* MATLABSystem: '<S4>/Encoder' */
    if (ControlaBCs_DW.obj_e.SampleTime != ControlaBCs_P.Encoder_SampleTime) {
      ControlaBCs_DW.obj_e.SampleTime = ControlaBCs_P.Encoder_SampleTime;
    }

    if (ControlaBCs_DW.obj_e.TunablePropsChanged) {
      ControlaBCs_DW.obj_e.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S4>/Encoder' */
    MW_EncoderRead(ControlaBCs_DW.obj_e.Index, &ControlaBCs_B.Encoder);

    /* MATLABSystem: '<S4>/Encoder1' */
    if (ControlaBCs_DW.obj.SampleTime != ControlaBCs_P.Encoder1_SampleTime) {
      ControlaBCs_DW.obj.SampleTime = ControlaBCs_P.Encoder1_SampleTime;
    }

    if (ControlaBCs_DW.obj.TunablePropsChanged) {
      ControlaBCs_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S4>/Encoder1' */
    MW_EncoderRead(ControlaBCs_DW.obj.Index, &ControlaBCs_B.Encoder1);

    /* Gain: '<S4>/Gain' */
    Gain_tmp = (real_T)ControlaBCs_P.Gain_Gain * 1.1368683772161603E-13;

    /* Gain: '<S4>/Gain' incorporates:
     *  SignalConversion generated from: '<S4>/Gain'
     */
    ControlaBCs_B.Gain[0] = Gain_tmp * (real_T)ControlaBCs_B.Encoder;
    ControlaBCs_B.Gain[1] = Gain_tmp * (real_T)ControlaBCs_B.Encoder1;
    if (rtmIsMajorTimeStep(ControlaBCs_M)) {
    }

    /* Derivative: '<S4>/Derivative' */
    Gain_tmp = ControlaBCs_M->Timing.t[0];
    if ((ControlaBCs_DW.TimeStampA >= Gain_tmp) && (ControlaBCs_DW.TimeStampB >=
         Gain_tmp)) {
      /* Derivative: '<S4>/Derivative' */
      ControlaBCs_B.Derivative[0] = 0.0;
      ControlaBCs_B.Derivative[1] = 0.0;
    } else {
      lastTime = ControlaBCs_DW.TimeStampA;
      lastU = &ControlaBCs_DW.LastUAtTimeA;
      if (ControlaBCs_DW.TimeStampA < ControlaBCs_DW.TimeStampB) {
        if (ControlaBCs_DW.TimeStampB < Gain_tmp) {
          lastTime = ControlaBCs_DW.TimeStampB;
          lastU = &ControlaBCs_DW.LastUAtTimeB;
        }
      } else if (ControlaBCs_DW.TimeStampA >= Gain_tmp) {
        lastTime = ControlaBCs_DW.TimeStampB;
        lastU = &ControlaBCs_DW.LastUAtTimeB;
      }

      Gain_tmp -= lastTime;

      /* Derivative: '<S4>/Derivative' */
      ControlaBCs_B.Derivative[0] = (ControlaBCs_B.Gain[0] - (*lastU)[0]) /
        Gain_tmp;
      ControlaBCs_B.Derivative[1] = (ControlaBCs_B.Gain[1] - (*lastU)[1]) /
        Gain_tmp;
    }

    /* End of Derivative: '<S4>/Derivative' */
    if (rtmIsMajorTimeStep(ControlaBCs_M)) {
      /* SignalConversion generated from: '<S4>/Mux' */
      ControlaBCs_B.TmpSignalConversionAtTAQSigLogg[0] = ControlaBCs_B.Encoder;
      ControlaBCs_B.TmpSignalConversionAtTAQSigLogg[1] = ControlaBCs_B.Encoder1;

      /* Sum: '<Root>/Sum' incorporates:
       *  Constant: '<Root>/Constant'
       *  Memory: '<Root>/Memory'
       */
      rtb_error_idx_0 = ControlaBCs_P.Constant_Value[0] -
        ControlaBCs_DW.Memory_PreviousInput[0];
      rtb_error_idx_1 = ControlaBCs_P.Constant_Value[1] -
        ControlaBCs_DW.Memory_PreviousInput[1];

      /* Gain: '<S94>/Proportional Gain' */
      ControlaBCs_B.ProportionalGain = ControlaBCs_P.PIDController2_P *
        rtb_error_idx_0;

      /* Gain: '<S46>/Proportional Gain' */
      ControlaBCs_B.ProportionalGain_p = ControlaBCs_P.PIDController1_P *
        rtb_error_idx_1;
    }

    /* Sum: '<S98>/Sum' incorporates:
     *  Integrator: '<S89>/Integrator'
     */
    Gain_tmp = ControlaBCs_B.ProportionalGain + ControlaBCs_X.Integrator_CSTATE;

    /* Saturate: '<S96>/Saturation' */
    if (Gain_tmp > ControlaBCs_P.PIDController2_UpperSaturationL) {
      Gain_tmp = ControlaBCs_P.PIDController2_UpperSaturationL;
    } else if (Gain_tmp < ControlaBCs_P.PIDController2_LowerSaturationL) {
      Gain_tmp = ControlaBCs_P.PIDController2_LowerSaturationL;
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Saturate: '<S96>/Saturation'
     */
    Gain_tmp = floor(Gain_tmp);
    if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
      Gain_tmp = 0.0;
    } else {
      Gain_tmp = fmod(Gain_tmp, 65536.0);
    }

    rtb_DataTypeConversion_idx_0 = Gain_tmp < 0.0 ? -(int16_T)(uint16_T)
      -Gain_tmp : (int16_T)(uint16_T)Gain_tmp;

    /* Sum: '<S50>/Sum' incorporates:
     *  Integrator: '<S41>/Integrator'
     */
    Gain_tmp = ControlaBCs_B.ProportionalGain_p +
      ControlaBCs_X.Integrator_CSTATE_c;

    /* Saturate: '<S48>/Saturation' */
    if (Gain_tmp > ControlaBCs_P.PIDController1_UpperSaturationL) {
      Gain_tmp = ControlaBCs_P.PIDController1_UpperSaturationL;
    } else if (Gain_tmp < ControlaBCs_P.PIDController1_LowerSaturationL) {
      Gain_tmp = ControlaBCs_P.PIDController1_LowerSaturationL;
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Saturate: '<S48>/Saturation'
     */
    Gain_tmp = floor(Gain_tmp);
    if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
      Gain_tmp = 0.0;
    } else {
      Gain_tmp = fmod(Gain_tmp, 65536.0);
    }

    rtb_DataTypeConversion_idx_1 = Gain_tmp < 0.0 ? -(int16_T)(uint16_T)
      -Gain_tmp : (int16_T)(uint16_T)Gain_tmp;

    /* MATLABSystem: '<S5>/Adelante_der' */
    ControlaBCs_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

    /* Saturate: '<S5>/Saturation2' */
    if (rtb_DataTypeConversion_idx_1 > ControlaBCs_P.Saturation2_UpperSat) {
      y = ControlaBCs_P.Saturation2_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 < ControlaBCs_P.Saturation2_LowerSat)
    {
      y = ControlaBCs_P.Saturation2_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
    }

    /* End of Saturate: '<S5>/Saturation2' */

    /* Start for MATLABSystem: '<S5>/Adelante_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S5>/Adelante_der' */
    MW_PWM_SetDutyCycle(ControlaBCs_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                        y);

    /* MATLABSystem: '<S5>/Adelante_izq' */
    ControlaBCs_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* Saturate: '<S5>/Saturation4' */
    if (rtb_DataTypeConversion_idx_0 > ControlaBCs_P.Saturation4_UpperSat) {
      y = ControlaBCs_P.Saturation4_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 < ControlaBCs_P.Saturation4_LowerSat)
    {
      y = ControlaBCs_P.Saturation4_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_0;
    }

    /* End of Saturate: '<S5>/Saturation4' */

    /* Abs: '<S5>/Abs2' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S5>/Abs2' */

    /* Start for MATLABSystem: '<S5>/Adelante_izq' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S5>/Adelante_izq' */
    MW_PWM_SetDutyCycle(ControlaBCs_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                        y);

    /* MATLABSystem: '<S5>/Atras_der' */
    ControlaBCs_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* Saturate: '<S5>/Saturation3' */
    if (rtb_DataTypeConversion_idx_1 > ControlaBCs_P.Saturation3_UpperSat) {
      y = ControlaBCs_P.Saturation3_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 < ControlaBCs_P.Saturation3_LowerSat)
    {
      y = ControlaBCs_P.Saturation3_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
    }

    /* End of Saturate: '<S5>/Saturation3' */

    /* Abs: '<S5>/Abs1' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S5>/Abs1' */

    /* Start for MATLABSystem: '<S5>/Atras_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S5>/Atras_der' */
    MW_PWM_SetDutyCycle(ControlaBCs_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S5>/Atras_izq' */
    ControlaBCs_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Saturate: '<S5>/Saturation5' */
    if (rtb_DataTypeConversion_idx_0 > ControlaBCs_P.Saturation5_UpperSat) {
      y = ControlaBCs_P.Saturation5_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 < ControlaBCs_P.Saturation5_LowerSat)
    {
      y = ControlaBCs_P.Saturation5_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_0;
    }

    /* End of Saturate: '<S5>/Saturation5' */

    /* Start for MATLABSystem: '<S5>/Atras_izq' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S5>/Atras_izq' */
    MW_PWM_SetDutyCycle(ControlaBCs_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                        y);

    /* MATLABSystem: '<S5>/Digital Output' incorporates:
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S6>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
      ControlaBCs_P.Constant_Value_h));

    /* MATLABSystem: '<S5>/Digital Output1' incorporates:
     *  Constant: '<S7>/Constant'
     *  RelationalOperator: '<S7>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
      ControlaBCs_P.Constant_Value_g));
    if (rtmIsMajorTimeStep(ControlaBCs_M)) {
      /* Gain: '<S38>/Integral Gain' */
      ControlaBCs_B.IntegralGain = ControlaBCs_P.PIDController1_I *
        rtb_error_idx_1;

      /* Gain: '<S86>/Integral Gain' */
      ControlaBCs_B.IntegralGain_e = ControlaBCs_P.PIDController2_I *
        rtb_error_idx_0;
    }
  }

  if (rtmIsMajorTimeStep(ControlaBCs_M)) {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S4>/Derivative' */
    if (ControlaBCs_DW.TimeStampA == (rtInf)) {
      ControlaBCs_DW.TimeStampA = ControlaBCs_M->Timing.t[0];
      lastU = &ControlaBCs_DW.LastUAtTimeA;
    } else if (ControlaBCs_DW.TimeStampB == (rtInf)) {
      ControlaBCs_DW.TimeStampB = ControlaBCs_M->Timing.t[0];
      lastU = &ControlaBCs_DW.LastUAtTimeB;
    } else if (ControlaBCs_DW.TimeStampA < ControlaBCs_DW.TimeStampB) {
      ControlaBCs_DW.TimeStampA = ControlaBCs_M->Timing.t[0];
      lastU = &ControlaBCs_DW.LastUAtTimeA;
    } else {
      ControlaBCs_DW.TimeStampB = ControlaBCs_M->Timing.t[0];
      lastU = &ControlaBCs_DW.LastUAtTimeB;
    }

    (*lastU)[0] = ControlaBCs_B.Gain[0];
    (*lastU)[1] = ControlaBCs_B.Gain[1];

    /* End of Update for Derivative: '<S4>/Derivative' */
    if (rtmIsMajorTimeStep(ControlaBCs_M)) {
      /* Update for Memory: '<Root>/Memory' */
      ControlaBCs_DW.Memory_PreviousInput[0] = ControlaBCs_B.Derivative[0];
      ControlaBCs_DW.Memory_PreviousInput[1] = ControlaBCs_B.Derivative[1];
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((ControlaBCs_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(ControlaBCs_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((ControlaBCs_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(ControlaBCs_M)) {
    rt_ertODEUpdateContinuousStates(&ControlaBCs_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++ControlaBCs_M->Timing.clockTick0;
    ControlaBCs_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ControlaBCs_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      ControlaBCs_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ControlaBCs_derivatives(void)
{
  XDot_ControlaBCs_T *_rtXdot;
  _rtXdot = ((XDot_ControlaBCs_T *) ControlaBCs_M->derivs);

  /* Derivatives for Integrator: '<S89>/Integrator' */
  _rtXdot->Integrator_CSTATE = ControlaBCs_B.IntegralGain_e;

  /* Derivatives for Integrator: '<S41>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = ControlaBCs_B.IntegralGain;
}

/* Model initialize function */
void ControlaBCs_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ControlaBCs_M->solverInfo,
                          &ControlaBCs_M->Timing.simTimeStep);
    rtsiSetTPtr(&ControlaBCs_M->solverInfo, &rtmGetTPtr(ControlaBCs_M));
    rtsiSetStepSizePtr(&ControlaBCs_M->solverInfo,
                       &ControlaBCs_M->Timing.stepSize0);
    rtsiSetdXPtr(&ControlaBCs_M->solverInfo, &ControlaBCs_M->derivs);
    rtsiSetContStatesPtr(&ControlaBCs_M->solverInfo, (real_T **)
                         &ControlaBCs_M->contStates);
    rtsiSetNumContStatesPtr(&ControlaBCs_M->solverInfo,
      &ControlaBCs_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ControlaBCs_M->solverInfo,
      &ControlaBCs_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ControlaBCs_M->solverInfo,
      &ControlaBCs_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ControlaBCs_M->solverInfo,
      &ControlaBCs_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&ControlaBCs_M->solverInfo, (boolean_T**)
      &ControlaBCs_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&ControlaBCs_M->solverInfo, (&rtmGetErrorStatus
      (ControlaBCs_M)));
    rtsiSetRTModelPtr(&ControlaBCs_M->solverInfo, ControlaBCs_M);
  }

  rtsiSetSimTimeStep(&ControlaBCs_M->solverInfo, MAJOR_TIME_STEP);
  ControlaBCs_M->intgData.y = ControlaBCs_M->odeY;
  ControlaBCs_M->intgData.f[0] = ControlaBCs_M->odeF[0];
  ControlaBCs_M->intgData.f[1] = ControlaBCs_M->odeF[1];
  ControlaBCs_M->intgData.f[2] = ControlaBCs_M->odeF[2];
  ControlaBCs_M->contStates = ((X_ControlaBCs_T *) &ControlaBCs_X);
  ControlaBCs_M->contStateDisabled = ((XDis_ControlaBCs_T *) &ControlaBCs_XDis);
  ControlaBCs_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&ControlaBCs_M->solverInfo, (void *)&ControlaBCs_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&ControlaBCs_M->solverInfo, false);
  rtsiSetSolverName(&ControlaBCs_M->solverInfo,"ode3");
  rtmSetTPtr(ControlaBCs_M, &ControlaBCs_M->Timing.tArray[0]);
  rtmSetTFinal(ControlaBCs_M, -1);
  ControlaBCs_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  ControlaBCs_M->Sizes.checksums[0] = (3927595973U);
  ControlaBCs_M->Sizes.checksums[1] = (371851733U);
  ControlaBCs_M->Sizes.checksums[2] = (1306358691U);
  ControlaBCs_M->Sizes.checksums[3] = (3793497284U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    ControlaBCs_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(ControlaBCs_M->extModeInfo,
      &ControlaBCs_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ControlaBCs_M->extModeInfo,
                        ControlaBCs_M->Sizes.checksums);
    rteiSetTPtr(ControlaBCs_M->extModeInfo, rtmGetTPtr(ControlaBCs_M));
  }

  /* InitializeConditions for Derivative: '<S4>/Derivative' */
  ControlaBCs_DW.TimeStampA = (rtInf);
  ControlaBCs_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Memory: '<Root>/Memory' */
  ControlaBCs_DW.Memory_PreviousInput[0] = ControlaBCs_P.Memory_InitialCondition;
  ControlaBCs_DW.Memory_PreviousInput[1] = ControlaBCs_P.Memory_InitialCondition;

  /* InitializeConditions for Integrator: '<S89>/Integrator' */
  ControlaBCs_X.Integrator_CSTATE =
    ControlaBCs_P.PIDController2_InitialCondition;

  /* InitializeConditions for Integrator: '<S41>/Integrator' */
  ControlaBCs_X.Integrator_CSTATE_c =
    ControlaBCs_P.PIDController1_InitialCondition;

  /* Start for MATLABSystem: '<S4>/Encoder' */
  ControlaBCs_DW.obj_e.Index = 0U;
  ControlaBCs_DW.obj_e.matlabCodegenIsDeleted = false;
  ControlaBCs_DW.obj_e.SampleTime = ControlaBCs_P.Encoder_SampleTime;
  ControlaBCs_DW.obj_e.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &ControlaBCs_DW.obj_e.Index);
  ControlaBCs_DW.obj_e.isSetupComplete = true;
  ControlaBCs_DW.obj_e.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S4>/Encoder' */
  MW_EncoderReset(ControlaBCs_DW.obj_e.Index);

  /* Start for MATLABSystem: '<S4>/Encoder1' */
  ControlaBCs_DW.obj.Index = 0U;
  ControlaBCs_DW.obj.matlabCodegenIsDeleted = false;
  ControlaBCs_DW.obj.SampleTime = ControlaBCs_P.Encoder1_SampleTime;
  ControlaBCs_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &ControlaBCs_DW.obj.Index);
  ControlaBCs_DW.obj.isSetupComplete = true;
  ControlaBCs_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S4>/Encoder1' */
  MW_EncoderReset(ControlaBCs_DW.obj.Index);

  /* Start for MATLABSystem: '<S5>/Adelante_der' */
  ControlaBCs_DW.obj_k.matlabCodegenIsDeleted = false;
  ControlaBCs_DW.obj_k.isInitialized = 1L;
  ControlaBCs_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0, 0.0);
  ControlaBCs_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Adelante_izq' */
  ControlaBCs_DW.obj_m.matlabCodegenIsDeleted = false;
  ControlaBCs_DW.obj_m.isInitialized = 1L;
  ControlaBCs_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  ControlaBCs_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Atras_der' */
  ControlaBCs_DW.obj_e5.matlabCodegenIsDeleted = false;
  ControlaBCs_DW.obj_e5.isInitialized = 1L;
  ControlaBCs_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  ControlaBCs_DW.obj_e5.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Atras_izq' */
  ControlaBCs_DW.obj_d.matlabCodegenIsDeleted = false;
  ControlaBCs_DW.obj_d.isInitialized = 1L;
  ControlaBCs_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
  ControlaBCs_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Digital Output' */
  ControlaBCs_DW.obj_p.matlabCodegenIsDeleted = false;
  ControlaBCs_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(8, 1);
  ControlaBCs_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Digital Output1' */
  ControlaBCs_DW.obj_n.matlabCodegenIsDeleted = false;
  ControlaBCs_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(13, 1);
  ControlaBCs_DW.obj_n.isSetupComplete = true;
}

/* Model terminate function */
void ControlaBCs_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/Encoder' */
  if (!ControlaBCs_DW.obj_e.matlabCodegenIsDeleted) {
    ControlaBCs_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((ControlaBCs_DW.obj_e.isInitialized == 1L) &&
        ControlaBCs_DW.obj_e.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Encoder' */

  /* Terminate for MATLABSystem: '<S4>/Encoder1' */
  if (!ControlaBCs_DW.obj.matlabCodegenIsDeleted) {
    ControlaBCs_DW.obj.matlabCodegenIsDeleted = true;
    if ((ControlaBCs_DW.obj.isInitialized == 1L) &&
        ControlaBCs_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Encoder1' */
  /* Terminate for MATLABSystem: '<S5>/Adelante_der' */
  if (!ControlaBCs_DW.obj_k.matlabCodegenIsDeleted) {
    ControlaBCs_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((ControlaBCs_DW.obj_k.isInitialized == 1L) &&
        ControlaBCs_DW.obj_k.isSetupComplete) {
      ControlaBCs_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle(ControlaBCs_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ControlaBCs_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_Close(ControlaBCs_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S5>/Adelante_izq' */
  if (!ControlaBCs_DW.obj_m.matlabCodegenIsDeleted) {
    ControlaBCs_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((ControlaBCs_DW.obj_m.isInitialized == 1L) &&
        ControlaBCs_DW.obj_m.isSetupComplete) {
      ControlaBCs_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(ControlaBCs_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ControlaBCs_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(ControlaBCs_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S5>/Atras_der' */
  if (!ControlaBCs_DW.obj_e5.matlabCodegenIsDeleted) {
    ControlaBCs_DW.obj_e5.matlabCodegenIsDeleted = true;
    if ((ControlaBCs_DW.obj_e5.isInitialized == 1L) &&
        ControlaBCs_DW.obj_e5.isSetupComplete) {
      ControlaBCs_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(ControlaBCs_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ControlaBCs_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(ControlaBCs_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Atras_der' */

  /* Terminate for MATLABSystem: '<S5>/Atras_izq' */
  if (!ControlaBCs_DW.obj_d.matlabCodegenIsDeleted) {
    ControlaBCs_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((ControlaBCs_DW.obj_d.isInitialized == 1L) &&
        ControlaBCs_DW.obj_d.isSetupComplete) {
      ControlaBCs_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(ControlaBCs_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ControlaBCs_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(ControlaBCs_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  if (!ControlaBCs_DW.obj_p.matlabCodegenIsDeleted) {
    ControlaBCs_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!ControlaBCs_DW.obj_n.matlabCodegenIsDeleted) {
    ControlaBCs_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
