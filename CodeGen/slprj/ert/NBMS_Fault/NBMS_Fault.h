/*
 * File: NBMS_Fault.h
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

#ifndef NBMS_Fault_h_
#define NBMS_Fault_h_
#ifndef NBMS_Fault_COMMON_INCLUDES_
#define NBMS_Fault_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* NBMS_Fault_COMMON_INCLUDES_ */

#include "NBMS_Fault_types.h"

/* Real-time Model Data Structure */
struct tag_RTM_NBMS_Fault_T {
  const char_T **errorStatus;
};

typedef struct {
  RT_MODEL_NBMS_Fault_T rtm;
} MdlrefDW_NBMS_Fault_T;

/* Model reference registration function */
extern void NBMS_Fault_initialize(const char_T **rt_errorStatus,
  RT_MODEL_NBMS_Fault_T *const NBMS_Fault_M);
extern void NBMS_Fault(const boolean_T *rtu_AppIn_BMSVltSnsrFail, const
  boolean_T *rtu_AppIn_BattPackTempSnsrFail, const boolean_T
  *rtu_AppIn_VltImbFlt, const boolean_T *rtu_AppIn_TempImbWarn, boolean_T
  *rty_Derate);

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
 * '<Root>' : 'NBMS_Fault'
 */
#endif                                 /* NBMS_Fault_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
