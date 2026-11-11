/*
 * File: NBMS_CCCV.h
 *
 * Code generated for Simulink model 'NBMS_CCCV'.
 *
 * Model version                  : 7.23
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 11 09:32:01 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_CCCV_h_
#define NBMS_CCCV_h_
#ifndef NBMS_CCCV_COMMON_INCLUDES_
#define NBMS_CCCV_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* NBMS_CCCV_COMMON_INCLUDES_ */

#include "NBMS_CCCV_types.h"

/* Includes for objects with custom storage classes */
#include "DID.h"

/* Block signals for model 'NBMS_CCCV' */
typedef struct {
  real_T ChargeCurrentLimit;           /* '<Root>/Charge Profile' */
} B_NBMS_CCCV_c_T;

/* Block states (default storage) for model 'NBMS_CCCV' */
typedef struct {
  uint32_T temporalCounter_i1;         /* '<Root>/Charge Profile' */
  uint32_T durationCounter_1;          /* '<Root>/Charge Profile' */
  uint32_T durationCounter_1_i;        /* '<Root>/Charge Profile' */
  uint32_T durationCounter_1_c;        /* '<Root>/BMS NM Msg' */
  uint8_T is_active_c3_NBMS_CCCV;      /* '<Root>/Charge Profile' */
  uint8_T is_CHARGE_CCCV;              /* '<Root>/Charge Profile' */
  uint8_T is_CC;                       /* '<Root>/Charge Profile' */
  uint8_T is_active_c1_NBMS_CCCV;      /* '<Root>/BMS NM Msg' */
  uint8_T is_c1_NBMS_CCCV;             /* '<Root>/BMS NM Msg' */
  boolean_T Ign_prev;                  /* '<Root>/BMS NM Msg' */
  boolean_T Ign_start;                 /* '<Root>/BMS NM Msg' */
} DW_NBMS_CCCV_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_NBMS_CCCV_T {
  const char_T **errorStatus;
};

typedef struct {
  B_NBMS_CCCV_c_T rtb;
  DW_NBMS_CCCV_f_T rtdw;
  RT_MODEL_NBMS_CCCV_T rtm;
} MdlrefDW_NBMS_CCCV_T;

/* Model reference registration function */
extern void NBMS_CCCV_initialize(const char_T **rt_errorStatus,
  RT_MODEL_NBMS_CCCV_T *const NBMS_CCCV_M);
extern real_T NBMS_CCCV_CCL(real_T rtu_SoC, real_T rtu_temp);
extern void NBMS_CCCV(const OBC_E *rtu_mi_OBC_wakeup, const uint8_T
                      *rtu_Display_SoC, const BMS_MODE_E *rtu_sm_BMSMODE, const
                      BMS_HVMosfet_STS_E *rtu_HV_Mosfet, const real_T *rtu_SoH,
                      const real_T *rtu_AppIn_BattTemp, const int16_T
                      *rtu_VtAvgmax, const boolean_T *rtu_Hardwired_Ign, const
                      boolean_T *rtu_RTC_Wakeup, const boolean_T
                      *rtu_OBC_Heartbeat_fail, const boolean_T
                      *rtu_OBC_HVIL_input, const int16_T *rtu_MinCellVolt, const
                      real_T *rtu_mi_Pack_Volt, const boolean_T *rtu_Chrg_Derate,
                      const boolean_T *rtu_G4_Charge_Fault, const boolean_T
                      *rtu_G4_Common_Fault, const boolean_T *rtu_G3_Common_Fault,
                      BMS_NM_Msg_E *rty_BMS_NM_Msg, Charger_Mode_Req_E
                      *rty_Chg_Mode_Req, real_T *rty_ChargeVoltageLt, uint8_T
                      *rty_soc_full, real_T *rty_ChargeCurrentLt,
                      B_NBMS_CCCV_c_T *localB, DW_NBMS_CCCV_f_T *localDW);

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
 * '<Root>' : 'NBMS_CCCV'
 * '<S1>'   : 'NBMS_CCCV/BMS NM Msg'
 * '<S2>'   : 'NBMS_CCCV/Charge Profile'
 * '<S3>'   : 'NBMS_CCCV/Charge Profile/CCL'
 */
#endif                                 /* NBMS_CCCV_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
