/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Madgwick_embedded.h
 *
 * Code generated for Simulink model 'Madgwick_embedded'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Mon Nov 23 21:38:45 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Madgwick_embedded_h_
#define RTW_HEADER_Madgwick_embedded_h_
#include <math.h>
#ifndef Madgwick_embedded_COMMON_INCLUDES_
# define Madgwick_embedded_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Madgwick_embedded_COMMON_INCLUDES_ */

#include "Madgwick_embedded_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T S_Eq_estt[4];                 /* '<S1>/Sum1' */
  real_T TmpSignalConversionAtMATLABAnim[3];
  real_T CoordinateTransformationConvers[3];
                               /* '<S1>/Coordinate Transformation Conversion' */
} B_Madgwick_embedded_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[4];              /* '<S1>/Delay' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } GyroX_PWORK;                       /* '<Root>/GyroX' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } GyroY_PWORK;                       /* '<Root>/GyroY' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } GyroZ_PWORK;                       /* '<Root>/GyroZ' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } AccX_PWORK;                        /* '<Root>/AccX' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } AccY_PWORK;                        /* '<Root>/AccY' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } AccZ_PWORK;                        /* '<Root>/AccZ' */

  struct {
    int_T PrevIndex;
  } GyroX_IWORK;                       /* '<Root>/GyroX' */

  struct {
    int_T PrevIndex;
  } GyroY_IWORK;                       /* '<Root>/GyroY' */

  struct {
    int_T PrevIndex;
  } GyroZ_IWORK;                       /* '<Root>/GyroZ' */

  struct {
    int_T PrevIndex;
  } AccX_IWORK;                        /* '<Root>/AccX' */

  struct {
    int_T PrevIndex;
  } AccY_IWORK;                        /* '<Root>/AccY' */

  struct {
    int_T PrevIndex;
  } AccZ_IWORK;                        /* '<Root>/AccZ' */
} DW_Madgwick_embedded_T;

/* Real-time Model Data Structure */
struct tag_RTM_Madgwick_embedded_T {
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

/* Block signals (default storage) */
extern B_Madgwick_embedded_T Madgwick_embedded_B;

/* Block states (default storage) */
extern DW_Madgwick_embedded_T Madgwick_embedded_DW;

/* Model entry point functions */
extern void Madgwick_embedded_initialize(void);
extern void Madgwick_embedded_step(void);
extern void Madgwick_embedded_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Madgwick_embedded_T *const Madgwick_embedded_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
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
 * '<Root>' : 'Madgwick_embedded'
 * '<S1>'   : 'Madgwick_embedded/Algorithm'
 * '<S2>'   : 'Madgwick_embedded/Algorithm/Quaternion Multiplication'
 * '<S3>'   : 'Madgwick_embedded/Algorithm/Subsystem'
 * '<S4>'   : 'Madgwick_embedded/Algorithm/Subsystem1'
 * '<S5>'   : 'Madgwick_embedded/Algorithm/Quaternion Multiplication/q0'
 * '<S6>'   : 'Madgwick_embedded/Algorithm/Quaternion Multiplication/q1'
 * '<S7>'   : 'Madgwick_embedded/Algorithm/Quaternion Multiplication/q2'
 * '<S8>'   : 'Madgwick_embedded/Algorithm/Quaternion Multiplication/q3'
 * '<S9>'   : 'Madgwick_embedded/Algorithm/Subsystem/Row1'
 * '<S10>'  : 'Madgwick_embedded/Algorithm/Subsystem/Row2'
 * '<S11>'  : 'Madgwick_embedded/Algorithm/Subsystem/Row3'
 * '<S12>'  : 'Madgwick_embedded/Algorithm/Subsystem1/row1'
 * '<S13>'  : 'Madgwick_embedded/Algorithm/Subsystem1/row2'
 * '<S14>'  : 'Madgwick_embedded/Algorithm/Subsystem1/row3'
 */
#endif                                 /* RTW_HEADER_Madgwick_embedded_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
