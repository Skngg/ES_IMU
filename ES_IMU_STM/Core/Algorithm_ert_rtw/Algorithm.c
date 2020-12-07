/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Algorithm.c
 *
 * Code generated for Simulink model 'Algorithm'.
 *
 * Model version                  : 1.36
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Dec  8 00:13:45 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "Algorithm.h"
#include "Algorithm_private.h"

/* Block signals and states (default storage) */
DW_Algorithm_T Algorithm_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Algorithm_T Algorithm_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Algorithm_T Algorithm_Y;

/* Model step function */
void Algorithm_step(void)
{
  int32_T i;
  real_T rtb_S_Eq_wt_idx_0;
  real_T rtb_S_Eq_wt_idx_1;
  real_T rtb_S_Eq_wt_idx_2;
  real_T rtb_S_Eq_wt_idx_3;
  real_T tmp;
  real_T tmp_0;
  real_T EulXYZ_tmp;

  /* Gain: '<S1>/Gain' incorporates:
   *  Delay: '<S1>/Delay'
   */
  Algorithm_DW.Normalization1[0] = 0.5 * Algorithm_DW.Delay_DSTATE[0];
  Algorithm_DW.Normalization1[1] = 0.5 * Algorithm_DW.Delay_DSTATE[1];
  Algorithm_DW.Normalization1[2] = 0.5 * Algorithm_DW.Delay_DSTATE[2];
  Algorithm_DW.Normalization1[3] = 0.5 * Algorithm_DW.Delay_DSTATE[3];

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S1>/\delta t'
   *  Inport: '<Root>/GyroX'
   *  Inport: '<Root>/GyroY'
   *  Inport: '<Root>/GyroZ'
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product3'
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product2'
   *  Product: '<S6>/Product3'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product3'
   *  Product: '<S8>/Product'
   *  Product: '<S8>/Product1'
   *  Product: '<S8>/Product2'
   *  Sum: '<S5>/Sum'
   *  Sum: '<S6>/Sum'
   *  Sum: '<S7>/Sum'
   *  Sum: '<S8>/Sum'
   */
  rtb_S_Eq_wt_idx_0 = (((0.0 - Algorithm_DW.Normalization1[1] *
    Algorithm_U.GyroX) - Algorithm_DW.Normalization1[2] * Algorithm_U.GyroY) -
                       Algorithm_DW.Normalization1[3] * Algorithm_U.GyroZ) *
    0.01 + Algorithm_DW.Delay_DSTATE[0];
  rtb_S_Eq_wt_idx_1 = ((Algorithm_DW.Normalization1[0] * Algorithm_U.GyroX +
                        Algorithm_DW.Normalization1[2] * Algorithm_U.GyroZ) -
                       Algorithm_DW.Normalization1[3] * Algorithm_U.GyroY) *
    0.01 + Algorithm_DW.Delay_DSTATE[1];
  rtb_S_Eq_wt_idx_2 = ((Algorithm_DW.Normalization1[0] * Algorithm_U.GyroY -
                        Algorithm_DW.Normalization1[1] * Algorithm_U.GyroZ) +
                       Algorithm_DW.Normalization1[3] * Algorithm_U.GyroX) *
    0.01 + Algorithm_DW.Delay_DSTATE[2];
  rtb_S_Eq_wt_idx_3 = ((Algorithm_DW.Normalization1[0] * Algorithm_U.GyroZ +
                        Algorithm_DW.Normalization1[1] * Algorithm_U.GyroY) -
                       Algorithm_DW.Normalization1[2] * Algorithm_U.GyroX) *
    0.01 + Algorithm_DW.Delay_DSTATE[3];

  /* SignalConversion generated from: '<S3>/Vector Concatenate' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S9>/Gain'
   *  Gain: '<S9>/Gain1'
   *  Gain: '<S9>/Gain2'
   *  Gain: '<S9>/Gain3'
   */
  Algorithm_DW.VectorConcatenate[0] = -2.0 * Algorithm_DW.Delay_DSTATE[2];
  Algorithm_DW.VectorConcatenate[1] = 2.0 * Algorithm_DW.Delay_DSTATE[3];
  Algorithm_DW.VectorConcatenate[2] = -2.0 * Algorithm_DW.Delay_DSTATE[0];
  Algorithm_DW.VectorConcatenate[3] = 2.0 * Algorithm_DW.Delay_DSTATE[1];

  /* SignalConversion generated from: '<S3>/Vector Concatenate' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S10>/Gain2'
   *  Gain: '<S10>/Gain3'
   *  Gain: '<S10>/Gain4'
   */
  Algorithm_DW.VectorConcatenate[4] = 2.0 * Algorithm_DW.Delay_DSTATE[1];
  Algorithm_DW.VectorConcatenate[5] = 2.0 * Algorithm_DW.Delay_DSTATE[0];
  Algorithm_DW.VectorConcatenate[6] = 2.0 * Algorithm_DW.Delay_DSTATE[3];
  Algorithm_DW.VectorConcatenate[7] = 2.0 * Algorithm_DW.Delay_DSTATE[2];

  /* SignalConversion generated from: '<S3>/Vector Concatenate' incorporates:
   *  Constant: '<S11>/Constant'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S11>/Gain1'
   *  Gain: '<S11>/Gain2'
   */
  Algorithm_DW.VectorConcatenate[8] = 0.0;
  Algorithm_DW.VectorConcatenate[9] = -4.0 * Algorithm_DW.Delay_DSTATE[1];
  Algorithm_DW.VectorConcatenate[10] = -4.0 * Algorithm_DW.Delay_DSTATE[2];
  Algorithm_DW.VectorConcatenate[11] = 0.0;

  /* SignalConversion generated from: '<S1>/Product' incorporates:
   *  Constant: '<S14>/Constant'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S12>/Gain'
   *  Gain: '<S13>/Gain'
   *  Gain: '<S14>/Gain'
   *  Gain: '<S1>/Normalization'
   *  Inport: '<Root>/AccX'
   *  Inport: '<Root>/AccY'
   *  Inport: '<Root>/AccZ'
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product1'
   *  Product: '<S13>/Product'
   *  Product: '<S13>/Product1'
   *  Product: '<S14>/Product'
   *  Product: '<S14>/Product1'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S12>/Sum1'
   *  Sum: '<S13>/Sum'
   *  Sum: '<S13>/Sum1'
   *  Sum: '<S14>/Sum'
   *  Sum: '<S14>/Sum1'
   *  Sum: '<S14>/Sum2'
   */
  Algorithm_DW.aSinInput = (Algorithm_DW.Delay_DSTATE[1] *
    Algorithm_DW.Delay_DSTATE[3] - Algorithm_DW.Delay_DSTATE[0] *
    Algorithm_DW.Delay_DSTATE[2]) * 2.0 - 0.1019367991845056 * Algorithm_U.AccX;
  tmp = (Algorithm_DW.Delay_DSTATE[0] * Algorithm_DW.Delay_DSTATE[1] +
         Algorithm_DW.Delay_DSTATE[2] * Algorithm_DW.Delay_DSTATE[3]) * 2.0 -
    0.1019367991845056 * Algorithm_U.AccY;
  tmp_0 = ((0.5 - Algorithm_DW.Delay_DSTATE[1] * Algorithm_DW.Delay_DSTATE[1]) -
           Algorithm_DW.Delay_DSTATE[2] * Algorithm_DW.Delay_DSTATE[2]) * 2.0 -
    0.1019367991845056 * Algorithm_U.AccZ;

  /* Product: '<S1>/Product' */
  for (i = 0; i < 4; i++) {
    Algorithm_DW.Normalization1[i] = 0.0;
    Algorithm_DW.Normalization1[i] += Algorithm_DW.VectorConcatenate[i] *
      Algorithm_DW.aSinInput;
    Algorithm_DW.Normalization1[i] += Algorithm_DW.VectorConcatenate[i + 4] *
      tmp;
    Algorithm_DW.Normalization1[i] += Algorithm_DW.VectorConcatenate[i + 8] *
      tmp_0;
  }

  /* End of Product: '<S1>/Product' */

  /* S-Function (sdsp2norm2): '<S1>/Normalization1' */
  Algorithm_DW.aSinInput = 1.0 / (sqrt(((Algorithm_DW.Normalization1[0] *
    Algorithm_DW.Normalization1[0] + Algorithm_DW.Normalization1[1] *
    Algorithm_DW.Normalization1[1]) + Algorithm_DW.Normalization1[2] *
    Algorithm_DW.Normalization1[2]) + Algorithm_DW.Normalization1[3] *
    Algorithm_DW.Normalization1[3]) + 1.0E-10);
  Algorithm_DW.Normalization1[0] *= Algorithm_DW.aSinInput;
  Algorithm_DW.Normalization1[1] *= Algorithm_DW.aSinInput;
  Algorithm_DW.Normalization1[2] *= Algorithm_DW.aSinInput;
  Algorithm_DW.Normalization1[3] *= Algorithm_DW.aSinInput;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/beta'
   */
  rtb_S_Eq_wt_idx_0 -= 0.010738715006927038 * Algorithm_DW.Normalization1[0];
  rtb_S_Eq_wt_idx_1 -= 0.010738715006927038 * Algorithm_DW.Normalization1[1];
  rtb_S_Eq_wt_idx_2 -= 0.010738715006927038 * Algorithm_DW.Normalization1[2];
  rtb_S_Eq_wt_idx_3 -= 0.010738715006927038 * Algorithm_DW.Normalization1[3];

  /* MATLABSystem: '<S1>/Coordinate Transformation Conversion' */
  Algorithm_DW.aSinInput = 1.0 / sqrt(((rtb_S_Eq_wt_idx_0 * rtb_S_Eq_wt_idx_0 +
    rtb_S_Eq_wt_idx_1 * rtb_S_Eq_wt_idx_1) + rtb_S_Eq_wt_idx_2 *
    rtb_S_Eq_wt_idx_2) + rtb_S_Eq_wt_idx_3 * rtb_S_Eq_wt_idx_3);
  Algorithm_DW.Normalization1[0] = rtb_S_Eq_wt_idx_0 * Algorithm_DW.aSinInput;
  Algorithm_DW.Normalization1[1] = rtb_S_Eq_wt_idx_1 * Algorithm_DW.aSinInput;
  Algorithm_DW.Normalization1[2] = rtb_S_Eq_wt_idx_2 * Algorithm_DW.aSinInput;
  Algorithm_DW.Normalization1[3] = rtb_S_Eq_wt_idx_3 * Algorithm_DW.aSinInput;
  Algorithm_DW.aSinInput = (Algorithm_DW.Normalization1[1] *
    Algorithm_DW.Normalization1[3] + Algorithm_DW.Normalization1[2] *
    Algorithm_DW.Normalization1[0]) * 2.0;
  Algorithm_DW.b = Algorithm_DW.aSinInput;
  if (Algorithm_DW.aSinInput > 1.0) {
    Algorithm_DW.b = 1.0;
  }

  Algorithm_DW.c = Algorithm_DW.b;
  if (Algorithm_DW.b < -1.0) {
    Algorithm_DW.c = -1.0;
  }

  Algorithm_DW.aSinInput = Algorithm_DW.Normalization1[0] *
    Algorithm_DW.Normalization1[0];
  tmp = Algorithm_DW.Normalization1[1] * Algorithm_DW.Normalization1[1];
  tmp_0 = Algorithm_DW.Normalization1[2] * Algorithm_DW.Normalization1[2];
  EulXYZ_tmp = Algorithm_DW.Normalization1[3] * Algorithm_DW.Normalization1[3];

  /* Outport: '<Root>/EulXYZ' incorporates:
   *  MATLABSystem: '<S1>/Coordinate Transformation Conversion'
   */
  Algorithm_Y.EulXYZ[0] = atan2((Algorithm_DW.Normalization1[2] *
    Algorithm_DW.Normalization1[3] - Algorithm_DW.Normalization1[1] *
    Algorithm_DW.Normalization1[0]) * -2.0, ((Algorithm_DW.aSinInput - tmp) -
    tmp_0) + EulXYZ_tmp);
  Algorithm_Y.EulXYZ[1] = asin(Algorithm_DW.c);
  Algorithm_Y.EulXYZ[2] = atan2((Algorithm_DW.Normalization1[1] *
    Algorithm_DW.Normalization1[2] - Algorithm_DW.Normalization1[3] *
    Algorithm_DW.Normalization1[0]) * -2.0, ((Algorithm_DW.aSinInput + tmp) -
    tmp_0) - EulXYZ_tmp);

  /* Update for Delay: '<S1>/Delay' */
  Algorithm_DW.Delay_DSTATE[0] = rtb_S_Eq_wt_idx_0;
  Algorithm_DW.Delay_DSTATE[1] = rtb_S_Eq_wt_idx_1;
  Algorithm_DW.Delay_DSTATE[2] = rtb_S_Eq_wt_idx_2;
  Algorithm_DW.Delay_DSTATE[3] = rtb_S_Eq_wt_idx_3;
}

/* Model initialize function */
void Algorithm_initialize(void)
{
  /* InitializeConditions for Delay: '<S1>/Delay' */
  Algorithm_DW.Delay_DSTATE[0] = 1.0;
  Algorithm_DW.Delay_DSTATE[1] = 0.0;
  Algorithm_DW.Delay_DSTATE[2] = 0.0;
  Algorithm_DW.Delay_DSTATE[3] = 0.0;
}

/* Model terminate function */
void Algorithm_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
