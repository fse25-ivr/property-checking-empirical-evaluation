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
#define input_1 rtU.D_mode
#define input_2 rtU.W_mode
#define input_3 rtU.M_mode
#define input_4 rtU.Door_sens
#define input_5 rtU.Win_sens
#define input_6 rtU.Mot_sens
#define input_7 rtU.Alarm_active
#define number_input 7

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
        if (d < 0 || d > 1)
        { 
                return 0;
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
        if (d < 0 || d > 1)
        { 
                return 0;
        }  
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

        if (d < 0 || d > 1)
        { 
                return 0;
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

        if (d < 0 || d > 1)
        { 
                return 0;
        }  

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

        SYM_assume(d >= 0 && d <= 1); 

        return d ;
}
#endif



ExtU read_input() //UniversalDriver
{
        ExtU rtU ;
        input_1 = nondet() ;
        input_2 = nondet() ;
        input_3 = nondet() ;
        input_4 = nondet() ;
        input_5 = nondet() ;
        input_6 = nondet() ;
        input_7 = nondet() ;
        
        // __CPROVER_assume(input_1 >= 0 && input_1 <= 1);
        // __CPROVER_assume(input_2 >= 0 && input_2 <= 1);
        // __CPROVER_assume(input_3 >= 0 && input_3 <= 1);
        // __CPROVER_assume(input_4 >= 0 && input_4 <= 1);
        // __CPROVER_assume(input_5 >= 0 && input_5 <= 1);
        // __CPROVER_assume(input_6 >= 0 && input_6 <= 1);
        // __CPROVER_assume(input_7 >= 0 && input_7 <= 1);        

        if (__builtin_types_compatible_p(typeof(input_type), uint8_T) || __builtin_types_compatible_p(typeof(input_type), int8_T))
        {
                printf("ILX, input_type, %d\n", input_1) ;
                printf("ILX, input_type, %d\n", input_2) ;
                printf("ILX, input_type, %d\n", input_3) ;
                printf("ILX, input_type, %d\n", input_4) ;
                printf("ILX, input_type, %d\n", input_5) ;
                printf("ILX, input_type, %d\n", input_6) ;
                printf("ILX, input_type, %d\n", input_7) ;
        }
        else if (__builtin_types_compatible_p(typeof(input_type), double))
        {
                printf("ILX, input_type, %d\n", input_1) ;
                printf("ILX, input_type, %d\n", input_2) ;
                printf("ILX, input_type, %d\n", input_3) ;
                printf("ILX, input_type, %d\n", input_4) ;
                printf("ILX, input_type, %d\n", input_5) ;
                printf("ILX, input_type, %d\n", input_6) ;
                printf("ILX, input_type, %d\n", input_7) ;
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
