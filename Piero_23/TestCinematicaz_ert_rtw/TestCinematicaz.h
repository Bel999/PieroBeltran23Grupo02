/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestCinematicaz.h
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

#ifndef RTW_HEADER_TestCinematicaz_h_
#define RTW_HEADER_TestCinematicaz_h_
#ifndef TestCinematicaz_COMMON_INCLUDES_
#define TestCinematicaz_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* TestCinematicaz_COMMON_INCLUDES_ */

#include "TestCinematicaz_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T rel[2];                       /* '<Root>/Constant' */
  real_T MatrixMultiply[2];            /* '<S1>/Matrix Multiply' */
  real_T error[2];                     /* '<S3>/Sum' */
  real_T Saturation;                   /* '<S95>/Saturation' */
  real_T Saturation_a;                 /* '<S47>/Saturation' */
  real_T pwm[2];
  /* '<S3>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Subsystem Reference_at_outport_0Inport1' */
  real_T DiscreteTimeIntegrator[3];    /* '<S4>/Discrete-Time Integrator' */
  real_T Gain[2];                      /* '<S106>/Gain' */
  real_T Derivative[2];                /* '<S106>/Derivative' */
  real_T MatrixMultiply_d[2];          /* '<S2>/Matrix Multiply' */
  real_T Vx;                           /* '<S4>/Product' */
  real_T Vy;                           /* '<S4>/Product1' */
  int32_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S106>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  int32_T Encoder1;                    /* '<S106>/Encoder1' */
  int32_T Encoder;                     /* '<S106>/Encoder' */
} B_TestCinematicaz_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S106>/Encoder1' */
  codertarget_arduinobase_inter_T obj_d;/* '<S106>/Encoder' */
  codertarget_arduinobase_int_b_T obj_m;/* '<S107>/Atras_izq' */
  codertarget_arduinobase_int_b_T obj_b;/* '<S107>/Atras_der' */
  codertarget_arduinobase_int_b_T obj_dx;/* '<S107>/Adelante_izq' */
  codertarget_arduinobase_int_b_T obj_m5;/* '<S107>/Adelante_der' */
  codertarget_arduinobase_block_T obj_l;/* '<S107>/Digital Output1' */
  codertarget_arduinobase_block_T obj_bt;/* '<S107>/Digital Output' */
  real_T Integrator_DSTATE;            /* '<S88>/Integrator' */
  real_T Integrator_DSTATE_h;          /* '<S40>/Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S4>/Discrete-Time Integrator' */
  real_T Memory1_PreviousInput[2];     /* '<S3>/Memory1' */
  real_T TimeStampA;                   /* '<S106>/Derivative' */
  real_T LastUAtTimeA[2];              /* '<S106>/Derivative' */
  real_T TimeStampB;                   /* '<S106>/Derivative' */
  real_T LastUAtTimeB[2];              /* '<S106>/Derivative' */
} DW_TestCinematicaz_T;

/* Parameters (default storage) */
struct P_TestCinematicaz_T_ {
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S37>/Integral Gain'
                                        */
  real_T PIDController2_I;             /* Mask Parameter: PIDController2_I
                                        * Referenced by: '<S85>/Integral Gain'
                                        */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S88>/Integrator'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S40>/Integrator'
                               */
  real_T PIDController2_LowerSaturationL;
                              /* Mask Parameter: PIDController2_LowerSaturationL
                               * Referenced by: '<S95>/Saturation'
                               */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S47>/Saturation'
                               */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S93>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S45>/Proportional Gain'
                                        */
  real_T PIDController2_UpperSaturationL;
                              /* Mask Parameter: PIDController2_UpperSaturationL
                               * Referenced by: '<S95>/Saturation'
                               */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S47>/Saturation'
                               */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S106>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S106>/Encoder1'
                                        */
  real_T Constant_Value[4];            /* Expression: [1 -d/2; 1 d/2]
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant_Value_j[2];          /* Expression: [0.25 2*pi/10]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S3>/Memory1'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S88>/Integrator'
                                        */
  real_T Integrator_gainval_k;       /* Computed Parameter: Integrator_gainval_k
                                      * Referenced by: '<S40>/Integrator'
                                      */
  real_T Constant_Value_b[4];          /* Expression: [1/2 1/2; -1/d 1/d]
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S4>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S4>/Discrete-Time Integrator'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S106>/Gain'
                                        */
  int16_T Constant_Value_k;            /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S108>/Constant'
                                        */
  int16_T Constant_Value_jh;           /* Computed Parameter: Constant_Value_jh
                                        * Referenced by: '<S109>/Constant'
                                        */
  int16_T Saturation2_UpperSat;      /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S107>/Saturation2'
                                      */
  int16_T Saturation2_LowerSat;      /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S107>/Saturation2'
                                      */
  int16_T Saturation4_UpperSat;      /* Computed Parameter: Saturation4_UpperSat
                                      * Referenced by: '<S107>/Saturation4'
                                      */
  int16_T Saturation4_LowerSat;      /* Computed Parameter: Saturation4_LowerSat
                                      * Referenced by: '<S107>/Saturation4'
                                      */
  int16_T Saturation3_UpperSat;      /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<S107>/Saturation3'
                                      */
  int16_T Saturation3_LowerSat;      /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<S107>/Saturation3'
                                      */
  int16_T Saturation5_UpperSat;      /* Computed Parameter: Saturation5_UpperSat
                                      * Referenced by: '<S107>/Saturation5'
                                      */
  int16_T Saturation5_LowerSat;      /* Computed Parameter: Saturation5_LowerSat
                                      * Referenced by: '<S107>/Saturation5'
                                      */
};

/* Real-time Model Data Structure */
struct tag_RTM_TestCinematicaz_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_TestCinematicaz_T TestCinematicaz_P;

/* Block signals (default storage) */
extern B_TestCinematicaz_T TestCinematicaz_B;

/* Block states (default storage) */
extern DW_TestCinematicaz_T TestCinematicaz_DW;

/* Model entry point functions */
extern void TestCinematicaz_initialize(void);
extern void TestCinematicaz_step(void);
extern void TestCinematicaz_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TestCinematicaz_T *const TestCinematicaz_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S107>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TestCinematicaz'
 * '<S1>'   : 'TestCinematicaz/Subsystem Reference1'
 * '<S2>'   : 'TestCinematicaz/Subsystem Reference2'
 * '<S3>'   : 'TestCinematicaz/Subsystem Reference3'
 * '<S4>'   : 'TestCinematicaz/Subsystem Reference4'
 * '<S5>'   : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference'
 * '<S6>'   : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference1'
 * '<S7>'   : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1'
 * '<S8>'   : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2'
 * '<S9>'   : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Anti-windup'
 * '<S10>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/D Gain'
 * '<S11>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Filter'
 * '<S12>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Filter ICs'
 * '<S13>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/I Gain'
 * '<S14>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Ideal P Gain'
 * '<S15>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Ideal P Gain Fdbk'
 * '<S16>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Integrator'
 * '<S17>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Integrator ICs'
 * '<S18>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/N Copy'
 * '<S19>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/N Gain'
 * '<S20>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/P Copy'
 * '<S21>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Parallel P Gain'
 * '<S22>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Reset Signal'
 * '<S23>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Saturation'
 * '<S24>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Saturation Fdbk'
 * '<S25>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Sum'
 * '<S26>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Sum Fdbk'
 * '<S27>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Tracking Mode'
 * '<S28>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Tracking Mode Sum'
 * '<S29>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Tsamp - Integral'
 * '<S30>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Tsamp - Ngain'
 * '<S31>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/postSat Signal'
 * '<S32>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/preSat Signal'
 * '<S33>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Anti-windup/Passthrough'
 * '<S34>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/D Gain/Disabled'
 * '<S35>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Filter/Disabled'
 * '<S36>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Filter ICs/Disabled'
 * '<S37>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/I Gain/Internal Parameters'
 * '<S38>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Ideal P Gain/Passthrough'
 * '<S39>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S40>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Integrator/Discrete'
 * '<S41>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Integrator ICs/Internal IC'
 * '<S42>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S43>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/N Gain/Disabled'
 * '<S44>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/P Copy/Disabled'
 * '<S45>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S46>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Reset Signal/Disabled'
 * '<S47>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Saturation/Enabled'
 * '<S48>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Saturation Fdbk/Disabled'
 * '<S49>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Sum/Sum_PI'
 * '<S50>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Sum Fdbk/Disabled'
 * '<S51>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Tracking Mode/Disabled'
 * '<S52>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S53>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S54>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S55>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/postSat Signal/Forward_Path'
 * '<S56>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller1/preSat Signal/Forward_Path'
 * '<S57>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Anti-windup'
 * '<S58>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/D Gain'
 * '<S59>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Filter'
 * '<S60>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Filter ICs'
 * '<S61>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/I Gain'
 * '<S62>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Ideal P Gain'
 * '<S63>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Ideal P Gain Fdbk'
 * '<S64>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Integrator'
 * '<S65>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Integrator ICs'
 * '<S66>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/N Copy'
 * '<S67>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/N Gain'
 * '<S68>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/P Copy'
 * '<S69>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Parallel P Gain'
 * '<S70>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Reset Signal'
 * '<S71>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Saturation'
 * '<S72>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Saturation Fdbk'
 * '<S73>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Sum'
 * '<S74>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Sum Fdbk'
 * '<S75>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Tracking Mode'
 * '<S76>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Tracking Mode Sum'
 * '<S77>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Tsamp - Integral'
 * '<S78>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Tsamp - Ngain'
 * '<S79>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/postSat Signal'
 * '<S80>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/preSat Signal'
 * '<S81>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Anti-windup/Passthrough'
 * '<S82>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/D Gain/Disabled'
 * '<S83>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Filter/Disabled'
 * '<S84>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Filter ICs/Disabled'
 * '<S85>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/I Gain/Internal Parameters'
 * '<S86>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Ideal P Gain/Passthrough'
 * '<S87>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S88>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Integrator/Discrete'
 * '<S89>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Integrator ICs/Internal IC'
 * '<S90>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S91>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/N Gain/Disabled'
 * '<S92>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/P Copy/Disabled'
 * '<S93>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S94>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Reset Signal/Disabled'
 * '<S95>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Saturation/Enabled'
 * '<S96>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Saturation Fdbk/Disabled'
 * '<S97>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Sum/Sum_PI'
 * '<S98>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Sum Fdbk/Disabled'
 * '<S99>'  : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Tracking Mode/Disabled'
 * '<S100>' : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S101>' : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S102>' : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S103>' : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/postSat Signal/Forward_Path'
 * '<S104>' : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference/PID Controller2/preSat Signal/Forward_Path'
 * '<S105>' : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference1/Subsystem Reference1'
 * '<S106>' : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference1/Subsystem Reference1/Subsystem Reference'
 * '<S107>' : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4'
 * '<S108>' : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4/Compare To Zero'
 * '<S109>' : 'TestCinematicaz/Subsystem Reference3/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_TestCinematicaz_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
