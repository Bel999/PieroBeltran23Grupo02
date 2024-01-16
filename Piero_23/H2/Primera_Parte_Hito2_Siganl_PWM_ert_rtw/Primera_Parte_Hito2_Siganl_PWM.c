/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Primera_Parte_Hito2_Siganl_PWM.c
 *
 * Code generated for Simulink model 'Primera_Parte_Hito2_Siganl_PWM'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Nov 14 17:25:37 2023
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

/* Model step function */
void Primera_Parte_Hito2_Siganl_PWM_step(void)
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

    /* Gain: '<S3>/Gain' */
    Gain_tmp = (real_T)Primera_Parte_Hito2_Siganl_PW_P.Gain_Gain *
      1.1368683772161603E-13;

    /* Gain: '<S3>/Gain' incorporates:
     *  MATLABSystem: '<S3>/Encoder'
     *  MATLABSystem: '<S3>/Encoder1'
     */
    Primera_Parte_Hito2_Siganl_PW_B.Gain[0] = Gain_tmp * (real_T)rtb_Encoder_0;
    Primera_Parte_Hito2_Siganl_PW_B.Gain[1] = Gain_tmp * (real_T)rtb_Encoder1_0;

    /* Derivative: '<S3>/Derivative' */
    Gain_tmp = Primera_Parte_Hito2_Siganl_P_M->Timing.t[0];
    if ((Primera_Parte_Hito2_Siganl_P_DW.TimeStampA >= Gain_tmp) &&
        (Primera_Parte_Hito2_Siganl_P_DW.TimeStampB >= Gain_tmp)) {
      /* Derivative: '<S3>/Derivative' */
      Primera_Parte_Hito2_Siganl_PW_B.Derivative[0] = 0.0;
      Primera_Parte_Hito2_Siganl_PW_B.Derivative[1] = 0.0;
    } else {
      lastTime_tmp = Primera_Parte_Hito2_Siganl_P_DW.TimeStampA;
      lastU = &Primera_Parte_Hito2_Siganl_P_DW.LastUAtTimeA;
      if (Primera_Parte_Hito2_Siganl_P_DW.TimeStampA <
          Primera_Parte_Hito2_Siganl_P_DW.TimeStampB) {
        if (Primera_Parte_Hito2_Siganl_P_DW.TimeStampB < Gain_tmp) {
          lastTime_tmp = Primera_Parte_Hito2_Siganl_P_DW.TimeStampB;
          lastU = &Primera_Parte_Hito2_Siganl_P_DW.LastUAtTimeB;
        }
      } else if (Primera_Parte_Hito2_Siganl_P_DW.TimeStampA >= Gain_tmp) {
        lastTime_tmp = Primera_Parte_Hito2_Siganl_P_DW.TimeStampB;
        lastU = &Primera_Parte_Hito2_Siganl_P_DW.LastUAtTimeB;
      }

      Gain_tmp -= lastTime_tmp;

      /* Derivative: '<S3>/Derivative' */
      Primera_Parte_Hito2_Siganl_PW_B.Derivative[0] =
        (Primera_Parte_Hito2_Siganl_PW_B.Gain[0] - (*lastU)[0]) / Gain_tmp;
      Primera_Parte_Hito2_Siganl_PW_B.Derivative[1] =
        (Primera_Parte_Hito2_Siganl_PW_B.Gain[1] - (*lastU)[1]) / Gain_tmp;
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
      if (t > pTimeValues[10]) {
        Primera_Parte_Hito2_Siganl_PW_B.PWM = 0.0;
      } else {
        /* Get index */
        if (t <= pTimeValues[0]) {
          currTimeIndex = 0;
        } else if (t >= pTimeValues[10]) {
          currTimeIndex = 9;
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
              Primera_Parte_Hito2_Siganl_PW_B.PWM = pDataValues[currTimeIndex];
            } else {
              Primera_Parte_Hito2_Siganl_PW_B.PWM = pDataValues[currTimeIndex +
                1];
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex = currTimeIndex;
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            Primera_Parte_Hito2_Siganl_PW_B.PWM = (real_T) rtInterpolate(d1, d2,
              f1, f2);
            pDataValues += 11;
          }
        }
      }
    }

    /* SignalConversion generated from: '<Root>/To Workspace' */
    Primera_Parte_Hito2_Siganl_PW_B.TmpSignalConversionAt_asyncqueu[0] =
      Primera_Parte_Hito2_Siganl_PW_B.PWM;
    Primera_Parte_Hito2_Siganl_PW_B.TmpSignalConversionAt_asyncqueu[1] =
      Primera_Parte_Hito2_Siganl_PW_B.PWM;
    Primera_Parte_Hito2_Siganl_PW_B.TmpSignalConversionAt_asyncqueu[2] =
      Primera_Parte_Hito2_Siganl_PW_B.Derivative[0];
    Primera_Parte_Hito2_Siganl_PW_B.TmpSignalConversionAt_asyncqueu[3] =
      Primera_Parte_Hito2_Siganl_PW_B.Derivative[1];

    /* DataTypeConversion: '<Root>/Data Type Conversion' */
    Gain_tmp = floor(Primera_Parte_Hito2_Siganl_PW_B.PWM);
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

    (*lastU)[0] = Primera_Parte_Hito2_Siganl_PW_B.Gain[0];
    (*lastU)[1] = Primera_Parte_Hito2_Siganl_PW_B.Gain[1];

    /* End of Update for Derivative: '<S3>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Primera_Parte_Hito2_Siganl_P_M->Timing.clockTick0 * 1) + 0)
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
      ((Primera_Parte_Hito2_Siganl_P_M->Timing.clockTick1 * 1) + 0)
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
  Primera_Parte_Hito2_Siganl_P_M->Timing.t[0] =
    ((time_T)(++Primera_Parte_Hito2_Siganl_P_M->Timing.clockTick0)) *
    Primera_Parte_Hito2_Siganl_P_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Primera_Parte_Hito2_Siganl_P_M->Timing.clockTick1++;
  }
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
  Primera_Parte_Hito2_Siganl_P_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Primera_Parte_Hito2_Siganl_P_M->Sizes.checksums[0] = (2705947128U);
  Primera_Parte_Hito2_Siganl_P_M->Sizes.checksums[1] = (3605625117U);
  Primera_Parte_Hito2_Siganl_P_M->Sizes.checksums[2] = (1823198613U);
  Primera_Parte_Hito2_Siganl_P_M->Sizes.checksums[3] = (3669085649U);

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

  /* Start for FromWorkspace: '<S1>/fromWS_Signal 1' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
      9.0, 10.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 127.5, 255.0, 127.5, 0.0, -127.5,
      -255.0, -127.5, 0.0, 0.0 } ;

    Primera_Parte_Hito2_Siganl_P_DW.fromWS_Signal1_PWORK.TimePtr = (void *)
      pTimeValues0;
    Primera_Parte_Hito2_Siganl_P_DW.fromWS_Signal1_PWORK.DataPtr = (void *)
      pDataValues0;
    Primera_Parte_Hito2_Siganl_P_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  Primera_Parte_Hito2_Siganl_P_DW.TimeStampA = (rtInf);
  Primera_Parte_Hito2_Siganl_P_DW.TimeStampB = (rtInf);

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
}

/* Model terminate function */
void Primera_Parte_Hito2_Siganl_PWM_terminate(void)
{
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
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
