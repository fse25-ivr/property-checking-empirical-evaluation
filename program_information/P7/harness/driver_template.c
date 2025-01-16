#include <stdio.h>
#include <stddef.h>
#include <stdio.h> 
#include <stdbool.h> 
#include <stdint.h>
#include <stdlib.h>
#include "../model_package/common/rtwtypes.h"
#include "../model_package/common/model.h"
#include <assert.h>

#define input_type int8_T
#define input_1 rtU.DiscEject
#define input_2 rtU.DiscPresent
#define input_3 rtU.DiscInsert
#define input_4 rtU.RadioReq
#define input_5 rtU.CdReq
#define number_input 5

#ifdef CROWN_MODE
#include "crown.h"
#endif

#if (defined CROWN_MODE || defined AFL_BYTE_MODE || defined AFL_TEXT_MODE) && defined LOOP_BND
static int loop_iter = 0 ; 
int loop_term ()
{
        if (LOOP_BND <= loop_iter++)
                return 0 ;

        return 1 ;
}
#endif 

input_type nondet(int i);//UniversalDriver

#ifdef NATIVE_TEXT_MODE
input_type nondet(int i)
{
        input_type d ;
        int r ;
        if (__builtin_types_compatible_p(typeof(input_type), uint8_T))
        {
                r = scanf("%hhu", &d) ;
        }
        else if (__builtin_types_compatible_p(typeof(input_type), int8_T))
        {
                r = scanf("%hhd", &d) ;
        }
        else if (__builtin_types_compatible_p(typeof(input_type), double))
        {
                r = scanf("%le", &d) ;
        }

        if (i == 4)
        {
                if (d < 0 || d > 3)
                { 
                        return 0;
                }
        }
        else if (i == 5)
        {
                if (d < -2 || (d > 1 && d < 3) || d > 5)
                { 
                        return 0;
                }                
        }
        else
        {
                if (d < 0 || d > 1)
                { 
                        return 0;
                }                
        }

        if (r != 1) {
                exit(0) ;
        }
        return d ;
}
#endif

#ifdef NATIVE_BYTE_MODE
input_type nondet(int i)
{
        input_type d ;
        int r ;
        r = fread(&d, 1, sizeof(input_type), stdin);

        if (i == 4)
        {
                if (d < 0 || d > 3)
                { 
                        return 0;
                }
        }
        else if (i == 5)
        {
                if (d < -2 || (d > 1 && d < 3) || d > 5)
                { 
                        return 0;
                }                
        }
        else
        {
                if (d < 0 || d > 1)
                { 
                        return 0;
                }                
        }

        if (r != sizeof(input_type)) {
                exit(0) ;
        }
        return d ;
}
#endif

#ifdef AFL_TEXT_MODE
input_type nondet(int i)
{
        input_type d ;
        int r ;
        if (__builtin_types_compatible_p(typeof(input_type), uint8_T))
        {
                r = scanf("%hhu", &d) ;
        }
        else if (__builtin_types_compatible_p(typeof(input_type), int8_T))
        {
                r = scanf("%hhd", &d) ;
        }
        else if (__builtin_types_compatible_p(typeof(input_type), double))
        {
                r = scanf("%le", &d) ;
        }
        
        if (i == 4)
        {
                if (d < 0 || d > 3)
                { 
                        return 0;
                }
        }
        else if (i == 5)
        {
                if (d < -2 || (d > 1 && d < 3) || d > 5)
                { 
                        return 0;
                }                
        }
        else
        {
                if (d < 0 || d > 1)
                { 
                        return 0;
                }                
        }

        if (r != 1) {
            exit(0) ;
        }
        return d ;
}
#endif

#ifdef AFL_BYTE_MODE
input_type nondet(int i)
{
        input_type d ;
        int r ; 
        r = fread(&d, 1, sizeof(input_type), stdin);

        if (i == 4)
        {
                if (d < 0 || d > 3)
                { 
                        return 0;
                }
        }
        else if (i == 5)
        {
                if (d < -2 || (d > 1 && d < 3) || d > 5)
                { 
                        return 0;
                }                
        }
        else
        {
                if (d < 0 || d > 1)
                { 
                        return 0;
                }                
        }
      
        if (r != sizeof(input_type)) {
            exit(0) ;
        }
        return d ;
}
#endif


#ifdef CROWN_MODE
input_type nondet(int i)
{
        input_type d;

        if (__builtin_types_compatible_p(typeof(input_type), uint8_T))
        {
                SYM_unsigned_char(d) ;
        }
        else if (__builtin_types_compatible_p(typeof(input_type), int8_T))
        {
                SYM_char(d) ;
        }
        else if (__builtin_types_compatible_p(typeof(input_type), double))
        {
                SYM_double(d) ;
        }
        if (i == 4)
        {
                SYM_assume(d >= 0 && d <= 3);
        }
        else if (i == 5)
        {
                SYM_assume((d >= -2 && d <= 1) || (d >= 3 && d <= 5));                
        }
        else
        {
                SYM_assume(d >= 0 && d <= 1);               
        }


        return d ;
}
#endif



ExtU read_input() //UniversalDriver
{
        ExtU rtU ;
        input_1 = nondet(1) ;
        input_2 = nondet(2) ;
        input_3 = nondet(3) ;
        input_4 = nondet(4) ;
        input_5 = nondet(5) ;

        //__CPROVER_assume(input_1 >= 0 && input_1 <= 1);
        //__CPROVER_assume(input_2 >= 0 && input_2 <= 1);
        //__CPROVER_assume(input_3 >= 0 && input_3 <= 1);
        //__CPROVER_assume(input_4 >= 0 && input_4 <= 3);
        //__CPROVER_assume((input_5 >= -2 && input_5 <= 1) || (input_5 >= 3 && input_5 <= 5));

        if (__builtin_types_compatible_p(typeof(input_type), uint8_T) || __builtin_types_compatible_p(typeof(input_type), int8_T))
        {
                printf("ILX, input_type, %d\n", input_1) ;
                printf("ILX, input_type, %d\n", input_2) ;
                printf("ILX, input_type, %d\n", input_3) ;
                printf("ILX, input_type, %d\n", input_4) ;
                printf("ILX, input_type, %d\n", input_5) ;

        }
        else if (__builtin_types_compatible_p(typeof(input_type), double))
        {
                printf("ILX, input_type, %e\n", input_1) ;
        }

        fflush(stdout);
        return rtU ;
} 


int_T main()
{

        model_initialize();
        ExtY out = rtY;
        DW dw = rtDW;
        rtU = read_input();
        model_step();
               
        while(1)
        {
#if defined CROWN_MODE || defined AFL_BYTE_MODE || defined AFL_TEXT_MODE 
                if (loop_term() == 0)
                        break ;
#endif 
                ExtY out = rtY;
                DW dw = rtDW;
                rtU = read_input() ; //UniversalDriver
                model_step();

// SPEC LOCATION //

        
        }
        return 0 ;
}
