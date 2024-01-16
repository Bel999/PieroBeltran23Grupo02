/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Toma_De_Datos_grafica.c
 *
 * Code generated for Simulink model 'Toma_De_Datos_grafica'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 30 12:35:22 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Toma_De_Datos_grafica.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "Toma_De_Datos_grafica_private.h"

/* Block signals (default storage) */
B_Toma_De_Datos_grafica_T Toma_De_Datos_grafica_B;

/* Block states (default storage) */
DW_Toma_De_Datos_grafica_T Toma_De_Datos_grafica_DW;

/* Real-time model */
static RT_MODEL_Toma_De_Datos_grafic_T Toma_De_Datos_grafica_M_;
RT_MODEL_Toma_De_Datos_grafic_T *const Toma_De_Datos_grafica_M =
  &Toma_De_Datos_grafica_M_;

/* Model step function */
void Toma_De_Datos_grafica_step(void)
{
  {
    real_T (*lastU)[2];
    real_T Gain_tmp;
    real_T lastTime_tmp;
    int32_T rtb_Gain;
    int32_T rtb_Saturation4;
    int16_T rtb_DataTypeConversion_idx_1;
    int16_T y;

    /* MATLABSystem: '<S3>/Encoder' */
    if (Toma_De_Datos_grafica_DW.obj_n.SampleTime !=
        Toma_De_Datos_grafica_P.Encoder_SampleTime) {
      Toma_De_Datos_grafica_DW.obj_n.SampleTime =
        Toma_De_Datos_grafica_P.Encoder_SampleTime;
    }

    if (Toma_De_Datos_grafica_DW.obj_n.TunablePropsChanged) {
      Toma_De_Datos_grafica_DW.obj_n.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S3>/Encoder' */
    MW_EncoderRead(Toma_De_Datos_grafica_DW.obj_n.Index,
                   &Toma_De_Datos_grafica_B.Encoder);

    /* MATLABSystem: '<S3>/Encoder1' */
    if (Toma_De_Datos_grafica_DW.obj.SampleTime !=
        Toma_De_Datos_grafica_P.Encoder1_SampleTime) {
      Toma_De_Datos_grafica_DW.obj.SampleTime =
        Toma_De_Datos_grafica_P.Encoder1_SampleTime;
    }

    if (Toma_De_Datos_grafica_DW.obj.TunablePropsChanged) {
      Toma_De_Datos_grafica_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S3>/Encoder1' */
    MW_EncoderRead(Toma_De_Datos_grafica_DW.obj.Index,
                   &Toma_De_Datos_grafica_B.Encoder1);

    /* Gain: '<S3>/Gain' */
    Gain_tmp = (real_T)Toma_De_Datos_grafica_P.Gain_Gain *
      1.1368683772161603E-13;

    /* Gain: '<S3>/Gain' incorporates:
     *  SignalConversion generated from: '<S3>/Gain'
     */
    Toma_De_Datos_grafica_B.Gain[0] = Gain_tmp * (real_T)
      Toma_De_Datos_grafica_B.Encoder;
    Toma_De_Datos_grafica_B.Gain[1] = Gain_tmp * (real_T)
      Toma_De_Datos_grafica_B.Encoder1;

    /* Derivative: '<S3>/Derivative' */
    Gain_tmp = Toma_De_Datos_grafica_M->Timing.t[0];
    if ((Toma_De_Datos_grafica_DW.TimeStampA >= Gain_tmp) &&
        (Toma_De_Datos_grafica_DW.TimeStampB >= Gain_tmp)) {
      /* Derivative: '<S3>/Derivative' */
      Toma_De_Datos_grafica_B.Derivative[0] = 0.0;
      Toma_De_Datos_grafica_B.Derivative[1] = 0.0;
    } else {
      lastTime_tmp = Toma_De_Datos_grafica_DW.TimeStampA;
      lastU = &Toma_De_Datos_grafica_DW.LastUAtTimeA;
      if (Toma_De_Datos_grafica_DW.TimeStampA <
          Toma_De_Datos_grafica_DW.TimeStampB) {
        if (Toma_De_Datos_grafica_DW.TimeStampB < Gain_tmp) {
          lastTime_tmp = Toma_De_Datos_grafica_DW.TimeStampB;
          lastU = &Toma_De_Datos_grafica_DW.LastUAtTimeB;
        }
      } else if (Toma_De_Datos_grafica_DW.TimeStampA >= Gain_tmp) {
        lastTime_tmp = Toma_De_Datos_grafica_DW.TimeStampB;
        lastU = &Toma_De_Datos_grafica_DW.LastUAtTimeB;
      }

      Gain_tmp -= lastTime_tmp;

      /* Derivative: '<S3>/Derivative' */
      Toma_De_Datos_grafica_B.Derivative[0] = (Toma_De_Datos_grafica_B.Gain[0] -
        (*lastU)[0]) / Gain_tmp;
      Toma_De_Datos_grafica_B.Derivative[1] = (Toma_De_Datos_grafica_B.Gain[1] -
        (*lastU)[1]) / Gain_tmp;
    }

    /* End of Derivative: '<S3>/Derivative' */

    /* FromWorkspace: '<S1>/From Workspace' */
    {
      real_T *pDataValues = (real_T *)
        Toma_De_Datos_grafica_DW.FromWorkspace_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        Toma_De_Datos_grafica_DW.FromWorkspace_PWORK.TimePtr;
      int_T currTimeIndex =
        Toma_De_Datos_grafica_DW.FromWorkspace_IWORK.PrevIndex;
      real_T t = Toma_De_Datos_grafica_M->Timing.t[0];
      if (t > pTimeValues[13]) {
        Toma_De_Datos_grafica_B.Signal2 = 0.0;
      } else {
        /* Get index */
        if (t <= pTimeValues[0]) {
          currTimeIndex = 0;
        } else if (t >= pTimeValues[13]) {
          currTimeIndex = 12;
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

        Toma_De_Datos_grafica_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

        /* Post output */
        {
          real_T t1 = pTimeValues[currTimeIndex];
          real_T t2 = pTimeValues[currTimeIndex + 1];
          if (t1 == t2) {
            if (t < t1) {
              Toma_De_Datos_grafica_B.Signal2 = pDataValues[currTimeIndex];
            } else {
              Toma_De_Datos_grafica_B.Signal2 = pDataValues[currTimeIndex + 1];
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex = currTimeIndex;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            Toma_De_Datos_grafica_B.Signal2 = (real_T) rtInterpolate(d1, d2, f1,
              f2);
            pDataValues += 14;
          }
        }
      }
    }

    /* SignalConversion generated from: '<Root>/To Workspace' */
    Toma_De_Datos_grafica_B.TmpSignalConversionAt_asyncqueu[0] =
      Toma_De_Datos_grafica_B.Signal2;
    Toma_De_Datos_grafica_B.TmpSignalConversionAt_asyncqueu[1] =
      Toma_De_Datos_grafica_B.Signal2;
    Toma_De_Datos_grafica_B.TmpSignalConversionAt_asyncqueu[2] =
      Toma_De_Datos_grafica_B.Derivative[0];
    Toma_De_Datos_grafica_B.TmpSignalConversionAt_asyncqueu[3] =
      Toma_De_Datos_grafica_B.Derivative[1];

    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    Gain_tmp = floor(Toma_De_Datos_grafica_B.Signal2);
    if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
      lastTime_tmp = 0.0;
      Gain_tmp = 0.0;
    } else {
      lastTime_tmp = fmod(Gain_tmp, 65536.0);
      Gain_tmp = lastTime_tmp;
    }

    rtb_DataTypeConversion_idx_1 = Gain_tmp < 0.0 ? -(int16_T)(uint16_T)
      -Gain_tmp : (int16_T)(uint16_T)Gain_tmp;

    /* SignalConversion generated from: '<S3>/Mux' */
    Toma_De_Datos_grafica_B.TmpSignalConversionAtTAQSigLogg[0] =
      Toma_De_Datos_grafica_B.Encoder;
    Toma_De_Datos_grafica_B.TmpSignalConversionAtTAQSigLogg[1] =
      Toma_De_Datos_grafica_B.Encoder1;

    /* MATLABSystem: '<S4>/Adelante_der' */
    Toma_De_Datos_grafica_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (12UL);

    /* Saturate: '<S4>/Saturation2' */
    if (rtb_DataTypeConversion_idx_1 >
        Toma_De_Datos_grafica_P.Saturation2_UpperSat) {
      y = Toma_De_Datos_grafica_P.Saturation2_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               Toma_De_Datos_grafica_P.Saturation2_LowerSat) {
      y = Toma_De_Datos_grafica_P.Saturation2_LowerSat;
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
      (Toma_De_Datos_grafica_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

    /* Gain: '<S4>/Gain' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     */
    rtb_Gain = (int32_T)(lastTime_tmp < 0.0 ? -(int16_T)(uint16_T)-lastTime_tmp :
                         (int16_T)(uint16_T)lastTime_tmp) *
      Toma_De_Datos_grafica_P.Gain_Gain_f;

    /* MATLABSystem: '<S4>/Digital Output' incorporates:
     *  Constant: '<S5>/Constant'
     *  Gain: '<S4>/Gain'
     *  RelationalOperator: '<S5>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_Gain !=
      Toma_De_Datos_grafica_P.Constant_Value));

    /* Saturate: '<S4>/Saturation4' incorporates:
     *  Gain: '<S4>/Gain'
     */
    if (rtb_Gain > Toma_De_Datos_grafica_P.Saturation4_UpperSat) {
      rtb_Saturation4 = Toma_De_Datos_grafica_P.Saturation4_UpperSat;
    } else if (rtb_Gain < Toma_De_Datos_grafica_P.Saturation4_LowerSat) {
      rtb_Saturation4 = Toma_De_Datos_grafica_P.Saturation4_LowerSat;
    } else {
      rtb_Saturation4 = rtb_Gain;
    }

    /* End of Saturate: '<S4>/Saturation4' */

    /* MATLABSystem: '<S4>/Adelante_izq' */
    Toma_De_Datos_grafica_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE =
      MW_PWM_GetHandle(9UL);

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
    MW_PWM_SetDutyCycle
      (Toma_De_Datos_grafica_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE, Gain_tmp);

    /* MATLABSystem: '<S4>/Atras_izq' */
    Toma_De_Datos_grafica_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (10UL);

    /* Saturate: '<S4>/Saturation5' incorporates:
     *  Gain: '<S4>/Gain'
     */
    if (rtb_Gain > Toma_De_Datos_grafica_P.Saturation5_UpperSat) {
      rtb_Gain = Toma_De_Datos_grafica_P.Saturation5_UpperSat;
    } else if (rtb_Gain < Toma_De_Datos_grafica_P.Saturation5_LowerSat) {
      rtb_Gain = Toma_De_Datos_grafica_P.Saturation5_LowerSat;
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
    MW_PWM_SetDutyCycle
      (Toma_De_Datos_grafica_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE, Gain_tmp);

    /* MATLABSystem: '<S4>/Atras_der' */
    Toma_De_Datos_grafica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
      (11UL);

    /* Saturate: '<S4>/Saturation3' */
    if (rtb_DataTypeConversion_idx_1 >
        Toma_De_Datos_grafica_P.Saturation3_UpperSat) {
      y = Toma_De_Datos_grafica_P.Saturation3_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               Toma_De_Datos_grafica_P.Saturation3_LowerSat) {
      y = Toma_De_Datos_grafica_P.Saturation3_LowerSat;
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
      (Toma_De_Datos_grafica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

    /* MATLABSystem: '<S4>/Digital Output1' incorporates:
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S6>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
      Toma_De_Datos_grafica_P.Constant_Value_j));
  }

  {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S3>/Derivative' */
    if (Toma_De_Datos_grafica_DW.TimeStampA == (rtInf)) {
      Toma_De_Datos_grafica_DW.TimeStampA = Toma_De_Datos_grafica_M->Timing.t[0];
      lastU = &Toma_De_Datos_grafica_DW.LastUAtTimeA;
    } else if (Toma_De_Datos_grafica_DW.TimeStampB == (rtInf)) {
      Toma_De_Datos_grafica_DW.TimeStampB = Toma_De_Datos_grafica_M->Timing.t[0];
      lastU = &Toma_De_Datos_grafica_DW.LastUAtTimeB;
    } else if (Toma_De_Datos_grafica_DW.TimeStampA <
               Toma_De_Datos_grafica_DW.TimeStampB) {
      Toma_De_Datos_grafica_DW.TimeStampA = Toma_De_Datos_grafica_M->Timing.t[0];
      lastU = &Toma_De_Datos_grafica_DW.LastUAtTimeA;
    } else {
      Toma_De_Datos_grafica_DW.TimeStampB = Toma_De_Datos_grafica_M->Timing.t[0];
      lastU = &Toma_De_Datos_grafica_DW.LastUAtTimeB;
    }

    (*lastU)[0] = Toma_De_Datos_grafica_B.Gain[0];
    (*lastU)[1] = Toma_De_Datos_grafica_B.Gain[1];

    /* End of Update for Derivative: '<S3>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Toma_De_Datos_grafica_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Toma_De_Datos_grafica_M->Timing.clockTick1 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Toma_De_Datos_grafica_M->Timing.t[0] =
    ((time_T)(++Toma_De_Datos_grafica_M->Timing.clockTick0)) *
    Toma_De_Datos_grafica_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Toma_De_Datos_grafica_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Toma_De_Datos_grafica_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Toma_De_Datos_grafica_M->solverInfo,
                          &Toma_De_Datos_grafica_M->Timing.simTimeStep);
    rtsiSetTPtr(&Toma_De_Datos_grafica_M->solverInfo, &rtmGetTPtr
                (Toma_De_Datos_grafica_M));
    rtsiSetStepSizePtr(&Toma_De_Datos_grafica_M->solverInfo,
                       &Toma_De_Datos_grafica_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Toma_De_Datos_grafica_M->solverInfo,
                          (&rtmGetErrorStatus(Toma_De_Datos_grafica_M)));
    rtsiSetRTModelPtr(&Toma_De_Datos_grafica_M->solverInfo,
                      Toma_De_Datos_grafica_M);
  }

  rtsiSetSimTimeStep(&Toma_De_Datos_grafica_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Toma_De_Datos_grafica_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Toma_De_Datos_grafica_M, &Toma_De_Datos_grafica_M->Timing.tArray[0]);
  rtmSetTFinal(Toma_De_Datos_grafica_M, 10.0);
  Toma_De_Datos_grafica_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Toma_De_Datos_grafica_M->Sizes.checksums[0] = (3660311288U);
  Toma_De_Datos_grafica_M->Sizes.checksums[1] = (1621013883U);
  Toma_De_Datos_grafica_M->Sizes.checksums[2] = (1431185010U);
  Toma_De_Datos_grafica_M->Sizes.checksums[3] = (584955893U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    Toma_De_Datos_grafica_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(Toma_De_Datos_grafica_M->extModeInfo,
      &Toma_De_Datos_grafica_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Toma_De_Datos_grafica_M->extModeInfo,
                        Toma_De_Datos_grafica_M->Sizes.checksums);
    rteiSetTPtr(Toma_De_Datos_grafica_M->extModeInfo, rtmGetTPtr
                (Toma_De_Datos_grafica_M));
  }

  /* Start for FromWorkspace: '<S1>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 2.0, 2.0, 3.0, 3.0, 5.0, 5.0,
      7.0, 7.0, 9.0, 9.0, 10.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 113.47499847412109,
      113.47499847412109, -113.47499847412109, -113.47499847412109,
      113.47499847412109, 113.47499847412109, -113.47499847412109,
      -113.47499847412109, 113.47499847412109, 113.47499847412109, 0.0, 0.0 } ;

    Toma_De_Datos_grafica_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    Toma_De_Datos_grafica_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    Toma_De_Datos_grafica_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  Toma_De_Datos_grafica_DW.TimeStampA = (rtInf);
  Toma_De_Datos_grafica_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<S3>/Encoder' */
  Toma_De_Datos_grafica_DW.obj_n.Index = 0U;
  Toma_De_Datos_grafica_DW.obj_n.matlabCodegenIsDeleted = false;
  Toma_De_Datos_grafica_DW.obj_n.SampleTime =
    Toma_De_Datos_grafica_P.Encoder_SampleTime;
  Toma_De_Datos_grafica_DW.obj_n.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &Toma_De_Datos_grafica_DW.obj_n.Index);
  Toma_De_Datos_grafica_DW.obj_n.isSetupComplete = true;
  Toma_De_Datos_grafica_DW.obj_n.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
  MW_EncoderReset(Toma_De_Datos_grafica_DW.obj_n.Index);

  /* Start for MATLABSystem: '<S3>/Encoder1' */
  Toma_De_Datos_grafica_DW.obj.Index = 0U;
  Toma_De_Datos_grafica_DW.obj.matlabCodegenIsDeleted = false;
  Toma_De_Datos_grafica_DW.obj.SampleTime =
    Toma_De_Datos_grafica_P.Encoder1_SampleTime;
  Toma_De_Datos_grafica_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &Toma_De_Datos_grafica_DW.obj.Index);
  Toma_De_Datos_grafica_DW.obj.isSetupComplete = true;
  Toma_De_Datos_grafica_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder1' */
  MW_EncoderReset(Toma_De_Datos_grafica_DW.obj.Index);

  /* Start for MATLABSystem: '<S4>/Adelante_der' */
  Toma_De_Datos_grafica_DW.obj_d.matlabCodegenIsDeleted = false;
  Toma_De_Datos_grafica_DW.obj_d.isInitialized = 1L;
  Toma_De_Datos_grafica_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL,
    0.0, 0.0);
  Toma_De_Datos_grafica_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output' */
  Toma_De_Datos_grafica_DW.obj_g1.matlabCodegenIsDeleted = false;
  Toma_De_Datos_grafica_DW.obj_g1.isInitialized = 1L;
  digitalIOSetup(8, 1);
  Toma_De_Datos_grafica_DW.obj_g1.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Adelante_izq' */
  Toma_De_Datos_grafica_DW.obj_pv.matlabCodegenIsDeleted = false;
  Toma_De_Datos_grafica_DW.obj_pv.isInitialized = 1L;
  Toma_De_Datos_grafica_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL,
    0.0, 0.0);
  Toma_De_Datos_grafica_DW.obj_pv.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_izq' */
  Toma_De_Datos_grafica_DW.obj_p.matlabCodegenIsDeleted = false;
  Toma_De_Datos_grafica_DW.obj_p.isInitialized = 1L;
  Toma_De_Datos_grafica_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL,
    0.0, 0.0);
  Toma_De_Datos_grafica_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_der' */
  Toma_De_Datos_grafica_DW.obj_g.matlabCodegenIsDeleted = false;
  Toma_De_Datos_grafica_DW.obj_g.isInitialized = 1L;
  Toma_De_Datos_grafica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL,
    0.0, 0.0);
  Toma_De_Datos_grafica_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  Toma_De_Datos_grafica_DW.obj_j.matlabCodegenIsDeleted = false;
  Toma_De_Datos_grafica_DW.obj_j.isInitialized = 1L;
  digitalIOSetup(13, 1);
  Toma_De_Datos_grafica_DW.obj_j.isSetupComplete = true;
}

/* Model terminate function */
void Toma_De_Datos_grafica_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!Toma_De_Datos_grafica_DW.obj_n.matlabCodegenIsDeleted) {
    Toma_De_Datos_grafica_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Toma_De_Datos_grafica_DW.obj_n.isInitialized == 1L) &&
        Toma_De_Datos_grafica_DW.obj_n.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */

  /* Terminate for MATLABSystem: '<S3>/Encoder1' */
  if (!Toma_De_Datos_grafica_DW.obj.matlabCodegenIsDeleted) {
    Toma_De_Datos_grafica_DW.obj.matlabCodegenIsDeleted = true;
    if ((Toma_De_Datos_grafica_DW.obj.isInitialized == 1L) &&
        Toma_De_Datos_grafica_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder1' */
  /* Terminate for MATLABSystem: '<S4>/Adelante_der' */
  if (!Toma_De_Datos_grafica_DW.obj_d.matlabCodegenIsDeleted) {
    Toma_De_Datos_grafica_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Toma_De_Datos_grafica_DW.obj_d.isInitialized == 1L) &&
        Toma_De_Datos_grafica_DW.obj_d.isSetupComplete) {
      Toma_De_Datos_grafica_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle
        (Toma_De_Datos_grafica_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Toma_De_Datos_grafica_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(12UL);
      MW_PWM_Close(Toma_De_Datos_grafica_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!Toma_De_Datos_grafica_DW.obj_g1.matlabCodegenIsDeleted) {
    Toma_De_Datos_grafica_DW.obj_g1.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */

  /* Terminate for MATLABSystem: '<S4>/Adelante_izq' */
  if (!Toma_De_Datos_grafica_DW.obj_pv.matlabCodegenIsDeleted) {
    Toma_De_Datos_grafica_DW.obj_pv.matlabCodegenIsDeleted = true;
    if ((Toma_De_Datos_grafica_DW.obj_pv.isInitialized == 1L) &&
        Toma_De_Datos_grafica_DW.obj_pv.isSetupComplete) {
      Toma_De_Datos_grafica_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle
        (Toma_De_Datos_grafica_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Toma_De_Datos_grafica_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_Close(Toma_De_Datos_grafica_DW.obj_pv.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S4>/Atras_izq' */
  if (!Toma_De_Datos_grafica_DW.obj_p.matlabCodegenIsDeleted) {
    Toma_De_Datos_grafica_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Toma_De_Datos_grafica_DW.obj_p.isInitialized == 1L) &&
        Toma_De_Datos_grafica_DW.obj_p.isSetupComplete) {
      Toma_De_Datos_grafica_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle
        (Toma_De_Datos_grafica_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Toma_De_Datos_grafica_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(10UL);
      MW_PWM_Close(Toma_De_Datos_grafica_DW.obj_p.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S4>/Atras_der' */
  if (!Toma_De_Datos_grafica_DW.obj_g.matlabCodegenIsDeleted) {
    Toma_De_Datos_grafica_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Toma_De_Datos_grafica_DW.obj_g.isInitialized == 1L) &&
        Toma_De_Datos_grafica_DW.obj_g.isSetupComplete) {
      Toma_De_Datos_grafica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle
        (Toma_De_Datos_grafica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Toma_De_Datos_grafica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_Close(Toma_De_Datos_grafica_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_der' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!Toma_De_Datos_grafica_DW.obj_j.matlabCodegenIsDeleted) {
    Toma_De_Datos_grafica_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */