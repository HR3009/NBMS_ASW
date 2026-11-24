classdef BMS_BattSoCDerate_E < Simulink.IntEnumType
    enumeration
        SOC_NoDerating(0)
        SOC_Derating(1)

    end
    methods (Static)
        function retVal = getDefaultValue()
            retVal = BMS_BattSoCDerate_E.SOC_NoDerating;
        end
    end
end