                // spec.1
                assert(!((dw.is_c4_model == IN_ON_TO_OFF) && (rtDW.is_c4_model == IN_OFF_TO_ON)));
                // spec.2
                assert(!((dw.is_c4_model == IN_ON) && (rtDW.is_c4_model == IN_OFF)));
                // spec.3
                assert(!((dw.is_c4_model == IN_ON) && (rtDW.is_c4_model == IN_OFF_TO_ON)));
                // spec.4
                assert(!((dw.is_c4_model == IN_OFF) && (rtDW.is_c4_model == IN_ON_TO_OFF)));
                // spec.5
                assert(!((dw.is_c4_model == IN_OFF) && (rtDW.is_c4_model == IN_ON)));
                // spec.6
                assert(!((dw.is_c4_model == IN_OFF_TO_ON) && (rtDW.is_c4_model == IN_ON_TO_OFF)));
                // spec.7
                assert(!(dw.is_c4_model == IN_ON_TO_OFF && (!(rtU.u == 0) && (9 > dw.temporalCounter_i1))) || rtDW.is_c4_model == IN_ON);
                // spec.8
                assert(!(dw.is_c4_model == IN_ON_TO_OFF && !(9 > dw.temporalCounter_i1)) || rtDW.is_c4_model == IN_OFF);
                // spec.9
                assert(!(dw.is_c4_model == IN_ON && (rtU.u == 0)) || rtDW.is_c4_model == IN_ON_TO_OFF);
                // spec.10
                assert(!(dw.is_c4_model == IN_OFF && !(rtU.u == 0)) || rtDW.is_c4_model == IN_OFF_TO_ON);
                // spec.11
                assert(!(dw.is_c4_model == IN_OFF_TO_ON && (!(rtU.u == 1) && (9 > dw.temporalCounter_i1))) || rtDW.is_c4_model == IN_OFF);
                // spec.12
                assert(!(dw.is_c4_model == IN_OFF_TO_ON && !(9 > dw.temporalCounter_i1)) || rtDW.is_c4_model == IN_ON);