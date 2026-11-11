/*
 * File: NBMS_SoC.c
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

#include "NBMS_SoC.h"
#include "rtwtypes.h"
#include "NBMS_SoC_types.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "NBMS_SoC_private.h"
#include "div_nzp_repeat_s32_floor.h"
#include "look2_binlcpw.h"
#include "look1_binlxpw.h"
#include "DID.h"
#include "zero_crossing_types.h"
#include "NBMS_DischargeOCV.h"
#include "NBMS_ChargeOCV.h"

/* Named constants for Chart: '<S51>/StateWaitCondition' */
#define NBMS_SoC_IN_In                 ((uint8_T)1U)
#define NBMS_SoC_IN_Out                ((uint8_T)2U)

/* Named constants for Chart: '<S5>/InitialSocManager' */
#define NBMS_SoC_IN_IgnOff             ((uint8_T)1U)
#define NBMS_SoC_IN_StoreInitialSOC    ((uint8_T)2U)

/* Named constants for Chart: '<S36>/SocStateController' */
#define NBMS_SoC_IN_entry              ((uint8_T)1U)
#define NBMS_SoC_IN_entry1             ((uint8_T)2U)
#define NBMS_SoC_IN_entry2             ((uint8_T)3U)
#define NBMS_SoC_IN_entry3             ((uint8_T)4U)

/* Named constants for Chart: '<S81>/SOC_Init_Decision' */
#define NBMS_SoC_IN_Charge             ((uint8_T)1U)
#define NBMS_SoC_IN_Default            ((uint8_T)2U)
#define NBMS_SoC_IN_Discharge          ((uint8_T)3U)

/*
 * Output and update for enable system:
 *    '<S83>/Moving Average'
 *    '<S83>/Moving Average1'
 *    '<S83>/Moving Average10'
 *    '<S83>/Moving Average11'
 *    '<S83>/Moving Average12'
 *    '<S83>/Moving Average13'
 *    '<S83>/Moving Average14'
 *    '<S83>/Moving Average15'
 *    '<S83>/Moving Average16'
 *    '<S83>/Moving Average17'
 *    ...
 */
void NBMS_SoC_MovingAverage(boolean_T rtu_EnableCellVoltValid, int16_T rtu_In,
  int16_T *rty_Out, DW_MovingAverage_NBMS_SoC_T *localDW)
{
  int_T i;

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average' incorporates:
   *  EnablePort: '<S125>/EnableCellVoltValid'
   */
  if (rtu_EnableCellVoltValid) {
    real_T tmp;

    /* Sum: '<S125>/Counter' incorporates:
     *  Constant: '<S125>/CountStep'
     *  UnitDelay: '<S125>/Delayfor1Unit'
     */
    tmp = floor(localDW->Delayfor1Unit_DSTATE);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    if (tmp < 0.0) {
      i = (uint8_T)-(int8_T)(uint8_T)-tmp;
    } else {
      i = (uint8_T)tmp;
    }

    localDW->Delayfor1Unit_DSTATE = (uint8_T)((uint32_T)i + 1U);

    /* End of Sum: '<S125>/Counter' */

    /* Switch: '<S125>/Counterfor20' incorporates:
     *  Constant: '<S125>/ZeroVt'
     *  Product: '<S125>/Average'
     *  Sum: '<S125>/SumofVoltage'
     *  Sum: '<S125>/TotalSum'
     *  UnitDelay: '<S125>/Delayfor1Unit'
     */
    if (localDW->Delayfor1Unit_DSTATE > 20.0) {
      int32_T y;

      /* Sum: '<S125>/SumofVoltage' incorporates:
       *  S-Function (sfix_udelay): '<S125>/20Delay'
       */
      y = 0;
      for (i = 0; i < 20; i++) {
        y += localDW->u0Delay_DWORK1[i];
      }

      *rty_Out = (int16_T)(((int16_T)div_nzp_repeat_s32_floor(y + rtu_In, 2625,
        6U) * 125) >> 6);
    } else {
      *rty_Out = 0;
    }

    /* End of Switch: '<S125>/Counterfor20' */

    /* Update for S-Function (sfix_udelay): '<S125>/20Delay' */
    for (i = 0; i < 19; i++) {
      localDW->u0Delay_DWORK1[19 - i] = localDW->u0Delay_DWORK1[18 - i];
    }

    localDW->u0Delay_DWORK1[0] = rtu_In;

    /* End of Update for S-Function (sfix_udelay): '<S125>/20Delay' */
  }

  /* End of Outputs for SubSystem: '<S83>/Moving Average' */
}

/* System initialize for referenced model: 'NBMS_SoC' */
void NBMS_SoC_Init(boolean_T *rty_LOW_SOC, real_T *rty_FailSensorVolt, int16_T
                   *rty_FailSensorVoltAvg, B_NBMS_SoC_c_T *localB,
                   DW_NBMS_SoC_f_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S1>/udlyPackSoC' */
  localDW->udlyPackSoC_DSTATE = 1.0;

  /* InitializeConditions for Switch: '<S32>/selSoHsource' incorporates:
   *  UnitDelay: '<S1>/udlySoH'
   */
  localDW->udlySoH_DSTATE = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/DischargeAccumulator' */
  localDW->DischargeAccumulator_PrevResetS = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/CalcCurrAccum' */
  localDW->CalcCurrAccum_PrevResetState = 2;

  /* InitializeConditions for UnitDelay: '<S33>/ZeroReset' */
  localDW->ZeroReset_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S33>/uDlySoC' */
  localDW->uDlySoC_DSTATE = 100U;

  /* InitializeConditions for UnitDelay: '<S33>/udlyDSoC' */
  localDW->udlyDSoC_DSTATE = 100U;

  /* InitializeConditions for UnitDelay: '<S10>/udlySoH' */
  localDW->udlySoH_DSTATE_k = 100U;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Accumulate BattCurrent' */
  localDW->AccumulateBattCurrent_PrevReset = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S32>/CoulombCounter' */
  localDW->CoulombCounter_PrevResetState = 2;

  /* SystemInitialize for Enabled SubSystem: '<S33>/LatchBattSoc' */
  /* InitializeConditions for UnitDelay: '<S52>/udlyBattSoC' */
  localDW->udlyBattSoC_DSTATE = 100.0;

  /* End of SystemInitialize for SubSystem: '<S33>/LatchBattSoc' */

  /* SystemInitialize for Enabled SubSystem: '<S10>/CalcChgMeasured' */
  /* InitializeConditions for DiscreteIntegrator: '<S15>/CalcAccumulatedBattCurr' */
  localDW->CalcAccumulatedBattCurr_PrevRes = 2;

  /* End of SystemInitialize for SubSystem: '<S10>/CalcChgMeasured' */

  /* SystemInitialize for SignalConversion generated from: '<Root>/LOW_SOC' */
  *rty_LOW_SOC = localB->Logic[0];

  /* SystemInitialize for Enabled SubSystem: '<S83>/OneSensorVoltFailure' */
  /* SystemInitialize for Outport: '<S145>/FailSensorVolt' */
  *rty_FailSensorVolt = 5.0;

  /* SystemInitialize for Outport: '<S145>/FailSensorVoltAvg' */
  *rty_FailSensorVoltAvg = 5000;

  /* End of SystemInitialize for SubSystem: '<S83>/OneSensorVoltFailure' */
}

/* Disable for referenced model: 'NBMS_SoC' */
void NBMS_SoC_Disable(boolean_T *rty_LOW_SOC_WARN_15, boolean_T *rty_LOW_SOC,
                      boolean_T *rty_LOW_SOC_WARN, real_T *rty_FailSensorVolt,
                      int16_T *rty_FailSensorVoltAvg, int16_T
                      *rty_BatteryCurrentAvg5sec, B_NBMS_SoC_c_T *localB,
                      DW_NBMS_SoC_f_T *localDW)
{
  /* Disable for ModelReference: '<S81>/InitialDichargeOCV' */
  NBMS_DischargeOCV_Disable(&localB->InitialDichargeOCV,
    &(localDW->InitialDichargeOCV_InstanceData.rtdw));

  /* Disable for ModelReference: '<S81>/InitialChargeOCV' */
  NBMS_ChargeOCV_Disable(&localB->InitialChargeOCV,
    &(localDW->InitialChargeOCV_InstanceData.rtdw));

  /* Disable for Enabled SubSystem: '<S82>/MovingAverageCurrent2sec' */
  if (localDW->MovingAverageCurrent2sec_MODE) {
    /* Disable for RelationalOperator: '<S99>/Compare' incorporates:
     *  Outport: '<S97>/EnableCurrentMA'
     */
    localB->Compare_b = false;

    /* Disable for Switch: '<S97>/Sample Accumulator ' incorporates:
     *  Outport: '<S97>/BatteryCurrent'
     */
    localB->usecAvgBatteryCurrent = 0;
    localDW->MovingAverageCurrent2sec_MODE = false;
  }

  /* End of Disable for SubSystem: '<S82>/MovingAverageCurrent2sec' */

  /* Disable for ModelReference: '<S81>/ChargeOCV' */
  NBMS_ChargeOCV_Disable(&localB->ChargeOCV,
    &(localDW->ChargeOCV_InstanceData.rtdw));

  /* Disable for ModelReference: '<S81>/DischargeOCV' */
  NBMS_DischargeOCV_Disable(&localB->DischargeOCV,
    &(localDW->DischargeOCV_InstanceData.rtdw));

  /* Disable for ModelReference: '<S5>/DischgOCV' */
  NBMS_DischargeOCV_Disable(&localB->DischgOCV,
    &(localDW->DischgOCV_InstanceData.rtdw));

  /* Disable for Enabled SubSystem: '<S1>/SOC Fault Detection' */
  if (localDW->SOCFaultDetection_MODE) {
    /* Disable for Outport: '<S6>/ LOW_SOC_WARN_15' */
    *rty_LOW_SOC_WARN_15 = false;

    /* Disable for Outport: '<S6>/ LOW_SOC' incorporates:
     *  CombinatorialLogic: '<S72>/Logic'
     */
    localB->Logic[0] = false;

    /* Disable for Outport: '<S6>/ LOW_SOC_WARN' */
    *rty_LOW_SOC_WARN = false;
    localDW->SOCFaultDetection_MODE = false;
  }

  /* End of Disable for SubSystem: '<S1>/SOC Fault Detection' */

  /* Disable for SignalConversion generated from: '<Root>/LOW_SOC' */
  *rty_LOW_SOC = localB->Logic[0];

  /* Disable for Enabled SubSystem: '<S82>/MovingAverageCurrent5sec' */
  if (localDW->MovingAverageCurrent5sec_MODE) {
    /* Disable for Outport: '<S98>/BatteryCurrent' */
    *rty_BatteryCurrentAvg5sec = 0;
    localDW->MovingAverageCurrent5sec_MODE = false;
  }

  /* End of Disable for SubSystem: '<S82>/MovingAverageCurrent5sec' */

  /* Disable for Enabled SubSystem: '<S83>/OneSensorVoltFailure' */
  if (localDW->OneSensorVoltFailure_MODE) {
    /* Disable for Outport: '<S145>/FailSensorVolt' */
    *rty_FailSensorVolt = 5.0;

    /* Disable for Outport: '<S145>/FailSensorVoltAvg' */
    *rty_FailSensorVoltAvg = 5000;
    localDW->OneSensorVoltFailure_MODE = false;
  }

  /* End of Disable for SubSystem: '<S83>/OneSensorVoltFailure' */
}

/* Output and update for referenced model: 'NBMS_SoC' */
void NBMS_SoC(const uint8_T *rtu_soc_full, const real_T rtu_Batt_Temps[6], const
              real_T *rtu_AppIn_BattCurrent, const real_T
              rtu_AppIn_BattVoltages[20], const boolean_T *rtu_Ignition, const
              Charger_Mode_Req_E *rtu_Charger_Mode_Req, const BMS_MODE_E
              *rtu_sm_BMSMODE_en, const real_T *rtu_AppIn_LastStoredSOC, const
              real_T *rtu_AppIn_LastStoredCycle, const boolean_T
              *rtu_AppIn_I2Cerror, const real_T *rtu_AppIn_LastStoredSOH, const
              OBC_E *rtu_OBCWakeup, const real_T *rtu_mi_Pack_Volt, const
              VEH_STT_LVL1_E *rtu_AppIn_VehL1, const real_T
              *rtu_DischrgCurrLimit, uint8_T *rty_Display_SOC, real_T
              *rty_Battery_Capacity, boolean_T *rty_LOW_SOC_WARN_15, boolean_T
              *rty_LOW_SOC, boolean_T *rty_LOW_SOC_WARN, real_T
              *rty_Batt_Pack_SOC, real_T *rty_LifeCycle, real_T *rty_SOH,
              int16_T *rty_VtAvgMax, real_T *rty_CurrentCapacity, uint16_T
              *rty_SOCcc, uint16_T *rty_SOCAvg, int16_T *rty_Vmin, real_T
              *rty_SOC_OCVInit, real_T *rty_SOCAvgInitial, real_T
              *rty_AvailableEnergy, int16_T *rty_VtAvgMin, real_T
              *rty_FailSensorVolt, int16_T *rty_FailSensorVoltAvg, int16_T
              *rty_BatteryCurrentAvg5sec, real_T *rty_ChargeCapacity,
              B_NBMS_SoC_c_T *localB, DW_NBMS_SoC_f_T *localDW, ZCE_NBMS_SoC_T
              *localZCE)
{
  real_T maxV;
  real_T rtb_InternalVoltageDrop_0;
  real_T rtb_ScaledGoldenDC_e;
  real_T rtb_SoCCoulombCounting;
  int32_T i;
  int32_T rtb_CountofNonZeroCell_0;
  int32_T y;
  uint32_T rowIdx;
  uint32_T rtb_Logic_idx_0_tmp;
  int16_T rtb_TmpSignalConversionAtSFunct[20];
  int16_T tmpForInput[20];
  int16_T rtb_OCVInitial;
  int16_T rtb_OpenCircuitVoltage;
  uint16_T rtb_InitialSoCAvg;
  uint16_T rtb_SOCAvgHystersis;
  uint16_T rtb_Uk1;
  uint8_T rtb_Init;
  boolean_T rtb_Compare_ei[20];
  boolean_T TriggerswhentheBMSModeisDischar;
  boolean_T rtb_ChgStarted;
  boolean_T rtb_Compare_c2;
  boolean_T rtb_Compare_cf;
  boolean_T rtb_Compare_il;
  boolean_T rtb_Compare_lv;
  boolean_T rtb_Compare_mx;
  boolean_T rtb_Compare_o1;
  boolean_T rtb_IntegratorReset;
  boolean_T rtb_IntegratorReset_tmp;
  boolean_T tmp;
  for (i = 0; i < 20; i++) {
    /* DataTypeConversion: '<S1>/ConvertToFixdt' */
    rtb_SoCCoulombCounting = floor(rtu_AppIn_BattVoltages[i] / 0.001);
    if (rtIsNaN(rtb_SoCCoulombCounting) || rtIsInf(rtb_SoCCoulombCounting)) {
      rtb_SoCCoulombCounting = 0.0;
    } else {
      rtb_SoCCoulombCounting = fmod(rtb_SoCCoulombCounting, 65536.0);
    }

    if (rtb_SoCCoulombCounting < 0.0) {
      /* DataTypeConversion: '<S1>/ConvertToFixdt' */
      rtb_OCVInitial = (int16_T)-(int16_T)(uint16_T)-rtb_SoCCoulombCounting;
    } else {
      /* DataTypeConversion: '<S1>/ConvertToFixdt' */
      rtb_OCVInitial = (int16_T)(uint16_T)rtb_SoCCoulombCounting;
    }

    /* End of DataTypeConversion: '<S1>/ConvertToFixdt' */

    /* DataTypeConversion: '<S1>/ConvertToFixdt' */
    localB->ConvBattVolt[i] = rtb_OCVInitial;

    /* RelationalOperator: '<S124>/Compare' incorporates:
     *  DataTypeConversion: '<S1>/ConvertToFixdt'
     */
    rtb_Compare_ei[i] = (rtb_OCVInitial != 0);
  }

  /* MinMax: '<S1>/CalcMaxTemp' */
  maxV = rtu_Batt_Temps[0];
  for (i = 0; i < 5; i++) {
    maxV = fmax(maxV, rtu_Batt_Temps[i + 1]);
  }

  /* Outputs for Triggered SubSystem: '<S81>/InitPackTemperature' incorporates:
   *  TriggerPort: '<S90>/Trigger'
   */
  if (*rtu_Ignition && (localZCE->InitPackTemperature_Trig_ZCE != POS_ZCSIG)) {
    /* SignalConversion generated from: '<S90>/Temp' incorporates:
     *  MinMax: '<S1>/CalcMaxTemp'
     */
    localB->InitialTemp = maxV;
  }

  localZCE->InitPackTemperature_Trig_ZCE = *rtu_Ignition;

  /* End of Outputs for SubSystem: '<S81>/InitPackTemperature' */

  /* Outputs for Triggered SubSystem: '<S1>/CalcOCV' incorporates:
   *  TriggerPort: '<S2>/Trigger'
   */
  if (*rtu_Ignition && (localZCE->CalcOCV_Trig_ZCE != POS_ZCSIG)) {
    /* Product: '<S2>/CalcSingleCellVolt' incorporates:
     *  Constant: '<S2>/TotalCellinSeries'
     */
    *rty_SOC_OCVInit = *rtu_mi_Pack_Volt / 20.0;
  }

  /* Outputs for Triggered SubSystem: '<S81>/InitPackTemperature' incorporates:
   *  TriggerPort: '<S90>/Trigger'
   */
  localZCE->CalcOCV_Trig_ZCE = *rtu_Ignition;

  /* End of Outputs for SubSystem: '<S81>/InitPackTemperature' */
  /* End of Outputs for SubSystem: '<S1>/CalcOCV' */

  /* DataTypeConversion: '<S1>/FixdtTypeConvert' */
  rtb_SoCCoulombCounting = floor(*rty_SOC_OCVInit / 0.001);
  if (rtIsNaN(rtb_SoCCoulombCounting) || rtIsInf(rtb_SoCCoulombCounting)) {
    rtb_SoCCoulombCounting = 0.0;
  } else {
    rtb_SoCCoulombCounting = fmod(rtb_SoCCoulombCounting, 65536.0);
  }

  if (rtb_SoCCoulombCounting < 0.0) {
    rtb_OCVInitial = (int16_T)-(int16_T)(uint16_T)-rtb_SoCCoulombCounting;
  } else {
    rtb_OCVInitial = (int16_T)(uint16_T)rtb_SoCCoulombCounting;
  }

  /* End of DataTypeConversion: '<S1>/FixdtTypeConvert' */

  /* Chart: '<S81>/SOC_Init_Decision' */
  if (localDW->is_active_c18_NBMS_SoC == 0) {
    localDW->is_active_c18_NBMS_SoC = 1U;
    localDW->is_SOC_Init = NBMS_SoC_IN_Default;
    rtb_Init = 0U;
  } else {
    switch (localDW->is_SOC_Init) {
     case NBMS_SoC_IN_Charge:
      rtb_Init = 1U;
      if (*rtu_sm_BMSMODE_en != BMS_CHARGE) {
        localDW->is_SOC_Init = NBMS_SoC_IN_Default;
        rtb_Init = 0U;
      }
      break;

     case NBMS_SoC_IN_Default:
      rtb_Init = 0U;
      switch (*rtu_sm_BMSMODE_en) {
       case BMS_CHARGE:
        localDW->is_SOC_Init = NBMS_SoC_IN_Charge;
        rtb_Init = 1U;
        break;

       case BMS_DISCHARGE:
        localDW->is_SOC_Init = NBMS_SoC_IN_Discharge;
        rtb_Init = 2U;
        break;
      }
      break;

     default:
      /* case IN_Discharge: */
      rtb_Init = 2U;
      if (!*rtu_Ignition) {
        localDW->is_SOC_Init = NBMS_SoC_IN_Default;
        rtb_Init = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S81>/SOC_Init_Decision' */

  /* RelationalOperator: '<S86>/Compare' incorporates:
   *  Constant: '<S86>/Constant'
   */
  localB->Compare = (rtb_Init == 2);

  /* ModelReference: '<S81>/InitialDichargeOCV' */
  NBMS_DischargeOCV(&localB->InitialTemp, &rtb_OCVInitial, &localB->Compare,
                    &localB->InitialDichargeOCV,
                    &(localDW->InitialDichargeOCV_InstanceData.rtdw));

  /* RelationalOperator: '<S85>/Compare' incorporates:
   *  Constant: '<S85>/Constant'
   */
  localB->Compare_k = (rtb_Init == 1);

  /* ModelReference: '<S81>/InitialChargeOCV' */
  NBMS_ChargeOCV(&localB->InitialTemp, &rtb_OCVInitial, &localB->Compare_k,
                 &localB->InitialChargeOCV,
                 &(localDW->InitialChargeOCV_InstanceData.rtdw));

  /* RelationalOperator: '<S95>/Compare' incorporates:
   *  Constant: '<S95>/Constant'
   */
  rtb_Compare_o1 = (*rtu_sm_BMSMODE_en != BMS_SLEEP);

  /* Outputs for Enabled SubSystem: '<S82>/MovingAverageCurrent2sec' incorporates:
   *  EnablePort: '<S97>/Enable'
   */
  if (rtb_Compare_o1) {
    if (!localDW->MovingAverageCurrent2sec_MODE) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S97>/20Delay' */
      for (i = 0; i < 20; i++) {
        localDW->u0Delay_DWORK1_p[i] = 0;
      }

      /* End of InitializeConditions for S-Function (sfix_udelay): '<S97>/20Delay' */

      /* InitializeConditions for UnitDelay: '<S97>/1UnitDelay' */
      localDW->uUnitDelay_DSTATE_f = 0U;
      localDW->MovingAverageCurrent2sec_MODE = true;
    }

    /* Switch: '<S82>/SelectBattCurrOutput' incorporates:
     *  Constant: '<S94>/Constant'
     *  Logic: '<S82>/ChkDischgValid'
     *  RelationalOperator: '<S82>/CheckCurrentWithinLimit'
     *  RelationalOperator: '<S94>/Compare'
     */
    if ((*rtu_AppIn_VehL1 == DRIVE) && (*rtu_AppIn_BattCurrent <=
         *rtu_DischrgCurrLimit)) {
      /* DataTypeConversion: '<S97>/ConvertToFixdt' */
      rtb_SoCCoulombCounting = floor(*rtu_DischrgCurrLimit / 0.01);
      if (rtIsNaN(rtb_SoCCoulombCounting) || rtIsInf(rtb_SoCCoulombCounting)) {
        rtb_SoCCoulombCounting = 0.0;
      } else {
        rtb_SoCCoulombCounting = fmod(rtb_SoCCoulombCounting, 65536.0);
      }

      if (rtb_SoCCoulombCounting < 0.0) {
        /* DataTypeConversion: '<S97>/ConvertToFixdt' */
        localB->u1stSample_d = (int16_T)-(int16_T)(uint16_T)
          -rtb_SoCCoulombCounting;
      } else {
        /* DataTypeConversion: '<S97>/ConvertToFixdt' */
        localB->u1stSample_d = (int16_T)(uint16_T)rtb_SoCCoulombCounting;
      }
    } else {
      /* DataTypeConversion: '<S97>/ConvertToFixdt' */
      rtb_SoCCoulombCounting = floor(*rtu_AppIn_BattCurrent / 0.01);
      if (rtIsNaN(rtb_SoCCoulombCounting) || rtIsInf(rtb_SoCCoulombCounting)) {
        rtb_SoCCoulombCounting = 0.0;
      } else {
        rtb_SoCCoulombCounting = fmod(rtb_SoCCoulombCounting, 65536.0);
      }

      if (rtb_SoCCoulombCounting < 0.0) {
        /* DataTypeConversion: '<S97>/ConvertToFixdt' */
        localB->u1stSample_d = (int16_T)-(int16_T)(uint16_T)
          -rtb_SoCCoulombCounting;
      } else {
        /* DataTypeConversion: '<S97>/ConvertToFixdt' */
        localB->u1stSample_d = (int16_T)(uint16_T)rtb_SoCCoulombCounting;
      }
    }

    /* End of Switch: '<S82>/SelectBattCurrOutput' */

    /* Sum: '<S97>/Counter' incorporates:
     *  Constant: '<S97>/CountStep'
     *  UnitDelay: '<S97>/1UnitDelay'
     */
    rowIdx = localDW->uUnitDelay_DSTATE_f + 1U;
    if (localDW->uUnitDelay_DSTATE_f + 1U > 255U) {
      rowIdx = 255U;
    }

    localDW->uUnitDelay_DSTATE_f = (uint8_T)rowIdx;

    /* End of Sum: '<S97>/Counter' */

    /* RelationalOperator: '<S99>/Compare' incorporates:
     *  Constant: '<S99>/Constant'
     *  UnitDelay: '<S97>/1UnitDelay'
     */
    localB->Compare_b = (localDW->uUnitDelay_DSTATE_f > 20);

    /* Switch: '<S97>/Sample Accumulator ' */
    if (localB->Compare_b) {
      /* Sum: '<S97>/SumofCurrent' incorporates:
       *  S-Function (sfix_udelay): '<S97>/20Delay'
       */
      y = 0;
      for (i = 0; i < 20; i++) {
        y += localDW->u0Delay_DWORK1_p[i];
      }

      /* Switch: '<S97>/Sample Accumulator ' incorporates:
       *  DataTypeConversion: '<S97>/ConvertToFixdt'
       *  Product: '<S97>/Average'
       *  Sum: '<S97>/Sumof21Samples'
       *  Sum: '<S97>/SumofCurrent'
       */
      localB->usecAvgBatteryCurrent = (int16_T)(((int16_T)
        div_nzp_repeat_s32_floor(y + localB->u1stSample_d, 525, 4U) * 25) >> 4);
    } else {
      /* Switch: '<S97>/Sample Accumulator ' incorporates:
       *  Constant: '<S97>/ConstZeroCurrent'
       */
      localB->usecAvgBatteryCurrent = 0;
    }

    /* End of Switch: '<S97>/Sample Accumulator ' */

    /* Update for S-Function (sfix_udelay): '<S97>/20Delay' incorporates:
     *  DataTypeConversion: '<S97>/ConvertToFixdt'
     */
    for (i = 0; i < 19; i++) {
      localDW->u0Delay_DWORK1_p[i] = localDW->u0Delay_DWORK1_p[i + 1];
    }

    localDW->u0Delay_DWORK1_p[19] = localB->u1stSample_d;

    /* End of Update for S-Function (sfix_udelay): '<S97>/20Delay' */
  } else if (localDW->MovingAverageCurrent2sec_MODE) {
    /* Disable for RelationalOperator: '<S99>/Compare' incorporates:
     *  Outport: '<S97>/EnableCurrentMA'
     */
    localB->Compare_b = false;

    /* Disable for Switch: '<S97>/Sample Accumulator ' incorporates:
     *  Outport: '<S97>/BatteryCurrent'
     */
    localB->usecAvgBatteryCurrent = 0;
    localDW->MovingAverageCurrent2sec_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S82>/MovingAverageCurrent2sec' */

  /* RelationalOperator: '<S38>/Compare' incorporates:
   *  Constant: '<S38>/Constant'
   */
  rtb_Compare_c2 = (*rtu_sm_BMSMODE_en != BMS_SLEEP);

  /* CombinatorialLogic: '<S50>/Logic' incorporates:
   *  CombinatorialLogic: '<S93>/Logic'
   *  Logic: '<S33>/StartSocCalcPermissive'
   *  Memory: '<S50>/Memory'
   *  RelationalOperator: '<S55>/Compare'
   */
  rtb_Logic_idx_0_tmp = (uint32_T)!*rtu_Ignition;

  /* Outputs for Enabled SubSystem: '<S33>/LatchBattSoc' incorporates:
   *  EnablePort: '<S52>/Enable'
   */
  localDW->Memory_PreviousInput = rtCP_Logic_table_o[((((uint32_T)
    (rtb_Compare_c2 && localB->Compare_b) << 1U) + rtb_Logic_idx_0_tmp) << 1U) +
    localDW->Memory_PreviousInput];

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average' */
  /* RelationalOperator: '<S101>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[0] != 0), localB->ConvBattVolt[0],
    &localB->AvgVoltofCell0, &localDW->MovingAverage);

  /* End of Outputs for SubSystem: '<S83>/Moving Average' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average1' */
  /* RelationalOperator: '<S102>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[1] != 0), localB->ConvBattVolt[1],
    &localB->AvgVoltofCell1, &localDW->MovingAverage1);

  /* End of Outputs for SubSystem: '<S83>/Moving Average1' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average2' */
  /* RelationalOperator: '<S113>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[2] != 0), localB->ConvBattVolt[2],
    &localB->AvgVoltofCell2, &localDW->MovingAverage2);

  /* End of Outputs for SubSystem: '<S83>/Moving Average2' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average3' */
  /* RelationalOperator: '<S114>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[3] != 0), localB->ConvBattVolt[3],
    &localB->AvgVoltofCell3, &localDW->MovingAverage3);

  /* End of Outputs for SubSystem: '<S83>/Moving Average3' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average4' */
  /* RelationalOperator: '<S115>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[4] != 0), localB->ConvBattVolt[4],
    &localB->AvgVoltofCell4, &localDW->MovingAverage4);

  /* End of Outputs for SubSystem: '<S83>/Moving Average4' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average5' */
  /* RelationalOperator: '<S116>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[5] != 0), localB->ConvBattVolt[5],
    &localB->AvgVoltofCell5, &localDW->MovingAverage5);

  /* End of Outputs for SubSystem: '<S83>/Moving Average5' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average6' */
  /* RelationalOperator: '<S117>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[6] != 0), localB->ConvBattVolt[6],
    &localB->AvgVoltofCell6, &localDW->MovingAverage6);

  /* End of Outputs for SubSystem: '<S83>/Moving Average6' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average7' */
  /* RelationalOperator: '<S118>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[7] != 0), localB->ConvBattVolt[7],
    &localB->AvgVoltofCell7, &localDW->MovingAverage7);

  /* End of Outputs for SubSystem: '<S83>/Moving Average7' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average8' */
  /* RelationalOperator: '<S119>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[8] != 0), localB->ConvBattVolt[8],
    &localB->AvgVoltofCell8, &localDW->MovingAverage8);

  /* End of Outputs for SubSystem: '<S83>/Moving Average8' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average9' */
  /* RelationalOperator: '<S120>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[9] != 0), localB->ConvBattVolt[9],
    &localB->AvgVoltofCell9, &localDW->MovingAverage9);

  /* End of Outputs for SubSystem: '<S83>/Moving Average9' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average10' */
  /* RelationalOperator: '<S103>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[10] != 0), localB->ConvBattVolt
    [10], &localB->AvgVoltofCell10, &localDW->MovingAverage10);

  /* End of Outputs for SubSystem: '<S83>/Moving Average10' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average11' */
  /* RelationalOperator: '<S104>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[11] != 0), localB->ConvBattVolt
    [11], &localB->AvgVoltofCell11, &localDW->MovingAverage11);

  /* End of Outputs for SubSystem: '<S83>/Moving Average11' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average12' */
  /* RelationalOperator: '<S105>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[12] != 0), localB->ConvBattVolt
    [12], &localB->AvgVoltofCell12, &localDW->MovingAverage12);

  /* End of Outputs for SubSystem: '<S83>/Moving Average12' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average13' */
  /* RelationalOperator: '<S106>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[13] != 0), localB->ConvBattVolt
    [13], &localB->AvgVoltofCell13, &localDW->MovingAverage13);

  /* End of Outputs for SubSystem: '<S83>/Moving Average13' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average14' */
  /* RelationalOperator: '<S107>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[14] != 0), localB->ConvBattVolt
    [14], &localB->AvgVoltofCell14, &localDW->MovingAverage14);

  /* End of Outputs for SubSystem: '<S83>/Moving Average14' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average15' */
  /* RelationalOperator: '<S108>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[15] != 0), localB->ConvBattVolt
    [15], &localB->AvgVoltofCell15, &localDW->MovingAverage15);

  /* End of Outputs for SubSystem: '<S83>/Moving Average15' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average16' */
  /* RelationalOperator: '<S109>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[16] != 0), localB->ConvBattVolt
    [16], &localB->AvgVoltofCell16, &localDW->MovingAverage16);

  /* End of Outputs for SubSystem: '<S83>/Moving Average16' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average17' */
  /* RelationalOperator: '<S110>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[17] != 0), localB->ConvBattVolt
    [17], &localB->AvgVoltofCell17, &localDW->MovingAverage17);

  /* End of Outputs for SubSystem: '<S83>/Moving Average17' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average18' */
  /* RelationalOperator: '<S111>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[18] != 0), localB->ConvBattVolt
    [18], &localB->AvgVoltofCell18, &localDW->MovingAverage18);

  /* End of Outputs for SubSystem: '<S83>/Moving Average18' */

  /* Outputs for Enabled SubSystem: '<S83>/Moving Average19' */
  /* RelationalOperator: '<S112>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[19] != 0), localB->ConvBattVolt
    [19], &localB->AvgVoltofCell19, &localDW->MovingAverage19);

  /* End of Outputs for SubSystem: '<S83>/Moving Average19' */

  /* Sum: '<S83>/SumofAvgVolt' */
  tmpForInput[0] = localB->AvgVoltofCell0;
  tmpForInput[1] = localB->AvgVoltofCell1;
  tmpForInput[2] = localB->AvgVoltofCell2;
  tmpForInput[3] = localB->AvgVoltofCell3;
  tmpForInput[4] = localB->AvgVoltofCell4;
  tmpForInput[5] = localB->AvgVoltofCell5;
  tmpForInput[6] = localB->AvgVoltofCell6;
  tmpForInput[7] = localB->AvgVoltofCell7;
  tmpForInput[8] = localB->AvgVoltofCell8;
  tmpForInput[9] = localB->AvgVoltofCell9;
  tmpForInput[10] = localB->AvgVoltofCell10;
  tmpForInput[11] = localB->AvgVoltofCell11;
  tmpForInput[12] = localB->AvgVoltofCell12;
  tmpForInput[13] = localB->AvgVoltofCell13;
  tmpForInput[14] = localB->AvgVoltofCell14;
  tmpForInput[15] = localB->AvgVoltofCell15;
  tmpForInput[16] = localB->AvgVoltofCell16;
  tmpForInput[17] = localB->AvgVoltofCell17;
  tmpForInput[18] = localB->AvgVoltofCell18;
  tmpForInput[19] = localB->AvgVoltofCell19;
  rtb_InternalVoltageDrop_0 = 0.0;

  /* Sum: '<S83>/CountofNonZeroCellVolt' */
  rtb_CountofNonZeroCell_0 = 0;
  for (i = 0; i < 20; i++) {
    /* Sum: '<S83>/SumofAvgVolt' */
    rtb_InternalVoltageDrop_0 += (real_T)tmpForInput[i] * 0.001;

    /* Sum: '<S83>/CountofNonZeroCellVolt' incorporates:
     *  RelationalOperator: '<S124>/Compare'
     */
    rtb_CountofNonZeroCell_0 += rtb_Compare_ei[i];
  }

  /* Product: '<S83>/Average' incorporates:
   *  Sum: '<S83>/CountofNonZeroCellVolt'
   *  Sum: '<S83>/SumofAvgVolt'
   */
  rtb_SoCCoulombCounting = floor(rtb_InternalVoltageDrop_0 / (real_T)
    rtb_CountofNonZeroCell_0 / 0.01);
  if (rtIsNaN(rtb_SoCCoulombCounting) || rtIsInf(rtb_SoCCoulombCounting)) {
    rtb_SoCCoulombCounting = 0.0;
  } else {
    rtb_SoCCoulombCounting = fmod(rtb_SoCCoulombCounting, 65536.0);
  }

  /* Switch: '<S82>/Switch' incorporates:
   *  Constant: '<S96>/Constant'
   *  Lookup_n-D: '<S82>/DCIRCharge'
   *  Lookup_n-D: '<S82>/DCIRdisCharge'
   *  MinMax: '<S1>/CalcMaxTemp'
   *  RelationalOperator: '<S96>/Compare'
   *  UnitDelay: '<S1>/udlyPackSoC'
   */
  if (*rtu_sm_BMSMODE_en == BMS_CHARGE) {
    rtb_ScaledGoldenDC_e = look2_binlcpw(maxV, localDW->udlyPackSoC_DSTATE,
      rtCP_DCIRCharge_bp01Data, rtCP_DCIRCharge_bp02Data,
      rtCP_DCIRCharge_tableData, rtCP_DCIRCharge_maxIndex, 7U);
  } else {
    rtb_ScaledGoldenDC_e = look2_binlcpw(maxV, localDW->udlyPackSoC_DSTATE,
      rtCP_DCIRdisCharge_bp01Data, rtCP_DCIRdisCharge_bp02Data,
      rtCP_DCIRdisCharge_tableData, rtCP_DCIRdisCharge_maxIndex, 7U);
  }

  /* End of Switch: '<S82>/Switch' */

  /* Sum: '<S81>/VoltDiff' incorporates:
   *  Constant: '<S82>/TotalCellsInParallel'
   *  Product: '<S82>/CalcOneCellCurrent'
   *  Product: '<S82>/CalcVoltage'
   *  Sum: '<S83>/MaxVoltDiff'
   *  Sum: '<S83>/MinVoltDiff'
   *  Switch: '<S97>/Sample Accumulator '
   */
  rtb_InternalVoltageDrop_0 = floor((real_T)localB->usecAvgBatteryCurrent * 0.01
    / 7.0 * rtb_ScaledGoldenDC_e / 0.001);
  tmp = (rtIsNaN(rtb_InternalVoltageDrop_0) || rtIsInf(rtb_InternalVoltageDrop_0));
  if (tmp) {
    rtb_ScaledGoldenDC_e = 0.0;
  } else {
    rtb_ScaledGoldenDC_e = fmod(rtb_InternalVoltageDrop_0, 65536.0);
  }

  /* Product: '<S83>/Average' */
  if (rtb_SoCCoulombCounting < 0.0) {
    i = (uint16_T)-(int16_T)(uint16_T)-rtb_SoCCoulombCounting;
  } else {
    i = (uint16_T)rtb_SoCCoulombCounting;
  }

  /* Sum: '<S81>/VoltDiff' incorporates:
   *  Product: '<S83>/Average'
   */
  if (rtb_ScaledGoldenDC_e < 0.0) {
    y = (int16_T)-(int16_T)(uint16_T)-rtb_ScaledGoldenDC_e;
  } else {
    y = (int16_T)(uint16_T)rtb_ScaledGoldenDC_e;
  }

  rtb_OpenCircuitVoltage = (int16_T)((int16_T)((uint32_T)i * 10U) - y);

  /* RelationalOperator: '<S91>/Compare' incorporates:
   *  Constant: '<S91>/Constant'
   */
  localB->Compare_h = (*rtu_sm_BMSMODE_en == BMS_CHARGE);

  /* ModelReference: '<S81>/ChargeOCV' incorporates:
   *  MinMax: '<S1>/CalcMaxTemp'
   */
  NBMS_ChargeOCV(&maxV, &rtb_OpenCircuitVoltage, &localB->Compare_h,
                 &localB->ChargeOCV, &(localDW->ChargeOCV_InstanceData.rtdw));

  /* RelationalOperator: '<S84>/Compare' incorporates:
   *  Constant: '<S84>/Constant'
   */
  rtb_Compare_il = (*rtu_sm_BMSMODE_en == BMS_CHARGE);

  /* Logic: '<S81>/logIsNotCharging' incorporates:
   *  Logic: '<S32>/ChkIsBMSModeNotCharge'
   */
  TriggerswhentheBMSModeisDischar = !rtb_Compare_il;

  /* Logic: '<S81>/logIsNotCharging' */
  localB->TriggerswhentheBMSModeisDischar = TriggerswhentheBMSModeisDischar;

  /* ModelReference: '<S81>/DischargeOCV' incorporates:
   *  MinMax: '<S1>/CalcMaxTemp'
   */
  NBMS_DischargeOCV(&maxV, &rtb_OpenCircuitVoltage,
                    &localB->TriggerswhentheBMSModeisDischar,
                    &localB->DischargeOCV,
                    &(localDW->DischargeOCV_InstanceData.rtdw));

  /* Switch: '<S81>/Switch1' */
  if (rtb_Compare_il) {
    rtb_SoCCoulombCounting = floor(localB->ChargeOCV / 0.01);
    if (rtIsNaN(rtb_SoCCoulombCounting) || rtIsInf(rtb_SoCCoulombCounting)) {
      rtb_SoCCoulombCounting = 0.0;
    } else {
      rtb_SoCCoulombCounting = fmod(rtb_SoCCoulombCounting, 65536.0);
    }

    if (rtb_SoCCoulombCounting < 0.0) {
      rtb_SOCAvgHystersis = (uint16_T)-(int16_T)(uint16_T)
        -rtb_SoCCoulombCounting;
    } else {
      rtb_SOCAvgHystersis = (uint16_T)rtb_SoCCoulombCounting;
    }
  } else {
    rtb_SoCCoulombCounting = floor(localB->DischargeOCV / 0.01);
    if (rtIsNaN(rtb_SoCCoulombCounting) || rtIsInf(rtb_SoCCoulombCounting)) {
      rtb_SoCCoulombCounting = 0.0;
    } else {
      rtb_SoCCoulombCounting = fmod(rtb_SoCCoulombCounting, 65536.0);
    }

    if (rtb_SoCCoulombCounting < 0.0) {
      rtb_SOCAvgHystersis = (uint16_T)-(int16_T)(uint16_T)
        -rtb_SoCCoulombCounting;
    } else {
      rtb_SOCAvgHystersis = (uint16_T)rtb_SoCCoulombCounting;
    }
  }

  /* End of Switch: '<S81>/Switch1' */

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   */
  rtb_Compare_mx = (*rtu_OBCWakeup == Wake_Up);

  /* CombinatorialLogic: '<S93>/Logic' incorporates:
   *  Logic: '<S81>/SoCResetReq'
   *  Memory: '<S93>/Memory'
   *  RelationalOperator: '<S88>/FixPt Relational Operator'
   *  RelationalOperator: '<S89>/FixPt Relational Operator'
   *  Switch: '<S81>/Switch1'
   *  UnitDelay: '<S88>/Delay Input1'
   *  UnitDelay: '<S89>/Delay Input1'
   *
   * Block description for '<S88>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S89>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Logic_idx_0_tmp = ((((uint32_T)((rtb_SOCAvgHystersis !=
    localDW->DelayInput1_DSTATE) || ((int32_T)rtb_Compare_mx > (int32_T)
    localDW->DelayInput1_DSTATE_g)) << 1U) + rtb_Logic_idx_0_tmp) << 1U) +
    localDW->Memory_PreviousInput_c;

  /* Logic: '<S10>/ChgStarted' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S22>/Constant'
   *  Constant: '<S23>/Constant'
   *  Logic: '<S10>/IsCharging'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S22>/Compare'
   *  RelationalOperator: '<S23>/Compare'
   *  UnitDelay: '<S10>/udlyChgModeReq'
   */
  rtb_ChgStarted = ((localDW->udlyChgModeReq_DSTATE == Standby) &&
                    ((*rtu_Charger_Mode_Req == CC_Start) ||
                     (*rtu_Charger_Mode_Req == CV)));

  /* RelationalOperator: '<S60>/Compare' incorporates:
   *  Constant: '<S60>/Constant'
   */
  rtb_Compare_cf = (*rtu_Charger_Mode_Req == Charge_Complete);

  /* Outputs for Triggered SubSystem: '<S51>/LatchFullSoc' incorporates:
   *  TriggerPort: '<S61>/Trigger'
   */
  if (rtb_Compare_cf && (localZCE->LatchFullSoc_Trig_ZCE != POS_ZCSIG)) {
    /* SignalConversion generated from: '<S61>/SOC_Full' */
    localB->LatchedFullSoC = *rtu_soc_full;
  }

  localZCE->LatchFullSoc_Trig_ZCE = rtb_Compare_cf;

  /* End of Outputs for SubSystem: '<S51>/LatchFullSoc' */

  /* RelationalOperator: '<S46>/Compare' incorporates:
   *  Constant: '<S46>/Constant'
   */
  rtb_Compare_il = (*rtu_sm_BMSMODE_en == BMS_CHARGE);

  /* MultiPortSwitch: '<S81>/Multiport Switch' */
  switch (rtb_Init) {
   case 0:
    rtb_ScaledGoldenDC_e = localB->InitialDichargeOCV;
    break;

   case 1:
    rtb_ScaledGoldenDC_e = localB->InitialChargeOCV;
    break;

   default:
    rtb_ScaledGoldenDC_e = localB->InitialDichargeOCV;
    break;
  }

  /* End of MultiPortSwitch: '<S81>/Multiport Switch' */

  /* DataTypeConversion: '<S81>/ConvertToFixdt' */
  rtb_SoCCoulombCounting = floor(rtb_ScaledGoldenDC_e / 0.01);
  if (rtIsNaN(rtb_SoCCoulombCounting) || rtIsInf(rtb_SoCCoulombCounting)) {
    rtb_SoCCoulombCounting = 0.0;
  } else {
    rtb_SoCCoulombCounting = fmod(rtb_SoCCoulombCounting, 65536.0);
  }

  if (rtb_SoCCoulombCounting < 0.0) {
    rtb_InitialSoCAvg = (uint16_T)-(int16_T)(uint16_T)-rtb_SoCCoulombCounting;
  } else {
    rtb_InitialSoCAvg = (uint16_T)rtb_SoCCoulombCounting;
  }

  /* End of DataTypeConversion: '<S81>/ConvertToFixdt' */

  /* Switch: '<S81>/Switch2' incorporates:
   *  CombinatorialLogic: '<S93>/Logic'
   *  DataTypeConversion: '<S81>/ConvertToFixdt'
   *  Switch: '<S81>/Switch1'
   *  UnitDelay: '<S48>/Delay Input1'
   *
   * Block description for '<S48>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (rtCP_Logic_table_c[rtb_Logic_idx_0_tmp + 8U]) {
    rtb_Uk1 = rtb_InitialSoCAvg;
  } else {
    rtb_Uk1 = rtb_SOCAvgHystersis;
  }

  /* End of Switch: '<S81>/Switch2' */

  /* Saturate: '<S81>/SoCBoundaries' incorporates:
   *  UnitDelay: '<S48>/Delay Input1'
   *
   * Block description for '<S48>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (rtb_Uk1 <= 10000) {
    *rty_SOCAvg = rtb_Uk1;
  } else {
    *rty_SOCAvg = 10000U;
  }

  /* End of Saturate: '<S81>/SoCBoundaries' */

  /* RelationalOperator: '<S66>/Compare' incorporates:
   *  Constant: '<S66>/Constant'
   */
  rtb_Compare_lv = (*rtu_Charger_Mode_Req == Charge_Complete);

  /* Outputs for Triggered SubSystem: '<S36>/LatchSoC' incorporates:
   *  TriggerPort: '<S68>/Trigger'
   */
  if (rtb_Compare_lv && (localZCE->LatchSoC_Trig_ZCE != POS_ZCSIG)) {
    /* SignalConversion generated from: '<S68>/SOC_Full' */
    localB->SoC = *rtu_soc_full;
  }

  /* Outputs for Triggered SubSystem: '<S51>/LatchFullSoc' incorporates:
   *  TriggerPort: '<S61>/Trigger'
   */
  localZCE->LatchSoC_Trig_ZCE = rtb_Compare_cf;

  /* End of Outputs for SubSystem: '<S51>/LatchFullSoc' */
  /* End of Outputs for SubSystem: '<S36>/LatchSoC' */

  /* Switch: '<S28>/selBatteryCapacitySource' incorporates:
   *  Constant: '<S28>/CalDOD'
   *  Constant: '<S28>/CalGoldenDC'
   *  Constant: '<S28>/CalSoHEnable'
   *  Gain: '<S28>/gainDCscale'
   *  Gain: '<S28>/gainDODscale'
   *  Product: '<S28>/CalcActualCapacity'
   *  Product: '<S28>/CalcCapacity'
   *  UnitDelay: '<S1>/udlySoH'
   */
  if (CAL_SOH_Enable) {
    *rty_Battery_Capacity = 0.0009999871253967285 * (real_T)CAL_GOLDEN_DC *
      (0.010009765625 * (real_T)CAL_DOD) * localDW->udlySoH_DSTATE;
  } else {
    *rty_Battery_Capacity = 0.0009999871253967285 * (real_T)CAL_GOLDEN_DC *
      (0.010009765625 * (real_T)CAL_DOD);
  }

  /* End of Switch: '<S28>/selBatteryCapacitySource' */

  /* Logic: '<S5>/InvertState' incorporates:
   *  DiscreteIntegrator: '<S5>/CalcCurrAccum'
   */
  rtb_IntegratorReset_tmp = !rtb_Compare_c2;

  /* Logic: '<S5>/IntegratorResetTrigger' incorporates:
   *  Constant: '<S30>/Constant'
   *  Logic: '<S5>/InvertState'
   *  RelationalOperator: '<S30>/Compare'
   */
  rtb_IntegratorReset = ((*rtu_Charger_Mode_Req == Charge_Complete) ||
    rtb_IntegratorReset_tmp);

  /* DiscreteIntegrator: '<S5>/DischargeAccumulator' incorporates:
   *  DiscreteIntegrator: '<S5>/CalcCurrAccum'
   *  Gain: '<S5>/gainSecToHourScale'
   *  Gain: '<S5>/scaleBattCurr'
   *  Product: '<S5>/divCurrentToCapacityRatio'
   *  Switch: '<S97>/Sample Accumulator '
   */
  if (rtb_IntegratorReset && (localDW->DischargeAccumulator_PrevResetS <= 0)) {
    localDW->DischargeAccumulator_DSTATE = 0.0;
  }

  rtb_SoCCoulombCounting = -32768.0 * (real_T)localB->usecAvgBatteryCurrent *
    3.0517578125E-7 / *rty_Battery_Capacity * 0.0002777777777777778 * 0.1;

  /* DiscreteIntegrator: '<S5>/DischargeAccumulator' */
  localDW->DischargeAccumulator_DSTATE += rtb_SoCCoulombCounting;

  /* Chart: '<S36>/SocStateController' incorporates:
   *  Constant: '<S65>/Constant'
   *  Constant: '<S67>/Constant'
   *  RelationalOperator: '<S65>/Compare'
   *  RelationalOperator: '<S67>/Compare'
   */
  if (localDW->is_active_c15_NBMS_SoC == 0) {
    localDW->is_active_c15_NBMS_SoC = 1U;
    localDW->is_c15_NBMS_SoC = NBMS_SoC_IN_entry;
    i = 0;
  } else {
    switch (localDW->is_c15_NBMS_SoC) {
     case NBMS_SoC_IN_entry:
      if (*rtu_Charger_Mode_Req == Disabled) {
        localDW->is_c15_NBMS_SoC = NBMS_SoC_IN_entry1;
        i = 0;
      } else {
        i = 0;
      }
      break;

     case NBMS_SoC_IN_entry1:
      if (rtb_Compare_lv) {
        localDW->is_c15_NBMS_SoC = NBMS_SoC_IN_entry2;
        i = 1;
      } else {
        i = 0;
      }
      break;

     case NBMS_SoC_IN_entry2:
      if (*rtu_Charger_Mode_Req == Disabled) {
        localDW->is_c15_NBMS_SoC = NBMS_SoC_IN_entry3;
        i = 1;
      } else {
        i = 1;
      }
      break;

     default:
      /* case IN_entry3: */
      if (*rtu_sm_BMSMODE_en == BMS_SLEEP) {
        localDW->is_c15_NBMS_SoC = NBMS_SoC_IN_entry;
        i = 0;
      } else {
        i = 1;
      }
      break;
    }
  }

  /* End of Chart: '<S36>/SocStateController' */

  /* DiscreteIntegrator: '<S5>/CalcCurrAccum' */
  if (rtb_IntegratorReset_tmp && (localDW->CalcCurrAccum_PrevResetState == 1)) {
    localDW->CalcCurrAccum_DSTATE = 0.0;
  }

  /* DiscreteIntegrator: '<S5>/CalcCurrAccum' */
  localDW->CalcCurrAccum_DSTATE += rtb_SoCCoulombCounting;

  /* Switch: '<S5>/selSoCcc' incorporates:
   *  Constant: '<S31>/Constant'
   *  Logic: '<S5>/SoCccUpdateTrigger'
   *  RelationalOperator: '<S31>/Compare'
   */
  if ((*rtu_AppIn_LastStoredCycle <= 0.0) || *rtu_Ignition) {
    /* Switch: '<S36>/selChgOrRealSoc' */
    if (i > 0) {
      /* Switch: '<S36>/selChgOrRealSoc' incorporates:
       *  Gain: '<S5>/ConvToPercent'
       *  Sum: '<S36>/CalcChgSoC'
       */
      localDW->udlySoCcc_DSTATE = (real_T)localB->SoC - 100.0 *
        localDW->DischargeAccumulator_DSTATE;
    } else {
      /* Switch: '<S36>/selChgOrRealSoc' incorporates:
       *  DataTypeConversion: '<S81>/ConvertToFixdt'
       *  Gain: '<S5>/gainCurrent'
       *  Sum: '<S5>/ApplySocCorrection'
       */
      localDW->udlySoCcc_DSTATE = (real_T)rtb_InitialSoCAvg * 0.01 - 100.0 *
        localDW->CalcCurrAccum_DSTATE;
    }

    /* End of Switch: '<S36>/selChgOrRealSoc' */

    /* Saturate: '<S36>/SoCccBoundaries' */
    if (localDW->udlySoCcc_DSTATE > 100.0) {
      /* Switch: '<S36>/selChgOrRealSoc' */
      localDW->udlySoCcc_DSTATE = 100.0;
    } else if (localDW->udlySoCcc_DSTATE < 0.0) {
      /* Switch: '<S36>/selChgOrRealSoc' */
      localDW->udlySoCcc_DSTATE = 0.0;
    }

    /* End of Saturate: '<S36>/SoCccBoundaries' */
  }

  /* End of Switch: '<S5>/selSoCcc' */

  /* Lookup_n-D: '<S33>/USER SOC' incorporates:
   *  Switch: '<S5>/selSoCcc'
   *  UnitDelay: '<S5>/udlySoCcc'
   */
  rtb_SoCCoulombCounting = look1_binlxpw(localDW->udlySoCcc_DSTATE,
    rtCP_USERSOC_bp01Data, rtCP_USERSOC_tableData, 1U);

  /* Outputs for Enabled SubSystem: '<S33>/CalcSoCCorrection' incorporates:
   *  EnablePort: '<S42>/EnableBlock'
   */
  /* Logic: '<S33>/SoCHoldReq' incorporates:
   *  Constant: '<S45>/Constant'
   *  Logic: '<S33>/ChkHasAvgSoCNotChanged'
   *  RelationalOperator: '<S45>/Compare'
   *  RelationalOperator: '<S48>/FixPt Relational Operator'
   *  UnitDelay: '<S48>/Delay Input1'
   *
   * Block description for '<S48>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((*rtu_sm_BMSMODE_en == BMS_SLEEP) || (*rty_SOCAvg ==
       localDW->DelayInput1_DSTATE_f)) {
    /* Sum: '<S42>/SoCDeviation' */
    localB->Switch2 = (real_T)*rty_SOCAvg * 0.01 - rtb_SoCCoulombCounting;

    /* Switch: '<S42>/selSleepStateFallBack' incorporates:
     *  Constant: '<S42>/SecperHour'
     *  Constant: '<S42>/ZeroHold'
     *  Constant: '<S58>/Constant'
     *  Product: '<S42>/ScaleSoCError'
     *  RelationalOperator: '<S58>/Compare'
     *  Sum: '<S42>/SoCAccumulate'
     *  UnitDelay: '<S42>/udlySoCError'
     */
    if (*rtu_sm_BMSMODE_en == BMS_SLEEP) {
      localDW->udlySoCError_DSTATE = 0.0;
    }

    localDW->udlySoCError_DSTATE += localB->Switch2 / 36000.0;

    /* End of Switch: '<S42>/selSleepStateFallBack' */

    /* Switch: '<S42>/selUpperBoundaryCheck' incorporates:
     *  Constant: '<S42>/ClampZero'
     */
    if (localB->Switch2 >= 0.0) {
      rtb_ScaledGoldenDC_e = localB->Switch2;
    } else {
      rtb_ScaledGoldenDC_e = 0.0;
    }

    /* End of Switch: '<S42>/selUpperBoundaryCheck' */

    /* Switch: '<S59>/Switch2' incorporates:
     *  RelationalOperator: '<S59>/LowerRelop1'
     *  Switch: '<S42>/selLowerBoundaryCheck'
     *  UnitDelay: '<S42>/udlySoCError'
     */
    if (localDW->udlySoCError_DSTATE > rtb_ScaledGoldenDC_e) {
      /* Sum: '<S42>/SoCDeviation' incorporates:
       *  Switch: '<S59>/Switch2'
       */
      localB->Switch2 = rtb_ScaledGoldenDC_e;
    } else {
      if (localB->Switch2 >= 0.0) {
        /* Sum: '<S42>/SoCDeviation' incorporates:
         *  Constant: '<S42>/HoldZero'
         *  Switch: '<S42>/selLowerBoundaryCheck'
         */
        localB->Switch2 = 0.0;
      }

      /* Switch: '<S59>/Switch' incorporates:
       *  RelationalOperator: '<S59>/UpperRelop'
       */
      if (!(localDW->udlySoCError_DSTATE < localB->Switch2)) {
        /* Sum: '<S42>/SoCDeviation' incorporates:
         *  Switch: '<S59>/Switch2'
         */
        localB->Switch2 = localDW->udlySoCError_DSTATE;
      }

      /* End of Switch: '<S59>/Switch' */
    }

    /* End of Switch: '<S59>/Switch2' */
  }

  /* End of Logic: '<S33>/SoCHoldReq' */
  /* End of Outputs for SubSystem: '<S33>/CalcSoCCorrection' */

  /* DataTypeConversion: '<S33>/ConvertToFixdt' incorporates:
   *  Sum: '<S33>/CalcCorrectedSoCcc'
   */
  rtb_SoCCoulombCounting = (localB->Switch2 + rtb_SoCCoulombCounting) / 0.01;
  if (rtb_SoCCoulombCounting < 65536.0) {
    if (rtb_SoCCoulombCounting >= 0.0) {
      rtb_Uk1 = (uint16_T)rtb_SoCCoulombCounting;
    } else {
      rtb_Uk1 = 0U;
    }
  } else {
    rtb_Uk1 = MAX_uint16_T;
  }

  /* Switch: '<S33>/SoCccBoundarySelection' incorporates:
   *  Constant: '<S44>/Constant'
   *  DataTypeConversion: '<S33>/ConvertToFixdt'
   *  RelationalOperator: '<S44>/Compare'
   *  RelationalOperator: '<S57>/LowerRelop1'
   *  RelationalOperator: '<S57>/UpperRelop'
   *  Switch: '<S57>/Switch'
   *  Switch: '<S57>/Switch2'
   */
  if (*rtu_sm_BMSMODE_en == BMS_CHARGE) {
    /* Switch: '<S56>/Switch2' incorporates:
     *  DataTypeConversion: '<S33>/ConvertToFixdt'
     *  RelationalOperator: '<S56>/LowerRelop1'
     */
    if (rtb_Uk1 > *rty_SOCAvg) {
      /* Switch: '<S33>/SoCccBoundarySelection' */
      rtb_Uk1 = *rty_SOCAvg;
    }
  } else if (rtb_Uk1 > 10000) {
    /* Switch: '<S57>/Switch2' incorporates:
     *  Constant: '<S33>/UpperBoundSoC'
     *  Switch: '<S33>/SoCccBoundarySelection'
     *  Switch: '<S56>/Switch2'
     */
    rtb_Uk1 = 10000U;
  } else if (rtb_Uk1 < *rty_SOCAvg) {
    /* Switch: '<S57>/Switch' incorporates:
     *  Switch: '<S33>/SoCccBoundarySelection'
     *  Switch: '<S56>/Switch2'
     *  Switch: '<S57>/Switch2'
     */
    rtb_Uk1 = *rty_SOCAvg;
  }

  /* End of Switch: '<S33>/SoCccBoundarySelection' */

  /* Outputs for Triggered SubSystem: '<S5>/LatchTempinit' incorporates:
   *  TriggerPort: '<S35>/Ignition'
   */
  if (*rtu_Ignition && (localZCE->LatchTempinit_Trig_ZCE != POS_ZCSIG)) {
    /* SignalConversion generated from: '<S35>/Temp' incorporates:
     *  MinMax: '<S1>/CalcMaxTemp'
     */
    localB->Temp = maxV;
  }

  /* Outputs for Triggered SubSystem: '<S81>/InitPackTemperature' incorporates:
   *  TriggerPort: '<S90>/Trigger'
   */
  localZCE->LatchTempinit_Trig_ZCE = *rtu_Ignition;

  /* End of Outputs for SubSystem: '<S81>/InitPackTemperature' */
  /* End of Outputs for SubSystem: '<S5>/LatchTempinit' */

  /* ModelReference: '<S5>/DischgOCV' incorporates:
   *  Constant: '<S5>/ConstOne'
   */
  NBMS_DischargeOCV(&localB->Temp, &rtb_OCVInitial, &rtCP_ConstOne_Value,
                    &localB->DischgOCV, &(localDW->DischgOCV_InstanceData.rtdw));

  /* Switch: '<S5>/selSocInitArbitration' incorporates:
   *  Abs: '<S5>/absSocError'
   *  Constant: '<S37>/Constant'
   *  Logic: '<S5>/InitFallbackTrigger'
   *  RelationalOperator: '<S37>/Compare'
   *  Sum: '<S5>/SocInitDeviation'
   */
  if (*rtu_AppIn_I2Cerror || (fabs(localB->DischgOCV - *rtu_AppIn_LastStoredSOC)
       >= 3.0)) {
    rtb_SoCCoulombCounting = localB->DischgOCV;
  } else {
    rtb_SoCCoulombCounting = *rtu_AppIn_LastStoredSOC;
  }

  /* End of Switch: '<S5>/selSocInitArbitration' */

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   */
  rtb_Compare_lv = (*rtu_sm_BMSMODE_en == BMS_SLEEP);

  /* Chart: '<S5>/InitialSocManager' */
  if (localDW->is_active_c14_NBMS_SoC == 0) {
    localDW->is_active_c14_NBMS_SoC = 1U;
    localDW->is_c14_NBMS_SoC = NBMS_SoC_IN_StoreInitialSOC;
    localB->InitialSOC = rtb_SoCCoulombCounting;
  } else if (localDW->is_c14_NBMS_SoC == NBMS_SoC_IN_IgnOff) {
    if (rtb_Compare_lv) {
      localDW->is_c14_NBMS_SoC = NBMS_SoC_IN_StoreInitialSOC;
      localB->InitialSOC = rtb_SoCCoulombCounting;
    }

    /* case IN_StoreInitialSOC: */
  } else if (!rtb_Compare_lv) {
    localDW->is_c14_NBMS_SoC = NBMS_SoC_IN_IgnOff;
  } else {
    localB->InitialSOC = rtb_SoCCoulombCounting;
  }

  /* End of Chart: '<S5>/InitialSocManager' */

  /* Switch: '<S33>/selSoCOutput' incorporates:
   *  Switch: '<S33>/SoCccBoundarySelection'
   *  Switch: '<S33>/selInitialSoc'
   *  UnitDelay: '<S33>/ZeroReset'
   *  UnitDelay: '<S33>/udlyDislaySoC'
   */
  if (localB->Compare_b) {
    rtb_SoCCoulombCounting = (real_T)rtb_Uk1 * 0.01;
  } else if (localDW->ZeroReset_DSTATE) {
    /* Switch: '<S33>/selInitialSoc' */
    rtb_SoCCoulombCounting = localB->InitialSOC;
  } else {
    rtb_SoCCoulombCounting = localDW->udlyDislaySoC_DSTATE;
  }

  /* End of Switch: '<S33>/selSoCOutput' */
  if (localDW->Memory_PreviousInput) {
    /* Switch: '<S52>/selBattSoC' incorporates:
     *  MinMax: '<S52>/FindMax'
     *  MinMax: '<S52>/FindMin'
     *  UnitDelay: '<S52>/uDlyBattSoC'
     *  UnitDelay: '<S52>/udlyBattSoC'
     */
    if (rtb_Compare_il) {
      localDW->udlyBattSoC_DSTATE = fmax(localDW->uDlyBattSoC_DSTATE,
        rtb_SoCCoulombCounting);
    } else {
      localDW->udlyBattSoC_DSTATE = fmin(rtb_SoCCoulombCounting,
        localDW->udlyBattSoC_DSTATE);
    }

    /* End of Switch: '<S52>/selBattSoC' */

    /* Saturate: '<S52>/BattSoCBoundaries' incorporates:
     *  UnitDelay: '<S52>/udlyBattSoC'
     */
    if (localDW->udlyBattSoC_DSTATE > 100.0) {
      *rty_Batt_Pack_SOC = 100.0;
    } else if (localDW->udlyBattSoC_DSTATE < 0.0) {
      *rty_Batt_Pack_SOC = 0.0;
    } else {
      *rty_Batt_Pack_SOC = localDW->udlyBattSoC_DSTATE;
    }

    /* End of Saturate: '<S52>/BattSoCBoundaries' */

    /* Update for UnitDelay: '<S52>/uDlyBattSoC' incorporates:
     *  UnitDelay: '<S52>/udlyBattSoC'
     */
    localDW->uDlyBattSoC_DSTATE = localDW->udlyBattSoC_DSTATE;
  }

  /* End of Outputs for SubSystem: '<S33>/LatchBattSoc' */

  /* Switch: '<S33>/selSocIgnLatch' */
  if (*rtu_Ignition) {
    /* Switch: '<S33>/selActiveOrHoldDisplaySoc' */
    if (localB->Compare_b) {
      /* UnitDelay: '<S33>/udlySoC' incorporates:
       *  Constant: '<S53>/CalDODMinThrsh'
       *  Constant: '<S53>/ScalingFactor'
       *  Constant: '<S53>/calDODMaxThrsh'
       *  Constant: '<S53>/calDODMinThrsh'
       *  Constant: '<S54>/ScalingFactor'
       *  Constant: '<S54>/calDODMaxThrsh'
       *  Constant: '<S54>/calDODMinThrsh'
       *  Product: '<S33>/SoCFactorScaling'
       *  Product: '<S53>/CalcOffset'
       *  Product: '<S53>/ScaleMinThrsh'
       *  Product: '<S54>/CalcSoCFactor'
       *  Sum: '<S33>/OffsetCorrection'
       *  Sum: '<S53>/DODThrshDiff'
       *  Sum: '<S54>/DODThrshDiff'
       *  Switch: '<S33>/SoCccBoundarySelection'
       */
      localDW->udlySoC_DSTATE = ((real_T)rtb_Uk1 * 0.01 - 100.0 * (real_T)
        CAL_DOD_MIN_THRSH / (real_T)(uint8_T)(CAL_DOD_MAX_THRSH -
        CAL_DOD_MIN_THRSH)) * (100.0 / (real_T)(uint8_T)(CAL_DOD_MAX_THRSH -
        CAL_DOD_MIN_THRSH));
    } else {
      /* UnitDelay: '<S33>/udlySoC' incorporates:
       *  UnitDelay: '<S33>/uDlySoC'
       */
      localDW->udlySoC_DSTATE = localDW->uDlySoC_DSTATE;
    }

    /* End of Switch: '<S33>/selActiveOrHoldDisplaySoc' */
  }

  /* End of Switch: '<S33>/selSocIgnLatch' */

  /* Switch: '<S33>/selModeTransitionRef' */
  if (rtb_Compare_il) {
    /* DataTypeConversion: '<S33>/ConvtTouint8' incorporates:
     *  UnitDelay: '<S33>/udlySoC'
     */
    if (localDW->udlySoC_DSTATE < 256.0) {
      if (localDW->udlySoC_DSTATE >= 0.0) {
        rtb_Init = (uint8_T)localDW->udlySoC_DSTATE;
      } else {
        rtb_Init = 0U;
      }
    } else {
      rtb_Init = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S33>/ConvtTouint8' */
  } else {
    /* DataTypeConversion: '<S33>/ConvertTouin8' incorporates:
     *  UnitDelay: '<S33>/udlySoC'
     */
    rtb_SoCCoulombCounting = ceil(localDW->udlySoC_DSTATE);
    if (rtb_SoCCoulombCounting < 256.0) {
      if (rtb_SoCCoulombCounting >= 0.0) {
        rtb_Init = (uint8_T)rtb_SoCCoulombCounting;
      } else {
        rtb_Init = 0U;
      }
    } else {
      rtb_Init = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S33>/ConvertTouin8' */
  }

  /* End of Switch: '<S33>/selModeTransitionRef' */

  /* Chart: '<S51>/StateWaitCondition' incorporates:
   *  UnitDelay: '<S51>/udlyEnableCurrent'
   */
  if (localDW->is_active_c1_NBMS_SoC == 0) {
    localDW->is_active_c1_NBMS_SoC = 1U;
    localB->out = 0.0;
    localDW->is_Decision = NBMS_SoC_IN_In;
    localDW->count = 0.0;
  } else if (localDW->is_Decision == NBMS_SoC_IN_In) {
    if (!localDW->udlyEnableCurrent_DSTATE && localB->Compare_b) {
      localB->out = 0.0;
      localDW->is_Decision = NBMS_SoC_IN_Out;
      localDW->count = 0.0;
    }

    /* case IN_Out: */
  } else if (localDW->count >= 5.0) {
    localB->out = 1.0;
    localDW->is_Decision = NBMS_SoC_IN_In;
    localDW->count = 0.0;
  } else {
    localDW->count++;
  }

  /* End of Chart: '<S51>/StateWaitCondition' */

  /* Switch: '<S51>/selFullChargeSocSource' incorporates:
   *  Constant: '<S43>/Constant'
   *  RelationalOperator: '<S43>/Compare'
   *  Switch: '<S33>/selDisplaySocFallback'
   *  Switch: '<S33>/selFinalGaugeOutput'
   */
  if (rtb_Compare_cf) {
    rtb_ScaledGoldenDC_e = localB->LatchedFullSoC;
  } else {
    if (localB->Compare_b) {
      /* Switch: '<S33>/selChargeSocCompensation' incorporates:
       *  Constant: '<S47>/Constant'
       *  MinMax: '<S33>/FindMinSoC'
       *  RelationalOperator: '<S47>/Compare'
       *  Switch: '<S33>/selFinalGaugeOutput'
       *  UnitDelay: '<S33>/UdlySoc'
       */
      if (*rtu_sm_BMSMODE_en == BMS_CHARGE) {
        /* MinMax: '<S33>/FindMaxSoC' incorporates:
         *  UnitDelay: '<S33>/UDlySOC'
         */
        if (localDW->UDlySOC_DSTATE >= rtb_Init) {
          /* Switch: '<S33>/selChargeSocCompensation' */
          localDW->UdlySoc_DSTATE = localDW->UDlySOC_DSTATE;
        } else {
          /* Switch: '<S33>/selChargeSocCompensation' */
          localDW->UdlySoc_DSTATE = rtb_Init;
        }
      } else if (rtb_Init <= localDW->UdlySoc_DSTATE) {
        /* Switch: '<S33>/selChargeSocCompensation' incorporates:
         *  MinMax: '<S33>/FindMaxSoC'
         *  MinMax: '<S33>/FindMinSoC'
         */
        localDW->UdlySoc_DSTATE = rtb_Init;
      }

      /* End of Switch: '<S33>/selChargeSocCompensation' */

      /* Switch: '<S33>/selFinalGaugeOutput' */
      rtb_ScaledGoldenDC_e = localDW->UdlySoc_DSTATE;
    } else if (*rtu_sm_BMSMODE_en != BMS_SLEEP) {
      /* Switch: '<S33>/selDisplaySocFallback' incorporates:
       *  Switch: '<S33>/selFinalGaugeOutput'
       */
      rtb_ScaledGoldenDC_e = localB->InitialSOC;
    } else {
      /* Switch: '<S33>/selFinalGaugeOutput' incorporates:
       *  Constant: '<S33>/ZeroSoC'
       *  Switch: '<S33>/selDisplaySocFallback'
       */
      rtb_ScaledGoldenDC_e = 0.0;
    }

    /* Switch: '<S51>/selTerminationSocRef' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S51>/ChgTerminationLt'
     *  Constant: '<S51>/MaxSOC'
     *  Constant: '<S51>/MaxSoC'
     *  Constant: '<S63>/Constant'
     *  Constant: '<S64>/Constant'
     *  Logic: '<S51>/ChargeCompletionTrigger'
     *  Logic: '<S51>/PackTopOffCondition'
     *  RelationalOperator: '<S43>/Compare'
     *  RelationalOperator: '<S51>/chkDisplaySocAtMax'
     *  RelationalOperator: '<S51>/chkPrevStateComplete'
     *  RelationalOperator: '<S63>/Compare'
     *  RelationalOperator: '<S64>/Compare'
     *  Switch: '<S33>/selDisplaySocFallback'
     *  Switch: '<S33>/selFinalGaugeOutput'
     *  Switch: '<S51>/selDisplaySocFallback'
     */
    if ((*rty_Batt_Pack_SOC <= 99.0) && (rtb_ScaledGoldenDC_e == 100.0) &&
        (localB->out != 0.0)) {
      rtb_ScaledGoldenDC_e = 99.0;
    } else if ((rtb_ScaledGoldenDC_e == 100.0) && (*rtu_sm_BMSMODE_en ==
                BMS_CHARGE)) {
      /* Switch: '<S51>/selDisplaySocFallback' incorporates:
       *  UnitDelay: '<S33>/udlyDSoC'
       */
      rtb_ScaledGoldenDC_e = localDW->udlyDSoC_DSTATE;
    }

    /* End of Switch: '<S51>/selTerminationSocRef' */
  }

  /* End of Switch: '<S51>/selFullChargeSocSource' */

  /* Saturate: '<S33>/SoCBoundaries' */
  if (rtb_ScaledGoldenDC_e > 100.0) {
    rtb_ScaledGoldenDC_e = 100.0;
  } else if (rtb_ScaledGoldenDC_e < 0.0) {
    rtb_ScaledGoldenDC_e = 0.0;
  }

  rtb_SoCCoulombCounting = ceil(rtb_ScaledGoldenDC_e);
  if (rtb_SoCCoulombCounting < 256.0) {
    rtb_Init = (uint8_T)rtb_SoCCoulombCounting;
  } else {
    rtb_Init = MAX_uint8_T;
  }

  /* SignalConversion generated from: '<S122>/ SFunction ' incorporates:
   *  Chart: '<S83>/FindMinAvgVolt'
   */
  rtb_TmpSignalConversionAtSFunct[0] = localB->AvgVoltofCell0;
  rtb_TmpSignalConversionAtSFunct[1] = localB->AvgVoltofCell1;
  rtb_TmpSignalConversionAtSFunct[2] = localB->AvgVoltofCell2;
  rtb_TmpSignalConversionAtSFunct[3] = localB->AvgVoltofCell3;
  rtb_TmpSignalConversionAtSFunct[4] = localB->AvgVoltofCell4;
  rtb_TmpSignalConversionAtSFunct[5] = localB->AvgVoltofCell5;
  rtb_TmpSignalConversionAtSFunct[6] = localB->AvgVoltofCell6;
  rtb_TmpSignalConversionAtSFunct[7] = localB->AvgVoltofCell7;
  rtb_TmpSignalConversionAtSFunct[8] = localB->AvgVoltofCell8;
  rtb_TmpSignalConversionAtSFunct[9] = localB->AvgVoltofCell9;
  rtb_TmpSignalConversionAtSFunct[10] = localB->AvgVoltofCell10;
  rtb_TmpSignalConversionAtSFunct[11] = localB->AvgVoltofCell11;
  rtb_TmpSignalConversionAtSFunct[12] = localB->AvgVoltofCell12;
  rtb_TmpSignalConversionAtSFunct[13] = localB->AvgVoltofCell13;
  rtb_TmpSignalConversionAtSFunct[14] = localB->AvgVoltofCell14;
  rtb_TmpSignalConversionAtSFunct[15] = localB->AvgVoltofCell15;
  rtb_TmpSignalConversionAtSFunct[16] = localB->AvgVoltofCell16;
  rtb_TmpSignalConversionAtSFunct[17] = localB->AvgVoltofCell17;
  rtb_TmpSignalConversionAtSFunct[18] = localB->AvgVoltofCell18;
  rtb_TmpSignalConversionAtSFunct[19] = localB->AvgVoltofCell19;

  /* Chart: '<S83>/FindMinAvgVolt' incorporates:
   *  SignalConversion generated from: '<S122>/ SFunction '
   */
  if (localDW->is_active_c2_NBMS_SoC == 0) {
    localDW->is_active_c2_NBMS_SoC = 1U;
    rtb_OpenCircuitVoltage = localB->AvgVoltofCell0;
    for (i = 0; i < 19; i++) {
      rtb_OCVInitial = rtb_TmpSignalConversionAtSFunct[i + 1];
      if (rtb_OpenCircuitVoltage < rtb_OCVInitial) {
        rtb_OpenCircuitVoltage = rtb_OCVInitial;
      }
    }

    for (i = 0; i < 20; i++) {
      rtb_OCVInitial = rtb_TmpSignalConversionAtSFunct[i];
      if ((rtb_OCVInitial != 0) && (rtb_OpenCircuitVoltage > rtb_OCVInitial)) {
        rtb_OpenCircuitVoltage = rtb_OCVInitial;
      }
    }
  } else {
    rtb_OpenCircuitVoltage = localB->AvgVoltofCell0;
    for (i = 0; i < 19; i++) {
      rtb_OCVInitial = rtb_TmpSignalConversionAtSFunct[i + 1];
      if (rtb_OpenCircuitVoltage < rtb_OCVInitial) {
        rtb_OpenCircuitVoltage = rtb_OCVInitial;
      }
    }

    for (i = 0; i < 20; i++) {
      rtb_OCVInitial = rtb_TmpSignalConversionAtSFunct[i];
      if ((rtb_OCVInitial != 0) && (rtb_OpenCircuitVoltage > rtb_OCVInitial)) {
        rtb_OpenCircuitVoltage = rtb_OCVInitial;
      }
    }
  }

  /* Sum: '<S83>/MinVoltDiff' */
  if (tmp) {
    rtb_SoCCoulombCounting = 0.0;
  } else {
    rtb_SoCCoulombCounting = fmod(rtb_InternalVoltageDrop_0, 65536.0);
  }

  if (rtb_SoCCoulombCounting < 0.0) {
    i = (int16_T)-(int16_T)(uint16_T)-rtb_SoCCoulombCounting;
  } else {
    i = (int16_T)(uint16_T)rtb_SoCCoulombCounting;
  }

  *rty_VtAvgMin = (int16_T)(rtb_OpenCircuitVoltage - i);

  /* Switch: '<S33>/selDisplaySoC' incorporates:
   *  Constant: '<S33>/calDischgEndThrsh'
   *  Constant: '<S49>/Constant'
   *  Gain: '<S33>/scaleDchgEndThrsh'
   *  RelationalOperator: '<S33>/chkVoltBelowCutoff'
   *  RelationalOperator: '<S49>/Compare'
   *  Saturate: '<S33>/SoCBoundaries'
   *  Switch: '<S33>/selSocCutoffArbitration'
   *  UnitDelay: '<S33>/udlyDisplaySoC'
   */
  if (rtb_Init > 0) {
    *rty_Display_SOC = rtb_Init;
  } else if (*rty_VtAvgMin * 16777 <= (int32_T)((33554U * CAL_DCHRG_END_THRSH) >>
              1)) {
    /* Switch: '<S33>/selSocCutoffArbitration' incorporates:
     *  Constant: '<S33>/SoCZeroClamp'
     */
    *rty_Display_SOC = 0U;
  } else {
    *rty_Display_SOC = localDW->udlyDisplaySoC_DSTATE;
  }

  /* End of Switch: '<S33>/selDisplaySoC' */

  /* Logic: '<S10>/CalcChargMeasureTrigger' incorporates:
   *  Constant: '<S20>/Constant'
   *  RelationalOperator: '<S20>/Compare'
   */
  rtb_Compare_cf = (rtb_ChgStarted && (*rty_Display_SOC < 10));

  /* Logic: '<S10>/UpdateSoHTrigger' incorporates:
   *  CombinatorialLogic: '<S17>/Logic'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S24>/Constant'
   *  Memory: '<S17>/Memory'
   *  RelationalOperator: '<S19>/Compare'
   *  RelationalOperator: '<S24>/Compare'
   *  UnitDelay: '<S10>/udlySoHtrigger'
   */
  localDW->Memory_PreviousInput_m = rtCP_Logic_table_a[((((uint32_T)
    rtb_Compare_cf << 1U) + localDW->udlySoHtrigger_DSTATE) << 1U) +
    localDW->Memory_PreviousInput_m];
  localDW->udlySoHtrigger_DSTATE = (localDW->Memory_PreviousInput_m &&
    (*rtu_Charger_Mode_Req == Charge_Complete) && (*rty_Display_SOC == 100));

  /* Outputs for Enabled SubSystem: '<S10>/CalcChgMeasured' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   */
  if (*rtu_sm_BMSMODE_en == BMS_CHARGE) {
    /* DiscreteIntegrator: '<S15>/CalcAccumulatedBattCurr' */
    if (rtb_Compare_cf && (localDW->CalcAccumulatedBattCurr_PrevRes <= 0)) {
      localDW->CalcAccumulatedBattCurr_DSTATE = 0.0;
    }

    /* Gain: '<S15>/scaleBattCurr' incorporates:
     *  DiscreteIntegrator: '<S15>/CalcAccumulatedBattCurr'
     */
    localB->ChargeMeasured = 1000.0 * localDW->CalcAccumulatedBattCurr_DSTATE;

    /* Update for DiscreteIntegrator: '<S15>/CalcAccumulatedBattCurr' incorporates:
     *  Abs: '<S15>/Absolute'
     *  DataTypeConversion: '<S4>/ConverToDouble'
     *  Gain: '<S15>/secPerHour'
     *  Switch: '<S97>/Sample Accumulator '
     */
    localDW->CalcAccumulatedBattCurr_DSTATE += fabs((real_T)
      localB->usecAvgBatteryCurrent * 0.01) * 0.0002777777777777778 * 0.1;
    localDW->CalcAccumulatedBattCurr_PrevRes = (int8_T)rtb_Compare_cf;
  }

  /* End of RelationalOperator: '<S18>/Compare' */
  /* End of Outputs for SubSystem: '<S10>/CalcChgMeasured' */

  /* Outputs for Triggered SubSystem: '<S10>/Initial_SoC_Storage' incorporates:
   *  TriggerPort: '<S27>/TriggerWhenChargeHasinitiated'
   */
  if (rtb_ChgStarted && (localZCE->Initial_SoC_Storage_Trig_ZCE != POS_ZCSIG)) {
    /* SignalConversion generated from: '<S27>/Display_SOC' */
    localB->SoCStart = *rty_Display_SOC;
  }

  localZCE->Initial_SoC_Storage_Trig_ZCE = rtb_ChgStarted;

  /* End of Outputs for SubSystem: '<S10>/Initial_SoC_Storage' */

  /* Switch: '<S10>/selLifecycleClamp' incorporates:
   *  Constant: '<S10>/MaxSoH'
   *  Constant: '<S26>/Constant'
   *  RelationalOperator: '<S26>/Compare'
   *  UnitDelay: '<S4>/udlyLifeCycle'
   */
  if (localDW->udlyLifeCycle_DSTATE > 0.0) {
    /* Switch: '<S10>/selIgnFallbackSoH' incorporates:
     *  RelationalOperator: '<S25>/FixPt Relational Operator'
     *  Switch: '<S10>/selUpdatedSoH'
     *  UnitDelay: '<S10>/udlySoHtrigger'
     *  UnitDelay: '<S25>/Delay Input1'
     *
     * Block description for '<S25>/Delay Input1':
     *
     *  Store in Global RAM
     */
    if ((int32_T)*rtu_Ignition > (int32_T)localDW->DelayInput1_DSTATE_j) {
      rtb_ScaledGoldenDC_e = *rtu_AppIn_LastStoredSOH;
    } else if (localDW->udlySoHtrigger_DSTATE) {
      /* Switch: '<S10>/selUpdatedSoH' incorporates:
       *  Constant: '<S10>/Charg_Capacity1'
       *  Constant: '<S16>/MaxSoC'
       *  Constant: '<S16>/MaxSoH'
       *  Gain: '<S16>/scaleMeasuredCharge'
       *  MinMax: '<S16>/CalcMinSoH'
       *  Product: '<S16>/CalcDischgCapacity'
       *  Product: '<S16>/CalcSoH'
       *  Sum: '<S16>/CalcDOD'
       */
      rtb_ScaledGoldenDC_e = fmin(10000.0 * localB->ChargeMeasured / (real_T)
        ((100 - localB->SoCStart) * CAL_GOLDEN_CHARGE), 100.0);
    } else {
      /* Switch: '<S10>/selUpdatedSoH' incorporates:
       *  UnitDelay: '<S10>/udlySoH'
       */
      rtb_ScaledGoldenDC_e = localDW->udlySoH_DSTATE_k;
    }

    /* End of Switch: '<S10>/selIgnFallbackSoH' */
  } else {
    rtb_ScaledGoldenDC_e = 100.0;
  }

  /* End of Switch: '<S10>/selLifecycleClamp' */

  /* Saturate: '<S10>/SoHBoundaries' incorporates:
   *  UnitDelay: '<S10>/udlySoH'
   */
  if (rtb_ScaledGoldenDC_e > 100.0) {
    rtb_ScaledGoldenDC_e = 100.0;
  } else if (rtb_ScaledGoldenDC_e < 0.0) {
    rtb_ScaledGoldenDC_e = 0.0;
  }

  rtb_SoCCoulombCounting = ceil(rtb_ScaledGoldenDC_e);
  if (rtb_SoCCoulombCounting < 256.0) {
    localDW->udlySoH_DSTATE_k = (uint8_T)rtb_SoCCoulombCounting;
  } else {
    localDW->udlySoH_DSTATE_k = MAX_uint8_T;
  }

  /* End of Saturate: '<S10>/SoHBoundaries' */

  /* DataTypeConversion: '<S10>/cnvToDouble' incorporates:
   *  UnitDelay: '<S10>/udlySoH'
   */
  *rty_SOH = localDW->udlySoH_DSTATE_k;

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_ChgStarted = (*rtu_sm_BMSMODE_en == BMS_SLEEP);

  /* DiscreteIntegrator: '<S9>/Accumulate BattCurrent' */
  if (rtb_ChgStarted && (localDW->AccumulateBattCurrent_PrevReset <= 0)) {
    localDW->AccumulateBattCurrent_DSTATE = 0.0;
  }

  /* DiscreteIntegrator: '<S9>/Accumulate BattCurrent' incorporates:
   *  Abs: '<S9>/Absolute'
   *  DataTypeConversion: '<S4>/ConverToDouble'
   *  Gain: '<S9>/CurrentToAh'
   *  Switch: '<S97>/Sample Accumulator '
   */
  localDW->AccumulateBattCurrent_DSTATE += fabs((real_T)
    localB->usecAvgBatteryCurrent * 0.01) * 0.0002777777777777778 * 0.1;

  /* Switch: '<S9>/selAccumulateorHold' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Logic: '<S9>/lastStoredCycleTrigger'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S13>/Compare'
   *  UnitDelay: '<S9>/udlyBMSMode'
   *  UnitDelay: '<S9>/udlyCycleCount'
   */
  if ((localDW->udlyBMSMode_DSTATE == BMS_SLEEP) && (*rtu_sm_BMSMODE_en ==
       BMS_STANDBY)) {
    localDW->udlyCycleCount_DSTATE = *rtu_AppIn_LastStoredCycle;
  }

  /* End of Switch: '<S9>/selAccumulateorHold' */

  /* Switch: '<S9>/selLifeCycleOutput' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S9>/FullCycleFactor'
   *  Constant: '<S9>/calDOD'
   *  Constant: '<S9>/calGoldenDC'
   *  Gain: '<S9>/gainDCscale'
   *  Gain: '<S9>/gainDODscale'
   *  Gain: '<S9>/gainSoHscale'
   *  Product: '<S9>/CalcCapacity'
   *  Product: '<S9>/CalcDegradedCapacity'
   *  Product: '<S9>/CalcLifecycle'
   *  Product: '<S9>/NormalizeBattCurr'
   *  RelationalOperator: '<S11>/Compare'
   *  Sum: '<S9>/CalcTotalLifeCycle'
   *  Switch: '<S9>/selSoHoverrideSource'
   *  UnitDelay: '<S9>/udlyCycleCount'
   *  UnitDelay: '<S9>/udlyLifeCylce'
   */
  if (*rtu_sm_BMSMODE_en != BMS_SLEEP) {
    /* Switch: '<S9>/selSoHoverrideSource' incorporates:
     *  Constant: '<S9>/MaxSoH'
     *  Constant: '<S9>/calSoHEnable'
     */
    if (CAL_SOH_Enable) {
      rtb_SoCCoulombCounting = *rty_SOH;
    } else {
      rtb_SoCCoulombCounting = 100.0;
    }

    *rty_LifeCycle = localDW->AccumulateBattCurrent_DSTATE / 2.0 /
      (0.0009999871253967285 * (real_T)CAL_GOLDEN_DC * (0.010009765625 * (real_T)
        CAL_DOD) * (0.01 * rtb_SoCCoulombCounting)) +
      localDW->udlyCycleCount_DSTATE;
  } else {
    *rty_LifeCycle = localDW->udlyLifeCylce_DSTATE;
  }

  /* End of Switch: '<S9>/selLifeCycleOutput' */

  /* Gain: '<S10>/scalechargemeasured' */
  *rty_ChargeCapacity = 0.001 * localB->ChargeMeasured;

  /* RelationalOperator: '<S39>/Compare' incorporates:
   *  Constant: '<S39>/Constant'
   */
  rtb_Compare_cf = (*rtu_sm_BMSMODE_en == BMS_CHARGE);

  /* DiscreteIntegrator: '<S32>/CoulombCounter' */
  if (TriggerswhentheBMSModeisDischar && (localDW->CoulombCounter_PrevResetState
       <= 0)) {
    localDW->CoulombCounter_DSTATE = 0.0;
  }

  /* DiscreteIntegrator: '<S32>/CoulombCounter' incorporates:
   *  Constant: '<S32>/secperHour'
   *  Product: '<S32>/DivideBattCurrToAmp-hour'
   *  Switch: '<S97>/Sample Accumulator '
   */
  localDW->CoulombCounter_DSTATE += (real_T)localB->usecAvgBatteryCurrent * 0.01
    / 3600.0 * 0.1;

  /* DiscreteIntegrator: '<S32>/CoulombCounter' */
  if (localDW->CoulombCounter_DSTATE > 38.4) {
    /* DiscreteIntegrator: '<S32>/CoulombCounter' */
    localDW->CoulombCounter_DSTATE = 38.4;
  } else if (localDW->CoulombCounter_DSTATE < -38.4) {
    /* DiscreteIntegrator: '<S32>/CoulombCounter' */
    localDW->CoulombCounter_DSTATE = -38.4;
  }

  /* RelationalOperator: '<S40>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S40>/Delay Input1'
   *
   * Block description for '<S40>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Compare_il = ((int32_T)rtb_Compare_cf > (int32_T)
                    localDW->DelayInput1_DSTATE_ju);

  /* Outputs for Triggered SubSystem: '<S32>/LatchInitCapacity' incorporates:
   *  TriggerPort: '<S41>/Trigger'
   */
  if (rtb_Compare_il && (localZCE->LatchInitCapacity_Trig_ZCE != POS_ZCSIG)) {
    /* SignalConversion generated from: '<S41>/CurrCapacity' incorporates:
     *  UnitDelay: '<S32>/udlyCurrentCapacity'
     */
    localB->InitialCapacity = localDW->udlyCurrentCapacity_DSTATE;
  }

  localZCE->LatchInitCapacity_Trig_ZCE = rtb_Compare_il;

  /* End of Outputs for SubSystem: '<S32>/LatchInitCapacity' */

  /* Switch: '<S32>/selCapacity' incorporates:
   *  Constant: '<S32>/SoHEnable'
   *  Constant: '<S32>/calDOD'
   *  Constant: '<S32>/calGoldenDC'
   *  Gain: '<S32>/gainDCscale'
   *  Gain: '<S32>/gainDODscale'
   *  Gain: '<S32>/gainSoCscale'
   *  Gain: '<S32>/gainSoHscale'
   *  Product: '<S32>/CalcInitialCurrCapacity'
   *  Sum: '<S32>/TotalCapacity'
   *  Switch: '<S32>/selSoHsource'
   *  UnitDelay: '<S32>/udlyCurrentCapacity'
   */
  if (rtb_Compare_cf) {
    localDW->udlyCurrentCapacity_DSTATE = localDW->CoulombCounter_DSTATE +
      localB->InitialCapacity;
  } else {
    if (!CAL_SOH_Enable) {
      /* Switch: '<S32>/selSoHsource' incorporates:
       *  Constant: '<S32>/MaxSoH'
       */
      localDW->udlySoH_DSTATE = 100.0;
    }

    localDW->udlyCurrentCapacity_DSTATE = 0.01 * localDW->udlySoH_DSTATE *
      (0.0009999871253967285 * (real_T)CAL_GOLDEN_DC) * (0.010009765625 *
      (real_T)CAL_DOD) * (0.010009765625 * (real_T)*rty_Display_SOC);
  }

  /* End of Switch: '<S32>/selCapacity' */

  /* Saturate: '<S32>/SetCapacityBoundaries' incorporates:
   *  UnitDelay: '<S32>/udlyCurrentCapacity'
   */
  if (localDW->udlyCurrentCapacity_DSTATE > 38.4) {
    *rty_CurrentCapacity = 38.4;
  } else if (localDW->udlyCurrentCapacity_DSTATE < 0.0) {
    *rty_CurrentCapacity = 0.0;
  } else {
    *rty_CurrentCapacity = localDW->udlyCurrentCapacity_DSTATE;
  }

  /* End of Saturate: '<S32>/SetCapacityBoundaries' */

  /* Gain: '<S8>/scaleAvailEnergykWh' incorporates:
   *  Constant: '<S4>/calNominalVoltage'
   *  Gain: '<S4>/gainNominalVt'
   *  Product: '<S8>/CalcAvailEneregy'
   */
  *rty_AvailableEnergy = 0.0010000000002037268 * (real_T)CAL_NOMINAL_VOLTAGE *
    *rty_CurrentCapacity * 0.001;

  /* Outputs for Enabled SubSystem: '<S1>/SOC Fault Detection' incorporates:
   *  EnablePort: '<S6>/triggerWhenSoCCalcValid'
   */
  /* UnitDelay: '<S1>/udlyStartSoC' */
  if (localDW->udlyStartSoC_DSTATE) {
    if (!localDW->SOCFaultDetection_MODE) {
      /* InitializeConditions for Switch: '<S6>/selSoc15WarningOutput' incorporates:
       *  Memory: '<S73>/Memory'
       */
      localDW->Memory_PreviousInput_a = false;

      /* InitializeConditions for Switch: '<S6>/selSoc20WarningOutput' incorporates:
       *  Memory: '<S74>/Memory'
       */
      localDW->Memory_PreviousInput_ar = false;

      /* InitializeConditions for Memory: '<S72>/Memory' */
      localDW->Memory_PreviousInput_g = false;
      localDW->SOCFaultDetection_MODE = true;
    }

    /* RelationalOperator: '<S70>/Compare' incorporates:
     *  Constant: '<S70>/Constant'
     */
    rtb_Compare_il = (*rtu_sm_BMSMODE_en == BMS_DISCHARGE);

    /* Switch: '<S6>/selSoc15WarningOutput' incorporates:
     *  CombinatorialLogic: '<S73>/Logic'
     *  Constant: '<S75>/Constant'
     *  Constant: '<S78>/Constant'
     *  Logic: '<S6>/Soc15WarningTrip'
     *  Memory: '<S73>/Memory'
     *  RelationalOperator: '<S75>/Compare'
     *  RelationalOperator: '<S78>/Compare'
     */
    localDW->Memory_PreviousInput_a = rtCP_Logic_table[((((uint32_T)
      ((*rty_Display_SOC < CAL_15_SOC_WRN_THRSH) && rtb_Compare_il) << 1U) +
      (uint32_T)(*rty_Display_SOC >= CAL_15_SOC_WRN_RVL_THRSH)) << 1U) +
      localDW->Memory_PreviousInput_a];

    /* Switch: '<S6>/selSoc20WarningOutput' incorporates:
     *  CombinatorialLogic: '<S74>/Logic'
     *  Constant: '<S76>/Constant'
     *  Constant: '<S79>/Constant'
     *  Logic: '<S6>/Soc20WarningTrip'
     *  Memory: '<S74>/Memory'
     *  RelationalOperator: '<S76>/Compare'
     *  RelationalOperator: '<S79>/Compare'
     */
    localDW->Memory_PreviousInput_ar = rtCP_Logic_table_m[((((uint32_T)
      (rtb_Compare_il && (*rty_Display_SOC < CAL_SOC_WRN_THRSH)) << 1U) +
      (uint32_T)(*rty_Display_SOC >= CAL_SOC_WRN_RVL_THRSH)) << 1U) +
      localDW->Memory_PreviousInput_ar];

    /* CombinatorialLogic: '<S72>/Logic' incorporates:
     *  Constant: '<S71>/Constant'
     *  Constant: '<S77>/Constant'
     *  Constant: '<S80>/Constant'
     *  Logic: '<S6>/IsDischargeOrFault'
     *  Logic: '<S6>/LowSocTripCondition'
     *  Memory: '<S72>/Memory'
     *  RelationalOperator: '<S71>/Compare'
     *  RelationalOperator: '<S77>/Compare'
     *  RelationalOperator: '<S80>/Compare'
     */
    rowIdx = ((((uint32_T)((*rty_Display_SOC <= CAL_LOW_SOC_THRSH) &&
      (rtb_Compare_il || (*rtu_sm_BMSMODE_en == BMS_FAULT))) << 1U) + (uint32_T)
               (*rty_Display_SOC >= CAL_LOW_SOC_RVL_THRSH)) << 1U) +
      localDW->Memory_PreviousInput_g;
    localB->Logic[0U] = rtCP_Logic_table_g[rowIdx];
    localB->Logic[1U] = rtCP_Logic_table_g[rowIdx + 8U];

    /* Switch: '<S6>/selSoc20WarningOutput' incorporates:
     *  Constant: '<S6>/calEnableSoCWarn20'
     */
    *rty_LOW_SOC_WARN = (CAL_ENABLE_SOC_WARN_20 &&
                         localDW->Memory_PreviousInput_ar);

    /* Switch: '<S6>/selSoc15WarningOutput' incorporates:
     *  Constant: '<S6>/calEnableSoCWarn15'
     */
    *rty_LOW_SOC_WARN_15 = (CAL_ENABLE_SOC_WARN_15 &&
      localDW->Memory_PreviousInput_a);

    /* Update for Memory: '<S72>/Memory' */
    localDW->Memory_PreviousInput_g = localB->Logic[0];
  } else if (localDW->SOCFaultDetection_MODE) {
    /* Disable for Outport: '<S6>/ LOW_SOC_WARN_15' */
    *rty_LOW_SOC_WARN_15 = false;

    /* Disable for Outport: '<S6>/ LOW_SOC' incorporates:
     *  CombinatorialLogic: '<S72>/Logic'
     */
    localB->Logic[0] = false;

    /* Disable for Outport: '<S6>/ LOW_SOC_WARN' */
    *rty_LOW_SOC_WARN = false;
    localDW->SOCFaultDetection_MODE = false;
  }

  /* End of UnitDelay: '<S1>/udlyStartSoC' */
  /* End of Outputs for SubSystem: '<S1>/SOC Fault Detection' */

  /* SignalConversion generated from: '<Root>/LOW_SOC' */
  *rty_LOW_SOC = localB->Logic[0];

  /* Outputs for Enabled SubSystem: '<S82>/MovingAverageCurrent5sec' incorporates:
   *  EnablePort: '<S98>/EnableBlock'
   */
  if (rtb_Compare_o1) {
    if (!localDW->MovingAverageCurrent5sec_MODE) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S98>/50Delay' */
      memset(&localDW->u0Delay_DWORK1_m[0], 0, 50U * sizeof(int16_T));

      /* InitializeConditions for UnitDelay: '<S98>/1UnitDelay' */
      localDW->uUnitDelay_DSTATE = 0U;
      localDW->MovingAverageCurrent5sec_MODE = true;
    }

    /* DataTypeConversion: '<S98>/ConvertToFixdt' */
    rtb_SoCCoulombCounting = floor(*rtu_AppIn_BattCurrent / 0.01);
    if (rtIsNaN(rtb_SoCCoulombCounting) || rtIsInf(rtb_SoCCoulombCounting)) {
      rtb_SoCCoulombCounting = 0.0;
    } else {
      rtb_SoCCoulombCounting = fmod(rtb_SoCCoulombCounting, 65536.0);
    }

    if (rtb_SoCCoulombCounting < 0.0) {
      /* DataTypeConversion: '<S98>/ConvertToFixdt' */
      localB->u1stSample = (int16_T)-(int16_T)(uint16_T)-rtb_SoCCoulombCounting;
    } else {
      /* DataTypeConversion: '<S98>/ConvertToFixdt' */
      localB->u1stSample = (int16_T)(uint16_T)rtb_SoCCoulombCounting;
    }

    /* End of DataTypeConversion: '<S98>/ConvertToFixdt' */

    /* Sum: '<S98>/Counter' incorporates:
     *  Constant: '<S98>/CountStep'
     *  UnitDelay: '<S98>/1UnitDelay'
     */
    rowIdx = localDW->uUnitDelay_DSTATE + 1U;
    if (localDW->uUnitDelay_DSTATE + 1U > 255U) {
      rowIdx = 255U;
    }

    localDW->uUnitDelay_DSTATE = (uint8_T)rowIdx;

    /* End of Sum: '<S98>/Counter' */

    /* Switch: '<S98>/Sample Accumulator ' incorporates:
     *  Constant: '<S100>/Constant'
     *  Constant: '<S98>/ConstZeroCurrent'
     *  DataTypeConversion: '<S98>/ConvertToFixdt'
     *  Product: '<S98>/Average'
     *  RelationalOperator: '<S100>/Compare'
     *  Sum: '<S98>/Sumof51Samples'
     *  Sum: '<S98>/SumofCurrent'
     *  UnitDelay: '<S98>/1UnitDelay'
     */
    if (localDW->uUnitDelay_DSTATE > 50) {
      /* Sum: '<S98>/SumofCurrent' incorporates:
       *  S-Function (sfix_udelay): '<S98>/50Delay'
       */
      y = 0;
      for (i = 0; i < 50; i++) {
        y += localDW->u0Delay_DWORK1_m[i];
      }

      *rty_BatteryCurrentAvg5sec = (int16_T)(((int16_T)div_nzp_repeat_s32_floor
        (y + localB->u1stSample, 1275, 4U) * 25) >> 4);
    } else {
      *rty_BatteryCurrentAvg5sec = 0;
    }

    /* End of Switch: '<S98>/Sample Accumulator ' */

    /* Update for S-Function (sfix_udelay): '<S98>/50Delay' incorporates:
     *  DataTypeConversion: '<S98>/ConvertToFixdt'
     */
    for (i = 0; i < 49; i++) {
      localDW->u0Delay_DWORK1_m[i] = localDW->u0Delay_DWORK1_m[i + 1];
    }

    localDW->u0Delay_DWORK1_m[49] = localB->u1stSample;

    /* End of Update for S-Function (sfix_udelay): '<S98>/50Delay' */
  } else if (localDW->MovingAverageCurrent5sec_MODE) {
    /* Disable for Outport: '<S98>/BatteryCurrent' */
    *rty_BatteryCurrentAvg5sec = 0;
    localDW->MovingAverageCurrent5sec_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S82>/MovingAverageCurrent5sec' */

  /* Sum: '<S83>/SumofRawVolt' incorporates:
   *  DataTypeConversion: '<S1>/ConvertToFixdt'
   */
  rtb_SoCCoulombCounting = 0.0;
  for (i = 0; i < 20; i++) {
    rtb_SoCCoulombCounting += (real_T)localB->ConvBattVolt[i] * 0.001;
  }

  /* Outputs for Enabled SubSystem: '<S83>/OneSensorVoltFailure' incorporates:
   *  EnablePort: '<S145>/Enable'
   */
  /* RelationalOperator: '<S121>/Compare' incorporates:
   *  Constant: '<S121>/Constant'
   *  Sum: '<S83>/CountofNonZeroCellVolt'
   */
  if (rtb_CountofNonZeroCell_0 == 19) {
    if (!localDW->OneSensorVoltFailure_MODE) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S146>/20Delay' */
      for (i = 0; i < 20; i++) {
        localDW->u0Delay_DWORK1[i] = 0;
      }

      /* End of InitializeConditions for S-Function (sfix_udelay): '<S146>/20Delay' */

      /* InitializeConditions for UnitDelay: '<S146>/PreviousValue' */
      localDW->PreviousValue_DSTATE = 0.0;
      localDW->OneSensorVoltFailure_MODE = true;
    }

    /* Sum: '<S145>/VoltDifference' incorporates:
     *  Sum: '<S83>/SumofRawVolt'
     */
    *rty_FailSensorVolt = *rtu_mi_Pack_Volt - rtb_SoCCoulombCounting;

    /* DataTypeConversion: '<S146>/FixdtDataTypeConversion' */
    rtb_SoCCoulombCounting = floor(*rty_FailSensorVolt / 0.001);
    if (rtIsNaN(rtb_SoCCoulombCounting) || rtIsInf(rtb_SoCCoulombCounting)) {
      rtb_SoCCoulombCounting = 0.0;
    } else {
      rtb_SoCCoulombCounting = fmod(rtb_SoCCoulombCounting, 65536.0);
    }

    if (rtb_SoCCoulombCounting < 0.0) {
      /* DataTypeConversion: '<S146>/FixdtDataTypeConversion' */
      localB->u1stVoltage = (int16_T)-(int16_T)(uint16_T)-rtb_SoCCoulombCounting;
    } else {
      /* DataTypeConversion: '<S146>/FixdtDataTypeConversion' */
      localB->u1stVoltage = (int16_T)(uint16_T)rtb_SoCCoulombCounting;
    }

    /* End of DataTypeConversion: '<S146>/FixdtDataTypeConversion' */

    /* Sum: '<S146>/Counter' incorporates:
     *  Constant: '<S146>/CountStep'
     *  UnitDelay: '<S146>/PreviousValue'
     */
    if (localDW->PreviousValue_DSTATE < 256.0) {
      if (localDW->PreviousValue_DSTATE >= 0.0) {
        rtb_Init = (uint8_T)localDW->PreviousValue_DSTATE;
      } else {
        rtb_Init = 0U;
      }
    } else {
      rtb_Init = MAX_uint8_T;
    }

    rowIdx = rtb_Init + 1U;
    if (rtb_Init + 1U > 255U) {
      rowIdx = 255U;
    }

    /* Switch: '<S146>/Counterfor20' incorporates:
     *  Constant: '<S146>/ConstZeroVt'
     *  DataTypeConversion: '<S146>/FixdtDataTypeConversion'
     *  Product: '<S146>/Average'
     *  Sum: '<S146>/Counter'
     *  Sum: '<S146>/SumofVoltage'
     *  Sum: '<S146>/TotalSum'
     */
    if (rowIdx > 20U) {
      /* Sum: '<S146>/SumofVoltage' incorporates:
       *  S-Function (sfix_udelay): '<S146>/20Delay'
       */
      y = 0;
      for (i = 0; i < 20; i++) {
        y += localDW->u0Delay_DWORK1[i];
      }

      *rty_FailSensorVoltAvg = (int16_T)(((int16_T)div_nzp_repeat_s32_floor(y +
        localB->u1stVoltage, 2625, 6U) * 125) >> 6);
    } else {
      *rty_FailSensorVoltAvg = 0;
    }

    /* End of Switch: '<S146>/Counterfor20' */

    /* Update for S-Function (sfix_udelay): '<S146>/20Delay' incorporates:
     *  DataTypeConversion: '<S146>/FixdtDataTypeConversion'
     */
    for (i = 0; i < 19; i++) {
      localDW->u0Delay_DWORK1[19 - i] = localDW->u0Delay_DWORK1[18 - i];
    }

    localDW->u0Delay_DWORK1[0] = localB->u1stVoltage;

    /* End of Update for S-Function (sfix_udelay): '<S146>/20Delay' */

    /* Update for UnitDelay: '<S146>/PreviousValue' incorporates:
     *  Sum: '<S146>/Counter'
     */
    localDW->PreviousValue_DSTATE = rowIdx;
  } else if (localDW->OneSensorVoltFailure_MODE) {
    /* Disable for Outport: '<S145>/FailSensorVolt' */
    *rty_FailSensorVolt = 5.0;

    /* Disable for Outport: '<S145>/FailSensorVoltAvg' */
    *rty_FailSensorVoltAvg = 5000;
    localDW->OneSensorVoltFailure_MODE = false;
  }

  /* End of RelationalOperator: '<S121>/Compare' */
  /* End of Outputs for SubSystem: '<S83>/OneSensorVoltFailure' */

  /* Saturate: '<S33>/SoCccBoundaries' incorporates:
   *  Switch: '<S33>/SoCccBoundarySelection'
   */
  if (rtb_Uk1 <= 10000) {
    *rty_SOCcc = rtb_Uk1;
  } else {
    *rty_SOCcc = 10000U;
  }

  /* End of Saturate: '<S33>/SoCccBoundaries' */

  /* DataTypeConversion: '<S1>/ConvertToDouble' incorporates:
   *  DataTypeConversion: '<S81>/ConvertToFixdt'
   */
  *rty_SOCAvgInitial = (real_T)rtb_InitialSoCAvg * 0.01;

  /* MinMax: '<S83>/FindMaxAvgVt' */
  tmpForInput[0] = localB->AvgVoltofCell0;
  tmpForInput[1] = localB->AvgVoltofCell1;
  tmpForInput[2] = localB->AvgVoltofCell2;
  tmpForInput[3] = localB->AvgVoltofCell3;
  tmpForInput[4] = localB->AvgVoltofCell4;
  tmpForInput[5] = localB->AvgVoltofCell5;
  tmpForInput[6] = localB->AvgVoltofCell6;
  tmpForInput[7] = localB->AvgVoltofCell7;
  tmpForInput[8] = localB->AvgVoltofCell8;
  tmpForInput[9] = localB->AvgVoltofCell9;
  tmpForInput[10] = localB->AvgVoltofCell10;
  tmpForInput[11] = localB->AvgVoltofCell11;
  tmpForInput[12] = localB->AvgVoltofCell12;
  tmpForInput[13] = localB->AvgVoltofCell13;
  tmpForInput[14] = localB->AvgVoltofCell14;
  tmpForInput[15] = localB->AvgVoltofCell15;
  tmpForInput[16] = localB->AvgVoltofCell16;
  tmpForInput[17] = localB->AvgVoltofCell17;
  tmpForInput[18] = localB->AvgVoltofCell18;
  tmpForInput[19] = localB->AvgVoltofCell19;
  rtb_OCVInitial = localB->AvgVoltofCell0;
  for (i = 0; i < 19; i++) {
    rtb_OpenCircuitVoltage = tmpForInput[i + 1];
    if (rtb_OCVInitial < rtb_OpenCircuitVoltage) {
      rtb_OCVInitial = rtb_OpenCircuitVoltage;
    }
  }

  /* Sum: '<S83>/MaxVoltDiff' incorporates:
   *  MinMax: '<S83>/FindMaxAvgVt'
   */
  if (tmp) {
    rtb_SoCCoulombCounting = 0.0;
  } else {
    rtb_SoCCoulombCounting = fmod(rtb_InternalVoltageDrop_0, 65536.0);
  }

  if (rtb_SoCCoulombCounting < 0.0) {
    i = (int16_T)-(int16_T)(uint16_T)-rtb_SoCCoulombCounting;
  } else {
    i = (int16_T)(uint16_T)rtb_SoCCoulombCounting;
  }

  *rty_VtAvgMax = (int16_T)(rtb_OCVInitial - i);

  /* Chart: '<S83>/FindMinVolt' incorporates:
   *  DataTypeConversion: '<S1>/ConvertToFixdt'
   */
  if (localDW->is_active_c5_NBMS_SoC == 0) {
    localDW->is_active_c5_NBMS_SoC = 1U;
    rtb_OpenCircuitVoltage = localB->ConvBattVolt[0];
    for (i = 0; i < 19; i++) {
      rtb_OCVInitial = localB->ConvBattVolt[i + 1];
      if (rtb_OpenCircuitVoltage < rtb_OCVInitial) {
        rtb_OpenCircuitVoltage = rtb_OCVInitial;
      }
    }

    *rty_Vmin = rtb_OpenCircuitVoltage;
    for (i = 0; i < 20; i++) {
      rtb_OCVInitial = localB->ConvBattVolt[i];
      if ((rtb_OCVInitial != 0) && (*rty_Vmin > rtb_OCVInitial)) {
        *rty_Vmin = rtb_OCVInitial;
      }
    }
  } else {
    rtb_OpenCircuitVoltage = localB->ConvBattVolt[0];
    for (i = 0; i < 19; i++) {
      rtb_OCVInitial = localB->ConvBattVolt[i + 1];
      if (rtb_OpenCircuitVoltage < rtb_OCVInitial) {
        rtb_OpenCircuitVoltage = rtb_OCVInitial;
      }
    }

    *rty_Vmin = rtb_OpenCircuitVoltage;
    for (i = 0; i < 20; i++) {
      rtb_OCVInitial = localB->ConvBattVolt[i];
      if ((rtb_OCVInitial != 0) && (*rty_Vmin > rtb_OCVInitial)) {
        *rty_Vmin = rtb_OCVInitial;
      }
    }
  }

  /* End of Chart: '<S83>/FindMinVolt' */

  /* Update for UnitDelay: '<S1>/udlyPackSoC' */
  localDW->udlyPackSoC_DSTATE = *rty_Batt_Pack_SOC;

  /* Update for UnitDelay: '<S89>/Delay Input1' incorporates:
   *  Switch: '<S81>/Switch1'
   *
   * Block description for '<S89>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtb_SOCAvgHystersis;

  /* Update for UnitDelay: '<S88>/Delay Input1'
   *
   * Block description for '<S88>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE_g = rtb_Compare_mx;

  /* Update for Memory: '<S93>/Memory' incorporates:
   *  CombinatorialLogic: '<S93>/Logic'
   */
  localDW->Memory_PreviousInput_c = rtCP_Logic_table_c[rtb_Logic_idx_0_tmp];

  /* Update for UnitDelay: '<S10>/udlyChgModeReq' */
  localDW->udlyChgModeReq_DSTATE = *rtu_Charger_Mode_Req;

  /* Update for Switch: '<S32>/selSoHsource' incorporates:
   *  UnitDelay: '<S1>/udlySoH'
   */
  localDW->udlySoH_DSTATE = *rty_SOH;

  /* Update for DiscreteIntegrator: '<S5>/DischargeAccumulator' */
  localDW->DischargeAccumulator_PrevResetS = (int8_T)rtb_IntegratorReset;

  /* Update for DiscreteIntegrator: '<S5>/CalcCurrAccum' */
  localDW->CalcCurrAccum_PrevResetState = (int8_T)rtb_Compare_c2;

  /* Update for UnitDelay: '<S48>/Delay Input1'
   *
   * Block description for '<S48>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE_f = *rty_SOCAvg;

  /* Update for UnitDelay: '<S33>/ZeroReset' incorporates:
   *  Constant: '<S33>/constZero'
   */
  localDW->ZeroReset_DSTATE = false;

  /* Update for UnitDelay: '<S33>/udlyDislaySoC' */
  localDW->udlyDislaySoC_DSTATE = *rty_Display_SOC;

  /* Update for UnitDelay: '<S33>/UDlySOC' */
  localDW->UDlySOC_DSTATE = *rty_Display_SOC;

  /* Update for UnitDelay: '<S33>/uDlySoC' */
  localDW->uDlySoC_DSTATE = *rty_Display_SOC;

  /* Update for Switch: '<S33>/selChargeSocCompensation' incorporates:
   *  UnitDelay: '<S33>/UdlySoc'
   */
  localDW->UdlySoc_DSTATE = *rty_Display_SOC;

  /* Update for UnitDelay: '<S51>/udlyEnableCurrent' */
  localDW->udlyEnableCurrent_DSTATE = localB->Compare_b;

  /* Update for UnitDelay: '<S33>/udlyDSoC' */
  localDW->udlyDSoC_DSTATE = *rty_Display_SOC;

  /* Update for UnitDelay: '<S33>/udlyDisplaySoC' */
  localDW->udlyDisplaySoC_DSTATE = *rty_Display_SOC;

  /* Update for UnitDelay: '<S25>/Delay Input1'
   *
   * Block description for '<S25>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE_j = *rtu_Ignition;

  /* Update for UnitDelay: '<S4>/udlyLifeCycle' */
  localDW->udlyLifeCycle_DSTATE = *rty_LifeCycle;

  /* Update for DiscreteIntegrator: '<S9>/Accumulate BattCurrent' */
  localDW->AccumulateBattCurrent_PrevReset = (int8_T)rtb_ChgStarted;

  /* Update for UnitDelay: '<S9>/udlyBMSMode' */
  localDW->udlyBMSMode_DSTATE = *rtu_sm_BMSMODE_en;

  /* Update for UnitDelay: '<S9>/udlyLifeCylce' */
  localDW->udlyLifeCylce_DSTATE = *rty_LifeCycle;

  /* Update for DiscreteIntegrator: '<S32>/CoulombCounter' */
  localDW->CoulombCounter_PrevResetState = (int8_T)
    TriggerswhentheBMSModeisDischar;

  /* Update for UnitDelay: '<S40>/Delay Input1'
   *
   * Block description for '<S40>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE_ju = rtb_Compare_cf;

  /* Update for UnitDelay: '<S1>/udlyStartSoC' */
  localDW->udlyStartSoC_DSTATE = rtb_Compare_c2;
}

/* Model initialize function */
void NBMS_SoC_initialize(const char_T **rt_errorStatus, RT_MODEL_NBMS_SoC_T *
  const NBMS_SoC_M, DW_NBMS_SoC_f_T *localDW, ZCE_NBMS_SoC_T *localZCE)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(NBMS_SoC_M, rt_errorStatus);

  /* Model Initialize function for ModelReference Block: '<S5>/DischgOCV' */
  NBMS_DischargeOCV_initialize(rtmGetErrorStatusPointer(NBMS_SoC_M),
    &(localDW->DischgOCV_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S81>/ChargeOCV' */
  NBMS_ChargeOCV_initialize(rtmGetErrorStatusPointer(NBMS_SoC_M),
    &(localDW->ChargeOCV_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S81>/DischargeOCV' */
  NBMS_DischargeOCV_initialize(rtmGetErrorStatusPointer(NBMS_SoC_M),
    &(localDW->DischargeOCV_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S81>/InitialChargeOCV' */
  NBMS_ChargeOCV_initialize(rtmGetErrorStatusPointer(NBMS_SoC_M),
    &(localDW->InitialChargeOCV_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S81>/InitialDichargeOCV' */
  NBMS_DischargeOCV_initialize(rtmGetErrorStatusPointer(NBMS_SoC_M),
    &(localDW->InitialDichargeOCV_InstanceData.rtm));
  localZCE->CalcOCV_Trig_ZCE = POS_ZCSIG;
  localZCE->Initial_SoC_Storage_Trig_ZCE = POS_ZCSIG;
  localZCE->LatchInitCapacity_Trig_ZCE = POS_ZCSIG;
  localZCE->LatchFullSoc_Trig_ZCE = POS_ZCSIG;
  localZCE->LatchTempinit_Trig_ZCE = POS_ZCSIG;
  localZCE->LatchSoC_Trig_ZCE = POS_ZCSIG;
  localZCE->InitPackTemperature_Trig_ZCE = POS_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
