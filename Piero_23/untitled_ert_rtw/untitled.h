/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.h
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

#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include "untitled_types.h"
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
  real_T Gain[2];                      /* '<S102>/Gain' */
  real_T Derivative[2];                /* '<S102>/Derivative' */
  int32_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S102>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  int32_T Encoder1;                    /* '<S102>/Encoder1' */
  int32_T Encoder;                     /* '<S102>/Encoder' */
} B_untitled_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S102>/Encoder1' */
  codertarget_arduinobase_inter_T obj_k;/* '<S102>/Encoder' */
  codertarget_arduinobase_int_b_T obj_o;/* '<S103>/Atras_izq' */
  codertarget_arduinobase_int_b_T obj_j;/* '<S103>/Atras_der' */
  codertarget_arduinobase_int_b_T obj_kh;/* '<S103>/Adelante_izq' */
  codertarget_arduinobase_int_b_T obj_f;/* '<S103>/Adelante_der' */
  codertarget_arduinobase_block_T obj_n;/* '<S103>/Digital Output1' */
  codertarget_arduinobase_block_T obj_b;/* '<S103>/Digital Output' */
  real_T Integrator_DSTATE;            /* '<S36>/Integrator' */
  real_T Integrator_DSTATE_c;          /* '<S84>/Integrator' */
  real_T TimeStampA;                   /* '<S102>/Derivative' */
  real_T LastUAtTimeA[2];              /* '<S102>/Derivative' */
  real_T TimeStampB;                   /* '<S102>/Derivative' */
  real_T LastUAtTimeB[2];              /* '<S102>/Derivative' */
  real_T Memory1_PreviousInput[2];     /* '<Root>/Memory1' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */
} DW_untitled_T;

/* Parameters (default storage) */
struct P_untitled_T_ {
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S33>/Integral Gain'
                                        */
  real_T PIDController2_I;             /* Mask Parameter: PIDController2_I
                                        * Referenced by: '<S81>/Integral Gain'
                                        */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S36>/Integrator'
                               */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S84>/Integrator'
                               */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S43>/Saturation'
                               */
  real_T PIDController2_LowerSaturationL;
                              /* Mask Parameter: PIDController2_LowerSaturationL
                               * Referenced by: '<S91>/Saturation'
                               */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S41>/Proportional Gain'
                                        */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S89>/Proportional Gain'
                                        */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S43>/Saturation'
                               */
  real_T PIDController2_UpperSaturationL;
                              /* Mask Parameter: PIDController2_UpperSaturationL
                               * Referenced by: '<S91>/Saturation'
                               */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S102>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S102>/Encoder1'
                                        */
  real_T Constant1_Value[2];           /* Expression: [.205 .205]
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S36>/Integrator'
                                        */
  real_T Integrator_gainval_k;       /* Computed Parameter: Integrator_gainval_k
                                      * Referenced by: '<S84>/Integrator'
                                      */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S102>/Gain'
                                        */
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S104>/Constant'
                                        */
  int16_T Constant_Value_h;            /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S105>/Constant'
                                        */
  int16_T Saturation2_UpperSat;      /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S103>/Saturation2'
                                      */
  int16_T Saturation2_LowerSat;      /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S103>/Saturation2'
                                      */
  int16_T Saturation4_UpperSat;      /* Computed Parameter: Saturation4_UpperSat
                                      * Referenced by: '<S103>/Saturation4'
                                      */
  int16_T Saturation4_LowerSat;      /* Computed Parameter: Saturation4_LowerSat
                                      * Referenced by: '<S103>/Saturation4'
                                      */
  int16_T Saturation3_UpperSat;      /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<S103>/Saturation3'
                                      */
  int16_T Saturation3_LowerSat;      /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<S103>/Saturation3'
                                      */
  int16_T Saturation5_UpperSat;      /* Computed Parameter: Saturation5_UpperSat
                                      * Referenced by: '<S103>/Saturation5'
                                      */
  int16_T Saturation5_LowerSat;      /* Computed Parameter: Saturation5_LowerSat
                                      * Referenced by: '<S103>/Saturation5'
                                      */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
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
extern P_untitled_T untitled_P;

/* Block signals (default storage) */
extern B_untitled_T untitled_B;

/* Block states (default storage) */
extern DW_untitled_T untitled_DW;

/* Model entry point functions */
extern void untitled_initialize(void);
extern void untitled_step(void);
extern void untitled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled_T *const untitled_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S103>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/Subsystem Reference2'
 * '<S2>'   : 'untitled/Subsystem Reference3'
 * '<S3>'   : 'untitled/Subsystem Reference2/PID Controller1'
 * '<S4>'   : 'untitled/Subsystem Reference2/PID Controller2'
 * '<S5>'   : 'untitled/Subsystem Reference2/PID Controller1/Anti-windup'
 * '<S6>'   : 'untitled/Subsystem Reference2/PID Controller1/D Gain'
 * '<S7>'   : 'untitled/Subsystem Reference2/PID Controller1/Filter'
 * '<S8>'   : 'untitled/Subsystem Reference2/PID Controller1/Filter ICs'
 * '<S9>'   : 'untitled/Subsystem Reference2/PID Controller1/I Gain'
 * '<S10>'  : 'untitled/Subsystem Reference2/PID Controller1/Ideal P Gain'
 * '<S11>'  : 'untitled/Subsystem Reference2/PID Controller1/Ideal P Gain Fdbk'
 * '<S12>'  : 'untitled/Subsystem Reference2/PID Controller1/Integrator'
 * '<S13>'  : 'untitled/Subsystem Reference2/PID Controller1/Integrator ICs'
 * '<S14>'  : 'untitled/Subsystem Reference2/PID Controller1/N Copy'
 * '<S15>'  : 'untitled/Subsystem Reference2/PID Controller1/N Gain'
 * '<S16>'  : 'untitled/Subsystem Reference2/PID Controller1/P Copy'
 * '<S17>'  : 'untitled/Subsystem Reference2/PID Controller1/Parallel P Gain'
 * '<S18>'  : 'untitled/Subsystem Reference2/PID Controller1/Reset Signal'
 * '<S19>'  : 'untitled/Subsystem Reference2/PID Controller1/Saturation'
 * '<S20>'  : 'untitled/Subsystem Reference2/PID Controller1/Saturation Fdbk'
 * '<S21>'  : 'untitled/Subsystem Reference2/PID Controller1/Sum'
 * '<S22>'  : 'untitled/Subsystem Reference2/PID Controller1/Sum Fdbk'
 * '<S23>'  : 'untitled/Subsystem Reference2/PID Controller1/Tracking Mode'
 * '<S24>'  : 'untitled/Subsystem Reference2/PID Controller1/Tracking Mode Sum'
 * '<S25>'  : 'untitled/Subsystem Reference2/PID Controller1/Tsamp - Integral'
 * '<S26>'  : 'untitled/Subsystem Reference2/PID Controller1/Tsamp - Ngain'
 * '<S27>'  : 'untitled/Subsystem Reference2/PID Controller1/postSat Signal'
 * '<S28>'  : 'untitled/Subsystem Reference2/PID Controller1/preSat Signal'
 * '<S29>'  : 'untitled/Subsystem Reference2/PID Controller1/Anti-windup/Passthrough'
 * '<S30>'  : 'untitled/Subsystem Reference2/PID Controller1/D Gain/Disabled'
 * '<S31>'  : 'untitled/Subsystem Reference2/PID Controller1/Filter/Disabled'
 * '<S32>'  : 'untitled/Subsystem Reference2/PID Controller1/Filter ICs/Disabled'
 * '<S33>'  : 'untitled/Subsystem Reference2/PID Controller1/I Gain/Internal Parameters'
 * '<S34>'  : 'untitled/Subsystem Reference2/PID Controller1/Ideal P Gain/Passthrough'
 * '<S35>'  : 'untitled/Subsystem Reference2/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'untitled/Subsystem Reference2/PID Controller1/Integrator/Discrete'
 * '<S37>'  : 'untitled/Subsystem Reference2/PID Controller1/Integrator ICs/Internal IC'
 * '<S38>'  : 'untitled/Subsystem Reference2/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S39>'  : 'untitled/Subsystem Reference2/PID Controller1/N Gain/Disabled'
 * '<S40>'  : 'untitled/Subsystem Reference2/PID Controller1/P Copy/Disabled'
 * '<S41>'  : 'untitled/Subsystem Reference2/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S42>'  : 'untitled/Subsystem Reference2/PID Controller1/Reset Signal/Disabled'
 * '<S43>'  : 'untitled/Subsystem Reference2/PID Controller1/Saturation/Enabled'
 * '<S44>'  : 'untitled/Subsystem Reference2/PID Controller1/Saturation Fdbk/Disabled'
 * '<S45>'  : 'untitled/Subsystem Reference2/PID Controller1/Sum/Sum_PI'
 * '<S46>'  : 'untitled/Subsystem Reference2/PID Controller1/Sum Fdbk/Disabled'
 * '<S47>'  : 'untitled/Subsystem Reference2/PID Controller1/Tracking Mode/Disabled'
 * '<S48>'  : 'untitled/Subsystem Reference2/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'untitled/Subsystem Reference2/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S50>'  : 'untitled/Subsystem Reference2/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'untitled/Subsystem Reference2/PID Controller1/postSat Signal/Forward_Path'
 * '<S52>'  : 'untitled/Subsystem Reference2/PID Controller1/preSat Signal/Forward_Path'
 * '<S53>'  : 'untitled/Subsystem Reference2/PID Controller2/Anti-windup'
 * '<S54>'  : 'untitled/Subsystem Reference2/PID Controller2/D Gain'
 * '<S55>'  : 'untitled/Subsystem Reference2/PID Controller2/Filter'
 * '<S56>'  : 'untitled/Subsystem Reference2/PID Controller2/Filter ICs'
 * '<S57>'  : 'untitled/Subsystem Reference2/PID Controller2/I Gain'
 * '<S58>'  : 'untitled/Subsystem Reference2/PID Controller2/Ideal P Gain'
 * '<S59>'  : 'untitled/Subsystem Reference2/PID Controller2/Ideal P Gain Fdbk'
 * '<S60>'  : 'untitled/Subsystem Reference2/PID Controller2/Integrator'
 * '<S61>'  : 'untitled/Subsystem Reference2/PID Controller2/Integrator ICs'
 * '<S62>'  : 'untitled/Subsystem Reference2/PID Controller2/N Copy'
 * '<S63>'  : 'untitled/Subsystem Reference2/PID Controller2/N Gain'
 * '<S64>'  : 'untitled/Subsystem Reference2/PID Controller2/P Copy'
 * '<S65>'  : 'untitled/Subsystem Reference2/PID Controller2/Parallel P Gain'
 * '<S66>'  : 'untitled/Subsystem Reference2/PID Controller2/Reset Signal'
 * '<S67>'  : 'untitled/Subsystem Reference2/PID Controller2/Saturation'
 * '<S68>'  : 'untitled/Subsystem Reference2/PID Controller2/Saturation Fdbk'
 * '<S69>'  : 'untitled/Subsystem Reference2/PID Controller2/Sum'
 * '<S70>'  : 'untitled/Subsystem Reference2/PID Controller2/Sum Fdbk'
 * '<S71>'  : 'untitled/Subsystem Reference2/PID Controller2/Tracking Mode'
 * '<S72>'  : 'untitled/Subsystem Reference2/PID Controller2/Tracking Mode Sum'
 * '<S73>'  : 'untitled/Subsystem Reference2/PID Controller2/Tsamp - Integral'
 * '<S74>'  : 'untitled/Subsystem Reference2/PID Controller2/Tsamp - Ngain'
 * '<S75>'  : 'untitled/Subsystem Reference2/PID Controller2/postSat Signal'
 * '<S76>'  : 'untitled/Subsystem Reference2/PID Controller2/preSat Signal'
 * '<S77>'  : 'untitled/Subsystem Reference2/PID Controller2/Anti-windup/Passthrough'
 * '<S78>'  : 'untitled/Subsystem Reference2/PID Controller2/D Gain/Disabled'
 * '<S79>'  : 'untitled/Subsystem Reference2/PID Controller2/Filter/Disabled'
 * '<S80>'  : 'untitled/Subsystem Reference2/PID Controller2/Filter ICs/Disabled'
 * '<S81>'  : 'untitled/Subsystem Reference2/PID Controller2/I Gain/Internal Parameters'
 * '<S82>'  : 'untitled/Subsystem Reference2/PID Controller2/Ideal P Gain/Passthrough'
 * '<S83>'  : 'untitled/Subsystem Reference2/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S84>'  : 'untitled/Subsystem Reference2/PID Controller2/Integrator/Discrete'
 * '<S85>'  : 'untitled/Subsystem Reference2/PID Controller2/Integrator ICs/Internal IC'
 * '<S86>'  : 'untitled/Subsystem Reference2/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S87>'  : 'untitled/Subsystem Reference2/PID Controller2/N Gain/Disabled'
 * '<S88>'  : 'untitled/Subsystem Reference2/PID Controller2/P Copy/Disabled'
 * '<S89>'  : 'untitled/Subsystem Reference2/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S90>'  : 'untitled/Subsystem Reference2/PID Controller2/Reset Signal/Disabled'
 * '<S91>'  : 'untitled/Subsystem Reference2/PID Controller2/Saturation/Enabled'
 * '<S92>'  : 'untitled/Subsystem Reference2/PID Controller2/Saturation Fdbk/Disabled'
 * '<S93>'  : 'untitled/Subsystem Reference2/PID Controller2/Sum/Sum_PI'
 * '<S94>'  : 'untitled/Subsystem Reference2/PID Controller2/Sum Fdbk/Disabled'
 * '<S95>'  : 'untitled/Subsystem Reference2/PID Controller2/Tracking Mode/Disabled'
 * '<S96>'  : 'untitled/Subsystem Reference2/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S97>'  : 'untitled/Subsystem Reference2/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S98>'  : 'untitled/Subsystem Reference2/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S99>'  : 'untitled/Subsystem Reference2/PID Controller2/postSat Signal/Forward_Path'
 * '<S100>' : 'untitled/Subsystem Reference2/PID Controller2/preSat Signal/Forward_Path'
 * '<S101>' : 'untitled/Subsystem Reference3/Subsystem Reference1'
 * '<S102>' : 'untitled/Subsystem Reference3/Subsystem Reference1/Subsystem Reference'
 * '<S103>' : 'untitled/Subsystem Reference3/Subsystem Reference1/Subsystem Reference4'
 * '<S104>' : 'untitled/Subsystem Reference3/Subsystem Reference1/Subsystem Reference4/Compare To Zero'
 * '<S105>' : 'untitled/Subsystem Reference3/Subsystem Reference1/Subsystem Reference4/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_untitled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
