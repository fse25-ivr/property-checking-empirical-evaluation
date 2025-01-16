/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: model.c
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
#include <stdio.h>
#include "../common/model.h"

/* Named constants for Chart: '<Root>/Security System' */
#define IN_Active                      ((uint8_T)1U)
#define IN_Debouncing                  ((uint8_T)1U)
#define IN_Disabled                    ((uint8_T)2U)
#define IN_Idle                        ((uint8_T)2U)
#define IN_Idle_j                      ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_Off                         ((uint8_T)1U)
#define IN_On                          ((uint8_T)2U)
#define IN_Pending                     ((uint8_T)2U)
#define event_Alert                    (0)
#define event_sl_call                  (1)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

//nat
int32_T event_store;
//nat

/* Forward declaration for local functions */
static void Alarm(const int32_T *sfEvent);

/* Function for Chart: '<Root>/Security System' */
static void Alarm(const int32_T *sfEvent)
{
  switch (rtDW.is_Alarm) {
   case IN_Off:
    /* Inport: '<Root>/Alarm_active' */
    if (rtU.Alarm_active) {
      rtDW.is_Alarm = IN_On;
      rtDW.is_On = IN_Idle_j;
    }
    break;

   case IN_On:
    /* Inport: '<Root>/Alarm_active' */
    if (!rtU.Alarm_active) {
      rtDW.is_On = IN_NO_ACTIVE_CHILD;
      rtDW.is_Alarm = IN_Off;
    } else {
      switch (rtDW.is_On) {
       case IN_Idle_j:
        if (*sfEvent == event_Alert) {
          rtDW.is_On = IN_Pending;
          rtDW.temporalCounter_i2 = 0U;
          rtDW.SoundEventCounter++;
        }
        break;

       case IN_Pending:
        if ((*sfEvent == event_sl_call) && (rtDW.temporalCounter_i2 >= 80U)) {
          rtDW.call_policeEventCounter++;
          rtDW.is_On = IN_Idle_j;
        }
        break;
      }
    }
    break;
  }
}

char* alarm_state_str[] = {"IN_NO_ACTIVE_CHILD","IN_Off","IN_On"};
char* alarm_on_state_str[] = {"IN_NO_ACTIVE_CHILD","IN_Idle_j","IN_Pending"};
char* door_state_str[] = {"IN_NO_ACTIVE_CHILD","IN_Active","IN_Disabled"};
char* active_state_str[] = {"IN_NO_ACTIVE_CHILD","IN_Debouncing","IN_Idle"};
char* event_str[] = {"event_Alert","event_sl_call"};
char* bool_str[] = {"false","true"};

/* Model step function */
void model_step(void)
{
  printf("%s %s %s %s %s %s %d %s %s %s %d %d %d %d %d ", alarm_on_state_str[rtDW.is_Active],
    alarm_state_str[rtDW.is_Alarm], door_state_str[rtDW.is_Door],
    door_state_str[rtDW.is_Motion], active_state_str[rtDW.is_Active],
    door_state_str[rtDW.is_Win], rtU.Alarm_active,
    bool_str[rtU.Door_sens], bool_str[rtU.Mot_sens], bool_str[rtU.Win_sens],
    rtU.D_mode, rtU.M_mode, rtU.W_mode, rtDW.temporalCounter_i1, rtDW.temporalCounter_i2);

  event_store = event_sl_call;

  int32_T sfEvent;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Chart: '<Root>/Security System'
   */
  /* Chart: '<Root>/Security System' incorporates:
   *  Inport: '<Root>/D_mode'
   *  Inport: '<Root>/Door_sens'
   *  Inport: '<Root>/M_mode'
   *  Inport: '<Root>/Mot_sens'
   *  Inport: '<Root>/W_mode'
   *  Inport: '<Root>/Win_sens'
   */
  if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.temporalCounter_i2 < MAX_uint32_T) {
    rtDW.temporalCounter_i2++;
  }

  sfEvent = event_sl_call;
  if (rtDW.is_active_c1_model == 0U) {
    rtDW.is_active_c1_model = 1U;
    rtDW.is_active_Door = 1U;

    /* On the first sample call the door mode is set to active. */
    rtDW.is_Door = IN_Active;
    rtDW.is_active_Motion = 1U;

    /* On the first sample call the motion sensor mode is set to active, in the idle substate. */
    rtDW.is_Motion = IN_Active;
    rtDW.is_Active = IN_Idle;
    rtDW.is_active_Win = 1U;

    /* On the first sample call the window mode is set to active. */
    rtDW.is_Win = IN_Active;
    rtDW.is_active_Alarm = 1U;

    /* On the first sample call the Alarm is set to active. */
    rtDW.is_Alarm = IN_On;
    rtDW.is_On = IN_Idle_j;
  } else {
    if (rtDW.is_active_Door != 0U) {
      /* This state models the modes of a door sensor and implements logic to respond when that sensor is producing a signal. */
      switch (rtDW.is_Door) {
       case IN_Active:
        if (!rtU.D_mode) {
          rtDW.is_Door = IN_Disabled;
        } else {
          if (rtU.Door_sens && (rtDW.is_On == IN_Idle_j)) {
            sfEvent = event_Alert;
            event_store = sfEvent; //nat
            if (rtDW.is_active_Alarm != 0U) {
              Alarm(&sfEvent);
            }

            sfEvent = event_sl_call;
          }
        }
        break;

       case IN_Disabled:
        if (rtU.D_mode) {
          rtDW.is_Door = IN_Active;
        }
        break;
      }
    }

    if (rtDW.is_active_Motion != 0U) {
      /* This state models the modes of a motion detector sensor and implements logic to respond when that sensor is producing a signal. */
      switch (rtDW.is_Motion) {
       case IN_Active:
        if (!rtU.M_mode) {
          rtDW.is_Active = IN_NO_ACTIVE_CHILD;
          rtDW.is_Motion = IN_Disabled;
        } else {
          switch (rtDW.is_Active) {
           case IN_Debouncing:
            if (((boolean_T)event_sl_call) && (rtDW.temporalCounter_i1 >= 20U) &&
                (rtDW.is_On == IN_Idle_j)) {
              rtDW.is_Active = IN_NO_ACTIVE_CHILD;
              sfEvent = event_Alert;
              event_store = sfEvent; //nat
              if (rtDW.is_active_Alarm != 0U) {
                Alarm(&sfEvent);
              }

              sfEvent = 1;
              rtDW.is_Active = IN_Debouncing;
              rtDW.temporalCounter_i1 = 0U;
            } else {
              if (!rtU.Mot_sens) {
                rtDW.is_Active = IN_Idle;
              }
            }
            break;

           case IN_Idle:
            if (rtU.Mot_sens) {
              rtDW.is_Active = IN_Debouncing;
              rtDW.temporalCounter_i1 = 0U;
            }
            break;
          }
        }
        break;

       case IN_Disabled:
        if (rtU.M_mode) {
          rtDW.is_Motion = IN_Active;
          rtDW.is_Active = IN_Idle;
        }
        break;
      }
    }

    if (rtDW.is_active_Win != 0U) {
      /* This state models the modes of a window sensor and implements logic to respond when that sensor is producing a signal. */
      switch (rtDW.is_Win) {
       case IN_Active:
        if (!rtU.W_mode) {
          rtDW.is_Win = IN_Disabled;
        } else {
          if (rtU.Win_sens && (rtDW.is_On == IN_Idle_j)) {
            sfEvent = event_Alert;
            event_store = sfEvent; //nat
            if (rtDW.is_active_Alarm != 0U) {
              Alarm(&sfEvent);
            }

            sfEvent = 1;
          }
        }
        break;

       case IN_Disabled:
        if (rtU.W_mode) {
          rtDW.is_Win = IN_Active;
        }
        break;
      }
    }

    if (rtDW.is_active_Alarm != 0U) {
      Alarm(&sfEvent);
    }
  }

  if (rtDW.SoundEventCounter > 0U) {
    /* Outport: '<Root>/Sound' */
    rtY.Sound = !rtY.Sound;
    rtDW.SoundEventCounter--;
  }

  if (rtDW.call_policeEventCounter > 0U) {
    /* Outport: '<Root>/call_police' */
    rtY.call_police = !rtY.call_police;
    rtDW.call_policeEventCounter--;
  }

  /* End of Chart: '<Root>/Security System' */
  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Generator' */

  printf("%s\n", event_str[event_store]);
}

/* Model initialize function */
void model_initialize(void)
{
  /* (no initialization code required) */

  //nat
  rtDW.is_active_c1_model = 0;
  rtDW.is_Alarm = 0;
  rtDW.is_On = 0;
  rtDW.is_Door = 0;
  rtDW.is_Motion = 0;
  rtDW.is_Active = 0;
  rtDW.is_Win = 0;
  rtDW.temporalCounter_i1 = 0;
  rtDW.temporalCounter_i2 = 0;
  //nat
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
