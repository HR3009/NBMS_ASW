classdef VEH_STT_LVL1_E < Simulink.IntEnumType
enumeration 
    VL1_SNA(0)
    VEH_SLEEP(1)
    AWAKE(2)
    STANDBY(3)
    DRIVE(4)
    CHARGE(5)
    
end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = VEH_STT_LVL1_E.VEH_SLEEP;
    end
  end
end


