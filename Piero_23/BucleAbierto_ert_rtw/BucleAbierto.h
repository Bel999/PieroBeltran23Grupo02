/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: BucleAbierto.h
 *
 * Code generated for Simulink model 'BucleAbierto'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 30 01:15:24 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BucleAbierto_h_
#define RTW_HEADER_BucleAbierto_h_
#ifndef BucleAbierto_COMMON_INCLUDES_
#define BucleAbierto_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#endif                                 /* BucleAbierto_COMMON_INCLUDES_ */

#include "BucleAbierto_types.h"
#include "rt_zcfcn.h"
#include <string.h>
#include "rt_nonfinite.h"
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
  real_T Rizq;                         /* '<S101>/Rizq' */
  real_T Rder;                         /* '<S101>/Rder' */
  real_T vel[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Planta_at_outport_0Inport1' */
  real_T error[2];                     /* '<Root>/Sum' */
  real_T ProportionalGain;             /* '<S41>/Proportional Gain' */
  real_T DerivativeGain;               /* '<S30>/Derivative Gain' */
  real_T FilterCoefficient;            /* '<S39>/Filter Coefficient' */
  real_T Saturation;                   /* '<S43>/Saturation' */
  real_T ProportionalGain_d;           /* '<S89>/Proportional Gain' */
  real_T Saturation_f;                 /* '<S91>/Saturation' */
  real_T pwm[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Controlador_at_outport_0Inport1' */
  real_T DataTypeConversion[2];        /* '<S101>/Data Type Conversion' */
  real_T IntegralGain;                 /* '<S33>/Integral Gain' */
  real_T IntegralGain_c;               /* '<S81>/Integral Gain' */
} B_BucleAbierto_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory1_PreviousInput[2];     /* '<Root>/Memory1' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_BucleAbierto_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Rizq_CSTATE;                  /* '<S101>/Rizq' */
  real_T Rder_CSTATE;                  /* '<S101>/Rder' */
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Integrator_CSTATE_g;          /* '<S84>/Integrator' */
} X_BucleAbierto_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Rizq_CSTATE;                  /* '<S101>/Rizq' */
  real_T Rder_CSTATE;                  /* '<S101>/Rder' */
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Integrator_CSTATE_g;          /* '<S84>/Integrator' */
} XDot_BucleAbierto_T;

/* State disabled  */
typedef struct {
  boolean_T Rizq_CSTATE;               /* '<S101>/Rizq' */
  boolean_T Rder_CSTATE;               /* '<S101>/Rder' */
  boolean_T Integrator_CSTATE;         /* '<S36>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S31>/Filter' */
  boolean_T Integrator_CSTATE_g;       /* '<S84>/Integrator' */
} XDis_BucleAbierto_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S36>/Integrator' */
  ZCSigState Filter_Reset_ZCE;         /* '<S31>/Filter' */
} PrevZCX_BucleAbierto_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_BucleAbierto_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S30>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S33>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S81>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S31>/Filter'
                               */
  real_T PIDController_InitialConditio_c;
                              /* Mask Parameter: PIDController_InitialConditio_c
                               * Referenced by: '<S36>/Integrator'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S84>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S43>/Saturation'
                               */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S91>/Saturation'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S39>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S41>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S89>/Proportional Gain'
                                        */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S43>/Saturation'
                               */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S91>/Saturation'
                               */
  real_T Constant_Value[2];            /* Expression: [.205 .205]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Rizq_A;                       /* Computed Parameter: Rizq_A
                                        * Referenced by: '<S101>/Rizq'
                                        */
  real_T Rizq_C;                       /* Computed Parameter: Rizq_C
                                        * Referenced by: '<S101>/Rizq'
                                        */
  real_T Rder_A;                       /* Computed Parameter: Rder_A
                                        * Referenced by: '<S101>/Rder'
                                        */
  real_T Rder_C;                       /* Computed Parameter: Rder_C
                                        * Referenced by: '<S101>/Rder'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<Root>/Memory1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_BucleAbierto_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_BucleAbierto_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_BucleAbierto_T *contStateDisabled;
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
extern P_BucleAbierto_T BucleAbierto_P;

/* Block signals (default storage) */
extern B_BucleAbierto_T BucleAbierto_B;

/* Continuous states (default storage) */
extern X_BucleAbierto_T BucleAbierto_X;

/* Disabled states (default storage) */
extern XDis_BucleAbierto_T BucleAbierto_XDis;

/* Block states (default storage) */
extern DW_BucleAbierto_T BucleAbierto_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_BucleAbierto_T BucleAbierto_PrevZCX;

/* Model entry point functions */
extern void BucleAbierto_initialize(void);
extern void BucleAbierto_step(void);
extern void BucleAbierto_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BucleAbierto_T *const BucleAbierto_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'BucleAbierto'
 * '<S1>'   : 'BucleAbierto/Controlador'
 * '<S2>'   : 'BucleAbierto/Planta'
 * '<S3>'   : 'BucleAbierto/Controlador/PID Controller'
 * '<S4>'   : 'BucleAbierto/Controlador/PID Controller1'
 * '<S5>'   : 'BucleAbierto/Controlador/PID Controller/Anti-windup'
 * '<S6>'   : 'BucleAbierto/Controlador/PID Controller/D Gain'
 * '<S7>'   : 'BucleAbierto/Controlador/PID Controller/Filter'
 * '<S8>'   : 'BucleAbierto/Controlador/PID Controller/Filter ICs'
 * '<S9>'   : 'BucleAbierto/Controlador/PID Controller/I Gain'
 * '<S10>'  : 'BucleAbierto/Controlador/PID Controller/Ideal P Gain'
 * '<S11>'  : 'BucleAbierto/Controlador/PID Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'BucleAbierto/Controlador/PID Controller/Integrator'
 * '<S13>'  : 'BucleAbierto/Controlador/PID Controller/Integrator ICs'
 * '<S14>'  : 'BucleAbierto/Controlador/PID Controller/N Copy'
 * '<S15>'  : 'BucleAbierto/Controlador/PID Controller/N Gain'
 * '<S16>'  : 'BucleAbierto/Controlador/PID Controller/P Copy'
 * '<S17>'  : 'BucleAbierto/Controlador/PID Controller/Parallel P Gain'
 * '<S18>'  : 'BucleAbierto/Controlador/PID Controller/Reset Signal'
 * '<S19>'  : 'BucleAbierto/Controlador/PID Controller/Saturation'
 * '<S20>'  : 'BucleAbierto/Controlador/PID Controller/Saturation Fdbk'
 * '<S21>'  : 'BucleAbierto/Controlador/PID Controller/Sum'
 * '<S22>'  : 'BucleAbierto/Controlador/PID Controller/Sum Fdbk'
 * '<S23>'  : 'BucleAbierto/Controlador/PID Controller/Tracking Mode'
 * '<S24>'  : 'BucleAbierto/Controlador/PID Controller/Tracking Mode Sum'
 * '<S25>'  : 'BucleAbierto/Controlador/PID Controller/Tsamp - Integral'
 * '<S26>'  : 'BucleAbierto/Controlador/PID Controller/Tsamp - Ngain'
 * '<S27>'  : 'BucleAbierto/Controlador/PID Controller/postSat Signal'
 * '<S28>'  : 'BucleAbierto/Controlador/PID Controller/preSat Signal'
 * '<S29>'  : 'BucleAbierto/Controlador/PID Controller/Anti-windup/Passthrough'
 * '<S30>'  : 'BucleAbierto/Controlador/PID Controller/D Gain/Internal Parameters'
 * '<S31>'  : 'BucleAbierto/Controlador/PID Controller/Filter/Cont. Filter'
 * '<S32>'  : 'BucleAbierto/Controlador/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S33>'  : 'BucleAbierto/Controlador/PID Controller/I Gain/Internal Parameters'
 * '<S34>'  : 'BucleAbierto/Controlador/PID Controller/Ideal P Gain/Passthrough'
 * '<S35>'  : 'BucleAbierto/Controlador/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'BucleAbierto/Controlador/PID Controller/Integrator/Continuous'
 * '<S37>'  : 'BucleAbierto/Controlador/PID Controller/Integrator ICs/Internal IC'
 * '<S38>'  : 'BucleAbierto/Controlador/PID Controller/N Copy/Disabled'
 * '<S39>'  : 'BucleAbierto/Controlador/PID Controller/N Gain/Internal Parameters'
 * '<S40>'  : 'BucleAbierto/Controlador/PID Controller/P Copy/Disabled'
 * '<S41>'  : 'BucleAbierto/Controlador/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S42>'  : 'BucleAbierto/Controlador/PID Controller/Reset Signal/External Reset'
 * '<S43>'  : 'BucleAbierto/Controlador/PID Controller/Saturation/Enabled'
 * '<S44>'  : 'BucleAbierto/Controlador/PID Controller/Saturation Fdbk/Disabled'
 * '<S45>'  : 'BucleAbierto/Controlador/PID Controller/Sum/Sum_PID'
 * '<S46>'  : 'BucleAbierto/Controlador/PID Controller/Sum Fdbk/Disabled'
 * '<S47>'  : 'BucleAbierto/Controlador/PID Controller/Tracking Mode/Disabled'
 * '<S48>'  : 'BucleAbierto/Controlador/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'BucleAbierto/Controlador/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S50>'  : 'BucleAbierto/Controlador/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'BucleAbierto/Controlador/PID Controller/postSat Signal/Forward_Path'
 * '<S52>'  : 'BucleAbierto/Controlador/PID Controller/preSat Signal/Forward_Path'
 * '<S53>'  : 'BucleAbierto/Controlador/PID Controller1/Anti-windup'
 * '<S54>'  : 'BucleAbierto/Controlador/PID Controller1/D Gain'
 * '<S55>'  : 'BucleAbierto/Controlador/PID Controller1/Filter'
 * '<S56>'  : 'BucleAbierto/Controlador/PID Controller1/Filter ICs'
 * '<S57>'  : 'BucleAbierto/Controlador/PID Controller1/I Gain'
 * '<S58>'  : 'BucleAbierto/Controlador/PID Controller1/Ideal P Gain'
 * '<S59>'  : 'BucleAbierto/Controlador/PID Controller1/Ideal P Gain Fdbk'
 * '<S60>'  : 'BucleAbierto/Controlador/PID Controller1/Integrator'
 * '<S61>'  : 'BucleAbierto/Controlador/PID Controller1/Integrator ICs'
 * '<S62>'  : 'BucleAbierto/Controlador/PID Controller1/N Copy'
 * '<S63>'  : 'BucleAbierto/Controlador/PID Controller1/N Gain'
 * '<S64>'  : 'BucleAbierto/Controlador/PID Controller1/P Copy'
 * '<S65>'  : 'BucleAbierto/Controlador/PID Controller1/Parallel P Gain'
 * '<S66>'  : 'BucleAbierto/Controlador/PID Controller1/Reset Signal'
 * '<S67>'  : 'BucleAbierto/Controlador/PID Controller1/Saturation'
 * '<S68>'  : 'BucleAbierto/Controlador/PID Controller1/Saturation Fdbk'
 * '<S69>'  : 'BucleAbierto/Controlador/PID Controller1/Sum'
 * '<S70>'  : 'BucleAbierto/Controlador/PID Controller1/Sum Fdbk'
 * '<S71>'  : 'BucleAbierto/Controlador/PID Controller1/Tracking Mode'
 * '<S72>'  : 'BucleAbierto/Controlador/PID Controller1/Tracking Mode Sum'
 * '<S73>'  : 'BucleAbierto/Controlador/PID Controller1/Tsamp - Integral'
 * '<S74>'  : 'BucleAbierto/Controlador/PID Controller1/Tsamp - Ngain'
 * '<S75>'  : 'BucleAbierto/Controlador/PID Controller1/postSat Signal'
 * '<S76>'  : 'BucleAbierto/Controlador/PID Controller1/preSat Signal'
 * '<S77>'  : 'BucleAbierto/Controlador/PID Controller1/Anti-windup/Passthrough'
 * '<S78>'  : 'BucleAbierto/Controlador/PID Controller1/D Gain/Disabled'
 * '<S79>'  : 'BucleAbierto/Controlador/PID Controller1/Filter/Disabled'
 * '<S80>'  : 'BucleAbierto/Controlador/PID Controller1/Filter ICs/Disabled'
 * '<S81>'  : 'BucleAbierto/Controlador/PID Controller1/I Gain/Internal Parameters'
 * '<S82>'  : 'BucleAbierto/Controlador/PID Controller1/Ideal P Gain/Passthrough'
 * '<S83>'  : 'BucleAbierto/Controlador/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S84>'  : 'BucleAbierto/Controlador/PID Controller1/Integrator/Continuous'
 * '<S85>'  : 'BucleAbierto/Controlador/PID Controller1/Integrator ICs/Internal IC'
 * '<S86>'  : 'BucleAbierto/Controlador/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S87>'  : 'BucleAbierto/Controlador/PID Controller1/N Gain/Disabled'
 * '<S88>'  : 'BucleAbierto/Controlador/PID Controller1/P Copy/Disabled'
 * '<S89>'  : 'BucleAbierto/Controlador/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S90>'  : 'BucleAbierto/Controlador/PID Controller1/Reset Signal/Disabled'
 * '<S91>'  : 'BucleAbierto/Controlador/PID Controller1/Saturation/Enabled'
 * '<S92>'  : 'BucleAbierto/Controlador/PID Controller1/Saturation Fdbk/Disabled'
 * '<S93>'  : 'BucleAbierto/Controlador/PID Controller1/Sum/Sum_PI'
 * '<S94>'  : 'BucleAbierto/Controlador/PID Controller1/Sum Fdbk/Disabled'
 * '<S95>'  : 'BucleAbierto/Controlador/PID Controller1/Tracking Mode/Disabled'
 * '<S96>'  : 'BucleAbierto/Controlador/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S97>'  : 'BucleAbierto/Controlador/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S98>'  : 'BucleAbierto/Controlador/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S99>'  : 'BucleAbierto/Controlador/PID Controller1/postSat Signal/Forward_Path'
 * '<S100>' : 'BucleAbierto/Controlador/PID Controller1/preSat Signal/Forward_Path'
 * '<S101>' : 'BucleAbierto/Planta/Subsystem Reference'
 */
#endif                                 /* RTW_HEADER_BucleAbierto_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
