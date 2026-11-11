/*
 * File: NBMS_SM_types.h
 *
 * Code generated for Simulink model 'NBMS_SM'.
 *
 * Model version                  : 7.16
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Tue Nov 10 18:06:00 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_SM_types_h_
#define NBMS_SM_types_h_
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

#ifndef DEFINED_TYPEDEF_FOR_CV_Mode_Timer_E_
#define DEFINED_TYPEDEF_FOR_CV_Mode_Timer_E_

typedef enum {
  Off = 0,                             /* Default value */
  On,
  Expired
} CV_Mode_Timer_E;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Charger_Mode_E_
#define DEFINED_TYPEDEF_FOR_Charger_Mode_E_

typedef enum {
  OFF = 0,                             /* Default value */
  OBC_Standby,
  Precharge,
  Charging,
  PCBTempDerating,
  FETTempDerating,
  IPVoltDerating,
  Error
} Charger_Mode_E;

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
typedef struct tag_RTM_NBMS_SM_T RT_MODEL_NBMS_SM_T;

#endif                                 /* NBMS_SM_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
