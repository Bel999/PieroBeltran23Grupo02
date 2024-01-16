/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Compara_modelos_H3.h
 *
 * Code generated for Simulink model 'Compara_modelos_H3'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 30 01:09:28 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Compara_modelos_H3_h_
#define RTW_HEADER_Compara_modelos_H3_h_
#ifndef Compara_modelos_H3_COMMON_INCLUDES_
#define Compara_modelos_H3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* Compara_modelos_H3_COMMON_INCLUDES_ */

#include "Compara_modelos_H3_types.h"
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
  real_T Gain[2];                      /* '<S3>/Gain' */
  real_T Derivative[2];                /* '<S3>/Derivative' */
  real_T Rizq;                         /* '<S1>/Rizq' */
  real_T Rder;                         /* '<S1>/Rder' */
  real_T TmpSignalConversionAtTAQSigLogg[4];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  real_T Constant[2];                  /* '<Root>/Constant' */
  real_T DataTypeConversion[2];        /* '<S1>/Data Type Conversion' */
  int32_T TmpSignalConversionAtTAQSigLo_j[2];
  /* '<S3>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  int32_T Encoder1;                    /* '<S3>/Encoder1' */
  int32_T Encoder;                     /* '<S3>/Encoder' */
} B_Compara_modelos_H3_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S3>/Encoder1' */
  codertarget_arduinobase_inter_T obj_d;/* '<S3>/Encoder' */
  codertarget_arduinobase_int_i_T obj_a;/* '<S4>/Atras_izq' */
  codertarget_arduinobase_int_i_T obj_i;/* '<S4>/Atras_der' */
  codertarget_arduinobase_int_i_T obj_j;/* '<S4>/Adelante_izq' */
  codertarget_arduinobase_int_i_T obj_g;/* '<S4>/Adelante_der' */
  codertarget_arduinobase_block_T obj_gs;/* '<S4>/Digital Output1' */
  codertarget_arduinobase_block_T obj_m;/* '<S4>/Digital Output' */
  real_T TimeStampA;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeA[2];              /* '<S3>/Derivative' */
  real_T TimeStampB;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeB[2];              /* '<S3>/Derivative' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_Compara_modelos_H3_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Rizq_CSTATE;                  /* '<S1>/Rizq' */
  real_T Rder_CSTATE;                  /* '<S1>/Rder' */
} X_Compara_modelos_H3_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Rizq_CSTATE;                  /* '<S1>/Rizq' */
  real_T Rder_CSTATE;                  /* '<S1>/Rder' */
} XDot_Compara_modelos_H3_T;

/* State disabled  */
typedef struct {
  boolean_T Rizq_CSTATE;               /* '<S1>/Rizq' */
  boolean_T Rder_CSTATE;               /* '<S1>/Rder' */
} XDis_Compara_modelos_H3_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_Compara_modelos_H3_T_ {
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S3>/Encoder1'
                                        */
  real_T Rizq_A;                       /* Computed Parameter: Rizq_A
                                        * Referenced by: '<S1>/Rizq'
                                        */
  real_T Rizq_C;                       /* Computed Parameter: Rizq_C
                                        * Referenced by: '<S1>/Rizq'
                                        */
  real_T Rder_A;                       /* Computed Parameter: Rder_A
                                        * Referenced by: '<S1>/Rder'
                                        */
  real_T Rder_C;                       /* Computed Parameter: Rder_C
                                        * Referenced by: '<S1>/Rder'
                                        */
  real_T Constant_Value[2];            /* Expression: [0.205 0.205]
                                        * Referenced by: '<Root>/Constant'
                                        */
  int32_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S5>/Constant'
                                        */
  int32_T Saturation4_UpperSat;      /* Computed Parameter: Saturation4_UpperSat
                                      * Referenced by: '<S4>/Saturation4'
                                      */
  int32_T Saturation4_LowerSat;      /* Computed Parameter: Saturation4_LowerSat
                                      * Referenced by: '<S4>/Saturation4'
                                      */
  int32_T Saturation5_UpperSat;      /* Computed Parameter: Saturation5_UpperSat
                                      * Referenced by: '<S4>/Saturation5'
                                      */
  int32_T Saturation5_LowerSat;      /* Computed Parameter: Saturation5_LowerSat
                                      * Referenced by: '<S4>/Saturation5'
                                      */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S3>/Gain'
                                        */
  int16_T Constant_Value_p;            /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S6>/Constant'
                                        */
  int16_T Saturation2_UpperSat;      /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S4>/Saturation2'
                                      */
  int16_T Saturation2_LowerSat;      /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S4>/Saturation2'
                                      */
  int16_T Saturation3_UpperSat;      /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<S4>/Saturation3'
                                      */
  int16_T Saturation3_LowerSat;      /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<S4>/Saturation3'
                                      */
  int16_T Gain_Gain_f;                 /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S4>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Compara_modelos_H3_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_Compara_modelos_H3_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Compara_modelos_H3_T *contStateDisabled;
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
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Compara_modelos_H3_T Compara_modelos_H3_P;

/* Block signals (default storage) */
extern B_Compara_modelos_H3_T Compara_modelos_H3_B;

/* Continuous states (default storage) */
extern X_Compara_modelos_H3_T Compara_modelos_H3_X;

/* Disabled states (default storage) */
extern XDis_Compara_modelos_H3_T Compara_modelos_H3_XDis;

/* Block states (default storage) */
extern DW_Compara_modelos_H3_T Compara_modelos_H3_DW;

/* Model entry point functions */
extern void Compara_modelos_H3_initialize(void);
extern void Compara_modelos_H3_step(void);
extern void Compara_modelos_H3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Compara_modelos_H3_T *const Compara_modelos_H3_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Compara_modelos_H3'
 * '<S1>'   : 'Compara_modelos_H3/Subsystem Reference'
 * '<S2>'   : 'Compara_modelos_H3/Subsystem Reference1'
 * '<S3>'   : 'Compara_modelos_H3/Subsystem Reference1/Subsystem Reference'
 * '<S4>'   : 'Compara_modelos_H3/Subsystem Reference1/Subsystem Reference4'
 * '<S5>'   : 'Compara_modelos_H3/Subsystem Reference1/Subsystem Reference4/Compare To Zero'
 * '<S6>'   : 'Compara_modelos_H3/Subsystem Reference1/Subsystem Reference4/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_Compara_modelos_H3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
