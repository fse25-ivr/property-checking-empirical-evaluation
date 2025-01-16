/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Controller.c
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
#include<stdio.h>
#include "../common/model.h"

/* Named constants for Chart: '<Root>/Controller.Light1Controller' */
#define IN_DelayState                  ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_WaitForInput                ((uint8_T)2U)
#define IN_WaitUntilSafeToChange       ((uint8_T)3U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

#define REDDELAY ((uint8_T)4U-1)
#define YELLOWDELAY ((uint8_T)9U-1)
#define GREENDELAY ((uint8_T)14U-1)
#define MINGREENDELAY ((uint8_T)12U-1)
#define MAXREDDELAY ((uint8_T)20U-1)

char* lightmode_state_str[] = {"LightModeType_Green","LightModeType_Yellow","LightModeType_Red","LightModeType_None"};
char* red_state_str[] = {"IN_NO_ACTIVE_CHILD","IN_DelayState","IN_WaitForInput","IN_WaitUntilSafeToChange"};
char* bool_str[] = {"false","true"};

/* Model step function */
void model_step(void)
{

  printf("%s %s %d %s %s %d %d %d %d %d %d\n", red_state_str[rtDW.is_Red], 
    lightmode_state_str[rtY.LightMode], rtU.numCars,
    bool_str[rtDW.greenLightLocked],
    bool_str[rtDW.greenLightRequested],
    rtDW.temporalCounter_i1, 
    REDDELAY, YELLOWDELAY, GREENDELAY, MINGREENDELAY, 
    MAXREDDELAY);

  /* Chart: '<Root>/Controller.Light1Controller' incorporates:
   *  Inport: '<Root>/numCars'
   *  Outport: '<Root>/LightMode'
   */
  if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c3_sf_traffic_light_l == 0U) {
    rtDW.is_active_c3_sf_traffic_light_l = 1U;

    /* Outport: '<Root>/LightMode' */
    rtY.LightMode = LightModeType_Red;
    rtDW.is_Red = IN_DelayState;
    rtDW.temporalCounter_i1 = 0U;
  } else {
    switch (rtY.LightMode) {
     case LightModeType_Green:
      if ((rtDW.temporalCounter_i1 >= 14U) || ((rtDW.temporalCounter_i1 >= 12U) &&
           rtDW.greenLightRequested)) {
        rtY.LightMode = LightModeType_Yellow;
        rtDW.temporalCounter_i1 = 0U;
      }
      break;

     case LightModeType_Yellow:
      if (rtDW.temporalCounter_i1 >= 9U) {
        rtDW.temporalCounter_i1 = false;
        rtY.LightMode = LightModeType_Red;
        rtDW.is_Red = IN_DelayState;
        rtDW.temporalCounter_i1 = 0U;
      }
      break;

     default:
      switch (rtDW.is_Red) {
       case IN_DelayState:
        if (rtDW.temporalCounter_i1 >= 4U) {
          rtDW.is_Red = IN_WaitForInput;
          rtDW.temporalCounter_i1 = 0U;
        }
        break;

       case IN_WaitForInput:
        if ((rtU.numCars > 0) || (rtDW.temporalCounter_i1 >= 20U)) {
          rtDW.is_Red = IN_WaitUntilSafeToChange;
          rtDW.temporalCounter_i1 = 0U;
        }
        break;

       default:
        if ((!rtDW.greenLightLocked) && (rtDW.temporalCounter_i1 >= 4U)) {
          rtDW.is_Red = IN_NO_ACTIVE_CHILD;
          rtY.LightMode = LightModeType_Green;
          rtDW.temporalCounter_i1 = 0U;
          rtDW.greenLightLocked = true;
          rtDW.greenLightRequested = false;
        } else {
          rtDW.greenLightRequested = true;
        }
        break;
      }
      break;
    }
  }
  
  /* End of Chart: '<Root>/Controller.Light1Controller' */
}

/* Model initialize function */
void model_initialize(void)
{
  /* Registration code */

  /* external outputs */
  rtY.LightMode = LightModeType_None;

  /* SystemInitialize for Outport: '<Root>/LightMode' incorporates:
   *  Chart: '<Root>/Controller.Light1Controller'
   */
  rtY.LightMode = LightModeType_None;

  //nat
  rtDW.is_active_c3_sf_traffic_light_l = 0;
  rtDW.is_Red = 0;
  rtDW.temporalCounter_i1 = 0;
  //nat
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */