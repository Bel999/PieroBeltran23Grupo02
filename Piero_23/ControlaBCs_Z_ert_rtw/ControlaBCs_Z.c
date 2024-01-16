/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlaBCs_Z.c
 *
 * Code generated for Simulink model 'ControlaBCs_Z'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Dec 18 00:08:39 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ControlaBCs_Z.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "ControlaBCs_Z_private.h"

/* Block signals (default storage) */
B_ControlaBCs_Z_T ControlaBCs_Z_B;

/* Block states (default storage) */
DW_ControlaBCs_Z_T ControlaBCs_Z_DW;

/* Real-time model */
static RT_MODEL_ControlaBCs_Z_T ControlaBCs_Z_M_;
RT_MODEL_ControlaBCs_Z_T *const ControlaBCs_Z_M = &ControlaBCs_Z_M_;

/* Model step function */
void ControlaBCs_Z_step(void)
{
  /* local block i/o variables */
  real_T rtb_IntegralGain;
  real_T rtb_IntegralGain_e;

  {
    real_T (*lastU)[2];
    real_T rtb_error_idx_0;
    real_T rtb_error_idx_1;
    real_T u0;
    int16_T rtb_DataTypeConversion_idx_0;
    int16_T rtb_DataTypeConversion_idx_1;
    int16_T y;

    /* MATLABSystem: '<S4>/Encoder' */
    if (ControlaBCs_Z_DW.obj_e.SampleTime != ControlaBCs_Z_P.Encoder_SampleTime)
    {
      ControlaBCs_Z_DW.obj_e.SampleTime = ControlaBCs_Z_P.Encoder_SampleTime;
    }

    if (ControlaBCs_Z_DW.obj_e.TunablePropsChanged) {
      ControlaBCs_Z_DW.obj_e.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S4>/Encoder' */
    MW_EncoderRead(ControlaBCs_Z_DW.obj_e.Index, &ControlaBCs_Z_B.Encoder);

    /* MATLABSystem: '<S4>/Encoder1' */
    if (ControlaBCs_Z_DW.obj.SampleTime != ControlaBCs_Z_P.Encoder1_SampleTime)
    {
      ControlaBCs_Z_DW.obj.SampleTime = ControlaBCs_Z_P.Encoder1_SampleTime;
    }

    if (ControlaBCs_Z_DW.obj.TunablePropsChanged) {
      ControlaBCs_Z_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S4>/Encoder1' */
    MW_EncoderRead(ControlaBCs_Z_DW.obj.Index, &ControlaBCs_Z_B.Encoder1);

    /* Gain: '<S4>/Gain' */
    rtb_error_idx_0 = (real_T)ControlaBCs_Z_P.Gain_Gain * 1.1368683772161603E-13;

    /* Gain: '<S4>/Gain' incorporates:
     *  SignalConversion generated from: '<S4>/Gain'
     */
    ControlaBCs_Z_B.Gain[0] = rtb_error_idx_0 * (real_T)ControlaBCs_Z_B.Encoder;
    ControlaBCs_Z_B.Gain[1] = rtb_error_idx_0 * (real_T)ControlaBCs_Z_B.Encoder1;

    /* Derivative: '<S4>/Derivative' */
    u0 = ControlaBCs_Z_M->Timing.t[0];
    if ((ControlaBCs_Z_DW.TimeStampA >= u0) && (ControlaBCs_Z_DW.TimeStampB >=
         u0)) {
      /* Derivative: '<S4>/Derivative' */
      ControlaBCs_Z_B.Derivative[0] = 0.0;
      ControlaBCs_Z_B.Derivative[1] = 0.0;
    } else {
      rtb_error_idx_0 = ControlaBCs_Z_DW.TimeStampA;
      lastU = &ControlaBCs_Z_DW.LastUAtTimeA;
      if (ControlaBCs_Z_DW.TimeStampA < ControlaBCs_Z_DW.TimeStampB) {
        if (ControlaBCs_Z_DW.TimeStampB < u0) {
          rtb_error_idx_0 = ControlaBCs_Z_DW.TimeStampB;
          lastU = &ControlaBCs_Z_DW.LastUAtTimeB;
        }
      } else if (ControlaBCs_Z_DW.TimeStampA >= u0) {
        rtb_error_idx_0 = ControlaBCs_Z_DW.TimeStampB;
        lastU = &ControlaBCs_Z_DW.LastUAtTimeB;
      }

      rtb_error_idx_0 = u0 - rtb_error_idx_0;

      /* Derivative: '<S4>/Derivative' */
      ControlaBCs_Z_B.Derivative[0] = (ControlaBCs_Z_B.Gain[0] - (*lastU)[0]) /
        rtb_error_idx_0;
      ControlaBCs_Z_B.Derivative[1] = (ControlaBCs_Z_B.Gain[1] - (*lastU)[1]) /
        rtb_error_idx_0;
    }

    /* End of Derivative: '<S4>/Derivative' */
    /* SignalConversion generated from: '<S4>/Mux' */
    ControlaBCs_Z_B.TmpSignalConversionAtTAQSigLogg[0] = ControlaBCs_Z_B.Encoder;
    ControlaBCs_Z_B.TmpSignalConversionAtTAQSigLogg[1] =
      ControlaBCs_Z_B.Encoder1;

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant'
     *  Memory: '<Root>/Memory'
     */
    rtb_error_idx_0 = ControlaBCs_Z_P.Constant_Value[0] -
      ControlaBCs_Z_DW.Memory_PreviousInput[0];
    rtb_error_idx_1 = ControlaBCs_Z_P.Constant_Value[1] -
      ControlaBCs_Z_DW.Memory_PreviousInput[1];

    /* Sum: '<S98>/Sum' incorporates:
     *  DiscreteIntegrator: '<S89>/Integrator'
     *  Gain: '<S94>/Proportional Gain'
     */
    u0 = ControlaBCs_Z_P.PIDController2_P * rtb_error_idx_0 +
      ControlaBCs_Z_DW.Integrator_DSTATE;

    /* Saturate: '<S96>/Saturation' */
    if (u0 > ControlaBCs_Z_P.PIDController2_UpperSaturationL) {
      u0 = ControlaBCs_Z_P.PIDController2_UpperSaturationL;
    } else if (u0 < ControlaBCs_Z_P.PIDController2_LowerSaturationL) {
      u0 = ControlaBCs_Z_P.PIDController2_LowerSaturationL;
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Saturate: '<S96>/Saturation'
     */
    u0 = floor(u0);
    if (rtIsNaN(u0) || rtIsInf(u0)) {
      u0 = 0.0;
    } else {
      u0 = fmod(u0, 65536.0);
    }

    rtb_DataTypeConversion_idx_0 = u0 < 0.0 ? -(int16_T)(uint16_T)-u0 : (int16_T)
      (uint16_T)u0;

    /* Sum: '<S50>/Sum' incorporates:
     *  DiscreteIntegrator: '<S41>/Integrator'
     *  Gain: '<S46>/Proportional Gain'
     */
    u0 = ControlaBCs_Z_P.PIDController1_P * rtb_error_idx_1 +
      ControlaBCs_Z_DW.Integrator_DSTATE_i;

    /* Saturate: '<S48>/Saturation' */
    if (u0 > ControlaBCs_Z_P.PIDController1_UpperSaturationL) {
      u0 = ControlaBCs_Z_P.PIDController1_UpperSaturationL;
    } else if (u0 < ControlaBCs_Z_P.PIDController1_LowerSaturationL) {
      u0 = ControlaBCs_Z_P.PIDController1_LowerSaturationL;
    }

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Saturate: '<S48>/Saturation'
     */
    u0 = floor(u0);
    if (rtIsNaN(u0) || rtIsInf(u0)) {
      u0 = 0.0;
    } else {
      u0 = fmod(u0, 65536.0);
    }

    rtb_DataTypeConversion_idx_1 = u0 < 0.0 ? -(int16_T)(uint16_T)-u0 : (int16_T)
      (uint16_T)u0;

    /* MATLABSystem: '<S5>/Adelante_der' */
    ControlaBCs_Z_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

    /* Saturate: '<S5>/Saturation2' */
    if (rtb_DataTypeConversion_idx_1 > ControlaBCs_Z_P.Saturation2_UpperSat) {
      y = ControlaBCs_Z_P.Saturation2_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               ControlaBCs_Z_P.Saturation2_LowerSat) {
      y = ControlaBCs_Z_P.Saturation2_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
    }

    /* End of Saturate: '<S5>/Saturation2' */

    /* Start for MATLABSystem: '<S5>/Adelante_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S5>/Adelante_der' */
    MW_PWM_SetDutyCycle(ControlaBCs_Z_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S5>/Adelante_izq' */
    ControlaBCs_Z_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* Saturate: '<S5>/Saturation4' */
    if (rtb_DataTypeConversion_idx_0 > ControlaBCs_Z_P.Saturation4_UpperSat) {
      y = ControlaBCs_Z_P.Saturation4_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               ControlaBCs_Z_P.Saturation4_LowerSat) {
      y = ControlaBCs_Z_P.Saturation4_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_0;
    }

    /* End of Saturate: '<S5>/Saturation4' */

    /* Abs: '<S5>/Abs2' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S5>/Abs2' */

    /* Start for MATLABSystem: '<S5>/Adelante_izq' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S5>/Adelante_izq' */
    MW_PWM_SetDutyCycle(ControlaBCs_Z_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S5>/Atras_der' */
    ControlaBCs_Z_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* Saturate: '<S5>/Saturation3' */
    if (rtb_DataTypeConversion_idx_1 > ControlaBCs_Z_P.Saturation3_UpperSat) {
      y = ControlaBCs_Z_P.Saturation3_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               ControlaBCs_Z_P.Saturation3_LowerSat) {
      y = ControlaBCs_Z_P.Saturation3_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
    }

    /* End of Saturate: '<S5>/Saturation3' */

    /* Abs: '<S5>/Abs1' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S5>/Abs1' */

    /* Start for MATLABSystem: '<S5>/Atras_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S5>/Atras_der' */
    MW_PWM_SetDutyCycle(ControlaBCs_Z_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S5>/Atras_izq' */
    ControlaBCs_Z_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Saturate: '<S5>/Saturation5' */
    if (rtb_DataTypeConversion_idx_0 > ControlaBCs_Z_P.Saturation5_UpperSat) {
      y = ControlaBCs_Z_P.Saturation5_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               ControlaBCs_Z_P.Saturation5_LowerSat) {
      y = ControlaBCs_Z_P.Saturation5_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_0;
    }

    /* End of Saturate: '<S5>/Saturation5' */

    /* Start for MATLABSystem: '<S5>/Atras_izq' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S5>/Atras_izq' */
    MW_PWM_SetDutyCycle(ControlaBCs_Z_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S5>/Digital Output' incorporates:
     *  Constant: '<S6>/Constant'
     *  RelationalOperator: '<S6>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
      ControlaBCs_Z_P.Constant_Value_h));

    /* MATLABSystem: '<S5>/Digital Output1' incorporates:
     *  Constant: '<S7>/Constant'
     *  RelationalOperator: '<S7>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
      ControlaBCs_Z_P.Constant_Value_g));

    /* Gain: '<S38>/Integral Gain' */
    rtb_IntegralGain = ControlaBCs_Z_P.PIDController1_I * rtb_error_idx_1;

    /* Gain: '<S86>/Integral Gain' */
    rtb_IntegralGain_e = ControlaBCs_Z_P.PIDController2_I * rtb_error_idx_0;
  }

  {
    real_T (*lastU)[2];

    /* Update for Derivative: '<S4>/Derivative' */
    if (ControlaBCs_Z_DW.TimeStampA == (rtInf)) {
      ControlaBCs_Z_DW.TimeStampA = ControlaBCs_Z_M->Timing.t[0];
      lastU = &ControlaBCs_Z_DW.LastUAtTimeA;
    } else if (ControlaBCs_Z_DW.TimeStampB == (rtInf)) {
      ControlaBCs_Z_DW.TimeStampB = ControlaBCs_Z_M->Timing.t[0];
      lastU = &ControlaBCs_Z_DW.LastUAtTimeB;
    } else if (ControlaBCs_Z_DW.TimeStampA < ControlaBCs_Z_DW.TimeStampB) {
      ControlaBCs_Z_DW.TimeStampA = ControlaBCs_Z_M->Timing.t[0];
      lastU = &ControlaBCs_Z_DW.LastUAtTimeA;
    } else {
      ControlaBCs_Z_DW.TimeStampB = ControlaBCs_Z_M->Timing.t[0];
      lastU = &ControlaBCs_Z_DW.LastUAtTimeB;
    }

    (*lastU)[0] = ControlaBCs_Z_B.Gain[0];

    /* Update for Memory: '<Root>/Memory' */
    ControlaBCs_Z_DW.Memory_PreviousInput[0] = ControlaBCs_Z_B.Derivative[0];

    /* Update for Derivative: '<S4>/Derivative' */
    (*lastU)[1] = ControlaBCs_Z_B.Gain[1];

    /* Update for Memory: '<Root>/Memory' */
    ControlaBCs_Z_DW.Memory_PreviousInput[1] = ControlaBCs_Z_B.Derivative[1];

    /* Update for DiscreteIntegrator: '<S89>/Integrator' */
    ControlaBCs_Z_DW.Integrator_DSTATE += ControlaBCs_Z_P.Integrator_gainval *
      rtb_IntegralGain_e;

    /* Update for DiscreteIntegrator: '<S41>/Integrator' */
    ControlaBCs_Z_DW.Integrator_DSTATE_i += ControlaBCs_Z_P.Integrator_gainval_k
      * rtb_IntegralGain;
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((ControlaBCs_Z_M->Timing.clockTick0 * 1) + 0)
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
      ((ControlaBCs_Z_M->Timing.clockTick1 * 1) + 0)
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
  ControlaBCs_Z_M->Timing.t[0] =
    ((time_T)(++ControlaBCs_Z_M->Timing.clockTick0)) *
    ControlaBCs_Z_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    ControlaBCs_Z_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void ControlaBCs_Z_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ControlaBCs_Z_M->solverInfo,
                          &ControlaBCs_Z_M->Timing.simTimeStep);
    rtsiSetTPtr(&ControlaBCs_Z_M->solverInfo, &rtmGetTPtr(ControlaBCs_Z_M));
    rtsiSetStepSizePtr(&ControlaBCs_Z_M->solverInfo,
                       &ControlaBCs_Z_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&ControlaBCs_Z_M->solverInfo, (&rtmGetErrorStatus
      (ControlaBCs_Z_M)));
    rtsiSetRTModelPtr(&ControlaBCs_Z_M->solverInfo, ControlaBCs_Z_M);
  }

  rtsiSetSimTimeStep(&ControlaBCs_Z_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&ControlaBCs_Z_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(ControlaBCs_Z_M, &ControlaBCs_Z_M->Timing.tArray[0]);
  rtmSetTFinal(ControlaBCs_Z_M, -1);
  ControlaBCs_Z_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  ControlaBCs_Z_M->Sizes.checksums[0] = (27173078U);
  ControlaBCs_Z_M->Sizes.checksums[1] = (2936173693U);
  ControlaBCs_Z_M->Sizes.checksums[2] = (1841454275U);
  ControlaBCs_Z_M->Sizes.checksums[3] = (1122763976U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    ControlaBCs_Z_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(ControlaBCs_Z_M->extModeInfo,
      &ControlaBCs_Z_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ControlaBCs_Z_M->extModeInfo,
                        ControlaBCs_Z_M->Sizes.checksums);
    rteiSetTPtr(ControlaBCs_Z_M->extModeInfo, rtmGetTPtr(ControlaBCs_Z_M));
  }

  /* InitializeConditions for Derivative: '<S4>/Derivative' */
  ControlaBCs_Z_DW.TimeStampA = (rtInf);
  ControlaBCs_Z_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Memory: '<Root>/Memory' */
  ControlaBCs_Z_DW.Memory_PreviousInput[0] =
    ControlaBCs_Z_P.Memory_InitialCondition;
  ControlaBCs_Z_DW.Memory_PreviousInput[1] =
    ControlaBCs_Z_P.Memory_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S89>/Integrator' */
  ControlaBCs_Z_DW.Integrator_DSTATE =
    ControlaBCs_Z_P.PIDController2_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S41>/Integrator' */
  ControlaBCs_Z_DW.Integrator_DSTATE_i =
    ControlaBCs_Z_P.PIDController1_InitialCondition;

  /* Start for MATLABSystem: '<S4>/Encoder' */
  ControlaBCs_Z_DW.obj_e.Index = 0U;
  ControlaBCs_Z_DW.obj_e.matlabCodegenIsDeleted = false;
  ControlaBCs_Z_DW.obj_e.SampleTime = ControlaBCs_Z_P.Encoder_SampleTime;
  ControlaBCs_Z_DW.obj_e.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &ControlaBCs_Z_DW.obj_e.Index);
  ControlaBCs_Z_DW.obj_e.isSetupComplete = true;
  ControlaBCs_Z_DW.obj_e.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S4>/Encoder' */
  MW_EncoderReset(ControlaBCs_Z_DW.obj_e.Index);

  /* Start for MATLABSystem: '<S4>/Encoder1' */
  ControlaBCs_Z_DW.obj.Index = 0U;
  ControlaBCs_Z_DW.obj.matlabCodegenIsDeleted = false;
  ControlaBCs_Z_DW.obj.SampleTime = ControlaBCs_Z_P.Encoder1_SampleTime;
  ControlaBCs_Z_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &ControlaBCs_Z_DW.obj.Index);
  ControlaBCs_Z_DW.obj.isSetupComplete = true;
  ControlaBCs_Z_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S4>/Encoder1' */
  MW_EncoderReset(ControlaBCs_Z_DW.obj.Index);

  /* Start for MATLABSystem: '<S5>/Adelante_der' */
  ControlaBCs_Z_DW.obj_k.matlabCodegenIsDeleted = false;
  ControlaBCs_Z_DW.obj_k.isInitialized = 1L;
  ControlaBCs_Z_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0, 0.0);
  ControlaBCs_Z_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Adelante_izq' */
  ControlaBCs_Z_DW.obj_m.matlabCodegenIsDeleted = false;
  ControlaBCs_Z_DW.obj_m.isInitialized = 1L;
  ControlaBCs_Z_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0, 0.0);
  ControlaBCs_Z_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Atras_der' */
  ControlaBCs_Z_DW.obj_e5.matlabCodegenIsDeleted = false;
  ControlaBCs_Z_DW.obj_e5.isInitialized = 1L;
  ControlaBCs_Z_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  ControlaBCs_Z_DW.obj_e5.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Atras_izq' */
  ControlaBCs_Z_DW.obj_d.matlabCodegenIsDeleted = false;
  ControlaBCs_Z_DW.obj_d.isInitialized = 1L;
  ControlaBCs_Z_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0, 0.0);
  ControlaBCs_Z_DW.obj_d.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Digital Output' */
  ControlaBCs_Z_DW.obj_p.matlabCodegenIsDeleted = false;
  ControlaBCs_Z_DW.obj_p.isInitialized = 1L;
  digitalIOSetup(8, 1);
  ControlaBCs_Z_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Digital Output1' */
  ControlaBCs_Z_DW.obj_n.matlabCodegenIsDeleted = false;
  ControlaBCs_Z_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(13, 1);
  ControlaBCs_Z_DW.obj_n.isSetupComplete = true;
}

/* Model terminate function */
void ControlaBCs_Z_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/Encoder' */
  if (!ControlaBCs_Z_DW.obj_e.matlabCodegenIsDeleted) {
    ControlaBCs_Z_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((ControlaBCs_Z_DW.obj_e.isInitialized == 1L) &&
        ControlaBCs_Z_DW.obj_e.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Encoder' */

  /* Terminate for MATLABSystem: '<S4>/Encoder1' */
  if (!ControlaBCs_Z_DW.obj.matlabCodegenIsDeleted) {
    ControlaBCs_Z_DW.obj.matlabCodegenIsDeleted = true;
    if ((ControlaBCs_Z_DW.obj.isInitialized == 1L) &&
        ControlaBCs_Z_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Encoder1' */
  /* Terminate for MATLABSystem: '<S5>/Adelante_der' */
  if (!ControlaBCs_Z_DW.obj_k.matlabCodegenIsDeleted) {
    ControlaBCs_Z_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((ControlaBCs_Z_DW.obj_k.isInitialized == 1L) &&
        ControlaBCs_Z_DW.obj_k.isSetupComplete) {
      ControlaBCs_Z_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle(ControlaBCs_Z_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ControlaBCs_Z_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);
      MW_PWM_Close(ControlaBCs_Z_DW.obj_k.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S5>/Adelante_izq' */
  if (!ControlaBCs_Z_DW.obj_m.matlabCodegenIsDeleted) {
    ControlaBCs_Z_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((ControlaBCs_Z_DW.obj_m.isInitialized == 1L) &&
        ControlaBCs_Z_DW.obj_m.isSetupComplete) {
      ControlaBCs_Z_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle(ControlaBCs_Z_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ControlaBCs_Z_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);
      MW_PWM_Close(ControlaBCs_Z_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S5>/Atras_der' */
  if (!ControlaBCs_Z_DW.obj_e5.matlabCodegenIsDeleted) {
    ControlaBCs_Z_DW.obj_e5.matlabCodegenIsDeleted = true;
    if ((ControlaBCs_Z_DW.obj_e5.isInitialized == 1L) &&
        ControlaBCs_Z_DW.obj_e5.isSetupComplete) {
      ControlaBCs_Z_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle(ControlaBCs_Z_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ControlaBCs_Z_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);
      MW_PWM_Close(ControlaBCs_Z_DW.obj_e5.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Atras_der' */

  /* Terminate for MATLABSystem: '<S5>/Atras_izq' */
  if (!ControlaBCs_Z_DW.obj_d.matlabCodegenIsDeleted) {
    ControlaBCs_Z_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((ControlaBCs_Z_DW.obj_d.isInitialized == 1L) &&
        ControlaBCs_Z_DW.obj_d.isSetupComplete) {
      ControlaBCs_Z_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle(ControlaBCs_Z_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      ControlaBCs_Z_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);
      MW_PWM_Close(ControlaBCs_Z_DW.obj_d.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  if (!ControlaBCs_Z_DW.obj_p.matlabCodegenIsDeleted) {
    ControlaBCs_Z_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!ControlaBCs_Z_DW.obj_n.matlabCodegenIsDeleted) {
    ControlaBCs_Z_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
