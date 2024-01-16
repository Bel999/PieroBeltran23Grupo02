/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: controlBA.h
 *
 * Code generated for Simulink model 'controlBA'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Nov 15 00:33:25 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controlBA_h_
#define RTW_HEADER_controlBA_h_
#ifndef controlBA_COMMON_INCLUDES_
#define controlBA_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* controlBA_COMMON_INCLUDES_ */

#include "controlBA_types.h"
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
  real_T Constant[2];                  /* '<Root>/Constant' */
  real_T Gain[2];                      /* '<S3>/Gain' */
  real_T Derivative[2];                /* '<S3>/Derivative' */
  int32_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S3>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  int32_T Encoder1;                    /* '<S3>/Encoder1' */
  int32_T Encoder;                     /* '<S3>/Encoder' */
} B_controlBA_T;

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
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_controlBA_T;

/* Parameters (default storage) */
struct P_controlBA_T_ {
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S3>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S3>/Encoder1'
                                        */
  real_T Constant_Value[2];            /* Expression: [0.205 0.205]
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: pi*0.065/1498
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T CRIzq1_tableData[11];
                   /* Expression: [-255 -200 -150 -100 -50 0 50 100 150 200 255]
                    * Referenced by: '<S1>/CRIzq1'
                    */
  real_T CRIzq1_bp01Data[11];
  /* Expression: [-0.46346914768219 -0.368067800998688 -0.272638410329819 -0.190837785601616 -0.054527681320906 0 0.109050162136555 0.204469054937363 0.299901068210602 0.381690621376038 0.43621701002121]
   * Referenced by: '<S1>/CRIzq1'
   */
  real_T CRDere1_tableData[11];
                   /* Expression: [-255 -200 -150 -100 -50 0 50 100 150 200 255]
                    * Referenced by: '<S1>/CRDere1'
                    */
  real_T CRDere1_bp01Data[11];
  /* Expression: [-0.449837893247604 -0.368067800998688 -0.272644370794296 -0.177214965224266 -0.081791520118713 0 0.122681431472301 0.218100324273109 0.313526690006256 0.395322233438492 0.449848592281342]
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
struct tag_RTM_controlBA_T {
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
extern P_controlBA_T controlBA_P;

/* Block signals (default storage) */
extern B_controlBA_T controlBA_B;

/* Block states (default storage) */
extern DW_controlBA_T controlBA_DW;

/* Model entry point functions */
extern void controlBA_initialize(void);
extern void controlBA_step(void);
extern void controlBA_terminate(void);

/* Real-time Model object */
extern RT_MODEL_controlBA_T *const controlBA_M;
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
 * '<Root>' : 'controlBA'
 * '<S1>'   : 'controlBA/Subsystem Reference'
 * '<S2>'   : 'controlBA/Subsystem Reference1'
 * '<S3>'   : 'controlBA/Subsystem Reference1/Subsystem Reference'
 * '<S4>'   : 'controlBA/Subsystem Reference1/Subsystem Reference4'
 * '<S5>'   : 'controlBA/Subsystem Reference1/Subsystem Reference4/Compare To Zero'
 * '<S6>'   : 'controlBA/Subsystem Reference1/Subsystem Reference4/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_controlBA_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
