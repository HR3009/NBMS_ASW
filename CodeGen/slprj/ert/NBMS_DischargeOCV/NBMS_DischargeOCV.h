/*
 * File: NBMS_DischargeOCV.h
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

#ifndef NBMS_DischargeOCV_h_
#define NBMS_DischargeOCV_h_
#ifndef NBMS_DischargeOCV_COMMON_INCLUDES_
#define NBMS_DischargeOCV_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* NBMS_DischargeOCV_COMMON_INCLUDES_ */

#include "NBMS_DischargeOCV_types.h"

/* Block states (default storage) for model 'NBMS_DischargeOCV' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T UnitDelay2_DSTATE;            /* '<S1>/Unit Delay2' */
  real_T UnitDelay1_DSTATE;            /* '<S1>/Unit Delay1' */
  boolean_T TmpModelReferenceSubsystem_MODE;/* synthesized block */
} DW_NBMS_DischargeOCV_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_NBMS_DischargeOCV_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_NBMS_DischargeOCV_f_T rtdw;
  RT_MODEL_NBMS_DischargeOCV_T rtm;
} MdlrefDW_NBMS_DischargeOCV_T;

/* Model reference registration function */
extern void NBMS_DischargeOCV_initialize(const char_T **rt_errorStatus,
  RT_MODEL_NBMS_DischargeOCV_T *const NBMS_DischargeOCV_M);
extern void NBMS_DischargeOCV_Disable(real_T *rty_Initial_SOC,
  DW_NBMS_DischargeOCV_f_T *localDW);
extern void NBMS_DischargeOCV(const real_T *rtu_Temp, const int16_T *rtu_OCV,
  const boolean_T *rtu_Enable, real_T *rty_Initial_SOC, DW_NBMS_DischargeOCV_f_T
  *localDW);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'NBMS_DischargeOCV'
 * '<S1>'   : 'NBMS_DischargeOCV/OCV vs SOC @ all Temperatures'
 */
#endif                                 /* NBMS_DischargeOCV_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
