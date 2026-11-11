/*
 * File: NBMS_MosfetSeq_types.h
 *
 * Code generated for Simulink model 'NBMS_MosfetSeq'.
 *
 * Model version                  : 7.42
 * Simulink Coder version         : 26.2 (R2026b) 22-May-2026
 * C/C++ source code generated on : Wed Nov 11 09:32:09 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef NBMS_MosfetSeq_types_h_
#define NBMS_MosfetSeq_types_h_
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

#ifndef DEFINED_TYPEDEF_FOR_BMS_PMosfet_STS_E_
#define DEFINED_TYPEDEF_FOR_BMS_PMosfet_STS_E_

typedef enum {
  PDISCONNECTED = 0,                   /* Default value */
  PCONNECTED,
  PMOSFET_FAULT
} BMS_PMosfet_STS_E;

#endif

#ifndef DEFINED_TYPEDEF_FOR_OBC_E_
#define DEFINED_TYPEDEF_FOR_OBC_E_

typedef enum {
  Sleep = 0,                           /* Default value */
  Wake_Up
} OBC_E;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_NBMS_MosfetSeq_T RT_MODEL_NBMS_MosfetSeq_T;

#endif                                 /* NBMS_MosfetSeq_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
