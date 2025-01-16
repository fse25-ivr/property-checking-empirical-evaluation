                // spec.1
                assert(!((dw.is_c1_model == IN_s0) && (rtDW.is_c1_model == IN_s12)));
                // spec.2
                assert(!((dw.is_c1_model == IN_s0) && (rtDW.is_c1_model == IN_s121)));
                // spec.3
                assert(!((dw.is_c1_model == IN_s0) && (rtDW.is_c1_model == IN_s1213)));
                // spec.4
                assert(!((dw.is_c1_model == IN_s1) && (rtDW.is_c1_model == IN_s121)));
                // spec.5
                assert(!((dw.is_c1_model == IN_s1) && (rtDW.is_c1_model == IN_s1213)));
                // spec.6
                assert(!((dw.is_c1_model == IN_s12) && (rtDW.is_c1_model == IN_s1)));
                // spec.7
                assert(!((dw.is_c1_model == IN_s12) && (rtDW.is_c1_model == IN_s1213)));
                // spec.8
                assert(!((dw.is_c1_model == IN_s1213) && (rtDW.is_c1_model == IN_s12)));
                // spec.9
                assert(!((dw.is_c1_model == IN_s1213) && (rtDW.is_c1_model == IN_s121)));
                // spec.10
                assert(!(dw.is_c1_model == IN_s0 && (rtU.u == 1)) || rtDW.is_c1_model == IN_s1);
                // spec.11
                assert(!(dw.is_c1_model == IN_s1 && (rtU.u == 2)) || rtDW.is_c1_model == IN_s12);
                // spec.12
                assert(!(dw.is_c1_model == IN_s1 && (!(rtU.u == 2) && !(rtU.u == 1))) || rtDW.is_c1_model == IN_s0);
                // spec.13
                assert(!(dw.is_c1_model == IN_s12 && !(rtU.u == 1)) || rtDW.is_c1_model == IN_s0);
                // spec.14
                assert(!(dw.is_c1_model == IN_s12 && (rtU.u == 1)) || rtDW.is_c1_model == IN_s121);
                // spec.15
                assert(!(dw.is_c1_model == IN_s121 && (rtU.u == 1)) || rtDW.is_c1_model == IN_s1);
                // spec.16
                assert(!(dw.is_c1_model == IN_s121 && (rtU.u == 2)) || rtDW.is_c1_model == IN_s12);
                // spec.17
                assert(!(dw.is_c1_model == IN_s121 && ((rtU.u == 0) || (!(rtU.u == 0) && !(rtU.u == 1) && !(rtU.u == 3) && !(rtU.u == 2)))) || rtDW.is_c1_model == IN_s0);
                // spec.18
                assert(!(dw.is_c1_model == IN_s121 && (rtU.u == 3)) || rtDW.is_c1_model == IN_s1213);
                // spec.19
                assert(!(dw.is_c1_model == IN_s1213 && (rtU.u == 1)) || rtDW.is_c1_model == IN_s1);
                // spec.20
                assert(!(dw.is_c1_model == IN_s1213 && !(rtU.u == 1)) || rtDW.is_c1_model == IN_s0);
