/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Evita_Paredes_Sist_Completo.h
 *
 * Code generated for Simulink model 'Evita_Paredes_Sist_Completo'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Nov 12 16:46:18 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Evita_Paredes_Sist_Completo_h_
#define RTW_HEADER_Evita_Paredes_Sist_Completo_h_
#ifndef Evita_Paredes_Sist_Completo_COMMON_INCLUDES_
#define Evita_Paredes_Sist_Completo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                        /* Evita_Paredes_Sist_Completo_COMMON_INCLUDES_ */

#include "Evita_Paredes_Sist_Completo_types.h"
#include "multiword_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  int96m_T r;
  int96m_T r1;
  int96m_T r2;
  int96m_T r3;
  int96m_T r4;
  int96m_T r5;
  int96m_T r6;
  real_T TmpRTBAtSwitchInport1;        /* '<S4>/Pulse Generator' */
  boolean_T TmpRTBAtSwitchInport2;     /* '<S4>/Cast To Boolean3' */
  boolean_T TmpRTBAtAND1Inport1;       /* '<S4>/Cast To Boolean1' */
  boolean_T TmpRTBAtANDInport1;        /* '<S4>/Cast To Boolean' */
  boolean_T TmpRTBAtAND2Inport1;       /* '<S4>/Cast To Boolean2' */
} B_Evita_Paredes_Sist_Completo_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<S3>/Sonar Izquierdo' */
  codertarget_arduinobase_inter_T obj_j;/* '<S3>/Sonar Derecho' */
  codertarget_arduinobase_block_T obj_e;/* '<S5>/Digital Output1' */
  codertarget_arduinobase_block_T obj_jk;/* '<S5>/Digital Output' */
  codertarget_arduinobase_block_T obj_f;/* '<S4>/YELLOW_LED' */
  codertarget_arduinobase_block_T obj_k;/* '<S4>/RED_LED' */
  codertarget_arduinobase_block_T obj_a;/* '<S4>/GREEN_LED' */
  codertarget_arduinobase_int_n_T obj_h;/* '<S5>/Atras_izq' */
  codertarget_arduinobase_int_n_T obj_hu;/* '<S5>/Atras_der' */
  codertarget_arduinobase_int_n_T obj_l;/* '<S5>/Adelante_izq' */
  codertarget_arduinobase_int_n_T obj_b;/* '<S5>/Adelante_der' */
  real_T TmpRTBAtSwitchInport1_Buffer0;/* synthesized block */
  int32_T clockTickCounter;            /* '<S4>/Pulse Generator' */
  boolean_T TmpRTBAtSwitchInport2_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtAND1Inport1_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtANDInport1_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtAND2Inport1_Buffer0;/* synthesized block */
} DW_Evita_Paredes_Sist_Complet_T;

/* Parameters (default storage) */
struct P_Evita_Paredes_Sist_Completo_T_ {
  uint32_T CompareToConstant3_const; /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S9>/Constant'
                                      */
  uint32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S6>/Constant'
                                       */
  uint32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S7>/Constant'
                                      */
  uint32_T CompareToConstant2_const; /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S8>/Constant'
                                      */
  uint32_T CompareToConstant4_const; /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S10>/Constant'
                                      */
  uint32_T CompareToConstant5_const; /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S11>/Constant'
                                      */
  uint8_T BitwiseOperator_BitMask;    /* Mask Parameter: BitwiseOperator_BitMask
                                       * Referenced by: '<S4>/Bitwise Operator'
                                       */
  uint8_T BitwiseOperator1_BitMask;  /* Mask Parameter: BitwiseOperator1_BitMask
                                      * Referenced by: '<S4>/Bitwise Operator1'
                                      */
  uint8_T BitwiseOperator2_BitMask;  /* Mask Parameter: BitwiseOperator2_BitMask
                                      * Referenced by: '<S4>/Bitwise Operator2'
                                      */
  uint8_T BitwiseOperator3_BitMask;  /* Mask Parameter: BitwiseOperator3_BitMask
                                      * Referenced by: '<S4>/Bitwise Operator3'
                                      */
  real_T SonarDerecho_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<S3>/Sonar Derecho'
                                        */
  real_T SonarIzquierdo_SampleTime;    /* Expression: 0.1
                                        * Referenced by: '<S3>/Sonar Izquierdo'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T TmpRTBAtSwitchInport1_InitialCo;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S4>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S4>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S4>/Pulse Generator'
                                        */
  uint32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S2>/Gain'
                                        */
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S12>/Constant'
                                        */
  int16_T Constant_Value_b;            /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S13>/Constant'
                                        */
  int16_T Saturation_UpperSat;        /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S2>/Saturation'
                                       */
  int16_T Saturation_LowerSat;        /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S2>/Saturation'
                                       */
  int16_T Saturation2_UpperSat;      /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<S5>/Saturation2'
                                      */
  int16_T Saturation2_LowerSat;      /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<S5>/Saturation2'
                                      */
  int16_T Saturation4_UpperSat;      /* Computed Parameter: Saturation4_UpperSat
                                      * Referenced by: '<S5>/Saturation4'
                                      */
  int16_T Saturation4_LowerSat;      /* Computed Parameter: Saturation4_LowerSat
                                      * Referenced by: '<S5>/Saturation4'
                                      */
  int16_T Saturation3_UpperSat;      /* Computed Parameter: Saturation3_UpperSat
                                      * Referenced by: '<S5>/Saturation3'
                                      */
  int16_T Saturation3_LowerSat;      /* Computed Parameter: Saturation3_LowerSat
                                      * Referenced by: '<S5>/Saturation3'
                                      */
  int16_T Saturation5_UpperSat;      /* Computed Parameter: Saturation5_UpperSat
                                      * Referenced by: '<S5>/Saturation5'
                                      */
  int16_T Saturation5_LowerSat;      /* Computed Parameter: Saturation5_LowerSat
                                      * Referenced by: '<S5>/Saturation5'
                                      */
  uint16_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S3>/Gain'
                                        */
  boolean_T TmpRTBAtSwitchInport2_InitialCo;
                          /* Computed Parameter: TmpRTBAtSwitchInport2_InitialCo
                           * Referenced by:
                           */
  boolean_T TmpRTBAtAND1Inport1_InitialCond;
                          /* Computed Parameter: TmpRTBAtAND1Inport1_InitialCond
                           * Referenced by:
                           */
  boolean_T TmpRTBAtANDInport1_InitialCondi;
                          /* Computed Parameter: TmpRTBAtANDInport1_InitialCondi
                           * Referenced by:
                           */
  boolean_T TmpRTBAtAND2Inport1_InitialCond;
                          /* Computed Parameter: TmpRTBAtAND2Inport1_InitialCond
                           * Referenced by:
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_Evita_Paredes_Sist_Co_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
      boolean_T TID0_2;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Evita_Paredes_Sist_Completo_T Evita_Paredes_Sist_Completo_P;

/* Block signals (default storage) */
extern B_Evita_Paredes_Sist_Completo_T Evita_Paredes_Sist_Completo_B;

/* Block states (default storage) */
extern DW_Evita_Paredes_Sist_Complet_T Evita_Paredes_Sist_Completo_DW;

/* External function called from main */
extern void Evita_Paredes_Sist_Completo_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void Evita_Paredes_Sist_Completo_initialize(void);
extern void Evita_Paredes_Sist_Completo_step0(void);
extern void Evita_Paredes_Sist_Completo_step1(void);
extern void Evita_Paredes_Sist_Completo_step2(void);
extern void Evita_Paredes_Sist_Completo_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Evita_Paredes_Sist_C_T *const Evita_Paredes_Sist_Completo_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Evita_Paredes_Sist_Completo'
 * '<S1>'   : 'Evita_Paredes_Sist_Completo/Controlador Alerta'
 * '<S2>'   : 'Evita_Paredes_Sist_Completo/Controlador motor'
 * '<S3>'   : 'Evita_Paredes_Sist_Completo/Subsystem Reference'
 * '<S4>'   : 'Evita_Paredes_Sist_Completo/Subsystem Reference3'
 * '<S5>'   : 'Evita_Paredes_Sist_Completo/Subsystem Reference4'
 * '<S6>'   : 'Evita_Paredes_Sist_Completo/Controlador Alerta/Compare To Constant'
 * '<S7>'   : 'Evita_Paredes_Sist_Completo/Controlador Alerta/Compare To Constant1'
 * '<S8>'   : 'Evita_Paredes_Sist_Completo/Controlador Alerta/Compare To Constant2'
 * '<S9>'   : 'Evita_Paredes_Sist_Completo/Controlador Alerta/Compare To Constant3'
 * '<S10>'  : 'Evita_Paredes_Sist_Completo/Controlador Alerta/Compare To Constant4'
 * '<S11>'  : 'Evita_Paredes_Sist_Completo/Controlador Alerta/Compare To Constant5'
 * '<S12>'  : 'Evita_Paredes_Sist_Completo/Subsystem Reference4/Compare To Zero'
 * '<S13>'  : 'Evita_Paredes_Sist_Completo/Subsystem Reference4/Compare To Zero1'
 */
#endif                           /* RTW_HEADER_Evita_Paredes_Sist_Completo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
