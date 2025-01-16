		// spec.1
        assert(!((dw.is_Red == IN_DelayState) && (rtDW.is_Red == IN_WaitUntilSafeToChange)));
        // spec.2
		assert(!((dw.is_Red == IN_DelayState) && (rtDW.is_Red == IN_NO_ACTIVE_CHILD)));
        // spec.3
		assert(!((dw.is_Red == IN_DelayState) && (rtDW.is_Red == IN_WaitUntilSafeToChange)));
        // spec.4
		assert(!((dw.is_Red == IN_DelayState) && (rtDW.is_Red == IN_NO_ACTIVE_CHILD)));
        // spec.5
		assert(!((dw.is_Red == IN_WaitForInput) && (rtDW.is_Red == IN_DelayState)));
        // spec.6
		assert(!((dw.is_Red == IN_WaitForInput) && (rtDW.is_Red == IN_NO_ACTIVE_CHILD)));
        // spec.7
		assert(!((dw.is_Red == IN_WaitUntilSafeToChange) && (rtDW.is_Red == IN_DelayState)));
        // spec.8
		assert(!((dw.is_Red == IN_WaitUntilSafeToChange) && (rtDW.is_Red == IN_WaitForInput)));
        // spec.9
		assert(!((dw.is_Red == IN_NO_ACTIVE_CHILD) && (rtDW.is_Red == IN_WaitForInput)));
        // spec.10
		assert(!((dw.is_Red == IN_NO_ACTIVE_CHILD) && (rtDW.is_Red == IN_WaitUntilSafeToChange)));
        // spec.11
		assert(!(dw.is_Red == IN_DelayState && (dw.temporalCounter_i1 >= REDDELAY)) || rtDW.is_Red == IN_WaitForInput);
        // spec.12
		assert(!(dw.is_Red == IN_WaitForInput && !(rtU.numCars <= 0)) || rtDW.is_Red == IN_WaitUntilSafeToChange);
        // spec.13
		assert(!(dw.is_Red == IN_WaitUntilSafeToChange && (dw.temporalCounter_i1 >= REDDELAY)) || rtDW.is_Red == IN_NO_ACTIVE_CHILD);
        // spec.14
		assert(!(dw.is_Red == IN_NO_ACTIVE_CHILD && ((out.LightMode == LightModeType_None) || (!(out.LightMode == LightModeType_None) && (dw.temporalCounter_i1 >= YELLOWDELAY) && !(out.LightMode == LightModeType_Green)))) || rtDW.is_Red == IN_DelayState);
    