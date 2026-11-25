/*
 * File: NBMS_Regen_private.h
 *
 * Code generated for Simulink model 'NBMS_Regen'.
 *
 * Model version                  : 7.14
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 25 15:35:08 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_Regen_private_h_
#define NBMS_Regen_private_h_
#include "rtwtypes.h"
#include "NBMS_Regen_types.h"

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

extern const real_T rtCP_pooled_DsnmT4uKTAuL[117];
extern const uint32_T rtCP_pooled_4VxQjGiMgLkO[2];

#define rtCP_RgenCurrent_tableData     rtCP_pooled_DsnmT4uKTAuL  /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0 0; 0 0 0 0 0 0 0 0 0 0 0 0 0; 0 0 0 0 0 0 0 0 0 0 0 0 0; 52 52 52 52 52 52 52 49 35 21 14 7 0; 52 52 52 52 52 52 52 52 49 35 21 17 2; 52 52 52 52 52 52 52 52 52 49 28 21 2; 52 52 52 52 52 52 52 52 52 49 28 21 2; 52 52 52 52 52 52 52 52 52 49 28 21 2; 0 0 0 0 0 0 0 0 0 0 0 0 0];

                                                                  * Referenced by: '<Root>/Rgen Current'
                                                                  */
#define rtCP_RgenCurrent_maxIndex      rtCP_pooled_4VxQjGiMgLkO  /* Computed Parameter: rtCP_RgenCurrent_maxIndex
                                                                  * Referenced by: '<Root>/Rgen Current'
                                                                  */
#endif                                 /* NBMS_Regen_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
