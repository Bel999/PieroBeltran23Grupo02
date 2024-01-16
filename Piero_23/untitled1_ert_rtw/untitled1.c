/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.c
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Nov 14 19:52:17 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "untitled1_private.h"

/* Block states (default storage) */
DW_untitled1_T untitled1_DW;

/* Real-time model */
static RT_MODEL_untitled1_T untitled1_M_;
RT_MODEL_untitled1_T *const untitled1_M = &untitled1_M_;
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
void untitled1_step(void)
{
  real_T tmp_0;
  int32_T tmp;
  int16_T rtb_DataTypeConversion_idx_0;
  int16_T rtb_DataTypeConversion_idx_1;
  int16_T y;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   *  Lookup_n-D: '<S1>/CRDere1'
   *  Lookup_n-D: '<S1>/CRIzq1'
   */
  tmp_0 = floor(look1_binlxpw(untitled1_P.Constant_Value[0],
    untitled1_P.CRIzq1_bp01Data, untitled1_P.CRIzq1_tableData, 10UL));
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 65536.0);
  }

  rtb_DataTypeConversion_idx_0 = tmp_0 < 0.0 ? -(int16_T)(uint16_T)-tmp_0 :
    (int16_T)(uint16_T)tmp_0;
  tmp_0 = floor(look1_binlxpw(untitled1_P.Constant_Value[1],
    untitled1_P.CRDere1_bp01Data, untitled1_P.CRDere1_tableData, 10UL));
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 65536.0);
  }

  rtb_DataTypeConversion_idx_1 = tmp_0 < 0.0 ? -(int16_T)(uint16_T)-tmp_0 :
    (int16_T)(uint16_T)tmp_0;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* MATLABSystem: '<S4>/Adelante_der' */
  untitled1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

  /* Saturate: '<S4>/Saturation2' */
  if (rtb_DataTypeConversion_idx_1 > untitled1_P.Saturation2_UpperSat) {
    y = untitled1_P.Saturation2_UpperSat;
  } else if (rtb_DataTypeConversion_idx_1 < untitled1_P.Saturation2_LowerSat) {
    y = untitled1_P.Saturation2_LowerSat;
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
  MW_PWM_SetDutyCycle(untitled1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

  /* MATLABSystem: '<S4>/Adelante_izq' */
  untitled1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

  /* Saturate: '<S4>/Saturation4' */
  if (rtb_DataTypeConversion_idx_0 > untitled1_P.Saturation4_UpperSat) {
    y = untitled1_P.Saturation4_UpperSat;
  } else if (rtb_DataTypeConversion_idx_0 < untitled1_P.Saturation4_LowerSat) {
    y = untitled1_P.Saturation4_LowerSat;
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
  MW_PWM_SetDutyCycle(untitled1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

  /* MATLABSystem: '<S4>/Atras_der' */
  untitled1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

  /* Saturate: '<S4>/Saturation3' */
  if (rtb_DataTypeConversion_idx_1 > untitled1_P.Saturation3_UpperSat) {
    y = untitled1_P.Saturation3_UpperSat;
  } else if (rtb_DataTypeConversion_idx_1 < untitled1_P.Saturation3_LowerSat) {
    y = untitled1_P.Saturation3_LowerSat;
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
  MW_PWM_SetDutyCycle(untitled1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

  /* MATLABSystem: '<S4>/Atras_izq' */
  untitled1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

  /* Saturate: '<S4>/Saturation5' */
  if (rtb_DataTypeConversion_idx_0 > untitled1_P.Saturation5_UpperSat) {
    y = untitled1_P.Saturation5_UpperSat;
  } else if (rtb_DataTypeConversion_idx_0 < untitled1_P.Saturation5_LowerSat) {
    y = untitled1_P.Saturation5_LowerSat;
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
  MW_PWM_SetDutyCycle(untitled1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

  /* MATLABSystem: '<S4>/Digital Output' incorporates:
   *  Constant: '<S5>/Constant'
   *  RelationalOperator: '<S5>/Compare'
   */
  writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
    untitled1_P.Constant_Value_o));

  /* MATLABSystem: '<S4>/Digital Output1' incorporates:
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S6>/Compare'
   */
  writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
    untitled1_P.Constant_Value_h));

  /* MATLABSystem: '<S3>/Encoder' */
  if (untitled1_DW.obj_p.SampleTime != untitled1_P.Encoder_SampleTime) {
    untitled1_DW.obj_p.SampleTime = untitled1_P.Encoder_SampleTime;
  }

  if (untitled1_DW.obj_p.TunablePropsChanged) {
    untitled1_DW.obj_p.TunablePropsChanged = false;
  }

  MW_EncoderRead(untitled1_DW.obj_p.Index, &tmp);

  /* End of MATLABSystem: '<S3>/Encoder' */

  /* MATLABSystem: '<S3>/Encoder1' */
  if (untitled1_DW.obj.SampleTime != untitled1_P.Encoder1_SampleTime) {
    untitled1_DW.obj.SampleTime = untitled1_P.Encoder1_SampleTime;
  }

  if (untitled1_DW.obj.TunablePropsChanged) {
    untitled1_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(untitled1_DW.obj.Index, &tmp);

  /* End of MATLABSystem: '<S3>/Encoder1' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled1_M->Timing.t[0] =
    ((time_T)(++untitled1_M->Timing.clockTick0)) * untitled1_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    untitled1_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void untitled1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled1_M->solverInfo,
                          &untitled1_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled1_M->solverInfo, &rtmGetTPtr(untitled1_M));
    rtsiSetStepSizePtr(&untitled1_M->solverInfo, &untitled1_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled1_M->solverInfo, (&rtmGetErrorStatus
      (untitled1_M)));
    rtsiSetRTModelPtr(&untitled1_M->solverInfo, untitled1_M);
  }

  rtsiSetSimTimeStep(&untitled1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&untitled1_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(untitled1_M, &untitled1_M->Timing.tArray[0]);
  untitled1_M->Timing.stepSize0 = 0.1;

  /* Start for MATLABSystem: '<S4>/Adelante_der' */
  untitled1_DW.obj_k.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_k.isInitialized = 1L;
  untitled1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0, 0.0);
  untitled1_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Adelante_izq' */
  untitled1_DW.obj_c.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_c.isInitialized = 1L;
  untitled1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  untitled1_DW.obj_c.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_der' */
  untitled1_DW.obj_l.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_l.isInitialized = 1L;
  untitled1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  untitled1_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Atras_izq' */
  untitled1_DW.obj_m.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_m.isInitialized = 1L;
  untitled1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
  untitled1_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output' */
  untitled1_DW.obj_mx.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_mx.isInitialized = 1L;
  digitalIOSetup(8, 1);
  untitled1_DW.obj_mx.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/Digital Output1' */
  untitled1_DW.obj_o.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_o.isInitialized = 1L;
  digitalIOSetup(13, 1);
  untitled1_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Encoder' */
  untitled1_DW.obj_p.Index = 0U;
  untitled1_DW.obj_p.matlabCodegenIsDeleted = false;
  untitled1_DW.obj_p.SampleTime = untitled1_P.Encoder_SampleTime;
  untitled1_DW.obj_p.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &untitled1_DW.obj_p.Index);
  untitled1_DW.obj_p.isSetupComplete = true;
  untitled1_DW.obj_p.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder' */
  MW_EncoderReset(untitled1_DW.obj_p.Index);

  /* Start for MATLABSystem: '<S3>/Encoder1' */
  untitled1_DW.obj.Index = 0U;
  untitled1_DW.obj.matlabCodegenIsDeleted = false;
  untitled1_DW.obj.SampleTime = untitled1_P.Encoder1_SampleTime;
  untitled1_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &untitled1_DW.obj.Index);
  untitled1_DW.obj.isSetupComplete = true;
  untitled1_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S3>/Encoder1' */
  MW_EncoderReset(untitled1_DW.obj.Index);
}

/* Model terminate function */
void untitled1_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/Adelante_der' */
  if (!untitled1_DW.obj_k.matlabCodegenIsDeleted) {
    untitled1_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_k.isInitialized == 1L) &&
        untitled1_DW.obj_k.isSetupComplete) {
      untitled1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle(untitled1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      untitled1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_Close(untitled1_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S4>/Adelante_izq' */
  if (!untitled1_DW.obj_c.matlabCodegenIsDeleted) {
    untitled1_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_c.isInitialized == 1L) &&
        untitled1_DW.obj_c.isSetupComplete) {
      untitled1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(untitled1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      untitled1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(untitled1_DW.obj_c.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S4>/Atras_der' */
  if (!untitled1_DW.obj_l.matlabCodegenIsDeleted) {
    untitled1_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_l.isInitialized == 1L) &&
        untitled1_DW.obj_l.isSetupComplete) {
      untitled1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(untitled1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      untitled1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(untitled1_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_der' */

  /* Terminate for MATLABSystem: '<S4>/Atras_izq' */
  if (!untitled1_DW.obj_m.matlabCodegenIsDeleted) {
    untitled1_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_m.isInitialized == 1L) &&
        untitled1_DW.obj_m.isSetupComplete) {
      untitled1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(untitled1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      untitled1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(untitled1_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output' */
  if (!untitled1_DW.obj_mx.matlabCodegenIsDeleted) {
    untitled1_DW.obj_mx.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output' */

  /* Terminate for MATLABSystem: '<S4>/Digital Output1' */
  if (!untitled1_DW.obj_o.matlabCodegenIsDeleted) {
    untitled1_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Output1' */

  /* Terminate for MATLABSystem: '<S3>/Encoder' */
  if (!untitled1_DW.obj_p.matlabCodegenIsDeleted) {
    untitled1_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj_p.isInitialized == 1L) &&
        untitled1_DW.obj_p.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Encoder' */

  /* Terminate for MATLABSystem: '<S3>/Encoder1' */
  if (!untitled1_DW.obj.matlabCodegenIsDeleted) {
    untitled1_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled1_DW.obj.isInitialized == 1L) &&
        untitled1_DW.obj.isSetupComplete) {
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
