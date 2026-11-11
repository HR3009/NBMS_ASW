classdef Charger_Mode_Req_E < Simulink.IntEnumType
  enumeration
    Disabled(0)
    CC_Start(1)
    CV(2)
    Charge_Complete(3)
    CC_End(4)
    Standby(5)
  end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = Charger_Mode_Req_E.Disabled;
    end
  end
end 