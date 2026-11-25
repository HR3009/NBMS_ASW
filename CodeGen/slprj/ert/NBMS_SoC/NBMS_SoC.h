/*
 * File: NBMS_SoC.h
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

/* Block states (default storage) for system '<S93>/Moving Average' */
typedef struct {
  real_T Delayfor1Unit_DSTATE;         /* '<S135>/Delayfor1Unit' */
  int16_T u0Delay_DWORK1[20];          /* '<S135>/20Delay' */
} DW_MovingAverage_NBMS_SoC_T;

/* Block signals for model 'NBMS_SoC' */
typedef struct {
  real_T DischgInitialSoC;             /* '<S91>/InitialDichargeOCV' */
  real_T ChgInitialSoC;                /* '<S91>/InitialChargeOCV' */
  real_T InitialTemp;                  /* '<S100>/Temp' */
  real_T Temp;                         /* '<S44>/Temp' */
  real_T InitialSOC;                   /* '<S6>/InitialSocManager' */
  real_T out;                          /* '<S60>/StateWaitCondition' */
  real_T Switch2;                      /* '<S68>/Switch2' */
  real_T InitialCapacity;              /* '<S50>/CurrCapacity' */
  real_T ChargeMeasured;               /* '<S23>/scaleBattCurr' */
  real_T ChgInitialSoC_b;              /* '<S91>/ChargeOCV' */
  real_T DischgInitialSoC_i;           /* '<S91>/DischargeOCV' */
  real_T DischgInitialSoC_p;           /* '<S6>/DischgOCV' */
  int16_T u1stSample;                  /* '<S108>/ConvertToFixdt' */
  int16_T u1stSample_d;                /* '<S107>/ConvertToFixdt' */
  int16_T usecAvgBatteryCurrent;       /* '<S107>/Sample Accumulator ' */
  int16_T ConvBattVolt[20];            /* '<S1>/ConvertToFixdt' */
  int16_T u1stVoltage;                 /* '<S156>/FixdtDataTypeConversion' */
  int16_T AvgVoltofCell9;              /* '<S154>/Counterfor20' */
  int16_T AvgVoltofCell8;              /* '<S153>/Counterfor20' */
  int16_T AvgVoltofCell7;              /* '<S152>/Counterfor20' */
  int16_T AvgVoltofCell6;              /* '<S151>/Counterfor20' */
  int16_T AvgVoltofCell5;              /* '<S150>/Counterfor20' */
  int16_T AvgVoltofCell4;              /* '<S149>/Counterfor20' */
  int16_T AvgVoltofCell3;              /* '<S148>/Counterfor20' */
  int16_T AvgVoltofCell2;              /* '<S147>/Counterfor20' */
  int16_T AvgVoltofCell19;             /* '<S146>/Counterfor20' */
  int16_T AvgVoltofCell18;             /* '<S145>/Counterfor20' */
  int16_T AvgVoltofCell17;             /* '<S144>/Counterfor20' */
  int16_T AvgVoltofCell16;             /* '<S143>/Counterfor20' */
  int16_T AvgVoltofCell15;             /* '<S142>/Counterfor20' */
  int16_T AvgVoltofCell14;             /* '<S141>/Counterfor20' */
  int16_T AvgVoltofCell13;             /* '<S140>/Counterfor20' */
  int16_T AvgVoltofCell12;             /* '<S139>/Counterfor20' */
  int16_T AvgVoltofCell11;             /* '<S138>/Counterfor20' */
  int16_T AvgVoltofCell10;             /* '<S137>/Counterfor20' */
  int16_T AvgVoltofCell1;              /* '<S136>/Counterfor20' */
  int16_T AvgVoltofCell0;              /* '<S135>/Counterfor20' */
  uint8_T SoC;                         /* '<S78>/SOC_Full' */
  uint8_T LatchedFullSoC;              /* '<S71>/SOC_Full' */
  boolean_T Compare;                   /* '<S96>/Compare' */
  boolean_T Compare_k;                 /* '<S95>/Compare' */
  boolean_T Compare_h;                 /* '<S101>/Compare' */
  boolean_T TriggerswhentheBMSModeisDischar;/* '<S91>/logIsNotCharging' */
  boolean_T Compare_b;                 /* '<S109>/Compare' */
  boolean_T Logic[2];                  /* '<S82>/Logic' */
} B_NBMS_SoC_c_T;

/* Block states (default storage) for model 'NBMS_SoC' */
typedef struct {
  real_T udlyPackSoC_DSTATE;           /* '<S1>/udlyPackSoC' */
  real_T udlySoH_DSTATE;               /* '<S1>/udlySoH' */
  real_T DischargeAccumulator_DSTATE;  /* '<S6>/DischargeAccumulator' */
  real_T CalcCurrAccum_DSTATE;         /* '<S6>/CalcCurrAccum' */
  real_T udlySoCcc_DSTATE;             /* '<S6>/udlySoCcc' */
  real_T udlySoC_DSTATE;               /* '<S42>/udlySoC' */
  real_T AccumulateBattCurrent_DSTATE; /* '<S17>/Accumulate BattCurrent' */
  real_T udlyCycleCount_DSTATE;        /* '<S17>/udlyCycleCount' */
  real_T udlyLifeCylce_DSTATE;         /* '<S17>/udlyLifeCylce' */
  real_T CoulombCounter_DSTATE;        /* '<S41>/CoulombCounter' */
  real_T udlyCurrentCapacity_DSTATE;   /* '<S41>/udlyCurrentCapacity' */
  real_T PreviousValue_DSTATE;         /* '<S156>/PreviousValue' */
  real_T uDlyBattSoC_DSTATE;           /* '<S61>/uDlyBattSoC' */
  real_T udlyBattSoC_DSTATE;           /* '<S61>/udlyBattSoC' */
  real_T udlySoCError_DSTATE;          /* '<S51>/udlySoCError' */
  real_T CalcAccumulatedBattCurr_DSTATE;/* '<S23>/CalcAccumulatedBattCurr' */
  real_T count;                        /* '<S60>/StateWaitCondition' */
  BMS_MODE_E UnitDelay_DSTATE;         /* '<S6>/Unit Delay' */
  BMS_MODE_E udlyBMSMode_DSTATE;       /* '<S17>/udlyBMSMode' */
  Charger_Mode_Req_E udlyChgModeReq_DSTATE;/* '<S18>/udlyChgModeReq' */
  uint16_T DelayInput1_DSTATE;         /* '<S99>/Delay Input1' */
  uint16_T DelayInput1_DSTATE_f;       /* '<S57>/Delay Input1' */
  int16_T u0Delay_DWORK1[20];          /* '<S156>/20Delay' */
  int16_T u0Delay_DWORK1_m[50];        /* '<S108>/50Delay' */
  int16_T u0Delay_DWORK1_p[20];        /* '<S107>/20Delay' */
  uint8_T uDlySoC_DSTATE;              /* '<S42>/uDlySoC' */
  uint8_T UDlySOC_DSTATE;              /* '<S42>/UDlySOC' */
  uint8_T UdlySoc_DSTATE;              /* '<S42>/UdlySoc' */
  uint8_T udlyDislaySoC_DSTATE;        /* '<S42>/udlyDislaySoC' */
  uint8_T udlyDSoC_DSTATE;             /* '<S42>/udlyDSoC' */
  uint8_T udlyDisplaySoC_DSTATE;       /* '<S42>/udlyDisplaySoC' */
  uint8_T uUnitDelay_DSTATE;           /* '<S108>/1UnitDelay' */
  uint8_T uUnitDelay_DSTATE_f;         /* '<S107>/1UnitDelay' */
  boolean_T DelayInput1_DSTATE_g;      /* '<S98>/Delay Input1' */
  boolean_T ZeroReset_DSTATE;          /* '<S42>/ZeroReset' */
  boolean_T udlyEnableCurrent_DSTATE;  /* '<S60>/udlyEnableCurrent' */
  boolean_T DelayInput1_DSTATE_a;      /* '<S70>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_j;      /* '<S49>/Delay Input1' */
  boolean_T udlyStartSoC_DSTATE;       /* '<S1>/udlyStartSoC' */
  int8_T DischargeAccumulator_PrevResetS;/* '<S6>/DischargeAccumulator' */
  int8_T CalcCurrAccum_PrevResetState; /* '<S6>/CalcCurrAccum' */
  int8_T AccumulateBattCurrent_PrevReset;/* '<S17>/Accumulate BattCurrent' */
  int8_T CoulombCounter_PrevResetState;/* '<S41>/CoulombCounter' */
  int8_T CalcAccumulatedBattCurr_PrevRes;/* '<S23>/CalcAccumulatedBattCurr' */
  uint8_T is_active_c5_NBMS_SoC;       /* '<S93>/FindMinVolt' */
  uint8_T is_active_c2_NBMS_SoC;       /* '<S93>/FindMinAvgVolt' */
  uint8_T is_active_c18_NBMS_SoC;      /* '<S91>/SOC_Init_Decision' */
  uint8_T is_SOC_Init;                 /* '<S91>/SOC_Init_Decision' */
  uint8_T is_active_c15_NBMS_SoC;      /* '<S45>/SocStateController' */
  uint8_T is_c15_NBMS_SoC;             /* '<S45>/SocStateController' */
  uint8_T is_active_c14_NBMS_SoC;      /* '<S6>/InitialSocManager' */
  uint8_T is_c14_NBMS_SoC;             /* '<S6>/InitialSocManager' */
  uint8_T is_active_c1_NBMS_SoC;       /* '<S60>/StateWaitCondition' */
  uint8_T is_Decision;                 /* '<S60>/StateWaitCondition' */
  boolean_T Memory_PreviousInput;      /* '<S59>/Memory' */
  boolean_T Memory_PreviousInput_c;    /* '<S103>/Memory' */
  boolean_T Memory_PreviousInput_a;    /* '<S84>/Memory' */
  boolean_T Memory_PreviousInput_g;    /* '<S82>/Memory' */
  boolean_T Memory_PreviousInput_al;   /* '<S83>/Memory' */
  boolean_T OneSensorVoltFailure_MODE; /* '<S93>/OneSensorVoltFailure' */
  boolean_T MovingAverageCurrent5sec_MODE;/* '<S92>/MovingAverageCurrent5sec' */
  boolean_T MovingAverageCurrent2sec_MODE;/* '<S92>/MovingAverageCurrent2sec' */
  boolean_T SOCFaultDetection_MODE;    /* '<S1>/SOC Fault Detection' */
  MdlrefDW_NBMS_DischargeOCV_T InitialDichargeOCV_InstanceData;/* '<S91>/InitialDichargeOCV' */
  MdlrefDW_NBMS_ChargeOCV_T InitialChargeOCV_InstanceData;/* '<S91>/InitialChargeOCV' */
  MdlrefDW_NBMS_ChargeOCV_T ChargeOCV_InstanceData;/* '<S91>/ChargeOCV' */
  MdlrefDW_NBMS_DischargeOCV_T DischargeOCV_InstanceData;/* '<S91>/DischargeOCV' */
  MdlrefDW_NBMS_DischargeOCV_T DischgOCV_InstanceData;/* '<S6>/DischgOCV' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage9;/* '<S93>/Moving Average9' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage8;/* '<S93>/Moving Average8' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage7;/* '<S93>/Moving Average7' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage6;/* '<S93>/Moving Average6' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage5;/* '<S93>/Moving Average5' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage4;/* '<S93>/Moving Average4' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage3;/* '<S93>/Moving Average3' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage2;/* '<S93>/Moving Average2' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage19;/* '<S93>/Moving Average19' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage18;/* '<S93>/Moving Average18' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage17;/* '<S93>/Moving Average17' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage16;/* '<S93>/Moving Average16' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage15;/* '<S93>/Moving Average15' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage14;/* '<S93>/Moving Average14' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage13;/* '<S93>/Moving Average13' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage12;/* '<S93>/Moving Average12' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage11;/* '<S93>/Moving Average11' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage10;/* '<S93>/Moving Average10' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage1;/* '<S93>/Moving Average1' */
  DW_MovingAverage_NBMS_SoC_T MovingAverage;/* '<S93>/Moving Average' */
} DW_NBMS_SoC_f_T;

/* Zero-crossing (trigger) state for model 'NBMS_SoC' */
typedef struct {
  ZCSigState InitPackTemperature_Trig_ZCE;/* '<S91>/InitPackTemperature' */
  ZCSigState LatchSoC_Trig_ZCE;        /* '<S45>/LatchSoC' */
  ZCSigState LatchTempinit_Trig_ZCE;   /* '<S6>/LatchTempinit' */
  ZCSigState LatchFullSoc_Trig_ZCE;    /* '<S60>/LatchFullSoc' */
  ZCSigState LatchInitCapacity_Trig_ZCE;/* '<S41>/LatchInitCapacity' */
  ZCSigState Initial_SoC_Storage_Trig_ZCE;/* '<S18>/Initial_SoC_Storage' */
  ZCSigState CalcOCV_Trig_ZCE;         /* '<S1>/CalcOCV' */
} ZCE_NBMS_SoC_T;

/* Invariant block signals for model 'NBMS_SoC' */
typedef struct {
  const real_T SoH;                    /* '<S18>/Constant' */
} ConstB_NBMS_SoC_h_T;

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
                     rtu_AppIn_BattVoltages[20], const boolean_T
                     *rtu_Ignition_Sts, const Charger_Mode_Req_E
                     *rtu_Charger_Mode_Req, const BMS_MODE_E *rtu_sm_BMSMODE_en,
                     const real_T *rtu_AppIn_LastStoredSOC, const real_T
                     *rtu_AppIn_LastStoredCycle, const boolean_T
                     *rtu_AppIn_I2Cerror, const OBC_E *rtu_OBCWakeup, const
                     real_T *rtu_mi_Pack_Volt, const VDU_MACHINE_STS_E
                     *rtu_AppIn_MachineStatus, const real_T
                     *rtu_DischrgCurrLimit, const boolean_T *rtu_RTC_Wakeup,
                     const boolean_T *rtu_AppIn_SoCLEDSW, const boolean_T
                     *rtu_EEPROM_SOC_WARN15, uint8_T *rty_Display_SOC, real_T
                     *rty_Battery_Capacity, boolean_T *rty_LOW_SOC_WARN_15,
                     boolean_T *rty_LOW_SOC, boolean_T *rty_LOW_SOC_WARN, real_T
                     *rty_Batt_Pack_SOC, real_T *rty_LifeCycle, int16_T
                     *rty_VtAvgMax, real_T *rty_CurrentCapacity, uint16_T
                     *rty_SOCcc, uint16_T *rty_SOCAvg, int16_T *rty_Vmin, real_T
                     *rty_SOC_OCVInit, real_T *rty_SOCAvgInitial, real_T
                     *rty_AvailableEnergy, int16_T *rty_VtAvgMin, real_T
                     *rty_FailSensorVolt, int16_T *rty_FailSensorVoltAvg,
                     int16_T *rty_BatteryCurrentAvg5sec, real_T
                     *rty_ChargeCapacity, BMS_BattTempDerate_E
                     *rty_Batt_Temp_Derating, BMS_BattSoCDerate_E
                     *rty_Batt_SoC_Derating, B_NBMS_SoC_c_T *localB,
                     DW_NBMS_SoC_f_T *localDW, ZCE_NBMS_SoC_T *localZCE);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S24>/CalcDOD' : Unused code path elimination
 * Block '<S24>/CalcDischgCapacity' : Unused code path elimination
 * Block '<S24>/CalcMinSoH' : Unused code path elimination
 * Block '<S24>/CalcSoH' : Unused code path elimination
 * Block '<S24>/MaxSoC' : Unused code path elimination
 * Block '<S24>/MaxSoH' : Unused code path elimination
 * Block '<S24>/scaleMeasuredCharge' : Unused code path elimination
 * Block '<S18>/Charg_Capacity1' : Unused code path elimination
 * Block '<S25>/Logic' : Unused code path elimination
 * Block '<S25>/Memory' : Unused code path elimination
 * Block '<S27>/Compare' : Unused code path elimination
 * Block '<S27>/Constant' : Unused code path elimination
 * Block '<S32>/Compare' : Unused code path elimination
 * Block '<S32>/Constant' : Unused code path elimination
 * Block '<S33>/Delay Input1' : Unused code path elimination
 * Block '<S33>/FixPt Relational Operator' : Unused code path elimination
 * Block '<S34>/Compare' : Unused code path elimination
 * Block '<S34>/Constant' : Unused code path elimination
 * Block '<S18>/MaxSoH' : Unused code path elimination
 * Block '<S18>/SoHBoundaries' : Unused code path elimination
 * Block '<S18>/UpdateSoHTrigger' : Unused code path elimination
 * Block '<S18>/cnvToDouble' : Unused code path elimination
 * Block '<S18>/selIgnFallbackSoH' : Unused code path elimination
 * Block '<S18>/selLifecycleClamp' : Unused code path elimination
 * Block '<S18>/selUpdatedSoH' : Unused code path elimination
 * Block '<S18>/udlySoH' : Unused code path elimination
 * Block '<S18>/udlySoHtrigger' : Unused code path elimination
 * Block '<S5>/udlyLifeCycle' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Data Type Propagation' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Propagation' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Propagation' : Unused code path elimination
 * Block '<S42>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
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
 * Block '<S145>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S146>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S147>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S148>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S149>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S150>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S151>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S152>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S153>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
 * Block '<S154>/FixdtDataTypeConversion' : Eliminate redundant data type conversion
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
 * '<S4>'   : 'NBMS_SoC/SOC/FindDerating'
 * '<S5>'   : 'NBMS_SoC/SOC/LifeCycle SOH Energy'
 * '<S6>'   : 'NBMS_SoC/SOC/SOC Estimation'
 * '<S7>'   : 'NBMS_SoC/SOC/SOC Fault Detection'
 * '<S8>'   : 'NBMS_SoC/SOC/VtAvg'
 * '<S9>'   : 'NBMS_SoC/SOC/FindDerating/ChkSoCbelow20'
 * '<S10>'  : 'NBMS_SoC/SOC/FindDerating/ChkTempabove56'
 * '<S11>'  : 'NBMS_SoC/SOC/FindDerating/ChkTempbelow10'
 * '<S12>'  : 'NBMS_SoC/SOC/FindDerating/Derate'
 * '<S13>'  : 'NBMS_SoC/SOC/FindDerating/Derate1'
 * '<S14>'  : 'NBMS_SoC/SOC/FindDerating/Derate2'
 * '<S15>'  : 'NBMS_SoC/SOC/FindDerating/Derate3'
 * '<S16>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/CalcAvailableEnergy '
 * '<S17>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/Life Cycle'
 * '<S18>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health'
 * '<S19>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/Life Cycle/CheckBMSModeIsNotSleep'
 * '<S20>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/Life Cycle/ChkBMSModeIsSleep'
 * '<S21>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/Life Cycle/ChkBMSModeIsStandby'
 * '<S22>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/Life Cycle/ChkBmsModeIsSleep'
 * '<S23>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/CalcChgMeasured'
 * '<S24>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/CalculateSoH'
 * '<S25>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChgStartLatch'
 * '<S26>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkBmsModeIsCharge'
 * '<S27>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkChgCompleted'
 * '<S28>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkChgHasStartedBelow10'
 * '<S29>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkChgModeReqCCStart'
 * '<S30>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkChgModeReqCV'
 * '<S31>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkChgModeReqStandby'
 * '<S32>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkChgPerIs100'
 * '<S33>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkIgnHasTurnedOn'
 * '<S34>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/ChkLifeCycleActive'
 * '<S35>'  : 'NBMS_SoC/SOC/LifeCycle SOH Energy/State of Health/Initial_SoC_Storage'
 * '<S36>'  : 'NBMS_SoC/SOC/SOC Estimation/Cell Chemestry Selection'
 * '<S37>'  : 'NBMS_SoC/SOC/SOC Estimation/ChkBmsModeSleep'
 * '<S38>'  : 'NBMS_SoC/SOC/SOC Estimation/ChkBmsModeStandby'
 * '<S39>'  : 'NBMS_SoC/SOC/SOC Estimation/ChkChgModeReqChgComplete'
 * '<S40>'  : 'NBMS_SoC/SOC/SOC Estimation/ChkcycleLessThanZero'
 * '<S41>'  : 'NBMS_SoC/SOC/SOC Estimation/CurrentCapacityCalculation'
 * '<S42>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC'
 * '<S43>'  : 'NBMS_SoC/SOC/SOC Estimation/InitialSocManager'
 * '<S44>'  : 'NBMS_SoC/SOC/SOC Estimation/LatchTempinit'
 * '<S45>'  : 'NBMS_SoC/SOC/SOC Estimation/SOC Overriding Handling'
 * '<S46>'  : 'NBMS_SoC/SOC/SOC Estimation/chkSocDeviation'
 * '<S47>'  : 'NBMS_SoC/SOC/SOC Estimation/Cell Chemestry Selection/ChkBMSModeNotSleep'
 * '<S48>'  : 'NBMS_SoC/SOC/SOC Estimation/CurrentCapacityCalculation/ChkIsBMSModeCharge'
 * '<S49>'  : 'NBMS_SoC/SOC/SOC Estimation/CurrentCapacityCalculation/ChkIsChargeModeTriggered'
 * '<S50>'  : 'NBMS_SoC/SOC/SOC Estimation/CurrentCapacityCalculation/LatchInitCapacity'
 * '<S51>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/CalcSoCCorrection'
 * '<S52>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkBMSMODEIsSleep'
 * '<S53>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkBMSModeIsCharge'
 * '<S54>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkBMSModeSleep'
 * '<S55>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkBMSModeisCharge'
 * '<S56>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkBmsModeCharge'
 * '<S57>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkHasAvgSoCChanged'
 * '<S58>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/ChkSoCabove0'
 * '<S59>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/DisplaySocLockLatch'
 * '<S60>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge'
 * '<S61>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/LatchBattSoc'
 * '<S62>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/SOC_Offset'
 * '<S63>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/SOC_factor'
 * '<S64>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/chkIgnitionOff'
 * '<S65>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/satDynamicLowerBound'
 * '<S66>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/satDynamicUpperBound'
 * '<S67>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/CalcSoCCorrection/ChkBMSModeIsSleep'
 * '<S68>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/CalcSoCCorrection/SocCorrectionLimits'
 * '<S69>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge/ChkChgModeReqChgComplete'
 * '<S70>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge/Detect Increase'
 * '<S71>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge/LatchFullSoc'
 * '<S72>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge/StateWaitCondition'
 * '<S73>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge/chkIsModeCharge'
 * '<S74>'  : 'NBMS_SoC/SOC/SOC Estimation/DisplaySOC/FullCharge/chkPackSocBelowFull'
 * '<S75>'  : 'NBMS_SoC/SOC/SOC Estimation/SOC Overriding Handling/ChkBMSModeSleep'
 * '<S76>'  : 'NBMS_SoC/SOC/SOC Estimation/SOC Overriding Handling/ChkChgModeReqChgComplete'
 * '<S77>'  : 'NBMS_SoC/SOC/SOC Estimation/SOC Overriding Handling/ChkChgModeReqDisabled'
 * '<S78>'  : 'NBMS_SoC/SOC/SOC Estimation/SOC Overriding Handling/LatchSoC'
 * '<S79>'  : 'NBMS_SoC/SOC/SOC Estimation/SOC Overriding Handling/SocStateController'
 * '<S80>'  : 'NBMS_SoC/SOC/SOC Fault Detection/ChkBMSModeDischarge'
 * '<S81>'  : 'NBMS_SoC/SOC/SOC Fault Detection/ChkBMSModeFault'
 * '<S82>'  : 'NBMS_SoC/SOC/SOC Fault Detection/LowSocAlertLatch'
 * '<S83>'  : 'NBMS_SoC/SOC/SOC Fault Detection/Soc15WarningLatch'
 * '<S84>'  : 'NBMS_SoC/SOC/SOC Fault Detection/Soc20WarningLatch'
 * '<S85>'  : 'NBMS_SoC/SOC/SOC Fault Detection/chkDisplaySocAbove15Recovery'
 * '<S86>'  : 'NBMS_SoC/SOC/SOC Fault Detection/chkDisplaySocAbove20Recovery'
 * '<S87>'  : 'NBMS_SoC/SOC/SOC Fault Detection/chkDisplaySocAboveLowRecovery'
 * '<S88>'  : 'NBMS_SoC/SOC/SOC Fault Detection/chkDisplaySocBelow15Thresh'
 * '<S89>'  : 'NBMS_SoC/SOC/SOC Fault Detection/chkDisplaySocBelow20Thresh'
 * '<S90>'  : 'NBMS_SoC/SOC/SOC Fault Detection/chkDisplaySocBelowLowThresh'
 * '<S91>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC'
 * '<S92>'  : 'NBMS_SoC/SOC/VtAvg/IR Calculation'
 * '<S93>'  : 'NBMS_SoC/SOC/VtAvg/Voltage Average'
 * '<S94>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/CheckBMSModeCharge'
 * '<S95>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/ChkBMSModeCharge'
 * '<S96>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/ChkBMSModeDischg'
 * '<S97>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/ChkIgnOff'
 * '<S98>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/ChkOBCWakeupIncrease'
 * '<S99>'  : 'NBMS_SoC/SOC/VtAvg/AverageSoC/ChkSoCHysteresisChange'
 * '<S100>' : 'NBMS_SoC/SOC/VtAvg/AverageSoC/InitPackTemperature'
 * '<S101>' : 'NBMS_SoC/SOC/VtAvg/AverageSoC/IsBMSModeCharge'
 * '<S102>' : 'NBMS_SoC/SOC/VtAvg/AverageSoC/SOC_Init_Decision'
 * '<S103>' : 'NBMS_SoC/SOC/VtAvg/AverageSoC/SoCStateLatch'
 * '<S104>' : 'NBMS_SoC/SOC/VtAvg/IR Calculation/Check If the VehicleState is DRIVE'
 * '<S105>' : 'NBMS_SoC/SOC/VtAvg/IR Calculation/Check if  BMS Mode &#x2260; SLEEP     '
 * '<S106>' : 'NBMS_SoC/SOC/VtAvg/IR Calculation/Check if BMS Mode is CHARGE'
 * '<S107>' : 'NBMS_SoC/SOC/VtAvg/IR Calculation/MovingAverageCurrent2sec'
 * '<S108>' : 'NBMS_SoC/SOC/VtAvg/IR Calculation/MovingAverageCurrent5sec'
 * '<S109>' : 'NBMS_SoC/SOC/VtAvg/IR Calculation/MovingAverageCurrent2sec/CheckBufferComplete  '
 * '<S110>' : 'NBMS_SoC/SOC/VtAvg/IR Calculation/MovingAverageCurrent5sec/CheckBufferComplete'
 * '<S111>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell0'
 * '<S112>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell1'
 * '<S113>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell10'
 * '<S114>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell11'
 * '<S115>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell12'
 * '<S116>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell13'
 * '<S117>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell14'
 * '<S118>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell15'
 * '<S119>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell16'
 * '<S120>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell17'
 * '<S121>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell18'
 * '<S122>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell19'
 * '<S123>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell2'
 * '<S124>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell3'
 * '<S125>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell4'
 * '<S126>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell5'
 * '<S127>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell6'
 * '<S128>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell7'
 * '<S129>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell8'
 * '<S130>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Cell9'
 * '<S131>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/CountforOneCellFail'
 * '<S132>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/FindMinAvgVolt'
 * '<S133>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/FindMinVolt'
 * '<S134>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/FindNonZeroCellVolt'
 * '<S135>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average'
 * '<S136>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average1'
 * '<S137>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average10'
 * '<S138>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average11'
 * '<S139>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average12'
 * '<S140>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average13'
 * '<S141>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average14'
 * '<S142>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average15'
 * '<S143>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average16'
 * '<S144>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average17'
 * '<S145>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average18'
 * '<S146>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average19'
 * '<S147>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average2'
 * '<S148>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average3'
 * '<S149>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average4'
 * '<S150>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average5'
 * '<S151>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average6'
 * '<S152>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average7'
 * '<S153>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average8'
 * '<S154>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/Moving Average9'
 * '<S155>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/OneSensorVoltFailure'
 * '<S156>' : 'NBMS_SoC/SOC/VtAvg/Voltage Average/OneSensorVoltFailure/AverageofSensorVoltFail'
 */
#endif                                 /* NBMS_SoC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
