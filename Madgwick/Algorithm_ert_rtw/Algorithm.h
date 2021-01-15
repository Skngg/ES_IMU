/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Algorithm.h
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

#ifndef RTW_HEADER_Algorithm_h_
#define RTW_HEADER_Algorithm_h_
#include <math.h>
#ifndef Algorithm_COMMON_INCLUDES_
# define Algorithm_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Algorithm_COMMON_INCLUDES_ */

#include "Algorithm_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T Delay_DSTATE[4];            /* '<S1>/Delay' */
  real32_T VectorConcatenate[12];      /* '<S3>/Vector Concatenate' */
} DW_Algorithm_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T AccX;                       /* '<Root>/AccX' */
  real32_T AccY;                       /* '<Root>/AccY' */
  real32_T AccZ;                       /* '<Root>/AccZ' */
  real32_T GyroX;                      /* '<Root>/GyroX' */
  real32_T GyroY;                      /* '<Root>/GyroY' */
  real32_T GyroZ;                      /* '<Root>/GyroZ' */
} ExtU_Algorithm_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Quat[4];                    /* '<Root>/Quat' */
} ExtY_Algorithm_T;

/* Block signals and states (default storage) */
extern DW_Algorithm_T Algorithm_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Algorithm_T Algorithm_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Algorithm_T Algorithm_Y;

/* Model entry point functions */
extern void Algorithm_initialize(void);
extern void Algorithm_step(void);
extern void Algorithm_terminate(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Constant1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Madgwick_embedded/Algorithm')    - opens subsystem Madgwick_embedded/Algorithm
 * hilite_system('Madgwick_embedded/Algorithm/Kp') - opens and selects block Kp
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
#endif                                 /* RTW_HEADER_Algorithm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
