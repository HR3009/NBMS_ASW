/*
 * File: NBMS_Regen_private.h
 *
 * Code generated for Simulink model 'NBMS_Regen'.
 *
 * Model version                  : 7.12
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Fri Nov 20 12:34:41 2026
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

extern const uint32_T rtCP_pooled_4VxQjGiMgLkO[2];

#define rtCP_RgenCurrent_maxIndex      rtCP_pooled_4VxQjGiMgLkO  /* Computed Parameter: rtCP_RgenCurrent_maxIndex
                                                                  * Referenced by: '<Root>/Rgen Current'
                                                                  */
#endif                                 /* NBMS_Regen_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
