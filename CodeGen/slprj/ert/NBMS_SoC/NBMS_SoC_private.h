/*
 * File: NBMS_SoC_private.h
 *
 * Code generated for Simulink model 'NBMS_SoC'.
 *
 * Model version                  : 7.73
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 11 09:32:21 2026
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

extern const real_T rtCP_pooled_LcfBKAGpDnfc[77];
extern const real_T rtCP_pooled_p1cmNKJnz2p6[7];
extern const real_T rtCP_pooled_wf09jZU7lAz7[11];
extern const real_T rtCP_pooled_m6ZzdnrnXBRj[77];
extern const real_T rtCP_pooled_Z3wcCkCpVwGi[2];
extern const uint32_T rtCP_pooled_sVZrsSjtiqmP[2];
extern const boolean_T rtCP_pooled_kUC6nmgO8rex[16];
extern const boolean_T rtCP_pooled_DpagMRBkrPSQ;

#define rtCP_DCIRCharge_tableData      rtCP_pooled_LcfBKAGpDnfc  /* Expression: [0.1796 0.1796 0.1427 0.2163 0.2033 0.2013 0.2128 0.2128 0.2128 0.2128 0.2128;0.0883 0.0883 0.0672 0.1006 0.0948 0.0949 0.1067 0.1035 0.1035 0.1035 0.1035;0.0742 0.0742 0.0579 0.0531 0.0482 0.0485 0.0584 0.0576 0.0631 0.0631 0.0631;0.0554 0.0554 0.0407 0.0412 0.038 0.039 0.0386 0.0389 0.0429 0.0402 0.0402;0.059 0.0414 0.0282 0.0291 0.0272 0.0277 0.0285 0.0271 0.0286 0.0269 0.0269;0.0479 0.0358 0.0221 0.0233 0.0215 0.0217 0.0218 0.0212 0.022 0.0195 0.0195;0.0448 0.0327 0.02 0.0219 0.0202 0.0204 0.0205 0.0195 0.0206 0.0181 0.0181]
                                                                  * Referenced by: '<S82>/DCIRCharge'
                                                                  */
#define rtCP_DCIRCharge_bp01Data       rtCP_pooled_p1cmNKJnz2p6  /* Expression: [-20;-10;0;10;25;45;60]
                                                                  * Referenced by: '<S82>/DCIRCharge'
                                                                  */
#define rtCP_DCIRCharge_bp02Data       rtCP_pooled_wf09jZU7lAz7  /* Expression: [0;10;20;30;40;50;60;70;80;90;100]
                                                                  * Referenced by: '<S82>/DCIRCharge'
                                                                  */
#define rtCP_DCIRdisCharge_tableData   rtCP_pooled_m6ZzdnrnXBRj  /* Expression: [0.4429 0.4429 0.1677 0.1473 0.1409 0.1403 0.1384 0.1409 0.1428 0.1421 0.151;0.2169 0.2169 0.0906 0.0755 0.0721 0.0709 0.0713 0.0732 0.0738 0.0709 0.0772;0.1281 0.1281 0.0657 0.0554 0.053 0.053 0.0526 0.0531 0.0556 0.0525 0.0558;0.0808 0.0808 0.0453 0.0396 0.0389 0.0387 0.0385 0.0396 0.0407 0.038 0.0417;0.1135 0.0531 0.0333 0.029 0.0284 0.0284 0.028 0.0284 0.0299 0.0277 0.0296;0.0885 0.0407 0.0269 0.0233 0.0227 0.0229 0.0219 0.0228 0.0239 0.021 0.0234;0.086 0.0373 0.025 0.0221 0.022 0.0218 0.0207 0.0214 0.0224 0.0195 0.022]
                                                                  * Referenced by: '<S82>/DCIRdisCharge'
                                                                  */
#define rtCP_DCIRdisCharge_bp01Data    rtCP_pooled_p1cmNKJnz2p6  /* Expression: [-20;-10;0;10;25;45;60]
                                                                  * Referenced by: '<S82>/DCIRdisCharge'
                                                                  */
#define rtCP_DCIRdisCharge_bp02Data    rtCP_pooled_wf09jZU7lAz7  /* Expression: [0;10;20;30;40;50;60;70;80;90;100]
                                                                  * Referenced by: '<S82>/DCIRdisCharge'
                                                                  */
#define rtCP_USERSOC_tableData         rtCP_pooled_Z3wcCkCpVwGi  /* Expression: [0,100]
                                                                  * Referenced by: '<S33>/USER SOC'
                                                                  */
#define rtCP_USERSOC_bp01Data          rtCP_pooled_Z3wcCkCpVwGi  /* Expression: [0,100]
                                                                  * Referenced by: '<S33>/USER SOC'
                                                                  */
#define rtCP_DCIRCharge_maxIndex       rtCP_pooled_sVZrsSjtiqmP  /* Computed Parameter: rtCP_DCIRCharge_maxIndex
                                                                  * Referenced by: '<S82>/DCIRCharge'
                                                                  */
#define rtCP_DCIRdisCharge_maxIndex    rtCP_pooled_sVZrsSjtiqmP  /* Computed Parameter: rtCP_DCIRdisCharge_maxIndex
                                                                  * Referenced by: '<S82>/DCIRdisCharge'
                                                                  */
#define rtCP_Logic_table               rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table
                                                                  * Referenced by: '<S73>/Logic'
                                                                  */
#define rtCP_Logic_table_m             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_m
                                                                  * Referenced by: '<S74>/Logic'
                                                                  */
#define rtCP_Logic_table_g             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_g
                                                                  * Referenced by: '<S72>/Logic'
                                                                  */
#define rtCP_ConstOne_Value            rtCP_pooled_DpagMRBkrPSQ  /* Computed Parameter: rtCP_ConstOne_Value
                                                                  * Referenced by: '<S5>/ConstOne'
                                                                  */
#define rtCP_Logic_table_o             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_o
                                                                  * Referenced by: '<S50>/Logic'
                                                                  */
#define rtCP_Logic_table_c             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_c
                                                                  * Referenced by: '<S93>/Logic'
                                                                  */
#define rtCP_Logic_table_a             rtCP_pooled_kUC6nmgO8rex  /* Computed Parameter: rtCP_Logic_table_a
                                                                  * Referenced by: '<S17>/Logic'
                                                                  */
#endif                                 /* NBMS_SoC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
