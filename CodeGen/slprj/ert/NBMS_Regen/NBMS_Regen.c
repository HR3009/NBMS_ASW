/*
 * File: NBMS_Regen.c
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

#include "NBMS_Regen.h"
#include "rtwtypes.h"
#include "NBMS_Regen_types.h"
#include <math.h>
#include "look2_binlxpw.h"
#include "NBMS_Regen_private.h"
#include "DID.h"

/* Named constants for Chart: '<Root>/CalcRegenOverCurrent' */
#define NBMS_Regen_IN_Comparison       ((uint8_T)1U)
#define NBMS_Regen_IN_result           ((uint8_T)2U)

/* Output and update for referenced model: 'NBMS_Regen' */
void NBMS_Regen(const real_T *rtu_MeasuredCurrent, const real_T rtu_Temp[6],
                const real_T *rtu_SOC, const BMS_MODE_E *rtu_BMS_MODE_E,
                boolean_T *rty_RegenOverCurrentFlg, real_T *rty_RegenCurrent,
                DW_NBMS_Regen_f_T *localDW)
{
  real_T rtb_RegenCurrent_b;
  int32_T k;

  /* MinMax: '<Root>/FindMaxTemp' */
  rtb_RegenCurrent_b = rtu_Temp[0];
  for (k = 0; k < 5; k++) {
    rtb_RegenCurrent_b = fmax(rtb_RegenCurrent_b, rtu_Temp[k + 1]);
  }

  /* Lookup_n-D: '<Root>/Rgen Current' incorporates:
   *  MinMax: '<Root>/FindMaxTemp'
   */
  rtb_RegenCurrent_b = look2_binlxpw(rtb_RegenCurrent_b, *rtu_SOC,
    rtCP_RgenCurrent_bp01Data, rtCP_RgenCurrent_bp02Data,
    rtCP_RgenCurrent_tableData, rtCP_RgenCurrent_maxIndex, 9U);

  /* Chart: '<Root>/CalcRegenOverCurrent' */
  if (localDW->is_active_c3_NBMS_Regen == 0) {
    localDW->is_active_c3_NBMS_Regen = 1U;
    localDW->durationCounter_1_m = 0U;
    localDW->is_c3_NBMS_Regen = NBMS_Regen_IN_Comparison;
    *rty_RegenOverCurrentFlg = false;
  } else if (localDW->is_c3_NBMS_Regen == NBMS_Regen_IN_Comparison) {
    if (!(*rtu_MeasuredCurrent > rtb_RegenCurrent_b)) {
      localDW->durationCounter_1_m = 0U;
    }

    if (localDW->durationCounter_1_m > (uint32_T)ceil(RegenAllowedTime * 10.0))
    {
      localDW->durationCounter_1 = 0U;
      localDW->is_c3_NBMS_Regen = NBMS_Regen_IN_result;
      *rty_RegenOverCurrentFlg = true;
    } else {
      *rty_RegenOverCurrentFlg = false;
    }
  } else {
    /* case IN_result: */
    if (!(*rtu_MeasuredCurrent < rtb_RegenCurrent_b)) {
      localDW->durationCounter_1 = 0U;
    }

    if (localDW->durationCounter_1 > (uint32_T)ceil(RegenAllowedTime * 10.0)) {
      localDW->durationCounter_1_m = 0U;
      localDW->is_c3_NBMS_Regen = NBMS_Regen_IN_Comparison;
      *rty_RegenOverCurrentFlg = false;
    } else {
      *rty_RegenOverCurrentFlg = true;
    }
  }

  if (*rtu_MeasuredCurrent < rtb_RegenCurrent_b) {
    localDW->durationCounter_1++;
  } else {
    localDW->durationCounter_1 = 0U;
  }

  if (*rtu_MeasuredCurrent > rtb_RegenCurrent_b) {
    localDW->durationCounter_1_m++;
  } else {
    localDW->durationCounter_1_m = 0U;
  }

  /* End of Chart: '<Root>/CalcRegenOverCurrent' */

  /* Switch: '<Root>/selRegenCurrent' incorporates:
   *  Constant: '<Root>/ZeroCurrent'
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Compare'
   *  Switch: '<Root>/selRcurrent'
   */
  if (*rtu_BMS_MODE_E == BMS_DISCHARGE) {
    /* Switch: '<Root>/selRcurrent' incorporates:
     *  Constant: '<Root>/ZeroCurr'
     */
    if (*rty_RegenOverCurrentFlg) {
      *rty_RegenCurrent = 0.0;
    } else {
      *rty_RegenCurrent = rtb_RegenCurrent_b;
    }
  } else {
    *rty_RegenCurrent = 0.0;
  }

  /* End of Switch: '<Root>/selRegenCurrent' */
}

/* Model initialize function */
void NBMS_Regen_initialize(const char_T **rt_errorStatus, RT_MODEL_NBMS_Regen_T *
  const NBMS_Regen_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(NBMS_Regen_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
