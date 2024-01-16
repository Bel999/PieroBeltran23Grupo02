/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Primera_Parte_Hito2_Siganl_PWM.c
 *
 * Code generated for Simulink model 'Primera_Parte_Hito2_Siganl_PWM'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Nov 14 20:31:21 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Primera_Parte_Hito2_Siganl_PWM.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "Primera_Parte_Hito2_Siganl_PWM_private.h"

/* Block signals (default storage) */
B_Primera_Parte_Hito2_Siganl__T Primera_Parte_Hito2_Siganl_PW_B;

/* Block states (default storage) */
DW_Primera_Parte_Hito2_Siganl_T Primera_Parte_Hito2_Siganl_P_DW;

/* Real-time model */
static RT_MODEL_Primera_Parte_Hito2__T Primera_Parte_Hito2_Siganl_P_M_;
RT_MODEL_Primera_Parte_Hito2__T *const Primera_Parte_Hito2_Siganl_P_M =
  &Primera_Parte_Hito2_Siganl_P_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Primera_Parte_Hito2_Siganl_PWM_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(Primera_Parte_Hito2_Siganl_P_M, 2));
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
  if (Primera_Parte_Hito2_Siganl_P_M->Timing.TaskCounters.TID[1] == 0) {
    Primera_Parte_Hito2_Siganl_P_M->Timing.RateInteraction.TID1_2 =
      (Primera_Parte_Hito2_Siganl_P_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Primera_Parte_Hito2_Siganl_P_M->Timing.TaskCounters.TID[2])++;
  if ((Primera_Parte_Hito2_Siganl_P_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    Primera_Parte_Hito2_Siganl_P_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function for TID0 */
void Primera_Parte_Hito2_Siganl_PWM_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  {
    real_T (*lastU)[2];
    real_T deltaT;
    real_T lastTime_tmp;
    int16_T rtb_DataTypeConversion_idx_0;
    int16_T rtb_DataTypeConversion_idx_1;
    int16_T y;

    /* RateTransition generated from: '<S3>/Derivative' */
    if (Primera_Parte_Hito2_Siganl_P_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition generated from: '<S3>/Derivative' */
      Primera_Parte_Hito2_Siganl_PW_B.TmpRTBAtDerivativeInport1[0] =
        Primera_Parte_Hito2_Siganl_P_DW.TmpRTBAtDerivativeInport1_Buffe[0];
      Primera_Parte_Hito2_Siganl_PW_B.TmpRTBAtDerivativeInport1[1] =
        Primera_Parte_Hito2_Siganl_P_DW.TmpRTBAtDerivativeInport1_Buffe[1];
    }

    /* End of RateTransition generated from: '<S3>/Derivative' */

    /* Derivative: '<S3>/Derivative' */
    deltaT = Primera_Parte_Hito2_Siganl_P_M->Timing.t[0];
    if ((Primera_Parte_Hito2_Siganl_P_DW.TimeStampA >= deltaT) &&
        (Primera_Parte_Hito2_Siganl_P_DW.TimeStampB >= deltaT)) {
      /* Derivative: '<S3>/Derivative' */
      Primera_Parte_Hito2_Siganl_PW_B.Derivative[0] = 0.0;
      Primera_Parte_Hito2_Siganl_PW_B.Derivative[1] = 0.0;
    } else {
      lastTime_tmp = Primera_Parte_Hito2_Siganl_P_DW.TimeStampA;
      lastU = &Primera_Parte_Hito2_Siganl_P_DW.LastUAtTimeA;
      if (Primera_Parte_Hito2_Siganl_P_DW.TimeStampA <
          Primera_Parte_Hito2_Siganl_P_DW.TimeStampB) {
        if (Primera_Parte_Hito2_Siganl_P_DW.TimeStampB < deltaT) {
          lastTime_tmp = Primera_Parte_Hito2_Siganl_P_DW.TimeStampB;
          lastU = &Primera_Parte_Hito2_Siganl_P_DW.LastUAtTimeB;
        }
      } else if (Primera_Parte_Hito2_Siganl_P_DW.TimeStampA >= deltaT) {
        lastTime_tmp = Primera_Parte_Hito2_Siganl_P_DW.TimeStampB;
        lastU = &Primera_Parte_Hito2_Siganl_P_DW.LastUAtTimeB;
      }

      deltaT -= lastTime_tmp;

      /* Derivative: '<S3>/Derivative' */
      Primera_Parte_Hito2_Siganl_PW_B.Derivative[0] =
        (Primera_Parte_Hito2_Siganl_PW_B.TmpRTBAtDerivativeInport1[0] - (*lastU)
         [0]) / deltaT;
      Primera_Parte_Hito2_Siganl_PW_B.Derivative[1] =
        (Primera_Parte_Hito2_Siganl_PW_B.TmpRTBAtDerivativeInport1[1] - (*lastU)
         [1]) / deltaT;
    }

    /* End of Derivative: '<S3>/Derivative' */

    /* FromWorkspace: '<S1>/fromWS_Signal 1' */
    {
      real_T *pDataValues = (real_T *)
        Primera_Parte_Hito2_Siganl_P_DW.fromWS_Signal1_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        Primera_Parte_Hito2_Siganl_P_DW.fromWS_Signal1_PWORK.TimePtr;
      int_T currTimeIndex =
        Primera_Parte_Hito2_Siganl_P_DW.fromWS_Signal1_IWORK.PrevIndex;
      real_T t = Primera_Parte_Hito2_Siganl_P_M->Timing.t[0];
      if (t > pTimeValues[1]) {
        Primera_Parte_Hito2_Siganl_PW_B.Signal1 = 0.0;
      } else {
        /* Get index */
        if (t <= pTimeValues[0]) {
          currTimeIndex = 0;
        } else if (t >= pTimeValues[1]) {
          currTimeIndex = 0;
        } else {
          if (t < pTimeValues[currTimeIndex]) {
            while (t < pTimeValues[currTimeIndex]) {
              currTimeIndex--;
            }
          } else {
            while (t >= pTimeValues[currTimeIndex + 1]) {
              currTimeIndex++;
            }
          }
        }

        Primera_Parte_Hito2_Siganl_P_DW.fromWS_Signal1_IWORK.PrevIndex =
          currTimeIndex;

        /* Post output */
        {
          real_T t1 = pTimeValues[currTimeIndex];
          real_T t2 = pTimeValues[currTimeIndex + 1];
          if (t1 == t2) {
            if (t < t1) {
              Primera_Parte_Hito2_Siganl_PW_B.Signal1 =
                pDataValues[currTimeIndex];
            } else {
              Primera_Parte_Hito2_Siganl_PW_B.Signal1 =
                pDataValues[currTimeIndex + 1];
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex = currTimeIndex;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            Primera_Parte_Hito2_Siganl_PW_B.Signal1 = (real_T) rtInterpolate(d1,
              d2, f1, f2);
            pDataValues += 2;
          }
        }
      }
    }

    /* SignalConversion generated from: '<Root>/To Workspace' */
    Primera_Parte_Hito2_Siganl_PW_B.TmpSignalConversionAt_asyncqueu[0] =
      Primera_Parte_Hito2_Siganl_PW_B.Signal1;
    Primera_Parte_Hito2_Siganl_PW_B.TmpSignalConversionAt_asyncqueu[1] =
      Primera_Parte_Hito2_Siganl_PW_B.Signal1;
    Primera_Parte_Hito2_Siganl_PW_B.TmpSignalConversionAt_asyncqueu[2] =
      Primera_Parte_Hito2_Siganl_PW_B.Derivative[0];
    Primera_Parte_Hito2_Siganl_PW_B.TmpSignalConversionAt_asyncqueu[3] =
      Primera_Parte_Hito2_Siganl_PW_B.Derivative[1];

    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    deltaT = floor(Primera_Parte_Hito2_Siganl_PW_B.Signal1);
    if (rtIsNaN(deltaT) || rtIsInf(deltaT)) {
      lastTime_tmp = 0.0;
      deltaT = 0.0;
    } else {
      lastTime_tmp = fmod(deltaT, 65536.0);
      deltaT = lastTime_tmp;
    }

    rtb_DataTypeConversion_idx_0 = lastTime_tmp < 0.0 ? -(int16_T)(uint16_T)
      -lastTime_tmp : (int16_T)(uint16_T)lastTime_tmp;
    rtb_DataTypeConversion_idx_1 = deltaT < 0.0 ? -(int16_T)(uint16_T)-deltaT :
      (int16_T)(uint16_T)deltaT;

    /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
    /* MATLABSystem: '<S4>/Adelante_der' */
    Primera_Parte_Hito2_Siganl_P_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(12UL);

    /* Saturate: '<S4>/Saturation2' */
    if (rtb_DataTypeConversion_idx_1 >
        Primera_Parte_Hito2_Siganl_PW_P.Saturation2_UpperSat) {
      y = Primera_Parte_Hito2_Siganl_PW_P.Saturation2_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               Primera_Parte_Hito2_Siganl_PW_P.Saturation2_LowerSat) {
      y = Primera_Parte_Hito2_Siganl_PW_P.Saturation2_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
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
    MW_PWM_SetDutyCycle
      (Primera_Parte_Hito2_Siganl_P_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, (real_T)
       y);

    /* MATLABSystem: '<S4>/Adelante_izq' */
    Primera_Parte_Hito2_Siganl_P_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(9UL);

    /* Saturate: '<S4>/Saturation4' */
    if (rtb_DataTypeConversion_idx_0 >
        Primera_Parte_Hito2_Siganl_PW_P.Saturation4_UpperSat) {
      y = Primera_Parte_Hito2_Siganl_PW_P.Saturation4_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               Primera_Parte_Hito2_Siganl_PW_P.Saturation4_LowerSat) {
      y = Primera_Parte_Hito2_Siganl_PW_P.Saturation4_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_0;
    }

    /* End of Saturate: '<S4>/Saturation4' */

    /* Abs: '<S4>/Abs2' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S4>/Abs2' */

    /* Start for MATLABSystem: '<S4>/Adelante_izq' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S4>/Adelante_izq' */
    MW_PWM_SetDutyCycle
      (Primera_Parte_Hito2_Siganl_P_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, (real_T)
       y);

    /* MATLABSystem: '<S4>/Atras_der' */
    Primera_Parte_Hito2_Siganl_P_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(11UL);

    /* Saturate: '<S4>/Saturation3' */
    if (rtb_DataTypeConversion_idx_1 >
        Primera_Parte_Hito2_Siganl_PW_P.Saturation3_UpperSat) {
      y = Primera_Parte_Hito2_Siganl_PW_P.Saturation3_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               Primera_Parte_Hito2_Siganl_PW_P.Saturation3_LowerSat) {
      y = Primera_Parte_Hito2_Siganl_PW_P.Saturation3_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
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
    MW_PWM_SetDutyCycle
      (Primera_Parte_Hito2_Siganl_P_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, (real_T)
       y);

    /* MATLABSystem: '<S4>/Atras_izq' */
    Primera_Parte_Hito2_Siganl_P_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(10UL);

    /* Saturate: '<S4>/Saturation5' */
    if (rtb_DataTypeConversion_idx_0 >
        Primera_Parte_Hito2_Siganl_PW_P.Saturation5_UpperSat) {
      y = Primera_Parte_Hito2_Siganl_PW_P.Saturation5_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               Primera_Parte_Hito2_Siganl_PW_P.Saturation5_LowerSat) {
      y = Primera_Parte_Hito2_Siganl_PW_P.Saturation5_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_0;
    }

    /* End of Saturate: '<S4>/Saturation5' */

    /* Start for MATLABSystem: '<S4>/Atras_izq' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S4>/Atras_izq' */
    MW_PWM_SetDutyCycle
      (Primera_Parte_Hito2_Siganl_P_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, (real_T)
       y);

    /* MATLABSystem: '<S4>/Digital Output' incorporates:
     *  Constant: '<S5>/Constant'
     *  RelationalOperator: '<S5>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
      Primera_Parte_Hito2_Siganl_PW_P.Constant_Value));

    /* MATLABSystem: '<S4>/Digital Output1' incorporates:
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S6>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
      Primera_Parte_Hito2_Siganl_PW_P.Constant_Value_h));
  }

  {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S3>/Derivative' */
    if (Primera_Parte_Hito2_Siganl_P_DW.TimeStampA == (rtInf)) {
      Primera_Parte_Hito2_Siganl_P_DW.TimeStampA =
        Primera_Parte_Hito2_Siganl_P_M->Timing.t[0];
      lastU = &Primera_Parte_Hito2_Siganl_P_DW.LastUAtTimeA;
    } else if (Primera_Parte_Hito2_Siganl_P_DW.TimeStampB == (rtInf)) {
      Primera_Parte_Hito2_Siganl_P_DW.TimeStampB =
        Primera_Parte_Hito2_Siganl_P_M->Timing.t[0];
      lastU = &Primera_Parte_Hito2_Siganl_P_DW.LastUAtTimeB;
    } else if (Primera_Parte_Hito2_Siganl_P_DW.TimeStampA <
               Primera_Parte_Hito2_Siganl_P_DW.TimeStampB) {
      Primera_Parte_Hito2_Siganl_P_DW.TimeStampA =
        Primera_Parte_Hito2_Siganl_P_M->Timing.t[0];
      lastU = &Primera_Parte_Hito2_Siganl_P_DW.LastUAtTimeA;
    } else {
      Primera_Parte_Hito2_Siganl_P_DW.TimeStampB =
        Primera_Parte_Hito2_Siganl_P_M->Timing.t[0];
      lastU = &Primera_Parte_Hito2_Siganl_P_DW.LastUAtTimeB;
    }

    (*lastU)[0] = Primera_Parte_Hito2_Siganl_PW_B.TmpRTBAtDerivativeInport1[0];
    (*lastU)[1] = Primera_Parte_Hito2_Siganl_PW_B.TmpRTBAtDerivativeInport1[1];

    /* End of Update for Derivative: '<S3>/Derivative' */
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Primera_Parte_Hito2_Siganl_P_M->Timing.t[0] =
    ((time_T)(++Primera_Parte_Hito2_Siganl_P_M->Timing.clockTick0)) *
    Primera_Parte_Hito2_Siganl_P_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Primera_Parte_Hito2_Siganl_P_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void Primera_Parte_Hito2_Siganl_PWM_step2(void) /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_Gain[2];
  real_T rtb_Gain_tmp;
  int32_T rtb_Encoder1_0;
  int32_T rtb_Encoder_0;

  /* MATLABSystem: '<S3>/Encoder' */
  if (Primera_Parte_Hito2_Siganl_P_DW.obj_p.SampleTime !=
      Primera_Parte_Hito2_Siganl_PW_P.Encoder_SampleTime) {
    Primera_Parte_Hito2_Siganl_P_DW.obj_p.SampleTime =
      Primera_Parte_Hito2_Siganl_PW_P.Encoder_SampleTime;
  }

  if (Primera_Parte_Hito2_Siganl_P_DW.obj_p.TunablePropsChanged) {
    Primera_Parte_Hito2_Siganl_P_DW.obj_p.TunablePropsChanged = false;
  }

  MW_EncoderRead(Primera_Parte_Hito2_Siganl_P_DW.obj_p.Index, &rtb_Encoder_0);

  /* MATLABSystem: '<S3>/Encoder1' */
  if (Primera_Parte_Hito2_Siganl_P_DW.obj.SampleTime !=
      Primera_Parte_Hito2_Siganl_PW_P.Encoder1_SampleTime) {
    Primera_Parte_Hito2_Siganl_P_DW.obj.SampleTime =
      Primera_Parte_Hito2_Siganl_PW_P.Encoder1_SampleTime;
  }

  if (Primera_Parte_Hito2_Siganl_P_DW.obj.TunablePropsChanged) {
    Primera_Parte_Hito2_Siganl_P_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(Primera_Parte_Hito2_Siganl_P_DW.obj.Index, &rtb_Encoder1_0);

  /* Gain: '<S3>/Gain' incorporates:
   *  MATLABSystem: '<S3>/Encoder'
   *  MATLABSystem: '<S3>/Encoder1'
   */
  rtb_Gain_tmp = (real_T)Primera_Parte_Hito2_Siganl_PW_P.Gain_Gain *
    1.1368683772161603E-13;
  rtb_Gain[0] = rtb_Gain_tmp * (real_T)rtb_Encoder_0;
  rtb_Gain[1] = rtb_Gain_tmp * (real_T)rtb_Encoder1_0;

  /* RateTransition generated from: '<S3>/Derivative' */
  Primera_Parte_Hito2_Siganl_P_DW.TmpRTBAtDerivativeInport1_Buffe[0] = rtb_Gain
    [0];
  Primera_Parte_Hito2_Siganl_P_DW.TmpRTBAtDerivativeInport1_Buffe[1] = rtb_Gain
    [1];

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Primera_Parte_Hito2_Siganl_P_M->Timing.clockTick2++;
}

/* Model initialize function */
void Primera_Parte_Hito2_Siganl_PWM_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Primera_Parte_Hito2_Siganl_P_M->solverInfo,
                          &Primera_Parte_Hito2_Siganl_P_M->Timing.simTimeStep);
    rtsiSetTPtr(&Primera_Parte_Hito2_Siganl_P_M->solverInfo, &rtmGetTPtr
                (Primera_Parte_Hito2_Siganl_P_M));
    rtsiSetStepSizePtr(&Primera_Parte_Hito2_Siganl_P_M->solverInfo,
                       &Primera_Parte_Hito2_Siganl_P_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Primera_Parte_Hito2_Siganl_P_M->solverInfo,
                          (&rtmGetErrorStatus(Primera_Parte_Hito2_Siganl_P_M)));
    rtsiSetRTModelPtr(&Primera_Parte_Hito2_Siganl_P_M->solverInfo,
                      Primera_Parte_Hito2_Siganl_P_M);
  }

  rtsiSetSimTimeStep(&Primera_Parte_Hito2_Siganl_P_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&Primera_Parte_Hito2_Siganl_P_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(Primera_Parte_Hito2_Siganl_P_M,
             &Primera_Parte_Hito2_Siganl_P_M->Timing.tArray[0]);
  rtmSetTFinal(Primera_Parte_Hito2_Siganl_P_M, 10.0);
  Primera_Parte_Hito2_Siganl_P_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Primera_Parte_Hito2_Siganl_P_M->Sizes.checksums[0] = (2624880857U);
  Primera_Parte_Hito2_Siganl_P_M->Sizes.checksums[1] = (886416841U);
  Primera_Parte_Hito2_Siganl_P_M->Sizes.checksums[2] = (2276098538U);
  Primera_Parte_Hito2_Siganl_P_M->Sizes.checksums[3] = (1763426892U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    Primera_Parte_Hito2_Siganl_P_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(Primera_Parte_Hito2_Siganl_P_M->extModeInfo,
      &Primera_Parte_Hito2_Siganl_P_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Primera_Parte_Hito2_Siganl_P_M->extModeInfo,
                        Primera_Parte_Hito2_Siganl_P_M->Sizes.checksums);
    rteiSetTPtr(Primera_Parte_Hito2_Siganl_P_M->extModeInfo, rtmGetTPtr
                (Primera_Parte_Hito2_Siganl_P_M));
  }

  /* Start for RateTransition generated from: '<S3>/Derivative' */
  Primera_Parte_Hito2_Siganl_PW_B.TmpRTBAtDerivativeInport1[0] =
    Primera_Parte_Hito2_Siganl_PW_P.TmpRTBAtDerivativeInport1_Initi;
  Primera_Parte_Hito2_Siganl_PW_B.TmpRTBAtDerivativeInport1[1] =
    Primera_Parte_Hito2_Siganl_PW_P.TmpRTBAtDerivativeInport1_Initi;

  /* Start for FromWorkspace: '<S1>/fromWS_Signal 1' */
  {
    static real_T pTimeValues0[] = { 0.0, 10.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0 } ;

    Primera_Parte_Hito2_Siganl_P_DW.fromWS_Signal1_PWORK.TimePtr = (void *)
      pTimeValues0;
    Primera_Parte_Hito2_Siganl_P_DW.fromWS_Signal1_PWORK.DataPtr = (void *)
      pDataValues0;
    Primera_Parte_Hito2_Siganl_P_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for RateTransition generated from: '<S3>/Derivative' */
  Primera_Parte_Hito2_Siganl_P_DW.TmpRTBAtDerivativeInport1_Buffe[0] =
    Primera_Parte_Hito2_Siganl_PW_P.TmpRTBAtDerivativeInport1_Initi;
  Primera_Parte_Hito2_Siganl_P_DW.TmpRTBAtDerivativeInport1_Buffe[1] =
    Primera_Parte_Hito2_Siganl_PW_P.TmpRTBAtDerivativeInport1_Initi;

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  Primera_Parte_Hito2_Siganl_P_DW.TimeStampA = (rtInf);
  Primera_Parte_Hito2_Siganl_P_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<S4>/Adelante_der' */
  Primera_Parte_Hito2_Siganl_P_DW.obj_k.matlabCodegenIsDeleted = false;
  Primera_Parte_Hito2_Siganl_P_DW.obj_k.isInitialized = 1L;
  Primera_Parte_Hito2_Siganl_P_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (12UL, 0.0, 0.0);
  Primera_Parte_Hito2_Siganl_P_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Adelante_izq' */
  Primera_Parte_Hito2_Siganl_P_DW.obj_c.matlabCodegenIsDeleted = false;
  Primera_Parte_Hito2_Siganl_P_DW.obj_c.isInitialized = 1L;
  Primera_Parte_Hito2_Siganl_P_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (9UL, 0.0, 0.0);
  Primera_Parte_Hito2_Siganl_P_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_der' */
  Primera_Parte_Hito2_Siganl_P_DW.obj_l.matlabCodegenIsDeleted = false;
  Primera_Parte_Hito2_Siganl_P_DW.obj_l.isInitialized = 1L;
  Primera_Parte_Hito2_Siganl_P_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (11UL, 0.0, 0.0);
  Primera_Parte_Hito2_Siganl_P_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_izq' */
  Primera_Parte_Hito2_Siganl_P_DW.obj_m.matlabCodegenIsDeleted = false;
  Primera_Parte_Hito2_Siganl_P_DW.obj_m.isInitialized = 1L;
  Primera_Parte_Hito2_Siganl_P_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (10UL, 0.0, 0.0);
  Primera_Parte_Hito2_Siganl_P_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output' */
  Primera_Parte_Hito2_Siganl_P_DW.obj_mx.matlabCodegenIsDeleted = false;
  Primera_Parte_Hito2_Siganl_P_DW.obj_mx.isInitialized = 1L;
  digitalIOSetup(8, 1);
  Primera_Parte_Hito2_Siganl_P_DW.obj_mx.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  Primera_Parte_Hito2_Siganl_P_DW.obj_o.matlabCodegenIsDeleted = false;
  Primera_Parte_Hito2_Siganl_P_DW.obj_o.isInitialized = 1L;
  digitalIOSetup(13, 1);
  Primera_Parte_Hito2_Siganl_P_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Encoder' */
  Primera_Parte_Hito2_Siganl_P_DW.obj_p.Index = 0U;
  Primera_Parte_Hito2_Siganl_P_DW.obj_p.matlabCodegenIsDeleted = false;
  Primera_Parte_Hito2_Siganl_P_DW.obj_p.SampleTime =
    Primera_Parte_Hito2_Siganl_PW_P.Encoder_SampleTime;
  Primera_Parte_Hito2_Siganl_P_DW.obj_p.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &Primera_Parte_Hito2_Siganl_P_DW.obj_p.Index);
  Primera_Parte_Hito2_Siganl_P_DW.obj_p.isSetupComplete = true;
  Primera_Parte_Hito2_Siganl_P_DW.obj_p.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
  MW_EncoderReset(Primera_Parte_Hito2_Siganl_P_DW.obj_p.Index);

  /* Start for MATLABSystem: '<S3>/Encoder1' */
  Primera_Parte_Hito2_Siganl_P_DW.obj.Index = 0U;
  Primera_Parte_Hito2_Siganl_P_DW.obj.matlabCodegenIsDeleted = false;
  Primera_Parte_Hito2_Siganl_P_DW.obj.SampleTime =
    Primera_Parte_Hito2_Siganl_PW_P.Encoder1_SampleTime;
  Primera_Parte_Hito2_Siganl_P_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &Primera_Parte_Hito2_Siganl_P_DW.obj.Index);
  Primera_Parte_Hito2_Siganl_P_DW.obj.isSetupComplete = true;
  Primera_Parte_Hito2_Siganl_P_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder1' */
  MW_EncoderReset(Primera_Parte_Hito2_Siganl_P_DW.obj.Index);
}

/* Model terminate function */
void Primera_Parte_Hito2_Siganl_PWM_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/Adelante_der' */
  if (!Primera_Parte_Hito2_Siganl_P_DW.obj_k.matlabCodegenIsDeleted) {
    Primera_Parte_Hito2_Siganl_P_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Primera_Parte_Hito2_Siganl_P_DW.obj_k.isInitialized == 1L) &&
        Primera_Parte_Hito2_Siganl_P_DW.obj_k.isSetupComplete) {
      Primera_Parte_Hito2_Siganl_P_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle
        (Primera_Parte_Hito2_Siganl_P_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Primera_Parte_Hito2_Siganl_P_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(12UL);
      MW_PWM_Close
        (Primera_Parte_Hito2_Siganl_P_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S4>/Adelante_izq' */
  if (!Primera_Parte_Hito2_Siganl_P_DW.obj_c.matlabCodegenIsDeleted) {
    Primera_Parte_Hito2_Siganl_P_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Primera_Parte_Hito2_Siganl_P_DW.obj_c.isInitialized == 1L) &&
        Primera_Parte_Hito2_Siganl_P_DW.obj_c.isSetupComplete) {
      Primera_Parte_Hito2_Siganl_P_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle
        (Primera_Parte_Hito2_Siganl_P_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Primera_Parte_Hito2_Siganl_P_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_Close
        (Primera_Parte_Hito2_Siganl_P_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S4>/Atras_der' */
  if (!Primera_Parte_Hito2_Siganl_P_DW.obj_l.matlabCodegenIsDeleted) {
    Primera_Parte_Hito2_Siganl_P_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Primera_Parte_Hito2_Siganl_P_DW.obj_l.isInitialized == 1L) &&
        Primera_Parte_Hito2_Siganl_P_DW.obj_l.isSetupComplete) {
      Primera_Parte_Hito2_Siganl_P_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle
        (Primera_Parte_Hito2_Siganl_P_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Primera_Parte_Hito2_Siganl_P_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_Close
        (Primera_Parte_Hito2_Siganl_P_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_der' */

  /* Terminate for MATLABSystem: '<S4>/Atras_izq' */
  if (!Primera_Parte_Hito2_Siganl_P_DW.obj_m.matlabCodegenIsDeleted) {
    Primera_Parte_Hito2_Siganl_P_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Primera_Parte_Hito2_Siganl_P_DW.obj_m.isInitialized == 1L) &&
        Primera_Parte_Hito2_Siganl_P_DW.obj_m.isSetupComplete) {
      Primera_Parte_Hito2_Siganl_P_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle
        (Primera_Parte_Hito2_Siganl_P_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Primera_Parte_Hito2_Siganl_P_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(10UL);
      MW_PWM_Close
        (Primera_Parte_Hito2_Siganl_P_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!Primera_Parte_Hito2_Siganl_P_DW.obj_mx.matlabCodegenIsDeleted) {
    Primera_Parte_Hito2_Siganl_P_DW.obj_mx.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!Primera_Parte_Hito2_Siganl_P_DW.obj_o.matlabCodegenIsDeleted) {
    Primera_Parte_Hito2_Siganl_P_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */
  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!Primera_Parte_Hito2_Siganl_P_DW.obj_p.matlabCodegenIsDeleted) {
    Primera_Parte_Hito2_Siganl_P_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Primera_Parte_Hito2_Siganl_P_DW.obj_p.isInitialized == 1L) &&
        Primera_Parte_Hito2_Siganl_P_DW.obj_p.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */

  /* Terminate for MATLABSystem: '<S3>/Encoder1' */
  if (!Primera_Parte_Hito2_Siganl_P_DW.obj.matlabCodegenIsDeleted) {
    Primera_Parte_Hito2_Siganl_P_DW.obj.matlabCodegenIsDeleted = true;
    if ((Primera_Parte_Hito2_Siganl_P_DW.obj.isInitialized == 1L) &&
        Primera_Parte_Hito2_Siganl_P_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
