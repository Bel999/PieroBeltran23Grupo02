/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestCinematicaz.c
 *
 * Code generated for Simulink model 'TestCinematicaz'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Dec 18 12:52:32 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TestCinematicaz.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "TestCinematicaz_private.h"

/* Block signals (default storage) */
B_TestCinematicaz_T TestCinematicaz_B;

/* Block states (default storage) */
DW_TestCinematicaz_T TestCinematicaz_DW;

/* Real-time model */
static RT_MODEL_TestCinematicaz_T TestCinematicaz_M_;
RT_MODEL_TestCinematicaz_T *const TestCinematicaz_M = &TestCinematicaz_M_;

/* Model step function */
void TestCinematicaz_step(void)
{
  /* local block i/o variables */
  real_T rtb_IntegralGain;
  real_T rtb_IntegralGain_j;

  {
    real_T (*lastU)[2];
    real_T Gain_tmp;
    real_T lastTime;
    int16_T rtb_DataTypeConversion_idx_0;
    int16_T rtb_DataTypeConversion_idx_1;
    int16_T y;

    /* Constant: '<Root>/Constant' */
    TestCinematicaz_B.rel[0] = TestCinematicaz_P.Constant_Value_j[0];
    TestCinematicaz_B.rel[1] = TestCinematicaz_P.Constant_Value_j[1];

    /* Product: '<S1>/Matrix Multiply' incorporates:
     *  Constant: '<S1>/Constant'
     */
    TestCinematicaz_B.MatrixMultiply[0] = TestCinematicaz_P.Constant_Value[0] *
      TestCinematicaz_B.rel[0] + TestCinematicaz_B.rel[1] *
      TestCinematicaz_P.Constant_Value[2];
    TestCinematicaz_B.MatrixMultiply[1] = TestCinematicaz_B.rel[0] *
      TestCinematicaz_P.Constant_Value[1] + TestCinematicaz_B.rel[1] *
      TestCinematicaz_P.Constant_Value[3];

    /* Sum: '<S3>/Sum' incorporates:
     *  Memory: '<S3>/Memory1'
     */
    TestCinematicaz_B.error[0] = TestCinematicaz_B.MatrixMultiply[0] -
      TestCinematicaz_DW.Memory1_PreviousInput[0];
    TestCinematicaz_B.error[1] = TestCinematicaz_B.MatrixMultiply[1] -
      TestCinematicaz_DW.Memory1_PreviousInput[1];

    /* Sum: '<S97>/Sum' incorporates:
     *  DiscreteIntegrator: '<S88>/Integrator'
     *  Gain: '<S93>/Proportional Gain'
     */
    TestCinematicaz_B.Saturation = TestCinematicaz_P.PIDController2_P *
      TestCinematicaz_B.error[0] + TestCinematicaz_DW.Integrator_DSTATE;

    /* Saturate: '<S95>/Saturation' */
    if (TestCinematicaz_B.Saturation >
        TestCinematicaz_P.PIDController2_UpperSaturationL) {
      /* Sum: '<S97>/Sum' incorporates:
       *  Saturate: '<S95>/Saturation'
       */
      TestCinematicaz_B.Saturation =
        TestCinematicaz_P.PIDController2_UpperSaturationL;
    } else if (TestCinematicaz_B.Saturation <
               TestCinematicaz_P.PIDController2_LowerSaturationL) {
      /* Sum: '<S97>/Sum' incorporates:
       *  Saturate: '<S95>/Saturation'
       */
      TestCinematicaz_B.Saturation =
        TestCinematicaz_P.PIDController2_LowerSaturationL;
    }

    /* End of Saturate: '<S95>/Saturation' */

    /* Sum: '<S49>/Sum' incorporates:
     *  DiscreteIntegrator: '<S40>/Integrator'
     *  Gain: '<S45>/Proportional Gain'
     */
    TestCinematicaz_B.Saturation_a = TestCinematicaz_P.PIDController1_P *
      TestCinematicaz_B.error[1] + TestCinematicaz_DW.Integrator_DSTATE_h;

    /* Saturate: '<S47>/Saturation' */
    if (TestCinematicaz_B.Saturation_a >
        TestCinematicaz_P.PIDController1_UpperSaturationL) {
      /* Sum: '<S49>/Sum' incorporates:
       *  Saturate: '<S47>/Saturation'
       */
      TestCinematicaz_B.Saturation_a =
        TestCinematicaz_P.PIDController1_UpperSaturationL;
    } else if (TestCinematicaz_B.Saturation_a <
               TestCinematicaz_P.PIDController1_LowerSaturationL) {
      /* Sum: '<S49>/Sum' incorporates:
       *  Saturate: '<S47>/Saturation'
       */
      TestCinematicaz_B.Saturation_a =
        TestCinematicaz_P.PIDController1_LowerSaturationL;
    }

    /* End of Saturate: '<S47>/Saturation' */

    /* SignalConversion generated from: '<S3>/Subsystem Reference' */
    TestCinematicaz_B.pwm[0] = TestCinematicaz_B.Saturation;
    TestCinematicaz_B.pwm[1] = TestCinematicaz_B.Saturation_a;

    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    Gain_tmp = floor(TestCinematicaz_B.pwm[0]);
    if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
      Gain_tmp = 0.0;
    } else {
      Gain_tmp = fmod(Gain_tmp, 65536.0);
    }

    rtb_DataTypeConversion_idx_0 = Gain_tmp < 0.0 ? -(int16_T)(uint16_T)
      -Gain_tmp : (int16_T)(uint16_T)Gain_tmp;
    Gain_tmp = floor(TestCinematicaz_B.pwm[1]);
    if (rtIsNaN(Gain_tmp) || rtIsInf(Gain_tmp)) {
      Gain_tmp = 0.0;
    } else {
      Gain_tmp = fmod(Gain_tmp, 65536.0);
    }

    rtb_DataTypeConversion_idx_1 = Gain_tmp < 0.0 ? -(int16_T)(uint16_T)
      -Gain_tmp : (int16_T)(uint16_T)Gain_tmp;

    /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

    /* MATLABSystem: '<S107>/Adelante_der' */
    TestCinematicaz_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(12UL);

    /* Saturate: '<S107>/Saturation2' */
    if (rtb_DataTypeConversion_idx_1 > TestCinematicaz_P.Saturation2_UpperSat) {
      y = TestCinematicaz_P.Saturation2_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               TestCinematicaz_P.Saturation2_LowerSat) {
      y = TestCinematicaz_P.Saturation2_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
    }

    /* End of Saturate: '<S107>/Saturation2' */

    /* Start for MATLABSystem: '<S107>/Adelante_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S107>/Adelante_der' */
    MW_PWM_SetDutyCycle(TestCinematicaz_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S107>/Adelante_izq' */
    TestCinematicaz_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(9UL);

    /* Saturate: '<S107>/Saturation4' */
    if (rtb_DataTypeConversion_idx_0 > TestCinematicaz_P.Saturation4_UpperSat) {
      y = TestCinematicaz_P.Saturation4_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               TestCinematicaz_P.Saturation4_LowerSat) {
      y = TestCinematicaz_P.Saturation4_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_0;
    }

    /* End of Saturate: '<S107>/Saturation4' */

    /* Abs: '<S107>/Abs2' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S107>/Abs2' */

    /* Start for MATLABSystem: '<S107>/Adelante_izq' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S107>/Adelante_izq' */
    MW_PWM_SetDutyCycle(TestCinematicaz_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S107>/Atras_der' */
    TestCinematicaz_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(11UL);

    /* Saturate: '<S107>/Saturation3' */
    if (rtb_DataTypeConversion_idx_1 > TestCinematicaz_P.Saturation3_UpperSat) {
      y = TestCinematicaz_P.Saturation3_UpperSat;
    } else if (rtb_DataTypeConversion_idx_1 <
               TestCinematicaz_P.Saturation3_LowerSat) {
      y = TestCinematicaz_P.Saturation3_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_1;
    }

    /* End of Saturate: '<S107>/Saturation3' */

    /* Abs: '<S107>/Abs1' */
    if (y < 0) {
      y = -y;
    }

    /* End of Abs: '<S107>/Abs1' */

    /* Start for MATLABSystem: '<S107>/Atras_der' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S107>/Atras_der' */
    MW_PWM_SetDutyCycle(TestCinematicaz_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S107>/Atras_izq' */
    TestCinematicaz_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(10UL);

    /* Saturate: '<S107>/Saturation5' */
    if (rtb_DataTypeConversion_idx_0 > TestCinematicaz_P.Saturation5_UpperSat) {
      y = TestCinematicaz_P.Saturation5_UpperSat;
    } else if (rtb_DataTypeConversion_idx_0 <
               TestCinematicaz_P.Saturation5_LowerSat) {
      y = TestCinematicaz_P.Saturation5_LowerSat;
    } else {
      y = rtb_DataTypeConversion_idx_0;
    }

    /* End of Saturate: '<S107>/Saturation5' */

    /* Start for MATLABSystem: '<S107>/Atras_izq' */
    if (y > 255) {
      y = 255;
    }

    if (y < 0) {
      y = 0;
    }

    /* MATLABSystem: '<S107>/Atras_izq' */
    MW_PWM_SetDutyCycle(TestCinematicaz_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                        (real_T)y);

    /* MATLABSystem: '<S107>/Digital Output' incorporates:
     *  Constant: '<S108>/Constant'
     *  RelationalOperator: '<S108>/Compare'
     */
    writeDigitalPin(8, (uint8_T)(rtb_DataTypeConversion_idx_0 !=
      TestCinematicaz_P.Constant_Value_k));

    /* MATLABSystem: '<S107>/Digital Output1' incorporates:
     *  Constant: '<S109>/Constant'
     *  RelationalOperator: '<S109>/Compare'
     */
    writeDigitalPin(13, (uint8_T)(rtb_DataTypeConversion_idx_1 !=
      TestCinematicaz_P.Constant_Value_jh));

    /* Gain: '<S37>/Integral Gain' */
    rtb_IntegralGain = TestCinematicaz_P.PIDController1_I *
      TestCinematicaz_B.error[1];

    /* Gain: '<S85>/Integral Gain' */
    rtb_IntegralGain_j = TestCinematicaz_P.PIDController2_I *
      TestCinematicaz_B.error[0];

    /* DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
    TestCinematicaz_B.DiscreteTimeIntegrator[0] =
      TestCinematicaz_DW.DiscreteTimeIntegrator_DSTATE[0];
    TestCinematicaz_B.DiscreteTimeIntegrator[1] =
      TestCinematicaz_DW.DiscreteTimeIntegrator_DSTATE[1];
    TestCinematicaz_B.DiscreteTimeIntegrator[2] =
      TestCinematicaz_DW.DiscreteTimeIntegrator_DSTATE[2];

    /* MATLABSystem: '<S106>/Encoder' */
    if (TestCinematicaz_DW.obj_d.SampleTime !=
        TestCinematicaz_P.Encoder_SampleTime) {
      TestCinematicaz_DW.obj_d.SampleTime = TestCinematicaz_P.Encoder_SampleTime;
    }

    if (TestCinematicaz_DW.obj_d.TunablePropsChanged) {
      TestCinematicaz_DW.obj_d.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S106>/Encoder' */
    MW_EncoderRead(TestCinematicaz_DW.obj_d.Index, &TestCinematicaz_B.Encoder);

    /* MATLABSystem: '<S106>/Encoder1' */
    if (TestCinematicaz_DW.obj.SampleTime !=
        TestCinematicaz_P.Encoder1_SampleTime) {
      TestCinematicaz_DW.obj.SampleTime = TestCinematicaz_P.Encoder1_SampleTime;
    }

    if (TestCinematicaz_DW.obj.TunablePropsChanged) {
      TestCinematicaz_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S106>/Encoder1' */
    MW_EncoderRead(TestCinematicaz_DW.obj.Index, &TestCinematicaz_B.Encoder1);

    /* Gain: '<S106>/Gain' */
    Gain_tmp = (real_T)TestCinematicaz_P.Gain_Gain * 1.1368683772161603E-13;

    /* Gain: '<S106>/Gain' incorporates:
     *  SignalConversion generated from: '<S106>/Gain'
     */
    TestCinematicaz_B.Gain[0] = Gain_tmp * (real_T)TestCinematicaz_B.Encoder;
    TestCinematicaz_B.Gain[1] = Gain_tmp * (real_T)TestCinematicaz_B.Encoder1;

    /* Derivative: '<S106>/Derivative' */
    Gain_tmp = TestCinematicaz_M->Timing.t[0];
    if ((TestCinematicaz_DW.TimeStampA >= Gain_tmp) &&
        (TestCinematicaz_DW.TimeStampB >= Gain_tmp)) {
      /* Derivative: '<S106>/Derivative' */
      TestCinematicaz_B.Derivative[0] = 0.0;
      TestCinematicaz_B.Derivative[1] = 0.0;
    } else {
      lastTime = TestCinematicaz_DW.TimeStampA;
      lastU = &TestCinematicaz_DW.LastUAtTimeA;
      if (TestCinematicaz_DW.TimeStampA < TestCinematicaz_DW.TimeStampB) {
        if (TestCinematicaz_DW.TimeStampB < Gain_tmp) {
          lastTime = TestCinematicaz_DW.TimeStampB;
          lastU = &TestCinematicaz_DW.LastUAtTimeB;
        }
      } else if (TestCinematicaz_DW.TimeStampA >= Gain_tmp) {
        lastTime = TestCinematicaz_DW.TimeStampB;
        lastU = &TestCinematicaz_DW.LastUAtTimeB;
      }

      Gain_tmp -= lastTime;

      /* Derivative: '<S106>/Derivative' */
      TestCinematicaz_B.Derivative[0] = (TestCinematicaz_B.Gain[0] - (*lastU)[0])
        / Gain_tmp;
      TestCinematicaz_B.Derivative[1] = (TestCinematicaz_B.Gain[1] - (*lastU)[1])
        / Gain_tmp;
    }

    /* End of Derivative: '<S106>/Derivative' */

    /* Product: '<S2>/Matrix Multiply' incorporates:
     *  Constant: '<S2>/Constant'
     */
    TestCinematicaz_B.MatrixMultiply_d[0] = TestCinematicaz_P.Constant_Value_b[0]
      * TestCinematicaz_B.Derivative[0] + TestCinematicaz_B.Derivative[1] *
      TestCinematicaz_P.Constant_Value_b[2];
    TestCinematicaz_B.MatrixMultiply_d[1] = TestCinematicaz_B.Derivative[0] *
      TestCinematicaz_P.Constant_Value_b[1] + TestCinematicaz_B.Derivative[1] *
      TestCinematicaz_P.Constant_Value_b[3];

    /* SignalConversion generated from: '<S106>/Mux' */
    TestCinematicaz_B.TmpSignalConversionAtTAQSigLogg[0] =
      TestCinematicaz_B.Encoder;
    TestCinematicaz_B.TmpSignalConversionAtTAQSigLogg[1] =
      TestCinematicaz_B.Encoder1;

    /* Product: '<S4>/Product' incorporates:
     *  Trigonometry: '<S4>/Cos'
     */
    TestCinematicaz_B.Vx = cos(TestCinematicaz_B.DiscreteTimeIntegrator[2]) *
      TestCinematicaz_B.MatrixMultiply_d[0];

    /* Product: '<S4>/Product1' incorporates:
     *  Trigonometry: '<S4>/Sin'
     */
    TestCinematicaz_B.Vy = TestCinematicaz_B.MatrixMultiply_d[0] * sin
      (TestCinematicaz_B.DiscreteTimeIntegrator[2]);
  }

  {
    real_T (*lastU)[2];
    real_T tmp;
    real_T tmp_0;
    real_T tmp_1;

    /* Update for Memory: '<S3>/Memory1' */
    TestCinematicaz_DW.Memory1_PreviousInput[0] = TestCinematicaz_B.Derivative[0];
    TestCinematicaz_DW.Memory1_PreviousInput[1] = TestCinematicaz_B.Derivative[1];

    /* Update for DiscreteIntegrator: '<S88>/Integrator' */
    TestCinematicaz_DW.Integrator_DSTATE += TestCinematicaz_P.Integrator_gainval
      * rtb_IntegralGain_j;

    /* Update for DiscreteIntegrator: '<S40>/Integrator' */
    TestCinematicaz_DW.Integrator_DSTATE_h +=
      TestCinematicaz_P.Integrator_gainval_k * rtb_IntegralGain;

    /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
    tmp = TestCinematicaz_DW.DiscreteTimeIntegrator_DSTATE[0];
    tmp_0 = TestCinematicaz_DW.DiscreteTimeIntegrator_DSTATE[1];
    tmp_1 = TestCinematicaz_DW.DiscreteTimeIntegrator_DSTATE[2];
    TestCinematicaz_DW.DiscreteTimeIntegrator_DSTATE[0] =
      TestCinematicaz_P.DiscreteTimeIntegrator_gainval * TestCinematicaz_B.Vx +
      tmp;
    TestCinematicaz_DW.DiscreteTimeIntegrator_DSTATE[1] =
      TestCinematicaz_P.DiscreteTimeIntegrator_gainval * TestCinematicaz_B.Vy +
      tmp_0;
    TestCinematicaz_DW.DiscreteTimeIntegrator_DSTATE[2] =
      TestCinematicaz_P.DiscreteTimeIntegrator_gainval *
      TestCinematicaz_B.MatrixMultiply_d[1] + tmp_1;

    /* Update for Derivative: '<S106>/Derivative' */
    if (TestCinematicaz_DW.TimeStampA == (rtInf)) {
      TestCinematicaz_DW.TimeStampA = TestCinematicaz_M->Timing.t[0];
      lastU = &TestCinematicaz_DW.LastUAtTimeA;
    } else if (TestCinematicaz_DW.TimeStampB == (rtInf)) {
      TestCinematicaz_DW.TimeStampB = TestCinematicaz_M->Timing.t[0];
      lastU = &TestCinematicaz_DW.LastUAtTimeB;
    } else if (TestCinematicaz_DW.TimeStampA < TestCinematicaz_DW.TimeStampB) {
      TestCinematicaz_DW.TimeStampA = TestCinematicaz_M->Timing.t[0];
      lastU = &TestCinematicaz_DW.LastUAtTimeA;
    } else {
      TestCinematicaz_DW.TimeStampB = TestCinematicaz_M->Timing.t[0];
      lastU = &TestCinematicaz_DW.LastUAtTimeB;
    }

    (*lastU)[0] = TestCinematicaz_B.Gain[0];
    (*lastU)[1] = TestCinematicaz_B.Gain[1];

    /* End of Update for Derivative: '<S106>/Derivative' */
  }

  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((TestCinematicaz_M->Timing.clockTick0 * 1) + 0)
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
      ((TestCinematicaz_M->Timing.clockTick1 * 1) + 0)
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
  TestCinematicaz_M->Timing.t[0] =
    ((time_T)(++TestCinematicaz_M->Timing.clockTick0)) *
    TestCinematicaz_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    TestCinematicaz_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void TestCinematicaz_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TestCinematicaz_M->solverInfo,
                          &TestCinematicaz_M->Timing.simTimeStep);
    rtsiSetTPtr(&TestCinematicaz_M->solverInfo, &rtmGetTPtr(TestCinematicaz_M));
    rtsiSetStepSizePtr(&TestCinematicaz_M->solverInfo,
                       &TestCinematicaz_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&TestCinematicaz_M->solverInfo, (&rtmGetErrorStatus
      (TestCinematicaz_M)));
    rtsiSetRTModelPtr(&TestCinematicaz_M->solverInfo, TestCinematicaz_M);
  }

  rtsiSetSimTimeStep(&TestCinematicaz_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&TestCinematicaz_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(TestCinematicaz_M, &TestCinematicaz_M->Timing.tArray[0]);
  rtmSetTFinal(TestCinematicaz_M, 10.0);
  TestCinematicaz_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  TestCinematicaz_M->Sizes.checksums[0] = (4039819891U);
  TestCinematicaz_M->Sizes.checksums[1] = (1891520704U);
  TestCinematicaz_M->Sizes.checksums[2] = (3914924778U);
  TestCinematicaz_M->Sizes.checksums[3] = (453755577U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    TestCinematicaz_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(TestCinematicaz_M->extModeInfo,
      &TestCinematicaz_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TestCinematicaz_M->extModeInfo,
                        TestCinematicaz_M->Sizes.checksums);
    rteiSetTPtr(TestCinematicaz_M->extModeInfo, rtmGetTPtr(TestCinematicaz_M));
  }

  /* InitializeConditions for Memory: '<S3>/Memory1' */
  TestCinematicaz_DW.Memory1_PreviousInput[0] =
    TestCinematicaz_P.Memory1_InitialCondition;
  TestCinematicaz_DW.Memory1_PreviousInput[1] =
    TestCinematicaz_P.Memory1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S88>/Integrator' */
  TestCinematicaz_DW.Integrator_DSTATE =
    TestCinematicaz_P.PIDController2_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S40>/Integrator' */
  TestCinematicaz_DW.Integrator_DSTATE_h =
    TestCinematicaz_P.PIDController1_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  TestCinematicaz_DW.DiscreteTimeIntegrator_DSTATE[0] =
    TestCinematicaz_P.DiscreteTimeIntegrator_IC;
  TestCinematicaz_DW.DiscreteTimeIntegrator_DSTATE[1] =
    TestCinematicaz_P.DiscreteTimeIntegrator_IC;
  TestCinematicaz_DW.DiscreteTimeIntegrator_DSTATE[2] =
    TestCinematicaz_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for Derivative: '<S106>/Derivative' */
  TestCinematicaz_DW.TimeStampA = (rtInf);
  TestCinematicaz_DW.TimeStampB = (rtInf);

  /* Start for MATLABSystem: '<S107>/Adelante_der' */
  TestCinematicaz_DW.obj_m5.matlabCodegenIsDeleted = false;
  TestCinematicaz_DW.obj_m5.isInitialized = 1L;
  TestCinematicaz_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(12UL, 0.0,
    0.0);
  TestCinematicaz_DW.obj_m5.isSetupComplete = true;

  /* Start for MATLABSystem: '<S107>/Adelante_izq' */
  TestCinematicaz_DW.obj_dx.matlabCodegenIsDeleted = false;
  TestCinematicaz_DW.obj_dx.isInitialized = 1L;
  TestCinematicaz_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(9UL, 0.0,
    0.0);
  TestCinematicaz_DW.obj_dx.isSetupComplete = true;

  /* Start for MATLABSystem: '<S107>/Atras_der' */
  TestCinematicaz_DW.obj_b.matlabCodegenIsDeleted = false;
  TestCinematicaz_DW.obj_b.isInitialized = 1L;
  TestCinematicaz_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(11UL, 0.0,
    0.0);
  TestCinematicaz_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S107>/Atras_izq' */
  TestCinematicaz_DW.obj_m.matlabCodegenIsDeleted = false;
  TestCinematicaz_DW.obj_m.isInitialized = 1L;
  TestCinematicaz_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(10UL, 0.0,
    0.0);
  TestCinematicaz_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S107>/Digital Output' */
  TestCinematicaz_DW.obj_bt.matlabCodegenIsDeleted = false;
  TestCinematicaz_DW.obj_bt.isInitialized = 1L;
  digitalIOSetup(8, 1);
  TestCinematicaz_DW.obj_bt.isSetupComplete = true;

  /* Start for MATLABSystem: '<S107>/Digital Output1' */
  TestCinematicaz_DW.obj_l.matlabCodegenIsDeleted = false;
  TestCinematicaz_DW.obj_l.isInitialized = 1L;
  digitalIOSetup(13, 1);
  TestCinematicaz_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S106>/Encoder' */
  TestCinematicaz_DW.obj_d.Index = 0U;
  TestCinematicaz_DW.obj_d.matlabCodegenIsDeleted = false;
  TestCinematicaz_DW.obj_d.SampleTime = TestCinematicaz_P.Encoder_SampleTime;
  TestCinematicaz_DW.obj_d.isInitialized = 1L;
  MW_EncoderSetup(18UL, 19UL, &TestCinematicaz_DW.obj_d.Index);
  TestCinematicaz_DW.obj_d.isSetupComplete = true;
  TestCinematicaz_DW.obj_d.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S106>/Encoder' */
  MW_EncoderReset(TestCinematicaz_DW.obj_d.Index);

  /* Start for MATLABSystem: '<S106>/Encoder1' */
  TestCinematicaz_DW.obj.Index = 0U;
  TestCinematicaz_DW.obj.matlabCodegenIsDeleted = false;
  TestCinematicaz_DW.obj.SampleTime = TestCinematicaz_P.Encoder1_SampleTime;
  TestCinematicaz_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &TestCinematicaz_DW.obj.Index);
  TestCinematicaz_DW.obj.isSetupComplete = true;
  TestCinematicaz_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S106>/Encoder1' */
  MW_EncoderReset(TestCinematicaz_DW.obj.Index);
}

/* Model terminate function */
void TestCinematicaz_terminate(void)
{
  /* Terminate for MATLABSystem: '<S107>/Adelante_der' */
  if (!TestCinematicaz_DW.obj_m5.matlabCodegenIsDeleted) {
    TestCinematicaz_DW.obj_m5.matlabCodegenIsDeleted = true;
    if ((TestCinematicaz_DW.obj_m5.isInitialized == 1L) &&
        TestCinematicaz_DW.obj_m5.isSetupComplete) {
      TestCinematicaz_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_SetDutyCycle(TestCinematicaz_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      TestCinematicaz_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (12UL);
      MW_PWM_Close(TestCinematicaz_DW.obj_m5.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S107>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S107>/Adelante_izq' */
  if (!TestCinematicaz_DW.obj_dx.matlabCodegenIsDeleted) {
    TestCinematicaz_DW.obj_dx.matlabCodegenIsDeleted = true;
    if ((TestCinematicaz_DW.obj_dx.isInitialized == 1L) &&
        TestCinematicaz_DW.obj_dx.isSetupComplete) {
      TestCinematicaz_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);
      MW_PWM_SetDutyCycle(TestCinematicaz_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      TestCinematicaz_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (9UL);
      MW_PWM_Close(TestCinematicaz_DW.obj_dx.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S107>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S107>/Atras_der' */
  if (!TestCinematicaz_DW.obj_b.matlabCodegenIsDeleted) {
    TestCinematicaz_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((TestCinematicaz_DW.obj_b.isInitialized == 1L) &&
        TestCinematicaz_DW.obj_b.isSetupComplete) {
      TestCinematicaz_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_SetDutyCycle(TestCinematicaz_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      TestCinematicaz_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (11UL);
      MW_PWM_Close(TestCinematicaz_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S107>/Atras_der' */

  /* Terminate for MATLABSystem: '<S107>/Atras_izq' */
  if (!TestCinematicaz_DW.obj_m.matlabCodegenIsDeleted) {
    TestCinematicaz_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((TestCinematicaz_DW.obj_m.isInitialized == 1L) &&
        TestCinematicaz_DW.obj_m.isSetupComplete) {
      TestCinematicaz_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_SetDutyCycle(TestCinematicaz_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      TestCinematicaz_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (10UL);
      MW_PWM_Close(TestCinematicaz_DW.obj_m.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S107>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S107>/Digital Output' */
  if (!TestCinematicaz_DW.obj_bt.matlabCodegenIsDeleted) {
    TestCinematicaz_DW.obj_bt.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S107>/Digital Output' */

  /* Terminate for MATLABSystem: '<S107>/Digital Output1' */
  if (!TestCinematicaz_DW.obj_l.matlabCodegenIsDeleted) {
    TestCinematicaz_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S107>/Digital Output1' */
  /* Terminate for MATLABSystem: '<S106>/Encoder' */
  if (!TestCinematicaz_DW.obj_d.matlabCodegenIsDeleted) {
    TestCinematicaz_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((TestCinematicaz_DW.obj_d.isInitialized == 1L) &&
        TestCinematicaz_DW.obj_d.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/Encoder' */

  /* Terminate for MATLABSystem: '<S106>/Encoder1' */
  if (!TestCinematicaz_DW.obj.matlabCodegenIsDeleted) {
    TestCinematicaz_DW.obj.matlabCodegenIsDeleted = true;
    if ((TestCinematicaz_DW.obj.isInitialized == 1L) &&
        TestCinematicaz_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/Encoder1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
