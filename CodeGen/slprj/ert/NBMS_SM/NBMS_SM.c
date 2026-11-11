/*
 * File: NBMS_SM.c
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

#include "NBMS_SM.h"
#include "NBMS_SM_types.h"
#include "rtwtypes.h"
#include "NBMS_SM_private.h"

/* Named constants for Chart: '<Root>/BMS_MODE_STATE_MACHINE' */
#define NBMS_SM_IN_Charge              ((uint8_T)1U)
#define NBMS_SM_IN_Discharge           ((uint8_T)2U)
#define NBMS_SM_IN_Fault               ((uint8_T)3U)
#define NBMS_SM_IN_Sleep               ((uint8_T)4U)
#define NBMS_SM_IN_Standby             ((uint8_T)5U)

/* Forward declaration for local functions */
static void NBMS_SM_Fault(const boolean_T *G4DischargeFault, const boolean_T
  *rtu_AppIn_HardwiredIgn, const boolean_T *rtu_AppIn_OBCHVIL, const OBC_E
  *rtu_AppIn_OBCwakeup, const BMS_HVMosfet_STS_E *rtu_HV_Mosfet, const
  Charger_Mode_E *rtu_AppIn_ChgMode, const Charger_Mode_Req_E *rtu_Chrg_mode_req,
  const boolean_T *rtu_AppIn_TRerror, const boolean_T *rtu_AppIn_TRtimer, const
  boolean_T *rtu_AppIn_G3DischargeFlt, const boolean_T *rtu_AppIn_G3CommonFlt,
  const boolean_T *rtu_AppIn_G4CommonFlt, const boolean_T *rtu_AppIn_G4ChargeFlt,
  BMS_MODE_E *rty_sm_BMSMODE, DW_NBMS_SM_f_T *localDW);

/* Function for Chart: '<Root>/BMS_MODE_STATE_MACHINE' */
static void NBMS_SM_Fault(const boolean_T *G4DischargeFault, const boolean_T
  *rtu_AppIn_HardwiredIgn, const boolean_T *rtu_AppIn_OBCHVIL, const OBC_E
  *rtu_AppIn_OBCwakeup, const BMS_HVMosfet_STS_E *rtu_HV_Mosfet, const
  Charger_Mode_E *rtu_AppIn_ChgMode, const Charger_Mode_Req_E *rtu_Chrg_mode_req,
  const boolean_T *rtu_AppIn_TRerror, const boolean_T *rtu_AppIn_TRtimer, const
  boolean_T *rtu_AppIn_G3DischargeFlt, const boolean_T *rtu_AppIn_G3CommonFlt,
  const boolean_T *rtu_AppIn_G4CommonFlt, const boolean_T *rtu_AppIn_G4ChargeFlt,
  BMS_MODE_E *rty_sm_BMSMODE, DW_NBMS_SM_f_T *localDW)
{
  /* Chart: '<Root>/BMS_MODE_STATE_MACHINE' */
  if (!*rtu_AppIn_HardwiredIgn && (*rtu_HV_Mosfet == HV_DISCONNECTED) &&
      ((!*rtu_AppIn_TRerror && (localDW->temporalCounter_i1 >= 100)) ||
       (*rtu_AppIn_TRerror && *rtu_AppIn_TRtimer))) {
    localDW->is_c3_NBMS_SM = NBMS_SM_IN_Sleep;
    *rty_sm_BMSMODE = BMS_SLEEP;
  } else if (*rtu_AppIn_OBCHVIL && (*rtu_AppIn_OBCwakeup == Wake_Up) &&
             (*rtu_AppIn_ChgMode != Error) && (*rtu_Chrg_mode_req !=
              Charge_Complete) && !*rtu_AppIn_G4ChargeFlt &&
             !*rtu_AppIn_G3CommonFlt && !*rtu_AppIn_G4CommonFlt) {
    localDW->is_c3_NBMS_SM = NBMS_SM_IN_Charge;
    *rty_sm_BMSMODE = BMS_CHARGE;
  } else if (!*rtu_AppIn_OBCHVIL && *rtu_AppIn_HardwiredIgn &&
             !*G4DischargeFault && !*rtu_AppIn_G3DischargeFlt &&
             !*rtu_AppIn_G3CommonFlt && !*rtu_AppIn_G4CommonFlt) {
    localDW->is_c3_NBMS_SM = NBMS_SM_IN_Discharge;
    *rty_sm_BMSMODE = BMS_DISCHARGE;
  } else if (!*rtu_AppIn_G4CommonFlt && !*rtu_AppIn_G3CommonFlt &&
             !*rtu_AppIn_G4ChargeFlt && !*G4DischargeFault &&
             !*rtu_AppIn_G3DischargeFlt) {
    localDW->temporalCounter_i1 = 0U;
    localDW->is_c3_NBMS_SM = NBMS_SM_IN_Standby;
    *rty_sm_BMSMODE = BMS_STANDBY;
  } else {
    *rty_sm_BMSMODE = BMS_FAULT;
  }

  /* End of Chart: '<Root>/BMS_MODE_STATE_MACHINE' */
}

/* Output and update for referenced model: 'NBMS_SM' */
void NBMS_SM(const boolean_T *rtu_AppIn_HardwiredIgn, const boolean_T
             *rtu_AppIn_OBCHVIL, const OBC_E *rtu_AppIn_OBCwakeup, const
             boolean_T *rtu_AppIn_MCUHVIL, const boolean_T *rtu_AppIn_RTCwakeup,
             const boolean_T *rtu_AppIn_SoCLEDSW, const BMS_HVMosfet_STS_E
             *rtu_HV_Mosfet, const Charger_Mode_E *rtu_AppIn_ChgMode, const
             Charger_Mode_Req_E *rtu_Chrg_mode_req, const CV_Mode_Timer_E
             *rtu_AppIn_CVmodeTimer, const boolean_T *rtu_AppIn_TRerror, const
             boolean_T *rtu_AppIn_TRtimer, const boolean_T
             *rtu_AppIn_G3DischargeFlt, const boolean_T *rtu_AppIn_G3CommonFlt,
             const boolean_T *rtu_AppIn_G4CommonFlt, const boolean_T
             *rtu_AppIn_G4ChargeFlt, const boolean_T *rtu_AppIn_OBCHeartbeatFail,
             const uint8_T *rtu_DisplaySoc, const int16_T *rtu_MinCellVolt,
             const boolean_T *rtu_AppIn_G4T1DischargeFlt, const boolean_T
             *rtu_AppIn_G4T2DischargeFlt, BMS_MODE_E *rty_sm_BMSMODE,
             DW_NBMS_SM_f_T *localDW)
{
  boolean_T G4DischargeFault;

  /* Logic: '<Root>/OR' */
  G4DischargeFault = (*rtu_AppIn_G4T1DischargeFlt || *rtu_AppIn_G4T2DischargeFlt);

  /* Chart: '<Root>/BMS_MODE_STATE_MACHINE' incorporates:
   *  DataTypeConversion: '<Root>/ConvertToDouble'
   *  Logic: '<Root>/OR'
   */
  if (localDW->temporalCounter_i1 < 127) {
    localDW->temporalCounter_i1++;
  }

  localDW->SoC_LED_SW_prev = localDW->SoC_LED_SW_start;
  localDW->SoC_LED_SW_start = *rtu_AppIn_SoCLEDSW;
  if (localDW->is_active_c3_NBMS_SM == 0) {
    localDW->SoC_LED_SW_prev = *rtu_AppIn_SoCLEDSW;
    localDW->is_active_c3_NBMS_SM = 1U;
    localDW->is_c3_NBMS_SM = NBMS_SM_IN_Sleep;
    *rty_sm_BMSMODE = BMS_SLEEP;
  } else {
    switch (localDW->is_c3_NBMS_SM) {
     case NBMS_SM_IN_Charge:
      if (*rtu_AppIn_G3CommonFlt || *rtu_AppIn_G4ChargeFlt ||
          *rtu_AppIn_G4CommonFlt) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c3_NBMS_SM = NBMS_SM_IN_Fault;
        *rty_sm_BMSMODE = BMS_FAULT;
      } else if (*rtu_AppIn_OBCHeartbeatFail || !*rtu_AppIn_OBCHVIL ||
                 (*rtu_Chrg_mode_req == Charge_Complete) || (*rtu_AppIn_ChgMode ==
                  Error) || (*rtu_AppIn_CVmodeTimer == Expired)) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c3_NBMS_SM = NBMS_SM_IN_Standby;
        *rty_sm_BMSMODE = BMS_STANDBY;
      } else {
        *rty_sm_BMSMODE = BMS_CHARGE;
      }
      break;

     case NBMS_SM_IN_Discharge:
      if (*rtu_AppIn_G3CommonFlt || (*rtu_AppIn_G4T1DischargeFlt ||
           *rtu_AppIn_G4T2DischargeFlt) || *rtu_AppIn_G3DischargeFlt ||
          *rtu_AppIn_G4CommonFlt) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c3_NBMS_SM = NBMS_SM_IN_Fault;
        *rty_sm_BMSMODE = BMS_FAULT;
      } else if (!*rtu_AppIn_HardwiredIgn || ((*rtu_AppIn_OBCwakeup == Wake_Up) &&
                  !*rtu_AppIn_OBCHeartbeatFail && *rtu_AppIn_OBCHVIL)) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c3_NBMS_SM = NBMS_SM_IN_Standby;
        *rty_sm_BMSMODE = BMS_STANDBY;
      } else {
        *rty_sm_BMSMODE = BMS_DISCHARGE;
      }
      break;

     case NBMS_SM_IN_Fault:
      NBMS_SM_Fault(&G4DischargeFault, rtu_AppIn_HardwiredIgn, rtu_AppIn_OBCHVIL,
                    rtu_AppIn_OBCwakeup, rtu_HV_Mosfet, rtu_AppIn_ChgMode,
                    rtu_Chrg_mode_req, rtu_AppIn_TRerror, rtu_AppIn_TRtimer,
                    rtu_AppIn_G3DischargeFlt, rtu_AppIn_G3CommonFlt,
                    rtu_AppIn_G4CommonFlt, rtu_AppIn_G4ChargeFlt, rty_sm_BMSMODE,
                    localDW);
      break;

     case NBMS_SM_IN_Sleep:
      if (*rtu_AppIn_HardwiredIgn || ((localDW->SoC_LED_SW_prev !=
            localDW->SoC_LED_SW_start) && localDW->SoC_LED_SW_start) ||
          (!*rtu_AppIn_OBCHeartbeatFail && (*rtu_AppIn_OBCwakeup == Wake_Up)) ||
          *rtu_AppIn_RTCwakeup) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c3_NBMS_SM = NBMS_SM_IN_Standby;
        *rty_sm_BMSMODE = BMS_STANDBY;
      } else {
        *rty_sm_BMSMODE = BMS_SLEEP;
      }
      break;

     default:
      /* case IN_Standby: */
      if (!*rtu_AppIn_HardwiredIgn && (*rtu_HV_Mosfet == HV_DISCONNECTED) &&
          (!*rtu_AppIn_RTCwakeup || (*rtu_AppIn_OBCwakeup != Wake_Up)) &&
          (localDW->temporalCounter_i1 >= 100)) {
        localDW->is_c3_NBMS_SM = NBMS_SM_IN_Sleep;
        *rty_sm_BMSMODE = BMS_SLEEP;
      } else if (*rtu_AppIn_G4CommonFlt || *rtu_AppIn_G3CommonFlt ||
                 *rtu_AppIn_G4ChargeFlt) {
        localDW->temporalCounter_i1 = 0U;
        localDW->is_c3_NBMS_SM = NBMS_SM_IN_Fault;
        *rty_sm_BMSMODE = BMS_FAULT;
      } else if (*rtu_AppIn_OBCHVIL && (*rtu_AppIn_OBCwakeup == Wake_Up) &&
                 !*rtu_AppIn_OBCHeartbeatFail && (*rtu_Chrg_mode_req !=
                  Charge_Complete) && (*rtu_AppIn_ChgMode != Error) &&
                 (*rtu_DisplaySoc <= 99) && ((real_T)*rtu_MinCellVolt * 0.001 >=
                  2.25)) {
        localDW->is_c3_NBMS_SM = NBMS_SM_IN_Charge;
        *rty_sm_BMSMODE = BMS_CHARGE;
      } else if (*rtu_AppIn_HardwiredIgn && !*rtu_AppIn_OBCHVIL &&
                 *rtu_AppIn_MCUHVIL) {
        localDW->is_c3_NBMS_SM = NBMS_SM_IN_Discharge;
        *rty_sm_BMSMODE = BMS_DISCHARGE;
      } else {
        *rty_sm_BMSMODE = BMS_STANDBY;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/BMS_MODE_STATE_MACHINE' */
}

/* Model initialize function */
void NBMS_SM_initialize(const char_T **rt_errorStatus, RT_MODEL_NBMS_SM_T *const
  NBMS_SM_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(NBMS_SM_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
