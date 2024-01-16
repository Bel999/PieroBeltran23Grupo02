/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ComparaModelos.h
 *
 * Code generated for Simulink model 'ComparaModelos'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 30 13:19:10 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ComparaModelos_h_
#define RTW_HEADER_ComparaModelos_h_
#ifndef ComparaModelos_COMMON_INCLUDES_
#define ComparaModelos_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* ComparaModelos_COMMON_INCLUDES_ */

#include "ComparaModelos_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <string.h>
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Constant[2];                  /* '<Root>/Constant' */
  real_T TmpRTBAtDerivativeInport1[2]; /* '<S102>/Gain' */
  real_T Derivative[2];                /* '<S102>/Derivative' */
  real_T Sum[2];                       /* '<Root>/Sum' */
  real_T ProportionalGain;             /* '<S41>/Proportional Gain' */
  real_T ProportionalGain_c;           /* '<S89>/Proportional Gain' */
  real_T IntegralGain;                 /* '<S33>/Integral Gain' */
  real_T IntegralGain_o;               /* '<S81>/Integral Gain' */
  int16_T Saturation;                  /* '<S43>/Saturation' */
  int16_T Saturation_p;                /* '<S91>/Saturation' */
  int16_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Subsystem_at_outport_0Inport1' */
} B_ComparaModelos_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S102>/Encoder1' */
  codertarget_arduinobase_inter_T obj_c;/* '<S102>/Encoder' */
  codertarget_arduinobase_int_e_T obj_cc;/* '<S103>/Atras_izq' */
  codertarget_arduinobase_int_e_T obj_b;/* '<S103>/Atras_der' */
  codertarget_arduinobase_int_e_T obj_g;/* '<S103>/Adelante_izq' */
  codertarget_arduinobase_int_e_T obj_d;/* '<S103>/Adelante_der' */
  codertarget_arduinobase_block_T obj_c0;/* '<S103>/Digital Output1' */
  codertarget_arduinobase_block_T obj_i;/* '<S103>/Digital Output' */
  real_T TmpRTBAtDerivativeInport1_Buffe[2];/* synthesized block */
  real_T TimeStampA;                   /* '<S102>/Derivative' */
  real_T LastUAtTimeA[2];              /* '<S102>/Derivative' */
  real_T TimeStampB;                   /* '<S102>/Derivative' */
  real_T LastUAtTimeB[2];              /* '<S102>/Derivative' */
  real_T Memory_PreviousInput[2];      /* '<Root>/Memory' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_ComparaModelos_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S84>/Integrator' */
} X_ComparaModelos_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S84>/Integrator' */
} XDot_ComparaModelos_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S36>/Integrator' */
  boolean_T Integrator_CSTATE_m;       /* '<S84>/Integrator' */
} XDis_ComparaModelos_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_ComparaModelos_T_ {
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S33>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S81>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S36>/Integrator'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S84>/Integrator'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S41>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S89>/Proportional Gain'
                                        */
  int16_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S43>/Saturation'
                               */
  int16_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S91>/Saturation'
                               */
  int16_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S43>/Saturation'
                               */
  int16_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S91>/Saturation'
                               */
  real_T Encoder_SampleTime;           /* Expression: 0.5
                                        * Referenced by: '<S102>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: 0.5
                                        * Referenced by: '<S102>/Encoder1'
                                        */
  real_T Constant_Value[2];            /* Expression: [0.205 0.205]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T TmpRTBAtDerivativeInport1_Initi;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  int32_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S104>/Constant'
                                        */
  int32_T Saturation4_UpperSat;      /* Computed Parameter: Saturation4_UpperSat
                                      * Referenced by: '<S103>/Saturation4'
                                      */
  int32_T Saturation4_LowerSat;      /* Computed Parameter: Saturation4_LowerSat
                                      * Referenced by: '<S103>/Saturation4'
                                      */
  int32_T Saturation5_UpperSat;      /* Computed Parameter: Saturation5_UpperSat
                                      * Referenced by: '<S103>/Saturation5'
                                      */
  int32_T Saturation5_LowerSat;      /* Computed Parameter: Saturation5_LowerSat
                                      * Referenced by: '<S103>/Saturation5'
                                      */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S102>/Gain'
                                        */
  int16_T Constant_Value_n;            /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S105>/Constant'
                                        */
  int16_T Saturation2_UpperSat;      /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S103>/Saturation2'
                                      */
  int16_T Saturation2_LowerSat;      /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S103>/Saturation2'
                                      */
  int16_T Saturation3_UpperSat;      /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<S103>/Saturation3'
                                      */
  int16_T Saturation3_LowerSat;      /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<S103>/Saturation3'
                                      */
  int16_T Gain_Gain_o;                 /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S103>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ComparaModelos_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_ComparaModelos_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_ComparaModelos_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
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
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_ComparaModelos_T ComparaModelos_P;

/* Block signals (default storage) */
extern B_ComparaModelos_T ComparaModelos_B;

/* Continuous states (default storage) */
extern X_ComparaModelos_T ComparaModelos_X;

/* Disabled states (default storage) */
extern XDis_ComparaModelos_T ComparaModelos_XDis;

/* Block states (default storage) */
extern DW_ComparaModelos_T ComparaModelos_DW;

/* External function called from main */
extern void ComparaModelos_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void ComparaModelos_initialize(void);
extern void ComparaModelos_step0(void);
extern void ComparaModelos_step2(void);
extern void ComparaModelos_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ComparaModelos_T *const ComparaModelos_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Cumulative Sum' : Unused code path elimination
 * Block '<S2>/Logical Operator' : Unused code path elimination
 * Block '<Root>/Sum of Elements' : Unused code path elimination
 * Block '<Root>/Sum1' : Unused code path elimination
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
 * '<Root>' : 'ComparaModelos'
 * '<S1>'   : 'ComparaModelos/Subsystem'
 * '<S2>'   : 'ComparaModelos/Subsystem3'
 * '<S3>'   : 'ComparaModelos/Subsystem/PID Controller'
 * '<S4>'   : 'ComparaModelos/Subsystem/PID Controller1'
 * '<S5>'   : 'ComparaModelos/Subsystem/PID Controller/Anti-windup'
 * '<S6>'   : 'ComparaModelos/Subsystem/PID Controller/D Gain'
 * '<S7>'   : 'ComparaModelos/Subsystem/PID Controller/Filter'
 * '<S8>'   : 'ComparaModelos/Subsystem/PID Controller/Filter ICs'
 * '<S9>'   : 'ComparaModelos/Subsystem/PID Controller/I Gain'
 * '<S10>'  : 'ComparaModelos/Subsystem/PID Controller/Ideal P Gain'
 * '<S11>'  : 'ComparaModelos/Subsystem/PID Controller/Ideal P Gain Fdbk'
 * '<S12>'  : 'ComparaModelos/Subsystem/PID Controller/Integrator'
 * '<S13>'  : 'ComparaModelos/Subsystem/PID Controller/Integrator ICs'
 * '<S14>'  : 'ComparaModelos/Subsystem/PID Controller/N Copy'
 * '<S15>'  : 'ComparaModelos/Subsystem/PID Controller/N Gain'
 * '<S16>'  : 'ComparaModelos/Subsystem/PID Controller/P Copy'
 * '<S17>'  : 'ComparaModelos/Subsystem/PID Controller/Parallel P Gain'
 * '<S18>'  : 'ComparaModelos/Subsystem/PID Controller/Reset Signal'
 * '<S19>'  : 'ComparaModelos/Subsystem/PID Controller/Saturation'
 * '<S20>'  : 'ComparaModelos/Subsystem/PID Controller/Saturation Fdbk'
 * '<S21>'  : 'ComparaModelos/Subsystem/PID Controller/Sum'
 * '<S22>'  : 'ComparaModelos/Subsystem/PID Controller/Sum Fdbk'
 * '<S23>'  : 'ComparaModelos/Subsystem/PID Controller/Tracking Mode'
 * '<S24>'  : 'ComparaModelos/Subsystem/PID Controller/Tracking Mode Sum'
 * '<S25>'  : 'ComparaModelos/Subsystem/PID Controller/Tsamp - Integral'
 * '<S26>'  : 'ComparaModelos/Subsystem/PID Controller/Tsamp - Ngain'
 * '<S27>'  : 'ComparaModelos/Subsystem/PID Controller/postSat Signal'
 * '<S28>'  : 'ComparaModelos/Subsystem/PID Controller/preSat Signal'
 * '<S29>'  : 'ComparaModelos/Subsystem/PID Controller/Anti-windup/Passthrough'
 * '<S30>'  : 'ComparaModelos/Subsystem/PID Controller/D Gain/Disabled'
 * '<S31>'  : 'ComparaModelos/Subsystem/PID Controller/Filter/Disabled'
 * '<S32>'  : 'ComparaModelos/Subsystem/PID Controller/Filter ICs/Disabled'
 * '<S33>'  : 'ComparaModelos/Subsystem/PID Controller/I Gain/Internal Parameters'
 * '<S34>'  : 'ComparaModelos/Subsystem/PID Controller/Ideal P Gain/Passthrough'
 * '<S35>'  : 'ComparaModelos/Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'ComparaModelos/Subsystem/PID Controller/Integrator/Continuous'
 * '<S37>'  : 'ComparaModelos/Subsystem/PID Controller/Integrator ICs/Internal IC'
 * '<S38>'  : 'ComparaModelos/Subsystem/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S39>'  : 'ComparaModelos/Subsystem/PID Controller/N Gain/Disabled'
 * '<S40>'  : 'ComparaModelos/Subsystem/PID Controller/P Copy/Disabled'
 * '<S41>'  : 'ComparaModelos/Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S42>'  : 'ComparaModelos/Subsystem/PID Controller/Reset Signal/Disabled'
 * '<S43>'  : 'ComparaModelos/Subsystem/PID Controller/Saturation/Enabled'
 * '<S44>'  : 'ComparaModelos/Subsystem/PID Controller/Saturation Fdbk/Disabled'
 * '<S45>'  : 'ComparaModelos/Subsystem/PID Controller/Sum/Sum_PI'
 * '<S46>'  : 'ComparaModelos/Subsystem/PID Controller/Sum Fdbk/Disabled'
 * '<S47>'  : 'ComparaModelos/Subsystem/PID Controller/Tracking Mode/Disabled'
 * '<S48>'  : 'ComparaModelos/Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'ComparaModelos/Subsystem/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S50>'  : 'ComparaModelos/Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'ComparaModelos/Subsystem/PID Controller/postSat Signal/Forward_Path'
 * '<S52>'  : 'ComparaModelos/Subsystem/PID Controller/preSat Signal/Forward_Path'
 * '<S53>'  : 'ComparaModelos/Subsystem/PID Controller1/Anti-windup'
 * '<S54>'  : 'ComparaModelos/Subsystem/PID Controller1/D Gain'
 * '<S55>'  : 'ComparaModelos/Subsystem/PID Controller1/Filter'
 * '<S56>'  : 'ComparaModelos/Subsystem/PID Controller1/Filter ICs'
 * '<S57>'  : 'ComparaModelos/Subsystem/PID Controller1/I Gain'
 * '<S58>'  : 'ComparaModelos/Subsystem/PID Controller1/Ideal P Gain'
 * '<S59>'  : 'ComparaModelos/Subsystem/PID Controller1/Ideal P Gain Fdbk'
 * '<S60>'  : 'ComparaModelos/Subsystem/PID Controller1/Integrator'
 * '<S61>'  : 'ComparaModelos/Subsystem/PID Controller1/Integrator ICs'
 * '<S62>'  : 'ComparaModelos/Subsystem/PID Controller1/N Copy'
 * '<S63>'  : 'ComparaModelos/Subsystem/PID Controller1/N Gain'
 * '<S64>'  : 'ComparaModelos/Subsystem/PID Controller1/P Copy'
 * '<S65>'  : 'ComparaModelos/Subsystem/PID Controller1/Parallel P Gain'
 * '<S66>'  : 'ComparaModelos/Subsystem/PID Controller1/Reset Signal'
 * '<S67>'  : 'ComparaModelos/Subsystem/PID Controller1/Saturation'
 * '<S68>'  : 'ComparaModelos/Subsystem/PID Controller1/Saturation Fdbk'
 * '<S69>'  : 'ComparaModelos/Subsystem/PID Controller1/Sum'
 * '<S70>'  : 'ComparaModelos/Subsystem/PID Controller1/Sum Fdbk'
 * '<S71>'  : 'ComparaModelos/Subsystem/PID Controller1/Tracking Mode'
 * '<S72>'  : 'ComparaModelos/Subsystem/PID Controller1/Tracking Mode Sum'
 * '<S73>'  : 'ComparaModelos/Subsystem/PID Controller1/Tsamp - Integral'
 * '<S74>'  : 'ComparaModelos/Subsystem/PID Controller1/Tsamp - Ngain'
 * '<S75>'  : 'ComparaModelos/Subsystem/PID Controller1/postSat Signal'
 * '<S76>'  : 'ComparaModelos/Subsystem/PID Controller1/preSat Signal'
 * '<S77>'  : 'ComparaModelos/Subsystem/PID Controller1/Anti-windup/Passthrough'
 * '<S78>'  : 'ComparaModelos/Subsystem/PID Controller1/D Gain/Disabled'
 * '<S79>'  : 'ComparaModelos/Subsystem/PID Controller1/Filter/Disabled'
 * '<S80>'  : 'ComparaModelos/Subsystem/PID Controller1/Filter ICs/Disabled'
 * '<S81>'  : 'ComparaModelos/Subsystem/PID Controller1/I Gain/Internal Parameters'
 * '<S82>'  : 'ComparaModelos/Subsystem/PID Controller1/Ideal P Gain/Passthrough'
 * '<S83>'  : 'ComparaModelos/Subsystem/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S84>'  : 'ComparaModelos/Subsystem/PID Controller1/Integrator/Continuous'
 * '<S85>'  : 'ComparaModelos/Subsystem/PID Controller1/Integrator ICs/Internal IC'
 * '<S86>'  : 'ComparaModelos/Subsystem/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S87>'  : 'ComparaModelos/Subsystem/PID Controller1/N Gain/Disabled'
 * '<S88>'  : 'ComparaModelos/Subsystem/PID Controller1/P Copy/Disabled'
 * '<S89>'  : 'ComparaModelos/Subsystem/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S90>'  : 'ComparaModelos/Subsystem/PID Controller1/Reset Signal/Disabled'
 * '<S91>'  : 'ComparaModelos/Subsystem/PID Controller1/Saturation/Enabled'
 * '<S92>'  : 'ComparaModelos/Subsystem/PID Controller1/Saturation Fdbk/Disabled'
 * '<S93>'  : 'ComparaModelos/Subsystem/PID Controller1/Sum/Sum_PI'
 * '<S94>'  : 'ComparaModelos/Subsystem/PID Controller1/Sum Fdbk/Disabled'
 * '<S95>'  : 'ComparaModelos/Subsystem/PID Controller1/Tracking Mode/Disabled'
 * '<S96>'  : 'ComparaModelos/Subsystem/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S97>'  : 'ComparaModelos/Subsystem/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S98>'  : 'ComparaModelos/Subsystem/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S99>'  : 'ComparaModelos/Subsystem/PID Controller1/postSat Signal/Forward_Path'
 * '<S100>' : 'ComparaModelos/Subsystem/PID Controller1/preSat Signal/Forward_Path'
 * '<S101>' : 'ComparaModelos/Subsystem3/Subsystem1'
 * '<S102>' : 'ComparaModelos/Subsystem3/Subsystem1/Subsystem'
 * '<S103>' : 'ComparaModelos/Subsystem3/Subsystem1/Subsystem Reference'
 * '<S104>' : 'ComparaModelos/Subsystem3/Subsystem1/Subsystem Reference/Compare To Zero'
 * '<S105>' : 'ComparaModelos/Subsystem3/Subsystem1/Subsystem Reference/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_ComparaModelos_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
