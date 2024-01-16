/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controlBA.c
 *
 * Code generated for Simulink model 'controlBA'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Nov 15 00:58:52 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controlBA.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "controlBA_private.h"

/* Block signals (default storage) */
B_controlBA_T controlBA_B;

/* Block states (default storage) */
DW_controlBA_T controlBA_DW;

/* Real-time model */
static RT_MODEL_controlBA_T controlBA_M_;
RT_MODEL_controlBA_T *const controlBA_M = &controlBA_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1UL;
    frac = (u0 - bp0[maxIndex - 1UL]) / (bp0[maxIndex] - bp0[maxIndex - 1UL]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1UL] - yL_0d0) * frac + yL_0d0;
}

/* Model step function */
void controlBA_step(void)
{
  {
    real_T (*lastU)[2];
    real_T Gain_tmp;
    real_T lastTime;
    int32_T rtb_Saturation3;
    int32_T tmp;
    int16_T rtb_DataTypeConversion_idx_0;
    int16_T y;

    /* Constant: '<Root>/Constant' */
    controlBA_B.Constant[0] = controlBA_P.Constant_Value[0];
    controlBA_B.Constant[1] = controlBA_P.Constant_Value[1];

    /* MATLABSystem: '<S3>/Encoder' */
    if (controlBA_DW.obj_p.SampleTime != controlBA_P.Encoder_SampleTime) {
      controlBA_DW.obj_p.SampleTime = controlBA_P.Encoder_SampleTime;
    }

    if (controlBA_DW.obj_p.TunablePropsChanged) {
      controlBA_DW.obj_p.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S3>/Encoder' */
    MW_EncoderRead(controlBA_DW.obj_p.Index, &controlBA_B.Encoder);

    /* MATLABSystem: '<S3>/Encoder1' */
    if (controlBA_DW.obj.SampleTime != controlBA_P.Encoder1_SampleTime) {
      controlBA_DW.obj.SampleTime = controlBA_P.Encoder1_SampleTime;
    }

    if (controlBA_DW.obj.TunablePropsChanged) {
      controlBA_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S3>/Encoder1' */
    MW_EncoderRead(controlBA_DW.obj.Index, &controlBA_B.Encoder1);

    /* Gain: '<S3>/Gain' */
    Gain_tmp = (real_T)controlBA_P.Gain_Gain * 1.1368683772161603E-13;

    /* Gain: '<S3>/Gain' incorporates:
     *  SignalConversion generated from: '<S3>/Gain'
     */
    controlBA_B.Gain[0] = Gain_tmp * (real_T)controlBA_B.Encoder;
    controlBA_B.Gain[1] = Gain_tmp * (real_T)controlBA_B.Encoder1;

    /* Derivative: '<S3>/Derivative' */
    Gain_tmp = controlBA_M->Timing.t[0];
    if ((controlBA_DW.TimeStampA >= Gain_tmp) && (controlBA_DW.TimeStampB >=
         Gain_tmp)) {
      /* Derivative: '<S3>/Derivative' */
      controlBA_B.Derivative[0] = 0.0;
      controlBA_B.Derivative[1] = 0.0;
    } else {
      lastTime = controlBA_DW.TimeStampA;
      lastU = &controlBA_DW.LastUAtTimeA;
      if (controlBA_DW.TimeStampA < controlBA_DW.TimeStampB) {
        if (controlBA_DW.TimeStampB < Gain_tmp) {
          lastTime = controlBA_DW.TimeStampB;
          lastU = &controlBA_DW.LastUAtTimeB;
        }
      } else if (controlBA_DW.TimeStampA >= Gain_tmp) {
        lastTime = controlBA_DW.TimeStampB;
        lastU = &controlBA_DW.LastUAtTimeB;
      }

      Gain_tmp -= lastTime;

      /* Derivative: '<S3>/Derivative' */
      controlBA_B.Derivative[0] = (controlBA_B.Gain[0] - (*lastU)[0]) / Gain_tmp;
      controlBA_B.Derivative[1] = (controlBA_B.Gain[1] - (*lastU)[1]) / Gain_tmp;
    }

    /* End of Derivative: '<S3>/Derivative' */
    /* SignalConversion generated from: '<S3>/Mux' */
    controlBA_B.TmpSignalConversionAtTAQSigLogg[0] = controlBA_B.Encoder;
    controlBA_B.TmpSignalConversionAtTAQSigLogg[1] = controlBA_B.Encoder1;

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Lookup_n-D: '<S1>/CRDere1'
     *  Lookup_n-D: '<S1>/CRIzq1'
     */
    Gain_tmp = floor(look1_binlxpw(controlBA_B.Constant[0],
      controlBA_P.CRIzq1_bp01Data, controlBA_P.CRIzq1_tableData, 10UL));
    if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
      Gain_tmp = 0.0;
    } else {
      Gain_tmp = fmod(Gain_tmp, 65536.0);
    }

    rtb_DataTypeConversion_idx_0 = Gain_tmp < 0.0 ? -(int16_T)(uint16_T)
      -Gain_tmp : (int16_T)(uint16_T)Gain_tmp;
    Gain_tmp = floor(look1_binlxpw(controlBA_B.Constant[1],
      controlBA_P.CRDere1_bp01Data, controlBA_P.CRDere1_tableData, 10UL));
    if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
      Gain_tmp = 0.0;
    } else {
      Gain_tmp = fmod(Gain_tmp, 65536.0);
    }

    /* Gain: '<S4>/Gain' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Saturate: '<S4>/Saturation3'
     */
    rtb_Saturation3 = (int32_T)(Gain_tmp < 0.0 ? -(int16_T)(uint16_T)-Gain_tmp :
      (int16_T)(uint16_T)Gain_tmp) * controlBA_P.Gain_Gain_i;

    /* MATLABSystem: '<S4>/Digital Output1' incorporates:
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S6>/Compare'
     *  Saturate: '<S4>/Saturation3'
     */
    writeDigitalPin(13, (uint8_T)(rtb_Saturation3 !=
      controlBA_P.Constant_Value_h));

    /* MATLABSystem: '<S4>/Adelante_der' */
    controlBA_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

    /* Saturate: '<S4>/Saturation2' incorporates:
     *  Saturate: '<S4>/Saturation3'
     */
    if (rtb_Saturation3 > controlBA_P.Saturation2_UpperSat) {
      tmp = controlBA_P.Saturation2_UpperSat;
    } else if (rtb_Saturation3 < controlBA_P.Saturation2_LowerSat) {
      tmp = controlBA_P.Saturation2_LowerSat;
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
    MW_PWM_SetDutyCycle(controlBA_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, Gain_tmp);

    /* Saturate: '<S4>/Saturation3' */
    if (rtb_Saturation3 > controlBA_P.Saturation3_UpperSat) {
      rtb_Saturation3 = controlBA_P.Saturation3_UpperSat;
    } else if (rtb_Saturation3 < controlBA_P.Saturation3_LowerSat) {
      rtb_Saturation3 = controlBA_P.Saturation3_LowerSat;
    }

    /* End of Saturate: '<S4>/Saturation3' */

    /* MATLABSystem: '<S4>/Atras_der' */
    controlBA_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

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
    MW_PWM_SetDutyCycle(controlBA_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, Gain_tmp);

    /* MATLABSystem: '<S4>/Adelante_izq' */
    controlBA_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* Saturate: '<S4>/Saturation4' */
    if (rtb_DataTypeConversion_idx_0 > controlBA_P.Saturation4_UpperSat) {
      y = controlBA_P.Saturation4_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 < controlBA_P.Saturation4_LowerSat)
    {
      y = controlBA_P.Saturation4_LowerSat;
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
    MW_PWM_SetDutyCycle(controlBA_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

    /* MATLABSystem: '<S4>/Atras_izq' */
    controlBA_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Saturate: '<S4>/Saturation5' */
    if (rtb_DataTypeConversion_idx_0 > controlBA_P.Saturation5_UpperSat) {
      y = controlBA_P.Saturation5_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 < controlBA_P.Saturation5_LowerSat)
    {
      y = controlBA_P.Saturation5_LowerSat;
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
    MW_PWM_SetDutyCycle(controlBA_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

    /* MATLABSystem: '<S4>/Digital Output' incorporates:
     *  Constant: '<S5>/Constant'
     *  RelationalOperator: '<S5>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
      controlBA_P.Constant_Value_o));
  }

  {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S3>/Derivative' */
    if (controlBA_DW.TimeStampA == (rtInf)) {
      controlBA_DW.TimeStampA = controlBA_M->Timing.t[0];
      lastU = &controlBA_DW.LastUAtTimeA;
    } else if (controlBA_DW.TimeStampB == (rtInf)) {
      controlBA_DW.TimeStampB = controlBA_M->Timing.t[0];
      lastU = &controlBA_DW.LastUAtTimeB;
    } else if (controlBA_DW.TimeStampA < controlBA_DW.TimeStampB) {
      controlBA_DW.TimeStampA = controlBA_M->Timing.t[0];
      lastU = &controlBA_DW.LastUAtTimeA;
    } else {
      controlBA_DW.TimeStampB = controlBA_M->Timing.t[0];
      lastU = &controlBA_DW.LastUAtTimeB;
    }

    (*lastU)[0] = controlBA_B.Gain[0];
    (*lastU)[1] = controlBA_B.Gain[1];

    /* End of Update for Derivative: '<S3>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((controlBA_M->Timing.clockTick0 * 1) + 0)
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
      ((controlBA_M->Timing.clockTick1 * 1) + 0)
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
  controlBA_M->Timing.t[0] =
    ((time_T)(++controlBA_M->Timing.clockTick0)) * controlBA_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    controlBA_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void controlBA_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&controlBA_M->solverInfo,
                          &controlBA_M->Timing.simTimeStep);
    rtsiSetTPtr(&controlBA_M->solverInfo, &rtmGetTPtr(controlBA_M));
    rtsiSetStepSizePtr(&controlBA_M->solverInfo, &controlBA_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&controlBA_M->solverInfo, (&rtmGetErrorStatus
      (controlBA_M)));
    rtsiSetRTModelPtr(&controlBA_M->solverInfo, controlBA_M);
  }

  rtsiSetSimTimeStep(&controlBA_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&controlBA_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(controlBA_M, &controlBA_M->Timing.tArray[0]);
  rtmSetTFinal(controlBA_M, 5.0);
  controlBA_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  controlBA_M->Sizes.checksums[0] = (418177125U);
  controlBA_M->Sizes.checksums[1] = (2992586423U);
  controlBA_M->Sizes.checksums[2] = (568559038U);
  controlBA_M->Sizes.checksums[3] = (1283664804U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    controlBA_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(controlBA_M->extModeInfo,
      &controlBA_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(controlBA_M->extModeInfo, controlBA_M->Sizes.checksums);
    rteiSetTPtr(controlBA_M->extModeInfo, rtmGetTPtr(controlBA_M));
  }

  /* InitializeConditions for Derivative: '<S3>/Derivative' */
  controlBA_DW.TimeStampA = (rtInf);
  controlBA_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<S3>/Encoder' */
  controlBA_DW.obj_p.Index = 0U;
  controlBA_DW.obj_p.matlabCodegenIsDeleted = false;
  controlBA_DW.obj_p.SampleTime = controlBA_P.Encoder_SampleTime;
  controlBA_DW.obj_p.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &controlBA_DW.obj_p.Index);
  controlBA_DW.obj_p.isSetupComplete = true;
  controlBA_DW.obj_p.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
  MW_EncoderReset(controlBA_DW.obj_p.Index);

  /* Start for MATLABSystem: '<S3>/Encoder1' */
  controlBA_DW.obj.Index = 0U;
  controlBA_DW.obj.matlabCodegenIsDeleted = false;
  controlBA_DW.obj.SampleTime = controlBA_P.Encoder1_SampleTime;
  controlBA_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &controlBA_DW.obj.Index);
  controlBA_DW.obj.isSetupComplete = true;
  controlBA_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder1' */
  MW_EncoderReset(controlBA_DW.obj.Index);

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  controlBA_DW.obj_o.matlabCodegenIsDeleted = false;
  controlBA_DW.obj_o.isInitialized = 1L;
  digitalIOSetup(13, 1);
  controlBA_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Adelante_der' */
  controlBA_DW.obj_k.matlabCodegenIsDeleted = false;
  controlBA_DW.obj_k.isInitialized = 1L;
  controlBA_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0, 0.0);
  controlBA_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_der' */
  controlBA_DW.obj_l.matlabCodegenIsDeleted = false;
  controlBA_DW.obj_l.isInitialized = 1L;
  controlBA_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  controlBA_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Adelante_izq' */
  controlBA_DW.obj_c.matlabCodegenIsDeleted = false;
  controlBA_DW.obj_c.isInitialized = 1L;
  controlBA_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  controlBA_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_izq' */
  controlBA_DW.obj_m.matlabCodegenIsDeleted = false;
  controlBA_DW.obj_m.isInitialized = 1L;
  controlBA_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
  controlBA_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output' */
  controlBA_DW.obj_mx.matlabCodegenIsDeleted = false;
  controlBA_DW.obj_mx.isInitialized = 1L;
  digitalIOSetup(8, 1);
  controlBA_DW.obj_mx.isSetupComplete = true;
}

/* Model terminate function */
void controlBA_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!controlBA_DW.obj_p.matlabCodegenIsDeleted) {
    controlBA_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((controlBA_DW.obj_p.isInitialized == 1L) &&
        controlBA_DW.obj_p.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */

  /* Terminate for MATLABSystem: '<S3>/Encoder1' */
  if (!controlBA_DW.obj.matlabCodegenIsDeleted) {
    controlBA_DW.obj.matlabCodegenIsDeleted = true;
    if ((controlBA_DW.obj.isInitialized == 1L) &&
        controlBA_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder1' */
  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!controlBA_DW.obj_o.matlabCodegenIsDeleted) {
    controlBA_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S4>/Adelante_der' */
  if (!controlBA_DW.obj_k.matlabCodegenIsDeleted) {
    controlBA_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((controlBA_DW.obj_k.isInitialized == 1L) &&
        controlBA_DW.obj_k.isSetupComplete) {
      controlBA_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle(controlBA_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      controlBA_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_Close(controlBA_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S4>/Atras_der' */
  if (!controlBA_DW.obj_l.matlabCodegenIsDeleted) {
    controlBA_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((controlBA_DW.obj_l.isInitialized == 1L) &&
        controlBA_DW.obj_l.isSetupComplete) {
      controlBA_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(controlBA_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      controlBA_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(controlBA_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_der' */

  /* Terminate for MATLABSystem: '<S4>/Adelante_izq' */
  if (!controlBA_DW.obj_c.matlabCodegenIsDeleted) {
    controlBA_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((controlBA_DW.obj_c.isInitialized == 1L) &&
        controlBA_DW.obj_c.isSetupComplete) {
      controlBA_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(controlBA_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      controlBA_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(controlBA_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S4>/Atras_izq' */
  if (!controlBA_DW.obj_m.matlabCodegenIsDeleted) {
    controlBA_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((controlBA_DW.obj_m.isInitialized == 1L) &&
        controlBA_DW.obj_m.isSetupComplete) {
      controlBA_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(controlBA_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      controlBA_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(controlBA_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!controlBA_DW.obj_mx.matlabCodegenIsDeleted) {
    controlBA_DW.obj_mx.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
