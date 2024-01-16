/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled1.h
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Nov 14 19:52:17 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_untitled1_h_
#define RTW_HEADER_untitled1_h_
#ifndef untitled1_COMMON_INCLUDES_
#define untitled1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* untitled1_COMMON_INCLUDES_ */

#include "untitled1_types.h"
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

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S3>/Encoder1' */
  codertarget_arduinobase_inter_T obj_p;/* '<S3>/Encoder' */
  codertarget_arduinobase_int_l_T obj_m;/* '<S4>/Atras_izq' */
  codertarget_arduinobase_int_l_T obj_l;/* '<S4>/Atras_der' */
  codertarget_arduinobase_int_l_T obj_c;/* '<S4>/Adelante_izq' */
  codertarget_arduinobase_int_l_T obj_k;/* '<S4>/Adelante_der' */
  codertarget_arduinobase_block_T obj_o;/* '<S4>/Digital Output1' */
  codertarget_arduinobase_block_T obj_mx;/* '<S4>/Digital Output' */
} DW_untitled1_T;

/* Parameters (default storage) */
struct P_untitled1_T_ {
  real_T Encoder_SampleTime;           /* Expression: 0.1
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: 0.1
                                        * Referenced by: '<S3>/Encoder1'
                                        */
  real_T Constant_Value[2];            /* Expression: [0.205 0.205]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T CRIzq1_tableData[11];
                   /* Expression: [-255 -200 -150 -100 -50 0 50 100 150 200 255]
                    * Referenced by: '<S1>/CRIzq1'
                    */
  real_T CRIzq1_bp01Data[11];
  /* Expression: [-0.455300360918045 -0.374873638153076 -0.276723057031631 -0.175849363207817 -0.043621104210615 0.029990104958415 0.141770377755165 0.244007378816605 0.339430898427963 0.430762141942978 0.448484838008881]
   * Referenced by: '<S1>/CRIzq1'
   */
  real_T CRDere1_tableData[11];
                   /* Expression: [-255 -200 -150 -100 -50 0 50 100 150 200 255]
                    * Referenced by: '<S1>/CRDere1'
                    */
  real_T CRDere1_bp01Data[11];
  /* Expression: [-0.443032205104828 -0.363968372344971 -0.268544733524323 -0.171759888529778 -0.044984862208366 0.031352669000626 0.143133535981178 0.245370522141457 0.347609847784042 0.441668003797531 0.458026975393295]
   * Referenced by: '<S1>/CRDere1'
   */
  int16_T Constant_Value_o;            /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S5>/Constant'
                                        */
  int16_T Constant_Value_h;            /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S6>/Constant'
                                        */
  int16_T Saturation2_UpperSat;      /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S4>/Saturation2'
                                      */
  int16_T Saturation2_LowerSat;      /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S4>/Saturation2'
                                      */
  int16_T Saturation4_UpperSat;      /* Computed Parameter: Saturation4_UpperSat
                                      * Referenced by: '<S4>/Saturation4'
                                      */
  int16_T Saturation4_LowerSat;      /* Computed Parameter: Saturation4_LowerSat
                                      * Referenced by: '<S4>/Saturation4'
                                      */
  int16_T Saturation3_UpperSat;      /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<S4>/Saturation3'
                                      */
  int16_T Saturation3_LowerSat;      /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<S4>/Saturation3'
                                      */
  int16_T Saturation5_UpperSat;      /* Computed Parameter: Saturation5_UpperSat
                                      * Referenced by: '<S4>/Saturation5'
                                      */
  int16_T Saturation5_LowerSat;      /* Computed Parameter: Saturation5_LowerSat
                                      * Referenced by: '<S4>/Saturation5'
                                      */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled1_T {
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
extern P_untitled1_T untitled1_P;

/* Block states (default storage) */
extern DW_untitled1_T untitled1_DW;

/* Model entry point functions */
extern void untitled1_initialize(void);
extern void untitled1_step(void);
extern void untitled1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled1_T *const untitled1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S3>/Derivative' : Unused code path elimination
 * Block '<S3>/Gain' : Unused code path elimination
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
 * '<Root>' : 'untitled1'
 * '<S1>'   : 'untitled1/Subsystem Reference'
 * '<S2>'   : 'untitled1/Subsystem Reference1'
 * '<S3>'   : 'untitled1/Subsystem Reference1/Subsystem Reference'
 * '<S4>'   : 'untitled1/Subsystem Reference1/Subsystem Reference4'
 * '<S5>'   : 'untitled1/Subsystem Reference1/Subsystem Reference4/Compare To Zero'
 * '<S6>'   : 'untitled1/Subsystem Reference1/Subsystem Reference4/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_untitled1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
