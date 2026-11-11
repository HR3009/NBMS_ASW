/*
 * File: DID.c
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

#include "DID.h"
#include "rtwtypes.h"

/* Exported data definition */

/* Definition for custom storage class: ExportToFile */
uint8_T CAL_15_SOC_WRN_RVL_THRSH = 15U;
uint8_T CAL_15_SOC_WRN_THRSH = 15U;
uint16_T CAL_CC_END_DEBOUNCE_TIMER = 3U;
uint16_T CAL_CC_END_THRSH = 4185U;
uint32_T CAL_CHRG_CC_CURRENT_LIMIT = 10000U;
uint32_T CAL_CHRG_CV_CURRENT_LIMIT = 2000U;
uint32_T CAL_CHRG_VOLT_LIMIT = 85000U;
uint32_T CAL_CV_COMPLETE_TIMER = 3600U;
uint16_T CAL_CV_END_DEBOUNCE_TIMER = 5U;
uint16_T CAL_CV_END_THRSH = 4220U;
uint16_T CAL_CV_WAIT_TIMER = 3U;
uint16_T CAL_DCHRG_END_THRSH = 2900U;
uint16_T CAL_DD_REVIVAL_CCL = 1000U;
uint8_T CAL_DOD = 100U;
uint8_T CAL_DOD_MAX_THRSH = 99U;
uint8_T CAL_DOD_MIN_THRSH = 1U;
boolean_T CAL_ENABLE_SOC_WARN_15 = false;
boolean_T CAL_ENABLE_SOC_WARN_20 = true;
uint16_T CAL_GOLDEN_CHARGE = 34000U;
uint16_T CAL_GOLDEN_DC = 34000U;
uint8_T CAL_LOW_SOC_RVL_THRSH = 3U;
uint8_T CAL_LOW_SOC_THRSH = 0U;
uint16_T CAL_MOSFET_DISENG_THRSH = 5000U;
uint16_T CAL_MOSFET_FEEDBACK = 200U;
uint16_T CAL_NM_MSG_Sleep_timer = 5U;
uint32_T CAL_NOMINAL_VOLTAGE = 84000U;
uint8_T CAL_SOC_WRN_RVL_THRSH = 20U;
uint8_T CAL_SOC_WRN_THRSH = 20U;
boolean_T CAL_SOH_Enable = false;
real_T MosfetTime = 400.0;
real_T RegenAllowedTime = 3.0;
real_T SOC[13] = { 0.0, 5.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0,
  90.0, 95.0, 100.0 } ;

real_T TEMP[10] = { -30.0, -20.0, -10.0, 0.0, 10.0, 25.0, 45.0, 50.0, 60.0, 70.0
} ;

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
