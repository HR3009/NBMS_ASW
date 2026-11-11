/*
 * File: NBMS_App.c
 *
 * Code generated for Simulink model 'NBMS_App'.
 *
 * Model version                  : 7.74
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 11 09:32:27 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <math.h>
#include "NBMS_App_types.h"
#include "rtwtypes.h"
#include "NBMS_App_private.h"
#include "NBMS_SM.h"
#include "NBMS_MosfetSeq.h"
#include "NBMS_SoC.h"
#include "NBMS_Fault.h"
#include "NBMS_CCCV.h"
#include "NBMS_DCL.h"
#include "NBMS_Regen.h"
#include "NBMS_App.h"

/* Storage class 'Inputs' */
NBMS_App_Inputs_St NBMS_App_Inputs;

/* Storage class 'Outputs' */
NBMS_App_Outputs_St NBMS_App_Outputs;

/* Block signals (default storage) */
B_NBMS_App_T NBMS_App_B;

/* Block states (default storage) */
DW_NBMS_App_T NBMS_App_DW;

/* Real-time model */
static RT_MODEL_NBMS_App_T NBMS_App_M_;
RT_MODEL_NBMS_App_T *const NBMS_App_M = &NBMS_App_M_;

/* Model step function */
void NBMS_App_step(void)
{
  /* local block i/o variables */
  int16_T rtb_VtAvgMin;
  real_T rtb_SoC;
  int32_T k;
  Charger_Mode_Req_E rtb_PrevChgReq;

  /* UnitDelay: '<S1>/udlyHvMOSFET' */
  NBMS_App_B.HVMosfet = NBMS_App_DW.udlyHvMOSFET_DSTATE;

  /* UnitDelay: '<S1>/UdlyChrgReq' */
  NBMS_App_B.ChrgReq = NBMS_App_DW.UdlyChrgReq_DSTATE;

  /* UnitDelay: '<S1>/udlyDSoC' */
  NBMS_App_B.DisplaySoC = NBMS_App_DW.udlyDSoC_DSTATE;

  /* ModelReference: '<S1>/BMS Mode State Machine' incorporates:
   *  Inport: '<Root>/AppIn_CVmodeTimer'
   *  Inport: '<Root>/AppIn_ChgMode'
   *  Inport: '<Root>/AppIn_G3CommonFlt'
   *  Inport: '<Root>/AppIn_G3DischargeFlt'
   *  Inport: '<Root>/AppIn_G4ChargeFlt'
   *  Inport: '<Root>/AppIn_G4CommonFlt'
   *  Inport: '<Root>/AppIn_G4T1DischargeFlt'
   *  Inport: '<Root>/AppIn_G4T2DischargeFlt'
   *  Inport: '<Root>/AppIn_HardwiredIgn'
   *  Inport: '<Root>/AppIn_MCUHVIL'
   *  Inport: '<Root>/AppIn_OBCHVIL'
   *  Inport: '<Root>/AppIn_OBCHeartbeatFail'
   *  Inport: '<Root>/AppIn_OBCwakeup'
   *  Inport: '<Root>/AppIn_RTCwakeup'
   *  Inport: '<Root>/AppIn_SoCLEDSW'
   *  Inport: '<Root>/AppIn_TRerror'
   *  Inport: '<Root>/AppIn_TRtimer'
   *  Outport: '<Root>/AppOut_BMSMODE'
   *  UnitDelay: '<S1>/udlyMinCellVt'
   */
  NBMS_SM(&NBMS_App_Inputs.IgnitionStatus, &NBMS_App_Inputs.ObcInterlock,
          &NBMS_App_Inputs.OBCWakeup, &NBMS_App_Inputs.McuInterlock,
          &NBMS_App_Inputs.RTCWakeup, &NBMS_App_Inputs.SocLedSwitch,
          &NBMS_App_B.HVMosfet, &NBMS_App_Inputs.ChgMode, &NBMS_App_B.ChrgReq,
          &NBMS_App_Inputs.CvModeTimer, &NBMS_App_Inputs.ThermalRunawayError,
          &NBMS_App_Inputs.ThermalRunawayTimer, &NBMS_App_Inputs.G3DischgFault,
          &NBMS_App_Inputs.G3CommonFault, &NBMS_App_Inputs.G4CommonFault,
          &NBMS_App_Inputs.G4ChargeFault, &NBMS_App_Inputs.ObcHeartbeatFailure,
          &NBMS_App_B.DisplaySoC, &NBMS_App_DW.udlyMinCellVt_DSTATE,
          &NBMS_App_Inputs.G4Type1DischargeFault,
          &NBMS_App_Inputs.G4Type2DischargeFault,
          &NBMS_App_Outputs.AppOut_BMSMODE,
          &(NBMS_App_DW.BMSModeStateMachine_InstanceDat.rtdw));

  /* ModelReference: '<S1>/Mosfet Control State Machine' incorporates:
   *  Inport: '<Root>/AppIn_ActiveDischg'
   *  Inport: '<Root>/AppIn_DCDCMosfetfb'
   *  Inport: '<Root>/AppIn_G4ChargeFlt'
   *  Inport: '<Root>/AppIn_G4CommonFlt'
   *  Inport: '<Root>/AppIn_G4T1DischargeFlt'
   *  Inport: '<Root>/AppIn_G4T2DischargeFlt'
   *  Inport: '<Root>/AppIn_HVMosfetfb'
   *  Inport: '<Root>/AppIn_HardwiredIgn'
   *  Inport: '<Root>/AppIn_LoadVolt'
   *  Inport: '<Root>/AppIn_OBCHVIL'
   *  Inport: '<Root>/AppIn_OBCwakeup'
   *  Inport: '<Root>/AppIn_PMosfetfb'
   *  Inport: '<Root>/AppIn_PackVolt'
   *  Outport: '<Root>/AppOut_ASC_Prep_Flag'
   *  Outport: '<Root>/AppOut_BMSMODE'
   *  Outport: '<Root>/AppOut_Chrgr_Prep_Flag'
   *  Outport: '<Root>/AppOut_DCDCMosfet'
   *  Outport: '<Root>/AppOut_DCDCMosfetCmd'
   *  Outport: '<Root>/AppOut_HVMosfet'
   *  Outport: '<Root>/AppOut_HVMosfetCmd'
   *  Outport: '<Root>/AppOut_PrechgMosfet'
   *  Outport: '<Root>/AppOut_PrechgMosfetCmd'
   *  Outport: '<Root>/AppOut_PrechgVoltFlt'
   */
  NBMS_MosfetSeq(&NBMS_App_Inputs.IgnitionStatus,
                 &NBMS_App_Outputs.AppOut_BMSMODE, &NBMS_App_Inputs.LoadVoltage,
                 &NBMS_App_Inputs.PackVoltage, &NBMS_App_Inputs.ObcInterlock,
                 &NBMS_App_Inputs.OBCWakeup, &NBMS_App_Inputs.ActiveDischarge,
                 &NBMS_App_Inputs.PrechgMosfetFb, &NBMS_App_Inputs.HVMosfetFb,
                 &NBMS_App_Inputs.DCDCMosfetFb, &NBMS_App_Inputs.G4CommonFault,
                 &NBMS_App_Inputs.G4ChargeFault,
                 &NBMS_App_Inputs.G4Type2DischargeFault,
                 &NBMS_App_Inputs.G4Type1DischargeFault,
                 &NBMS_App_Outputs.AppOut_PrechgMosfetCmd,
                 &NBMS_App_Outputs.AppOut_HVMosfetCmd,
                 &NBMS_App_Outputs.AppOut_DCDCMosfetCmd,
                 &NBMS_App_Outputs.AppOut_PrechgMosfet,
                 &NBMS_App_Outputs.AppOut_HVMosfet,
                 &NBMS_App_Outputs.AppOut_DCDCMosfet,
                 &NBMS_App_Outputs.AppOut_ASC_Prep_Flag,
                 &NBMS_App_Outputs.AppOut_Chrgr_Prep_Flag,
                 &NBMS_App_Outputs.AppOut_PrechgVoltFlt,
                 &(NBMS_App_DW.MosfetControlStateMachine_Insta.rtdw));

  /* UnitDelay: '<S1>/udlyChgReq' */
  rtb_PrevChgReq = NBMS_App_DW.udlyChgReq_DSTATE;

  /* ModelReference: '<S1>/State of Charge' incorporates:
   *  Inport: '<Root>/AppIn_BattCurrent'
   *  Inport: '<Root>/AppIn_BattTemp'
   *  Inport: '<Root>/AppIn_BattVoltages'
   *  Inport: '<Root>/AppIn_HardwiredIgn'
   *  Inport: '<Root>/AppIn_I2Cerror'
   *  Inport: '<Root>/AppIn_LastStoredCycle'
   *  Inport: '<Root>/AppIn_LastStoredSOC'
   *  Inport: '<Root>/AppIn_LastStoredSOH'
   *  Inport: '<Root>/AppIn_OBCwakeup'
   *  Inport: '<Root>/AppIn_PackVolt'
   *  Inport: '<Root>/AppIn_VehL1'
   *  Outport: '<Root>/AppOut_AvailableEnergy'
   *  Outport: '<Root>/AppOut_BMSMODE'
   *  Outport: '<Root>/AppOut_BattPackSOC'
   *  Outport: '<Root>/AppOut_BatteryCapacity'
   *  Outport: '<Root>/AppOut_ChargeCapacity'
   *  Outport: '<Root>/AppOut_CurrentCapacity'
   *  Outport: '<Root>/AppOut_DisplaySoC'
   *  Outport: '<Root>/AppOut_LifeCycle'
   *  Outport: '<Root>/AppOut_LowSoC'
   *  Outport: '<Root>/AppOut_LowSoCWarn'
   *  Outport: '<Root>/AppOut_LowSoCWarn15'
   *  Outport: '<Root>/AppOut_SOCAvgInitial'
   *  Outport: '<Root>/AppOut_SOCcc'
   *  Outport: '<Root>/AppOut_SOCocvInit'
   *  Outport: '<Root>/AppOut_SOCocvavg'
   *  Outport: '<Root>/AppOut_SOH'
   *  UnitDelay: '<S1>/udlyDCL'
   *  UnitDelay: '<S1>/udlyMinCellVt'
   *  UnitDelay: '<S1>/udlySoCFull'
   */
  NBMS_SoC(&NBMS_App_DW.udlySoCFull_DSTATE, &NBMS_App_Inputs.BattTemp[0],
           &NBMS_App_Inputs.BattCurr, &NBMS_App_Inputs.BattVolt[0],
           &NBMS_App_Inputs.IgnitionStatus, &rtb_PrevChgReq,
           &NBMS_App_Outputs.AppOut_BMSMODE, &NBMS_App_Inputs.LastStoredSoC,
           &NBMS_App_Inputs.LastStoredCycle, &NBMS_App_Inputs.I2CError,
           &NBMS_App_Inputs.LastStoredSoH, &NBMS_App_Inputs.OBCWakeup,
           &NBMS_App_Inputs.PackVoltage, &NBMS_App_Inputs.VehicleLevel,
           &NBMS_App_DW.udlyDCL_DSTATE, &NBMS_App_Outputs.AppOut_DisplaySoC,
           &NBMS_App_Outputs.AppOut_BatteryCapacity,
           &NBMS_App_Outputs.AppOut_LowSoCWarn15,
           &NBMS_App_Outputs.AppOut_LowSoC, &NBMS_App_Outputs.AppOut_LowSoCWarn,
           &NBMS_App_Outputs.AppOut_BattPackSOC,
           &NBMS_App_Outputs.AppOut_LifeCycle, &NBMS_App_Outputs.AppOut_SOH,
           &NBMS_App_DW.udlyMinCellVt_DSTATE,
           &NBMS_App_Outputs.AppOut_CurrentCapacity,
           &NBMS_App_Outputs.AppOut_SOCcc, &NBMS_App_Outputs.AppOut_SOCocvavg,
           &NBMS_App_B.VoltageMin, &NBMS_App_Outputs.AppOut_SOCocvInit,
           &NBMS_App_Outputs.AppOut_SOCAvgInitial,
           &NBMS_App_Outputs.AppOut_AvailableEnergy, &rtb_VtAvgMin,
           &NBMS_App_B.SensorVoltFail, &NBMS_App_B.AvgSensorVoltFail,
           &NBMS_App_B.usecAvgBatteryCurrent,
           &NBMS_App_Outputs.AppOut_ChargeCapacity,
           &(NBMS_App_DW.StateofCharge_InstanceData.rtb),
           &(NBMS_App_DW.StateofCharge_InstanceData.rtdw),
           &(NBMS_App_DW.StateofCharge_InstanceData.rtzce));

  /* ModelReference: '<S1>/Fault' incorporates:
   *  Inport: '<Root>/AppIn_BMSVltSnsrFail'
   *  Inport: '<Root>/AppIn_BattPackTempSnsrFail'
   *  Inport: '<Root>/AppIn_TempImbWarn'
   *  Inport: '<Root>/AppIn_VltImbFlt'
   *  Outport: '<Root>/AppOut_DerateFlg'
   */
  NBMS_Fault(&NBMS_App_Inputs.BMSVoltSensorFailure,
             &NBMS_App_Inputs.BattPackTempSensorFailure,
             &NBMS_App_Inputs.VoltImbalanceError,
             &NBMS_App_Inputs.TempImbalanceWarn,
             &NBMS_App_Outputs.AppOut_DerateFlg);

  /* MinMax: '<S1>/FindMaxTemp' incorporates:
   *  Inport: '<Root>/AppIn_BattTemp'
   */
  rtb_SoC = NBMS_App_Inputs.BattTemp[0];
  for (k = 0; k < 5; k++) {
    rtb_SoC = fmax(rtb_SoC, NBMS_App_Inputs.BattTemp[k + 1]);
  }

  /* ModelReference: '<S1>/Charger Profile' incorporates:
   *  Inport: '<Root>/AppIn_G3CommonFlt'
   *  Inport: '<Root>/AppIn_G4ChargeFlt'
   *  Inport: '<Root>/AppIn_G4CommonFlt'
   *  Inport: '<Root>/AppIn_HardwiredIgn'
   *  Inport: '<Root>/AppIn_OBCHVIL'
   *  Inport: '<Root>/AppIn_OBCHeartbeatFail'
   *  Inport: '<Root>/AppIn_OBCwakeup'
   *  Inport: '<Root>/AppIn_PackVolt'
   *  Inport: '<Root>/AppIn_RTCwakeup'
   *  MinMax: '<S1>/FindMaxTemp'
   *  Outport: '<Root>/AppOut_BMSMODE'
   *  Outport: '<Root>/AppOut_BMS_NM_Msg'
   *  Outport: '<Root>/AppOut_ChargeCurrentLt'
   *  Outport: '<Root>/AppOut_ChargeVoltageLt'
   *  Outport: '<Root>/AppOut_ChgModeReq'
   *  Outport: '<Root>/AppOut_DerateFlg'
   *  Outport: '<Root>/AppOut_HVMosfet'
   *  Outport: '<Root>/AppOut_SOH'
   *  UnitDelay: '<S1>/uDlyDSOC'
   *  UnitDelay: '<S1>/udlyMinCellVt'
   */
  NBMS_CCCV(&NBMS_App_Inputs.OBCWakeup, &NBMS_App_DW.uDlyDSOC_DSTATE,
            &NBMS_App_Outputs.AppOut_BMSMODE, &NBMS_App_Outputs.AppOut_HVMosfet,
            &NBMS_App_Outputs.AppOut_SOH, &rtb_SoC,
            &NBMS_App_DW.udlyMinCellVt_DSTATE, &NBMS_App_Inputs.IgnitionStatus,
            &NBMS_App_Inputs.RTCWakeup, &NBMS_App_Inputs.ObcHeartbeatFailure,
            &NBMS_App_Inputs.ObcInterlock, &NBMS_App_B.VoltageMin,
            &NBMS_App_Inputs.PackVoltage, &NBMS_App_Outputs.AppOut_DerateFlg,
            &NBMS_App_Inputs.G4ChargeFault, &NBMS_App_Inputs.G4CommonFault,
            &NBMS_App_Inputs.G3CommonFault, &NBMS_App_Outputs.AppOut_BMS_NM_Msg,
            &NBMS_App_Outputs.AppOut_ChgModeReq,
            &NBMS_App_Outputs.AppOut_ChargeVoltageLt, &NBMS_App_B.soc_full,
            &NBMS_App_Outputs.AppOut_ChargeCurrentLt,
            &(NBMS_App_DW.ChargerProfile_InstanceData.rtb),
            &(NBMS_App_DW.ChargerProfile_InstanceData.rtdw));

  /* ModelReference: '<S1>/Discharge Current Limit' incorporates:
   *  Inport: '<Root>/AppIn_BattCurrent'
   *  Inport: '<Root>/AppIn_BattTemp'
   *  Inport: '<Root>/AppIn_G3CommonFlt'
   *  Inport: '<Root>/AppIn_G3DischargeFlt'
   *  Inport: '<Root>/AppIn_G4CommonFlt'
   *  Inport: '<Root>/AppIn_G4T1DischargeFlt'
   *  Inport: '<Root>/AppIn_G4T2DischargeFlt'
   *  Inport: '<Root>/AppIn_VehL1'
   *  Outport: '<Root>/AppOut_DischgCurrLimit'
   *  Outport: '<Root>/AppOut_Timer30'
   *  UnitDelay: '<S1>/udlySOC'
   */
  NBMS_DCL(&NBMS_App_Inputs.VehicleLevel, &NBMS_App_DW.udlySOC_DSTATE,
           &NBMS_App_Inputs.BattTemp[0], &NBMS_App_Inputs.BattCurr,
           &NBMS_App_Inputs.G3CommonFault, &NBMS_App_Inputs.G4CommonFault,
           &NBMS_App_Inputs.G3DischgFault,
           &NBMS_App_Inputs.G4Type1DischargeFault,
           &NBMS_App_Inputs.G4Type2DischargeFault,
           &NBMS_App_Outputs.AppOut_DischgCurrLimit,
           &NBMS_App_Outputs.AppOut_Timer30,
           &(NBMS_App_DW.DischargeCurrentLimit_InstanceD.rtb),
           &(NBMS_App_DW.DischargeCurrentLimit_InstanceD.rtdw));

  /* DataTypeConversion: '<S1>/DoubleConv' incorporates:
   *  Outport: '<Root>/AppOut_DisplaySoC'
   */
  rtb_SoC = NBMS_App_Outputs.AppOut_DisplaySoC;

  /* ModelReference: '<S1>/Regen Current Limit' incorporates:
   *  Inport: '<Root>/AppIn_BattCurrent'
   *  Inport: '<Root>/AppIn_BattTemp'
   *  Outport: '<Root>/AppOut_RegenCurrent'
   *  Outport: '<Root>/AppOut_RegenOverCurrentFlg'
   *  UnitDelay: '<S1>/udlyBmsMode1'
   */
  NBMS_Regen(&NBMS_App_Inputs.BattCurr, &NBMS_App_Inputs.BattTemp[0], &rtb_SoC,
             &NBMS_App_DW.udlyBmsMode1_DSTATE,
             &NBMS_App_Outputs.AppOut_RegenOverCurrentFlg,
             &NBMS_App_Outputs.AppOut_RegenCurrent,
             &(NBMS_App_DW.RegenCurrentLimit_InstanceData.rtdw));

  /* Update for UnitDelay: '<S1>/udlyHvMOSFET' incorporates:
   *  Outport: '<Root>/AppOut_HVMosfet'
   */
  NBMS_App_DW.udlyHvMOSFET_DSTATE = NBMS_App_Outputs.AppOut_HVMosfet;

  /* Update for UnitDelay: '<S1>/UdlyChrgReq' incorporates:
   *  Outport: '<Root>/AppOut_ChgModeReq'
   */
  NBMS_App_DW.UdlyChrgReq_DSTATE = NBMS_App_Outputs.AppOut_ChgModeReq;

  /* Update for UnitDelay: '<S1>/udlyDSoC' incorporates:
   *  Outport: '<Root>/AppOut_DisplaySoC'
   */
  NBMS_App_DW.udlyDSoC_DSTATE = NBMS_App_Outputs.AppOut_DisplaySoC;

  /* Update for UnitDelay: '<S1>/udlyMinCellVt' incorporates:
   *  ModelReference: '<S1>/State of Charge'
   */
  NBMS_App_DW.udlyMinCellVt_DSTATE = NBMS_App_B.VoltageMin;

  /* Update for UnitDelay: '<S1>/udlySoCFull' */
  NBMS_App_DW.udlySoCFull_DSTATE = NBMS_App_B.soc_full;

  /* Update for UnitDelay: '<S1>/udlyChgReq' incorporates:
   *  Outport: '<Root>/AppOut_ChgModeReq'
   */
  NBMS_App_DW.udlyChgReq_DSTATE = NBMS_App_Outputs.AppOut_ChgModeReq;

  /* Update for UnitDelay: '<S1>/udlyDCL' incorporates:
   *  Outport: '<Root>/AppOut_DischgCurrLimit'
   */
  NBMS_App_DW.udlyDCL_DSTATE = NBMS_App_Outputs.AppOut_DischgCurrLimit;

  /* Update for UnitDelay: '<S1>/uDlyDSOC' incorporates:
   *  Outport: '<Root>/AppOut_DisplaySoC'
   */
  NBMS_App_DW.uDlyDSOC_DSTATE = NBMS_App_Outputs.AppOut_DisplaySoC;

  /* Update for UnitDelay: '<S1>/udlySOC' incorporates:
   *  Outport: '<Root>/AppOut_DisplaySoC'
   */
  NBMS_App_DW.udlySOC_DSTATE = NBMS_App_Outputs.AppOut_DisplaySoC;

  /* Update for UnitDelay: '<S1>/udlyBmsMode1' incorporates:
   *  Outport: '<Root>/AppOut_BMSMODE'
   */
  NBMS_App_DW.udlyBmsMode1_DSTATE = NBMS_App_Outputs.AppOut_BMSMODE;
}

/* Model initialize function */
void NBMS_App_initialize(void)
{
  /* Registration code */
  NBMS_App_Inputs.VehicleLevel = VEH_SLEEP;

  /* Model Initialize function for ModelReference Block: '<S1>/BMS Mode State Machine' */
  NBMS_SM_initialize(rtmGetErrorStatusPointer(NBMS_App_M),
                     &(NBMS_App_DW.BMSModeStateMachine_InstanceDat.rtm));

  /* Model Initialize function for ModelReference Block: '<S1>/Charger Profile' */
  NBMS_CCCV_initialize(rtmGetErrorStatusPointer(NBMS_App_M),
                       &(NBMS_App_DW.ChargerProfile_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S1>/Discharge Current Limit' */
  NBMS_DCL_initialize(rtmGetErrorStatusPointer(NBMS_App_M),
                      &(NBMS_App_DW.DischargeCurrentLimit_InstanceD.rtm));

  /* Model Initialize function for ModelReference Block: '<S1>/Fault' */
  NBMS_Fault_initialize(rtmGetErrorStatusPointer(NBMS_App_M),
                        &(NBMS_App_DW.Fault_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S1>/Mosfet Control State Machine' */
  NBMS_MosfetSeq_initialize(rtmGetErrorStatusPointer(NBMS_App_M),
    &(NBMS_App_DW.MosfetControlStateMachine_Insta.rtm));

  /* Model Initialize function for ModelReference Block: '<S1>/Regen Current Limit' */
  NBMS_Regen_initialize(rtmGetErrorStatusPointer(NBMS_App_M),
                        &(NBMS_App_DW.RegenCurrentLimit_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<S1>/State of Charge' */
  NBMS_SoC_initialize(rtmGetErrorStatusPointer(NBMS_App_M),
                      &(NBMS_App_DW.StateofCharge_InstanceData.rtm),
                      &(NBMS_App_DW.StateofCharge_InstanceData.rtdw),
                      &(NBMS_App_DW.StateofCharge_InstanceData.rtzce));

  /* SystemInitialize for ModelReference: '<S1>/State of Charge' incorporates:
   *  Outport: '<Root>/AppOut_LowSoC'
   */
  NBMS_SoC_Init(&NBMS_App_Outputs.AppOut_LowSoC, &NBMS_App_B.SensorVoltFail,
                &NBMS_App_B.AvgSensorVoltFail,
                &(NBMS_App_DW.StateofCharge_InstanceData.rtb),
                &(NBMS_App_DW.StateofCharge_InstanceData.rtdw));
}

/* Model terminate function */
void NBMS_App_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
