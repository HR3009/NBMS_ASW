/*
 * File: NBMS_DCL_private.h
 *
 * Code generated for Simulink model 'NBMS_DCL'.
 *
 * Model version                  : 7.26
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 25 15:34:59 2026
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

extern const real_T rtCP_pooled_es7FJ4oMwKBG[130];
extern const real_T rtCP_pooled_8OKsYL1c5Ssw[130];
extern const uint32_T rtCP_pooled_8CKvuowr1N9x[2];

#define rtCP_u0s_Safety_Pack_tableData rtCP_pooled_es7FJ4oMwKBG  /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0;0 7 14 56 77 91 98 105 110 110 110 110 110;14 14 35 84 110 110 110 110 110 110 110 110 110;20 21 56 110 110 110 110 110 110 110 110 110 110;20 42 84 110 110 110 110 110 110 110 110 110 110;20 42 84 110 110 110 110 110 110 110 110 110 110;20 42 84 110 110 110 110 110 110 110 110 110 110;20 35 52 98 110 110 110 110 110 110 110 110 110;0 0 0 0 0 0 0 0 0 0 0 0 0]
                                                                  * Referenced by: '<S3>/30s_Safety_Pack'
                                                                  */
#define rtCP_Continuous_Safety_Pack_tab rtCP_pooled_8OKsYL1c5Ssw /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0;0 7 14 21 21 31 31 31 31 31 31 31 31;14 14 35 52 52 52 52 52 52 52 52 52 52;20 21 56 70 84 84 84 84 84 84 84 84 84;20 42 42 70 90 90 90 90 90 90 90 90 90;20 42 42 70 90 90 90 90 90 90 90 90 90;20 42 42 52.5 90 90 90 90 90 90 90 90 90;20 28 35 35 35 35 35 35 35 35 35 35 35;0 0 0 0 0 0 0 0 0 0 0 0 0;]
                                                                  * Referenced by: '<S3>/Continuous_Safety_Pack'
                                                                  */
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
