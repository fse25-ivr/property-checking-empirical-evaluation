/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: model.h
 *
 * Code generated for Simulink model 'model'.
 *
 * Model version                  : 1.79
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug 25 22:18:04 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Mac OS X)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_model_h_
#define RTW_HEADER_model_h_
#ifndef model_COMMON_INCLUDES_
# define model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* model_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_c1_model;                 /* '<Root>/MooreChart' */
  uint8_T is_c2_model;                 /* '<Root>/MealyChart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T u;                           /* '<Root>/u' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T seqFound1;                 /* '<Root>/seqFound1' */
  boolean_T seqFound2;                 /* '<Root>/seqFound2' */
  real_T state1;                       /* '<Root>/state1' */
  real_T state2;                       /* '<Root>/state2' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void model_initialize(void);
extern void model_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'model'
 * '<S1>'   : 'model/MealyChart'
 * '<S2>'   : 'model/MooreChart'
 */
#endif                                 /* RTW_HEADER_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
