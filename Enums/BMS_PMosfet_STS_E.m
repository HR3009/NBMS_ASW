classdef BMS_PMosfet_STS_E < Simulink.IntEnumType
enumeration
PDISCONNECTED(0)
PCONNECTED(1)
end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = BMS_PMosfet_STS_E.PDISCONNECTED;
    end
  end
end
