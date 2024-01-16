/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlaBCs_Z.h
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

#ifndef RTW_HEADER_ControlaBCs_Z_h_
#define RTW_HEADER_ControlaBCs_Z_h_
#ifndef ControlaBCs_Z_COMMON_INCLUDES_
#define ControlaBCs_Z_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* ControlaBCs_Z_COMMON_INCLUDES_ */

#include "ControlaBCs_Z_types.h"
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
  real_T Gain[2];                      /* '<S4>/Gain' */
  real_T Derivative[2];                /* '<S4>/Derivative' */
  int32_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S4>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  int32_T Encoder1;                    /* '<S4>/Encoder1' */
  int32_T Encoder;                     /* '<S4>/Encoder' */
} B_ControlaBCs_Z_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S4>/Encoder1' */
  codertarget_arduinobase_inter_T obj_e;/* '<S4>/Encoder' */
  codertarget_arduinobase_int_l_T obj_d;/* '<S5>/Atras_izq' */
  codertarget_arduinobase_int_l_T obj_e5;/* '<S5>/Atras_der' */
  codertarget_arduinobase_int_l_T obj_m;/* '<S5>/Adelante_izq' */
  codertarget_arduinobase_int_l_T obj_k;/* '<S5>/Adelante_der' */
  codertarget_arduinobase_block_T obj_n;/* '<S5>/Digital Output1' */
  codertarget_arduinobase_block_T obj_p;/* '<S5>/Digital Output' */
  real_T Integrator_DSTATE;            /* '<S89>/Integrator' */
  real_T Integrator_DSTATE_i;          /* '<S41>/Integrator' */
  real_T TimeStampA;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeA[2];              /* '<S4>/Derivative' */
  real_T TimeStampB;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeB[2];              /* '<S4>/Derivative' */
  real_T Memory_PreviousInput[2];      /* '<Root>/Memory' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */
} DW_ControlaBCs_Z_T;

/* Parameters (default storage) */
struct P_ControlaBCs_Z_T_ {
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S38>/Integral Gain'
                                        */
  real_T PIDController2_I;             /* Mask Parameter: PIDController2_I
                                        * Referenced by: '<S86>/Integral Gain'
                                        */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S89>/Integrator'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S41>/Integrator'
                               */
  real_T PIDController2_LowerSaturationL;
                              /* Mask Parameter: PIDController2_LowerSaturationL
                               * Referenced by: '<S96>/Saturation'
                               */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S48>/Saturation'
                               */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S94>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S46>/Proportional Gain'
                                        */
  real_T PIDController2_UpperSaturationL;
                              /* Mask Parameter: PIDController2_UpperSaturationL
                               * Referenced by: '<S96>/Saturation'
                               */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S48>/Saturation'
                               */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S4>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S4>/Encoder1'
                                        */
  real_T Constant_Value[2];            /* Expression: [.205 .205]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S89>/Integrator'
                                        */
  real_T Integrator_gainval_k;       /* Computed Parameter: Integrator_gainval_k
                                      * Referenced by: '<S41>/Integrator'
                                      */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S4>/Gain'
                                        */
  int16_T Constant_Value_h;            /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S6>/Constant'
                                        */
  int16_T Constant_Value_g;            /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S7>/Constant'
                                        */
  int16_T Saturation2_UpperSat;      /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S5>/Saturation2'
                                      */
  int16_T Saturation2_LowerSat;      /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S5>/Saturation2'
                                      */
  int16_T Saturation4_UpperSat;      /* Computed Parameter: Saturation4_UpperSat
                                      * Referenced by: '<S5>/Saturation4'
                                      */
  int16_T Saturation4_LowerSat;      /* Computed Parameter: Saturation4_LowerSat
                                      * Referenced by: '<S5>/Saturation4'
                                      */
  int16_T Saturation3_UpperSat;      /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<S5>/Saturation3'
                                      */
  int16_T Saturation3_LowerSat;      /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<S5>/Saturation3'
                                      */
  int16_T Saturation5_UpperSat;      /* Computed Parameter: Saturation5_UpperSat
                                      * Referenced by: '<S5>/Saturation5'
                                      */
  int16_T Saturation5_LowerSat;      /* Computed Parameter: Saturation5_LowerSat
                                      * Referenced by: '<S5>/Saturation5'
                                      */
};

/* Real-time Model Data Structure */
struct tag_RTM_ControlaBCs_Z_T {
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
extern P_ControlaBCs_Z_T ControlaBCs_Z_P;

/* Block signals (default storage) */
extern B_ControlaBCs_Z_T ControlaBCs_Z_B;

/* Block states (default storage) */
extern DW_ControlaBCs_Z_T ControlaBCs_Z_DW;

/* Model entry point functions */
extern void ControlaBCs_Z_initialize(void);
extern void ControlaBCs_Z_step(void);
extern void ControlaBCs_Z_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ControlaBCs_Z_T *const ControlaBCs_Z_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'ControlaBCs_Z'
 * '<S1>'   : 'ControlaBCs_Z/Planta'
 * '<S2>'   : 'ControlaBCs_Z/Subsystem Reference'
 * '<S3>'   : 'ControlaBCs_Z/Planta/Subsystem Reference1'
 * '<S4>'   : 'ControlaBCs_Z/Planta/Subsystem Reference1/Subsystem Reference'
 * '<S5>'   : 'ControlaBCs_Z/Planta/Subsystem Reference1/Subsystem Reference4'
 * '<S6>'   : 'ControlaBCs_Z/Planta/Subsystem Reference1/Subsystem Reference4/Compare To Zero'
 * '<S7>'   : 'ControlaBCs_Z/Planta/Subsystem Reference1/Subsystem Reference4/Compare To Zero1'
 * '<S8>'   : 'ControlaBCs_Z/Subsystem Reference/PID Controller1'
 * '<S9>'   : 'ControlaBCs_Z/Subsystem Reference/PID Controller2'
 * '<S10>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Anti-windup'
 * '<S11>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/D Gain'
 * '<S12>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Filter'
 * '<S13>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Filter ICs'
 * '<S14>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/I Gain'
 * '<S15>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Ideal P Gain'
 * '<S16>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Ideal P Gain Fdbk'
 * '<S17>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Integrator'
 * '<S18>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Integrator ICs'
 * '<S19>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/N Copy'
 * '<S20>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/N Gain'
 * '<S21>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/P Copy'
 * '<S22>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Parallel P Gain'
 * '<S23>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Reset Signal'
 * '<S24>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Saturation'
 * '<S25>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Saturation Fdbk'
 * '<S26>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Sum'
 * '<S27>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Sum Fdbk'
 * '<S28>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Tracking Mode'
 * '<S29>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Tracking Mode Sum'
 * '<S30>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Tsamp - Integral'
 * '<S31>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Tsamp - Ngain'
 * '<S32>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/postSat Signal'
 * '<S33>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/preSat Signal'
 * '<S34>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Anti-windup/Passthrough'
 * '<S35>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/D Gain/Disabled'
 * '<S36>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Filter/Disabled'
 * '<S37>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Filter ICs/Disabled'
 * '<S38>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/I Gain/Internal Parameters'
 * '<S39>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Ideal P Gain/Passthrough'
 * '<S40>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Integrator/Discrete'
 * '<S42>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Integrator ICs/Internal IC'
 * '<S43>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S44>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/N Gain/Disabled'
 * '<S45>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/P Copy/Disabled'
 * '<S46>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S47>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Reset Signal/Disabled'
 * '<S48>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Saturation/Enabled'
 * '<S49>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Saturation Fdbk/Disabled'
 * '<S50>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Sum/Sum_PI'
 * '<S51>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Sum Fdbk/Disabled'
 * '<S52>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Tracking Mode/Disabled'
 * '<S53>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S55>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/postSat Signal/Forward_Path'
 * '<S57>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller1/preSat Signal/Forward_Path'
 * '<S58>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Anti-windup'
 * '<S59>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/D Gain'
 * '<S60>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Filter'
 * '<S61>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Filter ICs'
 * '<S62>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/I Gain'
 * '<S63>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Ideal P Gain'
 * '<S64>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Ideal P Gain Fdbk'
 * '<S65>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Integrator'
 * '<S66>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Integrator ICs'
 * '<S67>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/N Copy'
 * '<S68>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/N Gain'
 * '<S69>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/P Copy'
 * '<S70>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Parallel P Gain'
 * '<S71>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Reset Signal'
 * '<S72>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Saturation'
 * '<S73>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Saturation Fdbk'
 * '<S74>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Sum'
 * '<S75>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Sum Fdbk'
 * '<S76>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Tracking Mode'
 * '<S77>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Tracking Mode Sum'
 * '<S78>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Tsamp - Integral'
 * '<S79>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Tsamp - Ngain'
 * '<S80>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/postSat Signal'
 * '<S81>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/preSat Signal'
 * '<S82>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Anti-windup/Passthrough'
 * '<S83>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/D Gain/Disabled'
 * '<S84>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Filter/Disabled'
 * '<S85>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Filter ICs/Disabled'
 * '<S86>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/I Gain/Internal Parameters'
 * '<S87>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Ideal P Gain/Passthrough'
 * '<S88>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S89>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Integrator/Discrete'
 * '<S90>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Integrator ICs/Internal IC'
 * '<S91>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S92>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/N Gain/Disabled'
 * '<S93>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/P Copy/Disabled'
 * '<S94>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S95>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Reset Signal/Disabled'
 * '<S96>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Saturation/Enabled'
 * '<S97>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Saturation Fdbk/Disabled'
 * '<S98>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Sum/Sum_PI'
 * '<S99>'  : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Sum Fdbk/Disabled'
 * '<S100>' : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Tracking Mode/Disabled'
 * '<S101>' : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S102>' : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S103>' : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S104>' : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/postSat Signal/Forward_Path'
 * '<S105>' : 'ControlaBCs_Z/Subsystem Reference/PID Controller2/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_ControlaBCs_Z_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
