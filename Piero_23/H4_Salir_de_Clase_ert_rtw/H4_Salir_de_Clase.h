/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: H4_Salir_de_Clase.h
 *
 * Code generated for Simulink model 'H4_Salir_de_Clase'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Dec 20 12:04:38 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_H4_Salir_de_Clase_h_
#define RTW_HEADER_H4_Salir_de_Clase_h_
#ifndef H4_Salir_de_Clase_COMMON_INCLUDES_
#define H4_Salir_de_Clase_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* H4_Salir_de_Clase_COMMON_INCLUDES_ */

#include "H4_Salir_de_Clase_types.h"
#include <math.h>
#include "rt_nonfinite.h"
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
  real_T TSamp[2];                     /* '<S158>/TSamp' */
  real_T MatrixMultiply[2];            /* '<S5>/Matrix Multiply' */
  real_T Gain1[2];                     /* '<S155>/Gain1' */
  real_T Sum;
  real_T error_idx_0;
} B_H4_Salir_de_Clase_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S156>/Encoder1' */
  codertarget_arduinobase_inter_T obj_p;/* '<S156>/Encoder' */
  codertarget_arduinobase_int_p_T obj_g;/* '<S157>/Atras_izq' */
  codertarget_arduinobase_int_p_T obj_e;/* '<S157>/Atras_der' */
  codertarget_arduinobase_int_p_T obj_j;/* '<S157>/Adelante_izq' */
  codertarget_arduinobase_int_p_T obj_b;/* '<S157>/Adelante_der' */
  codertarget_arduinobase_block_T obj_m;/* '<S157>/Digital Output1' */
  codertarget_arduinobase_block_T obj_pi;/* '<S157>/Digital Output' */
  real_T Integrator_DSTATE;            /* '<S38>/Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_h;          /* '<S90>/Integrator' */
  real_T Integrator_DSTATE_he;         /* '<S138>/Integrator' */
  real_T UD_DSTATE[2];                 /* '<S158>/UD' */
  real_T Memory_PreviousInput[2];      /* '<S3>/Memory' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S2>/From Workspace' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK;              /* '<S2>/fromWS_Signal 1' */

  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S2>/From Workspace' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK;              /* '<S2>/fromWS_Signal 1' */
} DW_H4_Salir_de_Clase_T;

/* Parameters (default storage) */
struct P_H4_Salir_de_Clase_T_ {
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S87>/Integral Gain'
                                        */
  real_T PIDController2_I;             /* Mask Parameter: PIDController2_I
                                        * Referenced by: '<S135>/Integral Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S35>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S158>/UD'
                               */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S38>/Integrator'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S90>/Integrator'
                               */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S138>/Integrator'
                               */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S97>/Saturation'
                               */
  real_T PIDController2_LowerSaturationL;
                              /* Mask Parameter: PIDController2_LowerSaturationL
                               * Referenced by: '<S145>/Saturation'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S43>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S95>/Proportional Gain'
                                        */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S143>/Proportional Gain'
                                        */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S97>/Saturation'
                               */
  real_T PIDController2_UpperSaturationL;
                              /* Mask Parameter: PIDController2_UpperSaturationL
                               * Referenced by: '<S145>/Saturation'
                               */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S156>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S156>/Encoder1'
                                        */
  real_T Constant_Value[4];            /* Expression: [1 -d/2; 1 d/2]
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S38>/Integrator'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T Integrator_gainval_d;       /* Computed Parameter: Integrator_gainval_d
                                      * Referenced by: '<S90>/Integrator'
                                      */
  real_T Integrator_gainval_i;       /* Computed Parameter: Integrator_gainval_i
                                      * Referenced by: '<S138>/Integrator'
                                      */
  real_T Constant_Value_b[4];          /* Expression: [1/2 1/2; -1/d 1/d]
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S158>/TSamp'
                                        */
  real_T Gain1_Gain[2];                /* Expression: [1.0045 1]
                                        * Referenced by: '<S155>/Gain1'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S156>/Gain'
                                        */
  int16_T Constant_Value_c;            /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S159>/Constant'
                                        */
  int16_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S160>/Constant'
                                        */
  int16_T Saturation2_UpperSat;      /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S157>/Saturation2'
                                      */
  int16_T Saturation2_LowerSat;      /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S157>/Saturation2'
                                      */
  int16_T Saturation4_UpperSat;      /* Computed Parameter: Saturation4_UpperSat
                                      * Referenced by: '<S157>/Saturation4'
                                      */
  int16_T Saturation4_LowerSat;      /* Computed Parameter: Saturation4_LowerSat
                                      * Referenced by: '<S157>/Saturation4'
                                      */
  int16_T Saturation3_UpperSat;      /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<S157>/Saturation3'
                                      */
  int16_T Saturation3_LowerSat;      /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<S157>/Saturation3'
                                      */
  int16_T Saturation5_UpperSat;      /* Computed Parameter: Saturation5_UpperSat
                                      * Referenced by: '<S157>/Saturation5'
                                      */
  int16_T Saturation5_LowerSat;      /* Computed Parameter: Saturation5_LowerSat
                                      * Referenced by: '<S157>/Saturation5'
                                      */
};

/* Real-time Model Data Structure */
struct tag_RTM_H4_Salir_de_Clase_T {
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
extern P_H4_Salir_de_Clase_T H4_Salir_de_Clase_P;

/* Block signals (default storage) */
extern B_H4_Salir_de_Clase_T H4_Salir_de_Clase_B;

/* Block states (default storage) */
extern DW_H4_Salir_de_Clase_T H4_Salir_de_Clase_DW;

/* Model entry point functions */
extern void H4_Salir_de_Clase_initialize(void);
extern void H4_Salir_de_Clase_step(void);
extern void H4_Salir_de_Clase_terminate(void);

/* Real-time Model object */
extern RT_MODEL_H4_Salir_de_Clase_T *const H4_Salir_de_Clase_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Display' : Unused code path elimination
 * Block '<S3>/Display1' : Unused code path elimination
 * Block '<S3>/Display2' : Unused code path elimination
 * Block '<S3>/Display3' : Unused code path elimination
 * Block '<S3>/Display4' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S155>/Display' : Unused code path elimination
 * Block '<S155>/Display1' : Unused code path elimination
 * Block '<S158>/Data Type Duplicate' : Unused code path elimination
 * Block '<S156>/Display' : Unused code path elimination
 * Block '<S156>/Display1' : Unused code path elimination
 * Block '<S156>/Display2' : Unused code path elimination
 * Block '<S6>/Cos' : Unused code path elimination
 * Block '<S6>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S6>/Product' : Unused code path elimination
 * Block '<S6>/Product1' : Unused code path elimination
 * Block '<S6>/Sin' : Unused code path elimination
 * Block '<S157>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'H4_Salir_de_Clase'
 * '<S1>'   : 'H4_Salir_de_Clase/PID Controller'
 * '<S2>'   : 'H4_Salir_de_Clase/Signal Editor'
 * '<S3>'   : 'H4_Salir_de_Clase/Subsystem Reference'
 * '<S4>'   : 'H4_Salir_de_Clase/Subsystem Reference1'
 * '<S5>'   : 'H4_Salir_de_Clase/Subsystem Reference2'
 * '<S6>'   : 'H4_Salir_de_Clase/Subsystem Reference4'
 * '<S7>'   : 'H4_Salir_de_Clase/PID Controller/Anti-windup'
 * '<S8>'   : 'H4_Salir_de_Clase/PID Controller/D Gain'
 * '<S9>'   : 'H4_Salir_de_Clase/PID Controller/Filter'
 * '<S10>'  : 'H4_Salir_de_Clase/PID Controller/Filter ICs'
 * '<S11>'  : 'H4_Salir_de_Clase/PID Controller/I Gain'
 * '<S12>'  : 'H4_Salir_de_Clase/PID Controller/Ideal P Gain'
 * '<S13>'  : 'H4_Salir_de_Clase/PID Controller/Ideal P Gain Fdbk'
 * '<S14>'  : 'H4_Salir_de_Clase/PID Controller/Integrator'
 * '<S15>'  : 'H4_Salir_de_Clase/PID Controller/Integrator ICs'
 * '<S16>'  : 'H4_Salir_de_Clase/PID Controller/N Copy'
 * '<S17>'  : 'H4_Salir_de_Clase/PID Controller/N Gain'
 * '<S18>'  : 'H4_Salir_de_Clase/PID Controller/P Copy'
 * '<S19>'  : 'H4_Salir_de_Clase/PID Controller/Parallel P Gain'
 * '<S20>'  : 'H4_Salir_de_Clase/PID Controller/Reset Signal'
 * '<S21>'  : 'H4_Salir_de_Clase/PID Controller/Saturation'
 * '<S22>'  : 'H4_Salir_de_Clase/PID Controller/Saturation Fdbk'
 * '<S23>'  : 'H4_Salir_de_Clase/PID Controller/Sum'
 * '<S24>'  : 'H4_Salir_de_Clase/PID Controller/Sum Fdbk'
 * '<S25>'  : 'H4_Salir_de_Clase/PID Controller/Tracking Mode'
 * '<S26>'  : 'H4_Salir_de_Clase/PID Controller/Tracking Mode Sum'
 * '<S27>'  : 'H4_Salir_de_Clase/PID Controller/Tsamp - Integral'
 * '<S28>'  : 'H4_Salir_de_Clase/PID Controller/Tsamp - Ngain'
 * '<S29>'  : 'H4_Salir_de_Clase/PID Controller/postSat Signal'
 * '<S30>'  : 'H4_Salir_de_Clase/PID Controller/preSat Signal'
 * '<S31>'  : 'H4_Salir_de_Clase/PID Controller/Anti-windup/Passthrough'
 * '<S32>'  : 'H4_Salir_de_Clase/PID Controller/D Gain/Disabled'
 * '<S33>'  : 'H4_Salir_de_Clase/PID Controller/Filter/Disabled'
 * '<S34>'  : 'H4_Salir_de_Clase/PID Controller/Filter ICs/Disabled'
 * '<S35>'  : 'H4_Salir_de_Clase/PID Controller/I Gain/Internal Parameters'
 * '<S36>'  : 'H4_Salir_de_Clase/PID Controller/Ideal P Gain/Passthrough'
 * '<S37>'  : 'H4_Salir_de_Clase/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'H4_Salir_de_Clase/PID Controller/Integrator/Discrete'
 * '<S39>'  : 'H4_Salir_de_Clase/PID Controller/Integrator ICs/Internal IC'
 * '<S40>'  : 'H4_Salir_de_Clase/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S41>'  : 'H4_Salir_de_Clase/PID Controller/N Gain/Disabled'
 * '<S42>'  : 'H4_Salir_de_Clase/PID Controller/P Copy/Disabled'
 * '<S43>'  : 'H4_Salir_de_Clase/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S44>'  : 'H4_Salir_de_Clase/PID Controller/Reset Signal/Disabled'
 * '<S45>'  : 'H4_Salir_de_Clase/PID Controller/Saturation/Passthrough'
 * '<S46>'  : 'H4_Salir_de_Clase/PID Controller/Saturation Fdbk/Disabled'
 * '<S47>'  : 'H4_Salir_de_Clase/PID Controller/Sum/Sum_PI'
 * '<S48>'  : 'H4_Salir_de_Clase/PID Controller/Sum Fdbk/Disabled'
 * '<S49>'  : 'H4_Salir_de_Clase/PID Controller/Tracking Mode/Disabled'
 * '<S50>'  : 'H4_Salir_de_Clase/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'H4_Salir_de_Clase/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S52>'  : 'H4_Salir_de_Clase/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'H4_Salir_de_Clase/PID Controller/postSat Signal/Forward_Path'
 * '<S54>'  : 'H4_Salir_de_Clase/PID Controller/preSat Signal/Forward_Path'
 * '<S55>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference'
 * '<S56>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference1'
 * '<S57>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1'
 * '<S58>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2'
 * '<S59>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Anti-windup'
 * '<S60>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/D Gain'
 * '<S61>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Filter'
 * '<S62>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Filter ICs'
 * '<S63>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/I Gain'
 * '<S64>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Ideal P Gain'
 * '<S65>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Ideal P Gain Fdbk'
 * '<S66>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Integrator'
 * '<S67>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Integrator ICs'
 * '<S68>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/N Copy'
 * '<S69>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/N Gain'
 * '<S70>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/P Copy'
 * '<S71>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Parallel P Gain'
 * '<S72>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Reset Signal'
 * '<S73>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Saturation'
 * '<S74>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Saturation Fdbk'
 * '<S75>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Sum'
 * '<S76>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Sum Fdbk'
 * '<S77>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Tracking Mode'
 * '<S78>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Tracking Mode Sum'
 * '<S79>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Tsamp - Integral'
 * '<S80>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Tsamp - Ngain'
 * '<S81>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/postSat Signal'
 * '<S82>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/preSat Signal'
 * '<S83>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Anti-windup/Passthrough'
 * '<S84>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/D Gain/Disabled'
 * '<S85>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Filter/Disabled'
 * '<S86>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Filter ICs/Disabled'
 * '<S87>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/I Gain/Internal Parameters'
 * '<S88>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Ideal P Gain/Passthrough'
 * '<S89>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S90>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Integrator/Discrete'
 * '<S91>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Integrator ICs/Internal IC'
 * '<S92>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S93>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/N Gain/Disabled'
 * '<S94>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/P Copy/Disabled'
 * '<S95>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S96>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Reset Signal/Disabled'
 * '<S97>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Saturation/Enabled'
 * '<S98>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Saturation Fdbk/Disabled'
 * '<S99>'  : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Sum/Sum_PI'
 * '<S100>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Sum Fdbk/Disabled'
 * '<S101>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Tracking Mode/Disabled'
 * '<S102>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S103>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S104>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S105>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/postSat Signal/Forward_Path'
 * '<S106>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller1/preSat Signal/Forward_Path'
 * '<S107>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Anti-windup'
 * '<S108>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/D Gain'
 * '<S109>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Filter'
 * '<S110>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Filter ICs'
 * '<S111>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/I Gain'
 * '<S112>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Ideal P Gain'
 * '<S113>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Ideal P Gain Fdbk'
 * '<S114>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Integrator'
 * '<S115>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Integrator ICs'
 * '<S116>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/N Copy'
 * '<S117>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/N Gain'
 * '<S118>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/P Copy'
 * '<S119>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Parallel P Gain'
 * '<S120>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Reset Signal'
 * '<S121>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Saturation'
 * '<S122>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Saturation Fdbk'
 * '<S123>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Sum'
 * '<S124>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Sum Fdbk'
 * '<S125>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Tracking Mode'
 * '<S126>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Tracking Mode Sum'
 * '<S127>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Tsamp - Integral'
 * '<S128>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Tsamp - Ngain'
 * '<S129>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/postSat Signal'
 * '<S130>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/preSat Signal'
 * '<S131>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Anti-windup/Passthrough'
 * '<S132>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/D Gain/Disabled'
 * '<S133>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Filter/Disabled'
 * '<S134>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Filter ICs/Disabled'
 * '<S135>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/I Gain/Internal Parameters'
 * '<S136>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Ideal P Gain/Passthrough'
 * '<S137>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S138>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Integrator/Discrete'
 * '<S139>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Integrator ICs/Internal IC'
 * '<S140>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S141>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/N Gain/Disabled'
 * '<S142>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/P Copy/Disabled'
 * '<S143>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S144>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Reset Signal/Disabled'
 * '<S145>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Saturation/Enabled'
 * '<S146>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Saturation Fdbk/Disabled'
 * '<S147>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Sum/Sum_PI'
 * '<S148>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Sum Fdbk/Disabled'
 * '<S149>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Tracking Mode/Disabled'
 * '<S150>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S151>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S152>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S153>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/postSat Signal/Forward_Path'
 * '<S154>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference/PID Controller2/preSat Signal/Forward_Path'
 * '<S155>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference1/Subsystem Reference1'
 * '<S156>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference'
 * '<S157>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4'
 * '<S158>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference/Discrete Derivative'
 * '<S159>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4/Compare To Zero'
 * '<S160>' : 'H4_Salir_de_Clase/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_H4_Salir_de_Clase_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
