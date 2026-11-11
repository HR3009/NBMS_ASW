/*
 * File: NBMS_DischargeOCV.c
 *
 * Code generated for Simulink model 'NBMS_DischargeOCV'.
 *
 * Model version                  : 7.2
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Tue Nov 10 18:06:05 2026
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

/* Disable for referenced model: 'NBMS_DischargeOCV' */
void NBMS_DischargeOCV_Disable(real_T *rty_Initial_SOC, DW_NBMS_DischargeOCV_f_T
  *localDW)
{
  if (localDW->TmpModelReferenceSubsystem_MODE) {
    /* Outputs for Enabled SubSystem: '<Root>/TmpModelReferenceSubsystem' incorporates:
     *  EnablePort: '<Root>/Enable'
     */
    /* Disable for Outport: '<Root>/Initial_SOC' */
    *rty_Initial_SOC = 0.0;
    localDW->TmpModelReferenceSubsystem_MODE = false;
  }
}

/* Output and update for referenced model: 'NBMS_DischargeOCV' */
void NBMS_DischargeOCV(const real_T *rtu_Temp, const int16_T *rtu_OCV, const
  boolean_T *rtu_Enable, real_T *rty_Initial_SOC, DW_NBMS_DischargeOCV_f_T
  *localDW)
{
  real_T rtb_Gain;
  real_T rtb_UnitDelay;
  real_T tmp;
  int32_T s1_iter;

  /* Outputs for Enabled SubSystem: '<Root>/TmpModelReferenceSubsystem' incorporates:
   *  EnablePort: '<Root>/Enable'
   */
  if (*rtu_Enable) {
    localDW->TmpModelReferenceSubsystem_MODE = true;

    /* Outputs for Iterator SubSystem: '<Root>/OCV vs SOC @ all Temperatures' incorporates:
     *  ForIterator: '<S1>/For Iterator'
     */
    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
    localDW->UnitDelay_DSTATE = 0.0;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay2' */
    localDW->UnitDelay2_DSTATE = 0.0;

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay1' */
    localDW->UnitDelay1_DSTATE = 0.0;
    for (s1_iter = 0; s1_iter < 501; s1_iter++) {
      /* UnitDelay: '<S1>/Unit Delay' */
      rtb_UnitDelay = localDW->UnitDelay_DSTATE;

      /* Gain: '<S1>/Gain' */
      rtb_Gain = 0.2 * (real_T)s1_iter;

      /* Lookup_n-D: '<S1>/OCV vs SOC at all Temp' incorporates:
       *  Gain: '<S1>/Gain'
       *  UnitDelay: '<S1>/Unit Delay'
       */
      localDW->UnitDelay_DSTATE = look2_binlcpw(rtb_Gain, *rtu_Temp,
        rtCP_OCVvsSOCatallTemp_bp01Data, rtCP_OCVvsSOCatallTemp_bp02Data,
        rtCP_OCVvsSOCatallTemp_tableDat, rtCP_OCVvsSOCatallTemp_maxIndex, 21U);

      /* RelationalOperator: '<S1>/Relational Operator2' incorporates:
       *  RelationalOperator: '<S1>/Relational Operator'
       *  RelationalOperator: '<S1>/Relational Operator1'
       *  RelationalOperator: '<S1>/Relational Operator3'
       *  Sum: '<S1>/Add2'
       *  Switch: '<S1>/Switch'
       *  Switch: '<S1>/Switch1'
       *  Switch: '<S1>/Switch2'
       */
      tmp = (real_T)*rtu_OCV * 0.001;

      /* Switch: '<S1>/Switch1' incorporates:
       *  Constant: '<S1>/Constant'
       *  Constant: '<S1>/Constant1'
       *  Logic: '<S1>/AND'
       *  Lookup_n-D: '<S1>/OCV vs SOC at all Temp1'
       *  Lookup_n-D: '<S1>/OCV vs SOC at all Temp2'
       *  RelationalOperator: '<S1>/Relational Operator'
       *  RelationalOperator: '<S1>/Relational Operator1'
       *  RelationalOperator: '<S1>/Relational Operator2'
       *  RelationalOperator: '<S1>/Relational Operator3'
       *  Switch: '<S1>/Switch'
       *  Switch: '<S1>/Switch2'
       *  UnitDelay: '<S1>/Unit Delay'
       */
      if (tmp >= look2_binlcpw(100.0, *rtu_Temp, rtCP_OCVvsSOCatallTemp1_bp01Dat,
           rtCP_OCVvsSOCatallTemp1_bp02Dat, rtCP_OCVvsSOCatallTemp1_tableDa,
           rtCP_OCVvsSOCatallTemp1_maxInde, 21U)) {
        rtb_UnitDelay = 100.0;
      } else if (tmp <= look2_binlcpw(0.0, *rtu_Temp,
                  rtCP_OCVvsSOCatallTemp2_bp01Dat,
                  rtCP_OCVvsSOCatallTemp2_bp02Dat,
                  rtCP_OCVvsSOCatallTemp2_tableDa,
                  rtCP_OCVvsSOCatallTemp2_maxInde, 21U)) {
        /* Switch: '<S1>/Switch2' incorporates:
         *  Constant: '<S1>/Constant1'
         */
        rtb_UnitDelay = 0.0;
      } else if ((rtb_UnitDelay < tmp) && (localDW->UnitDelay_DSTATE >= tmp)) {
        /* Switch: '<S1>/Switch' incorporates:
         *  Product: '<S1>/Divide'
         *  Product: '<S1>/Product'
         *  Sum: '<S1>/Add'
         *  Sum: '<S1>/Add1'
         *  Sum: '<S1>/Add2'
         *  Sum: '<S1>/Add3'
         *  Switch: '<S1>/Switch2'
         *  UnitDelay: '<S1>/Unit Delay'
         *  UnitDelay: '<S1>/Unit Delay2'
         */
        rtb_UnitDelay = rtb_Gain - (rtb_Gain - localDW->UnitDelay2_DSTATE) /
          (localDW->UnitDelay_DSTATE - rtb_UnitDelay) * (tmp -
          localDW->UnitDelay_DSTATE);
      } else {
        /* Switch: '<S1>/Switch' incorporates:
         *  Switch: '<S1>/Switch2'
         *  UnitDelay: '<S1>/Unit Delay1'
         */
        rtb_UnitDelay = localDW->UnitDelay1_DSTATE;
      }

      /* Update for UnitDelay: '<S1>/Unit Delay2' */
      localDW->UnitDelay2_DSTATE = rtb_Gain;

      /* Update for UnitDelay: '<S1>/Unit Delay1' */
      localDW->UnitDelay1_DSTATE = rtb_UnitDelay;
    }

    /* End of Outputs for SubSystem: '<Root>/OCV vs SOC @ all Temperatures' */

    /* SignalConversion generated from: '<Root>/Initial_SOC' */
    *rty_Initial_SOC = rtb_UnitDelay;
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
