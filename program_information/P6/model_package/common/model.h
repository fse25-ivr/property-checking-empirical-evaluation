/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: model.h
 *
 * Code generated for Simulink model 'model'.
 *
 * Model version                  : 1.83
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug 25 11:32:49 2021
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
  uint32_T SoundEventCounter;          /* '<Root>/Security System' */
  uint32_T call_policeEventCounter;    /* '<Root>/Security System' */
  uint32_T temporalCounter_i1;         /* '<Root>/Security System' */
  uint32_T temporalCounter_i2;         /* '<Root>/Security System' */
  uint8_T is_active_c1_model;          /* '<Root>/Security System' */
  uint8_T is_Motion;                   /* '<Root>/Security System' */
  uint8_T is_active_Motion;            /* '<Root>/Security System' */
  uint8_T is_Active;                   /* '<Root>/Security System' */
  uint8_T is_Door;                     /* '<Root>/Security System' */
  uint8_T is_active_Door;              /* '<Root>/Security System' */
  uint8_T is_Win;                      /* '<Root>/Security System' */
  uint8_T is_active_Win;               /* '<Root>/Security System' */
  uint8_T is_Alarm;                    /* '<Root>/Security System' */
  uint8_T is_active_Alarm;             /* '<Root>/Security System' */
  uint8_T is_On;                       /* '<Root>/Security System' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T D_mode;                    /* '<Root>/D_mode' */
  boolean_T W_mode;                    /* '<Root>/W_mode' */
  boolean_T M_mode;                    /* '<Root>/M_mode' */
  boolean_T Door_sens;                 /* '<Root>/Door_sens' */
  boolean_T Win_sens;                  /* '<Root>/Win_sens' */
  boolean_T Mot_sens;                  /* '<Root>/Mot_sens' */
  boolean_T Alarm_active;              /* '<Root>/Alarm_active' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T Sound;                     /* '<Root>/Sound' */
  boolean_T call_police;               /* '<Root>/call_police' */
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
 * '<S1>'   : 'model/Security System'
 */
#endif                                 /* RTW_HEADER_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
