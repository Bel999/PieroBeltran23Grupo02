/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ComparaModelos111.c
 *
 * Code generated for Simulink model 'ComparaModelos111'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 30 15:36:05 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ComparaModelos111.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "ComparaModelos111_private.h"

/* Block signals (default storage) */
B_ComparaModelos111_T ComparaModelos111_B;

/* Continuous states */
X_ComparaModelos111_T ComparaModelos111_X;

/* Disabled State Vector */
XDis_ComparaModelos111_T ComparaModelos111_XDis;

/* Block states (default storage) */
DW_ComparaModelos111_T ComparaModelos111_DW;

/* Real-time model */
static RT_MODEL_ComparaModelos111_T ComparaModelos111_M_;
RT_MODEL_ComparaModelos111_T *const ComparaModelos111_M = &ComparaModelos111_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void ComparaModelos111_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(ComparaModelos111_M, 2));
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
  if (ComparaModelos111_M->Timing.TaskCounters.TID[1] == 0) {
    ComparaModelos111_M->Timing.RateInteraction.TID1_2 =
      (ComparaModelos111_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ComparaModelos111_M->Timing.TaskCounters.TID[2])++;
  if ((ComparaModelos111_M->Timing.TaskCounters.TID[2]) > 49) {/* Sample time: [0.5s, 0.0s] */
    ComparaModelos111_M->Timing.TaskCounters.TID[2] = 0;
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
  ComparaModelos111_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ComparaModelos111_step0();
  ComparaModelos111_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ComparaModelos111_step0();
  ComparaModelos111_derivatives();

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
void ComparaModelos111_step0(void)     /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(ComparaModelos111_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&ComparaModelos111_M->solverInfo,
                          ((ComparaModelos111_M->Timing.clockTick0+1)*
      ComparaModelos111_M->Timing.stepSize0));

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ComparaModelos111_M)) {
    ComparaModelos111_M->Timing.t[0] = rtsiGetT(&ComparaModelos111_M->solverInfo);
  }

  {
    real_T (*lastU)[2];
    real_T deltaT;
    real_T lastTime;
    int32_T rtb_Gain_p;
    int32_T rtb_Saturation4;
    int16_T y;
    if (rtmIsMajorTimeStep(ComparaModelos111_M)) {
      /* Constant: '<Root>/Constant' */
      ComparaModelos111_B.Constant[0] = ComparaModelos111_P.Constant_Value[0];
      ComparaModelos111_B.Constant[1] = ComparaModelos111_P.Constant_Value[1];

      /* RateTransition generated from: '<S102>/Derivative' */
      if (ComparaModelos111_M->Timing.RateInteraction.TID1_2) {
        /* RateTransition generated from: '<S102>/Derivative' */
        ComparaModelos111_B.TmpRTBAtDerivativeInport1[0] =
          ComparaModelos111_DW.TmpRTBAtDerivativeInport1_Buffe[0];
        ComparaModelos111_B.TmpRTBAtDerivativeInport1[1] =
          ComparaModelos111_DW.TmpRTBAtDerivativeInport1_Buffe[1];
      }

      /* End of RateTransition generated from: '<S102>/Derivative' */
    }

    /* Derivative: '<S102>/Derivative' */
    deltaT = ComparaModelos111_M->Timing.t[0];
    if ((ComparaModelos111_DW.TimeStampA >= deltaT) &&
        (ComparaModelos111_DW.TimeStampB >= deltaT)) {
      /* Derivative: '<S102>/Derivative' */
      ComparaModelos111_B.Derivative[0] = 0.0;
      ComparaModelos111_B.Derivative[1] = 0.0;
    } else {
      lastTime = ComparaModelos111_DW.TimeStampA;
      lastU = &ComparaModelos111_DW.LastUAtTimeA;
      if (ComparaModelos111_DW.TimeStampA < ComparaModelos111_DW.TimeStampB) {
        if (ComparaModelos111_DW.TimeStampB < deltaT) {
          lastTime = ComparaModelos111_DW.TimeStampB;
          lastU = &ComparaModelos111_DW.LastUAtTimeB;
        }
      } else if (ComparaModelos111_DW.TimeStampA >= deltaT) {
        lastTime = ComparaModelos111_DW.TimeStampB;
        lastU = &ComparaModelos111_DW.LastUAtTimeB;
      }

      deltaT -= lastTime;

      /* Derivative: '<S102>/Derivative' */
      ComparaModelos111_B.Derivative[0] =
        (ComparaModelos111_B.TmpRTBAtDerivativeInport1[0] - (*lastU)[0]) /
        deltaT;
      ComparaModelos111_B.Derivative[1] =
        (ComparaModelos111_B.TmpRTBAtDerivativeInport1[1] - (*lastU)[1]) /
        deltaT;
    }

    /* End of Derivative: '<S102>/Derivative' */
    if (rtmIsMajorTimeStep(ComparaModelos111_M)) {
      /* Sum: '<Root>/Sum' incorporates:
       *  Constant: '<Root>/Constant'
       *  Memory: '<Root>/Memory'
       */
      ComparaModelos111_B.Sum[0] = ComparaModelos111_B.Constant[0] -
        ComparaModelos111_DW.Memory_PreviousInput[0];
      ComparaModelos111_B.Sum[1] = ComparaModelos111_B.Constant[1] -
        ComparaModelos111_DW.Memory_PreviousInput[1];

      /* Gain: '<S41>/Proportional Gain' */
      ComparaModelos111_B.ProportionalGain = ComparaModelos111_P.PIDController_P
        * ComparaModelos111_B.Sum[0];
    }

    /* Sum: '<S45>/Sum' incorporates:
     *  Integrator: '<S36>/Integrator'
     */
    deltaT = floor(ComparaModelos111_B.ProportionalGain +
                   ComparaModelos111_X.Integrator_CSTATE);
    if (rtIsNaN(deltaT) || rtIsInf(deltaT)) {
      deltaT = 0.0;
    } else {
      deltaT = fmod(deltaT, 65536.0);
    }

    ComparaModelos111_B.Saturation = deltaT < 0.0 ? -(int16_T)(uint16_T)-deltaT :
      (int16_T)(uint16_T)deltaT;

    /* Saturate: '<S43>/Saturation' */
    if (ComparaModelos111_B.Saturation >
        ComparaModelos111_P.PIDController_UpperSaturationLi) {
      /* Sum: '<S45>/Sum' incorporates:
       *  Saturate: '<S43>/Saturation'
       */
      ComparaModelos111_B.Saturation =
        ComparaModelos111_P.PIDController_UpperSaturationLi;
    } else if (ComparaModelos111_B.Saturation <
               ComparaModelos111_P.PIDController_LowerSaturationLi) {
      /* Sum: '<S45>/Sum' incorporates:
       *  Saturate: '<S43>/Saturation'
       */
      ComparaModelos111_B.Saturation =
        ComparaModelos111_P.PIDController_LowerSaturationLi;
    }

    /* End of Saturate: '<S43>/Saturation' */
    if (rtmIsMajorTimeStep(ComparaModelos111_M)) {
      /* Gain: '<S89>/Proportional Gain' */
      ComparaModelos111_B.ProportionalGain_c =
        ComparaModelos111_P.PIDController1_P * ComparaModelos111_B.Sum[1];
    }

    /* Sum: '<S93>/Sum' incorporates:
     *  Integrator: '<S84>/Integrator'
     */
    deltaT = floor(ComparaModelos111_B.ProportionalGain_c +
                   ComparaModelos111_X.Integrator_CSTATE_m);
    if (rtIsNaN(deltaT) || rtIsInf(deltaT)) {
      deltaT = 0.0;
    } else {
      deltaT = fmod(deltaT, 65536.0);
    }

    ComparaModelos111_B.Saturation_p = deltaT < 0.0 ? -(int16_T)(uint16_T)
      -deltaT : (int16_T)(uint16_T)deltaT;

    /* Saturate: '<S91>/Saturation' */
    if (ComparaModelos111_B.Saturation_p >
        ComparaModelos111_P.PIDController1_UpperSaturationL) {
      /* Sum: '<S93>/Sum' incorporates:
       *  Saturate: '<S91>/Saturation'
       */
      ComparaModelos111_B.Saturation_p =
        ComparaModelos111_P.PIDController1_UpperSaturationL;
    } else if (ComparaModelos111_B.Saturation_p <
               ComparaModelos111_P.PIDController1_LowerSaturationL) {
      /* Sum: '<S93>/Sum' incorporates:
       *  Saturate: '<S91>/Saturation'
       */
      ComparaModelos111_B.Saturation_p =
        ComparaModelos111_P.PIDController1_LowerSaturationL;
    }

    /* End of Saturate: '<S91>/Saturation' */
    if (rtmIsMajorTimeStep(ComparaModelos111_M)) {
      /* SignalConversion generated from: '<Root>/Subsystem' */
      ComparaModelos111_B.TmpSignalConversionAtTAQSigLogg[0] =
        ComparaModelos111_B.Saturation;
      ComparaModelos111_B.TmpSignalConversionAtTAQSigLogg[1] =
        ComparaModelos111_B.Saturation_p;
    }

    /* MATLABSystem: '<S103>/Adelante_der' */
    ComparaModelos111_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (12UL);

    /* Saturate: '<S103>/Saturation2' */
    if (ComparaModelos111_B.Saturation_p >
        ComparaModelos111_P.Saturation2_UpperSat) {
      y = ComparaModelos111_P.Saturation2_UpperSat;
    } else if (ComparaModelos111_B.Saturation_p <
               ComparaModelos111_P.Saturation2_LowerSat) {
      y = ComparaModelos111_P.Saturation2_LowerSat;
    } else {
      y = ComparaModelos111_B.Saturation_p;
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
    MW_PWM_SetDutyCycle(ComparaModelos111_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S103>/Atras_der' */
    ComparaModelos111_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (11UL);

    /* Saturate: '<S103>/Saturation3' */
    if (ComparaModelos111_B.Saturation_p >
        ComparaModelos111_P.Saturation3_UpperSat) {
      y = ComparaModelos111_P.Saturation3_UpperSat;
    } else if (ComparaModelos111_B.Saturation_p <
               ComparaModelos111_P.Saturation3_LowerSat) {
      y = ComparaModelos111_P.Saturation3_LowerSat;
    } else {
      y = ComparaModelos111_B.Saturation_p;
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
    MW_PWM_SetDutyCycle(ComparaModelos111_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S103>/Digital Output1' incorporates:
     *  Constant: '<S105>/Constant'
     *  RelationalOperator: '<S105>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(ComparaModelos111_B.Saturation_p !=
      ComparaModelos111_P.Constant_Value_n));

    /* Gain: '<S103>/Gain' */
    rtb_Gain_p = (int32_T)ComparaModelos111_P.Gain_Gain_o *
      ComparaModelos111_B.Saturation;

    /* MATLABSystem: '<S103>/Digital Output' incorporates:
     *  Constant: '<S104>/Constant'
     *  Gain: '<S103>/Gain'
     *  RelationalOperator: '<S104>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_Gain_p !=
      ComparaModelos111_P.Constant_Value_d));

    /* Saturate: '<S103>/Saturation4' incorporates:
     *  Gain: '<S103>/Gain'
     */
    if (rtb_Gain_p > ComparaModelos111_P.Saturation4_UpperSat) {
      rtb_Saturation4 = ComparaModelos111_P.Saturation4_UpperSat;
    } else if (rtb_Gain_p < ComparaModelos111_P.Saturation4_LowerSat) {
      rtb_Saturation4 = ComparaModelos111_P.Saturation4_LowerSat;
    } else {
      rtb_Saturation4 = rtb_Gain_p;
    }

    /* End of Saturate: '<S103>/Saturation4' */

    /* MATLABSystem: '<S103>/Adelante_izq' */
    ComparaModelos111_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

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
    MW_PWM_SetDutyCycle(ComparaModelos111_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                        deltaT);

    /* MATLABSystem: '<S103>/Atras_izq' */
    ComparaModelos111_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (10UL);

    /* Saturate: '<S103>/Saturation5' incorporates:
     *  Gain: '<S103>/Gain'
     */
    if (rtb_Gain_p > ComparaModelos111_P.Saturation5_UpperSat) {
      rtb_Gain_p = ComparaModelos111_P.Saturation5_UpperSat;
    } else if (rtb_Gain_p < ComparaModelos111_P.Saturation5_LowerSat) {
      rtb_Gain_p = ComparaModelos111_P.Saturation5_LowerSat;
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
    MW_PWM_SetDutyCycle(ComparaModelos111_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE,
                        deltaT);
    if (rtmIsMajorTimeStep(ComparaModelos111_M)) {
      /* Gain: '<S33>/Integral Gain' */
      ComparaModelos111_B.IntegralGain = ComparaModelos111_P.PIDController_I *
        ComparaModelos111_B.Sum[0];

      /* Gain: '<S81>/Integral Gain' */
      ComparaModelos111_B.IntegralGain_o = ComparaModelos111_P.PIDController1_I *
        ComparaModelos111_B.Sum[1];
    }
  }

  if (rtmIsMajorTimeStep(ComparaModelos111_M)) {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S102>/Derivative' */
    if (ComparaModelos111_DW.TimeStampA == (rtInf)) {
      ComparaModelos111_DW.TimeStampA = ComparaModelos111_M->Timing.t[0];
      lastU = &ComparaModelos111_DW.LastUAtTimeA;
    } else if (ComparaModelos111_DW.TimeStampB == (rtInf)) {
      ComparaModelos111_DW.TimeStampB = ComparaModelos111_M->Timing.t[0];
      lastU = &ComparaModelos111_DW.LastUAtTimeB;
    } else if (ComparaModelos111_DW.TimeStampA < ComparaModelos111_DW.TimeStampB)
    {
      ComparaModelos111_DW.TimeStampA = ComparaModelos111_M->Timing.t[0];
      lastU = &ComparaModelos111_DW.LastUAtTimeA;
    } else {
      ComparaModelos111_DW.TimeStampB = ComparaModelos111_M->Timing.t[0];
      lastU = &ComparaModelos111_DW.LastUAtTimeB;
    }

    (*lastU)[0] = ComparaModelos111_B.TmpRTBAtDerivativeInport1[0];
    (*lastU)[1] = ComparaModelos111_B.TmpRTBAtDerivativeInport1[1];

    /* End of Update for Derivative: '<S102>/Derivative' */
    if (rtmIsMajorTimeStep(ComparaModelos111_M)) {
      /* Update for Memory: '<Root>/Memory' */
      ComparaModelos111_DW.Memory_PreviousInput[0] =
        ComparaModelos111_B.Derivative[0];
      ComparaModelos111_DW.Memory_PreviousInput[1] =
        ComparaModelos111_B.Derivative[1];
    }

    {
      extmodeErrorCode_T returnCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentSimTime = (extmodeSimulationTime_T)
        ((ComparaModelos111_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      returnCode = extmodeEvent(1,currentSimTime);
      if (returnCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(ComparaModelos111_M)) {
    rt_ertODEUpdateContinuousStates(&ComparaModelos111_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++ComparaModelos111_M->Timing.clockTick0;
    ComparaModelos111_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ComparaModelos111_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    ComparaModelos111_M->Timing.clockTick1++;
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ComparaModelos111_derivatives(void)
{
  XDot_ComparaModelos111_T *_rtXdot;
  _rtXdot = ((XDot_ComparaModelos111_T *) ComparaModelos111_M->derivs);

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE = ComparaModelos111_B.IntegralGain;

  /* Derivatives for Integrator: '<S84>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = ComparaModelos111_B.IntegralGain_o;
}

/* Model step function for TID2 */
void ComparaModelos111_step2(void)     /* Sample time: [0.5s, 0.0s] */
{
  real_T rtb_Gain[2];
  real_T rtb_Gain_tmp;
  int32_T rtb_Encoder1_0;
  int32_T rtb_Encoder_0;

  /* MATLABSystem: '<S102>/Encoder' */
  if (ComparaModelos111_DW.obj_c.SampleTime !=
      ComparaModelos111_P.Encoder_SampleTime) {
    ComparaModelos111_DW.obj_c.SampleTime =
      ComparaModelos111_P.Encoder_SampleTime;
  }

  if (ComparaModelos111_DW.obj_c.TunablePropsChanged) {
    ComparaModelos111_DW.obj_c.TunablePropsChanged = false;
  }

  MW_EncoderRead(ComparaModelos111_DW.obj_c.Index, &rtb_Encoder_0);

  /* MATLABSystem: '<S102>/Encoder1' */
  if (ComparaModelos111_DW.obj.SampleTime !=
      ComparaModelos111_P.Encoder1_SampleTime) {
    ComparaModelos111_DW.obj.SampleTime =
      ComparaModelos111_P.Encoder1_SampleTime;
  }

  if (ComparaModelos111_DW.obj.TunablePropsChanged) {
    ComparaModelos111_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(ComparaModelos111_DW.obj.Index, &rtb_Encoder1_0);

  /* Gain: '<S102>/Gain' incorporates:
   *  MATLABSystem: '<S102>/Encoder'
   *  MATLABSystem: '<S102>/Encoder1'
   */
  rtb_Gain_tmp = (real_T)ComparaModelos111_P.Gain_Gain * 1.1368683772161603E-13;
  rtb_Gain[0] = rtb_Gain_tmp * (real_T)rtb_Encoder1_0;
  rtb_Gain[1] = rtb_Gain_tmp * (real_T)rtb_Encoder_0;

  /* RateTransition generated from: '<S102>/Derivative' */
  ComparaModelos111_DW.TmpRTBAtDerivativeInport1_Buffe[0] = rtb_Gain[0];
  ComparaModelos111_DW.TmpRTBAtDerivativeInport1_Buffe[1] = rtb_Gain[1];

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.5, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ComparaModelos111_M->Timing.clockTick2++;
}

/* Model initialize function */
void ComparaModelos111_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ComparaModelos111_M->solverInfo,
                          &ComparaModelos111_M->Timing.simTimeStep);
    rtsiSetTPtr(&ComparaModelos111_M->solverInfo, &rtmGetTPtr
                (ComparaModelos111_M));
    rtsiSetStepSizePtr(&ComparaModelos111_M->solverInfo,
                       &ComparaModelos111_M->Timing.stepSize0);
    rtsiSetdXPtr(&ComparaModelos111_M->solverInfo, &ComparaModelos111_M->derivs);
    rtsiSetContStatesPtr(&ComparaModelos111_M->solverInfo, (real_T **)
                         &ComparaModelos111_M->contStates);
    rtsiSetNumContStatesPtr(&ComparaModelos111_M->solverInfo,
      &ComparaModelos111_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ComparaModelos111_M->solverInfo,
      &ComparaModelos111_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ComparaModelos111_M->solverInfo,
      &ComparaModelos111_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ComparaModelos111_M->solverInfo,
      &ComparaModelos111_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&ComparaModelos111_M->solverInfo, (boolean_T**)
      &ComparaModelos111_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&ComparaModelos111_M->solverInfo, (&rtmGetErrorStatus
      (ComparaModelos111_M)));
    rtsiSetRTModelPtr(&ComparaModelos111_M->solverInfo, ComparaModelos111_M);
  }

  rtsiSetSimTimeStep(&ComparaModelos111_M->solverInfo, MAJOR_TIME_STEP);
  ComparaModelos111_M->intgData.y = ComparaModelos111_M->odeY;
  ComparaModelos111_M->intgData.f[0] = ComparaModelos111_M->odeF[0];
  ComparaModelos111_M->intgData.f[1] = ComparaModelos111_M->odeF[1];
  ComparaModelos111_M->intgData.f[2] = ComparaModelos111_M->odeF[2];
  ComparaModelos111_M->contStates = ((X_ComparaModelos111_T *)
    &ComparaModelos111_X);
  ComparaModelos111_M->contStateDisabled = ((XDis_ComparaModelos111_T *)
    &ComparaModelos111_XDis);
  ComparaModelos111_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&ComparaModelos111_M->solverInfo, (void *)
                    &ComparaModelos111_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&ComparaModelos111_M->solverInfo, false);
  rtsiSetSolverName(&ComparaModelos111_M->solverInfo,"ode3");
  rtmSetTPtr(ComparaModelos111_M, &ComparaModelos111_M->Timing.tArray[0]);
  rtmSetTFinal(ComparaModelos111_M, -1);
  ComparaModelos111_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  ComparaModelos111_M->Sizes.checksums[0] = (1435758055U);
  ComparaModelos111_M->Sizes.checksums[1] = (3471678582U);
  ComparaModelos111_M->Sizes.checksums[2] = (2228659172U);
  ComparaModelos111_M->Sizes.checksums[3] = (684012670U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    ComparaModelos111_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(ComparaModelos111_M->extModeInfo,
      &ComparaModelos111_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ComparaModelos111_M->extModeInfo,
                        ComparaModelos111_M->Sizes.checksums);
    rteiSetTPtr(ComparaModelos111_M->extModeInfo, rtmGetTPtr(ComparaModelos111_M));
  }

  /* Start for RateTransition generated from: '<S102>/Derivative' */
  ComparaModelos111_B.TmpRTBAtDerivativeInport1[0] =
    ComparaModelos111_P.TmpRTBAtDerivativeInport1_Initi;
  ComparaModelos111_B.TmpRTBAtDerivativeInport1[1] =
    ComparaModelos111_P.TmpRTBAtDerivativeInport1_Initi;

  /* InitializeConditions for RateTransition generated from: '<S102>/Derivative' */
  ComparaModelos111_DW.TmpRTBAtDerivativeInport1_Buffe[0] =
    ComparaModelos111_P.TmpRTBAtDerivativeInport1_Initi;
  ComparaModelos111_DW.TmpRTBAtDerivativeInport1_Buffe[1] =
    ComparaModelos111_P.TmpRTBAtDerivativeInport1_Initi;

  /* InitializeConditions for Derivative: '<S102>/Derivative' */
  ComparaModelos111_DW.TimeStampA = (rtInf);
  ComparaModelos111_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Memory: '<Root>/Memory' */
  ComparaModelos111_DW.Memory_PreviousInput[0] =
    ComparaModelos111_P.Memory_InitialCondition;
  ComparaModelos111_DW.Memory_PreviousInput[1] =
    ComparaModelos111_P.Memory_InitialCondition;

  /* InitializeConditions for Integrator: '<S36>/Integrator' */
  ComparaModelos111_X.Integrator_CSTATE =
    ComparaModelos111_P.PIDController_InitialConditionF;

  /* InitializeConditions for Integrator: '<S84>/Integrator' */
  ComparaModelos111_X.Integrator_CSTATE_m =
    ComparaModelos111_P.PIDController1_InitialCondition;

  /* Start for MATLABSystem: '<S103>/Adelante_der' */
  ComparaModelos111_DW.obj_d.matlabCodegenIsDeleted = false;
  ComparaModelos111_DW.obj_d.isInitialized = 1L;
  ComparaModelos111_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0,
    0.0);
  ComparaModelos111_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Atras_der' */
  ComparaModelos111_DW.obj_b.matlabCodegenIsDeleted = false;
  ComparaModelos111_DW.obj_b.isInitialized = 1L;
  ComparaModelos111_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  ComparaModelos111_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Digital Output1' */
  ComparaModelos111_DW.obj_c0.matlabCodegenIsDeleted = false;
  ComparaModelos111_DW.obj_c0.isInitialized = 1L;
  digitalIOSetup(13, 1);
  ComparaModelos111_DW.obj_c0.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Digital Output' */
  ComparaModelos111_DW.obj_i.matlabCodegenIsDeleted = false;
  ComparaModelos111_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(8, 1);
  ComparaModelos111_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Adelante_izq' */
  ComparaModelos111_DW.obj_g.matlabCodegenIsDeleted = false;
  ComparaModelos111_DW.obj_g.isInitialized = 1L;
  ComparaModelos111_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0,
    0.0);
  ComparaModelos111_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Atras_izq' */
  ComparaModelos111_DW.obj_cc.matlabCodegenIsDeleted = false;
  ComparaModelos111_DW.obj_cc.isInitialized = 1L;
  ComparaModelos111_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0,
    0.0);
  ComparaModelos111_DW.obj_cc.isSetupComplete = true;

  /* Start for MATLABSystem: '<S102>/Encoder' */
  ComparaModelos111_DW.obj_c.Index = 0U;
  ComparaModelos111_DW.obj_c.matlabCodegenIsDeleted = false;
  ComparaModelos111_DW.obj_c.SampleTime = ComparaModelos111_P.Encoder_SampleTime;
  ComparaModelos111_DW.obj_c.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &ComparaModelos111_DW.obj_c.Index);
  ComparaModelos111_DW.obj_c.isSetupComplete = true;
  ComparaModelos111_DW.obj_c.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S102>/Encoder' */
  MW_EncoderReset(ComparaModelos111_DW.obj_c.Index);

  /* Start for MATLABSystem: '<S102>/Encoder1' */
  ComparaModelos111_DW.obj.Index = 0U;
  ComparaModelos111_DW.obj.matlabCodegenIsDeleted = false;
  ComparaModelos111_DW.obj.SampleTime = ComparaModelos111_P.Encoder1_SampleTime;
  ComparaModelos111_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &ComparaModelos111_DW.obj.Index);
  ComparaModelos111_DW.obj.isSetupComplete = true;
  ComparaModelos111_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S102>/Encoder1' */
  MW_EncoderReset(ComparaModelos111_DW.obj.Index);
}

/* Model terminate function */
void ComparaModelos111_terminate(void)
{
  /* Terminate for MATLABSystem: '<S103>/Adelante_der' */
  if (!ComparaModelos111_DW.obj_d.matlabCodegenIsDeleted) {
    ComparaModelos111_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((ComparaModelos111_DW.obj_d.isInitialized == 1L) &&
        ComparaModelos111_DW.obj_d.isSetupComplete) {
      ComparaModelos111_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_SetDutyCycle(ComparaModelos111_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ComparaModelos111_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_Close(ComparaModelos111_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S103>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S103>/Atras_der' */
  if (!ComparaModelos111_DW.obj_b.matlabCodegenIsDeleted) {
    ComparaModelos111_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((ComparaModelos111_DW.obj_b.isInitialized == 1L) &&
        ComparaModelos111_DW.obj_b.isSetupComplete) {
      ComparaModelos111_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_SetDutyCycle(ComparaModelos111_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ComparaModelos111_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_Close(ComparaModelos111_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S103>/Atras_der' */

  /* Terminate for MATLABSystem: '<S103>/Digital Output1' */
  if (!ComparaModelos111_DW.obj_c0.matlabCodegenIsDeleted) {
    ComparaModelos111_DW.obj_c0.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S103>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S103>/Digital Output' */
  if (!ComparaModelos111_DW.obj_i.matlabCodegenIsDeleted) {
    ComparaModelos111_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S103>/Digital Output' */

  /* Terminate for MATLABSystem: '<S103>/Adelante_izq' */
  if (!ComparaModelos111_DW.obj_g.matlabCodegenIsDeleted) {
    ComparaModelos111_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((ComparaModelos111_DW.obj_g.isInitialized == 1L) &&
        ComparaModelos111_DW.obj_g.isSetupComplete) {
      ComparaModelos111_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);
      MW_PWM_SetDutyCycle(ComparaModelos111_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ComparaModelos111_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);
      MW_PWM_Close(ComparaModelos111_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S103>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S103>/Atras_izq' */
  if (!ComparaModelos111_DW.obj_cc.matlabCodegenIsDeleted) {
    ComparaModelos111_DW.obj_cc.matlabCodegenIsDeleted = true;
    if ((ComparaModelos111_DW.obj_cc.isInitialized == 1L) &&
        ComparaModelos111_DW.obj_cc.isSetupComplete) {
      ComparaModelos111_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_SetDutyCycle(ComparaModelos111_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ComparaModelos111_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_Close(ComparaModelos111_DW.obj_cc.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S103>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S102>/Encoder' */
  if (!ComparaModelos111_DW.obj_c.matlabCodegenIsDeleted) {
    ComparaModelos111_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((ComparaModelos111_DW.obj_c.isInitialized == 1L) &&
        ComparaModelos111_DW.obj_c.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S102>/Encoder' */

  /* Terminate for MATLABSystem: '<S102>/Encoder1' */
  if (!ComparaModelos111_DW.obj.matlabCodegenIsDeleted) {
    ComparaModelos111_DW.obj.matlabCodegenIsDeleted = true;
    if ((ComparaModelos111_DW.obj.isInitialized == 1L) &&
        ComparaModelos111_DW.obj.isSetupComplete) {
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
