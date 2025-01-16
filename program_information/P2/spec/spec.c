                // spec.1
                assert(!(dw.is_c1_model == IN_got_0 && ((2 >= rtU.coin) && !(1 >= rtU.coin))) || rtDW.is_c1_model == IN_got_dime);
                // spec.2
                assert(!(dw.is_c1_model == IN_got_0 && ((1 >= rtU.coin) && !(1 > rtU.coin))) || rtDW.is_c1_model == IN_got_nickel);
                // spec.3
                assert(!(dw.is_c1_model == IN_got_dime && ((1 >= rtU.coin) && !(1 > rtU.coin))) || rtDW.is_c1_model == IN_got_0);
                // spec.4
                assert(!(dw.is_c1_model == IN_got_dime && ((2 >= rtU.coin) && !(1 >= rtU.coin))) || rtDW.is_c1_model == IN_got_nickel);
                // spec.5
                assert(!(dw.is_c1_model == IN_got_nickel && ((1 >= rtU.coin) && !(1 > rtU.coin))) || rtDW.is_c1_model == IN_got_dime);
                // spec.6
                assert(!(dw.is_c1_model == IN_got_nickel && ((2 >= rtU.coin) && !(1 >= rtU.coin))) || rtDW.is_c1_model == IN_got_0);
                