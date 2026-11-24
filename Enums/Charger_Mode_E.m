classdef Charger_Mode_E < Simulink.IntEnumType
  enumeration
    OFF(0)
    OBC_Standby(1)
    Precharge(2)
    Charging(3)
    Derating(4)
    Error(5)
    ChgMode_Reserved(6)
    Reserved(7)
  end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = Charger_Mode_E.OFF;
    end
  end
end 