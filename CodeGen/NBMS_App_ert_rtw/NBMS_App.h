/*
 * File: NBMS_App.h
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
  real_T SensorVoltFail;               /* '<S1>/State of Charge' */
  Charger_Mode_Req_E ChrgReq;          /* '<S1>/UdlyChrgReq' */
  BMS_HVMosfet_STS_E HVMosfet;         /* '<S1>/udlyHvMOSFET' */
  int16_T usecAvgBatteryCurrent;       /* '<S1>/State of Charge' */
  int16_T VoltageMin;                  /* '<S1>/State of Charge' */
  int16_T AvgSensorVoltFail;           /* '<S1>/State of Charge' */
  uint8_T DisplaySoC;                  /* '<S1>/udlyDSoC' */
  uint8_T soc_full;                    /* '<S1>/Charger Profile' */
} B_NBMS_App_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T udlyDCL_DSTATE;               /* '<S1>/udlyDCL' */
  BMS_HVMosfet_STS_E udlyHvMOSFET_DSTATE;/* '<S1>/udlyHvMOSFET' */
  Charger_Mode_Req_E UdlyChrgReq_DSTATE;/* '<S1>/UdlyChrgReq' */
  Charger_Mode_Req_E udlyChgReq_DSTATE;/* '<S1>/udlyChgReq' */
  BMS_MODE_E udlyBmsMode1_DSTATE;      /* '<S1>/udlyBmsMode1' */
  int16_T udlyMinCellVt_DSTATE;        /* '<S1>/udlyMinCellVt' */
  uint8_T udlyDSoC_DSTATE;             /* '<S1>/udlyDSoC' */
  uint8_T udlySoCFull_DSTATE;          /* '<S1>/udlySoCFull' */
  uint8_T uDlyDSOC_DSTATE;             /* '<S1>/uDlyDSOC' */
  uint8_T udlySOC_DSTATE;              /* '<S1>/udlySOC' */
  MdlrefDW_NBMS_SM_T BMSModeStateMachine_InstanceDat;/* '<S1>/BMS Mode State Machine' */
  MdlrefDW_NBMS_MosfetSeq_T MosfetControlStateMachine_Insta;/* '<S1>/Mosfet Control State Machine' */
  MdlrefDW_NBMS_SoC_T StateofCharge_InstanceData;/* '<S1>/State of Charge' */
  MdlrefDW_NBMS_Fault_T Fault_InstanceData;/* '<S1>/Fault' */
  MdlrefDW_NBMS_CCCV_T ChargerProfile_InstanceData;/* '<S1>/Charger Profile' */
  MdlrefDW_NBMS_DCL_T DischargeCurrentLimit_InstanceD;/* '<S1>/Discharge Current Limit' */
  MdlrefDW_NBMS_Regen_T RegenCurrentLimit_InstanceData;/* '<S1>/Regen Current Limit' */
} DW_NBMS_App_T;

/* Storage class 'Inputs', for system '<Root>' */
typedef struct {
  real_T BattTemp[6];                  /* '<Root>/AppIn_BattTemp' */
  real_T BattVolt[20];                 /* '<Root>/AppIn_BattVoltages' */
  real_T LoadVoltage;                  /* '<Root>/AppIn_LoadVolt' */
  real_T PackVoltage;                  /* '<Root>/AppIn_PackVolt' */
  real_T BattCurr;                     /* '<Root>/AppIn_BattCurrent' */
  real_T LastStoredSoC;                /* '<Root>/AppIn_LastStoredSOC' */
  real_T LastStoredCycle;              /* '<Root>/AppIn_LastStoredCycle' */
  real_T LastStoredSoH;                /* '<Root>/AppIn_LastStoredSOH' */
  OBC_E OBCWakeup;                     /* '<Root>/AppIn_OBCwakeup' */
  Charger_Mode_E ChgMode;              /* '<Root>/AppIn_ChgMode' */
  CV_Mode_Timer_E CvModeTimer;         /* '<Root>/AppIn_CVmodeTimer' */
  Active_DisChrg_E ActiveDischarge;    /* '<Root>/AppIn_ActiveDischg' */
  VEH_STT_LVL1_E VehicleLevel;         /* '<Root>/AppIn_VehL1' */
  boolean_T IgnitionStatus;            /* '<Root>/AppIn_HardwiredIgn' */
  boolean_T RTCWakeup;                 /* '<Root>/AppIn_RTCwakeup' */
  boolean_T McuInterlock;              /* '<Root>/AppIn_MCUHVIL' */
  boolean_T ObcInterlock;              /* '<Root>/AppIn_OBCHVIL' */
  boolean_T SocLedSwitch;              /* '<Root>/AppIn_SoCLEDSW' */
  boolean_T ThermalRunawayError;       /* '<Root>/AppIn_TRerror' */
  boolean_T ThermalRunawayTimer;       /* '<Root>/AppIn_TRtimer' */
  boolean_T G3CommonFault;             /* '<Root>/AppIn_G3CommonFlt' */
  boolean_T G3DischgFault;             /* '<Root>/AppIn_G3DischargeFlt' */
  boolean_T G4Type1DischargeFault;     /* '<Root>/AppIn_G4T1DischargeFlt' */
  boolean_T G4Type2DischargeFault;     /* '<Root>/AppIn_G4T2DischargeFlt' */
  boolean_T G4CommonFault;             /* '<Root>/AppIn_G4CommonFlt' */
  boolean_T G4ChargeFault;             /* '<Root>/AppIn_G4ChargeFlt' */
  boolean_T ObcHeartbeatFailure;       /* '<Root>/AppIn_OBCHeartbeatFail' */
  boolean_T I2CError;                  /* '<Root>/AppIn_I2Cerror' */
  boolean_T HVMosfetFb;                /* '<Root>/AppIn_HVMosfetfb' */
  boolean_T DCDCMosfetFb;              /* '<Root>/AppIn_DCDCMosfetfb' */
  boolean_T PrechgMosfetFb;            /* '<Root>/AppIn_PMosfetfb' */
  boolean_T BMSVoltSensorFailure;      /* '<Root>/AppIn_BMSVltSnsrFail' */
  boolean_T BattPackTempSensorFailure; /* '<Root>/AppIn_BattPackTempSnsrFail' */
  boolean_T VoltImbalanceError;        /* '<Root>/AppIn_VltImbFlt' */
  boolean_T TempImbalanceWarn;         /* '<Root>/AppIn_TempImbWarn' */
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
  BMS_HVMosfet_STS_E AppOut_HVMosfet;  /* '<Root>/AppOut_HVMosfet' */
  Charger_Mode_Req_E AppOut_ChgModeReq;/* '<Root>/AppOut_ChgModeReq' */
  BMS_MODE_E AppOut_BMSMODE;           /* '<Root>/AppOut_BMSMODE' */
  BMS_NM_Msg_E AppOut_BMS_NM_Msg;      /* '<Root>/AppOut_BMS_NM_Msg' */
  BMS_PMosfet_STS_E AppOut_PrechgMosfet;/* '<Root>/AppOut_PrechgMosfet' */
  BMS_DCDCMosfet_STS_E AppOut_DCDCMosfet;/* '<Root>/AppOut_DCDCMosfet' */
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
  boolean_T AppOut_DerateFlg;          /* '<Root>/AppOut_DerateFlg' */
} NBMS_App_Outputs_St;

/* Real-time Model Data Structure */
struct tag_RTM_NBMS_App_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_NBMS_App_T NBMS_App_B;

/* Block states (default storage) */
extern DW_NBMS_App_T NBMS_App_DW;

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
