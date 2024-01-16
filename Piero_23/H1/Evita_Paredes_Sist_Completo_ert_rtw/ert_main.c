/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include "Evita_Paredes_Sist_Completo.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[3] = { 0, 0, 0 };

boolean_T need2runFlags[3] = { 0, 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[3];
  int_T i;

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.
   */
  Evita_Paredes_Sist_Completo_SetEventsForThisBaseStep(eventFlags);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  Evita_Paredes_Sist_Completo_step0();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  isRateRunning[0]--;
  for (i = 1; i < 3; i++) {
    if (eventFlags[i]) {
      if (need2runFlags[i]++) {
        IsrOverrun = 1;
        need2runFlags[i]--;            /* allow future iterations to succeed*/
        break;
      }
    }
  }

  for (i = 1; i < 3; i++) {
    if (isRateRunning[i]) {
      /* Yield to higher priority*/
      return;
    }

    if (need2runFlags[i]) {
      isRateRunning[i]++;

#ifndef _MW_ARDUINO_LOOP_

      sei();

#endif;

      /* Step the model for subrate "i" */
      switch (i)
      {
       case 1 :
        Evita_Paredes_Sist_Completo_step1();

        /* Get model outputs here */
        break;

       case 2 :
        Evita_Paredes_Sist_Completo_step2();

        /* Get model outputs here */
        break;

       default :
        break;
      }

#ifndef _MW_ARDUINO_LOOP_

      cli();

#endif;

      need2runFlags[i]--;
      isRateRunning[i]--;
    }
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.05;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(Evita_Paredes_Sist_Completo_M, 0);
  Evita_Paredes_Sist_Completo_initialize();
  cli();
  configureArduinoAVRTimer();
  runModel = rtmGetErrorStatus(Evita_Paredes_Sist_Completo_M) == (NULL);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei();
  while (runModel) {
    stopRequested = !(rtmGetErrorStatus(Evita_Paredes_Sist_Completo_M) == (NULL));
    runModel = !(stopRequested);
    MW_Arduino_Loop();
  }

  /* Terminate model */
  Evita_Paredes_Sist_Completo_terminate();
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
