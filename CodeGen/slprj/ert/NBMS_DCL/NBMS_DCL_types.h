/*
 * File: NBMS_DCL_types.h
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

#ifndef NBMS_DCL_types_h_
#define NBMS_DCL_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_VDU_MACHINE_STS_E_
#define DEFINED_TYPEDEF_FOR_VDU_MACHINE_STS_E_

typedef enum {
  SNA = 0,                             /* Default value */
  VDU_SLEEP,
  POWER_ON,
  IDLE,
  DRIVE,
  FAULT,
  DERATE
} VDU_MACHINE_STS_E;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_NBMS_DCL_T RT_MODEL_NBMS_DCL_T;

#endif                                 /* NBMS_DCL_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
