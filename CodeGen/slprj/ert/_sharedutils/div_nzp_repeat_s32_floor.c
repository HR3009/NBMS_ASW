/*
 * File: div_nzp_repeat_s32_floor.c
 *
 * Code generated for Simulink model 'NBMS_SoC'.
 *
 * Model version                  : 7.73
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Tue Nov 10 18:06:13 2026
 */

#include "div_nzp_repeat_s32_floor.h"
#include "div_nzp_repeat_u32.h"
#include "div_nzp_repeat_u32_ceiling.h"
#include "rtwtypes.h"

int32_T div_nzp_repeat_s32_floor(int32_T numerator, int32_T denominator,
  uint32_T nRepeatSub)
{
  int32_T quotient;
  uint32_T absDenominator;
  uint32_T absNumerator;
  absNumerator = numerator < 0 ? ~(uint32_T)/*MW:OvOk*/ numerator + 1U :
    (uint32_T)numerator;
  absDenominator = denominator < 0 ? ~(uint32_T)/*MW:OvOk*/ denominator + 1U :
    (uint32_T)denominator;
  if ((numerator < 0) != (denominator < 0)) {
    quotient = -/*MW:OvOk*/ ((int32_T)div_nzp_repeat_u32_ceiling(absNumerator,
      absDenominator, nRepeatSub));
  } else {
    quotient = (int32_T)div_nzp_repeat_u32(absNumerator, absDenominator,
      nRepeatSub);
  }

  return quotient;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
