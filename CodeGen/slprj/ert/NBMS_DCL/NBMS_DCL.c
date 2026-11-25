/*
 * File: NBMS_DCL.c
 *
 * Code generated for Simulink model 'NBMS_DCL'.
 *
 * Model version                  : 7.26
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 25 15:34:59 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "NBMS_DCL.h"
#include "rtwtypes.h"
#include "NBMS_DCL_types.h"
#include <math.h>
#include "look2_binlxpw.h"
#include "DID.h"
#include "NBMS_DCL_private.h"

/* Named constants for Chart: '<S5>/CalcDCL' */
#define NBMS_DCL_IN_C1_Advantage       ((uint8_T)1U)
#define NBMS_DCL_IN_C1_Condition       ((uint8_T)1U)
#define NBMS_DCL_IN_Continuous         ((uint8_T)2U)
#define NBMS_DCL_IN_NO_ACTIVE_CHILD    ((uint8_T)0U)
#define NBMS_DCL_IN_Peak               ((uint8_T)2U)

/* Named constants for Chart: '<S1>/Derate' */
#define NBMS_DCL_IN_DRIVE              ((uint8_T)1U)
#define NBMS_DCL_IN_G2_Derating        ((uint8_T)1U)
#define NBMS_DCL_IN_G2_Eco             ((uint8_T)1U)
#define NBMS_DCL_IN_G2_min             ((uint8_T)2U)
#define NBMS_DCL_IN_IDLE               ((uint8_T)2U)
#define NBMS_DCL_IN_PeakMode           ((uint8_T)2U)

/* Forward declaration for local functions */
static void NBM_enter_internal_C1_Condition(const boolean_T
  *IsBattCurrAboveSafetyLt, real_T *rty_Timer30, B_NBMS_DCL_c_T *localB,
  DW_NBMS_DCL_f_T *localDW);

/* Function for Chart: '<S5>/CalcDCL' */
static void NBM_enter_internal_C1_Condition(const boolean_T
  *IsBattCurrAboveSafetyLt, real_T *rty_Timer30, B_NBMS_DCL_c_T *localB,
  DW_NBMS_DCL_f_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S1>/DCL' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  /* Chart: '<S5>/CalcDCL' */
  *rty_Timer30 = 30.0;

  /* End of Outputs for SubSystem: '<S1>/DCL' */
  localB->DCL = 0.0;
  if (!*IsBattCurrAboveSafetyLt) {
    localDW->is_C1_Condition = NBMS_DCL_IN_C1_Advantage;
  } else {
    localDW->is_C1_Condition = NBMS_DCL_IN_Peak;

    /* Outputs for Enabled SubSystem: '<S1>/DCL' incorporates:
     *  EnablePort: '<S3>/Enable'
     */
    /* Chart: '<S5>/CalcDCL' */
    *rty_Timer30 = 29.9;

    /* End of Outputs for SubSystem: '<S1>/DCL' */
  }
}

/* Disable for referenced model: 'NBMS_DCL' */
void NBMS_DCL_Disable(B_NBMS_DCL_c_T *localB, DW_NBMS_DCL_f_T *localDW)
{
  /* Disable for Enabled SubSystem: '<S1>/DCL' */
  if (localDW->DCL_MODE) {
    /* Disable for Lookup_n-D: '<S3>/Continuous_Safety_Pack' incorporates:
     *  Outport: '<S3>/Currentlimit'
     *  Switch: '<S3>/SelCurrentLimit'
     */
    localB->CurrentLimit = 0.0;
    localDW->DCL_MODE = false;
  }

  /* End of Disable for SubSystem: '<S1>/DCL' */
}

/* Output and update for referenced model: 'NBMS_DCL' */
void NBMS_DCL(const VDU_MACHINE_STS_E *rtu_MachineStatus, const uint8_T *rtu_SOC,
              const real_T rtu_Temperature[6], const real_T *rtu_Current, const
              boolean_T *rtu_G3_Common_Flt, const boolean_T *rtu_G4_Common_Flt,
              const boolean_T *rtu_G3_Dischg_Flt, const boolean_T
              *rtu_G4T1_Dischg_Flt, const boolean_T *rtu_G4T2_Dischg_Flt, const
              boolean_T *rtu_derate_flg, const real_T *rtu_SoH, const boolean_T *
              rtu_derateImmediate, const boolean_T *rtu_derateafterX1, real_T
              *rty_Dischg_CurrentLimit, real_T *rty_Timer30, B_NBMS_DCL_c_T
              *localB, DW_NBMS_DCL_f_T *localDW)
{
  real_T rtb_DcurrLt;
  int32_T k;
  boolean_T IsBattCurrAboveSafetyLt;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T rtb_Fault;

  /* Logic: '<S1>/ChkForFault' incorporates:
   *  Logic: '<Root>/ChkG4DischgFlt'
   */
  rtb_Fault = (*rtu_G3_Common_Flt || *rtu_G4_Common_Flt || *rtu_G3_Dischg_Flt ||
               (*rtu_G4T1_Dischg_Flt || *rtu_G4T2_Dischg_Flt));

  /* Outputs for Enabled SubSystem: '<S1>/DCL' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  if (*rtu_MachineStatus == DRIVE) {
    if (!localDW->DCL_MODE) {
      /* SystemReset for Chart: '<S5>/CalcDCL' */
      localDW->durationCounter_1 = 0U;
      localB->DCL = 0.0;
      *rty_Timer30 = 0.0;
      localDW->is_active_c1_NBMS_DCL = 0U;
      localDW->is_c1_NBMS_DCL = NBMS_DCL_IN_NO_ACTIVE_CHILD;
      localDW->is_C1_Condition = NBMS_DCL_IN_NO_ACTIVE_CHILD;
      localDW->DCL_MODE = true;
    }

    /* MinMax: '<S3>/FindMaxTemp' */
    rtb_DcurrLt = rtu_Temperature[0];
    for (k = 0; k < 5; k++) {
      rtb_DcurrLt = fmax(rtb_DcurrLt, rtu_Temperature[k + 1]);
    }

    /* Lookup_n-D: '<S3>/Continuous_Safety_Pack' incorporates:
     *  DataTypeConversion: '<S3>/COnvToDouble'
     *  MinMax: '<S3>/FindMaxTemp'
     */
    localB->CurrentLimit = look2_binlxpw(rtb_DcurrLt, *rtu_SOC,
      &X_DCL_CONT_SAFETY_PACK[0], &Y_DCL_CONT_SAFETY_PACK[0],
      rtCP_Continuous_Safety_Pack_tab, rtCP_Continuous_Safety_Pack_max, 10U);

    /* RelationalOperator: '<S3>/ChkBattCurrAboveSafetyLt' incorporates:
     *  Abs: '<S3>/Absolute'
     */
    IsBattCurrAboveSafetyLt = (fabs(*rtu_Current) > localB->CurrentLimit);

    /* Chart: '<S5>/CalcDCL' incorporates:
     *  MinMax: '<S3>/FindMaxTemp'
     */
    if (localDW->is_active_c1_NBMS_DCL == 0) {
      localDW->is_active_c1_NBMS_DCL = 1U;
      if ((*rtu_SOC > 20) && (rtb_DcurrLt <= 47.0) && (rtb_DcurrLt >= 10.0)) {
        localDW->durationCounter_1 = 0U;
        localDW->is_c1_NBMS_DCL = NBMS_DCL_IN_C1_Condition;
        NBM_enter_internal_C1_Condition(&IsBattCurrAboveSafetyLt, rty_Timer30,
          localB, localDW);
      } else {
        localDW->is_c1_NBMS_DCL = NBMS_DCL_IN_Continuous;
        localB->DCL = 1.0;
      }
    } else {
      guard1 = false;
      guard2 = false;
      if (localDW->is_c1_NBMS_DCL == NBMS_DCL_IN_C1_Condition) {
        if (*rty_Timer30 <= 0.0) {
          guard2 = true;
        } else {
          if (!*rtu_derateafterX1) {
            localDW->durationCounter_1 = 0U;
          }

          if ((localDW->durationCounter_1 >= 20U) || *rtu_derateImmediate ||
              (rtb_DcurrLt >= 47.0) || (rtb_DcurrLt < 10.0)) {
            guard2 = true;
          } else if (localDW->is_C1_Condition == NBMS_DCL_IN_C1_Advantage) {
            if (IsBattCurrAboveSafetyLt) {
              localDW->is_C1_Condition = NBMS_DCL_IN_Peak;
              if (*rty_Timer30 > 0.0) {
                *rty_Timer30 -= 0.1;
              }
            } else if (*rty_Timer30 < 30.0) {
              *rty_Timer30 += 0.1;
            }

            /* case IN_Peak: */
          } else if (!IsBattCurrAboveSafetyLt) {
            localDW->is_C1_Condition = NBMS_DCL_IN_C1_Advantage;
            if (*rty_Timer30 < 30.0) {
              *rty_Timer30 += 0.1;
            }
          } else if (*rty_Timer30 > 0.0) {
            *rty_Timer30 -= 0.1;
          }
        }

        /* case IN_Continuous: */
      } else if (*rtu_MachineStatus != DRIVE) {
        if ((*rtu_SOC > 20) && (rtb_DcurrLt <= 47.0) && (rtb_DcurrLt >= 10.0)) {
          guard1 = true;
        } else {
          localDW->is_c1_NBMS_DCL = NBMS_DCL_IN_Continuous;
          localB->DCL = 1.0;
        }
      } else if (!*rtu_derateafterX1 && !*rtu_derateImmediate && (rtb_DcurrLt <=
                  47.0) && (rtb_DcurrLt >= 10.0)) {
        guard1 = true;
      } else {
        localB->DCL = 1.0;
      }

      if (guard2) {
        localDW->is_C1_Condition = NBMS_DCL_IN_NO_ACTIVE_CHILD;
        localDW->is_c1_NBMS_DCL = NBMS_DCL_IN_Continuous;
        localB->DCL = 1.0;
      }

      if (guard1) {
        localDW->durationCounter_1 = 0U;
        localDW->is_c1_NBMS_DCL = NBMS_DCL_IN_C1_Condition;
        NBM_enter_internal_C1_Condition(&IsBattCurrAboveSafetyLt, rty_Timer30,
          localB, localDW);
      }
    }

    if (*rtu_derateafterX1) {
      localDW->durationCounter_1++;
    } else {
      localDW->durationCounter_1 = 0U;
    }

    /* End of Chart: '<S5>/CalcDCL' */

    /* Switch: '<S3>/SelCurrentLimit' */
    if (!(localB->DCL != 0.0)) {
      /* Lookup_n-D: '<S3>/Continuous_Safety_Pack' incorporates:
       *  DataTypeConversion: '<S3>/COnvToDouble'
       *  Lookup_n-D: '<S3>/30s_Safety_Pack'
       *  MinMax: '<S3>/FindMaxTemp'
       *  Switch: '<S3>/SelCurrentLimit'
       */
      localB->CurrentLimit = look2_binlxpw(rtb_DcurrLt, *rtu_SOC,
        &X_DCL_30sSAFETY_PACK[0], &Y_DCL_30sSAFETY_PACK[0],
        rtCP_u0s_Safety_Pack_tableData, rtCP_u0s_Safety_Pack_maxIndex, 10U);
    }

    /* End of Switch: '<S3>/SelCurrentLimit' */
  } else if (localDW->DCL_MODE) {
    /* Disable for Lookup_n-D: '<S3>/Continuous_Safety_Pack' incorporates:
     *  Outport: '<S3>/Currentlimit'
     *  Switch: '<S3>/SelCurrentLimit'
     */
    localB->CurrentLimit = 0.0;
    localDW->DCL_MODE = false;
  }

  /* End of RelationalOperator: '<S2>/Compare' */
  /* End of Outputs for SubSystem: '<S1>/DCL' */

  /* Chart: '<S1>/Derate' */
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  if (localDW->is_active_c3_NBMS_DCL == 0) {
    localDW->is_active_c3_NBMS_DCL = 1U;
    localDW->is_c3_NBMS_DCL = NBMS_DCL_IN_IDLE;
    rtb_DcurrLt = 0.0;
  } else if (localDW->is_c3_NBMS_DCL == NBMS_DCL_IN_DRIVE) {
    if ((*rtu_MachineStatus != DRIVE) || rtb_Fault) {
      localDW->is_G2_Derating = NBMS_DCL_IN_NO_ACTIVE_CHILD;
      localDW->is_DRIVE = NBMS_DCL_IN_NO_ACTIVE_CHILD;
      localDW->is_c3_NBMS_DCL = NBMS_DCL_IN_IDLE;
      rtb_DcurrLt = 0.0;
    } else if (localDW->is_DRIVE == NBMS_DCL_IN_G2_Derating) {
      if (!*rtu_derate_flg) {
        localDW->is_G2_Derating = NBMS_DCL_IN_NO_ACTIVE_CHILD;
        localDW->is_DRIVE = NBMS_DCL_IN_PeakMode;
        rtb_DcurrLt = localB->CurrentLimit;
      } else if (localDW->is_G2_Derating == NBMS_DCL_IN_G2_Eco) {
        rtb_DcurrLt = fmin(60.0, localB->CurrentLimit);

        /* case IN_G2_min: */
      } else if (localDW->time >= 10.0) {
        localDW->is_G2_Derating = NBMS_DCL_IN_G2_Eco;
        rtb_DcurrLt = fmin(60.0, localB->CurrentLimit);
      } else {
        rtb_DcurrLt = localB->CurrentLimit;
        localDW->time = (real_T)localDW->temporalCounter_i1 * 0.5;
      }

      /* case IN_PeakMode: */
    } else if (*rtu_derate_flg) {
      localDW->is_DRIVE = NBMS_DCL_IN_G2_Derating;
      localDW->temporalCounter_i1 = 0U;
      localDW->is_G2_Derating = NBMS_DCL_IN_G2_min;
      rtb_DcurrLt = localB->CurrentLimit;
      localDW->time = 0.0;
    } else {
      rtb_DcurrLt = localB->CurrentLimit;
    }

    /* case IN_IDLE: */
  } else if ((*rtu_MachineStatus == DRIVE) && !rtb_Fault) {
    localDW->is_c3_NBMS_DCL = NBMS_DCL_IN_DRIVE;
    localDW->is_DRIVE = NBMS_DCL_IN_PeakMode;
    rtb_DcurrLt = localB->CurrentLimit;
  } else {
    rtb_DcurrLt = 0.0;
  }

  /* End of Chart: '<S1>/Derate' */

  /* Gain: '<S1>/gainDCL' incorporates:
   *  Gain: '<S1>/gainSoH'
   *  Product: '<S1>/ProdDCL'
   */
  *rty_Dischg_CurrentLimit = -(0.01 * *rtu_SoH * rtb_DcurrLt);
}

/* Model initialize function */
void NBMS_DCL_initialize(const char_T **rt_errorStatus, RT_MODEL_NBMS_DCL_T *
  const NBMS_DCL_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(NBMS_DCL_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
