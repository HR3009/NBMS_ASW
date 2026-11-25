/*
 * File: NBMS_TTC_private.h
 *
 * Code generated for Simulink model 'NBMS_TTC'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 25 15:37:45 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_TTC_private_h_
#define NBMS_TTC_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "NBMS_TTC_types.h"
#include "NBMS_TTC.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

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

extern const boolean_T rtCP_pooled_kUC6nmgO8rex[16];

#define rtCP_Logic_table               rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table
                                                                  * Referenced by: '<S29>/Logic'
                                                                  */
#define rtCP_Logic_table_a             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_a
                                                                  * Referenced by: '<S34>/Logic'
                                                                  */
#define rtCP_Logic_table_e             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_e
                                                                  * Referenced by: '<S23>/Logic'
                                                                  */
#define rtCP_Logic_table_ao            rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_ao
                                                                  * Referenced by: '<S24>/Logic'
                                                                  */

/* Invariant block signals (default storage) */
extern const ConstB_NBMS_TTC_h_T NBMS_TTC_ConstB;

#endif                                 /* NBMS_TTC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
