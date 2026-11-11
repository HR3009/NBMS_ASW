classdef Charger_Mode_E < Simulink.IntEnumType
  enumeration
    OFF(0)
    OBC_Standby(1)
    Precharge(2)
    Charging(3)
    PCBTempDerating(4)
    FETTempDerating(5)
    IPVoltDerating(6)
    Error(7)
  end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = Charger_Mode_E.OFF;
    end
  end
end 