classdef BMS_DCDCMosfet_STS_E < Simulink.IntEnumType
enumeration
DCDC_DISCONNECTED(0)
DCDC_CONNECTED(1)
DCDC_MOSFET_FAULT(2)
DCDC_RESERVATION(3)

end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = BMS_DCDCMosfet_STS_E.DCDC_DISCONNECTED;
    end
  end
end