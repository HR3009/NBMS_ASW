/*
 * File: NBMS_ChargeOCV_private.h
 *
 * Code generated for Simulink model 'NBMS_ChargeOCV'.
 *
 * Model version                  : 7.2
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Tue Nov 10 18:06:02 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_ChargeOCV_private_h_
#define NBMS_ChargeOCV_private_h_
#include "rtwtypes.h"
#include "NBMS_ChargeOCV_types.h"
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

extern const real_T rtCP_pooled_Che86US4F7XI[147];
extern const real_T rtCP_pooled_6QV4OqumygMa[21];
extern const real_T rtCP_pooled_S734yA675FsN[7];
extern const uint32_T rtCP_pooled_OJvaNeQ52mdS[2];

#define rtCP_OCVvsSOCatallTemp2_tableDa rtCP_pooled_Che86US4F7XI /* Expression: [2.934 2.929 2.92 2.9 2.91 2.903 2.922;3.26 3.274 3.271 3.271 3.254 3.238 3.24;3.387 3.399 3.397 3.397 3.385 3.362 3.363;3.436 3.442 3.442 3.441 3.439 3.429 3.43;3.481 3.491 3.491 3.493 3.492 3.479 3.481;3.538 3.547 3.546 3.547 3.54 3.534 3.534;3.586 3.592 3.592 3.593 3.589 3.582 3.582;3.616 3.621 3.622 3.624 3.622 3.622 3.623;3.644 3.65 3.651 3.653 3.652 3.653 3.656;3.677 3.683 3.685 3.687 3.686 3.688 3.691;3.719 3.726 3.727 3.73 3.728 3.731 3.734;3.766 3.772 3.774 3.777 3.776 3.777 3.78;3.819 3.837 3.838 3.84 3.835 3.829 3.831;3.88 3.886 3.886 3.887 3.885 3.883 3.882;3.913 3.918 3.919 3.92 3.918 3.917 3.917;3.952 3.958 3.959 3.96 3.958 3.958 3.958;4.01 4.017 4.017 4.019 4.017 4.016 4.016;4.061 4.066 4.067 4.068 4.067 4.067 4.067;4.076 4.08 4.082 4.083 4.083 4.083 4.084;4.09 4.096 4.098 4.1 4.099 4.098 4.099;4.185 4.185 4.185 4.185 4.185 4.185 4.185]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp2'
                                                                  */
#define rtCP_OCVvsSOCatallTemp2_bp01Dat rtCP_pooled_6QV4OqumygMa /* Expression: [0;5;10;15;20;25;30;35;40;45;50;55;60;65;70;75;80;85;90;95;100]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp2'
                                                                  */
#define rtCP_OCVvsSOCatallTemp2_bp02Dat rtCP_pooled_S734yA675FsN /* Expression: [-20;-10;0;10;25;45;55]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp2'
                                                                  */
#define rtCP_OCVvsSOCatallTemp_tableDat rtCP_pooled_Che86US4F7XI /* Expression: [2.934 2.929 2.92 2.9 2.91 2.903 2.922;3.26 3.274 3.271 3.271 3.254 3.238 3.24;3.387 3.399 3.397 3.397 3.385 3.362 3.363;3.436 3.442 3.442 3.441 3.439 3.429 3.43;3.481 3.491 3.491 3.493 3.492 3.479 3.481;3.538 3.547 3.546 3.547 3.54 3.534 3.534;3.586 3.592 3.592 3.593 3.589 3.582 3.582;3.616 3.621 3.622 3.624 3.622 3.622 3.623;3.644 3.65 3.651 3.653 3.652 3.653 3.656;3.677 3.683 3.685 3.687 3.686 3.688 3.691;3.719 3.726 3.727 3.73 3.728 3.731 3.734;3.766 3.772 3.774 3.777 3.776 3.777 3.78;3.819 3.837 3.838 3.84 3.835 3.829 3.831;3.88 3.886 3.886 3.887 3.885 3.883 3.882;3.913 3.918 3.919 3.92 3.918 3.917 3.917;3.952 3.958 3.959 3.96 3.958 3.958 3.958;4.01 4.017 4.017 4.019 4.017 4.016 4.016;4.061 4.066 4.067 4.068 4.067 4.067 4.067;4.076 4.08 4.082 4.083 4.083 4.083 4.084;4.09 4.096 4.098 4.1 4.099 4.098 4.099;4.185 4.185 4.185 4.185 4.185 4.185 4.185]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp'
                                                                  */
#define rtCP_OCVvsSOCatallTemp_bp01Data rtCP_pooled_6QV4OqumygMa /* Expression: [0;5;10;15;20;25;30;35;40;45;50;55;60;65;70;75;80;85;90;95;100]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp'
                                                                  */
#define rtCP_OCVvsSOCatallTemp_bp02Data rtCP_pooled_S734yA675FsN /* Expression: [-20;-10;0;10;25;45;55]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp'
                                                                  */
#define rtCP_OCVvsSOCatallTemp1_tableDa rtCP_pooled_Che86US4F7XI /* Expression: [2.934 2.929 2.92 2.9 2.91 2.903 2.922;3.26 3.274 3.271 3.271 3.254 3.238 3.24;3.387 3.399 3.397 3.397 3.385 3.362 3.363;3.436 3.442 3.442 3.441 3.439 3.429 3.43;3.481 3.491 3.491 3.493 3.492 3.479 3.481;3.538 3.547 3.546 3.547 3.54 3.534 3.534;3.586 3.592 3.592 3.593 3.589 3.582 3.582;3.616 3.621 3.622 3.624 3.622 3.622 3.623;3.644 3.65 3.651 3.653 3.652 3.653 3.656;3.677 3.683 3.685 3.687 3.686 3.688 3.691;3.719 3.726 3.727 3.73 3.728 3.731 3.734;3.766 3.772 3.774 3.777 3.776 3.777 3.78;3.819 3.837 3.838 3.84 3.835 3.829 3.831;3.88 3.886 3.886 3.887 3.885 3.883 3.882;3.913 3.918 3.919 3.92 3.918 3.917 3.917;3.952 3.958 3.959 3.96 3.958 3.958 3.958;4.01 4.017 4.017 4.019 4.017 4.016 4.016;4.061 4.066 4.067 4.068 4.067 4.067 4.067;4.076 4.08 4.082 4.083 4.083 4.083 4.084;4.09 4.096 4.098 4.1 4.099 4.098 4.099;4.185 4.185 4.185 4.185 4.185 4.185 4.185]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp1'
                                                                  */
#define rtCP_OCVvsSOCatallTemp1_bp01Dat rtCP_pooled_6QV4OqumygMa /* Expression: [0;5;10;15;20;25;30;35;40;45;50;55;60;65;70;75;80;85;90;95;100]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp1'
                                                                  */
#define rtCP_OCVvsSOCatallTemp1_bp02Dat rtCP_pooled_S734yA675FsN /* Expression: [-20;-10;0;10;25;45;55]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp1'
                                                                  */
#define rtCP_OCVvsSOCatallTemp2_maxInde rtCP_pooled_OJvaNeQ52mdS /* Computed Parameter: rtCP_OCVvsSOCatallTemp2_maxInde
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp2'
                                                                  */
#define rtCP_OCVvsSOCatallTemp_maxIndex rtCP_pooled_OJvaNeQ52mdS /* Computed Parameter: rtCP_OCVvsSOCatallTemp_maxIndex
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp'
                                                                  */
#define rtCP_OCVvsSOCatallTemp1_maxInde rtCP_pooled_OJvaNeQ52mdS /* Computed Parameter: rtCP_OCVvsSOCatallTemp1_maxInde
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp1'
                                                                  */
#endif                                 /* NBMS_ChargeOCV_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
