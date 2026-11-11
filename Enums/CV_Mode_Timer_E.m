classdef CV_Mode_Timer_E < Simulink.IntEnumType
  enumeration
    Off(0)
    On(1)
    Expired(2)
  end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = CV_Mode_Timer_E.Off;
    end
  end
end 