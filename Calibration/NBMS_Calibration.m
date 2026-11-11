% -------------------------------------------------------------------
%               CALIBARATION PARAMETERS AND CONSTANTS
% -------------------------------------------------------------------

%% MOSFET PARAMETER

%CAL_MOSFET_FEEDBACK
CAL_MOSFET_FEEDBACK =Simulink.Parameter;
CAL_MOSFET_FEEDBACK.Value =200; 
CAL_MOSFET_FEEDBACK.DataType='uint16';
CAL_MOSFET_FEEDBACK.CoderInfo.StorageClass='Custom';
CAL_MOSFET_FEEDBACK.CoderInfo.CustomStorageClass='ExportToFile';
CAL_MOSFET_FEEDBACK.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_MOSFET_FEEDBACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';



%CAL_MOSFET_DISENG_THRSH
CAL_MOSFET_DISENG_THRSH =Simulink.Parameter;
CAL_MOSFET_DISENG_THRSH.Value =5000; 
CAL_MOSFET_DISENG_THRSH.DataType='uint16';
CAL_MOSFET_DISENG_THRSH.CoderInfo.StorageClass='Custom';
CAL_MOSFET_DISENG_THRSH.CoderInfo.CustomStorageClass='ExportToFile';
CAL_MOSFET_DISENG_THRSH.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_MOSFET_DISENG_THRSH.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%MosfetTime
MosfetTime = Simulink.Parameter;
MosfetTime.Value = 400;
MosfetTime.DataType = 'double';
MosfetTime.CoderInfo.StorageClass='Custom';
MosfetTime.CoderInfo.CustomStorageClass='ExportToFile';
MosfetTime.CoderInfo.CustomAttributes.HeaderFile='DID.h';
MosfetTime.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%% CHARGE PARAMETER

%CAL_NM_MSG_Sleep_timer
CAL_NM_MSG_Sleep_timer =Simulink.Parameter;
CAL_NM_MSG_Sleep_timer.Value = 5;
CAL_NM_MSG_Sleep_timer.DataType = 'uint16';
CAL_NM_MSG_Sleep_timer.CoderInfo.StorageClass='Custom';
CAL_NM_MSG_Sleep_timer.CoderInfo.CustomStorageClass='ExportToFile';
CAL_NM_MSG_Sleep_timer.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_NM_MSG_Sleep_timer.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_DD_REVIVAL_CCL
CAL_DD_REVIVAL_CCL = Simulink.Parameter;
CAL_DD_REVIVAL_CCL.Value = 1000;
CAL_DD_REVIVAL_CCL.DataType = 'uint16';
CAL_DD_REVIVAL_CCL.CoderInfo.StorageClass='Custom';
CAL_DD_REVIVAL_CCL.CoderInfo.CustomStorageClass='ExportToFile';
CAL_DD_REVIVAL_CCL.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_DD_REVIVAL_CCL.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_CC_END_THRSH
CAL_CC_END_THRSH =Simulink.Parameter;
CAL_CC_END_THRSH.Value =4185; 
CAL_CC_END_THRSH.DataType='uint16';
CAL_CC_END_THRSH.CoderInfo.StorageClass='Custom';
CAL_CC_END_THRSH.CoderInfo.CustomStorageClass='ExportToFile';
CAL_CC_END_THRSH.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_CC_END_THRSH.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_CC_END_DEBOUNCE_TIMER
CAL_CC_END_DEBOUNCE_TIMER =Simulink.Parameter;
CAL_CC_END_DEBOUNCE_TIMER.Value = 3; 
CAL_CC_END_DEBOUNCE_TIMER.DataType='uint16';
CAL_CC_END_DEBOUNCE_TIMER.CoderInfo.StorageClass='Custom';
CAL_CC_END_DEBOUNCE_TIMER.CoderInfo.CustomStorageClass='ExportToFile';
CAL_CC_END_DEBOUNCE_TIMER.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_CC_END_DEBOUNCE_TIMER.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_CV_WAIT_TIMER
CAL_CV_WAIT_TIMER =Simulink.Parameter;
CAL_CV_WAIT_TIMER.Value = 3; 
CAL_CV_WAIT_TIMER.DataType='uint16';
CAL_CV_WAIT_TIMER.CoderInfo.StorageClass='Custom';
CAL_CV_WAIT_TIMER.CoderInfo.CustomStorageClass='ExportToFile';
CAL_CV_WAIT_TIMER.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_CV_WAIT_TIMER.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_CV_END_THRSH
CAL_CV_END_THRSH =Simulink.Parameter;
CAL_CV_END_THRSH.Value =4220; 
CAL_CV_END_THRSH.DataType='uint16';
CAL_CV_END_THRSH.CoderInfo.StorageClass='Custom';
CAL_CV_END_THRSH.CoderInfo.CustomStorageClass='ExportToFile';
CAL_CV_END_THRSH.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_CV_END_THRSH.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_CV_END_DEBOUNCE_TIMER
CAL_CV_END_DEBOUNCE_TIMER =Simulink.Parameter;
CAL_CV_END_DEBOUNCE_TIMER.Value = 5; 
CAL_CV_END_DEBOUNCE_TIMER.DataType='uint16';
CAL_CV_END_DEBOUNCE_TIMER.CoderInfo.StorageClass='Custom';
CAL_CV_END_DEBOUNCE_TIMER.CoderInfo.CustomStorageClass='ExportToFile';
CAL_CV_END_DEBOUNCE_TIMER.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_CV_END_DEBOUNCE_TIMER.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_CV_COMPLETE_TIMER
CAL_CV_COMPLETE_TIMER =Simulink.Parameter;
CAL_CV_COMPLETE_TIMER.Value = 3600; 
CAL_CV_COMPLETE_TIMER.DataType='uint32';
CAL_CV_COMPLETE_TIMER.CoderInfo.StorageClass='Custom';
CAL_CV_COMPLETE_TIMER.CoderInfo.CustomStorageClass='ExportToFile';
CAL_CV_COMPLETE_TIMER.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_CV_COMPLETE_TIMER.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_CHRG_VOLT_LIMIT
CAL_CHRG_VOLT_LIMIT =Simulink.Parameter;
CAL_CHRG_VOLT_LIMIT.Value = 85000; 
CAL_CHRG_VOLT_LIMIT.DataType='uint32';
CAL_CHRG_VOLT_LIMIT.CoderInfo.StorageClass='Custom';
CAL_CHRG_VOLT_LIMIT.CoderInfo.CustomStorageClass='ExportToFile';
CAL_CHRG_VOLT_LIMIT.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_CHRG_VOLT_LIMIT.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_CHRG_CV_CURRENT_LIMIT
CAL_CHRG_CV_CURRENT_LIMIT =Simulink.Parameter;
CAL_CHRG_CV_CURRENT_LIMIT.Value = 2000; 
CAL_CHRG_CV_CURRENT_LIMIT.DataType='uint32';
CAL_CHRG_CV_CURRENT_LIMIT.CoderInfo.StorageClass='Custom';
CAL_CHRG_CV_CURRENT_LIMIT.CoderInfo.CustomStorageClass='ExportToFile';
CAL_CHRG_CV_CURRENT_LIMIT.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_CHRG_CV_CURRENT_LIMIT.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_CHRG_CC_CURRENT_LIMIT
CAL_CHRG_CC_CURRENT_LIMIT =Simulink.Parameter;
CAL_CHRG_CC_CURRENT_LIMIT.Value = 10000; 
CAL_CHRG_CC_CURRENT_LIMIT.DataType='uint32';
CAL_CHRG_CC_CURRENT_LIMIT.CoderInfo.StorageClass='Custom';
CAL_CHRG_CC_CURRENT_LIMIT.CoderInfo.CustomStorageClass='ExportToFile';
CAL_CHRG_CC_CURRENT_LIMIT.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_CHRG_CC_CURRENT_LIMIT.CoderInfo.CustomAttributes.DefinitionFile='DID.c';


%% STATE OF CHARGE PARAMETER

%CAL_GOLDEN_DC
CAL_GOLDEN_DC =Simulink.Parameter;
CAL_GOLDEN_DC.Value =34000;
CAL_GOLDEN_DC.DataType='uint16';
CAL_GOLDEN_DC.CoderInfo.StorageClass='Custom';
CAL_GOLDEN_DC.CoderInfo.CustomStorageClass='ExportToFile';
CAL_GOLDEN_DC.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_GOLDEN_DC.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_SOH_Enable
CAL_SOH_Enable =Simulink.Parameter;
CAL_SOH_Enable.Value =false;  % true- SOH logic, false- SOH=1
CAL_SOH_Enable.DataType='boolean';
CAL_SOH_Enable.CoderInfo.StorageClass='Custom';
CAL_SOH_Enable.CoderInfo.CustomStorageClass='ExportToFile';
CAL_SOH_Enable.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_SOH_Enable.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_DOD
CAL_DOD =Simulink.Parameter;
CAL_DOD.Value =100;
CAL_DOD.DataType='uint8';
CAL_DOD.CoderInfo.StorageClass='Custom';
CAL_DOD.CoderInfo.CustomStorageClass='ExportToFile';
CAL_DOD.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_DOD.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_DOD_MIN_THRSH
CAL_DOD_MIN_THRSH =Simulink.Parameter;
CAL_DOD_MIN_THRSH.Value =1;
CAL_DOD_MIN_THRSH.DataType='uint8';
CAL_DOD_MIN_THRSH.CoderInfo.StorageClass='Custom';
CAL_DOD_MIN_THRSH.CoderInfo.CustomStorageClass='ExportToFile';
CAL_DOD_MIN_THRSH.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_DOD_MIN_THRSH.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_DOD_MAX_THRSH
CAL_DOD_MAX_THRSH =Simulink.Parameter;
CAL_DOD_MAX_THRSH.Value =99;
CAL_DOD_MAX_THRSH.DataType='uint8';
CAL_DOD_MAX_THRSH.CoderInfo.StorageClass='Custom';
CAL_DOD_MAX_THRSH.CoderInfo.CustomStorageClass='ExportToFile';
CAL_DOD_MAX_THRSH.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_DOD_MAX_THRSH.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_ENABLE_SOC_WARN_20
CAL_ENABLE_SOC_WARN_20 =Simulink.Parameter;
CAL_ENABLE_SOC_WARN_20.Value =true; 
CAL_ENABLE_SOC_WARN_20.DataType='boolean';
CAL_ENABLE_SOC_WARN_20.CoderInfo.StorageClass='Custom';
CAL_ENABLE_SOC_WARN_20.CoderInfo.CustomStorageClass='ExportToFile';
CAL_ENABLE_SOC_WARN_20.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_ENABLE_SOC_WARN_20.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_ENABLE_SOC_WARN_15
CAL_ENABLE_SOC_WARN_15 =Simulink.Parameter;
CAL_ENABLE_SOC_WARN_15.Value =false; 
CAL_ENABLE_SOC_WARN_15.DataType='boolean';
CAL_ENABLE_SOC_WARN_15.CoderInfo.StorageClass='Custom';
CAL_ENABLE_SOC_WARN_15.CoderInfo.CustomStorageClass='ExportToFile';
CAL_ENABLE_SOC_WARN_15.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_ENABLE_SOC_WARN_15.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_DCHRG_END_THRSH
CAL_DCHRG_END_THRSH =Simulink.Parameter;
CAL_DCHRG_END_THRSH.Value =2900; 
CAL_DCHRG_END_THRSH.DataType='uint16';
CAL_DCHRG_END_THRSH.CoderInfo.StorageClass='Custom';
CAL_DCHRG_END_THRSH.CoderInfo.CustomStorageClass='ExportToFile';
CAL_DCHRG_END_THRSH.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_DCHRG_END_THRSH.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_SOC_WRN_THRSH
CAL_SOC_WRN_THRSH =Simulink.Parameter;
CAL_SOC_WRN_THRSH.Value =20; 
CAL_SOC_WRN_THRSH.DataType='uint8';
CAL_SOC_WRN_THRSH.CoderInfo.StorageClass='Custom';
CAL_SOC_WRN_THRSH.CoderInfo.CustomStorageClass='ExportToFile';
CAL_SOC_WRN_THRSH.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_SOC_WRN_THRSH.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_SOC_WRN_RVL_THRSH
CAL_SOC_WRN_RVL_THRSH =Simulink.Parameter;
CAL_SOC_WRN_RVL_THRSH.Value =20; 
CAL_SOC_WRN_RVL_THRSH.DataType='uint8';
CAL_SOC_WRN_RVL_THRSH.CoderInfo.StorageClass='Custom';
CAL_SOC_WRN_RVL_THRSH.CoderInfo.CustomStorageClass='ExportToFile';
CAL_SOC_WRN_RVL_THRSH.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_SOC_WRN_RVL_THRSH.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_15_SOC_WRN_THRSH
CAL_15_SOC_WRN_THRSH =Simulink.Parameter;
CAL_15_SOC_WRN_THRSH.Value =15; 
CAL_15_SOC_WRN_THRSH.DataType='uint8';
CAL_15_SOC_WRN_THRSH.CoderInfo.StorageClass='Custom';
CAL_15_SOC_WRN_THRSH.CoderInfo.CustomStorageClass='ExportToFile';
CAL_15_SOC_WRN_THRSH.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_15_SOC_WRN_THRSH.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_15_SOC_WRN_RVL_THRSH
CAL_15_SOC_WRN_RVL_THRSH =Simulink.Parameter;
CAL_15_SOC_WRN_RVL_THRSH.Value =15; 
CAL_15_SOC_WRN_RVL_THRSH.DataType='uint8';
CAL_15_SOC_WRN_RVL_THRSH.CoderInfo.StorageClass='Custom';
CAL_15_SOC_WRN_RVL_THRSH.CoderInfo.CustomStorageClass='ExportToFile';
CAL_15_SOC_WRN_RVL_THRSH.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_15_SOC_WRN_RVL_THRSH.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_LOW_SOC_THRSH
CAL_LOW_SOC_THRSH =Simulink.Parameter;
CAL_LOW_SOC_THRSH.Value =0; 
CAL_LOW_SOC_THRSH.DataType='uint8';
CAL_LOW_SOC_THRSH.CoderInfo.StorageClass='Custom';
CAL_LOW_SOC_THRSH.CoderInfo.CustomStorageClass='ExportToFile';
CAL_LOW_SOC_THRSH.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_LOW_SOC_THRSH.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_LOW_SOC_RVL_THRSH
CAL_LOW_SOC_RVL_THRSH =Simulink.Parameter;
CAL_LOW_SOC_RVL_THRSH.Value =3; 
CAL_LOW_SOC_RVL_THRSH.DataType='uint8';
CAL_LOW_SOC_RVL_THRSH.CoderInfo.StorageClass='Custom';
CAL_LOW_SOC_RVL_THRSH.CoderInfo.CustomStorageClass='ExportToFile';
CAL_LOW_SOC_RVL_THRSH.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_LOW_SOC_RVL_THRSH.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_NOMINAL_VOLTAGE
CAL_NOMINAL_VOLTAGE =Simulink.Parameter;
CAL_NOMINAL_VOLTAGE.Value =84000; 
CAL_NOMINAL_VOLTAGE.DataType='uint32';
CAL_NOMINAL_VOLTAGE.CoderInfo.StorageClass='Custom';
CAL_NOMINAL_VOLTAGE.CoderInfo.CustomStorageClass='ExportToFile';
CAL_NOMINAL_VOLTAGE.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_NOMINAL_VOLTAGE.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%CAL_GOLDEN_CHARGE
CAL_GOLDEN_CHARGE =Simulink.Parameter;
CAL_GOLDEN_CHARGE.Value =34000;
CAL_GOLDEN_CHARGE.DataType='uint16';
CAL_GOLDEN_CHARGE.CoderInfo.StorageClass='Custom';
CAL_GOLDEN_CHARGE.CoderInfo.CustomStorageClass='ExportToFile';
CAL_GOLDEN_CHARGE.CoderInfo.CustomAttributes.HeaderFile='DID.h';
CAL_GOLDEN_CHARGE.CoderInfo.CustomAttributes.DefinitionFile='DID.c';


%% LOOKUP TABLE CONSTANT

% STATE OF CHARGE
SOC = Simulink.Parameter;
SOC.Value = [0 5 10 20 30 40 50 60 70 80 90 95 100];
SOC.DataType = 'double';
SOC.CoderInfo.StorageClass='Custom';
SOC.CoderInfo.CustomStorageClass='ExportToFile';
SOC.CoderInfo.CustomAttributes.HeaderFile='DID.h';
SOC.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

% TEMPERATURE
TEMP = Simulink.Parameter;
TEMP.Value = [-30 -20 -10 0 10 25 45 50 60 70];
TEMP.DataType = 'double';
TEMP.CoderInfo.StorageClass='Custom';
TEMP.CoderInfo.CustomStorageClass='ExportToFile';
TEMP.CoderInfo.CustomAttributes.HeaderFile='DID.h';
TEMP.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%% REGEN LIMIT

%RegenAllowedTime
RegenAllowedTime =Simulink.Parameter;
RegenAllowedTime.Value =3;
RegenAllowedTime.DataType='double';
RegenAllowedTime.CoderInfo.StorageClass='Custom';
RegenAllowedTime.CoderInfo.CustomStorageClass='ExportToFile';
RegenAllowedTime.CoderInfo.CustomAttributes.HeaderFile='DID.h';
RegenAllowedTime.CoderInfo.CustomAttributes.DefinitionFile='DID.c';
