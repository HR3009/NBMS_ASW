/*
 * File: NBMS_App.h
 *
 * Code generated for Simulink model 'NBMS_App'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 25 15:38:07 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_App_h_
#define NBMS_App_h_
#ifndef NBMS_App_COMMON_INCLUDES_
#define NBMS_App_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* NBMS_App_COMMON_INCLUDES_ */

#include "NBMS_App_types.h"
#include "NBMS_SM.h"
#include "NBMS_MosfetSeq.h"
#include "NBMS_SoC.h"
#include "NBMS_Fault.h"
#include "NBMS_CCCV.h"
#include "NBMS_DCL.h"
#include "NBMS_Regen.h"
#include "NBMS_TTC.h"
#include "zero_crossing_types.h"

/* Includes for objects with custom storage classes */
#include "DID.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PrevDCL;                      /* '<S1>/udlyDCL' */
  real_T SensorVoltFail;               /* '<S1>/State of Charge' */
  real_T DischargeCurrLimit;           /* '<S1>/Discharge Current Limit' */
  real_T Timer30;                      /* '<S1>/Discharge Current Limit' */
  real_T SoH;                          /* '<S1>/State of Charge' */
  Charger_Mode_Req_E ChrgReq;          /* '<S1>/UdlyChrgReq' */
  BMS_NM_Msg_E BMS_NM_Msg;             /* '<S1>/udlyBMS_NM' */
  BMS_HVMosfet_STS_E HVMosfet;         /* '<S1>/udlyHvMOSFET' */
  int16_T usecAvgBatteryCurrent;       /* '<S1>/State of Charge' */
  int16_T VoltageMin;                  /* '<S1>/State of Charge' */
  int16_T AvgSensorVoltFail;           /* '<S1>/State of Charge' */
  uint8_T DisplaySoC;                  /* '<S1>/udlyDSoC' */
  uint8_T soc_full;                    /* '<S1>/Charger Profile' */
  uint8_T SoC;                         /* '<S1>/udlySOC' */
  boolean_T Ignition_Sts;              /* '<S1>/BMS Mode State Machine' */
  boolean_T Derate;                    /* '<S1>/Fault' */
  boolean_T DischDeratefromCont;       /* '<S1>/Fault' */
  boolean_T DischDerateafterX1;        /* '<S1>/Fault' */
} B_NBMS_App_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T udlyDCL_DSTATE;               /* '<S1>/udlyDCL' */
  BMS_HVMosfet_STS_E udlyHvMOSFET_DSTATE;/* '<S1>/udlyHvMOSFET' */
  Charger_Mode_Req_E UdlyChrgReq_DSTATE;/* '<S1>/UdlyChrgReq' */
  Charger_Mode_Req_E udlyChgReq_DSTATE;/* '<S1>/udlyChgReq' */
  BMS_NM_Msg_E udlyBMS_NM_DSTATE;      /* '<S1>/udlyBMS_NM' */
  BMS_MODE_E udlyBmsMode1_DSTATE;      /* '<S1>/udlyBmsMode1' */
  int16_T udlyMinCellVt_DSTATE;        /* '<S1>/udlyMinCellVt' */
  uint8_T udlyDSoC_DSTATE;             /* '<S1>/udlyDSoC' */
  uint8_T udlySoCFull_DSTATE;          /* '<S1>/udlySoCFull' */
  uint8_T uDlyDSOC_DSTATE;             /* '<S1>/uDlyDSOC' */
  uint8_T udlySOC_DSTATE;              /* '<S1>/udlySOC' */
  boolean_T udlySoC_DSTATE;            /* '<S1>/udlySoC' */
  MdlrefDW_NBMS_SM_T BMSModeStateMachine_InstanceDat;/* '<S1>/BMS Mode State Machine' */
  MdlrefDW_NBMS_MosfetSeq_T MosfetControlStateMachine_Insta;/* '<S1>/Mosfet Control State Machine' */
  MdlrefDW_NBMS_SoC_T StateofCharge_InstanceData;/* '<S1>/State of Charge' */
  MdlrefDW_NBMS_Fault_T Fault_InstanceData;/* '<S1>/Fault' */
  MdlrefDW_NBMS_CCCV_T ChargerProfile_InstanceData;/* '<S1>/Charger Profile' */
  MdlrefDW_NBMS_DCL_T DischargeCurrentLimit_InstanceD;/* '<S1>/Discharge Current Limit' */
  MdlrefDW_NBMS_Regen_T RegenCurrentLimit_InstanceData;/* '<S1>/Regen Current Limit' */
  MdlrefDW_NBMS_TTC_T Model_InstanceData;/* '<S1>/Model' */
} DW_NBMS_App_T;

/* Storage class 'Inputs', for system '<Root>' */
typedef struct {
  real_T AppIn_BattTemp[6];            /* '<Root>/AppIn_BattTemp' */
  real_T AppIn_BattVoltages[20];       /* '<Root>/AppIn_BattVoltages' */
  real_T AppIn_LoadVolt;               /* '<Root>/AppIn_LoadVolt' */
  real_T AppIn_PackVolt;               /* '<Root>/AppIn_PackVolt' */
  real_T AppIn_BattCurrent;            /* '<Root>/AppIn_BattCurrent' */
  real_T AppIn_LastStoredSOC;          /* '<Root>/AppIn_LastStoredSOC' */
  real_T AppIn_LastStoredCycle;        /* '<Root>/AppIn_LastStoredCycle' */
  real_T AppIn_LastStoredSOH;          /* '<Root>/AppIn_LastStoredSOH' */
  OBC_E AppIn_OBCwakeup;               /* '<Root>/AppIn_OBCwakeup' */
  Charger_Mode_E AppIn_ChgMode;        /* '<Root>/AppIn_ChgMode' */
  CV_Mode_Timer_E AppIn_CVmodeTimer;   /* '<Root>/AppIn_CVmodeTimer' */
  Active_DisChrg_E AppIn_ActiveDischg; /* '<Root>/AppIn_ActiveDischg' */
  VDU_MACHINE_STS_E AppIn_MachineStatus;/* '<Root>/AppIn_MachineStatus' */
  boolean_T AppIn_HardwiredIgn;        /* '<Root>/AppIn_HardwiredIgn' */
  boolean_T AppIn_RTCwakeup;           /* '<Root>/AppIn_RTCwakeup' */
  boolean_T AppIn_MCUHVIL;             /* '<Root>/AppIn_MCUHVIL' */
  boolean_T AppIn_OBCHVIL;             /* '<Root>/AppIn_OBCHVIL' */
  boolean_T AppIn_SoCLEDSW;            /* '<Root>/AppIn_SoCLEDSW' */
  boolean_T AppIn_TRerror;             /* '<Root>/AppIn_TRerror' */
  boolean_T AppIn_TRtimer;             /* '<Root>/AppIn_TRtimer' */
  boolean_T AppIn_G3CommonFlt;         /* '<Root>/AppIn_G3CommonFlt' */
  boolean_T AppIn_G3DischargeFlt;      /* '<Root>/AppIn_G3DischargeFlt' */
  boolean_T AppIn_G4T1DischargeFlt;    /* '<Root>/AppIn_G4T1DischargeFlt' */
  boolean_T AppIn_G4T2DischargeFlt;    /* '<Root>/AppIn_G4T2DischargeFlt' */
  boolean_T AppIn_G4CommonFlt;         /* '<Root>/AppIn_G4CommonFlt' */
  boolean_T AppIn_G4ChargeFlt;         /* '<Root>/AppIn_G4ChargeFlt' */
  boolean_T AppIn_OBCHeartbeatFail;    /* '<Root>/AppIn_OBCHeartbeatFail' */
  boolean_T AppIn_I2Cerror;            /* '<Root>/AppIn_I2Cerror' */
  boolean_T AppIn_HVMosfetfb;          /* '<Root>/AppIn_HVMosfetfb' */
  boolean_T AppIn_DCDCMosfetfb;        /* '<Root>/AppIn_DCDCMosfetfb' */
  boolean_T AppIn_PMosfetfb;           /* '<Root>/AppIn_PMosfetfb' */
  boolean_T AppIn_BMSVltSnsrFail;      /* '<Root>/AppIn_BMSVltSnsrFail' */
  boolean_T AppIn_BattPackTempSnsrFail;/* '<Root>/AppIn_BattPackTempSnsrFail' */
  boolean_T AppIn_VltImbFlt;           /* '<Root>/AppIn_VltImbFlt' */
  boolean_T AppIn_TempImbWarn;         /* '<Root>/AppIn_TempImbWarn' */
  boolean_T AppIn_EEPROMSoCWarn15;     /* '<Root>/AppIn_EEPROMSoCWarn15' */
  boolean_T AppIn_BMSLowTempduringDriveWarn;
                                  /* '<Root>/AppIn_BMSLowTempduringDriveWarn' */
  boolean_T AppIn_BMSOverTempDriveWarnInfo;
                                   /* '<Root>/AppIn_BMSOverTempDriveWarnInfo' */
} NBMS_App_Inputs_St;

/* Storage class 'Outputs', for system '<Root>' */
typedef struct {
  real_T AppOut_ChargeVoltageLt;       /* '<Root>/AppOut_ChargeVoltageLt' */
  real_T AppOut_ChargeCurrentLt;       /* '<Root>/AppOut_ChargeCurrentLt' */
  real_T AppOut_BatteryCapacity;       /* '<Root>/AppOut_BatteryCapacity' */
  real_T AppOut_BattPackSOC;           /* '<Root>/AppOut_BattPackSOC' */
  real_T AppOut_LifeCycle;             /* '<Root>/AppOut_LifeCycle' */
  real_T AppOut_SOH;                   /* '<Root>/AppOut_SOH' */
  real_T AppOut_CurrentCapacity;       /* '<Root>/AppOut_CurrentCapacity' */
  real_T AppOut_SOCocvInit;            /* '<Root>/AppOut_SOCocvInit' */
  real_T AppOut_SOCAvgInitial;         /* '<Root>/AppOut_SOCAvgInitial' */
  real_T AppOut_AvailableEnergy;       /* '<Root>/AppOut_AvailableEnergy' */
  real_T AppOut_ChargeCapacity;        /* '<Root>/AppOut_ChargeCapacity' */
  real_T AppOut_DischgCurrLimit;       /* '<Root>/AppOut_DischgCurrLimit' */
  real_T AppOut_Timer30;               /* '<Root>/AppOut_Timer30' */
  real_T AppOut_RegenCurrent;          /* '<Root>/AppOut_RegenCurrent' */
  real_T AppOut_TTCHour;               /* '<Root>/AppOut_TTCHour' */
  real_T AppOut_TTCMinutes;            /* '<Root>/AppOut_TTCMinutes' */
  BMS_HVMosfet_STS_E AppOut_HVMosfet;  /* '<Root>/AppOut_HVMosfet' */
  Charger_Mode_Req_E AppOut_ChgModeReq;/* '<Root>/AppOut_ChgModeReq' */
  BMS_NM_Msg_E AppOut_BMS_NM_Msg;      /* '<Root>/AppOut_BMS_NM_Msg' */
  BMS_MODE_E AppOut_BMSMODE;           /* '<Root>/AppOut_BMSMODE' */
  BMS_PMosfet_STS_E AppOut_PrechgMosfet;/* '<Root>/AppOut_PrechgMosfet' */
  BMS_DCDCMosfet_STS_E AppOut_DCDCMosfet;/* '<Root>/AppOut_DCDCMosfet' */
  BMS_BattTempDerate_E AppOut_BattTempDerating;/* '<Root>/AppOut_BattTempDerating' */
  BMS_BattSoCDerate_E AppOut_BattSoCDerating;/* '<Root>/AppOut_BattSoCDerating' */
  uint16_T AppOut_SOCcc;               /* '<Root>/AppOut_SOCcc' */
  uint16_T AppOut_SOCocvavg;           /* '<Root>/AppOut_SOCocvavg' */
  uint8_T AppOut_DisplaySoC;           /* '<Root>/AppOut_DisplaySoC' */
  boolean_T AppOut_PrechgMosfetCmd;    /* '<Root>/AppOut_PrechgMosfetCmd' */
  boolean_T AppOut_HVMosfetCmd;        /* '<Root>/AppOut_HVMosfetCmd' */
  boolean_T AppOut_DCDCMosfetCmd;      /* '<Root>/AppOut_DCDCMosfetCmd' */
  boolean_T AppOut_ASC_Prep_Flag;      /* '<Root>/AppOut_ASC_Prep_Flag' */
  boolean_T AppOut_Chrgr_Prep_Flag;    /* '<Root>/AppOut_Chrgr_Prep_Flag' */
  boolean_T AppOut_PrechgVoltFlt;      /* '<Root>/AppOut_PrechgVoltFlt' */
  boolean_T AppOut_LowSoCWarn15;       /* '<Root>/AppOut_LowSoCWarn15' */
  boolean_T AppOut_LowSoC;             /* '<Root>/AppOut_LowSoC' */
  boolean_T AppOut_LowSoCWarn;         /* '<Root>/AppOut_LowSoCWarn' */
  boolean_T AppOut_RegenOverCurrentFlg;/* '<Root>/AppOut_RegenOverCurrentFlg' */
} NBMS_App_Outputs_St;

/* Real-time Model Data Structure */
struct tag_RTM_NBMS_App_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_NBMS_App_T NBMS_App_B;

/* Block states (default storage) */
extern DW_NBMS_App_T NBMS_App_DW;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern uint8_T CAL_CV_ChargeTime;      /* Variable: CAL_CV_ChargeTime
                                        * Referenced by: '<S1>/Model'
                                        */

/* Model entry point functions */
extern void NBMS_App_initialize(void);
extern void NBMS_App_step(void);
extern void NBMS_App_terminate(void);

/* Storage class 'Inputs' */
extern NBMS_App_Inputs_St NBMS_App_Inputs;

/* Storage class 'Outputs' */
extern NBMS_App_Outputs_St NBMS_App_Outputs;

/* Real-time Model object */
extern RT_MODEL_NBMS_App_T *const NBMS_App_M;

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
 * '<Root>' : 'NBMS_App'
 * '<S1>'   : 'NBMS_App/NBMS'
 */
#endif                                 /* NBMS_App_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
