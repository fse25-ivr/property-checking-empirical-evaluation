                // spec.1
                assert(!((dw.is_On == IN_NORM) && (rtDW.is_On == IN_HIGH)));
                // spec.2
                assert(!((dw.is_On == IN_NO_ACTIVE_CHILD) && (rtDW.is_On == IN_NORM)));
                // spec.3
                assert(!(dw.is_On == IN_HIGH && (!(20 >= rtU.temp) && (19 > dw.temporalCounter_i1))) || rtDW.is_On == IN_NORM);
                // spec.4
                assert(!(dw.is_On == IN_HIGH && !(19 > dw.temporalCounter_i1)) || rtDW.is_On == IN_NO_ACTIVE_CHILD);
                // spec.5
                assert(!(dw.is_On == IN_NORM && (((20 >= rtU.temp) && !(19 > dw.temporalCounter_i1)) || !(20 >= rtU.temp))) || rtDW.is_On == IN_NO_ACTIVE_CHILD);
                // spec.6
                assert(!(dw.is_On == IN_NO_ACTIVE_CHILD && (!(39 > dw.temporalCounter_i1) && (20 >= rtU.temp))) || rtDW.is_On == IN_HIGH);