/*
 * File: NBMS_Fault.c
 *
 * Code generated for Simulink model 'NBMS_Fault'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 25 15:35:01 2026
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
                const boolean_T *rtu_AppIn_BMSLowTempduringDrive, const
                boolean_T *rtu_AppIn_BMSOverTempDriveWarnI, const boolean_T
                *rtu_LowSoCWarn, const boolean_T *rtu_LowSoCWarn15, boolean_T
                *rty_Derate, boolean_T *rty_DischDeratefromCont, boolean_T
                *rty_DischDerateafterX1)
{
  /* Logic: '<Root>/ChkDerating' */
  *rty_Derate = (*rtu_AppIn_BMSVltSnsrFail || *rtu_AppIn_BattPackTempSnsrFail ||
                 *rtu_AppIn_VltImbFlt || *rtu_AppIn_TempImbWarn);

  /* Logic: '<Root>/ChkDischDeratefromCont' */
  *rty_DischDeratefromCont = (*rtu_AppIn_BMSLowTempduringDrive ||
    *rtu_LowSoCWarn15);

  /* Logic: '<Root>/ChkDischDerateafterX1' */
  *rty_DischDerateafterX1 = (*rtu_LowSoCWarn || *rtu_AppIn_BMSOverTempDriveWarnI);
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
