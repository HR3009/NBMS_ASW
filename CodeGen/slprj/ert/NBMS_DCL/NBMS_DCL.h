/*
 * File: NBMS_DCL.h
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

#ifndef NBMS_DCL_h_
#define NBMS_DCL_h_
#ifndef NBMS_DCL_COMMON_INCLUDES_
#define NBMS_DCL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* NBMS_DCL_COMMON_INCLUDES_ */

#include "NBMS_DCL_types.h"

/* Includes for objects with custom storage classes */
#include "DID.h"

/* Block signals for model 'NBMS_DCL' */
typedef struct {
  real_T CurrentLimit;                 /* '<S3>/SelCurrentLimit' */
  real_T DCL;                          /* '<S4>/CalcDCL' */
} B_NBMS_DCL_c_T;

/* Block states (default storage) for model 'NBMS_DCL' */
typedef struct {
  uint8_T is_active_c1_NBMS_DCL;       /* '<S4>/CalcDCL' */
  uint8_T is_c1_NBMS_DCL;              /* '<S4>/CalcDCL' */
  uint8_T is_C1_Condition;             /* '<S4>/CalcDCL' */
} DW_NBMS_DCL_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_NBMS_DCL_T {
  const char_T **errorStatus;
};

typedef struct {
  B_NBMS_DCL_c_T rtb;
  DW_NBMS_DCL_f_T rtdw;
  RT_MODEL_NBMS_DCL_T rtm;
} MdlrefDW_NBMS_DCL_T;

/* Model reference registration function */
extern void NBMS_DCL_initialize(const char_T **rt_errorStatus,
  RT_MODEL_NBMS_DCL_T *const NBMS_DCL_M);
extern void NBMS_DCL(const VEH_STT_LVL1_E *rtu_Veh_Lvl1, const uint8_T *rtu_SOC,
                     const real_T rtu_Temperature[6], const real_T *rtu_Current,
                     const boolean_T *rtu_G3_Common_Flt, const boolean_T
                     *rtu_G4_Common_Flt, const boolean_T *rtu_G3_Dischg_Flt,
                     const boolean_T *rtu_G4T1_Dischg_Flt, const boolean_T
                     *rtu_G4T2_Dischg_Flt, real_T *rty_Dischg_CurrentLimit,
                     real_T *rty_Timer30, B_NBMS_DCL_c_T *localB,
                     DW_NBMS_DCL_f_T *localDW);

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
 * '<Root>' : 'NBMS_DCL'
 * '<S1>'   : 'NBMS_DCL/Discharge_Current_Limit'
 * '<S2>'   : 'NBMS_DCL/Discharge_Current_Limit/ChkVehicleLvlDrive'
 * '<S3>'   : 'NBMS_DCL/Discharge_Current_Limit/DCL'
 * '<S4>'   : 'NBMS_DCL/Discharge_Current_Limit/DCL/DCL'
 * '<S5>'   : 'NBMS_DCL/Discharge_Current_Limit/DCL/DCL/CalcDCL'
 */
#endif                                 /* NBMS_DCL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
