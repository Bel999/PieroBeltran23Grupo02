/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BucleAbierto.c
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
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "BucleAbierto_private.h"
#include "zero_crossing_types.h"

/* Block signals (default storage) */
B_BucleAbierto_T BucleAbierto_B;

/* Continuous states */
X_BucleAbierto_T BucleAbierto_X;

/* Disabled State Vector */
XDis_BucleAbierto_T BucleAbierto_XDis;

/* Block states (default storage) */
DW_BucleAbierto_T BucleAbierto_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_BucleAbierto_T BucleAbierto_PrevZCX;

/* Real-time model */
static RT_MODEL_BucleAbierto_T BucleAbierto_M_;
RT_MODEL_BucleAbierto_T *const BucleAbierto_M = &BucleAbierto_M_;

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
  BucleAbierto_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  BucleAbierto_step();
  BucleAbierto_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  BucleAbierto_step();
  BucleAbierto_derivatives();

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
void BucleAbierto_step(void)
{
  real_T tmp;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep(BucleAbierto_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&BucleAbierto_M->solverInfo,
                          ((BucleAbierto_M->Timing.clockTick0+1)*
      BucleAbierto_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(BucleAbierto_M)) {
    BucleAbierto_M->Timing.t[0] = rtsiGetT(&BucleAbierto_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(BucleAbierto_M)) {
    /* Constant: '<Root>/Constant' */
    BucleAbierto_B.rel[0] = BucleAbierto_P.Constant_Value[0];
    BucleAbierto_B.rel[1] = BucleAbierto_P.Constant_Value[1];
  }

  /* TransferFcn: '<S101>/Rizq' */
  BucleAbierto_B.Rizq = BucleAbierto_P.Rizq_C * BucleAbierto_X.Rizq_CSTATE;

  /* TransferFcn: '<S101>/Rder' */
  BucleAbierto_B.Rder = BucleAbierto_P.Rder_C * BucleAbierto_X.Rder_CSTATE;
  if (rtmIsMajorTimeStep(BucleAbierto_M)) {
    /* SignalConversion generated from: '<Root>/Planta' */
    BucleAbierto_B.vel[0] = BucleAbierto_B.Rizq;
    BucleAbierto_B.vel[1] = BucleAbierto_B.Rder;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant'
     *  Memory: '<Root>/Memory1'
     */
    BucleAbierto_B.error[0] = BucleAbierto_B.rel[0] -
      BucleAbierto_DW.Memory1_PreviousInput[0];
    BucleAbierto_B.error[1] = BucleAbierto_B.rel[1] -
      BucleAbierto_DW.Memory1_PreviousInput[1];

    /* Gain: '<S41>/Proportional Gain' */
    BucleAbierto_B.ProportionalGain = BucleAbierto_P.PIDController_P *
      BucleAbierto_B.error[0];
  }

  /* Integrator: '<S36>/Integrator' */
  if (rtsiIsModeUpdateTimeStep(&BucleAbierto_M->solverInfo)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &BucleAbierto_PrevZCX.Integrator_Reset_ZCE,
                       (0.0));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      BucleAbierto_X.Integrator_CSTATE =
        BucleAbierto_P.PIDController_InitialConditio_c;
    }
  }

  if (rtmIsMajorTimeStep(BucleAbierto_M)) {
    /* Gain: '<S30>/Derivative Gain' */
    BucleAbierto_B.DerivativeGain = BucleAbierto_P.PIDController_D *
      BucleAbierto_B.error[0];
  }

  /* Integrator: '<S31>/Filter' */
  if (rtsiIsModeUpdateTimeStep(&BucleAbierto_M->solverInfo)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &BucleAbierto_PrevZCX.Filter_Reset_ZCE,
                       (0.0));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      BucleAbierto_X.Filter_CSTATE =
        BucleAbierto_P.PIDController_InitialConditionF;
    }
  }

  /* Gain: '<S39>/Filter Coefficient' incorporates:
   *  Integrator: '<S31>/Filter'
   *  Sum: '<S31>/SumD'
   */
  BucleAbierto_B.FilterCoefficient = (BucleAbierto_B.DerivativeGain -
    BucleAbierto_X.Filter_CSTATE) * BucleAbierto_P.PIDController_N;

  /* Sum: '<S45>/Sum' incorporates:
   *  Integrator: '<S36>/Integrator'
   */
  BucleAbierto_B.Saturation = (BucleAbierto_B.ProportionalGain +
    BucleAbierto_X.Integrator_CSTATE) + BucleAbierto_B.FilterCoefficient;

  /* Saturate: '<S43>/Saturation' */
  if (BucleAbierto_B.Saturation > BucleAbierto_P.PIDController_UpperSaturationLi)
  {
    /* Sum: '<S45>/Sum' incorporates:
     *  Saturate: '<S43>/Saturation'
     */
    BucleAbierto_B.Saturation = BucleAbierto_P.PIDController_UpperSaturationLi;
  } else if (BucleAbierto_B.Saturation <
             BucleAbierto_P.PIDController_LowerSaturationLi) {
    /* Sum: '<S45>/Sum' incorporates:
     *  Saturate: '<S43>/Saturation'
     */
    BucleAbierto_B.Saturation = BucleAbierto_P.PIDController_LowerSaturationLi;
  }

  /* End of Saturate: '<S43>/Saturation' */
  if (rtmIsMajorTimeStep(BucleAbierto_M)) {
    /* Gain: '<S89>/Proportional Gain' */
    BucleAbierto_B.ProportionalGain_d = BucleAbierto_P.PIDController1_P *
      BucleAbierto_B.error[1];
  }

  /* Sum: '<S93>/Sum' incorporates:
   *  Integrator: '<S84>/Integrator'
   */
  BucleAbierto_B.Saturation_f = BucleAbierto_B.ProportionalGain_d +
    BucleAbierto_X.Integrator_CSTATE_g;

  /* Saturate: '<S91>/Saturation' */
  if (BucleAbierto_B.Saturation_f >
      BucleAbierto_P.PIDController1_UpperSaturationL) {
    /* Sum: '<S93>/Sum' incorporates:
     *  Saturate: '<S91>/Saturation'
     */
    BucleAbierto_B.Saturation_f = BucleAbierto_P.PIDController1_UpperSaturationL;
  } else if (BucleAbierto_B.Saturation_f <
             BucleAbierto_P.PIDController1_LowerSaturationL) {
    /* Sum: '<S93>/Sum' incorporates:
     *  Saturate: '<S91>/Saturation'
     */
    BucleAbierto_B.Saturation_f = BucleAbierto_P.PIDController1_LowerSaturationL;
  }

  /* End of Saturate: '<S91>/Saturation' */
  if (rtmIsMajorTimeStep(BucleAbierto_M)) {
    /* SignalConversion generated from: '<Root>/Controlador' */
    BucleAbierto_B.pwm[0] = BucleAbierto_B.Saturation;
    BucleAbierto_B.pwm[1] = BucleAbierto_B.Saturation_f;
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  tmp = floor(BucleAbierto_B.Saturation);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S101>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  BucleAbierto_B.DataTypeConversion[0] = tmp < 0.0 ? -(int16_T)(uint16_T)-tmp :
    (int16_T)(uint16_T)tmp;

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  tmp = floor(BucleAbierto_B.Saturation_f);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S101>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  BucleAbierto_B.DataTypeConversion[1] = tmp < 0.0 ? -(int16_T)(uint16_T)-tmp :
    (int16_T)(uint16_T)tmp;
  if (rtmIsMajorTimeStep(BucleAbierto_M)) {
    /* Gain: '<S33>/Integral Gain' */
    BucleAbierto_B.IntegralGain = BucleAbierto_P.PIDController_I *
      BucleAbierto_B.error[0];

    /* Gain: '<S81>/Integral Gain' */
    BucleAbierto_B.IntegralGain_c = BucleAbierto_P.PIDController1_I *
      BucleAbierto_B.error[1];
  }

  if (rtmIsMajorTimeStep(BucleAbierto_M)) {
    if (rtmIsMajorTimeStep(BucleAbierto_M)) {
      /* Update for Memory: '<Root>/Memory1' */
      BucleAbierto_DW.Memory1_PreviousInput[0] = BucleAbierto_B.vel[0];
      BucleAbierto_DW.Memory1_PreviousInput[1] = BucleAbierto_B.vel[1];
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((BucleAbierto_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(BucleAbierto_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((BucleAbierto_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(BucleAbierto_M)) {
    rt_ertODEUpdateContinuousStates(&BucleAbierto_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++BucleAbierto_M->Timing.clockTick0;
    BucleAbierto_M->Timing.t[0] = rtsiGetSolverStopTime
      (&BucleAbierto_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      BucleAbierto_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void BucleAbierto_derivatives(void)
{
  XDot_BucleAbierto_T *_rtXdot;
  _rtXdot = ((XDot_BucleAbierto_T *) BucleAbierto_M->derivs);

  /* Derivatives for TransferFcn: '<S101>/Rizq' */
  _rtXdot->Rizq_CSTATE = BucleAbierto_P.Rizq_A * BucleAbierto_X.Rizq_CSTATE;
  _rtXdot->Rizq_CSTATE += BucleAbierto_B.DataTypeConversion[0];

  /* Derivatives for TransferFcn: '<S101>/Rder' */
  _rtXdot->Rder_CSTATE = BucleAbierto_P.Rder_A * BucleAbierto_X.Rder_CSTATE;
  _rtXdot->Rder_CSTATE += BucleAbierto_B.DataTypeConversion[1];

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE = BucleAbierto_B.IntegralGain;

  /* Derivatives for Integrator: '<S31>/Filter' */
  _rtXdot->Filter_CSTATE = BucleAbierto_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S84>/Integrator' */
  _rtXdot->Integrator_CSTATE_g = BucleAbierto_B.IntegralGain_c;
}

/* Model initialize function */
void BucleAbierto_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&BucleAbierto_M->solverInfo,
                          &BucleAbierto_M->Timing.simTimeStep);
    rtsiSetTPtr(&BucleAbierto_M->solverInfo, &rtmGetTPtr(BucleAbierto_M));
    rtsiSetStepSizePtr(&BucleAbierto_M->solverInfo,
                       &BucleAbierto_M->Timing.stepSize0);
    rtsiSetdXPtr(&BucleAbierto_M->solverInfo, &BucleAbierto_M->derivs);
    rtsiSetContStatesPtr(&BucleAbierto_M->solverInfo, (real_T **)
                         &BucleAbierto_M->contStates);
    rtsiSetNumContStatesPtr(&BucleAbierto_M->solverInfo,
      &BucleAbierto_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&BucleAbierto_M->solverInfo,
      &BucleAbierto_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&BucleAbierto_M->solverInfo,
      &BucleAbierto_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&BucleAbierto_M->solverInfo,
      &BucleAbierto_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&BucleAbierto_M->solverInfo, (boolean_T**)
      &BucleAbierto_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&BucleAbierto_M->solverInfo, (&rtmGetErrorStatus
      (BucleAbierto_M)));
    rtsiSetRTModelPtr(&BucleAbierto_M->solverInfo, BucleAbierto_M);
  }

  rtsiSetSimTimeStep(&BucleAbierto_M->solverInfo, MAJOR_TIME_STEP);
  BucleAbierto_M->intgData.y = BucleAbierto_M->odeY;
  BucleAbierto_M->intgData.f[0] = BucleAbierto_M->odeF[0];
  BucleAbierto_M->intgData.f[1] = BucleAbierto_M->odeF[1];
  BucleAbierto_M->intgData.f[2] = BucleAbierto_M->odeF[2];
  BucleAbierto_M->contStates = ((X_BucleAbierto_T *) &BucleAbierto_X);
  BucleAbierto_M->contStateDisabled = ((XDis_BucleAbierto_T *)
    &BucleAbierto_XDis);
  BucleAbierto_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&BucleAbierto_M->solverInfo, (void *)
                    &BucleAbierto_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&BucleAbierto_M->solverInfo, false);
  rtsiSetSolverName(&BucleAbierto_M->solverInfo,"ode3");
  rtmSetTPtr(BucleAbierto_M, &BucleAbierto_M->Timing.tArray[0]);
  rtmSetTFinal(BucleAbierto_M, -1);
  BucleAbierto_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  BucleAbierto_M->Sizes.checksums[0] = (2348804875U);
  BucleAbierto_M->Sizes.checksums[1] = (1227368219U);
  BucleAbierto_M->Sizes.checksums[2] = (3173477514U);
  BucleAbierto_M->Sizes.checksums[3] = (3896886933U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    BucleAbierto_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(BucleAbierto_M->extModeInfo,
      &BucleAbierto_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(BucleAbierto_M->extModeInfo,
                        BucleAbierto_M->Sizes.checksums);
    rteiSetTPtr(BucleAbierto_M->extModeInfo, rtmGetTPtr(BucleAbierto_M));
  }

  BucleAbierto_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  BucleAbierto_PrevZCX.Filter_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for TransferFcn: '<S101>/Rizq' */
  BucleAbierto_X.Rizq_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S101>/Rder' */
  BucleAbierto_X.Rder_CSTATE = 0.0;

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  BucleAbierto_DW.Memory1_PreviousInput[0] =
    BucleAbierto_P.Memory1_InitialCondition;
  BucleAbierto_DW.Memory1_PreviousInput[1] =
    BucleAbierto_P.Memory1_InitialCondition;

  /* InitializeConditions for Integrator: '<S36>/Integrator' */
  BucleAbierto_X.Integrator_CSTATE =
    BucleAbierto_P.PIDController_InitialConditio_c;

  /* InitializeConditions for Integrator: '<S31>/Filter' */
  BucleAbierto_X.Filter_CSTATE = BucleAbierto_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S84>/Integrator' */
  BucleAbierto_X.Integrator_CSTATE_g =
    BucleAbierto_P.PIDController1_InitialCondition;
}

/* Model terminate function */
void BucleAbierto_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
