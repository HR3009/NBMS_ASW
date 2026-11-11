/*
 * File: NBMS_Fault.c
 *
 * Code generated for Simulink model 'NBMS_Fault'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Tue Nov 10 18:05:50 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "NBMS_Fault.h"
#include "rtwtypes.h"
#include "NBMS_Fault_private.h"

/* Output and update for referenced model: 'NBMS_Fault' */
void NBMS_Fault(const boolean_T *rtu_AppIn_BMSVltSnsrFail, const boolean_T
                *rtu_AppIn_BattPackTempSnsrFail, const boolean_T
                *rtu_AppIn_VltImbFlt, const boolean_T *rtu_AppIn_TempImbWarn,
                boolean_T *rty_Derate)
{
  /* Logic: '<Root>/ChkDerating' */
  *rty_Derate = (*rtu_AppIn_BMSVltSnsrFail || *rtu_AppIn_BattPackTempSnsrFail ||
                 *rtu_AppIn_VltImbFlt || *rtu_AppIn_TempImbWarn);
}

/* Model initialize function */
void NBMS_Fault_initialize(const char_T **rt_errorStatus, RT_MODEL_NBMS_Fault_T *
  const NBMS_Fault_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(NBMS_Fault_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
