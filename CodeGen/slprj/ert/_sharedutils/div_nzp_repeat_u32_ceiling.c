/*
 * File: div_nzp_repeat_u32_ceiling.c
 *
 * Code generated for Simulink model 'NBMS_SoC'.
 *
 * Model version                  : 7.73
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Tue Nov 10 18:06:13 2026
 */

#include "div_nzp_repeat_u32_ceiling.h"
#include "rtwtypes.h"

uint32_T div_nzp_repeat_u32_ceiling(uint32_T numerator, uint32_T denominator,
  uint32_T nRepeatSub)
{
  uint32_T iRepeatSub;
  uint32_T localNumerator;
  uint32_T quotient;
  quotient = numerator / denominator;
  localNumerator = numerator % denominator;
  for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub++) {
    boolean_T numeratorExtraBit;
    numeratorExtraBit = (localNumerator >= 2147483648U);
    localNumerator <<= 1U;
    quotient <<= 1U;
    if (numeratorExtraBit || (localNumerator >= denominator)) {
      quotient++;
      localNumerator -= denominator;
    }
  }

  if (localNumerator > 0U) {
    quotient++;
  }

  return quotient;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
