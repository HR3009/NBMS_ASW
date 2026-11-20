classdef BMS_BattSoCDerate_E < Simulink.IntEnumType
    enumeration
        SOC_No_Derating(0)
        SOC_Derating(1)

    end
    methods (Static)
        function retVal = getDefaultValue()
            retVal = BMS_BattSoCDerate_E.SOC_No_Derating;
        end
    end
end