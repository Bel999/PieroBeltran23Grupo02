/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Dec 17 23:26:18 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "untitled_private.h"

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  /* local block i/o variables */
  real_T rtb_IntegralGain;
  real_T rtb_IntegralGain_m;

  {
    real_T (*lastU)[2];
    real_T rtb_error_idx_0;
    real_T rtb_error_idx_1;
    real_T u0;
    int16_T rtb_DataTypeConversion_idx_0;
    int16_T rtb_DataTypeConversion_idx_1;
    int16_T y;

    /* MATLABSystem: '<S102>/Encoder' */
    if (untitled_DW.obj_k.SampleTime != untitled_P.Encoder_SampleTime) {
      untitled_DW.obj_k.SampleTime = untitled_P.Encoder_SampleTime;
    }

    if (untitled_DW.obj_k.TunablePropsChanged) {
      untitled_DW.obj_k.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S102>/Encoder' */
    MW_EncoderRead(untitled_DW.obj_k.Index, &untitled_B.Encoder);

    /* MATLABSystem: '<S102>/Encoder1' */
    if (untitled_DW.obj.SampleTime != untitled_P.Encoder1_SampleTime) {
      untitled_DW.obj.SampleTime = untitled_P.Encoder1_SampleTime;
    }

    if (untitled_DW.obj.TunablePropsChanged) {
      untitled_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S102>/Encoder1' */
    MW_EncoderRead(untitled_DW.obj.Index, &untitled_B.Encoder1);

    /* Gain: '<S102>/Gain' */
    rtb_error_idx_0 = (real_T)untitled_P.Gain_Gain * 1.1368683772161603E-13;

    /* Gain: '<S102>/Gain' incorporates:
     *  SignalConversion generated from: '<S102>/Gain'
     */
    untitled_B.Gain[0] = rtb_error_idx_0 * (real_T)untitled_B.Encoder;
    untitled_B.Gain[1] = rtb_error_idx_0 * (real_T)untitled_B.Encoder1;

    /* Derivative: '<S102>/Derivative' */
    u0 = untitled_M->Timing.t[0];
    if ((untitled_DW.TimeStampA >= u0) && (untitled_DW.TimeStampB >= u0)) {
      /* Derivative: '<S102>/Derivative' */
      untitled_B.Derivative[0] = 0.0;
      untitled_B.Derivative[1] = 0.0;
    } else {
      rtb_error_idx_0 = untitled_DW.TimeStampA;
      lastU = &untitled_DW.LastUAtTimeA;
      if (untitled_DW.TimeStampA < untitled_DW.TimeStampB) {
        if (untitled_DW.TimeStampB < u0) {
          rtb_error_idx_0 = untitled_DW.TimeStampB;
          lastU = &untitled_DW.LastUAtTimeB;
        }
      } else if (untitled_DW.TimeStampA >= u0) {
        rtb_error_idx_0 = untitled_DW.TimeStampB;
        lastU = &untitled_DW.LastUAtTimeB;
      }

      rtb_error_idx_0 = u0 - rtb_error_idx_0;

      /* Derivative: '<S102>/Derivative' */
      untitled_B.Derivative[0] = (untitled_B.Gain[0] - (*lastU)[0]) /
        rtb_error_idx_0;
      untitled_B.Derivative[1] = (untitled_B.Gain[1] - (*lastU)[1]) /
        rtb_error_idx_0;
    }

    /* End of Derivative: '<S102>/Derivative' */
    /* SignalConversion generated from: '<S102>/Mux' */
    untitled_B.TmpSignalConversionAtTAQSigLogg[0] = untitled_B.Encoder;
    untitled_B.TmpSignalConversionAtTAQSigLogg[1] = untitled_B.Encoder1;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Memory: '<Root>/Memory1'
     */
    rtb_error_idx_0 = untitled_P.Constant1_Value[0] -
      untitled_DW.Memory1_PreviousInput[0];
    rtb_error_idx_1 = untitled_P.Constant1_Value[1] -
      untitled_DW.Memory1_PreviousInput[1];

    /* Sum: '<S93>/Sum' incorporates:
     *  DiscreteIntegrator: '<S84>/Integrator'
     *  Gain: '<S89>/Proportional Gain'
     */
    u0 = untitled_P.PIDController2_P * rtb_error_idx_0 +
      untitled_DW.Integrator_DSTATE_c;

    /* Saturate: '<S91>/Saturation' */
    if (u0 > untitled_P.PIDController2_UpperSaturationL) {
      u0 = untitled_P.PIDController2_UpperSaturationL;
    } else if (u0 < untitled_P.PIDController2_LowerSaturationL) {
      u0 = untitled_P.PIDController2_LowerSaturationL;
    }

    /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
     *  Saturate: '<S91>/Saturation'
     */
    u0 = floor(u0);
    if (rtIsNaN(u0) || rtIsInf(u0)) {
      u0 = 0.0;
    } else {
      u0 = fmod(u0, 65536.0);
    }

    rtb_DataTypeConversion_idx_0 = u0 < 0.0 ? -(int16_T)(uint16_T)-u0 : (int16_T)
      (uint16_T)u0;

    /* Sum: '<S45>/Sum' incorporates:
     *  DiscreteIntegrator: '<S36>/Integrator'
     *  Gain: '<S41>/Proportional Gain'
     */
    u0 = untitled_P.PIDController1_P * rtb_error_idx_1 +
      untitled_DW.Integrator_DSTATE;

    /* Saturate: '<S43>/Saturation' */
    if (u0 > untitled_P.PIDController1_UpperSaturationL) {
      u0 = untitled_P.PIDController1_UpperSaturationL;
    } else if (u0 < untitled_P.PIDController1_LowerSaturationL) {
      u0 = untitled_P.PIDController1_LowerSaturationL;
    }

    /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
     *  Saturate: '<S43>/Saturation'
     */
    u0 = floor(u0);
    if (rtIsNaN(u0) || rtIsInf(u0)) {
      u0 = 0.0;
    } else {
      u0 = fmod(u0, 65536.0);
    }

    rtb_DataTypeConversion_idx_1 = u0 < 0.0 ? -(int16_T)(uint16_T)-u0 : (int16_T)
      (uint16_T)u0;

    /* MATLABSystem: '<S103>/Adelante_der' */
    untitled_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

    /* Saturate: '<S103>/Saturation2' */
    if (rtb_DataTypeConversion_idx_1 > untitled_P.Saturation2_UpperSat) {
      y = untitled_P.Saturation2_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 < untitled_P.Saturation2_LowerSat) {
      y = untitled_P.Saturation2_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
    }

    /* End of Saturate: '<S103>/Saturation2' */

    /* Start for MATLABSystem: '<S103>/Adelante_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S103>/Adelante_der' */
    MW_PWM_SetDutyCycle(untitled_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

    /* MATLABSystem: '<S103>/Adelante_izq' */
    untitled_DW.obj_kh.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* Saturate: '<S103>/Saturation4' */
    if (rtb_DataTypeConversion_idx_0 > untitled_P.Saturation4_UpperSat) {
      y = untitled_P.Saturation4_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 < untitled_P.Saturation4_LowerSat) {
      y = untitled_P.Saturation4_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_0;
    }

    /* End of Saturate: '<S103>/Saturation4' */

    /* Abs: '<S103>/Abs2' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S103>/Abs2' */

    /* Start for MATLABSystem: '<S103>/Adelante_izq' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S103>/Adelante_izq' */
    MW_PWM_SetDutyCycle(untitled_DW.obj_kh.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

    /* MATLABSystem: '<S103>/Atras_der' */
    untitled_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* Saturate: '<S103>/Saturation3' */
    if (rtb_DataTypeConversion_idx_1 > untitled_P.Saturation3_UpperSat) {
      y = untitled_P.Saturation3_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 < untitled_P.Saturation3_LowerSat) {
      y = untitled_P.Saturation3_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
    }

    /* End of Saturate: '<S103>/Saturation3' */

    /* Abs: '<S103>/Abs1' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S103>/Abs1' */

    /* Start for MATLABSystem: '<S103>/Atras_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S103>/Atras_der' */
    MW_PWM_SetDutyCycle(untitled_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

    /* MATLABSystem: '<S103>/Atras_izq' */
    untitled_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Saturate: '<S103>/Saturation5' */
    if (rtb_DataTypeConversion_idx_0 > untitled_P.Saturation5_UpperSat) {
      y = untitled_P.Saturation5_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 < untitled_P.Saturation5_LowerSat) {
      y = untitled_P.Saturation5_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_0;
    }

    /* End of Saturate: '<S103>/Saturation5' */

    /* Start for MATLABSystem: '<S103>/Atras_izq' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S103>/Atras_izq' */
    MW_PWM_SetDutyCycle(untitled_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

    /* MATLABSystem: '<S103>/Digital Output' incorporates:
     *  Constant: '<S104>/Constant'
     *  RelationalOperator: '<S104>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
      untitled_P.Constant_Value));

    /* MATLABSystem: '<S103>/Digital Output1' incorporates:
     *  Constant: '<S105>/Constant'
     *  RelationalOperator: '<S105>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
      untitled_P.Constant_Value_h));

    /* Gain: '<S33>/Integral Gain' */
    rtb_IntegralGain = untitled_P.PIDController1_I * rtb_error_idx_1;

    /* Gain: '<S81>/Integral Gain' */
    rtb_IntegralGain_m = untitled_P.PIDController2_I * rtb_error_idx_0;
  }

  {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S102>/Derivative' */
    if (untitled_DW.TimeStampA == (rtInf)) {
      untitled_DW.TimeStampA = untitled_M->Timing.t[0];
      lastU = &untitled_DW.LastUAtTimeA;
    } else if (untitled_DW.TimeStampB == (rtInf)) {
      untitled_DW.TimeStampB = untitled_M->Timing.t[0];
      lastU = &untitled_DW.LastUAtTimeB;
    } else if (untitled_DW.TimeStampA < untitled_DW.TimeStampB) {
      untitled_DW.TimeStampA = untitled_M->Timing.t[0];
      lastU = &untitled_DW.LastUAtTimeA;
    } else {
      untitled_DW.TimeStampB = untitled_M->Timing.t[0];
      lastU = &untitled_DW.LastUAtTimeB;
    }

    (*lastU)[0] = untitled_B.Gain[0];

    /* Update for Memory: '<Root>/Memory1' */
    untitled_DW.Memory1_PreviousInput[0] = untitled_B.Derivative[0];

    /* Update for Derivative: '<S102>/Derivative' */
    (*lastU)[1] = untitled_B.Gain[1];

    /* Update for Memory: '<Root>/Memory1' */
    untitled_DW.Memory1_PreviousInput[1] = untitled_B.Derivative[1];

    /* Update for DiscreteIntegrator: '<S36>/Integrator' */
    untitled_DW.Integrator_DSTATE += untitled_P.Integrator_gainval *
      rtb_IntegralGain;

    /* Update for DiscreteIntegrator: '<S84>/Integrator' */
    untitled_DW.Integrator_DSTATE_c += untitled_P.Integrator_gainval_k *
      rtb_IntegralGain_m;
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((untitled_M->Timing.clockTick0 * 1) + 0)
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
      ((untitled_M->Timing.clockTick1 * 1) + 0)
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
  untitled_M->Timing.t[0] =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    untitled_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&untitled_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (3166988329U);
  untitled_M->Sizes.checksums[1] = (1452294632U);
  untitled_M->Sizes.checksums[2] = (1041187284U);
  untitled_M->Sizes.checksums[3] = (2730893273U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* InitializeConditions for Derivative: '<S102>/Derivative' */
  untitled_DW.TimeStampA = (rtInf);
  untitled_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Memory: '<Root>/Memory1' */
  untitled_DW.Memory1_PreviousInput[0] = untitled_P.Memory1_InitialCondition;
  untitled_DW.Memory1_PreviousInput[1] = untitled_P.Memory1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S36>/Integrator' */
  untitled_DW.Integrator_DSTATE = untitled_P.PIDController1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S84>/Integrator' */
  untitled_DW.Integrator_DSTATE_c = untitled_P.PIDController2_InitialCondition;

  /* Start for MATLABSystem: '<S102>/Encoder' */
  untitled_DW.obj_k.Index = 0U;
  untitled_DW.obj_k.matlabCodegenIsDeleted = false;
  untitled_DW.obj_k.SampleTime = untitled_P.Encoder_SampleTime;
  untitled_DW.obj_k.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &untitled_DW.obj_k.Index);
  untitled_DW.obj_k.isSetupComplete = true;
  untitled_DW.obj_k.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S102>/Encoder' */
  MW_EncoderReset(untitled_DW.obj_k.Index);

  /* Start for MATLABSystem: '<S102>/Encoder1' */
  untitled_DW.obj.Index = 0U;
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.SampleTime = untitled_P.Encoder1_SampleTime;
  untitled_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &untitled_DW.obj.Index);
  untitled_DW.obj.isSetupComplete = true;
  untitled_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S102>/Encoder1' */
  MW_EncoderReset(untitled_DW.obj.Index);

  /* Start for MATLABSystem: '<S103>/Adelante_der' */
  untitled_DW.obj_f.matlabCodegenIsDeleted = false;
  untitled_DW.obj_f.isInitialized = 1L;
  untitled_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0, 0.0);
  untitled_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Adelante_izq' */
  untitled_DW.obj_kh.matlabCodegenIsDeleted = false;
  untitled_DW.obj_kh.isInitialized = 1L;
  untitled_DW.obj_kh.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  untitled_DW.obj_kh.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Atras_der' */
  untitled_DW.obj_j.matlabCodegenIsDeleted = false;
  untitled_DW.obj_j.isInitialized = 1L;
  untitled_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0, 0.0);
  untitled_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Atras_izq' */
  untitled_DW.obj_o.matlabCodegenIsDeleted = false;
  untitled_DW.obj_o.isInitialized = 1L;
  untitled_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
  untitled_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Digital Output' */
  untitled_DW.obj_b.matlabCodegenIsDeleted = false;
  untitled_DW.obj_b.isInitialized = 1L;
  digitalIOSetup(8, 1);
  untitled_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S103>/Digital Output1' */
  untitled_DW.obj_n.matlabCodegenIsDeleted = false;
  untitled_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(13, 1);
  untitled_DW.obj_n.isSetupComplete = true;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Terminate for MATLABSystem: '<S102>/Encoder' */
  if (!untitled_DW.obj_k.matlabCodegenIsDeleted) {
    untitled_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_k.isInitialized == 1L) &&
        untitled_DW.obj_k.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S102>/Encoder' */

  /* Terminate for MATLABSystem: '<S102>/Encoder1' */
  if (!untitled_DW.obj.matlabCodegenIsDeleted) {
    untitled_DW.obj.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj.isInitialized == 1L) && untitled_DW.obj.isSetupComplete)
    {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S102>/Encoder1' */
  /* Terminate for MATLABSystem: '<S103>/Adelante_der' */
  if (!untitled_DW.obj_f.matlabCodegenIsDeleted) {
    untitled_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_f.isInitialized == 1L) &&
        untitled_DW.obj_f.isSetupComplete) {
      untitled_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle(untitled_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      untitled_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_Close(untitled_DW.obj_f.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S103>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S103>/Adelante_izq' */
  if (!untitled_DW.obj_kh.matlabCodegenIsDeleted) {
    untitled_DW.obj_kh.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_kh.isInitialized == 1L) &&
        untitled_DW.obj_kh.isSetupComplete) {
      untitled_DW.obj_kh.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(untitled_DW.obj_kh.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      untitled_DW.obj_kh.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(untitled_DW.obj_kh.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S103>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S103>/Atras_der' */
  if (!untitled_DW.obj_j.matlabCodegenIsDeleted) {
    untitled_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_j.isInitialized == 1L) &&
        untitled_DW.obj_j.isSetupComplete) {
      untitled_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(untitled_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      untitled_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(untitled_DW.obj_j.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S103>/Atras_der' */

  /* Terminate for MATLABSystem: '<S103>/Atras_izq' */
  if (!untitled_DW.obj_o.matlabCodegenIsDeleted) {
    untitled_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((untitled_DW.obj_o.isInitialized == 1L) &&
        untitled_DW.obj_o.isSetupComplete) {
      untitled_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(untitled_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      untitled_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(untitled_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S103>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S103>/Digital Output' */
  if (!untitled_DW.obj_b.matlabCodegenIsDeleted) {
    untitled_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S103>/Digital Output' */

  /* Terminate for MATLABSystem: '<S103>/Digital Output1' */
  if (!untitled_DW.obj_n.matlabCodegenIsDeleted) {
    untitled_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S103>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
