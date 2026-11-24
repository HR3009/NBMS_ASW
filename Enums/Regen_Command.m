classdef Regen_Command < Simulink.IntEnumType
    enumeration
    NO_REGEN(0)
    COAST_REGEN(1)
    BRAKE_REGEN(2)
    REGEN_RESERVATION(3)
    REG_RESERVATION(4)
    end
    methods (Static)
        function retVal = getDefaultValue()
            retVal = Regen_Command.NO_REGEN;
        end
    end
end


