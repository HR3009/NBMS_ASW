/*
 * File: NBMS_SoC_private.h
 *
 * Code generated for Simulink model 'NBMS_SoC'.
 *
 * Model version                  : 7.101
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Fri Nov 20 12:35:00 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_SoC_private_h_
#define NBMS_SoC_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "NBMS_SoC_types.h"
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

extern const real_T rtCP_pooled_Z3wcCkCpVwGi[2];
extern const uint32_T rtCP_pooled_sVZrsSjtiqmP[2];
extern const boolean_T rtCP_pooled_kUC6nmgO8rex[16];
extern const boolean_T rtCP_pooled_DpagMRBkrPSQ;

#define rtCP_USERSOC_tableData         rtCP_pooled_Z3wcCkCpVwGi  /* Expression: [0,100]
                                                                  * Referenced by: '<S42>/USER SOC'
                                                                  */
#define rtCP_USERSOC_bp01Data          rtCP_pooled_Z3wcCkCpVwGi  /* Expression: [0,100]
                                                                  * Referenced by: '<S42>/USER SOC'
                                                                  */
#define rtCP_DCIRCharge_maxIndex       rtCP_pooled_sVZrsSjtiqmP  /* Computed Parameter: rtCP_DCIRCharge_maxIndex
                                                                  * Referenced by: '<S92>/DCIRCharge'
                                                                  */
#define rtCP_DCIRdisCharge_maxIndex    rtCP_pooled_sVZrsSjtiqmP  /* Computed Parameter: rtCP_DCIRdisCharge_maxIndex
                                                                  * Referenced by: '<S92>/DCIRdisCharge'
                                                                  */
#define rtCP_Logic_table               rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table
                                                                  * Referenced by: '<S84>/Logic'
                                                                  */
#define rtCP_Logic_table_g             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_g
                                                                  * Referenced by: '<S82>/Logic'
                                                                  */
#define rtCP_Logic_table_m             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_m
                                                                  * Referenced by: '<S83>/Logic'
                                                                  */
#define rtCP_ConstOne_Value            rtCP_pooled_DpagMRBkrPSQ  /* Computed Parameter: rtCP_ConstOne_Value
                                                                  * Referenced by: '<S6>/ConstOne'
                                                                  */
#define rtCP_Logic_table_o             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_o
                                                                  * Referenced by: '<S59>/Logic'
                                                                  */
#define rtCP_Logic_table_c             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_c
                                                                  * Referenced by: '<S103>/Logic'
                                                                  */
#define rtCP_Logic_table_a             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_a
                                                                  * Referenced by: '<S25>/Logic'
                                                                  */
#endif                                 /* NBMS_SoC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
