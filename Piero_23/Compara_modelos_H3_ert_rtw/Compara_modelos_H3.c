/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Compara_modelos_H3.c
 *
 * Code generated for Simulink model 'Compara_modelos_H3'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 30 01:09:28 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Compara_modelos_H3.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "Compara_modelos_H3_private.h"

/* Block signals (default storage) */
B_Compara_modelos_H3_T Compara_modelos_H3_B;

/* Continuous states */
X_Compara_modelos_H3_T Compara_modelos_H3_X;

/* Disabled State Vector */
XDis_Compara_modelos_H3_T Compara_modelos_H3_XDis;

/* Block states (default storage) */
DW_Compara_modelos_H3_T Compara_modelos_H3_DW;

/* Real-time model */
static RT_MODEL_Compara_modelos_H3_T Compara_modelos_H3_M_;
RT_MODEL_Compara_modelos_H3_T *const Compara_modelos_H3_M =
  &Compara_modelos_H3_M_;

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
  Compara_modelos_H3_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Compara_modelos_H3_step();
  Compara_modelos_H3_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Compara_modelos_H3_step();
  Compara_modelos_H3_derivatives();

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
void Compara_modelos_H3_step(void)
{
  if (rtmIsMajorTimeStep(Compara_modelos_H3_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Compara_modelos_H3_M->solverInfo,
                          ((Compara_modelos_H3_M->Timing.clockTick0+1)*
      Compara_modelos_H3_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Compara_modelos_H3_M)) {
    Compara_modelos_H3_M->Timing.t[0] = rtsiGetT
      (&Compara_modelos_H3_M->solverInfo);
  }

  {
    real_T (*lastU)[2];
    real_T Gain_tmp;
    real_T lastTime;
    int32_T rtb_Gain;
    int32_T rtb_Saturation4;
    int16_T rtb_DataTypeConversion_0;
    int16_T rtb_DataTypeConversion_idx_0;
    int16_T y;

    /* MATLABSystem: '<S3>/Encoder' */
    if (Compara_modelos_H3_DW.obj_d.SampleTime !=
        Compara_modelos_H3_P.Encoder_SampleTime) {
      Compara_modelos_H3_DW.obj_d.SampleTime =
        Compara_modelos_H3_P.Encoder_SampleTime;
    }

    if (Compara_modelos_H3_DW.obj_d.TunablePropsChanged) {
      Compara_modelos_H3_DW.obj_d.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S3>/Encoder' */
    MW_EncoderRead(Compara_modelos_H3_DW.obj_d.Index,
                   &Compara_modelos_H3_B.Encoder);

    /* MATLABSystem: '<S3>/Encoder1' */
    if (Compara_modelos_H3_DW.obj.SampleTime !=
        Compara_modelos_H3_P.Encoder1_SampleTime) {
      Compara_modelos_H3_DW.obj.SampleTime =
        Compara_modelos_H3_P.Encoder1_SampleTime;
    }

    if (Compara_modelos_H3_DW.obj.TunablePropsChanged) {
      Compara_modelos_H3_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S3>/Encoder1' */
    MW_EncoderRead(Compara_modelos_H3_DW.obj.Index,
                   &Compara_modelos_H3_B.Encoder1);

    /* Gain: '<S3>/Gain' */
    Gain_tmp = (real_T)Compara_modelos_H3_P.Gain_Gain * 1.1368683772161603E-13;

    /* Gain: '<S3>/Gain' incorporates:
     *  SignalConversion generated from: '<S3>/Gain'
     */
    Compara_modelos_H3_B.Gain[0] = Gain_tmp * (real_T)
      Compara_modelos_H3_B.Encoder;
    Compara_modelos_H3_B.Gain[1] = Gain_tmp * (real_T)
      Compara_modelos_H3_B.Encoder1;

    /* Derivative: '<S3>/Derivative' */
    Gain_tmp = Compara_modelos_H3_M->Timing.t[0];
    if ((Compara_modelos_H3_DW.TimeStampA >= Gain_tmp) &&
        (Compara_modelos_H3_DW.TimeStampB >= Gain_tmp)) {
      /* Derivative: '<S3>/Derivative' */
      Compara_modelos_H3_B.Derivative[0] = 0.0;
      Compara_modelos_H3_B.Derivative[1] = 0.0;
    } else {
      lastTime = Compara_modelos_H3_DW.TimeStampA;
      lastU = &Compara_modelos_H3_DW.LastUAtTimeA;
      if (Compara_modelos_H3_DW.TimeStampA < Compara_modelos_H3_DW.TimeStampB) {
        if (Compara_modelos_H3_DW.TimeStampB < Gain_tmp) {
          lastTime = Compara_modelos_H3_DW.TimeStampB;
          lastU = &Compara_modelos_H3_DW.LastUAtTimeB;
        }
      } else if (Compara_modelos_H3_DW.TimeStampA >= Gain_tmp) {
        lastTime = Compara_modelos_H3_DW.TimeStampB;
        lastU = &Compara_modelos_H3_DW.LastUAtTimeB;
      }

      Gain_tmp -= lastTime;

      /* Derivative: '<S3>/Derivative' */
      Compara_modelos_H3_B.Derivative[0] = (Compara_modelos_H3_B.Gain[0] -
        (*lastU)[0]) / Gain_tmp;
      Compara_modelos_H3_B.Derivative[1] = (Compara_modelos_H3_B.Gain[1] -
        (*lastU)[1]) / Gain_tmp;
    }

    /* End of Derivative: '<S3>/Derivative' */

    /* TransferFcn: '<S1>/Rizq' */
    Compara_modelos_H3_B.Rizq = Compara_modelos_H3_P.Rizq_C *
      Compara_modelos_H3_X.Rizq_CSTATE;

    /* TransferFcn: '<S1>/Rder' */
    Compara_modelos_H3_B.Rder = Compara_modelos_H3_P.Rder_C *
      Compara_modelos_H3_X.Rder_CSTATE;
    if (rtmIsMajorTimeStep(Compara_modelos_H3_M)) {
      /* SignalConversion generated from: '<Root>/Mux' */
      Compara_modelos_H3_B.TmpSignalConversionAtTAQSigLogg[2] =
        Compara_modelos_H3_B.Rizq;
      Compara_modelos_H3_B.TmpSignalConversionAtTAQSigLogg[3] =
        Compara_modelos_H3_B.Rder;
      Compara_modelos_H3_B.TmpSignalConversionAtTAQSigLogg[0] =
        Compara_modelos_H3_B.Derivative[0];

      /* Constant: '<Root>/Constant' */
      Compara_modelos_H3_B.Constant[0] = Compara_modelos_H3_P.Constant_Value[0];

      /* SignalConversion generated from: '<Root>/Mux' */
      Compara_modelos_H3_B.TmpSignalConversionAtTAQSigLogg[1] =
        Compara_modelos_H3_B.Derivative[1];

      /* Constant: '<Root>/Constant' */
      Compara_modelos_H3_B.Constant[1] = Compara_modelos_H3_P.Constant_Value[1];

      /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
       *  Constant: '<Root>/Constant'
       */
      Gain_tmp = floor(Compara_modelos_H3_B.Constant[0]);
      if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
        Gain_tmp = 0.0;
      } else {
        Gain_tmp = fmod(Gain_tmp, 65536.0);
      }

      rtb_DataTypeConversion_0 = Gain_tmp < 0.0 ? -(int16_T)(uint16_T)-Gain_tmp :
        (int16_T)(uint16_T)Gain_tmp;
      rtb_DataTypeConversion_idx_0 = rtb_DataTypeConversion_0;

      /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion'
       */
      Compara_modelos_H3_B.DataTypeConversion[0] = rtb_DataTypeConversion_0;

      /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
       *  Constant: '<Root>/Constant'
       */
      Gain_tmp = floor(Compara_modelos_H3_B.Constant[1]);
      if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
        Gain_tmp = 0.0;
      } else {
        Gain_tmp = fmod(Gain_tmp, 65536.0);
      }

      rtb_DataTypeConversion_0 = Gain_tmp < 0.0 ? -(int16_T)(uint16_T)-Gain_tmp :
        (int16_T)(uint16_T)Gain_tmp;

      /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion'
       */
      Compara_modelos_H3_B.DataTypeConversion[1] = rtb_DataTypeConversion_0;

      /* SignalConversion generated from: '<S3>/Mux' */
      Compara_modelos_H3_B.TmpSignalConversionAtTAQSigLo_j[0] =
        Compara_modelos_H3_B.Encoder;
      Compara_modelos_H3_B.TmpSignalConversionAtTAQSigLo_j[1] =
        Compara_modelos_H3_B.Encoder1;

      /* MATLABSystem: '<S4>/Adelante_der' */
      Compara_modelos_H3_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);

      /* Saturate: '<S4>/Saturation2' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion'
       */
      if (rtb_DataTypeConversion_0 > Compara_modelos_H3_P.Saturation2_UpperSat)
      {
        y = Compara_modelos_H3_P.Saturation2_UpperSat;
      } else if (rtb_DataTypeConversion_0 <
                 Compara_modelos_H3_P.Saturation2_LowerSat) {
        y = Compara_modelos_H3_P.Saturation2_LowerSat;
      } else {
        y = rtb_DataTypeConversion_0;
      }

      /* End of Saturate: '<S4>/Saturation2' */

      /* Start for MATLABSystem: '<S4>/Adelante_der' */
      if (y > 255) {
        y = 255;
      }

      if (y < 0) {
        y = 0;
      }

      /* MATLABSystem: '<S4>/Adelante_der' */
      MW_PWM_SetDutyCycle(Compara_modelos_H3_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                          (real_T)y);

      /* Gain: '<S4>/Gain' */
      rtb_Gain = (int32_T)Compara_modelos_H3_P.Gain_Gain_f *
        rtb_DataTypeConversion_idx_0;

      /* MATLABSystem: '<S4>/Digital Output' incorporates:
       *  Constant: '<S5>/Constant'
       *  Gain: '<S4>/Gain'
       *  RelationalOperator: '<S5>/Compare'
       */
      writeDigitalPin(8, (uint8_T)(rtb_Gain !=
        Compara_modelos_H3_P.Constant_Value_d));

      /* Saturate: '<S4>/Saturation4' incorporates:
       *  Gain: '<S4>/Gain'
       */
      if (rtb_Gain > Compara_modelos_H3_P.Saturation4_UpperSat) {
        rtb_Saturation4 = Compara_modelos_H3_P.Saturation4_UpperSat;
      } else if (rtb_Gain < Compara_modelos_H3_P.Saturation4_LowerSat) {
        rtb_Saturation4 = Compara_modelos_H3_P.Saturation4_LowerSat;
      } else {
        rtb_Saturation4 = rtb_Gain;
      }

      /* End of Saturate: '<S4>/Saturation4' */

      /* MATLABSystem: '<S4>/Adelante_izq' */
      Compara_modelos_H3_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);

      /* Abs: '<S4>/Abs2' incorporates:
       *  Saturate: '<S4>/Saturation4'
       */
      if (rtb_Saturation4 < 0L) {
        rtb_Saturation4 = -rtb_Saturation4;
      }

      /* Start for MATLABSystem: '<S4>/Adelante_izq' incorporates:
       *  Abs: '<S4>/Abs2'
       */
      Gain_tmp = (real_T)rtb_Saturation4 * 6.103515625E-5;
      if (!(Gain_tmp <= 255.0)) {
        Gain_tmp = 255.0;
      }

      if (!(Gain_tmp >= 0.0)) {
        Gain_tmp = 0.0;
      }

      /* MATLABSystem: '<S4>/Adelante_izq' */
      MW_PWM_SetDutyCycle(Compara_modelos_H3_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                          Gain_tmp);

      /* MATLABSystem: '<S4>/Atras_izq' */
      Compara_modelos_H3_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);

      /* Saturate: '<S4>/Saturation5' incorporates:
       *  Gain: '<S4>/Gain'
       */
      if (rtb_Gain > Compara_modelos_H3_P.Saturation5_UpperSat) {
        rtb_Gain = Compara_modelos_H3_P.Saturation5_UpperSat;
      } else if (rtb_Gain < Compara_modelos_H3_P.Saturation5_LowerSat) {
        rtb_Gain = Compara_modelos_H3_P.Saturation5_LowerSat;
      }

      /* Start for MATLABSystem: '<S4>/Atras_izq' incorporates:
       *  Saturate: '<S4>/Saturation5'
       */
      Gain_tmp = (real_T)rtb_Gain * 6.103515625E-5;
      if (!(Gain_tmp <= 255.0)) {
        Gain_tmp = 255.0;
      }

      if (!(Gain_tmp >= 0.0)) {
        Gain_tmp = 0.0;
      }

      /* MATLABSystem: '<S4>/Atras_izq' */
      MW_PWM_SetDutyCycle(Compara_modelos_H3_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE,
                          Gain_tmp);

      /* MATLABSystem: '<S4>/Atras_der' */
      Compara_modelos_H3_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);

      /* Saturate: '<S4>/Saturation3' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion'
       */
      if (rtb_DataTypeConversion_0 > Compara_modelos_H3_P.Saturation3_UpperSat)
      {
        y = Compara_modelos_H3_P.Saturation3_UpperSat;
      } else if (rtb_DataTypeConversion_0 <
                 Compara_modelos_H3_P.Saturation3_LowerSat) {
        y = Compara_modelos_H3_P.Saturation3_LowerSat;
      } else {
        y = rtb_DataTypeConversion_0;
      }

      /* End of Saturate: '<S4>/Saturation3' */

      /* Abs: '<S4>/Abs1' */
      if (y < 0) {
        y = -y;
      }

      /* End of Abs: '<S4>/Abs1' */

      /* Start for MATLABSystem: '<S4>/Atras_der' */
      if (y > 255) {
        y = 255;
      }

      if (y < 0) {
        y = 0;
      }

      /* MATLABSystem: '<S4>/Atras_der' */
      MW_PWM_SetDutyCycle(Compara_modelos_H3_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE,
                          (real_T)y);

      /* MATLABSystem: '<S4>/Digital Output1' incorporates:
       *  Constant: '<S6>/Constant'
       *  DataTypeConversion: '<Root>/Data Type Conversion'
       *  RelationalOperator: '<S6>/Compare'
       */
      writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_0 !=
        Compara_modelos_H3_P.Constant_Value_p));
    }
  }

  if (rtmIsMajorTimeStep(Compara_modelos_H3_M)) {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S3>/Derivative' */
    if (Compara_modelos_H3_DW.TimeStampA == (rtInf)) {
      Compara_modelos_H3_DW.TimeStampA = Compara_modelos_H3_M->Timing.t[0];
      lastU = &Compara_modelos_H3_DW.LastUAtTimeA;
    } else if (Compara_modelos_H3_DW.TimeStampB == (rtInf)) {
      Compara_modelos_H3_DW.TimeStampB = Compara_modelos_H3_M->Timing.t[0];
      lastU = &Compara_modelos_H3_DW.LastUAtTimeB;
    } else if (Compara_modelos_H3_DW.TimeStampA <
               Compara_modelos_H3_DW.TimeStampB) {
      Compara_modelos_H3_DW.TimeStampA = Compara_modelos_H3_M->Timing.t[0];
      lastU = &Compara_modelos_H3_DW.LastUAtTimeA;
    } else {
      Compara_modelos_H3_DW.TimeStampB = Compara_modelos_H3_M->Timing.t[0];
      lastU = &Compara_modelos_H3_DW.LastUAtTimeB;
    }

    (*lastU)[0] = Compara_modelos_H3_B.Gain[0];
    (*lastU)[1] = Compara_modelos_H3_B.Gain[1];

    /* End of Update for Derivative: '<S3>/Derivative' */
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((Compara_modelos_H3_M->Timing.clockTick0 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(Compara_modelos_H3_M)) {/* Sample time: [0.2s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((Compara_modelos_H3_M->Timing.clockTick1 * 1) + 0)
        ;

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Compara_modelos_H3_M)) {
    rt_ertODEUpdateContinuousStates(&Compara_modelos_H3_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Compara_modelos_H3_M->Timing.clockTick0;
    Compara_modelos_H3_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Compara_modelos_H3_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Compara_modelos_H3_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Compara_modelos_H3_derivatives(void)
{
  XDot_Compara_modelos_H3_T *_rtXdot;
  _rtXdot = ((XDot_Compara_modelos_H3_T *) Compara_modelos_H3_M->derivs);

  /* Derivatives for TransferFcn: '<S1>/Rizq' */
  _rtXdot->Rizq_CSTATE = Compara_modelos_H3_P.Rizq_A *
    Compara_modelos_H3_X.Rizq_CSTATE;
  _rtXdot->Rizq_CSTATE += Compara_modelos_H3_B.DataTypeConversion[0];

  /* Derivatives for TransferFcn: '<S1>/Rder' */
  _rtXdot->Rder_CSTATE = Compara_modelos_H3_P.Rder_A *
    Compara_modelos_H3_X.Rder_CSTATE;
  _rtXdot->Rder_CSTATE += Compara_modelos_H3_B.DataTypeConversion[1];
}

/* Model initialize function */
void Compara_modelos_H3_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Compara_modelos_H3_M->solverInfo,
                          &Compara_modelos_H3_M->Timing.simTimeStep);
    rtsiSetTPtr(&Compara_modelos_H3_M->solverInfo, &rtmGetTPtr
                (Compara_modelos_H3_M));
    rtsiSetStepSizePtr(&Compara_modelos_H3_M->solverInfo,
                       &Compara_modelos_H3_M->Timing.stepSize0);
    rtsiSetdXPtr(&Compara_modelos_H3_M->solverInfo,
                 &Compara_modelos_H3_M->derivs);
    rtsiSetContStatesPtr(&Compara_modelos_H3_M->solverInfo, (real_T **)
                         &Compara_modelos_H3_M->contStates);
    rtsiSetNumContStatesPtr(&Compara_modelos_H3_M->solverInfo,
      &Compara_modelos_H3_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Compara_modelos_H3_M->solverInfo,
      &Compara_modelos_H3_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Compara_modelos_H3_M->solverInfo,
      &Compara_modelos_H3_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Compara_modelos_H3_M->solverInfo,
      &Compara_modelos_H3_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&Compara_modelos_H3_M->solverInfo, (boolean_T**)
      &Compara_modelos_H3_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&Compara_modelos_H3_M->solverInfo, (&rtmGetErrorStatus
      (Compara_modelos_H3_M)));
    rtsiSetRTModelPtr(&Compara_modelos_H3_M->solverInfo, Compara_modelos_H3_M);
  }

  rtsiSetSimTimeStep(&Compara_modelos_H3_M->solverInfo, MAJOR_TIME_STEP);
  Compara_modelos_H3_M->intgData.y = Compara_modelos_H3_M->odeY;
  Compara_modelos_H3_M->intgData.f[0] = Compara_modelos_H3_M->odeF[0];
  Compara_modelos_H3_M->intgData.f[1] = Compara_modelos_H3_M->odeF[1];
  Compara_modelos_H3_M->intgData.f[2] = Compara_modelos_H3_M->odeF[2];
  Compara_modelos_H3_M->contStates = ((X_Compara_modelos_H3_T *)
    &Compara_modelos_H3_X);
  Compara_modelos_H3_M->contStateDisabled = ((XDis_Compara_modelos_H3_T *)
    &Compara_modelos_H3_XDis);
  Compara_modelos_H3_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&Compara_modelos_H3_M->solverInfo, (void *)
                    &Compara_modelos_H3_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Compara_modelos_H3_M->solverInfo, false);
  rtsiSetSolverName(&Compara_modelos_H3_M->solverInfo,"ode3");
  rtmSetTPtr(Compara_modelos_H3_M, &Compara_modelos_H3_M->Timing.tArray[0]);
  rtmSetTFinal(Compara_modelos_H3_M, 10.0);
  Compara_modelos_H3_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  Compara_modelos_H3_M->Sizes.checksums[0] = (1024578215U);
  Compara_modelos_H3_M->Sizes.checksums[1] = (1032329745U);
  Compara_modelos_H3_M->Sizes.checksums[2] = (3267303908U);
  Compara_modelos_H3_M->Sizes.checksums[3] = (1804623537U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    Compara_modelos_H3_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(Compara_modelos_H3_M->extModeInfo,
      &Compara_modelos_H3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Compara_modelos_H3_M->extModeInfo,
                        Compara_modelos_H3_M->Sizes.checksums);
    rteiSetTPtr(Compara_modelos_H3_M->extModeInfo, rtmGetTPtr
                (Compara_modelos_H3_M));
  }

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  Compara_modelos_H3_DW.TimeStampA = (rtInf);
  Compara_modelos_H3_DW.TimeStampB = (rtInf);

  /* InitializeConditions for TransferFcn: '<S1>/Rizq' */
  Compara_modelos_H3_X.Rizq_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Rder' */
  Compara_modelos_H3_X.Rder_CSTATE = 0.0;

  /* Start for MATLABSystem: '<S3>/Encoder' */
  Compara_modelos_H3_DW.obj_d.Index = 0U;
  Compara_modelos_H3_DW.obj_d.matlabCodegenIsDeleted = false;
  Compara_modelos_H3_DW.obj_d.SampleTime =
    Compara_modelos_H3_P.Encoder_SampleTime;
  Compara_modelos_H3_DW.obj_d.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &Compara_modelos_H3_DW.obj_d.Index);
  Compara_modelos_H3_DW.obj_d.isSetupComplete = true;
  Compara_modelos_H3_DW.obj_d.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
  MW_EncoderReset(Compara_modelos_H3_DW.obj_d.Index);

  /* Start for MATLABSystem: '<S3>/Encoder1' */
  Compara_modelos_H3_DW.obj.Index = 0U;
  Compara_modelos_H3_DW.obj.matlabCodegenIsDeleted = false;
  Compara_modelos_H3_DW.obj.SampleTime =
    Compara_modelos_H3_P.Encoder1_SampleTime;
  Compara_modelos_H3_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &Compara_modelos_H3_DW.obj.Index);
  Compara_modelos_H3_DW.obj.isSetupComplete = true;
  Compara_modelos_H3_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder1' */
  MW_EncoderReset(Compara_modelos_H3_DW.obj.Index);

  /* Start for MATLABSystem: '<S4>/Adelante_der' */
  Compara_modelos_H3_DW.obj_g.matlabCodegenIsDeleted = false;
  Compara_modelos_H3_DW.obj_g.isInitialized = 1L;
  Compara_modelos_H3_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0,
    0.0);
  Compara_modelos_H3_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output' */
  Compara_modelos_H3_DW.obj_m.matlabCodegenIsDeleted = false;
  Compara_modelos_H3_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(8, 1);
  Compara_modelos_H3_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Adelante_izq' */
  Compara_modelos_H3_DW.obj_j.matlabCodegenIsDeleted = false;
  Compara_modelos_H3_DW.obj_j.isInitialized = 1L;
  Compara_modelos_H3_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0,
    0.0);
  Compara_modelos_H3_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_izq' */
  Compara_modelos_H3_DW.obj_a.matlabCodegenIsDeleted = false;
  Compara_modelos_H3_DW.obj_a.isInitialized = 1L;
  Compara_modelos_H3_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0,
    0.0);
  Compara_modelos_H3_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_der' */
  Compara_modelos_H3_DW.obj_i.matlabCodegenIsDeleted = false;
  Compara_modelos_H3_DW.obj_i.isInitialized = 1L;
  Compara_modelos_H3_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  Compara_modelos_H3_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  Compara_modelos_H3_DW.obj_gs.matlabCodegenIsDeleted = false;
  Compara_modelos_H3_DW.obj_gs.isInitialized = 1L;
  digitalIOSetup(13, 1);
  Compara_modelos_H3_DW.obj_gs.isSetupComplete = true;
}

/* Model terminate function */
void Compara_modelos_H3_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!Compara_modelos_H3_DW.obj_d.matlabCodegenIsDeleted) {
    Compara_modelos_H3_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Compara_modelos_H3_DW.obj_d.isInitialized == 1L) &&
        Compara_modelos_H3_DW.obj_d.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */

  /* Terminate for MATLABSystem: '<S3>/Encoder1' */
  if (!Compara_modelos_H3_DW.obj.matlabCodegenIsDeleted) {
    Compara_modelos_H3_DW.obj.matlabCodegenIsDeleted = true;
    if ((Compara_modelos_H3_DW.obj.isInitialized == 1L) &&
        Compara_modelos_H3_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder1' */
  /* Terminate for MATLABSystem: '<S4>/Adelante_der' */
  if (!Compara_modelos_H3_DW.obj_g.matlabCodegenIsDeleted) {
    Compara_modelos_H3_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Compara_modelos_H3_DW.obj_g.isInitialized == 1L) &&
        Compara_modelos_H3_DW.obj_g.isSetupComplete) {
      Compara_modelos_H3_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_SetDutyCycle(Compara_modelos_H3_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      Compara_modelos_H3_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_Close(Compara_modelos_H3_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!Compara_modelos_H3_DW.obj_m.matlabCodegenIsDeleted) {
    Compara_modelos_H3_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */

  /* Terminate for MATLABSystem: '<S4>/Adelante_izq' */
  if (!Compara_modelos_H3_DW.obj_j.matlabCodegenIsDeleted) {
    Compara_modelos_H3_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Compara_modelos_H3_DW.obj_j.isInitialized == 1L) &&
        Compara_modelos_H3_DW.obj_j.isSetupComplete) {
      Compara_modelos_H3_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);
      MW_PWM_SetDutyCycle(Compara_modelos_H3_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      Compara_modelos_H3_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);
      MW_PWM_Close(Compara_modelos_H3_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S4>/Atras_izq' */
  if (!Compara_modelos_H3_DW.obj_a.matlabCodegenIsDeleted) {
    Compara_modelos_H3_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Compara_modelos_H3_DW.obj_a.isInitialized == 1L) &&
        Compara_modelos_H3_DW.obj_a.isSetupComplete) {
      Compara_modelos_H3_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_SetDutyCycle(Compara_modelos_H3_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      Compara_modelos_H3_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_Close(Compara_modelos_H3_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S4>/Atras_der' */
  if (!Compara_modelos_H3_DW.obj_i.matlabCodegenIsDeleted) {
    Compara_modelos_H3_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Compara_modelos_H3_DW.obj_i.isInitialized == 1L) &&
        Compara_modelos_H3_DW.obj_i.isSetupComplete) {
      Compara_modelos_H3_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_SetDutyCycle(Compara_modelos_H3_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      Compara_modelos_H3_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_Close(Compara_modelos_H3_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_der' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!Compara_modelos_H3_DW.obj_gs.matlabCodegenIsDeleted) {
    Compara_modelos_H3_DW.obj_gs.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
