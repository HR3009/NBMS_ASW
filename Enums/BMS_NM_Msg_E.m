classdef BMS_NM_Msg_E < Simulink.IntEnumType
  enumeration
    SLEEP(0)
    ACTIVE(1)
  end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = BMS_NM_Msg_E.SLEEP;
    end
  end
end 