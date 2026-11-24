classdef BMS_MODE_E < Simulink.IntEnumType
enumeration
BMS_SNA(0)
BMS_SLEEP(1)
BMS_DISCHARGE(2)
BMS_CHARGE(3)
BMS_STANDBY(4)
BMS_FAULT(5)
BMS_DIAGNOSTIC(6)
end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = BMS_MODE_E.BMS_SNA;
    end
  end
end
