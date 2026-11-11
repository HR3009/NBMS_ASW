/*
 * File: NBMS_Regen_types.h
 *
 * Code generated for Simulink model 'NBMS_Regen'.
 *
 * Model version                  : 7.10
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 11 09:32:12 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_Regen_types_h_
#define NBMS_Regen_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_BMS_MODE_E_
#define DEFINED_TYPEDEF_FOR_BMS_MODE_E_

typedef enum {
  BMS_SLEEP = 0,                       /* Default value */
  BMS_DISCHARGE,
  BMS_CHARGE,
  BMS_STANDBY,
  BMS_FAULT
} BMS_MODE_E;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_NBMS_Regen_T RT_MODEL_NBMS_Regen_T;

#endif                                 /* NBMS_Regen_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
