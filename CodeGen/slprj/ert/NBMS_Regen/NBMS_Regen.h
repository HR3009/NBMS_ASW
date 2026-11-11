/*
 * File: NBMS_Regen.h
 *
 * Code generated for Simulink model 'NBMS_Regen'.
 *
 * Model version                  : 7.10
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 11 09:32:12 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_Regen_h_
#define NBMS_Regen_h_
#ifndef NBMS_Regen_COMMON_INCLUDES_
#define NBMS_Regen_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* NBMS_Regen_COMMON_INCLUDES_ */

#include "NBMS_Regen_types.h"

/* Includes for objects with custom storage classes */
#include "DID.h"

/* Block states (default storage) for model 'NBMS_Regen' */
typedef struct {
  uint32_T durationCounter_1;          /* '<Root>/CalcRegenOverCurrent' */
  uint32_T durationCounter_1_m;        /* '<Root>/CalcRegenOverCurrent' */
  uint8_T is_active_c3_NBMS_Regen;     /* '<Root>/CalcRegenOverCurrent' */
  uint8_T is_c3_NBMS_Regen;            /* '<Root>/CalcRegenOverCurrent' */
} DW_NBMS_Regen_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_NBMS_Regen_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_NBMS_Regen_f_T rtdw;
  RT_MODEL_NBMS_Regen_T rtm;
} MdlrefDW_NBMS_Regen_T;

/* Model reference registration function */
extern void NBMS_Regen_initialize(const char_T **rt_errorStatus,
  RT_MODEL_NBMS_Regen_T *const NBMS_Regen_M);
extern void NBMS_Regen(const real_T *rtu_MeasuredCurrent, const real_T rtu_Temp
  [6], const real_T *rtu_SOC, const BMS_MODE_E *rtu_BMS_MODE_E, boolean_T
  *rty_RegenOverCurrentFlg, real_T *rty_RegenCurrent, DW_NBMS_Regen_f_T *localDW);

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
 * '<Root>' : 'NBMS_Regen'
 * '<S1>'   : 'NBMS_Regen/CalcRegenOverCurrent'
 * '<S2>'   : 'NBMS_Regen/ChkBmsModeIsDischarge'
 */
#endif                                 /* NBMS_Regen_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
