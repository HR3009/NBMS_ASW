/*
 * File: NBMS_SoC.c
 *
 * Code generated for Simulink model 'NBMS_SoC'.
 *
 * Model version                  : 7.110
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 25 15:37:59 2026
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

/* Named constants for Chart: '<S60>/StateWaitCondition' */
#define NBMS_SoC_IN_In                 ((uint8_T)1U)
#define NBMS_SoC_IN_Out                ((uint8_T)2U)

/* Named constants for Chart: '<S6>/InitialSocManager' */
#define NBMS_SoC_IN_IgnOff             ((uint8_T)1U)
#define NBMS_SoC_IN_StoreInitialSOC    ((uint8_T)2U)

/* Named constants for Chart: '<S45>/SocStateController' */
#define NBMS_SoC_IN_entry              ((uint8_T)1U)
#define NBMS_SoC_IN_entry1             ((uint8_T)2U)
#define NBMS_SoC_IN_entry2             ((uint8_T)3U)
#define NBMS_SoC_IN_entry3             ((uint8_T)4U)

/* Named constants for Chart: '<S91>/SOC_Init_Decision' */
#define NBMS_SoC_IN_Charge             ((uint8_T)1U)
#define NBMS_SoC_IN_Default            ((uint8_T)2U)
#define NBMS_SoC_IN_Discharge          ((uint8_T)3U)

/*
 * Output and update for enable system:
 *    '<S93>/Moving Average'
 *    '<S93>/Moving Average1'
 *    '<S93>/Moving Average10'
 *    '<S93>/Moving Average11'
 *    '<S93>/Moving Average12'
 *    '<S93>/Moving Average13'
 *    '<S93>/Moving Average14'
 *    '<S93>/Moving Average15'
 *    '<S93>/Moving Average16'
 *    '<S93>/Moving Average17'
 *    ...
 */
void NBMS_SoC_MovingAverage(boolean_T rtu_EnableCellVoltValid, int16_T rtu_In,
  int16_T *rty_Out, DW_MovingAverage_NBMS_SoC_T *localDW)
{
  int_T i;

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average' incorporates:
   *  EnablePort: '<S135>/EnableCellVoltValid'
   */
  if (rtu_EnableCellVoltValid) {
    uint32_T tmp;
    uint8_T tmp_0;

    /* Sum: '<S135>/Counter' incorporates:
     *  Constant: '<S135>/CountStep'
     *  UnitDelay: '<S135>/Delayfor1Unit'
     */
    if (localDW->Delayfor1Unit_DSTATE < 256.0) {
      if (localDW->Delayfor1Unit_DSTATE >= 0.0) {
        tmp_0 = (uint8_T)localDW->Delayfor1Unit_DSTATE;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    tmp = tmp_0 + 1U;
    if (tmp_0 + 1U > 255U) {
      tmp = 255U;
    }

    localDW->Delayfor1Unit_DSTATE = tmp;

    /* End of Sum: '<S135>/Counter' */

    /* Switch: '<S135>/Counterfor20' incorporates:
     *  Constant: '<S135>/ZeroVt'
     *  Product: '<S135>/Average'
     *  Sum: '<S135>/SumofVoltage'
     *  Sum: '<S135>/TotalSum'
     *  UnitDelay: '<S135>/Delayfor1Unit'
     */
    if (localDW->Delayfor1Unit_DSTATE > 20.0) {
      int32_T y;

      /* Sum: '<S135>/SumofVoltage' incorporates:
       *  S-Function (sfix_udelay): '<S135>/20Delay'
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

    /* End of Switch: '<S135>/Counterfor20' */

    /* Update for S-Function (sfix_udelay): '<S135>/20Delay' */
    for (i = 0; i < 19; i++) {
      localDW->u0Delay_DWORK1[19 - i] = localDW->u0Delay_DWORK1[18 - i];
    }

    localDW->u0Delay_DWORK1[0] = rtu_In;

    /* End of Update for S-Function (sfix_udelay): '<S135>/20Delay' */
  }

  /* End of Outputs for SubSystem: '<S93>/Moving Average' */
}

/* System initialize for referenced model: 'NBMS_SoC' */
void NBMS_SoC_Init(boolean_T *rty_LOW_SOC, real_T *rty_FailSensorVolt, int16_T
                   *rty_FailSensorVoltAvg, B_NBMS_SoC_c_T *localB,
                   DW_NBMS_SoC_f_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S1>/udlyPackSoC' */
  localDW->udlyPackSoC_DSTATE = 1.0;

  /* InitializeConditions for Switch: '<S41>/selSoHsource' incorporates:
   *  UnitDelay: '<S1>/udlySoH'
   */
  localDW->udlySoH_DSTATE = 1.0;

  /* InitializeConditions for DiscreteIntegrator: '<S6>/DischargeAccumulator' */
  localDW->DischargeAccumulator_PrevResetS = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S6>/CalcCurrAccum' */
  localDW->CalcCurrAccum_PrevResetState = 2;

  /* InitializeConditions for UnitDelay: '<S42>/uDlySoC' */
  localDW->uDlySoC_DSTATE = 100U;

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
  localDW->UnitDelay_DSTATE = BMS_SLEEP;

  /* InitializeConditions for UnitDelay: '<S42>/ZeroReset' */
  localDW->ZeroReset_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S42>/udlyDSoC' */
  localDW->udlyDSoC_DSTATE = 100U;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Accumulate BattCurrent' */
  localDW->AccumulateBattCurrent_PrevReset = 2;

  /* InitializeConditions for UnitDelay: '<S17>/udlyBMSMode' */
  localDW->udlyBMSMode_DSTATE = BMS_SLEEP;

  /* InitializeConditions for DiscreteIntegrator: '<S41>/CoulombCounter' */
  localDW->CoulombCounter_PrevResetState = 2;

  /* SystemInitialize for Enabled SubSystem: '<S42>/LatchBattSoc' */
  /* InitializeConditions for UnitDelay: '<S61>/udlyBattSoC' */
  localDW->udlyBattSoC_DSTATE = 100.0;

  /* End of SystemInitialize for SubSystem: '<S42>/LatchBattSoc' */

  /* SystemInitialize for Enabled SubSystem: '<S18>/CalcChgMeasured' */
  /* InitializeConditions for DiscreteIntegrator: '<S23>/CalcAccumulatedBattCurr' */
  localDW->CalcAccumulatedBattCurr_PrevRes = 2;

  /* End of SystemInitialize for SubSystem: '<S18>/CalcChgMeasured' */

  /* SystemInitialize for SignalConversion generated from: '<Root>/LOW_SOC' */
  *rty_LOW_SOC = localB->Logic[0];

  /* SystemInitialize for Enabled SubSystem: '<S93>/OneSensorVoltFailure' */
  /* SystemInitialize for Outport: '<S155>/FailSensorVolt' */
  *rty_FailSensorVolt = 5.0;

  /* SystemInitialize for Outport: '<S155>/FailSensorVoltAvg' */
  *rty_FailSensorVoltAvg = 5000;

  /* End of SystemInitialize for SubSystem: '<S93>/OneSensorVoltFailure' */
}

/* Disable for referenced model: 'NBMS_SoC' */
void NBMS_SoC_Disable(boolean_T *rty_LOW_SOC_WARN_15, boolean_T *rty_LOW_SOC,
                      boolean_T *rty_LOW_SOC_WARN, real_T *rty_FailSensorVolt,
                      int16_T *rty_FailSensorVoltAvg, int16_T
                      *rty_BatteryCurrentAvg5sec, B_NBMS_SoC_c_T *localB,
                      DW_NBMS_SoC_f_T *localDW)
{
  /* Disable for ModelReference: '<S91>/InitialDichargeOCV' */
  NBMS_DischargeOCV_Disable(&localB->DischgInitialSoC,
    &(localDW->InitialDichargeOCV_InstanceData.rtdw));

  /* Disable for ModelReference: '<S91>/InitialChargeOCV' */
  NBMS_ChargeOCV_Disable(&localB->ChgInitialSoC,
    &(localDW->InitialChargeOCV_InstanceData.rtdw));

  /* Disable for Enabled SubSystem: '<S92>/MovingAverageCurrent2sec' */
  if (localDW->MovingAverageCurrent2sec_MODE) {
    /* Disable for RelationalOperator: '<S109>/Compare' incorporates:
     *  Outport: '<S107>/EnableCurrentMA'
     */
    localB->Compare_b = false;

    /* Disable for Switch: '<S107>/Sample Accumulator ' incorporates:
     *  Outport: '<S107>/BatteryCurrent'
     */
    localB->usecAvgBatteryCurrent = 0;
    localDW->MovingAverageCurrent2sec_MODE = false;
  }

  /* End of Disable for SubSystem: '<S92>/MovingAverageCurrent2sec' */

  /* Disable for ModelReference: '<S91>/ChargeOCV' */
  NBMS_ChargeOCV_Disable(&localB->ChgInitialSoC_b,
    &(localDW->ChargeOCV_InstanceData.rtdw));

  /* Disable for ModelReference: '<S91>/DischargeOCV' */
  NBMS_DischargeOCV_Disable(&localB->DischgInitialSoC_i,
    &(localDW->DischargeOCV_InstanceData.rtdw));

  /* Disable for ModelReference: '<S6>/DischgOCV' */
  NBMS_DischargeOCV_Disable(&localB->DischgInitialSoC_p,
    &(localDW->DischgOCV_InstanceData.rtdw));

  /* Disable for Enabled SubSystem: '<S1>/SOC Fault Detection' */
  if (localDW->SOCFaultDetection_MODE) {
    /* Disable for Outport: '<S7>/ LOW_SOC_WARN_15' */
    *rty_LOW_SOC_WARN_15 = false;

    /* Disable for Outport: '<S7>/ LOW_SOC' incorporates:
     *  CombinatorialLogic: '<S82>/Logic'
     */
    localB->Logic[0] = false;

    /* Disable for Outport: '<S7>/ LOW_SOC_WARN' */
    *rty_LOW_SOC_WARN = false;
    localDW->SOCFaultDetection_MODE = false;
  }

  /* End of Disable for SubSystem: '<S1>/SOC Fault Detection' */

  /* Disable for SignalConversion generated from: '<Root>/LOW_SOC' */
  *rty_LOW_SOC = localB->Logic[0];

  /* Disable for Enabled SubSystem: '<S92>/MovingAverageCurrent5sec' */
  if (localDW->MovingAverageCurrent5sec_MODE) {
    /* Disable for Outport: '<S108>/BatteryCurrent' */
    *rty_BatteryCurrentAvg5sec = 0;
    localDW->MovingAverageCurrent5sec_MODE = false;
  }

  /* End of Disable for SubSystem: '<S92>/MovingAverageCurrent5sec' */

  /* Disable for Enabled SubSystem: '<S93>/OneSensorVoltFailure' */
  if (localDW->OneSensorVoltFailure_MODE) {
    /* Disable for Outport: '<S155>/FailSensorVolt' */
    *rty_FailSensorVolt = 5.0;

    /* Disable for Outport: '<S155>/FailSensorVoltAvg' */
    *rty_FailSensorVoltAvg = 5000;
    localDW->OneSensorVoltFailure_MODE = false;
  }

  /* End of Disable for SubSystem: '<S93>/OneSensorVoltFailure' */
}

/* Output and update for referenced model: 'NBMS_SoC' */
void NBMS_SoC(const uint8_T *rtu_soc_full, const real_T rtu_Batt_Temps[6], const
              real_T *rtu_AppIn_BattCurrent, const real_T
              rtu_AppIn_BattVoltages[20], const boolean_T *rtu_Ignition_Sts,
              const Charger_Mode_Req_E *rtu_Charger_Mode_Req, const BMS_MODE_E
              *rtu_sm_BMSMODE_en, const real_T *rtu_AppIn_LastStoredSOC, const
              real_T *rtu_AppIn_LastStoredCycle, const boolean_T
              *rtu_AppIn_I2Cerror, const OBC_E *rtu_OBCWakeup, const real_T
              *rtu_mi_Pack_Volt, const VDU_MACHINE_STS_E
              *rtu_AppIn_MachineStatus, const real_T *rtu_DischrgCurrLimit,
              const boolean_T *rtu_RTC_Wakeup, const boolean_T
              *rtu_AppIn_SoCLEDSW, const boolean_T *rtu_EEPROM_SOC_WARN15,
              uint8_T *rty_Display_SOC, real_T *rty_Battery_Capacity, boolean_T *
              rty_LOW_SOC_WARN_15, boolean_T *rty_LOW_SOC, boolean_T
              *rty_LOW_SOC_WARN, real_T *rty_Batt_Pack_SOC, real_T
              *rty_LifeCycle, int16_T *rty_VtAvgMax, real_T *rty_CurrentCapacity,
              uint16_T *rty_SOCcc, uint16_T *rty_SOCAvg, int16_T *rty_Vmin,
              real_T *rty_SOC_OCVInit, real_T *rty_SOCAvgInitial, real_T
              *rty_AvailableEnergy, int16_T *rty_VtAvgMin, real_T
              *rty_FailSensorVolt, int16_T *rty_FailSensorVoltAvg, int16_T
              *rty_BatteryCurrentAvg5sec, real_T *rty_ChargeCapacity,
              BMS_BattTempDerate_E *rty_Batt_Temp_Derating, BMS_BattSoCDerate_E *
              rty_Batt_SoC_Derating, B_NBMS_SoC_c_T *localB, DW_NBMS_SoC_f_T
              *localDW, ZCE_NBMS_SoC_T *localZCE)
{
  real_T maxV;
  real_T rtb_ArbitratedInitSoc;
  real_T rtb_ScaledDOD;
  real_T rtb_SumofAvgVolt_0;
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
  uint16_T rtb_SoCcc_a;
  uint8_T rtb_Init;
  boolean_T rtb_Compare_ei[20];
  boolean_T TriggerswhentheBMSModeisDischar;
  boolean_T rtb_AND;
  boolean_T rtb_ChgStarted;
  boolean_T rtb_Compare_bn;
  boolean_T rtb_Compare_c2;
  boolean_T rtb_Compare_mx;
  boolean_T rtb_Compare_o1;
  boolean_T rtb_Compare_pt;
  boolean_T rtb_IntegratorReset;
  boolean_T tmp;
  for (i = 0; i < 20; i++) {
    /* DataTypeConversion: '<S1>/ConvertToFixdt' */
    rtb_SumofAvgVolt_0 = floor(rtu_AppIn_BattVoltages[i] / 0.001);
    if (rtIsNaN(rtb_SumofAvgVolt_0) || rtIsInf(rtb_SumofAvgVolt_0)) {
      rtb_SumofAvgVolt_0 = 0.0;
    } else {
      rtb_SumofAvgVolt_0 = fmod(rtb_SumofAvgVolt_0, 65536.0);
    }

    if (rtb_SumofAvgVolt_0 < 0.0) {
      /* DataTypeConversion: '<S1>/ConvertToFixdt' */
      rtb_OCVInitial = (int16_T)-(int16_T)(uint16_T)-rtb_SumofAvgVolt_0;
    } else {
      /* DataTypeConversion: '<S1>/ConvertToFixdt' */
      rtb_OCVInitial = (int16_T)(uint16_T)rtb_SumofAvgVolt_0;
    }

    /* End of DataTypeConversion: '<S1>/ConvertToFixdt' */

    /* DataTypeConversion: '<S1>/ConvertToFixdt' */
    localB->ConvBattVolt[i] = rtb_OCVInitial;

    /* RelationalOperator: '<S134>/Compare' incorporates:
     *  DataTypeConversion: '<S1>/ConvertToFixdt'
     */
    rtb_Compare_ei[i] = (rtb_OCVInitial != 0);
  }

  /* MinMax: '<S1>/CalcMaxTemp' */
  maxV = rtu_Batt_Temps[0];
  for (i = 0; i < 5; i++) {
    maxV = fmax(maxV, rtu_Batt_Temps[i + 1]);
  }

  /* Outputs for Triggered SubSystem: '<S91>/InitPackTemperature' incorporates:
   *  TriggerPort: '<S100>/TrigWhenValid'
   */
  if (*rtu_Ignition_Sts && (localZCE->InitPackTemperature_Trig_ZCE != POS_ZCSIG))
  {
    /* SignalConversion generated from: '<S100>/Temp' incorporates:
     *  MinMax: '<S1>/CalcMaxTemp'
     */
    localB->InitialTemp = maxV;
  }

  localZCE->InitPackTemperature_Trig_ZCE = *rtu_Ignition_Sts;

  /* End of Outputs for SubSystem: '<S91>/InitPackTemperature' */

  /* Outputs for Triggered SubSystem: '<S1>/CalcOCV' incorporates:
   *  TriggerPort: '<S2>/Trigger'
   */
  if (*rtu_Ignition_Sts && (localZCE->CalcOCV_Trig_ZCE != POS_ZCSIG)) {
    /* Product: '<S2>/CalcSingleCellVolt' incorporates:
     *  Constant: '<S2>/TotalCellinSeries'
     */
    *rty_SOC_OCVInit = *rtu_mi_Pack_Volt / 20.0;
  }

  /* Outputs for Triggered SubSystem: '<S91>/InitPackTemperature' incorporates:
   *  TriggerPort: '<S100>/TrigWhenValid'
   */
  localZCE->CalcOCV_Trig_ZCE = *rtu_Ignition_Sts;

  /* End of Outputs for SubSystem: '<S91>/InitPackTemperature' */
  /* End of Outputs for SubSystem: '<S1>/CalcOCV' */

  /* DataTypeConversion: '<S1>/FixdtTypeConvert' */
  rtb_SumofAvgVolt_0 = floor(*rty_SOC_OCVInit / 0.001);
  if (rtIsNaN(rtb_SumofAvgVolt_0) || rtIsInf(rtb_SumofAvgVolt_0)) {
    rtb_SumofAvgVolt_0 = 0.0;
  } else {
    rtb_SumofAvgVolt_0 = fmod(rtb_SumofAvgVolt_0, 65536.0);
  }

  if (rtb_SumofAvgVolt_0 < 0.0) {
    rtb_OCVInitial = (int16_T)-(int16_T)(uint16_T)-rtb_SumofAvgVolt_0;
  } else {
    rtb_OCVInitial = (int16_T)(uint16_T)rtb_SumofAvgVolt_0;
  }

  /* End of DataTypeConversion: '<S1>/FixdtTypeConvert' */

  /* Chart: '<S91>/SOC_Init_Decision' */
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
      if (*rtu_sm_BMSMODE_en == BMS_CHARGE) {
        localDW->is_SOC_Init = NBMS_SoC_IN_Charge;
        rtb_Init = 1U;
      } else if ((*rtu_sm_BMSMODE_en == BMS_DISCHARGE) || *rtu_RTC_Wakeup ||
                 *rtu_AppIn_SoCLEDSW || (*rtu_sm_BMSMODE_en == BMS_FAULT)) {
        localDW->is_SOC_Init = NBMS_SoC_IN_Discharge;
        rtb_Init = 2U;
      }
      break;

     default:
      /* case IN_Discharge: */
      rtb_Init = 2U;
      if (!*rtu_Ignition_Sts) {
        localDW->is_SOC_Init = NBMS_SoC_IN_Default;
        rtb_Init = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S91>/SOC_Init_Decision' */

  /* RelationalOperator: '<S96>/Compare' incorporates:
   *  Constant: '<S96>/Constant'
   */
  localB->Compare = (rtb_Init == 2);

  /* ModelReference: '<S91>/InitialDichargeOCV' */
  NBMS_DischargeOCV(&localB->InitialTemp, &rtb_OCVInitial, &localB->Compare,
                    &localB->DischgInitialSoC,
                    &(localDW->InitialDichargeOCV_InstanceData.rtdw));

  /* RelationalOperator: '<S95>/Compare' incorporates:
   *  Constant: '<S95>/Constant'
   */
  localB->Compare_k = (rtb_Init == 1);

  /* ModelReference: '<S91>/InitialChargeOCV' */
  NBMS_ChargeOCV(&localB->InitialTemp, &rtb_OCVInitial, &localB->Compare_k,
                 &localB->ChgInitialSoC,
                 &(localDW->InitialChargeOCV_InstanceData.rtdw));

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average' */
  /* RelationalOperator: '<S111>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[0] != 0), localB->ConvBattVolt[0],
    &localB->AvgVoltofCell0, &localDW->MovingAverage);

  /* End of Outputs for SubSystem: '<S93>/Moving Average' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average1' */
  /* RelationalOperator: '<S112>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[1] != 0), localB->ConvBattVolt[1],
    &localB->AvgVoltofCell1, &localDW->MovingAverage1);

  /* End of Outputs for SubSystem: '<S93>/Moving Average1' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average2' */
  /* RelationalOperator: '<S123>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[2] != 0), localB->ConvBattVolt[2],
    &localB->AvgVoltofCell2, &localDW->MovingAverage2);

  /* End of Outputs for SubSystem: '<S93>/Moving Average2' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average3' */
  /* RelationalOperator: '<S124>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[3] != 0), localB->ConvBattVolt[3],
    &localB->AvgVoltofCell3, &localDW->MovingAverage3);

  /* End of Outputs for SubSystem: '<S93>/Moving Average3' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average4' */
  /* RelationalOperator: '<S125>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[4] != 0), localB->ConvBattVolt[4],
    &localB->AvgVoltofCell4, &localDW->MovingAverage4);

  /* End of Outputs for SubSystem: '<S93>/Moving Average4' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average5' */
  /* RelationalOperator: '<S126>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[5] != 0), localB->ConvBattVolt[5],
    &localB->AvgVoltofCell5, &localDW->MovingAverage5);

  /* End of Outputs for SubSystem: '<S93>/Moving Average5' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average6' */
  /* RelationalOperator: '<S127>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[6] != 0), localB->ConvBattVolt[6],
    &localB->AvgVoltofCell6, &localDW->MovingAverage6);

  /* End of Outputs for SubSystem: '<S93>/Moving Average6' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average7' */
  /* RelationalOperator: '<S128>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[7] != 0), localB->ConvBattVolt[7],
    &localB->AvgVoltofCell7, &localDW->MovingAverage7);

  /* End of Outputs for SubSystem: '<S93>/Moving Average7' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average8' */
  /* RelationalOperator: '<S129>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[8] != 0), localB->ConvBattVolt[8],
    &localB->AvgVoltofCell8, &localDW->MovingAverage8);

  /* End of Outputs for SubSystem: '<S93>/Moving Average8' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average9' */
  /* RelationalOperator: '<S130>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[9] != 0), localB->ConvBattVolt[9],
    &localB->AvgVoltofCell9, &localDW->MovingAverage9);

  /* End of Outputs for SubSystem: '<S93>/Moving Average9' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average10' */
  /* RelationalOperator: '<S113>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[10] != 0), localB->ConvBattVolt
    [10], &localB->AvgVoltofCell10, &localDW->MovingAverage10);

  /* End of Outputs for SubSystem: '<S93>/Moving Average10' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average11' */
  /* RelationalOperator: '<S114>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[11] != 0), localB->ConvBattVolt
    [11], &localB->AvgVoltofCell11, &localDW->MovingAverage11);

  /* End of Outputs for SubSystem: '<S93>/Moving Average11' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average12' */
  /* RelationalOperator: '<S115>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[12] != 0), localB->ConvBattVolt
    [12], &localB->AvgVoltofCell12, &localDW->MovingAverage12);

  /* End of Outputs for SubSystem: '<S93>/Moving Average12' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average13' */
  /* RelationalOperator: '<S116>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[13] != 0), localB->ConvBattVolt
    [13], &localB->AvgVoltofCell13, &localDW->MovingAverage13);

  /* End of Outputs for SubSystem: '<S93>/Moving Average13' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average14' */
  /* RelationalOperator: '<S117>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[14] != 0), localB->ConvBattVolt
    [14], &localB->AvgVoltofCell14, &localDW->MovingAverage14);

  /* End of Outputs for SubSystem: '<S93>/Moving Average14' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average15' */
  /* RelationalOperator: '<S118>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[15] != 0), localB->ConvBattVolt
    [15], &localB->AvgVoltofCell15, &localDW->MovingAverage15);

  /* End of Outputs for SubSystem: '<S93>/Moving Average15' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average16' */
  /* RelationalOperator: '<S119>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[16] != 0), localB->ConvBattVolt
    [16], &localB->AvgVoltofCell16, &localDW->MovingAverage16);

  /* End of Outputs for SubSystem: '<S93>/Moving Average16' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average17' */
  /* RelationalOperator: '<S120>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[17] != 0), localB->ConvBattVolt
    [17], &localB->AvgVoltofCell17, &localDW->MovingAverage17);

  /* End of Outputs for SubSystem: '<S93>/Moving Average17' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average18' */
  /* RelationalOperator: '<S121>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[18] != 0), localB->ConvBattVolt
    [18], &localB->AvgVoltofCell18, &localDW->MovingAverage18);

  /* End of Outputs for SubSystem: '<S93>/Moving Average18' */

  /* Outputs for Enabled SubSystem: '<S93>/Moving Average19' */
  /* RelationalOperator: '<S122>/Compare' */
  NBMS_SoC_MovingAverage((localB->ConvBattVolt[19] != 0), localB->ConvBattVolt
    [19], &localB->AvgVoltofCell19, &localDW->MovingAverage19);

  /* End of Outputs for SubSystem: '<S93>/Moving Average19' */

  /* RelationalOperator: '<S105>/Compare' incorporates:
   *  Constant: '<S105>/Constant'
   */
  rtb_Compare_o1 = (*rtu_sm_BMSMODE_en != BMS_SLEEP);

  /* Outputs for Enabled SubSystem: '<S92>/MovingAverageCurrent2sec' incorporates:
   *  EnablePort: '<S107>/Enable'
   */
  if (rtb_Compare_o1) {
    if (!localDW->MovingAverageCurrent2sec_MODE) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S107>/20Delay' */
      for (i = 0; i < 20; i++) {
        localDW->u0Delay_DWORK1_p[i] = 0;
      }

      /* End of InitializeConditions for S-Function (sfix_udelay): '<S107>/20Delay' */

      /* InitializeConditions for UnitDelay: '<S107>/1UnitDelay' */
      localDW->uUnitDelay_DSTATE_f = 0U;
      localDW->MovingAverageCurrent2sec_MODE = true;
    }

    /* Switch: '<S92>/SelectBattCurrOutput' incorporates:
     *  Constant: '<S104>/Constant'
     *  Logic: '<S92>/ChkDischgValid'
     *  RelationalOperator: '<S104>/Compare'
     *  RelationalOperator: '<S92>/CheckCurrentWithinLimit'
     */
    if ((*rtu_AppIn_MachineStatus == DRIVE) && (*rtu_AppIn_BattCurrent <=
         *rtu_DischrgCurrLimit)) {
      /* DataTypeConversion: '<S107>/ConvertToFixdt' */
      rtb_SumofAvgVolt_0 = floor(*rtu_DischrgCurrLimit / 0.01);
      if (rtIsNaN(rtb_SumofAvgVolt_0) || rtIsInf(rtb_SumofAvgVolt_0)) {
        rtb_SumofAvgVolt_0 = 0.0;
      } else {
        rtb_SumofAvgVolt_0 = fmod(rtb_SumofAvgVolt_0, 65536.0);
      }

      if (rtb_SumofAvgVolt_0 < 0.0) {
        /* DataTypeConversion: '<S107>/ConvertToFixdt' */
        localB->u1stSample_d = (int16_T)-(int16_T)(uint16_T)-rtb_SumofAvgVolt_0;
      } else {
        /* DataTypeConversion: '<S107>/ConvertToFixdt' */
        localB->u1stSample_d = (int16_T)(uint16_T)rtb_SumofAvgVolt_0;
      }
    } else {
      /* DataTypeConversion: '<S107>/ConvertToFixdt' */
      rtb_SumofAvgVolt_0 = floor(*rtu_AppIn_BattCurrent / 0.01);
      if (rtIsNaN(rtb_SumofAvgVolt_0) || rtIsInf(rtb_SumofAvgVolt_0)) {
        rtb_SumofAvgVolt_0 = 0.0;
      } else {
        rtb_SumofAvgVolt_0 = fmod(rtb_SumofAvgVolt_0, 65536.0);
      }

      if (rtb_SumofAvgVolt_0 < 0.0) {
        /* DataTypeConversion: '<S107>/ConvertToFixdt' */
        localB->u1stSample_d = (int16_T)-(int16_T)(uint16_T)-rtb_SumofAvgVolt_0;
      } else {
        /* DataTypeConversion: '<S107>/ConvertToFixdt' */
        localB->u1stSample_d = (int16_T)(uint16_T)rtb_SumofAvgVolt_0;
      }
    }

    /* End of Switch: '<S92>/SelectBattCurrOutput' */

    /* Sum: '<S107>/Counter' incorporates:
     *  Constant: '<S107>/CountStep'
     *  UnitDelay: '<S107>/1UnitDelay'
     */
    rowIdx = localDW->uUnitDelay_DSTATE_f + 1U;
    if (localDW->uUnitDelay_DSTATE_f + 1U > 255U) {
      rowIdx = 255U;
    }

    localDW->uUnitDelay_DSTATE_f = (uint8_T)rowIdx;

    /* End of Sum: '<S107>/Counter' */

    /* RelationalOperator: '<S109>/Compare' incorporates:
     *  Constant: '<S109>/Constant'
     *  UnitDelay: '<S107>/1UnitDelay'
     */
    localB->Compare_b = (localDW->uUnitDelay_DSTATE_f > 20);

    /* Switch: '<S107>/Sample Accumulator ' */
    if (localB->Compare_b) {
      /* Sum: '<S107>/SumofCurrent' incorporates:
       *  S-Function (sfix_udelay): '<S107>/20Delay'
       */
      y = 0;
      for (i = 0; i < 20; i++) {
        y += localDW->u0Delay_DWORK1_p[i];
      }

      /* Switch: '<S107>/Sample Accumulator ' incorporates:
       *  DataTypeConversion: '<S107>/ConvertToFixdt'
       *  Product: '<S107>/Average'
       *  Sum: '<S107>/Sumof21Samples'
       *  Sum: '<S107>/SumofCurrent'
       */
      localB->usecAvgBatteryCurrent = (int16_T)(((int16_T)
        div_nzp_repeat_s32_floor(y + localB->u1stSample_d, 525, 4U) * 25) >> 4);
    } else {
      /* Switch: '<S107>/Sample Accumulator ' incorporates:
       *  Constant: '<S107>/ConstZeroCurrent'
       */
      localB->usecAvgBatteryCurrent = 0;
    }

    /* End of Switch: '<S107>/Sample Accumulator ' */

    /* Update for S-Function (sfix_udelay): '<S107>/20Delay' incorporates:
     *  DataTypeConversion: '<S107>/ConvertToFixdt'
     */
    for (i = 0; i < 19; i++) {
      localDW->u0Delay_DWORK1_p[i] = localDW->u0Delay_DWORK1_p[i + 1];
    }

    localDW->u0Delay_DWORK1_p[19] = localB->u1stSample_d;

    /* End of Update for S-Function (sfix_udelay): '<S107>/20Delay' */
  } else if (localDW->MovingAverageCurrent2sec_MODE) {
    /* Disable for RelationalOperator: '<S109>/Compare' incorporates:
     *  Outport: '<S107>/EnableCurrentMA'
     */
    localB->Compare_b = false;

    /* Disable for Switch: '<S107>/Sample Accumulator ' incorporates:
     *  Outport: '<S107>/BatteryCurrent'
     */
    localB->usecAvgBatteryCurrent = 0;
    localDW->MovingAverageCurrent2sec_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S92>/MovingAverageCurrent2sec' */

  /* RelationalOperator: '<S47>/Compare' incorporates:
   *  Constant: '<S47>/Constant'
   */
  rtb_Compare_c2 = (*rtu_sm_BMSMODE_en != BMS_SLEEP);

  /* CombinatorialLogic: '<S59>/Logic' incorporates:
   *  CombinatorialLogic: '<S103>/Logic'
   *  Logic: '<S42>/StartSocCalcPermissive'
   *  Memory: '<S59>/Memory'
   *  RelationalOperator: '<S64>/Compare'
   */
  rtb_Logic_idx_0_tmp = (uint32_T)!*rtu_Ignition_Sts;

  /* Outputs for Enabled SubSystem: '<S42>/LatchBattSoc' incorporates:
   *  EnablePort: '<S61>/Enable'
   */
  localDW->Memory_PreviousInput = rtCP_Logic_table_o[((((uint32_T)
    (rtb_Compare_c2 && localB->Compare_b) << 1U) + rtb_Logic_idx_0_tmp) << 1U) +
    localDW->Memory_PreviousInput];

  /* Sum: '<S93>/CountofNonZeroCellVolt' incorporates:
   *  RelationalOperator: '<S134>/Compare'
   */
  rtb_CountofNonZeroCell_0 = 0;
  for (i = 0; i < 20; i++) {
    rtb_CountofNonZeroCell_0 += rtb_Compare_ei[i];
  }

  /* Switch: '<S93>/selAvgVolt' incorporates:
   *  Constant: '<S93>/zeroavgvt'
   *  Product: '<S93>/Average'
   *  Sum: '<S93>/CountofNonZeroCellVolt'
   */
  if (rtb_CountofNonZeroCell_0 > 0) {
    /* Sum: '<S93>/SumofAvgVolt' */
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
    rtb_SumofAvgVolt_0 = 0.0;
    for (i = 0; i < 20; i++) {
      rtb_SumofAvgVolt_0 += (real_T)tmpForInput[i] * 0.001;
    }

    /* Product: '<S93>/Average' incorporates:
     *  Sum: '<S93>/SumofAvgVolt'
     */
    i = (int32_T)fmod(floor(rtb_SumofAvgVolt_0 / (real_T)
      rtb_CountofNonZeroCell_0 / 0.01), 65536.0);
    if (i < 0) {
      i = (uint16_T)-(int16_T)(uint16_T)-(real_T)i;
    } else {
      i = (uint16_T)i;
    }

    rtb_ScaledDOD = (real_T)i * 0.01;
  } else {
    rtb_ScaledDOD = 0.0;
  }

  /* End of Switch: '<S93>/selAvgVolt' */

  /* Switch: '<S92>/selInternalResistance' incorporates:
   *  Constant: '<S106>/Constant'
   *  Lookup_n-D: '<S92>/DCIRCharge'
   *  Lookup_n-D: '<S92>/DCIRdisCharge'
   *  MinMax: '<S1>/CalcMaxTemp'
   *  RelationalOperator: '<S106>/Compare'
   *  UnitDelay: '<S1>/udlyPackSoC'
   */
  if (*rtu_sm_BMSMODE_en == BMS_CHARGE) {
    rtb_ArbitratedInitSoc = look2_binlcpw(maxV, localDW->udlyPackSoC_DSTATE,
      &X_DCIR_CHG[0], &Y_DCIR_CHG[0], rtCP_DCIRCharge_tableData,
      rtCP_DCIRCharge_maxIndex, 7U);
  } else {
    rtb_ArbitratedInitSoc = look2_binlcpw(maxV, localDW->udlyPackSoC_DSTATE,
      &X_DCIR_DISCH[0], &Y_DCIR_DISCH[0], rtCP_DCIRdisCharge_tableData,
      rtCP_DCIRdisCharge_maxIndex, 7U);
  }

  /* End of Switch: '<S92>/selInternalResistance' */

  /* Sum: '<S91>/VoltDiff' incorporates:
   *  Constant: '<S92>/TotalCellsInParallel'
   *  Product: '<S92>/CalcOneCellCurrent'
   *  Product: '<S92>/CalcVoltage'
   *  Sum: '<S93>/MaxVoltDiff'
   *  Sum: '<S93>/MinVoltDiff'
   *  Switch: '<S107>/Sample Accumulator '
   */
  rtb_SumofAvgVolt_0 = floor((real_T)localB->usecAvgBatteryCurrent * 0.01 / 7.0 *
    rtb_ArbitratedInitSoc / 0.001);
  tmp = (rtIsNaN(rtb_SumofAvgVolt_0) || rtIsInf(rtb_SumofAvgVolt_0));
  if (tmp) {
    rtb_ArbitratedInitSoc = 0.0;
  } else {
    rtb_ArbitratedInitSoc = fmod(rtb_SumofAvgVolt_0, 65536.0);
  }

  if (rtb_ArbitratedInitSoc < 0.0) {
    i = (int16_T)-(int16_T)(uint16_T)-rtb_ArbitratedInitSoc;
  } else {
    i = (int16_T)(uint16_T)rtb_ArbitratedInitSoc;
  }

  rtb_OpenCircuitVoltage = (int16_T)((int16_T)(int32_T)fmod(floor(rtb_ScaledDOD /
    0.001), 65536.0) - i);

  /* End of Sum: '<S91>/VoltDiff' */

  /* RelationalOperator: '<S101>/Compare' incorporates:
   *  Constant: '<S101>/Constant'
   */
  localB->Compare_h = (*rtu_sm_BMSMODE_en == BMS_CHARGE);

  /* ModelReference: '<S91>/ChargeOCV' incorporates:
   *  MinMax: '<S1>/CalcMaxTemp'
   */
  NBMS_ChargeOCV(&maxV, &rtb_OpenCircuitVoltage, &localB->Compare_h,
                 &localB->ChgInitialSoC_b,
                 &(localDW->ChargeOCV_InstanceData.rtdw));

  /* RelationalOperator: '<S94>/Compare' incorporates:
   *  Constant: '<S94>/Constant'
   */
  rtb_Compare_bn = (*rtu_sm_BMSMODE_en == BMS_CHARGE);

  /* Logic: '<S91>/logIsNotCharging' incorporates:
   *  Logic: '<S41>/ChkIsBMSModeNotCharge'
   */
  TriggerswhentheBMSModeisDischar = !rtb_Compare_bn;

  /* Logic: '<S91>/logIsNotCharging' */
  localB->TriggerswhentheBMSModeisDischar = TriggerswhentheBMSModeisDischar;

  /* ModelReference: '<S91>/DischargeOCV' incorporates:
   *  MinMax: '<S1>/CalcMaxTemp'
   */
  NBMS_DischargeOCV(&maxV, &rtb_OpenCircuitVoltage,
                    &localB->TriggerswhentheBMSModeisDischar,
                    &localB->DischgInitialSoC_i,
                    &(localDW->DischargeOCV_InstanceData.rtdw));

  /* Switch: '<S91>/Switch1' */
  if (rtb_Compare_bn) {
    rtb_ArbitratedInitSoc = floor(localB->ChgInitialSoC_b / 0.01);
    if (rtIsNaN(rtb_ArbitratedInitSoc) || rtIsInf(rtb_ArbitratedInitSoc)) {
      rtb_ArbitratedInitSoc = 0.0;
    } else {
      rtb_ArbitratedInitSoc = fmod(rtb_ArbitratedInitSoc, 65536.0);
    }

    if (rtb_ArbitratedInitSoc < 0.0) {
      rtb_SOCAvgHystersis = (uint16_T)-(int16_T)(uint16_T)-rtb_ArbitratedInitSoc;
    } else {
      rtb_SOCAvgHystersis = (uint16_T)rtb_ArbitratedInitSoc;
    }
  } else {
    rtb_ArbitratedInitSoc = floor(localB->DischgInitialSoC_i / 0.01);
    if (rtIsNaN(rtb_ArbitratedInitSoc) || rtIsInf(rtb_ArbitratedInitSoc)) {
      rtb_ArbitratedInitSoc = 0.0;
    } else {
      rtb_ArbitratedInitSoc = fmod(rtb_ArbitratedInitSoc, 65536.0);
    }

    if (rtb_ArbitratedInitSoc < 0.0) {
      rtb_SOCAvgHystersis = (uint16_T)-(int16_T)(uint16_T)-rtb_ArbitratedInitSoc;
    } else {
      rtb_SOCAvgHystersis = (uint16_T)rtb_ArbitratedInitSoc;
    }
  }

  /* End of Switch: '<S91>/Switch1' */

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   */
  rtb_Compare_mx = (*rtu_OBCWakeup == Wake_Up);

  /* CombinatorialLogic: '<S103>/Logic' incorporates:
   *  Logic: '<S91>/SoCResetReq'
   *  Memory: '<S103>/Memory'
   *  RelationalOperator: '<S98>/FixPt Relational Operator'
   *  RelationalOperator: '<S99>/FixPt Relational Operator'
   *  Switch: '<S91>/Switch1'
   *  UnitDelay: '<S57>/Delay Input1'
   *  UnitDelay: '<S98>/Delay Input1'
   *  UnitDelay: '<S99>/Delay Input1'
   *
   * Block description for '<S57>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S98>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S99>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Logic_idx_0_tmp = ((((uint32_T)((rtb_SOCAvgHystersis !=
    localDW->DelayInput1_DSTATE) || ((int32_T)rtb_Compare_mx > (int32_T)
    localDW->DelayInput1_DSTATE_g)) << 1U) + rtb_Logic_idx_0_tmp) << 1U) +
    localDW->Memory_PreviousInput_c;

  /* MultiPortSwitch: '<S91>/Multiport Switch' */
  switch (rtb_Init) {
   case 0:
    rtb_ArbitratedInitSoc = localB->DischgInitialSoC;
    break;

   case 1:
    rtb_ArbitratedInitSoc = localB->ChgInitialSoC;
    break;

   default:
    rtb_ArbitratedInitSoc = localB->DischgInitialSoC;
    break;
  }

  /* End of MultiPortSwitch: '<S91>/Multiport Switch' */

  /* DataTypeConversion: '<S91>/ConvertToFixdt' */
  rtb_ArbitratedInitSoc = floor(rtb_ArbitratedInitSoc / 0.01);
  if (rtIsNaN(rtb_ArbitratedInitSoc) || rtIsInf(rtb_ArbitratedInitSoc)) {
    rtb_ArbitratedInitSoc = 0.0;
  } else {
    rtb_ArbitratedInitSoc = fmod(rtb_ArbitratedInitSoc, 65536.0);
  }

  if (rtb_ArbitratedInitSoc < 0.0) {
    rtb_InitialSoCAvg = (uint16_T)-(int16_T)(uint16_T)-rtb_ArbitratedInitSoc;
  } else {
    rtb_InitialSoCAvg = (uint16_T)rtb_ArbitratedInitSoc;
  }

  /* End of DataTypeConversion: '<S91>/ConvertToFixdt' */

  /* Switch: '<S91>/Switch2' incorporates:
   *  CombinatorialLogic: '<S103>/Logic'
   *  DataTypeConversion: '<S91>/ConvertToFixdt'
   *  Switch: '<S91>/Switch1'
   *  UnitDelay: '<S57>/Delay Input1'
   *  UnitDelay: '<S99>/Delay Input1'
   *
   * Block description for '<S57>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S99>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (rtCP_Logic_table_c[rtb_Logic_idx_0_tmp + 8U]) {
    localDW->DelayInput1_DSTATE = rtb_InitialSoCAvg;
  } else {
    localDW->DelayInput1_DSTATE = rtb_SOCAvgHystersis;
  }

  /* End of Switch: '<S91>/Switch2' */

  /* Saturate: '<S91>/SoCBoundaries' incorporates:
   *  UnitDelay: '<S57>/Delay Input1'
   *  UnitDelay: '<S99>/Delay Input1'
   *
   * Block description for '<S57>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S99>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (localDW->DelayInput1_DSTATE <= 10000) {
    *rty_SOCAvg = localDW->DelayInput1_DSTATE;
  } else {
    *rty_SOCAvg = 10000U;
  }

  /* End of Saturate: '<S91>/SoCBoundaries' */

  /* UnitDelay: '<S57>/Delay Input1' incorporates:
   *  UnitDelay: '<S99>/Delay Input1'
   *
   * Block description for '<S57>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S99>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = localDW->DelayInput1_DSTATE_f;

  /* RelationalOperator: '<S76>/Compare' incorporates:
   *  Constant: '<S76>/Constant'
   */
  rtb_Compare_pt = (*rtu_Charger_Mode_Req == Charge_Complete);

  /* Outputs for Triggered SubSystem: '<S45>/LatchSoC' incorporates:
   *  TriggerPort: '<S78>/Trigger'
   */
  if (rtb_Compare_pt && (localZCE->LatchSoC_Trig_ZCE != POS_ZCSIG)) {
    /* SignalConversion generated from: '<S78>/SOC_Full' */
    localB->SoC = *rtu_soc_full;
  }

  localZCE->LatchSoC_Trig_ZCE = rtb_Compare_pt;

  /* End of Outputs for SubSystem: '<S45>/LatchSoC' */

  /* Switch: '<S36>/selBatteryCapacitySource' incorporates:
   *  Constant: '<S36>/CalDOD'
   *  Constant: '<S36>/CalGoldenDC'
   *  Constant: '<S36>/CalSoHEnable'
   *  Gain: '<S36>/gainDCscale'
   *  Gain: '<S36>/gainDODscale'
   *  Product: '<S36>/CalcActualCapacity'
   *  Product: '<S36>/CalcCapacity'
   *  UnitDelay: '<S1>/udlySoH'
   */
  if (CAL_SOH_Enable) {
    *rty_Battery_Capacity = 0.0009999871253967285 * (real_T)CAL_GOLDEN_DC *
      (0.010009765625 * (real_T)CAL_DOD) * localDW->udlySoH_DSTATE;
  } else {
    *rty_Battery_Capacity = 0.0009999871253967285 * (real_T)CAL_GOLDEN_DC *
      (0.010009765625 * (real_T)CAL_DOD);
  }

  /* End of Switch: '<S36>/selBatteryCapacitySource' */

  /* Logic: '<S6>/InvertState' incorporates:
   *  DiscreteIntegrator: '<S6>/CalcCurrAccum'
   */
  rtb_AND = !rtb_Compare_c2;

  /* Logic: '<S6>/IntegratorResetTrigger' incorporates:
   *  Constant: '<S39>/Constant'
   *  Logic: '<S6>/InvertState'
   *  RelationalOperator: '<S39>/Compare'
   */
  rtb_IntegratorReset = ((*rtu_Charger_Mode_Req == Charge_Complete) || rtb_AND);

  /* DiscreteIntegrator: '<S6>/DischargeAccumulator' incorporates:
   *  DiscreteIntegrator: '<S6>/CalcCurrAccum'
   *  Gain: '<S6>/gainSecToHourScale'
   *  Gain: '<S6>/scaleBattCurr'
   *  Product: '<S6>/divCurrentToCapacityRatio'
   *  Switch: '<S107>/Sample Accumulator '
   */
  if (rtb_IntegratorReset && (localDW->DischargeAccumulator_PrevResetS <= 0)) {
    localDW->DischargeAccumulator_DSTATE = 0.0;
  }

  rtb_ArbitratedInitSoc = -32768.0 * (real_T)localB->usecAvgBatteryCurrent *
    3.0517578125E-7 / *rty_Battery_Capacity * 0.0002777777777777778 * 0.1;

  /* DiscreteIntegrator: '<S6>/DischargeAccumulator' */
  localDW->DischargeAccumulator_DSTATE += rtb_ArbitratedInitSoc;

  /* Chart: '<S45>/SocStateController' incorporates:
   *  Constant: '<S75>/Constant'
   *  Constant: '<S77>/Constant'
   *  RelationalOperator: '<S75>/Compare'
   *  RelationalOperator: '<S77>/Compare'
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
      if (rtb_Compare_pt) {
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

  /* End of Chart: '<S45>/SocStateController' */

  /* DiscreteIntegrator: '<S6>/CalcCurrAccum' */
  if (rtb_AND && (localDW->CalcCurrAccum_PrevResetState == 1)) {
    localDW->CalcCurrAccum_DSTATE = 0.0;
  }

  /* DiscreteIntegrator: '<S6>/CalcCurrAccum' */
  localDW->CalcCurrAccum_DSTATE += rtb_ArbitratedInitSoc;

  /* Switch: '<S6>/selSoCcc' incorporates:
   *  Constant: '<S40>/Constant'
   *  Logic: '<S6>/SoCccUpdateTrigger'
   *  RelationalOperator: '<S40>/Compare'
   */
  if ((*rtu_AppIn_LastStoredCycle <= 0.0) || *rtu_Ignition_Sts) {
    /* Switch: '<S45>/selChgOrRealSoc' */
    if (i > 0) {
      /* Switch: '<S45>/selChgOrRealSoc' incorporates:
       *  Gain: '<S6>/ConvToPercent'
       *  Sum: '<S45>/CalcChgSoC'
       */
      localDW->udlySoCcc_DSTATE = (real_T)localB->SoC - 100.0 *
        localDW->DischargeAccumulator_DSTATE;
    } else {
      /* Switch: '<S45>/selChgOrRealSoc' incorporates:
       *  DataTypeConversion: '<S91>/ConvertToFixdt'
       *  Gain: '<S6>/gainCurrent'
       *  Sum: '<S6>/ApplySocCorrection'
       */
      localDW->udlySoCcc_DSTATE = (real_T)rtb_InitialSoCAvg * 0.01 - 100.0 *
        localDW->CalcCurrAccum_DSTATE;
    }

    /* End of Switch: '<S45>/selChgOrRealSoc' */

    /* Saturate: '<S45>/SoCccBoundaries' */
    if (localDW->udlySoCcc_DSTATE > 100.0) {
      /* Switch: '<S45>/selChgOrRealSoc' */
      localDW->udlySoCcc_DSTATE = 100.0;
    } else if (localDW->udlySoCcc_DSTATE < 0.0) {
      /* Switch: '<S45>/selChgOrRealSoc' */
      localDW->udlySoCcc_DSTATE = 0.0;
    }

    /* End of Saturate: '<S45>/SoCccBoundaries' */
  }

  /* End of Switch: '<S6>/selSoCcc' */

  /* Lookup_n-D: '<S42>/USER SOC' incorporates:
   *  Switch: '<S6>/selSoCcc'
   *  UnitDelay: '<S6>/udlySoCcc'
   */
  rtb_ScaledDOD = look1_binlxpw(localDW->udlySoCcc_DSTATE, rtCP_USERSOC_bp01Data,
    rtCP_USERSOC_tableData, 1U);

  /* Outputs for Enabled SubSystem: '<S42>/CalcSoCCorrection' incorporates:
   *  EnablePort: '<S51>/EnableBlock'
   */
  /* Logic: '<S42>/SoCHoldReq' incorporates:
   *  Constant: '<S54>/Constant'
   *  Logic: '<S42>/ChkHasAvgSoCNotChanged'
   *  RelationalOperator: '<S54>/Compare'
   *  RelationalOperator: '<S57>/FixPt Relational Operator'
   *  UnitDelay: '<S57>/Delay Input1'
   *  UnitDelay: '<S99>/Delay Input1'
   *
   * Block description for '<S57>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S99>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((*rtu_sm_BMSMODE_en == BMS_SLEEP) || (*rty_SOCAvg ==
       localDW->DelayInput1_DSTATE)) {
    /* Sum: '<S51>/SoCDeviation' */
    localB->Switch2 = (real_T)*rty_SOCAvg * 0.01 - rtb_ScaledDOD;

    /* Switch: '<S51>/selSleepStateFallBack' incorporates:
     *  Constant: '<S51>/SecperHour'
     *  Constant: '<S51>/ZeroHold'
     *  Constant: '<S67>/Constant'
     *  Product: '<S51>/ScaleSoCError'
     *  RelationalOperator: '<S67>/Compare'
     *  Sum: '<S51>/SoCAccumulate'
     *  UnitDelay: '<S51>/udlySoCError'
     */
    if (*rtu_sm_BMSMODE_en == BMS_SLEEP) {
      localDW->udlySoCError_DSTATE = 0.0;
    }

    localDW->udlySoCError_DSTATE += localB->Switch2 / 36000.0;

    /* End of Switch: '<S51>/selSleepStateFallBack' */

    /* Switch: '<S51>/selUpperBoundaryCheck' incorporates:
     *  Constant: '<S51>/ClampZero'
     */
    if (localB->Switch2 >= 0.0) {
      rtb_ArbitratedInitSoc = localB->Switch2;
    } else {
      rtb_ArbitratedInitSoc = 0.0;
    }

    /* End of Switch: '<S51>/selUpperBoundaryCheck' */

    /* Switch: '<S68>/Switch2' incorporates:
     *  RelationalOperator: '<S68>/LowerRelop1'
     *  Switch: '<S51>/selLowerBoundaryCheck'
     *  UnitDelay: '<S51>/udlySoCError'
     */
    if (localDW->udlySoCError_DSTATE > rtb_ArbitratedInitSoc) {
      /* Sum: '<S51>/SoCDeviation' incorporates:
       *  Switch: '<S68>/Switch2'
       */
      localB->Switch2 = rtb_ArbitratedInitSoc;
    } else {
      if (localB->Switch2 >= 0.0) {
        /* Sum: '<S51>/SoCDeviation' incorporates:
         *  Constant: '<S51>/HoldZero'
         *  Switch: '<S51>/selLowerBoundaryCheck'
         */
        localB->Switch2 = 0.0;
      }

      /* Switch: '<S68>/Switch' incorporates:
       *  RelationalOperator: '<S68>/UpperRelop'
       */
      if (!(localDW->udlySoCError_DSTATE < localB->Switch2)) {
        /* Sum: '<S51>/SoCDeviation' incorporates:
         *  Switch: '<S68>/Switch2'
         */
        localB->Switch2 = localDW->udlySoCError_DSTATE;
      }

      /* End of Switch: '<S68>/Switch' */
    }

    /* End of Switch: '<S68>/Switch2' */
  }

  /* End of Logic: '<S42>/SoCHoldReq' */
  /* End of Outputs for SubSystem: '<S42>/CalcSoCCorrection' */

  /* DataTypeConversion: '<S42>/ConvertToFixdt' incorporates:
   *  Sum: '<S42>/CalcCorrectedSoCcc'
   */
  rtb_ArbitratedInitSoc = (localB->Switch2 + rtb_ScaledDOD) / 0.01;
  if (rtb_ArbitratedInitSoc < 65536.0) {
    if (rtb_ArbitratedInitSoc >= 0.0) {
      rtb_SoCcc_a = (uint16_T)rtb_ArbitratedInitSoc;
    } else {
      rtb_SoCcc_a = 0U;
    }
  } else {
    rtb_SoCcc_a = MAX_uint16_T;
  }

  /* Switch: '<S42>/SoCccBoundarySelection' incorporates:
   *  Constant: '<S53>/Constant'
   *  DataTypeConversion: '<S42>/ConvertToFixdt'
   *  RelationalOperator: '<S53>/Compare'
   *  RelationalOperator: '<S66>/LowerRelop1'
   *  RelationalOperator: '<S66>/UpperRelop'
   *  Switch: '<S66>/Switch'
   *  Switch: '<S66>/Switch2'
   */
  if (*rtu_sm_BMSMODE_en == BMS_CHARGE) {
    /* Switch: '<S65>/Switch2' incorporates:
     *  DataTypeConversion: '<S42>/ConvertToFixdt'
     *  RelationalOperator: '<S65>/LowerRelop1'
     */
    if (rtb_SoCcc_a > *rty_SOCAvg) {
      /* Switch: '<S42>/SoCccBoundarySelection' */
      rtb_SoCcc_a = *rty_SOCAvg;
    }
  } else if (rtb_SoCcc_a > 10000) {
    /* Switch: '<S66>/Switch2' incorporates:
     *  Constant: '<S42>/UpperBoundSoC'
     *  Switch: '<S42>/SoCccBoundarySelection'
     *  Switch: '<S65>/Switch2'
     */
    rtb_SoCcc_a = 10000U;
  } else if (rtb_SoCcc_a < *rty_SOCAvg) {
    /* Switch: '<S66>/Switch' incorporates:
     *  Switch: '<S42>/SoCccBoundarySelection'
     *  Switch: '<S65>/Switch2'
     *  Switch: '<S66>/Switch2'
     */
    rtb_SoCcc_a = *rty_SOCAvg;
  }

  /* End of Switch: '<S42>/SoCccBoundarySelection' */

  /* Switch: '<S42>/selSocIgnLatch' */
  if (*rtu_Ignition_Sts) {
    /* Switch: '<S42>/selActiveOrHoldDisplaySoc' */
    if (localB->Compare_b) {
      /* UnitDelay: '<S42>/udlySoC' incorporates:
       *  Constant: '<S62>/CalDODMinThrsh'
       *  Constant: '<S62>/ScalingFactor'
       *  Constant: '<S62>/calDODMaxThrsh'
       *  Constant: '<S62>/calDODMinThrsh'
       *  Constant: '<S63>/ScalingFactor'
       *  Constant: '<S63>/calDODMaxThrsh'
       *  Constant: '<S63>/calDODMinThrsh'
       *  Product: '<S42>/SoCFactorScaling'
       *  Product: '<S62>/CalcOffset'
       *  Product: '<S62>/ScaleMinThrsh'
       *  Product: '<S63>/CalcSoCFactor'
       *  Sum: '<S42>/OffsetCorrection'
       *  Sum: '<S62>/DODThrshDiff'
       *  Sum: '<S63>/DODThrshDiff'
       *  Switch: '<S42>/SoCccBoundarySelection'
       */
      localDW->udlySoC_DSTATE = ((real_T)rtb_SoCcc_a * 0.01 - 100.0 * (real_T)
        CAL_DOD_MIN_THRSH / (real_T)(uint8_T)(CAL_DOD_MAX_THRSH -
        CAL_DOD_MIN_THRSH)) * (100.0 / (real_T)(uint8_T)(CAL_DOD_MAX_THRSH -
        CAL_DOD_MIN_THRSH));
    } else {
      /* UnitDelay: '<S42>/udlySoC' incorporates:
       *  UnitDelay: '<S42>/uDlySoC'
       */
      localDW->udlySoC_DSTATE = localDW->uDlySoC_DSTATE;
    }

    /* End of Switch: '<S42>/selActiveOrHoldDisplaySoc' */
  }

  /* End of Switch: '<S42>/selSocIgnLatch' */

  /* RelationalOperator: '<S55>/Compare' incorporates:
   *  Constant: '<S55>/Constant'
   */
  rtb_Compare_pt = (*rtu_sm_BMSMODE_en == BMS_CHARGE);

  /* Switch: '<S42>/selModeTransitionRef' */
  if (rtb_Compare_pt) {
    /* DataTypeConversion: '<S42>/ConvtTouint8' incorporates:
     *  UnitDelay: '<S42>/udlySoC'
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

    /* End of DataTypeConversion: '<S42>/ConvtTouint8' */
  } else {
    /* DataTypeConversion: '<S42>/ConvertTouin8' incorporates:
     *  UnitDelay: '<S42>/udlySoC'
     */
    rtb_ArbitratedInitSoc = ceil(localDW->udlySoC_DSTATE);
    if (rtb_ArbitratedInitSoc < 256.0) {
      if (rtb_ArbitratedInitSoc >= 0.0) {
        rtb_Init = (uint8_T)rtb_ArbitratedInitSoc;
      } else {
        rtb_Init = 0U;
      }
    } else {
      rtb_Init = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S42>/ConvertTouin8' */
  }

  /* End of Switch: '<S42>/selModeTransitionRef' */

  /* Outputs for Triggered SubSystem: '<S6>/LatchTempinit' incorporates:
   *  TriggerPort: '<S44>/Ignition'
   */
  if (*rtu_Ignition_Sts && (localZCE->LatchTempinit_Trig_ZCE != POS_ZCSIG)) {
    /* SignalConversion generated from: '<S44>/Temp' incorporates:
     *  MinMax: '<S1>/CalcMaxTemp'
     */
    localB->Temp = maxV;
  }

  /* Outputs for Triggered SubSystem: '<S91>/InitPackTemperature' incorporates:
   *  TriggerPort: '<S100>/TrigWhenValid'
   */
  localZCE->LatchTempinit_Trig_ZCE = *rtu_Ignition_Sts;

  /* End of Outputs for SubSystem: '<S91>/InitPackTemperature' */
  /* End of Outputs for SubSystem: '<S6>/LatchTempinit' */

  /* ModelReference: '<S6>/DischgOCV' incorporates:
   *  Constant: '<S6>/ConstOne'
   */
  NBMS_DischargeOCV(&localB->Temp, &rtb_OCVInitial, &rtCP_ConstOne_Value,
                    &localB->DischgInitialSoC_p,
                    &(localDW->DischgOCV_InstanceData.rtdw));

  /* Switch: '<S6>/selSocInitArbitration' incorporates:
   *  Abs: '<S6>/absSocError'
   *  Constant: '<S46>/Constant'
   *  Logic: '<S6>/InitFallbackTrigger'
   *  RelationalOperator: '<S46>/Compare'
   *  Sum: '<S6>/SocInitDeviation'
   */
  if (*rtu_AppIn_I2Cerror || (fabs(localB->DischgInitialSoC_p -
        *rtu_AppIn_LastStoredSOC) >= 3.0)) {
    rtb_ArbitratedInitSoc = localB->DischgInitialSoC_p;
  } else {
    rtb_ArbitratedInitSoc = *rtu_AppIn_LastStoredSOC;
  }

  /* End of Switch: '<S6>/selSocInitArbitration' */

  /* Logic: '<S6>/AND' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S38>/Constant'
   *  RelationalOperator: '<S37>/Compare'
   *  RelationalOperator: '<S38>/Compare'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  rtb_AND = ((localDW->UnitDelay_DSTATE == BMS_SLEEP) && (*rtu_sm_BMSMODE_en ==
              BMS_STANDBY));

  /* Chart: '<S6>/InitialSocManager' */
  if (localDW->is_active_c14_NBMS_SoC == 0) {
    localDW->is_active_c14_NBMS_SoC = 1U;
    localDW->is_c14_NBMS_SoC = NBMS_SoC_IN_StoreInitialSOC;
    localB->InitialSOC = rtb_ArbitratedInitSoc;
  } else if (localDW->is_c14_NBMS_SoC == NBMS_SoC_IN_IgnOff) {
    if (rtb_AND) {
      localDW->is_c14_NBMS_SoC = NBMS_SoC_IN_StoreInitialSOC;
      localB->InitialSOC = rtb_ArbitratedInitSoc;
    }

    /* case IN_StoreInitialSOC: */
  } else if (!rtb_AND) {
    localDW->is_c14_NBMS_SoC = NBMS_SoC_IN_IgnOff;
  } else {
    localB->InitialSOC = rtb_ArbitratedInitSoc;
  }

  /* End of Chart: '<S6>/InitialSocManager' */

  /* Switch: '<S42>/selSoCOutput' incorporates:
   *  Switch: '<S42>/SoCccBoundarySelection'
   *  Switch: '<S42>/selInitialSoc'
   *  UnitDelay: '<S42>/ZeroReset'
   *  UnitDelay: '<S42>/udlyDislaySoC'
   */
  if (localB->Compare_b) {
    rtb_ArbitratedInitSoc = (real_T)rtb_SoCcc_a * 0.01;
  } else if (localDW->ZeroReset_DSTATE) {
    /* Switch: '<S42>/selInitialSoc' */
    rtb_ArbitratedInitSoc = localB->InitialSOC;
  } else {
    rtb_ArbitratedInitSoc = localDW->udlyDislaySoC_DSTATE;
  }

  /* End of Switch: '<S42>/selSoCOutput' */
  if (localDW->Memory_PreviousInput) {
    /* Switch: '<S61>/selBattSoC' incorporates:
     *  MinMax: '<S61>/FindMax'
     *  MinMax: '<S61>/FindMin'
     *  UnitDelay: '<S61>/uDlyBattSoC'
     *  UnitDelay: '<S61>/udlyBattSoC'
     */
    if (rtb_Compare_pt) {
      localDW->udlyBattSoC_DSTATE = fmax(localDW->uDlyBattSoC_DSTATE,
        rtb_ArbitratedInitSoc);
    } else {
      localDW->udlyBattSoC_DSTATE = fmin(rtb_ArbitratedInitSoc,
        localDW->udlyBattSoC_DSTATE);
    }

    /* End of Switch: '<S61>/selBattSoC' */

    /* Saturate: '<S61>/BattSoCBoundaries' incorporates:
     *  UnitDelay: '<S61>/udlyBattSoC'
     */
    if (localDW->udlyBattSoC_DSTATE > 100.0) {
      *rty_Batt_Pack_SOC = 100.0;
    } else if (localDW->udlyBattSoC_DSTATE < 0.0) {
      *rty_Batt_Pack_SOC = 0.0;
    } else {
      *rty_Batt_Pack_SOC = localDW->udlyBattSoC_DSTATE;
    }

    /* End of Saturate: '<S61>/BattSoCBoundaries' */

    /* Update for UnitDelay: '<S61>/uDlyBattSoC' incorporates:
     *  UnitDelay: '<S61>/udlyBattSoC'
     */
    localDW->uDlyBattSoC_DSTATE = localDW->udlyBattSoC_DSTATE;
  }

  /* End of Outputs for SubSystem: '<S42>/LatchBattSoc' */

  /* Chart: '<S60>/StateWaitCondition' incorporates:
   *  UnitDelay: '<S60>/udlyEnableCurrent'
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

  /* End of Chart: '<S60>/StateWaitCondition' */

  /* RelationalOperator: '<S69>/Compare' incorporates:
   *  Constant: '<S69>/Constant'
   */
  rtb_Compare_pt = (*rtu_Charger_Mode_Req == Charge_Complete);

  /* RelationalOperator: '<S70>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S70>/Delay Input1'
   *
   * Block description for '<S70>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_AND = ((int32_T)rtb_Compare_pt > (int32_T)localDW->DelayInput1_DSTATE_a);

  /* Outputs for Triggered SubSystem: '<S60>/LatchFullSoc' incorporates:
   *  TriggerPort: '<S71>/Trigger'
   */
  if (rtb_AND && (localZCE->LatchFullSoc_Trig_ZCE != POS_ZCSIG)) {
    /* SignalConversion generated from: '<S71>/SOC_Full' */
    localB->LatchedFullSoC = *rtu_soc_full;
  }

  localZCE->LatchFullSoc_Trig_ZCE = rtb_AND;

  /* End of Outputs for SubSystem: '<S60>/LatchFullSoc' */

  /* Switch: '<S60>/selFullChargeSocSource' incorporates:
   *  Constant: '<S52>/Constant'
   *  RelationalOperator: '<S52>/Compare'
   *  Switch: '<S42>/selDisplaySocFallback'
   *  Switch: '<S42>/selFinalGaugeOutput'
   */
  if (rtb_AND) {
    rtb_ArbitratedInitSoc = localB->LatchedFullSoC;
  } else {
    if (localB->Compare_b) {
      /* Switch: '<S42>/selChargeSocCompensation' incorporates:
       *  Constant: '<S56>/Constant'
       *  MinMax: '<S42>/FindMinSoC'
       *  RelationalOperator: '<S56>/Compare'
       *  Switch: '<S42>/selFinalGaugeOutput'
       *  UnitDelay: '<S42>/UdlySoc'
       */
      if (*rtu_sm_BMSMODE_en == BMS_CHARGE) {
        /* MinMax: '<S42>/FindMaxSoC' incorporates:
         *  UnitDelay: '<S42>/UDlySOC'
         */
        if (localDW->UDlySOC_DSTATE >= rtb_Init) {
          /* Switch: '<S42>/selChargeSocCompensation' */
          localDW->UdlySoc_DSTATE = localDW->UDlySOC_DSTATE;
        } else {
          /* Switch: '<S42>/selChargeSocCompensation' */
          localDW->UdlySoc_DSTATE = rtb_Init;
        }
      } else if (rtb_Init <= localDW->UdlySoc_DSTATE) {
        /* Switch: '<S42>/selChargeSocCompensation' incorporates:
         *  MinMax: '<S42>/FindMaxSoC'
         *  MinMax: '<S42>/FindMinSoC'
         */
        localDW->UdlySoc_DSTATE = rtb_Init;
      }

      /* End of Switch: '<S42>/selChargeSocCompensation' */

      /* Switch: '<S42>/selFinalGaugeOutput' */
      rtb_ArbitratedInitSoc = localDW->UdlySoc_DSTATE;
    } else if (*rtu_sm_BMSMODE_en != BMS_SLEEP) {
      /* Switch: '<S42>/selDisplaySocFallback' incorporates:
       *  Switch: '<S42>/selFinalGaugeOutput'
       */
      rtb_ArbitratedInitSoc = localB->InitialSOC;
    } else {
      /* Switch: '<S42>/selFinalGaugeOutput' incorporates:
       *  Constant: '<S42>/ZeroSoC'
       *  Switch: '<S42>/selDisplaySocFallback'
       */
      rtb_ArbitratedInitSoc = 0.0;
    }

    /* Switch: '<S60>/selTerminationSocRef' incorporates:
     *  Constant: '<S52>/Constant'
     *  Constant: '<S60>/ChgTerminationLt'
     *  Constant: '<S60>/MaxSOC'
     *  Constant: '<S60>/MaxSoC'
     *  Constant: '<S73>/Constant'
     *  Constant: '<S74>/Constant'
     *  Logic: '<S60>/ChargeCompletionTrigger'
     *  Logic: '<S60>/PackTopOffCondition'
     *  RelationalOperator: '<S52>/Compare'
     *  RelationalOperator: '<S60>/chkDisplaySocAtMax'
     *  RelationalOperator: '<S60>/chkPrevStateComplete'
     *  RelationalOperator: '<S73>/Compare'
     *  RelationalOperator: '<S74>/Compare'
     *  Switch: '<S42>/selDisplaySocFallback'
     *  Switch: '<S42>/selFinalGaugeOutput'
     *  Switch: '<S60>/selDisplaySocFallback'
     */
    if ((*rty_Batt_Pack_SOC <= 99.0) && (rtb_ArbitratedInitSoc == 100.0) &&
        (localB->out != 0.0)) {
      rtb_ArbitratedInitSoc = 99.0;
    } else if ((rtb_ArbitratedInitSoc == 100.0) && (*rtu_sm_BMSMODE_en ==
                BMS_CHARGE)) {
      /* Switch: '<S60>/selDisplaySocFallback' incorporates:
       *  UnitDelay: '<S42>/udlyDSoC'
       */
      rtb_ArbitratedInitSoc = localDW->udlyDSoC_DSTATE;
    }

    /* End of Switch: '<S60>/selTerminationSocRef' */
  }

  /* End of Switch: '<S60>/selFullChargeSocSource' */

  /* Saturate: '<S42>/SoCBoundaries' */
  if (rtb_ArbitratedInitSoc > 100.0) {
    rtb_ArbitratedInitSoc = 100.0;
  } else if (rtb_ArbitratedInitSoc < 0.0) {
    rtb_ArbitratedInitSoc = 0.0;
  }

  rtb_ArbitratedInitSoc = ceil(rtb_ArbitratedInitSoc);
  if (rtb_ArbitratedInitSoc < 256.0) {
    rtb_Init = (uint8_T)rtb_ArbitratedInitSoc;
  } else {
    rtb_Init = MAX_uint8_T;
  }

  /* SignalConversion generated from: '<S132>/ SFunction ' incorporates:
   *  Chart: '<S93>/FindMinAvgVolt'
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

  /* Chart: '<S93>/FindMinAvgVolt' incorporates:
   *  SignalConversion generated from: '<S132>/ SFunction '
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

  /* Sum: '<S93>/MinVoltDiff' */
  if (tmp) {
    rtb_ArbitratedInitSoc = 0.0;
  } else {
    rtb_ArbitratedInitSoc = fmod(rtb_SumofAvgVolt_0, 65536.0);
  }

  if (rtb_ArbitratedInitSoc < 0.0) {
    i = (int16_T)-(int16_T)(uint16_T)-rtb_ArbitratedInitSoc;
  } else {
    i = (int16_T)(uint16_T)rtb_ArbitratedInitSoc;
  }

  *rty_VtAvgMin = (int16_T)(rtb_OpenCircuitVoltage - i);

  /* Switch: '<S42>/selDisplaySoC' incorporates:
   *  Constant: '<S42>/calDischgEndThrsh'
   *  Constant: '<S58>/Constant'
   *  Gain: '<S42>/scaleDchgEndThrsh'
   *  RelationalOperator: '<S42>/chkVoltBelowCutoff'
   *  RelationalOperator: '<S58>/Compare'
   *  Saturate: '<S42>/SoCBoundaries'
   *  Switch: '<S42>/selSocCutoffArbitration'
   *  UnitDelay: '<S42>/udlyDisplaySoC'
   */
  if (rtb_Init > 0) {
    *rty_Display_SOC = rtb_Init;
  } else if (*rty_VtAvgMin * 16777 <= (int32_T)((33554U * CAL_DCHRG_END_THRSH) >>
              1)) {
    /* Switch: '<S42>/selSocCutoffArbitration' incorporates:
     *  Constant: '<S42>/SoCZeroClamp'
     */
    *rty_Display_SOC = 0U;
  } else {
    *rty_Display_SOC = localDW->udlyDisplaySoC_DSTATE;
  }

  /* End of Switch: '<S42>/selDisplaySoC' */

  /* Switch: '<S4>/selderateflg1' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S9>/Compare'
   */
  if (*rty_Display_SOC <= 20) {
    *rty_Batt_SoC_Derating = SOC_Derating;
  } else {
    *rty_Batt_SoC_Derating = SOC_NoDerating;
  }

  /* End of Switch: '<S4>/selderateflg1' */

  /* Logic: '<S18>/ChgStarted' incorporates:
   *  Constant: '<S29>/Constant'
   *  Constant: '<S30>/Constant'
   *  Constant: '<S31>/Constant'
   *  Logic: '<S18>/IsCharging'
   *  RelationalOperator: '<S29>/Compare'
   *  RelationalOperator: '<S30>/Compare'
   *  RelationalOperator: '<S31>/Compare'
   *  UnitDelay: '<S18>/udlyChgModeReq'
   */
  rtb_ChgStarted = ((localDW->udlyChgModeReq_DSTATE == Standby) &&
                    ((*rtu_Charger_Mode_Req == CC_Start) ||
                     (*rtu_Charger_Mode_Req == CV)));

  /* Logic: '<S18>/CalcChargMeasureTrigger' incorporates:
   *  Constant: '<S28>/Constant'
   *  RelationalOperator: '<S28>/Compare'
   */
  rtb_AND = (rtb_ChgStarted && (*rty_Display_SOC < 10));

  /* Outputs for Enabled SubSystem: '<S18>/CalcChgMeasured' incorporates:
   *  EnablePort: '<S23>/Enable'
   */
  /* RelationalOperator: '<S26>/Compare' incorporates:
   *  Constant: '<S26>/Constant'
   */
  if (*rtu_sm_BMSMODE_en == BMS_CHARGE) {
    /* DiscreteIntegrator: '<S23>/CalcAccumulatedBattCurr' */
    if (rtb_AND && (localDW->CalcAccumulatedBattCurr_PrevRes <= 0)) {
      localDW->CalcAccumulatedBattCurr_DSTATE = 0.0;
    }

    /* Gain: '<S23>/scaleBattCurr' incorporates:
     *  DiscreteIntegrator: '<S23>/CalcAccumulatedBattCurr'
     */
    localB->ChargeMeasured = 1000.0 * localDW->CalcAccumulatedBattCurr_DSTATE;

    /* Update for DiscreteIntegrator: '<S23>/CalcAccumulatedBattCurr' incorporates:
     *  Abs: '<S23>/Absolute'
     *  DataTypeConversion: '<S5>/ConverToDouble'
     *  Gain: '<S23>/secPerHour'
     *  Switch: '<S107>/Sample Accumulator '
     */
    localDW->CalcAccumulatedBattCurr_DSTATE += fabs((real_T)
      localB->usecAvgBatteryCurrent * 0.01) * 0.0002777777777777778 * 0.1;
    localDW->CalcAccumulatedBattCurr_PrevRes = (int8_T)rtb_AND;
  }

  /* End of RelationalOperator: '<S26>/Compare' */
  /* End of Outputs for SubSystem: '<S18>/CalcChgMeasured' */

  /* Gain: '<S18>/scalechargemeasured' */
  *rty_ChargeCapacity = 0.001 * localB->ChargeMeasured;

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   */
  rtb_AND = (*rtu_sm_BMSMODE_en == BMS_SLEEP);

  /* DiscreteIntegrator: '<S17>/Accumulate BattCurrent' */
  if (rtb_AND && (localDW->AccumulateBattCurrent_PrevReset <= 0)) {
    localDW->AccumulateBattCurrent_DSTATE = 0.0;
  }

  /* DiscreteIntegrator: '<S17>/Accumulate BattCurrent' incorporates:
   *  Abs: '<S17>/Absolute'
   *  DataTypeConversion: '<S5>/ConverToDouble'
   *  Gain: '<S17>/CurrentToAh'
   *  Switch: '<S107>/Sample Accumulator '
   */
  localDW->AccumulateBattCurrent_DSTATE += fabs((real_T)
    localB->usecAvgBatteryCurrent * 0.01) * 0.0002777777777777778 * 0.1;

  /* UnitDelay: '<S17>/udlyBMSMode' incorporates:
   *  UnitDelay: '<S6>/Unit Delay'
   */
  localDW->UnitDelay_DSTATE = localDW->udlyBMSMode_DSTATE;

  /* Switch: '<S17>/selAccumulateorHold' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S21>/Constant'
   *  Logic: '<S17>/lastStoredCycleTrigger'
   *  RelationalOperator: '<S20>/Compare'
   *  RelationalOperator: '<S21>/Compare'
   *  UnitDelay: '<S17>/udlyCycleCount'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  if ((localDW->UnitDelay_DSTATE == BMS_SLEEP) && (*rtu_sm_BMSMODE_en ==
       BMS_STANDBY)) {
    localDW->udlyCycleCount_DSTATE = *rtu_AppIn_LastStoredCycle;
  }

  /* End of Switch: '<S17>/selAccumulateorHold' */

  /* Switch: '<S17>/selLifeCycleOutput' incorporates:
   *  Constant: '<S17>/FullCycleFactor'
   *  Constant: '<S17>/calDOD'
   *  Constant: '<S17>/calGoldenDC'
   *  Constant: '<S19>/Constant'
   *  Gain: '<S17>/gainDCscale'
   *  Gain: '<S17>/gainDODscale'
   *  Gain: '<S17>/gainSoHscale'
   *  Product: '<S17>/CalcCapacity'
   *  Product: '<S17>/CalcDegradedCapacity'
   *  Product: '<S17>/CalcLifecycle'
   *  Product: '<S17>/NormalizeBattCurr'
   *  RelationalOperator: '<S19>/Compare'
   *  Sum: '<S17>/CalcTotalLifeCycle'
   *  Switch: '<S17>/selSoHoverrideSource'
   *  UnitDelay: '<S17>/udlyCycleCount'
   *  UnitDelay: '<S17>/udlyLifeCylce'
   */
  if (*rtu_sm_BMSMODE_en != BMS_SLEEP) {
    /* Switch: '<S17>/selSoHoverrideSource' incorporates:
     *  Constant: '<S17>/MaxSoH'
     *  Constant: '<S17>/calSoHEnable'
     */
    if (CAL_SOH_Enable) {
      rtb_ArbitratedInitSoc = NBMS_SoC_ConstB.SoH;
    } else {
      rtb_ArbitratedInitSoc = 100.0;
    }

    *rty_LifeCycle = localDW->AccumulateBattCurrent_DSTATE / 2.0 /
      (0.0009999871253967285 * (real_T)CAL_GOLDEN_DC * (0.010009765625 * (real_T)
        CAL_DOD) * (0.01 * rtb_ArbitratedInitSoc)) +
      localDW->udlyCycleCount_DSTATE;
  } else {
    *rty_LifeCycle = localDW->udlyLifeCylce_DSTATE;
  }

  /* End of Switch: '<S17>/selLifeCycleOutput' */

  /* Outputs for Triggered SubSystem: '<S18>/Initial_SoC_Storage' incorporates:
   *  TriggerPort: '<S35>/TriggerWhenChargeHasinitiated'
   */
  localZCE->Initial_SoC_Storage_Trig_ZCE = rtb_ChgStarted;

  /* End of Outputs for SubSystem: '<S18>/Initial_SoC_Storage' */

  /* RelationalOperator: '<S48>/Compare' incorporates:
   *  Constant: '<S48>/Constant'
   */
  rtb_ChgStarted = (*rtu_sm_BMSMODE_en == BMS_CHARGE);

  /* DiscreteIntegrator: '<S41>/CoulombCounter' */
  if (TriggerswhentheBMSModeisDischar && (localDW->CoulombCounter_PrevResetState
       <= 0)) {
    localDW->CoulombCounter_DSTATE = 0.0;
  }

  /* DiscreteIntegrator: '<S41>/CoulombCounter' incorporates:
   *  Constant: '<S41>/secperHour'
   *  Product: '<S41>/DivideBattCurrToAmp-hour'
   *  Switch: '<S107>/Sample Accumulator '
   */
  localDW->CoulombCounter_DSTATE += (real_T)localB->usecAvgBatteryCurrent * 0.01
    / 3600.0 * 0.1;

  /* DiscreteIntegrator: '<S41>/CoulombCounter' */
  if (localDW->CoulombCounter_DSTATE > 38.4) {
    /* DiscreteIntegrator: '<S41>/CoulombCounter' */
    localDW->CoulombCounter_DSTATE = 38.4;
  } else if (localDW->CoulombCounter_DSTATE < -38.4) {
    /* DiscreteIntegrator: '<S41>/CoulombCounter' */
    localDW->CoulombCounter_DSTATE = -38.4;
  }

  /* RelationalOperator: '<S49>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S49>/Delay Input1'
   *
   * Block description for '<S49>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Compare_bn = ((int32_T)rtb_ChgStarted > (int32_T)
                    localDW->DelayInput1_DSTATE_j);

  /* Outputs for Triggered SubSystem: '<S41>/LatchInitCapacity' incorporates:
   *  TriggerPort: '<S50>/Trigger'
   */
  if (rtb_Compare_bn && (localZCE->LatchInitCapacity_Trig_ZCE != POS_ZCSIG)) {
    /* SignalConversion generated from: '<S50>/CurrCapacity' incorporates:
     *  UnitDelay: '<S41>/udlyCurrentCapacity'
     */
    localB->InitialCapacity = localDW->udlyCurrentCapacity_DSTATE;
  }

  localZCE->LatchInitCapacity_Trig_ZCE = rtb_Compare_bn;

  /* End of Outputs for SubSystem: '<S41>/LatchInitCapacity' */

  /* Switch: '<S41>/selCapacity' incorporates:
   *  Constant: '<S41>/SoHEnable'
   *  Constant: '<S41>/calDOD'
   *  Constant: '<S41>/calGoldenDC'
   *  Gain: '<S41>/gainDCscale'
   *  Gain: '<S41>/gainDODscale'
   *  Gain: '<S41>/gainSoCscale'
   *  Gain: '<S41>/gainSoHscale'
   *  Product: '<S41>/CalcInitialCurrCapacity'
   *  Sum: '<S41>/TotalCapacity'
   *  Switch: '<S41>/selSoHsource'
   *  UnitDelay: '<S41>/udlyCurrentCapacity'
   */
  if (rtb_ChgStarted) {
    localDW->udlyCurrentCapacity_DSTATE = localDW->CoulombCounter_DSTATE +
      localB->InitialCapacity;
  } else {
    if (!CAL_SOH_Enable) {
      /* Switch: '<S41>/selSoHsource' incorporates:
       *  Constant: '<S41>/MaxSoH'
       */
      localDW->udlySoH_DSTATE = 100.0;
    }

    localDW->udlyCurrentCapacity_DSTATE = 0.01 * localDW->udlySoH_DSTATE *
      (0.0009999871253967285 * (real_T)CAL_GOLDEN_DC) * (0.010009765625 *
      (real_T)CAL_DOD) * (0.010009765625 * (real_T)*rty_Display_SOC);
  }

  /* End of Switch: '<S41>/selCapacity' */

  /* Saturate: '<S41>/SetCapacityBoundaries' incorporates:
   *  UnitDelay: '<S41>/udlyCurrentCapacity'
   */
  if (localDW->udlyCurrentCapacity_DSTATE > 38.4) {
    *rty_CurrentCapacity = 38.4;
  } else if (localDW->udlyCurrentCapacity_DSTATE < 0.0) {
    *rty_CurrentCapacity = 0.0;
  } else {
    *rty_CurrentCapacity = localDW->udlyCurrentCapacity_DSTATE;
  }

  /* End of Saturate: '<S41>/SetCapacityBoundaries' */

  /* Gain: '<S16>/scaleAvailEnergykWh' incorporates:
   *  Constant: '<S5>/calNominalVoltage'
   *  Gain: '<S5>/gainNominalVt'
   *  Product: '<S16>/CalcAvailEneregy'
   */
  *rty_AvailableEnergy = 0.0010000000002037268 * (real_T)CAL_NOMINAL_VOLTAGE *
    *rty_CurrentCapacity * 0.001;

  /* Outputs for Enabled SubSystem: '<S1>/SOC Fault Detection' incorporates:
   *  EnablePort: '<S7>/triggerWhenSoCCalcValid'
   */
  /* UnitDelay: '<S1>/udlyStartSoC' */
  if (localDW->udlyStartSoC_DSTATE) {
    if (!localDW->SOCFaultDetection_MODE) {
      /* InitializeConditions for Switch: '<S7>/selSoc20WarningOutput' incorporates:
       *  Memory: '<S84>/Memory'
       */
      localDW->Memory_PreviousInput_a = false;

      /* InitializeConditions for Memory: '<S82>/Memory' */
      localDW->Memory_PreviousInput_g = false;

      /* InitializeConditions for Switch: '<S7>/selSoc15WarningOutput' incorporates:
       *  Memory: '<S83>/Memory'
       */
      localDW->Memory_PreviousInput_al = false;
      localDW->SOCFaultDetection_MODE = true;
    }

    /* RelationalOperator: '<S80>/Compare' incorporates:
     *  Constant: '<S80>/Constant'
     */
    rtb_Compare_bn = (*rtu_sm_BMSMODE_en == BMS_DISCHARGE);

    /* Switch: '<S7>/selSoc20WarningOutput' incorporates:
     *  CombinatorialLogic: '<S84>/Logic'
     *  Constant: '<S86>/Constant'
     *  Constant: '<S89>/Constant'
     *  Logic: '<S7>/Soc20WarningTrip'
     *  Memory: '<S84>/Memory'
     *  RelationalOperator: '<S86>/Compare'
     *  RelationalOperator: '<S89>/Compare'
     */
    localDW->Memory_PreviousInput_a = rtCP_Logic_table[((((uint32_T)
      (rtb_Compare_bn && (*rty_Display_SOC < CAL_SOC_WRN_THRSH)) << 1U) +
      (uint32_T)(*rty_Display_SOC >= CAL_SOC_WRN_RVL_THRSH)) << 1U) +
      localDW->Memory_PreviousInput_a];

    /* CombinatorialLogic: '<S82>/Logic' incorporates:
     *  Constant: '<S81>/Constant'
     *  Constant: '<S87>/Constant'
     *  Constant: '<S90>/Constant'
     *  Logic: '<S7>/IsDischargeOrFault'
     *  Logic: '<S7>/LowSocTripCondition'
     *  Memory: '<S82>/Memory'
     *  RelationalOperator: '<S81>/Compare'
     *  RelationalOperator: '<S87>/Compare'
     *  RelationalOperator: '<S90>/Compare'
     */
    rowIdx = ((((uint32_T)((*rty_Display_SOC <= CAL_LOW_SOC_THRSH) &&
      (rtb_Compare_bn || (*rtu_sm_BMSMODE_en == BMS_FAULT))) << 1U) + (uint32_T)
               (*rty_Display_SOC >= CAL_LOW_SOC_RVL_THRSH)) << 1U) +
      localDW->Memory_PreviousInput_g;
    localB->Logic[0U] = rtCP_Logic_table_g[rowIdx];
    localB->Logic[1U] = rtCP_Logic_table_g[rowIdx + 8U];

    /* Switch: '<S7>/selSoc15WarningOutput' incorporates:
     *  CombinatorialLogic: '<S83>/Logic'
     *  Constant: '<S7>/calEnableSoCWarn15'
     *  Constant: '<S85>/Constant'
     *  Constant: '<S88>/Constant'
     *  Logic: '<S7>/ChkSoC15Warning'
     *  Logic: '<S7>/Soc15WarningTrip'
     *  Logic: '<S7>/Soc15WarningTrip1'
     *  Memory: '<S83>/Memory'
     *  RelationalOperator: '<S85>/Compare'
     *  RelationalOperator: '<S88>/Compare'
     */
    localDW->Memory_PreviousInput_al = rtCP_Logic_table_m[((((uint32_T)
      (((*rty_Display_SOC < CAL_15_SOC_WRN_THRSH) && rtb_Compare_bn) ||
       (rtb_Compare_bn && *rtu_EEPROM_SOC_WARN15)) << 1U) + (uint32_T)
      (*rty_Display_SOC >= CAL_15_SOC_WRN_RVL_THRSH)) << 1U) +
      localDW->Memory_PreviousInput_al];
    *rty_LOW_SOC_WARN_15 = (CAL_ENABLE_SOC_WARN_15 &&
      localDW->Memory_PreviousInput_al);

    /* Switch: '<S7>/selSoc20WarningOutput' incorporates:
     *  Constant: '<S7>/calEnableSoCWarn20'
     */
    *rty_LOW_SOC_WARN = (CAL_ENABLE_SOC_WARN_20 &&
                         localDW->Memory_PreviousInput_a);

    /* Update for Memory: '<S82>/Memory' */
    localDW->Memory_PreviousInput_g = localB->Logic[0];
  } else if (localDW->SOCFaultDetection_MODE) {
    /* Disable for Outport: '<S7>/ LOW_SOC_WARN_15' */
    *rty_LOW_SOC_WARN_15 = false;

    /* Disable for Outport: '<S7>/ LOW_SOC' incorporates:
     *  CombinatorialLogic: '<S82>/Logic'
     */
    localB->Logic[0] = false;

    /* Disable for Outport: '<S7>/ LOW_SOC_WARN' */
    *rty_LOW_SOC_WARN = false;
    localDW->SOCFaultDetection_MODE = false;
  }

  /* End of UnitDelay: '<S1>/udlyStartSoC' */
  /* End of Outputs for SubSystem: '<S1>/SOC Fault Detection' */

  /* SignalConversion generated from: '<Root>/LOW_SOC' */
  *rty_LOW_SOC = localB->Logic[0];

  /* Outputs for Enabled SubSystem: '<S92>/MovingAverageCurrent5sec' incorporates:
   *  EnablePort: '<S108>/EnableBlock'
   */
  if (rtb_Compare_o1) {
    if (!localDW->MovingAverageCurrent5sec_MODE) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S108>/50Delay' */
      memset(&localDW->u0Delay_DWORK1_m[0], 0, 50U * sizeof(int16_T));

      /* InitializeConditions for UnitDelay: '<S108>/1UnitDelay' */
      localDW->uUnitDelay_DSTATE = 0U;
      localDW->MovingAverageCurrent5sec_MODE = true;
    }

    /* DataTypeConversion: '<S108>/ConvertToFixdt' */
    rtb_ArbitratedInitSoc = floor(*rtu_AppIn_BattCurrent / 0.01);
    if (rtIsNaN(rtb_ArbitratedInitSoc) || rtIsInf(rtb_ArbitratedInitSoc)) {
      rtb_ArbitratedInitSoc = 0.0;
    } else {
      rtb_ArbitratedInitSoc = fmod(rtb_ArbitratedInitSoc, 65536.0);
    }

    if (rtb_ArbitratedInitSoc < 0.0) {
      /* DataTypeConversion: '<S108>/ConvertToFixdt' */
      localB->u1stSample = (int16_T)-(int16_T)(uint16_T)-rtb_ArbitratedInitSoc;
    } else {
      /* DataTypeConversion: '<S108>/ConvertToFixdt' */
      localB->u1stSample = (int16_T)(uint16_T)rtb_ArbitratedInitSoc;
    }

    /* End of DataTypeConversion: '<S108>/ConvertToFixdt' */

    /* Sum: '<S108>/Counter' incorporates:
     *  Constant: '<S108>/CountStep'
     *  UnitDelay: '<S108>/1UnitDelay'
     */
    rowIdx = localDW->uUnitDelay_DSTATE + 1U;
    if (localDW->uUnitDelay_DSTATE + 1U > 255U) {
      rowIdx = 255U;
    }

    localDW->uUnitDelay_DSTATE = (uint8_T)rowIdx;

    /* End of Sum: '<S108>/Counter' */

    /* Switch: '<S108>/Sample Accumulator ' incorporates:
     *  Constant: '<S108>/ConstZeroCurrent'
     *  Constant: '<S110>/Constant'
     *  DataTypeConversion: '<S108>/ConvertToFixdt'
     *  Product: '<S108>/Average'
     *  RelationalOperator: '<S110>/Compare'
     *  Sum: '<S108>/Sumof51Samples'
     *  Sum: '<S108>/SumofCurrent'
     *  UnitDelay: '<S108>/1UnitDelay'
     */
    if (localDW->uUnitDelay_DSTATE > 50) {
      /* Sum: '<S108>/SumofCurrent' incorporates:
       *  S-Function (sfix_udelay): '<S108>/50Delay'
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

    /* End of Switch: '<S108>/Sample Accumulator ' */

    /* Update for S-Function (sfix_udelay): '<S108>/50Delay' incorporates:
     *  DataTypeConversion: '<S108>/ConvertToFixdt'
     */
    for (i = 0; i < 49; i++) {
      localDW->u0Delay_DWORK1_m[i] = localDW->u0Delay_DWORK1_m[i + 1];
    }

    localDW->u0Delay_DWORK1_m[49] = localB->u1stSample;

    /* End of Update for S-Function (sfix_udelay): '<S108>/50Delay' */
  } else if (localDW->MovingAverageCurrent5sec_MODE) {
    /* Disable for Outport: '<S108>/BatteryCurrent' */
    *rty_BatteryCurrentAvg5sec = 0;
    localDW->MovingAverageCurrent5sec_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S92>/MovingAverageCurrent5sec' */

  /* Sum: '<S93>/SumofRawVolt' incorporates:
   *  DataTypeConversion: '<S1>/ConvertToFixdt'
   */
  rtb_ArbitratedInitSoc = 0.0;
  for (i = 0; i < 20; i++) {
    rtb_ArbitratedInitSoc += (real_T)localB->ConvBattVolt[i] * 0.001;
  }

  /* Outputs for Enabled SubSystem: '<S93>/OneSensorVoltFailure' incorporates:
   *  EnablePort: '<S155>/Enable'
   */
  /* RelationalOperator: '<S131>/Compare' incorporates:
   *  Constant: '<S131>/Constant'
   *  Sum: '<S93>/CountofNonZeroCellVolt'
   */
  if (rtb_CountofNonZeroCell_0 == 19) {
    if (!localDW->OneSensorVoltFailure_MODE) {
      /* InitializeConditions for S-Function (sfix_udelay): '<S156>/20Delay' */
      for (i = 0; i < 20; i++) {
        localDW->u0Delay_DWORK1[i] = 0;
      }

      /* End of InitializeConditions for S-Function (sfix_udelay): '<S156>/20Delay' */

      /* InitializeConditions for UnitDelay: '<S156>/PreviousValue' */
      localDW->PreviousValue_DSTATE = 0.0;
      localDW->OneSensorVoltFailure_MODE = true;
    }

    /* Sum: '<S155>/VoltDifference' incorporates:
     *  Sum: '<S93>/SumofRawVolt'
     */
    *rty_FailSensorVolt = *rtu_mi_Pack_Volt - rtb_ArbitratedInitSoc;

    /* DataTypeConversion: '<S156>/FixdtDataTypeConversion' */
    rtb_ArbitratedInitSoc = floor(*rty_FailSensorVolt / 0.001);
    if (rtIsNaN(rtb_ArbitratedInitSoc) || rtIsInf(rtb_ArbitratedInitSoc)) {
      rtb_ArbitratedInitSoc = 0.0;
    } else {
      rtb_ArbitratedInitSoc = fmod(rtb_ArbitratedInitSoc, 65536.0);
    }

    if (rtb_ArbitratedInitSoc < 0.0) {
      /* DataTypeConversion: '<S156>/FixdtDataTypeConversion' */
      localB->u1stVoltage = (int16_T)-(int16_T)(uint16_T)-rtb_ArbitratedInitSoc;
    } else {
      /* DataTypeConversion: '<S156>/FixdtDataTypeConversion' */
      localB->u1stVoltage = (int16_T)(uint16_T)rtb_ArbitratedInitSoc;
    }

    /* End of DataTypeConversion: '<S156>/FixdtDataTypeConversion' */

    /* Sum: '<S156>/Counter' incorporates:
     *  Constant: '<S156>/CountStep'
     *  UnitDelay: '<S156>/PreviousValue'
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

    /* Switch: '<S156>/Counterfor20' incorporates:
     *  Constant: '<S156>/ConstZeroVt'
     *  DataTypeConversion: '<S156>/FixdtDataTypeConversion'
     *  Product: '<S156>/Average'
     *  Sum: '<S156>/Counter'
     *  Sum: '<S156>/SumofVoltage'
     *  Sum: '<S156>/TotalSum'
     */
    if (rowIdx > 20U) {
      /* Sum: '<S156>/SumofVoltage' incorporates:
       *  S-Function (sfix_udelay): '<S156>/20Delay'
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

    /* End of Switch: '<S156>/Counterfor20' */

    /* Update for S-Function (sfix_udelay): '<S156>/20Delay' incorporates:
     *  DataTypeConversion: '<S156>/FixdtDataTypeConversion'
     */
    for (i = 0; i < 19; i++) {
      localDW->u0Delay_DWORK1[19 - i] = localDW->u0Delay_DWORK1[18 - i];
    }

    localDW->u0Delay_DWORK1[0] = localB->u1stVoltage;

    /* End of Update for S-Function (sfix_udelay): '<S156>/20Delay' */

    /* Update for UnitDelay: '<S156>/PreviousValue' incorporates:
     *  Sum: '<S156>/Counter'
     */
    localDW->PreviousValue_DSTATE = rowIdx;
  } else if (localDW->OneSensorVoltFailure_MODE) {
    /* Disable for Outport: '<S155>/FailSensorVolt' */
    *rty_FailSensorVolt = 5.0;

    /* Disable for Outport: '<S155>/FailSensorVoltAvg' */
    *rty_FailSensorVoltAvg = 5000;
    localDW->OneSensorVoltFailure_MODE = false;
  }

  /* End of RelationalOperator: '<S131>/Compare' */
  /* End of Outputs for SubSystem: '<S93>/OneSensorVoltFailure' */

  /* Saturate: '<S42>/SoCccBoundaries' incorporates:
   *  Switch: '<S42>/SoCccBoundarySelection'
   */
  if (rtb_SoCcc_a <= 10000) {
    *rty_SOCcc = rtb_SoCcc_a;
  } else {
    *rty_SOCcc = 10000U;
  }

  /* End of Saturate: '<S42>/SoCccBoundaries' */

  /* DataTypeConversion: '<S1>/ConvertToDouble' incorporates:
   *  DataTypeConversion: '<S91>/ConvertToFixdt'
   */
  *rty_SOCAvgInitial = (real_T)rtb_InitialSoCAvg * 0.01;

  /* MinMax: '<S93>/FindMaxAvgVt' */
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

  /* Sum: '<S93>/MaxVoltDiff' incorporates:
   *  MinMax: '<S93>/FindMaxAvgVt'
   */
  if (tmp) {
    rtb_SumofAvgVolt_0 = 0.0;
  } else {
    rtb_SumofAvgVolt_0 = fmod(rtb_SumofAvgVolt_0, 65536.0);
  }

  if (rtb_SumofAvgVolt_0 < 0.0) {
    i = (int16_T)-(int16_T)(uint16_T)-rtb_SumofAvgVolt_0;
  } else {
    i = (int16_T)(uint16_T)rtb_SumofAvgVolt_0;
  }

  *rty_VtAvgMax = (int16_T)(rtb_OCVInitial - i);

  /* Switch: '<S4>/selderateflg' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S13>/Constant'
   *  Logic: '<S4>/Isvalid'
   *  MinMax: '<S1>/CalcMaxTemp'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S11>/Compare'
   */
  if ((maxV < 10.0) || (maxV >= 56.0)) {
    *rty_Batt_Temp_Derating = Temp_Derating;
  } else {
    *rty_Batt_Temp_Derating = Temp_NoDerating;
  }

  /* End of Switch: '<S4>/selderateflg' */

  /* Chart: '<S93>/FindMinVolt' incorporates:
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

  /* End of Chart: '<S93>/FindMinVolt' */

  /* Update for UnitDelay: '<S1>/udlyPackSoC' */
  localDW->udlyPackSoC_DSTATE = *rty_Batt_Pack_SOC;

  /* Update for UnitDelay: '<S99>/Delay Input1' incorporates:
   *  Switch: '<S91>/Switch1'
   *
   * Block description for '<S99>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE = rtb_SOCAvgHystersis;

  /* Update for UnitDelay: '<S98>/Delay Input1'
   *
   * Block description for '<S98>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE_g = rtb_Compare_mx;

  /* Update for Memory: '<S103>/Memory' incorporates:
   *  CombinatorialLogic: '<S103>/Logic'
   */
  localDW->Memory_PreviousInput_c = rtCP_Logic_table_c[rtb_Logic_idx_0_tmp];

  /* Update for UnitDelay: '<S57>/Delay Input1'
   *
   * Block description for '<S57>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE_f = *rty_SOCAvg;

  /* Update for Switch: '<S41>/selSoHsource' incorporates:
   *  UnitDelay: '<S1>/udlySoH'
   */
  localDW->udlySoH_DSTATE = NBMS_SoC_ConstB.SoH;

  /* Update for DiscreteIntegrator: '<S6>/DischargeAccumulator' */
  localDW->DischargeAccumulator_PrevResetS = (int8_T)rtb_IntegratorReset;

  /* Update for DiscreteIntegrator: '<S6>/CalcCurrAccum' */
  localDW->CalcCurrAccum_PrevResetState = (int8_T)rtb_Compare_c2;

  /* Update for UnitDelay: '<S42>/uDlySoC' */
  localDW->uDlySoC_DSTATE = *rty_Display_SOC;

  /* Update for UnitDelay: '<S42>/UDlySOC' */
  localDW->UDlySOC_DSTATE = *rty_Display_SOC;

  /* Update for Switch: '<S42>/selChargeSocCompensation' incorporates:
   *  UnitDelay: '<S42>/UdlySoc'
   */
  localDW->UdlySoc_DSTATE = *rty_Display_SOC;

  /* Update for UnitDelay: '<S6>/Unit Delay' */
  localDW->UnitDelay_DSTATE = *rtu_sm_BMSMODE_en;

  /* Update for UnitDelay: '<S42>/ZeroReset' incorporates:
   *  Constant: '<S42>/constZero'
   */
  localDW->ZeroReset_DSTATE = false;

  /* Update for UnitDelay: '<S42>/udlyDislaySoC' */
  localDW->udlyDislaySoC_DSTATE = *rty_Display_SOC;

  /* Update for UnitDelay: '<S60>/udlyEnableCurrent' */
  localDW->udlyEnableCurrent_DSTATE = localB->Compare_b;

  /* Update for UnitDelay: '<S42>/udlyDSoC' */
  localDW->udlyDSoC_DSTATE = *rty_Display_SOC;

  /* Update for UnitDelay: '<S70>/Delay Input1'
   *
   * Block description for '<S70>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE_a = rtb_Compare_pt;

  /* Update for UnitDelay: '<S42>/udlyDisplaySoC' */
  localDW->udlyDisplaySoC_DSTATE = *rty_Display_SOC;

  /* Update for UnitDelay: '<S18>/udlyChgModeReq' */
  localDW->udlyChgModeReq_DSTATE = *rtu_Charger_Mode_Req;

  /* Update for DiscreteIntegrator: '<S17>/Accumulate BattCurrent' */
  localDW->AccumulateBattCurrent_PrevReset = (int8_T)rtb_AND;

  /* Update for UnitDelay: '<S17>/udlyBMSMode' */
  localDW->udlyBMSMode_DSTATE = *rtu_sm_BMSMODE_en;

  /* Update for UnitDelay: '<S17>/udlyLifeCylce' */
  localDW->udlyLifeCylce_DSTATE = *rty_LifeCycle;

  /* Update for DiscreteIntegrator: '<S41>/CoulombCounter' */
  localDW->CoulombCounter_PrevResetState = (int8_T)
    TriggerswhentheBMSModeisDischar;

  /* Update for UnitDelay: '<S49>/Delay Input1'
   *
   * Block description for '<S49>/Delay Input1':
   *
   *  Store in Global RAM
   */
  localDW->DelayInput1_DSTATE_j = rtb_ChgStarted;

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

  /* Model Initialize function for ModelReference Block: '<S6>/DischgOCV' */
  NBMS_DischargeOCV_initialize(rtmGetErrorStatusPointer(NBMS_SoC_M),
    &(localDW->DischgOCV_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S91>/ChargeOCV' */
  NBMS_ChargeOCV_initialize(rtmGetErrorStatusPointer(NBMS_SoC_M),
    &(localDW->ChargeOCV_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S91>/DischargeOCV' */
  NBMS_DischargeOCV_initialize(rtmGetErrorStatusPointer(NBMS_SoC_M),
    &(localDW->DischargeOCV_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S91>/InitialChargeOCV' */
  NBMS_ChargeOCV_initialize(rtmGetErrorStatusPointer(NBMS_SoC_M),
    &(localDW->InitialChargeOCV_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S91>/InitialDichargeOCV' */
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
