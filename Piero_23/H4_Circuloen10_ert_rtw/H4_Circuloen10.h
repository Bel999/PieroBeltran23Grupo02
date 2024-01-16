/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: H4_Circuloen10.h
 *
 * Code generated for Simulink model 'H4_Circuloen10'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Dec 21 14:42:21 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_H4_Circuloen10_h_
#define RTW_HEADER_H4_Circuloen10_h_
#ifndef H4_Circuloen10_COMMON_INCLUDES_
#define H4_Circuloen10_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* H4_Circuloen10_COMMON_INCLUDES_ */

#include "H4_Circuloen10_types.h"
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

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S155>/Encoder1' */
  codertarget_arduinobase_inter_T obj_p;/* '<S155>/Encoder' */
  codertarget_arduinobase_int_a_T obj_g;/* '<S156>/Atras_izq' */
  codertarget_arduinobase_int_a_T obj_e;/* '<S156>/Atras_der' */
  codertarget_arduinobase_int_a_T obj_j;/* '<S156>/Adelante_izq' */
  codertarget_arduinobase_int_a_T obj_b;/* '<S156>/Adelante_der' */
  codertarget_arduinobase_block_T obj_m;/* '<S156>/Digital Output1' */
  codertarget_arduinobase_block_T obj_pi;/* '<S156>/Digital Output' */
  real_T Integrator_DSTATE;            /* '<S37>/Integrator' */
  real_T Filter_DSTATE;                /* '<S32>/Filter' */
  real_T Integrator_DSTATE_h;          /* '<S89>/Integrator' */
  real_T Integrator_DSTATE_he;         /* '<S137>/Integrator' */
  real_T UD_DSTATE[2];                 /* '<S157>/UD' */
  real_T Memory_PreviousInput;         /* '<Root>/Memory' */
  real_T Memory_PreviousInput_f[2];    /* '<S2>/Memory' */
} DW_H4_Circuloen10_T;

/* Parameters (default storage) */
struct P_H4_Circuloen10_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S31>/Derivative Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S86>/Integral Gain'
                                        */
  real_T PIDController2_I;             /* Mask Parameter: PIDController2_I
                                        * Referenced by: '<S134>/Integral Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S34>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S157>/UD'
                               */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S32>/Filter'
                               */
  real_T PIDController_InitialConditio_k;
                              /* Mask Parameter: PIDController_InitialConditio_k
                               * Referenced by: '<S37>/Integrator'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S89>/Integrator'
                               */
  real_T PIDController2_InitialCondition;
                              /* Mask Parameter: PIDController2_InitialCondition
                               * Referenced by: '<S137>/Integrator'
                               */
  real_T PIDController1_LowerSaturationL;
                              /* Mask Parameter: PIDController1_LowerSaturationL
                               * Referenced by: '<S96>/Saturation'
                               */
  real_T PIDController2_LowerSaturationL;
                              /* Mask Parameter: PIDController2_LowerSaturationL
                               * Referenced by: '<S144>/Saturation'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S40>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S42>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S94>/Proportional Gain'
                                        */
  real_T PIDController2_P;             /* Mask Parameter: PIDController2_P
                                        * Referenced by: '<S142>/Proportional Gain'
                                        */
  real_T PIDController1_UpperSaturationL;
                              /* Mask Parameter: PIDController1_UpperSaturationL
                               * Referenced by: '<S96>/Saturation'
                               */
  real_T PIDController2_UpperSaturationL;
                              /* Mask Parameter: PIDController2_UpperSaturationL
                               * Referenced by: '<S144>/Saturation'
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
  real_T Constant1_Value;              /* Expression: [0.3]
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S37>/Integrator'
                                        */
  real_T Constant2_Value;              /* Expression: [2*pi/10]
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S32>/Filter'
                                        */
  real_T Memory_InitialCondition_h;    /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T Integrator_gainval_d;       /* Computed Parameter: Integrator_gainval_d
                                      * Referenced by: '<S89>/Integrator'
                                      */
  real_T Integrator_gainval_i;       /* Computed Parameter: Integrator_gainval_i
                                      * Referenced by: '<S137>/Integrator'
                                      */
  real_T Constant_Value_b[4];          /* Expression: [1/2 1/2; -1/d 1/d]
                                        * Referenced by: '<S4>/Constant'
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
struct tag_RTM_H4_Circuloen10_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_H4_Circuloen10_T H4_Circuloen10_P;

/* Block states (default storage) */
extern DW_H4_Circuloen10_T H4_Circuloen10_DW;

/* Model entry point functions */
extern void H4_Circuloen10_initialize(void);
extern void H4_Circuloen10_step(void);
extern void H4_Circuloen10_terminate(void);

/* Real-time Model object */
extern RT_MODEL_H4_Circuloen10_T *const H4_Circuloen10_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display3' : Unused code path elimination
 * Block '<Root>/Display4' : Unused code path elimination
 * Block '<S2>/Display' : Unused code path elimination
 * Block '<S2>/Display1' : Unused code path elimination
 * Block '<S2>/Display2' : Unused code path elimination
 * Block '<S2>/Display3' : Unused code path elimination
 * Block '<S2>/Display4' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S154>/Display' : Unused code path elimination
 * Block '<S154>/Display1' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate' : Unused code path elimination
 * Block '<S155>/Display' : Unused code path elimination
 * Block '<S155>/Display1' : Unused code path elimination
 * Block '<S155>/Display2' : Unused code path elimination
 * Block '<S5>/Cos' : Unused code path elimination
 * Block '<S5>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S5>/Product' : Unused code path elimination
 * Block '<S5>/Product1' : Unused code path elimination
 * Block '<S5>/Sin' : Unused code path elimination
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
 * '<Root>' : 'H4_Circuloen10'
 * '<S1>'   : 'H4_Circuloen10/PID Controller'
 * '<S2>'   : 'H4_Circuloen10/Subsystem Reference'
 * '<S3>'   : 'H4_Circuloen10/Subsystem Reference1'
 * '<S4>'   : 'H4_Circuloen10/Subsystem Reference2'
 * '<S5>'   : 'H4_Circuloen10/Subsystem Reference4'
 * '<S6>'   : 'H4_Circuloen10/PID Controller/Anti-windup'
 * '<S7>'   : 'H4_Circuloen10/PID Controller/D Gain'
 * '<S8>'   : 'H4_Circuloen10/PID Controller/Filter'
 * '<S9>'   : 'H4_Circuloen10/PID Controller/Filter ICs'
 * '<S10>'  : 'H4_Circuloen10/PID Controller/I Gain'
 * '<S11>'  : 'H4_Circuloen10/PID Controller/Ideal P Gain'
 * '<S12>'  : 'H4_Circuloen10/PID Controller/Ideal P Gain Fdbk'
 * '<S13>'  : 'H4_Circuloen10/PID Controller/Integrator'
 * '<S14>'  : 'H4_Circuloen10/PID Controller/Integrator ICs'
 * '<S15>'  : 'H4_Circuloen10/PID Controller/N Copy'
 * '<S16>'  : 'H4_Circuloen10/PID Controller/N Gain'
 * '<S17>'  : 'H4_Circuloen10/PID Controller/P Copy'
 * '<S18>'  : 'H4_Circuloen10/PID Controller/Parallel P Gain'
 * '<S19>'  : 'H4_Circuloen10/PID Controller/Reset Signal'
 * '<S20>'  : 'H4_Circuloen10/PID Controller/Saturation'
 * '<S21>'  : 'H4_Circuloen10/PID Controller/Saturation Fdbk'
 * '<S22>'  : 'H4_Circuloen10/PID Controller/Sum'
 * '<S23>'  : 'H4_Circuloen10/PID Controller/Sum Fdbk'
 * '<S24>'  : 'H4_Circuloen10/PID Controller/Tracking Mode'
 * '<S25>'  : 'H4_Circuloen10/PID Controller/Tracking Mode Sum'
 * '<S26>'  : 'H4_Circuloen10/PID Controller/Tsamp - Integral'
 * '<S27>'  : 'H4_Circuloen10/PID Controller/Tsamp - Ngain'
 * '<S28>'  : 'H4_Circuloen10/PID Controller/postSat Signal'
 * '<S29>'  : 'H4_Circuloen10/PID Controller/preSat Signal'
 * '<S30>'  : 'H4_Circuloen10/PID Controller/Anti-windup/Passthrough'
 * '<S31>'  : 'H4_Circuloen10/PID Controller/D Gain/Internal Parameters'
 * '<S32>'  : 'H4_Circuloen10/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S33>'  : 'H4_Circuloen10/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S34>'  : 'H4_Circuloen10/PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'H4_Circuloen10/PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'H4_Circuloen10/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'H4_Circuloen10/PID Controller/Integrator/Discrete'
 * '<S38>'  : 'H4_Circuloen10/PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'H4_Circuloen10/PID Controller/N Copy/Disabled'
 * '<S40>'  : 'H4_Circuloen10/PID Controller/N Gain/Internal Parameters'
 * '<S41>'  : 'H4_Circuloen10/PID Controller/P Copy/Disabled'
 * '<S42>'  : 'H4_Circuloen10/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'H4_Circuloen10/PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'H4_Circuloen10/PID Controller/Saturation/Passthrough'
 * '<S45>'  : 'H4_Circuloen10/PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'H4_Circuloen10/PID Controller/Sum/Sum_PID'
 * '<S47>'  : 'H4_Circuloen10/PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'H4_Circuloen10/PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'H4_Circuloen10/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'H4_Circuloen10/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S51>'  : 'H4_Circuloen10/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'H4_Circuloen10/PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'H4_Circuloen10/PID Controller/preSat Signal/Forward_Path'
 * '<S54>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference'
 * '<S55>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference1'
 * '<S56>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1'
 * '<S57>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2'
 * '<S58>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Anti-windup'
 * '<S59>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/D Gain'
 * '<S60>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Filter'
 * '<S61>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Filter ICs'
 * '<S62>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/I Gain'
 * '<S63>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Ideal P Gain'
 * '<S64>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Ideal P Gain Fdbk'
 * '<S65>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Integrator'
 * '<S66>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Integrator ICs'
 * '<S67>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/N Copy'
 * '<S68>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/N Gain'
 * '<S69>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/P Copy'
 * '<S70>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Parallel P Gain'
 * '<S71>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Reset Signal'
 * '<S72>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Saturation'
 * '<S73>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Saturation Fdbk'
 * '<S74>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Sum'
 * '<S75>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Sum Fdbk'
 * '<S76>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Tracking Mode'
 * '<S77>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Tracking Mode Sum'
 * '<S78>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Tsamp - Integral'
 * '<S79>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Tsamp - Ngain'
 * '<S80>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/postSat Signal'
 * '<S81>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/preSat Signal'
 * '<S82>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Anti-windup/Passthrough'
 * '<S83>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/D Gain/Disabled'
 * '<S84>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Filter/Disabled'
 * '<S85>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Filter ICs/Disabled'
 * '<S86>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/I Gain/Internal Parameters'
 * '<S87>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Ideal P Gain/Passthrough'
 * '<S88>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S89>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Integrator/Discrete'
 * '<S90>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Integrator ICs/Internal IC'
 * '<S91>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S92>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/N Gain/Disabled'
 * '<S93>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/P Copy/Disabled'
 * '<S94>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S95>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Reset Signal/Disabled'
 * '<S96>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Saturation/Enabled'
 * '<S97>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Saturation Fdbk/Disabled'
 * '<S98>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Sum/Sum_PI'
 * '<S99>'  : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Sum Fdbk/Disabled'
 * '<S100>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Tracking Mode/Disabled'
 * '<S101>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S102>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S103>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S104>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/postSat Signal/Forward_Path'
 * '<S105>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller1/preSat Signal/Forward_Path'
 * '<S106>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Anti-windup'
 * '<S107>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/D Gain'
 * '<S108>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Filter'
 * '<S109>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Filter ICs'
 * '<S110>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/I Gain'
 * '<S111>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Ideal P Gain'
 * '<S112>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Ideal P Gain Fdbk'
 * '<S113>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Integrator'
 * '<S114>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Integrator ICs'
 * '<S115>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/N Copy'
 * '<S116>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/N Gain'
 * '<S117>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/P Copy'
 * '<S118>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Parallel P Gain'
 * '<S119>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Reset Signal'
 * '<S120>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Saturation'
 * '<S121>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Saturation Fdbk'
 * '<S122>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Sum'
 * '<S123>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Sum Fdbk'
 * '<S124>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Tracking Mode'
 * '<S125>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Tracking Mode Sum'
 * '<S126>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Tsamp - Integral'
 * '<S127>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Tsamp - Ngain'
 * '<S128>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/postSat Signal'
 * '<S129>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/preSat Signal'
 * '<S130>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Anti-windup/Passthrough'
 * '<S131>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/D Gain/Disabled'
 * '<S132>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Filter/Disabled'
 * '<S133>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Filter ICs/Disabled'
 * '<S134>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/I Gain/Internal Parameters'
 * '<S135>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Ideal P Gain/Passthrough'
 * '<S136>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S137>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Integrator/Discrete'
 * '<S138>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Integrator ICs/Internal IC'
 * '<S139>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S140>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/N Gain/Disabled'
 * '<S141>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/P Copy/Disabled'
 * '<S142>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S143>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Reset Signal/Disabled'
 * '<S144>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Saturation/Enabled'
 * '<S145>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Saturation Fdbk/Disabled'
 * '<S146>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Sum/Sum_PI'
 * '<S147>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Sum Fdbk/Disabled'
 * '<S148>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Tracking Mode/Disabled'
 * '<S149>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S150>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S151>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S152>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/postSat Signal/Forward_Path'
 * '<S153>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference/PID Controller2/preSat Signal/Forward_Path'
 * '<S154>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference1/Subsystem Reference1'
 * '<S155>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference'
 * '<S156>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4'
 * '<S157>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference/Discrete Derivative'
 * '<S158>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4/Compare To Zero'
 * '<S159>' : 'H4_Circuloen10/Subsystem Reference/Subsystem Reference1/Subsystem Reference1/Subsystem Reference4/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_H4_Circuloen10_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
