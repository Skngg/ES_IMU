/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Algorithm.c
 *
 * Code generated for Simulink model 'Algorithm'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Fri Jan 15 19:03:00 2021
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
  real32_T rtb_Normalization1[4];
  real32_T rtb_Sum_g;
  real32_T rtb_Gain3;
  real32_T rtb_Gain4;
  real32_T rtb_Product1_m1;
  real32_T acc;
  int32_T i;
  real32_T tmp;
  real32_T tmp_0;

  /* Gain: '<S1>/Gain' incorporates:
   *  Delay: '<S1>/Delay'
   */
  rtb_Normalization1[0] = 0.5F * Algorithm_DW.Delay_DSTATE[0];
  rtb_Normalization1[1] = 0.5F * Algorithm_DW.Delay_DSTATE[1];
  rtb_Normalization1[2] = 0.5F * Algorithm_DW.Delay_DSTATE[2];
  rtb_Normalization1[3] = 0.5F * Algorithm_DW.Delay_DSTATE[3];

  /* Sum: '<S5>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  Inport: '<Root>/GyroX'
   *  Inport: '<Root>/GyroY'
   *  Inport: '<Root>/GyroZ'
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product3'
   */
  rtb_Sum_g = ((0.0F - rtb_Normalization1[1] * Algorithm_U.GyroX) -
               rtb_Normalization1[2] * Algorithm_U.GyroY) - rtb_Normalization1[3]
    * Algorithm_U.GyroZ;

  /* Sum: '<S6>/Sum' incorporates:
   *  Inport: '<Root>/GyroX'
   *  Inport: '<Root>/GyroY'
   *  Inport: '<Root>/GyroZ'
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product2'
   *  Product: '<S6>/Product3'
   */
  rtb_Gain3 = (rtb_Normalization1[0] * Algorithm_U.GyroX + rtb_Normalization1[2]
               * Algorithm_U.GyroZ) - rtb_Normalization1[3] * Algorithm_U.GyroY;

  /* Sum: '<S7>/Sum' incorporates:
   *  Inport: '<Root>/GyroX'
   *  Inport: '<Root>/GyroY'
   *  Inport: '<Root>/GyroZ'
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product3'
   */
  rtb_Gain4 = (rtb_Normalization1[0] * Algorithm_U.GyroY - rtb_Normalization1[1]
               * Algorithm_U.GyroZ) + rtb_Normalization1[3] * Algorithm_U.GyroX;

  /* Sum: '<S8>/Sum' incorporates:
   *  Inport: '<Root>/GyroX'
   *  Inport: '<Root>/GyroY'
   *  Inport: '<Root>/GyroZ'
   *  Product: '<S8>/Product'
   *  Product: '<S8>/Product1'
   *  Product: '<S8>/Product2'
   */
  rtb_Product1_m1 = (rtb_Normalization1[0] * Algorithm_U.GyroZ +
                     rtb_Normalization1[1] * Algorithm_U.GyroY) -
    rtb_Normalization1[2] * Algorithm_U.GyroX;

  /* SignalConversion generated from: '<S3>/Vector Concatenate' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S9>/Gain'
   *  Gain: '<S9>/Gain1'
   *  Gain: '<S9>/Gain2'
   *  Gain: '<S9>/Gain3'
   */
  Algorithm_DW.VectorConcatenate[0] = -2.0F * Algorithm_DW.Delay_DSTATE[2];
  Algorithm_DW.VectorConcatenate[1] = 2.0F * Algorithm_DW.Delay_DSTATE[3];
  Algorithm_DW.VectorConcatenate[2] = -2.0F * Algorithm_DW.Delay_DSTATE[0];
  Algorithm_DW.VectorConcatenate[3] = 2.0F * Algorithm_DW.Delay_DSTATE[1];

  /* SignalConversion generated from: '<S3>/Vector Concatenate' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S10>/Gain2'
   *  Gain: '<S10>/Gain3'
   *  Gain: '<S10>/Gain4'
   */
  Algorithm_DW.VectorConcatenate[4] = 2.0F * Algorithm_DW.Delay_DSTATE[1];
  Algorithm_DW.VectorConcatenate[5] = 2.0F * Algorithm_DW.Delay_DSTATE[0];
  Algorithm_DW.VectorConcatenate[6] = 2.0F * Algorithm_DW.Delay_DSTATE[3];
  Algorithm_DW.VectorConcatenate[7] = 2.0F * Algorithm_DW.Delay_DSTATE[2];

  /* SignalConversion generated from: '<S3>/Vector Concatenate' incorporates:
   *  Constant: '<S11>/Constant'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S11>/Gain1'
   *  Gain: '<S11>/Gain2'
   */
  Algorithm_DW.VectorConcatenate[8] = 0.0F;
  Algorithm_DW.VectorConcatenate[9] = -4.0F * Algorithm_DW.Delay_DSTATE[1];
  Algorithm_DW.VectorConcatenate[10] = -4.0F * Algorithm_DW.Delay_DSTATE[2];
  Algorithm_DW.VectorConcatenate[11] = 0.0F;

  /* SignalConversion generated from: '<S1>/Product' incorporates:
   *  Constant: '<S14>/Constant'
   *  Delay: '<S1>/Delay'
   *  Gain: '<S12>/Gain'
   *  Gain: '<S13>/Gain'
   *  Gain: '<S14>/Gain'
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
  acc = (Algorithm_DW.Delay_DSTATE[1] * Algorithm_DW.Delay_DSTATE[3] -
         Algorithm_DW.Delay_DSTATE[0] * Algorithm_DW.Delay_DSTATE[2]) * 2.0F -
    Algorithm_U.AccX;
  tmp = (Algorithm_DW.Delay_DSTATE[0] * Algorithm_DW.Delay_DSTATE[1] +
         Algorithm_DW.Delay_DSTATE[2] * Algorithm_DW.Delay_DSTATE[3]) * 2.0F -
    Algorithm_U.AccY;
  tmp_0 = ((0.5F - Algorithm_DW.Delay_DSTATE[1] * Algorithm_DW.Delay_DSTATE[1])
           - Algorithm_DW.Delay_DSTATE[2] * Algorithm_DW.Delay_DSTATE[2]) * 2.0F
    - Algorithm_U.AccZ;

  /* Product: '<S1>/Product' */
  for (i = 0; i < 4; i++) {
    rtb_Normalization1[i] = 0.0F;
    rtb_Normalization1[i] += Algorithm_DW.VectorConcatenate[i] * acc;
    rtb_Normalization1[i] += Algorithm_DW.VectorConcatenate[i + 4] * tmp;
    rtb_Normalization1[i] += Algorithm_DW.VectorConcatenate[i + 8] * tmp_0;
  }

  /* End of Product: '<S1>/Product' */

  /* S-Function (sdsp2norm2): '<S1>/Normalization1' */
  acc = 1.0F / ((real32_T)sqrt(((rtb_Normalization1[0] * rtb_Normalization1[0] +
    rtb_Normalization1[1] * rtb_Normalization1[1]) + rtb_Normalization1[2] *
    rtb_Normalization1[2]) + rtb_Normalization1[3] * rtb_Normalization1[3]) +
                1.0E-10F);
  rtb_Normalization1[0] *= acc;
  rtb_Normalization1[1] *= acc;
  rtb_Normalization1[2] *= acc;
  rtb_Normalization1[3] *= acc;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Delay: '<S1>/Delay'
   *  Gain: '<S1>/\delta t'
   *  Gain: '<S1>/beta'
   *  Sum: '<S1>/Sum'
   */
  rtb_Sum_g = (0.011F * rtb_Sum_g + Algorithm_DW.Delay_DSTATE[0]) -
    0.0107387146F * rtb_Normalization1[0];
  rtb_Gain3 = (0.011F * rtb_Gain3 + Algorithm_DW.Delay_DSTATE[1]) -
    0.0107387146F * rtb_Normalization1[1];
  rtb_Gain4 = (0.011F * rtb_Gain4 + Algorithm_DW.Delay_DSTATE[2]) -
    0.0107387146F * rtb_Normalization1[2];
  rtb_Product1_m1 = (0.011F * rtb_Product1_m1 + Algorithm_DW.Delay_DSTATE[3]) -
    0.0107387146F * rtb_Normalization1[3];

  /* Outport: '<Root>/Quat' */
  Algorithm_Y.Quat[0] = rtb_Sum_g;

  /* Update for Delay: '<S1>/Delay' incorporates:
   *  Outport: '<Root>/Quat'
   */
  Algorithm_DW.Delay_DSTATE[0] = rtb_Sum_g;

  /* Outport: '<Root>/Quat' */
  Algorithm_Y.Quat[1] = rtb_Gain3;

  /* Update for Delay: '<S1>/Delay' incorporates:
   *  Outport: '<Root>/Quat'
   */
  Algorithm_DW.Delay_DSTATE[1] = rtb_Gain3;

  /* Outport: '<Root>/Quat' */
  Algorithm_Y.Quat[2] = rtb_Gain4;

  /* Update for Delay: '<S1>/Delay' incorporates:
   *  Outport: '<Root>/Quat'
   */
  Algorithm_DW.Delay_DSTATE[2] = rtb_Gain4;

  /* Outport: '<Root>/Quat' */
  Algorithm_Y.Quat[3] = rtb_Product1_m1;

  /* Update for Delay: '<S1>/Delay' incorporates:
   *  Outport: '<Root>/Quat'
   */
  Algorithm_DW.Delay_DSTATE[3] = rtb_Product1_m1;
}

/* Model initialize function */
void Algorithm_initialize(void)
{
  /* InitializeConditions for Delay: '<S1>/Delay' */
  Algorithm_DW.Delay_DSTATE[0] = 1.0F;
  Algorithm_DW.Delay_DSTATE[1] = 0.0F;
  Algorithm_DW.Delay_DSTATE[2] = 0.0F;
  Algorithm_DW.Delay_DSTATE[3] = 0.0F;
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
