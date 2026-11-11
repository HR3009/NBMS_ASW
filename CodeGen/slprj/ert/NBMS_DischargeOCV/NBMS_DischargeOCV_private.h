/*
 * File: NBMS_DischargeOCV_private.h
 *
 * Code generated for Simulink model 'NBMS_DischargeOCV'.
 *
 * Model version                  : 7.2
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Tue Nov 10 18:06:05 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_DischargeOCV_private_h_
#define NBMS_DischargeOCV_private_h_
#include "rtwtypes.h"
#include "NBMS_DischargeOCV_types.h"
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

extern const real_T rtCP_pooled_gyU43vPfdlBF[147];
extern const real_T rtCP_pooled_6QV4OqumygMa[21];
extern const real_T rtCP_pooled_S734yA675FsN[7];
extern const uint32_T rtCP_pooled_OJvaNeQ52mdS[2];

#define rtCP_OCVvsSOCatallTemp2_tableDa rtCP_pooled_gyU43vPfdlBF /* Expression: [2.934 2.929 2.92 2.9 2.911 2.903 2.922;3.148 3.135 3.129 3.118 3.123 3.121 3.133;3.295 3.294 3.289 3.281 3.272 3.266 3.276;3.409 3.409 3.405 3.4 3.395 3.386 3.395;3.45 3.452 3.451 3.451 3.452 3.449 3.452;3.494 3.501 3.501 3.499 3.499 3.49 3.496;3.552 3.559 3.558 3.557 3.554 3.546 3.551;3.597 3.607 3.607 3.606 3.603 3.593 3.598;3.636 3.64 3.641 3.642 3.642 3.642 3.648;3.667 3.672 3.674 3.676 3.676 3.679 3.685;3.708 3.715 3.717 3.718 3.718 3.721 3.727;3.753 3.756 3.758 3.759 3.763 3.766 3.763;3.799 3.803 3.805 3.807 3.813 3.812 3.808;3.868 3.872 3.872 3.87 3.877 3.874 3.866;3.907 3.909 3.91 3.91 3.912 3.911 3.907;3.946 3.949 3.95 3.95 3.953 3.952 3.947;4.006 4.008 4.009 4.009 4.012 4.011 4.005;4.057 4.059 4.06 4.06 4.063 4.063 4.059;4.072 4.075 4.077 4.077 4.08 4.08 4.079;4.087 4.091 4.093 4.094 4.096 4.096 4.094;4.185 4.185 4.185 4.185 4.185 4.185 4.185]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp2'
                                                                  */
#define rtCP_OCVvsSOCatallTemp2_bp01Dat rtCP_pooled_6QV4OqumygMa /* Expression: [0;5;10;15;20;25;30;35;40;45;50;55;60;65;70;75;80;85;90;95;100]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp2'
                                                                  */
#define rtCP_OCVvsSOCatallTemp2_bp02Dat rtCP_pooled_S734yA675FsN /* Expression: [-20;-10;0;10;25;45;55]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp2'
                                                                  */
#define rtCP_OCVvsSOCatallTemp_tableDat rtCP_pooled_gyU43vPfdlBF /* Expression: [2.934 2.929 2.92 2.9 2.911 2.903 2.922;3.148 3.135 3.129 3.118 3.123 3.121 3.133;3.295 3.294 3.289 3.281 3.272 3.266 3.276;3.409 3.409 3.405 3.4 3.395 3.386 3.395;3.45 3.452 3.451 3.451 3.452 3.449 3.452;3.494 3.501 3.501 3.499 3.499 3.49 3.496;3.552 3.559 3.558 3.557 3.554 3.546 3.551;3.597 3.607 3.607 3.606 3.603 3.593 3.598;3.636 3.64 3.641 3.642 3.642 3.642 3.648;3.667 3.672 3.674 3.676 3.676 3.679 3.685;3.708 3.715 3.717 3.718 3.718 3.721 3.727;3.753 3.756 3.758 3.759 3.763 3.766 3.763;3.799 3.803 3.805 3.807 3.813 3.812 3.808;3.868 3.872 3.872 3.87 3.877 3.874 3.866;3.907 3.909 3.91 3.91 3.912 3.911 3.907;3.946 3.949 3.95 3.95 3.953 3.952 3.947;4.006 4.008 4.009 4.009 4.012 4.011 4.005;4.057 4.059 4.06 4.06 4.063 4.063 4.059;4.072 4.075 4.077 4.077 4.08 4.08 4.079;4.087 4.091 4.093 4.094 4.096 4.096 4.094;4.185 4.185 4.185 4.185 4.185 4.185 4.185]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp'
                                                                  */
#define rtCP_OCVvsSOCatallTemp_bp01Data rtCP_pooled_6QV4OqumygMa /* Expression: [0;5;10;15;20;25;30;35;40;45;50;55;60;65;70;75;80;85;90;95;100]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp'
                                                                  */
#define rtCP_OCVvsSOCatallTemp_bp02Data rtCP_pooled_S734yA675FsN /* Expression: [-20;-10;0;10;25;45;55]
                                                                  * Referenced by: '<S1>/OCV vs SOC at all Temp'
                                                                  */
#define rtCP_OCVvsSOCatallTemp1_tableDa rtCP_pooled_gyU43vPfdlBF /* Expression: [2.934 2.929 2.92 2.9 2.911 2.903 2.922;3.148 3.135 3.129 3.118 3.123 3.121 3.133;3.295 3.294 3.289 3.281 3.272 3.266 3.276;3.409 3.409 3.405 3.4 3.395 3.386 3.395;3.45 3.452 3.451 3.451 3.452 3.449 3.452;3.494 3.501 3.501 3.499 3.499 3.49 3.496;3.552 3.559 3.558 3.557 3.554 3.546 3.551;3.597 3.607 3.607 3.606 3.603 3.593 3.598;3.636 3.64 3.641 3.642 3.642 3.642 3.648;3.667 3.672 3.674 3.676 3.676 3.679 3.685;3.708 3.715 3.717 3.718 3.718 3.721 3.727;3.753 3.756 3.758 3.759 3.763 3.766 3.763;3.799 3.803 3.805 3.807 3.813 3.812 3.808;3.868 3.872 3.872 3.87 3.877 3.874 3.866;3.907 3.909 3.91 3.91 3.912 3.911 3.907;3.946 3.949 3.95 3.95 3.953 3.952 3.947;4.006 4.008 4.009 4.009 4.012 4.011 4.005;4.057 4.059 4.06 4.06 4.063 4.063 4.059;4.072 4.075 4.077 4.077 4.08 4.08 4.079;4.087 4.091 4.093 4.094 4.096 4.096 4.094;4.185 4.185 4.185 4.185 4.185 4.185 4.185]
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
#endif                                 /* NBMS_DischargeOCV_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
