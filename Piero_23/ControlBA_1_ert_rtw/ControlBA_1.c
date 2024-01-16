/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlBA_1.c
 *
 * Code generated for Simulink model 'ControlBA_1'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Nov 15 01:47:14 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ControlBA_1.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "ControlBA_1_private.h"

/* Block signals (default storage) */
B_ControlBA_1_T ControlBA_1_B;

/* Block states (default storage) */
DW_ControlBA_1_T ControlBA_1_DW;

/* Real-time model */
static RT_MODEL_ControlBA_1_T ControlBA_1_M_;
RT_MODEL_ControlBA_1_T *const ControlBA_1_M = &ControlBA_1_M_;

/* Model step function */
void ControlBA_1_step(void)
{
  {
    real_T (*lastU)[2];
    real_T Gain_tmp;
    real_T lastTime_tmp;
    int16_T rtb_DataTypeConversion_idx_0;
    int16_T rtb_DataTypeConversion_idx_1;
    int16_T y;

    /* MATLABSystem: '<S3>/Encoder' */
    if (ControlBA_1_DW.obj_p.SampleTime != ControlBA_1_P.Encoder_SampleTime) {
      ControlBA_1_DW.obj_p.SampleTime = ControlBA_1_P.Encoder_SampleTime;
    }

    if (ControlBA_1_DW.obj_p.TunablePropsChanged) {
      ControlBA_1_DW.obj_p.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S3>/Encoder' */
    MW_EncoderRead(ControlBA_1_DW.obj_p.Index, &ControlBA_1_B.Encoder);

    /* MATLABSystem: '<S3>/Encoder1' */
    if (ControlBA_1_DW.obj.SampleTime != ControlBA_1_P.Encoder1_SampleTime) {
      ControlBA_1_DW.obj.SampleTime = ControlBA_1_P.Encoder1_SampleTime;
    }

    if (ControlBA_1_DW.obj.TunablePropsChanged) {
      ControlBA_1_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S3>/Encoder1' */
    MW_EncoderRead(ControlBA_1_DW.obj.Index, &ControlBA_1_B.Encoder1);

    /* Gain: '<S3>/Gain' */
    Gain_tmp = (real_T)ControlBA_1_P.Gain_Gain * 1.1368683772161603E-13;

    /* Gain: '<S3>/Gain' incorporates:
     *  SignalConversion generated from: '<S3>/Gain'
     */
    ControlBA_1_B.Gain[0] = Gain_tmp * (real_T)ControlBA_1_B.Encoder;
    ControlBA_1_B.Gain[1] = Gain_tmp * (real_T)ControlBA_1_B.Encoder1;

    /* Derivative: '<S3>/Derivative' */
    Gain_tmp = ControlBA_1_M->Timing.t[0];
    if ((ControlBA_1_DW.TimeStampA >= Gain_tmp) && (ControlBA_1_DW.TimeStampB >=
         Gain_tmp)) {
      /* Derivative: '<S3>/Derivative' */
      ControlBA_1_B.Derivative[0] = 0.0;
      ControlBA_1_B.Derivative[1] = 0.0;
    } else {
      lastTime_tmp = ControlBA_1_DW.TimeStampA;
      lastU = &ControlBA_1_DW.LastUAtTimeA;
      if (ControlBA_1_DW.TimeStampA < ControlBA_1_DW.TimeStampB) {
        if (ControlBA_1_DW.TimeStampB < Gain_tmp) {
          lastTime_tmp = ControlBA_1_DW.TimeStampB;
          lastU = &ControlBA_1_DW.LastUAtTimeB;
        }
      } else if (ControlBA_1_DW.TimeStampA >= Gain_tmp) {
        lastTime_tmp = ControlBA_1_DW.TimeStampB;
        lastU = &ControlBA_1_DW.LastUAtTimeB;
      }

      Gain_tmp -= lastTime_tmp;

      /* Derivative: '<S3>/Derivative' */
      ControlBA_1_B.Derivative[0] = (ControlBA_1_B.Gain[0] - (*lastU)[0]) /
        Gain_tmp;
      ControlBA_1_B.Derivative[1] = (ControlBA_1_B.Gain[1] - (*lastU)[1]) /
        Gain_tmp;
    }

    /* End of Derivative: '<S3>/Derivative' */

    /* FromWorkspace: '<S1>/From Workspace' */
    {
      real_T *pDataValues = (real_T *)
        ControlBA_1_DW.FromWorkspace_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        ControlBA_1_DW.FromWorkspace_PWORK.TimePtr;
      int_T currTimeIndex = ControlBA_1_DW.FromWorkspace_IWORK.PrevIndex;
      real_T t = ControlBA_1_M->Timing.t[0];
      if (t > pTimeValues[13]) {
        ControlBA_1_B.Signal2 = 0.0;
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

        ControlBA_1_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

        /* Post output */
        {
          real_T t1 = pTimeValues[currTimeIndex];
          real_T t2 = pTimeValues[currTimeIndex + 1];
          if (t1 == t2) {
            if (t < t1) {
              ControlBA_1_B.Signal2 = pDataValues[currTimeIndex];
            } else {
              ControlBA_1_B.Signal2 = pDataValues[currTimeIndex + 1];
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex = currTimeIndex;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            ControlBA_1_B.Signal2 = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 14;
          }
        }
      }
    }

    /* SignalConversion generated from: '<Root>/To Workspace' */
    ControlBA_1_B.TmpSignalConversionAt_asyncqueu[0] = ControlBA_1_B.Signal2;
    ControlBA_1_B.TmpSignalConversionAt_asyncqueu[1] = ControlBA_1_B.Signal2;
    ControlBA_1_B.TmpSignalConversionAt_asyncqueu[2] = ControlBA_1_B.Derivative
      [0];
    ControlBA_1_B.TmpSignalConversionAt_asyncqueu[3] = ControlBA_1_B.Derivative
      [1];

    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    Gain_tmp = floor(ControlBA_1_B.Signal2);
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
    ControlBA_1_B.TmpSignalConversionAtTAQSigLogg[0] = ControlBA_1_B.Encoder;
    ControlBA_1_B.TmpSignalConversionAtTAQSigLogg[1] = ControlBA_1_B.Encoder1;

    /* MATLABSystem: '<S4>/Adelante_der' */
    ControlBA_1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

    /* Saturate: '<S4>/Saturation2' */
    if (rtb_DataTypeConversion_idx_1 > ControlBA_1_P.Saturation2_UpperSat) {
      y = ControlBA_1_P.Saturation2_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 < ControlBA_1_P.Saturation2_LowerSat)
    {
      y = ControlBA_1_P.Saturation2_LowerSat;
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
    MW_PWM_SetDutyCycle(ControlBA_1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                        y);

    /* MATLABSystem: '<S4>/Adelante_izq' */
    ControlBA_1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* Saturate: '<S4>/Saturation4' */
    if (rtb_DataTypeConversion_idx_0 > ControlBA_1_P.Saturation4_UpperSat) {
      y = ControlBA_1_P.Saturation4_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 < ControlBA_1_P.Saturation4_LowerSat)
    {
      y = ControlBA_1_P.Saturation4_LowerSat;
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
    MW_PWM_SetDutyCycle(ControlBA_1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                        y);

    /* MATLABSystem: '<S4>/Atras_der' */
    ControlBA_1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* Saturate: '<S4>/Saturation3' */
    if (rtb_DataTypeConversion_idx_1 > ControlBA_1_P.Saturation3_UpperSat) {
      y = ControlBA_1_P.Saturation3_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 < ControlBA_1_P.Saturation3_LowerSat)
    {
      y = ControlBA_1_P.Saturation3_LowerSat;
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
    MW_PWM_SetDutyCycle(ControlBA_1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                        y);

    /* MATLABSystem: '<S4>/Atras_izq' */
    ControlBA_1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Saturate: '<S4>/Saturation5' */
    if (rtb_DataTypeConversion_idx_0 > ControlBA_1_P.Saturation5_UpperSat) {
      y = ControlBA_1_P.Saturation5_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 < ControlBA_1_P.Saturation5_LowerSat)
    {
      y = ControlBA_1_P.Saturation5_LowerSat;
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
    MW_PWM_SetDutyCycle(ControlBA_1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, (real_T)
                        y);

    /* MATLABSystem: '<S4>/Digital Output' incorporates:
     *  Constant: '<S5>/Constant'
     *  RelationalOperator: '<S5>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
      ControlBA_1_P.Constant_Value));

    /* MATLABSystem: '<S4>/Digital Output1' incorporates:
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S6>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
      ControlBA_1_P.Constant_Value_h));

    /* MATLABSystem: '<Root>/Analog Input' */
    if (ControlBA_1_DW.obj_n.SampleTime != ControlBA_1_P.AnalogInput_SampleTime)
    {
      ControlBA_1_DW.obj_n.SampleTime = ControlBA_1_P.AnalogInput_SampleTime;
    }

    ControlBA_1_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
      MW_AnalogIn_GetHandle(59UL);

    /* MATLABSystem: '<Root>/Analog Input' */
    MW_AnalogInSingle_ReadResult
      (ControlBA_1_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
       &ControlBA_1_B.AnalogInput, MW_ANALOGIN_UINT16);
  }

  {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S3>/Derivative' */
    if (ControlBA_1_DW.TimeStampA == (rtInf)) {
      ControlBA_1_DW.TimeStampA = ControlBA_1_M->Timing.t[0];
      lastU = &ControlBA_1_DW.LastUAtTimeA;
    } else if (ControlBA_1_DW.TimeStampB == (rtInf)) {
      ControlBA_1_DW.TimeStampB = ControlBA_1_M->Timing.t[0];
      lastU = &ControlBA_1_DW.LastUAtTimeB;
    } else if (ControlBA_1_DW.TimeStampA < ControlBA_1_DW.TimeStampB) {
      ControlBA_1_DW.TimeStampA = ControlBA_1_M->Timing.t[0];
      lastU = &ControlBA_1_DW.LastUAtTimeA;
    } else {
      ControlBA_1_DW.TimeStampB = ControlBA_1_M->Timing.t[0];
      lastU = &ControlBA_1_DW.LastUAtTimeB;
    }

    (*lastU)[0] = ControlBA_1_B.Gain[0];
    (*lastU)[1] = ControlBA_1_B.Gain[1];

    /* End of Update for Derivative: '<S3>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((ControlBA_1_M->Timing.clockTick0 * 1) + 0)
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
      ((ControlBA_1_M->Timing.clockTick1 * 1) + 0)
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
  ControlBA_1_M->Timing.t[0] =
    ((time_T)(++ControlBA_1_M->Timing.clockTick0)) *
    ControlBA_1_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    ControlBA_1_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void ControlBA_1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ControlBA_1_M->solverInfo,
                          &ControlBA_1_M->Timing.simTimeStep);
    rtsiSetTPtr(&ControlBA_1_M->solverInfo, &rtmGetTPtr(ControlBA_1_M));
    rtsiSetStepSizePtr(&ControlBA_1_M->solverInfo,
                       &ControlBA_1_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&ControlBA_1_M->solverInfo, (&rtmGetErrorStatus
      (ControlBA_1_M)));
    rtsiSetRTModelPtr(&ControlBA_1_M->solverInfo, ControlBA_1_M);
  }

  rtsiSetSimTimeStep(&ControlBA_1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&ControlBA_1_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(ControlBA_1_M, &ControlBA_1_M->Timing.tArray[0]);
  rtmSetTFinal(ControlBA_1_M, 10.0);
  ControlBA_1_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  ControlBA_1_M->Sizes.checksums[0] = (2538202215U);
  ControlBA_1_M->Sizes.checksums[1] = (2756176228U);
  ControlBA_1_M->Sizes.checksums[2] = (3921550178U);
  ControlBA_1_M->Sizes.checksums[3] = (479300803U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    ControlBA_1_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(ControlBA_1_M->extModeInfo,
      &ControlBA_1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ControlBA_1_M->extModeInfo,
                        ControlBA_1_M->Sizes.checksums);
    rteiSetTPtr(ControlBA_1_M->extModeInfo, rtmGetTPtr(ControlBA_1_M));
  }

  /* Start for FromWorkspace: '<S1>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 2.0, 2.0, 3.0, 3.0, 5.0, 5.0,
      7.0, 7.0, 9.0, 9.0, 10.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 100.72499847412109,
      100.72499847412109, -100.72499847412109, -100.72499847412109,
      100.72499847412109, 100.72499847412109, -100.72499847412109,
      -100.72499847412109, 100.72499847412109, 100.72499847412109, 0.0, 0.0 } ;

    ControlBA_1_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    ControlBA_1_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    ControlBA_1_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  ControlBA_1_DW.TimeStampA = (rtInf);
  ControlBA_1_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<S3>/Encoder' */
  ControlBA_1_DW.obj_p.Index = 0U;
  ControlBA_1_DW.obj_p.matlabCodegenIsDeleted = false;
  ControlBA_1_DW.obj_p.SampleTime = ControlBA_1_P.Encoder_SampleTime;
  ControlBA_1_DW.obj_p.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &ControlBA_1_DW.obj_p.Index);
  ControlBA_1_DW.obj_p.isSetupComplete = true;
  ControlBA_1_DW.obj_p.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
  MW_EncoderReset(ControlBA_1_DW.obj_p.Index);

  /* Start for MATLABSystem: '<S3>/Encoder1' */
  ControlBA_1_DW.obj.Index = 0U;
  ControlBA_1_DW.obj.matlabCodegenIsDeleted = false;
  ControlBA_1_DW.obj.SampleTime = ControlBA_1_P.Encoder1_SampleTime;
  ControlBA_1_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &ControlBA_1_DW.obj.Index);
  ControlBA_1_DW.obj.isSetupComplete = true;
  ControlBA_1_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder1' */
  MW_EncoderReset(ControlBA_1_DW.obj.Index);

  /* Start for MATLABSystem: '<S4>/Adelante_der' */
  ControlBA_1_DW.obj_k.matlabCodegenIsDeleted = false;
  ControlBA_1_DW.obj_k.isInitialized = 1L;
  ControlBA_1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0, 0.0);
  ControlBA_1_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Adelante_izq' */
  ControlBA_1_DW.obj_c.matlabCodegenIsDeleted = false;
  ControlBA_1_DW.obj_c.isInitialized = 1L;
  ControlBA_1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  ControlBA_1_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_der' */
  ControlBA_1_DW.obj_l.matlabCodegenIsDeleted = false;
  ControlBA_1_DW.obj_l.isInitialized = 1L;
  ControlBA_1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  ControlBA_1_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_izq' */
  ControlBA_1_DW.obj_m.matlabCodegenIsDeleted = false;
  ControlBA_1_DW.obj_m.isInitialized = 1L;
  ControlBA_1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
  ControlBA_1_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output' */
  ControlBA_1_DW.obj_mx.matlabCodegenIsDeleted = false;
  ControlBA_1_DW.obj_mx.isInitialized = 1L;
  digitalIOSetup(8, 1);
  ControlBA_1_DW.obj_mx.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  ControlBA_1_DW.obj_o.matlabCodegenIsDeleted = false;
  ControlBA_1_DW.obj_o.isInitialized = 1L;
  digitalIOSetup(13, 1);
  ControlBA_1_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  ControlBA_1_DW.obj_n.matlabCodegenIsDeleted = false;
  ControlBA_1_DW.obj_n.SampleTime = ControlBA_1_P.AnalogInput_SampleTime;
  ControlBA_1_DW.obj_n.isInitialized = 1L;
  ControlBA_1_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(59UL);
  ControlBA_1_DW.obj_n.isSetupComplete = true;
}

/* Model terminate function */
void ControlBA_1_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!ControlBA_1_DW.obj_p.matlabCodegenIsDeleted) {
    ControlBA_1_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((ControlBA_1_DW.obj_p.isInitialized == 1L) &&
        ControlBA_1_DW.obj_p.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */

  /* Terminate for MATLABSystem: '<S3>/Encoder1' */
  if (!ControlBA_1_DW.obj.matlabCodegenIsDeleted) {
    ControlBA_1_DW.obj.matlabCodegenIsDeleted = true;
    if ((ControlBA_1_DW.obj.isInitialized == 1L) &&
        ControlBA_1_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder1' */
  /* Terminate for MATLABSystem: '<S4>/Adelante_der' */
  if (!ControlBA_1_DW.obj_k.matlabCodegenIsDeleted) {
    ControlBA_1_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((ControlBA_1_DW.obj_k.isInitialized == 1L) &&
        ControlBA_1_DW.obj_k.isSetupComplete) {
      ControlBA_1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle(ControlBA_1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ControlBA_1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_Close(ControlBA_1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S4>/Adelante_izq' */
  if (!ControlBA_1_DW.obj_c.matlabCodegenIsDeleted) {
    ControlBA_1_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((ControlBA_1_DW.obj_c.isInitialized == 1L) &&
        ControlBA_1_DW.obj_c.isSetupComplete) {
      ControlBA_1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(ControlBA_1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ControlBA_1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(ControlBA_1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S4>/Atras_der' */
  if (!ControlBA_1_DW.obj_l.matlabCodegenIsDeleted) {
    ControlBA_1_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((ControlBA_1_DW.obj_l.isInitialized == 1L) &&
        ControlBA_1_DW.obj_l.isSetupComplete) {
      ControlBA_1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(ControlBA_1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ControlBA_1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(ControlBA_1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_der' */

  /* Terminate for MATLABSystem: '<S4>/Atras_izq' */
  if (!ControlBA_1_DW.obj_m.matlabCodegenIsDeleted) {
    ControlBA_1_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((ControlBA_1_DW.obj_m.isInitialized == 1L) &&
        ControlBA_1_DW.obj_m.isSetupComplete) {
      ControlBA_1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(ControlBA_1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ControlBA_1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(ControlBA_1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!ControlBA_1_DW.obj_mx.matlabCodegenIsDeleted) {
    ControlBA_1_DW.obj_mx.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!ControlBA_1_DW.obj_o.matlabCodegenIsDeleted) {
    ControlBA_1_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!ControlBA_1_DW.obj_n.matlabCodegenIsDeleted) {
    ControlBA_1_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((ControlBA_1_DW.obj_n.isInitialized == 1L) &&
        ControlBA_1_DW.obj_n.isSetupComplete) {
      ControlBA_1_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(59UL);
      MW_AnalogIn_Close
        (ControlBA_1_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
