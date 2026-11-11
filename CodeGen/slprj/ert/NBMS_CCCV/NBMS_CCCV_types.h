/*
 * File: NBMS_CCCV_types.h
 *
 * Code generated for Simulink model 'NBMS_CCCV'.
 *
 * Model version                  : 7.23
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 11 09:32:01 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_CCCV_types_h_
#define NBMS_CCCV_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_BMS_HVMosfet_STS_E_
#define DEFINED_TYPEDEF_FOR_BMS_HVMosfet_STS_E_

typedef enum {
  HV_DISCONNECTED = 0,                 /* Default value */
  HV_DISCONNECT_PENDING,
  HV_CONNECTED,
  HV_CONNECT_PENDING,
  HV_MOSFET_FAULT,
  HV_RESERVATION
} BMS_HVMosfet_STS_E;

#endif

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

#ifndef DEFINED_TYPEDEF_FOR_BMS_NM_Msg_E_
#define DEFINED_TYPEDEF_FOR_BMS_NM_Msg_E_

typedef enum {
  SLEEP = 0,                           /* Default value */
  ACTIVE
} BMS_NM_Msg_E;

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

/* Forward declaration for rtModel */
typedef struct tag_RTM_NBMS_CCCV_T RT_MODEL_NBMS_CCCV_T;

#endif                                 /* NBMS_CCCV_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
