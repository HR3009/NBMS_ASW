classdef OBC_E < Simulink.IntEnumType
enumeration
Sleep(0)
Wake_Up(1)
end
  methods (Static)
    function retVal = getDefaultValue()
      retVal = OBC_E.Sleep;
    end
  end
end

