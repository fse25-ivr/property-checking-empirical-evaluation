/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: model.c
 *
 * Code generated for Simulink model 'model'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug 25 23:34:34 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Mac OS X)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */
#include <stdio.h>
#include "../common/model.h"

/* Named constants for State Transition Table: '<Root>/Debouncer Logic Table' */
#define IN_OFF                         ((uint8_T)1U)
#define IN_OFF_TO_ON                   ((uint8_T)2U)
#define IN_ON                          ((uint8_T)3U)
#define IN_ON_TO_OFF                   ((uint8_T)4U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

char* state_str[] = {"IN_NO_ACTIVE_CHILD","IN_OFF","IN_OFF_TO_ON","IN_ON","IN_ON_TO_OFF"};

/* Model step function */
void model_step(void)
{

  printf("%s %d %d\n", state_str[rtDW.is_c4_model],
    rtU.u, rtDW.temporalCounter_i1);

  /* State Transition Table: '<Root>/Debouncer Logic Table' incorporates:
   *  Inport: '<Root>/u'
   */
  if (rtDW.temporalCounter_i1 < 15U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_c4_model == 0U) {
    rtDW.is_active_c4_model = 1U;
    rtDW.is_c4_model = IN_ON;

    /* Outport: '<Root>/y' */
    rtY.y = 1.0;
  } else {
    switch (rtDW.is_c4_model) {
     case IN_OFF:
      /* Outport: '<Root>/y' */
      rtY.y = 0.0;
      if (rtU.u) {
        rtDW.is_c4_model = IN_OFF_TO_ON;
        rtDW.temporalCounter_i1 = 0U;
      }
      break;

     case IN_OFF_TO_ON:
      if (rtDW.temporalCounter_i1 >= 10U) {
        rtDW.is_c4_model = IN_ON;

        /* Outport: '<Root>/y' */
        rtY.y = 1.0;
      } else {
        if (!rtU.u) {
          rtDW.is_c4_model = IN_OFF;

          /* Outport: '<Root>/y' */
          rtY.y = 0.0;
        }
      }
      break;

     case IN_ON:
      /* Outport: '<Root>/y' */
      rtY.y = 1.0;
      if (!rtU.u) {
        rtDW.is_c4_model = IN_ON_TO_OFF;
        rtDW.temporalCounter_i1 = 0U;
      }
      break;

     default:
      if (rtDW.temporalCounter_i1 >= 10U) {
        rtDW.is_c4_model = IN_OFF;

        /* Outport: '<Root>/y' */
        rtY.y = 0.0;
      } else {
        if (rtU.u) {
          rtDW.is_c4_model = IN_ON;

          /* Outport: '<Root>/y' */
          rtY.y = 1.0;
        }
      }
      break;
    }
  }

  /* End of State Transition Table: '<Root>/Debouncer Logic Table' */
}

/* Model initialize function */
void model_initialize(void)
{
  /* (no initialization code required) */
  //nat
  rtDW.is_active_c4_model = 0;
  rtDW.is_c4_model = 0;
  rtDW.temporalCounter_i1 = 0;
  //nat
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
