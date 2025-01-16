#include <stdio.h>
#include <stddef.h>
#include <stdio.h> 
#include <stdbool.h> 
#include <stdint.h>
#include <stdlib.h>
#include "../model_package/common/rtwtypes.h"
#include "../model_package/common/model.h"
#include <assert.h>

#define input_type uint8_T
#define input_1 rtU.u
#define number_input 1

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

input_type nondet(); ; //UniversalDriver

#ifdef NATIVE_TEXT_MODE
input_type nondet()
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
        if (r != 1) {
                exit(0) ;
        }
        return d ;
}
#endif

#ifdef NATIVE_BYTE_MODE
input_type nondet()
{
        input_type d ;
        int r ;
        r = fread(&d, 1, sizeof(input_type), stdin);
        if (r != sizeof(input_type)) {
                exit(0) ;
        }
        return d ;
}
#endif

#ifdef AFL_TEXT_MODE
input_type nondet()
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
        if (r != 1) {
            exit(0) ;
        }
        return d ;
}
#endif

#ifdef AFL_BYTE_MODE
input_type nondet()
{
        input_type d ;
        int r ; 
        r = fread(&d, 1, sizeof(input_type), stdin);       
        if (r != sizeof(input_type)) {
            exit(0) ;
        }
        return d ;
}
#endif


#ifdef CROWN_MODE
input_type nondet()
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

        return d ;
}
#endif



ExtU read_input() //UniversalDriver
{
        ExtU rtU ;
        input_1 = nondet() ;
        if (__builtin_types_compatible_p(typeof(input_type), uint8_T) || __builtin_types_compatible_p(typeof(input_type), int8_T))
        {
                printf("ILX, input_type, %d\n", input_1) ;
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
