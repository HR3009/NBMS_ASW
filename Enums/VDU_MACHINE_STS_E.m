classdef VDU_MACHINE_STS_E < Simulink.IntEnumType
enumeration 
    SNA(0)
    VDU_SLEEP(1)
    POWER_ON(2)
    IDLE(3)
    DRIVE(4)
    FAULT(5)
    DERATE(6)
    
end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = VDU_MACHINE_STS_E.SNA;
    end
  end
end


