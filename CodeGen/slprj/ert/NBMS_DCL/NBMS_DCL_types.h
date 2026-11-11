/*
 * File: NBMS_DCL_types.h
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

#ifndef NBMS_DCL_types_h_
#define NBMS_DCL_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_VEH_STT_LVL1_E_
#define DEFINED_TYPEDEF_FOR_VEH_STT_LVL1_E_

typedef enum {
  VL1_SNA = 0,
  VEH_SLEEP,                           /* Default value */
  AWAKE,
  STANDBY,
  DRIVE,
  CHARGE
} VEH_STT_LVL1_E;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_NBMS_DCL_T RT_MODEL_NBMS_DCL_T;

#endif                                 /* NBMS_DCL_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
