classdef BMS_HVMosfet_STS_E < Simulink.IntEnumType
enumeration
HV_DISCONNECTED(0)
HV_DISCONNECT_PENDING(1)
HV_CONNECTED(2)
HV_CONNECT_PENDING(3)
HV_MOSFET_FAULT(4)
HV_RESERVATION(5)
end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = BMS_HVMosfet_STS_E.HV_DISCONNECTED;
    end
  end
end
