/*
 * File: NBMS_DCL_private.h
 *
 * Code generated for Simulink model 'NBMS_DCL'.
 *
 * Model version                  : 7.9
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 11 09:32:04 2026
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

extern const real_T rtCP_pooled_tomZcbzCPt42[130];
extern const real_T rtCP_pooled_6PX36LxqMYmp[130];
extern const uint32_T rtCP_pooled_8CKvuowr1N9x[2];

#define rtCP_u0s_Safety_Pack_tableData rtCP_pooled_tomZcbzCPt42  /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0;0 7 14 56 77 91 98 105 112 119 120 120 120;14 14 35 84 112 120 120 120 120 120 120 120 120;21 21 56 119 120 120 120 120 120 120 120 120 120;42 42 84 120 120 120 120 120 120 120 120 120 120;42 42 84 120 120 120 120 120 120 120 120 120 120;42 42 84 120 120 120 120 120 120 120 120 120 120;35 35 52 98 120 120 120 120 120 120 120 120 120;0 0 0 0 0 0 0 0 0 0 0 0 0]
                                                                  * Referenced by: '<S3>/30s_Safety_Pack'
                                                                  */
#define rtCP_Continuous_Safety_Pack_tab rtCP_pooled_6PX36LxqMYmp /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0;0 7 14 21 21 31 31 31 31 31 31 31 31;14 14 35 52 52 52 52 52 52 52 52 52 52;21 21 56 77 84 84 84 84 84 84 84 84 84;42 42 77 77 105 105 105 120 120 120 120 120 120;42 42 77 77 105 105 105 120 120 120 120 120 120;42 42 42 52 105 105 105 105 105 105 105 105 105;28 28 35 35 35 35 35 35 35 35 35 35 35;0 0 0 0 0 0 0 0 0 0 0 0 0]
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
