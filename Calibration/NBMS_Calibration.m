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


%% REGEN LIMIT

%RegenAllowedTime
RegenAllowedTime =Simulink.Parameter;
RegenAllowedTime.Value =3;
RegenAllowedTime.DataType='double';
RegenAllowedTime.CoderInfo.StorageClass='Custom';
RegenAllowedTime.CoderInfo.CustomStorageClass='ExportToFile';
RegenAllowedTime.CoderInfo.CustomAttributes.HeaderFile='DID.h';
RegenAllowedTime.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%% CURRENT LIMIT LOOKUP TABLE CONSTANT

%DISCHARGE CURRENT LIMIT - 30s Safety(Pack)
    % X_DCL_30sSAFETY_PACK
    X_DCL_30sSAFETY_PACK = Simulink.Parameter;
    X_DCL_30sSAFETY_PACK.Value = [-30; -20; -10; 0; 10; 25; 45; 55; 60; 70;];
    X_DCL_30sSAFETY_PACK.DataType = 'double';
    X_DCL_30sSAFETY_PACK.CoderInfo.StorageClass = 'Custom';
    X_DCL_30sSAFETY_PACK.CoderInfo.CustomStorageClass = 'ExportToFile';
    X_DCL_30sSAFETY_PACK.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    X_DCL_30sSAFETY_PACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

    % Y_DCL_30sSAFETY_PACK
    Y_DCL_30sSAFETY_PACK = Simulink.Parameter;
    Y_DCL_30sSAFETY_PACK.Value = [0 5 10 20 30 40 50 60 70 80 90 95 100];
    Y_DCL_30sSAFETY_PACK.DataType = 'double';
    Y_DCL_30sSAFETY_PACK.CoderInfo.StorageClass = 'Custom';
    Y_DCL_30sSAFETY_PACK.CoderInfo.CustomStorageClass = 'ExportToFile';
    Y_DCL_30sSAFETY_PACK.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    Y_DCL_30sSAFETY_PACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

    % TABLE_DCL_30sSAFETY_PACK
    TABLE_DCL_30sSAFETY_PACK = Simulink.Parameter;
    %                                 0   5  10  20   30   40   50   60   70   80   90   95   100
    TABLE_DCL_30sSAFETY_PACK.Value = [0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0;       % -30
                                      0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0;       % -20
                                      0,  7,  14, 56,  77,  91,  98,  105, 110, 110, 110, 110, 110;     % -10
                                      14, 14, 35, 84,  110, 110, 110, 110, 110, 110, 110, 110, 110;     %   0 
                                      20, 21, 56, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110;     %  10
                                      20, 42, 84, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110;     %  25
                                      20, 42, 84, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110;     %  45
                                      20, 42, 84, 110, 110, 110, 110, 110, 110, 110, 110, 110, 110;     %  55 
                                      20, 35, 52, 98,  110, 110, 110, 110, 110, 110, 110, 110, 110;     %  60 
                                      0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0;];      %  70 
    TABLE_DCL_30sSAFETY_PACK.DataType = 'double';
    TABLE_DCL_30sSAFETY_PACK.CoderInfo.StorageClass = 'Custom';
    TABLE_DCL_30sSAFETY_PACK.CoderInfo.CustomStorageClass = 'ExportToFile';
    TABLE_DCL_30sSAFETY_PACK.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    TABLE_DCL_30sSAFETY_PACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

%DISCHARGE CURRENT LIMIT - Continuous Safety(Pack)
    % X_DCL_CONT_SAFETY_PACK
    X_DCL_CONT_SAFETY_PACK = Simulink.Parameter;
    X_DCL_CONT_SAFETY_PACK.Value = [-30; -20; -10; 0; 10; 25; 45; 55; 60; 70;];
    X_DCL_CONT_SAFETY_PACK.DataType = 'double';
    X_DCL_CONT_SAFETY_PACK.CoderInfo.StorageClass = 'Custom';
    X_DCL_CONT_SAFETY_PACK.CoderInfo.CustomStorageClass = 'ExportToFile';
    X_DCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    X_DCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

    % Y_DCL_CONT_SAFETY_PACK
    Y_DCL_CONT_SAFETY_PACK = Simulink.Parameter;
    Y_DCL_CONT_SAFETY_PACK.Value = [0 5 10 20 30 40 50 60 70 80 90 95 100];
    Y_DCL_CONT_SAFETY_PACK.DataType = 'double';
    Y_DCL_CONT_SAFETY_PACK.CoderInfo.StorageClass = 'Custom';
    Y_DCL_CONT_SAFETY_PACK.CoderInfo.CustomStorageClass = 'ExportToFile';
    Y_DCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    Y_DCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';
  
    % TABLE_DCL_CONT_SAFETY_PACK
    TABLE_DCL_CONT_SAFETY_PACK = Simulink.Parameter;
    %                                   0   5  10  20    30  40  50  60  70  80  90  95  100
    TABLE_DCL_CONT_SAFETY_PACK.Value = [0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,  0;      % -30
                                        0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,  0;      % -20
                                        0,  7,  14, 21,   21, 31, 31, 31, 31, 31, 31, 31, 31;     % -10
                                        14, 14, 35, 52,   52, 52, 52, 52, 52, 52, 52, 52, 52;     %   0 
                                        20, 21, 56, 70,   84, 84, 84, 84, 84, 84, 84, 84, 84;     %  10
                                        20, 42, 42, 70,   90, 90, 90, 90, 90, 90, 90, 90, 90;     %  25
                                        20, 42, 42, 70,   90, 90, 90, 90, 90, 90, 90, 90, 90;     %  45
                                        20, 42, 42, 52.5, 90, 90, 90, 90, 90, 90, 90, 90, 90;     %  55 
                                        20, 28, 35, 35,   35, 35, 35, 35, 35, 35, 35, 35, 35;     %  60 
                                        0,  0,  0,  0,    0,  0,  0,  0,  0,  0,  0,  0,  0;];     %  70 
    TABLE_DCL_CONT_SAFETY_PACK.DataType = 'double';
    TABLE_DCL_CONT_SAFETY_PACK.CoderInfo.StorageClass = 'Custom';
    TABLE_DCL_CONT_SAFETY_PACK.CoderInfo.CustomStorageClass = 'ExportToFile';
    TABLE_DCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    TABLE_DCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';   

%CHARGE CURRENT LIMIT - Continuous Safety(Pack)
    % X_CCL_CONT_SAFETY_PACK
    X_CCL_CONT_SAFETY_PACK = Simulink.Parameter;
    X_CCL_CONT_SAFETY_PACK.Value = [-30; -20; -10; 0; 10; 25; 45; 50; 60;];
    X_CCL_CONT_SAFETY_PACK.DataType = 'double';
    X_CCL_CONT_SAFETY_PACK.CoderInfo.StorageClass = 'Custom';
    X_CCL_CONT_SAFETY_PACK.CoderInfo.CustomStorageClass = 'ExportToFile';
    X_CCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    X_CCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

    % Y_CCL_CONT_SAFETY_PACK
    Y_CCL_CONT_SAFETY_PACK = Simulink.Parameter;
    Y_CCL_CONT_SAFETY_PACK.Value = [0 5 10 20 30 40 50 60 70 80 90 95 100];
    Y_CCL_CONT_SAFETY_PACK.DataType = 'double';
    Y_CCL_CONT_SAFETY_PACK.CoderInfo.StorageClass = 'Custom';
    Y_CCL_CONT_SAFETY_PACK.CoderInfo.CustomStorageClass = 'ExportToFile';
    Y_CCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    Y_CCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

    % TABLE_CCL_CONT_SAFETY_PACK
    TABLE_CCL_CONT_SAFETY_PACK = Simulink.Parameter;
    %                                   0   5  10  20  30  40  50  60  70  80  90  95  100
    TABLE_CCL_CONT_SAFETY_PACK.Value = [0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0;     % -30
                                        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0;     % -20
                                        16, 16, 16, 16, 3,  3,  2,  2,  0,  0,  0,  0, 0;     % -10
                                        16, 16, 16, 16, 7,  7,  4,  4,  3,  3,  2,  0, 0;     %   0 
                                        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 7, 2;     %  10
                                        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 7, 2;     %  25
                                        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 7, 2;     %  45
                                        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 7, 2;     %  50 
                                        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0;];   %  60                             
    TABLE_CCL_CONT_SAFETY_PACK.DataType = 'double';
    TABLE_CCL_CONT_SAFETY_PACK.CoderInfo.StorageClass = 'Custom';
    TABLE_CCL_CONT_SAFETY_PACK.CoderInfo.CustomStorageClass = 'ExportToFile';
    TABLE_CCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    TABLE_CCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';   

%REGEN CURRENT LIMIT - Continuous Safety(Pack-5s)
    % X_RCL_CONT_SAFETY_PACK
    X_RCL_CONT_SAFETY_PACK = Simulink.Parameter;
    X_RCL_CONT_SAFETY_PACK.Value = [-30; -20; -10; 0; 10; 25; 45; 50; 60;];
    X_RCL_CONT_SAFETY_PACK.DataType = 'double';
    X_RCL_CONT_SAFETY_PACK.CoderInfo.StorageClass = 'Custom';
    X_RCL_CONT_SAFETY_PACK.CoderInfo.CustomStorageClass = 'ExportToFile';
    X_RCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    X_RCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

    % Y_RCL_CONT_SAFETY_PACK
    Y_RCL_CONT_SAFETY_PACK = Simulink.Parameter;
    Y_RCL_CONT_SAFETY_PACK.Value = [0 5 10 20 30 40 50 60 70 80 90 95 100];
    Y_RCL_CONT_SAFETY_PACK.DataType = 'double';
    Y_RCL_CONT_SAFETY_PACK.CoderInfo.StorageClass = 'Custom';
    Y_RCL_CONT_SAFETY_PACK.CoderInfo.CustomStorageClass = 'ExportToFile';
    Y_RCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    Y_RCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';

    % TABLE_RCL_CONT_SAFETY_PACK
    TABLE_RCL_CONT_SAFETY_PACK = Simulink.Parameter;
    %                                   0   5  10  20  30  40  50  60  70  80  90  95  100
    TABLE_RCL_CONT_SAFETY_PACK.Value = [0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0;     % -30
                                        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0;     % -20
                                        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0;     % -10
                                        52, 52, 52, 52, 52, 52, 52, 49, 35, 21, 14, 7,  0;     %   0 
                                        52, 52, 52, 52, 52, 52, 52, 52, 49, 35, 21, 17, 2;     %  10
                                        52, 52, 52, 52, 52, 52, 52, 52, 52, 49, 28, 21, 2;     %  25
                                        52, 52, 52, 52, 52, 52, 52, 52, 52, 49, 28, 21, 2;     %  45
                                        52, 52, 52, 52, 52, 52, 52, 52, 52, 49, 28, 21, 2;     %  50 
                                        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0;];   %  60                             
    TABLE_RCL_CONT_SAFETY_PACK.DataType = 'double';
    TABLE_RCL_CONT_SAFETY_PACK.CoderInfo.StorageClass = 'Custom';
    TABLE_RCL_CONT_SAFETY_PACK.CoderInfo.CustomStorageClass = 'ExportToFile';
    TABLE_RCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    TABLE_RCL_CONT_SAFETY_PACK.CoderInfo.CustomAttributes.DefinitionFile='DID.c';   

%% SOC Vs OCV LOOKUP TABLE CONSTANT

%SOC Vs OCV (DISCHARGING)
    % X_SOC_VS_OCV_DISCH 
    X_SOC_VS_OCV_DISCH = Simulink.Parameter;
    X_SOC_VS_OCV_DISCH.Value = [0; 5; 10; 15; 20; 25; 30; 35; 40; 45; 50; 55; 60; 65; 70; 75; 80; 85; 90; 95; 100;];
    X_SOC_VS_OCV_DISCH.DataType = 'double';
    X_SOC_VS_OCV_DISCH.CoderInfo.StorageClass = 'Custom';
    X_SOC_VS_OCV_DISCH.CoderInfo.CustomStorageClass = 'ExportToFile';
    X_SOC_VS_OCV_DISCH.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    X_SOC_VS_OCV_DISCH.CoderInfo.CustomAttributes.DefinitionFile = 'DID.c';

    % Y_SOC_VS_OCV_DISCH 
    Y_SOC_VS_OCV_DISCH = Simulink.Parameter;
    Y_SOC_VS_OCV_DISCH.Value = [-20 -10 0 10 25 45 55];
    Y_SOC_VS_OCV_DISCH.DataType = 'double';
    Y_SOC_VS_OCV_DISCH.CoderInfo.StorageClass = 'Custom';
    Y_SOC_VS_OCV_DISCH.CoderInfo.CustomStorageClass = 'ExportToFile';
    Y_SOC_VS_OCV_DISCH.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    Y_SOC_VS_OCV_DISCH.CoderInfo.CustomAttributes.DefinitionFile = 'DID.c';

    % TABLE_SOC_VS_OCV_DISCH 
    TABLE_SOC_VS_OCV_DISCH = Simulink.Parameter;
    %                                -20     -10       0      10      25      45      55  
    TABLE_SOC_VS_OCV_DISCH.Value = [
                                    2.934,  2.929,  2.920,  2.900,  2.911,  2.903,  2.922;   %   0 
                                    3.148,  3.135,  3.129,  3.118,  3.123,  3.121,  3.133;   %   5 
                                    3.295,  3.294,  3.289,  3.281,  3.272,  3.266,  3.276;   %  10 
                                    3.409,  3.409,  3.405,  3.400,  3.395,  3.386,  3.395;   %  15 
                                    3.450,  3.452,  3.451,  3.451,  3.452,  3.449,  3.452;   %  20 
                                    3.494,  3.501,  3.501,  3.499,  3.499,  3.490,  3.496;   %  25 
                                    3.552,  3.559,  3.558,  3.557,  3.554,  3.546,  3.551;   %  30 
                                    3.597,  3.607,  3.607,  3.606,  3.603,  3.593,  3.598;   %  35 
                                    3.636,  3.640,  3.641,  3.642,  3.642,  3.642,  3.648;   %  40 
                                    3.667,  3.672,  3.674,  3.676,  3.676,  3.679,  3.685;   %  45 
                                    3.708,  3.715,  3.717,  3.718,  3.718,  3.721,  3.727;   %  50 
                                    3.753,  3.756,  3.758,  3.759,  3.763,  3.766,  3.763;   %  55 
                                    3.799,  3.803,  3.805,  3.807,  3.813,  3.812,  3.808;   %  60 
                                    3.868,  3.872,  3.872,  3.870,  3.877,  3.874,  3.866;   %  65 
                                    3.907,  3.909,  3.910,  3.910,  3.912,  3.911,  3.907;   %  70 
                                    3.946,  3.949,  3.950,  3.950,  3.953,  3.952,  3.947;   %  75 
                                    4.006,  4.008,  4.009,  4.009,  4.012,  4.011,  4.005;   %  80
                                    4.057,  4.059,  4.060,  4.060,  4.063,  4.063,  4.059;   %  85 
                                    4.072,  4.075,  4.077,  4.077,  4.080,  4.080,  4.079;   %  90 
                                    4.087,  4.091,  4.093,  4.094,  4.096,  4.096,  4.094;   %  95 
                                    4.185,  4.185,  4.185,  4.185,  4.185,  4.185,  4.185;   % 100 
                                    ];
    TABLE_SOC_VS_OCV_DISCH.DataType = 'double';
    TABLE_SOC_VS_OCV_DISCH.CoderInfo.StorageClass = 'Custom';
    TABLE_SOC_VS_OCV_DISCH.CoderInfo.CustomStorageClass = 'ExportToFile';
    TABLE_SOC_VS_OCV_DISCH.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    TABLE_SOC_VS_OCV_DISCH.CoderInfo.CustomAttributes.DefinitionFile = 'DID.c';


% SOC Vs OCV Table (CHARGING)
    % X_SOC_VS_OCV_CHG 
    X_SOC_VS_OCV_CHG = Simulink.Parameter;
    X_SOC_VS_OCV_CHG.Value = [0; 5; 10; 15; 20; 25; 30; 35; 40; 45; 50; 55; 60; 65; 70; 75; 80; 85; 90; 95; 100;];
    X_SOC_VS_OCV_CHG.DataType = 'double';
    X_SOC_VS_OCV_CHG.CoderInfo.StorageClass = 'Custom';
    X_SOC_VS_OCV_CHG.CoderInfo.CustomStorageClass = 'ExportToFile';
    X_SOC_VS_OCV_CHG.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    X_SOC_VS_OCV_CHG.CoderInfo.CustomAttributes.DefinitionFile = 'DID.c';

    % Y_SOC_VS_OCV_CHG 
    Y_SOC_VS_OCV_CHG = Simulink.Parameter;
    Y_SOC_VS_OCV_CHG.Value = [-20 -10 0 10 25 45 55];
    Y_SOC_VS_OCV_CHG.DataType = 'double';
    Y_SOC_VS_OCV_CHG.CoderInfo.StorageClass = 'Custom';
    Y_SOC_VS_OCV_CHG.CoderInfo.CustomStorageClass = 'ExportToFile';
    Y_SOC_VS_OCV_CHG.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    Y_SOC_VS_OCV_CHG.CoderInfo.CustomAttributes.DefinitionFile = 'DID.c';

    % TABLE_SOC_VS_OCV_CHG
    TABLE_SOC_VS_OCV_CHG = Simulink.Parameter;
    %                              -20     -10       0      10      25      45      55   
    TABLE_SOC_VS_OCV_CHG.Value = [
                                  2.934,  2.929,  2.920,  2.900,  2.911,  2.903,  2.922;    %   0 
                                  3.260,  3.274,  3.271,  3.271,  3.254,  3.238,  3.240;    %   5 
                                  3.387,  3.399,  3.397,  3.397,  3.385,  3.362,  3.363;    %  10 
                                  3.436,  3.442,  3.442,  3.441,  3.439,  3.429,  3.430;    %  15 
                                  3.481,  3.491,  3.491,  3.493,  3.492,  3.479,  3.481;    %  20 
                                  3.538,  3.547,  3.546,  3.547,  3.540,  3.534,  3.534;    %  25 
                                  3.586,  3.592,  3.592,  3.593,  3.589,  3.582,  3.582;    %  30 
                                  3.616,  3.621,  3.622,  3.624,  3.622,  3.622,  3.623;    %  35 
                                  3.644,  3.650,  3.651,  3.653,  3.652,  3.653,  3.656;    %  40 
                                  3.677,  3.683,  3.685,  3.687,  3.686,  3.688,  3.691;    %  45 
                                  3.719,  3.726,  3.727,  3.730,  3.728,  3.731,  3.734;    %  50 
                                  3.766,  3.772,  3.774,  3.777,  3.776,  3.777,  3.780;    %  55 
                                  3.819,  3.837,  3.838,  3.840,  3.835,  3.829,  3.831;    %  60 
                                  3.880,  3.886,  3.886,  3.887,  3.885,  3.883,  3.882;    %  65 
                                  3.913,  3.918,  3.919,  3.920,  3.918,  3.917,  3.917;    %  70 
                                  3.952,  3.958,  3.959,  3.960,  3.958,  3.958,  3.958;    %  75 
                                  4.010,  4.017,  4.017,  4.019,  4.017,  4.016,  4.016;    %  80 
                                  4.061,  4.066,  4.067,  4.068,  4.067,  4.067,  4.067;    %  85 
                                  4.076,  4.080,  4.082,  4.083,  4.083,  4.083,  4.084;    %  90 
                                  4.090,  4.096,  4.098,  4.100,  4.099,  4.098,  4.099;    %  95 
                                  4.185,  4.185,  4.185,  4.185,  4.185,  4.185,  4.185;    % 100 
                                ];
    TABLE_SOC_VS_OCV_CHG.DataType = 'double';
    TABLE_SOC_VS_OCV_CHG.CoderInfo.StorageClass = 'Custom';
    TABLE_SOC_VS_OCV_CHG.CoderInfo.CustomStorageClass = 'ExportToFile';
    TABLE_SOC_VS_OCV_CHG.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    TABLE_SOC_VS_OCV_CHG.CoderInfo.CustomAttributes.DefinitionFile = 'DID.c';

%% DCIR LOOKUP TABLE

% DCIR - DISCHARGE (ohms)
    % X_DCIR_DISCH 
    X_DCIR_DISCH = Simulink.Parameter;
    X_DCIR_DISCH.Value = [-20; -10; 0; 10; 25; 45; 60;];
    X_DCIR_DISCH.DataType = 'double';
    X_DCIR_DISCH.CoderInfo.StorageClass = 'Custom';
    X_DCIR_DISCH.CoderInfo.CustomStorageClass = 'ExportToFile';
    X_DCIR_DISCH.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    X_DCIR_DISCH.CoderInfo.CustomAttributes.DefinitionFile = 'DID.c';

    % Y_DCIR_DISCH 
    Y_DCIR_DISCH = Simulink.Parameter;
    Y_DCIR_DISCH.Value = [0 10 20 30 40 50 60 70 80 90 100];
    Y_DCIR_DISCH.DataType = 'double';
    Y_DCIR_DISCH.CoderInfo.StorageClass = 'Custom';
    Y_DCIR_DISCH.CoderInfo.CustomStorageClass = 'ExportToFile';
    Y_DCIR_DISCH.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    Y_DCIR_DISCH.CoderInfo.CustomAttributes.DefinitionFile = 'DID.c';

    % TABLE_DCIR_DISCH (7x11 Matrix: Temp [BP1] x SOC [BP2])
    TABLE_DCIR_DISCH = Simulink.Parameter;
    %                               0      10      20      30      40      50      60      70      80      90     100   
    TABLE_DCIR_DISCH.Value = [
                                0.4429, 0.4429, 0.1677, 0.1473, 0.1409, 0.1403, 0.1384, 0.1409, 0.1428, 0.1421, 0.1510;   % -20
                                0.2169, 0.2169, 0.0906, 0.0755, 0.0721, 0.0709, 0.0713, 0.0732, 0.0738, 0.0709, 0.0772;   % -10 
                                0.1281, 0.1281, 0.0657, 0.0554, 0.0530, 0.0530, 0.0526, 0.0531, 0.0556, 0.0525, 0.0558;   %   0 
                                0.0808, 0.0808, 0.0453, 0.0396, 0.0389, 0.0387, 0.0385, 0.0396, 0.0407, 0.0380, 0.0417;   %  10 
                                0.1135, 0.0531, 0.0333, 0.0290, 0.0284, 0.0284, 0.0280, 0.0284, 0.0299, 0.0277, 0.0296;   %  25 
                                0.0885, 0.0407, 0.0269, 0.0233, 0.0227, 0.0229, 0.0219, 0.0228, 0.0239, 0.0210, 0.0234;   %  45 
                                0.0860, 0.0373, 0.0250, 0.0221, 0.0220, 0.0218, 0.0207, 0.0214, 0.0224, 0.0195, 0.0220    %  60 
                            ];
    TABLE_DCIR_DISCH.DataType = 'double';
    TABLE_DCIR_DISCH.CoderInfo.StorageClass = 'Custom';
    TABLE_DCIR_DISCH.CoderInfo.CustomStorageClass = 'ExportToFile';
    TABLE_DCIR_DISCH.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    TABLE_DCIR_DISCH.CoderInfo.CustomAttributes.DefinitionFile = 'DID.c';

% DCIR - CHARGE (Ohms)
    % X_DCIR_CHG 
    X_DCIR_CHG = Simulink.Parameter;
    X_DCIR_CHG.Value = [-20; -10; 0; 10; 25; 45; 60;];
    X_DCIR_CHG.DataType = 'double';
    X_DCIR_CHG.CoderInfo.StorageClass = 'Custom';
    X_DCIR_CHG.CoderInfo.CustomStorageClass = 'ExportToFile';
    X_DCIR_CHG.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    X_DCIR_CHG.CoderInfo.CustomAttributes.DefinitionFile = 'DID.c';

    % Y_DCIR_CHG
    Y_DCIR_CHG = Simulink.Parameter;
    Y_DCIR_CHG.Value = [0 10 20 30 40 50 60 70 80 90 100];
    Y_DCIR_CHG.DataType = 'double';
    Y_DCIR_CHG.CoderInfo.StorageClass = 'Custom';
    Y_DCIR_CHG.CoderInfo.CustomStorageClass = 'ExportToFile';
    Y_DCIR_CHG.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    Y_DCIR_CHG.CoderInfo.CustomAttributes.DefinitionFile = 'DID.c';

    % TABLE_DCIR_CHG 
    TABLE_DCIR_CHG = Simulink.Parameter;
    %                             0      10      20      30      40      50      60      70      80      90     100   
    TABLE_DCIR_CHG.Value = [
                               0.1796, 0.1796, 0.1427, 0.2163, 0.2033, 0.2013, 0.2128, 0.2128, 0.2128, 0.2128, 0.2128;   % -20  
                               0.0883, 0.0883, 0.0672, 0.1006, 0.0948, 0.0949, 0.1067, 0.1035, 0.1035, 0.1035, 0.1035;   % -10 
                               0.0742, 0.0742, 0.0579, 0.0531, 0.0482, 0.0485, 0.0584, 0.0576, 0.0631, 0.0631, 0.0631;   %   0 
                               0.0554, 0.0554, 0.0407, 0.0412, 0.0380, 0.0390, 0.0386, 0.0389, 0.0429, 0.0402, 0.0402;   %  10 
                               0.0590, 0.0414, 0.0282, 0.0291, 0.0272, 0.0277, 0.0285, 0.0271, 0.0286, 0.0269, 0.0269;   %  25 
                               0.0479, 0.0358, 0.0221, 0.0233, 0.0215, 0.0217, 0.0218, 0.0212, 0.0220, 0.0195, 0.0195;   %  45 
                               0.0448, 0.0327, 0.0200, 0.0219, 0.0202, 0.0204, 0.0205, 0.0195, 0.0206, 0.0181, 0.0181;   %  60 
                          ];
    TABLE_DCIR_CHG.DataType = 'double';
    TABLE_DCIR_CHG.CoderInfo.StorageClass = 'Custom';
    TABLE_DCIR_CHG.CoderInfo.CustomStorageClass = 'ExportToFile';
    TABLE_DCIR_CHG.CoderInfo.CustomAttributes.HeaderFile = 'DID.h';
    TABLE_DCIR_CHG.CoderInfo.CustomAttributes.DefinitionFile = 'DID.c';
