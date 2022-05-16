/* *************************
Dyaln Faulk
*CPSC2310 Lab7  
*UserName: faulk
*Lab Section: 001
************************/
#include<stdio.h>
#include <limits.h>


int main()
{
    /*Your code MUST follow the Rules described in the lab document. With the
     *additional restriction that you may not use equality (==) or inequality
     *(!=) test. */
    //This was the given value in the Lab doc that tells us how many bits
    //we have avalable
    int w = sizeof(int) << 3;
    //Part A:  
    printf("1.\n");
    int a = 0;
    printf("prints 1 when any bit of a number equals 1 %d\n",(-(a&-a))>>(w-1)&1 );
    
    a = -13;
    printf("prints 1 when any bit of a number equals 1 %d\n",(-(a&-a))>>(w-1)&1 );
//take complement of b first and use simaler a expression
    //Part B:
    printf("\n2.\n");
    int b = 23;
    printf("prints 1 when any bit of a number equals 0 %d\n",-((((b-INT_MAX)&(b+INT_MAX)))>>(w-1)) ); 
    b = INT_MAX;
    printf("prints 1 when any bit of a number equals 0 %d\n",-((((b-INT_MAX)&(b+INT_MAX)))>>(w-1)) );
    //Part C:
    printf("\n3.\n");
    int c = -12;
    printf("prints 1 when any bit in the least significant byte of c equals 1 %d\n",((((c&-c)-(16))>>(w-1))&((c>>(w-1))-(-c>>(w-1))))&1 );
    c = 12;
    printf("prints 1 when any bit in the least significant byte of c equals 1 %d\n",((((c&-c)-(16))>>(w-1))&((c>>(w-1))-(-c>>(w-1))))&1 );
  
    //Part D;
    printf("\n4.\n");
    int d = 4444;
    printf("prints 1 when any bit in the most significant byte of d equals 0 %d\n", !!(~d&0xff) );
    d = INT_MAX ;
    printf("prints 1 when any bit in the most significant byte of d equals 0 %d\n", !!(~d&0xff) );

        return 0;
}
