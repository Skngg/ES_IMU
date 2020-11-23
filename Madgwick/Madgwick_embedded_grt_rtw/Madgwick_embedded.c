/*
 * Madgwick_embedded.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Madgwick_embedded".
 *
 * Model version              : 1.33
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Mon Nov 23 21:27:16 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "Madgwick_embedded.h"
#include "Madgwick_embedded_private.h"

/* Model step function */
void Madgwick_embedded_step(RT_MODEL_Madgwick_embedded_T *const
  Madgwick_embedded_M)
{
  B_Madgwick_embedded_T *Madgwick_embedded_B = ((B_Madgwick_embedded_T *)
    Madgwick_embedded_M->blockIO);
  DW_Madgwick_embedded_T *Madgwick_embedded_DW = ((DW_Madgwick_embedded_T *)
    Madgwick_embedded_M->dwork);

  /* local block i/o variables */
  real_T rtb_Sum_j;
  real_T rtb_Product1_d;
  real_T rtb_Sum_lj;
  real_T rtb_Product2;
  real_T c;
  real_T rtb_Sum_i;
  real_T rtb_Sum_o;
  real_T rtb_deltat[4];
  int32_T i;
  real_T CoordinateTransformationConvers;
  real_T CoordinateTransformationConve_0;

  /* SignalConversion generated from: '<Root>/MATLAB Animation' */
  Madgwick_embedded_B->TmpSignalConversionAtMATLABAnim[0] = 0.0;
  Madgwick_embedded_B->TmpSignalConversionAtMATLABAnim[1] = 0.0;
  Madgwick_embedded_B->TmpSignalConversionAtMATLABAnim[2] = 0.0;

  /* Delay: '<S1>/Delay' */
  Madgwick_embedded_B->S_Ehatq_estt1[0] = Madgwick_embedded_DW->Delay_DSTATE[0];
  Madgwick_embedded_B->S_Ehatq_estt1[1] = Madgwick_embedded_DW->Delay_DSTATE[1];
  Madgwick_embedded_B->S_Ehatq_estt1[2] = Madgwick_embedded_DW->Delay_DSTATE[2];
  Madgwick_embedded_B->S_Ehatq_estt1[3] = Madgwick_embedded_DW->Delay_DSTATE[3];

  /* SignalConversion generated from: '<S3>/Vector Concatenate' incorporates:
   *  Gain: '<S9>/Gain'
   *  Gain: '<S9>/Gain1'
   *  Gain: '<S9>/Gain2'
   *  Gain: '<S9>/Gain3'
   */
  Madgwick_embedded_B->VectorConcatenate[0] = -2.0 *
    Madgwick_embedded_B->S_Ehatq_estt1[2];
  Madgwick_embedded_B->VectorConcatenate[1] = 2.0 *
    Madgwick_embedded_B->S_Ehatq_estt1[3];
  Madgwick_embedded_B->VectorConcatenate[2] = -2.0 *
    Madgwick_embedded_B->S_Ehatq_estt1[0];
  Madgwick_embedded_B->VectorConcatenate[3] = 2.0 *
    Madgwick_embedded_B->S_Ehatq_estt1[1];

  /* SignalConversion generated from: '<S3>/Vector Concatenate' incorporates:
   *  Gain: '<S10>/Gain1'
   *  Gain: '<S10>/Gain2'
   *  Gain: '<S10>/Gain3'
   *  Gain: '<S10>/Gain4'
   */
  Madgwick_embedded_B->VectorConcatenate[4] = 2.0 *
    Madgwick_embedded_B->S_Ehatq_estt1[1];
  Madgwick_embedded_B->VectorConcatenate[5] = 2.0 *
    Madgwick_embedded_B->S_Ehatq_estt1[0];
  Madgwick_embedded_B->VectorConcatenate[6] = 2.0 *
    Madgwick_embedded_B->S_Ehatq_estt1[3];
  Madgwick_embedded_B->VectorConcatenate[7] = 2.0 *
    Madgwick_embedded_B->S_Ehatq_estt1[2];

  /* SignalConversion generated from: '<S3>/Vector Concatenate' incorporates:
   *  Constant: '<S11>/Constant'
   *  Gain: '<S11>/Gain1'
   *  Gain: '<S11>/Gain2'
   */
  Madgwick_embedded_B->VectorConcatenate[8] = 0.0;
  Madgwick_embedded_B->VectorConcatenate[9] = -4.0 *
    Madgwick_embedded_B->S_Ehatq_estt1[1];
  Madgwick_embedded_B->VectorConcatenate[10] = -4.0 *
    Madgwick_embedded_B->S_Ehatq_estt1[2];
  Madgwick_embedded_B->VectorConcatenate[11] = 0.0;

  /* Gain: '<S12>/Gain' incorporates:
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product1'
   *  Sum: '<S12>/Sum'
   */
  Madgwick_embedded_B->Gain = (Madgwick_embedded_B->S_Ehatq_estt1[1] *
    Madgwick_embedded_B->S_Ehatq_estt1[3] - Madgwick_embedded_B->S_Ehatq_estt1[0]
    * Madgwick_embedded_B->S_Ehatq_estt1[2]) * 2.0;

  /* FromWorkspace: '<Root>/AccX' */
  {
    real_T *pDataValues = (real_T *) Madgwick_embedded_DW->AccX_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Madgwick_embedded_DW->AccX_PWORK.TimePtr;
    int_T currTimeIndex = Madgwick_embedded_DW->AccX_IWORK.PrevIndex;
    real_T t = Madgwick_embedded_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[1199]) {
      currTimeIndex = 1198;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    Madgwick_embedded_DW->AccX_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Product1_d = pDataValues[currTimeIndex];
        } else {
          rtb_Product1_d = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Product1_d = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 1200;
      }
    }
  }

  /* FromWorkspace: '<Root>/AccY' */
  {
    real_T *pDataValues = (real_T *) Madgwick_embedded_DW->AccY_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Madgwick_embedded_DW->AccY_PWORK.TimePtr;
    int_T currTimeIndex = Madgwick_embedded_DW->AccY_IWORK.PrevIndex;
    real_T t = Madgwick_embedded_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[1199]) {
      currTimeIndex = 1198;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    Madgwick_embedded_DW->AccY_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Sum_lj = pDataValues[currTimeIndex];
        } else {
          rtb_Sum_lj = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Sum_lj = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 1200;
      }
    }
  }

  /* FromWorkspace: '<Root>/AccZ' */
  {
    real_T *pDataValues = (real_T *) Madgwick_embedded_DW->AccZ_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Madgwick_embedded_DW->AccZ_PWORK.TimePtr;
    int_T currTimeIndex = Madgwick_embedded_DW->AccZ_IWORK.PrevIndex;
    real_T t = Madgwick_embedded_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[1199]) {
      currTimeIndex = 1198;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    Madgwick_embedded_DW->AccZ_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Product2 = pDataValues[currTimeIndex];
        } else {
          rtb_Product2 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Product2 = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 1200;
      }
    }
  }

  /* Gain: '<S1>/Normalization' */
  rtb_deltat[3] = 0.1019367991845056 * rtb_Product2;

  /* Sum: '<S12>/Sum1' incorporates:
   *  Gain: '<S1>/Normalization'
   */
  rtb_Product2 = Madgwick_embedded_B->Gain - 0.1019367991845056 * rtb_Product1_d;

  /* Gain: '<S13>/Gain' incorporates:
   *  Product: '<S13>/Product'
   *  Product: '<S13>/Product1'
   *  Sum: '<S13>/Sum'
   */
  Madgwick_embedded_B->Gain_a = (Madgwick_embedded_B->S_Ehatq_estt1[0] *
    Madgwick_embedded_B->S_Ehatq_estt1[1] + Madgwick_embedded_B->S_Ehatq_estt1[2]
    * Madgwick_embedded_B->S_Ehatq_estt1[3]) * 2.0;

  /* Sum: '<S13>/Sum1' incorporates:
   *  Gain: '<S1>/Normalization'
   */
  rtb_Sum_lj = Madgwick_embedded_B->Gain_a - 0.1019367991845056 * rtb_Sum_lj;

  /* Gain: '<S14>/Gain' incorporates:
   *  Constant: '<S14>/Constant'
   *  Product: '<S14>/Product'
   *  Product: '<S14>/Product1'
   *  Sum: '<S14>/Sum'
   *  Sum: '<S14>/Sum2'
   */
  Madgwick_embedded_B->Gain_m = ((0.5 - Madgwick_embedded_B->S_Ehatq_estt1[1] *
    Madgwick_embedded_B->S_Ehatq_estt1[1]) - Madgwick_embedded_B->S_Ehatq_estt1
    [2] * Madgwick_embedded_B->S_Ehatq_estt1[2]) * 2.0;

  /* Sum: '<S14>/Sum1' */
  rtb_Product1_d = Madgwick_embedded_B->Gain_m - rtb_deltat[3];

  /* Product: '<S1>/Product' incorporates:
   *  SignalConversion generated from: '<S1>/Product'
   */
  for (i = 0; i < 4; i++) {
    rtb_deltat[i] = Madgwick_embedded_B->VectorConcatenate[i + 8] *
      rtb_Product1_d + (Madgwick_embedded_B->VectorConcatenate[i + 4] *
                        rtb_Sum_lj + Madgwick_embedded_B->VectorConcatenate[i] *
                        rtb_Product2);
  }

  /* End of Product: '<S1>/Product' */

  /* S-Function (sdsp2norm2): '<S1>/Normalization1' */
  rtb_Sum_o = 1.0 / (sqrt(((rtb_deltat[0] * rtb_deltat[0] + rtb_deltat[1] *
    rtb_deltat[1]) + rtb_deltat[2] * rtb_deltat[2]) + rtb_deltat[3] *
    rtb_deltat[3]) + 1.0E-10);
  rtb_deltat[0] *= rtb_Sum_o;

  /* Gain: '<S1>/Gain' */
  Madgwick_embedded_B->frac12S_Ehatq_estt1[0] = 0.5 *
    Madgwick_embedded_B->S_Ehatq_estt1[0];

  /* S-Function (sdsp2norm2): '<S1>/Normalization1' */
  rtb_deltat[1] *= rtb_Sum_o;

  /* Gain: '<S1>/Gain' */
  Madgwick_embedded_B->frac12S_Ehatq_estt1[1] = 0.5 *
    Madgwick_embedded_B->S_Ehatq_estt1[1];

  /* S-Function (sdsp2norm2): '<S1>/Normalization1' */
  rtb_deltat[2] *= rtb_Sum_o;

  /* Gain: '<S1>/Gain' */
  Madgwick_embedded_B->frac12S_Ehatq_estt1[2] = 0.5 *
    Madgwick_embedded_B->S_Ehatq_estt1[2];

  /* S-Function (sdsp2norm2): '<S1>/Normalization1' */
  rtb_deltat[3] *= rtb_Sum_o;

  /* Gain: '<S1>/Gain' */
  Madgwick_embedded_B->frac12S_Ehatq_estt1[3] = 0.5 *
    Madgwick_embedded_B->S_Ehatq_estt1[3];

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S1>/Constant'
   */
  Madgwick_embedded_B->Product = 0.0;

  /* FromWorkspace: '<Root>/GyroX' */
  {
    real_T *pDataValues = (real_T *) Madgwick_embedded_DW->GyroX_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Madgwick_embedded_DW->GyroX_PWORK.TimePtr;
    int_T currTimeIndex = Madgwick_embedded_DW->GyroX_IWORK.PrevIndex;
    real_T t = Madgwick_embedded_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[1199]) {
      currTimeIndex = 1198;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    Madgwick_embedded_DW->GyroX_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Product2 = pDataValues[currTimeIndex];
        } else {
          rtb_Product2 = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Product2 = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 1200;
      }
    }
  }

  /* Product: '<S5>/Product1' */
  rtb_Sum_lj = Madgwick_embedded_B->frac12S_Ehatq_estt1[1] * rtb_Product2;

  /* FromWorkspace: '<Root>/GyroY' */
  {
    real_T *pDataValues = (real_T *) Madgwick_embedded_DW->GyroY_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Madgwick_embedded_DW->GyroY_PWORK.TimePtr;
    int_T currTimeIndex = Madgwick_embedded_DW->GyroY_IWORK.PrevIndex;
    real_T t = Madgwick_embedded_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[1199]) {
      currTimeIndex = 1198;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    Madgwick_embedded_DW->GyroY_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Product1_d = pDataValues[currTimeIndex];
        } else {
          rtb_Product1_d = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Product1_d = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 1200;
      }
    }
  }

  /* FromWorkspace: '<Root>/GyroZ' */
  {
    real_T *pDataValues = (real_T *) Madgwick_embedded_DW->GyroZ_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Madgwick_embedded_DW->GyroZ_PWORK.TimePtr;
    int_T currTimeIndex = Madgwick_embedded_DW->GyroZ_IWORK.PrevIndex;
    real_T t = Madgwick_embedded_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[1199]) {
      currTimeIndex = 1198;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    Madgwick_embedded_DW->GyroZ_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_Sum_j = pDataValues[currTimeIndex];
        } else {
          rtb_Sum_j = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_Sum_j = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 1200;
      }
    }
  }

  /* Sum: '<S5>/Sum' incorporates:
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product3'
   */
  rtb_Sum_lj = ((Madgwick_embedded_B->Product - rtb_Sum_lj) -
                Madgwick_embedded_B->frac12S_Ehatq_estt1[2] * rtb_Product1_d) -
    Madgwick_embedded_B->frac12S_Ehatq_estt1[3] * rtb_Sum_j;

  /* Product: '<S6>/Product1' incorporates:
   *  Constant: '<S1>/Constant'
   */
  Madgwick_embedded_B->Product1 = 0.0;

  /* Sum: '<S6>/Sum' incorporates:
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product2'
   *  Product: '<S6>/Product3'
   */
  rtb_Sum_o = ((Madgwick_embedded_B->frac12S_Ehatq_estt1[0] * rtb_Product2 +
                Madgwick_embedded_B->Product1) +
               Madgwick_embedded_B->frac12S_Ehatq_estt1[2] * rtb_Sum_j) -
    Madgwick_embedded_B->frac12S_Ehatq_estt1[3] * rtb_Product1_d;

  /* Product: '<S7>/Product2' incorporates:
   *  Constant: '<S1>/Constant'
   */
  Madgwick_embedded_B->Product2 = 0.0;

  /* Sum: '<S7>/Sum' incorporates:
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   *  Product: '<S7>/Product3'
   */
  rtb_Sum_i = ((Madgwick_embedded_B->frac12S_Ehatq_estt1[0] * rtb_Product1_d -
                Madgwick_embedded_B->frac12S_Ehatq_estt1[1] * rtb_Sum_j) +
               Madgwick_embedded_B->Product2) +
    Madgwick_embedded_B->frac12S_Ehatq_estt1[3] * rtb_Product2;

  /* Product: '<S8>/Product' */
  rtb_Sum_j *= Madgwick_embedded_B->frac12S_Ehatq_estt1[0];

  /* Product: '<S8>/Product1' */
  rtb_Product1_d *= Madgwick_embedded_B->frac12S_Ehatq_estt1[1];

  /* Product: '<S8>/Product2' */
  rtb_Product2 *= Madgwick_embedded_B->frac12S_Ehatq_estt1[2];

  /* Product: '<S8>/Product3' incorporates:
   *  Constant: '<S1>/Constant'
   */
  Madgwick_embedded_B->Product3 = 0.0;

  /* Sum: '<S8>/Sum' */
  rtb_Sum_j = ((rtb_Sum_j + rtb_Product1_d) - rtb_Product2) +
    Madgwick_embedded_B->Product3;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/\delta t'
   *  Gain: '<S1>/beta'
   *  Sum: '<S1>/Sum'
   */
  Madgwick_embedded_B->S_Eq_estt[0] = (0.01 * rtb_Sum_lj +
    Madgwick_embedded_B->S_Ehatq_estt1[0]) - 0.075574973509759 * rtb_deltat[0];
  Madgwick_embedded_B->S_Eq_estt[1] = (0.01 * rtb_Sum_o +
    Madgwick_embedded_B->S_Ehatq_estt1[1]) - 0.075574973509759 * rtb_deltat[1];
  Madgwick_embedded_B->S_Eq_estt[2] = (0.01 * rtb_Sum_i +
    Madgwick_embedded_B->S_Ehatq_estt1[2]) - 0.075574973509759 * rtb_deltat[2];
  Madgwick_embedded_B->S_Eq_estt[3] = (0.01 * rtb_Sum_j +
    Madgwick_embedded_B->S_Ehatq_estt1[3]) - 0.075574973509759 * rtb_deltat[3];

  /* MATLABSystem: '<S1>/Coordinate Transformation Conversion' */
  rtb_Sum_o = 1.0 / sqrt(((Madgwick_embedded_B->S_Eq_estt[0] *
    Madgwick_embedded_B->S_Eq_estt[0] + Madgwick_embedded_B->S_Eq_estt[1] *
    Madgwick_embedded_B->S_Eq_estt[1]) + Madgwick_embedded_B->S_Eq_estt[2] *
    Madgwick_embedded_B->S_Eq_estt[2]) + Madgwick_embedded_B->S_Eq_estt[3] *
    Madgwick_embedded_B->S_Eq_estt[3]);
  rtb_deltat[0] = Madgwick_embedded_B->S_Eq_estt[0] * rtb_Sum_o;
  rtb_deltat[1] = Madgwick_embedded_B->S_Eq_estt[1] * rtb_Sum_o;
  rtb_deltat[2] = Madgwick_embedded_B->S_Eq_estt[2] * rtb_Sum_o;
  rtb_deltat[3] = Madgwick_embedded_B->S_Eq_estt[3] * rtb_Sum_o;
  rtb_Sum_o = (rtb_deltat[1] * rtb_deltat[3] + rtb_deltat[2] * rtb_deltat[0]) *
    2.0;
  if (rtb_Sum_o > 1.0) {
    rtb_Sum_o = 1.0;
  }

  c = rtb_Sum_o;
  if (rtb_Sum_o < -1.0) {
    c = -1.0;
  }

  rtb_Sum_o = rtb_deltat[0] * rtb_deltat[0];
  rtb_Sum_i = rtb_deltat[1] * rtb_deltat[1];
  CoordinateTransformationConvers = rtb_deltat[2] * rtb_deltat[2];
  CoordinateTransformationConve_0 = rtb_deltat[3] * rtb_deltat[3];
  Madgwick_embedded_B->CoordinateTransformationConvers[0] = atan2((rtb_deltat[2]
    * rtb_deltat[3] - rtb_deltat[1] * rtb_deltat[0]) * -2.0, ((rtb_Sum_o -
    rtb_Sum_i) - CoordinateTransformationConvers) +
    CoordinateTransformationConve_0);
  Madgwick_embedded_B->CoordinateTransformationConvers[1] = asin(c);
  Madgwick_embedded_B->CoordinateTransformationConvers[2] = atan2((rtb_deltat[1]
    * rtb_deltat[2] - rtb_deltat[3] * rtb_deltat[0]) * -2.0, ((rtb_Sum_o +
    rtb_Sum_i) - CoordinateTransformationConvers) -
    CoordinateTransformationConve_0);

  /* End of MATLABSystem: '<S1>/Coordinate Transformation Conversion' */

  /* Update for Delay: '<S1>/Delay' */
  Madgwick_embedded_DW->Delay_DSTATE[0] = Madgwick_embedded_B->S_Eq_estt[0];
  Madgwick_embedded_DW->Delay_DSTATE[1] = Madgwick_embedded_B->S_Eq_estt[1];
  Madgwick_embedded_DW->Delay_DSTATE[2] = Madgwick_embedded_B->S_Eq_estt[2];
  Madgwick_embedded_DW->Delay_DSTATE[3] = Madgwick_embedded_B->S_Eq_estt[3];

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Madgwick_embedded_M->Timing.t[0] =
    ((time_T)(++Madgwick_embedded_M->Timing.clockTick0)) *
    Madgwick_embedded_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Madgwick_embedded_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Madgwick_embedded_initialize(RT_MODEL_Madgwick_embedded_T *const
  Madgwick_embedded_M)
{
  DW_Madgwick_embedded_T *Madgwick_embedded_DW = ((DW_Madgwick_embedded_T *)
    Madgwick_embedded_M->dwork);

  /* Start for FromWorkspace: '<Root>/AccX' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06,
      0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18,
      0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31,
      0.32, 0.33, 0.34, 0.35, 0.36, 0.37, 0.38, 0.39, 0.4, 0.41, 0.42, 0.43,
      0.44, 0.45, 0.46, 0.47, 0.48, 0.49, 0.5, 0.51, 0.52, 0.53, 0.54, 0.55,
      0.56, 0.57, 0.58, 0.59, 0.6, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67,
      0.68, 0.69, 0.7, 0.71, 0.72, 0.73, 0.74, 0.75, 0.76, 0.77, 0.78, 0.79, 0.8,
      0.81, 0.82, 0.83, 0.84, 0.85, 0.86, 0.87, 0.88, 0.89, 0.9, 0.91, 0.92,
      0.93, 0.94, 0.95, 0.96, 0.97, 0.98, 0.99, 1.0, 1.01, 1.02, 1.03, 1.04,
      1.05, 1.06, 1.07, 1.08, 1.09, 1.1, 1.11, 1.12, 1.13, 1.14, 1.15, 1.16,
      1.17, 1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28,
      1.29, 1.3, 1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37, 1.38, 1.39, 1.4, 1.41,
      1.42, 1.43, 1.44, 1.45, 1.46, 1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53,
      1.54, 1.55, 1.56, 1.57, 1.58, 1.59, 1.6, 1.61, 1.62, 1.63, 1.64, 1.65,
      1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75, 1.76, 1.77,
      1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.85, 1.86, 1.87, 1.88, 1.89, 1.9,
      1.91, 1.92, 1.93, 1.94, 1.95, 1.96, 1.97, 1.98, 1.99, 2.0, 2.01, 2.02,
      2.03, 2.04, 2.05, 2.06, 2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14,
      2.15, 2.16, 2.17, 2.18, 2.19, 2.2, 2.21, 2.22, 2.23, 2.24, 2.25, 2.26,
      2.27, 2.28, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34, 2.35, 2.36, 2.37, 2.38,
      2.39, 2.4, 2.41, 2.42, 2.43, 2.44, 2.45, 2.46, 2.47, 2.48, 2.49, 2.5, 2.51,
      2.52, 2.53, 2.54, 2.55, 2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63,
      2.64, 2.65, 2.66, 2.67, 2.68, 2.69, 2.7, 2.71, 2.72, 2.73, 2.74, 2.75,
      2.76, 2.77, 2.78, 2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87,
      2.88, 2.89, 2.9, 2.91, 2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0,
      3.01, 3.02, 3.03, 3.04, 3.05, 3.06, 3.07, 3.08, 3.09, 3.1, 3.11, 3.12,
      3.13, 3.14, 3.15, 3.16, 3.17, 3.18, 3.19, 3.2, 3.21, 3.22, 3.23, 3.24,
      3.25, 3.26, 3.27, 3.28, 3.29, 3.3, 3.31, 3.32, 3.33, 3.34, 3.35, 3.36,
      3.37, 3.38, 3.39, 3.4, 3.41, 3.42, 3.43, 3.44, 3.45, 3.46, 3.47, 3.48,
      3.49, 3.5, 3.51, 3.52, 3.53, 3.54, 3.55, 3.56, 3.57, 3.58, 3.59, 3.6, 3.61,
      3.62, 3.63, 3.64, 3.65, 3.66, 3.67, 3.68, 3.69, 3.7, 3.71, 3.72, 3.73,
      3.74, 3.75, 3.76, 3.77, 3.78, 3.79, 3.8, 3.81, 3.82, 3.83, 3.84, 3.85,
      3.86, 3.87, 3.88, 3.89, 3.9, 3.91, 3.92, 3.93, 3.94, 3.95, 3.96, 3.97,
      3.98, 3.99, 4.0, 4.01, 4.02, 4.03, 4.04, 4.05, 4.06, 4.07, 4.08, 4.09, 4.1,
      4.11, 4.12, 4.13, 4.14, 4.15, 4.16, 4.17, 4.18, 4.19, 4.2, 4.21, 4.22,
      4.23, 4.24, 4.25, 4.26, 4.27, 4.28, 4.29, 4.3, 4.31, 4.32, 4.33, 4.34,
      4.35, 4.36, 4.37, 4.38, 4.39, 4.4, 4.41, 4.42, 4.43, 4.44, 4.45, 4.46,
      4.47, 4.48, 4.49, 4.5, 4.51, 4.52, 4.53, 4.54, 4.55, 4.56, 4.57, 4.58,
      4.59, 4.6, 4.61, 4.62, 4.63, 4.64, 4.65, 4.66, 4.67, 4.68, 4.69, 4.7, 4.71,
      4.72, 4.73, 4.74, 4.75, 4.76, 4.77, 4.78, 4.79, 4.8, 4.81, 4.82, 4.83,
      4.84, 4.85, 4.86, 4.87, 4.88, 4.89, 4.9, 4.91, 4.92, 4.93, 4.94, 4.95,
      4.96, 4.97, 4.98, 4.99, 5.0, 5.01, 5.02, 5.03, 5.04, 5.05, 5.06, 5.07,
      5.08, 5.09, 5.1, 5.11, 5.12, 5.13, 5.14, 5.15, 5.16, 5.17, 5.18, 5.19, 5.2,
      5.21, 5.22, 5.23, 5.24, 5.25, 5.26, 5.27, 5.28, 5.29, 5.3, 5.31, 5.32,
      5.33, 5.34, 5.35, 5.36, 5.37, 5.38, 5.39, 5.4, 5.41, 5.42, 5.43, 5.44,
      5.45, 5.46, 5.47, 5.48, 5.49, 5.5, 5.51, 5.52, 5.53, 5.54, 5.55, 5.56,
      5.57, 5.58, 5.59, 5.6, 5.61, 5.62, 5.63, 5.64, 5.65, 5.66, 5.67, 5.68,
      5.69, 5.7, 5.71, 5.72, 5.73, 5.74, 5.75, 5.76, 5.77, 5.78, 5.79, 5.8, 5.81,
      5.82, 5.83, 5.84, 5.85, 5.86, 5.87, 5.88, 5.89, 5.9, 5.91, 5.92, 5.93,
      5.94, 5.95, 5.96, 5.97, 5.98, 5.99, 6.0, 6.01, 6.02, 6.03, 6.04, 6.05,
      6.06, 6.07, 6.08, 6.09, 6.1, 6.11, 6.12, 6.13, 6.14, 6.15, 6.16, 6.17,
      6.18, 6.19, 6.2, 6.21, 6.22, 6.23, 6.24, 6.25, 6.26, 6.27, 6.28, 6.29, 6.3,
      6.31, 6.32, 6.33, 6.34, 6.35, 6.36, 6.37, 6.38, 6.39, 6.4, 6.41, 6.42,
      6.43, 6.44, 6.45, 6.46, 6.47, 6.48, 6.49, 6.5, 6.51, 6.52, 6.53, 6.54,
      6.55, 6.56, 6.57, 6.58, 6.59, 6.6, 6.61, 6.62, 6.63, 6.64, 6.65, 6.66,
      6.67, 6.68, 6.69, 6.7, 6.71, 6.72, 6.73, 6.74, 6.75, 6.76, 6.77, 6.78,
      6.79, 6.8, 6.81, 6.82, 6.83, 6.84, 6.85, 6.86, 6.87, 6.88, 6.89, 6.9, 6.91,
      6.92, 6.93, 6.94, 6.95, 6.96, 6.97, 6.98, 6.99, 7.0, 7.01, 7.02, 7.03,
      7.04, 7.05, 7.06, 7.07, 7.08, 7.09, 7.1, 7.11, 7.12, 7.13, 7.14, 7.15,
      7.16, 7.17, 7.18, 7.19, 7.2, 7.21, 7.22, 7.23, 7.24, 7.25, 7.26, 7.27,
      7.28, 7.29, 7.3, 7.31, 7.32, 7.33, 7.34, 7.35, 7.36, 7.37, 7.38, 7.39, 7.4,
      7.41, 7.42, 7.43, 7.44, 7.45, 7.46, 7.47, 7.48, 7.49, 7.5, 7.51, 7.52,
      7.53, 7.54, 7.55, 7.56, 7.57, 7.58, 7.59, 7.6, 7.61, 7.62, 7.63, 7.64,
      7.65, 7.66, 7.67, 7.68, 7.69, 7.7, 7.71, 7.72, 7.73, 7.74, 7.75, 7.76,
      7.77, 7.78, 7.79, 7.8, 7.81, 7.82, 7.83, 7.84, 7.85, 7.86, 7.87, 7.88,
      7.89, 7.9, 7.91, 7.92, 7.93, 7.94, 7.95, 7.96, 7.97, 7.98, 7.99, 8.0, 8.01,
      8.02, 8.03, 8.04, 8.05, 8.06, 8.07, 8.08, 8.09, 8.1, 8.11, 8.12, 8.13,
      8.14, 8.15, 8.16, 8.17, 8.18, 8.19, 8.2, 8.21, 8.22, 8.23, 8.24, 8.25,
      8.26, 8.27, 8.28, 8.29, 8.3, 8.31, 8.32, 8.33, 8.34, 8.35, 8.36, 8.37,
      8.38, 8.39, 8.4, 8.41, 8.42, 8.43, 8.44, 8.45, 8.46, 8.47, 8.48, 8.49, 8.5,
      8.51, 8.52, 8.53, 8.54, 8.55, 8.56, 8.57, 8.58, 8.59, 8.6, 8.61, 8.62,
      8.63, 8.64, 8.65, 8.66, 8.67, 8.68, 8.69, 8.7, 8.71, 8.72, 8.73, 8.74,
      8.75, 8.76, 8.77, 8.78, 8.79, 8.8, 8.81, 8.82, 8.83, 8.84, 8.85, 8.86,
      8.87, 8.88, 8.89, 8.9, 8.91, 8.92, 8.93, 8.94, 8.95, 8.96, 8.97, 8.98,
      8.99, 9.0, 9.01, 9.02, 9.03, 9.04, 9.05, 9.06, 9.07, 9.08, 9.09, 9.1, 9.11,
      9.12, 9.13, 9.14, 9.15, 9.16, 9.17, 9.18, 9.19, 9.2, 9.21, 9.22, 9.23,
      9.24, 9.25, 9.26, 9.27, 9.28, 9.29, 9.3, 9.31, 9.32, 9.33, 9.34, 9.35,
      9.36, 9.37, 9.38, 9.39, 9.4, 9.41, 9.42, 9.43, 9.44, 9.45, 9.46, 9.47,
      9.48, 9.49, 9.5, 9.51, 9.52, 9.53, 9.54, 9.55, 9.56, 9.57, 9.58, 9.59, 9.6,
      9.61, 9.62, 9.63, 9.64, 9.65, 9.66, 9.67, 9.68, 9.69, 9.7, 9.71, 9.72,
      9.73, 9.74, 9.75, 9.76, 9.77, 9.78, 9.79, 9.8, 9.81, 9.82, 9.83, 9.84,
      9.85, 9.86, 9.87, 9.88, 9.89, 9.9, 9.91, 9.92, 9.93, 9.94, 9.95, 9.96,
      9.97, 9.98, 9.99, 10.0, 10.01, 10.02, 10.03, 10.04, 10.05, 10.06, 10.07,
      10.08, 10.09, 10.1, 10.11, 10.12, 10.13, 10.14, 10.15, 10.16, 10.17, 10.18,
      10.19, 10.2, 10.21, 10.22, 10.23, 10.24, 10.25, 10.26, 10.27, 10.28, 10.29,
      10.3, 10.31, 10.32, 10.33, 10.34, 10.35, 10.36, 10.37, 10.38, 10.39, 10.4,
      10.41, 10.42, 10.43, 10.44, 10.45, 10.46, 10.47, 10.48, 10.49, 10.5, 10.51,
      10.52, 10.53, 10.54, 10.55, 10.56, 10.57, 10.58, 10.59, 10.6, 10.61, 10.62,
      10.63, 10.64, 10.65, 10.66, 10.67, 10.68, 10.69, 10.7, 10.71, 10.72, 10.73,
      10.74, 10.75, 10.76, 10.77, 10.78, 10.79, 10.8, 10.81, 10.82, 10.83, 10.84,
      10.85, 10.86, 10.87, 10.88, 10.89, 10.9, 10.91, 10.92, 10.93, 10.94, 10.95,
      10.96, 10.97, 10.98, 10.99, 11.0, 11.01, 11.02, 11.03, 11.04, 11.05, 11.06,
      11.07, 11.08, 11.09, 11.1, 11.11, 11.12, 11.13, 11.14, 11.15, 11.16, 11.17,
      11.18, 11.19, 11.2, 11.21, 11.22, 11.23, 11.24, 11.25, 11.26, 11.27, 11.28,
      11.29, 11.3, 11.31, 11.32, 11.33, 11.34, 11.35, 11.36, 11.37, 11.38, 11.39,
      11.4, 11.41, 11.42, 11.43, 11.44, 11.45, 11.46, 11.47, 11.48, 11.49, 11.5,
      11.51, 11.52, 11.53, 11.54, 11.55, 11.56, 11.57, 11.58, 11.59, 11.6, 11.61,
      11.62, 11.63, 11.64, 11.65, 11.66, 11.67, 11.68, 11.69, 11.7, 11.71, 11.72,
      11.73, 11.74, 11.75, 11.76, 11.77, 11.78, 11.79, 11.8, 11.81, 11.82, 11.83,
      11.84, 11.85, 11.86, 11.87, 11.88, 11.89, 11.9, 11.91, 11.92, 11.93, 11.94,
      11.95, 11.96, 11.97, 11.98, 11.99 } ;

    static real_T pDataValues0[] = { -9.01568568062217, -8.88991499736422,
      -8.80921201753588, -8.6941384717510122, -9.0146291862846919,
      -8.7425101152582787, -8.2410009054249667, -8.7897147748904967,
      -8.7310459042212, -8.7802437518003771, -8.8687943013515724,
      -8.55877608185392, -8.5508957065928737, -8.6468189455376638,
      -8.505785270923111, -8.6266431954811225, -8.5967902779056011,
      -8.4201746733239364, -8.7485468392341446, -8.1095436234823914,
      -8.206222185177527, -8.3402899845641461, -8.372596669816577,
      -8.1186780810616828, -7.7324606875013284, -8.0041735106583527,
      -8.21653081467568, -7.6402833878523548, -8.0122895368489733,
      -7.9657086053544717, -7.7867603936860057, -7.7323905116961154,
      -7.6538102732622608, -7.6417514556836057, -7.6840662733988214,
      -7.2811257946702437, -7.2269521666377479, -7.283523874190724,
      -6.9560442017732607, -6.5695391425357315, -6.9577691279492715,
      -7.0598832393350026, -6.6996920551895682, -6.3884829837551855,
      -6.2756780265958039, -6.391655577987521, -6.3897700961978456,
      -6.6167510339821147, -5.7943190446279065, -6.0251620867731663,
      -6.009984224731137, -5.7938571866776263, -5.4960514273823966,
      -5.6146497174506083, -5.4239961610615524, -5.1515096898452235,
      -5.4402847935412169, -5.2299031584742508, -5.0197722552594817,
      -4.7550565722224212, -4.8177101553381751, -4.8673752511420236,
      -4.2964604117816911, -4.5133724435970572, -4.341963396513064,
      -3.9116232821625818, -3.8210534792655482, -3.81888947252701,
      -3.7284796596370571, -3.8967435781012512, -3.59241065682901,
      -3.3395672767082507, -3.1724255528326513, -2.9891072720059815,
      -2.9058066466360741, -2.7875468397844756, -2.6083378638846009,
      -2.6369756445718124, -2.3492413792616138, -2.3512229871269859,
      -1.9534953377733695, -1.8537277536595158, -1.9701997813052454,
      -1.6865862454093832, -1.2465628262851465, -1.4632116300009517,
      -0.82884790312216228, -0.87555943631110433, -1.07224100229107,
      -0.39884067687350977, -0.88824303068770627, -0.22079653238519636,
      -0.14384285022817989, 0.0040587601121000461, 0.42086816264454374,
      0.083886904296992526, 0.45279834576208522, 0.52941612596016108,
      0.58381403714881053, 0.5403921087952277, 1.2018216294673751,
      1.237519688541743, 1.4029658780388037, 1.6538626106672383,
      1.5717603760295056, 1.8331908794401273, 2.0561361287109365,
      2.117337610179673, 2.4826164875064705, 2.1549882855988196,
      2.5978204659637241, 2.5050783651116646, 2.6169712459242565,
      2.8386870136548339, 3.2654297205342795, 3.0720389174785017,
      3.6417622044810676, 3.6319412112845986, 3.5892335235587622,
      4.0809010334087805, 3.9290793680435869, 4.1099541734327509,
      4.3796630923106088, 4.4525405313366493, 4.9093378527379405,
      4.6571901155471505, 5.1528191739772318, 5.1164582154432541,
      5.2722807174802968, 5.2538210915147614, 5.6642152638054908,
      5.6269946825378314, 5.7495529625751685, 5.7674653753267577,
      6.1608236371432872, 5.88348290335911, 6.1156449809877138,
      6.5038079521506615, 6.6181526572607812, 6.6022140607324094,
      6.642440611807535, 6.6153411865345824, 7.6605370616634314,
      6.9969777112087961, 7.2155260647589978, 7.2376377118364523,
      7.5226605985915409, 7.5764132599192413, 7.4047737174631534,
      7.5494848551648959, 7.8329922106803478, 8.3168084360245516,
      8.0704691243209847, 8.3572621999790044, 8.4795369572461166,
      8.6731815903544209, 8.7056341090887237, 8.7663326711189775,
      8.85215947559436, 8.8851132591808728, 9.3524827175343166,
      9.1301048945899854, 9.0693666090926559, 9.1355120553434261,
      9.5223037213563462, 9.5069052196955628, 9.3469094981392828,
      9.4857035870452222, 9.43313683176859, 9.596244467211152,
      9.7700229192331456, 9.6962493030415224, 9.773505543204374,
      9.7527945444849813, 10.069465511057137, 10.027435586721786,
      9.8623057954591786, 10.260351726950558, 10.382010958153025,
      10.037607089418632, 10.156251475563852, 10.249052758860934,
      9.8955821667561068, 10.491552294598824, 10.624888739363811,
      10.764433179222664, 10.89414957021326, 10.462757042928262,
      10.391212497116658, 10.54346839528959, 10.919451616149734,
      10.78695579811364, 10.615368459679662, 10.472512793158055,
      10.917479723519822, 10.733350516296536, 10.590548877932928,
      10.866499274893011, 10.727479547902202, 10.890142786260615,
      10.65878294835885, 11.00709605388985, 10.659880503454154,
      10.819707134609896, 10.690246811099222, 10.929145684254115,
      10.688670516240153, 10.988198540222339, 10.545989578045917,
      10.953179776703818, 10.73650447235066, 10.729362775556718,
      10.448809220476814, 10.662153290950807, 10.891102077213281,
      10.706335041871666, 10.431429770805645, 10.590052393486637,
      10.305115304029606, 10.34469859782774, 10.526081102351485,
      10.289049254953857, 10.384287811215076, 10.106241311080341,
      10.025235493057171, 10.297674044736205, 9.9108590690131564,
      9.9395832289941612, 9.9610605087553932, 9.75377866706752,
      9.577149840955407, 9.5084426717398323, 9.3246226483735235,
      9.4886895359841947, 9.3598369561193451, 9.2856976196666245,
      9.3062710964714661, 9.2346217823373564, 9.1866937293897,
      8.5968318713652643, 8.7770669147653919, 8.8865272984462074,
      9.0378433172850823, 8.844036753195514, 8.5740093326802853,
      8.306623949366557, 8.5382682917241866, 8.3009710481612053,
      8.3454673719428243, 8.0399086979305139, 7.8654990012719548,
      7.8758022255556535, 7.6642940775079627, 7.9849357977394053,
      7.4513579262051923, 7.2817323730640009, 7.0397435067312557,
      7.1489000572959522, 6.7050869384705312, 7.1544570398556093,
      6.9644454024242481, 6.6198802467678206, 6.3374840800600785,
      6.61313233510664, 6.11042435418565, 6.1454533803234064, 6.0298884050066013,
      5.7536630358988949, 5.6437966714521366, 5.738668398314517,
      5.4947788589485151, 5.527357795520123, 5.2324569213126884,
      4.7097615530026555, 4.6691856238017886, 4.7408689537923223,
      4.8259250419138731, 4.5991772523667791, 4.1503075280535349,
      4.1726369962423586, 3.83927656054871, 3.7145000562809707,
      3.8065067030862418, 3.5087907042291389, 3.3011004122635161,
      3.054307568938011, 3.5641621464960522, 2.9250725612449289,
      2.9718077572693087, 2.7611394629710508, 2.8125845124640212,
      2.5541796150931493, 2.2467039697082778, 1.906307038051545,
      2.1847124788639691, 1.91254582753123, 1.3426292313464157, 1.2355555406341,
      1.4156396581755795, 1.1089908616624802, 0.73724507544284523,
      0.92407298001900751, 0.545823731812217, 0.40075429723829448,
      0.30620661353774992, -0.11009159292914372, 0.05750495359369634,
      -0.2683781988656222, -0.140902420579063, -0.33829624167660977,
      -0.50912019238009876, -0.65700189317591984, -0.85850451424241569,
      -1.0226829230737526, -1.2558489364845165, -0.99362496817251,
      -1.2100794751560326, -1.3455568896730985, -1.659380707754412,
      -2.0576198876169975, -2.1305923615266833, -2.1945579476490753,
      -2.2935460461765511, -2.4059027700049174, -2.75370733348746,
      -2.6990822361796689, -3.008167238555191, -3.0830385684318795,
      -2.9876281012119685, -3.2321564740641842, -3.4986731418848525,
      -3.9241118188264874, -3.8071140113106745, -3.9807199054556275,
      -4.0740412775890444, -4.0379125101759525, -4.1058949676183,
      -4.7971436164146066, -4.2043638124749059, -4.5124690801840961,
      -5.063255747665476, -4.8039164626284094, -4.8347340428700862,
      -4.9337435440336526, -5.2201785462414207, -5.334351268829141,
      -5.3357406355376744, -5.0521801929752783, -5.769384855058898,
      -5.7231249296518545, -6.32590773862143, -5.8825703971945327,
      -6.0664842849775553, -6.2996399506401382, -6.17310820814603,
      -6.4855545187883763, -6.1709162828033728, -6.6662095012210854,
      -6.7420696127239976, -7.0907573161436765, -7.0256273563442626,
      -6.9169791732502706, -7.3596280196846511, -7.2575379409451539,
      -7.15330116324726, -7.3740898391110772, -7.7186103912853259,
      -7.4527713488623526, -7.7741469487471431, -7.8023361639148181,
      -7.8965138059627, -7.78925531093987, -7.8235825095986673,
      -8.2474934793456516, -8.255820483832407, -8.1231840169612468,
      -8.37207788966909, -7.8375712692460091, -8.05733090798565,
      -8.3107895209433167, -8.4979594584591212, -8.37290725786929,
      -8.2287383590899736, -8.4178235933858012, -8.3975682248031447,
      -8.55171014475745, -8.48941227175249, -8.6980226777109184,
      -9.0992008203474217, -8.6650332900789042, -8.9853516524582968,
      -8.1928512535722327, -8.5845111717650582, -8.68445869867573,
      -8.83649433791091, -8.540004568369671, -8.77243659874085,
      -8.5196717608724786, -8.8473227891746848, -8.8728012500861411,
      -8.6934427566608345, -8.6377807703584164, -8.8640705164085443,
      -8.5923114071480917, -8.7862399359686947, -8.8212610645118,
      -8.8424194961424512, -8.5952738680804028, -8.5268495035662255,
      -8.519423925747013, -8.696308215169255, -8.7087722290016831,
      -8.4408669707909567, -8.6723621139457769, -8.7004209832468771,
      -8.7153339089275139, -8.2865427306105612, -8.2454097168227385,
      -8.4221663174544048, -8.4283197703543848, -8.2232556429803481,
      -8.3870508060677817, -8.2959768519941459, -8.19991215590502,
      -8.2012298841056648, -8.18863550860256, -7.7613291951523706,
      -7.6616328627882258, -8.2590368961554663, -7.738675157217239,
      -7.8035997184175319, -7.965515620135891, -7.6361903534827,
      -7.705121163189899, -7.4333819838739181, -7.3350687326615187,
      -7.1947956552900969, -6.8654848748649826, -7.3300111277783291,
      -6.9733981477972637, -6.5455354246873094, -6.5088605359254013,
      -6.7881583510257659, -6.8124667750275405, -6.26630332580513,
      -6.4683969409303739, -6.40549243911397, -6.2997746470437832,
      -6.2755399608539673, -6.0427474312307883, -6.1513199139687078,
      -6.0202897293136495, -5.8404445272752845, -5.4643903916609116,
      -5.5630736321501466, -5.37029127328251, -5.151851808927332,
      -5.3932086861866742, -5.0854363599466206, -4.7911822521126268,
      -4.6501023160610124, -4.8314845353559228, -4.5177431224286435,
      -4.3083205714768225, -3.9478434649418972, -4.0217418305688506,
      -3.8681330619675718, -3.8234717248758079, -4.1957803786623584,
      -3.7255496611579746, -3.0213592294896605, -3.3422139970376117,
      -2.8967788271871608, -2.7100597086207481, -2.7730970521567944,
      -2.6056290694203468, -2.1952017044991008, -2.3775010644706356,
      -2.228130946822978, -2.2459304613119073, -2.1070492665763156,
      -2.0407798083149116, -1.7864846103032184, -1.2882109201124683,
      -1.5569000451694195, -1.0509154366966933, -1.2898326727696761,
      -1.1316446842158414, -0.84531458150686456, -0.43615392220202609,
      -0.7402234868324562, -0.81849875976510411, -0.31456063666147527,
      -0.11000301111811295, -0.15410604678194506, 0.13933345400984576,
      0.25710195753370979, 0.6784115855827898, 0.73584373928730562,
      1.0484650248579404, 0.84313287261281478, 1.1627721451487671,
      1.067381035344916, 1.4095131738663238, 1.6002701421775978,
      1.6677313860020393, 2.0635997377592448, 2.2176445968943694,
      2.3001667247566457, 2.5221823818273084, 2.6174646091760265,
      2.7027186397485874, 2.9505435921411691, 3.0338224511075187,
      3.3684979245310163, 3.4887853680509977, 3.3353948618738221,
      3.4503488233748043, 3.69286498482571, 3.8025700044805131,
      3.8256415156002461, 3.9922016254765604, 4.66823940330517,
      4.7048424617462175, 4.7044110096302951, 4.56671055284096,
      4.9498805752791446, 4.8628856964106113, 5.1636312025584719,
      5.5422711713678225, 5.2762844224744212, 5.6641978718844133,
      5.8378522682272349, 5.9020076181111767, 5.7948494785088043,
      6.17089298167547, 6.3636811652627667, 6.5280476820787907,
      6.380212735228584, 6.5326837295041642, 6.7010673685494559,
      7.14463183667314, 6.9712674948116486, 7.4886914073436905,
      7.4202259704119449, 7.2797769048475729, 7.3855223994055414,
      7.7237978204474471, 7.9876463747715816, 7.55841972999252, 8.0885469875644,
      7.8187354911492264, 8.1639667611897941, 8.3932646508656532,
      8.2032926616874491, 8.0474798065462778, 8.70849753530933,
      8.2936300165732852, 8.8924724486287232, 8.72108520267901,
      8.9090342416934725, 8.8749210244719521, 9.30400665873524, 8.93909833258855,
      9.2670132942713739, 9.8530714467968821, 9.3587826553180111,
      9.4496779679707021, 9.8724165021133139, 9.968229316248209,
      9.5228546049822054, 9.8259772192973021, 9.9712845411146986,
      9.8748201144673615, 9.9030493203431771, 9.7761418908169677,
      10.183438288448153, 10.378129638850808, 10.295500078599572,
      10.340523545700155, 10.693282918363559, 10.279995942307044,
      10.226538525795087, 10.457871072110953, 10.246671075227479,
      10.447608449577912, 10.857817104798075, 10.471368252361593,
      10.237653192991528, 10.461844142017265, 10.438029636347421,
      10.762397548444136, 10.72972018825247, 10.748080050430987,
      10.878967031073033, 11.038431792596432, 10.640676678013888,
      10.985327624349123, 10.900602927786135, 10.701695252317515,
      10.935690003374383, 11.088317755373115, 11.133254600878043,
      10.619400611182375, 10.543894708812127, 10.691025800958293,
      10.654777411090029, 10.618895839975206, 10.581323987477825,
      10.615719528708919, 11.047375123793595, 10.733325994294294,
      10.460414077637704, 10.798703600086652, 10.713288990821317,
      10.640154670605225, 10.519378966961069, 10.383547251904851,
      10.331522685990171, 10.211422632847675, 10.189174034539741,
      9.8888658773259, 10.34566711959595, 10.041605970506353, 10.149409094742275,
      9.9398975282689488, 10.018777189809546, 10.072875267531023,
      9.9353826040070121, 9.7768391271377482, 9.414057080792535,
      9.64509082956001, 9.6349022669078259, 9.3790911593771558, 9.22020167328513,
      9.38401651052999, 9.61977163032562, 9.1065158740901566, 9.4992077431840709,
      9.1002858719880848, 8.8955847355318944, 8.7971499448023529,
      8.6877975825770513, 8.6739837578777035, 8.3138578950608348,
      8.3084487966301737, 8.1305167291561418, 8.2318199917004975,
      8.13816148612429, 8.1219574972286281, 7.8869316764484623,
      7.7652423491319329, 7.3704736021730355, 7.8433922432661216,
      7.1227059066620395, 7.7567029505860523, 7.1359028017109507,
      6.9310110841749921, 7.11274066610569, 7.1240550740549073,
      6.9402943324094082, 6.7235222812084166, 6.5054863662355933,
      6.251813335580005, 6.240081936261725, 6.1195331175380066,
      6.0043977718539949, 6.012470343301, 5.6198177779409928, 5.7862375013975367,
      5.4802948516035466, 5.0750453421431247, 5.289505672102413,
      5.2049852296263746, 4.6448359628036773, 4.7239840234780388,
      4.7664159200673355, 4.3396829649557338, 4.3200731088302646,
      4.063451709740538, 3.8217077296837321, 3.8600970008805873,
      3.4347666021753387, 3.5134520227965891, 3.435800222956138,
      3.264409846268026, 3.19982391861554, 2.8514585132691428,
      3.0764402311592671, 2.7244559405294897, 2.8197289199916287,
      2.0013256669524537, 2.0608699954329426, 2.1150133771730353,
      1.7283813216524617, 1.9200486843526599, 1.1716604456006925,
      1.3123983698686281, 1.5016506274881256, 0.94730206844836706,
      1.0625875796528839, 1.0282945887478565, 0.97903250420333632,
      0.47321174870735305, 0.78696742747575543, 0.14523360019766585,
      0.362624697759081, -0.38457729320011791, -0.44400983602892685,
      -0.65738377574576878, -0.94236072036779572, -0.59255202345102354,
      -0.76094421453644356, -0.9357518618648375, -1.1009606139140113,
      -1.6380629108249707, -1.2254323822888304, -1.7480139610845109,
      -1.663948340349334, -1.7873191123685319, -1.9952828606982633,
      -2.0481590152805991, -2.3006122005231169, -2.3818799909288635,
      -2.7539307688368697, -2.9704501491626818, -2.9783370250518257,
      -3.21094375372285, -3.0991427578336923, -3.3765057160754042,
      -3.4176405361090056, -3.5120197327905158, -3.6212101942752914,
      -3.839703728367013, -4.0245294018242577, -4.2196519206945018,
      -4.5489390510772756, -4.3981908392330986, -4.6007278874322965,
      -4.5666431540955594, -4.656193655588873, -4.9833041094377837,
      -5.2137781116194306, -5.0508888749233414, -5.2943526941851458,
      -5.1275558890957091, -5.3211928184465069, -5.6207990741175378,
      -6.0166301527913459, -5.783067187913872, -6.057853072715238,
      -6.1225559096024593, -6.252882963463791, -6.4181657420764822,
      -6.5907465849944886, -6.4646457233820849, -6.600464310129432,
      -6.3851917656685142, -6.8608124405967486, -6.9831964464116414,
      -6.9036980555903433, -6.8741314932280462, -6.8828343858673104,
      -7.2903048854708032, -7.3390642960723209, -7.3104408028325167,
      -7.4480835504879561, -7.6222529426149421, -7.4784424981202839,
      -7.6478755986241875, -7.5968787719651889, -7.8467489516895093,
      -7.7430532268594394, -7.8126418690769039, -8.0476311274987733,
      -8.29634343142116, -8.0415148384850017, -8.189204301413687,
      -8.018432494417933, -8.3263157794675617, -8.2607886465480469,
      -8.3873788797318589, -8.5236161749028039, -8.4666188447940414,
      -8.4200791143020091, -8.58692981661946, -8.6667838230850638,
      -8.490509658428202, -8.79716309500508, -8.9092354252681858,
      -8.6695289908933511, -8.919193972448145, -9.00426025903581,
      -8.7322485613911471, -8.6677607246389972, -8.884718674404839,
      -8.7132499926538536, -9.0399071067896735, -8.8048184315471634,
      -9.0150518936065183, 0.832160948358433, 0.52815080446492368,
      -0.024692166796095982, 0.2056190985861065, -0.53958113307783817,
      -0.5399664731384457, -0.78036762746854937, -1.3031548854818493,
      -1.4460621473454709, -1.351920689697971, -1.8509385643446166,
      -2.3998224755357813, -2.7398533322143295, -2.9455934795335881,
      -3.3473660058253421, -3.3632963377532521, -3.7898301641863981,
      -4.4337726340092072, -4.0141201524937191, -4.4809792373657178,
      -4.6137545771511519, -5.0595989961227827, -5.3468073325277938,
      -5.5905839434245417, -6.1419281607185248, -5.8373204168930908,
      -5.72580711718508, -6.3416372277518978, -6.45667683828227,
      -6.5416060270448426, -6.8819094738892588, -6.9237439268092738,
      -7.0410866334441167, -7.6426804830036978, -7.4952083426920382,
      -7.53687959903397, -7.8665292466564853, -7.9452708805303764,
      -7.9647916024827428, -8.02644682414969, -8.3088348236022238,
      -8.3173856362208447, -8.79573056518386, -8.46721564520407,
      -8.9145628568896154, -8.636118207177315, -8.7242072203466634,
      -8.8687880074784413, -8.7298614403892536, -8.64256264145939,
      -8.7736115571362916, -8.9124900159850355, -8.99930500916454,
      -8.6978838493614781, -8.9482802512609876, -8.85002582702807,
      -8.6302612576521511, -8.9093934269787081, -8.5290705031102689,
      -8.7558877522414953, -8.0137427376193013, -8.2012072772912887,
      -8.07917637568836, -7.98892887925107, -7.6286855758204144,
      -7.7330428235575681, -7.3855210228226156, -7.2943614647568857,
      -7.6472559292351026, -7.1389631385165266, -7.05088207389565,
      -6.4519200648524588, -6.7889616731453328, -6.2748421548528119,
      -6.2306021378046692, -6.1018967713788559, -5.6834809333028486,
      -5.7407998574184509, -5.3875024671381277, -4.7269934124776256,
      -4.8567191517553674, -4.5945941614014485, -4.3549991930761021,
      -3.7567868179561783, -3.3587809412694769, -3.6493158817318232,
      -3.2737886130304865, -2.4853165963525377, -2.6709422948485968,
      -2.6459908957573406, -1.9675537451354224, -1.897582822426306,
      -1.8134826441822574, -1.1167750174501037, -0.74418681991381974,
      -0.717418980358989, -0.54166437343269846, -0.29606715835908348,
      0.61873659312250873, 0.80444896389804121, 1.1732475457741214,
      1.1183212193277352, 1.747747134180262, 1.7166211284870778,
      2.043947317458719, 2.4787224045112479, 2.8230285577759195,
      2.9516346215580818, 3.5194066322422866, 3.743088239745525,
      4.038909088684818, 4.6345673191077035, 4.3459772301788675,
      5.0192391311815916, 5.2034727259681777, 5.3224513845244212,
      5.5618044476649882, 5.6698737149451057, 6.0504697171998316,
      6.1471059350138066, 6.713398743878586, 7.0628798360440062,
      7.3067311445342753, 7.363905103425572, 7.6789665642120895,
      7.8698330233306706, 8.3205242410440317, 8.3221252054313872,
      8.5256618065152736, 8.7977231702094532, 8.9990791415893874,
      8.5012085712553613, 8.9560505255617322, 9.44430384264308,
      9.7661727403490346, 9.61380935664233, 9.9195073177550661,
      9.7398789229321228, 9.7212858572206038, 10.247856779572777,
      10.472536093057593, 10.299093290626951, 10.464331194223567,
      10.492055670092597, 10.698155732867754, 10.748713788970729,
      10.551389408016519, 11.268637500158905, 10.757766229606869,
      10.715636662589638, 10.642848859784324, 10.945716655966072,
      10.777613909821232, 10.772036899504249, 11.032136500394195,
      10.629052752050885, 10.467242075216319, 10.469606794725912,
      10.276369934843029, 10.115290556552063, 10.473128873474918,
      10.454587222049195, 10.183025370374356, 10.333858517260916,
      9.5961597759308841, 9.5017686083300053, 9.7560988491022087,
      9.7893423145635463, 9.30905519146146, 9.1439980577735174,
      9.1428937892115343, 8.8367077056019632, 8.4802420409957442,
      8.2479419074075153, 8.2264858794543141, 7.8439988061672059,
      7.4635467691614306, 7.5188164521150824, 7.3425555388151755,
      7.1166163198959733, 6.9990117811612595, 6.4648425279931638,
      6.3525608566926088, 5.8096686242858668, 6.2006041976589863,
      5.53946311783285, 5.0912978607060557, 4.8000594053051628, 4.73388319682332,
      4.1611637579894438, 4.0021473241305427, 3.6242453125642893,
      3.4177161627125834, 3.3008144292311483, 2.8153158724390086,
      2.6062586625137447, 2.0151662874784275, 2.1533100523481359,
      1.6731621464889352, 1.5277247658481969, 0.92768063559334246,
      0.86453614619262442, 0.390818093162423, 0.3013667415975283,
      -0.14554329218395257, -0.41869298439324654, -0.5840776865225088,
      -1.1705331505544319, -1.3592703703538693, -1.8478266189232029,
      -1.9992309730623332, -2.8743525918045743, -2.7781974353436496,
      -2.8700377306600093, -3.3976653192186097, -3.5512111188030806,
      -3.9168991438974752, -3.9411259688350926, -4.22816865691234,
      -4.4588844662266753, -4.7809768021580048, -5.1926591515492095,
      -5.2690503212826183, -5.7897358035196591, -5.8372674936927469,
      -5.8688098458842495, -6.4331942266539581, -6.3864767499220525,
      -6.2217095214759413, -6.5492533376188549, -6.9205990227247085,
      -7.14848317192965, -7.4700941435744657, -7.4528456884898091,
      -7.5719052802081457, -7.8054702983233337, -7.9223657736810438,
      -8.1291789915244355, -8.014918318772839, -8.04909281347162,
      -8.6630927432689315, -8.37261014317869, -8.3877915394153462,
      -8.820005809057907, -8.6323047810201459, -8.7785633163616019,
      -8.7272969899073534, -8.5023172824580477, -8.6137906793713963,
      -8.4251026006347551, -8.6391555398888062, -8.83821990410594,
      -8.4249131917443361, -8.8552000683614764, -8.8379809821387312,
      -8.8242129675822536, -8.28527893865408, -8.5891638507983,
      -8.5775466767481987, -8.18346631433621, -8.5939732740678885,
      -8.1177937470174939, -8.1335485897338042, -8.1316730051666646,
      -8.0314964704224163, -7.7271826221172937, -7.4185082571534924,
      -7.5112067174697685, -7.44144255608612, -6.9200270040981371,
      -6.919557586740785, -6.4810711059458841, -6.4647323678985371,
      -6.283810946291843, -6.1441786916193593, -5.97796623808142,
      -5.7379963798947138, -5.7883352112322948, -5.3374596546264117,
      -5.4156596587001218, -4.6720060154870184, -4.5835043540025842,
      -4.8087540203563579, -4.1303247650010109, -3.4758715675522174,
      -3.0788544633427568, -3.2115985323106209, -2.7284470904835674,
      -2.6196879159792106, -2.1263428044475008, -2.1413767435652349,
      -1.7224177829847171, -1.5135479992465348, -1.0010105538678067,
      -0.81797598923789927, -0.61809092394854948, -0.39979420692442691,
      -0.23606829478248859, 0.39587434686848977, 0.88751508498014708,
      1.4001542742023796, 1.3985582237926142, 1.4744560298532314,
      1.9275875925200496, 2.322404499890852, 2.3443626079492863,
      2.8651478796306034, 3.0383624243716238, 3.375696824356476,
      3.7517506549716932, 3.9897278819128736, 4.1779867046275809,
      4.4023577188189691, 4.7846253878999985, 5.0179452442096206,
      5.5665018231824552, 5.6553304137116189, 6.11851687616868, 6.37786561760314,
      6.4545008010948282, 6.4025213405172856, 7.1543223339816135,
      7.2891974466000633, 7.5216285059796517, 8.07706177735417,
      7.7045281513330046, 8.445598861363047, 8.17528291332953,
      8.3264455365496985, 8.5466723214446763, 9.0591001207344224,
      8.95753445615103, 9.4157774207033622, 9.4623204445686948, 9.4536380151652,
      9.8719232682949212, 10.053555857215709, 10.246960438736309,
      9.7994620688889835, 10.089500316296101, 10.34662107083175,
      10.204253563468797, 10.72612383435621, 10.558785453101196,
      10.548832017150069, 10.709132909221076, 10.616502446143311,
      10.891784175813589, 10.668376258888379, 10.752027245075894,
      10.908802801086356, 10.705480648390196, 10.621341744137425,
      10.701673152724593, 10.644554636128863, 10.642330430169425,
      10.679159153017771, 10.440124912936676, 10.63218466835432,
      10.545178424083931, 10.263584317132821, 10.288799485045462,
      10.089872938396256, 10.098413996559117, 9.8118830448188419,
      9.8091956323764009, 9.6371737099500034, 9.5318905289210036,
      9.1598808372327181, 8.8493859438898355, 8.9652059453657138,
      8.7948477672088465, 8.2629263057912965, 8.49672319990194, 8.35466950004595,
      7.8426507347903627, 7.54520284496469, 7.3872435716288312,
      7.0827203958593072, 6.9217661031172319, 6.80277236715741,
      6.5012901198941835, 6.47883408400402, 5.8674586236940263,
      5.4974740381634506, 5.4062769823904055, 5.368108648313898,
      5.1016507454567339, 4.3689566307536545, 4.15414189945571,
      4.2380206888477456, 3.9010869077899613, 3.1553732716916616,
      2.8194472264343773, 3.0024214913887746, 2.463957455382336,
      1.9778919214490758, 1.9247049830469773, 1.7981098197794294,
      1.5601558947045835 } ;

    Madgwick_embedded_DW->AccX_PWORK.TimePtr = (void *) pTimeValues0;
    Madgwick_embedded_DW->AccX_PWORK.DataPtr = (void *) pDataValues0;
    Madgwick_embedded_DW->AccX_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/AccY' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06,
      0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18,
      0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31,
      0.32, 0.33, 0.34, 0.35, 0.36, 0.37, 0.38, 0.39, 0.4, 0.41, 0.42, 0.43,
      0.44, 0.45, 0.46, 0.47, 0.48, 0.49, 0.5, 0.51, 0.52, 0.53, 0.54, 0.55,
      0.56, 0.57, 0.58, 0.59, 0.6, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67,
      0.68, 0.69, 0.7, 0.71, 0.72, 0.73, 0.74, 0.75, 0.76, 0.77, 0.78, 0.79, 0.8,
      0.81, 0.82, 0.83, 0.84, 0.85, 0.86, 0.87, 0.88, 0.89, 0.9, 0.91, 0.92,
      0.93, 0.94, 0.95, 0.96, 0.97, 0.98, 0.99, 1.0, 1.01, 1.02, 1.03, 1.04,
      1.05, 1.06, 1.07, 1.08, 1.09, 1.1, 1.11, 1.12, 1.13, 1.14, 1.15, 1.16,
      1.17, 1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28,
      1.29, 1.3, 1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37, 1.38, 1.39, 1.4, 1.41,
      1.42, 1.43, 1.44, 1.45, 1.46, 1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53,
      1.54, 1.55, 1.56, 1.57, 1.58, 1.59, 1.6, 1.61, 1.62, 1.63, 1.64, 1.65,
      1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75, 1.76, 1.77,
      1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.85, 1.86, 1.87, 1.88, 1.89, 1.9,
      1.91, 1.92, 1.93, 1.94, 1.95, 1.96, 1.97, 1.98, 1.99, 2.0, 2.01, 2.02,
      2.03, 2.04, 2.05, 2.06, 2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14,
      2.15, 2.16, 2.17, 2.18, 2.19, 2.2, 2.21, 2.22, 2.23, 2.24, 2.25, 2.26,
      2.27, 2.28, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34, 2.35, 2.36, 2.37, 2.38,
      2.39, 2.4, 2.41, 2.42, 2.43, 2.44, 2.45, 2.46, 2.47, 2.48, 2.49, 2.5, 2.51,
      2.52, 2.53, 2.54, 2.55, 2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63,
      2.64, 2.65, 2.66, 2.67, 2.68, 2.69, 2.7, 2.71, 2.72, 2.73, 2.74, 2.75,
      2.76, 2.77, 2.78, 2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87,
      2.88, 2.89, 2.9, 2.91, 2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0,
      3.01, 3.02, 3.03, 3.04, 3.05, 3.06, 3.07, 3.08, 3.09, 3.1, 3.11, 3.12,
      3.13, 3.14, 3.15, 3.16, 3.17, 3.18, 3.19, 3.2, 3.21, 3.22, 3.23, 3.24,
      3.25, 3.26, 3.27, 3.28, 3.29, 3.3, 3.31, 3.32, 3.33, 3.34, 3.35, 3.36,
      3.37, 3.38, 3.39, 3.4, 3.41, 3.42, 3.43, 3.44, 3.45, 3.46, 3.47, 3.48,
      3.49, 3.5, 3.51, 3.52, 3.53, 3.54, 3.55, 3.56, 3.57, 3.58, 3.59, 3.6, 3.61,
      3.62, 3.63, 3.64, 3.65, 3.66, 3.67, 3.68, 3.69, 3.7, 3.71, 3.72, 3.73,
      3.74, 3.75, 3.76, 3.77, 3.78, 3.79, 3.8, 3.81, 3.82, 3.83, 3.84, 3.85,
      3.86, 3.87, 3.88, 3.89, 3.9, 3.91, 3.92, 3.93, 3.94, 3.95, 3.96, 3.97,
      3.98, 3.99, 4.0, 4.01, 4.02, 4.03, 4.04, 4.05, 4.06, 4.07, 4.08, 4.09, 4.1,
      4.11, 4.12, 4.13, 4.14, 4.15, 4.16, 4.17, 4.18, 4.19, 4.2, 4.21, 4.22,
      4.23, 4.24, 4.25, 4.26, 4.27, 4.28, 4.29, 4.3, 4.31, 4.32, 4.33, 4.34,
      4.35, 4.36, 4.37, 4.38, 4.39, 4.4, 4.41, 4.42, 4.43, 4.44, 4.45, 4.46,
      4.47, 4.48, 4.49, 4.5, 4.51, 4.52, 4.53, 4.54, 4.55, 4.56, 4.57, 4.58,
      4.59, 4.6, 4.61, 4.62, 4.63, 4.64, 4.65, 4.66, 4.67, 4.68, 4.69, 4.7, 4.71,
      4.72, 4.73, 4.74, 4.75, 4.76, 4.77, 4.78, 4.79, 4.8, 4.81, 4.82, 4.83,
      4.84, 4.85, 4.86, 4.87, 4.88, 4.89, 4.9, 4.91, 4.92, 4.93, 4.94, 4.95,
      4.96, 4.97, 4.98, 4.99, 5.0, 5.01, 5.02, 5.03, 5.04, 5.05, 5.06, 5.07,
      5.08, 5.09, 5.1, 5.11, 5.12, 5.13, 5.14, 5.15, 5.16, 5.17, 5.18, 5.19, 5.2,
      5.21, 5.22, 5.23, 5.24, 5.25, 5.26, 5.27, 5.28, 5.29, 5.3, 5.31, 5.32,
      5.33, 5.34, 5.35, 5.36, 5.37, 5.38, 5.39, 5.4, 5.41, 5.42, 5.43, 5.44,
      5.45, 5.46, 5.47, 5.48, 5.49, 5.5, 5.51, 5.52, 5.53, 5.54, 5.55, 5.56,
      5.57, 5.58, 5.59, 5.6, 5.61, 5.62, 5.63, 5.64, 5.65, 5.66, 5.67, 5.68,
      5.69, 5.7, 5.71, 5.72, 5.73, 5.74, 5.75, 5.76, 5.77, 5.78, 5.79, 5.8, 5.81,
      5.82, 5.83, 5.84, 5.85, 5.86, 5.87, 5.88, 5.89, 5.9, 5.91, 5.92, 5.93,
      5.94, 5.95, 5.96, 5.97, 5.98, 5.99, 6.0, 6.01, 6.02, 6.03, 6.04, 6.05,
      6.06, 6.07, 6.08, 6.09, 6.1, 6.11, 6.12, 6.13, 6.14, 6.15, 6.16, 6.17,
      6.18, 6.19, 6.2, 6.21, 6.22, 6.23, 6.24, 6.25, 6.26, 6.27, 6.28, 6.29, 6.3,
      6.31, 6.32, 6.33, 6.34, 6.35, 6.36, 6.37, 6.38, 6.39, 6.4, 6.41, 6.42,
      6.43, 6.44, 6.45, 6.46, 6.47, 6.48, 6.49, 6.5, 6.51, 6.52, 6.53, 6.54,
      6.55, 6.56, 6.57, 6.58, 6.59, 6.6, 6.61, 6.62, 6.63, 6.64, 6.65, 6.66,
      6.67, 6.68, 6.69, 6.7, 6.71, 6.72, 6.73, 6.74, 6.75, 6.76, 6.77, 6.78,
      6.79, 6.8, 6.81, 6.82, 6.83, 6.84, 6.85, 6.86, 6.87, 6.88, 6.89, 6.9, 6.91,
      6.92, 6.93, 6.94, 6.95, 6.96, 6.97, 6.98, 6.99, 7.0, 7.01, 7.02, 7.03,
      7.04, 7.05, 7.06, 7.07, 7.08, 7.09, 7.1, 7.11, 7.12, 7.13, 7.14, 7.15,
      7.16, 7.17, 7.18, 7.19, 7.2, 7.21, 7.22, 7.23, 7.24, 7.25, 7.26, 7.27,
      7.28, 7.29, 7.3, 7.31, 7.32, 7.33, 7.34, 7.35, 7.36, 7.37, 7.38, 7.39, 7.4,
      7.41, 7.42, 7.43, 7.44, 7.45, 7.46, 7.47, 7.48, 7.49, 7.5, 7.51, 7.52,
      7.53, 7.54, 7.55, 7.56, 7.57, 7.58, 7.59, 7.6, 7.61, 7.62, 7.63, 7.64,
      7.65, 7.66, 7.67, 7.68, 7.69, 7.7, 7.71, 7.72, 7.73, 7.74, 7.75, 7.76,
      7.77, 7.78, 7.79, 7.8, 7.81, 7.82, 7.83, 7.84, 7.85, 7.86, 7.87, 7.88,
      7.89, 7.9, 7.91, 7.92, 7.93, 7.94, 7.95, 7.96, 7.97, 7.98, 7.99, 8.0, 8.01,
      8.02, 8.03, 8.04, 8.05, 8.06, 8.07, 8.08, 8.09, 8.1, 8.11, 8.12, 8.13,
      8.14, 8.15, 8.16, 8.17, 8.18, 8.19, 8.2, 8.21, 8.22, 8.23, 8.24, 8.25,
      8.26, 8.27, 8.28, 8.29, 8.3, 8.31, 8.32, 8.33, 8.34, 8.35, 8.36, 8.37,
      8.38, 8.39, 8.4, 8.41, 8.42, 8.43, 8.44, 8.45, 8.46, 8.47, 8.48, 8.49, 8.5,
      8.51, 8.52, 8.53, 8.54, 8.55, 8.56, 8.57, 8.58, 8.59, 8.6, 8.61, 8.62,
      8.63, 8.64, 8.65, 8.66, 8.67, 8.68, 8.69, 8.7, 8.71, 8.72, 8.73, 8.74,
      8.75, 8.76, 8.77, 8.78, 8.79, 8.8, 8.81, 8.82, 8.83, 8.84, 8.85, 8.86,
      8.87, 8.88, 8.89, 8.9, 8.91, 8.92, 8.93, 8.94, 8.95, 8.96, 8.97, 8.98,
      8.99, 9.0, 9.01, 9.02, 9.03, 9.04, 9.05, 9.06, 9.07, 9.08, 9.09, 9.1, 9.11,
      9.12, 9.13, 9.14, 9.15, 9.16, 9.17, 9.18, 9.19, 9.2, 9.21, 9.22, 9.23,
      9.24, 9.25, 9.26, 9.27, 9.28, 9.29, 9.3, 9.31, 9.32, 9.33, 9.34, 9.35,
      9.36, 9.37, 9.38, 9.39, 9.4, 9.41, 9.42, 9.43, 9.44, 9.45, 9.46, 9.47,
      9.48, 9.49, 9.5, 9.51, 9.52, 9.53, 9.54, 9.55, 9.56, 9.57, 9.58, 9.59, 9.6,
      9.61, 9.62, 9.63, 9.64, 9.65, 9.66, 9.67, 9.68, 9.69, 9.7, 9.71, 9.72,
      9.73, 9.74, 9.75, 9.76, 9.77, 9.78, 9.79, 9.8, 9.81, 9.82, 9.83, 9.84,
      9.85, 9.86, 9.87, 9.88, 9.89, 9.9, 9.91, 9.92, 9.93, 9.94, 9.95, 9.96,
      9.97, 9.98, 9.99, 10.0, 10.01, 10.02, 10.03, 10.04, 10.05, 10.06, 10.07,
      10.08, 10.09, 10.1, 10.11, 10.12, 10.13, 10.14, 10.15, 10.16, 10.17, 10.18,
      10.19, 10.2, 10.21, 10.22, 10.23, 10.24, 10.25, 10.26, 10.27, 10.28, 10.29,
      10.3, 10.31, 10.32, 10.33, 10.34, 10.35, 10.36, 10.37, 10.38, 10.39, 10.4,
      10.41, 10.42, 10.43, 10.44, 10.45, 10.46, 10.47, 10.48, 10.49, 10.5, 10.51,
      10.52, 10.53, 10.54, 10.55, 10.56, 10.57, 10.58, 10.59, 10.6, 10.61, 10.62,
      10.63, 10.64, 10.65, 10.66, 10.67, 10.68, 10.69, 10.7, 10.71, 10.72, 10.73,
      10.74, 10.75, 10.76, 10.77, 10.78, 10.79, 10.8, 10.81, 10.82, 10.83, 10.84,
      10.85, 10.86, 10.87, 10.88, 10.89, 10.9, 10.91, 10.92, 10.93, 10.94, 10.95,
      10.96, 10.97, 10.98, 10.99, 11.0, 11.01, 11.02, 11.03, 11.04, 11.05, 11.06,
      11.07, 11.08, 11.09, 11.1, 11.11, 11.12, 11.13, 11.14, 11.15, 11.16, 11.17,
      11.18, 11.19, 11.2, 11.21, 11.22, 11.23, 11.24, 11.25, 11.26, 11.27, 11.28,
      11.29, 11.3, 11.31, 11.32, 11.33, 11.34, 11.35, 11.36, 11.37, 11.38, 11.39,
      11.4, 11.41, 11.42, 11.43, 11.44, 11.45, 11.46, 11.47, 11.48, 11.49, 11.5,
      11.51, 11.52, 11.53, 11.54, 11.55, 11.56, 11.57, 11.58, 11.59, 11.6, 11.61,
      11.62, 11.63, 11.64, 11.65, 11.66, 11.67, 11.68, 11.69, 11.7, 11.71, 11.72,
      11.73, 11.74, 11.75, 11.76, 11.77, 11.78, 11.79, 11.8, 11.81, 11.82, 11.83,
      11.84, 11.85, 11.86, 11.87, 11.88, 11.89, 11.9, 11.91, 11.92, 11.93, 11.94,
      11.95, 11.96, 11.97, 11.98, 11.99 } ;

    static real_T pDataValues0[] = { 0.61973124415648417, 1.0927139067752667,
      0.69496330893578251, 0.38491110852870192, 0.43491819793284991,
      0.31266322659891166, 0.0030051575256153651, 0.08900954986595111,
      -0.21809227098674255, -0.19001121612140515, -0.34159481014939641,
      -0.6649903693498278, -0.53174621922999465, -0.90881811283757452,
      -1.2549853276619962, -1.2152210302362292, -1.5235919289974813,
      -1.5663741606496395, -1.7960192959377013, -1.8553807870057706,
      -1.7838465485908328, -1.9225778210703832, -2.1558904108215229,
      -2.411092105963264, -2.7656228916561174, -2.7770763985891342,
      -2.9357204442679281, -2.9722221769762309, -3.2165145310082242,
      -3.2669699696140544, -3.2448836708002116, -3.276822129651821,
      -3.6309249518705871, -4.0554325227647041, -4.1885884089018113,
      -4.1661890937813348, -4.1530914279574951, -4.293125697827838,
      -4.4472203959757426, -4.8475293986138555, -4.9803813018809553,
      -4.6781264094844817, -5.0096294990926546, -5.1510171239704237,
      -5.4866818983703824, -5.2476276536447388, -5.4813058734650681,
      -5.6321692284205955, -5.4823683364193014, -5.9281975263352749,
      -6.1467766344142358, -6.054719349772836, -5.6102767693905626,
      -6.2389000578509037, -6.5137700786627288, -6.58849148848839,
      -6.5113192899999861, -6.5085467478888974, -6.9670761903214906,
      -6.74109849829489, -6.9976067812176961, -6.8881276999724674,
      -7.0722836128134272, -7.1473905951081189, -7.0234540077314005,
      -7.3541566565453547, -7.7110670772092842, -7.2108450154190287,
      -7.53171025291393, -7.5912915167635, -7.6361663465209091,
      -7.7963588278005638, -8.1799531511598964, -7.8984316986275829,
      -8.1638076477186114, -7.8639902019966321, -8.2814658574953945,
      -7.9262737921272564, -8.276139275218954, -8.600553118702031,
      -8.3260381978143041, -8.1247179514803953, -8.3140471705773287,
      -8.6123902859795969, -8.3978075038076661, -9.0130955153882528,
      -8.1415864486620872, -8.4192222816421065, -8.2527679587764879,
      -8.9234415005636833, -8.5961050180977665, -8.5509661085880815,
      -8.8816497906802852, -8.8459050585088868, -9.1374797942769312,
      -8.6454911277759567, -9.0428235904172851, -8.5536770178589432,
      -8.7555258481822982, -8.985656605377363, -8.6999629830632461,
      -8.8243933689330856, -8.73199071085748, -8.6309072690725728,
      -8.615088605006342, -8.6999437837762539, -8.7271831553290724,
      -8.4985772218974578, -8.385520050061162, -8.6190685148429917,
      -8.2789885256450564, -8.8814810810584213, -8.8821737941180245,
      -8.3364398447393775, -8.5653913005314664, -8.7459822285507354,
      -8.5316395355246968, -8.5283581078374286, -8.4817285203871347,
      -8.3015363431239688, -8.3029605584641075, -8.4606151207689937,
      -8.3541938952086863, -8.0737111908917658, -7.7760241670334178,
      -7.8696438096087906, -8.1111264698892178, -7.9431378628551919,
      -7.791002147860091, -8.0057872812199271, -7.7819487461738639,
      -7.745753964232625, -7.53370391364577, -7.4641693941910141,
      -7.3135612779488373, -7.4723917710788132, -7.3087417878047294,
      -7.2914283663107611, -7.0460384702294352, -6.9551857155880823,
      -6.99243457865152, -6.4560321403697367, -7.035627751616115,
      -6.9260350069336942, -6.8337906817370175, -6.4393343502027323,
      -6.4825071162140189, -6.4651813804768317, -6.0989237822358762,
      -6.2149376491137591, -6.0791365703023352, -5.8265637261788834,
      -5.69329848051307, -5.729666878679045, -5.7360721344059824,
      -5.611089104392974, -5.0117493817022476, -5.2576632358166284,
      -5.0099507240998493, -5.0284931821790826, -4.6253187367888193,
      -4.6074720478914148, -4.292171528158133, -4.1915939334267209,
      -4.0729775082152857, -3.9793035941381918, -4.2634214488721041,
      -3.9346243229423372, -3.8126169301007895, -3.4264261120195387,
      -3.4812112910578037, -3.463482805497641, -3.0393689331317058,
      -3.2153414251123156, -2.9626629720932742, -2.9810402255402355,
      -2.4767675289924798, -2.5291158687633946, -2.4358309179490854,
      -2.2346672434918924, -2.1297056491019326, -1.9066040372481066,
      -1.7635749130551126, -1.2491652526711818, -1.2143314956348941,
      -1.3099081168514606, -1.1531978338148079, -1.0568041448456413,
      -0.84054396430646272, -0.48088172278693797, -0.675756900513732,
      -0.36580515675143666, -0.29534431087940316, -0.16347590492153619,
      0.26889020093757909, 0.42781948954528504, 0.51090699992921418,
      0.4229846050518784, 0.84769087030576074, 0.86107935946807734,
      0.98921784658403078, 1.0838427616166018, 1.0627863679499099,
      1.3702856516270068, 1.5251569004026682, 2.0412075838033621,
      1.4487474519121832, 1.8447047684098141, 2.3472126592271154,
      2.0356259965570871, 2.8429832924768537, 2.7116741676585958,
      3.0086129027077497, 2.9952226036927581, 3.4837586223627643,
      3.2144050488383376, 3.3918419516517249, 3.6366657030232337,
      3.8887519338648522, 4.1268056546931327, 4.2229034834594925,
      4.0041489314030629, 4.4214352036623819, 4.45972731613083,
      4.578236997583331, 4.9257116920133779, 4.8987251099578053,
      5.1180965692276024, 5.3311708286118931, 5.3817418448925993,
      5.2011948019997529, 5.7370359085864369, 5.633814626627399,
      5.8168595169783677, 6.0905516554097936, 5.9319843640196765,
      6.0870975680425605, 6.462695689394848, 6.5603470874216576,
      6.4544624752045632, 6.965340662988841, 6.9494126912792114,
      7.1663746419164553, 7.1887236635022607, 7.3338967612037571,
      7.3830952083074726, 7.340222632813302, 7.747534261651003,
      8.0680250534019642, 7.8148684818507013, 8.07909868119325, 7.82992879803279,
      8.1463990351676436, 8.3774967262976041, 8.3525271236222,
      8.4533389100318761, 8.39675230429948, 8.4104980726587684,
      8.874377721029461, 8.7351036057455964, 8.5988324487491568,
      8.9693667345356651, 9.148682066591574, 9.5003608404011821,
      9.3358442335554379, 9.17235615090801, 9.357722788982052,
      9.1168873165652986, 9.5843272915937732, 9.8534344518922481,
      9.9593368692224153, 9.6742983931463051, 9.7965943284992587,
      10.136618504789741, 10.150343869406228, 10.122342012421434,
      10.297417710006199, 10.252300449933637, 10.280610197504506,
      10.534620807198939, 10.050652735375703, 10.005706490825808,
      10.539615966676847, 10.506705101343455, 10.457205633686225,
      10.58796846673305, 10.306257824575955, 10.730035882345414,
      10.573221687131115, 10.885057971485123, 10.782366830038233,
      10.7830094965826, 10.570883743664531, 10.668613395027419,
      10.474094236633629, 10.577272357638106, 10.903564135968319,
      10.597442674041087, 10.954792587345235, 11.052931313568557,
      10.974399279936943, 10.548012033136766, 11.095912382868807,
      10.678607643440245, 10.516910976321403, 10.632161678472412,
      10.819295937489516, 10.840145498723388, 10.850254233433366,
      10.67012205364172, 10.754595395387124, 10.627712121953108,
      10.711465270442865, 10.583132078833078, 10.481068125291863,
      10.521419273198347, 10.570917205037926, 10.772409288075597,
      10.482433946387667, 10.160556547977611, 10.353581201007163,
      10.349073065370632, 10.353571389347536, 10.057189580860788,
      9.976032025654737, 10.201209198469341, 9.8088158273977815,
      9.913575313984472, 9.9257126193114544, 9.9751400813527642,
      9.8055522040086736, 9.44696829076557, 9.3866172650060573,
      9.6222280774040936, 9.3329813673882782, 9.4306859768426374,
      9.4242072045902656, 9.3214264895000163, 9.3504925398072878,
      8.79758895753268, 9.23207656022593, 8.6789146507702863, 8.7476777132473149,
      8.6856312547612085, 8.83879457639404, 8.5413616860679333,
      8.3441827002029232, 7.97268436047137, 8.0653053688926732,
      8.2700135289246326, 7.97314493590778, 7.5543882143326755,
      7.8096529220338793, 7.7157814418220285, 7.576027845440529,
      6.9867999378107832, 7.2504136763995044, 7.20231421263584,
      6.8260113774677329, 6.7593030681027058, 6.6217844573304578,
      6.293075722661122, 6.49439955490669, 6.6080570973468395,
      6.1782771162497081, 6.0565400536206759, 6.123903997279907,
      6.1517355343696272, 5.9390633528946539, 5.3377459041645787,
      5.0904957236744215, 5.453348334752067, 5.1894348656371143,
      4.851423227809132, 5.0852056700435657, 4.82722044405226,
      4.3589075371311043, 4.6669681873176607, 4.4779975454684458,
      4.120102520392158, 4.3732467081517648, 3.6135575977503169,
      3.701731541437054, 3.6098342334138356, 3.482885353211818,
      2.9730127427841588, 2.778540934065389, 2.7724861257206785,
      2.8577831499486672, 2.704839678352287, 2.6842750509197115,
      2.6757451787886009, 2.0082675298597774, 2.0681896748334188,
      2.1329536899225494, 1.7161318797056859, 1.4743616057623645,
      1.3055117514604984, 1.4246475581557254, 1.3674310044442319,
      0.70725370442760882, 0.88461093607677388, 0.75735863361532985,
      0.6520091252692084, 0.26399695652699318, 0.6912995397072188,
      0.091758757955606951, -0.039135417020334851, -0.44580344179582032,
      -0.37935554055033394, -0.33979842331549315, -0.62640951824150637,
      -1.0295753709173296, -0.98136876636015313, -0.89584197651253006,
      -1.6519661445305691, -1.4808326792580235, -1.5599272362800787,
      -1.84788331687718, -1.7278352618358137, -2.0519611573111511,
      -1.9033149359066384, -2.3151159500634697, -2.2530569941442229,
      -2.7754994223649772, -2.7394631427746603, -2.8188285136044238,
      -3.2500847019755774, -3.388560034455443, -3.5972083910814305,
      -2.7364826659391577, -3.5964559038352437, -3.8043015428187035,
      -3.7388102039493782, -3.9993841901708223, -4.0859379465131811,
      -4.4705813100310463, -4.4270063246097093, -4.6779445319774675,
      -4.6127678030652062, -4.8438817142249819, -5.0195232555387008,
      -5.0869607451063539, -4.956776580809966, -5.1435387635500147,
      -5.4588946456676011, -5.4118256677832655, -5.6715481732014155,
      -5.7560554405807052, -5.9286369010775779, -5.9805581419302474,
      -6.3074395984844225, -6.2990607682574682, -6.4258541354833794,
      -6.57992641201948, -6.315405625094038, -6.5603424205860028,
      -6.9954398280614205, -6.8941721691634417, -6.9921871988994209,
      -6.7279278049026612, -6.9315968422199772, -6.8855661483468076,
      -7.3872270330493173, -7.3032295875497155, -7.568935072108335,
      -7.2491175928093075, -7.5951963162251062, -7.4789938510262,
      -7.5475599628867052, -7.82559230226318, -7.6722601480937733,
      -7.8996643139785174, -7.9801369119585246, -8.2137729229568013,
      -8.3622425095341075, -7.9627273467545567, -8.3045098482077311,
      -8.7007726192624162, -8.3445742398033449, -8.4514460155412561,
      -8.46155302718836, -8.4793203177847, -8.4939523257901985,
      -8.8398717690676474, -8.1414647955740662, -8.8843073009073485,
      -8.5929292017309731, -8.61717158531343, -8.9658821487200111,
      -8.8879960930442774, -8.77435503933395, -8.7615909780798855,
      -8.3951577233123746, -8.6365292793817368, -8.4327464877565177,
      -9.0412955523230476, -8.8308935173694376, -9.007372108987779,
      -8.8303932763387749, -8.942686552352475, -8.8376978906853765,
      -8.8829084844594437, -8.77551285981416, -8.69249286588921,
      -8.6018507244816966, -8.8288075863702318, -8.5502480192043073,
      -8.9263573734155557, -8.7691778638621347, -8.61303230769635,
      -8.4078190101127177, -8.7336778762316261, -8.7525427387932844,
      -8.37804483526663, -8.43115462915446, -8.4403802846954861,
      -8.3324241739209448, -8.14074216421997, -8.424216623431338,
      -8.3480181105241087, -8.3737078510544016, -8.2316147199201719,
      -8.29435463912221, -8.2585557778308285, -8.17842958237515,
      -8.1532519925758216, -7.6180941634973927, -7.7587873759678629,
      -7.8858957732013479, -7.9001284592508281, -7.7123011061956053,
      -7.409824958905693, -7.7275283751526409, -7.5603780707670847,
      -7.1583094904795992, -7.1930604115685064, -7.5250021610078193,
      -7.3550457678888339, -7.0732115982309818, -7.0367616280335046,
      -7.0876861543507683, -6.7534541630309119, -6.6607665913860421,
      -6.5198396061585342, -6.3176637540461389, -6.55581836002567,
      -6.4254147033192819, -5.9781916444454462, -6.0395677047622671,
      -6.0601011401690821, -6.0205257028490085, -5.6019938420449495,
      -5.6437043417457362, -5.4738112070566443, -5.5319034852799795,
      -4.9519618052953041, -4.9528058794501728, -4.9897743822662237,
      -4.8311811826354623, -4.6458765105048911, -4.4284935048664931,
      -4.77720869474955, -4.6544986075519343, -4.3719361156153536,
      -4.111843240961071, -3.9720639326067237, -4.005263543577092,
      -3.9915447479070183, -3.4579779715731593, -3.5225705731041508,
      -3.30605811761954, -3.1114923473094596, -2.7862111495705228,
      -3.2456253058006643, -2.7703754027566605, -2.622020508150384,
      -2.525925194148229, -2.3272351344832911, -1.9586286003770899,
      -2.2993550400698468, -2.2316223644078947, -1.6673650135400169,
      -1.956035222844323, -1.4901913439678078, -1.4331364859354863,
      -0.76867812795894452, -0.9369182870283157, -0.84782783476572554,
      -0.606284564463238, -0.74139940890647837, -0.46770680987109348,
      -0.37318720550618378, 0.028082490357575818, -0.067110905121188669,
      0.17741438405839061, 0.11834478190806663, 0.75912547995396806,
      0.87861023208784461, 0.55871104552911421, 0.9344030649757914,
      1.0649373964959461, 1.3474224691774641, 1.5270902994992088,
      1.4039050340310166, 1.7389990890173668, 1.8171395960815726,
      2.2468483134610837, 2.180997079404503, 2.3341076513139889,
      2.173701238034921, 2.8212163639503043, 2.8361374864192035,
      2.8847184124712779, 3.218963808542481, 3.4567413758173204,
      3.7264941959932032, 3.7767523126329094, 3.6375289955941508,
      4.0467971757550112, 4.0010317614490338, 3.8661175247137716,
      4.2355759825653028, 4.22403145039217, 4.9753618841539744,
      5.2372131814903859, 5.0159678806155235, 4.7969590660945176,
      5.2541965292206054, 5.1143761857537582, 5.6207638637022672,
      5.69628896557097, 5.5565160380378051, 5.6584959962912835,
      5.8575893809214055, 6.1448850934853816, 6.4794412904861121,
      6.7591540661531342, 6.4491442801468883, 6.4740653389589129,
      6.6623406520731567, 6.958571067048771, 6.9966593239943791,
      6.7242396256572414, 7.2753432674564991, 7.3946920189174214,
      7.72519773469778, 7.589467396605369, 8.2287675942700034,
      7.9321747852964064, 7.9516257292842427, 8.0609707637182026,
      8.21422185475345, 8.39302936881861, 8.2036466908230459, 8.4394057076717424,
      8.57270023528418, 9.14449116779268, 8.4553425778471123, 8.8727802948558967,
      8.9701320760006382, 8.7653366365041059, 9.12125869569093,
      8.9642915079693228, 9.1931102693096935, 9.5319453849515234,
      9.3513700357282339, 9.5433219223447914, 9.8353653420760363,
      9.6582911403276519, 9.8522483646320076, 9.8891031618669754,
      9.8644307162361216, 10.037561161905996, 10.081764299703032,
      10.003342332124843, 10.100650353050314, 9.9297395954779049,
      10.308445869818634, 9.8363382057434539, 10.403249948398415,
      10.235714809245124, 10.422640803021176, 10.445095600384469,
      10.698974683364593, 10.568565489807069, 10.656956549517467,
      10.585824487703286, 10.551251876931614, 10.697858634676184,
      10.998528652175427, 11.022132710907018, 10.763465809005194,
      10.762716421094849, 10.802195195188812, 10.459500945140951,
      10.565922473491302, 10.838550221400556, 10.824538294092662,
      10.922306442538089, 10.577992462878855, 10.494275291087597,
      10.895994282013975, 10.703362174779869, 10.752468097246464,
      10.509464258811541, 10.720011960923676, 10.589832458494159,
      11.082736318187205, 10.826552381830441, 10.675843409910874,
      10.399036239192361, 10.773170597532367, 10.778734962102725,
      10.920206802864257, 10.82443459584783, 10.201242409745465,
      10.324721339429518, 10.618278575518026, 10.350656637429845,
      10.60253857842102, 10.14337614920826, 10.158695468851906,
      10.246215071100531, 10.167382445759678, 10.102790522430846,
      9.868001690656639, 9.6563428546672885, 9.7804073232948809,
      10.06249939847093, 9.8031810346175412, 9.7275801113574047,
      9.4090479122915944, 9.5281844169706762, 9.3114950486464139,
      9.129163720156507, 9.428928911768482, 9.43096966910501, 8.8717646245109165,
      9.07156259395821, 8.6099503230072312, 8.9732381069027962,
      8.7630339029479867, 8.6790864658007543, 8.6247263791374351,
      8.5431723068121066, 8.5131613477763253, 8.32342002707977,
      7.7534997671889716, 7.9365502072245269, 7.8088005923723092,
      7.8396349633850715, 7.9636047602769144, 7.6275091381941262,
      7.5837286825548, 7.0556239102108131, 7.3986385190580606,
      6.9299554522592013, 7.1365710108720588, 7.0661944692527427,
      6.7536571995573293, 7.0213879175287754, 6.5266650387031833,
      6.2478581638299238, 6.152643087532752, 5.847030659068877, 5.9135328565017,
      6.06435696633795, 5.5302394530287664, 5.6818243037866942,
      5.1882563649613394, 5.2368374232240793, 5.0873838724092826,
      5.0977301680587184, 4.9172974348951808, 4.7618559761426971,
      4.2367521141532052, 4.74039769895528, 4.0731497799170224, 4.29111022102726,
      4.3619761770801251, 3.7169164936433612, 3.8582956122173013,
      3.7488079838653015, 3.6300094906931428, 3.3971001314627842,
      3.2963778991928465, 3.229929446344058, 2.7891325109562888,
      2.354767882615735, 2.4453764086008549, 2.3963376222642534,
      2.4766515487249112, 2.0953352158470455, 2.2552397193977942,
      1.4895407412210286, 1.7200351036635322, 1.6740180116729473,
      1.6579884853663047, 0.88516545574240157, 10.697319278644875,
      10.617139414895689, 11.052098486253861, 10.667497711941865,
      10.956765940896307, 10.476365356171605, 10.732717666551554,
      10.368087521575028, 10.567829986991086, 10.311453179792931,
      9.9491784998756287, 10.197091478912009, 9.99826562702713,
      10.035144028211912, 9.7412012142348, 9.8243363718455647, 9.49934071101852,
      9.1937465378237135, 9.5256733677629768, 8.5857616956199188,
      8.95288347965007, 8.4193301540485876, 8.4080656734665951, 8.45170620937257,
      8.227991042561591, 8.0088564286882349, 7.7285370468015842,
      7.7644987035437341, 7.3073808070972941, 7.0171095022335166,
      6.7205434399746329, 6.5383971161311605, 6.2502342577987822,
      6.0175930444096482, 5.9713230030977726, 5.6019362553955956,
      4.5445004457255518, 4.962153221648947, 4.3867662620878747,
      4.3751770735449682, 4.10944955469312, 3.9148318677233402,
      3.4678036140425825, 2.92317945560551, 2.9463652960897972,
      2.7226448873082019, 2.4681041019856527, 1.8894625016198563,
      1.6180776149687215, 1.3831158062028579, 1.1681483833253763,
      0.88282824936082849, 0.60175017910607065, -0.13784397238610846,
      -0.046859786750729215, -0.47387712289738571, -0.724849478424801,
      -1.5859992580329614, -1.339352177497231, -1.6924963065523508,
      -2.0699082037408032, -2.4144426822275804, -2.639253147523188,
      -2.8415751799020574, -3.3297996676921109, -3.6913340967102712,
      -3.4835159001199036, -4.1299123389707235, -4.3749857525825915,
      -4.7249886462244035, -4.7648985451197516, -5.06117757004886,
      -4.9764254305717124, -5.5598771168403731, -5.84660648906768,
      -6.2729889986817975, -6.1766807629014409, -6.243660797898209,
      -6.4417697804878191, -6.7652299792519361, -7.0122683165137047,
      -7.0653545086293406, -7.2381192090274542, -7.6112800633264328,
      -7.7054094580838246, -7.6831839941698963, -7.9883325469829352,
      -8.0789502618940574, -8.1777367076409444, -8.2029744545174754,
      -8.2342695604447211, -8.39053554682372, -8.24795856423534,
      -8.3733827722448577, -8.3775910042834063, -8.79704299881554,
      -8.4543496399082869, -8.5436338431442156, -8.96982636588357,
      -8.97078804165095, -8.8159770729950448, -9.0298078536209463,
      -8.6270712860412875, -8.8889349410268235, -9.0356871346661549,
      -8.743459744921001, -8.6254082630851077, -8.8870072169241521,
      -8.4796451735933314, -8.3489352048486385, -8.5277983947837,
      -8.2514338089285513, -8.1217808867269241, -7.9502984517009008,
      -7.5843985559383622, -7.6189955761959993, -7.6072041140247926,
      -7.63694102101697, -7.4029421537918818, -7.0450141684850571,
      -6.8126630429731669, -6.5314152853888876, -6.62792803628086,
      -6.3252032968687262, -5.98196936954357, -5.7489516065400537,
      -5.5756149922722864, -5.3070191294402527, -5.3015412588636126,
      -4.8930301181274025, -4.7219275198254191, -4.6558630392600291,
      -4.3075224358448585, -3.8230965246701905, -4.0029924986436694,
      -3.5432597443152662, -3.1475486044548306, -3.0589266746250141,
      -2.677075845573786, -2.3220445760420172, -2.1646766673442506,
      -1.5935349483811194, -1.3782835349317515, -1.4432749793787436,
      -0.62373994873159555, -0.25414846107323363, -0.045615176459850248,
      0.13193899549284371, 0.96977851459842723, 0.60241038447582684,
      1.1118742253491942, 1.3974176136198528, 1.7878322609914012,
      2.0683980909499504, 2.3317575420450476, 2.4056225509205507,
      2.8915173666935328, 3.0327264673468721, 3.6112078663127565,
      3.5131345370618048, 3.9491807404819221, 4.2036017518337747,
      4.5403589755188856, 4.8535699445364164, 5.1545793995392017,
      5.4222534285197055, 5.9923644091573918, 6.0589056858401058,
      6.471163201271815, 6.4220248613320239, 6.8132551150569469,
      6.98553322309425, 7.415115702054039, 7.6189534595810846,
      7.8269407250746292, 7.8208279983169824, 7.8397210420011039,
      8.2399463014561061, 8.7328053302234139, 9.10604644297898,
      8.7580173996017781, 9.23188101224383, 9.6362043973850131,
      9.0373125035583026, 9.6682408060963034, 9.76852958812531,
      9.6155806459834139, 10.142402297211778, 10.185220749840768,
      10.199920636970326, 10.280139438478892, 10.269671559857791,
      10.404248833976963, 10.737949659707253, 10.630876166654657,
      10.634625624150647, 10.608309880881531, 10.811682381131511,
      11.059703612276369, 10.711755632845589, 10.61983754874141,
      10.847912855322276, 10.805357087884037, 10.673370026916865,
      10.438565251464974, 10.651703472564344, 10.678173650685814,
      10.327125764125812, 10.515850524009588, 10.656600577130854,
      10.413395659175174, 10.362877333241203, 10.297279791619266,
      10.163112747362748, 10.040141960444682, 9.5226369390961025,
      9.7419289400281777, 9.8093437562867756, 9.4654900475246055,
      9.01900982158297, 9.10167741842589, 8.5815525317273611, 8.8427591668428054,
      8.0244508160344488, 8.20656896360937, 7.7790627488087285,
      7.8106406619967865, 7.4561969079876516, 7.2007358167941433,
      6.7551400546033111, 6.7208615141071046, 6.7401752486226805,
      6.3903936588666213, 5.9478908553195486, 5.6864469159519588,
      5.5646349765230188, 5.323709126140864, 5.0578423384982747,
      4.5542741407586735, 4.0058021385923839, 4.2626264024603095,
      3.7269973685984925, 3.6148217648170027, 3.3541617922620892,
      2.9540178145125413, 2.4169412336780525, 2.1100902426698145,
      2.0392115682864347, 1.7169610087302039, 1.1215780173584162,
      0.79297199420710918, 0.44181347107363123, -0.072676911885443118,
      -0.0465966458626057, -0.58342769908231928, -0.41089294265232135,
      -0.912091117966461, -1.1809565960903394, -1.7416714627390624,
      -1.5448749089552694, -1.7846403818977765, -2.0677942931280437,
      -2.8000385527906708, -3.0254606132485877, -3.0336715910595542,
      -3.4984455881289334, -3.5848750665899418, -3.8904956803095931,
      -4.443761524693735, -4.3354294346380255, -4.7429389127632229,
      -5.1450962731264243, -5.1272269077313553, -5.6729994605464436,
      -5.6884464489255162, -6.0654874214189922, -6.00394954994951,
      -6.2893144917087449, -6.78148398144266, -6.9629890042711713,
      -6.8018198793960227, -6.6315415092913543, -7.2488330015188858,
      -7.2647257756480759, -7.2192680216418452, -7.8205979810992972,
      -7.8765891635471643, -8.03825672624585, -7.994400057184297,
      -7.8666361282351946, -8.2207329268878766, -8.503688382853273,
      -8.5473424014355928, -8.4304427848014889, -8.4712099423210088,
      -8.7538823580692533, -8.8227589438351384, -8.8682722817008681,
      -8.7609739356476446, -8.71788770947989, -8.5180207954123688,
      -8.832295867528881, -8.82310953030087, -8.4416595273589774,
      -8.9535453455563463, -8.7084997883455184, -8.8899731322314821,
      -8.6824889608363183, -8.74084316532858, -8.2799092983016589,
      -8.59589985852475, -8.2950574198054419, -8.2892028705581886,
      -8.2008396994016657, -7.5532426020889538, -7.9572092344764531,
      -7.6431608260307069, -7.53458635653422, -7.1935867710986567,
      -7.3160039766706344, -6.9865693851801032, -6.4794048108456259,
      -6.6905120203696313, -6.1826652107803941, -6.2079146336365882,
      -5.8776915103807958, -5.6377885707695476, -5.8421823408522471,
      -5.2221840081739774, -5.0442830349388323, -5.0054496732228912,
      -4.4554116368963292, -4.0678692437126678, -4.1758413354858561,
      -3.5409041218759771, -3.5804255417369957, -3.4010987164411128,
      -2.7656317507623869, -2.5103690428039918, -2.1387403996559664,
      -2.0573440242705834, -1.8010826133012712, -1.254353400697076,
      -1.3453340062482133, -0.99987082288506168, -0.5624472373464362,
      -0.29551294074389522, 0.064874568882400174, 0.1793206743742346,
      0.68876723936629247, 1.2133169098112386, 1.1466370383712741,
      1.3392792873399069, 1.8059842074871226, 2.2403862927495624,
      2.5509174272102655, 3.0131655426142427, 3.1993498899156192,
      3.515969616625445, 3.9101016809866858, 4.0237883416786095,
      4.1652044300975675, 4.4795278261216405, 4.913537530101669, 5.2202942302843,
      5.5483762666338645, 5.6094952089894878, 5.8494505309776619,
      6.1560731534023629, 6.5720606337736838, 6.8043924033954006,
      7.1626296045325812, 7.140296119436333, 7.2374225156046617,
      7.7397328043321405, 7.7509041307174344, 8.2266479308311382,
      8.4465302104236084, 8.4036975939894543, 8.7325357091458482,
      8.9346777766892842, 9.0240693845239246, 9.322783837677953,
      9.4371679190931079, 9.5551798369555243, 9.87510292780461,
      9.7750747084039116, 10.135839690651054, 10.085753538319395,
      10.237107323527121, 10.332445322547832, 10.469610854489787,
      10.825136173423212, 10.482776392792818, 10.943514142971223,
      10.524966987220854, 10.486596160972141, 10.803412706641199,
      10.85908080513949, 10.815121717588243 } ;

    Madgwick_embedded_DW->AccY_PWORK.TimePtr = (void *) pTimeValues0;
    Madgwick_embedded_DW->AccY_PWORK.DataPtr = (void *) pDataValues0;
    Madgwick_embedded_DW->AccY_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/AccZ' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06,
      0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18,
      0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31,
      0.32, 0.33, 0.34, 0.35, 0.36, 0.37, 0.38, 0.39, 0.4, 0.41, 0.42, 0.43,
      0.44, 0.45, 0.46, 0.47, 0.48, 0.49, 0.5, 0.51, 0.52, 0.53, 0.54, 0.55,
      0.56, 0.57, 0.58, 0.59, 0.6, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67,
      0.68, 0.69, 0.7, 0.71, 0.72, 0.73, 0.74, 0.75, 0.76, 0.77, 0.78, 0.79, 0.8,
      0.81, 0.82, 0.83, 0.84, 0.85, 0.86, 0.87, 0.88, 0.89, 0.9, 0.91, 0.92,
      0.93, 0.94, 0.95, 0.96, 0.97, 0.98, 0.99, 1.0, 1.01, 1.02, 1.03, 1.04,
      1.05, 1.06, 1.07, 1.08, 1.09, 1.1, 1.11, 1.12, 1.13, 1.14, 1.15, 1.16,
      1.17, 1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28,
      1.29, 1.3, 1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37, 1.38, 1.39, 1.4, 1.41,
      1.42, 1.43, 1.44, 1.45, 1.46, 1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53,
      1.54, 1.55, 1.56, 1.57, 1.58, 1.59, 1.6, 1.61, 1.62, 1.63, 1.64, 1.65,
      1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75, 1.76, 1.77,
      1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.85, 1.86, 1.87, 1.88, 1.89, 1.9,
      1.91, 1.92, 1.93, 1.94, 1.95, 1.96, 1.97, 1.98, 1.99, 2.0, 2.01, 2.02,
      2.03, 2.04, 2.05, 2.06, 2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14,
      2.15, 2.16, 2.17, 2.18, 2.19, 2.2, 2.21, 2.22, 2.23, 2.24, 2.25, 2.26,
      2.27, 2.28, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34, 2.35, 2.36, 2.37, 2.38,
      2.39, 2.4, 2.41, 2.42, 2.43, 2.44, 2.45, 2.46, 2.47, 2.48, 2.49, 2.5, 2.51,
      2.52, 2.53, 2.54, 2.55, 2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63,
      2.64, 2.65, 2.66, 2.67, 2.68, 2.69, 2.7, 2.71, 2.72, 2.73, 2.74, 2.75,
      2.76, 2.77, 2.78, 2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87,
      2.88, 2.89, 2.9, 2.91, 2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0,
      3.01, 3.02, 3.03, 3.04, 3.05, 3.06, 3.07, 3.08, 3.09, 3.1, 3.11, 3.12,
      3.13, 3.14, 3.15, 3.16, 3.17, 3.18, 3.19, 3.2, 3.21, 3.22, 3.23, 3.24,
      3.25, 3.26, 3.27, 3.28, 3.29, 3.3, 3.31, 3.32, 3.33, 3.34, 3.35, 3.36,
      3.37, 3.38, 3.39, 3.4, 3.41, 3.42, 3.43, 3.44, 3.45, 3.46, 3.47, 3.48,
      3.49, 3.5, 3.51, 3.52, 3.53, 3.54, 3.55, 3.56, 3.57, 3.58, 3.59, 3.6, 3.61,
      3.62, 3.63, 3.64, 3.65, 3.66, 3.67, 3.68, 3.69, 3.7, 3.71, 3.72, 3.73,
      3.74, 3.75, 3.76, 3.77, 3.78, 3.79, 3.8, 3.81, 3.82, 3.83, 3.84, 3.85,
      3.86, 3.87, 3.88, 3.89, 3.9, 3.91, 3.92, 3.93, 3.94, 3.95, 3.96, 3.97,
      3.98, 3.99, 4.0, 4.01, 4.02, 4.03, 4.04, 4.05, 4.06, 4.07, 4.08, 4.09, 4.1,
      4.11, 4.12, 4.13, 4.14, 4.15, 4.16, 4.17, 4.18, 4.19, 4.2, 4.21, 4.22,
      4.23, 4.24, 4.25, 4.26, 4.27, 4.28, 4.29, 4.3, 4.31, 4.32, 4.33, 4.34,
      4.35, 4.36, 4.37, 4.38, 4.39, 4.4, 4.41, 4.42, 4.43, 4.44, 4.45, 4.46,
      4.47, 4.48, 4.49, 4.5, 4.51, 4.52, 4.53, 4.54, 4.55, 4.56, 4.57, 4.58,
      4.59, 4.6, 4.61, 4.62, 4.63, 4.64, 4.65, 4.66, 4.67, 4.68, 4.69, 4.7, 4.71,
      4.72, 4.73, 4.74, 4.75, 4.76, 4.77, 4.78, 4.79, 4.8, 4.81, 4.82, 4.83,
      4.84, 4.85, 4.86, 4.87, 4.88, 4.89, 4.9, 4.91, 4.92, 4.93, 4.94, 4.95,
      4.96, 4.97, 4.98, 4.99, 5.0, 5.01, 5.02, 5.03, 5.04, 5.05, 5.06, 5.07,
      5.08, 5.09, 5.1, 5.11, 5.12, 5.13, 5.14, 5.15, 5.16, 5.17, 5.18, 5.19, 5.2,
      5.21, 5.22, 5.23, 5.24, 5.25, 5.26, 5.27, 5.28, 5.29, 5.3, 5.31, 5.32,
      5.33, 5.34, 5.35, 5.36, 5.37, 5.38, 5.39, 5.4, 5.41, 5.42, 5.43, 5.44,
      5.45, 5.46, 5.47, 5.48, 5.49, 5.5, 5.51, 5.52, 5.53, 5.54, 5.55, 5.56,
      5.57, 5.58, 5.59, 5.6, 5.61, 5.62, 5.63, 5.64, 5.65, 5.66, 5.67, 5.68,
      5.69, 5.7, 5.71, 5.72, 5.73, 5.74, 5.75, 5.76, 5.77, 5.78, 5.79, 5.8, 5.81,
      5.82, 5.83, 5.84, 5.85, 5.86, 5.87, 5.88, 5.89, 5.9, 5.91, 5.92, 5.93,
      5.94, 5.95, 5.96, 5.97, 5.98, 5.99, 6.0, 6.01, 6.02, 6.03, 6.04, 6.05,
      6.06, 6.07, 6.08, 6.09, 6.1, 6.11, 6.12, 6.13, 6.14, 6.15, 6.16, 6.17,
      6.18, 6.19, 6.2, 6.21, 6.22, 6.23, 6.24, 6.25, 6.26, 6.27, 6.28, 6.29, 6.3,
      6.31, 6.32, 6.33, 6.34, 6.35, 6.36, 6.37, 6.38, 6.39, 6.4, 6.41, 6.42,
      6.43, 6.44, 6.45, 6.46, 6.47, 6.48, 6.49, 6.5, 6.51, 6.52, 6.53, 6.54,
      6.55, 6.56, 6.57, 6.58, 6.59, 6.6, 6.61, 6.62, 6.63, 6.64, 6.65, 6.66,
      6.67, 6.68, 6.69, 6.7, 6.71, 6.72, 6.73, 6.74, 6.75, 6.76, 6.77, 6.78,
      6.79, 6.8, 6.81, 6.82, 6.83, 6.84, 6.85, 6.86, 6.87, 6.88, 6.89, 6.9, 6.91,
      6.92, 6.93, 6.94, 6.95, 6.96, 6.97, 6.98, 6.99, 7.0, 7.01, 7.02, 7.03,
      7.04, 7.05, 7.06, 7.07, 7.08, 7.09, 7.1, 7.11, 7.12, 7.13, 7.14, 7.15,
      7.16, 7.17, 7.18, 7.19, 7.2, 7.21, 7.22, 7.23, 7.24, 7.25, 7.26, 7.27,
      7.28, 7.29, 7.3, 7.31, 7.32, 7.33, 7.34, 7.35, 7.36, 7.37, 7.38, 7.39, 7.4,
      7.41, 7.42, 7.43, 7.44, 7.45, 7.46, 7.47, 7.48, 7.49, 7.5, 7.51, 7.52,
      7.53, 7.54, 7.55, 7.56, 7.57, 7.58, 7.59, 7.6, 7.61, 7.62, 7.63, 7.64,
      7.65, 7.66, 7.67, 7.68, 7.69, 7.7, 7.71, 7.72, 7.73, 7.74, 7.75, 7.76,
      7.77, 7.78, 7.79, 7.8, 7.81, 7.82, 7.83, 7.84, 7.85, 7.86, 7.87, 7.88,
      7.89, 7.9, 7.91, 7.92, 7.93, 7.94, 7.95, 7.96, 7.97, 7.98, 7.99, 8.0, 8.01,
      8.02, 8.03, 8.04, 8.05, 8.06, 8.07, 8.08, 8.09, 8.1, 8.11, 8.12, 8.13,
      8.14, 8.15, 8.16, 8.17, 8.18, 8.19, 8.2, 8.21, 8.22, 8.23, 8.24, 8.25,
      8.26, 8.27, 8.28, 8.29, 8.3, 8.31, 8.32, 8.33, 8.34, 8.35, 8.36, 8.37,
      8.38, 8.39, 8.4, 8.41, 8.42, 8.43, 8.44, 8.45, 8.46, 8.47, 8.48, 8.49, 8.5,
      8.51, 8.52, 8.53, 8.54, 8.55, 8.56, 8.57, 8.58, 8.59, 8.6, 8.61, 8.62,
      8.63, 8.64, 8.65, 8.66, 8.67, 8.68, 8.69, 8.7, 8.71, 8.72, 8.73, 8.74,
      8.75, 8.76, 8.77, 8.78, 8.79, 8.8, 8.81, 8.82, 8.83, 8.84, 8.85, 8.86,
      8.87, 8.88, 8.89, 8.9, 8.91, 8.92, 8.93, 8.94, 8.95, 8.96, 8.97, 8.98,
      8.99, 9.0, 9.01, 9.02, 9.03, 9.04, 9.05, 9.06, 9.07, 9.08, 9.09, 9.1, 9.11,
      9.12, 9.13, 9.14, 9.15, 9.16, 9.17, 9.18, 9.19, 9.2, 9.21, 9.22, 9.23,
      9.24, 9.25, 9.26, 9.27, 9.28, 9.29, 9.3, 9.31, 9.32, 9.33, 9.34, 9.35,
      9.36, 9.37, 9.38, 9.39, 9.4, 9.41, 9.42, 9.43, 9.44, 9.45, 9.46, 9.47,
      9.48, 9.49, 9.5, 9.51, 9.52, 9.53, 9.54, 9.55, 9.56, 9.57, 9.58, 9.59, 9.6,
      9.61, 9.62, 9.63, 9.64, 9.65, 9.66, 9.67, 9.68, 9.69, 9.7, 9.71, 9.72,
      9.73, 9.74, 9.75, 9.76, 9.77, 9.78, 9.79, 9.8, 9.81, 9.82, 9.83, 9.84,
      9.85, 9.86, 9.87, 9.88, 9.89, 9.9, 9.91, 9.92, 9.93, 9.94, 9.95, 9.96,
      9.97, 9.98, 9.99, 10.0, 10.01, 10.02, 10.03, 10.04, 10.05, 10.06, 10.07,
      10.08, 10.09, 10.1, 10.11, 10.12, 10.13, 10.14, 10.15, 10.16, 10.17, 10.18,
      10.19, 10.2, 10.21, 10.22, 10.23, 10.24, 10.25, 10.26, 10.27, 10.28, 10.29,
      10.3, 10.31, 10.32, 10.33, 10.34, 10.35, 10.36, 10.37, 10.38, 10.39, 10.4,
      10.41, 10.42, 10.43, 10.44, 10.45, 10.46, 10.47, 10.48, 10.49, 10.5, 10.51,
      10.52, 10.53, 10.54, 10.55, 10.56, 10.57, 10.58, 10.59, 10.6, 10.61, 10.62,
      10.63, 10.64, 10.65, 10.66, 10.67, 10.68, 10.69, 10.7, 10.71, 10.72, 10.73,
      10.74, 10.75, 10.76, 10.77, 10.78, 10.79, 10.8, 10.81, 10.82, 10.83, 10.84,
      10.85, 10.86, 10.87, 10.88, 10.89, 10.9, 10.91, 10.92, 10.93, 10.94, 10.95,
      10.96, 10.97, 10.98, 10.99, 11.0, 11.01, 11.02, 11.03, 11.04, 11.05, 11.06,
      11.07, 11.08, 11.09, 11.1, 11.11, 11.12, 11.13, 11.14, 11.15, 11.16, 11.17,
      11.18, 11.19, 11.2, 11.21, 11.22, 11.23, 11.24, 11.25, 11.26, 11.27, 11.28,
      11.29, 11.3, 11.31, 11.32, 11.33, 11.34, 11.35, 11.36, 11.37, 11.38, 11.39,
      11.4, 11.41, 11.42, 11.43, 11.44, 11.45, 11.46, 11.47, 11.48, 11.49, 11.5,
      11.51, 11.52, 11.53, 11.54, 11.55, 11.56, 11.57, 11.58, 11.59, 11.6, 11.61,
      11.62, 11.63, 11.64, 11.65, 11.66, 11.67, 11.68, 11.69, 11.7, 11.71, 11.72,
      11.73, 11.74, 11.75, 11.76, 11.77, 11.78, 11.79, 11.8, 11.81, 11.82, 11.83,
      11.84, 11.85, 11.86, 11.87, 11.88, 11.89, 11.9, 11.91, 11.92, 11.93, 11.94,
      11.95, 11.96, 11.97, 11.98, 11.99 } ;

    static real_T pDataValues0[] = { 10.862712689954089, 10.953573060549001,
      11.069602471615351, 10.624256250454481, 11.1307704426835,
      10.656685811118901, 10.722048622148977, 10.829879124971423,
      10.549715175016928, 10.654457000883154, 10.635393589534196,
      10.5859819158193, 10.641146330896255, 10.626525879022717,
      10.720812484069961, 10.744490406316304, 10.691091854002888,
      10.471166637797793, 11.128228061020977, 10.51702976561285,
      11.023991440680923, 11.043045777532505, 10.724893033650673,
      10.594405404830781, 11.058743192570111, 10.91125117377665,
      10.617693937491069, 10.82519392236523, 10.515018765957553,
      11.145188713814671, 10.928042591597709, 10.56313180377599,
      11.097275656262187, 10.501194186554944, 10.604751914695212,
      10.910415107844203, 10.96502784081131, 10.836434369889085,
      11.187130322022689, 10.742399878757597, 10.701680624536644,
      10.881824763241143, 10.588834413542871, 10.7533991675621,
      10.891939592911831, 10.733756996667193, 10.811712538327885,
      10.686793014294702, 11.038432579965596, 10.792756468880139,
      11.109765416039313, 10.672022820108927, 10.714935110795675,
      10.769653441878571, 10.918488960498422, 10.739359774706108,
      10.63778676983363, 10.566686652342696, 10.864237402507976,
      10.586902234855037, 10.961320967684287, 10.973880516837021,
      10.95898122034148, 10.90524189134582, 10.754054895423012,
      10.936409146149588, 10.76812918990203, 10.888772349412138,
      11.051462981793566, 10.928382730359548, 11.112343490098278,
      10.682879729172125, 10.51675844418353, 10.759177803715724,
      11.01463640622063, 11.052890390600071, 10.969054326203963,
      10.569469097327339, 10.465667152231218, 10.842537978764392,
      10.96670300117818, 10.69949184208631, 11.062206692651314,
      10.780452049823587, 10.584358221244472, 10.859886058580003,
      10.623122101148386, 10.722922839906714, 10.673036646098119,
      10.841189928690948, 10.975292968878767, 10.782163301947318,
      10.865951890800853, 10.618472367695388, 10.871598534671147,
      10.918168546213398, 10.948358547910827, 10.858341678151843,
      10.537745440186303, 11.04600451421887, 10.775082261929615,
      10.988801093605193, 10.885348880758723, 10.47566347928719,
      10.852802818563546, 11.106780156238028, 10.628637914037789,
      10.847055360559382, 10.886423719889256, 10.758919645803822,
      10.604413161766553, 10.783870313300184, 10.996531789176295,
      10.887837676306308, 10.747166436503237, 10.961580632501443,
      10.894454921164252, 10.986663977174565, 10.936051873268058,
      10.795285769442428, 10.865094544751804, 10.942357035132661,
      10.774680959662753, 10.66481954789343, 10.957642800300073,
      10.715214055730208, 10.732756905748232, 10.876363729438467,
      10.453290087023722, 11.019272325414901, 10.786261338419935,
      10.925914889872137, 10.742224521377141, 10.598305368605583,
      10.849787422911428, 10.695871813091127, 10.569886265295295,
      10.763561528807658, 11.112663335912181, 10.631361740986605,
      10.664736052730555, 10.669905679304634, 10.913866817647516,
      10.962157931628733, 10.787940746221663, 10.60472804804002,
      10.566898741579019, 11.086759402887161, 10.559071281961444,
      10.593004443865702, 10.662816231269147, 10.777055502718371,
      10.897698671002733, 10.706667891937641, 10.919976410527148,
      10.852804513638674, 10.698214008859569, 10.532766392911057,
      10.84447415471629, 10.81750463966824, 10.901388534813536,
      10.664880034601783, 10.91727474267865, 11.041839003482423,
      10.849167944889583, 11.056993540628955, 10.841038952515145,
      11.072563368581157, 10.543173127735081, 10.857718063318721,
      10.742020501250172, 10.884925512613311, 10.586536230212669,
      10.583039182583859, 10.726112277877458, 10.596428222095323,
      10.798508541723328, 10.711150061401723, 10.85691294678049,
      10.692305179529797, 10.64991156825198, 10.75258538243162, 10.8495752197269,
      11.006982609090695, 10.770768105780848, 10.729340859076274,
      10.856043233328366, 10.747006237574555, 10.559778194387267,
      10.688014250494177, 10.918896309594361, 10.418421709572835,
      10.831945796034351, 10.983604537714958, 10.938190133420751,
      10.876677231176798, 10.92920156889835, 10.70792744841485,
      10.756108772726154, 10.850933562510621, 10.72841424633909,
      10.998968654145038, 10.706472880922679, 10.758661257154499,
      10.963200098575177, 11.054181839949328, 10.7803815600536,
      11.016862155173621, 10.633907669418528, 10.743410511939947,
      10.791678825386688, 10.767834924229396, 10.651595982441952,
      10.562454406080803, 10.7597070365373, 11.075837641384062,
      10.999232357731467, 10.849488031445878, 10.977496020136229,
      10.780613239838074, 10.856362213011693, 10.791096676032451,
      10.854135687241648, 10.667380685262687, 10.924903953789883,
      10.520293315717806, 10.616249476913742, 10.917998047384193,
      10.80760157587496, 10.800301094859654, 10.546380201354252,
      10.656086257189104, 11.009163195443604, 10.787745938051444,
      10.40222037460096, 10.799388868534512, 10.991094212882428,
      11.043651260172215, 10.814771930417818, 10.798101958731834,
      10.684496249770502, 10.935348519147526, 10.611572155457747,
      10.568959763550335, 10.717725172804949, 10.975412219003685,
      10.653629782653958, 10.856851154826199, 10.665517059843404,
      11.125558143679445, 10.899792003616206, 10.595684123270146,
      11.003265974125226, 10.57195275716539, 10.528118982788133,
      10.915954587260442, 10.717771043929577, 10.628248817853683,
      11.003395170199651, 10.590063133813523, 11.249930588044396,
      10.789047479117302, 10.709280230727412, 11.175773623781865,
      10.948152162043865, 10.68377342217582, 10.983839399168616,
      10.746267073107566, 10.9361842379012, 10.996739384748755,
      10.808159152598252, 10.805520191918628, 10.941126554524075,
      10.785818791105253, 10.980775916466966, 10.623990088250999,
      10.772427774825079, 10.939792033450688, 10.948614124854029,
      10.661322033035356, 10.750538255643479, 10.85846110984261,
      10.869704350365238, 10.971912703880369, 10.948712772332643,
      10.558187734987738, 10.724743880864715, 10.80394846733687,
      10.724775807638531, 10.629283802924455, 10.71857508102093,
      10.591850629424698, 10.557261392129996, 10.69107833485636,
      10.975503004765585, 10.749489399580394, 11.048484240713462,
      10.833498146350111, 10.863054340418003, 10.971834095140149,
      10.612164290858825, 11.008924383146018, 10.809094454416101,
      10.733788392452729, 10.817242257154714, 10.901345143740198,
      10.82505712138218, 10.723987814109918, 11.019706126197832,
      10.615682372926891, 10.827314647506915, 10.562816612665479,
      10.851093964117169, 10.828979581082663, 10.787519496460247,
      10.952932769380739, 10.636823540201707, 10.519299725394809,
      11.050689921626674, 11.396243222932119, 10.72398347074706,
      10.868343453547752, 10.909273354749187, 10.947856000510157,
      10.670891062686374, 10.718971413921928, 10.864668524472931,
      10.678105408351175, 10.945461876264199, 11.024070630287074,
      11.084575810476332, 10.61543039947454, 11.059121923826224,
      10.683486179058013, 10.639374076362007, 10.903104789792685,
      10.737285982877664, 10.67881649582368, 10.874006364460788,
      10.678542031631645, 10.811205635858208, 10.834687478135134,
      10.773975659341787, 10.821652953320337, 10.851163451037035,
      10.746788636036134, 11.059646561366289, 10.698746264699651,
      11.035600858798817, 10.752932264475271, 10.70490015953324,
      10.899401775045805, 10.244691698975599, 10.669382460623394,
      11.091467837772441, 10.88240165166498, 10.910897791968747,
      10.601842388530962, 10.7177208423779, 10.726697216579586,
      10.648032150897055, 10.805401064240888, 10.753855112665113,
      10.577428039466415, 10.520701462199812, 10.623785260327553,
      10.579400238538147, 10.683628266249642, 10.569958112777542,
      10.773445573944466, 10.734994526653882, 10.731155428590551,
      10.887642595449391, 10.780641524338408, 10.762532374892345,
      10.465605126331118, 10.801550562780463, 11.201928405740402,
      10.903930210974721, 10.934911606231459, 10.568727643774794,
      10.86488718109738, 10.678811088506665, 10.8942759583357,
      10.548679817578373, 11.024623505147067, 10.590641433035522,
      10.707969726934683, 11.061789632504647, 10.918977083339318,
      10.603034595229586, 11.094332771307789, 10.642913534605571,
      10.91141963785372, 10.90824481487711, 11.232215583467614,
      11.00730438655267, 10.801805609487795, 10.756375393910814,
      10.296531555747338, 10.987066273653006, 10.532213184427889,
      10.753539691421016, 10.975418846825777, 10.874411844956734,
      10.857909484379942, 10.706823341369285, 10.677585006778918,
      10.772306297867233, 10.961603539751057, 10.691186235666775,
      10.837306982354496, 10.736798967307394, 10.65987553605472,
      10.641746112643181, 10.812205422778781, 10.890182319258834,
      10.540628029358341, 10.677708974914832, 10.921744122917465,
      10.687403613376325, 10.895916410480018, 10.957069392138111,
      10.625661683905768, 10.92760542255505, 10.787890299310291,
      10.872779839434363, 10.616559638469496, 10.865527000432342,
      10.718387778254661, 10.858164519598958, 10.671365181263965,
      10.549899391070362, 10.76424986566254, 10.668796386182628,
      10.870949981933451, 10.726798410867824, 10.96570472038133,
      10.847868777957212, 10.728758993477042, 10.837785458987131,
      10.861602943929627, 10.941033409782726, 10.81216990051503,
      10.272627578916074, 10.948747825331616, 10.9515710758701,
      10.853216511427879, 10.703782890286, 10.755300225125771,
      10.739543220455426, 10.889457865638098, 10.754355362624045,
      10.656769630871084, 10.776071217204839, 10.676423480867586,
      10.762584181950489, 10.537668600053264, 10.836825853835016,
      10.683869290761487, 11.140085454378037, 11.021949211012467,
      10.910097728043546, 10.665079359278819, 10.753904908761051,
      10.717070466429609, 10.99000190207089, 11.065765172956546,
      10.929166552483844, 10.964340084756493, 11.125046766537247,
      10.85446284036192, 10.626169499615512, 10.74852429020711,
      10.838458674981432, 10.471106999138224, 10.778845176944246,
      10.913532029458921, 10.8076490300316, 10.76818505307001,
      10.756343177434781, 11.018079608416969, 10.902818892999598,
      10.778497890546054, 10.662491545526409, 11.274951972163306,
      10.646859326254498, 10.909278643045008, 10.853932330911483,
      10.759648203079987, 10.897780172414441, 10.536915069179351,
      10.78822520542761, 10.738576854451907, 10.866068406206477,
      11.015469298256715, 10.990251086305289, 10.701514297056802,
      10.997158837444351, 10.55319423703029, 10.738621782080461,
      10.865284784074863, 10.518330084076423, 10.460621593929458,
      10.474606575790324, 10.56355102253997, 10.723936324423526,
      11.115235866567554, 10.836327594813509, 10.665189772131303,
      10.917447882701108, 10.862883582004944, 11.014064292013268,
      10.663500857832517, 10.61658685100914, 10.944473215795313,
      10.336714218878189, 10.834845355941482, 10.560569729748513,
      10.528842551411083, 11.022202306535704, 10.978886390711654,
      10.625923231147288, 10.534599067581595, 10.525515456569673,
      10.907434901071316, 10.481114004215762, 10.557550803408587,
      10.871194178236946, 10.790025873927952, 10.929341360510982,
      10.672729987522052, 10.832666349559597, 10.793108713343051,
      11.119485535423255, 10.730822724809149, 10.657565563331948,
      10.83762544145373, 10.797064245036221, 10.593361775171418,
      10.775885534385745, 10.810892731712514, 11.05378299823113,
      10.584952898662474, 10.589855985554614, 10.447444453582706,
      10.974433281407203, 10.926717593052791, 10.553918262752624,
      10.633478470161842, 10.705087696190985, 10.687823999200644,
      10.889414406815785, 10.829410881422831, 10.825126016508701,
      10.984688653376217, 10.600096233165516, 10.90217929672866,
      11.147570088909321, 10.885833061929594, 10.972924716740861,
      11.000313593799637, 11.056219755112044, 10.604288011366059,
      10.783304479546333, 10.662090021471455, 10.699661600184415,
      10.489688173412157, 10.89802475672605, 10.838566556007457,
      11.378353818674505, 10.918248852672539, 10.810328461892455,
      10.411366341050735, 10.915040893151437, 10.550955833330603,
      10.834688083782599, 10.931929948451337, 11.126755634022896,
      10.856890196650596, 10.539647964661288, 10.699200427620822,
      11.0420670031529, 10.827871587858628, 10.859857131294763,
      10.921902925145815, 10.634448064230943, 10.705749944287509,
      10.702157884804379, 11.057872462940818, 10.799075000670298,
      10.63361122760346, 10.754918655135013, 10.972876250070147,
      10.87091532293045, 11.013754241700704, 10.742690030608387,
      10.388176528202933, 10.656286494399657, 10.824489612919605,
      10.708975484770658, 11.00538197140618, 10.533045873021008,
      10.851794283525226, 10.765806885224082, 10.334863036156936,
      11.151802570732197, 10.623739407933192, 10.867340812970129,
      10.949601415947193, 10.716594687488787, 10.999179147791731,
      10.943765565324055, 10.644959758586419, 10.950819463373181,
      10.766657329663929, 10.483801664281179, 10.916266163671025,
      11.141017313583957, 10.897996202534035, 10.736477014898057,
      10.607679680157723, 10.82163120354646, 10.68051125240148,
      10.636101375317816, 10.702918588068066, 10.508968903631942,
      10.775393691234733, 10.85617291018395, 10.843155864606324,
      10.856487257311832, 10.629829718789448, 10.596655552136786,
      10.584207945037102, 10.752343479552202, 10.679480869519809,
      10.833143976513618, 11.236122559188859, 10.63653077693561,
      10.858918877172277, 10.535939196864945, 10.727545642887527,
      10.904160855965552, 10.434727798926707, 10.990075131585979,
      11.016111838737386, 10.894077309004615, 10.670442043307553,
      11.045900749222636, 10.833355978114074, 10.70199615772435,
      10.574065161037284, 10.754462104360519, 10.855192513293558,
      10.984031288289266, 10.697997217499065, 10.885290932858528,
      10.622005526156403, 10.599382296613431, 11.015255131600814,
      10.552518487982661, 10.968312138044384, 11.026889640633868,
      10.7273102262044, 10.7049404185563, 10.574781887955069, 10.69505926652065,
      10.946361325877248, 10.956640113291835, 10.784131251790587,
      10.556597208699369, 10.734196355290692, 10.724248916322594,
      10.687797241775112, 10.712949670159015, 11.134683953559829,
      10.8399462845981, 10.72092947830552, 11.167641610613973,
      10.849220478915409, 11.183295575907639, 11.027626875737502,
      10.384228748210603, 10.505170663370169, 10.488949525438413,
      10.62749029991762, 10.841227328742406, 10.859252665280058,
      11.005605228979265, 10.682704593542432, 10.996133258147948,
      10.837555252195845, 10.793124419813783, 10.854124575224837,
      11.005945664553277, 10.751590821553062, 10.666308359508378,
      10.742930811426623, 11.065723421590951, 10.936872591651976,
      10.619315678296923, 10.882185014098903, 10.645669237033291,
      11.084524258274918, 10.455224518436406, 10.522604712072436,
      10.955748829049078, 10.714776815887824, 10.880300048159633,
      10.714460336697153, 10.837399353864484, 10.439581947048941,
      10.67518000223787, 10.822714301914292, 10.547723940464767,
      10.771312337511333, 10.759621433016456, 10.698120266082856,
      10.818048285716333, 10.81042111186758, 10.666327630880044,
      10.800775121278123, 10.992912234757153, 10.972244473880487,
      10.598416432768891, 11.0550550098499, 10.904383080007186,
      11.117377796669494, 10.762388081739493, 10.908965852834624,
      11.202948277286957, 10.771596144811983, 10.872279533444775,
      11.106827742010847, 10.956199306932149, 10.841675265891636,
      11.171701960235469, 10.942664144046761, 10.429882843918422,
      10.781184315945294, 10.675758373442891, 10.624111864642325,
      10.691083564527798, 10.740878057479614, 11.028056451306764,
      10.536403545879422, 10.644434332663053, 10.415811016795352,
      11.088940493706357, 10.511328077198984, 10.667565650319087,
      11.136843249811323, 10.846655032058852, 11.11934560640835,
      10.807539395708025, 10.751333681584414, 10.720727106327727,
      10.494710971050409, 10.793200332120328, 11.093942994531979,
      10.983189873160143, 10.936445546188885, 10.559146934619122,
      11.030986128973591, 11.047051866542359, 11.024935224356696,
      10.641539497700816, 10.966388758093649, 11.13817540806798,
      11.134577827075518, 10.862266041833289, 10.768004530649598,
      10.58611823475259, 10.831446916490924, 10.78438342615, 10.894616005905132,
      10.745818158340105, 10.837306075128021, 10.971673113560001,
      10.946430548720407, 11.117060051828588, 10.965933067507939,
      10.937309587057793, 10.825535634107668, 10.677849066128442,
      10.852955852547643, 10.489433313249497, 10.669409218136069,
      10.979522389755763, 10.701866224896396, 10.968459659278331,
      10.940407538024024, 10.881065247150017, 10.753272742572568,
      10.939213836874899, 10.835216630411363, 10.767963905749486,
      11.030652844341905, 11.043872042337306, 11.282497707908943,
      10.993888811734145, 10.856510500632579, 10.359568711925707,
      10.607884576064329, 10.647119665981386, 10.68060405035448,
      10.945348814009167, 10.865725598371945, 10.893901656246875,
      10.834024136369226, 10.786418682768128, 10.882545130746058,
      10.761489545439776, 10.449920836659707, 10.638352165156851,
      11.035266232507684, 10.513106886419857, 11.101288765577689,
      10.751165029566689, 10.695757062450475, 10.85021162630308,
      10.742806463742278, 11.021689020646331, 10.600238026073781,
      10.438116331145368, 10.943266455537106, 10.633658396280946,
      11.063753838383384, 10.876496500331456, 10.759442431321714,
      10.895121427570887, 10.819039645791106, 10.883252106511677,
      10.873275596573244, 10.855767093657056, 10.620923365728565,
      10.902911471010588, 10.771439005000479, 10.622207064690624,
      11.016477681743538, 11.163041891515341, 11.042511625406844,
      10.893728381934757, 10.753842327036528, 10.853300529879457,
      10.823181464863563, 10.887327779877978, 10.764246291442955,
      10.641599159622338, 10.858265288138995, 10.658581361284707,
      10.726413097002727, 10.998263971206576, 10.713186320207742,
      10.864258848341402, 10.768199974517229, 10.688526552857974,
      10.812152501710747, 10.78370306886942, 10.684089081127151,
      10.703599270581018, 11.063004149170194, 10.930475154878154,
      10.927402637600276, 10.742010476029245, 10.763971196548242,
      10.517577923154976, 10.889612988003536, 10.613940754259211,
      11.00879525252858, 10.84096278130486, 10.776085649507166,
      10.807047872040476, 10.85681976899015, 10.664931817005465,
      10.728869299678617, 10.980635907754962, 10.422132677466205,
      10.962582533371322, 10.997577889975469, 10.890895738159962,
      10.94179147158497, 10.890175771687273, 10.98892207595982,
      10.805710952707432, 10.623914335219727, 10.751329089441066,
      11.003310710987654, 10.905567596146025, 10.705095991761146,
      11.055113324141836, 10.831270670501111, 10.54445897089732,
      10.887270166709413, 11.021002268411333, 11.082526036685467,
      10.790043161496616, 10.669356969393574, 10.566602045163044,
      10.862594318534851, 10.911533530037477, 10.948846849892425,
      10.741135585462096, 10.750429293876177, 10.7126605154831,
      10.835356736587688, 10.728863376883295, 10.929285583564811,
      10.790816085168725, 10.680474146276081, 10.855821781603948,
      10.931815115209417, 10.938388863371832, 11.079418158154667,
      10.985784126074552, 10.761070315832574, 10.857972296900947,
      10.912517161310655, 10.598613857401155, 10.986222982794976,
      10.699255125803198, 11.09286017432756, 11.106289180879322,
      10.745787462876562, 10.590778850887745, 10.701891147141827,
      10.741525951793731, 10.929236142014783, 10.853744723213488,
      10.916497175172264, 11.08167253507346, 10.799476501900939,
      10.792755132762863, 10.72030417591014, 10.701008994982057,
      10.879766101689071, 10.921784234502041, 10.745103442737374,
      10.78494266602409, 10.751252389267909, 10.810160157526049,
      10.690814578355679, 10.760021813280476, 11.002808616011226,
      10.324393409781894, 10.736744466885492, 10.536708270627836,
      10.904531054389171, 10.999488506806056, 11.021291813675942,
      10.875704707747385, 10.96775067829558, 10.834380987250574,
      11.038164022753596, 10.355200489739348, 10.488720735322962,
      10.706525421744454, 10.892341087071891, 10.994379678957138,
      11.052214005881247, 10.483699947434149, 11.03115962624773,
      11.140020137482539, 10.817823057979234, 10.564645927809778,
      11.34799609433693, 10.658457231287933, 10.910305507563693,
      10.746418545278161, 10.833727399941733, 11.14194042094711,
      10.681448212380326, 11.005481358304085, 11.109483494571458,
      10.945759221121184, 10.937160724492449, 11.031271329059182,
      10.744397333144592, 10.76894887305737, 10.720358024299442,
      10.99678067293417, 10.962890734498174, 10.965128618386041,
      10.537733255047881, 10.695602510855974, 10.673425619566752,
      10.526922137286931, 10.765441373262652, 10.760198791855895,
      10.940756992469401, 10.976914229926388, 10.642132371700415,
      10.852314153533079, 10.742200320298, 10.876817043796921,
      11.057751706909348, 10.584991558914487, 10.811187601369834,
      10.901634454267938, 10.508635406786905, 11.006187359392404,
      10.866582199585677, 11.240535659453023, 10.960352735232076,
      10.95090545323635, 11.084858074819431, 10.755433712548836,
      11.018955704389791, 10.78475930332335, 10.914553779074945,
      10.836837382392662, 10.759344919664617, 10.632884002472606,
      10.810165067878774, 10.830374143782226, 10.818286876297336,
      10.814680009583522, 10.771665117416649, 10.912630059492535,
      10.942623101127717, 10.960526275157484, 10.806141990396171,
      10.719207521877266, 11.09550742075128, 10.78010305234019,
      10.734823610041952, 10.675355376586657, 10.78838673583822,
      10.820495864923577, 10.740381253148671, 10.794129077279932,
      10.59085293932646, 10.693094615916817, 10.609180929147522,
      10.816276912386384, 10.971547021792629, 10.708926259558803,
      10.651052277733601, 10.623454111674981, 10.907714406052206,
      10.851950142740897, 10.835125729268617, 11.009810579043938,
      10.542224272751881, 11.052510198049344, 10.527965260972245,
      10.994119622234548, 10.851722090344884, 10.715993094346308,
      10.927481284067053, 10.969852765274714, 10.766144990149151,
      10.966012826134229, 11.108854212483688, 11.005062224542366,
      11.058746694020025, 10.654902790887423, 10.610516871762414,
      10.489067423374017, 10.98255756663295, 10.668015811375076,
      10.653322892125185, 10.600938644555361, 10.770410954124724,
      10.718303726157838, 10.849435825906701, 10.623258352808518,
      10.75510460074614, 10.836610530508732, 11.097120822242166,
      11.027341898393324, 10.752585290754737, 11.086812287534691,
      10.98779826071145, 10.6612878956603, 10.704667400657661,
      10.760621252053745, 11.064448405853268, 10.761896603885729,
      11.039079390441097, 10.792445009576076, 11.179145670368664,
      11.101183294443658, 10.473916550227152, 10.965731593352734,
      10.719955457250141, 10.522229262523416, 10.686794639690548,
      11.024828196695196, 10.72450009433898, 11.049002682419907,
      10.865659044947654, 10.908430967802419, 10.574279841575473,
      10.630685251554619, 10.761353476498458, 10.763397108683979,
      10.774988938808679, 11.008079677974967, 10.675708402611253,
      10.924219016109978, 10.6124690093067, 10.614956210447039,
      10.84787247413953, 11.155970627242956, 10.968647859626344,
      10.436724682484334, 10.690602009713979, 10.67042662428306,
      10.588382535588666, 11.041887024631039, 10.813664395875449,
      10.533325495671361, 10.865075907048665, 10.758120459787984,
      10.629379059626558, 10.894563660189466, 10.648523286165981,
      10.805377171471637, 10.679620413432348, 10.499443085950684,
      10.707073322078251, 10.774500542694971, 10.884177894723027,
      10.924465257861245, 10.720944389092882, 10.846105292034734,
      10.739088871901084, 10.830541446387546, 10.563326674525536,
      10.909214842178381, 10.789398582394112, 10.780370849651877,
      10.941203508480868, 10.605066368104298, 10.948399481549863,
      10.620726982028142, 10.864594600952016, 10.769680487568449,
      10.727536464885235, 10.926118557087902, 10.989426123563094,
      10.903559342096873, 10.845739339732162, 10.785230973613082,
      10.480409018895989, 10.596028227134386, 10.999870225457245,
      10.789946222897109, 10.775720971505605, 10.810124415034444,
      10.842080777578875, 10.782623608485711, 10.942267675590296,
      10.740741633955752, 10.590338107765229, 10.917805433296406,
      11.089243470131558, 10.718906741791015, 10.976221710490027,
      10.778801152616031, 10.811050260261538, 10.881658331601955,
      10.718148147038097, 10.912040946912253, 10.711365105496558,
      10.749623775173914, 10.853747085329651, 11.131735121635849,
      10.818242601259515, 10.644092355934337, 11.029102881478359,
      10.790002128454034, 10.951519762683359, 10.74107439835857,
      10.747505172805454, 10.628619899140283, 10.950545914368575,
      10.890306591922748, 10.613897604743219, 10.693348918367306,
      10.899418396219389, 10.656460108836216, 10.923146270490028,
      10.512478783549252, 10.955008590278823, 10.725299333763834,
      10.73783572613784, 10.994702665579581, 10.67046153076576,
      10.613609725696049, 11.080666185699357, 10.658618999155046,
      10.913849354567935, 10.919772224470467, 10.865211536743399,
      10.889465001823174, 10.71174269240062, 10.975972609810865,
      10.95411859007792 } ;

    Madgwick_embedded_DW->AccZ_PWORK.TimePtr = (void *) pTimeValues0;
    Madgwick_embedded_DW->AccZ_PWORK.DataPtr = (void *) pDataValues0;
    Madgwick_embedded_DW->AccZ_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/GyroX' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06,
      0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18,
      0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31,
      0.32, 0.33, 0.34, 0.35, 0.36, 0.37, 0.38, 0.39, 0.4, 0.41, 0.42, 0.43,
      0.44, 0.45, 0.46, 0.47, 0.48, 0.49, 0.5, 0.51, 0.52, 0.53, 0.54, 0.55,
      0.56, 0.57, 0.58, 0.59, 0.6, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67,
      0.68, 0.69, 0.7, 0.71, 0.72, 0.73, 0.74, 0.75, 0.76, 0.77, 0.78, 0.79, 0.8,
      0.81, 0.82, 0.83, 0.84, 0.85, 0.86, 0.87, 0.88, 0.89, 0.9, 0.91, 0.92,
      0.93, 0.94, 0.95, 0.96, 0.97, 0.98, 0.99, 1.0, 1.01, 1.02, 1.03, 1.04,
      1.05, 1.06, 1.07, 1.08, 1.09, 1.1, 1.11, 1.12, 1.13, 1.14, 1.15, 1.16,
      1.17, 1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28,
      1.29, 1.3, 1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37, 1.38, 1.39, 1.4, 1.41,
      1.42, 1.43, 1.44, 1.45, 1.46, 1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53,
      1.54, 1.55, 1.56, 1.57, 1.58, 1.59, 1.6, 1.61, 1.62, 1.63, 1.64, 1.65,
      1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75, 1.76, 1.77,
      1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.85, 1.86, 1.87, 1.88, 1.89, 1.9,
      1.91, 1.92, 1.93, 1.94, 1.95, 1.96, 1.97, 1.98, 1.99, 2.0, 2.01, 2.02,
      2.03, 2.04, 2.05, 2.06, 2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14,
      2.15, 2.16, 2.17, 2.18, 2.19, 2.2, 2.21, 2.22, 2.23, 2.24, 2.25, 2.26,
      2.27, 2.28, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34, 2.35, 2.36, 2.37, 2.38,
      2.39, 2.4, 2.41, 2.42, 2.43, 2.44, 2.45, 2.46, 2.47, 2.48, 2.49, 2.5, 2.51,
      2.52, 2.53, 2.54, 2.55, 2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63,
      2.64, 2.65, 2.66, 2.67, 2.68, 2.69, 2.7, 2.71, 2.72, 2.73, 2.74, 2.75,
      2.76, 2.77, 2.78, 2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87,
      2.88, 2.89, 2.9, 2.91, 2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0,
      3.01, 3.02, 3.03, 3.04, 3.05, 3.06, 3.07, 3.08, 3.09, 3.1, 3.11, 3.12,
      3.13, 3.14, 3.15, 3.16, 3.17, 3.18, 3.19, 3.2, 3.21, 3.22, 3.23, 3.24,
      3.25, 3.26, 3.27, 3.28, 3.29, 3.3, 3.31, 3.32, 3.33, 3.34, 3.35, 3.36,
      3.37, 3.38, 3.39, 3.4, 3.41, 3.42, 3.43, 3.44, 3.45, 3.46, 3.47, 3.48,
      3.49, 3.5, 3.51, 3.52, 3.53, 3.54, 3.55, 3.56, 3.57, 3.58, 3.59, 3.6, 3.61,
      3.62, 3.63, 3.64, 3.65, 3.66, 3.67, 3.68, 3.69, 3.7, 3.71, 3.72, 3.73,
      3.74, 3.75, 3.76, 3.77, 3.78, 3.79, 3.8, 3.81, 3.82, 3.83, 3.84, 3.85,
      3.86, 3.87, 3.88, 3.89, 3.9, 3.91, 3.92, 3.93, 3.94, 3.95, 3.96, 3.97,
      3.98, 3.99, 4.0, 4.01, 4.02, 4.03, 4.04, 4.05, 4.06, 4.07, 4.08, 4.09, 4.1,
      4.11, 4.12, 4.13, 4.14, 4.15, 4.16, 4.17, 4.18, 4.19, 4.2, 4.21, 4.22,
      4.23, 4.24, 4.25, 4.26, 4.27, 4.28, 4.29, 4.3, 4.31, 4.32, 4.33, 4.34,
      4.35, 4.36, 4.37, 4.38, 4.39, 4.4, 4.41, 4.42, 4.43, 4.44, 4.45, 4.46,
      4.47, 4.48, 4.49, 4.5, 4.51, 4.52, 4.53, 4.54, 4.55, 4.56, 4.57, 4.58,
      4.59, 4.6, 4.61, 4.62, 4.63, 4.64, 4.65, 4.66, 4.67, 4.68, 4.69, 4.7, 4.71,
      4.72, 4.73, 4.74, 4.75, 4.76, 4.77, 4.78, 4.79, 4.8, 4.81, 4.82, 4.83,
      4.84, 4.85, 4.86, 4.87, 4.88, 4.89, 4.9, 4.91, 4.92, 4.93, 4.94, 4.95,
      4.96, 4.97, 4.98, 4.99, 5.0, 5.01, 5.02, 5.03, 5.04, 5.05, 5.06, 5.07,
      5.08, 5.09, 5.1, 5.11, 5.12, 5.13, 5.14, 5.15, 5.16, 5.17, 5.18, 5.19, 5.2,
      5.21, 5.22, 5.23, 5.24, 5.25, 5.26, 5.27, 5.28, 5.29, 5.3, 5.31, 5.32,
      5.33, 5.34, 5.35, 5.36, 5.37, 5.38, 5.39, 5.4, 5.41, 5.42, 5.43, 5.44,
      5.45, 5.46, 5.47, 5.48, 5.49, 5.5, 5.51, 5.52, 5.53, 5.54, 5.55, 5.56,
      5.57, 5.58, 5.59, 5.6, 5.61, 5.62, 5.63, 5.64, 5.65, 5.66, 5.67, 5.68,
      5.69, 5.7, 5.71, 5.72, 5.73, 5.74, 5.75, 5.76, 5.77, 5.78, 5.79, 5.8, 5.81,
      5.82, 5.83, 5.84, 5.85, 5.86, 5.87, 5.88, 5.89, 5.9, 5.91, 5.92, 5.93,
      5.94, 5.95, 5.96, 5.97, 5.98, 5.99, 6.0, 6.01, 6.02, 6.03, 6.04, 6.05,
      6.06, 6.07, 6.08, 6.09, 6.1, 6.11, 6.12, 6.13, 6.14, 6.15, 6.16, 6.17,
      6.18, 6.19, 6.2, 6.21, 6.22, 6.23, 6.24, 6.25, 6.26, 6.27, 6.28, 6.29, 6.3,
      6.31, 6.32, 6.33, 6.34, 6.35, 6.36, 6.37, 6.38, 6.39, 6.4, 6.41, 6.42,
      6.43, 6.44, 6.45, 6.46, 6.47, 6.48, 6.49, 6.5, 6.51, 6.52, 6.53, 6.54,
      6.55, 6.56, 6.57, 6.58, 6.59, 6.6, 6.61, 6.62, 6.63, 6.64, 6.65, 6.66,
      6.67, 6.68, 6.69, 6.7, 6.71, 6.72, 6.73, 6.74, 6.75, 6.76, 6.77, 6.78,
      6.79, 6.8, 6.81, 6.82, 6.83, 6.84, 6.85, 6.86, 6.87, 6.88, 6.89, 6.9, 6.91,
      6.92, 6.93, 6.94, 6.95, 6.96, 6.97, 6.98, 6.99, 7.0, 7.01, 7.02, 7.03,
      7.04, 7.05, 7.06, 7.07, 7.08, 7.09, 7.1, 7.11, 7.12, 7.13, 7.14, 7.15,
      7.16, 7.17, 7.18, 7.19, 7.2, 7.21, 7.22, 7.23, 7.24, 7.25, 7.26, 7.27,
      7.28, 7.29, 7.3, 7.31, 7.32, 7.33, 7.34, 7.35, 7.36, 7.37, 7.38, 7.39, 7.4,
      7.41, 7.42, 7.43, 7.44, 7.45, 7.46, 7.47, 7.48, 7.49, 7.5, 7.51, 7.52,
      7.53, 7.54, 7.55, 7.56, 7.57, 7.58, 7.59, 7.6, 7.61, 7.62, 7.63, 7.64,
      7.65, 7.66, 7.67, 7.68, 7.69, 7.7, 7.71, 7.72, 7.73, 7.74, 7.75, 7.76,
      7.77, 7.78, 7.79, 7.8, 7.81, 7.82, 7.83, 7.84, 7.85, 7.86, 7.87, 7.88,
      7.89, 7.9, 7.91, 7.92, 7.93, 7.94, 7.95, 7.96, 7.97, 7.98, 7.99, 8.0, 8.01,
      8.02, 8.03, 8.04, 8.05, 8.06, 8.07, 8.08, 8.09, 8.1, 8.11, 8.12, 8.13,
      8.14, 8.15, 8.16, 8.17, 8.18, 8.19, 8.2, 8.21, 8.22, 8.23, 8.24, 8.25,
      8.26, 8.27, 8.28, 8.29, 8.3, 8.31, 8.32, 8.33, 8.34, 8.35, 8.36, 8.37,
      8.38, 8.39, 8.4, 8.41, 8.42, 8.43, 8.44, 8.45, 8.46, 8.47, 8.48, 8.49, 8.5,
      8.51, 8.52, 8.53, 8.54, 8.55, 8.56, 8.57, 8.58, 8.59, 8.6, 8.61, 8.62,
      8.63, 8.64, 8.65, 8.66, 8.67, 8.68, 8.69, 8.7, 8.71, 8.72, 8.73, 8.74,
      8.75, 8.76, 8.77, 8.78, 8.79, 8.8, 8.81, 8.82, 8.83, 8.84, 8.85, 8.86,
      8.87, 8.88, 8.89, 8.9, 8.91, 8.92, 8.93, 8.94, 8.95, 8.96, 8.97, 8.98,
      8.99, 9.0, 9.01, 9.02, 9.03, 9.04, 9.05, 9.06, 9.07, 9.08, 9.09, 9.1, 9.11,
      9.12, 9.13, 9.14, 9.15, 9.16, 9.17, 9.18, 9.19, 9.2, 9.21, 9.22, 9.23,
      9.24, 9.25, 9.26, 9.27, 9.28, 9.29, 9.3, 9.31, 9.32, 9.33, 9.34, 9.35,
      9.36, 9.37, 9.38, 9.39, 9.4, 9.41, 9.42, 9.43, 9.44, 9.45, 9.46, 9.47,
      9.48, 9.49, 9.5, 9.51, 9.52, 9.53, 9.54, 9.55, 9.56, 9.57, 9.58, 9.59, 9.6,
      9.61, 9.62, 9.63, 9.64, 9.65, 9.66, 9.67, 9.68, 9.69, 9.7, 9.71, 9.72,
      9.73, 9.74, 9.75, 9.76, 9.77, 9.78, 9.79, 9.8, 9.81, 9.82, 9.83, 9.84,
      9.85, 9.86, 9.87, 9.88, 9.89, 9.9, 9.91, 9.92, 9.93, 9.94, 9.95, 9.96,
      9.97, 9.98, 9.99, 10.0, 10.01, 10.02, 10.03, 10.04, 10.05, 10.06, 10.07,
      10.08, 10.09, 10.1, 10.11, 10.12, 10.13, 10.14, 10.15, 10.16, 10.17, 10.18,
      10.19, 10.2, 10.21, 10.22, 10.23, 10.24, 10.25, 10.26, 10.27, 10.28, 10.29,
      10.3, 10.31, 10.32, 10.33, 10.34, 10.35, 10.36, 10.37, 10.38, 10.39, 10.4,
      10.41, 10.42, 10.43, 10.44, 10.45, 10.46, 10.47, 10.48, 10.49, 10.5, 10.51,
      10.52, 10.53, 10.54, 10.55, 10.56, 10.57, 10.58, 10.59, 10.6, 10.61, 10.62,
      10.63, 10.64, 10.65, 10.66, 10.67, 10.68, 10.69, 10.7, 10.71, 10.72, 10.73,
      10.74, 10.75, 10.76, 10.77, 10.78, 10.79, 10.8, 10.81, 10.82, 10.83, 10.84,
      10.85, 10.86, 10.87, 10.88, 10.89, 10.9, 10.91, 10.92, 10.93, 10.94, 10.95,
      10.96, 10.97, 10.98, 10.99, 11.0, 11.01, 11.02, 11.03, 11.04, 11.05, 11.06,
      11.07, 11.08, 11.09, 11.1, 11.11, 11.12, 11.13, 11.14, 11.15, 11.16, 11.17,
      11.18, 11.19, 11.2, 11.21, 11.22, 11.23, 11.24, 11.25, 11.26, 11.27, 11.28,
      11.29, 11.3, 11.31, 11.32, 11.33, 11.34, 11.35, 11.36, 11.37, 11.38, 11.39,
      11.4, 11.41, 11.42, 11.43, 11.44, 11.45, 11.46, 11.47, 11.48, 11.49, 11.5,
      11.51, 11.52, 11.53, 11.54, 11.55, 11.56, 11.57, 11.58, 11.59, 11.6, 11.61,
      11.62, 11.63, 11.64, 11.65, 11.66, 11.67, 11.68, 11.69, 11.7, 11.71, 11.72,
      11.73, 11.74, 11.75, 11.76, 11.77, 11.78, 11.79, 11.8, 11.81, 11.82, 11.83,
      11.84, 11.85, 11.86, 11.87, 11.88, 11.89, 11.9, 11.91, 11.92, 11.93, 11.94,
      11.95, 11.96, 11.97, 11.98, 11.99 } ;

    static real_T pDataValues0[] = { 1.0652067953741382, 0.64741852392668231,
      0.88928073382161632, 0.89887181313546838, 1.2367197431966785,
      1.1824815374885052, 0.934329610081437, 1.2725380382299327,
      1.0387335899440853, 1.1176953023944844, 0.60993375753995727,
      0.89372771537640061, 0.87273792342028433, 0.98177689295902126,
      1.0620787129098597, 1.0185789132204941, 0.827661645243652,
      1.3073817022549907, 1.1288585957567669, 1.0897414779206294,
      1.2250737179061097, 0.9548472840260438, 0.99731243147155424,
      1.273182478850277, 1.2355117373111209, 0.73357647556068784,
      1.3736669206662491, 1.0602620219137071, 0.91265187248668866,
      0.95830864061250687, 0.91125872076507863, 0.89544121027781365,
      1.186407292123884, 1.3306798221680995, 1.2246018243434835,
      1.1063344811861635, 1.1509653194041416, 0.84900628674529866,
      1.2871812750218825, 1.2962027286049143, 0.76333419563066474,
      0.87029906968856718, 1.2787012753566109, 0.98024983966561363,
      0.94753998303976472, 0.59874809064601919, 1.0014642039064634,
      0.91370643552728426, 0.90942634892971419, 0.73293773951661589,
      1.0946857333136641, 1.5069329329402441, 0.90489279180419691,
      0.990534988311862, 1.0748380790445839, 0.87563040904980927,
      1.1031248369025795, 1.0076474832418552, 0.89960081216190524,
      0.99277254144640192, 1.124518023587566, 0.83716634378388233,
      1.0273771743139293, 1.0157003347181963, 0.85713331906033974,
      1.2255234657130483, 0.77980611493417362, 1.1353704133840872,
      0.843395516125313, 0.96564056306560331, 1.1968623815627637,
      1.052581931861063, 0.672971988158668, 0.85693774506962339,
      0.84089670017740559, 0.83735679239503613, 1.0767410542609612,
      1.0365592225901064, 0.76497002010768922, 1.5963389545455311,
      1.0218716676641868, 0.66896847942058657, 0.9678238722123057,
      0.89407354185164045, 0.85593244956226033, 0.847497623437567,
      1.2298701770401075, 1.0651688116627402, 0.99896844135416574,
      0.97941563674893672, 1.0091994923378143, 0.92748399324697761,
      0.81731146070851579, 0.672086044333259, 1.0277992821749189,
      0.92460856571172079, 0.84249187484729715, 0.95032530364215617,
      1.0764858207075831, 1.0010413129191413, 1.1280585573702844,
      1.1077058871469234, 1.1394345083300856, 1.0343417058070798,
      0.86510748390166292, 1.3826833521323465, 1.3017072667874479,
      0.78404532389639026, 1.0345513166068108, 0.68132125941879851,
      1.2099448953456302, 1.0112617890440623, 0.827279369863277,
      0.48453559920311795, 0.60089198130969823, 1.3777734138103721,
      0.68077367310497938, 1.1345542443088896, 0.87314963200270757,
      1.0619506580778333, 1.1975763747146151, 1.1089789200022242,
      1.20241052278423, 1.0636427764786014, 0.92053153260585385,
      1.3665889583499831, 1.2038109274616449, 0.77322354835840323,
      0.79561719993582192, 1.1380175049314549, 1.0666897223875964,
      1.0466302706559374, 1.0413225874931133, 0.88848834675727262,
      1.0560566449829083, 1.358349288375714, 0.96984740313500573,
      0.780759782569211, 0.58013805425207621, 1.1323793735487337,
      1.0175499664952337, 1.0563352154511398, 1.0076907516440095,
      0.76241715346724948, 1.2063726961806911, 1.3671475200762351,
      1.0520583125292018, 1.0739238073691024, 1.0225990965758776,
      1.0963328974541138, 0.94273164846162938, 0.81933516489211422,
      1.0850354675960343, 0.970410860102451, 1.0191705110778944,
      0.76318248052809545, 1.1548219192724762, 1.0320998482380479,
      0.901994508994099, 0.751207502171013, 1.0941128255410337,
      1.0175679486187532, 1.1043386224271767, 1.0450490642919605,
      1.2763998462694124, 0.941410758223634, 0.93906489953166861,
      1.0162468815077472, 1.2713303014560524, 0.94694526752107289,
      1.0173894006357689, 1.0491092337347914, 0.98895288348389043,
      0.98675942918328274, 0.88162141440487884, 0.85892540060840139,
      0.92771788024154866, 0.99555094774062947, 1.0831502461044824,
      0.75871369006498657, 1.2870740494762973, 0.96014917304499581,
      0.971775131902994, 1.2244632972919434, 0.9454986127831726,
      1.1052054452760696, 0.89267608304126189, 0.71931823498209591,
      1.0286037502535619, 0.94324838674856193, 1.1694654848311341,
      0.74483637332588737, 1.1676988196192131, 0.91289790449443142,
      1.1219039975413616, 1.1112317324932464, 1.0455335233317677,
      1.0092424343587956, 0.85923255007087918, 1.1284828448868858,
      1.0480935616308684, 1.250535071620686, 0.9262616957750216,
      1.1837869954649793, 1.3929798594222798, 0.93025315904119066,
      0.91986580961540609, 0.98724163481811433, 0.984566216452088,
      0.88150372517381559, 1.0974052469864726, 0.98548673442996659,
      1.0540145483892582, 0.93768124422239385, 1.4775891859611343,
      1.143115211978565, 1.1147963855925347, 1.0996428778101053,
      0.88318777812523608, 1.1016187410515201, 0.79223074505206459,
      1.3537213493220894, 1.1463196608483657, 0.62747410768502387,
      1.073853792810546, 0.94474204109665483, 1.0841396840011981,
      1.0111470160014342, 1.125717430879325, 1.0013876476893107,
      0.849727467175754, 1.0019879825018645, 1.1801825105242016,
      0.98362830488023045, 0.90741517429663865, 1.0411039305327283,
      0.8426910652428512, 0.92577090672777229, 0.9166013694491939,
      0.91001241567401214, 1.4486868645317554, 1.3812188295425765,
      0.81054333017087554, 1.0024949250037134, 0.87401610252383344,
      1.358724369144904, 1.3682776189361696, 1.0209640244955152,
      0.84403577266892327, 0.96159209787235778, 1.2139883054246172,
      1.1097278217760571, 0.76022151602125609, 1.0463981508214275,
      1.1042919862252032, 1.1582853391576509, 0.82905911091763762,
      0.88192373519270262, 0.72097455139827726, 1.0606395671535191,
      1.067414271060281, 1.2025949600766366, 0.528488990204705,
      0.94858271314640763, 1.3060001896183446, 1.008255901297523,
      0.96502619355565167, 0.97539787978902093, 0.96052790999375737,
      1.0295822708089397, 1.0237061027389727, 0.81740455273115642,
      1.110649099812653, 1.0465360143207558, 1.0788203106608671,
      0.81214144305668656, 1.2227370106414412, 0.92113497524841581,
      1.0623489382283537, 1.2713294275345002, 1.1313804142755242,
      0.68639076911758234, 1.003681392002221, 1.0429755533219049,
      1.0020711934786453, 0.81759437919849076, 1.0885113310440382,
      0.94713672992640086, 0.97110974310068765, 1.1759728212468969,
      0.91555682346207934, 0.90336872709820681, 0.87353066295677539,
      1.044427519367197, 0.953325199041415, 0.619463336134765,
      0.87797903550040957, 1.0764355121158797, 0.98199196997035576,
      0.9949500066173329, 1.4099674197343983, 0.740875189829826,
      1.0441936809010337, 0.764297318980482, 0.818467641353219,
      0.99059780068046133, 0.79013486555696222, 0.99695903655779061,
      1.0793157032065541, 1.1222202725147139, 1.2892096812364726,
      0.920840660366139, 1.1338658126685552, 0.78579535054999938,
      1.1458854314618594, 0.993789824981024, 0.982969517470857,
      0.95924768903195856, 0.95790217173493786, 1.1444123271112605,
      0.86434858554040728, 1.1000857895923084, 1.0826666959172813,
      0.94668782406995367, 0.73753853081026555, 1.0422221296616749,
      1.3190689565683815, 1.0717627827186458, 0.84532056197823457,
      0.82085343933923616, 0.91783714151331, 1.1246616765422086,
      1.1817824258129712, 0.96518214863828566, 1.1552500414494073,
      1.3445421541811233, 1.0173239436539325, 1.0844393682178703,
      1.3447239615380675, 0.65787851609953474, 0.941797161796306,
      1.2846567020152468, 1.0402832087086857, 1.1626269539938181,
      0.79137358306968264, 1.2856266407329189, 1.1909073662422469,
      1.176859506726065, 0.91365361794995481, 1.0424259882197817,
      0.99359460415656686, 1.2523239705196434, 0.79766218376023434,
      0.98694790499322282, 0.7037187620272034, 1.0512871479262729,
      1.1044624784842283, 0.89737779412790264, 0.93268714290075116,
      1.2226110854120202, 0.96201410385488817, 0.80058614453468147,
      0.89867908947508823, 0.88661649901573769, 1.0920315160227076,
      0.96561341427729142, 1.1736041116287885, 0.97220511744228733,
      0.97576432363178112, 1.0734466215413774, 0.97031130471753824,
      0.937982972975213, 0.96871823476134233, 1.2325554211936343,
      1.0009330201223665, 0.63385072873239445, 0.80316241274429956,
      1.0149430447706125, 1.2529622341114368, 0.60195445397559577,
      0.82606904216256927, 0.67190960196450589, 0.99538872531519262,
      0.94699249565571375, 1.1545794163594021, 0.67192172718014709,
      1.0720945314485764, 1.0553901688787579, 1.2606987904118721,
      1.0467482332462614, 1.0465630960165928, 1.1764373680659406,
      1.0091294523507264, 0.84437539498500414, 0.98652625337698274,
      0.971815170550329, 0.64416401985846383, 0.7740566767549707,
      1.0574795597125846, 0.95819038539303558, 0.777052050792281,
      1.0519236314029399, 1.0853643663445878, 1.1637739866224981,
      1.0327445242796933, 1.1254445382706895, 1.2144021394832556,
      0.59841245361909023, 1.2067134140871634, 0.84183053357824278,
      1.0379900107985764, 1.1700752335549374, 0.87269761411403357,
      1.0761455928667225, 1.0862312902363127, 0.93998874386833742,
      0.90505652948155491, 0.78951042141676975, 1.1965871278015712,
      1.0126394954914808, 1.0390355643840086, 0.94348723872373741,
      1.2795698181297113, 0.72572703659912285, 0.75570501420411218,
      1.2160862127945229, 0.74287204480782676, 0.69328439875301151,
      1.142945247861251, 1.1034161375910627, 0.983989458431859,
      0.87426298576987138, 0.83299625494451268, 0.87081774766233055,
      0.99089040662824013, 1.0957426861346711, 0.89995700789162614,
      0.71473465222616517, 1.0047443143694634, 0.86932185144472018,
      1.0554805162236522, 0.60836173183372944, 0.85496707889055479,
      1.087044877541804, 0.82812529254783374, 1.254188971238098,
      1.1325309014939724, 0.85291212049208776, 1.0198513195490941,
      0.99372908385382808, 0.76308050822839935, 1.0298725261360651,
      1.0728204838016826, 1.2226535546480117, 1.1743782963258091,
      0.69531915730588245, 1.0965175656837256, 1.2032372447476796,
      0.917294597874912, 0.859156218592009, 1.0715891665859603,
      0.95521109643684321, 0.92270797509248248, 0.94095354313467294,
      0.91998682900245388, 0.62583769738755013, 0.80736862394951547,
      1.0783569926037473, 1.0035320515779229, 1.1381405631229269,
      0.60303337066311258, 1.3035967606375982, 0.80746982419055613,
      1.090788874170312, 0.94446369346749126, 0.954863999688655,
      1.2342366862620238, 1.0272388752856543, 0.97622347336596771,
      0.59365770161988873, 0.95233410593105483, 0.77211201025075371,
      0.94085563265243588, 0.81403427978028331, 1.0664963689555744,
      0.95614603337201043, 0.76552922169631588, 0.9211084194835566,
      1.0587477003352608, 0.9462677240183589, 0.82796768863008186,
      1.094745376532668, 1.0703997019681364, 0.86122286829779049,
      0.970290307947593, 0.90947792722468868, 0.83423134396396392,
      0.85146304254897032, 0.64059057152082, 1.0687988745479566,
      1.5092548255857086, 1.0558362521854441, 1.1271332739108171,
      1.2580539076398056, 0.79186155156608484, 0.89200752173656639,
      0.65093815960931933, 1.1344038642276448, 0.89311716292259191,
      0.990162334426579, 0.61346999699203075, 1.2572065440259386,
      1.1389144871148826, 0.91343953533696209, 1.5100012077525615,
      0.75664072063939625, 0.76667546403761044, 1.1348969492400451,
      1.1588955278514204, 0.90200343652137016, 0.94145834084516378,
      0.9212135025247532, 0.89676919040864289, 0.93746745586877434,
      0.96006326845943635, 1.1244814417039151, 1.1686603566874321,
      1.043073873965769, 1.0178331679259849, 0.87620445094956378,
      0.74948984404689034, 0.96797521724547353, 0.83686600427791924,
      0.74634229466419377, 1.2285271409382879, 1.0735684993344339,
      1.3274827152361515, 1.2106825005975317, 0.86517286477522326,
      0.76050886270988238, 0.79589683265633, 0.86518610675740648,
      0.72102027922732648, 1.0106810141550164, 0.802716564272755,
      0.75664906960821932, 1.0549793904744698, 1.0762270676343255,
      1.025712198432825, 1.1741866298649946, 1.063667462346519,
      1.0336480456503967, 0.7942098130631704, 0.77452645614540439,
      0.92226160335144258, 1.1004590448615774, 1.0228673701768036,
      1.07775112638787, 0.99798245213835191, 1.2108923452885925,
      0.75012318350733831, 1.5420407485800389, 1.0159175132747624,
      0.83989737944722132, 0.90500837446315863, 0.47297866841659031,
      1.1610957654122296, 1.0812389065089552, 1.0588604386769578,
      1.3319110846056479, 1.1369029696615029, 1.3433054925451258,
      1.0917498930814642, 1.172327550880109, 1.2545078700153631,
      1.1681520118673456, 0.94876899402059434, 1.0269426612738113,
      0.8907227368812779, 0.87029168603666029, 0.77394305558161225,
      0.946396080574461, 1.0204579977550676, 0.70547589032153923,
      1.0298581709079668, 1.0298355976160318, 1.0304108530932521,
      1.0975373911348989, 0.73075714648923351, 0.73147166048414269,
      1.1045451057608306, 0.72109383231808732, 0.99016981569348506,
      1.0587985646953579, 0.89345435715179256, 0.90146492776407794,
      1.288788520250113, 0.78727074262136676, 1.1960887342154716,
      1.1856313211378708, 0.78785692439953625, 0.75611376675859876,
      1.1099350731600155, 0.83276443080320783, 1.073139717577055,
      0.966597264043629, 1.202945779999105, 1.1930140490772581,
      1.0213857314243941, 1.2277410221541973, 0.88910454252146331,
      1.1796264905657443, 0.68668865445068628, 1.0645257100075409,
      0.96903323026352717, 1.0779122690970548, 1.034947462765931,
      0.94641347549470567, 0.76804296679255479, 0.89423366592387044,
      0.8819687596220509, 0.891133938696544, 0.96182367610464159,
      0.95783868568345221, 0.87902949198647506, 1.2440064584968329,
      0.89683606476326583, 0.75676433086691752, 0.96502190094253559,
      1.3317440172330819, 0.64724480548432084, 0.86252804136058492,
      0.86171607822413865, 0.64979338106379925, 0.89681914814997488,
      1.058410074040907, 1.2876145427824603, 0.93589565039135647,
      0.96482132596204229, 1.186869186314681, 1.0309015378886295,
      1.0553313055352869, 0.93139216927401225, 1.3620095701724049,
      1.3175033401929683, 0.78932142291349927, 0.95981028477732577,
      0.95390834479376163, 1.1713785466254103, 0.90577350338872642,
      1.1180784028041622, 0.76761118141162066, 1.0126639843044054,
      1.0716932249474613, 0.77035889099202726, 0.91876886471217756,
      1.1687001270126045, 1.3759901191047672, 1.07622357873798,
      1.0339011822349695, 1.249747222680597, 1.0603066286899974,
      0.85093651802855463, 0.97279095356092116, 0.80118707504885789,
      1.0799297464971489, 1.105571516234624, 0.890903509476581,
      0.8663286078817769, 1.193092072463863, 0.61021087621493431,
      1.1581097041596053, 0.87151495288530034, 1.3176574686479823,
      1.1139263684295877, 0.81835445949891783, 0.83697512851211608,
      1.145882904523891, 0.76790547664834741, 1.0529089497470809,
      1.0031292391883813, 0.78020628661820535, 1.1181299195140939,
      0.96349150137289408, 0.99474147179965167, 0.99127914308472953,
      1.1325621054131352, 0.96123599643221358, 1.1627092259689851,
      0.78714353711048934, 0.9992848668021056, 0.80749331482667808,
      0.7453347072720975, 1.1163338136048986, 1.3472912814038107,
      1.0648832061148317, 0.91093910063725136, 1.0357089231223051,
      0.979109636631619, 1.2297614805934496, 1.0955631263340071,
      1.0322653692197554, 1.1994240467970336, 1.3002090403628057,
      1.0540755234834991, 0.88319308835833144, 1.2625546127096394,
      1.0312061787993398, 1.1257935766274243, 1.1818587316119222,
      0.9095451987143427, 0.76574426927221684, 0.95361476561768432,
      1.2871411945287694, 0.94410852413692226, 0.96778318380865813,
      0.83940266232445782, 1.1675119081448946, 0.96747369218801571,
      0.82839115924046491, 0.983666774019542, 0.66579782331457116,
      0.91137930626087582, 1.0136551302783394, 0.99182511770764392,
      1.1714915015757932, 0.7775609016561229, 1.0055523568529199,
      1.0936699065157098, 1.0615063217480136, 1.0804524520417538,
      1.055620050234686, 1.0277251619976144, 0.74955056962226618,
      0.97299710010227236, 0.99798222883162435, 1.1776345714980381,
      1.00860264534703, 0.8895286900024314, 0.98782614205656127,
      0.87121396926293992, 1.0319079641849558, 0.93582612257594011,
      1.0144394720591758, 1.105625569993927, 0.75771389612610363,
      0.95744807663380171, 0.82951822206045489, 1.0145741379359492,
      1.0376380268115082, 0.94502635625965381, 1.2561180233628815,
      1.1364572416682632, 1.2272692864693917, 1.1739008882128914,
      1.3284406455998083, 1.0985368150358155, 1.1105423339148042,
      0.93515831566127616, 0.75341831400211379, 0.9023695448905773,
      1.0687521972698444, 1.1521173308974231, 0.86185356799884083,
      0.64557264230331357, 1.0871109827661534, 1.1482595612942443,
      0.90069992129838472, 1.1544782440243284, 0.95804780687709179,
      1.0851620656997858, 1.0404421500869474, 0.91149300864089777,
      0.83480843747541089, 0.8806417916042969, 1.2635229691220755,
      0.76861186139316273, 1.1010939771957371, 0.93929716793857743,
      1.0114082778246756, 0.87620037354205538, 1.1652268995699375,
      0.94708820559004436, 0.91342620728941248, 0.86138029411954042,
      0.98521873372821711, 1.0909609678350691, 0.99263694650413925,
      1.2855450383834739, 0.99312179004236079, 0.83551002665243446,
      0.818458746176368, 1.0400766247372715, 1.2238488415444368,
      1.0586860461290424, 1.0455652867523033, 1.0404572460889281,
      1.0335619002261294, 0.85083898909623334, 0.90953657287982415,
      1.0557374728541251, 1.3481916385885866, 1.1730218276234989,
      1.1870676859280866, 1.1319300407947184, 0.7494366245373979,
      1.2073006106671313, 0.51471186012387649, 0.93819718516046191,
      1.1069837951114176, 1.0341211441514677, 1.0871490764464498,
      0.817058392908406, 0.79978260040030846, 0.9995596517127262,
      0.93050598039656141, 0.7929136937711474, 0.85319771160648172,
      1.0268490532650443, 0.63778728279596963, 0.72874926258673178,
      1.1861967447596997, 1.0052458448879245, 1.4382353983896303,
      1.079435656025195, 1.1210559049214823, 0.8629347165404232,
      1.2718021922459892, 0.9748882450751396, 0.69742111270307694,
      0.71318898585509483, 0.90416213973816706, 1.0508597265252757,
      0.593392944271111, 0.862559294009897, 0.92545329216293037,
      1.1125148440059738, 0.95789046441363668, 0.72864517496017966,
      1.017403926684336, 1.3853852071874879, 0.941235912358242,
      1.0134939511210839, 1.1602654484701216, 0.80599398388182164,
      0.5632058007765337, 1.1470893090681009, 0.90151798735396571,
      1.3331878152897851, 0.8222447683515548, 0.97643353614699779,
      0.72766814438398, 0.88555076781978292, 1.0191016636648147,
      0.91516371731216606, 1.2160584000820349, 1.0092659711730487,
      0.88981518619791156, 1.1814277236905073, 0.64286779889319523,
      1.0077966776989382, 1.0988289077305988, 1.1142690126398991,
      1.1242326653846337, 0.97716945046361092, 1.1687271076178529,
      0.9976817044181564, 0.65223945339791478, 0.98020234354587477,
      0.85947281610641491, 0.83209528045165715, 0.933201877773617,
      0.86223911012527787, 0.964286090543529, 1.2384057195784659,
      1.2166829595727076, 1.2807485853480292, 0.88598160879887056,
      1.04918863269824, 1.350633302339745, 1.1019560981865966,
      0.82022214842103558, 1.133636568121092, 1.1706890025976355,
      0.93457954981747382, 0.87177886116305114, 1.0654187630611183,
      1.1340194379950319, 1.0817027656962461, 0.71750365383639325,
      0.95101096058533185, 0.75112736712795714, 0.77488618296249234,
      1.1345686047580326, 0.97132675104827315, 1.0190260232773098,
      0.89143306265280309, 1.1866757161222234, 0.84124102800627965,
      0.67286724547038723, 1.0722576847668646, 1.0850448287055043,
      0.9934508670201857, 1.3985982348887451, 1.0039831553302909,
      0.92602564751804728, 1.0231851916494963, 0.91971506396722413,
      1.2050458172563543, 0.7349899145099521, 0.801988028230364,
      0.98616505576524327, 0.890504995671136, 0.96187386818286225,
      0.99859104465646564, 1.2397240004969272, 1.1279395895843831,
      0.78139855902349264, 0.81988588010607155, 0.93727032425178081,
      1.3680098847638937, 0.86685450928438312, 0.91001600335296584,
      0.91332848315427873, 0.96136908738857652, 0.57247210730827236,
      1.1393831450291267, 0.80838004772965211, 1.1893999208576951,
      1.2082419517915033, 0.67224572797343241, 1.2256324192267292,
      0.79725845249037919, 0.76381704298420816, 0.9323653365965634,
      0.82999368611014834, 0.68124731431486607, 1.1041746632754725,
      1.1308095143547723, 1.0727710172002609, 0.91671369811223646,
      1.14744640135703, 1.0672619778523518, 0.87123227276855009,
      1.1089357924284964, 0.83566152328906851, 0.76413362580751953,
      1.0081729310065715, 1.0508708910249411, 0.77140383458441342,
      1.2972704991308328, 0.93370039935090754, 1.1485641745392117,
      0.983952197070514, 0.63613691471408362, 0.687148203447105,
      1.1988388228836806, 0.820289777558471, 1.419785196377692,
      0.99960680696599191, 1.1719798769459759, 0.93582723924762057,
      0.8645915440360743, 1.1984706919544839, 0.84960851761403922,
      0.664961831652543, 0.71626817102335327, 1.1653723363262638,
      0.93364249758077511, 1.0877968718167261, 1.0832507567871592,
      0.84019491644564781, 1.0189683286952373, 1.1360229010764007,
      0.977444301648592, 1.0385965143990707, 0.9797622444219628,
      1.1627338928920641, 0.81185190776697747, 1.174531555724297,
      0.82159929593833825, 0.87194791849044129, 1.010593005562487,
      0.8548639900611088, 1.0794816875851014, 1.1428112675236188,
      1.2786513998093914, 1.1872256283389031, 1.1340936548040401,
      1.1027998257208951, 1.0680057159417309, 1.0266593388298033,
      1.1388218046619316, 0.90018617679008872, 1.0206329281036037,
      1.3612206492739651, 1.1192213027347229, 1.06097763017991,
      1.0326095542999087, 1.3188018521466862, 0.5712093612370398,
      1.0213434622037987, 0.91259585034672686, 0.82713543768457953,
      0.7486863485339954, 0.96783106078854753, 0.96460905529161234,
      0.92097699856996429, 1.0681830196427768, 0.907536660729564,
      0.98612476252365311, 1.1693460846715669, 0.79555766537163108,
      1.0717447566287606, 0.92036342690734507, 0.95984181362257426,
      1.0838072196961368, 1.0543656852233207, 1.0553213287998753,
      1.0975117988376126, 1.0930830109617884, 1.1661260692452862,
      0.94729155564366041, 1.1144810358607431, 1.2993242421647182,
      0.86781857018944275, 1.0257475949704127, 1.0780657017334976,
      1.3356783430948176, 0.77892932493288125, 1.2418851621333853,
      1.0349732225613306, 0.88024905674327669, 0.86362012685127088,
      0.89267006217412626, 0.79063212485279921, 0.94113659063756927,
      0.88033658420352179, 1.2840913189158365, 1.2120613941218039,
      1.0000539137714772, 1.0365374165546872, 1.0808641994142643,
      1.189191134389759, 1.1462900464469747, 0.52324935663427441,
      0.76599040649691919, 0.90713076757927735, 1.1581088962169588,
      1.1855226359117366, 0.86729673213852376, 1.0589285371494472,
      0.947669517672535, 1.0643496408825828, 1.2182048677094273,
      0.92342297498990167, 1.3626624747636946, 0.90691876902663382,
      0.91594937915910657, 1.1345104627506784, 0.90342030411642638,
      0.80576007844879471, 0.9049327166872787, 1.2088834692397743,
      0.98085514882353408, 0.95817212160302689, 1.1057314029824421,
      0.88064065745483278, 1.2679351090335476, 0.84979572330688669,
      1.2388160209552934, 1.2437957055113715, 0.57474369676867854,
      0.89273117951404157, 1.0176695344451916, 1.2559250998831113,
      1.0695826056052371, 1.0246341583331859, 0.80815964705816945,
      1.0432560968442404, 1.1286031182982237, 1.313545634081019,
      0.90365426035204588, 0.89908862435341019, 1.1139459751918439,
      0.87762202564033931, 1.1093052171319131, 1.0200868637524367,
      0.8255919264559114, 0.97534596360698733, 1.0705658409112255,
      0.8664837936872799, 0.99093495032861556, 0.714983684345876,
      0.954056739771692, 0.75871448880544767, 1.1302566703706571,
      0.96340819571297875, 1.2289193696205309, 0.8436683669550078,
      1.2995880489825116, 0.93696527405393881, 0.86715099935656836,
      0.86683860991517148, 0.87483753247782547, 0.97500061265062177,
      0.97820085740776974, 0.60082753975316661, 0.91519771877932776,
      0.93517981390522786, 1.3090433250035516, 1.1314865097504632,
      0.84992391347324636, 0.8814188574773737, 1.4310260027641226,
      1.1637672504943424, 1.1725012409878774, 1.1409919062987492,
      0.80534658207170029, 0.862454395236576, 1.003676605829128,
      1.1580199055468281, 0.90264704742817081, 0.98534592513647046,
      1.0788673281002819, 1.248004528305491, 1.2274697364202338,
      0.90631448522493152, 0.96779974746023734, 0.87789825026345669,
      0.8960358404884311, 0.94870637589993145, 0.90535962368831158,
      0.82354878906682849, 0.96126920530771787, 0.7685971286698331,
      1.1596400982009865, 0.97780869449468577, 0.91481002528935662,
      1.3183582127786526, 0.93591414741606127, 1.1539811119654306,
      0.92614379756693477, 0.904691632893526, 0.81308298493440478,
      1.2331042544723585, 0.98185308700278706, 0.63028953082527472,
      1.1528148736804709, 0.93509505725517794, 1.3129447064011452,
      1.2172995203011558, 0.663130059814342, 1.1437719154959614,
      1.24208764442493, 0.77400636853400029, 1.2463517837856408,
      0.96765404700935564, 1.2451978425859596, 1.0199739064836175,
      0.790901443309225, 1.1037709310860866, 1.0524302037012621,
      0.91309336928851448, 0.9492003979093101, 0.79689998200416146,
      1.1013583833966838, 1.2828345736249629, 0.839953839826416,
      1.1092956583586886, 0.98711024391848, 0.87368641495852917,
      1.0583942672335349, 0.8210500929287583, 0.860819694030861,
      0.95176248493427107, 0.75045039773949818, 1.0054808960128303,
      1.0108029184256648, 1.2257809856541082, 1.3346676015185064,
      1.1905967436203779, 0.99728842446218557, 1.028772963204841,
      1.1221343020132564, 1.0211834441241587, 1.0568172986520439,
      0.8771447081802336, 0.920284324011515, 1.2082937929808288,
      1.0499103827089449, 0.88201271056849706, 1.0670159392108425,
      1.0579166532992952, 1.1111247888221236, 1.0300967306073989,
      0.81720754880885615, 0.71080903357924319, 1.2052949032752287,
      1.0165794579373051 } ;

    Madgwick_embedded_DW->GyroX_PWORK.TimePtr = (void *) pTimeValues0;
    Madgwick_embedded_DW->GyroX_PWORK.DataPtr = (void *) pDataValues0;
    Madgwick_embedded_DW->GyroX_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/GyroY' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06,
      0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18,
      0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31,
      0.32, 0.33, 0.34, 0.35, 0.36, 0.37, 0.38, 0.39, 0.4, 0.41, 0.42, 0.43,
      0.44, 0.45, 0.46, 0.47, 0.48, 0.49, 0.5, 0.51, 0.52, 0.53, 0.54, 0.55,
      0.56, 0.57, 0.58, 0.59, 0.6, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67,
      0.68, 0.69, 0.7, 0.71, 0.72, 0.73, 0.74, 0.75, 0.76, 0.77, 0.78, 0.79, 0.8,
      0.81, 0.82, 0.83, 0.84, 0.85, 0.86, 0.87, 0.88, 0.89, 0.9, 0.91, 0.92,
      0.93, 0.94, 0.95, 0.96, 0.97, 0.98, 0.99, 1.0, 1.01, 1.02, 1.03, 1.04,
      1.05, 1.06, 1.07, 1.08, 1.09, 1.1, 1.11, 1.12, 1.13, 1.14, 1.15, 1.16,
      1.17, 1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28,
      1.29, 1.3, 1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37, 1.38, 1.39, 1.4, 1.41,
      1.42, 1.43, 1.44, 1.45, 1.46, 1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53,
      1.54, 1.55, 1.56, 1.57, 1.58, 1.59, 1.6, 1.61, 1.62, 1.63, 1.64, 1.65,
      1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75, 1.76, 1.77,
      1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.85, 1.86, 1.87, 1.88, 1.89, 1.9,
      1.91, 1.92, 1.93, 1.94, 1.95, 1.96, 1.97, 1.98, 1.99, 2.0, 2.01, 2.02,
      2.03, 2.04, 2.05, 2.06, 2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14,
      2.15, 2.16, 2.17, 2.18, 2.19, 2.2, 2.21, 2.22, 2.23, 2.24, 2.25, 2.26,
      2.27, 2.28, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34, 2.35, 2.36, 2.37, 2.38,
      2.39, 2.4, 2.41, 2.42, 2.43, 2.44, 2.45, 2.46, 2.47, 2.48, 2.49, 2.5, 2.51,
      2.52, 2.53, 2.54, 2.55, 2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63,
      2.64, 2.65, 2.66, 2.67, 2.68, 2.69, 2.7, 2.71, 2.72, 2.73, 2.74, 2.75,
      2.76, 2.77, 2.78, 2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87,
      2.88, 2.89, 2.9, 2.91, 2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0,
      3.01, 3.02, 3.03, 3.04, 3.05, 3.06, 3.07, 3.08, 3.09, 3.1, 3.11, 3.12,
      3.13, 3.14, 3.15, 3.16, 3.17, 3.18, 3.19, 3.2, 3.21, 3.22, 3.23, 3.24,
      3.25, 3.26, 3.27, 3.28, 3.29, 3.3, 3.31, 3.32, 3.33, 3.34, 3.35, 3.36,
      3.37, 3.38, 3.39, 3.4, 3.41, 3.42, 3.43, 3.44, 3.45, 3.46, 3.47, 3.48,
      3.49, 3.5, 3.51, 3.52, 3.53, 3.54, 3.55, 3.56, 3.57, 3.58, 3.59, 3.6, 3.61,
      3.62, 3.63, 3.64, 3.65, 3.66, 3.67, 3.68, 3.69, 3.7, 3.71, 3.72, 3.73,
      3.74, 3.75, 3.76, 3.77, 3.78, 3.79, 3.8, 3.81, 3.82, 3.83, 3.84, 3.85,
      3.86, 3.87, 3.88, 3.89, 3.9, 3.91, 3.92, 3.93, 3.94, 3.95, 3.96, 3.97,
      3.98, 3.99, 4.0, 4.01, 4.02, 4.03, 4.04, 4.05, 4.06, 4.07, 4.08, 4.09, 4.1,
      4.11, 4.12, 4.13, 4.14, 4.15, 4.16, 4.17, 4.18, 4.19, 4.2, 4.21, 4.22,
      4.23, 4.24, 4.25, 4.26, 4.27, 4.28, 4.29, 4.3, 4.31, 4.32, 4.33, 4.34,
      4.35, 4.36, 4.37, 4.38, 4.39, 4.4, 4.41, 4.42, 4.43, 4.44, 4.45, 4.46,
      4.47, 4.48, 4.49, 4.5, 4.51, 4.52, 4.53, 4.54, 4.55, 4.56, 4.57, 4.58,
      4.59, 4.6, 4.61, 4.62, 4.63, 4.64, 4.65, 4.66, 4.67, 4.68, 4.69, 4.7, 4.71,
      4.72, 4.73, 4.74, 4.75, 4.76, 4.77, 4.78, 4.79, 4.8, 4.81, 4.82, 4.83,
      4.84, 4.85, 4.86, 4.87, 4.88, 4.89, 4.9, 4.91, 4.92, 4.93, 4.94, 4.95,
      4.96, 4.97, 4.98, 4.99, 5.0, 5.01, 5.02, 5.03, 5.04, 5.05, 5.06, 5.07,
      5.08, 5.09, 5.1, 5.11, 5.12, 5.13, 5.14, 5.15, 5.16, 5.17, 5.18, 5.19, 5.2,
      5.21, 5.22, 5.23, 5.24, 5.25, 5.26, 5.27, 5.28, 5.29, 5.3, 5.31, 5.32,
      5.33, 5.34, 5.35, 5.36, 5.37, 5.38, 5.39, 5.4, 5.41, 5.42, 5.43, 5.44,
      5.45, 5.46, 5.47, 5.48, 5.49, 5.5, 5.51, 5.52, 5.53, 5.54, 5.55, 5.56,
      5.57, 5.58, 5.59, 5.6, 5.61, 5.62, 5.63, 5.64, 5.65, 5.66, 5.67, 5.68,
      5.69, 5.7, 5.71, 5.72, 5.73, 5.74, 5.75, 5.76, 5.77, 5.78, 5.79, 5.8, 5.81,
      5.82, 5.83, 5.84, 5.85, 5.86, 5.87, 5.88, 5.89, 5.9, 5.91, 5.92, 5.93,
      5.94, 5.95, 5.96, 5.97, 5.98, 5.99, 6.0, 6.01, 6.02, 6.03, 6.04, 6.05,
      6.06, 6.07, 6.08, 6.09, 6.1, 6.11, 6.12, 6.13, 6.14, 6.15, 6.16, 6.17,
      6.18, 6.19, 6.2, 6.21, 6.22, 6.23, 6.24, 6.25, 6.26, 6.27, 6.28, 6.29, 6.3,
      6.31, 6.32, 6.33, 6.34, 6.35, 6.36, 6.37, 6.38, 6.39, 6.4, 6.41, 6.42,
      6.43, 6.44, 6.45, 6.46, 6.47, 6.48, 6.49, 6.5, 6.51, 6.52, 6.53, 6.54,
      6.55, 6.56, 6.57, 6.58, 6.59, 6.6, 6.61, 6.62, 6.63, 6.64, 6.65, 6.66,
      6.67, 6.68, 6.69, 6.7, 6.71, 6.72, 6.73, 6.74, 6.75, 6.76, 6.77, 6.78,
      6.79, 6.8, 6.81, 6.82, 6.83, 6.84, 6.85, 6.86, 6.87, 6.88, 6.89, 6.9, 6.91,
      6.92, 6.93, 6.94, 6.95, 6.96, 6.97, 6.98, 6.99, 7.0, 7.01, 7.02, 7.03,
      7.04, 7.05, 7.06, 7.07, 7.08, 7.09, 7.1, 7.11, 7.12, 7.13, 7.14, 7.15,
      7.16, 7.17, 7.18, 7.19, 7.2, 7.21, 7.22, 7.23, 7.24, 7.25, 7.26, 7.27,
      7.28, 7.29, 7.3, 7.31, 7.32, 7.33, 7.34, 7.35, 7.36, 7.37, 7.38, 7.39, 7.4,
      7.41, 7.42, 7.43, 7.44, 7.45, 7.46, 7.47, 7.48, 7.49, 7.5, 7.51, 7.52,
      7.53, 7.54, 7.55, 7.56, 7.57, 7.58, 7.59, 7.6, 7.61, 7.62, 7.63, 7.64,
      7.65, 7.66, 7.67, 7.68, 7.69, 7.7, 7.71, 7.72, 7.73, 7.74, 7.75, 7.76,
      7.77, 7.78, 7.79, 7.8, 7.81, 7.82, 7.83, 7.84, 7.85, 7.86, 7.87, 7.88,
      7.89, 7.9, 7.91, 7.92, 7.93, 7.94, 7.95, 7.96, 7.97, 7.98, 7.99, 8.0, 8.01,
      8.02, 8.03, 8.04, 8.05, 8.06, 8.07, 8.08, 8.09, 8.1, 8.11, 8.12, 8.13,
      8.14, 8.15, 8.16, 8.17, 8.18, 8.19, 8.2, 8.21, 8.22, 8.23, 8.24, 8.25,
      8.26, 8.27, 8.28, 8.29, 8.3, 8.31, 8.32, 8.33, 8.34, 8.35, 8.36, 8.37,
      8.38, 8.39, 8.4, 8.41, 8.42, 8.43, 8.44, 8.45, 8.46, 8.47, 8.48, 8.49, 8.5,
      8.51, 8.52, 8.53, 8.54, 8.55, 8.56, 8.57, 8.58, 8.59, 8.6, 8.61, 8.62,
      8.63, 8.64, 8.65, 8.66, 8.67, 8.68, 8.69, 8.7, 8.71, 8.72, 8.73, 8.74,
      8.75, 8.76, 8.77, 8.78, 8.79, 8.8, 8.81, 8.82, 8.83, 8.84, 8.85, 8.86,
      8.87, 8.88, 8.89, 8.9, 8.91, 8.92, 8.93, 8.94, 8.95, 8.96, 8.97, 8.98,
      8.99, 9.0, 9.01, 9.02, 9.03, 9.04, 9.05, 9.06, 9.07, 9.08, 9.09, 9.1, 9.11,
      9.12, 9.13, 9.14, 9.15, 9.16, 9.17, 9.18, 9.19, 9.2, 9.21, 9.22, 9.23,
      9.24, 9.25, 9.26, 9.27, 9.28, 9.29, 9.3, 9.31, 9.32, 9.33, 9.34, 9.35,
      9.36, 9.37, 9.38, 9.39, 9.4, 9.41, 9.42, 9.43, 9.44, 9.45, 9.46, 9.47,
      9.48, 9.49, 9.5, 9.51, 9.52, 9.53, 9.54, 9.55, 9.56, 9.57, 9.58, 9.59, 9.6,
      9.61, 9.62, 9.63, 9.64, 9.65, 9.66, 9.67, 9.68, 9.69, 9.7, 9.71, 9.72,
      9.73, 9.74, 9.75, 9.76, 9.77, 9.78, 9.79, 9.8, 9.81, 9.82, 9.83, 9.84,
      9.85, 9.86, 9.87, 9.88, 9.89, 9.9, 9.91, 9.92, 9.93, 9.94, 9.95, 9.96,
      9.97, 9.98, 9.99, 10.0, 10.01, 10.02, 10.03, 10.04, 10.05, 10.06, 10.07,
      10.08, 10.09, 10.1, 10.11, 10.12, 10.13, 10.14, 10.15, 10.16, 10.17, 10.18,
      10.19, 10.2, 10.21, 10.22, 10.23, 10.24, 10.25, 10.26, 10.27, 10.28, 10.29,
      10.3, 10.31, 10.32, 10.33, 10.34, 10.35, 10.36, 10.37, 10.38, 10.39, 10.4,
      10.41, 10.42, 10.43, 10.44, 10.45, 10.46, 10.47, 10.48, 10.49, 10.5, 10.51,
      10.52, 10.53, 10.54, 10.55, 10.56, 10.57, 10.58, 10.59, 10.6, 10.61, 10.62,
      10.63, 10.64, 10.65, 10.66, 10.67, 10.68, 10.69, 10.7, 10.71, 10.72, 10.73,
      10.74, 10.75, 10.76, 10.77, 10.78, 10.79, 10.8, 10.81, 10.82, 10.83, 10.84,
      10.85, 10.86, 10.87, 10.88, 10.89, 10.9, 10.91, 10.92, 10.93, 10.94, 10.95,
      10.96, 10.97, 10.98, 10.99, 11.0, 11.01, 11.02, 11.03, 11.04, 11.05, 11.06,
      11.07, 11.08, 11.09, 11.1, 11.11, 11.12, 11.13, 11.14, 11.15, 11.16, 11.17,
      11.18, 11.19, 11.2, 11.21, 11.22, 11.23, 11.24, 11.25, 11.26, 11.27, 11.28,
      11.29, 11.3, 11.31, 11.32, 11.33, 11.34, 11.35, 11.36, 11.37, 11.38, 11.39,
      11.4, 11.41, 11.42, 11.43, 11.44, 11.45, 11.46, 11.47, 11.48, 11.49, 11.5,
      11.51, 11.52, 11.53, 11.54, 11.55, 11.56, 11.57, 11.58, 11.59, 11.6, 11.61,
      11.62, 11.63, 11.64, 11.65, 11.66, 11.67, 11.68, 11.69, 11.7, 11.71, 11.72,
      11.73, 11.74, 11.75, 11.76, 11.77, 11.78, 11.79, 11.8, 11.81, 11.82, 11.83,
      11.84, 11.85, 11.86, 11.87, 11.88, 11.89, 11.9, 11.91, 11.92, 11.93, 11.94,
      11.95, 11.96, 11.97, 11.98, 11.99 } ;

    static real_T pDataValues0[] = { 0.75013009088574356, 0.9315928363058511,
      0.76354510267616582, 1.1251630995983171, 1.227340948821479,
      0.87041755257670539, 1.0243008940551475, 1.2301625415113426,
      1.119083400819106, 1.0055250791213008, 0.95983516058390439,
      1.0981793793426937, 0.979671194766052, 1.0772219772930494,
      0.89078429597572706, 0.96910404124374072, 1.2143806005087199,
      0.710380620993089, 1.0977792102700288, 0.840788734577766,
      1.0391885474673992, 0.96524779040277175, 1.2107740825086777,
      0.97498687979051391, 1.1441281267579322, 0.78645862490148166,
      0.94606280150287325, 0.87919783380043293, 1.01576947781015,
      0.95865436967427264, 0.7330062115073781, 0.885368248007423,
      1.1008717408492354, 0.92053016617571159, 1.1978367698653198,
      0.83042445566429413, 1.1324862869530912, 0.84701950728089925,
      1.0623838201535307, 0.84609261766927524, 0.9776866496618104,
      1.1361750817146845, 0.93232799805931843, 0.91855246150835623,
      1.1567713937838253, 1.1333654444395134, 1.0133121110097663,
      0.78384893599190841, 0.93122914353302533, 1.0389505004369137,
      1.2820216707350869, 0.61745161822301786, 1.2032483199838597,
      1.1081507045911867, 1.30733820964142, 1.0980314800764157,
      0.93689608947457192, 1.2112569997604006, 0.98222798232217268,
      0.82616996089885764, 1.2039449940798526, 1.0240834257347073,
      0.95262628164954488, 0.9598693040551225, 0.84246821690063878,
      1.2046210735239136, 0.69424089744816286, 1.1242763183666977,
      1.0984100579323153, 1.0486463996279689, 1.1247845421177622,
      0.68905609427803993, 1.1331545822666445, 0.90452307153868272,
      1.1357425856607313, 0.57719048683473, 1.0979004426307162,
      0.61617764943294162, 0.94559414120107466, 1.1516005090317805,
      1.1344605068530658, 0.91586435928548371, 1.1100663832220079,
      0.88734161856115767, 0.97696093468403389, 1.0867277620202918,
      1.1148971410439834, 0.88324088940411249, 0.96000421280420933,
      0.69745530826578239, 0.97461477837638588, 0.94929290833306779,
      1.2475102915252012, 1.0219577407771596, 1.0887672964461905,
      1.0125050682529029, 1.0400491980483648, 0.89321832478206475,
      1.0844447935491013, 0.92898839682837286, 1.0575670253542382,
      1.2840572916717505, 1.1034933249921748, 1.0774505679048372,
      0.86418954252528191, 1.2394176071049283, 0.98902821432822052,
      0.85687970508363276, 0.8792190007742009, 1.1838613612451185,
      1.1799470195920305, 1.1967229701610087, 0.83913272181221155,
      0.8741489126247165, 0.94741735537593785, 0.86588138461941488,
      0.90880708099964014, 0.85267649719729433, 0.90168589753866635,
      1.0196468190621846, 1.0327303526947542, 0.66882531798344647,
      0.99122131401481139, 0.88210665109499775, 1.018992788930676,
      1.1566329339559713, 1.0647077052494038, 0.747131733326595,
      0.896156843166135, 0.69682942091037492, 0.99481891896969277,
      0.81554904596842936, 1.0216195116218938, 0.88304564209087255,
      0.948229586799975, 0.77017259929308957, 0.93040640218560355,
      0.89371193911711522, 1.2058241979573121, 1.1203972260098147,
      1.2077274021305271, 1.133305014391357, 1.2213322174656134,
      0.9352251983171942, 0.8235359485206204, 1.2386340966933047,
      0.88674291149540418, 1.1620869315746778, 1.0630288372205787,
      1.1065680919527083, 1.2358304031056133, 0.88583943408172028,
      0.71160117558358538, 1.0798691024711837, 0.81967575345295574,
      0.68958675767772681, 0.96175871277526015, 1.2729997024513573,
      0.77136974543230363, 0.97219675566743413, 1.0025140857240809,
      0.77792230091425907, 1.0958879772209857, 0.73835654924240857,
      1.1462289065738234, 0.88471849858069329, 0.84065043888107938,
      0.85144668317576477, 1.0941186590463243, 0.98254847578111859,
      1.1759932310211061, 0.92535023724299836, 1.0215247184887692,
      0.81672638146887955, 1.5459556244528896, 1.2466580024606355,
      1.0288348895191564, 0.99070397447583081, 1.1208881505528852,
      1.0839028662187635, 0.8869810098946167, 0.649072073128924,
      1.1227763547547964, 0.8605124241099612, 1.166998087556824,
      1.2854129700499342, 0.82778518873308171, 1.1791390004132529,
      1.0925125608587491, 1.1511670795981213, 1.105667503283988,
      1.3177910022307158, 0.98617735518756533, 1.1706518052830563,
      1.093672420466131, 0.60487321102310743, 0.79665212709453015,
      0.82500008867970021, 1.2046822433632047, 1.0340470339231218,
      0.67704774345615282, 0.96305951156613012, 0.94466282072257579,
      0.97065849826875306, 1.1319803123164811, 0.81204266894016364,
      0.93864284812236631, 1.2836326541203475, 0.95911448101319408,
      1.3948103280719204, 0.92105826797523, 1.1266500126228753,
      1.0494729193067747, 0.86263839505225171, 0.85263973860702635,
      1.216961197398774, 0.83651681824838064, 0.94353910979534517,
      0.78158320364150591, 1.153946076425125, 1.2038038180272577,
      0.82788004348520339, 1.4095017491218631, 0.94956437895658552,
      0.9599383879236475, 1.1892589044031, 0.70073309901209457,
      1.0404595342555425, 1.1212854335208722, 1.0388630968730899,
      1.068209504742861, 1.1326311216099685, 0.959073417983018,
      1.0046476653777419, 0.771358968698115, 1.0400022574827645,
      1.0521649423893462, 1.1693779070301862, 1.1305338319790141,
      0.84573373134931507, 1.0919893120768813, 1.218765571616482,
      0.83613240337931394, 1.164866663030379, 1.3027803791196084,
      0.93218100591586128, 1.0916800381060485, 1.0266617736816277,
      0.91403247913679864, 0.94335467933434047, 0.88930362071530145,
      0.7470139922690946, 0.84172929925131246, 0.7181501221112041,
      1.0864591613058365, 1.2589964301740428, 0.93329942327720894,
      0.8781703759669296, 1.0680538357586695, 1.0526274072403767,
      0.83848061478676561, 0.95408041864862891, 1.14136423717513,
      1.1525875238016192, 1.09101975828115, 0.895077906712657,
      0.80526140691076464, 1.0165382203606734, 1.0873245484560665,
      0.92415504313901009, 1.217930780331562, 1.1369640084321047,
      0.97665825490489244, 1.0837701758412657, 1.0647720474903752,
      0.83409138813136385, 0.81121381925919223, 1.2519503669318894,
      1.0592581276765372, 1.0133697617003654, 0.94352386145968059,
      0.80344876998750414, 1.0927472157690929, 0.95156951729914729,
      0.83291153971372878, 1.3334663411178471, 1.0490510450591164,
      1.0620125719432592, 0.84433811041929141, 1.1058366766764438,
      0.977149287807263, 1.0595715302707978, 1.1024474502058961,
      1.259872117405137, 0.80290606421343091, 0.81354621562764029,
      1.1747127210692467, 1.1031557460868484, 0.92170382987849342,
      0.94843650581388206, 1.1167434928625597, 0.97580583367844242,
      1.2945853189085272, 1.1176339894130509, 0.68605321528581276,
      0.96093495818000285, 0.94678896700242121, 1.1919028863189065,
      1.0166058958092543, 0.7511087165235899, 0.97103789853730371,
      1.27613116610444, 0.97004632073404262, 0.83803143744314512,
      1.0602305629828472, 1.2946516163281898, 1.0540268332534544,
      0.780034996730331, 1.1738561098481357, 1.3725648653366256,
      1.1440728190354683, 1.1904639521191269, 0.89910648189879494,
      0.89589362879027012, 0.83400743545357847, 0.90835380033000124,
      0.88514053424235017, 1.1482819425092488, 0.98005954709845178,
      1.1951792611916274, 1.0558928581768487, 0.99912015033386159,
      0.71321059037886736, 0.822512011645846, 1.16320991559649,
      1.0383975714422107, 1.0034638196754002, 1.0531485352789469,
      0.82983088688727458, 1.0003719066228371, 0.87922408586763134,
      0.87063665555156189, 1.1172425016924987, 1.1859582383481253,
      1.1318538059574406, 1.25341326917761, 0.99298373683620034,
      0.85993458856975136, 0.99193149190340557, 0.88284878722130544,
      0.917240676117121, 1.0461583950481128, 0.962549510786613,
      1.3035850802061124, 0.85294769041153518, 1.0804333577816803,
      0.92398962341576485, 0.89655537610866443, 0.94341185158710439,
      1.0649179734641112, 0.69064244812402331, 1.0157272453467987,
      0.88120175744929374, 0.90591268103821831, 1.1716356759990794,
      1.2974357641557315, 0.69821514789582428, 0.89383864743537877,
      1.0304508136319321, 1.0148628921045444, 1.1130026427577746,
      1.0199904201064813, 0.840961823521453, 1.0519026065572907,
      0.77536107205508853, 0.91737402809665092, 1.1936108308803404,
      0.9194231629830083, 1.1818496871640571, 1.1299312822179914,
      1.0414953853169169, 1.1312382009611204, 1.0308500022636793,
      1.1187826032260524, 1.1110308317204389, 0.762437327612927,
      1.0940840441822239, 0.7750690591648961, 1.1023212461240071,
      1.175122444479997, 0.97431626523620674, 0.79895710253060837,
      0.724197372418733, 1.1290602585692937, 0.68846764794069126,
      1.0438414799451008, 0.90357822898971429, 0.96908929581837711,
      0.92717349636670965, 0.95518013753706521, 1.2921257281475211,
      1.1577823590151943, 1.1834961742303298, 1.1428509851736732,
      0.96619299305112571, 0.84494768035253687, 1.0911118360321,
      0.57109989035341424, 1.2901466411317222, 1.0506640109689105,
      1.1481999780493086, 1.1008461689667521, 0.925132953380697,
      0.69060620882295343, 1.1264066720798134, 0.71354047527854791,
      0.87140904977828026, 1.0312884152370958, 0.9774840807454338,
      0.98883025462626684, 1.3289644434899126, 0.9291895623134504,
      1.1833883087852128, 1.0704874399136473, 1.1815219441188269,
      1.0197869248135718, 0.78875205788896485, 0.929979704890394,
      1.0643834568631114, 0.96854979239438421, 0.9307209764068286,
      0.47229357559485607, 1.1338703667097882, 0.93112734083806,
      1.0934155766935012, 1.0872274054521354, 1.073932603220326,
      1.2108519130392357, 1.1940082195604356, 1.1434486528794332,
      0.63068182655450156, 0.87719838825853835, 1.1537282058780274,
      1.0630327501481942, 0.87182348107118179, 1.0966714674903673,
      1.0333479011518647, 0.89925905313631915, 1.0593662765249989,
      0.92269696917789079, 1.0628386106906109, 1.1559997339231438,
      0.98157419111550925, 0.85906177911613657, 1.3669422889772451,
      0.88315223987086111, 1.1021453705120616, 1.0315147367204103,
      1.2615736082541824, 0.91996751988329284, 1.0101567478724482,
      1.2439186005541949, 0.94136813718664547, 0.83332486731615418,
      1.0156130235036553, 1.0486489857850376, 1.1107416744815841,
      1.287533325654113, 0.93990686874843765, 0.78241985364491884,
      0.98855823576291046, 1.148019894906301, 0.76179213965094383,
      0.92906429386930434, 0.67246932507417378, 1.2258336262778466,
      1.0662264370209809, 1.2654182041153987, 1.2000802984048968,
      0.9932626877340941, 0.6691352195575061, 1.0129327104048023,
      0.9409657646160714, 1.0719537254770939, 1.2872453978808891,
      1.6433580345434691, 1.4072897761871339, 1.2485480706119259,
      0.86766589980334441, 0.77745559978973788, 0.83071188948766683,
      1.0943317392784275, 0.88518943224472135, 1.254614525519429,
      0.88453457357511, 1.1202047997593305, 0.89544567762495353,
      1.0761993545788386, 1.080140360489549, 0.92119120277273991,
      0.79009064278380436, 0.850840473178162, 1.2098741070844192,
      1.0600302024200354, 0.8501255518036952, 1.172215288686846,
      0.82840901971459791, 0.88514570459671438, 1.0901106352199379,
      0.70988561463697342, 0.80801964497653023, 0.97701400307500341,
      1.0853226212598526, 0.8071802541880353, 0.68475870997457289,
      1.0411553849564883, 0.96892513246014589, 0.87758167855580349,
      1.0702963031310264, 1.029491295105079, 1.1624423905378061,
      0.9536860951060494, 0.64353306899002938, 1.2991021559337979,
      0.713223815034965, 0.99679436597699256, 0.95043490862811264,
      1.084063251291532, 0.91636171363755259, 0.9066960675398319,
      1.0488583468666843, 1.3264784783000529, 0.72994600267889254,
      0.83908225049654872, 0.98789517577865216, 1.2317191930840892,
      1.1695875414202519, 0.8026871375290715, 1.1018081076166142,
      1.1071945120916988, 0.8933751741093312, 0.72252524294530307,
      1.2946947380372846, 1.102035915854878, 1.0076152966622904,
      0.89417554861885706, 0.88077235709089507, 1.0564267911436303,
      0.79247109696117346, 1.1309557862245199, 0.914923144853057,
      1.2064856899172931, 1.0537005937465982, 0.70285163491711833,
      1.2922908279300787, 0.8007602596979323, 0.82546288755169528,
      0.95818653143341947, 0.8132076902539378, 1.0541661725208149,
      0.74750393190359854, 1.1444791603344815, 1.1058813042957203,
      0.874774896260579, 1.15782261444866, 1.2697452961459899,
      0.84613490579302231, 1.0046690853124332, 0.737141654433502,
      1.1690982528428724, 1.3277310285881456, 1.3414346065106817,
      1.100708055361312, 0.91498654015423009, 0.5173486337022386,
      0.95477862910700062, 1.1335579695857019, 0.93518034395256378,
      0.85503898904986775, 1.2221660803555308, 0.84322935515845621,
      0.764327035973879, 0.89745671194883037, 1.2212310315848454,
      1.1691868897973157, 0.83374854561497069, 0.72846367968105308,
      0.7355967047263352, 1.3495511148376163, 1.0227125325599431,
      0.79117294752294787, 1.1540731419022585, 1.0925720599187205,
      0.78852882743537067, 1.0087012391334782, 0.90909737076052943,
      1.0851662579367709, 1.500523817743151, 1.1481938165097436,
      1.1577579497648423, 1.0109094925081048, 0.895224502475828,
      0.83507449942361656, 0.67105700623852393, 0.97168418913841292,
      0.67336819518714508, 1.0788370658662247, 1.1491243181819915,
      0.87573465838932085, 0.93739936996523077, 1.0148311789158182,
      1.1701264347823985, 0.82591635270873254, 1.04249949446409,
      0.92953956193197251, 0.5878915216099021, 0.6727560959129304,
      0.67409367508433127, 1.0174584162462044, 1.1993539405084541,
      0.82008224350672387, 0.82163443328262542, 1.0816684755747685,
      1.1599743341192279, 0.94410966898835236, 1.0409147988601202,
      1.0048437347268258, 0.82225314131788207, 0.96052112385320687,
      0.99028158945400258, 1.2233246903483337, 1.0889735612500215,
      0.97012816413064284, 0.81503185524111177, 1.0779344469948846,
      0.73891283440068745, 0.65795873224022516, 1.1343503461957112,
      0.817423883005251, 1.0942075838144754, 1.0806833001852152,
      1.1682209216169639, 0.93536011133776009, 1.1070237402457608,
      1.0578760022934841, 1.395671507012636, 1.1594164557013273,
      0.91176051805137437, 0.88655238706183281, 1.0405640582835598,
      1.1348300507098874, 0.96381396241115436, 0.86379252222021852,
      1.2941080017771542, 0.99629347396146961, 0.67881771389101331,
      0.61184521731799713, 1.0617888680162255, 0.93441259216127193,
      1.1920123943278118, 1.030611120791177, 1.0441766483897708,
      1.1720106276605207, 0.87848497618088928, 1.0141043042065074,
      1.0668795160199569, 1.1358521679565634, 1.3367779330890932,
      1.0809934650711506, 0.88339562143367656, 0.95468842138377807,
      0.86871402670264009, 1.142246224666561, 1.0111737373757326,
      0.68716824684268307, 1.0941626557947388, 1.07321289046765,
      1.2520357262896535, 0.99453142134933, 0.97789488967069693,
      1.08766288862662, 1.1740100020687452, 0.90504139590483057,
      0.7025743519842188, 1.1530899833906154, 0.72269888017762551,
      1.0244447580096063, 1.112301319131586, 1.0220934291870876,
      1.1905156733987079, 0.95758252246770226, 0.9354353312337047,
      0.95919458784697542, 0.86598300409622841, 1.1918596161481649,
      0.99752782789412253, 1.0739630251773109, 1.0063620460327452,
      1.3500503155779788, 1.138482022694326, 0.9980933852380155,
      1.3211091481668589, 0.9990466252295821, 1.0670744276617488,
      0.95092968276626244, 1.0327024451609204, 0.830111356040637,
      1.2454018763771102, 1.1640915789258746, 1.1460243301463426,
      1.1218419736322489, 1.112583710277993, 1.0962528651466952,
      0.8858804078176824, 0.84654661709123258, 0.6012990005415626,
      1.1063610742451857, 0.968830637946302, 0.91747781086780222,
      1.1029144922194138, 1.591200128056153, 0.69761879387340386,
      0.67694571180842944, 0.88208064905865335, 0.94867810342612424,
      0.75009659634538384, 0.64786503503916171, 0.72926643339215047,
      1.2078279077780918, 0.7878818458633392, 0.86979227679569127,
      0.76421007748877456, 1.226888396947138, 0.80934888360389468,
      0.91640809758704878, 0.58898036180073587, 1.0722545410005515,
      0.91194335612143507, 0.99321619529834926, 1.5079278846601865,
      0.82924796904622611, 1.2945279572679298, 0.97991561294027563,
      1.2979207954980154, 0.86666922877884955, 1.4265403401469863,
      0.728312062303287, 1.1986798921802218, 1.1301003988727993,
      0.91395213003544029, 1.0905720604671982, 1.3719906032114044,
      1.00338741416792, 1.2045736304150454, 1.1435635172040528,
      0.77461721250489379, 0.80699521675722186, 1.0917749120379749,
      0.76512764484211671, 0.89651399931946973, 0.99917798337975994,
      0.79593094809426879, 1.2013427154492018, 1.0468232234587265,
      0.90039403514784955, 1.0077896458601376, 0.90673498125041563,
      1.014840005308282, 1.3069141562286011, 0.61453020854291229,
      0.68111347769285491, 0.96998914076536424, 1.1116601654101483,
      0.97485242275182526, 1.0961611244796028, 0.9682485318757903,
      0.805419478041435, 0.96840641883545719, 1.1684394526860389,
      1.1331771921445428, 1.0396780644638444, 0.85089939933733461,
      1.0582568364605667, 0.9670989651915719, 0.873475374669191,
      0.8905762201419779, 1.3882667162603326, 1.2302809266987567,
      1.1100478465165871, 1.2305630440382977, 1.0433944467457272,
      0.78558765676165732, 0.84975080693781824, 0.61423003567851264,
      0.9408412523230455, 1.1236796917543055, 0.88805267347188477,
      0.906493895316524, 1.0574990969274762, 0.8985133225385683,
      0.7681069161833376, 0.87235808052151009, 1.0842486616105107,
      0.81767881466501735, 1.0782862660127006, 1.0555159066860715,
      1.1856311061553222, 1.0167028399220137, 1.1763922563124551,
      0.90422450790338116, 1.176735211353616, 1.0685840690061521,
      0.7100903936720292, 1.1981763815261526, 0.97560581102785093,
      0.81476483024164226, 1.1088919118390759, 1.0816297928619043,
      1.0587786204809972, 0.913781699887466, 1.1175121061524778,
      0.76212854920989526, 0.88808471543731426, 1.3127460243613274,
      0.93449089725313228, 1.2250191968254327, 1.0539517444497033,
      0.9018605290117313, 0.94400248278286691, 0.99522385903750521,
      0.91002048204155939, 1.262426443902759, 0.840887726324087,
      0.80928333243382944, 1.0802536522723905, 1.076888314703029,
      1.2303915746555707, 0.53263330894358318, 0.96851810900963642,
      1.0642529216677301, 0.83535713911745368, 0.89769820722462268,
      1.1254272472353339, 1.1114350006108951, 1.0503721442713665,
      0.73639323081163677, 1.1128413771007364, 1.0424329726616406,
      1.2986373795904407, 1.1245915090205438, 0.76733155668669928,
      1.1132892963265448, 0.98367722307669658, 0.98996539382982585,
      1.0073049098209428, 0.95448368394250116, 0.92532441400774013,
      0.85781804002060968, 0.69223920084274237, 1.1313297799947932,
      0.65264455742669614, 1.3117759094881978, 0.88702277835470533,
      0.96096359063064862, 0.92233065823474, 1.0634822407816527,
      0.99647723963567791, 0.75112637123147874, 0.58673372767823651,
      0.95744056037924219, 0.97448808999646386, 1.2610953046825593,
      0.92409749493474214, 1.0486526260533171, 1.1097446749753159,
      0.74765442269282611, 1.1308542106124022, 0.97529843903167357,
      0.78494103747187738, 0.97804971511725758, 0.91248437803894178,
      1.3980796971173963, 0.94715670770001592, 1.1204720106544281,
      1.2079141580880866, 1.2467313380642637, 0.7358992899048129,
      0.88104980459224658, 0.69861074586214733, 0.98640847127961107,
      1.1523091002908301, 1.0530675708840354, 0.807634183688144,
      1.3249964393389575, 0.89165181683374406, 1.2541940174192852,
      1.001354591507406, 1.1762170046681528, 1.1402878110850283,
      1.5875764522577187, 1.0244117392824645, 0.88098348375884139,
      1.2265293223642104, 0.94344722700296568, 0.92808726360064175,
      0.953764553358571, 0.96162225488580422, 1.0668398692924368,
      1.1537880296228338, 0.8028170039132041, 1.1360032697255684,
      0.83694741333362821, 0.8433805047874593, 0.43523125714773592,
      1.0351098360543756, 1.1602180367916002, 1.0132274217408166,
      1.015875439431285, 0.998081282101123, 1.1260828512150267,
      1.1386546827708166, 1.0578100059340321, 1.0011191690890546,
      0.73963025204683741, 1.1177026627860196, 0.75845641130482067,
      0.900581181622249, 0.81393665740171262, 1.0951651551030332,
      0.769955202824623, 0.96168181199228453, 1.0817759068721629,
      1.1807323789506998, 0.88056445696944363, 1.0241468248311627,
      0.88007105401560171, 0.77865858213876937, 1.1419970138702922,
      1.0726778881590886, 1.1592575120495168, 0.88418479562488284,
      1.1878062605074229, 0.79142808435930811, 1.0588132751057764,
      1.0686141262803623, 0.69460432038515729, 1.1388060060709932,
      1.2872954619517312, 1.220428491299929, 0.99253936038251811,
      1.0496393897862739, 0.93994836896686706, 0.83893172735872912,
      0.88532536207596058, 1.0649705504295237, 0.96131725419121827,
      1.3828820735031657, 1.077022443135879, 1.0721126923493742,
      0.95851880930323918, 0.986723363805323, 0.83483835987319444,
      1.2263011753310349, 0.8164916340294448, 0.93136214015309171,
      0.88353062936161164, 1.2835406095803359, 1.1576431530554607,
      0.95486071754024415, 0.99419846114298716, 1.0717159363633886,
      0.91057164792777434, 0.86251192398585785, 1.151397836245585,
      1.0852301836700444, 1.080633443278959, 1.2233619006704628,
      0.80591579878675579, 1.1049450157518221, 1.206216403415211,
      1.2600228924903476, 1.0287697851774813, 0.98341993505846048,
      1.1318274677006175, 0.86378624204071175, 0.59129118377614431,
      1.0753688121890348, 0.92708742770184682, 0.94970349566709,
      0.96847353283713355, 1.0307671330095849, 1.0864485803803223,
      0.81711466996386273, 0.94207765765721085, 0.84034262310005914,
      1.0150070792432326, 0.80975548898235816, 0.80117686463453874,
      0.91912955721311562, 1.0020839186376782, 0.83077945205073789,
      0.96966721815101042, 0.91531537687691022, 1.1317927318127632,
      1.1176917226560596, 1.2211991353744669, 0.71378285170142031,
      0.7466634194947116, 1.3491652342945517, 0.88753953160404842,
      1.0160559721466427, 1.1115970203203271, 0.98523413426811091,
      0.735179342977438, 0.98736467248727233, 0.91253998223394583,
      1.3469957648009778, 1.2914617022155639, 1.0604273359606571,
      0.892278092864347, 1.0183036802565477, 1.0426682500269011,
      0.80776724336866179, 1.1656560088047214, 0.96957644498982742,
      0.74757609115865475, 0.82246964208699658, 1.1987480830898991,
      0.9855702230019473, 1.2574216138277554, 0.91827103193592907,
      1.015050815475818, 0.62786211879496068, 1.0480372492797305,
      0.69450894964058252, 0.81246745916270724, 1.0639161663988046,
      1.2932927000423207, 0.97189862457306142, 0.99965861325890193,
      1.2132582866459392, 1.0289989704134173, 0.98217244499274414,
      0.97328301530578909, 0.87370669394459743, 1.0810972134752195,
      0.95526628154665538, 1.0209177545180519, 1.27672981038734,
      0.84491156573727078, 0.90129460249514348, 1.0778323975034991,
      1.07435420697952, 1.0446230001294814, 1.3169350804277007,
      0.83262691122416255, 0.95798455189108589, 0.89403201227345153,
      0.85427621333761361, 0.93188201555055594, 1.336332491271377,
      0.8648300126406645, 1.0762009150630789, 0.7741711060069103,
      0.84564338009689122, 1.1592771070957264, 0.901250495026975,
      0.94301556661508068, 0.895865168495788, 1.1995389641851015,
      0.68466590174651731, 1.0395498643827907, 0.880752445706369,
      1.086905835242252, 0.71045819637230634, 1.3196901442895423,
      0.92721162882194075, 1.3626545579051124, 0.880466456707971,
      0.83117135730297642, 1.0535648680418082, 0.821730670030221,
      1.0538000805277736, 1.0786141713313648, 1.0753229558925721,
      1.01767074372885, 0.99219440212685328, 0.86550310628253979,
      0.88223581904287218, 1.2879477215778419, 0.62484266415891532,
      0.8251614144078312, 1.0549122671241444, 1.079597579870871,
      0.91058440002152485, 1.050560141453452, 0.95019933906210463,
      1.1647996734151462, 1.0716898472530156, 0.90936459642337475,
      0.59735531525389263, 1.0735416325676563, 1.3658198195405169,
      1.0884670321570236, 0.946782301176724, 1.291742025285155,
      1.0239545971189936, 1.3066521915801985, 1.0496689028517234,
      1.1206287761898894, 1.2940199868144244, 1.1379651548172438,
      1.4383242686953388, 0.78202617998650581, 0.77592408822481218,
      1.2154876953907876, 0.91315799110253248, 1.0095130881779442,
      1.1734481852250898, 1.0515786398776359, 0.98682424285144255,
      1.0775606576051191, 0.82134213003099943, 0.99149043125048164,
      1.2226165376018083, 1.0608406888120869, 1.4779261492738416,
      1.2153811509729848, 1.3107683801012122, 1.0395600786115324,
      0.78150009246290408, 0.88078658528487319, 1.269806103909116,
      0.82224499884254176, 1.1587594623945241, 1.1092742545115,
      0.824000292803014, 1.1730859697019307, 0.78502560025606,
      1.0321539789569791, 0.84282865094102855, 1.0491059310106381,
      0.978815605831515, 0.73738152837917414, 1.1896915671448216,
      1.1943869996593297, 1.0758221369980645, 0.94164095489340616,
      0.663642838700597, 0.84540385217440239, 1.0534083596713628,
      1.0228453076272841, 0.99234947543937368, 1.0263976159644475,
      1.2071692902736628, 1.1707361392312072, 0.7098854800273553,
      1.0005517995132254, 0.64011317069384388, 1.3566126782801564,
      1.2806656200616677, 1.2240896395465428, 1.0530472265316291,
      1.129619586028153, 0.93664929296568156, 1.1791788578054554,
      0.93363520333110928, 0.72078253211216081, 1.1612126378216816,
      1.2877455243642064, 1.1017219988111153, 0.52334091340697764,
      1.168326856793817, 1.4078813138683974, 0.63260075573565544,
      1.2786511081965486, 1.193273277436157, 0.827357405541662,
      0.890133679768409, 0.58699680535442345, 1.439159580844755,
      0.79458558180379935, 1.0044404154690403, 0.93390766951670612,
      1.0516843343746141, 1.0126637802878793, 0.75007937328967755,
      0.99860486131579207, 1.0001247919530216, 0.93269969030499966,
      1.05243655371793, 0.86785437022343859, 0.78605951646124916,
      0.93934909452507676, 0.88310522055428486, 0.76879617822307289,
      1.1269864750090384, 0.94158611671421222, 1.0875450585795268,
      0.93782418907958165 } ;

    Madgwick_embedded_DW->GyroY_PWORK.TimePtr = (void *) pTimeValues0;
    Madgwick_embedded_DW->GyroY_PWORK.DataPtr = (void *) pDataValues0;
    Madgwick_embedded_DW->GyroY_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/GyroZ' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06,
      0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18,
      0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31,
      0.32, 0.33, 0.34, 0.35, 0.36, 0.37, 0.38, 0.39, 0.4, 0.41, 0.42, 0.43,
      0.44, 0.45, 0.46, 0.47, 0.48, 0.49, 0.5, 0.51, 0.52, 0.53, 0.54, 0.55,
      0.56, 0.57, 0.58, 0.59, 0.6, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67,
      0.68, 0.69, 0.7, 0.71, 0.72, 0.73, 0.74, 0.75, 0.76, 0.77, 0.78, 0.79, 0.8,
      0.81, 0.82, 0.83, 0.84, 0.85, 0.86, 0.87, 0.88, 0.89, 0.9, 0.91, 0.92,
      0.93, 0.94, 0.95, 0.96, 0.97, 0.98, 0.99, 1.0, 1.01, 1.02, 1.03, 1.04,
      1.05, 1.06, 1.07, 1.08, 1.09, 1.1, 1.11, 1.12, 1.13, 1.14, 1.15, 1.16,
      1.17, 1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28,
      1.29, 1.3, 1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37, 1.38, 1.39, 1.4, 1.41,
      1.42, 1.43, 1.44, 1.45, 1.46, 1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53,
      1.54, 1.55, 1.56, 1.57, 1.58, 1.59, 1.6, 1.61, 1.62, 1.63, 1.64, 1.65,
      1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75, 1.76, 1.77,
      1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.85, 1.86, 1.87, 1.88, 1.89, 1.9,
      1.91, 1.92, 1.93, 1.94, 1.95, 1.96, 1.97, 1.98, 1.99, 2.0, 2.01, 2.02,
      2.03, 2.04, 2.05, 2.06, 2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14,
      2.15, 2.16, 2.17, 2.18, 2.19, 2.2, 2.21, 2.22, 2.23, 2.24, 2.25, 2.26,
      2.27, 2.28, 2.29, 2.3, 2.31, 2.32, 2.33, 2.34, 2.35, 2.36, 2.37, 2.38,
      2.39, 2.4, 2.41, 2.42, 2.43, 2.44, 2.45, 2.46, 2.47, 2.48, 2.49, 2.5, 2.51,
      2.52, 2.53, 2.54, 2.55, 2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63,
      2.64, 2.65, 2.66, 2.67, 2.68, 2.69, 2.7, 2.71, 2.72, 2.73, 2.74, 2.75,
      2.76, 2.77, 2.78, 2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87,
      2.88, 2.89, 2.9, 2.91, 2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0,
      3.01, 3.02, 3.03, 3.04, 3.05, 3.06, 3.07, 3.08, 3.09, 3.1, 3.11, 3.12,
      3.13, 3.14, 3.15, 3.16, 3.17, 3.18, 3.19, 3.2, 3.21, 3.22, 3.23, 3.24,
      3.25, 3.26, 3.27, 3.28, 3.29, 3.3, 3.31, 3.32, 3.33, 3.34, 3.35, 3.36,
      3.37, 3.38, 3.39, 3.4, 3.41, 3.42, 3.43, 3.44, 3.45, 3.46, 3.47, 3.48,
      3.49, 3.5, 3.51, 3.52, 3.53, 3.54, 3.55, 3.56, 3.57, 3.58, 3.59, 3.6, 3.61,
      3.62, 3.63, 3.64, 3.65, 3.66, 3.67, 3.68, 3.69, 3.7, 3.71, 3.72, 3.73,
      3.74, 3.75, 3.76, 3.77, 3.78, 3.79, 3.8, 3.81, 3.82, 3.83, 3.84, 3.85,
      3.86, 3.87, 3.88, 3.89, 3.9, 3.91, 3.92, 3.93, 3.94, 3.95, 3.96, 3.97,
      3.98, 3.99, 4.0, 4.01, 4.02, 4.03, 4.04, 4.05, 4.06, 4.07, 4.08, 4.09, 4.1,
      4.11, 4.12, 4.13, 4.14, 4.15, 4.16, 4.17, 4.18, 4.19, 4.2, 4.21, 4.22,
      4.23, 4.24, 4.25, 4.26, 4.27, 4.28, 4.29, 4.3, 4.31, 4.32, 4.33, 4.34,
      4.35, 4.36, 4.37, 4.38, 4.39, 4.4, 4.41, 4.42, 4.43, 4.44, 4.45, 4.46,
      4.47, 4.48, 4.49, 4.5, 4.51, 4.52, 4.53, 4.54, 4.55, 4.56, 4.57, 4.58,
      4.59, 4.6, 4.61, 4.62, 4.63, 4.64, 4.65, 4.66, 4.67, 4.68, 4.69, 4.7, 4.71,
      4.72, 4.73, 4.74, 4.75, 4.76, 4.77, 4.78, 4.79, 4.8, 4.81, 4.82, 4.83,
      4.84, 4.85, 4.86, 4.87, 4.88, 4.89, 4.9, 4.91, 4.92, 4.93, 4.94, 4.95,
      4.96, 4.97, 4.98, 4.99, 5.0, 5.01, 5.02, 5.03, 5.04, 5.05, 5.06, 5.07,
      5.08, 5.09, 5.1, 5.11, 5.12, 5.13, 5.14, 5.15, 5.16, 5.17, 5.18, 5.19, 5.2,
      5.21, 5.22, 5.23, 5.24, 5.25, 5.26, 5.27, 5.28, 5.29, 5.3, 5.31, 5.32,
      5.33, 5.34, 5.35, 5.36, 5.37, 5.38, 5.39, 5.4, 5.41, 5.42, 5.43, 5.44,
      5.45, 5.46, 5.47, 5.48, 5.49, 5.5, 5.51, 5.52, 5.53, 5.54, 5.55, 5.56,
      5.57, 5.58, 5.59, 5.6, 5.61, 5.62, 5.63, 5.64, 5.65, 5.66, 5.67, 5.68,
      5.69, 5.7, 5.71, 5.72, 5.73, 5.74, 5.75, 5.76, 5.77, 5.78, 5.79, 5.8, 5.81,
      5.82, 5.83, 5.84, 5.85, 5.86, 5.87, 5.88, 5.89, 5.9, 5.91, 5.92, 5.93,
      5.94, 5.95, 5.96, 5.97, 5.98, 5.99, 6.0, 6.01, 6.02, 6.03, 6.04, 6.05,
      6.06, 6.07, 6.08, 6.09, 6.1, 6.11, 6.12, 6.13, 6.14, 6.15, 6.16, 6.17,
      6.18, 6.19, 6.2, 6.21, 6.22, 6.23, 6.24, 6.25, 6.26, 6.27, 6.28, 6.29, 6.3,
      6.31, 6.32, 6.33, 6.34, 6.35, 6.36, 6.37, 6.38, 6.39, 6.4, 6.41, 6.42,
      6.43, 6.44, 6.45, 6.46, 6.47, 6.48, 6.49, 6.5, 6.51, 6.52, 6.53, 6.54,
      6.55, 6.56, 6.57, 6.58, 6.59, 6.6, 6.61, 6.62, 6.63, 6.64, 6.65, 6.66,
      6.67, 6.68, 6.69, 6.7, 6.71, 6.72, 6.73, 6.74, 6.75, 6.76, 6.77, 6.78,
      6.79, 6.8, 6.81, 6.82, 6.83, 6.84, 6.85, 6.86, 6.87, 6.88, 6.89, 6.9, 6.91,
      6.92, 6.93, 6.94, 6.95, 6.96, 6.97, 6.98, 6.99, 7.0, 7.01, 7.02, 7.03,
      7.04, 7.05, 7.06, 7.07, 7.08, 7.09, 7.1, 7.11, 7.12, 7.13, 7.14, 7.15,
      7.16, 7.17, 7.18, 7.19, 7.2, 7.21, 7.22, 7.23, 7.24, 7.25, 7.26, 7.27,
      7.28, 7.29, 7.3, 7.31, 7.32, 7.33, 7.34, 7.35, 7.36, 7.37, 7.38, 7.39, 7.4,
      7.41, 7.42, 7.43, 7.44, 7.45, 7.46, 7.47, 7.48, 7.49, 7.5, 7.51, 7.52,
      7.53, 7.54, 7.55, 7.56, 7.57, 7.58, 7.59, 7.6, 7.61, 7.62, 7.63, 7.64,
      7.65, 7.66, 7.67, 7.68, 7.69, 7.7, 7.71, 7.72, 7.73, 7.74, 7.75, 7.76,
      7.77, 7.78, 7.79, 7.8, 7.81, 7.82, 7.83, 7.84, 7.85, 7.86, 7.87, 7.88,
      7.89, 7.9, 7.91, 7.92, 7.93, 7.94, 7.95, 7.96, 7.97, 7.98, 7.99, 8.0, 8.01,
      8.02, 8.03, 8.04, 8.05, 8.06, 8.07, 8.08, 8.09, 8.1, 8.11, 8.12, 8.13,
      8.14, 8.15, 8.16, 8.17, 8.18, 8.19, 8.2, 8.21, 8.22, 8.23, 8.24, 8.25,
      8.26, 8.27, 8.28, 8.29, 8.3, 8.31, 8.32, 8.33, 8.34, 8.35, 8.36, 8.37,
      8.38, 8.39, 8.4, 8.41, 8.42, 8.43, 8.44, 8.45, 8.46, 8.47, 8.48, 8.49, 8.5,
      8.51, 8.52, 8.53, 8.54, 8.55, 8.56, 8.57, 8.58, 8.59, 8.6, 8.61, 8.62,
      8.63, 8.64, 8.65, 8.66, 8.67, 8.68, 8.69, 8.7, 8.71, 8.72, 8.73, 8.74,
      8.75, 8.76, 8.77, 8.78, 8.79, 8.8, 8.81, 8.82, 8.83, 8.84, 8.85, 8.86,
      8.87, 8.88, 8.89, 8.9, 8.91, 8.92, 8.93, 8.94, 8.95, 8.96, 8.97, 8.98,
      8.99, 9.0, 9.01, 9.02, 9.03, 9.04, 9.05, 9.06, 9.07, 9.08, 9.09, 9.1, 9.11,
      9.12, 9.13, 9.14, 9.15, 9.16, 9.17, 9.18, 9.19, 9.2, 9.21, 9.22, 9.23,
      9.24, 9.25, 9.26, 9.27, 9.28, 9.29, 9.3, 9.31, 9.32, 9.33, 9.34, 9.35,
      9.36, 9.37, 9.38, 9.39, 9.4, 9.41, 9.42, 9.43, 9.44, 9.45, 9.46, 9.47,
      9.48, 9.49, 9.5, 9.51, 9.52, 9.53, 9.54, 9.55, 9.56, 9.57, 9.58, 9.59, 9.6,
      9.61, 9.62, 9.63, 9.64, 9.65, 9.66, 9.67, 9.68, 9.69, 9.7, 9.71, 9.72,
      9.73, 9.74, 9.75, 9.76, 9.77, 9.78, 9.79, 9.8, 9.81, 9.82, 9.83, 9.84,
      9.85, 9.86, 9.87, 9.88, 9.89, 9.9, 9.91, 9.92, 9.93, 9.94, 9.95, 9.96,
      9.97, 9.98, 9.99, 10.0, 10.01, 10.02, 10.03, 10.04, 10.05, 10.06, 10.07,
      10.08, 10.09, 10.1, 10.11, 10.12, 10.13, 10.14, 10.15, 10.16, 10.17, 10.18,
      10.19, 10.2, 10.21, 10.22, 10.23, 10.24, 10.25, 10.26, 10.27, 10.28, 10.29,
      10.3, 10.31, 10.32, 10.33, 10.34, 10.35, 10.36, 10.37, 10.38, 10.39, 10.4,
      10.41, 10.42, 10.43, 10.44, 10.45, 10.46, 10.47, 10.48, 10.49, 10.5, 10.51,
      10.52, 10.53, 10.54, 10.55, 10.56, 10.57, 10.58, 10.59, 10.6, 10.61, 10.62,
      10.63, 10.64, 10.65, 10.66, 10.67, 10.68, 10.69, 10.7, 10.71, 10.72, 10.73,
      10.74, 10.75, 10.76, 10.77, 10.78, 10.79, 10.8, 10.81, 10.82, 10.83, 10.84,
      10.85, 10.86, 10.87, 10.88, 10.89, 10.9, 10.91, 10.92, 10.93, 10.94, 10.95,
      10.96, 10.97, 10.98, 10.99, 11.0, 11.01, 11.02, 11.03, 11.04, 11.05, 11.06,
      11.07, 11.08, 11.09, 11.1, 11.11, 11.12, 11.13, 11.14, 11.15, 11.16, 11.17,
      11.18, 11.19, 11.2, 11.21, 11.22, 11.23, 11.24, 11.25, 11.26, 11.27, 11.28,
      11.29, 11.3, 11.31, 11.32, 11.33, 11.34, 11.35, 11.36, 11.37, 11.38, 11.39,
      11.4, 11.41, 11.42, 11.43, 11.44, 11.45, 11.46, 11.47, 11.48, 11.49, 11.5,
      11.51, 11.52, 11.53, 11.54, 11.55, 11.56, 11.57, 11.58, 11.59, 11.6, 11.61,
      11.62, 11.63, 11.64, 11.65, 11.66, 11.67, 11.68, 11.69, 11.7, 11.71, 11.72,
      11.73, 11.74, 11.75, 11.76, 11.77, 11.78, 11.79, 11.8, 11.81, 11.82, 11.83,
      11.84, 11.85, 11.86, 11.87, 11.88, 11.89, 11.9, 11.91, 11.92, 11.93, 11.94,
      11.95, 11.96, 11.97, 11.98, 11.99 } ;

    static real_T pDataValues0[] = { 2.645531146148381, 2.68256639109787,
      2.5807352635013023, 2.3524057915761878, 2.5170762223077059,
      2.3894971108019316, 2.6573015065766148, 2.4970620420892278,
      2.442103195392213, 2.6752515669208665, 2.734944939595247,
      2.3636131849238891, 2.5670502105032855, 2.6650871795650004,
      2.5570658049220496, 2.90077176709437, 2.5230764160092018,
      2.6778568813604564, 2.3554861539460479, 2.446706410233026,
      2.6489356225070519, 2.6874750571900519, 2.623135480141634,
      2.9569949774409596, 2.4808556312503049, 2.4702473188283998,
      2.7546062964416489, 2.4248098026917591, 2.9649568075666579,
      2.471520344692907, 2.5164331136962761, 2.7715290195372448,
      2.431373942845612, 2.7374424034289628, 2.7116563207902566,
      2.3797114834426747, 2.7191065583844809, 2.631571117926705,
      2.4719476967671525, 2.4586472184978088, 2.5741808791400036,
      2.6140746061683915, 2.4238171129362742, 2.6269795332239023,
      2.5488934422985876, 2.4215178825396935, 2.389816275182667,
      2.4706138527455974, 2.4276553228910345, 2.7615139496295376,
      2.3686706843710472, 2.594483755990828, 2.6633648320828436,
      2.3985051318395278, 2.6363630388734416, 2.48488794229504,
      2.4137764938227089, 2.31104862063282, 2.4019291000841934,
      2.8758666524963958, 2.2914287185687452, 2.4546597464571214,
      2.3654303017846079, 2.7061846669205218, 2.4075386496919142,
      2.4918961037439642, 2.699310016542074, 2.736391740282285,
      2.3764600412237549, 2.5366977739872549, 2.6380652118727372,
      2.5688829360038397, 2.9031239720074824, 2.8010747178455255,
      2.8078626856873723, 2.2055355156092746, 2.5082616362795545,
      2.528190611039637, 2.3775509248594497, 2.4302497105102594,
      2.699813954265466, 2.322348558521127, 2.778932539474738,
      2.8665811553352629, 2.5731440338901654, 2.8905205179702516,
      2.8565619747768873, 2.5848088826685727, 2.4996423217768129,
      2.7223249783613164, 2.4526417422419948, 2.5394408454112911,
      2.784296703938673, 2.3910900565276876, 2.44677225495775,
      2.7268942745694456, 2.2439624244416576, 2.7363015100552106,
      2.5538525175919755, 2.544496700593152, 2.5434324492418332,
      2.5018486877987858, 2.5608937008037502, 2.4885286782308915,
      2.4305342191247856, 2.7503244323414711, 2.5702013083630213,
      2.6520613928516412, 2.6712744308379657, 2.5400366529449721,
      2.5069760932962284, 2.647436486307877, 2.5168800872837864,
      2.663020586686299, 2.3770983171560589, 2.5759609908024603,
      2.5920138673552335, 2.8160978990899217, 2.8816557518188386,
      2.530512647918532, 2.4513019116506491, 2.3849001908252907,
      2.4685130353153935, 2.5712546543883574, 2.3491440994249584,
      2.4859497788577078, 2.6688208910293412, 2.8241820533579469,
      2.7454109181366131, 2.4578994848414641, 2.2153002254701843,
      2.499969720903096, 2.63290948576721, 2.5797086753964908,
      2.4631828253709962, 2.4706584322415557, 2.6495867041992378,
      2.8170721848264648, 2.6822481052028064, 2.1812575105299805,
      2.4212086354736595, 2.3791085075701273, 2.409376969708795,
      2.817230526604769, 2.6353385846139092, 2.575055240639597,
      2.5495682464696361, 2.2329312381522266, 2.5184136499885135,
      2.4623383808862904, 2.5417207883752475, 2.4292101165823476,
      2.6885206309418272, 2.5126852005864517, 2.61552020031584,
      2.6736558821769227, 2.5766191301303176, 2.5762124302126046,
      2.7330600868623884, 2.7360502938301803, 2.3459552073913148,
      2.3446241758857163, 2.8124848444707395, 2.52147025454068,
      2.6006156029948428, 2.6117104050560735, 2.5275955797590779,
      2.5941244395219041, 2.5011066679741765, 2.7625190699764648,
      2.6721586220692757, 2.43597111775781, 2.6887836508314331,
      2.3375350191564781, 2.3634419432749016, 2.3570840180948585,
      2.5341627633390482, 2.6595750380477727, 2.7353481588955688,
      2.4687029867174326, 2.4276035194685197, 2.6018217044085294,
      2.6846340725712476, 2.3683462629480387, 2.4972551429683834,
      2.585267874748074, 2.4917353791121886, 2.528761501482454,
      2.4778547340691812, 2.8618497106454353, 2.2474108503059895,
      2.5890099486069804, 2.8872416808892734, 2.5085443942315386,
      2.6073158736682105, 2.2113997416330822, 2.2820772360211885,
      2.3086821632949581, 2.8494297089841982, 2.7081905237187076,
      2.47780648492563, 2.6171151604896465, 2.9092106502567128,
      2.4169131385961364, 2.6557395919963032, 2.7154608240362954,
      2.3528436504024022, 2.3528581453173647, 2.6321826403922914,
      2.6787959243329218, 2.3165211734711715, 2.761814703097957,
      2.4952958728890358, 2.2439428830359347, 2.6109727493752866,
      2.8008404990204561, 2.5236815115723292, 2.8207494508161552,
      2.7042947226923051, 2.3294563412250562, 2.4202588153238862,
      2.5627182595087525, 2.783284520358956, 2.6615500423144409,
      2.3222720377124668, 2.8161401276824365, 2.6050645585238743,
      2.7249083007105224, 2.4666422676999349, 2.3907383837731748,
      2.3975603437150639, 2.7641034493666594, 2.2099815828430458,
      2.5749784464314667, 2.4675371900765164, 2.4909152999469071,
      2.4687196658979271, 2.5212566159149485, 2.6139592829992853,
      2.443278356823527, 2.40362761603209, 2.3060085964536992,
      2.3796242327026675, 2.8093971119598873, 2.4907102406014379,
      2.2887328042874135, 2.4132651010839252, 2.6251766768818592,
      2.5507768720091923, 2.582711660777242, 2.50811891955179,
      2.8073114508781796, 2.4439883830406783, 2.4285276312526043,
      2.240911807630896, 2.5431758411981606, 2.5110337107522138,
      2.6668958781169274, 2.4718320014550024, 2.3640514654757672,
      2.2198850823878731, 3.0779278830938162, 2.6386754151139424,
      2.9350071595896274, 2.64383491541484, 2.3103465427945231,
      2.7478156066762121, 2.4959945816028197, 2.7870180649595855,
      2.7539259471194741, 2.68945689218934, 2.6334093562123528,
      2.5344989977470429, 2.8972943856313531, 2.5471849484187468,
      2.3534519551349962, 2.3460279294735127, 2.596561837498391,
      2.4249678565760053, 2.2842567879368, 2.5107514450994595,
      2.6847002799026827, 2.7422696356729737, 2.5566571001859408,
      2.4409937759556679, 2.4824213385727196, 2.307143667840053,
      2.6098895970246465, 2.4336279518477983, 2.45749745739809,
      2.4862537548619872, 2.522115536550217, 2.6368485246820486,
      2.5615199764819652, 2.7876059454297892, 2.50157210232057,
      2.668107961102046, 2.3707096139466017, 2.3569211893831321,
      2.2305898987570361, 2.4755790656278931, 2.5606847356558835,
      2.5251049349679731, 2.633591228343418, 2.6197658131734967,
      2.3808121170161218, 2.8571646612877322, 2.7617572085054296,
      2.6965007967219612, 2.5036666454493659, 2.8278068235638791,
      2.6913522939366974, 2.7773439511044371, 2.4377195201863726,
      2.786233638998497, 2.5364518736156936, 2.44352867440914,
      2.3911227262956549, 2.4422692098715317, 2.2848094380004538,
      2.4626960340475734, 2.4001204701048451, 2.7303255577976406,
      2.8417678132452941, 2.4766649587497906, 2.5462938481000434,
      2.4048189704146061, 2.755244241258775, 2.3278542159127058,
      2.8148492593519254, 2.6857188729101171, 2.2313602178766923,
      2.4731086094326873, 2.4982864112507324, 2.664173909798107,
      2.7911714656396023, 2.5586463871360072, 2.4689272046721804,
      2.1095690317826423, 2.4619471877428287, 2.7691933509312441,
      2.4395568604351778, 2.6753362413209789, 2.6383497273826393,
      2.2974428796668329, 2.5282656699950175, 2.7206915791430131,
      2.6564713650208844, 2.6843040191207752, 2.5797673802797565,
      2.4048652418984924, 2.6548109077295656, 2.6037336780319214,
      2.5205644416173678, 2.2969037233425729, 2.57502567893754,
      2.4187111937888739, 2.8586455317226318, 2.6521053215456347,
      2.8923090744543578, 2.5896992709023339, 2.5201582370210533,
      2.4664866462745882, 2.46836688526381, 2.5003413335303906,
      2.8194651264129784, 2.3656686074251083, 2.6989726606370734,
      2.5513929610112625, 2.8362411679411661, 2.328205417940763,
      2.6259309212350708, 2.3883856717744676, 2.4764529789169369,
      2.5650745832004072, 2.4825252379465388, 2.6356480082384706,
      2.5736234265870142, 2.6284339728239359, 2.3120975726312287,
      2.5080395382076794, 2.4777808401670125, 2.5647236226425507,
      2.5591230836996397, 2.7149406212766038, 2.5922930331016447,
      2.7864932697843328, 2.7764787523888823, 2.31908067126911,
      2.3642386294701376, 2.425593877954543, 2.6018588071667232,
      2.3558488374056954, 2.6125459299147193, 2.6401444539505121,
      2.5445234009772055, 2.4959904601716461, 2.864593013906477,
      2.5214551658214477, 2.6964239734227808, 2.4741653543448066,
      2.78566376299797, 2.2311867056344363, 2.479958503538922,
      2.5714154635298847, 2.2164386490184613, 3.1205976305171887,
      2.531644151023329, 2.9649799682973792, 2.6868777251862861,
      2.5522055670579791, 2.307610617960695, 2.4763610002234113,
      2.6134612812960452, 2.2101041660282541, 2.4696061294705434,
      2.6746705205917021, 2.71026220851315, 2.54888314171947, 2.3544809719431781,
      2.3333435956635364, 2.5797849630671816, 2.5981387536374503,
      2.8885665911116778, 2.6514625666608329, 2.5774919219914416,
      2.5897537691907369, 2.5257928264057625, 2.4590000822906273,
      2.7379600730629452, 2.5387214699955374, 2.6163336393915295,
      2.6301095239149532, 2.414884972793387, 2.38968418788025, 2.47358177816648,
      2.1840898584833557, 2.6759792313515756, 2.7118551171772056,
      2.8079708192772896, 2.287246092785578, 2.7785921708234445,
      2.3072035070533712, 2.4552812615396835, 2.5315626438091252,
      2.2685842343357812, 2.6644312238908041, 2.5714377927713019,
      2.5549987963130159, 2.3055794312167492, 2.6581674889024356,
      2.4964200300035335, 2.8305551320370581, 2.8172293489690485,
      2.5479817792801946, 2.6038692755222721, 2.7819300196763423,
      2.8062657488691505, 2.5890447669350052, 2.9855168672311034,
      2.7191423296355515, 2.80249356994013, 2.488678413568314,
      2.3160224757357883, 2.7628718768149128, 2.6797292515089808,
      2.6980850156301868, 2.4245517320032093, 2.4620917252839583,
      2.7667351655894956, 2.4978146602244298, 2.8454667497261159,
      2.431303618524745, 2.9170426314160522, 2.2623627513209872,
      2.1373094409106259, 2.608093453172402, 2.8950288327279257,
      2.7535386069111878, 2.7692138879868051, 2.5313410257853581,
      2.6054802153980807, 2.622620539028012, 2.3511419472965103,
      2.8590219472661409, 2.5032897017994564, 2.6536618647430892,
      2.5089208318246561, 2.9008634642238942, 2.8427084430764671,
      2.698747460920266, 2.5008528014410167, 2.3435220270887305,
      2.6243867429846661, 2.7724094152563907, 2.5467754197874712,
      2.3116134139958326, 2.9300046503438342, 2.3480860479863708,
      2.8542159269494141, 2.7066913732125943, 2.6166754437150033,
      2.5911761720339759, 2.6432962278049086, 2.4965520917436983,
      2.6643466109309326, 2.6674251873491173, 2.7336592309260332,
      2.3801753844739584, 2.6130860168192589, 2.5474047038178447,
      2.9124229753426381, 2.2570650953328291, 2.687573613699183,
      2.4686410135987336, 2.3835614488450827, 2.8040216023670022,
      2.739705199201024, 2.7276119321630774, 2.9625319155212351,
      2.6916503556080711, 2.356147146709457, 2.5668443739521472,
      2.3888354728391379, 2.6296913424400845, 2.5545746354669756,
      2.6693524158419883, 2.7106678848028949, 2.8590669538985694,
      2.472845631429486, 2.690101677302982, 2.3715035447838426,
      2.757894111831328, 2.7434402474140427, 2.4363114369850631,
      2.5712961140623256, 2.9075491707619951, 2.3147194337489028,
      2.626980545490214, 2.3940459448642666, 2.4167042953717042,
      2.7237091216967615, 2.6657260836744214, 2.7549097974071417,
      2.819147808428565, 2.3426835166918352, 2.4300624899502283,
      2.3991666143229593, 2.5999416424821908, 2.8378430207445269,
      2.5922862177602077, 2.50717695392406, 2.5955737934449417,
      2.3307401736107751, 2.4292521296087579, 2.5818705723477247,
      2.3754007820467011, 2.3513924826578321, 2.9638465639140708,
      2.6843109802928113, 2.4036241380355996, 2.4049639172624389,
      2.501100378875142, 2.4206385070865712, 2.361533579234619,
      2.8645210984228227, 2.6860005041377017, 2.5971024202823116,
      2.6119390700128484, 2.3971146624882786, 2.4526339035206774,
      2.5978735692893462, 2.4117581982611047, 2.7603006787182336,
      2.3172483769144536, 2.6887747478430404, 2.4668275993452751,
      2.7951089430780911, 2.6561960450945787, 2.4350416299903359,
      2.5513176809703673, 2.5903384169558676, 2.7185688662401488,
      2.4450773588894474, 2.6800966389116709, 2.5093872800988857,
      2.7022736786616668, 2.7409784476790611, 2.9112059779350892,
      2.4140050901821053, 2.4632481680702467, 2.9195093738975642,
      2.4383170947767514, 2.5707751167504869, 2.5326668868184417,
      2.7672454570297349, 2.6566378588893431, 2.1256417375404637,
      2.8006452515321061, 2.3146543038605749, 2.59473353573725,
      2.6300521605764908, 2.6588963456441439, 2.829712613682263,
      2.26318535656907, 2.6774282593837446, 2.6930139456636777,
      2.8776001364782355, 2.4764410168659161, 2.4177832665823162,
      2.4566705199224619, 2.5094952313631178, 2.761824871092915,
      2.5508846950839761, 2.4822635101671748, 2.5621743399999639,
      2.4404104635832771, 2.5586193227659471, 2.7350754749878519,
      2.4399462373060388, 2.4001316963102517, 2.6937932485536749,
      2.5094980882463531, 2.6287361876793138, 2.8276519233092845,
      2.6212219938827683, 2.2946422405672244, 2.2164527757450552,
      2.3830504579106941, 2.6102487261104437, 2.4209290282774365,
      2.3909910766400491, 2.5704580548917653, 2.5974981779448125,
      2.9022371359701729, 2.5984856025352641, 2.5171957938584262,
      2.5491925387782732, 2.1611108139674471, 2.528995874518237,
      2.4374950445108183, 2.5576809503517852, 2.7179049650031279,
      2.6215107681749776, 2.2155697456851371, 2.3293024741702819,
      2.0578623332905392, 2.4754151426396955, 2.2950506549402023,
      2.4679156971262328, 2.3957245664976141, 2.437218520140946,
      2.7450787953681361, 2.8472520852550414, 2.8980409544705439,
      2.9491930673909432, 2.3854913091734113, 2.5142132213799746,
      2.9752200931627897, 2.6376136302700472, 2.2144371189152325,
      2.5670414611651147, 2.4228114915525452, 2.8759512830172875,
      2.8442700372464609, 2.6577652686083075, 2.3362218344524956,
      2.7565367650478914, 2.6921621771214586, 2.4566777888722209,
      2.448585932363482, 2.7230653148961652, 2.3421925861995012,
      2.284333400241652, 2.3506184000143961, 2.5186817190264943,
      2.6598180135951726, 2.20957362418485, 2.5701585576345236,
      2.3469877353490962, 2.6721849451040551, 2.6081675515364808,
      2.6090050016352264, 2.7370921610636856, 2.5781853614772343,
      2.3843692219531532, 2.6788315011491619, 2.8326018712322432,
      2.4771373000779979, 2.2831731760712515, 2.4843054730405858,
      3.02071689631208, 2.5144868036943135, 2.3880340905551218,
      2.4496451900695724, 2.4318176723018405, 2.3957477701311243,
      2.6343824586330262, 2.7093024439024562, 2.3469175622941725,
      2.3759488590983073, 2.8274872163581652, 2.7232958164311625,
      2.5374835683821395, 2.4182508829393745, 2.5405072560559896,
      2.62075403979997, 2.6796356766992044, 2.3437004092606677,
      2.8347306040849825, 2.4601448022077004, 2.8407778783375495,
      2.6677540088203786, 2.5717758952510072, 2.5049062177683554,
      2.4635638274207663, 2.2287841713312622, 2.357374175428514,
      2.7231677675216974, 2.7856454231159544, 2.5613290040561987,
      2.4694581437999057, 2.6579435586429088, 2.7321101602644005,
      2.3255709324975244, 2.7226835925627784, 2.5940442264539127,
      2.5769913018685826, 2.5815324073033561, 2.5204247143047755,
      2.533473237634019, 2.71855149951683, 2.6278004760168137,
      2.7863702316478776, 2.5935387626928956, 2.3227478882790127,
      2.6795631375632727, 2.4746441407335413, 2.3580825179320124,
      2.504776799809318, 2.7675500206506554, 2.3336845212053356,
      2.6786572001126037, 2.4981779664454029, 2.5077319224995187,
      2.4289174800946656, 2.4992048323383109, 2.7629561713549178,
      2.5008702029376733, 2.5491714512957055, 2.3485053996652714,
      2.38721755031688, 2.5326996478301051, 2.6600580981696309,
      2.5780608985420939, 2.448109536983889, 2.5321842693951306,
      2.7240538183103942, 2.5333332401846276, 2.836026335871936,
      2.4097624184141289, 2.31346742833576, 2.621435007375899,
      2.4992504240941926, 2.5548374806802854, 2.5883492669395229,
      2.8542800745448642, 2.3820475540031048, 2.6170345248129023,
      2.7542592800646863, 2.4347208078038984, 2.5636669690076084,
      2.783389027272968, 2.394762065650661, 2.6376674217400446,
      2.4905043978514265, 2.6237137776612189, 2.6988158672353633,
      2.9306482657809183, 2.2949395869940616, 2.61319415423715,
      2.5298901414175017, 2.5209314345254388, 2.50176779723102,
      2.3408803795701938, 2.5728582739752643, 2.6641654820878289,
      2.5407312977504479, 3.0291833972305393, 2.2811943801257666,
      2.5862755142337162, 2.8293335381975595, 2.3462986683893856,
      2.2923008687443511, 2.59544596209778, 2.4578105499876237,
      2.4325672736464354, 2.3377701794361379, 2.6612844951168, 2.316161379429496,
      4.1096979381077361, 3.8840124823676216, 4.1196764598488995,
      3.9751963725803012, 4.360994392503172, 4.1183125190126884,
      4.3037472052706152, 3.9883556299926246, 4.2763445714947235,
      4.4519763613636218, 3.7895723714581631, 4.0820150627095071,
      4.1505254049783478, 3.9495359406856672, 4.51360246479781,
      4.1134626764659661, 4.4699926021059788, 3.9648581132699419,
      4.09953034466904, 4.0466489572315165, 3.7158636577592579, 3.99984049310093,
      4.0681889581393573, 4.1577873878471623, 3.8661272398975042,
      4.1593402182054788, 4.259776186656981, 4.20084641161484,
      4.1435777218958734, 4.2114826106116912, 4.2473904658955792,
      4.0657937406393589, 4.1755239277413931, 4.3496119160543891,
      3.8994164905654332, 4.3132799019776424, 4.2117307776868511,
      4.4854833806778487, 4.2321294486792329, 4.209870026645663,
      4.0351271010523275, 4.4641046285591912, 4.0307029316482783,
      4.0330823500493276, 4.0883690477676105, 4.1492756874841978,
      3.9459406769198946, 4.1673860259135225, 4.0746311318872266,
      4.4562745915973618, 4.0748784506193783, 4.0815721506091913,
      4.3444131223926457, 4.0752156980978462, 4.2875077799997428,
      4.1455719189686588, 3.9054076215419853, 4.0536317722735857,
      4.1365732678735441, 4.2190767361864712, 4.476013379253204,
      4.1918156955484207, 4.3173087494895874, 3.9935056181825748,
      3.9615597147966741, 4.0439317958828687, 4.1600645905243931,
      4.1970543755307457, 3.9355516582818404, 4.048525665967956,
      4.5333945210225615, 4.2375222467234916, 4.3036614389266141,
      3.903048908478171, 4.1284373466278188, 3.864196954334612,
      4.1272531714305023, 4.1751386644067674, 4.3966470678593241,
      4.0878817263031779, 4.2939217047650651, 3.9844370859406473,
      3.8763499554439145, 4.3807911408192926, 4.2396155658215715,
      4.3135604993180454, 4.195705657266446, 3.8774323134068913,
      4.2583501053909405, 4.1443536665368237, 4.1843962021700882,
      4.1611453764071751, 3.9354815371359466, 4.2848792314379267,
      4.0243587804054721, 4.1196440507659382, 3.935827803280711,
      4.00424217699589, 3.6821343956509804, 4.2182501236444043,
      4.0869834116121861, 4.2165668551794226, 3.9440784895588621,
      4.0468824096415608, 3.9735451354390383, 4.0294341788103907,
      4.1326227423070989, 4.1667499949629647, 4.17489935708052,
      4.4087935552209281, 4.3437373374875161, 4.1457485623985315,
      4.1431008570192311, 4.1929555819590867, 4.1718885380122277,
      4.3177445396625016, 4.3857278382380533, 4.2036739481669745,
      4.2495748088947156, 4.1036273737831657, 3.7648963308957875,
      4.1614904812610085, 3.7916806870111386, 4.0612595061386179,
      4.5021630279760343, 4.335923979056723, 3.907108940295795,
      4.0646613650713945, 4.1149679325699413, 3.9467601519012496,
      4.1489975587354309, 4.1766128000781544, 4.031146554897207,
      4.081285177229212, 4.2253647241154564, 4.2639314420236616,
      4.1562184579356316, 4.0736593079549435, 4.295686774219341,
      4.1032211083305477, 4.156354024609719, 4.2575454209543135,
      4.2443033708005125, 4.2703100395127436, 4.0936616625089144,
      4.4478757676289158, 4.1303443271937974, 4.1180977595695136,
      4.133430020896073, 3.9587483051153489, 4.09039255866946,
      4.2313193797222839, 4.3136767013017066, 3.866370944820718,
      4.1190057818528114, 3.89883827937735, 3.7265374022172186,
      4.3757284756194927, 4.31177571965199, 4.1207061700240226,
      4.4575428283977709, 4.1406697748416814, 4.2296657473730868,
      4.2452035233869712, 4.0709058662616666, 3.8344497553704264,
      4.2532201543651631, 4.1288661310557879, 3.9068574089591985,
      4.0276871842873376, 4.20464150315078, 3.9291291137741475,
      4.0003924812604765, 4.1727486863422971, 4.1779470553994464,
      4.0194443384066592, 4.1158604356430155, 4.2518043783251551,
      3.9015231411538132, 4.1768413333739787, 4.1751773817674556,
      4.0340261693327522, 4.0759809626399921, 4.0898494811906048,
      4.0924684917192131, 4.0344815297217966, 4.2239137994912088,
      4.2626827752258727, 3.9963870836424551, 4.2581782963065749,
      3.8607539640941444, 4.0987650702503782, 4.1983974277832381,
      3.9515095945806529, 4.3135836960711309, 4.0221464550516188,
      3.8953507484155794, 4.4100267262900186, 4.2572761858539057,
      4.30088317907318, 4.7846912828628243, 3.8748401474440231,
      4.2561339116153007, 4.1478216175724754, 4.3694727676077942,
      4.3877651446881787, 4.3649253706060076, 4.2085971952237955,
      3.9321624207517374, 3.9985716488846688, 4.2094850226184883,
      4.3238848115837341, 4.46033309921067, 3.7670273546778072,
      3.9376772792053134, 4.1219810124564216, 4.3928414345870923,
      3.9579168736262291, 4.2863560970211232, 4.118652749430149,
      4.4657916939710152, 4.2340162630733609, 4.08221627366321,
      4.1093401597606638, 4.3063372297992712, 4.3078548578971949,
      4.1911915431217626, 4.4570806743246294, 4.0353654913332955,
      4.4950980340536688, 3.9892397878209716, 4.0652767934132887,
      4.417840684723533, 4.1441262534347416, 4.0488898300452512,
      4.1749608262776086, 4.0159454481189414, 4.3390715777334128,
      3.9560338250216311, 3.931132485502268, 4.1591778395153707,
      4.2143250322763386, 4.1324092626230069, 4.191821591991113,
      4.04896117854111, 4.1761470531457867, 4.0180473774144758,
      4.5695073268618458, 4.0980463271325389, 4.0024126278337837,
      4.1919582677669638, 4.2512723323890844, 4.318227509502039,
      4.2326701384938517, 4.5262904411573714, 4.0870118085562144,
      4.4942645681328237, 4.3808286858299548, 4.2822020238440128,
      3.9912549910420436, 4.0577199516540006, 4.1482172336495688,
      4.3053585328596178, 4.1744720741388628, 4.2255090965399349,
      4.0744078004898245, 4.1877712612809264, 3.9843108335154578,
      4.0781635537844547, 4.3724498831328864, 4.2254980981002355,
      3.8111529243018083, 4.2439587361542142, 4.0386434580648167,
      4.1168986378070525, 4.3797062791902279, 4.3504589574411119,
      3.9451051942667714, 4.3562319572807073, 3.6951243807970231,
      4.1863028817107146, 4.24403339198849, 3.8776428274697197,
      4.4569783169184438, 4.2293110800439919, 3.8898744984859008,
      3.8818872013257391, 4.0873992866312028, 4.480857755819601,
      4.14645238315892, 3.9728123091492904, 3.946892274357515,
      3.9640213376686004, 4.0002454235196439, 4.3002510899826731,
      4.23259217772718, 3.9801152441122616, 4.0456656090393537,
      4.2152922565657569, 4.11528330165422, 3.9063638025393752,
      4.0926787670515932, 4.1043537030579866, 4.1397022158101224,
      4.3393057089571867, 4.54761900810986, 4.2840476494679276,
      4.2721484469045148, 4.3306530225391766, 3.8898737212328038,
      4.2969076287344743, 4.0969852949540284, 4.1703454922891554,
      3.8648386530454863, 4.4315767958261016, 4.1348362067883411,
      4.0729706164060531, 4.1525155079769718, 4.33867979436314,
      4.280122692875322, 4.3517191111159672, 4.3522925865221609,
      4.1756638797464145, 4.111856783948177, 4.3018346263704839,
      4.0838361686983617, 4.0821715662609845, 4.2691550604824116,
      4.2541460355966905, 4.2078404820655262, 4.0941902218142427,
      4.0098989349635961, 4.1107142734954172, 4.2797710097126522,
      3.6558293606119436, 3.8658332137843652, 4.3758909470374885,
      4.0635887736629606, 4.0066170527150486, 4.3244679281003737,
      3.8667035077035838, 4.0127550733459314, 4.1823175634344327,
      4.0489479513973459, 4.20950581901862, 4.2239226181032326,
      4.0447134068319386, 3.7673446986784684, 4.0400397971842947,
      3.8303460677248031, 4.0126831508759038, 3.9068013552385006,
      4.1594973663798722, 4.2259209457625051, 4.1113978637882029,
      4.1352971398598095, 4.2725844636894221, 4.0311808378229284,
      4.34402292119565, 4.0627008748556674, 4.2142436309230344,
      4.1264502485119881, 4.03226210317464, 4.126517798049032,
      4.2238203020887628, 4.0680970852307432, 3.9492606512671324,
      4.154465053081859, 4.1259355714060071, 4.0505111852475117,
      3.9903672630622675, 4.1444467704813324, 4.230786377840742,
      4.6416984175420941, 4.3354795138969813, 4.5240238856072388,
      4.1035521869058638, 4.1733470748897634, 4.24110507356825,
      3.9961346967675389, 3.9128393100802539, 3.8941224035753272,
      3.9176743697297853, 4.0538980723649631, 4.0415670957481193,
      4.24390955767476, 4.1211084658888009, 3.9272150459057062,
      3.8983205221966832, 4.204422178720904, 3.8695364088816624,
      4.1404089488296361, 4.3068431813627495, 3.9831598004471487,
      4.323018597656537, 4.2286181004240309, 4.0580829131384561,
      4.0762438477201544, 4.3514065320285322, 4.0850552848132811 } ;

    Madgwick_embedded_DW->GyroZ_PWORK.TimePtr = (void *) pTimeValues0;
    Madgwick_embedded_DW->GyroZ_PWORK.DataPtr = (void *) pDataValues0;
    Madgwick_embedded_DW->GyroZ_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for Delay: '<S1>/Delay' */
  Madgwick_embedded_DW->Delay_DSTATE[0] = 1.0;
  Madgwick_embedded_DW->Delay_DSTATE[1] = 0.0;
  Madgwick_embedded_DW->Delay_DSTATE[2] = 0.0;
  Madgwick_embedded_DW->Delay_DSTATE[3] = 0.0;

  /* Start for MATLABSystem: '<S1>/Coordinate Transformation Conversion' */
  Madgwick_embedded_DW->objisempty = true;
  Madgwick_embedded_DW->obj.isInitialized = 1;
}

/* Model terminate function */
void Madgwick_embedded_terminate(RT_MODEL_Madgwick_embedded_T
  * Madgwick_embedded_M)
{
  rt_FREE(Madgwick_embedded_M->solverInfo);

  /* model code */
  rt_FREE(Madgwick_embedded_M->blockIO);
  rt_FREE(Madgwick_embedded_M->dwork);
  rt_FREE(Madgwick_embedded_M);
}

/* Model data allocation function */
RT_MODEL_Madgwick_embedded_T *Madgwick_embedded(void)
{
  RT_MODEL_Madgwick_embedded_T *Madgwick_embedded_M;
  Madgwick_embedded_M = (RT_MODEL_Madgwick_embedded_T *) malloc(sizeof
    (RT_MODEL_Madgwick_embedded_T));
  if (Madgwick_embedded_M == NULL) {
    return NULL;
  }

  (void) memset((char *)Madgwick_embedded_M, 0,
                sizeof(RT_MODEL_Madgwick_embedded_T));

  {
    /* Setup solver object */
    RTWSolverInfo *rt_SolverInfo = (RTWSolverInfo *) malloc(sizeof(RTWSolverInfo));
    rt_VALIDATE_MEMORY(Madgwick_embedded_M,rt_SolverInfo);
    Madgwick_embedded_M->solverInfo = (rt_SolverInfo);
    rtsiSetSimTimeStepPtr(Madgwick_embedded_M->solverInfo,
                          &Madgwick_embedded_M->Timing.simTimeStep);
    rtsiSetTPtr(Madgwick_embedded_M->solverInfo, &rtmGetTPtr(Madgwick_embedded_M));
    rtsiSetStepSizePtr(Madgwick_embedded_M->solverInfo,
                       &Madgwick_embedded_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(Madgwick_embedded_M->solverInfo, (&rtmGetErrorStatus
      (Madgwick_embedded_M)));
    rtsiSetRTModelPtr(Madgwick_embedded_M->solverInfo, Madgwick_embedded_M);
  }

  rtsiSetSolverName(Madgwick_embedded_M->solverInfo,"FixedStepDiscrete");

  /* block I/O */
  {
    B_Madgwick_embedded_T *b = (B_Madgwick_embedded_T *) malloc(sizeof
      (B_Madgwick_embedded_T));
    rt_VALIDATE_MEMORY(Madgwick_embedded_M,b);
    Madgwick_embedded_M->blockIO = (b);
  }

  /* states (dwork) */
  {
    DW_Madgwick_embedded_T *dwork = (DW_Madgwick_embedded_T *) malloc(sizeof
      (DW_Madgwick_embedded_T));
    rt_VALIDATE_MEMORY(Madgwick_embedded_M,dwork);
    Madgwick_embedded_M->dwork = (dwork);
  }

  {
    B_Madgwick_embedded_T *Madgwick_embedded_B = ((B_Madgwick_embedded_T *)
      Madgwick_embedded_M->blockIO);
    DW_Madgwick_embedded_T *Madgwick_embedded_DW = ((DW_Madgwick_embedded_T *)
      Madgwick_embedded_M->dwork);
    rtsiSetSimTimeStep(Madgwick_embedded_M->solverInfo, MAJOR_TIME_STEP);
    rtmSetTPtr(Madgwick_embedded_M, &Madgwick_embedded_M->Timing.tArray[0]);
    Madgwick_embedded_M->Timing.stepSize0 = 0.01;

    /* block I/O */
    (void) memset(((void *) Madgwick_embedded_B), 0,
                  sizeof(B_Madgwick_embedded_T));

    /* states (dwork) */
    (void) memset((void *)Madgwick_embedded_DW, 0,
                  sizeof(DW_Madgwick_embedded_T));
  }

  return Madgwick_embedded_M;
}
