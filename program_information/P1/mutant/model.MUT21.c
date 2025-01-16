/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: model.c
 *
 * Code generated for Simulink model 'model'.
 *
 * Model version                  : 1.100
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Tue Aug 17 13:49:50 2021
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

/* Named constants for Chart: '<Root>/Bang-Bang Controller' */
#define GREEN                          ((int8_T)2)
#define IN_HIGH                        ((uint8_T)1U)
#define IN_NORM                        ((uint8_T)2U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_Off                         ((uint8_T)1U)
#define IN_On                          ((uint8_T)2U)
#define OFF                            ((int8_T)0)
#define ON                             ((int8_T)1)
#define RED                            ((int8_T)1)
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong/long check: insufficient preprocessor integer range. */

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void flash_LED(void);
static boolean_T cold(void);
static boolean_T warm(void);
static void turn_boiler(int8_T mode);

/* Function for Chart: '<Root>/Bang-Bang Controller' */
static void flash_LED(void)
{
  /* Outport: '<Root>/LED' */
  if (rtY.LED == OFF) {
    rtY.LED = rtDW.color;
  } else {
    rtY.LED = OFF;
  }

  /* End of Outport: '<Root>/LED' */
}

/* Function for Chart: '<Root>/Bang-Bang Controller' */
static boolean_T cold(void)
{
  /* Inport: '<Root>/temp' incorporates:
   *  Constant: '<Root>/temperature set point'
   */
  return rtU.temp <= 20;
}

/* Function for Chart: '<Root>/Bang-Bang Controller' */
static boolean_T warm(void)
{
  return !cold();
}

/* Function for Chart: '<Root>/Bang-Bang Controller' */
static void turn_boiler(int8_T mode)
{
  if (mode == ON) {
    rtDW.color = GREEN;
  } else {
    rtDW.color = RED;
  }

  /* Outport: '<Root>/LED' */
  ;

  /* Outport: '<Root>/boiler' */
  rtY.boiler = mode;
}

char* state_str[] = {"IN_NO_ACTIVE_CHILD","IN_Off","IN_On"};
char* state1_str[] = {"IN_NO_ACTIVE_CHILD","IN_HIGH","IN_NORM"};
#define reference ((uint8_T) 20)

/* Model step function */
void model_step(void)
{
  printf("%s %d %d %s %s %d\n", state1_str[rtDW.is_On], 
    rtU.temp, rtDW.temporalCounter_i1, 
    state_str[rtDW.is_c7_model],
    state1_str[rtDW.was_On], reference);

  /* Chart: '<Root>/Bang-Bang Controller' */
  if (rtDW.temporalCounter_i1 < 63U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.temporalCounter_i2 < 7U) {
    rtDW.temporalCounter_i2++;
  }

  if (rtDW.is_active_c7_model == 0U) {
    rtDW.is_active_c7_model = 1U;
    rtDW.is_c7_model = IN_Off;
    rtDW.temporalCounter_i1 = 0U;
    turn_boiler(OFF);
    rtDW.temporalCounter_i2 = 0U;
    flash_LED();
  } else if (rtDW.is_c7_model == IN_Off) {
    if ((rtDW.temporalCounter_i1 >= 40U) && cold()) {
      rtDW.is_c7_model = IN_On;
      rtDW.temporalCounter_i1 = 0U;
      turn_boiler(ON);
      switch (rtDW.was_On) {
       case IN_HIGH:
        rtDW.is_On = IN_HIGH;
        rtDW.was_On = IN_HIGH;
        break;

       case IN_NORM:
        rtDW.is_On = IN_NORM;
        rtDW.was_On = IN_NORM;
        break;

       default:
        rtDW.is_On = IN_HIGH;
        rtDW.was_On = IN_HIGH;
        break;
      }
    } else {
      if (rtDW.temporalCounter_i2 >= 5U) {
        rtDW.temporalCounter_i2 = 0U;
        flash_LED();
      }
    }
  } else if (rtDW.temporalCounter_i1 >= 20U) {
    rtDW.is_On = IN_NO_ACTIVE_CHILD;
    rtDW.is_c7_model = IN_Off;
    rtDW.temporalCounter_i1 = 0U;
    turn_boiler(OFF);
    rtDW.temporalCounter_i2 = 0U;
    flash_LED();
  } else {
    flash_LED();
    if (rtDW.is_On == IN_HIGH) {
      if (warm()) {
        rtDW.is_On = IN_NORM;
        rtDW.was_On = IN_NORM;
      }
    } else {
      if (warm()) {
        rtDW.is_On = IN_NO_ACTIVE_CHILD;
        rtDW.is_c7_model = IN_Off;
        rtDW.temporalCounter_i1 = 0U;
        turn_boiler(OFF);
        rtDW.temporalCounter_i2 = 0U;
        flash_LED();
      }
    }
  }

  /* End of Chart: '<Root>/Bang-Bang Controller' */
}

/* Model initialize function */
void model_initialize(void)
{
  /* Registration code */

  /* external inputs */
  rtU.temp = 38;

  //nat
  rtDW.is_active_c7_model = 0;
  rtDW.is_c7_model = 0;
  rtDW.is_On = 0;
  rtDW.was_On = 0;
  rtDW.temporalCounter_i1 = 0;
  //nat
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
