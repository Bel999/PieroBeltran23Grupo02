/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: toma_de_datos_2.c
 *
 * Code generated for Simulink model 'toma_de_datos_2'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Dec 14 14:08:05 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "toma_de_datos_2.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "toma_de_datos_2_private.h"

/* Block signals (default storage) */
B_toma_de_datos_2_T toma_de_datos_2_B;

/* Block states (default storage) */
DW_toma_de_datos_2_T toma_de_datos_2_DW;

/* Real-time model */
static RT_MODEL_toma_de_datos_2_T toma_de_datos_2_M_;
RT_MODEL_toma_de_datos_2_T *const toma_de_datos_2_M = &toma_de_datos_2_M_;

/* Model step function */
void toma_de_datos_2_step(void)
{
  {
    real_T (*lastU)[2];
    real_T Gain_tmp;
    real_T lastTime_tmp;
    int16_T rtb_DataTypeConversion_idx_0;
    int16_T rtb_DataTypeConversion_idx_1;
    int16_T y;

    /* MATLABSystem: '<S3>/Encoder' */
    if (toma_de_datos_2_DW.obj_p.SampleTime !=
        toma_de_datos_2_P.Encoder_SampleTime) {
      toma_de_datos_2_DW.obj_p.SampleTime = toma_de_datos_2_P.Encoder_SampleTime;
    }

    if (toma_de_datos_2_DW.obj_p.TunablePropsChanged) {
      toma_de_datos_2_DW.obj_p.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S3>/Encoder' */
    MW_EncoderRead(toma_de_datos_2_DW.obj_p.Index, &toma_de_datos_2_B.Encoder);

    /* MATLABSystem: '<S3>/Encoder1' */
    if (toma_de_datos_2_DW.obj.SampleTime !=
        toma_de_datos_2_P.Encoder1_SampleTime) {
      toma_de_datos_2_DW.obj.SampleTime = toma_de_datos_2_P.Encoder1_SampleTime;
    }

    if (toma_de_datos_2_DW.obj.TunablePropsChanged) {
      toma_de_datos_2_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S3>/Encoder1' */
    MW_EncoderRead(toma_de_datos_2_DW.obj.Index, &toma_de_datos_2_B.Encoder1);

    /* Gain: '<S3>/Gain' */
    Gain_tmp = (real_T)toma_de_datos_2_P.Gain_Gain * 1.1368683772161603E-13;

    /* Gain: '<S3>/Gain' incorporates:
     *  SignalConversion generated from: '<S3>/Gain'
     */
    toma_de_datos_2_B.Gain[0] = Gain_tmp * (real_T)toma_de_datos_2_B.Encoder;
    toma_de_datos_2_B.Gain[1] = Gain_tmp * (real_T)toma_de_datos_2_B.Encoder1;

    /* Derivative: '<S3>/Derivative' */
    Gain_tmp = toma_de_datos_2_M->Timing.t[0];
    if ((toma_de_datos_2_DW.TimeStampA >= Gain_tmp) &&
        (toma_de_datos_2_DW.TimeStampB >= Gain_tmp)) {
      /* Derivative: '<S3>/Derivative' */
      toma_de_datos_2_B.Derivative[0] = 0.0;
      toma_de_datos_2_B.Derivative[1] = 0.0;
    } else {
      lastTime_tmp = toma_de_datos_2_DW.TimeStampA;
      lastU = &toma_de_datos_2_DW.LastUAtTimeA;
      if (toma_de_datos_2_DW.TimeStampA < toma_de_datos_2_DW.TimeStampB) {
        if (toma_de_datos_2_DW.TimeStampB < Gain_tmp) {
          lastTime_tmp = toma_de_datos_2_DW.TimeStampB;
          lastU = &toma_de_datos_2_DW.LastUAtTimeB;
        }
      } else if (toma_de_datos_2_DW.TimeStampA >= Gain_tmp) {
        lastTime_tmp = toma_de_datos_2_DW.TimeStampB;
        lastU = &toma_de_datos_2_DW.LastUAtTimeB;
      }

      Gain_tmp -= lastTime_tmp;

      /* Derivative: '<S3>/Derivative' */
      toma_de_datos_2_B.Derivative[0] = (toma_de_datos_2_B.Gain[0] - (*lastU)[0])
        / Gain_tmp;
      toma_de_datos_2_B.Derivative[1] = (toma_de_datos_2_B.Gain[1] - (*lastU)[1])
        / Gain_tmp;
    }

    /* End of Derivative: '<S3>/Derivative' */

    /* FromWorkspace: '<S1>/From Workspace' */
    {
      real_T *pDataValues = (real_T *)
        toma_de_datos_2_DW.FromWorkspace_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        toma_de_datos_2_DW.FromWorkspace_PWORK.TimePtr;
      int_T currTimeIndex = toma_de_datos_2_DW.FromWorkspace_IWORK.PrevIndex;
      real_T t = toma_de_datos_2_M->Timing.t[0];
      if (t > pTimeValues[13]) {
        toma_de_datos_2_B.Signal2 = 0.0;
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

        toma_de_datos_2_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

        /* Post output */
        {
          real_T t1 = pTimeValues[currTimeIndex];
          real_T t2 = pTimeValues[currTimeIndex + 1];
          if (t1 == t2) {
            if (t < t1) {
              toma_de_datos_2_B.Signal2 = pDataValues[currTimeIndex];
            } else {
              toma_de_datos_2_B.Signal2 = pDataValues[currTimeIndex + 1];
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex = currTimeIndex;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            toma_de_datos_2_B.Signal2 = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 14;
          }
        }
      }
    }

    /* SignalConversion generated from: '<Root>/To Workspace' */
    toma_de_datos_2_B.TmpSignalConversionAt_asyncqueu[0] =
      toma_de_datos_2_B.Signal2;
    toma_de_datos_2_B.TmpSignalConversionAt_asyncqueu[1] =
      toma_de_datos_2_B.Signal2;
    toma_de_datos_2_B.TmpSignalConversionAt_asyncqueu[2] =
      toma_de_datos_2_B.Derivative[0];
    toma_de_datos_2_B.TmpSignalConversionAt_asyncqueu[3] =
      toma_de_datos_2_B.Derivative[1];

    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    Gain_tmp = floor(toma_de_datos_2_B.Signal2);
    if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
      lastTime_tmp = 0.0;
      Gain_tmp = 0.0;
    } else {
      lastTime_tmp = fmod(Gain_tmp, 65536.0);
      Gain_tmp = lastTime_tmp;
    }

    rtb_DataTypeConversion_idx_0 = lastTime_tmp < 0.0 ? -(int16_T)(uint16_T)
      -lastTime_tmp : (int16_T)(uint16_T)lastTime_tmp;
    rtb_DataTypeConversion_idx_1 = Gain_tmp < 0.0 ? -(int16_T)(uint16_T)
      -Gain_tmp : (int16_T)(uint16_T)Gain_tmp;

    /* End of DataTypeConversion: '<Root>/Data Type Conversion' */
    /* SignalConversion generated from: '<S3>/Mux' */
    toma_de_datos_2_B.TmpSignalConversionAtTAQSigLogg[0] =
      toma_de_datos_2_B.Encoder;
    toma_de_datos_2_B.TmpSignalConversionAtTAQSigLogg[1] =
      toma_de_datos_2_B.Encoder1;

    /* MATLABSystem: '<S4>/Adelante_der' */
    toma_de_datos_2_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

    /* Saturate: '<S4>/Saturation2' */
    if (rtb_DataTypeConversion_idx_1 > toma_de_datos_2_P.Saturation2_UpperSat) {
      y = toma_de_datos_2_P.Saturation2_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               toma_de_datos_2_P.Saturation2_LowerSat) {
      y = toma_de_datos_2_P.Saturation2_LowerSat;
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
    MW_PWM_SetDutyCycle(toma_de_datos_2_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S4>/Adelante_izq' */
    toma_de_datos_2_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* Saturate: '<S4>/Saturation4' */
    if (rtb_DataTypeConversion_idx_0 > toma_de_datos_2_P.Saturation4_UpperSat) {
      y = toma_de_datos_2_P.Saturation4_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               toma_de_datos_2_P.Saturation4_LowerSat) {
      y = toma_de_datos_2_P.Saturation4_LowerSat;
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
    MW_PWM_SetDutyCycle(toma_de_datos_2_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S4>/Atras_der' */
    toma_de_datos_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* Saturate: '<S4>/Saturation3' */
    if (rtb_DataTypeConversion_idx_1 > toma_de_datos_2_P.Saturation3_UpperSat) {
      y = toma_de_datos_2_P.Saturation3_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               toma_de_datos_2_P.Saturation3_LowerSat) {
      y = toma_de_datos_2_P.Saturation3_LowerSat;
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
    MW_PWM_SetDutyCycle(toma_de_datos_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S4>/Atras_izq' */
    toma_de_datos_2_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Saturate: '<S4>/Saturation5' */
    if (rtb_DataTypeConversion_idx_0 > toma_de_datos_2_P.Saturation5_UpperSat) {
      y = toma_de_datos_2_P.Saturation5_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               toma_de_datos_2_P.Saturation5_LowerSat) {
      y = toma_de_datos_2_P.Saturation5_LowerSat;
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
    MW_PWM_SetDutyCycle(toma_de_datos_2_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S4>/Digital Output' incorporates:
     *  Constant: '<S5>/Constant'
     *  RelationalOperator: '<S5>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
      toma_de_datos_2_P.Constant_Value));

    /* MATLABSystem: '<S4>/Digital Output1' incorporates:
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S6>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
      toma_de_datos_2_P.Constant_Value_h));

    /* MATLABSystem: '<Root>/Analog Input' */
    if (toma_de_datos_2_DW.obj_n.SampleTime !=
        toma_de_datos_2_P.AnalogInput_SampleTime) {
      toma_de_datos_2_DW.obj_n.SampleTime =
        toma_de_datos_2_P.AnalogInput_SampleTime;
    }

    toma_de_datos_2_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
      MW_AnalogIn_GetHandle(59UL);

    /* MATLABSystem: '<Root>/Analog Input' */
    MW_AnalogInSingle_ReadResult
      (toma_de_datos_2_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
       &toma_de_datos_2_B.AnalogInput, MW_ANALOGIN_UINT16);
  }

  {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S3>/Derivative' */
    if (toma_de_datos_2_DW.TimeStampA == (rtInf)) {
      toma_de_datos_2_DW.TimeStampA = toma_de_datos_2_M->Timing.t[0];
      lastU = &toma_de_datos_2_DW.LastUAtTimeA;
    } else if (toma_de_datos_2_DW.TimeStampB == (rtInf)) {
      toma_de_datos_2_DW.TimeStampB = toma_de_datos_2_M->Timing.t[0];
      lastU = &toma_de_datos_2_DW.LastUAtTimeB;
    } else if (toma_de_datos_2_DW.TimeStampA < toma_de_datos_2_DW.TimeStampB) {
      toma_de_datos_2_DW.TimeStampA = toma_de_datos_2_M->Timing.t[0];
      lastU = &toma_de_datos_2_DW.LastUAtTimeA;
    } else {
      toma_de_datos_2_DW.TimeStampB = toma_de_datos_2_M->Timing.t[0];
      lastU = &toma_de_datos_2_DW.LastUAtTimeB;
    }

    (*lastU)[0] = toma_de_datos_2_B.Gain[0];
    (*lastU)[1] = toma_de_datos_2_B.Gain[1];

    /* End of Update for Derivative: '<S3>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((toma_de_datos_2_M->Timing.clockTick0 * 1) + 0)
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
      ((toma_de_datos_2_M->Timing.clockTick1 * 1) + 0)
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
  toma_de_datos_2_M->Timing.t[0] =
    ((time_T)(++toma_de_datos_2_M->Timing.clockTick0)) *
    toma_de_datos_2_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    toma_de_datos_2_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void toma_de_datos_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&toma_de_datos_2_M->solverInfo,
                          &toma_de_datos_2_M->Timing.simTimeStep);
    rtsiSetTPtr(&toma_de_datos_2_M->solverInfo, &rtmGetTPtr(toma_de_datos_2_M));
    rtsiSetStepSizePtr(&toma_de_datos_2_M->solverInfo,
                       &toma_de_datos_2_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&toma_de_datos_2_M->solverInfo, (&rtmGetErrorStatus
      (toma_de_datos_2_M)));
    rtsiSetRTModelPtr(&toma_de_datos_2_M->solverInfo, toma_de_datos_2_M);
  }

  rtsiSetSimTimeStep(&toma_de_datos_2_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&toma_de_datos_2_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(toma_de_datos_2_M, &toma_de_datos_2_M->Timing.tArray[0]);
  rtmSetTFinal(toma_de_datos_2_M, 10.0);
  toma_de_datos_2_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  toma_de_datos_2_M->Sizes.checksums[0] = (4043478205U);
  toma_de_datos_2_M->Sizes.checksums[1] = (4223639409U);
  toma_de_datos_2_M->Sizes.checksums[2] = (4223279173U);
  toma_de_datos_2_M->Sizes.checksums[3] = (2352776002U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    toma_de_datos_2_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(toma_de_datos_2_M->extModeInfo,
      &toma_de_datos_2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(toma_de_datos_2_M->extModeInfo,
                        toma_de_datos_2_M->Sizes.checksums);
    rteiSetTPtr(toma_de_datos_2_M->extModeInfo, rtmGetTPtr(toma_de_datos_2_M));
  }

  /* Start for FromWorkspace: '<S1>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 2.0, 2.0, 3.0, 3.0, 5.0, 5.0,
      7.0, 7.0, 9.0, 9.0, 10.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 100.72499847412109,
      100.72499847412109, -100.72499847412109, -100.72499847412109,
      100.72499847412109, 100.72499847412109, -100.72499847412109,
      -100.72499847412109, 100.72499847412109, 100.72499847412109, 0.0, 0.0 } ;

    toma_de_datos_2_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    toma_de_datos_2_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    toma_de_datos_2_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  toma_de_datos_2_DW.TimeStampA = (rtInf);
  toma_de_datos_2_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<S3>/Encoder' */
  toma_de_datos_2_DW.obj_p.Index = 0U;
  toma_de_datos_2_DW.obj_p.matlabCodegenIsDeleted = false;
  toma_de_datos_2_DW.obj_p.SampleTime = toma_de_datos_2_P.Encoder_SampleTime;
  toma_de_datos_2_DW.obj_p.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &toma_de_datos_2_DW.obj_p.Index);
  toma_de_datos_2_DW.obj_p.isSetupComplete = true;
  toma_de_datos_2_DW.obj_p.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
  MW_EncoderReset(toma_de_datos_2_DW.obj_p.Index);

  /* Start for MATLABSystem: '<S3>/Encoder1' */
  toma_de_datos_2_DW.obj.Index = 0U;
  toma_de_datos_2_DW.obj.matlabCodegenIsDeleted = false;
  toma_de_datos_2_DW.obj.SampleTime = toma_de_datos_2_P.Encoder1_SampleTime;
  toma_de_datos_2_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &toma_de_datos_2_DW.obj.Index);
  toma_de_datos_2_DW.obj.isSetupComplete = true;
  toma_de_datos_2_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder1' */
  MW_EncoderReset(toma_de_datos_2_DW.obj.Index);

  /* Start for MATLABSystem: '<S4>/Adelante_der' */
  toma_de_datos_2_DW.obj_k.matlabCodegenIsDeleted = false;
  toma_de_datos_2_DW.obj_k.isInitialized = 1L;
  toma_de_datos_2_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0,
    0.0);
  toma_de_datos_2_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Adelante_izq' */
  toma_de_datos_2_DW.obj_c.matlabCodegenIsDeleted = false;
  toma_de_datos_2_DW.obj_c.isInitialized = 1L;
  toma_de_datos_2_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0,
    0.0);
  toma_de_datos_2_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_der' */
  toma_de_datos_2_DW.obj_l.matlabCodegenIsDeleted = false;
  toma_de_datos_2_DW.obj_l.isInitialized = 1L;
  toma_de_datos_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  toma_de_datos_2_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_izq' */
  toma_de_datos_2_DW.obj_m.matlabCodegenIsDeleted = false;
  toma_de_datos_2_DW.obj_m.isInitialized = 1L;
  toma_de_datos_2_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0,
    0.0);
  toma_de_datos_2_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output' */
  toma_de_datos_2_DW.obj_mx.matlabCodegenIsDeleted = false;
  toma_de_datos_2_DW.obj_mx.isInitialized = 1L;
  digitalIOSetup(8, 1);
  toma_de_datos_2_DW.obj_mx.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  toma_de_datos_2_DW.obj_o.matlabCodegenIsDeleted = false;
  toma_de_datos_2_DW.obj_o.isInitialized = 1L;
  digitalIOSetup(13, 1);
  toma_de_datos_2_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  toma_de_datos_2_DW.obj_n.matlabCodegenIsDeleted = false;
  toma_de_datos_2_DW.obj_n.SampleTime = toma_de_datos_2_P.AnalogInput_SampleTime;
  toma_de_datos_2_DW.obj_n.isInitialized = 1L;
  toma_de_datos_2_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(59UL);
  toma_de_datos_2_DW.obj_n.isSetupComplete = true;
}

/* Model terminate function */
void toma_de_datos_2_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!toma_de_datos_2_DW.obj_p.matlabCodegenIsDeleted) {
    toma_de_datos_2_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((toma_de_datos_2_DW.obj_p.isInitialized == 1L) &&
        toma_de_datos_2_DW.obj_p.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */

  /* Terminate for MATLABSystem: '<S3>/Encoder1' */
  if (!toma_de_datos_2_DW.obj.matlabCodegenIsDeleted) {
    toma_de_datos_2_DW.obj.matlabCodegenIsDeleted = true;
    if ((toma_de_datos_2_DW.obj.isInitialized == 1L) &&
        toma_de_datos_2_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder1' */
  /* Terminate for MATLABSystem: '<S4>/Adelante_der' */
  if (!toma_de_datos_2_DW.obj_k.matlabCodegenIsDeleted) {
    toma_de_datos_2_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((toma_de_datos_2_DW.obj_k.isInitialized == 1L) &&
        toma_de_datos_2_DW.obj_k.isSetupComplete) {
      toma_de_datos_2_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_SetDutyCycle(toma_de_datos_2_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      toma_de_datos_2_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_Close(toma_de_datos_2_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S4>/Adelante_izq' */
  if (!toma_de_datos_2_DW.obj_c.matlabCodegenIsDeleted) {
    toma_de_datos_2_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((toma_de_datos_2_DW.obj_c.isInitialized == 1L) &&
        toma_de_datos_2_DW.obj_c.isSetupComplete) {
      toma_de_datos_2_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(toma_de_datos_2_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      toma_de_datos_2_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(toma_de_datos_2_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S4>/Atras_der' */
  if (!toma_de_datos_2_DW.obj_l.matlabCodegenIsDeleted) {
    toma_de_datos_2_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((toma_de_datos_2_DW.obj_l.isInitialized == 1L) &&
        toma_de_datos_2_DW.obj_l.isSetupComplete) {
      toma_de_datos_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_SetDutyCycle(toma_de_datos_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      toma_de_datos_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_Close(toma_de_datos_2_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_der' */

  /* Terminate for MATLABSystem: '<S4>/Atras_izq' */
  if (!toma_de_datos_2_DW.obj_m.matlabCodegenIsDeleted) {
    toma_de_datos_2_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((toma_de_datos_2_DW.obj_m.isInitialized == 1L) &&
        toma_de_datos_2_DW.obj_m.isSetupComplete) {
      toma_de_datos_2_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_SetDutyCycle(toma_de_datos_2_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      toma_de_datos_2_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_Close(toma_de_datos_2_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!toma_de_datos_2_DW.obj_mx.matlabCodegenIsDeleted) {
    toma_de_datos_2_DW.obj_mx.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!toma_de_datos_2_DW.obj_o.matlabCodegenIsDeleted) {
    toma_de_datos_2_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!toma_de_datos_2_DW.obj_n.matlabCodegenIsDeleted) {
    toma_de_datos_2_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((toma_de_datos_2_DW.obj_n.isInitialized == 1L) &&
        toma_de_datos_2_DW.obj_n.isSetupComplete) {
      toma_de_datos_2_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(59UL);
      MW_AnalogIn_Close
        (toma_de_datos_2_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
