/*  *************************
 *Dyaln Faulk
 *CPSC2310 Lab7
 *UserName: faulk
 *Lab Section: 001
 *************************/

#include "functions.h"

/*You are going to write a function that returns 1 when ran on a machine that uses
 arithmetic right shifts for data type int and yields 0 otherwise.
 FYI – I tested the solution on the SoC servers on a joey machine so you can assume
 that these machines use arithmetic right shifts. This will be useful when testing
 your algorithm.
You are to implement the  isArithmetic() function.  You are not allowed to
 change the prototype of the function. You will receive a 0 for this task if you
 change the prototype.
 */

int isArithmetic()
{
    //size of bit
    int w = sizeof(int) << 3;

    int test =  -1;
    int testZero = 1;
    
    //if the system is arithmetic then -1 shift will not be the same as 
    //the 0 extention carried out by 1
    return (test >> w-1) != (testZero >> w-1);
}

/*For this problem you must follow the Bit-Level Rules listed above.
 If you violate any of these Rules you will receive a 0 on this task.
You are going to write a function that returns 1 if any of the odd bits
 in an unsigned int equal one. As an example, the bit pattern 0100 0000
 has a one in the 2nd bit position so this would return 0.
 However, bit pattern 1000 0000 has a 1 in bit position 1 therefore it
 will return 1.
You are to implement the isOddOne function.  You are not allowed to
 change the prototype of the function. You will receive a 0 for this
 task if you change the prototype.
 */

int isOddOne(unsigned int x)
{ //just shift down and see if it1 then or it all
     return(((x>>(7))&1) | ((x>>(5))&1) | ((x>>(3))&1) | ((x>>(1))&1)) ; 
}

