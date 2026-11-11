classdef Regen_Command < Simulink.IntEnumType
    enumeration
    NotActive(0)
    COAST_REGEN(1)
    COAST_FORCED_REGEN(2)
    COAST_BRAKE_REGEN(3)
    COAST_FORCED_BRAKE_REGEN(4)
    end
    methods (Static)
        function retVal = getDefaultValue()
            retVal = Regen_Command.NotActive;
        end
    end
end


