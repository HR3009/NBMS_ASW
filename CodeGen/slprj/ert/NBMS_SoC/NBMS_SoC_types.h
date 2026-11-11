/*
 * File: NBMS_SoC_types.h
 *
 * Code generated for Simulink model 'NBMS_SoC'.
 *
 * Model version                  : 7.73
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 11 09:32:21 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_SoC_types_h_
#define NBMS_SoC_types_h_
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

#ifndef DEFINED_TYPEDEF_FOR_Charger_Mode_Req_E_
#define DEFINED_TYPEDEF_FOR_Charger_Mode_Req_E_

typedef enum {
  Disabled = 0,                        /* Default value */
  CC_Start,
  CV,
  Charge_Complete,
  CC_End,
  Standby
} Charger_Mode_Req_E;

#endif

#ifndef DEFINED_TYPEDEF_FOR_OBC_E_
#define DEFINED_TYPEDEF_FOR_OBC_E_

typedef enum {
  Sleep = 0,                           /* Default value */
  Wake_Up
} OBC_E;

#endif

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
typedef struct tag_RTM_NBMS_SoC_T RT_MODEL_NBMS_SoC_T;

#endif                                 /* NBMS_SoC_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
