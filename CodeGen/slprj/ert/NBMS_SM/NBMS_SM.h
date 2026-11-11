/*
 * File: NBMS_SM.h
 *
 * Code generated for Simulink model 'NBMS_SM'.
 *
 * Model version                  : 7.16
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Tue Nov 10 18:06:00 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_SM_h_
#define NBMS_SM_h_
#ifndef NBMS_SM_COMMON_INCLUDES_
#define NBMS_SM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* NBMS_SM_COMMON_INCLUDES_ */

#include "NBMS_SM_types.h"

/* Block states (default storage) for model 'NBMS_SM' */
typedef struct {
  uint8_T is_active_c3_NBMS_SM;        /* '<Root>/BMS_MODE_STATE_MACHINE' */
  uint8_T is_c3_NBMS_SM;               /* '<Root>/BMS_MODE_STATE_MACHINE' */
  uint8_T temporalCounter_i1;          /* '<Root>/BMS_MODE_STATE_MACHINE' */
  boolean_T SoC_LED_SW_prev;           /* '<Root>/BMS_MODE_STATE_MACHINE' */
  boolean_T SoC_LED_SW_start;          /* '<Root>/BMS_MODE_STATE_MACHINE' */
} DW_NBMS_SM_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_NBMS_SM_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_NBMS_SM_f_T rtdw;
  RT_MODEL_NBMS_SM_T rtm;
} MdlrefDW_NBMS_SM_T;

/* Model reference registration function */
extern void NBMS_SM_initialize(const char_T **rt_errorStatus, RT_MODEL_NBMS_SM_T
  *const NBMS_SM_M);
extern void NBMS_SM(const boolean_T *rtu_AppIn_HardwiredIgn, const boolean_T
                    *rtu_AppIn_OBCHVIL, const OBC_E *rtu_AppIn_OBCwakeup, const
                    boolean_T *rtu_AppIn_MCUHVIL, const boolean_T
                    *rtu_AppIn_RTCwakeup, const boolean_T *rtu_AppIn_SoCLEDSW,
                    const BMS_HVMosfet_STS_E *rtu_HV_Mosfet, const
                    Charger_Mode_E *rtu_AppIn_ChgMode, const Charger_Mode_Req_E *
                    rtu_Chrg_mode_req, const CV_Mode_Timer_E
                    *rtu_AppIn_CVmodeTimer, const boolean_T *rtu_AppIn_TRerror,
                    const boolean_T *rtu_AppIn_TRtimer, const boolean_T
                    *rtu_AppIn_G3DischargeFlt, const boolean_T
                    *rtu_AppIn_G3CommonFlt, const boolean_T
                    *rtu_AppIn_G4CommonFlt, const boolean_T
                    *rtu_AppIn_G4ChargeFlt, const boolean_T
                    *rtu_AppIn_OBCHeartbeatFail, const uint8_T *rtu_DisplaySoc,
                    const int16_T *rtu_MinCellVolt, const boolean_T
                    *rtu_AppIn_G4T1DischargeFlt, const boolean_T
                    *rtu_AppIn_G4T2DischargeFlt, BMS_MODE_E *rty_sm_BMSMODE,
                    DW_NBMS_SM_f_T *localDW);

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
 * '<Root>' : 'NBMS_SM'
 * '<S1>'   : 'NBMS_SM/BMS_MODE_STATE_MACHINE'
 */
#endif                                 /* NBMS_SM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
