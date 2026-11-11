/*
 * File: NBMS_App_types.h
 *
 * Code generated for Simulink model 'NBMS_App'.
 *
 * Model version                  : 7.74
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 11 09:32:27 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_App_types_h_
#define NBMS_App_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_Active_DisChrg_E_
#define DEFINED_TYPEDEF_FOR_Active_DisChrg_E_

typedef enum {
  Inactive = 0,                        /* Default value */
  InProgress,
  Completed,
  Invalid
} Active_DisChrg_E;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BMS_DCDCMosfet_STS_E_
#define DEFINED_TYPEDEF_FOR_BMS_DCDCMosfet_STS_E_

typedef enum {
  DCDC_DISCONNECTED = 0,               /* Default value */
  DCDC_CONNECTED,
  DCDC_MOSFET_FAULT,
  DCDC_RESERVATION
} BMS_DCDCMosfet_STS_E;

#endif

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

#ifndef DEFINED_TYPEDEF_FOR_BMS_PMosfet_STS_E_
#define DEFINED_TYPEDEF_FOR_BMS_PMosfet_STS_E_

typedef enum {
  PDISCONNECTED = 0,                   /* Default value */
  PCONNECTED,
  PMOSFET_FAULT
} BMS_PMosfet_STS_E;

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
typedef struct tag_RTM_NBMS_App_T RT_MODEL_NBMS_App_T;

#endif                                 /* NBMS_App_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
