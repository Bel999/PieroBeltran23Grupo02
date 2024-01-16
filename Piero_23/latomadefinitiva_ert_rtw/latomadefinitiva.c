/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: latomadefinitiva.c
 *
 * Code generated for Simulink model 'latomadefinitiva'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 16 13:50:03 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "latomadefinitiva.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "latomadefinitiva_private.h"

/* Block signals (default storage) */
B_latomadefinitiva_T latomadefinitiva_B;

/* Block states (default storage) */
DW_latomadefinitiva_T latomadefinitiva_DW;

/* Real-time model */
static RT_MODEL_latomadefinitiva_T latomadefinitiva_M_;
RT_MODEL_latomadefinitiva_T *const latomadefinitiva_M = &latomadefinitiva_M_;

/* Model step function */
void latomadefinitiva_step(void)
{
  {
    real_T (*lastU)[2];
    real_T Gain_tmp;
    real_T lastTime_tmp;
    int32_T rtb_Saturation3;
    int32_T tmp;
    int16_T rtb_DataTypeConversion_idx_0;
    int16_T y;

    /* MATLABSystem: '<S3>/Encoder' */
    if (latomadefinitiva_DW.obj_d.SampleTime !=
        latomadefinitiva_P.Encoder_SampleTime) {
      latomadefinitiva_DW.obj_d.SampleTime =
        latomadefinitiva_P.Encoder_SampleTime;
    }

    if (latomadefinitiva_DW.obj_d.TunablePropsChanged) {
      latomadefinitiva_DW.obj_d.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S3>/Encoder' */
    MW_EncoderRead(latomadefinitiva_DW.obj_d.Index, &latomadefinitiva_B.Encoder);

    /* MATLABSystem: '<S3>/Encoder1' */
    if (latomadefinitiva_DW.obj.SampleTime !=
        latomadefinitiva_P.Encoder1_SampleTime) {
      latomadefinitiva_DW.obj.SampleTime =
        latomadefinitiva_P.Encoder1_SampleTime;
    }

    if (latomadefinitiva_DW.obj.TunablePropsChanged) {
      latomadefinitiva_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S3>/Encoder1' */
    MW_EncoderRead(latomadefinitiva_DW.obj.Index, &latomadefinitiva_B.Encoder1);

    /* Gain: '<S3>/Gain' */
    Gain_tmp = (real_T)latomadefinitiva_P.Gain_Gain * 1.1368683772161603E-13;

    /* Gain: '<S3>/Gain' incorporates:
     *  SignalConversion generated from: '<S3>/Gain'
     */
    latomadefinitiva_B.Gain[0] = Gain_tmp * (real_T)latomadefinitiva_B.Encoder;
    latomadefinitiva_B.Gain[1] = Gain_tmp * (real_T)latomadefinitiva_B.Encoder1;

    /* Derivative: '<S3>/Derivative' */
    Gain_tmp = latomadefinitiva_M->Timing.t[0];
    if ((latomadefinitiva_DW.TimeStampA >= Gain_tmp) &&
        (latomadefinitiva_DW.TimeStampB >= Gain_tmp)) {
      /* Derivative: '<S3>/Derivative' */
      latomadefinitiva_B.Derivative[0] = 0.0;
      latomadefinitiva_B.Derivative[1] = 0.0;
    } else {
      lastTime_tmp = latomadefinitiva_DW.TimeStampA;
      lastU = &latomadefinitiva_DW.LastUAtTimeA;
      if (latomadefinitiva_DW.TimeStampA < latomadefinitiva_DW.TimeStampB) {
        if (latomadefinitiva_DW.TimeStampB < Gain_tmp) {
          lastTime_tmp = latomadefinitiva_DW.TimeStampB;
          lastU = &latomadefinitiva_DW.LastUAtTimeB;
        }
      } else if (latomadefinitiva_DW.TimeStampA >= Gain_tmp) {
        lastTime_tmp = latomadefinitiva_DW.TimeStampB;
        lastU = &latomadefinitiva_DW.LastUAtTimeB;
      }

      Gain_tmp -= lastTime_tmp;

      /* Derivative: '<S3>/Derivative' */
      latomadefinitiva_B.Derivative[0] = (latomadefinitiva_B.Gain[0] - (*lastU)
        [0]) / Gain_tmp;
      latomadefinitiva_B.Derivative[1] = (latomadefinitiva_B.Gain[1] - (*lastU)
        [1]) / Gain_tmp;
    }

    /* End of Derivative: '<S3>/Derivative' */

    /* FromWorkspace: '<S1>/fromWS_Signal 1' */
    {
      real_T *pDataValues = (real_T *)
        latomadefinitiva_DW.fromWS_Signal1_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        latomadefinitiva_DW.fromWS_Signal1_PWORK.TimePtr;
      int_T currTimeIndex = latomadefinitiva_DW.fromWS_Signal1_IWORK.PrevIndex;
      real_T t = latomadefinitiva_M->Timing.t[0];
      if (t > pTimeValues[6]) {
        latomadefinitiva_B.Signal1 = 0.0;
      } else {
        /* Get index */
        if (t <= pTimeValues[0]) {
          currTimeIndex = 0;
        } else if (t >= pTimeValues[6]) {
          currTimeIndex = 5;
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

        latomadefinitiva_DW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;

        /* Post output */
        {
          real_T t1 = pTimeValues[currTimeIndex];
          real_T t2 = pTimeValues[currTimeIndex + 1];
          if (t1 == t2) {
            if (t < t1) {
              latomadefinitiva_B.Signal1 = pDataValues[currTimeIndex];
            } else {
              latomadefinitiva_B.Signal1 = pDataValues[currTimeIndex + 1];
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex = currTimeIndex;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            latomadefinitiva_B.Signal1 = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 7;
          }
        }
      }
    }

    /* SignalConversion generated from: '<Root>/To Workspace' */
    latomadefinitiva_B.TmpSignalConversionAt_asyncqueu[0] =
      latomadefinitiva_B.Signal1;
    latomadefinitiva_B.TmpSignalConversionAt_asyncqueu[1] =
      latomadefinitiva_B.Signal1;
    latomadefinitiva_B.TmpSignalConversionAt_asyncqueu[2] =
      latomadefinitiva_B.Derivative[0];
    latomadefinitiva_B.TmpSignalConversionAt_asyncqueu[3] =
      latomadefinitiva_B.Derivative[1];

    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    Gain_tmp = floor(latomadefinitiva_B.Signal1);
    if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
      lastTime_tmp = 0.0;
      Gain_tmp = 0.0;
    } else {
      lastTime_tmp = fmod(Gain_tmp, 65536.0);
      Gain_tmp = lastTime_tmp;
    }

    rtb_DataTypeConversion_idx_0 = lastTime_tmp < 0.0 ? -(int16_T)(uint16_T)
      -lastTime_tmp : (int16_T)(uint16_T)lastTime_tmp;

    /* SignalConversion generated from: '<S3>/Mux' */
    latomadefinitiva_B.TmpSignalConversionAtTAQSigLogg[0] =
      latomadefinitiva_B.Encoder;
    latomadefinitiva_B.TmpSignalConversionAtTAQSigLogg[1] =
      latomadefinitiva_B.Encoder1;

    /* Gain: '<S4>/Gain' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Saturate: '<S4>/Saturation3'
     */
    rtb_Saturation3 = (int32_T)(Gain_tmp < 0.0 ? -(int16_T)(uint16_T)-Gain_tmp :
      (int16_T)(uint16_T)Gain_tmp) * latomadefinitiva_P.Gain_Gain_j;

    /* MATLABSystem: '<S4>/Digital Output1' incorporates:
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S6>/Compare'
     *  Saturate: '<S4>/Saturation3'
     */
    writeDigitalPin(13, (uint8_T)(rtb_Saturation3 !=
      latomadefinitiva_P.Constant_Value));

    /* MATLABSystem: '<S4>/Adelante_der' */
    latomadefinitiva_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

    /* Saturate: '<S4>/Saturation2' incorporates:
     *  Saturate: '<S4>/Saturation3'
     */
    if (rtb_Saturation3 > latomadefinitiva_P.Saturation2_UpperSat) {
      tmp = latomadefinitiva_P.Saturation2_UpperSat;
    } else if (rtb_Saturation3 < latomadefinitiva_P.Saturation2_LowerSat) {
      tmp = latomadefinitiva_P.Saturation2_LowerSat;
    } else {
      tmp = rtb_Saturation3;
    }

    /* Start for MATLABSystem: '<S4>/Adelante_der' incorporates:
     *  Saturate: '<S4>/Saturation2'
     */
    Gain_tmp = (real_T)tmp * 6.103515625E-5;
    if (!(Gain_tmp <= 255.0)) {
      Gain_tmp = 255.0;
    }

    if (!(Gain_tmp >= 0.0)) {
      Gain_tmp = 0.0;
    }

    /* MATLABSystem: '<S4>/Adelante_der' */
    MW_PWM_SetDutyCycle(latomadefinitiva_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                        Gain_tmp);

    /* Saturate: '<S4>/Saturation3' */
    if (rtb_Saturation3 > latomadefinitiva_P.Saturation3_UpperSat) {
      rtb_Saturation3 = latomadefinitiva_P.Saturation3_UpperSat;
    } else if (rtb_Saturation3 < latomadefinitiva_P.Saturation3_LowerSat) {
      rtb_Saturation3 = latomadefinitiva_P.Saturation3_LowerSat;
    }

    /* End of Saturate: '<S4>/Saturation3' */

    /* MATLABSystem: '<S4>/Atras_der' */
    latomadefinitiva_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* Abs: '<S4>/Abs1' incorporates:
     *  Saturate: '<S4>/Saturation3'
     */
    if (rtb_Saturation3 < 0L) {
      rtb_Saturation3 = -rtb_Saturation3;
    }

    /* Start for MATLABSystem: '<S4>/Atras_der' incorporates:
     *  Abs: '<S4>/Abs1'
     */
    Gain_tmp = (real_T)rtb_Saturation3 * 6.103515625E-5;
    if (!(Gain_tmp <= 255.0)) {
      Gain_tmp = 255.0;
    }

    if (!(Gain_tmp >= 0.0)) {
      Gain_tmp = 0.0;
    }

    /* MATLABSystem: '<S4>/Atras_der' */
    MW_PWM_SetDutyCycle(latomadefinitiva_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE,
                        Gain_tmp);

    /* MATLABSystem: '<S4>/Adelante_izq' */
    latomadefinitiva_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* Saturate: '<S4>/Saturation4' */
    if (rtb_DataTypeConversion_idx_0 > latomadefinitiva_P.Saturation4_UpperSat)
    {
      y = latomadefinitiva_P.Saturation4_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               latomadefinitiva_P.Saturation4_LowerSat) {
      y = latomadefinitiva_P.Saturation4_LowerSat;
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
    MW_PWM_SetDutyCycle(latomadefinitiva_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S4>/Atras_izq' */
    latomadefinitiva_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Saturate: '<S4>/Saturation5' */
    if (rtb_DataTypeConversion_idx_0 > latomadefinitiva_P.Saturation5_UpperSat)
    {
      y = latomadefinitiva_P.Saturation5_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               latomadefinitiva_P.Saturation5_LowerSat) {
      y = latomadefinitiva_P.Saturation5_LowerSat;
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
    MW_PWM_SetDutyCycle(latomadefinitiva_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S4>/Digital Output' incorporates:
     *  Constant: '<S5>/Constant'
     *  RelationalOperator: '<S5>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
      latomadefinitiva_P.Constant_Value_d));
  }

  {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S3>/Derivative' */
    if (latomadefinitiva_DW.TimeStampA == (rtInf)) {
      latomadefinitiva_DW.TimeStampA = latomadefinitiva_M->Timing.t[0];
      lastU = &latomadefinitiva_DW.LastUAtTimeA;
    } else if (latomadefinitiva_DW.TimeStampB == (rtInf)) {
      latomadefinitiva_DW.TimeStampB = latomadefinitiva_M->Timing.t[0];
      lastU = &latomadefinitiva_DW.LastUAtTimeB;
    } else if (latomadefinitiva_DW.TimeStampA < latomadefinitiva_DW.TimeStampB)
    {
      latomadefinitiva_DW.TimeStampA = latomadefinitiva_M->Timing.t[0];
      lastU = &latomadefinitiva_DW.LastUAtTimeA;
    } else {
      latomadefinitiva_DW.TimeStampB = latomadefinitiva_M->Timing.t[0];
      lastU = &latomadefinitiva_DW.LastUAtTimeB;
    }

    (*lastU)[0] = latomadefinitiva_B.Gain[0];
    (*lastU)[1] = latomadefinitiva_B.Gain[1];

    /* End of Update for Derivative: '<S3>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((latomadefinitiva_M->Timing.clockTick0 * 1) + 0)
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
      ((latomadefinitiva_M->Timing.clockTick1 * 1) + 0)
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
  latomadefinitiva_M->Timing.t[0] =
    ((time_T)(++latomadefinitiva_M->Timing.clockTick0)) *
    latomadefinitiva_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    latomadefinitiva_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void latomadefinitiva_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&latomadefinitiva_M->solverInfo,
                          &latomadefinitiva_M->Timing.simTimeStep);
    rtsiSetTPtr(&latomadefinitiva_M->solverInfo, &rtmGetTPtr(latomadefinitiva_M));
    rtsiSetStepSizePtr(&latomadefinitiva_M->solverInfo,
                       &latomadefinitiva_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&latomadefinitiva_M->solverInfo, (&rtmGetErrorStatus
      (latomadefinitiva_M)));
    rtsiSetRTModelPtr(&latomadefinitiva_M->solverInfo, latomadefinitiva_M);
  }

  rtsiSetSimTimeStep(&latomadefinitiva_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&latomadefinitiva_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(latomadefinitiva_M, &latomadefinitiva_M->Timing.tArray[0]);
  rtmSetTFinal(latomadefinitiva_M, 10.0);
  latomadefinitiva_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  latomadefinitiva_M->Sizes.checksums[0] = (3202797132U);
  latomadefinitiva_M->Sizes.checksums[1] = (2742781587U);
  latomadefinitiva_M->Sizes.checksums[2] = (3047195747U);
  latomadefinitiva_M->Sizes.checksums[3] = (996067589U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    latomadefinitiva_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(latomadefinitiva_M->extModeInfo,
      &latomadefinitiva_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(latomadefinitiva_M->extModeInfo,
                        latomadefinitiva_M->Sizes.checksums);
    rteiSetTPtr(latomadefinitiva_M->extModeInfo, rtmGetTPtr(latomadefinitiva_M));
  }

  /* Start for FromWorkspace: '<S1>/fromWS_Signal 1' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 3.0, 5.0, 7.0, 9.0, 10.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 255.0, 0.0, -255.0, 0.0, 0.0 } ;

    latomadefinitiva_DW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
    latomadefinitiva_DW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
    latomadefinitiva_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  latomadefinitiva_DW.TimeStampA = (rtInf);
  latomadefinitiva_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<S3>/Encoder' */
  latomadefinitiva_DW.obj_d.Index = 0U;
  latomadefinitiva_DW.obj_d.matlabCodegenIsDeleted = false;
  latomadefinitiva_DW.obj_d.SampleTime = latomadefinitiva_P.Encoder_SampleTime;
  latomadefinitiva_DW.obj_d.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &latomadefinitiva_DW.obj_d.Index);
  latomadefinitiva_DW.obj_d.isSetupComplete = true;
  latomadefinitiva_DW.obj_d.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
  MW_EncoderReset(latomadefinitiva_DW.obj_d.Index);

  /* Start for MATLABSystem: '<S3>/Encoder1' */
  latomadefinitiva_DW.obj.Index = 0U;
  latomadefinitiva_DW.obj.matlabCodegenIsDeleted = false;
  latomadefinitiva_DW.obj.SampleTime = latomadefinitiva_P.Encoder1_SampleTime;
  latomadefinitiva_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &latomadefinitiva_DW.obj.Index);
  latomadefinitiva_DW.obj.isSetupComplete = true;
  latomadefinitiva_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder1' */
  MW_EncoderReset(latomadefinitiva_DW.obj.Index);

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  latomadefinitiva_DW.obj_gs.matlabCodegenIsDeleted = false;
  latomadefinitiva_DW.obj_gs.isInitialized = 1L;
  digitalIOSetup(13, 1);
  latomadefinitiva_DW.obj_gs.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Adelante_der' */
  latomadefinitiva_DW.obj_g.matlabCodegenIsDeleted = false;
  latomadefinitiva_DW.obj_g.isInitialized = 1L;
  latomadefinitiva_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0,
    0.0);
  latomadefinitiva_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_der' */
  latomadefinitiva_DW.obj_i.matlabCodegenIsDeleted = false;
  latomadefinitiva_DW.obj_i.isInitialized = 1L;
  latomadefinitiva_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  latomadefinitiva_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Adelante_izq' */
  latomadefinitiva_DW.obj_j.matlabCodegenIsDeleted = false;
  latomadefinitiva_DW.obj_j.isInitialized = 1L;
  latomadefinitiva_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0,
    0.0);
  latomadefinitiva_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_izq' */
  latomadefinitiva_DW.obj_a.matlabCodegenIsDeleted = false;
  latomadefinitiva_DW.obj_a.isInitialized = 1L;
  latomadefinitiva_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0,
    0.0);
  latomadefinitiva_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output' */
  latomadefinitiva_DW.obj_m.matlabCodegenIsDeleted = false;
  latomadefinitiva_DW.obj_m.isInitialized = 1L;
  digitalIOSetup(8, 1);
  latomadefinitiva_DW.obj_m.isSetupComplete = true;
}

/* Model terminate function */
void latomadefinitiva_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!latomadefinitiva_DW.obj_d.matlabCodegenIsDeleted) {
    latomadefinitiva_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((latomadefinitiva_DW.obj_d.isInitialized == 1L) &&
        latomadefinitiva_DW.obj_d.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */

  /* Terminate for MATLABSystem: '<S3>/Encoder1' */
  if (!latomadefinitiva_DW.obj.matlabCodegenIsDeleted) {
    latomadefinitiva_DW.obj.matlabCodegenIsDeleted = true;
    if ((latomadefinitiva_DW.obj.isInitialized == 1L) &&
        latomadefinitiva_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder1' */
  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!latomadefinitiva_DW.obj_gs.matlabCodegenIsDeleted) {
    latomadefinitiva_DW.obj_gs.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S4>/Adelante_der' */
  if (!latomadefinitiva_DW.obj_g.matlabCodegenIsDeleted) {
    latomadefinitiva_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((latomadefinitiva_DW.obj_g.isInitialized == 1L) &&
        latomadefinitiva_DW.obj_g.isSetupComplete) {
      latomadefinitiva_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_SetDutyCycle(latomadefinitiva_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      latomadefinitiva_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_Close(latomadefinitiva_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S4>/Atras_der' */
  if (!latomadefinitiva_DW.obj_i.matlabCodegenIsDeleted) {
    latomadefinitiva_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((latomadefinitiva_DW.obj_i.isInitialized == 1L) &&
        latomadefinitiva_DW.obj_i.isSetupComplete) {
      latomadefinitiva_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_SetDutyCycle(latomadefinitiva_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      latomadefinitiva_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_Close(latomadefinitiva_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_der' */

  /* Terminate for MATLABSystem: '<S4>/Adelante_izq' */
  if (!latomadefinitiva_DW.obj_j.matlabCodegenIsDeleted) {
    latomadefinitiva_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((latomadefinitiva_DW.obj_j.isInitialized == 1L) &&
        latomadefinitiva_DW.obj_j.isSetupComplete) {
      latomadefinitiva_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);
      MW_PWM_SetDutyCycle(latomadefinitiva_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      latomadefinitiva_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);
      MW_PWM_Close(latomadefinitiva_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S4>/Atras_izq' */
  if (!latomadefinitiva_DW.obj_a.matlabCodegenIsDeleted) {
    latomadefinitiva_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((latomadefinitiva_DW.obj_a.isInitialized == 1L) &&
        latomadefinitiva_DW.obj_a.isSetupComplete) {
      latomadefinitiva_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_SetDutyCycle(latomadefinitiva_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      latomadefinitiva_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_Close(latomadefinitiva_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!latomadefinitiva_DW.obj_m.matlabCodegenIsDeleted) {
    latomadefinitiva_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
