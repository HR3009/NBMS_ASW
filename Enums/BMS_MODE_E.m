classdef BMS_MODE_E < Simulink.IntEnumType
enumeration
BMS_SLEEP(0)
BMS_DISCHARGE(1)
BMS_CHARGE(2)
BMS_STANDBY(3)
BMS_FAULT(4)
end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = BMS_MODE_E.BMS_SLEEP;
    end
  end
end
