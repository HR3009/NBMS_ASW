classdef BMS_BattTempDerate_E < Simulink.IntEnumType
    enumeration
        No_Derating(0)
        Derating(1)

    end
    methods (Static)
        function retVal = getDefaultValue()
            retVal = BMS_BattTempDerate_E.No_Derating;
        end
    end
end