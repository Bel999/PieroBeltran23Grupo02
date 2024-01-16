/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: H4_Giro360P.h
 *
 * Code generated for Simulink model 'H4_Giro360P'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Dec 21 15:55:48 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_H4_Giro360P_h_
#define RTW_HEADER_H4_Giro360P_h_
#ifndef H4_Giro360P_COMMON_INCLUDES_
#define H4_Giro360P_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* H4_Giro360P_COMMON_INCLUDES_ */

#include "H4_Giro360P_types.h"
#include "rt_nonfinite.h"
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T MatrixMultiply[2];            /* '<S3>/Matrix Multiply' */
  real_T Memory[2];                    /* '<S2>/Memory' */
  real_T error[2];                     /* '<S2>/Sum' */
  real_T Saturation;                   /* '<S144>/Saturation' */
  real_T Saturation_e;                 /* '<S96>/Saturation' */
  real_T pwm[2];
  /* '<S2>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Subsystem Reference_at_outport_0Inport1' */
  real_T DiscreteTimeIntegrator[3];    /* '<S5>/Discrete-Time Integrator' */
  real_T Gain[2];                      /* '<S155>/Gain' */
  real_T Diff[2];                      /* '<S157>/Diff' */
  real_T Gain1[2];                     /* '<S154>/Gain1' */
  real_T MatrixMultiply_d[2];          /* '<S4>/Matrix Multiply' */
  int32_T TmpSignalConversionAtGainInport[2];
                                /* '<S155>/TmpSignal ConversionAtGainInport1' */
  int32_T Encoder1;                    /* '<S155>/Encoder1' */
  int32_T Encoder;                     /* '<S155>/Encoder' */
} B_H4_Giro360P_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S155>/Encoder1' */
  codertarget_arduinobase_inter_T obj_p;/* '<S155>/Encoder' */
  codertarget_arduinobase_int_l_T obj_g;/* '<S156>/Atras_izq' */
  codertarget_arduinobase_int_l_T obj_e;/* '<S156>/Atras_der' */
  codertarget_arduinobase_int_l_T obj_j;/* '<S156>/Adelante_izq' */
  codertarget_arduinobase_int_l_T obj_b;/* '<S156>/Adelante_der' */
  codertarget_arduinobase_block_T obj_m;/* '<S156>/Digital Output1' */
  codertarget_arduinobase_block_T obj_pi;/* '<S156>/Digital Output' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE;            /* '<S137>/Integrator' */
  real_T Integrator_DSTATE_h;          /* '<S89>/Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_k[3];/* '<S5>/Discrete-Time Integrator' */
  real_T UD_DSTATE[2];                 /* '<S157>/UD' */
  real_T Memory_PreviousInput[2];      /* '<S2>/Memory' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S2>/Scope' */
} DW_H4_Giro360P_T;

/* Parameters (default storage) */
struct P_H4_Giro360P_T_ {
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S86>/Integral Gain'
                                        */
  real_T PIDController2_I;             /* Mask Parameter: PIDController2_I
                                        * Referenced by: '<S134>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S157>/UD'
                               */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S137>/Integrator'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S89>/Integrator'
                               */
  real_T PIDController_LowerSaturationLi;
                              /* Mask Parameter: PIDController_LowerSaturationLi
                               * Referenced by: '<S44>/Saturation'
                               */
  real_T PIDController2_LowerSaturationL;
                              /* Mask Parameter: PIDController2_LowerSaturationL
                               * Referenced by: '<S144>/Saturation'
                               */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S96>/Saturation'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S42>/Proportional Gain'
                                        */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S142>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S94>/Proportional Gain'
                                        */
  real_T PIDController_UpperSaturationLi;
                              /* Mask Parameter: PIDController_UpperSaturationLi
                               * Referenced by: '<S44>/Saturation'
                               */
  real_T PIDController2_UpperSaturationL;
                              /* Mask Parameter: PIDController2_UpperSaturationL
                               * Referenced by: '<S144>/Saturation'
                               */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S96>/Saturation'
                               */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S155>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S155>/Encoder1'
                                        */
  real_T Constant_Value[4];            /* Expression: [1 -d/2; 1 d/2]
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: [0]
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: [2*pi]
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S137>/Integrator'
                                        */
  real_T Integrator_gainval_d;       /* Computed Parameter: Integrator_gainval_d
                                      * Referenced by: '<S89>/Integrator'
                                      */
  real_T Constant_Value_b[4];          /* Expression: [1/2 1/2; -1/d 1/d]
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                           * Referenced by: '<S5>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S5>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S157>/TSamp'
                                        */
  real_T Gain1_Gain[2];                /* Expression: [1.0045 1]
                                        * Referenced by: '<S154>/Gain1'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S155>/Gain'
                                        */
  int16_T Constant_Value_c;            /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S158>/Constant'
                                        */
  int16_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S159>/Constant'
                                        */
  int16_T Saturation2_UpperSat;      /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S156>/Saturation2'
                                      */
  int16_T Saturation2_LowerSat;      /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S156>/Saturation2'
                                      */
  int16_T Saturation4_UpperSat;      /* Computed Parameter: Saturation4_UpperSat
                                      * Referenced by: '<S156>/Saturation4'
                                      */
  int16_T Saturation4_LowerSat;      /* Computed Parameter: Saturation4_LowerSat
                                      * Referenced by: '<S156>/Saturation4'
                                      */
  int16_T Saturation3_UpperSat;      /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<S156>/Saturation3'
                                      */
  int16_T Saturation3_LowerSat;      /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<S156>/Saturation3'
                                      */
  int16_T Saturation5_UpperSat;      /* Computed Parameter: Saturation5_UpperSat
                                      * Referenced by: '<S156>/Saturation5'
                                      */
  int16_T Saturation5_LowerSat;      /* Computed Parameter: Saturation5_LowerSat
                                      * Referenced by: '<S156>/Saturation5'
                                      */
};

/* Real-time Model Data Structure */
struct tag_RTM_H4_Giro360P_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

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
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_H4_Giro360P_T H4_Giro360P_P;

/* Block signals (default storage) */
extern B_H4_Giro360P_T H4_Giro360P_B;

/* Block states (default storage) */
extern DW_H4_Giro360P_T H4_Giro360P_DW;

/* Model entry point functions */
extern void H4_Giro360P_initialize(void);
extern void H4_Giro360P_step(void);
extern void H4_Giro360P_terminate(void);

/* Real-time Model object */
extern RT_MODEL_H4_Giro360P_T *const H4_Giro360P_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S157>/Data Type Duplicate' : Unused code path elimination
 * Block '<S156>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'H4_Giro360P'
 * '<S1>'   : 'H4_Giro360P/PID Controller'
 * '<S2>'   : 'H4_Giro360P/Subsystem Reference'
 * '<S3>'   : 'H4_Giro360P/Subsystem Reference1'
 * '<S4>'   : 'H4_Giro360P/Subsystem Reference2'
 * '<S5>'   : 'H4_Giro360P/Subsystem Reference4'
 * '<S6>'   : 'H4_Giro360P/PID Controller/Anti-windup'
 * '<S7>'   : 'H4_Giro360P/PID Controller/D Gain'
 * '<S8>'   : 'H4_Giro360P/PID Controller/Filter'
 * '<S9>'   : 'H4_Giro360P/PID Controller/Filter ICs'
 * '<S10>'  : 'H4_Giro360P/PID Controller/I Gain'
 * '<S11>'  : 'H4_Giro360P/PID Controller/Ideal P Gain'
 * '<S12>'  : 'H4_Giro360P/PID Controller/Ideal P Gain Fdbk'
 * '<S13>'  : 'H4_Giro360P/PID Controller/Integrator'
 * '<S14>'  : 'H4_Giro360P/PID Controller/Integrator ICs'
 * '<S15>'  : 'H4_Giro360P/PID Controller/N Copy'
 * '<S16>'  : 'H4_Giro360P/PID Controller/N Gain'
 * '<S17>'  : 'H4_Giro360P/PID Controller/P Copy'
 * '<S18>'  : 'H4_Giro360P/PID Controller/Parallel P Gain'
 * '<S19>'  : 'H4_Giro360P/PID Controller/Reset Signal'
 * '<S20>'  : 'H4_Giro360P/PID Controller/Saturation'
 * '<S21>'  : 'H4_Giro360P/PID Controller/Saturation Fdbk'
 * '<S22>'  : 'H4_Giro360P/PID Controller/Sum'
 * '<S23>'  : 'H4_Giro360P/PID Controller/Sum Fdbk'
 * '<S24>'  : 'H4_Giro360P/PID Controller/Tracking Mode'
 * '<S25>'  : 'H4_Giro360P/PID Controller/Tracking Mode Sum'
 * '<S26>'  : 'H4_Giro360P/PID Controller/Tsamp - Integral'
 * '<S27>'  : 'H4_Giro360P/PID Controller/Tsamp - Ngain'
 * '<S28>'  : 'H4_Giro360P/PID Controller/postSat Signal'
 * '<S29>'  : 'H4_Giro360P/PID Controller/preSat Signal'
 * '<S30>'  : 'H4_Giro360P/PID Controller/Anti-windup/Disabled'
 * '<S31>'  : 'H4_Giro360P/PID Controller/D Gain/Disabled'
 * '<S32>'  : 'H4_Giro360P/PID Controller/Filter/Disabled'
 * '<S33>'  : 'H4_Giro360P/PID Controller/Filter ICs/Disabled'
 * '<S34>'  : 'H4_Giro360P/PID Controller/I Gain/Disabled'
 * '<S35>'  : 'H4_Giro360P/PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'H4_Giro360P/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'H4_Giro360P/PID Controller/Integrator/Disabled'
 * '<S38>'  : 'H4_Giro360P/PID Controller/Integrator ICs/Disabled'
 * '<S39>'  : 'H4_Giro360P/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S40>'  : 'H4_Giro360P/PID Controller/N Gain/Disabled'
 * '<S41>'  : 'H4_Giro360P/PID Controller/P Copy/Disabled'
 * '<S42>'  : 'H4_Giro360P/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'H4_Giro360P/PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'H4_Giro360P/PID Controller/Saturation/Enabled'
 * '<S45>'  : 'H4_Giro360P/PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'H4_Giro360P/PID Controller/Sum/Passthrough_P'
 * '<S47>'  : 'H4_Giro360P/PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'H4_Giro360P/PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'H4_Giro360P/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'H4_Giro360P/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S51>'  : 'H4_Giro360P/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'H4_Giro360P/PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'H4_Giro360P/PID Controller/preSat Signal/Forward_Path'
 * '<S54>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference'
 * '<S55>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference1'
 * '<S56>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1'
 * '<S57>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2'
 * '<S58>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Anti-windup'
 * '<S59>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/D Gain'
 * '<S60>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Filter'
 * '<S61>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Filter ICs'
 * '<S62>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/I Gain'
 * '<S63>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Ideal P Gain'
 * '<S64>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Ideal P Gain Fdbk'
 * '<S65>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Integrator'
 * '<S66>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Integrator ICs'
 * '<S67>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/N Copy'
 * '<S68>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/N Gain'
 * '<S69>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/P Copy'
 * '<S70>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Parallel P Gain'
 * '<S71>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Reset Signal'
 * '<S72>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Saturation'
 * '<S73>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Saturation Fdbk'
 * '<S74>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Sum'
 * '<S75>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Sum Fdbk'
 * '<S76>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Tracking Mode'
 * '<S77>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Tracking Mode Sum'
 * '<S78>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Tsamp - Integral'
 * '<S79>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Tsamp - Ngain'
 * '<S80>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/postSat Signal'
 * '<S81>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/preSat Signal'
 * '<S82>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Anti-windup/Passthrough'
 * '<S83>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/D Gain/Disabled'
 * '<S84>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Filter/Disabled'
 * '<S85>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Filter ICs/Disabled'
 * '<S86>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/I Gain/Internal Parameters'
 * '<S87>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Ideal P Gain/Passthrough'
 * '<S88>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S89>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Integrator/Discrete'
 * '<S90>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Integrator ICs/Internal IC'
 * '<S91>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S92>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/N Gain/Disabled'
 * '<S93>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/P Copy/Disabled'
 * '<S94>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S95>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Reset Signal/Disabled'
 * '<S96>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Saturation/Enabled'
 * '<S97>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Saturation Fdbk/Disabled'
 * '<S98>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Sum/Sum_PI'
 * '<S99>'  : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Sum Fdbk/Disabled'
 * '<S100>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Tracking Mode/Disabled'
 * '<S101>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S102>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S103>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S104>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/postSat Signal/Forward_Path'
 * '<S105>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller1/preSat Signal/Forward_Path'
 * '<S106>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Anti-windup'
 * '<S107>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/D Gain'
 * '<S108>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Filter'
 * '<S109>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Filter ICs'
 * '<S110>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/I Gain'
 * '<S111>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Ideal P Gain'
 * '<S112>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Ideal P Gain Fdbk'
 * '<S113>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Integrator'
 * '<S114>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Integrator ICs'
 * '<S115>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/N Copy'
 * '<S116>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/N Gain'
 * '<S117>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/P Copy'
 * '<S118>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Parallel P Gain'
 * '<S119>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Reset Signal'
 * '<S120>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Saturation'
 * '<S121>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Saturation Fdbk'
 * '<S122>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Sum'
 * '<S123>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Sum Fdbk'
 * '<S124>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Tracking Mode'
 * '<S125>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Tracking Mode Sum'
 * '<S126>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Tsamp - Integral'
 * '<S127>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Tsamp - Ngain'
 * '<S128>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/postSat Signal'
 * '<S129>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/preSat Signal'
 * '<S130>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Anti-windup/Passthrough'
 * '<S131>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/D Gain/Disabled'
 * '<S132>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Filter/Disabled'
 * '<S133>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Filter ICs/Disabled'
 * '<S134>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/I Gain/Internal Parameters'
 * '<S135>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Ideal P Gain/Passthrough'
 * '<S136>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S137>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Integrator/Discrete'
 * '<S138>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Integrator ICs/Internal IC'
 * '<S139>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S140>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/N Gain/Disabled'
 * '<S141>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/P Copy/Disabled'
 * '<S142>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S143>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Reset Signal/Disabled'
 * '<S144>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Saturation/Enabled'
 * '<S145>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Saturation Fdbk/Disabled'
 * '<S146>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Sum/Sum_PI'
 * '<S147>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Sum Fdbk/Disabled'
 * '<S148>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Tracking Mode/Disabled'
 * '<S149>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S150>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S151>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S152>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/postSat Signal/Forward_Path'
 * '<S153>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference/PID Controller2/preSat Signal/Forward_Path'
 * '<S154>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference1/Subsystem Reference1'
 * '<S155>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference'
 * '<S156>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4'
 * '<S157>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference/Discrete Derivative'
 * '<S158>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4/Compare To Zero'
 * '<S159>' : 'H4_Giro360P/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_H4_Giro360P_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
