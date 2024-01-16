/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Evita_Paredes_Sist_Completo.c
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
#include "multiword_types.h"
#include "Evita_Paredes_Sist_Completo_private.h"

/* Block signals (default storage) */
B_Evita_Paredes_Sist_Completo_T Evita_Paredes_Sist_Completo_B;

/* Block states (default storage) */
DW_Evita_Paredes_Sist_Complet_T Evita_Paredes_Sist_Completo_DW;

/* Real-time model */
static RT_MODEL_Evita_Paredes_Sist_C_T Evita_Paredes_Sist_Completo_M_;
RT_MODEL_Evita_Paredes_Sist_C_T *const Evita_Paredes_Sist_Completo_M =
  &Evita_Paredes_Sist_Completo_M_;
static void rate_monotonic_scheduler(void);
void uMultiWordMul(const uint32_T u1[], int16_T n1, const uint32_T u2[], int16_T
                   n2, uint32_T y[], int16_T n)
{
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  int16_T i;
  int16_T j;
  int16_T k;
  int16_T ni;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0UL;
  }

  for (i = 0; i < n1; i++) {
    cb = 0UL;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535UL;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535UL;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

void uMultiWord2MultiWord(const uint32_T u1[], int16_T n1, uint32_T y[], int16_T
  n)
{
  int16_T i;
  int16_T nm;
  nm = n1 < n ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    for (i = nm; i < n; i++) {
      y[i] = 0UL;
    }
  }
}

boolean_T sMultiWordGe(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  return sMultiWordCmp(u1, u2, n) >= 0;
}

int16_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  uint32_T su1;
  uint32_T u2i;
  int16_T i;
  int16_T y;
  su1 = u1[n - 1] & 2147483648UL;
  if ((u2[n - 1] & 2147483648UL) != su1) {
    y = su1 != 0UL ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      u2i = u2[i];
      if (su1 != u2i) {
        y = su1 > u2i ? 1 : -1;
      }
    }
  }

  return y;
}

void sMultiWordShl(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  uint32_T u1i;
  uint32_T yi;
  uint32_T ys;
  int16_T i;
  int16_T nb;
  int16_T nc;
  uint16_T nl;
  nb = (int16_T)(n2 >> 5);
  ys = (u1[n1 - 1] & 2147483648UL) != 0UL ? MAX_uint32_T : 0UL;
  nc = nb > n ? n : nb;
  u1i = 0UL;
  for (i = 0; i < nc; i++) {
    y[i] = 0UL;
  }

  if (nb < n) {
    nl = n2 - ((uint16_T)nb << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      for (nc = 0; nc < nb; nc++) {
        yi = u1i >> (32U - nl);
        u1i = u1[nc];
        y[i] = u1i << nl | yi;
        i++;
      }

      if (i < n) {
        y[i] = u1i >> (32U - nl) | ys << nl;
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

void sLong2MultiWord(int32_T u, uint32_T y[], int16_T n)
{
  uint32_T yi;
  int16_T i;
  y[0] = (uint32_T)u;
  yi = u < 0L ? MAX_uint32_T : 0UL;
  for (i = 1; i < n; i++) {
    y[i] = yi;
  }
}

boolean_T sMultiWordLe(const uint32_T u1[], const uint32_T u2[], int16_T n)
{
  return sMultiWordCmp(u1, u2, n) <= 0;
}

int32_T MultiWord2sLong(const uint32_T u[])
{
  return (int32_T)u[0];
}

void uMultiWordShr(const uint32_T u1[], int16_T n1, uint16_T n2, uint32_T y[],
                   int16_T n)
{
  uint32_T u1i;
  uint32_T yi;
  int16_T i;
  int16_T i1;
  int16_T nb;
  int16_T nc;
  uint16_T nr;
  nb = (int16_T)(n2 >> 5);
  i = 0;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint16_T)nb << 5);
    if (nr > 0U) {
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      yi = u1i >> nr;
      if (nc < n1) {
        yi |= u1[nc] << (32U - nr);
      }

      y[i] = yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = 0UL;
    i++;
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Evita_Paredes_Sist_Completo_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Evita_Paredes_Sist_Completo_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Evita_Paredes_Sist_Completo_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rates: 1, 2 */
  Evita_Paredes_Sist_Completo_M->Timing.RateInteraction.TID0_1 =
    (Evita_Paredes_Sist_Completo_M->Timing.TaskCounters.TID[1] == 0);
  Evita_Paredes_Sist_Completo_M->Timing.RateInteraction.TID0_2 =
    (Evita_Paredes_Sist_Completo_M->Timing.TaskCounters.TID[2] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Evita_Paredes_Sist_Completo_M->Timing.TaskCounters.TID[1])++;
  if ((Evita_Paredes_Sist_Completo_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.1s, 0.0s] */
    Evita_Paredes_Sist_Completo_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Evita_Paredes_Sist_Completo_M->Timing.TaskCounters.TID[2])++;
  if ((Evita_Paredes_Sist_Completo_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.25s, 0.0s] */
    Evita_Paredes_Sist_Completo_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function for TID0 */
void Evita_Paredes_Sist_Completo_step0(void) /* Sample time: [0.05s, 0.0s] */
{
  real_T rtb_Switch;

  {                                    /* Sample time: [0.05s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition generated from: '<S4>/Switch' */
  if (Evita_Paredes_Sist_Completo_M->Timing.RateInteraction.TID0_2) {
    /* RateTransition generated from: '<S4>/Switch' */
    Evita_Paredes_Sist_Completo_B.TmpRTBAtSwitchInport1 =
      Evita_Paredes_Sist_Completo_DW.TmpRTBAtSwitchInport1_Buffer0;
  }

  /* RateTransition generated from: '<S4>/Switch' */
  if (Evita_Paredes_Sist_Completo_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<S4>/Switch' */
    Evita_Paredes_Sist_Completo_B.TmpRTBAtSwitchInport2 =
      Evita_Paredes_Sist_Completo_DW.TmpRTBAtSwitchInport2_Buffer0;

    /* RateTransition generated from: '<S4>/AND1' */
    Evita_Paredes_Sist_Completo_B.TmpRTBAtAND1Inport1 =
      Evita_Paredes_Sist_Completo_DW.TmpRTBAtAND1Inport1_Buffer0;
  }

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  if (Evita_Paredes_Sist_Completo_B.TmpRTBAtSwitchInport2) {
    rtb_Switch = Evita_Paredes_Sist_Completo_B.TmpRTBAtSwitchInport1;
  } else {
    rtb_Switch = Evita_Paredes_Sist_Completo_P.Constant1_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* MATLABSystem: '<S4>/GREEN_LED' incorporates:
   *  Logic: '<S4>/AND1'
   */
  writeDigitalPin(51, (uint8_T)
                  (Evita_Paredes_Sist_Completo_B.TmpRTBAtAND1Inport1 &&
                   (rtb_Switch != 0.0)));

  /* RateTransition generated from: '<S4>/AND' */
  if (Evita_Paredes_Sist_Completo_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<S4>/AND' */
    Evita_Paredes_Sist_Completo_B.TmpRTBAtANDInport1 =
      Evita_Paredes_Sist_Completo_DW.TmpRTBAtANDInport1_Buffer0;
  }

  /* MATLABSystem: '<S4>/RED_LED' incorporates:
   *  Logic: '<S4>/AND'
   */
  writeDigitalPin(53, (uint8_T)(Evita_Paredes_Sist_Completo_B.TmpRTBAtANDInport1
    && (rtb_Switch != 0.0)));

  /* RateTransition generated from: '<S4>/AND2' */
  if (Evita_Paredes_Sist_Completo_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<S4>/AND2' */
    Evita_Paredes_Sist_Completo_B.TmpRTBAtAND2Inport1 =
      Evita_Paredes_Sist_Completo_DW.TmpRTBAtAND2Inport1_Buffer0;
  }

  /* MATLABSystem: '<S4>/YELLOW_LED' incorporates:
   *  Logic: '<S4>/AND2'
   */
  writeDigitalPin(49, (uint8_T)
                  (Evita_Paredes_Sist_Completo_B.TmpRTBAtAND2Inport1 &&
                   (rtb_Switch != 0.0)));
}

/* Model step function for TID1 */
void Evita_Paredes_Sist_Completo_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  int96m_T tmp_0;
  uint64m_T rtb_Gain_idx_0;
  uint64m_T rtb_Gain_idx_1;
  uint64m_T tmp;
  uint32_T rtb_Gain_p_idx_0;
  uint32_T rtb_Gain_p_idx_1;
  int16_T rtb_Saturation_idx_0;
  int16_T rtb_Saturation_idx_1;
  int16_T y;
  uint16_T b_varargout_1;
  uint16_T b_varargout_1_0;
  boolean_T rtb_CastToBoolean3;

  /* MATLABSystem: '<S3>/Sonar Izquierdo' */
  if (Evita_Paredes_Sist_Completo_DW.obj.SampleTime !=
      Evita_Paredes_Sist_Completo_P.SonarIzquierdo_SampleTime) {
    Evita_Paredes_Sist_Completo_DW.obj.SampleTime =
      Evita_Paredes_Sist_Completo_P.SonarIzquierdo_SampleTime;
  }

  Evita_Paredes_Sist_Completo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(57UL);
  MW_AnalogInSingle_ReadResult
    (Evita_Paredes_Sist_Completo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* MATLABSystem: '<S3>/Sonar Derecho' */
  if (Evita_Paredes_Sist_Completo_DW.obj_j.SampleTime !=
      Evita_Paredes_Sist_Completo_P.SonarDerecho_SampleTime) {
    Evita_Paredes_Sist_Completo_DW.obj_j.SampleTime =
      Evita_Paredes_Sist_Completo_P.SonarDerecho_SampleTime;
  }

  Evita_Paredes_Sist_Completo_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(56UL);
  MW_AnalogInSingle_ReadResult
    (Evita_Paredes_Sist_Completo_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1_0, MW_ANALOGIN_UINT16);

  /* Gain: '<S3>/Gain' incorporates:
   *  MATLABSystem: '<S3>/Sonar Derecho'
   *  MATLABSystem: '<S3>/Sonar Izquierdo'
   * */
  rtb_Gain_p_idx_0 = (uint32_T)Evita_Paredes_Sist_Completo_P.Gain_Gain_f *
    b_varargout_1;
  rtb_Gain_p_idx_1 = (uint32_T)Evita_Paredes_Sist_Completo_P.Gain_Gain_f *
    b_varargout_1_0;

  /* Gain: '<S2>/Gain' incorporates:
   *  Gain: '<S3>/Gain'
   */
  uMultiWordMul(&Evita_Paredes_Sist_Completo_P.Gain_Gain, 1, &rtb_Gain_p_idx_0,
                1, &rtb_Gain_idx_0.chunks[0U], 2);
  uMultiWordMul(&Evita_Paredes_Sist_Completo_P.Gain_Gain, 1, &rtb_Gain_p_idx_1,
                1, &rtb_Gain_idx_1.chunks[0U], 2);

  /* Saturate: '<S2>/Saturation' */
  tmp = rtb_Gain_idx_1;
  uMultiWord2MultiWord(&rtb_Gain_idx_1.chunks[0U], 2,
                       &Evita_Paredes_Sist_Completo_B.r.chunks[0U], 3);
  sLong2MultiWord(Evita_Paredes_Sist_Completo_P.Saturation_UpperSat,
                  &Evita_Paredes_Sist_Completo_B.r2.chunks[0U], 3);
  sMultiWordShl(&Evita_Paredes_Sist_Completo_B.r2.chunks[0U], 3, 49U,
                &Evita_Paredes_Sist_Completo_B.r1.chunks[0U], 3);
  if (sMultiWordGe(&Evita_Paredes_Sist_Completo_B.r.chunks[0U],
                   &Evita_Paredes_Sist_Completo_B.r1.chunks[0U], 3)) {
    rtb_Saturation_idx_0 = Evita_Paredes_Sist_Completo_P.Saturation_UpperSat;
  } else {
    sLong2MultiWord(Evita_Paredes_Sist_Completo_P.Saturation_LowerSat,
                    &Evita_Paredes_Sist_Completo_B.r3.chunks[0U], 3);
    sMultiWordShl(&Evita_Paredes_Sist_Completo_B.r3.chunks[0U], 3, 49U,
                  &Evita_Paredes_Sist_Completo_B.r2.chunks[0U], 3);
    if (sMultiWordLe(&Evita_Paredes_Sist_Completo_B.r.chunks[0U],
                     &Evita_Paredes_Sist_Completo_B.r2.chunks[0U], 3)) {
      rtb_Saturation_idx_0 = Evita_Paredes_Sist_Completo_P.Saturation_LowerSat;
    } else {
      uMultiWordShr(&rtb_Gain_idx_1.chunks[0U], 2, 49U, &tmp.chunks[0U], 2);
      rtb_Saturation_idx_0 = (int16_T)MultiWord2sLong(&tmp.chunks[0U]);
    }
  }

  tmp = rtb_Gain_idx_0;
  uMultiWord2MultiWord(&rtb_Gain_idx_0.chunks[0U], 2,
                       &Evita_Paredes_Sist_Completo_B.r4.chunks[0U], 3);
  sLong2MultiWord(Evita_Paredes_Sist_Completo_P.Saturation_UpperSat,
                  &Evita_Paredes_Sist_Completo_B.r6.chunks[0U], 3);
  sMultiWordShl(&Evita_Paredes_Sist_Completo_B.r6.chunks[0U], 3, 49U,
                &Evita_Paredes_Sist_Completo_B.r5.chunks[0U], 3);
  if (sMultiWordGe(&Evita_Paredes_Sist_Completo_B.r4.chunks[0U],
                   &Evita_Paredes_Sist_Completo_B.r5.chunks[0U], 3)) {
    rtb_Saturation_idx_1 = Evita_Paredes_Sist_Completo_P.Saturation_UpperSat;
  } else {
    sLong2MultiWord(Evita_Paredes_Sist_Completo_P.Saturation_LowerSat,
                    &tmp_0.chunks[0U], 3);
    sMultiWordShl(&tmp_0.chunks[0U], 3, 49U,
                  &Evita_Paredes_Sist_Completo_B.r6.chunks[0U], 3);
    if (sMultiWordLe(&Evita_Paredes_Sist_Completo_B.r4.chunks[0U],
                     &Evita_Paredes_Sist_Completo_B.r6.chunks[0U], 3)) {
      rtb_Saturation_idx_1 = Evita_Paredes_Sist_Completo_P.Saturation_LowerSat;
    } else {
      uMultiWordShr(&rtb_Gain_idx_0.chunks[0U], 2, 49U, &tmp.chunks[0U], 2);
      rtb_Saturation_idx_1 = (int16_T)MultiWord2sLong(&tmp.chunks[0U]);
    }
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* MATLABSystem: '<S5>/Adelante_der' */
  Evita_Paredes_Sist_Completo_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(12UL);

  /* Saturate: '<S5>/Saturation2' */
  if (rtb_Saturation_idx_1 > Evita_Paredes_Sist_Completo_P.Saturation2_UpperSat)
  {
    y = Evita_Paredes_Sist_Completo_P.Saturation2_UpperSat;
  } else if (rtb_Saturation_idx_1 <
             Evita_Paredes_Sist_Completo_P.Saturation2_LowerSat) {
    y = Evita_Paredes_Sist_Completo_P.Saturation2_LowerSat;
  } else {
    y = rtb_Saturation_idx_1;
  }

  /* End of Saturate: '<S5>/Saturation2' */

  /* Start for MATLABSystem: '<S5>/Adelante_der' */
  if (y > 255) {
    y = 255;
  }

  if (y < 0) {
    y = 0;
  }

  /* MATLABSystem: '<S5>/Adelante_der' */
  MW_PWM_SetDutyCycle
    (Evita_Paredes_Sist_Completo_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

  /* MATLABSystem: '<S5>/Adelante_izq' */
  Evita_Paredes_Sist_Completo_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(9UL);

  /* Saturate: '<S5>/Saturation4' */
  if (rtb_Saturation_idx_0 > Evita_Paredes_Sist_Completo_P.Saturation4_UpperSat)
  {
    y = Evita_Paredes_Sist_Completo_P.Saturation4_UpperSat;
  } else if (rtb_Saturation_idx_0 <
             Evita_Paredes_Sist_Completo_P.Saturation4_LowerSat) {
    y = Evita_Paredes_Sist_Completo_P.Saturation4_LowerSat;
  } else {
    y = rtb_Saturation_idx_0;
  }

  /* End of Saturate: '<S5>/Saturation4' */

  /* Abs: '<S5>/Abs2' */
  if (y < 0) {
    y = -y;
  }

  /* End of Abs: '<S5>/Abs2' */

  /* Start for MATLABSystem: '<S5>/Adelante_izq' */
  if (y > 255) {
    y = 255;
  }

  if (y < 0) {
    y = 0;
  }

  /* MATLABSystem: '<S5>/Adelante_izq' */
  MW_PWM_SetDutyCycle
    (Evita_Paredes_Sist_Completo_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

  /* MATLABSystem: '<S5>/Atras_der' */
  Evita_Paredes_Sist_Completo_DW.obj_hu.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(11UL);

  /* Saturate: '<S5>/Saturation3' */
  if (rtb_Saturation_idx_1 > Evita_Paredes_Sist_Completo_P.Saturation3_UpperSat)
  {
    y = Evita_Paredes_Sist_Completo_P.Saturation3_UpperSat;
  } else if (rtb_Saturation_idx_1 <
             Evita_Paredes_Sist_Completo_P.Saturation3_LowerSat) {
    y = Evita_Paredes_Sist_Completo_P.Saturation3_LowerSat;
  } else {
    y = rtb_Saturation_idx_1;
  }

  /* End of Saturate: '<S5>/Saturation3' */

  /* Abs: '<S5>/Abs1' */
  if (y < 0) {
    y = -y;
  }

  /* End of Abs: '<S5>/Abs1' */

  /* Start for MATLABSystem: '<S5>/Atras_der' */
  if (y > 255) {
    y = 255;
  }

  if (y < 0) {
    y = 0;
  }

  /* MATLABSystem: '<S5>/Atras_der' */
  MW_PWM_SetDutyCycle
    (Evita_Paredes_Sist_Completo_DW.obj_hu.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

  /* MATLABSystem: '<S5>/Atras_izq' */
  Evita_Paredes_Sist_Completo_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(10UL);

  /* Saturate: '<S5>/Saturation5' */
  if (rtb_Saturation_idx_0 > Evita_Paredes_Sist_Completo_P.Saturation5_UpperSat)
  {
    y = Evita_Paredes_Sist_Completo_P.Saturation5_UpperSat;
  } else if (rtb_Saturation_idx_0 <
             Evita_Paredes_Sist_Completo_P.Saturation5_LowerSat) {
    y = Evita_Paredes_Sist_Completo_P.Saturation5_LowerSat;
  } else {
    y = rtb_Saturation_idx_0;
  }

  /* End of Saturate: '<S5>/Saturation5' */

  /* Start for MATLABSystem: '<S5>/Atras_izq' */
  if (y > 255) {
    y = 255;
  }

  if (y < 0) {
    y = 0;
  }

  /* MATLABSystem: '<S5>/Atras_izq' */
  MW_PWM_SetDutyCycle
    (Evita_Paredes_Sist_Completo_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, (real_T)y);

  /* MATLABSystem: '<S5>/Digital Output' incorporates:
   *  Constant: '<S12>/Constant'
   *  RelationalOperator: '<S12>/Compare'
   */
  writeDigitalPin(8, (uint8_T)(rtb_Saturation_idx_0 !=
    Evita_Paredes_Sist_Completo_P.Constant_Value));

  /* MATLABSystem: '<S5>/Digital Output1' incorporates:
   *  Constant: '<S13>/Constant'
   *  RelationalOperator: '<S13>/Compare'
   */
  writeDigitalPin(13, (uint8_T)(rtb_Saturation_idx_1 !=
    Evita_Paredes_Sist_Completo_P.Constant_Value_b));

  /* S-Function (scominttobit): '<S1>/Bit to Integer Converter' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S8>/Constant'
   *  Constant: '<S9>/Constant'
   *  Logic: '<S1>/AND'
   *  Logic: '<S1>/OR'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   *  RelationalOperator: '<S7>/Compare'
   *  RelationalOperator: '<S8>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  /* Bit to Integer Conversion */
  /* Input bit order is MSB first */
  rtb_Saturation_idx_0 = (((rtb_Gain_p_idx_1 <
    Evita_Paredes_Sist_Completo_P.CompareToConstant3_const) << 1 |
    ((rtb_Gain_p_idx_0 >= Evita_Paredes_Sist_Completo_P.CompareToConstant_const)
     && (rtb_Gain_p_idx_1 >=
         Evita_Paredes_Sist_Completo_P.CompareToConstant1_const))) << 1 |
    (rtb_Gain_p_idx_0 < Evita_Paredes_Sist_Completo_P.CompareToConstant2_const))
    << 1 | ((rtb_Gain_p_idx_0 <
             Evita_Paredes_Sist_Completo_P.CompareToConstant4_const) ||
            (rtb_Gain_p_idx_1 <
             Evita_Paredes_Sist_Completo_P.CompareToConstant5_const));

  /* DataTypeConversion: '<S4>/Cast To Boolean3' incorporates:
   *  S-Function (scominttobit): '<S1>/Bit to Integer Converter'
   *  S-Function (sfix_bitop): '<S4>/Bitwise Operator3'
   */
  rtb_CastToBoolean3 = ((rtb_Saturation_idx_0 &
    Evita_Paredes_Sist_Completo_P.BitwiseOperator3_BitMask) != 0);

  /* RateTransition generated from: '<S4>/Switch' */
  Evita_Paredes_Sist_Completo_DW.TmpRTBAtSwitchInport2_Buffer0 =
    rtb_CastToBoolean3;

  /* DataTypeConversion: '<S4>/Cast To Boolean2' incorporates:
   *  S-Function (scominttobit): '<S1>/Bit to Integer Converter'
   *  S-Function (sfix_bitop): '<S4>/Bitwise Operator2'
   */
  rtb_CastToBoolean3 = ((rtb_Saturation_idx_0 &
    Evita_Paredes_Sist_Completo_P.BitwiseOperator2_BitMask) != 0);

  /* RateTransition generated from: '<S4>/AND2' */
  Evita_Paredes_Sist_Completo_DW.TmpRTBAtAND2Inport1_Buffer0 =
    rtb_CastToBoolean3;

  /* DataTypeConversion: '<S4>/Cast To Boolean1' incorporates:
   *  S-Function (scominttobit): '<S1>/Bit to Integer Converter'
   *  S-Function (sfix_bitop): '<S4>/Bitwise Operator1'
   */
  rtb_CastToBoolean3 = ((rtb_Saturation_idx_0 &
    Evita_Paredes_Sist_Completo_P.BitwiseOperator1_BitMask) != 0);

  /* RateTransition generated from: '<S4>/AND1' */
  Evita_Paredes_Sist_Completo_DW.TmpRTBAtAND1Inport1_Buffer0 =
    rtb_CastToBoolean3;

  /* DataTypeConversion: '<S4>/Cast To Boolean' incorporates:
   *  S-Function (scominttobit): '<S1>/Bit to Integer Converter'
   *  S-Function (sfix_bitop): '<S4>/Bitwise Operator'
   */
  rtb_CastToBoolean3 = ((rtb_Saturation_idx_0 &
    Evita_Paredes_Sist_Completo_P.BitwiseOperator_BitMask) != 0);

  /* RateTransition generated from: '<S4>/AND' */
  Evita_Paredes_Sist_Completo_DW.TmpRTBAtANDInport1_Buffer0 = rtb_CastToBoolean3;
}

/* Model step function for TID2 */
void Evita_Paredes_Sist_Completo_step2(void) /* Sample time: [0.25s, 0.0s] */
{
  real_T rtb_PulseGenerator;

  /* DiscretePulseGenerator: '<S4>/Pulse Generator' */
  rtb_PulseGenerator = (Evita_Paredes_Sist_Completo_DW.clockTickCounter <
                        Evita_Paredes_Sist_Completo_P.PulseGenerator_Duty) &&
    (Evita_Paredes_Sist_Completo_DW.clockTickCounter >= 0L) ?
    Evita_Paredes_Sist_Completo_P.PulseGenerator_Amp : 0.0;
  if (Evita_Paredes_Sist_Completo_DW.clockTickCounter >=
      Evita_Paredes_Sist_Completo_P.PulseGenerator_Period - 1.0) {
    Evita_Paredes_Sist_Completo_DW.clockTickCounter = 0L;
  } else {
    Evita_Paredes_Sist_Completo_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S4>/Pulse Generator' */

  /* RateTransition generated from: '<S4>/Switch' */
  Evita_Paredes_Sist_Completo_DW.TmpRTBAtSwitchInport1_Buffer0 =
    rtb_PulseGenerator;
}

/* Model initialize function */
void Evita_Paredes_Sist_Completo_initialize(void)
{
  /* Start for RateTransition generated from: '<S4>/Switch' */
  Evita_Paredes_Sist_Completo_B.TmpRTBAtSwitchInport1 =
    Evita_Paredes_Sist_Completo_P.TmpRTBAtSwitchInport1_InitialCo;

  /* Start for RateTransition generated from: '<S4>/Switch' */
  Evita_Paredes_Sist_Completo_B.TmpRTBAtSwitchInport2 =
    Evita_Paredes_Sist_Completo_P.TmpRTBAtSwitchInport2_InitialCo;

  /* Start for RateTransition generated from: '<S4>/AND1' */
  Evita_Paredes_Sist_Completo_B.TmpRTBAtAND1Inport1 =
    Evita_Paredes_Sist_Completo_P.TmpRTBAtAND1Inport1_InitialCond;

  /* Start for RateTransition generated from: '<S4>/AND' */
  Evita_Paredes_Sist_Completo_B.TmpRTBAtANDInport1 =
    Evita_Paredes_Sist_Completo_P.TmpRTBAtANDInport1_InitialCondi;

  /* Start for RateTransition generated from: '<S4>/AND2' */
  Evita_Paredes_Sist_Completo_B.TmpRTBAtAND2Inport1 =
    Evita_Paredes_Sist_Completo_P.TmpRTBAtAND2Inport1_InitialCond;

  /* InitializeConditions for RateTransition generated from: '<S4>/Switch' */
  Evita_Paredes_Sist_Completo_DW.TmpRTBAtSwitchInport1_Buffer0 =
    Evita_Paredes_Sist_Completo_P.TmpRTBAtSwitchInport1_InitialCo;

  /* InitializeConditions for RateTransition generated from: '<S4>/Switch' */
  Evita_Paredes_Sist_Completo_DW.TmpRTBAtSwitchInport2_Buffer0 =
    Evita_Paredes_Sist_Completo_P.TmpRTBAtSwitchInport2_InitialCo;

  /* InitializeConditions for RateTransition generated from: '<S4>/AND1' */
  Evita_Paredes_Sist_Completo_DW.TmpRTBAtAND1Inport1_Buffer0 =
    Evita_Paredes_Sist_Completo_P.TmpRTBAtAND1Inport1_InitialCond;

  /* InitializeConditions for RateTransition generated from: '<S4>/AND' */
  Evita_Paredes_Sist_Completo_DW.TmpRTBAtANDInport1_Buffer0 =
    Evita_Paredes_Sist_Completo_P.TmpRTBAtANDInport1_InitialCondi;

  /* InitializeConditions for RateTransition generated from: '<S4>/AND2' */
  Evita_Paredes_Sist_Completo_DW.TmpRTBAtAND2Inport1_Buffer0 =
    Evita_Paredes_Sist_Completo_P.TmpRTBAtAND2Inport1_InitialCond;

  /* Start for MATLABSystem: '<S4>/GREEN_LED' */
  Evita_Paredes_Sist_Completo_DW.obj_a.matlabCodegenIsDeleted = false;
  Evita_Paredes_Sist_Completo_DW.obj_a.isInitialized = 1L;
  digitalIOSetup(51, 1);
  Evita_Paredes_Sist_Completo_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/RED_LED' */
  Evita_Paredes_Sist_Completo_DW.obj_k.matlabCodegenIsDeleted = false;
  Evita_Paredes_Sist_Completo_DW.obj_k.isInitialized = 1L;
  digitalIOSetup(53, 1);
  Evita_Paredes_Sist_Completo_DW.obj_k.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/YELLOW_LED' */
  Evita_Paredes_Sist_Completo_DW.obj_f.matlabCodegenIsDeleted = false;
  Evita_Paredes_Sist_Completo_DW.obj_f.isInitialized = 1L;
  digitalIOSetup(49, 1);
  Evita_Paredes_Sist_Completo_DW.obj_f.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Sonar Izquierdo' */
  Evita_Paredes_Sist_Completo_DW.obj.matlabCodegenIsDeleted = false;
  Evita_Paredes_Sist_Completo_DW.obj.SampleTime =
    Evita_Paredes_Sist_Completo_P.SonarIzquierdo_SampleTime;
  Evita_Paredes_Sist_Completo_DW.obj.isInitialized = 1L;
  Evita_Paredes_Sist_Completo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(57UL);
  Evita_Paredes_Sist_Completo_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Sonar Derecho' */
  Evita_Paredes_Sist_Completo_DW.obj_j.matlabCodegenIsDeleted = false;
  Evita_Paredes_Sist_Completo_DW.obj_j.SampleTime =
    Evita_Paredes_Sist_Completo_P.SonarDerecho_SampleTime;
  Evita_Paredes_Sist_Completo_DW.obj_j.isInitialized = 1L;
  Evita_Paredes_Sist_Completo_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(56UL);
  Evita_Paredes_Sist_Completo_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Adelante_der' */
  Evita_Paredes_Sist_Completo_DW.obj_b.matlabCodegenIsDeleted = false;
  Evita_Paredes_Sist_Completo_DW.obj_b.isInitialized = 1L;
  Evita_Paredes_Sist_Completo_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (12UL, 0.0, 0.0);
  Evita_Paredes_Sist_Completo_DW.obj_b.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Adelante_izq' */
  Evita_Paredes_Sist_Completo_DW.obj_l.matlabCodegenIsDeleted = false;
  Evita_Paredes_Sist_Completo_DW.obj_l.isInitialized = 1L;
  Evita_Paredes_Sist_Completo_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (9UL, 0.0, 0.0);
  Evita_Paredes_Sist_Completo_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Atras_der' */
  Evita_Paredes_Sist_Completo_DW.obj_hu.matlabCodegenIsDeleted = false;
  Evita_Paredes_Sist_Completo_DW.obj_hu.isInitialized = 1L;
  Evita_Paredes_Sist_Completo_DW.obj_hu.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (11UL, 0.0, 0.0);
  Evita_Paredes_Sist_Completo_DW.obj_hu.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Atras_izq' */
  Evita_Paredes_Sist_Completo_DW.obj_h.matlabCodegenIsDeleted = false;
  Evita_Paredes_Sist_Completo_DW.obj_h.isInitialized = 1L;
  Evita_Paredes_Sist_Completo_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (10UL, 0.0, 0.0);
  Evita_Paredes_Sist_Completo_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Digital Output' */
  Evita_Paredes_Sist_Completo_DW.obj_jk.matlabCodegenIsDeleted = false;
  Evita_Paredes_Sist_Completo_DW.obj_jk.isInitialized = 1L;
  digitalIOSetup(8, 1);
  Evita_Paredes_Sist_Completo_DW.obj_jk.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/Digital Output1' */
  Evita_Paredes_Sist_Completo_DW.obj_e.matlabCodegenIsDeleted = false;
  Evita_Paredes_Sist_Completo_DW.obj_e.isInitialized = 1L;
  digitalIOSetup(13, 1);
  Evita_Paredes_Sist_Completo_DW.obj_e.isSetupComplete = true;
}

/* Model terminate function */
void Evita_Paredes_Sist_Completo_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/GREEN_LED' */
  if (!Evita_Paredes_Sist_Completo_DW.obj_a.matlabCodegenIsDeleted) {
    Evita_Paredes_Sist_Completo_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/GREEN_LED' */

  /* Terminate for MATLABSystem: '<S4>/RED_LED' */
  if (!Evita_Paredes_Sist_Completo_DW.obj_k.matlabCodegenIsDeleted) {
    Evita_Paredes_Sist_Completo_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/RED_LED' */

  /* Terminate for MATLABSystem: '<S4>/YELLOW_LED' */
  if (!Evita_Paredes_Sist_Completo_DW.obj_f.matlabCodegenIsDeleted) {
    Evita_Paredes_Sist_Completo_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/YELLOW_LED' */

  /* Terminate for MATLABSystem: '<S3>/Sonar Izquierdo' */
  if (!Evita_Paredes_Sist_Completo_DW.obj.matlabCodegenIsDeleted) {
    Evita_Paredes_Sist_Completo_DW.obj.matlabCodegenIsDeleted = true;
    if ((Evita_Paredes_Sist_Completo_DW.obj.isInitialized == 1L) &&
        Evita_Paredes_Sist_Completo_DW.obj.isSetupComplete) {
      Evita_Paredes_Sist_Completo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(57UL);
      MW_AnalogIn_Close
        (Evita_Paredes_Sist_Completo_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Sonar Izquierdo' */

  /* Terminate for MATLABSystem: '<S3>/Sonar Derecho' */
  if (!Evita_Paredes_Sist_Completo_DW.obj_j.matlabCodegenIsDeleted) {
    Evita_Paredes_Sist_Completo_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Evita_Paredes_Sist_Completo_DW.obj_j.isInitialized == 1L) &&
        Evita_Paredes_Sist_Completo_DW.obj_j.isSetupComplete) {
      Evita_Paredes_Sist_Completo_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(56UL);
      MW_AnalogIn_Close
        (Evita_Paredes_Sist_Completo_DW.obj_j.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Sonar Derecho' */

  /* Terminate for MATLABSystem: '<S5>/Adelante_der' */
  if (!Evita_Paredes_Sist_Completo_DW.obj_b.matlabCodegenIsDeleted) {
    Evita_Paredes_Sist_Completo_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Evita_Paredes_Sist_Completo_DW.obj_b.isInitialized == 1L) &&
        Evita_Paredes_Sist_Completo_DW.obj_b.isSetupComplete) {
      Evita_Paredes_Sist_Completo_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(12UL);
      MW_PWM_SetDutyCycle
        (Evita_Paredes_Sist_Completo_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Evita_Paredes_Sist_Completo_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(12UL);
      MW_PWM_Close
        (Evita_Paredes_Sist_Completo_DW.obj_b.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Adelante_der' */

  /* Terminate for MATLABSystem: '<S5>/Adelante_izq' */
  if (!Evita_Paredes_Sist_Completo_DW.obj_l.matlabCodegenIsDeleted) {
    Evita_Paredes_Sist_Completo_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Evita_Paredes_Sist_Completo_DW.obj_l.isInitialized == 1L) &&
        Evita_Paredes_Sist_Completo_DW.obj_l.isSetupComplete) {
      Evita_Paredes_Sist_Completo_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_SetDutyCycle
        (Evita_Paredes_Sist_Completo_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Evita_Paredes_Sist_Completo_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(9UL);
      MW_PWM_Close
        (Evita_Paredes_Sist_Completo_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Adelante_izq' */

  /* Terminate for MATLABSystem: '<S5>/Atras_der' */
  if (!Evita_Paredes_Sist_Completo_DW.obj_hu.matlabCodegenIsDeleted) {
    Evita_Paredes_Sist_Completo_DW.obj_hu.matlabCodegenIsDeleted = true;
    if ((Evita_Paredes_Sist_Completo_DW.obj_hu.isInitialized == 1L) &&
        Evita_Paredes_Sist_Completo_DW.obj_hu.isSetupComplete) {
      Evita_Paredes_Sist_Completo_DW.obj_hu.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_SetDutyCycle
        (Evita_Paredes_Sist_Completo_DW.obj_hu.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Evita_Paredes_Sist_Completo_DW.obj_hu.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(11UL);
      MW_PWM_Close
        (Evita_Paredes_Sist_Completo_DW.obj_hu.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Atras_der' */

  /* Terminate for MATLABSystem: '<S5>/Atras_izq' */
  if (!Evita_Paredes_Sist_Completo_DW.obj_h.matlabCodegenIsDeleted) {
    Evita_Paredes_Sist_Completo_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Evita_Paredes_Sist_Completo_DW.obj_h.isInitialized == 1L) &&
        Evita_Paredes_Sist_Completo_DW.obj_h.isSetupComplete) {
      Evita_Paredes_Sist_Completo_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(10UL);
      MW_PWM_SetDutyCycle
        (Evita_Paredes_Sist_Completo_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      Evita_Paredes_Sist_Completo_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(10UL);
      MW_PWM_Close
        (Evita_Paredes_Sist_Completo_DW.obj_h.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Atras_izq' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output' */
  if (!Evita_Paredes_Sist_Completo_DW.obj_jk.matlabCodegenIsDeleted) {
    Evita_Paredes_Sist_Completo_DW.obj_jk.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output' */

  /* Terminate for MATLABSystem: '<S5>/Digital Output1' */
  if (!Evita_Paredes_Sist_Completo_DW.obj_e.matlabCodegenIsDeleted) {
    Evita_Paredes_Sist_Completo_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Output1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
