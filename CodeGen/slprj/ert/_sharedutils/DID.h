/*
 * File: DID.h
 *
 * Code generated for Simulink model 'NBMS_SoC'.
 *
 * Model version                  : 7.101
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Fri Nov 20 12:35:00 2026
 */

#ifndef DID_h_
#define DID_h_
#include "rtwtypes.h"

/* Exported data declaration */
/* Declaration for custom storage class: ExportToFile */
extern uint8_T CAL_15_SOC_WRN_RVL_THRSH;
extern uint8_T CAL_15_SOC_WRN_THRSH;
extern uint16_T CAL_CC_END_DEBOUNCE_TIMER;
extern uint16_T CAL_CC_END_THRSH;
extern uint32_T CAL_CHRG_CC_CURRENT_LIMIT;
extern uint32_T CAL_CHRG_CV_CURRENT_LIMIT;
extern uint32_T CAL_CHRG_VOLT_LIMIT;
extern uint32_T CAL_CV_COMPLETE_TIMER;
extern uint16_T CAL_CV_END_DEBOUNCE_TIMER;
extern uint16_T CAL_CV_END_THRSH;
extern uint16_T CAL_CV_WAIT_TIMER;
extern uint16_T CAL_DCHRG_END_THRSH;
extern uint16_T CAL_DD_REVIVAL_CCL;
extern uint8_T CAL_DOD;
extern uint8_T CAL_DOD_MAX_THRSH;
extern uint8_T CAL_DOD_MIN_THRSH;
extern boolean_T CAL_ENABLE_SOC_WARN_15;
extern boolean_T CAL_ENABLE_SOC_WARN_20;
extern uint16_T CAL_GOLDEN_CHARGE;
extern uint16_T CAL_GOLDEN_DC;
extern uint8_T CAL_LOW_SOC_RVL_THRSH;
extern uint8_T CAL_LOW_SOC_THRSH;
extern uint16_T CAL_MOSFET_DISENG_THRSH;
extern uint16_T CAL_MOSFET_FEEDBACK;
extern uint16_T CAL_NM_MSG_Sleep_timer;
extern uint32_T CAL_NOMINAL_VOLTAGE;
extern uint8_T CAL_SOC_WRN_RVL_THRSH;
extern uint8_T CAL_SOC_WRN_THRSH;
extern boolean_T CAL_SOH_Enable;
extern real_T MosfetTime;
extern real_T RegenAllowedTime;
extern real_T SOC[13];
extern real_T TABLE_CCL_CONT_SAFETY_PACK[117];
extern real_T TABLE_DCIR_CHG[77];
extern real_T TABLE_DCIR_DISCH[77];
extern real_T TABLE_DCL_30sSAFETY_PACK[130];
extern real_T TABLE_DCL_CONT_SAFETY_PACK[130];
extern real_T TABLE_RCL_CONT_SAFETY_PACK[117];
extern real_T TABLE_SOC_VS_OCV_CHG[147];
extern real_T TABLE_SOC_VS_OCV_DISCH[147];
extern real_T TEMP[10];
extern real_T X_CCL_CONT_SAFETY_PACK[9];
extern real_T X_DCIR_CHG[7];
extern real_T X_DCIR_DISCH[7];
extern real_T X_DCL_30sSAFETY_PACK[10];
extern real_T X_DCL_CONT_SAFETY_PACK[10];
extern real_T X_RCL_CONT_SAFETY_PACK[9];
extern real_T X_SOC_VS_OCV_CHG[21];
extern real_T X_SOC_VS_OCV_DISCH[21];
extern real_T Y_CCL_CONT_SAFETY_PACK[13];
extern real_T Y_DCIR_CHG[11];
extern real_T Y_DCIR_DISCH[11];
extern real_T Y_DCL_30sSAFETY_PACK[13];
extern real_T Y_DCL_CONT_SAFETY_PACK[13];
extern real_T Y_RCL_CONT_SAFETY_PACK[13];
extern real_T Y_SOC_VS_OCV_CHG[7];
extern real_T Y_SOC_VS_OCV_DISCH[7];

#endif                                 /* DID_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
