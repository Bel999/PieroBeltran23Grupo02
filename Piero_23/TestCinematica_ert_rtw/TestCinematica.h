/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TestCinematica.h
 *
 * Code generated for Simulink model 'TestCinematica'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 30 15:08:29 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TestCinematica_h_
#define RTW_HEADER_TestCinematica_h_
#ifndef TestCinematica_COMMON_INCLUDES_
#define TestCinematica_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* TestCinematica_COMMON_INCLUDES_ */

#include "TestCinematica_types.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"
#include "rtGetInf.h"
#include <string.h>
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
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

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T rel[2];                       /* '<Root>/Constant' */
  real_T error[2];                     /* '<S1>/Sum' */
  real_T ProportionalGain;             /* '<S45>/Proportional Gain' */
  real_T Saturation;                   /* '<S47>/Saturation' */
  real_T ProportionalGain_c;           /* '<S93>/Proportional Gain' */
  real_T Saturation_g;                 /* '<S95>/Saturation' */
  real_T pwm[2];
  /* '<S1>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Controlador_at_outport_0Inport1' */
  real_T IntegralGain;                 /* '<S37>/Integral Gain' */
  real_T IntegralGain_c;               /* '<S85>/Integral Gain' */
  real_T Integrator[3];                /* '<S4>/Integrator' */
  real_T Gain[2];                      /* '<S106>/Gain' */
  real_T Derivative[2];                /* '<S106>/Derivative' */
  real_T TmpSignalConversionAtIntegrator[3];
  int32_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S106>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  int32_T Encoder1;                    /* '<S106>/Encoder1' */
  int32_T Encoder;                     /* '<S106>/Encoder' */
} B_TestCinematica_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S106>/Encoder1' */
  codertarget_arduinobase_inter_T obj_d;/* '<S106>/Encoder' */
  codertarget_arduinobase_int_p_T obj_g;/* '<S107>/Atras_izq' */
  codertarget_arduinobase_int_p_T obj_h;/* '<S107>/Atras_der' */
  codertarget_arduinobase_int_p_T obj_f;/* '<S107>/Adelante_izq' */
  codertarget_arduinobase_int_p_T obj_ht;/* '<S107>/Adelante_der' */
  codertarget_arduinobase_block_T obj_a;/* '<S107>/Digital Output1' */
  codertarget_arduinobase_block_T obj_n;/* '<S107>/Digital Output' */
  real_T Memory_PreviousInput[2];      /* '<S1>/Memory' */
  real_T TimeStampA;                   /* '<S106>/Derivative' */
  real_T LastUAtTimeA[2];              /* '<S106>/Derivative' */
  real_T TimeStampB;                   /* '<S106>/Derivative' */
  real_T LastUAtTimeB[2];              /* '<S106>/Derivative' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_TestCinematica_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S40>/Integrator' */
  real_T Integrator_CSTATE_h;          /* '<S88>/Integrator' */
  real_T Integrator_CSTATE_n[3];       /* '<S4>/Integrator' */
} X_TestCinematica_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S40>/Integrator' */
  real_T Integrator_CSTATE_h;          /* '<S88>/Integrator' */
  real_T Integrator_CSTATE_n[3];       /* '<S4>/Integrator' */
} XDot_TestCinematica_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S40>/Integrator' */
  boolean_T Integrator_CSTATE_h;       /* '<S88>/Integrator' */
  boolean_T Integrator_CSTATE_n[3];    /* '<S4>/Integrator' */
} XDis_TestCinematica_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S40>/Integrator' */
} PrevZCX_TestCinematica_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_TestCinematica_T_ {
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S37>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S85>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S40>/Integrator'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S88>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S47>/Saturation'
                               */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S95>/Saturation'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S45>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S93>/Proportional Gain'
                                        */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S47>/Saturation'
                               */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S95>/Saturation'
                               */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S106>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S106>/Encoder1'
                                        */
  real_T Constant_Value[4];            /* Expression: [1 -d/2; 1 d/2]
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant_Value_j[2];          /* Expression: [0.25 2*pi/10]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Constant_Value_b[4];          /* Expression: [1/2 1/2; -1/d 1/d]
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  int32_T Constant_Value_bh;           /* Computed Parameter: Constant_Value_bh
                                        * Referenced by: '<S108>/Constant'
                                        */
  int32_T Saturation4_UpperSat;      /* Computed Parameter: Saturation4_UpperSat
                                      * Referenced by: '<S107>/Saturation4'
                                      */
  int32_T Saturation4_LowerSat;      /* Computed Parameter: Saturation4_LowerSat
                                      * Referenced by: '<S107>/Saturation4'
                                      */
  int32_T Saturation5_UpperSat;      /* Computed Parameter: Saturation5_UpperSat
                                      * Referenced by: '<S107>/Saturation5'
                                      */
  int32_T Saturation5_LowerSat;      /* Computed Parameter: Saturation5_LowerSat
                                      * Referenced by: '<S107>/Saturation5'
                                      */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S106>/Gain'
                                        */
  int16_T Constant_Value_a;            /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S109>/Constant'
                                        */
  int16_T Saturation2_UpperSat;      /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S107>/Saturation2'
                                      */
  int16_T Saturation2_LowerSat;      /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S107>/Saturation2'
                                      */
  int16_T Saturation3_UpperSat;      /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<S107>/Saturation3'
                                      */
  int16_T Saturation3_LowerSat;      /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<S107>/Saturation3'
                                      */
  int16_T Gain_Gain_o;                 /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S107>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TestCinematica_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_TestCinematica_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_TestCinematica_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[5];
  real_T odeF[3][5];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_TestCinematica_T TestCinematica_P;

/* Block signals (default storage) */
extern B_TestCinematica_T TestCinematica_B;

/* Continuous states (default storage) */
extern X_TestCinematica_T TestCinematica_X;

/* Disabled states (default storage) */
extern XDis_TestCinematica_T TestCinematica_XDis;

/* Block states (default storage) */
extern DW_TestCinematica_T TestCinematica_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_TestCinematica_T TestCinematica_PrevZCX;

/* Model entry point functions */
extern void TestCinematica_initialize(void);
extern void TestCinematica_step(void);
extern void TestCinematica_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TestCinematica_T *const TestCinematica_M;
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
 * '<Root>' : 'TestCinematica'
 * '<S1>'   : 'TestCinematica/Subsystem Reference'
 * '<S2>'   : 'TestCinematica/Subsystem Reference1'
 * '<S3>'   : 'TestCinematica/Subsystem Reference2'
 * '<S4>'   : 'TestCinematica/Subsystem Reference3'
 * '<S5>'   : 'TestCinematica/Subsystem Reference/Controlador'
 * '<S6>'   : 'TestCinematica/Subsystem Reference/Planta'
 * '<S7>'   : 'TestCinematica/Subsystem Reference/Controlador/PID Controller'
 * '<S8>'   : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1'
 * '<S9>'   : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Anti-windup'
 * '<S10>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/D Gain'
 * '<S11>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Filter'
 * '<S12>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Filter ICs'
 * '<S13>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/I Gain'
 * '<S14>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Ideal P Gain'
 * '<S15>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Ideal P Gain Fdbk'
 * '<S16>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Integrator'
 * '<S17>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Integrator ICs'
 * '<S18>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/N Copy'
 * '<S19>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/N Gain'
 * '<S20>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/P Copy'
 * '<S21>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Parallel P Gain'
 * '<S22>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Reset Signal'
 * '<S23>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Saturation'
 * '<S24>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Saturation Fdbk'
 * '<S25>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Sum'
 * '<S26>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Sum Fdbk'
 * '<S27>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Tracking Mode'
 * '<S28>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Tracking Mode Sum'
 * '<S29>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Tsamp - Integral'
 * '<S30>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Tsamp - Ngain'
 * '<S31>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/postSat Signal'
 * '<S32>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/preSat Signal'
 * '<S33>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Anti-windup/Passthrough'
 * '<S34>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/D Gain/Disabled'
 * '<S35>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Filter/Disabled'
 * '<S36>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Filter ICs/Disabled'
 * '<S37>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/I Gain/Internal Parameters'
 * '<S38>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Ideal P Gain/Passthrough'
 * '<S39>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S40>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Integrator/Continuous'
 * '<S41>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Integrator ICs/Internal IC'
 * '<S42>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S43>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/N Gain/Disabled'
 * '<S44>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/P Copy/Disabled'
 * '<S45>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S46>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Reset Signal/External Reset'
 * '<S47>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Saturation/Enabled'
 * '<S48>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Saturation Fdbk/Disabled'
 * '<S49>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Sum/Sum_PI'
 * '<S50>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Sum Fdbk/Disabled'
 * '<S51>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Tracking Mode/Disabled'
 * '<S52>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S53>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S54>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S55>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/postSat Signal/Forward_Path'
 * '<S56>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller/preSat Signal/Forward_Path'
 * '<S57>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Anti-windup'
 * '<S58>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/D Gain'
 * '<S59>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Filter'
 * '<S60>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Filter ICs'
 * '<S61>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/I Gain'
 * '<S62>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Ideal P Gain'
 * '<S63>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Ideal P Gain Fdbk'
 * '<S64>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Integrator'
 * '<S65>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Integrator ICs'
 * '<S66>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/N Copy'
 * '<S67>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/N Gain'
 * '<S68>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/P Copy'
 * '<S69>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Parallel P Gain'
 * '<S70>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Reset Signal'
 * '<S71>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Saturation'
 * '<S72>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Saturation Fdbk'
 * '<S73>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Sum'
 * '<S74>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Sum Fdbk'
 * '<S75>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Tracking Mode'
 * '<S76>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Tracking Mode Sum'
 * '<S77>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Tsamp - Integral'
 * '<S78>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Tsamp - Ngain'
 * '<S79>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/postSat Signal'
 * '<S80>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/preSat Signal'
 * '<S81>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Anti-windup/Passthrough'
 * '<S82>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/D Gain/Disabled'
 * '<S83>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Filter/Disabled'
 * '<S84>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Filter ICs/Disabled'
 * '<S85>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/I Gain/Internal Parameters'
 * '<S86>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Ideal P Gain/Passthrough'
 * '<S87>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S88>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Integrator/Continuous'
 * '<S89>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Integrator ICs/Internal IC'
 * '<S90>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S91>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/N Gain/Disabled'
 * '<S92>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/P Copy/Disabled'
 * '<S93>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S94>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Reset Signal/Disabled'
 * '<S95>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Saturation/Enabled'
 * '<S96>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Saturation Fdbk/Disabled'
 * '<S97>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Sum/Sum_PI'
 * '<S98>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Sum Fdbk/Disabled'
 * '<S99>'  : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Tracking Mode/Disabled'
 * '<S100>' : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S101>' : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S102>' : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S103>' : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/postSat Signal/Forward_Path'
 * '<S104>' : 'TestCinematica/Subsystem Reference/Controlador/PID Controller1/preSat Signal/Forward_Path'
 * '<S105>' : 'TestCinematica/Subsystem Reference/Planta/Subsystem Reference1'
 * '<S106>' : 'TestCinematica/Subsystem Reference/Planta/Subsystem Reference1/Subsystem Reference'
 * '<S107>' : 'TestCinematica/Subsystem Reference/Planta/Subsystem Reference1/Subsystem Reference4'
 * '<S108>' : 'TestCinematica/Subsystem Reference/Planta/Subsystem Reference1/Subsystem Reference4/Compare To Zero'
 * '<S109>' : 'TestCinematica/Subsystem Reference/Planta/Subsystem Reference1/Subsystem Reference4/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_TestCinematica_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
