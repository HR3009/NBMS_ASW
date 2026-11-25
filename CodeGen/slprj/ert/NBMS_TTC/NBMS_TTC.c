/*
 * File: NBMS_TTC.c
 *
 * Code generated for Simulink model 'NBMS_TTC'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 25 15:37:45 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "NBMS_TTC.h"
#include "rtwtypes.h"
#include "NBMS_TTC_types.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "NBMS_TTC_private.h"
#include "div_nzp_repeat_s32_floor.h"
#include "DID.h"
#include "zero_crossing_types.h"

/* System initialize for referenced model: 'NBMS_TTC' */
void NBMS_TTC_Init(DW_NBMS_TTC_f_T *localDW)
{
  /* SystemInitialize for Enabled SubSystem: '<S10>/Filter' */
  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 15.0;

  /* End of SystemInitialize for SubSystem: '<S10>/Filter' */
}

/* Disable for referenced model: 'NBMS_TTC' */
void NBMS_TTC_Disable(B_NBMS_TTC_c_T *localB, DW_NBMS_TTC_f_T *localDW)
{
  /* Disable for Enabled SubSystem: '<S10>/Delay' */
  if (localDW->Delay_MODE) {
    /* Disable for RelationalOperator: '<S25>/Compare' incorporates:
     *  Outport: '<S20>/Out1'
     */
    localB->Compare = false;
    localDW->Delay_MODE = false;
  }

  /* End of Disable for SubSystem: '<S10>/Delay' */

  /* Disable for Enabled SubSystem: '<S10>/Filter' */
  if (localDW->Filter_MODE) {
    /* Disable for Switch: '<S22>/Switch' incorporates:
     *  Outport: '<S22>/TTCFiltered'
     */
    localB->Switch = 0.0;
    localDW->Filter_MODE = false;
  }

  /* End of Disable for SubSystem: '<S10>/Filter' */
}

/* Output and update for referenced model: 'NBMS_TTC' */
void NBMS_TTC(const uint8_T *rtu_SOC, const int16_T *rtu_Batt_Current, const
              real_T *rtu_BatteryCapacity, const real_T *rtu_SOH, const
              BMS_MODE_E *rtu_BMS_Mode, const real_T *rtu_ChargecurrLimit, const
              Charger_Mode_Req_E *rtu_Chg_Mode_Req, real_T *rty_TTC_HR, real_T
              *rty_TTC_MIN, B_NBMS_TTC_c_T *localB, DW_NBMS_TTC_f_T *localDW,
              ZCE_NBMS_TTC_T *localZCE)
{
  real_T rtb_Logic_idx_0_tmp;
  real_T rtb_Logic_idx_0_tmp_tmp;
  real_T rtb_Switch2;
  real_T rtb_TTC;
  int32_T y;
  int_T i;
  uint32_T tmp;
  int16_T rtb_Switch1_l;
  uint16_T rtb_Gain1_cz;
  boolean_T rtb_AND;
  boolean_T rtb_NOT_l;

  /* Logic: '<S1>/OR' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S6>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   *  RelationalOperator: '<S6>/Compare'
   */
  rtb_AND = ((*rtu_Chg_Mode_Req == Disabled) || (*rtu_Chg_Mode_Req == Standby));

  /* Switch: '<S1>/Switch2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   */
  if (CAL_SOH_Enable) {
    rtb_Switch2 = *rtu_SOH;
  } else {
    rtb_Switch2 = 1.0;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Gain: '<S1>/Gain1' */
  rtb_Gain1_cz = (uint16_T)(164U * *rtu_SOC);

  /* Outputs for Atomic SubSystem: '<S10>/DelayPrediction' */
  /* Outputs for IfAction SubSystem: '<S1>/CC' incorporates:
   *  ActionPort: '<S2>/Action Port'
   */
  /* If: '<S1>/If2' incorporates:
   *  Gain: '<S11>/Gain4'
   *  Gain: '<S1>/Gain1'
   *  Sum: '<S21>/Remaining SOC'
   *  Sum: '<S2>/Remaining SOC'
   *  Switch: '<S21>/Switch'
   *  Switch: '<S21>/Switch3'
   *  Switch: '<S2>/Switch'
   */
  rtb_Logic_idx_0_tmp_tmp = (real_T)rtb_Gain1_cz * 6.103515625E-5;

  /* End of Outputs for SubSystem: '<S1>/CC' */

  /* Gain: '<S11>/Gain4' incorporates:
   *  Gain: '<S11>/Gain3'
   *  Gain: '<S21>/Gain3'
   *  Gain: '<S21>/Gain4'
   *  Switch: '<S11>/Switch3'
   *  Switch: '<S21>/Switch'
   *  Switch: '<S21>/Switch3'
   */
  rtb_Logic_idx_0_tmp = rtb_Logic_idx_0_tmp_tmp * 100.0;

  /* End of Outputs for SubSystem: '<S10>/DelayPrediction' */

  /* Switch: '<S11>/Switch3' incorporates:
   *  CombinatorialLogic: '<S34>/Logic'
   *  Constant: '<S33>/Constant'
   *  Gain: '<S11>/Gain4'
   *  Memory: '<S34>/Memory'
   *  RelationalOperator: '<S33>/Compare'
   */
  localDW->Memory_PreviousInput = rtCP_Logic_table_a[((((uint32_T)
    (rtb_Logic_idx_0_tmp < 95.0) << 1U) + rtb_AND) << 1U) +
    localDW->Memory_PreviousInput];

  /* If: '<S1>/If2' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Switch: '<S3>/Switch'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  if (rtb_AND) {
    /* Outputs for IfAction SubSystem: '<S1>/FullCharge1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* SignalConversion generated from: '<S9>/NoChrg' incorporates:
     *  Constant: '<S9>/Constant'
     */
    rtb_TTC = 0.0;

    /* End of Outputs for SubSystem: '<S1>/FullCharge1' */
  } else if (*rtu_SOC < 95) {
    /* Switch: '<S1>/Switch1' incorporates:
     *  Constant: '<S1>/Constant3'
     *  RelationalOperator: '<S5>/Compare'
     */
    if (*rtu_Batt_Current <= 0) {
      rtb_Switch1_l = 10;
    } else {
      rtb_Switch1_l = *rtu_Batt_Current;
    }

    /* Outputs for IfAction SubSystem: '<S1>/CC' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     *  Product: '<S2>/Divide'
     *  Product: '<S2>/Product'
     *  Product: '<S2>/Remaining CV capacity'
     *  Product: '<S2>/Remaining Capacity to charge'
     *  Sum: '<S2>/Remaining SOC'
     *  Sum: '<S2>/Subtract'
     *  Switch: '<S1>/Switch1'
     *  Switch: '<S2>/Switch'
     */
    rtb_TTC = floor(((1.0 - rtb_Logic_idx_0_tmp_tmp) * (*rtu_BatteryCapacity *
      rtb_Switch2) - *rtu_BatteryCapacity * 0.05) / ((real_T)rtb_Switch1_l *
      0.01) / 0.01);
    if (rtIsNaN(rtb_TTC) || rtIsInf(rtb_TTC)) {
      rtb_TTC = 0.0;
    } else {
      rtb_TTC = fmod(rtb_TTC, 65536.0);
    }

    if (rtb_TTC < 0.0) {
      /* DataTypeConversion: '<S12>/Data Type Conversion' */
      localB->DataTypeConversion = (int16_T)-(int16_T)(uint16_T)-rtb_TTC;
    } else {
      /* DataTypeConversion: '<S12>/Data Type Conversion' */
      localB->DataTypeConversion = (int16_T)(uint16_T)rtb_TTC;
    }

    /* End of DataTypeConversion: '<S12>/Data Type Conversion' */

    /* Sum: '<S12>/Add2' incorporates:
     *  Constant: '<S12>/Constant4'
     *  UnitDelay: '<S12>/Unit Delay1'
     */
    tmp = localDW->UnitDelay1_DSTATE_d + 1U;
    if (localDW->UnitDelay1_DSTATE_d + 1U > 255U) {
      tmp = 255U;
    }

    localDW->UnitDelay1_DSTATE_d = (uint8_T)tmp;

    /* End of Sum: '<S12>/Add2' */

    /* Switch: '<S12>/Switch1' incorporates:
     *  Constant: '<S12>/Constant6'
     *  Constant: '<S13>/Constant'
     *  DataTypeConversion: '<S12>/Data Type Conversion'
     *  Product: '<S12>/Divide1'
     *  RelationalOperator: '<S13>/Compare'
     *  Sum: '<S12>/Add3'
     *  Sum: '<S12>/Add4'
     *  UnitDelay: '<S12>/Unit Delay1'
     */
    if (localDW->UnitDelay1_DSTATE_d > 30) {
      /* Sum: '<S12>/Add3' incorporates:
       *  S-Function (sfix_udelay): '<S12>/Tapped Delay2'
       */
      y = 0;
      for (i = 0; i < 30; i++) {
        y += localDW->TappedDelay2_DWORK1[i];
      }

      rtb_Switch1_l = (int16_T)(((int16_T)div_nzp_repeat_s32_floor(y +
        localB->DataTypeConversion, 775, 4U) * 25) >> 4);
    } else {
      rtb_Switch1_l = 0;
    }

    /* End of Switch: '<S12>/Switch1' */

    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant3'
     *  Gain: '<S2>/Gain1'
     *  Product: '<S2>/CV charge time'
     *  Switch: '<S12>/Switch1'
     *  Switch: '<S2>/Switch1'
     */
    rtb_TTC = (real_T)CAL_CV_ChargeTime * 0.01 * rtb_Switch2 * (0.010009765625 *
      (real_T)CAL_DOD) + (real_T)rtb_Switch1_l * 0.01;

    /* Saturate: '<S2>/Saturation' */
    if (rtb_TTC > 15.0) {
      rtb_TTC = 15.0;
    } else if (rtb_TTC < 0.0) {
      rtb_TTC = 0.0;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* Update for S-Function (sfix_udelay): '<S12>/Tapped Delay2' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion'
     */
    for (i = 0; i < 29; i++) {
      localDW->TappedDelay2_DWORK1[i] = localDW->TappedDelay2_DWORK1[i + 1];
    }

    localDW->TappedDelay2_DWORK1[29] = localB->DataTypeConversion;

    /* End of Update for S-Function (sfix_udelay): '<S12>/Tapped Delay2' */
    /* End of Outputs for SubSystem: '<S1>/CC' */
  } else if (*rtu_SOC == 100) {
    /* Outputs for IfAction SubSystem: '<S1>/FullCharge' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* SignalConversion generated from: '<S8>/Full_Chg' incorporates:
     *  Constant: '<S8>/Constant'
     */
    rtb_TTC = 0.0;

    /* End of Outputs for SubSystem: '<S1>/FullCharge' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/CV' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    if (!(localDW->UnitDelay1_DSTATE_k > 0.0)) {
      /* Switch: '<S11>/Switch3' incorporates:
       *  Constant: '<S11>/Constant1'
       *  Constant: '<S11>/Constant2'
       *  Constant: '<S11>/Constant3'
       *  Constant: '<S11>/Constant9'
       *  Gain: '<S11>/Gain1'
       *  Product: '<S11>/CV charge time'
       *  Product: '<S11>/CV charge time2'
       *  Product: '<S11>/Divide1'
       *  Sum: '<S11>/Remaining SOC1'
       */
      if (localDW->Memory_PreviousInput) {
        rtb_TTC = (real_T)CAL_CV_ChargeTime * 0.01 * rtb_Switch2 *
          (0.010009765625 * (real_T)CAL_DOD);
      } else {
        rtb_TTC = (real_T)CAL_CV_ChargeTime * 0.01 * rtb_Switch2 *
          (0.010009765625 * (real_T)CAL_DOD) / 5.0 * (100.0 -
          rtb_Logic_idx_0_tmp);
      }

      /* Switch: '<S3>/Switch' incorporates:
       *  Constant: '<S3>/Constant4'
       *  Constant: '<S3>/Constant5'
       *  Product: '<S3>/CVtime1'
       *  Product: '<S3>/Product1'
       *  Switch: '<S11>/Switch3'
       *  UnitDelay: '<S3>/Unit Delay'
       */
      localDW->UnitDelay_DSTATE_c = rtb_TTC * 3600.0 * 10.0;
    }

    /* Sum: '<S3>/Add' incorporates:
     *  Constant: '<S3>/Constant7'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    localDW->UnitDelay_DSTATE_c--;

    /* Saturate: '<S3>/Saturation1' incorporates:
     *  UnitDelay: '<S3>/Unit Delay'
     */
    if (localDW->UnitDelay_DSTATE_c > 72000.0) {
      localDW->UnitDelay1_DSTATE_k = 72000.0;
    } else if (localDW->UnitDelay_DSTATE_c < 600.0) {
      localDW->UnitDelay1_DSTATE_k = 600.0;
    } else {
      localDW->UnitDelay1_DSTATE_k = localDW->UnitDelay_DSTATE_c;
    }

    /* End of Saturate: '<S3>/Saturation1' */

    /* Product: '<S3>/Divide2' incorporates:
     *  Constant: '<S3>/Constant8'
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    localDW->UnitDelay1_DSTATE_k /= 36000.0;

    /* SignalConversion generated from: '<S3>/CV' incorporates:
     *  UnitDelay: '<S3>/Unit Delay1'
     */
    rtb_TTC = localDW->UnitDelay1_DSTATE_k;

    /* Update for UnitDelay: '<S3>/Unit Delay1' incorporates:
     *  Constant: '<S3>/Constant6'
     */
    localDW->UnitDelay1_DSTATE_k = 1.0;

    /* End of Outputs for SubSystem: '<S1>/CV' */
  }

  /* RelationalOperator: '<S18>/Compare' incorporates:
   *  Constant: '<S18>/Constant'
   */
  rtb_AND = (*rtu_BMS_Mode == BMS_CHARGE);

  /* Logic: '<S10>/NOT' */
  rtb_NOT_l = !rtb_AND;

  /* Outputs for Enabled SubSystem: '<S10>/Delay' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  /* CombinatorialLogic: '<S23>/Logic' incorporates:
   *  Memory: '<S23>/Memory'
   */
  localDW->Memory_PreviousInput_p = rtCP_Logic_table_e[((((uint32_T)rtb_AND <<
    1U) + rtb_NOT_l) << 1U) + localDW->Memory_PreviousInput_p];
  if (localDW->Memory_PreviousInput_p) {
    if (!localDW->Delay_MODE) {
      /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
      localDW->UnitDelay1_DSTATE_p = 0U;
      localDW->Delay_MODE = true;
    }

    /* Sum: '<S20>/Subtract1' incorporates:
     *  Constant: '<S20>/Constant'
     *  UnitDelay: '<S20>/Unit Delay1'
     */
    tmp = localDW->UnitDelay1_DSTATE_p + 1U;
    if (localDW->UnitDelay1_DSTATE_p + 1U > 255U) {
      tmp = 255U;
    }

    localDW->UnitDelay1_DSTATE_p = (uint8_T)tmp;

    /* End of Sum: '<S20>/Subtract1' */

    /* RelationalOperator: '<S25>/Compare' incorporates:
     *  Constant: '<S25>/Constant'
     *  UnitDelay: '<S20>/Unit Delay1'
     */
    localB->Compare = (localDW->UnitDelay1_DSTATE_p >= 100);
  } else if (localDW->Delay_MODE) {
    /* Disable for RelationalOperator: '<S25>/Compare' incorporates:
     *  Outport: '<S20>/Out1'
     */
    localB->Compare = false;
    localDW->Delay_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S10>/Delay' */

  /* Outputs for Atomic SubSystem: '<S10>/DelayPrediction' */
  /* Switch: '<S21>/Switch' incorporates:
   *  Constant: '<S21>/Constant3'
   */
  if (*rtu_ChargecurrLimit > 0.0) {
    /* Switch: '<S21>/Switch3' incorporates:
     *  Constant: '<S21>/Constant'
     *  Constant: '<S21>/Constant1'
     *  Constant: '<S21>/Constant2'
     *  Constant: '<S21>/Constant4'
     *  Constant: '<S21>/Constant6'
     *  Constant: '<S21>/Constant7'
     *  Constant: '<S21>/Constant8'
     *  Constant: '<S21>/Constant9'
     *  Constant: '<S26>/Constant'
     *  Gain: '<S21>/Gain1'
     *  Gain: '<S21>/Gain2'
     *  Product: '<S21>/CV charge time'
     *  Product: '<S21>/CV charge time1'
     *  Product: '<S21>/CV charge time2'
     *  Product: '<S21>/Divide'
     *  Product: '<S21>/Divide2'
     *  Product: '<S21>/Remaining CV capacity'
     *  Product: '<S21>/Remaining Capacity to charge'
     *  RelationalOperator: '<S26>/Compare'
     *  Sum: '<S21>/Add'
     *  Sum: '<S21>/Remaining SOC'
     *  Sum: '<S21>/Remaining SOC1'
     *  Sum: '<S21>/Subtract'
     */
    if (rtb_Logic_idx_0_tmp < 95.0) {
      rtb_Switch2 = ((1.0 - rtb_Logic_idx_0_tmp_tmp) * *rtu_BatteryCapacity -
                     *rtu_BatteryCapacity * 0.05) / *rtu_ChargecurrLimit +
        (real_T)CAL_CV_ChargeTime * 0.01 * rtb_Switch2 * (0.010009765625 *
        (real_T)CAL_DOD);
    } else {
      rtb_Switch2 = (real_T)CAL_CV_ChargeTime * 0.01 * rtb_Switch2 *
        (0.010009765625 * (real_T)CAL_DOD) / 5.0 * (100.0 - rtb_Logic_idx_0_tmp);
    }
  } else {
    rtb_Switch2 = 0.0;
  }

  /* Saturate: '<S21>/Saturation' */
  if (rtb_Switch2 > 15.0) {
    rtb_Switch2 = 15.0;
  } else if (rtb_Switch2 < 0.0) {
    rtb_Switch2 = 0.0;
  }

  /* End of Saturate: '<S21>/Saturation' */
  /* End of Outputs for SubSystem: '<S10>/DelayPrediction' */

  /* Switch: '<S10>/Switch3' */
  if (!localB->Compare) {
    rtb_TTC = rtb_Switch2;
  }

  /* End of Switch: '<S10>/Switch3' */

  /* Outputs for Enabled SubSystem: '<S10>/Filter' incorporates:
   *  EnablePort: '<S22>/Enable'
   */
  /* CombinatorialLogic: '<S24>/Logic' incorporates:
   *  Constant: '<S19>/Constant'
   *  Logic: '<S10>/AND'
   *  Memory: '<S24>/Memory'
   *  RelationalOperator: '<S19>/Compare'
   */
  localDW->Memory_PreviousInput_c = rtCP_Logic_table_ao[((((uint32_T)(rtb_AND &&
    (rtb_Switch2 > 0.0)) << 1U) + rtb_NOT_l) << 1U) +
    localDW->Memory_PreviousInput_c];
  if (localDW->Memory_PreviousInput_c) {
    if (!localDW->Filter_MODE) {
      /* InitializeConditions for UnitDelay: '<S28>/Delay Input1'
       *
       * Block description for '<S28>/Delay Input1':
       *
       *  Store in Global RAM
       */
      localDW->DelayInput1_DSTATE = 0U;

      /* InitializeConditions for UnitDelay: '<S22>/Unit Delay' */
      localDW->UnitDelay_DSTATE = 15.0;

      /* InitializeConditions for Memory: '<S29>/Memory' */
      localDW->Memory_PreviousInput_d = false;

      /* SystemReset for Triggered SubSystem: '<S22>/Subsystem' */
      /* InitializeConditions for UnitDelay: '<S30>/Unit Delay1' */
      localDW->UnitDelay1_DSTATE = 0.0;

      /* End of SystemReset for SubSystem: '<S22>/Subsystem' */
      localDW->Filter_MODE = true;
    }

    /* RelationalOperator: '<S28>/FixPt Relational Operator' incorporates:
     *  Gain: '<S1>/Gain1'
     *  UnitDelay: '<S28>/Delay Input1'
     *
     * Block description for '<S28>/Delay Input1':
     *
     *  Store in Global RAM
     */
    rtb_NOT_l = (rtb_Gain1_cz > localDW->DelayInput1_DSTATE);

    /* Switch: '<S22>/Switch' incorporates:
     *  Sum: '<S22>/Subtract'
     *  UnitDelay: '<S22>/Unit Delay'
     */
    if (localDW->UnitDelay_DSTATE - rtb_TTC > 0.0) {
      /* Switch: '<S22>/Switch' */
      localB->Switch = rtb_TTC;
    } else {
      /* Switch: '<S22>/Switch' */
      localB->Switch = localDW->UnitDelay_DSTATE;
    }

    /* End of Switch: '<S22>/Switch' */

    /* Outputs for Triggered SubSystem: '<S22>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S31>/Trigger'
     */
    if (rtb_NOT_l && (localZCE->TriggeredSubsystem_Trig_ZCE != POS_ZCSIG)) {
      /* SignalConversion generated from: '<S31>/TTC' */
      localB->TTC = localB->Switch;
    }

    localZCE->TriggeredSubsystem_Trig_ZCE = rtb_NOT_l;

    /* End of Outputs for SubSystem: '<S22>/Triggered Subsystem' */

    /* Outputs for Triggered SubSystem: '<S22>/Subsystem' incorporates:
     *  TriggerPort: '<S30>/Trigger'
     */
    if (rtb_NOT_l && (localZCE->Subsystem_Trig_ZCE != POS_ZCSIG)) {
      /* RelationalOperator: '<S30>/Relational Operator' incorporates:
       *  UnitDelay: '<S30>/Unit Delay1'
       */
      localB->RelationalOperator = (localDW->UnitDelay1_DSTATE == localB->TTC);

      /* Update for UnitDelay: '<S30>/Unit Delay1' */
      localDW->UnitDelay1_DSTATE = localB->TTC;
    }

    /* Outputs for Triggered SubSystem: '<S22>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S31>/Trigger'
     */
    localZCE->Subsystem_Trig_ZCE = rtb_NOT_l;

    /* End of Outputs for SubSystem: '<S22>/Triggered Subsystem' */
    /* End of Outputs for SubSystem: '<S22>/Subsystem' */

    /* Update for UnitDelay: '<S28>/Delay Input1' incorporates:
     *  Gain: '<S1>/Gain1'
     *
     * Block description for '<S28>/Delay Input1':
     *
     *  Store in Global RAM
     */
    localDW->DelayInput1_DSTATE = rtb_Gain1_cz;

    /* Update for UnitDelay: '<S22>/Unit Delay' */
    localDW->UnitDelay_DSTATE = localB->Switch;

    /* Update for Memory: '<S29>/Memory' incorporates:
     *  CombinatorialLogic: '<S29>/Logic'
     *  Logic: '<S22>/NOT'
     */
    localDW->Memory_PreviousInput_d = rtCP_Logic_table[((((uint32_T)
      localB->RelationalOperator << 1U) + (uint32_T)!localB->RelationalOperator)
      << 1U) + localDW->Memory_PreviousInput_d];
  } else if (localDW->Filter_MODE) {
    /* Disable for Switch: '<S22>/Switch' incorporates:
     *  Outport: '<S22>/TTCFiltered'
     */
    localB->Switch = 0.0;
    localDW->Filter_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S10>/Filter' */

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (rtb_AND) {
    rtb_TTC = localB->Switch;
  } else {
    rtb_TTC = 0.0;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Rounding: '<S1>/Floor' */
  *rty_TTC_HR = floor(rtb_TTC);

  /* Sum: '<S1>/Subtract' incorporates:
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain3'
   */
  *rty_TTC_MIN = 60.0 * rtb_TTC - 60.0 * *rty_TTC_HR;
}

/* Model initialize function */
void NBMS_TTC_initialize(const char_T **rt_errorStatus, RT_MODEL_NBMS_TTC_T *
  const NBMS_TTC_M, ZCE_NBMS_TTC_T *localZCE)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(NBMS_TTC_M, rt_errorStatus);
  localZCE->Subsystem_Trig_ZCE = POS_ZCSIG;
  localZCE->TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
