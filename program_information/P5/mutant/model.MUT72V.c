/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: model.c
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
#include<stdio.h>
#include "../common/model.h"

/* Named constants for Chart: '<Root>/MealyChart' */
#define IN_s0                          ((uint8_T)1U)
#define IN_s1                          ((uint8_T)2U)
#define IN_s12                         ((uint8_T)3U)
#define IN_s121                        ((uint8_T)4U)
#define IN_s1213                       ((uint8_T)5U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

char* state_str[] = {"IN_NO_ACTIVE_CHILD","IN_s0","IN_s1","IN_s12","IN_s121","IN_s1213"};

/* Model step function */
void model_step(void)
{

  printf("%s %d\n", state_str[rtDW.is_c1_model],
    rtU.u);

  /* Outport: '<Root>/seqFound1' incorporates:
   *  Chart: '<Root>/MooreChart'
   */
  rtY.seqFound1 = false;

  /* Outport: '<Root>/state1' incorporates:
   *  Chart: '<Root>/MooreChart'
   */
  rtY.state1 = 0.0;

  /* Chart: '<Root>/MooreChart' incorporates:
   *  Inport: '<Root>/u'
   */
  switch (rtDW.is_c1_model) {
   case IN_s0:
    /* Outport: '<Root>/state1' */
    rtY.state1 = 0.0;

    /* Outport: '<Root>/seqFound1' */
    rtY.seqFound1 = false;
    break;

   case IN_s1:
    /* Outport: '<Root>/state1' */
    rtY.state1 = 1.0;

    /* Outport: '<Root>/seqFound1' */
    rtY.seqFound1 = false;
    break;

   case IN_s12:
    /* Outport: '<Root>/state1' */
    rtY.state1 = 2.0;
    break;

   case IN_s121:
    /* Outport: '<Root>/state1' */
    rtY.state1 = 3.0;
    break;

   default:
    /* Outport: '<Root>/state1' */
    rtY.state1 = 4.0;

    /* Outport: '<Root>/seqFound1' */
    rtY.seqFound1 = true;
    break;
  }

  switch (rtDW.is_c1_model) {
   case IN_s0:
    if (rtU.u == 1) {
      rtDW.is_c1_model = IN_s1;
    }
    break;

   case IN_s1:
    if (rtU.u == 2) {
      rtDW.is_c1_model = IN_s12;
    } else {
      if (rtU.u != 1) {
        rtDW.is_c1_model = IN_s0;
      }
    }
    break;

   case IN_s12:
    if (rtU.u == 1) {
      rtDW.is_c1_model = IN_s121;
    } else {
      rtDW.is_c1_model = IN_s0;
    }
    break;

   case IN_s121:
    if (rtU.u == 1) {
      rtDW.is_c1_model = IN_s1;
    } else if (rtU.u == 3) {
      rtDW.is_c1_model = IN_s1213;
    } else if (rtU.u == 2) {
      rtDW.is_c1_model = IN_s12;
    } else {
      rtDW.is_c1_model = IN_s0;
    }
    break;

   default:
    if (rtU.u == 1) {
      rtDW.is_c1_model = IN_s1;
    } else {
      rtDW.is_c1_model = IN_s0;
    }
    break;
  }

  /* Outport: '<Root>/seqFound2' incorporates:
   *  Chart: '<Root>/MealyChart'
   */
  rtY.seqFound2 = false;

  /* Outport: '<Root>/state2' incorporates:
   *  Chart: '<Root>/MealyChart'
   */
  rtY.state2 = 0.0;

  /* Chart: '<Root>/MealyChart' incorporates:
   *  Inport: '<Root>/u'
   */
  switch (rtDW.is_c2_model) {
   case IN_s0:
    if (rtU.u == 1) {
      /* Outport: '<Root>/state2' */
      rtY.state2 = 1.0;
      rtDW.is_c2_model = IN_s1;
    }
    break;

   case IN_s1:
    if (rtU.u == 2) {
      /* Outport: '<Root>/state2' */
      rtY.state2 = 2.0;
      rtDW.is_c2_model = IN_s12;
    } else {
      if (rtU.u != 1) {
        /* Outport: '<Root>/state2' */
        rtY.state2 = 0.0;
        rtDW.is_c2_model = IN_s0;
      }
    }
    break;

   case IN_s12:
    if (rtU.u == 1) {
      /* Outport: '<Root>/state2' */
      rtY.state2 = 3.0;
      rtDW.is_c2_model = IN_s121;
    } else {
      /* Outport: '<Root>/state2' */
      rtY.state2 = 0.0;
      rtDW.is_c2_model = IN_s0;
    }
    break;

   case IN_s121:
    if (rtU.u == 1) {
      /* Outport: '<Root>/state2' */
      rtY.seqFound1 = 1.0;
      rtDW.is_c2_model = IN_s1;
    } else if (rtU.u == 3) {
      /* Outport: '<Root>/state2' */
      rtY.state2 = 4.0;

      /* Outport: '<Root>/seqFound2' */
      rtY.seqFound2 = true;
      rtDW.is_c2_model = IN_s1213;
    } else if (rtU.u == 2) {
      /* Outport: '<Root>/state2' */
      rtY.state2 = 2.0;
      rtDW.is_c2_model = IN_s12;
    } else {
      /* Outport: '<Root>/state2' */
      rtY.state2 = 0.0;
      rtDW.is_c2_model = IN_s0;
    }
    break;

   default:
    if (rtU.u == 1) {
      /* Outport: '<Root>/state2' */
      rtY.state2 = 1.0;

      /* Outport: '<Root>/seqFound2' */
      rtY.seqFound2 = false;
      rtDW.is_c2_model = IN_s1;
    } else {
      /* Outport: '<Root>/state2' */
      rtY.state2 = 0.0;

      /* Outport: '<Root>/seqFound2' */
      rtY.seqFound2 = false;
      rtDW.is_c2_model = IN_s0;
    }
    break;
  }
}

/* Model initialize function */
void model_initialize(void)
{
  /* Chart: '<Root>/MooreChart' */
  rtDW.is_c1_model = IN_s0;

  /* Chart: '<Root>/MealyChart' */
  rtDW.is_c2_model = IN_s0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
