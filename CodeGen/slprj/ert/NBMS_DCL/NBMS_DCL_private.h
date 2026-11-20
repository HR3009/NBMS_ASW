/*
 * File: NBMS_DCL_private.h
 *
 * Code generated for Simulink model 'NBMS_DCL'.
 *
 * Model version                  : 7.14
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Fri Nov 20 12:34:33 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_DCL_private_h_
#define NBMS_DCL_private_h_
#include "rtwtypes.h"
#include "NBMS_DCL_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const uint32_T rtCP_pooled_8CKvuowr1N9x[2];

#define rtCP_u0s_Safety_Pack_maxIndex  rtCP_pooled_8CKvuowr1N9x  /* Computed Parameter: rtCP_u0s_Safety_Pack_maxIndex
                                                                  * Referenced by: '<S3>/30s_Safety_Pack'
                                                                  */
#define rtCP_Continuous_Safety_Pack_max rtCP_pooled_8CKvuowr1N9x /* Computed Parameter: rtCP_Continuous_Safety_Pack_max
                                                                  * Referenced by: '<S3>/Continuous_Safety_Pack'
                                                                  */
#endif                                 /* NBMS_DCL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
