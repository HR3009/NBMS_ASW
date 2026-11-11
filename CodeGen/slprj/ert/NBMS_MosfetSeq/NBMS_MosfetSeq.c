/*
 * File: NBMS_MosfetSeq.c
 *
 * Code generated for Simulink model 'NBMS_MosfetSeq'.
 *
 * Model version                  : 7.42
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 11 09:32:09 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "NBMS_MosfetSeq.h"
#include "rtwtypes.h"
#include "NBMS_MosfetSeq_types.h"
#include <math.h>
#include "NBMS_MosfetSeq_private.h"
#include "DID.h"

/* Named constants for Chart: '<Root>/Mosfet Control SM' */
#define NBMS_Mos_IN_CloseDCDCMosfetIgOn ((uint8_T)2U)
#define NBMS_Mos_IN_OpenDCDCMosfetIgOff ((uint8_T)5U)
#define NBMS_Mosfe_IN_ClosePrechgMosfet ((uint8_T)4U)
#define NBMS_Mosfe_IN_G4Typ1DischgFault ((uint8_T)4U)
#define NBMS_Mosfe_IN_G4Typ2DischgFault ((uint8_T)5U)
#define NBMS_Mosfe_IN_PrechgVoltFailure ((uint8_T)8U)
#define NBMS_MosfetS_IN_CheckPrechgVolt ((uint8_T)1U)
#define NBMS_MosfetS_IN_CloseDCDCMosfet ((uint8_T)2U)
#define NBMS_MosfetS_IN_Mosfet_Sequence ((uint8_T)2U)
#define NBMS_MosfetS_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define NBMS_MosfetSe_IN_OpenDCDCMosfet ((uint8_T)2U)
#define NBMS_MosfetSe_IN_OpenHVMosfet_n ((uint8_T)3U)
#define NBMS_MosfetSe_IN_Positiveclosed ((uint8_T)7U)
#define NBMS_MosfetSeq_IN_BMS_Sleep    ((uint8_T)1U)
#define NBMS_MosfetSeq_IN_CLOSING_SEQ  ((uint8_T)1U)
#define NBMS_MosfetSeq_IN_CloseDCDC    ((uint8_T)1U)
#define NBMS_MosfetSeq_IN_CloseHVMosfet ((uint8_T)3U)
#define NBMS_MosfetSeq_IN_DEF          ((uint8_T)1U)
#define NBMS_MosfetSeq_IN_DEFAULT      ((uint8_T)1U)
#define NBMS_MosfetSeq_IN_Def          ((uint8_T)1U)
#define NBMS_MosfetSeq_IN_G4ChargeFault ((uint8_T)2U)
#define NBMS_MosfetSeq_IN_G4CommonFault ((uint8_T)3U)
#define NBMS_MosfetSeq_IN_No_Action    ((uint8_T)6U)
#define NBMS_MosfetSeq_IN_OpenDCDC     ((uint8_T)2U)
#define NBMS_MosfetSeq_IN_OpenHVMosfet ((uint8_T)2U)
#define NBMS_MosfetSeq_IN_STANDBY      ((uint8_T)7U)
#define NBMS_Mosfet_IN_CLOSING_SEQ_CHRG ((uint8_T)2U)
#define NBMS_Mosfet_IN_OnFaultDetection ((uint8_T)2U)
#define NBMS_Mosfet_IN_OpenDCDCMosfet_p ((uint8_T)5U)
#define NBMS_Mosfet_IN_OpenPrechgMosfet ((uint8_T)6U)

/* Forward declaration for local functions */
static void NBMS_Mosf_exit_internal_DEFAULT(DW_NBMS_MosfetSeq_f_T *localDW);
static void NBMS_MosfetSe_G4Typ1DischgFault(const boolean_T
  *rtu_mi_Hardwired_Ign, const BMS_MODE_E *rtu_sm_bmsmode, const
  Active_DisChrg_E *rtu_AppIn_ActiveDischg, const boolean_T
  *rtu_G4T2_Discharge_Fault, boolean_T *rty_Prechg_Mosfet_cmd, boolean_T
  *rty_HV_Mosfet_cmd, boolean_T *rty_DCDC_Mosfet_cmd, BMS_PMosfet_STS_E
  *rty_Prechg_Mosfet, BMS_HVMosfet_STS_E *rty_HV_Mosfet, BMS_DCDCMosfet_STS_E
  *rty_DCDC_Mosfet, boolean_T *rty_ASC_Prep_flg, DW_NBMS_MosfetSeq_f_T *localDW);
static void NBMS_MosfetSeq_No_Action(const boolean_T *rtu_mi_Hardwired_Ign,
  const BMS_MODE_E *rtu_sm_bmsmode, const boolean_T *rtu_mi_OBC_HVIL, const
  OBC_E *rtu_mi_OBC_wakeup, boolean_T *rty_HV_Mosfet_cmd, boolean_T
  *rty_DCDC_Mosfet_cmd, BMS_DCDCMosfet_STS_E *rty_DCDC_Mosfet,
  DW_NBMS_MosfetSeq_f_T *localDW);
static void NBMS_MosfetSeq_DEFAULT(const real_T *constMosfetFB, const boolean_T *
  rtu_mi_Hardwired_Ign, const BMS_MODE_E *rtu_sm_bmsmode, const boolean_T
  *rtu_mi_OBC_HVIL, const OBC_E *rtu_mi_OBC_wakeup, const Active_DisChrg_E
  *rtu_AppIn_ActiveDischg, const boolean_T *rtu_AppIn_HVMosfetfb, const
  boolean_T *rtu_G4T2_Discharge_Fault, boolean_T *rty_Prechg_Mosfet_cmd,
  boolean_T *rty_HV_Mosfet_cmd, boolean_T *rty_DCDC_Mosfet_cmd,
  BMS_PMosfet_STS_E *rty_Prechg_Mosfet, BMS_HVMosfet_STS_E *rty_HV_Mosfet,
  BMS_DCDCMosfet_STS_E *rty_DCDC_Mosfet, boolean_T *rty_ASC_Prep_flg, boolean_T *
  rty_Chrgr_Prep_Flag, boolean_T *rty_Prechg_Volt_Flt, DW_NBMS_MosfetSeq_f_T
  *localDW);
static void N_exit_internal_Mosfet_Sequence(DW_NBMS_MosfetSeq_f_T *localDW);
static void NBMS_MosfetSeq_CLOSING_SEQ_CHRG(const real_T *constMosfetFB, const
  boolean_T *rtu_mi_Hardwired_Ign, const BMS_MODE_E *rtu_sm_bmsmode, const
  real_T *rtu_AppIn_LoadVolt, const real_T *rtu_AppIn_PackVolt, const boolean_T *
  rtu_AppIn_PMosfetfb, const boolean_T *rtu_AppIn_HVMosfetfb, const boolean_T
  *rtu_AppIn_DCDCMosfetfb, boolean_T *rty_Prechg_Mosfet_cmd, boolean_T
  *rty_HV_Mosfet_cmd, boolean_T *rty_DCDC_Mosfet_cmd, BMS_PMosfet_STS_E
  *rty_Prechg_Mosfet, BMS_HVMosfet_STS_E *rty_HV_Mosfet, BMS_DCDCMosfet_STS_E
  *rty_DCDC_Mosfet, boolean_T *rty_Prechg_Volt_Flt, DW_NBMS_MosfetSeq_f_T
  *localDW);
static void NBMS_MosfetSeq_Mosfet_Sequence(const real_T *constMosfetFB, const
  boolean_T *rtu_mi_Hardwired_Ign, const BMS_MODE_E *rtu_sm_bmsmode, const
  real_T *rtu_AppIn_LoadVolt, const real_T *rtu_AppIn_PackVolt, const boolean_T *
  rtu_mi_OBC_HVIL, const OBC_E *rtu_mi_OBC_wakeup, const Active_DisChrg_E
  *rtu_AppIn_ActiveDischg, const boolean_T *rtu_AppIn_PMosfetfb, const boolean_T
  *rtu_AppIn_HVMosfetfb, const boolean_T *rtu_AppIn_DCDCMosfetfb, const
  boolean_T *rtu_G4_Common_Fault, const boolean_T *rtu_G4_Charge_Fault, const
  boolean_T *rtu_G4T2_Discharge_Fault, const boolean_T *rtu_G4T1_Discharge_Fault,
  boolean_T *rty_Prechg_Mosfet_cmd, boolean_T *rty_HV_Mosfet_cmd, boolean_T
  *rty_DCDC_Mosfet_cmd, BMS_PMosfet_STS_E *rty_Prechg_Mosfet, BMS_HVMosfet_STS_E
  *rty_HV_Mosfet, BMS_DCDCMosfet_STS_E *rty_DCDC_Mosfet, boolean_T
  *rty_ASC_Prep_flg, boolean_T *rty_Chrgr_Prep_Flag, boolean_T
  *rty_Prechg_Volt_Flt, DW_NBMS_MosfetSeq_f_T *localDW);

/* Function for Chart: '<Root>/Mosfet Control SM' */
static void NBMS_Mosf_exit_internal_DEFAULT(DW_NBMS_MosfetSeq_f_T *localDW)
{
  localDW->is_OnFaultDetection = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_G4ChargeFault = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_OnFaultDetection_g = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_G4CommonFault = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_OnFaultDetection_i = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_G4Typ1DischgFault = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_OnFaultDetection_j = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_G4Typ2DischgFault = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_No_Action = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_STANDBY = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_DEFAULT = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<Root>/Mosfet Control SM' */
static void NBMS_MosfetSe_G4Typ1DischgFault(const boolean_T
  *rtu_mi_Hardwired_Ign, const BMS_MODE_E *rtu_sm_bmsmode, const
  Active_DisChrg_E *rtu_AppIn_ActiveDischg, const boolean_T
  *rtu_G4T2_Discharge_Fault, boolean_T *rty_Prechg_Mosfet_cmd, boolean_T
  *rty_HV_Mosfet_cmd, boolean_T *rty_DCDC_Mosfet_cmd, BMS_PMosfet_STS_E
  *rty_Prechg_Mosfet, BMS_HVMosfet_STS_E *rty_HV_Mosfet, BMS_DCDCMosfet_STS_E
  *rty_DCDC_Mosfet, boolean_T *rty_ASC_Prep_flg, DW_NBMS_MosfetSeq_f_T *localDW)
{
  if (*rtu_G4T2_Discharge_Fault) {
    *rty_ASC_Prep_flg = true;
    localDW->is_OnFaultDetection_i = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
    localDW->is_G4Typ1DischgFault = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
    localDW->is_DEFAULT = NBMS_Mosfe_IN_G4Typ2DischgFault;
    localDW->is_G4Typ2DischgFault = NBMS_Mosfet_IN_OnFaultDetection;
    localDW->is_OnFaultDetection_j = NBMS_MosfetSeq_IN_Def;
    localDW->count2 = 0.0;
  } else {
    switch (localDW->is_G4Typ1DischgFault) {
     case NBMS_MosfetSeq_IN_BMS_Sleep:
      break;

     default:
      /* case IN_OnFaultDetection: */
      if (((*rtu_sm_bmsmode == BMS_FAULT) && !*rtu_mi_Hardwired_Ign &&
           (*rtu_AppIn_ActiveDischg == Completed)) || (*rtu_sm_bmsmode ==
           BMS_SLEEP)) {
        localDW->is_OnFaultDetection_i = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
        localDW->is_G4Typ1DischgFault = NBMS_MosfetSeq_IN_BMS_Sleep;
        *rty_Prechg_Mosfet = PDISCONNECTED;
        *rty_HV_Mosfet = HV_DISCONNECTED;
        *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
        *rty_Prechg_Mosfet_cmd = false;
        *rty_HV_Mosfet_cmd = false;
        *rty_DCDC_Mosfet_cmd = false;
      } else if (localDW->is_OnFaultDetection_i == NBMS_MosfetSeq_IN_Def) {
        if (localDW->count >= CAL_MOSFET_DISENG_THRSH) {
          localDW->NA = false;
          *rty_ASC_Prep_flg = false;
          localDW->is_OnFaultDetection_i = NBMS_MosfetSeq_IN_OpenHVMosfet;
          *rty_Prechg_Mosfet = PDISCONNECTED;
          *rty_HV_Mosfet = HV_DISCONNECTED;
          *rty_Prechg_Mosfet_cmd = false;
          *rty_HV_Mosfet_cmd = false;
        } else {
          localDW->count += 100.0;
        }
      } else {
        /* case IN_OpenHVMosfet: */
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/Mosfet Control SM' */
static void NBMS_MosfetSeq_No_Action(const boolean_T *rtu_mi_Hardwired_Ign,
  const BMS_MODE_E *rtu_sm_bmsmode, const boolean_T *rtu_mi_OBC_HVIL, const
  OBC_E *rtu_mi_OBC_wakeup, boolean_T *rty_HV_Mosfet_cmd, boolean_T
  *rty_DCDC_Mosfet_cmd, BMS_DCDCMosfet_STS_E *rty_DCDC_Mosfet,
  DW_NBMS_MosfetSeq_f_T *localDW)
{
  if ((*rtu_sm_bmsmode == BMS_STANDBY) && (!*rtu_mi_Hardwired_Ign ||
       *rtu_mi_OBC_HVIL || (*rtu_mi_OBC_wakeup != Wake_Up))) {
    localDW->is_No_Action = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
    localDW->is_DEFAULT = NBMS_MosfetSeq_IN_STANDBY;
    localDW->NA = false;
    localDW->durationCounter_1 = 0U;
    localDW->is_STANDBY = NBMS_MosfetSeq_IN_DEFAULT;
    *rty_HV_Mosfet_cmd = false;
  } else {
    localDW->NA = true;
    if (localDW->is_No_Action == NBMS_MosfetSeq_IN_CloseDCDC) {
      if ((*rtu_sm_bmsmode == BMS_CHARGE) && !*rtu_mi_Hardwired_Ign) {
        localDW->is_No_Action = NBMS_MosfetSeq_IN_OpenDCDC;
        *rty_DCDC_Mosfet_cmd = false;
        *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
      } else {
        *rty_DCDC_Mosfet_cmd = true;
        *rty_DCDC_Mosfet = DCDC_CONNECTED;
      }

      /* case IN_OpenDCDC: */
    } else if (*rtu_mi_Hardwired_Ign) {
      localDW->is_No_Action = NBMS_MosfetSeq_IN_CloseDCDC;
      *rty_DCDC_Mosfet_cmd = true;
      *rty_DCDC_Mosfet = DCDC_CONNECTED;
    } else {
      *rty_DCDC_Mosfet_cmd = false;
      *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
    }
  }
}

/* Function for Chart: '<Root>/Mosfet Control SM' */
static void NBMS_MosfetSeq_DEFAULT(const real_T *constMosfetFB, const boolean_T *
  rtu_mi_Hardwired_Ign, const BMS_MODE_E *rtu_sm_bmsmode, const boolean_T
  *rtu_mi_OBC_HVIL, const OBC_E *rtu_mi_OBC_wakeup, const Active_DisChrg_E
  *rtu_AppIn_ActiveDischg, const boolean_T *rtu_AppIn_HVMosfetfb, const
  boolean_T *rtu_G4T2_Discharge_Fault, boolean_T *rty_Prechg_Mosfet_cmd,
  boolean_T *rty_HV_Mosfet_cmd, boolean_T *rty_DCDC_Mosfet_cmd,
  BMS_PMosfet_STS_E *rty_Prechg_Mosfet, BMS_HVMosfet_STS_E *rty_HV_Mosfet,
  BMS_DCDCMosfet_STS_E *rty_DCDC_Mosfet, boolean_T *rty_ASC_Prep_flg, boolean_T *
  rty_Chrgr_Prep_Flag, boolean_T *rty_Prechg_Volt_Flt, DW_NBMS_MosfetSeq_f_T
  *localDW)
{
  boolean_T tmp;
  tmp = !localDW->NA;

  /* Chart: '<Root>/Mosfet Control SM' */
  if (*rtu_mi_Hardwired_Ign && ((*rtu_sm_bmsmode == BMS_DISCHARGE) ||
       (*rtu_sm_bmsmode == BMS_CHARGE)) && tmp) {
    NBMS_Mosf_exit_internal_DEFAULT(localDW);
    localDW->durationCounter_1_b = 0U;
    localDW->is_c3_NBMS_MosfetSeq = NBMS_MosfetS_IN_Mosfet_Sequence;
    localDW->is_Mosfet_Sequence = NBMS_MosfetSeq_IN_CLOSING_SEQ;
    localDW->durationCounter_1_i = 0U;
    localDW->is_CLOSING_SEQ = NBMS_Mosfe_IN_ClosePrechgMosfet;
    *rty_Prechg_Mosfet_cmd = true;
  } else if (!*rtu_mi_Hardwired_Ign && (*rtu_sm_bmsmode == BMS_CHARGE) && tmp) {
    NBMS_Mosf_exit_internal_DEFAULT(localDW);
    localDW->durationCounter_1_b = 0U;
    localDW->is_c3_NBMS_MosfetSeq = NBMS_MosfetS_IN_Mosfet_Sequence;
    localDW->is_Mosfet_Sequence = NBMS_Mosfet_IN_CLOSING_SEQ_CHRG;
    localDW->durationCounter_1_d = 0U;
    localDW->is_CLOSING_SEQ_CHRG = NBMS_Mosfe_IN_ClosePrechgMosfet;
    *rty_Prechg_Mosfet_cmd = true;
  } else {
    switch (localDW->is_DEFAULT) {
     case NBMS_MosfetSeq_IN_DEF:
      break;

     case NBMS_MosfetSeq_IN_G4ChargeFault:
      switch (localDW->is_G4ChargeFault) {
       case NBMS_MosfetSeq_IN_BMS_Sleep:
        break;

       default:
        /* case IN_OnFaultDetection: */
        if (((*rtu_sm_bmsmode == BMS_FAULT) && !*rtu_mi_Hardwired_Ign &&
             (*rtu_AppIn_ActiveDischg == Completed)) || (*rtu_sm_bmsmode ==
             BMS_SLEEP)) {
          localDW->is_OnFaultDetection = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
          localDW->is_G4ChargeFault = NBMS_MosfetSeq_IN_BMS_Sleep;
          *rty_Prechg_Mosfet = PDISCONNECTED;
          *rty_HV_Mosfet = HV_DISCONNECTED;
          *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
          *rty_Prechg_Mosfet_cmd = false;
          *rty_HV_Mosfet_cmd = false;
          *rty_DCDC_Mosfet_cmd = false;
        } else if (localDW->is_OnFaultDetection == NBMS_MosfetSeq_IN_Def) {
          if (localDW->count3 >= CAL_MOSFET_DISENG_THRSH) {
            localDW->NA = false;
            *rty_Chrgr_Prep_Flag = false;
            localDW->is_OnFaultDetection = NBMS_MosfetSeq_IN_OpenHVMosfet;
            *rty_Prechg_Mosfet = PDISCONNECTED;
            *rty_HV_Mosfet = HV_DISCONNECTED;
            *rty_Prechg_Mosfet_cmd = false;
            *rty_HV_Mosfet_cmd = false;
          } else {
            localDW->count3 += 100.0;
          }
        } else {
          /* case IN_OpenHVMosfet: */
        }
        break;
      }
      break;

     case NBMS_MosfetSeq_IN_G4CommonFault:
      if (localDW->is_G4CommonFault == NBMS_MosfetSeq_IN_BMS_Sleep) {
        *rty_Prechg_Volt_Flt = false;

        /* case IN_OnFaultDetection: */
      } else if (((*rtu_sm_bmsmode == BMS_FAULT) && !*rtu_mi_Hardwired_Ign &&
                  (*rtu_AppIn_ActiveDischg == Completed)) || (*rtu_sm_bmsmode ==
                  BMS_SLEEP)) {
        localDW->is_OnFaultDetection_g = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
        localDW->is_G4CommonFault = NBMS_MosfetSeq_IN_BMS_Sleep;
        *rty_Prechg_Mosfet = PDISCONNECTED;
        *rty_HV_Mosfet = HV_DISCONNECTED;
        *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
        *rty_Prechg_Mosfet_cmd = false;
        *rty_HV_Mosfet_cmd = false;
        *rty_DCDC_Mosfet_cmd = false;
        *rty_Prechg_Volt_Flt = false;
      } else if (localDW->is_OnFaultDetection_g == NBMS_MosfetSeq_IN_Def) {
        if (localDW->count1 >= CAL_MOSFET_DISENG_THRSH) {
          localDW->NA = false;
          *rty_Chrgr_Prep_Flag = false;
          *rty_ASC_Prep_flg = false;
          localDW->is_OnFaultDetection_g = NBMS_MosfetSeq_IN_OpenHVMosfet;
          *rty_Prechg_Mosfet = PDISCONNECTED;
          *rty_HV_Mosfet = HV_DISCONNECTED;
          *rty_Prechg_Mosfet_cmd = false;
          *rty_HV_Mosfet_cmd = false;
          *rty_Prechg_Volt_Flt = false;
        } else {
          localDW->count1 += 100.0;
        }
      } else {
        /* case IN_OpenHVMosfet: */
        *rty_Prechg_Volt_Flt = false;
      }
      break;

     case NBMS_Mosfe_IN_G4Typ1DischgFault:
      NBMS_MosfetSe_G4Typ1DischgFault(rtu_mi_Hardwired_Ign, rtu_sm_bmsmode,
        rtu_AppIn_ActiveDischg, rtu_G4T2_Discharge_Fault, rty_Prechg_Mosfet_cmd,
        rty_HV_Mosfet_cmd, rty_DCDC_Mosfet_cmd, rty_Prechg_Mosfet, rty_HV_Mosfet,
        rty_DCDC_Mosfet, rty_ASC_Prep_flg, localDW);
      break;

     case NBMS_Mosfe_IN_G4Typ2DischgFault:
      switch (localDW->is_G4Typ2DischgFault) {
       case NBMS_MosfetSeq_IN_BMS_Sleep:
        break;

       default:
        /* case IN_OnFaultDetection: */
        if (((*rtu_sm_bmsmode == BMS_FAULT) && !*rtu_mi_Hardwired_Ign &&
             (*rtu_AppIn_ActiveDischg == Completed)) || (*rtu_sm_bmsmode ==
             BMS_SLEEP)) {
          localDW->is_OnFaultDetection_j = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
          localDW->is_G4Typ2DischgFault = NBMS_MosfetSeq_IN_BMS_Sleep;
          *rty_Prechg_Mosfet = PDISCONNECTED;
          *rty_HV_Mosfet = HV_DISCONNECTED;
          *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
          *rty_Prechg_Mosfet_cmd = false;
          *rty_HV_Mosfet_cmd = false;
          *rty_DCDC_Mosfet_cmd = false;
        } else if (localDW->is_OnFaultDetection_j == NBMS_MosfetSeq_IN_Def) {
          if (localDW->count2 >= CAL_MOSFET_DISENG_THRSH) {
            localDW->NA = false;
            *rty_ASC_Prep_flg = false;
            localDW->is_OnFaultDetection_j = NBMS_MosfetSeq_IN_OpenHVMosfet;
            *rty_Prechg_Mosfet = PDISCONNECTED;
            *rty_HV_Mosfet = HV_DISCONNECTED;
            *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
            *rty_Prechg_Mosfet_cmd = false;
            *rty_HV_Mosfet_cmd = false;
            *rty_DCDC_Mosfet_cmd = false;
          } else {
            localDW->count2 += 100.0;
          }
        } else {
          /* case IN_OpenHVMosfet: */
        }
        break;
      }
      break;

     case NBMS_MosfetSeq_IN_No_Action:
      NBMS_MosfetSeq_No_Action(rtu_mi_Hardwired_Ign, rtu_sm_bmsmode,
        rtu_mi_OBC_HVIL, rtu_mi_OBC_wakeup, rty_HV_Mosfet_cmd,
        rty_DCDC_Mosfet_cmd, rty_DCDC_Mosfet, localDW);
      break;

     default:
      /* case IN_STANDBY: */
      switch (localDW->is_STANDBY) {
       case NBMS_MosfetSeq_IN_DEFAULT:
        if (*rtu_AppIn_HVMosfetfb) {
          localDW->durationCounter_1 = 0U;
        }

        if (localDW->durationCounter_1 >= (uint32_T)ceil(*constMosfetFB * 10.0))
        {
          localDW->is_STANDBY = NBMS_MosfetSe_IN_OpenHVMosfet_n;
          *rty_HV_Mosfet = HV_DISCONNECTED;
        } else {
          *rty_HV_Mosfet_cmd = false;
        }
        break;

       case NBMS_MosfetSe_IN_OpenDCDCMosfet:
        break;

       default:
        /* case IN_OpenHVMosfet: */
        if ((*rtu_AppIn_ActiveDischg == Completed) || (*rtu_sm_bmsmode ==
             BMS_SLEEP)) {
          localDW->is_STANDBY = NBMS_MosfetSe_IN_OpenDCDCMosfet;
          *rty_DCDC_Mosfet_cmd = false;
          *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
        } else {
          *rty_HV_Mosfet = HV_DISCONNECTED;
        }
        break;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Mosfet Control SM' */
}

/* Function for Chart: '<Root>/Mosfet Control SM' */
static void N_exit_internal_Mosfet_Sequence(DW_NBMS_MosfetSeq_f_T *localDW)
{
  localDW->is_OpenDCDCMosfetIgOff = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_CLOSING_SEQ = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_CloseDCDCMosfetIgOn = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_CLOSING_SEQ_CHRG = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
  localDW->is_Mosfet_Sequence = NBMS_MosfetS_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<Root>/Mosfet Control SM' */
static void NBMS_MosfetSeq_CLOSING_SEQ_CHRG(const real_T *constMosfetFB, const
  boolean_T *rtu_mi_Hardwired_Ign, const BMS_MODE_E *rtu_sm_bmsmode, const
  real_T *rtu_AppIn_LoadVolt, const real_T *rtu_AppIn_PackVolt, const boolean_T *
  rtu_AppIn_PMosfetfb, const boolean_T *rtu_AppIn_HVMosfetfb, const boolean_T
  *rtu_AppIn_DCDCMosfetfb, boolean_T *rty_Prechg_Mosfet_cmd, boolean_T
  *rty_HV_Mosfet_cmd, boolean_T *rty_DCDC_Mosfet_cmd, BMS_PMosfet_STS_E
  *rty_Prechg_Mosfet, BMS_HVMosfet_STS_E *rty_HV_Mosfet, BMS_DCDCMosfet_STS_E
  *rty_DCDC_Mosfet, boolean_T *rty_Prechg_Volt_Flt, DW_NBMS_MosfetSeq_f_T
  *localDW)
{
  real_T tmp;
  switch (localDW->is_CLOSING_SEQ_CHRG) {
   case NBMS_MosfetS_IN_CheckPrechgVolt:
    tmp = *rtu_AppIn_LoadVolt / *rtu_AppIn_PackVolt;
    if (tmp >= 0.95) {
      localDW->durationCounter_1_n = 0U;
      localDW->is_CLOSING_SEQ_CHRG = NBMS_MosfetSeq_IN_CloseHVMosfet;
      *rty_HV_Mosfet_cmd = true;
    } else if ((tmp < 0.95) && ((uint32_T)((int32_T)localDW->temporalCounter_i1 *
      100) >= (uint32_T)ceil(MosfetTime))) {
      localDW->is_CLOSING_SEQ_CHRG = NBMS_Mosfe_IN_PrechgVoltFailure;
      *rty_Prechg_Volt_Flt = true;
      *rty_Prechg_Mosfet = PMOSFET_FAULT;
      *rty_Prechg_Mosfet_cmd = false;
    }
    break;

   case NBMS_Mos_IN_CloseDCDCMosfetIgOn:
    if (localDW->is_CloseDCDCMosfetIgOn == NBMS_MosfetSeq_IN_CloseDCDC) {
      if (!*rtu_mi_Hardwired_Ign) {
        localDW->is_CloseDCDCMosfetIgOn = NBMS_MosfetSeq_IN_OpenDCDC;
        *rty_DCDC_Mosfet_cmd = false;
        *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
      } else {
        *rty_DCDC_Mosfet_cmd = true;
        *rty_DCDC_Mosfet = DCDC_CONNECTED;
      }

      /* case IN_OpenDCDC: */
    } else if (*rtu_mi_Hardwired_Ign) {
      localDW->is_CloseDCDCMosfetIgOn = NBMS_MosfetSeq_IN_CloseDCDC;
      *rty_DCDC_Mosfet_cmd = true;
      *rty_DCDC_Mosfet = DCDC_CONNECTED;
    } else {
      *rty_DCDC_Mosfet_cmd = false;
      *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
    }
    break;

   case NBMS_MosfetSeq_IN_CloseHVMosfet:
    if (!*rtu_AppIn_HVMosfetfb) {
      localDW->durationCounter_1_n = 0U;
    }

    if (localDW->durationCounter_1_n >= (uint32_T)ceil(*constMosfetFB * 10.0)) {
      *rty_HV_Mosfet = HV_CONNECT_PENDING;
      localDW->durationCounter_1_k = 0U;
      localDW->is_CLOSING_SEQ_CHRG = NBMS_Mosfet_IN_OpenDCDCMosfet_p;
      *rty_DCDC_Mosfet_cmd = false;
    } else {
      *rty_HV_Mosfet_cmd = true;
    }
    break;

   case NBMS_Mosfe_IN_ClosePrechgMosfet:
    if (!*rtu_AppIn_PMosfetfb) {
      localDW->durationCounter_1_d = 0U;
    }

    if (localDW->durationCounter_1_d >= (uint32_T)ceil(*constMosfetFB * 10.0)) {
      *rty_Prechg_Mosfet = PCONNECTED;
      localDW->temporalCounter_i1 = 0U;
      localDW->is_CLOSING_SEQ_CHRG = NBMS_MosfetS_IN_CheckPrechgVolt;
    } else {
      *rty_Prechg_Mosfet_cmd = true;
    }
    break;

   case NBMS_Mosfet_IN_OpenDCDCMosfet_p:
    if (*rtu_AppIn_DCDCMosfetfb) {
      localDW->durationCounter_1_k = 0U;
    }

    if (localDW->durationCounter_1_k >= (uint32_T)ceil(*constMosfetFB * 10.0)) {
      *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
      localDW->durationCounter_1_k4 = 0U;
      localDW->is_CLOSING_SEQ_CHRG = NBMS_Mosfet_IN_OpenPrechgMosfet;
      *rty_Prechg_Mosfet_cmd = false;
    } else {
      *rty_DCDC_Mosfet_cmd = false;
    }
    break;

   case NBMS_Mosfet_IN_OpenPrechgMosfet:
    if (*rtu_AppIn_PMosfetfb) {
      localDW->durationCounter_1_k4 = 0U;
    }

    if (localDW->durationCounter_1_k4 >= (uint32_T)ceil(*constMosfetFB * 10.0))
    {
      *rty_Prechg_Mosfet = PDISCONNECTED;
      localDW->is_CLOSING_SEQ_CHRG = NBMS_MosfetSe_IN_Positiveclosed;
      *rty_HV_Mosfet = HV_CONNECTED;
    } else {
      *rty_Prechg_Mosfet_cmd = false;
    }
    break;

   case NBMS_MosfetSe_IN_Positiveclosed:
    if ((*rtu_sm_bmsmode == BMS_CHARGE) && *rtu_mi_Hardwired_Ign) {
      localDW->is_CLOSING_SEQ_CHRG = NBMS_Mos_IN_CloseDCDCMosfetIgOn;
      localDW->is_CloseDCDCMosfetIgOn = NBMS_MosfetSeq_IN_CloseDCDC;
      *rty_DCDC_Mosfet_cmd = true;
      *rty_DCDC_Mosfet = DCDC_CONNECTED;
    } else {
      *rty_HV_Mosfet = HV_CONNECTED;
    }
    break;

   default:
    /* case IN_PrechgVoltFailure: */
    *rty_Prechg_Volt_Flt = true;
    break;
  }
}

/* Function for Chart: '<Root>/Mosfet Control SM' */
static void NBMS_MosfetSeq_Mosfet_Sequence(const real_T *constMosfetFB, const
  boolean_T *rtu_mi_Hardwired_Ign, const BMS_MODE_E *rtu_sm_bmsmode, const
  real_T *rtu_AppIn_LoadVolt, const real_T *rtu_AppIn_PackVolt, const boolean_T *
  rtu_mi_OBC_HVIL, const OBC_E *rtu_mi_OBC_wakeup, const Active_DisChrg_E
  *rtu_AppIn_ActiveDischg, const boolean_T *rtu_AppIn_PMosfetfb, const boolean_T
  *rtu_AppIn_HVMosfetfb, const boolean_T *rtu_AppIn_DCDCMosfetfb, const
  boolean_T *rtu_G4_Common_Fault, const boolean_T *rtu_G4_Charge_Fault, const
  boolean_T *rtu_G4T2_Discharge_Fault, const boolean_T *rtu_G4T1_Discharge_Fault,
  boolean_T *rty_Prechg_Mosfet_cmd, boolean_T *rty_HV_Mosfet_cmd, boolean_T
  *rty_DCDC_Mosfet_cmd, BMS_PMosfet_STS_E *rty_Prechg_Mosfet, BMS_HVMosfet_STS_E
  *rty_HV_Mosfet, BMS_DCDCMosfet_STS_E *rty_DCDC_Mosfet, boolean_T
  *rty_ASC_Prep_flg, boolean_T *rty_Chrgr_Prep_Flag, boolean_T
  *rty_Prechg_Volt_Flt, DW_NBMS_MosfetSeq_f_T *localDW)
{
  real_T tmp;

  /* Chart: '<Root>/Mosfet Control SM' */
  if (*rtu_sm_bmsmode != BMS_STANDBY) {
    localDW->durationCounter_1_b = 0U;
  }

  if ((localDW->durationCounter_1_b >= 2U) && (!*rtu_mi_Hardwired_Ign ||
       *rtu_mi_OBC_HVIL || (*rtu_mi_OBC_wakeup != Wake_Up))) {
    N_exit_internal_Mosfet_Sequence(localDW);
    localDW->is_c3_NBMS_MosfetSeq = NBMS_MosfetSeq_IN_DEFAULT;
    localDW->is_DEFAULT = NBMS_MosfetSeq_IN_STANDBY;
    localDW->NA = false;
    localDW->durationCounter_1 = 0U;
    localDW->is_STANDBY = NBMS_MosfetSeq_IN_DEFAULT;

    /* Chart: '<Root>/Mosfet Control SM' */
    *rty_HV_Mosfet_cmd = false;

    /* Chart: '<Root>/Mosfet Control SM' */
  } else if ((*rty_HV_Mosfet == HV_CONNECTED) && (*rty_DCDC_Mosfet ==
              DCDC_CONNECTED) && (((localDW->sm_BMSMODE_prev !=
                localDW->sm_BMSMODE_start) && (localDW->sm_BMSMODE_start ==
                BMS_DISCHARGE)) || ((localDW->sm_BMSMODE_prev !=
                localDW->sm_BMSMODE_start) && (localDW->sm_BMSMODE_start ==
                BMS_CHARGE)))) {
    N_exit_internal_Mosfet_Sequence(localDW);
    localDW->is_c3_NBMS_MosfetSeq = NBMS_MosfetSeq_IN_DEFAULT;
    localDW->is_DEFAULT = NBMS_MosfetSeq_IN_No_Action;
    localDW->NA = true;
    localDW->is_No_Action = NBMS_MosfetSeq_IN_CloseDCDC;
    *rty_DCDC_Mosfet_cmd = true;
    *rty_DCDC_Mosfet = DCDC_CONNECTED;
  } else if (*rtu_G4_Charge_Fault) {
    *rty_Chrgr_Prep_Flag = true;
    N_exit_internal_Mosfet_Sequence(localDW);
    localDW->is_c3_NBMS_MosfetSeq = NBMS_MosfetSeq_IN_DEFAULT;
    localDW->is_DEFAULT = NBMS_MosfetSeq_IN_G4ChargeFault;
    localDW->is_G4ChargeFault = NBMS_Mosfet_IN_OnFaultDetection;
    localDW->is_OnFaultDetection = NBMS_MosfetSeq_IN_Def;
    localDW->count3 = 0.0;
  } else if (*rtu_G4T1_Discharge_Fault) {
    *rty_ASC_Prep_flg = true;
    N_exit_internal_Mosfet_Sequence(localDW);
    localDW->is_c3_NBMS_MosfetSeq = NBMS_MosfetSeq_IN_DEFAULT;
    localDW->is_DEFAULT = NBMS_Mosfe_IN_G4Typ1DischgFault;
    localDW->is_G4Typ1DischgFault = NBMS_Mosfet_IN_OnFaultDetection;
    localDW->is_OnFaultDetection_i = NBMS_MosfetSeq_IN_Def;
    localDW->count = 0.0;
  } else if (*rtu_G4T2_Discharge_Fault) {
    *rty_ASC_Prep_flg = true;
    N_exit_internal_Mosfet_Sequence(localDW);
    localDW->is_c3_NBMS_MosfetSeq = NBMS_MosfetSeq_IN_DEFAULT;
    localDW->is_DEFAULT = NBMS_Mosfe_IN_G4Typ2DischgFault;
    localDW->is_G4Typ2DischgFault = NBMS_Mosfet_IN_OnFaultDetection;
    localDW->is_OnFaultDetection_j = NBMS_MosfetSeq_IN_Def;
    localDW->count2 = 0.0;
  } else if (*rtu_G4_Common_Fault || (*rty_Prechg_Mosfet == PMOSFET_FAULT)) {
    *rty_ASC_Prep_flg = true;
    *rty_Chrgr_Prep_Flag = true;
    N_exit_internal_Mosfet_Sequence(localDW);
    localDW->is_c3_NBMS_MosfetSeq = NBMS_MosfetSeq_IN_DEFAULT;
    localDW->is_DEFAULT = NBMS_MosfetSeq_IN_G4CommonFault;
    localDW->is_G4CommonFault = NBMS_Mosfet_IN_OnFaultDetection;
    localDW->is_OnFaultDetection_g = NBMS_MosfetSeq_IN_Def;
    localDW->count1 = 0.0;
  } else if (localDW->is_Mosfet_Sequence == NBMS_MosfetSeq_IN_CLOSING_SEQ) {
    switch (localDW->is_CLOSING_SEQ) {
     case NBMS_MosfetS_IN_CheckPrechgVolt:
      tmp = *rtu_AppIn_LoadVolt / *rtu_AppIn_PackVolt;
      if (tmp >= 0.95) {
        localDW->durationCounter_1_h = 0U;
        localDW->is_CLOSING_SEQ = NBMS_MosfetSeq_IN_CloseHVMosfet;
        *rty_HV_Mosfet_cmd = true;
      } else if ((tmp < 0.95) && ((uint32_T)((int32_T)
                   localDW->temporalCounter_i1 * 100) >= (uint32_T)ceil
                  (MosfetTime))) {
        localDW->is_CLOSING_SEQ = NBMS_Mosfe_IN_PrechgVoltFailure;
        *rty_Prechg_Volt_Flt = true;
        *rty_Prechg_Mosfet = PMOSFET_FAULT;
        *rty_Prechg_Mosfet_cmd = false;
      }
      break;

     case NBMS_MosfetS_IN_CloseDCDCMosfet:
      if (!*rtu_AppIn_DCDCMosfetfb) {
        localDW->durationCounter_1_l = 0U;
      }

      if (localDW->durationCounter_1_l >= (uint32_T)ceil(*constMosfetFB * 10.0))
      {
        *rty_DCDC_Mosfet = DCDC_CONNECTED;
        localDW->durationCounter_1_lu = 0U;
        localDW->is_CLOSING_SEQ = NBMS_Mosfet_IN_OpenPrechgMosfet;
        *rty_Prechg_Mosfet_cmd = false;
      } else {
        *rty_DCDC_Mosfet_cmd = true;
      }
      break;

     case NBMS_MosfetSeq_IN_CloseHVMosfet:
      if (!*rtu_AppIn_HVMosfetfb) {
        localDW->durationCounter_1_h = 0U;
      }

      if (localDW->durationCounter_1_h >= (uint32_T)ceil(*constMosfetFB * 10.0))
      {
        *rty_HV_Mosfet = HV_CONNECT_PENDING;
        localDW->durationCounter_1_l = 0U;
        localDW->is_CLOSING_SEQ = NBMS_MosfetS_IN_CloseDCDCMosfet;
        *rty_DCDC_Mosfet_cmd = true;
      } else {
        *rty_HV_Mosfet_cmd = true;
      }
      break;

     case NBMS_Mosfe_IN_ClosePrechgMosfet:
      if (!*rtu_AppIn_PMosfetfb) {
        localDW->durationCounter_1_i = 0U;
      }

      if (localDW->durationCounter_1_i >= (uint32_T)ceil(*constMosfetFB * 10.0))
      {
        *rty_Prechg_Mosfet = PCONNECTED;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_CLOSING_SEQ = NBMS_MosfetS_IN_CheckPrechgVolt;
      } else {
        *rty_Prechg_Mosfet_cmd = true;
      }
      break;

     case NBMS_Mos_IN_OpenDCDCMosfetIgOff:
      if (localDW->is_OpenDCDCMosfetIgOff == NBMS_MosfetSeq_IN_CloseDCDC) {
        if (!*rtu_mi_Hardwired_Ign) {
          localDW->is_OpenDCDCMosfetIgOff = NBMS_MosfetSeq_IN_OpenDCDC;
          *rty_DCDC_Mosfet_cmd = false;
          *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
        } else {
          *rty_DCDC_Mosfet_cmd = true;
          *rty_DCDC_Mosfet = DCDC_CONNECTED;
        }

        /* case IN_OpenDCDC: */
      } else if (*rtu_mi_Hardwired_Ign) {
        localDW->is_OpenDCDCMosfetIgOff = NBMS_MosfetSeq_IN_CloseDCDC;
        *rty_DCDC_Mosfet_cmd = true;
        *rty_DCDC_Mosfet = DCDC_CONNECTED;
      } else {
        *rty_DCDC_Mosfet_cmd = false;
        *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
      }
      break;

     case NBMS_Mosfet_IN_OpenPrechgMosfet:
      if (*rtu_AppIn_PMosfetfb) {
        localDW->durationCounter_1_lu = 0U;
      }

      if (localDW->durationCounter_1_lu >= (uint32_T)ceil(*constMosfetFB * 10.0))
      {
        *rty_Prechg_Mosfet = PDISCONNECTED;
        localDW->is_CLOSING_SEQ = NBMS_MosfetSe_IN_Positiveclosed;
        *rty_HV_Mosfet = HV_CONNECTED;
      } else {
        *rty_Prechg_Mosfet_cmd = false;
      }
      break;

     case NBMS_MosfetSe_IN_Positiveclosed:
      if ((*rtu_sm_bmsmode == BMS_CHARGE) && !*rtu_mi_Hardwired_Ign &&
          (*rtu_AppIn_ActiveDischg == Completed)) {
        localDW->is_CLOSING_SEQ = NBMS_Mos_IN_OpenDCDCMosfetIgOff;
        localDW->is_OpenDCDCMosfetIgOff = NBMS_MosfetSeq_IN_OpenDCDC;
        *rty_DCDC_Mosfet_cmd = false;
        *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
      } else {
        *rty_HV_Mosfet = HV_CONNECTED;
      }
      break;

     default:
      /* case IN_PrechgVoltFailure: */
      *rty_Prechg_Volt_Flt = true;
      break;
    }
  } else {
    /* case IN_CLOSING_SEQ_CHRG: */
    NBMS_MosfetSeq_CLOSING_SEQ_CHRG(constMosfetFB, rtu_mi_Hardwired_Ign,
      rtu_sm_bmsmode, rtu_AppIn_LoadVolt, rtu_AppIn_PackVolt,
      rtu_AppIn_PMosfetfb, rtu_AppIn_HVMosfetfb, rtu_AppIn_DCDCMosfetfb,
      rty_Prechg_Mosfet_cmd, rty_HV_Mosfet_cmd, rty_DCDC_Mosfet_cmd,
      rty_Prechg_Mosfet, rty_HV_Mosfet, rty_DCDC_Mosfet, rty_Prechg_Volt_Flt,
      localDW);
  }
}

/* Output and update for referenced model: 'NBMS_MosfetSeq' */
void NBMS_MosfetSeq(const boolean_T *rtu_mi_Hardwired_Ign, const BMS_MODE_E
                    *rtu_sm_bmsmode, const real_T *rtu_AppIn_LoadVolt, const
                    real_T *rtu_AppIn_PackVolt, const boolean_T *rtu_mi_OBC_HVIL,
                    const OBC_E *rtu_mi_OBC_wakeup, const Active_DisChrg_E
                    *rtu_AppIn_ActiveDischg, const boolean_T
                    *rtu_AppIn_PMosfetfb, const boolean_T *rtu_AppIn_HVMosfetfb,
                    const boolean_T *rtu_AppIn_DCDCMosfetfb, const boolean_T
                    *rtu_G4_Common_Fault, const boolean_T *rtu_G4_Charge_Fault,
                    const boolean_T *rtu_G4T2_Discharge_Fault, const boolean_T
                    *rtu_G4T1_Discharge_Fault, boolean_T *rty_Prechg_Mosfet_cmd,
                    boolean_T *rty_HV_Mosfet_cmd, boolean_T *rty_DCDC_Mosfet_cmd,
                    BMS_PMosfet_STS_E *rty_Prechg_Mosfet, BMS_HVMosfet_STS_E
                    *rty_HV_Mosfet, BMS_DCDCMosfet_STS_E *rty_DCDC_Mosfet,
                    boolean_T *rty_ASC_Prep_flg, boolean_T *rty_Chrgr_Prep_Flag,
                    boolean_T *rty_Prechg_Volt_Flt, DW_NBMS_MosfetSeq_f_T
                    *localDW)
{
  real_T constMosfetFB;
  boolean_T tmp;

  /* Gain: '<Root>/gainMosfetFb' incorporates:
   *  Constant: '<Root>/calMosfetFB'
   */
  constMosfetFB = 0.0009999871253967285 * (real_T)CAL_MOSFET_FEEDBACK;

  /* Chart: '<Root>/Mosfet Control SM' */
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  localDW->sm_BMSMODE_prev = localDW->sm_BMSMODE_start;
  localDW->sm_BMSMODE_start = *rtu_sm_bmsmode;
  if (localDW->is_active_c3_NBMS_MosfetSeq == 0) {
    localDW->sm_BMSMODE_prev = *rtu_sm_bmsmode;
    localDW->is_active_c3_NBMS_MosfetSeq = 1U;
    localDW->is_c3_NBMS_MosfetSeq = NBMS_MosfetSeq_IN_DEFAULT;
    *rty_Prechg_Mosfet_cmd = false;
    *rty_HV_Mosfet_cmd = false;
    *rty_DCDC_Mosfet_cmd = false;
    *rty_Prechg_Mosfet = PDISCONNECTED;
    *rty_HV_Mosfet = HV_DISCONNECTED;
    *rty_DCDC_Mosfet = DCDC_DISCONNECTED;
    *rty_ASC_Prep_flg = false;
    localDW->NA = false;
    localDW->is_DEFAULT = NBMS_MosfetSeq_IN_DEF;
  } else if (localDW->is_c3_NBMS_MosfetSeq == NBMS_MosfetSeq_IN_DEFAULT) {
    NBMS_MosfetSeq_DEFAULT(&constMosfetFB, rtu_mi_Hardwired_Ign, rtu_sm_bmsmode,
      rtu_mi_OBC_HVIL, rtu_mi_OBC_wakeup, rtu_AppIn_ActiveDischg,
      rtu_AppIn_HVMosfetfb, rtu_G4T2_Discharge_Fault, rty_Prechg_Mosfet_cmd,
      rty_HV_Mosfet_cmd, rty_DCDC_Mosfet_cmd, rty_Prechg_Mosfet, rty_HV_Mosfet,
      rty_DCDC_Mosfet, rty_ASC_Prep_flg, rty_Chrgr_Prep_Flag,
      rty_Prechg_Volt_Flt, localDW);
  } else {
    /* case IN_Mosfet_Sequence: */
    NBMS_MosfetSeq_Mosfet_Sequence(&constMosfetFB, rtu_mi_Hardwired_Ign,
      rtu_sm_bmsmode, rtu_AppIn_LoadVolt, rtu_AppIn_PackVolt, rtu_mi_OBC_HVIL,
      rtu_mi_OBC_wakeup, rtu_AppIn_ActiveDischg, rtu_AppIn_PMosfetfb,
      rtu_AppIn_HVMosfetfb, rtu_AppIn_DCDCMosfetfb, rtu_G4_Common_Fault,
      rtu_G4_Charge_Fault, rtu_G4T2_Discharge_Fault, rtu_G4T1_Discharge_Fault,
      rty_Prechg_Mosfet_cmd, rty_HV_Mosfet_cmd, rty_DCDC_Mosfet_cmd,
      rty_Prechg_Mosfet, rty_HV_Mosfet, rty_DCDC_Mosfet, rty_ASC_Prep_flg,
      rty_Chrgr_Prep_Flag, rty_Prechg_Volt_Flt, localDW);
  }

  if (!*rtu_AppIn_HVMosfetfb) {
    localDW->durationCounter_1++;
  } else {
    localDW->durationCounter_1 = 0U;
  }

  if (*rtu_AppIn_PMosfetfb) {
    localDW->durationCounter_1_i++;
  } else {
    localDW->durationCounter_1_i = 0U;
  }

  if (*rtu_AppIn_HVMosfetfb) {
    localDW->durationCounter_1_h++;
  } else {
    localDW->durationCounter_1_h = 0U;
  }

  if (*rtu_AppIn_DCDCMosfetfb) {
    localDW->durationCounter_1_l++;
  } else {
    localDW->durationCounter_1_l = 0U;
  }

  tmp = !*rtu_AppIn_PMosfetfb;
  if (tmp) {
    localDW->durationCounter_1_lu++;
    localDW->durationCounter_1_d = 0U;
  } else {
    localDW->durationCounter_1_lu = 0U;
    localDW->durationCounter_1_d++;
  }

  if (*rtu_AppIn_HVMosfetfb) {
    localDW->durationCounter_1_n++;
  } else {
    localDW->durationCounter_1_n = 0U;
  }

  if (!*rtu_AppIn_DCDCMosfetfb) {
    localDW->durationCounter_1_k++;
  } else {
    localDW->durationCounter_1_k = 0U;
  }

  if (tmp) {
    localDW->durationCounter_1_k4++;
  } else {
    localDW->durationCounter_1_k4 = 0U;
  }

  if (*rtu_sm_bmsmode == BMS_STANDBY) {
    localDW->durationCounter_1_b++;
  } else {
    localDW->durationCounter_1_b = 0U;
  }

  /* End of Chart: '<Root>/Mosfet Control SM' */
}

/* Model initialize function */
void NBMS_MosfetSeq_initialize(const char_T **rt_errorStatus,
  RT_MODEL_NBMS_MosfetSeq_T *const NBMS_MosfetSeq_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(NBMS_MosfetSeq_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
