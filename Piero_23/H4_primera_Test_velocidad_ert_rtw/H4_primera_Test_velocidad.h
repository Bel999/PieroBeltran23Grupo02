/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: H4_primera_Test_velocidad.h
 *
 * Code generated for Simulink model 'H4_primera_Test_velocidad'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Dec 19 22:03:41 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_H4_primera_Test_velocidad_h_
#define RTW_HEADER_H4_primera_Test_velocidad_h_
#ifndef H4_primera_Test_velocidad_COMMON_INCLUDES_
#define H4_primera_Test_velocidad_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                          /* H4_primera_Test_velocidad_COMMON_INCLUDES_ */

#include "H4_primera_Test_velocidad_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Gain[2];                      /* '<S105>/Gain' */
  real_T Gain1[2];                     /* '<S104>/Gain1' */
} B_H4_primera_Test_velocidad_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S105>/Encoder1' */
  codertarget_arduinobase_inter_T obj_d;/* '<S105>/Encoder' */
  codertarget_arduinobase_int_a_T obj_m;/* '<S106>/Atras_izq' */
  codertarget_arduinobase_int_a_T obj_b;/* '<S106>/Atras_der' */
  codertarget_arduinobase_int_a_T obj_dx;/* '<S106>/Adelante_izq' */
  codertarget_arduinobase_int_a_T obj_m5;/* '<S106>/Adelante_der' */
  codertarget_arduinobase_block_T obj_l;/* '<S106>/Digital Output1' */
  codertarget_arduinobase_block_T obj_bt;/* '<S106>/Digital Output' */
  real_T DiscreteTimeIntegrator_DSTATE[2];/* '<S2>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE;            /* '<S39>/Integrator' */
  real_T Integrator_DSTATE_g;          /* '<S87>/Integrator' */
  real_T TimeStampA;                   /* '<S105>/Derivative' */
  real_T LastUAtTimeA[2];              /* '<S105>/Derivative' */
  real_T TimeStampB;                   /* '<S105>/Derivative' */
  real_T LastUAtTimeB[2];              /* '<S105>/Derivative' */
} DW_H4_primera_Test_velocidad_T;

/* Parameters (default storage) */
struct P_H4_primera_Test_velocidad_T_ {
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S36>/Integral Gain'
                                        */
  real_T PIDController2_I;             /* Mask Parameter: PIDController2_I
                                        * Referenced by: '<S84>/Integral Gain'
                                        */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S39>/Integrator'
                               */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S87>/Integrator'
                               */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S46>/Saturation'
                               */
  real_T PIDController2_LowerSaturationL;
                              /* Mask Parameter: PIDController2_LowerSaturationL
                               * Referenced by: '<S94>/Saturation'
                               */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S44>/Proportional Gain'
                                        */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S92>/Proportional Gain'
                                        */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S46>/Saturation'
                               */
  real_T PIDController2_UpperSaturationL;
                              /* Mask Parameter: PIDController2_UpperSaturationL
                               * Referenced by: '<S94>/Saturation'
                               */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S105>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S105>/Encoder1'
                                        */
  real_T Constant_Value[2];            /* Expression: [1.1 1.1]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S2>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S39>/Integrator'
                                        */
  real_T Integrator_gainval_o;       /* Computed Parameter: Integrator_gainval_o
                                      * Referenced by: '<S87>/Integrator'
                                      */
  real_T Gain1_Gain[2];                /* Expression: [1 1]
                                        * Referenced by: '<S104>/Gain1'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S105>/Gain'
                                        */
  int16_T Constant_Value_k;            /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S108>/Constant'
                                        */
  int16_T Constant_Value_j;            /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S109>/Constant'
                                        */
  int16_T Saturation2_UpperSat;      /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S106>/Saturation2'
                                      */
  int16_T Saturation2_LowerSat;      /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S106>/Saturation2'
                                      */
  int16_T Saturation4_UpperSat;      /* Computed Parameter: Saturation4_UpperSat
                                      * Referenced by: '<S106>/Saturation4'
                                      */
  int16_T Saturation4_LowerSat;      /* Computed Parameter: Saturation4_LowerSat
                                      * Referenced by: '<S106>/Saturation4'
                                      */
  int16_T Saturation3_UpperSat;      /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<S106>/Saturation3'
                                      */
  int16_T Saturation3_LowerSat;      /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<S106>/Saturation3'
                                      */
  int16_T Saturation5_UpperSat;      /* Computed Parameter: Saturation5_UpperSat
                                      * Referenced by: '<S106>/Saturation5'
                                      */
  int16_T Saturation5_LowerSat;      /* Computed Parameter: Saturation5_LowerSat
                                      * Referenced by: '<S106>/Saturation5'
                                      */
};

/* Real-time Model Data Structure */
struct tag_RTM_H4_primera_Test_veloc_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_H4_primera_Test_velocidad_T H4_primera_Test_velocidad_P;

/* Block signals (default storage) */
extern B_H4_primera_Test_velocidad_T H4_primera_Test_velocidad_B;

/* Block states (default storage) */
extern DW_H4_primera_Test_velocidad_T H4_primera_Test_velocidad_DW;

/* Model entry point functions */
extern void H4_primera_Test_velocidad_initialize(void);
extern void H4_primera_Test_velocidad_step(void);
extern void H4_primera_Test_velocidad_terminate(void);

/* Real-time Model object */
extern RT_MODEL_H4_primera_Test_velo_T *const H4_primera_Test_velocidad_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Display4' : Unused code path elimination
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/Matrix Multiply' : Unused code path elimination
 * Block '<S2>/Display' : Unused code path elimination
 * Block '<S2>/Display1' : Unused code path elimination
 * Block '<S2>/Display2' : Unused code path elimination
 * Block '<S2>/Display3' : Unused code path elimination
 * Block '<S2>/Display4' : Unused code path elimination
 * Block '<S2>/Display5' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S104>/Display' : Unused code path elimination
 * Block '<S104>/Display1' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S107>/Diff' : Unused code path elimination
 * Block '<S107>/TSamp' : Unused code path elimination
 * Block '<S107>/UD' : Unused code path elimination
 * Block '<S105>/Display' : Unused code path elimination
 * Block '<S105>/Display1' : Unused code path elimination
 * Block '<S105>/Display2' : Unused code path elimination
 * Block '<S3>/Cos' : Unused code path elimination
 * Block '<S3>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S3>/Product' : Unused code path elimination
 * Block '<S3>/Product1' : Unused code path elimination
 * Block '<S3>/Sin' : Unused code path elimination
 * Block '<S106>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'H4_primera_Test_velocidad'
 * '<S1>'   : 'H4_primera_Test_velocidad/Subsystem Reference2'
 * '<S2>'   : 'H4_primera_Test_velocidad/Subsystem Reference3'
 * '<S3>'   : 'H4_primera_Test_velocidad/Subsystem Reference4'
 * '<S4>'   : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference'
 * '<S5>'   : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference1'
 * '<S6>'   : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1'
 * '<S7>'   : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2'
 * '<S8>'   : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Anti-windup'
 * '<S9>'   : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/D Gain'
 * '<S10>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Filter'
 * '<S11>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Filter ICs'
 * '<S12>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/I Gain'
 * '<S13>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Ideal P Gain'
 * '<S14>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Ideal P Gain Fdbk'
 * '<S15>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Integrator'
 * '<S16>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Integrator ICs'
 * '<S17>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/N Copy'
 * '<S18>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/N Gain'
 * '<S19>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/P Copy'
 * '<S20>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Parallel P Gain'
 * '<S21>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Reset Signal'
 * '<S22>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Saturation'
 * '<S23>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Saturation Fdbk'
 * '<S24>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Sum'
 * '<S25>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Sum Fdbk'
 * '<S26>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Tracking Mode'
 * '<S27>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Tracking Mode Sum'
 * '<S28>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Tsamp - Integral'
 * '<S29>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Tsamp - Ngain'
 * '<S30>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/postSat Signal'
 * '<S31>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/preSat Signal'
 * '<S32>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Anti-windup/Passthrough'
 * '<S33>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/D Gain/Disabled'
 * '<S34>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Filter/Disabled'
 * '<S35>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Filter ICs/Disabled'
 * '<S36>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/I Gain/Internal Parameters'
 * '<S37>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Ideal P Gain/Passthrough'
 * '<S38>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S39>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Integrator/Discrete'
 * '<S40>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Integrator ICs/Internal IC'
 * '<S41>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S42>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/N Gain/Disabled'
 * '<S43>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/P Copy/Disabled'
 * '<S44>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S45>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Reset Signal/Disabled'
 * '<S46>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Saturation/Enabled'
 * '<S47>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Saturation Fdbk/Disabled'
 * '<S48>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Sum/Sum_PI'
 * '<S49>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Sum Fdbk/Disabled'
 * '<S50>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Tracking Mode/Disabled'
 * '<S51>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S53>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/postSat Signal/Forward_Path'
 * '<S55>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller1/preSat Signal/Forward_Path'
 * '<S56>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Anti-windup'
 * '<S57>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/D Gain'
 * '<S58>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Filter'
 * '<S59>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Filter ICs'
 * '<S60>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/I Gain'
 * '<S61>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Ideal P Gain'
 * '<S62>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Ideal P Gain Fdbk'
 * '<S63>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Integrator'
 * '<S64>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Integrator ICs'
 * '<S65>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/N Copy'
 * '<S66>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/N Gain'
 * '<S67>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/P Copy'
 * '<S68>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Parallel P Gain'
 * '<S69>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Reset Signal'
 * '<S70>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Saturation'
 * '<S71>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Saturation Fdbk'
 * '<S72>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Sum'
 * '<S73>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Sum Fdbk'
 * '<S74>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Tracking Mode'
 * '<S75>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Tracking Mode Sum'
 * '<S76>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Tsamp - Integral'
 * '<S77>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Tsamp - Ngain'
 * '<S78>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/postSat Signal'
 * '<S79>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/preSat Signal'
 * '<S80>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Anti-windup/Passthrough'
 * '<S81>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/D Gain/Disabled'
 * '<S82>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Filter/Disabled'
 * '<S83>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Filter ICs/Disabled'
 * '<S84>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/I Gain/Internal Parameters'
 * '<S85>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Ideal P Gain/Passthrough'
 * '<S86>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S87>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Integrator/Discrete'
 * '<S88>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Integrator ICs/Internal IC'
 * '<S89>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S90>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/N Gain/Disabled'
 * '<S91>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/P Copy/Disabled'
 * '<S92>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S93>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Reset Signal/Disabled'
 * '<S94>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Saturation/Enabled'
 * '<S95>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Saturation Fdbk/Disabled'
 * '<S96>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Sum/Sum_PI'
 * '<S97>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Sum Fdbk/Disabled'
 * '<S98>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Tracking Mode/Disabled'
 * '<S99>'  : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S100>' : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S101>' : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S102>' : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/postSat Signal/Forward_Path'
 * '<S103>' : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference/PID Controller2/preSat Signal/Forward_Path'
 * '<S104>' : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference1/Subsystem Reference1'
 * '<S105>' : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference1/Subsystem Reference1/Subsystem Reference'
 * '<S106>' : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4'
 * '<S107>' : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference1/Subsystem Reference1/Subsystem Reference/Discrete Derivative1'
 * '<S108>' : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4/Compare To Zero'
 * '<S109>' : 'H4_primera_Test_velocidad/Subsystem Reference3/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4/Compare To Zero1'
 */
#endif                             /* RTW_HEADER_H4_primera_Test_velocidad_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
