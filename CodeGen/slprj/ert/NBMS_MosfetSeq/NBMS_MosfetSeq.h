/*
 * File: NBMS_MosfetSeq.h
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

#ifndef NBMS_MosfetSeq_h_
#define NBMS_MosfetSeq_h_
#ifndef NBMS_MosfetSeq_COMMON_INCLUDES_
#define NBMS_MosfetSeq_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* NBMS_MosfetSeq_COMMON_INCLUDES_ */

#include "NBMS_MosfetSeq_types.h"

/* Includes for objects with custom storage classes */
#include "DID.h"

/* Block states (default storage) for model 'NBMS_MosfetSeq' */
typedef struct {
  real_T count1;                       /* '<Root>/Mosfet Control SM' */
  real_T count;                        /* '<Root>/Mosfet Control SM' */
  real_T count3;                       /* '<Root>/Mosfet Control SM' */
  real_T count2;                       /* '<Root>/Mosfet Control SM' */
  uint32_T temporalCounter_i1;         /* '<Root>/Mosfet Control SM' */
  uint32_T durationCounter_1;          /* '<Root>/Mosfet Control SM' */
  uint32_T durationCounter_1_i;        /* '<Root>/Mosfet Control SM' */
  uint32_T durationCounter_1_h;        /* '<Root>/Mosfet Control SM' */
  uint32_T durationCounter_1_l;        /* '<Root>/Mosfet Control SM' */
  uint32_T durationCounter_1_lu;       /* '<Root>/Mosfet Control SM' */
  uint32_T durationCounter_1_d;        /* '<Root>/Mosfet Control SM' */
  uint32_T durationCounter_1_n;        /* '<Root>/Mosfet Control SM' */
  uint32_T durationCounter_1_k;        /* '<Root>/Mosfet Control SM' */
  uint32_T durationCounter_1_k4;       /* '<Root>/Mosfet Control SM' */
  uint32_T durationCounter_1_b;        /* '<Root>/Mosfet Control SM' */
  BMS_MODE_E sm_BMSMODE_prev;          /* '<Root>/Mosfet Control SM' */
  BMS_MODE_E sm_BMSMODE_start;         /* '<Root>/Mosfet Control SM' */
  uint8_T is_active_c3_NBMS_MosfetSeq; /* '<Root>/Mosfet Control SM' */
  uint8_T is_c3_NBMS_MosfetSeq;        /* '<Root>/Mosfet Control SM' */
  uint8_T is_DEFAULT;                  /* '<Root>/Mosfet Control SM' */
  uint8_T is_G4ChargeFault;            /* '<Root>/Mosfet Control SM' */
  uint8_T is_OnFaultDetection;         /* '<Root>/Mosfet Control SM' */
  uint8_T is_G4CommonFault;            /* '<Root>/Mosfet Control SM' */
  uint8_T is_OnFaultDetection_g;       /* '<Root>/Mosfet Control SM' */
  uint8_T is_G4Typ1DischgFault;        /* '<Root>/Mosfet Control SM' */
  uint8_T is_OnFaultDetection_i;       /* '<Root>/Mosfet Control SM' */
  uint8_T is_G4Typ2DischgFault;        /* '<Root>/Mosfet Control SM' */
  uint8_T is_OnFaultDetection_j;       /* '<Root>/Mosfet Control SM' */
  uint8_T is_No_Action;                /* '<Root>/Mosfet Control SM' */
  uint8_T is_STANDBY;                  /* '<Root>/Mosfet Control SM' */
  uint8_T is_Mosfet_Sequence;          /* '<Root>/Mosfet Control SM' */
  uint8_T is_CLOSING_SEQ;              /* '<Root>/Mosfet Control SM' */
  uint8_T is_OpenDCDCMosfetIgOff;      /* '<Root>/Mosfet Control SM' */
  uint8_T is_CLOSING_SEQ_CHRG;         /* '<Root>/Mosfet Control SM' */
  uint8_T is_CloseDCDCMosfetIgOn;      /* '<Root>/Mosfet Control SM' */
  boolean_T NA;                        /* '<Root>/Mosfet Control SM' */
} DW_NBMS_MosfetSeq_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_NBMS_MosfetSeq_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_NBMS_MosfetSeq_f_T rtdw;
  RT_MODEL_NBMS_MosfetSeq_T rtm;
} MdlrefDW_NBMS_MosfetSeq_T;

/* Model reference registration function */
extern void NBMS_MosfetSeq_initialize(const char_T **rt_errorStatus,
  RT_MODEL_NBMS_MosfetSeq_T *const NBMS_MosfetSeq_M);
extern void NBMS_MosfetSeq(const boolean_T *rtu_mi_Hardwired_Ign, const
  BMS_MODE_E *rtu_sm_bmsmode, const real_T *rtu_AppIn_LoadVolt, const real_T
  *rtu_AppIn_PackVolt, const boolean_T *rtu_mi_OBC_HVIL, const OBC_E
  *rtu_mi_OBC_wakeup, const Active_DisChrg_E *rtu_AppIn_ActiveDischg, const
  boolean_T *rtu_AppIn_PMosfetfb, const boolean_T *rtu_AppIn_HVMosfetfb, const
  boolean_T *rtu_AppIn_DCDCMosfetfb, const boolean_T *rtu_G4_Common_Fault, const
  boolean_T *rtu_G4_Charge_Fault, const boolean_T *rtu_G4T2_Discharge_Fault,
  const boolean_T *rtu_G4T1_Discharge_Fault, boolean_T *rty_Prechg_Mosfet_cmd,
  boolean_T *rty_HV_Mosfet_cmd, boolean_T *rty_DCDC_Mosfet_cmd,
  BMS_PMosfet_STS_E *rty_Prechg_Mosfet, BMS_HVMosfet_STS_E *rty_HV_Mosfet,
  BMS_DCDCMosfet_STS_E *rty_DCDC_Mosfet, boolean_T *rty_ASC_Prep_flg, boolean_T *
  rty_Chrgr_Prep_Flag, boolean_T *rty_Prechg_Volt_Flt, DW_NBMS_MosfetSeq_f_T
  *localDW);

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
 * '<Root>' : 'NBMS_MosfetSeq'
 * '<S1>'   : 'NBMS_MosfetSeq/Mosfet Control SM'
 */
#endif                                 /* NBMS_MosfetSeq_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
