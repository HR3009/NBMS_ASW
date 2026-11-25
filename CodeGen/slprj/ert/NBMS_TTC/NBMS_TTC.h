/*
 * File: NBMS_TTC.h
 *
 * Code generated for Simulink model 'NBMS_TTC'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 25 15:37:45 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_TTC_h_
#define NBMS_TTC_h_
#ifndef NBMS_TTC_COMMON_INCLUDES_
#define NBMS_TTC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* NBMS_TTC_COMMON_INCLUDES_ */

#include "NBMS_TTC_types.h"
#include "zero_crossing_types.h"

/* Includes for objects with custom storage classes */
#include "DID.h"

/* Block signals for model 'NBMS_TTC' */
typedef struct {
  real_T Switch;                       /* '<S22>/Switch' */
  real_T TTC;                          /* '<S31>/TTC' */
  int16_T DataTypeConversion;          /* '<S12>/Data Type Conversion' */
  boolean_T RelationalOperator;        /* '<S30>/Relational Operator' */
  boolean_T Compare;                   /* '<S25>/Compare' */
} B_NBMS_TTC_c_T;

/* Block states (default storage) for model 'NBMS_TTC' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S22>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S30>/Unit Delay1' */
  real_T UnitDelay_DSTATE_c;           /* '<S3>/Unit Delay' */
  real_T UnitDelay1_DSTATE_k;          /* '<S3>/Unit Delay1' */
  uint16_T DelayInput1_DSTATE;         /* '<S28>/Delay Input1' */
  int16_T TappedDelay2_DWORK1[30];     /* '<S12>/Tapped Delay2' */
  uint8_T UnitDelay1_DSTATE_p;         /* '<S20>/Unit Delay1' */
  uint8_T UnitDelay1_DSTATE_d;         /* '<S12>/Unit Delay1' */
  boolean_T Memory_PreviousInput;      /* '<S34>/Memory' */
  boolean_T Memory_PreviousInput_p;    /* '<S23>/Memory' */
  boolean_T Memory_PreviousInput_c;    /* '<S24>/Memory' */
  boolean_T Memory_PreviousInput_d;    /* '<S29>/Memory' */
  boolean_T Filter_MODE;               /* '<S10>/Filter' */
  boolean_T Delay_MODE;                /* '<S10>/Delay' */
} DW_NBMS_TTC_f_T;

/* Zero-crossing (trigger) state for model 'NBMS_TTC' */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S22>/Triggered Subsystem' */
  ZCSigState Subsystem_Trig_ZCE;       /* '<S22>/Subsystem' */
} ZCE_NBMS_TTC_T;

/* Invariant block signals for model 'NBMS_TTC' */
typedef struct {
  const uint16_T Gain;                 /* '<S2>/Gain' */
} ConstB_NBMS_TTC_h_T;

/* Real-time Model Data Structure */
struct tag_RTM_NBMS_TTC_T {
  const char_T **errorStatus;
};

typedef struct {
  B_NBMS_TTC_c_T rtb;
  DW_NBMS_TTC_f_T rtdw;
  RT_MODEL_NBMS_TTC_T rtm;
  ZCE_NBMS_TTC_T rtzce;
} MdlrefDW_NBMS_TTC_T;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern uint8_T CAL_CV_ChargeTime;      /* Variable: CAL_CV_ChargeTime
                                        * Referenced by:
                                        *   '<S2>/Constant2'
                                        *   '<S11>/Constant2'
                                        *   '<S21>/Constant2'
                                        *   '<S21>/Constant6'
                                        */

/* Model reference registration function */
extern void NBMS_TTC_initialize(const char_T **rt_errorStatus,
  RT_MODEL_NBMS_TTC_T *const NBMS_TTC_M, ZCE_NBMS_TTC_T *localZCE);
extern void NBMS_TTC_Init(DW_NBMS_TTC_f_T *localDW);
extern void NBMS_TTC_Disable(B_NBMS_TTC_c_T *localB, DW_NBMS_TTC_f_T *localDW);
extern void NBMS_TTC(const uint8_T *rtu_SOC, const int16_T *rtu_Batt_Current,
                     const real_T *rtu_BatteryCapacity, const real_T *rtu_SOH,
                     const BMS_MODE_E *rtu_BMS_Mode, const real_T
                     *rtu_ChargecurrLimit, const Charger_Mode_Req_E
                     *rtu_Chg_Mode_Req, real_T *rty_TTC_HR, real_T *rty_TTC_MIN,
                     B_NBMS_TTC_c_T *localB, DW_NBMS_TTC_f_T *localDW,
                     ZCE_NBMS_TTC_T *localZCE);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Display' : Unused code path elimination
 * Block '<S3>/Display1' : Unused code path elimination
 * Block '<S7>/AND' : Unused code path elimination
 * Block '<S7>/ChargetoFault' : Unused code path elimination
 * Block '<S14>/Compare' : Unused code path elimination
 * Block '<S14>/Constant' : Unused code path elimination
 * Block '<S15>/Compare' : Unused code path elimination
 * Block '<S15>/Constant' : Unused code path elimination
 * Block '<S16>/Compare' : Unused code path elimination
 * Block '<S16>/Constant' : Unused code path elimination
 * Block '<S7>/Constant' : Unused code path elimination
 * Block '<S7>/NOT' : Unused code path elimination
 * Block '<S17>/Logic' : Unused code path elimination
 * Block '<S17>/Memory' : Unused code path elimination
 * Block '<S7>/Unit Delay' : Unused code path elimination
 * Block '<S7>/Unit Delay1' : Unused code path elimination
 * Block '<S27>/Compare' : Unused code path elimination
 * Block '<S27>/Constant' : Unused code path elimination
 * Block '<S22>/Gain' : Unused code path elimination
 * Block '<S22>/Subtract1' : Unused code path elimination
 * Block '<S22>/Subtract2' : Unused code path elimination
 * Block '<S22>/Switch1' : Unused code path elimination
 * Block '<S22>/Switch2' : Unused code path elimination
 * Block '<S32>/Add' : Unused code path elimination
 * Block '<S32>/Constant' : Unused code path elimination
 * Block '<S32>/Constant1' : Unused code path elimination
 * Block '<S32>/Divide' : Unused code path elimination
 * Block '<S32>/Unit Delay' : Unused code path elimination
 * Block '<S22>/Unit Delay1' : Unused code path elimination
 * Block '<S1>/Constant4' : Unused code path elimination
 * Block '<S1>/Relational Operator' : Unused code path elimination
 * Block '<S1>/Switch4' : Unused code path elimination
 * Block '<S21>/Constant5' : Unused code path elimination
 * Block '<S21>/Divide1' : Unused code path elimination
 * Block '<S21>/Gain' : Unused code path elimination
 * Block '<S21>/Remaining SOC based on chargeamount selection' : Unused code path elimination
 * Block '<S21>/Remaining capacity' : Unused code path elimination
 * Block '<S21>/capacity based on charge amount selection' : Unused code path elimination
 */

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
 * '<Root>' : 'NBMS_TTC'
 * '<S1>'   : 'NBMS_TTC/Time To Charge Logic'
 * '<S2>'   : 'NBMS_TTC/Time To Charge Logic/CC'
 * '<S3>'   : 'NBMS_TTC/Time To Charge Logic/CV'
 * '<S4>'   : 'NBMS_TTC/Time To Charge Logic/Compare To Constant'
 * '<S5>'   : 'NBMS_TTC/Time To Charge Logic/Compare To Constant1'
 * '<S6>'   : 'NBMS_TTC/Time To Charge Logic/Compare To Constant2'
 * '<S7>'   : 'NBMS_TTC/Time To Charge Logic/FreezeTTCinFault'
 * '<S8>'   : 'NBMS_TTC/Time To Charge Logic/FullCharge'
 * '<S9>'   : 'NBMS_TTC/Time To Charge Logic/FullCharge1'
 * '<S10>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter'
 * '<S11>'  : 'NBMS_TTC/Time To Charge Logic/TimerCV'
 * '<S12>'  : 'NBMS_TTC/Time To Charge Logic/CC/MovingAverageTTC'
 * '<S13>'  : 'NBMS_TTC/Time To Charge Logic/CC/MovingAverageTTC/Compare To Constant1'
 * '<S14>'  : 'NBMS_TTC/Time To Charge Logic/FreezeTTCinFault/Compare To Constant'
 * '<S15>'  : 'NBMS_TTC/Time To Charge Logic/FreezeTTCinFault/Compare To Constant2'
 * '<S16>'  : 'NBMS_TTC/Time To Charge Logic/FreezeTTCinFault/Compare To Constant3'
 * '<S17>'  : 'NBMS_TTC/Time To Charge Logic/FreezeTTCinFault/S-R Flip-Flop'
 * '<S18>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/Compare To Constant'
 * '<S19>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/Compare To Constant2'
 * '<S20>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/Delay'
 * '<S21>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/DelayPrediction'
 * '<S22>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/Filter'
 * '<S23>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/S-R Flip-Flop'
 * '<S24>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/S-R Flip-Flop1'
 * '<S25>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/Delay/Compare To Constant2'
 * '<S26>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/DelayPrediction/Compare To Constant'
 * '<S27>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/Filter/Compare To Constant'
 * '<S28>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/Filter/Detect Increase'
 * '<S29>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/Filter/S-R Flip-Flop'
 * '<S30>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/Filter/Subsystem'
 * '<S31>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/Filter/Triggered Subsystem'
 * '<S32>'  : 'NBMS_TTC/Time To Charge Logic/TTC filter/Filter/Triggered Subsystem1'
 * '<S33>'  : 'NBMS_TTC/Time To Charge Logic/TimerCV/Compare To Constant'
 * '<S34>'  : 'NBMS_TTC/Time To Charge Logic/TimerCV/S-R Flip-Flop'
 */
#endif                                 /* NBMS_TTC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
