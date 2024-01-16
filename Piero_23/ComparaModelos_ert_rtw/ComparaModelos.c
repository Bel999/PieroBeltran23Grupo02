/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ComparaModelos.c
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
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "ComparaModelos_private.h"

/* Block signals (default storage) */
B_ComparaModelos_T ComparaModelos_B;

/* Continuous states */
X_ComparaModelos_T ComparaModelos_X;

/* Disabled State Vector */
XDis_ComparaModelos_T ComparaModelos_XDis;

/* Block states (default storage) */
DW_ComparaModelos_T ComparaModelos_DW;

/* Real-time model */
static RT_MODEL_ComparaModelos_T ComparaModelos_M_;
RT_MODEL_ComparaModelos_T *const ComparaModelos_M = &ComparaModelos_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void ComparaModelos_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(ComparaModelos_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (ComparaModelos_M->Timing.TaskCounters.TID[1] == 0) {
    ComparaModelos_M->Timing.RateInteraction.TID1_2 =
      (ComparaModelos_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ComparaModelos_M->Timing.TaskCounters.TID[2])++;
  if ((ComparaModelos_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [0.5s, 0.0s] */
    ComparaModelos_M->Timing.TaskCounters.TID[2] = 0;
  }
}

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
  ComparaModelos_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ComparaModelos_step0();
  ComparaModelos_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ComparaModelos_step0();
  ComparaModelos_derivatives();

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

/* Model step function for TID0 */
void ComparaModelos_step0(void)        /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(ComparaModelos_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&ComparaModelos_M->solverInfo,
                          ((ComparaModelos_M->Timing.clockTick0+1)*
      ComparaModelos_M->Timing.stepSize0));

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ComparaModelos_M)) {
    ComparaModelos_M->Timing.t[0] = rtsiGetT(&ComparaModelos_M->solverInfo);
  }

  {
    real_T (*lastU)[2];
    real_T deltaT;
    real_T lastTime;
    int32_T rtb_Gain_p;
    int32_T rtb_Saturation4;
    int16_T y;
    if (rtmIsMajorTimeStep(ComparaModelos_M)) {
      /* Constant: '<Root>/Constant' */
      ComparaModelos_B.Constant[0] = ComparaModelos_P.Constant_Value[0];
      ComparaModelos_B.Constant[1] = ComparaModelos_P.Constant_Value[1];

      /* RateTransition generated from: '<S102>/Derivative' */
      if (ComparaModelos_M->Timing.RateInteraction.TID1_2) {
        /* RateTransition generated from: '<S102>/Derivative' */
        ComparaModelos_B.TmpRTBAtDerivativeInport1[0] =
          ComparaModelos_DW.TmpRTBAtDerivativeInport1_Buffe[0];
        ComparaModelos_B.TmpRTBAtDerivativeInport1[1] =
          ComparaModelos_DW.TmpRTBAtDerivativeInport1_Buffe[1];
      }

      /* End of RateTransition generated from: '<S102>/Derivative' */
    }

    /* Derivative: '<S102>/Derivative' */
    deltaT = ComparaModelos_M->Timing.t[0];
    if ((ComparaModelos_DW.TimeStampA >= deltaT) &&
        (ComparaModelos_DW.TimeStampB >= deltaT)) {
      /* Derivative: '<S102>/Derivative' */
      ComparaModelos_B.Derivative[0] = 0.0;
      ComparaModelos_B.Derivative[1] = 0.0;
    } else {
      lastTime = ComparaModelos_DW.TimeStampA;
      lastU = &ComparaModelos_DW.LastUAtTimeA;
      if (ComparaModelos_DW.TimeStampA < ComparaModelos_DW.TimeStampB) {
        if (ComparaModelos_DW.TimeStampB < deltaT) {
          lastTime = ComparaModelos_DW.TimeStampB;
          lastU = &ComparaModelos_DW.LastUAtTimeB;
        }
      } else if (ComparaModelos_DW.TimeStampA >= deltaT) {
        lastTime = ComparaModelos_DW.TimeStampB;
        lastU = &ComparaModelos_DW.LastUAtTimeB;
      }

      deltaT -= lastTime;

      /* Derivative: '<S102>/Derivative' */
      ComparaModelos_B.Derivative[0] =
        (ComparaModelos_B.TmpRTBAtDerivativeInport1[0] - (*lastU)[0]) / deltaT;
      ComparaModelos_B.Derivative[1] =
        (ComparaModelos_B.TmpRTBAtDerivativeInport1[1] - (*lastU)[1]) / deltaT;
    }

    /* End of Derivative: '<S102>/Derivative' */
    if (rtmIsMajorTimeStep(ComparaModelos_M)) {
      /* Sum: '<Root>/Sum' incorporates:
       *  Constant: '<Root>/Constant'
       *  Memory: '<Root>/Memory'
       */
      ComparaModelos_B.Sum[0] = ComparaModelos_B.Constant[0] -
        ComparaModelos_DW.Memory_PreviousInput[0];
      ComparaModelos_B.Sum[1] = ComparaModelos_B.Constant[1] -
        ComparaModelos_DW.Memory_PreviousInput[1];

      /* Gain: '<S41>/Proportional Gain' */
      ComparaModelos_B.ProportionalGain = ComparaModelos_P.PIDController_P *
        ComparaModelos_B.Sum[0];
    }

    /* Sum: '<S45>/Sum' incorporates:
     *  Integrator: '<S36>/Integrator'
     */
    deltaT = floor(ComparaModelos_B.ProportionalGain +
                   ComparaModelos_X.Integrator_CSTATE);
    if (rtIsNaN(deltaT) || rtIsInf(deltaT)) {
      deltaT = 0.0;
    } else {
      deltaT = fmod(deltaT, 65536.0);
    }

    ComparaModelos_B.Saturation = deltaT < 0.0 ? -(int16_T)(uint16_T)-deltaT :
      (int16_T)(uint16_T)deltaT;

    /* Saturate: '<S43>/Saturation' */
    if (ComparaModelos_B.Saturation >
        ComparaModelos_P.PIDController_UpperSaturationLi) {
      /* Sum: '<S45>/Sum' incorporates:
       *  Saturate: '<S43>/Saturation'
       */
      ComparaModelos_B.Saturation =
        ComparaModelos_P.PIDController_UpperSaturationLi;
    } else if (ComparaModelos_B.Saturation <
               ComparaModelos_P.PIDController_LowerSaturationLi) {
      /* Sum: '<S45>/Sum' incorporates:
       *  Saturate: '<S43>/Saturation'
       */
      ComparaModelos_B.Saturation =
        ComparaModelos_P.PIDController_LowerSaturationLi;
    }

    /* End of Saturate: '<S43>/Saturation' */
    if (rtmIsMajorTimeStep(ComparaModelos_M)) {
      /* Gain: '<S89>/Proportional Gain' */
      ComparaModelos_B.ProportionalGain_c = ComparaModelos_P.PIDController1_P *
        ComparaModelos_B.Sum[1];
    }

    /* Sum: '<S93>/Sum' incorporates:
     *  Integrator: '<S84>/Integrator'
     */
    deltaT = floor(ComparaModelos_B.ProportionalGain_c +
                   ComparaModelos_X.Integrator_CSTATE_m);
    if (rtIsNaN(deltaT) || rtIsInf(deltaT)) {
      deltaT = 0.0;
    } else {
      deltaT = fmod(deltaT, 65536.0);
    }

    ComparaModelos_B.Saturation_p = deltaT < 0.0 ? -(int16_T)(uint16_T)-deltaT :
      (int16_T)(uint16_T)deltaT;

    /* Saturate: '<S91>/Saturation' */
    if (ComparaModelos_B.Saturation_p >
        ComparaModelos_P.PIDController1_UpperSaturationL) {
      /* Sum: '<S93>/Sum' incorporates:
       *  Saturate: '<S91>/Saturation'
       */
      ComparaModelos_B.Saturation_p =
        ComparaModelos_P.PIDController1_UpperSaturationL;
    } else if (ComparaModelos_B.Saturation_p <
               ComparaModelos_P.PIDController1_LowerSaturationL) {
      /* Sum: '<S93>/Sum' incorporates:
       *  Saturate: '<S91>/Saturation'
       */
      ComparaModelos_B.Saturation_p =
        ComparaModelos_P.PIDController1_LowerSaturationL;
    }

    /* End of Saturate: '<S91>/Saturation' */
    if (rtmIsMajorTimeStep(ComparaModelos_M)) {
      /* SignalConversion generated from: '<Root>/Subsystem' */
      ComparaModelos_B.TmpSignalConversionAtTAQSigLogg[0] =
        ComparaModelos_B.Saturation;
      ComparaModelos_B.TmpSignalConversionAtTAQSigLogg[1] =
        ComparaModelos_B.Saturation_p;
    }

    /* MATLABSystem: '<S103>/Adelante_der' */
    ComparaModelos_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

    /* Saturate: '<S103>/Saturation2' */
    if (ComparaModelos_B.Saturation_p > ComparaModelos_P.Saturation2_UpperSat) {
      y = ComparaModelos_P.Saturation2_UpperSat;
    } else if (ComparaModelos_B.Saturation_p <
               ComparaModelos_P.Saturation2_LowerSat) {
      y = ComparaModelos_P.Saturation2_LowerSat;
    } else {
      y = ComparaModelos_B.Saturation_p;
    }

    /* End of Saturate: '<S103>/Saturation2' */

    /* Start for MATLABSystem: '<S103>/Adelante_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S103>/Adelante_der' */
    MW_PWM_SetDutyCycle(ComparaModelos_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S103>/Atras_der' */
    ComparaModelos_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* Saturate: '<S103>/Saturation3' */
    if (ComparaModelos_B.Saturation_p > ComparaModelos_P.Saturation3_UpperSat) {
      y = ComparaModelos_P.Saturation3_UpperSat;
    } else if (ComparaModelos_B.Saturation_p <
               ComparaModelos_P.Saturation3_LowerSat) {
      y = ComparaModelos_P.Saturation3_LowerSat;
    } else {
      y = ComparaModelos_B.Saturation_p;
    }

    /* End of Saturate: '<S103>/Saturation3' */

    /* Abs: '<S103>/Abs1' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S103>/Abs1' */

    /* Start for MATLABSystem: '<S103>/Atras_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S103>/Atras_der' */
    MW_PWM_SetDutyCycle(ComparaModelos_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S103>/Digital Output1' incorporates:
     *  Constant: '<S105>/Constant'
     *  RelationalOperator: '<S105>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(ComparaModelos_B.Saturation_p !=
      ComparaModelos_P.Constant_Value_n));

    /* Gain: '<S103>/Gain' */
    rtb_Gain_p = (int32_T)ComparaModelos_P.Gain_Gain_o *
      ComparaModelos_B.Saturation;

    /* MATLABSystem: '<S103>/Digital Output' incorporates:
     *  Constant: '<S104>/Constant'
     *  Gain: '<S103>/Gain'
     *  RelationalOperator: '<S104>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_Gain_p != ComparaModelos_P.Constant_Value_d));

    /* Saturate: '<S103>/Saturation4' incorporates:
     *  Gain: '<S103>/Gain'
     */
    if (rtb_Gain_p > ComparaModelos_P.Saturation4_UpperSat) {
      rtb_Saturation4 = ComparaModelos_P.Saturation4_UpperSat;
    } else if (rtb_Gain_p < ComparaModelos_P.Saturation4_LowerSat) {
      rtb_Saturation4 = ComparaModelos_P.Saturation4_LowerSat;
    } else {
      rtb_Saturation4 = rtb_Gain_p;
    }

    /* End of Saturate: '<S103>/Saturation4' */

    /* MATLABSystem: '<S103>/Adelante_izq' */
    ComparaModelos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* Abs: '<S103>/Abs2' incorporates:
     *  Saturate: '<S103>/Saturation4'
     */
    if (rtb_Saturation4 < 0L) {
      rtb_Saturation4 = -rtb_Saturation4;
    }

    /* Start for MATLABSystem: '<S103>/Adelante_izq' incorporates:
     *  Abs: '<S103>/Abs2'
     */
    deltaT = (real_T)rtb_Saturation4 * 6.103515625E-5;
    if (!(deltaT <= 255.0)) {
      deltaT = 255.0;
    }

    if (!(deltaT >= 0.0)) {
      deltaT = 0.0;
    }

    /* MATLABSystem: '<S103>/Adelante_izq' */
    MW_PWM_SetDutyCycle(ComparaModelos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                        deltaT);

    /* MATLABSystem: '<S103>/Atras_izq' */
    ComparaModelos_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Saturate: '<S103>/Saturation5' incorporates:
     *  Gain: '<S103>/Gain'
     */
    if (rtb_Gain_p > ComparaModelos_P.Saturation5_UpperSat) {
      rtb_Gain_p = ComparaModelos_P.Saturation5_UpperSat;
    } else if (rtb_Gain_p < ComparaModelos_P.Saturation5_LowerSat) {
      rtb_Gain_p = ComparaModelos_P.Saturation5_LowerSat;
    }

    /* Start for MATLABSystem: '<S103>/Atras_izq' incorporates:
     *  Saturate: '<S103>/Saturation5'
     */
    deltaT = (real_T)rtb_Gain_p * 6.103515625E-5;
    if (!(deltaT <= 255.0)) {
      deltaT = 255.0;
    }

    if (!(deltaT >= 0.0)) {
      deltaT = 0.0;
    }

    /* MATLABSystem: '<S103>/Atras_izq' */
    MW_PWM_SetDutyCycle(ComparaModelos_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE,
                        deltaT);
    if (rtmIsMajorTimeStep(ComparaModelos_M)) {
      /* Gain: '<S33>/Integral Gain' */
      ComparaModelos_B.IntegralGain = ComparaModelos_P.PIDController_I *
        ComparaModelos_B.Sum[0];

      /* Gain: '<S81>/Integral Gain' */
      ComparaModelos_B.IntegralGain_o = ComparaModelos_P.PIDController1_I *
        ComparaModelos_B.Sum[1];
    }
  }

  if (rtmIsMajorTimeStep(ComparaModelos_M)) {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S102>/Derivative' */
    if (ComparaModelos_DW.TimeStampA == (rtInf)) {
      ComparaModelos_DW.TimeStampA = ComparaModelos_M->Timing.t[0];
      lastU = &ComparaModelos_DW.LastUAtTimeA;
    } else if (ComparaModelos_DW.TimeStampB == (rtInf)) {
      ComparaModelos_DW.TimeStampB = ComparaModelos_M->Timing.t[0];
      lastU = &ComparaModelos_DW.LastUAtTimeB;
    } else if (ComparaModelos_DW.TimeStampA < ComparaModelos_DW.TimeStampB) {
      ComparaModelos_DW.TimeStampA = ComparaModelos_M->Timing.t[0];
      lastU = &ComparaModelos_DW.LastUAtTimeA;
    } else {
      ComparaModelos_DW.TimeStampB = ComparaModelos_M->Timing.t[0];
      lastU = &ComparaModelos_DW.LastUAtTimeB;
    }

    (*lastU)[0] = ComparaModelos_B.TmpRTBAtDerivativeInport1[0];
    (*lastU)[1] = ComparaModelos_B.TmpRTBAtDerivativeInport1[1];

    /* End of Update for Derivative: '<S102>/Derivative' */
    if (rtmIsMajorTimeStep(ComparaModelos_M)) {
      /* Update for Memory: '<Root>/Memory' */
      ComparaModelos_DW.Memory_PreviousInput[0] = ComparaModelos_B.Derivative[0];
      ComparaModelos_DW.Memory_PreviousInput[1] = ComparaModelos_B.Derivative[1];
    }

    {
      extmodeErrorCode_T returnCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentSimTime = (extmodeSimulationTime_T)
        ((ComparaModelos_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      returnCode = extmodeEvent(1,currentSimTime);
      if (returnCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(ComparaModelos_M)) {
    rt_ertODEUpdateContinuousStates(&ComparaModelos_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++ComparaModelos_M->Timing.clockTick0;
    ComparaModelos_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ComparaModelos_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    ComparaModelos_M->Timing.clockTick1++;
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ComparaModelos_derivatives(void)
{
  XDot_ComparaModelos_T *_rtXdot;
  _rtXdot = ((XDot_ComparaModelos_T *) ComparaModelos_M->derivs);

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE = ComparaModelos_B.IntegralGain;

  /* Derivatives for Integrator: '<S84>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = ComparaModelos_B.IntegralGain_o;
}

/* Model step function for TID2 */
void ComparaModelos_step2(void)        /* Sample time: [0.5s, 0.0s] */
{
  real_T rtb_Gain[2];
  real_T rtb_Gain_tmp;
  int32_T rtb_Encoder1_0;
  int32_T rtb_Encoder_0;

  /* MATLABSystem: '<S102>/Encoder' */
  if (ComparaModelos_DW.obj_c.SampleTime != ComparaModelos_P.Encoder_SampleTime)
  {
    ComparaModelos_DW.obj_c.SampleTime = ComparaModelos_P.Encoder_SampleTime;
  }

  if (ComparaModelos_DW.obj_c.TunablePropsChanged) {
    ComparaModelos_DW.obj_c.TunablePropsChanged = false;
  }

  MW_EncoderRead(ComparaModelos_DW.obj_c.Index, &rtb_Encoder_0);

  /* MATLABSystem: '<S102>/Encoder1' */
  if (ComparaModelos_DW.obj.SampleTime != ComparaModelos_P.Encoder1_SampleTime)
  {
    ComparaModelos_DW.obj.SampleTime = ComparaModelos_P.Encoder1_SampleTime;
  }

  if (ComparaModelos_DW.obj.TunablePropsChanged) {
    ComparaModelos_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(ComparaModelos_DW.obj.Index, &rtb_Encoder1_0);

  /* Gain: '<S102>/Gain' incorporates:
   *  MATLABSystem: '<S102>/Encoder'
   *  MATLABSystem: '<S102>/Encoder1'
   */
  rtb_Gain_tmp = (real_T)ComparaModelos_P.Gain_Gain * 1.1368683772161603E-13;
  rtb_Gain[0] = rtb_Gain_tmp * (real_T)rtb_Encoder1_0;
  rtb_Gain[1] = rtb_Gain_tmp * (real_T)rtb_Encoder_0;

  /* RateTransition generated from: '<S102>/Derivative' */
  ComparaModelos_DW.TmpRTBAtDerivativeInport1_Buffe[0] = rtb_Gain[0];
  ComparaModelos_DW.TmpRTBAtDerivativeInport1_Buffe[1] = rtb_Gain[1];

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.5, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ComparaModelos_M->Timing.clockTick2++;
}

/* Model initialize function */
void ComparaModelos_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ComparaModelos_M->solverInfo,
                          &ComparaModelos_M->Timing.simTimeStep);
    rtsiSetTPtr(&ComparaModelos_M->solverInfo, &rtmGetTPtr(ComparaModelos_M));
    rtsiSetStepSizePtr(&ComparaModelos_M->solverInfo,
                       &ComparaModelos_M->Timing.stepSize0);
    rtsiSetdXPtr(&ComparaModelos_M->solverInfo, &ComparaModelos_M->derivs);
    rtsiSetContStatesPtr(&ComparaModelos_M->solverInfo, (real_T **)
                         &ComparaModelos_M->contStates);
    rtsiSetNumContStatesPtr(&ComparaModelos_M->solverInfo,
      &ComparaModelos_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ComparaModelos_M->solverInfo,
      &ComparaModelos_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ComparaModelos_M->solverInfo,
      &ComparaModelos_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ComparaModelos_M->solverInfo,
      &ComparaModelos_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&ComparaModelos_M->solverInfo, (boolean_T**)
      &ComparaModelos_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&ComparaModelos_M->solverInfo, (&rtmGetErrorStatus
      (ComparaModelos_M)));
    rtsiSetRTModelPtr(&ComparaModelos_M->solverInfo, ComparaModelos_M);
  }

  rtsiSetSimTimeStep(&ComparaModelos_M->solverInfo, MAJOR_TIME_STEP);
  ComparaModelos_M->intgData.y = ComparaModelos_M->odeY;
  ComparaModelos_M->intgData.f[0] = ComparaModelos_M->odeF[0];
  ComparaModelos_M->intgData.f[1] = ComparaModelos_M->odeF[1];
  ComparaModelos_M->intgData.f[2] = ComparaModelos_M->odeF[2];
  ComparaModelos_M->contStates = ((X_ComparaModelos_T *) &ComparaModelos_X);
  ComparaModelos_M->contStateDisabled = ((XDis_ComparaModelos_T *)
    &ComparaModelos_XDis);
  ComparaModelos_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&ComparaModelos_M->solverInfo, (void *)
                    &ComparaModelos_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&ComparaModelos_M->solverInfo, false);
  rtsiSetSolverName(&ComparaModelos_M->solverInfo,"ode3");
  rtmSetTPtr(ComparaModelos_M, &ComparaModelos_M->Timing.tArray[0]);
  rtmSetTFinal(ComparaModelos_M, -1);
  ComparaModelos_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  ComparaModelos_M->Sizes.checksums[0] = (1116822500U);
  ComparaModelos_M->Sizes.checksums[1] = (2717076815U);
  ComparaModelos_M->Sizes.checksums[2] = (3072480768U);
  ComparaModelos_M->Sizes.checksums[3] = (3972836720U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    ComparaModelos_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(ComparaModelos_M->extModeInfo,
      &ComparaModelos_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ComparaModelos_M->extModeInfo,
                        ComparaModelos_M->Sizes.checksums);
    rteiSetTPtr(ComparaModelos_M->extModeInfo, rtmGetTPtr(ComparaModelos_M));
  }

  /* Start for RateTransition generated from: '<S102>/Derivative' */
  ComparaModelos_B.TmpRTBAtDerivativeInport1[0] =
    ComparaModelos_P.TmpRTBAtDerivativeInport1_Initi;
  ComparaModelos_B.TmpRTBAtDerivativeInport1[1] =
    ComparaModelos_P.TmpRTBAtDerivativeInport1_Initi;

  /* InitializeConditions for RateTransition generated from: '<S102>/Derivative' */
  ComparaModelos_DW.TmpRTBAtDerivativeInport1_Buffe[0] =
    ComparaModelos_P.TmpRTBAtDerivativeInport1_Initi;
  ComparaModelos_DW.TmpRTBAtDerivativeInport1_Buffe[1] =
    ComparaModelos_P.TmpRTBAtDerivativeInport1_Initi;

  /* InitializeConditions for Derivative: '<S102>/Derivative' */
  ComparaModelos_DW.TimeStampA = (rtInf);
  ComparaModelos_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Memory: '<Root>/Memory' */
  ComparaModelos_DW.Memory_PreviousInput[0] =
    ComparaModelos_P.Memory_InitialCondition;
  ComparaModelos_DW.Memory_PreviousInput[1] =
    ComparaModelos_P.Memory_InitialCondition;

  /* InitializeConditions for Integrator: '<S36>/Integrator' */
  ComparaModelos_X.Integrator_CSTATE =
    ComparaModelos_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S84>/Integrator' */
  ComparaModelos_X.Integrator_CSTATE_m =
    ComparaModelos_P.PIDController1_InitialCondition;

  /* Start for MATLABSystem: '<S103>/Adelante_der' */
  ComparaModelos_DW.obj_d.matlabCodegenIsDeleted = false;
  ComparaModelos_DW.obj_d.isInitialized = 1L;
  ComparaModelos_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0,
    0.0);
  ComparaModelos_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Atras_der' */
  ComparaModelos_DW.obj_b.matlabCodegenIsDeleted = false;
  ComparaModelos_DW.obj_b.isInitialized = 1L;
  ComparaModelos_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  ComparaModelos_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Digital Output1' */
  ComparaModelos_DW.obj_c0.matlabCodegenIsDeleted = false;
  ComparaModelos_DW.obj_c0.isInitialized = 1L;
  digitalIOSetup(13, 1);
  ComparaModelos_DW.obj_c0.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Digital Output' */
  ComparaModelos_DW.obj_i.matlabCodegenIsDeleted = false;
  ComparaModelos_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(8, 1);
  ComparaModelos_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Adelante_izq' */
  ComparaModelos_DW.obj_g.matlabCodegenIsDeleted = false;
  ComparaModelos_DW.obj_g.isInitialized = 1L;
  ComparaModelos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  ComparaModelos_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Atras_izq' */
  ComparaModelos_DW.obj_cc.matlabCodegenIsDeleted = false;
  ComparaModelos_DW.obj_cc.isInitialized = 1L;
  ComparaModelos_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0,
    0.0);
  ComparaModelos_DW.obj_cc.isSetupComplete = true;

  /* Start for MATLABSystem: '<S102>/Encoder' */
  ComparaModelos_DW.obj_c.Index = 0U;
  ComparaModelos_DW.obj_c.matlabCodegenIsDeleted = false;
  ComparaModelos_DW.obj_c.SampleTime = ComparaModelos_P.Encoder_SampleTime;
  ComparaModelos_DW.obj_c.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &ComparaModelos_DW.obj_c.Index);
  ComparaModelos_DW.obj_c.isSetupComplete = true;
  ComparaModelos_DW.obj_c.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S102>/Encoder' */
  MW_EncoderReset(ComparaModelos_DW.obj_c.Index);

  /* Start for MATLABSystem: '<S102>/Encoder1' */
  ComparaModelos_DW.obj.Index = 0U;
  ComparaModelos_DW.obj.matlabCodegenIsDeleted = false;
  ComparaModelos_DW.obj.SampleTime = ComparaModelos_P.Encoder1_SampleTime;
  ComparaModelos_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &ComparaModelos_DW.obj.Index);
  ComparaModelos_DW.obj.isSetupComplete = true;
  ComparaModelos_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S102>/Encoder1' */
  MW_EncoderReset(ComparaModelos_DW.obj.Index);
}

/* Model terminate function */
void ComparaModelos_terminate(void)
{
  /* Terminate for MATLABSystem: '<S103>/Adelante_der' */
  if (!ComparaModelos_DW.obj_d.matlabCodegenIsDeleted) {
    ComparaModelos_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((ComparaModelos_DW.obj_d.isInitialized == 1L) &&
        ComparaModelos_DW.obj_d.isSetupComplete) {
      ComparaModelos_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle(ComparaModelos_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ComparaModelos_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_Close(ComparaModelos_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S103>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S103>/Atras_der' */
  if (!ComparaModelos_DW.obj_b.matlabCodegenIsDeleted) {
    ComparaModelos_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((ComparaModelos_DW.obj_b.isInitialized == 1L) &&
        ComparaModelos_DW.obj_b.isSetupComplete) {
      ComparaModelos_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(ComparaModelos_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ComparaModelos_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(ComparaModelos_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S103>/Atras_der' */

  /* Terminate for MATLABSystem: '<S103>/Digital Output1' */
  if (!ComparaModelos_DW.obj_c0.matlabCodegenIsDeleted) {
    ComparaModelos_DW.obj_c0.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S103>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S103>/Digital Output' */
  if (!ComparaModelos_DW.obj_i.matlabCodegenIsDeleted) {
    ComparaModelos_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S103>/Digital Output' */

  /* Terminate for MATLABSystem: '<S103>/Adelante_izq' */
  if (!ComparaModelos_DW.obj_g.matlabCodegenIsDeleted) {
    ComparaModelos_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((ComparaModelos_DW.obj_g.isInitialized == 1L) &&
        ComparaModelos_DW.obj_g.isSetupComplete) {
      ComparaModelos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(ComparaModelos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ComparaModelos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(ComparaModelos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S103>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S103>/Atras_izq' */
  if (!ComparaModelos_DW.obj_cc.matlabCodegenIsDeleted) {
    ComparaModelos_DW.obj_cc.matlabCodegenIsDeleted = true;
    if ((ComparaModelos_DW.obj_cc.isInitialized == 1L) &&
        ComparaModelos_DW.obj_cc.isSetupComplete) {
      ComparaModelos_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_SetDutyCycle(ComparaModelos_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ComparaModelos_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_Close(ComparaModelos_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S103>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S102>/Encoder' */
  if (!ComparaModelos_DW.obj_c.matlabCodegenIsDeleted) {
    ComparaModelos_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((ComparaModelos_DW.obj_c.isInitialized == 1L) &&
        ComparaModelos_DW.obj_c.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S102>/Encoder' */

  /* Terminate for MATLABSystem: '<S102>/Encoder1' */
  if (!ComparaModelos_DW.obj.matlabCodegenIsDeleted) {
    ComparaModelos_DW.obj.matlabCodegenIsDeleted = true;
    if ((ComparaModelos_DW.obj.isInitialized == 1L) &&
        ComparaModelos_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S102>/Encoder1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
