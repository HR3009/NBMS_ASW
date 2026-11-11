/*
 * File: NBMS_Regen_private.h
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

extern const real_T rtCP_pooled_8bkkxg0RN7sm[117];
extern const real_T rtCP_pooled_LOGv4uxWvgTS[9];
extern const real_T rtCP_pooled_ZaHs2FQXxlJZ[13];
extern const uint32_T rtCP_pooled_4VxQjGiMgLkO[2];

#define rtCP_RgenCurrent_tableData     rtCP_pooled_8bkkxg0RN7sm  /* Expression: [0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0;0 0 0 0 0 0 0 0 0 0 0 0 0;52 52 52 52 52 52 52 49 35 21 14 7 0;52 52 52 52 52 52 52 52 49 35 21 17 0;52 52 52 52 52 52 52 52 52 49 28 21 0;52 52 52 52 52 52 52 52 52 49 28 21 0;52 52 52 52 52 52 52 52 52 49 28 21 0;0 0 0 0 0 0 0 0 0 0 0 0 0]
                                                                  * Referenced by: '<Root>/Rgen Current'
                                                                  */
#define rtCP_RgenCurrent_bp01Data      rtCP_pooled_LOGv4uxWvgTS  /* Expression: [-30;-20;-10;0;10;25;40;50;60]
                                                                  * Referenced by: '<Root>/Rgen Current'
                                                                  */
#define rtCP_RgenCurrent_bp02Data      rtCP_pooled_ZaHs2FQXxlJZ  /* Expression: [0;5;10;20;30;40;50;60;70;80;90;95;100]
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
