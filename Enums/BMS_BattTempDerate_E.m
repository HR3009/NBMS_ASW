classdef BMS_BattTempDerate_E < Simulink.IntEnumType
    enumeration
        Temp_NoDerating(0)
        Temp_Derating(1)

    end
    methods (Static)
        function retVal = getDefaultValue()
            retVal = BMS_BattTempDerate_E.Temp_NoDerating;
        end
    end
end