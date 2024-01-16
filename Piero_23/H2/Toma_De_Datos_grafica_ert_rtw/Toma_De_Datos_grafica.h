/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Toma_De_Datos_grafica.h
 *
 * Code generated for Simulink model 'Toma_De_Datos_grafica'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Nov 14 16:13:53 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Toma_De_Datos_grafica_h_
#define RTW_HEADER_Toma_De_Datos_grafica_h_
#ifndef Toma_De_Datos_grafica_COMMON_INCLUDES_
#define Toma_De_Datos_grafica_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                              /* Toma_De_Datos_grafica_COMMON_INCLUDES_ */

#include "Toma_De_Datos_grafica_types.h"
#include <math.h>
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
  real_T Signal1;                      /* '<S1>/fromWS_Signal 1' */
  real_T Gain[2];                      /* '<S3>/Gain' */
  real_T Derivative[2];                /* '<S3>/Derivative' */
  real_T TmpSignalConversionAt_asyncqueu[4];
  /* '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To WorkspaceInport1' */
} B_Toma_De_Datos_grafica_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S3>/Encoder1' */
  codertarget_arduinobase_inter_T obj_p;/* '<S3>/Encoder' */
  codertarget_arduinobase_int_j_T obj_m;/* '<S4>/Atras_izq' */
  codertarget_arduinobase_int_j_T obj_l;/* '<S4>/Atras_der' */
  codertarget_arduinobase_int_j_T obj_c;/* '<S4>/Adelante_izq' */
  codertarget_arduinobase_int_j_T obj_k;/* '<S4>/Adelante_der' */
  codertarget_arduinobase_block_T obj_o;/* '<S4>/Digital Output1' */
  codertarget_arduinobase_block_T obj_mx;/* '<S4>/Digital Output' */
  real_T TimeStampA;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeA[2];              /* '<S3>/Derivative' */
  real_T TimeStampB;                   /* '<S3>/Derivative' */
  real_T LastUAtTimeB[2];              /* '<S3>/Derivative' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK;              /* '<S1>/fromWS_Signal 1' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK;              /* '<S1>/fromWS_Signal 1' */
} DW_Toma_De_Datos_grafica_T;

/* Parameters (default storage) */
struct P_Toma_De_Datos_grafica_T_ {
  real_T Encoder_SampleTime;           /* Expression: 0.1
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: 0.1
                                        * Referenced by: '<S3>/Encoder1'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S3>/Gain'
                                        */
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
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
struct tag_RTM_Toma_De_Datos_grafica_T {
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
extern P_Toma_De_Datos_grafica_T Toma_De_Datos_grafica_P;

/* Block signals (default storage) */
extern B_Toma_De_Datos_grafica_T Toma_De_Datos_grafica_B;

/* Block states (default storage) */
extern DW_Toma_De_Datos_grafica_T Toma_De_Datos_grafica_DW;

/* Model entry point functions */
extern void Toma_De_Datos_grafica_initialize(void);
extern void Toma_De_Datos_grafica_step(void);
extern void Toma_De_Datos_grafica_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Toma_De_Datos_grafic_T *const Toma_De_Datos_grafica_M;
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
 * '<Root>' : 'Toma_De_Datos_grafica'
 * '<S1>'   : 'Toma_De_Datos_grafica/Signal Editor1'
 * '<S2>'   : 'Toma_De_Datos_grafica/Subsystem Reference'
 * '<S3>'   : 'Toma_De_Datos_grafica/Subsystem Reference/Subsystem Reference'
 * '<S4>'   : 'Toma_De_Datos_grafica/Subsystem Reference/Subsystem Reference4'
 * '<S5>'   : 'Toma_De_Datos_grafica/Subsystem Reference/Subsystem Reference4/Compare To Zero'
 * '<S6>'   : 'Toma_De_Datos_grafica/Subsystem Reference/Subsystem Reference4/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_Toma_De_Datos_grafica_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
