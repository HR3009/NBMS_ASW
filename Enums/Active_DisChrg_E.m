classdef Active_DisChrg_E < Simulink.IntEnumType
    enumeration
        Inactive(0)
        InProgress(1)
        Completed(2)
        Invalid(3)
    end
    methods (Static)
        function retVal = getDefaultValue()
            retVal = Active_DisChrg_E.Inactive;
        end
    end
end
