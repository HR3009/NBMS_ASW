/*
 * File: NBMS_CCCV.c
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

#include "NBMS_CCCV.h"
#include "rtwtypes.h"
#include "NBMS_CCCV_types.h"
#include <math.h>
#include "NBMS_CCCV_private.h"
#include "look2_binlxpw.h"
#include "DID.h"

/* Named constants for Chart: '<Root>/BMS NM Msg' */
#define NBMS_CCCV_IN_ACTIVE            ((uint8_T)1U)
#define NBMS_CCCV_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define NBMS_CCCV_IN_SLEEP             ((uint8_T)2U)

/* Named constants for Chart: '<Root>/Charge Profile' */
#define NBMS_CCCV_IN_CC                ((uint8_T)1U)
#define NBMS_CCCV_IN_CC_End            ((uint8_T)1U)
#define NBMS_CCCV_IN_CC_Start          ((uint8_T)2U)
#define NBMS_CCCV_IN_CV                ((uint8_T)2U)
#define NBMS_CCCV_IN_Charge_Complete   ((uint8_T)3U)
#define NBMS_CCCV_IN_Charge_Disable    ((uint8_T)4U)
#define NBMS_CCCV_IN_Charge_Standby    ((uint8_T)5U)

/* Output and update for function-call system: '<S2>/CCL' */
real_T NBMS_CCCV_CCL(real_T rtu_SoC, real_T rtu_temp)
{
  /* Lookup_n-D: '<S3>/ContinuousSafety' */
  return look2_binlxpw(rtu_temp, rtu_SoC, &TEMP[0], &SOC[0],
                       rtCP_ContinuousSafety_tableData,
                       rtCP_ContinuousSafety_maxIndex, 10U);
}

/* Output and update for referenced model: 'NBMS_CCCV' */
void NBMS_CCCV(const OBC_E *rtu_mi_OBC_wakeup, const uint8_T *rtu_Display_SoC,
               const BMS_MODE_E *rtu_sm_BMSMODE, const BMS_HVMosfet_STS_E
               *rtu_HV_Mosfet, const real_T *rtu_SoH, const real_T
               *rtu_AppIn_BattTemp, const int16_T *rtu_VtAvgmax, const boolean_T
               *rtu_Hardwired_Ign, const boolean_T *rtu_RTC_Wakeup, const
               boolean_T *rtu_OBC_Heartbeat_fail, const boolean_T
               *rtu_OBC_HVIL_input, const int16_T *rtu_MinCellVolt, const real_T
               *rtu_mi_Pack_Volt, const boolean_T *rtu_Chrg_Derate, const
               boolean_T *rtu_G4_Charge_Fault, const boolean_T
               *rtu_G4_Common_Fault, const boolean_T *rtu_G3_Common_Fault,
               BMS_NM_Msg_E *rty_BMS_NM_Msg, Charger_Mode_Req_E
               *rty_Chg_Mode_Req, real_T *rty_ChargeVoltageLt, uint8_T
               *rty_soc_full, real_T *rty_ChargeCurrentLt, B_NBMS_CCCV_c_T
               *localB, DW_NBMS_CCCV_f_T *localDW)
{
  real_T rtb_CCCurrLimit;
  real_T rtb_CVCurrLimit;
  real_T rtb_RevivalCurrLimit;
  real_T rtb_VoltLimit;
  real_T tmp_0;
  boolean_T tmp;

  /* Gain: '<Root>/gainVltLt' incorporates:
   *  Constant: '<Root>/VoltageLimit'
   */
  rtb_VoltLimit = 0.001 * (real_T)CAL_CHRG_VOLT_LIMIT;

  /* Gain: '<Root>/gainCVCurrLt' incorporates:
   *  Constant: '<Root>/CV_CurrentLimit'
   */
  rtb_CVCurrLimit = 0.001 * (real_T)CAL_CHRG_CV_CURRENT_LIMIT;

  /* Gain: '<Root>/GainCCCurrLt' incorporates:
   *  Constant: '<Root>/CC_CurrentLimit'
   */
  rtb_CCCurrLimit = 0.001 * (real_T)CAL_CHRG_CC_CURRENT_LIMIT;

  /* Gain: '<Root>/gainRevivalCurrLt' incorporates:
   *  Constant: '<Root>/DDRevivalCurrLt'
   */
  rtb_RevivalCurrLimit = 0.001 * (real_T)CAL_DD_REVIVAL_CCL;

  /* Chart: '<Root>/Charge Profile' incorporates:
   *  DataTypeConversion: '<Root>/ConvToDouble'
   *  DataTypeConversion: '<Root>/ConvToDouble1'
   *  DataTypeConversion: '<Root>/DoubleConv'
   */
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c3_NBMS_CCCV == 0) {
    localDW->is_active_c3_NBMS_CCCV = 1U;
    localDW->is_CHARGE_CCCV = NBMS_CCCV_IN_Charge_Disable;
    *rty_Chg_Mode_Req = Disabled;
    localB->ChargeCurrentLimit = 0.0;
    *rty_ChargeVoltageLt = 0.0;
    *rty_soc_full = 0U;
  } else {
    switch (localDW->is_CHARGE_CCCV) {
     case NBMS_CCCV_IN_CC:
      if (*rtu_sm_BMSMODE != BMS_CHARGE) {
        localDW->is_CC = NBMS_CCCV_IN_NO_ACTIVE_CHILD;
        localDW->is_CHARGE_CCCV = NBMS_CCCV_IN_Charge_Disable;
        *rty_Chg_Mode_Req = Disabled;
        localB->ChargeCurrentLimit = 0.0;
        *rty_ChargeVoltageLt = 0.0;
        *rty_soc_full = 0U;
      } else if (localDW->is_CC == NBMS_CCCV_IN_CC_End) {
        if (localDW->temporalCounter_i1 >= (uint32_T)(CAL_CV_WAIT_TIMER * 10)) {
          localDW->is_CC = NBMS_CCCV_IN_NO_ACTIVE_CHILD;
          localDW->temporalCounter_i1 = 0U;
          localDW->durationCounter_1_i = 0U;
          localDW->is_CHARGE_CCCV = NBMS_CCCV_IN_CV;
          *rty_Chg_Mode_Req = CV;
          localB->ChargeCurrentLimit = rtb_CVCurrLimit * *rtu_SoH;
          *rty_ChargeVoltageLt = rtb_VoltLimit;
        }
      } else {
        /* case IN_CC_Start: */
        if (!((real_T)*rtu_VtAvgmax * 0.001 >= CAL_CC_END_THRSH)) {
          localDW->durationCounter_1 = 0U;
        }

        if (localDW->durationCounter_1 > (uint32_T)(CAL_CC_END_DEBOUNCE_TIMER *
             10)) {
          localDW->temporalCounter_i1 = 0U;
          localDW->is_CC = NBMS_CCCV_IN_CC_End;
          *rty_Chg_Mode_Req = CC_End;
          localB->ChargeCurrentLimit = 0.0;
          *rty_ChargeVoltageLt = 0.0;
        } else {
          *rty_Chg_Mode_Req = CC_Start;
          localB->ChargeCurrentLimit = rtb_RevivalCurrLimit;
          *rty_ChargeVoltageLt = rtb_VoltLimit;
          if (*rtu_mi_Pack_Volt >= 60.0) {
            /* Outputs for Function Call SubSystem: '<S2>/CCL' */
            localB->ChargeCurrentLimit = fmin(rtb_CCCurrLimit, NBMS_CCCV_CCL
              ((real_T)*rtu_Display_SoC, *rtu_AppIn_BattTemp) * *rtu_SoH);

            /* End of Outputs for SubSystem: '<S2>/CCL' */
          }
        }
      }
      break;

     case NBMS_CCCV_IN_CV:
      if (!((real_T)*rtu_VtAvgmax * 0.001 >= CAL_CV_END_THRSH)) {
        localDW->durationCounter_1_i = 0U;
      }

      if ((localDW->durationCounter_1_i > (uint32_T)(CAL_CV_END_DEBOUNCE_TIMER *
            10)) || (localDW->temporalCounter_i1 >= (uint32_T)((int32_T)
            CAL_CV_COMPLETE_TIMER * 10))) {
        localDW->is_CHARGE_CCCV = NBMS_CCCV_IN_Charge_Complete;
        *rty_Chg_Mode_Req = Charge_Complete;
        localB->ChargeCurrentLimit = 0.0;
        *rty_ChargeVoltageLt = 0.0;
        *rty_soc_full = 100U;
      } else if (*rtu_sm_BMSMODE != BMS_CHARGE) {
        localDW->is_CHARGE_CCCV = NBMS_CCCV_IN_Charge_Disable;
        *rty_Chg_Mode_Req = Disabled;
        localB->ChargeCurrentLimit = 0.0;
        *rty_ChargeVoltageLt = 0.0;
        *rty_soc_full = 0U;
      } else {
        *rty_Chg_Mode_Req = CV;
        localB->ChargeCurrentLimit = rtb_CVCurrLimit * *rtu_SoH;
        *rty_ChargeVoltageLt = rtb_VoltLimit;
      }
      break;

     case NBMS_CCCV_IN_Charge_Complete:
      *rty_soc_full = 100U;
      if (*rtu_sm_BMSMODE != BMS_CHARGE) {
        localDW->is_CHARGE_CCCV = NBMS_CCCV_IN_Charge_Disable;
        *rty_Chg_Mode_Req = Disabled;
        localB->ChargeCurrentLimit = 0.0;
        *rty_ChargeVoltageLt = 0.0;
        *rty_soc_full = 0U;
      }
      break;

     case NBMS_CCCV_IN_Charge_Disable:
      *rty_soc_full = 0U;
      if ((*rtu_mi_OBC_wakeup == Wake_Up) && (*rtu_Display_SoC <= 99) &&
          ((real_T)*rtu_MinCellVolt * 0.001 >= 2.25)) {
        localDW->is_CHARGE_CCCV = NBMS_CCCV_IN_Charge_Standby;
        *rty_Chg_Mode_Req = Standby;
        localB->ChargeCurrentLimit = 0.0;
        *rty_ChargeVoltageLt = 0.0;
      } else if (*rtu_Display_SoC == 100) {
        localDW->is_CHARGE_CCCV = NBMS_CCCV_IN_Charge_Complete;
        *rty_Chg_Mode_Req = Charge_Complete;
        localB->ChargeCurrentLimit = 0.0;
        *rty_ChargeVoltageLt = 0.0;
        *rty_soc_full = 100U;
      }
      break;

     default:
      /* case IN_Charge_Standby: */
      tmp = ((*rtu_sm_BMSMODE == BMS_CHARGE) && (*rtu_HV_Mosfet == HV_CONNECTED));

      /* DataTypeConversion: '<Root>/DoubleConv' */
      tmp_0 = (real_T)*rtu_VtAvgmax * 0.001;
      if (tmp && (tmp_0 < CAL_CC_END_THRSH)) {
        localDW->is_CHARGE_CCCV = NBMS_CCCV_IN_CC;
        localDW->durationCounter_1 = 0U;
        localDW->is_CC = NBMS_CCCV_IN_CC_Start;
        *rty_Chg_Mode_Req = CC_Start;
        localB->ChargeCurrentLimit = rtb_RevivalCurrLimit;
        *rty_ChargeVoltageLt = rtb_VoltLimit;
        if (*rtu_mi_Pack_Volt >= 60.0) {
          /* Outputs for Function Call SubSystem: '<S2>/CCL' */
          localB->ChargeCurrentLimit = fmin(rtb_CCCurrLimit, NBMS_CCCV_CCL
            ((real_T)*rtu_Display_SoC, *rtu_AppIn_BattTemp) * *rtu_SoH);

          /* End of Outputs for SubSystem: '<S2>/CCL' */
        }
      } else if (tmp && (tmp_0 >= CAL_CC_END_THRSH)) {
        localDW->temporalCounter_i1 = 0U;
        localDW->durationCounter_1_i = 0U;
        localDW->is_CHARGE_CCCV = NBMS_CCCV_IN_CV;
        *rty_Chg_Mode_Req = CV;
        localB->ChargeCurrentLimit = rtb_CVCurrLimit * *rtu_SoH;
        *rty_ChargeVoltageLt = rtb_VoltLimit;
      }
      break;
    }
  }

  /* DataTypeConversion: '<Root>/DoubleConv' */
  tmp_0 = (real_T)*rtu_VtAvgmax * 0.001;

  /* Chart: '<Root>/Charge Profile' incorporates:
   *  DataTypeConversion: '<Root>/DoubleConv'
   */
  if (tmp_0 >= CAL_CC_END_THRSH) {
    localDW->durationCounter_1++;
  } else {
    localDW->durationCounter_1 = 0U;
  }

  if (tmp_0 >= CAL_CV_END_THRSH) {
    localDW->durationCounter_1_i++;
  } else {
    localDW->durationCounter_1_i = 0U;
  }

  /* Chart: '<Root>/BMS NM Msg' */
  localDW->Ign_prev = localDW->Ign_start;
  localDW->Ign_start = *rtu_Hardwired_Ign;
  if (localDW->is_active_c1_NBMS_CCCV == 0) {
    localDW->Ign_prev = *rtu_Hardwired_Ign;
    localDW->is_active_c1_NBMS_CCCV = 1U;
    localDW->is_c1_NBMS_CCCV = NBMS_CCCV_IN_SLEEP;
    *rty_BMS_NM_Msg = SLEEP;
  } else if (localDW->is_c1_NBMS_CCCV == NBMS_CCCV_IN_ACTIVE) {
    *rty_BMS_NM_Msg = ACTIVE;
    if (*rtu_Hardwired_Ign || (*rtu_OBC_HVIL_input && !*rtu_OBC_Heartbeat_fail &&
         (*rtu_mi_OBC_wakeup == Wake_Up) && (*rty_Chg_Mode_Req !=
          Charge_Complete)) || *rtu_RTC_Wakeup) {
      localDW->durationCounter_1_c = 0U;
    }

    if (localDW->durationCounter_1_c >= (uint32_T)(CAL_NM_MSG_Sleep_timer * 10))
    {
      localDW->is_c1_NBMS_CCCV = NBMS_CCCV_IN_SLEEP;
      *rty_BMS_NM_Msg = SLEEP;
    }
  } else {
    /* case IN_SLEEP: */
    *rty_BMS_NM_Msg = SLEEP;
    if (((localDW->Ign_prev != localDW->Ign_start) && localDW->Ign_start) ||
        (*rtu_OBC_HVIL_input && (*rtu_mi_OBC_wakeup == Wake_Up)) ||
        *rtu_RTC_Wakeup) {
      localDW->durationCounter_1_c = 0U;
      localDW->is_c1_NBMS_CCCV = NBMS_CCCV_IN_ACTIVE;
      *rty_BMS_NM_Msg = ACTIVE;
    }
  }

  if (!*rtu_Hardwired_Ign && (!*rtu_OBC_HVIL_input || *rtu_OBC_Heartbeat_fail ||
       (*rtu_mi_OBC_wakeup != Wake_Up) || (*rty_Chg_Mode_Req == Charge_Complete))
      && !*rtu_RTC_Wakeup) {
    localDW->durationCounter_1_c++;
  } else {
    localDW->durationCounter_1_c = 0U;
  }

  /* End of Chart: '<Root>/BMS NM Msg' */

  /* Switch: '<Root>/selChargeCurrLt' incorporates:
   *  Constant: '<Root>/ZeroCCL'
   *  Logic: '<Root>/ChkIfFaultIsPresent'
   *  Switch: '<Root>/selCCL'
   */
  if (*rtu_G4_Charge_Fault || *rtu_G4_Common_Fault || *rtu_G3_Common_Fault) {
    *rty_ChargeCurrentLt = 0.0;
  } else if (*rtu_Chrg_Derate) {
    /* Switch: '<Root>/selCCL' incorporates:
     *  Constant: '<Root>/MaxDerateCCL'
     *  MinMax: '<Root>/FindMinCCL'
     */
    *rty_ChargeCurrentLt = fmin(5.0, localB->ChargeCurrentLimit);
  } else {
    /* Switch: '<Root>/selCCL' */
    *rty_ChargeCurrentLt = localB->ChargeCurrentLimit;
  }

  /* End of Switch: '<Root>/selChargeCurrLt' */
}

/* Model initialize function */
void NBMS_CCCV_initialize(const char_T **rt_errorStatus, RT_MODEL_NBMS_CCCV_T *
  const NBMS_CCCV_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(NBMS_CCCV_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
