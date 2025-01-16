/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller.h
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.239
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Aug 20 14:43:26 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Mac OS X)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Controller_h_
#define RTW_HEADER_Controller_h_
#include "rtwtypes.h"
#ifndef Controller_COMMON_INCLUDES_
# define Controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Controller_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_LightModeType_
#define DEFINED_TYPEDEF_FOR_LightModeType_

typedef enum {
  LightModeType_Green = 0,
  LightModeType_Yellow,
  LightModeType_Red,
  LightModeType_None                   /* Default value */
} LightModeType;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  uint32_T temporalCounter_i1;         /* '<Root>/Controller.Light1Controller' */
  uint8_T is_active_c3_sf_traffic_light_l;/* '<Root>/Controller.Light1Controller' */
  uint8_T is_Red;                      /* '<Root>/Controller.Light1Controller' */
  boolean_T greenLightLocked;          /* '<Root>/_DataStoreBlk_1' */
  boolean_T greenLightRequested;       /* '<Root>/_DataStoreBlk_2' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T numCars;                     /* '<Root>/numCars' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  LightModeType LightMode;             /* '<Root>/LightMode' */
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
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('model/Traffic Controller/Controller.Light1Controller')    - opens subsystem model/Traffic Controller/Controller.Light1Controller
 * hilite_system('model/Traffic Controller/Controller.Light1Controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'model/Traffic Controller'
 * '<S1>'   : 'model/Traffic Controller/Controller.Light1Controller'
 */
#endif                                 /* RTW_HEADER_Controller_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
