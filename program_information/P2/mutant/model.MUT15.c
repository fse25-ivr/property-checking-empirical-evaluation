/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: model.c
 *
 * Code generated for Simulink model 'model'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Aug 18 18:18:30 2021
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

/* Named constants for Chart: '<Root>/Vending_Machine' */
#define IN_got_0                       ((uint8_T)1U)
#define IN_got_dime                    ((uint8_T)2U)
#define IN_got_nickel                  ((uint8_T)3U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

char* state_str[] = {"IN_NO_ACTIVE_CHILD","IN_got_0","IN_got_dime","IN_got_nickel"};

/* Model step function */
void model_step(void)
{
  printf("%s %d\n", state_str[rtDW.is_c1_model], rtU.coin);

  /* Outport: '<Root>/soda' incorporates:
   *  Chart: '<Root>/Vending_Machine'
   */
  rtY.soda = false;

  /* Chart: '<Root>/Vending_Machine' incorporates:
   *  Inport: '<Root>/coin'
   */
  if (rtDW.is_active_c1_model == 0U) {
    rtDW.is_active_c1_model = 1U;
    rtDW.is_c1_model = IN_got_0;
  } else {
    switch (rtDW.is_c1_model) {
     case IN_got_0:
      switch (rtU.coin) {
       case 1:
        /* Outport: '<Root>/soda' */
        rtY.soda = false;
        rtDW.is_c1_model = IN_got_nickel;
        break;

       case 2:
        /* Outport: '<Root>/soda' */
        rtY.soda = false;
        rtDW.is_c1_model = IN_got_dime;
        break;
      }
      break;

     case IN_got_dime:
      ;












      break;

     default:
      switch (rtU.coin) {
       case 1:
        /* Outport: '<Root>/soda' */
        rtY.soda = false;
        rtDW.is_c1_model = IN_got_dime;
        break;

       case 2:
        /* Outport: '<Root>/soda' */
        rtY.soda = true;
        rtDW.is_c1_model = IN_got_0;
        break;
      }
      break;
    }
  }
}

/* Model initialize function */
void model_initialize(void)
{
  /* (no initialization code required) */
  //nat
  rtDW.is_active_c1_model = 0;
  rtDW.is_c1_model = 0;
  //nat
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
