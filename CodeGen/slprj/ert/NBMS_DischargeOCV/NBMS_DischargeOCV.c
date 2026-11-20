/*
 * File: NBMS_DischargeOCV.c
 *
 * Code generated for Simulink model 'NBMS_DischargeOCV'.
 *
 * Model version                  : 7.6
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Fri Nov 20 12:34:51 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "NBMS_DischargeOCV.h"
#include "rtwtypes.h"
#include "NBMS_DischargeOCV_private.h"
#include "look2_binlcpw.h"
#include "DID.h"

/* Disable for referenced model: 'NBMS_DischargeOCV' */
void NBMS_DischargeOCV_Disable(real_T *rty_Initial_SOC, DW_NBMS_DischargeOCV_f_T
  *localDW)
{
  if (localDW->TmpModelReferenceSubsystem_MODE) {
    /* Outputs for Enabled SubSystem: '<Root>/TmpModelReferenceSubsystem' incorporates:
     *  EnablePort: '<Root>/EnableWhenValid'
     */
    /* Disable for Outport: '<Root>/Initial_SOC' */
    *rty_Initial_SOC = 0.0;
    localDW->TmpModelReferenceSubsystem_MODE = false;
  }
}

/* Output and update for referenced model: 'NBMS_DischargeOCV' */
void NBMS_DischargeOCV(const real_T *rtu_Temp, const int16_T *rtu_OCV, const
  boolean_T *rtu_EnableWhenValid, real_T *rty_Initial_SOC,
  DW_NBMS_DischargeOCV_f_T *localDW)
{
  real_T rtb_SoC;
  real_T rtb_delayCalculatedOCV;
  real_T tmp;
  int32_T IteratedSoC;

  /* Outputs for Enabled SubSystem: '<Root>/TmpModelReferenceSubsystem' incorporates:
   *  EnablePort: '<Root>/EnableWhenValid'
   */
  if (*rtu_EnableWhenValid) {
    localDW->TmpModelReferenceSubsystem_MODE = true;

    /* Outputs for Iterator SubSystem: '<Root>/OCV vs SOC @ all Temperatures' incorporates:
     *  ForIterator: '<S1>/SoCIteration'
     */
    /* InitializeConditions for UnitDelay: '<S1>/udlyCalcOCV' */
    localDW->udlyCalcOCV_DSTATE = 0.0;

    /* InitializeConditions for UnitDelay: '<S1>/udlySoC' */
    localDW->udlySoC_DSTATE = 0.0;

    /* InitializeConditions for UnitDelay: '<S1>/udlyInitialSoC' */
    localDW->udlyInitialSoC_DSTATE = 0.0;
    for (IteratedSoC = 0; IteratedSoC < 501; IteratedSoC++) {
      /* UnitDelay: '<S1>/udlyCalcOCV' */
      rtb_delayCalculatedOCV = localDW->udlyCalcOCV_DSTATE;

      /* Gain: '<S1>/scaleSoC' */
      rtb_SoC = 0.2 * (real_T)IteratedSoC;

      /* Lookup_n-D: '<S1>/OCV vs SOC at all Temp' incorporates:
       *  Gain: '<S1>/scaleSoC'
       *  UnitDelay: '<S1>/udlyCalcOCV'
       */
      localDW->udlyCalcOCV_DSTATE = look2_binlcpw(rtb_SoC, *rtu_Temp,
        &X_SOC_VS_OCV_DISCH[0], &Y_SOC_VS_OCV_DISCH[0], &TABLE_SOC_VS_OCV_DISCH
        [0], rtCP_OCVvsSOCatallTemp_maxIndex, 21U);

      /* RelationalOperator: '<S1>/ChkOCVaboveCalcOCV' incorporates:
       *  RelationalOperator: '<S1>/ChkLowerOCVBound'
       *  RelationalOperator: '<S1>/ChkOCVBelowCalcOCV'
       *  RelationalOperator: '<S1>/ChkUpperOCVBound'
       *  Sum: '<S1>/CalcDiffOCV'
       *  Switch: '<S1>/latchInitialSoC'
       *  Switch: '<S1>/selInitalSoC'
       *  Switch: '<S1>/selSoC'
       */
      tmp = (real_T)*rtu_OCV * 0.001;

      /* Switch: '<S1>/selInitalSoC' incorporates:
       *  Constant: '<S1>/MaxSoC'
       *  Constant: '<S1>/MinSoC'
       *  Logic: '<S1>/DetectOCVCrossing'
       *  Lookup_n-D: '<S1>/OCV vs SOC at all Temp1'
       *  Lookup_n-D: '<S1>/OCV vs SOC at all Temp2'
       *  RelationalOperator: '<S1>/ChkLowerOCVBound'
       *  RelationalOperator: '<S1>/ChkOCVBelowCalcOCV'
       *  RelationalOperator: '<S1>/ChkOCVaboveCalcOCV'
       *  RelationalOperator: '<S1>/ChkUpperOCVBound'
       *  Switch: '<S1>/latchInitialSoC'
       *  Switch: '<S1>/selSoC'
       *  UnitDelay: '<S1>/udlyCalcOCV'
       */
      if (tmp >= look2_binlcpw(100.0, *rtu_Temp, &X_SOC_VS_OCV_DISCH[0],
           &Y_SOC_VS_OCV_DISCH[0], &TABLE_SOC_VS_OCV_DISCH[0],
           rtCP_OCVvsSOCatallTemp1_maxInde, 21U)) {
        rtb_delayCalculatedOCV = 100.0;
      } else if (tmp <= look2_binlcpw(0.0, *rtu_Temp, &X_SOC_VS_OCV_DISCH[0],
                  &Y_SOC_VS_OCV_DISCH[0], &TABLE_SOC_VS_OCV_DISCH[0],
                  rtCP_OCVvsSOCatallTemp2_maxInde, 21U)) {
        /* Switch: '<S1>/selSoC' incorporates:
         *  Constant: '<S1>/MinSoC'
         */
        rtb_delayCalculatedOCV = 0.0;
      } else if ((localDW->udlyCalcOCV_DSTATE >= tmp) && (rtb_delayCalculatedOCV
                  < tmp)) {
        /* Switch: '<S1>/latchInitialSoC' incorporates:
         *  Product: '<S1>/CalcSoC'
         *  Product: '<S1>/divSoCbyOCV'
         *  Sum: '<S1>/CalcDiffOCV'
         *  Sum: '<S1>/CalcDiffSoC'
         *  Sum: '<S1>/CalcDiffcalcOCV'
         *  Sum: '<S1>/SoCDifference'
         *  Switch: '<S1>/selSoC'
         *  UnitDelay: '<S1>/udlyCalcOCV'
         *  UnitDelay: '<S1>/udlySoC'
         */
        rtb_delayCalculatedOCV = rtb_SoC - (rtb_SoC - localDW->udlySoC_DSTATE) /
          (localDW->udlyCalcOCV_DSTATE - rtb_delayCalculatedOCV) * (tmp -
          localDW->udlyCalcOCV_DSTATE);
      } else {
        /* Switch: '<S1>/latchInitialSoC' incorporates:
         *  Switch: '<S1>/selSoC'
         *  UnitDelay: '<S1>/udlyInitialSoC'
         */
        rtb_delayCalculatedOCV = localDW->udlyInitialSoC_DSTATE;
      }

      /* Update for UnitDelay: '<S1>/udlySoC' */
      localDW->udlySoC_DSTATE = rtb_SoC;

      /* Update for UnitDelay: '<S1>/udlyInitialSoC' */
      localDW->udlyInitialSoC_DSTATE = rtb_delayCalculatedOCV;
    }

    /* End of Outputs for SubSystem: '<Root>/OCV vs SOC @ all Temperatures' */

    /* SignalConversion generated from: '<Root>/Initial_SOC' */
    *rty_Initial_SOC = rtb_delayCalculatedOCV;
  } else {
    NBMS_DischargeOCV_Disable(rty_Initial_SOC, localDW);
  }
}

/* Model initialize function */
void NBMS_DischargeOCV_initialize(const char_T **rt_errorStatus,
  RT_MODEL_NBMS_DischargeOCV_T *const NBMS_DischargeOCV_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(NBMS_DischargeOCV_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
