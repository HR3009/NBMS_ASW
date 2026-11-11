/*
 * File: NBMS_DCL.c
 *
 * Code generated for Simulink model 'NBMS_DCL'.
 *
 * Model version                  : 7.9
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 11 09:32:04 2026
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

/* Named constants for Chart: '<S4>/CalcDCL' */
#define NBMS_DCL_IN_C1_Advantage       ((uint8_T)1U)
#define NBMS_DCL_IN_C1_Condition       ((uint8_T)1U)
#define NBMS_DCL_IN_Continuous         ((uint8_T)2U)
#define NBMS_DCL_IN_NO_ACTIVE_CHILD    ((uint8_T)0U)
#define NBMS_DCL_IN_Peak               ((uint8_T)2U)

/* Output and update for referenced model: 'NBMS_DCL' */
void NBMS_DCL(const VEH_STT_LVL1_E *rtu_Veh_Lvl1, const uint8_T *rtu_SOC, const
              real_T rtu_Temperature[6], const real_T *rtu_Current, const
              boolean_T *rtu_G3_Common_Flt, const boolean_T *rtu_G4_Common_Flt,
              const boolean_T *rtu_G3_Dischg_Flt, const boolean_T
              *rtu_G4T1_Dischg_Flt, const boolean_T *rtu_G4T2_Dischg_Flt, real_T
              *rty_Dischg_CurrentLimit, real_T *rty_Timer30, B_NBMS_DCL_c_T
              *localB, DW_NBMS_DCL_f_T *localDW)
{
  real_T maxV;
  int32_T k;
  boolean_T rtb_IsBattCurrAboveSafetyLt;

  /* Outputs for Enabled SubSystem: '<S1>/DCL' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  if (*rtu_Veh_Lvl1 == DRIVE) {
    /* MinMax: '<S3>/FindMaxTemp' */
    maxV = rtu_Temperature[0];
    for (k = 0; k < 5; k++) {
      maxV = fmax(maxV, rtu_Temperature[k + 1]);
    }

    /* Lookup_n-D: '<S3>/Continuous_Safety_Pack' incorporates:
     *  DataTypeConversion: '<S3>/COnvToDouble'
     *  MinMax: '<S3>/FindMaxTemp'
     */
    localB->CurrentLimit = look2_binlxpw(maxV, *rtu_SOC, &TEMP[0], &SOC[0],
      rtCP_Continuous_Safety_Pack_tab, rtCP_Continuous_Safety_Pack_max, 10U);

    /* RelationalOperator: '<S3>/ChkBattCurrAboveSafetyLt' incorporates:
     *  Abs: '<S3>/Absolute'
     */
    rtb_IsBattCurrAboveSafetyLt = (fabs(*rtu_Current) > localB->CurrentLimit);

    /* Chart: '<S4>/CalcDCL' */
    if (localDW->is_active_c1_NBMS_DCL == 0) {
      localDW->is_active_c1_NBMS_DCL = 1U;
      if (*rtu_SOC > 20) {
        *rty_Timer30 = 30.0;
        localB->DCL = 0.0;
        localDW->is_c1_NBMS_DCL = NBMS_DCL_IN_C1_Condition;
        if (!rtb_IsBattCurrAboveSafetyLt) {
          localDW->is_C1_Condition = NBMS_DCL_IN_C1_Advantage;
        } else {
          localDW->is_C1_Condition = NBMS_DCL_IN_Peak;
          *rty_Timer30 = 29.9;
        }
      } else {
        localDW->is_c1_NBMS_DCL = NBMS_DCL_IN_Continuous;
        localB->DCL = 1.0;
      }
    } else if (localDW->is_c1_NBMS_DCL == NBMS_DCL_IN_C1_Condition) {
      if (*rty_Timer30 <= 0.0) {
        localDW->is_C1_Condition = NBMS_DCL_IN_NO_ACTIVE_CHILD;
        localDW->is_c1_NBMS_DCL = NBMS_DCL_IN_Continuous;
        localB->DCL = 1.0;
      } else if (localDW->is_C1_Condition == NBMS_DCL_IN_C1_Advantage) {
        if (rtb_IsBattCurrAboveSafetyLt) {
          localDW->is_C1_Condition = NBMS_DCL_IN_Peak;
          if (*rty_Timer30 > 0.0) {
            *rty_Timer30 -= 0.1;
          }
        } else if (*rty_Timer30 < 30.0) {
          *rty_Timer30 += 0.1;
        }

        /* case IN_Peak: */
      } else if (!rtb_IsBattCurrAboveSafetyLt) {
        localDW->is_C1_Condition = NBMS_DCL_IN_C1_Advantage;
        if (*rty_Timer30 < 30.0) {
          *rty_Timer30 += 0.1;
        }
      } else if (*rty_Timer30 > 0.0) {
        *rty_Timer30 -= 0.1;
      }

      /* case IN_Continuous: */
    } else if (*rtu_Veh_Lvl1 != DRIVE) {
      if (*rtu_SOC > 20) {
        *rty_Timer30 = 30.0;
        localB->DCL = 0.0;
        localDW->is_c1_NBMS_DCL = NBMS_DCL_IN_C1_Condition;
        if (!rtb_IsBattCurrAboveSafetyLt) {
          localDW->is_C1_Condition = NBMS_DCL_IN_C1_Advantage;
        } else {
          localDW->is_C1_Condition = NBMS_DCL_IN_Peak;
          *rty_Timer30 = 29.9;
        }
      } else {
        localDW->is_c1_NBMS_DCL = NBMS_DCL_IN_Continuous;
        localB->DCL = 1.0;
      }
    } else {
      localB->DCL = 1.0;
    }

    /* End of Chart: '<S4>/CalcDCL' */

    /* Switch: '<S3>/SelCurrentLimit' */
    if (!(localB->DCL != 0.0)) {
      /* Lookup_n-D: '<S3>/Continuous_Safety_Pack' incorporates:
       *  DataTypeConversion: '<S3>/COnvToDouble'
       *  Lookup_n-D: '<S3>/30s_Safety_Pack'
       *  MinMax: '<S3>/FindMaxTemp'
       *  Switch: '<S3>/SelCurrentLimit'
       */
      localB->CurrentLimit = look2_binlxpw(maxV, *rtu_SOC, &TEMP[0], &SOC[0],
        rtCP_u0s_Safety_Pack_tableData, rtCP_u0s_Safety_Pack_maxIndex, 10U);
    }

    /* End of Switch: '<S3>/SelCurrentLimit' */
  }

  /* End of RelationalOperator: '<S2>/Compare' */
  /* End of Outputs for SubSystem: '<S1>/DCL' */

  /* Switch: '<S1>/selDCL' incorporates:
   *  Constant: '<S1>/ZeroDCL'
   *  Logic: '<Root>/ChkG4DischgFlt'
   *  Logic: '<S1>/ChkForFault'
   */
  if (*rtu_G3_Common_Flt || *rtu_G4_Common_Flt || *rtu_G3_Dischg_Flt ||
      (*rtu_G4T1_Dischg_Flt || *rtu_G4T2_Dischg_Flt)) {
    *rty_Dischg_CurrentLimit = 0.0;
  } else {
    *rty_Dischg_CurrentLimit = localB->CurrentLimit;
  }

  /* End of Switch: '<S1>/selDCL' */
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
