/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Toma_De_Datos.c
 *
 * Code generated for Simulink model 'Toma_De_Datos'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Nov 14 20:25:59 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Toma_De_Datos.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "Toma_De_Datos_private.h"

/* Block signals (default storage) */
B_Toma_De_Datos_T Toma_De_Datos_B;

/* Block states (default storage) */
DW_Toma_De_Datos_T Toma_De_Datos_DW;

/* Real-time model */
static RT_MODEL_Toma_De_Datos_T Toma_De_Datos_M_;
RT_MODEL_Toma_De_Datos_T *const Toma_De_Datos_M = &Toma_De_Datos_M_;

/* Model step function */
void Toma_De_Datos_step(void)
{
  {
    real_T (*lastU)[2];
    real_T Gain_tmp;
    real_T lastTime_tmp;
    int32_T rtb_Encoder1_0;
    int32_T rtb_Encoder_0;
    int16_T rtb_DataTypeConversion_idx_0;
    int16_T rtb_DataTypeConversion_idx_1;
    int16_T y;

    /* MATLABSystem: '<S3>/Encoder' */
    if (Toma_De_Datos_DW.obj_i.SampleTime != Toma_De_Datos_P.Encoder_SampleTime)
    {
      Toma_De_Datos_DW.obj_i.SampleTime = Toma_De_Datos_P.Encoder_SampleTime;
    }

    if (Toma_De_Datos_DW.obj_i.TunablePropsChanged) {
      Toma_De_Datos_DW.obj_i.TunablePropsChanged = false;
    }

    MW_EncoderRead(Toma_De_Datos_DW.obj_i.Index, &rtb_Encoder_0);

    /* MATLABSystem: '<S3>/Encoder1' */
    if (Toma_De_Datos_DW.obj.SampleTime != Toma_De_Datos_P.Encoder1_SampleTime)
    {
      Toma_De_Datos_DW.obj.SampleTime = Toma_De_Datos_P.Encoder1_SampleTime;
    }

    if (Toma_De_Datos_DW.obj.TunablePropsChanged) {
      Toma_De_Datos_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(Toma_De_Datos_DW.obj.Index, &rtb_Encoder1_0);

    /* Gain: '<S3>/Gain' */
    Gain_tmp = (real_T)Toma_De_Datos_P.Gain_Gain * 1.1368683772161603E-13;

    /* Gain: '<S3>/Gain' incorporates:
     *  MATLABSystem: '<S3>/Encoder'
     *  MATLABSystem: '<S3>/Encoder1'
     */
    Toma_De_Datos_B.Gain[0] = Gain_tmp * (real_T)rtb_Encoder_0;
    Toma_De_Datos_B.Gain[1] = Gain_tmp * (real_T)rtb_Encoder1_0;

    /* Derivative: '<S3>/Derivative' */
    Gain_tmp = Toma_De_Datos_M->Timing.t[0];
    if ((Toma_De_Datos_DW.TimeStampA >= Gain_tmp) &&
        (Toma_De_Datos_DW.TimeStampB >= Gain_tmp)) {
      /* Derivative: '<S3>/Derivative' */
      Toma_De_Datos_B.Derivative[0] = 0.0;
      Toma_De_Datos_B.Derivative[1] = 0.0;
    } else {
      lastTime_tmp = Toma_De_Datos_DW.TimeStampA;
      lastU = &Toma_De_Datos_DW.LastUAtTimeA;
      if (Toma_De_Datos_DW.TimeStampA < Toma_De_Datos_DW.TimeStampB) {
        if (Toma_De_Datos_DW.TimeStampB < Gain_tmp) {
          lastTime_tmp = Toma_De_Datos_DW.TimeStampB;
          lastU = &Toma_De_Datos_DW.LastUAtTimeB;
        }
      } else if (Toma_De_Datos_DW.TimeStampA >= Gain_tmp) {
        lastTime_tmp = Toma_De_Datos_DW.TimeStampB;
        lastU = &Toma_De_Datos_DW.LastUAtTimeB;
      }

      Gain_tmp -= lastTime_tmp;

      /* Derivative: '<S3>/Derivative' */
      Toma_De_Datos_B.Derivative[0] = (Toma_De_Datos_B.Gain[0] - (*lastU)[0]) /
        Gain_tmp;
      Toma_De_Datos_B.Derivative[1] = (Toma_De_Datos_B.Gain[1] - (*lastU)[1]) /
        Gain_tmp;
    }

    /* End of Derivative: '<S3>/Derivative' */

    /* FromWorkspace: '<S1>/fromWS_Signal 1' */
    {
      real_T *pDataValues = (real_T *)
        Toma_De_Datos_DW.fromWS_Signal1_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        Toma_De_Datos_DW.fromWS_Signal1_PWORK.TimePtr;
      int_T currTimeIndex = Toma_De_Datos_DW.fromWS_Signal1_IWORK.PrevIndex;
      real_T t = Toma_De_Datos_M->Timing.t[0];
      if (t > pTimeValues[1]) {
        Toma_De_Datos_B.Signal1 = 0.0;
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

        Toma_De_Datos_DW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;

        /* Post output */
        {
          real_T t1 = pTimeValues[currTimeIndex];
          real_T t2 = pTimeValues[currTimeIndex + 1];
          if (t1 == t2) {
            if (t < t1) {
              Toma_De_Datos_B.Signal1 = pDataValues[currTimeIndex];
            } else {
              Toma_De_Datos_B.Signal1 = pDataValues[currTimeIndex + 1];
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex = currTimeIndex;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            Toma_De_Datos_B.Signal1 = (real_T) rtInterpolate(d1, d2, f1, f2);
            pDataValues += 2;
          }
        }
      }
    }

    /* SignalConversion generated from: '<Root>/To Workspace' */
    Toma_De_Datos_B.TmpSignalConversionAt_asyncqueu[0] = Toma_De_Datos_B.Signal1;
    Toma_De_Datos_B.TmpSignalConversionAt_asyncqueu[1] = Toma_De_Datos_B.Signal1;
    Toma_De_Datos_B.TmpSignalConversionAt_asyncqueu[2] =
      Toma_De_Datos_B.Derivative[0];
    Toma_De_Datos_B.TmpSignalConversionAt_asyncqueu[3] =
      Toma_De_Datos_B.Derivative[1];

    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    Gain_tmp = floor(Toma_De_Datos_B.Signal1);
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
    /* MATLABSystem: '<S4>/Adelante_der' */
    Toma_De_Datos_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

    /* Saturate: '<S4>/Saturation2' */
    if (rtb_DataTypeConversion_idx_1 > Toma_De_Datos_P.Saturation2_UpperSat) {
      y = Toma_De_Datos_P.Saturation2_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               Toma_De_Datos_P.Saturation2_LowerSat) {
      y = Toma_De_Datos_P.Saturation2_LowerSat;
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
    MW_PWM_SetDutyCycle(Toma_De_Datos_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S4>/Adelante_izq' */
    Toma_De_Datos_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* Saturate: '<S4>/Saturation4' */
    if (rtb_DataTypeConversion_idx_0 > Toma_De_Datos_P.Saturation4_UpperSat) {
      y = Toma_De_Datos_P.Saturation4_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               Toma_De_Datos_P.Saturation4_LowerSat) {
      y = Toma_De_Datos_P.Saturation4_LowerSat;
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
    MW_PWM_SetDutyCycle(Toma_De_Datos_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S4>/Atras_der' */
    Toma_De_Datos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* Saturate: '<S4>/Saturation3' */
    if (rtb_DataTypeConversion_idx_1 > Toma_De_Datos_P.Saturation3_UpperSat) {
      y = Toma_De_Datos_P.Saturation3_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               Toma_De_Datos_P.Saturation3_LowerSat) {
      y = Toma_De_Datos_P.Saturation3_LowerSat;
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
    MW_PWM_SetDutyCycle(Toma_De_Datos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S4>/Atras_izq' */
    Toma_De_Datos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Saturate: '<S4>/Saturation5' */
    if (rtb_DataTypeConversion_idx_0 > Toma_De_Datos_P.Saturation5_UpperSat) {
      y = Toma_De_Datos_P.Saturation5_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               Toma_De_Datos_P.Saturation5_LowerSat) {
      y = Toma_De_Datos_P.Saturation5_LowerSat;
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
    MW_PWM_SetDutyCycle(Toma_De_Datos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S4>/Digital Output' incorporates:
     *  Constant: '<S5>/Constant'
     *  RelationalOperator: '<S5>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
      Toma_De_Datos_P.Constant_Value));

    /* MATLABSystem: '<S4>/Digital Output1' incorporates:
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S6>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
      Toma_De_Datos_P.Constant_Value_c));
  }

  {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S3>/Derivative' */
    if (Toma_De_Datos_DW.TimeStampA == (rtInf)) {
      Toma_De_Datos_DW.TimeStampA = Toma_De_Datos_M->Timing.t[0];
      lastU = &Toma_De_Datos_DW.LastUAtTimeA;
    } else if (Toma_De_Datos_DW.TimeStampB == (rtInf)) {
      Toma_De_Datos_DW.TimeStampB = Toma_De_Datos_M->Timing.t[0];
      lastU = &Toma_De_Datos_DW.LastUAtTimeB;
    } else if (Toma_De_Datos_DW.TimeStampA < Toma_De_Datos_DW.TimeStampB) {
      Toma_De_Datos_DW.TimeStampA = Toma_De_Datos_M->Timing.t[0];
      lastU = &Toma_De_Datos_DW.LastUAtTimeA;
    } else {
      Toma_De_Datos_DW.TimeStampB = Toma_De_Datos_M->Timing.t[0];
      lastU = &Toma_De_Datos_DW.LastUAtTimeB;
    }

    (*lastU)[0] = Toma_De_Datos_B.Gain[0];
    (*lastU)[1] = Toma_De_Datos_B.Gain[1];

    /* End of Update for Derivative: '<S3>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Toma_De_Datos_M->Timing.clockTick0 * 1) + 0)
      ;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.1s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Toma_De_Datos_M->Timing.clockTick1 * 1) + 0)
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
  Toma_De_Datos_M->Timing.t[0] =
    ((time_T)(++Toma_De_Datos_M->Timing.clockTick0)) *
    Toma_De_Datos_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Toma_De_Datos_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Toma_De_Datos_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Toma_De_Datos_M->solverInfo,
                          &Toma_De_Datos_M->Timing.simTimeStep);
    rtsiSetTPtr(&Toma_De_Datos_M->solverInfo, &rtmGetTPtr(Toma_De_Datos_M));
    rtsiSetStepSizePtr(&Toma_De_Datos_M->solverInfo,
                       &Toma_De_Datos_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Toma_De_Datos_M->solverInfo, (&rtmGetErrorStatus
      (Toma_De_Datos_M)));
    rtsiSetRTModelPtr(&Toma_De_Datos_M->solverInfo, Toma_De_Datos_M);
  }

  rtsiSetSimTimeStep(&Toma_De_Datos_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Toma_De_Datos_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Toma_De_Datos_M, &Toma_De_Datos_M->Timing.tArray[0]);
  rtmSetTFinal(Toma_De_Datos_M, 10.0);
  Toma_De_Datos_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Toma_De_Datos_M->Sizes.checksums[0] = (3558968783U);
  Toma_De_Datos_M->Sizes.checksums[1] = (1144063312U);
  Toma_De_Datos_M->Sizes.checksums[2] = (2067257041U);
  Toma_De_Datos_M->Sizes.checksums[3] = (337509733U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    Toma_De_Datos_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(Toma_De_Datos_M->extModeInfo,
      &Toma_De_Datos_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Toma_De_Datos_M->extModeInfo,
                        Toma_De_Datos_M->Sizes.checksums);
    rteiSetTPtr(Toma_De_Datos_M->extModeInfo, rtmGetTPtr(Toma_De_Datos_M));
  }

  /* Start for FromWorkspace: '<S1>/fromWS_Signal 1' */
  {
    static real_T pTimeValues0[] = { 0.0, 10.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0 } ;

    Toma_De_Datos_DW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
    Toma_De_Datos_DW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
    Toma_De_Datos_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  Toma_De_Datos_DW.TimeStampA = (rtInf);
  Toma_De_Datos_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<S3>/Encoder' */
  Toma_De_Datos_DW.obj_i.Index = 0U;
  Toma_De_Datos_DW.obj_i.matlabCodegenIsDeleted = false;
  Toma_De_Datos_DW.obj_i.SampleTime = Toma_De_Datos_P.Encoder_SampleTime;
  Toma_De_Datos_DW.obj_i.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &Toma_De_Datos_DW.obj_i.Index);
  Toma_De_Datos_DW.obj_i.isSetupComplete = true;
  Toma_De_Datos_DW.obj_i.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
  MW_EncoderReset(Toma_De_Datos_DW.obj_i.Index);

  /* Start for MATLABSystem: '<S3>/Encoder1' */
  Toma_De_Datos_DW.obj.Index = 0U;
  Toma_De_Datos_DW.obj.matlabCodegenIsDeleted = false;
  Toma_De_Datos_DW.obj.SampleTime = Toma_De_Datos_P.Encoder1_SampleTime;
  Toma_De_Datos_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &Toma_De_Datos_DW.obj.Index);
  Toma_De_Datos_DW.obj.isSetupComplete = true;
  Toma_De_Datos_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder1' */
  MW_EncoderReset(Toma_De_Datos_DW.obj.Index);

  /* Start for MATLABSystem: '<S4>/Adelante_der' */
  Toma_De_Datos_DW.obj_c.matlabCodegenIsDeleted = false;
  Toma_De_Datos_DW.obj_c.isInitialized = 1L;
  Toma_De_Datos_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0, 0.0);
  Toma_De_Datos_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Adelante_izq' */
  Toma_De_Datos_DW.obj_e.matlabCodegenIsDeleted = false;
  Toma_De_Datos_DW.obj_e.isInitialized = 1L;
  Toma_De_Datos_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  Toma_De_Datos_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_der' */
  Toma_De_Datos_DW.obj_g.matlabCodegenIsDeleted = false;
  Toma_De_Datos_DW.obj_g.isInitialized = 1L;
  Toma_De_Datos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  Toma_De_Datos_DW.obj_g.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_izq' */
  Toma_De_Datos_DW.obj_o.matlabCodegenIsDeleted = false;
  Toma_De_Datos_DW.obj_o.isInitialized = 1L;
  Toma_De_Datos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
  Toma_De_Datos_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output' */
  Toma_De_Datos_DW.obj_gs.matlabCodegenIsDeleted = false;
  Toma_De_Datos_DW.obj_gs.isInitialized = 1L;
  digitalIOSetup(8, 1);
  Toma_De_Datos_DW.obj_gs.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  Toma_De_Datos_DW.obj_oq.matlabCodegenIsDeleted = false;
  Toma_De_Datos_DW.obj_oq.isInitialized = 1L;
  digitalIOSetup(13, 1);
  Toma_De_Datos_DW.obj_oq.isSetupComplete = true;
}

/* Model terminate function */
void Toma_De_Datos_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!Toma_De_Datos_DW.obj_i.matlabCodegenIsDeleted) {
    Toma_De_Datos_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Toma_De_Datos_DW.obj_i.isInitialized == 1L) &&
        Toma_De_Datos_DW.obj_i.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */

  /* Terminate for MATLABSystem: '<S3>/Encoder1' */
  if (!Toma_De_Datos_DW.obj.matlabCodegenIsDeleted) {
    Toma_De_Datos_DW.obj.matlabCodegenIsDeleted = true;
    if ((Toma_De_Datos_DW.obj.isInitialized == 1L) &&
        Toma_De_Datos_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder1' */
  /* Terminate for MATLABSystem: '<S4>/Adelante_der' */
  if (!Toma_De_Datos_DW.obj_c.matlabCodegenIsDeleted) {
    Toma_De_Datos_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((Toma_De_Datos_DW.obj_c.isInitialized == 1L) &&
        Toma_De_Datos_DW.obj_c.isSetupComplete) {
      Toma_De_Datos_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle(Toma_De_Datos_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Toma_De_Datos_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_Close(Toma_De_Datos_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S4>/Adelante_izq' */
  if (!Toma_De_Datos_DW.obj_e.matlabCodegenIsDeleted) {
    Toma_De_Datos_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Toma_De_Datos_DW.obj_e.isInitialized == 1L) &&
        Toma_De_Datos_DW.obj_e.isSetupComplete) {
      Toma_De_Datos_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(Toma_De_Datos_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Toma_De_Datos_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(Toma_De_Datos_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S4>/Atras_der' */
  if (!Toma_De_Datos_DW.obj_g.matlabCodegenIsDeleted) {
    Toma_De_Datos_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Toma_De_Datos_DW.obj_g.isInitialized == 1L) &&
        Toma_De_Datos_DW.obj_g.isSetupComplete) {
      Toma_De_Datos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(Toma_De_Datos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Toma_De_Datos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(Toma_De_Datos_DW.obj_g.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_der' */

  /* Terminate for MATLABSystem: '<S4>/Atras_izq' */
  if (!Toma_De_Datos_DW.obj_o.matlabCodegenIsDeleted) {
    Toma_De_Datos_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Toma_De_Datos_DW.obj_o.isInitialized == 1L) &&
        Toma_De_Datos_DW.obj_o.isSetupComplete) {
      Toma_De_Datos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(Toma_De_Datos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Toma_De_Datos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(Toma_De_Datos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!Toma_De_Datos_DW.obj_gs.matlabCodegenIsDeleted) {
    Toma_De_Datos_DW.obj_gs.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!Toma_De_Datos_DW.obj_oq.matlabCodegenIsDeleted) {
    Toma_De_Datos_DW.obj_oq.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
