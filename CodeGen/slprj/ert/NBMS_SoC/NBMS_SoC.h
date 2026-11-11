/*
 * File: NBMS_SoC.h
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

#ifndef NBMS_SoC_h_
#define NBMS_SoC_h_
#ifndef NBMS_SoC_COMMON_INCLUDES_
#define NBMS_SoC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* NBMS_SoC_COMMON_INCLUDES_ */

#include "NBMS_SoC_types.h"
#include "NBMS_DischargeOCV.h"
#include "NBMS_ChargeOCV.h"
#include "zero_crossing_types.h"

/* Includes for objects with custom storage classes */
#include "DID.h"

/* Block states (default storage) for system '<S83>/Moving Average' */
typedef struct {
  real_T Delayfor1Unit_DSTATE;         /* '<S125>/Delayfor1Unit' */
  int16_T u0Delay_DWORK1[20];          /* '<S125>/20Delay' */
} DW_MovingAverage_NBMS_SoC_T;

/* Block signals for model 'NBMS_SoC' */
typedef struct {
  real_T InitialDichargeOCV;           /* '<S81>/InitialDichargeOCV' */
  real_T InitialChargeOCV;             /* '<S81>/InitialChargeOCV' */
  real_T InitialTemp;                  /* '<S90>/Temp' */
  real_T Temp;                         /* '<S35>/Temp' */
  real_T InitialSOC;                   /* '<S5>/InitialSocManager' */
  real_T out;                          /* '<S51>/StateWaitCondition' */
  real_T Switch2;                      /* '<S59>/Switch2' */
  real_T InitialCapacity;              /* '<S41>/CurrCapacity' */
  real_T ChargeMeasured;               /* '<S15>/scaleBattCurr' */
  real_T ChargeOCV;                    /* '<S81>/ChargeOCV' */
  real_T DischargeOCV;                 /* '<S81>/DischargeOCV' */
  real_T DischgOCV;                    /* '<S5>/DischgOCV' */
  int16_T u1stSample;                  /* '<S98>/ConvertToFixdt' */
  int16_T u1stSample_d;                /* '<S97>/ConvertToFixdt' */
  int16_T usecAvgBatteryCurrent;       /* '<S97>/Sample Accumulator ' */
  int16_T ConvBattVolt[20];            /* '<S1>/ConvertToFixdt' */
  int16_T u1stVoltage;                 /* '<S146>/FixdtDataTypeConversion' */
  int16_T AvgVoltofCell9;              /* '<S144>/Counterfor20' */
  int16_T AvgVoltofCell8;              /* '<S143>/Counterfor20' */
  int16_T AvgVoltofCell7;              /* '<S142>/Counterfor20' */
  int16_T AvgVoltofCell6;              /* '<S141>/Counterfor20' */
  int16_T AvgVoltofCell5;              /* '<S140>/Counterfor20' */
  int16_T AvgVoltofCell4;              /* '<S139>/Counterfor20' */
  int16_T AvgVoltofCell3;              /* '<S138>/Counterfor20' */
  int16_T AvgVoltofCell2;              /* '<S137>/Counterfor20' */
  int16_T AvgVoltofCell19;             /* '<S136>/Counterfor20' */
  int16_T AvgVoltofCell18;             /* '<S135>/Counterfor20' */
  int16_T AvgVoltofCell17;             /* '<S134>/Counterfor20' */
  int16_T AvgVoltofCell16;             /* '<S133>/Counterfor20' */
  int16_T AvgVoltofCell15;             /* '<S132>/Counterfor20' */
  int16_T AvgVoltofCell14;             /* '<S131>/Counterfor20' */
  int16_T AvgVoltofCell13;             /* '<S130>/Counterfor20' */
  int16_T AvgVoltofCell12;             /* '<S129>/Counterfor20' */
  int16_T AvgVoltofCell11;             /* '<S128>/Counterfor20' */
  int16_T AvgVoltofCell10;             /* '<S127>/Counterfor20' */
  int16_T AvgVoltofCell1;              /* '<S126>/Counterfor20' */
  int16_T AvgVoltofCell0;              /* '<S125>/Counterfor20' */
  uint8_T SoC;                         /* '<S68>/SOC_Full' */
  uint8_T LatchedFullSoC;              /* '<S61>/SOC_Full' */
  uint8_T SoCStart;                    /* '<S27>/Display_SOC' */
  boolean_T Compare;                   /* '<S86>/Compare' */
  boolean_T Compare_k;                 /* '<S85>/Compare' */
  boolean_T Compare_h;                 /* '<S91>/Compare' */
  boolean_T TriggerswhentheBMSModeisDischar;/* '<S81>/logIsNotCharging' */
  boolean_T Compare_b;                 /* '<S99>/Compare' */
  boolean_T Logic[2];                  /* '<S72>/Logic' */
} B_NBMS_SoC_c_T;

/* Block states (default storage) for model 'NBMS_SoC' */
typedef struct {
  real_T udlyPackSoC_DSTATE;           /* '<S1>/udlyPackSoC' */
  real_T udlySoH_DSTATE;               /* '<S1>/udlySoH' */
  real_T DischargeAccumulator_DSTATE;  /* '<S5>/DischargeAccumulator' */
  real_T CalcCurrAccum_DSTATE;         /* '<S5>/CalcCurrAccum' */
  real_T udlySoCcc_DSTATE;             /* '<S5>/udlySoCcc' */
  real_T udlySoC_DSTATE;               /* '<S33>/udlySoC' */
  real_T udlyLifeCycle_DSTATE;         /* '<S4>/udlyLifeCycle' */
  real_T AccumulateBattCurrent_DSTATE; /* '<S9>/Accumulate BattCurrent' */
  real_T udlyCycleCount_DSTATE;        /* '<S9>/udlyCycleCount' */
  real_T udlyLifeCylce_DSTATE;         /* '<S9>/udlyLifeCylce' */
  real_T CoulombCounter_DSTATE;        /* '<S32>/CoulombCounter' */
  real_T udlyCurrentCapacity_DSTATE;   /* '<S32>/udlyCurrentCapacity' */
  real_T PreviousValue_DSTATE;         /* '<S146>/PreviousValue' */
  real_T uDlyBattSoC_DSTATE;           /* '<S52>/uDlyBattSoC' */
  real_T udlyBattSoC_DSTATE;           /* '<S52>/udlyBattSoC' */
  real_T udlySoCError_DSTATE;          /* '<S42>/udlySoCError' */
  real_T CalcAccumulatedBattCurr_DSTATE;/* '<S15>/CalcAccumulatedBattCurr' */
  real_T count;                        /* '<S51>/StateWaitCondition' */
  BMS_MODE_E udlyBMSMode_DSTATE;       /* '<S9>/udlyBMSMode' */
  Charger_Mode_Req_E udlyChgModeReq_DSTATE;/* '<S10>/udlyChgModeReq' */
  uint16_T DelayInput1_DSTATE;         /* '<S89>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_f;       /* '<S48>/Delay Input1' */
  int16_T u0Delay_DWORK1[20];          /* '<S146>/20Delay' */
  int16_T u0Delay_DWORK1_m[50];        /* '<S98>/50Delay' */
  int16_T u0Delay_DWORK1_p[20];        /* '<S97>/20Delay' */
  uint8_T udlyDislaySoC_DSTATE;        /* '<S33>/udlyDislaySoC' */
  uint8_T UDlySOC_DSTATE;              /* '<S33>/UDlySOC' */
  uint8_T uDlySoC_DSTATE;              /* '<S33>/uDlySoC' */
  uint8_T UdlySoc_DSTATE;              /* '<S33>/UdlySoc' */
  uint8_T udlyDSoC_DSTATE;             /* '<S33>/udlyDSoC' */
  uint8_T udlyDisplaySoC_DSTATE;       /* '<S33>/udlyDisplaySoC' */
  uint8_T udlySoH_DSTATE_k;            /* '<S10>/udlySoH' */
  uint8_T uUnitDelay_DSTATE;           /* '<S98>/1UnitDelay' */
  uint8_T uUnitDelay_DSTATE_f;         /* '<S97>/1UnitDelay' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S88>/Delay Input1' */
  boolean_T ZeroReset_DSTATE;          /* '<S33>/ZeroReset' */
  boolean_T udlyEnableCurrent_DSTATE;  /* '<S51>/udlyEnableCurrent' */
  boolean_T udlySoHtrigger_DSTATE;     /* '<S10>/udlySoHtrigger' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S25>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ju;     /* '<S40>/Delay Input1' */
  boolean_T udlyStartSoC_DSTATE;       /* '<S1>/udlyStartSoC' */
  int8_T DischargeAccumulator_PrevResetS;/* '<S5>/DischargeAccumulator' */
  int8_T CalcCurrAccum_PrevResetState; /* '<S5>/CalcCurrAccum' */
  int8_T AccumulateBattCurrent_PrevReset;/* '<S9>/Accumulate BattCurrent' */
  int8_T CoulombCounter_PrevResetState;/* '<S32>/CoulombCounter' */
  int8_T CalcAccumulatedBattCurr_PrevRes;/* '<S15>/CalcAccumulatedBattCurr' */
  uint8_T is_active_c5_NBMS_SoC;       /* '<S83>/FindMinVolt' */
  uint8_T is_active_c2_NBMS_SoC;       /* '<S83>/FindMinAvgVolt' */
  uint8_T is_active_c18_NBMS_SoC;      /* '<S81>/SOC_Init_Decision' */
  uint8_T is_SOC_Init;                 /* '<S81>/SOC_Init_Decision' */
  uint8_T is_active_c15_NBMS_SoC;      /* '<S36>/SocStateController' */
  uint8_T is_c15_NBMS_SoC;             /* '<S36>/SocStateController' */
  uint8_T is_active_c14_NBMS_SoC;      /* '<S5>/InitialSocManager' */
  uint8_T is_c14_NBMS_SoC;             /* '<S5>/InitialSocManager' */
  uint8_T is_active_c1_NBMS_SoC;       /* '<S51>/StateWaitCondition' */
  uint8_T is_Decision;                 /* '<S51>/StateWaitCondition' */
  boolean_T Memory_PreviousInput;      /* '<S50>/Memory' */
  boolean_T Memory_PreviousInput_c;    /* '<S93>/Memory' */
  boolean_T Memory_PreviousInput_m;    /* '<S17>/Memory' */
  boolean_T Memory_PreviousInput_a;    /* '<S73>/Memory' */
  boolean_T Memory_PreviousInput_ar;   /* '<S74>/Memory' */
  boolean_T Memory_PreviousInput_g;    /* '<S72>/Memory' */
  boolean_T OneSensorVoltFailure_MODE; /* '<S83>/OneSensorVoltFailure' */
  boolean_T MovingAverageCurrent5sec_MODE;/* '<S82>/MovingAverageCurrent5sec' */
  boolean_T MovingAverageCurrent2sec_MODE;/* '<S82>/MovingAverageCurrent2sec' */
  boolean_T SOCFaultDetection_MODE;    /* '<S1>/SOC Fault Detection' */
  MdlrefDW_NBMS_DischargeOCV_T InitialDichargeOCV_InstanceData;/* '<S81>/InitialDichargeOCV' */
  MdlrefDW_NBMS_ChargeOCV_T InitialChargeOCV_InstanceData;/* '<S81>/InitialChargeOCV' */
  MdlrefDW_NBMS_ChargeOCV_T ChargeOCV_InstanceData;/* '<S81>/ChargeOCV' */
  MdlrefDW_NBMS_DischargeOCV_T DischargeOCV_InstanceData;/* '<S81>/DischargeOCV' */
  MdlrefDW_NBMS_DischargeOCV_T DischgOCV_InstanceData;/* '<S5>/DischgOCV' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage9;/* '<S83>/Moving Average9' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage8;/* '<S83>/Moving Average8' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage7;/* '<S83>/Moving Average7' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage6;/* '<S83>/Moving Average6' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage5;/* '<S83>/Moving Average5' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage4;/* '<S83>/Moving Average4' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage3;/* '<S83>/Moving Average3' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage2;/* '<S83>/Moving Average2' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage19;/* '<S83>/Moving Average19' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage18;/* '<S83>/Moving Average18' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage17;/* '<S83>/Moving Average17' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage16;/* '<S83>/Moving Average16' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage15;/* '<S83>/Moving Average15' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage14;/* '<S83>/Moving Average14' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage13;/* '<S83>/Moving Average13' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage12;/* '<S83>/Moving Average12' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage11;/* '<S83>/Moving Average11' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage10;/* '<S83>/Moving Average10' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage1;/* '<S83>/Moving Average1' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage;/* '<S83>/Moving Average' */
} DW_NBMS_SoC_f_T;

/* Zero-crossing (trigger) state for model 'NBMS_SoC' */
typedef struct {
  ZCSigState InitPackTemperature_Trig_ZCE;/* '<S81>/InitPackTemperature' */
  ZCSigState LatchSoC_Trig_ZCE;        /* '<S36>/LatchSoC' */
  ZCSigState LatchTempinit_Trig_ZCE;   /* '<S5>/LatchTempinit' */
  ZCSigState LatchFullSoc_Trig_ZCE;    /* '<S51>/LatchFullSoc' */
  ZCSigState LatchInitCapacity_Trig_ZCE;/* '<S32>/LatchInitCapacity' */
  ZCSigState Initial_SoC_Storage_Trig_ZCE;/* '<S10>/Initial_SoC_Storage' */
  ZCSigState CalcOCV_Trig_ZCE;         /* '<S1>/CalcOCV' */
} ZCE_NBMS_SoC_T;

/* Real-time Model Data Structure */
struct tag_RTM_NBMS_SoC_T {
  const char_T **errorStatus;
};

typedef struct {
  B_NBMS_SoC_c_T rtb;
  DW_NBMS_SoC_f_T rtdw;
  RT_MODEL_NBMS_SoC_T rtm;
  ZCE_NBMS_SoC_T rtzce;
} MdlrefDW_NBMS_SoC_T;

/* Model reference registration function */
extern void NBMS_SoC_initialize(const char_T **rt_errorStatus,
  RT_MODEL_NBMS_SoC_T *const NBMS_SoC_M, DW_NBMS_SoC_f_T *localDW,
  ZCE_NBMS_SoC_T *localZCE);
extern void NBMS_SoC_MovingAverage(boolean_T rtu_EnableCellVoltValid, int16_T
  rtu_In, int16_T *rty_Out, DW_MovingAverage_NBMS_SoC_T *localDW);
extern void NBMS_SoC_Init(boolean_T *rty_LOW_SOC, real_T *rty_FailSensorVolt,
  int16_T *rty_FailSensorVoltAvg, B_NBMS_SoC_c_T *localB, DW_NBMS_SoC_f_T
  *localDW);
extern void NBMS_SoC_Disable(boolean_T *rty_LOW_SOC_WARN_15, boolean_T
  *rty_LOW_SOC, boolean_T *rty_LOW_SOC_WARN, real_T *rty_FailSensorVolt, int16_T
  *rty_FailSensorVoltAvg, int16_T *rty_BatteryCurrentAvg5sec, B_NBMS_SoC_c_T
  *localB, DW_NBMS_SoC_f_T *localDW);
extern void NBMS_SoC(const uint8_T *rtu_soc_full, const real_T rtu_Batt_Temps[6],
                     const real_T *rtu_AppIn_BattCurrent, const real_T
                     rtu_AppIn_BattVoltages[20], const boolean_T *rtu_Ignition,
                     const Charger_Mode_Req_E *rtu_Charger_Mode_Req, const
                     BMS_MODE_E *rtu_sm_BMSMODE_en, const real_T
                     *rtu_AppIn_LastStoredSOC, const real_T
                     *rtu_AppIn_LastStoredCycle, const boolean_T
                     *rtu_AppIn_I2Cerror, const real_T *rtu_AppIn_LastStoredSOH,
                     const OBC_E *rtu_OBCWakeup, const real_T *rtu_mi_Pack_Volt,
                     const VEH_STT_LVL1_E *rtu_AppIn_VehL1, const real_T
                     *rtu_DischrgCurrLimit, uint8_T *rty_Display_SOC, real_T
                     *rty_Battery_Capacity, boolean_T *rty_LOW_SOC_WARN_15,
                     boolean_T *rty_LOW_SOC, boolean_T *rty_LOW_SOC_WARN, real_T
                     *rty_Batt_Pack_SOC, real_T *rty_LifeCycle, real_T *rty_SOH,
                     int16_T *rty_VtAvgMax, real_T *rty_CurrentCapacity,
                     uint16_T *rty_SOCcc, uint16_T *rty_SOCAvg, int16_T
                     *rty_Vmin, real_T *rty_SOC_OCVInit, real_T
                     *rty_SOCAvgInitial, real_T *rty_AvailableEnergy, int16_T
                     *rty_VtAvgMin, real_T *rty_FailSensorVolt, int16_T
                     *rty_FailSensorVoltAvg, int16_T *rty_BatteryCurrentAvg5sec,
                     real_T *rty_ChargeCapacity, B_NBMS_SoC_c_T *localB,
                     DW_NBMS_SoC_f_T *localDW, ZCE_NBMS_SoC_T *localZCE);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Propagation' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Propagation' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Data Type Propagation' : Unused code path elimination
 * Block '<S33>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S125>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S126>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S127>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S128>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S129>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S130>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S131>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S132>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S133>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S134>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S135>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S136>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S137>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S138>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S139>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S140>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S141>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S142>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S143>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S144>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'NBMS_SoC'
 * '<S1>'   : 'NBMS_SoC/SOC'
 * '<S2>'   : 'NBMS_SoC/SOC/CalcOCV'
 * '<S3>'   : 'NBMS_SoC/SOC/ChkOBCWakeupStatus'
 * '<S4>'   : 'NBMS_SoC/SOC/LifeCycle SOH Energy'
 * '<S5>'   : 'NBMS_SoC/SOC/SOC Estimation'
 * '<S6>'   : 'NBMS_SoC/SOC/SOC Fault Detection'
 * '<S7>'   : 'NBMS_SoC/SOC/VtAvg'
 * '<S8>'   : 'NBMS_SoC/SOC/LifeCycle SOH Energy/CalcAvailableEnergy '
 * '<S9>'   : 'NBMS_SoC/SOC/LifeCycle SOH Energy/Life Cycle'
 * '<S10>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health'
 * '<S11>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/Life Cycle/CheckBMSModeIsNotSleep'
 * '<S12>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/Life Cycle/ChkBMSModeIsSleep'
 * '<S13>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/Life Cycle/ChkBMSModeIsStandby'
 * '<S14>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/Life Cycle/ChkBmsModeIsSleep'
 * '<S15>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/CalcChgMeasured'
 * '<S16>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/CalculateSoH'
 * '<S17>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChgStartLatch'
 * '<S18>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkBmsModeIsCharge'
 * '<S19>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkChgCompleted'
 * '<S20>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkChgHasStartedBelow10'
 * '<S21>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkChgModeReqCCStart'
 * '<S22>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkChgModeReqCV'
 * '<S23>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkChgModeReqStandby'
 * '<S24>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkChgPerIs100'
 * '<S25>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkIgnHasTurnedOn'
 * '<S26>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkLifeCycleActive'
 * '<S27>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/Initial_SoC_Storage'
 * '<S28>'  : 'NBMS_SoC/SOC/SOC Estimation/Cell Chemestry Selection'
 * '<S29>'  : 'NBMS_SoC/SOC/SOC Estimation/ChkBmsModeSleep'
 * '<S30>'  : 'NBMS_SoC/SOC/SOC Estimation/ChkChgModeReqChgComplete'
 * '<S31>'  : 'NBMS_SoC/SOC/SOC Estimation/ChkcycleLessThanZero'
 * '<S32>'  : 'NBMS_SoC/SOC/SOC Estimation/CurrentCapacityCalculation'
 * '<S33>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC'
 * '<S34>'  : 'NBMS_SoC/SOC/SOC Estimation/InitialSocManager'
 * '<S35>'  : 'NBMS_SoC/SOC/SOC Estimation/LatchTempinit'
 * '<S36>'  : 'NBMS_SoC/SOC/SOC Estimation/SOC Overriding Handling'
 * '<S37>'  : 'NBMS_SoC/SOC/SOC Estimation/chkSocDeviation'
 * '<S38>'  : 'NBMS_SoC/SOC/SOC Estimation/Cell Chemestry Selection/ChkBMSModeNotSleep'
 * '<S39>'  : 'NBMS_SoC/SOC/SOC Estimation/CurrentCapacityCalculation/ChkIsBMSModeCharge'
 * '<S40>'  : 'NBMS_SoC/SOC/SOC Estimation/CurrentCapacityCalculation/ChkIsChargeModeTriggered'
 * '<S41>'  : 'NBMS_SoC/SOC/SOC Estimation/CurrentCapacityCalculation/LatchInitCapacity'
 * '<S42>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/CalcSoCCorrection'
 * '<S43>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkBMSMODEIsSleep'
 * '<S44>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkBMSModeIsCharge'
 * '<S45>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkBMSModeSleep'
 * '<S46>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkBMSModeisCharge'
 * '<S47>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkBmsModeCharge'
 * '<S48>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkHasAvgSoCChanged'
 * '<S49>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkSoCabove0'
 * '<S50>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/DisplaySocLockLatch'
 * '<S51>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge'
 * '<S52>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/LatchBattSoc'
 * '<S53>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/SOC_Offset'
 * '<S54>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/SOC_factor'
 * '<S55>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/chkIgnitionOff'
 * '<S56>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/satDynamicLowerBound'
 * '<S57>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/satDynamicUpperBound'
 * '<S58>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/CalcSoCCorrection/ChkBMSModeIsSleep'
 * '<S59>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/CalcSoCCorrection/SocCorrectionLimits'
 * '<S60>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge/ChkChgModeReqChgComplete'
 * '<S61>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge/LatchFullSoc'
 * '<S62>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge/StateWaitCondition'
 * '<S63>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge/chkIsModeCharge'
 * '<S64>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge/chkPackSocBelowFull'
 * '<S65>'  : 'NBMS_SoC/SOC/SOC Estimation/SOC Overriding Handling/ChkBMSModeSleep'
 * '<S66>'  : 'NBMS_SoC/SOC/SOC Estimation/SOC Overriding Handling/ChkChgModeReqChgComplete'
 * '<S67>'  : 'NBMS_SoC/SOC/SOC Estimation/SOC Overriding Handling/ChkChgModeReqDisabled'
 * '<S68>'  : 'NBMS_SoC/SOC/SOC Estimation/SOC Overriding Handling/LatchSoC'
 * '<S69>'  : 'NBMS_SoC/SOC/SOC Estimation/SOC Overriding Handling/SocStateController'
 * '<S70>'  : 'NBMS_SoC/SOC/SOC Fault Detection/ChkBMSModeDischarge'
 * '<S71>'  : 'NBMS_SoC/SOC/SOC Fault Detection/ChkBMSModeFault'
 * '<S72>'  : 'NBMS_SoC/SOC/SOC Fault Detection/LowSocAlertLatch'
 * '<S73>'  : 'NBMS_SoC/SOC/SOC Fault Detection/Soc15WarningLatch'
 * '<S74>'  : 'NBMS_SoC/SOC/SOC Fault Detection/Soc20WarningLatch'
 * '<S75>'  : 'NBMS_SoC/SOC/SOC Fault Detection/chkDisplaySocAbove15Recovery'
 * '<S76>'  : 'NBMS_SoC/SOC/SOC Fault Detection/chkDisplaySocAbove20Recovery'
 * '<S77>'  : 'NBMS_SoC/SOC/SOC Fault Detection/chkDisplaySocAboveLowRecovery'
 * '<S78>'  : 'NBMS_SoC/SOC/SOC Fault Detection/chkDisplaySocBelow15Thresh'
 * '<S79>'  : 'NBMS_SoC/SOC/SOC Fault Detection/chkDisplaySocBelow20Thresh'
 * '<S80>'  : 'NBMS_SoC/SOC/SOC Fault Detection/chkDisplaySocBelowLowThresh'
 * '<S81>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC'
 * '<S82>'  : 'NBMS_SoC/SOC/VtAvg/IR Calculation'
 * '<S83>'  : 'NBMS_SoC/SOC/VtAvg/Voltage Average'
 * '<S84>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/CheckBMSModeCharge'
 * '<S85>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/ChkBMSModeCharge'
 * '<S86>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/ChkBMSModeDischg'
 * '<S87>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/ChkIgnOff'
 * '<S88>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/ChkOBCWakeupIncrease'
 * '<S89>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/ChkSoCHysteresisChange'
 * '<S90>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/InitPackTemperature'
 * '<S91>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/IsBMSModeCharge'
 * '<S92>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/SOC_Init_Decision'
 * '<S93>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/SoCStateLatch'
 * '<S94>'  : 'NBMS_SoC/SOC/VtAvg/IR Calculation/Check If the VehicleState is DRIVE'
 * '<S95>'  : 'NBMS_SoC/SOC/VtAvg/IR Calculation/Check if  BMS Mode &#x2260; SLEEP     '
 * '<S96>'  : 'NBMS_SoC/SOC/VtAvg/IR Calculation/Check if BMS Mode is CHARGE'
 * '<S97>'  : 'NBMS_SoC/SOC/VtAvg/IR Calculation/MovingAverageCurrent2sec'
 * '<S98>'  : 'NBMS_SoC/SOC/VtAvg/IR Calculation/MovingAverageCurrent5sec'
 * '<S99>'  : 'NBMS_SoC/SOC/VtAvg/IR Calculation/MovingAverageCurrent2sec/CheckBufferComplete  '
 * '<S100>' : 'NBMS_SoC/SOC/VtAvg/IR Calculation/MovingAverageCurrent5sec/CheckBufferComplete'
 * '<S101>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell0'
 * '<S102>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell1'
 * '<S103>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell10'
 * '<S104>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell11'
 * '<S105>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell12'
 * '<S106>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell13'
 * '<S107>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell14'
 * '<S108>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell15'
 * '<S109>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell16'
 * '<S110>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell17'
 * '<S111>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell18'
 * '<S112>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell19'
 * '<S113>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell2'
 * '<S114>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell3'
 * '<S115>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell4'
 * '<S116>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell5'
 * '<S117>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell6'
 * '<S118>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell7'
 * '<S119>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell8'
 * '<S120>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell9'
 * '<S121>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/CountforOneCellFail'
 * '<S122>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/FindMinAvgVolt'
 * '<S123>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/FindMinVolt'
 * '<S124>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/FindNonZeroCellVolt'
 * '<S125>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average'
 * '<S126>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average1'
 * '<S127>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average10'
 * '<S128>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average11'
 * '<S129>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average12'
 * '<S130>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average13'
 * '<S131>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average14'
 * '<S132>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average15'
 * '<S133>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average16'
 * '<S134>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average17'
 * '<S135>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average18'
 * '<S136>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average19'
 * '<S137>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average2'
 * '<S138>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average3'
 * '<S139>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average4'
 * '<S140>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average5'
 * '<S141>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average6'
 * '<S142>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average7'
 * '<S143>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average8'
 * '<S144>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average9'
 * '<S145>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/OneSensorVoltFailure'
 * '<S146>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/OneSensorVoltFailure/AverageofSensorVoltFail'
 */
#endif                                 /* NBMS_SoC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
