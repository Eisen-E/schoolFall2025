//Evan Eisenman 10/31/25
//CIS 265 12555
//Chapter 14 exercise 6
//This program uses macros to display the value of a funtion call

#include <stdio.h> //directive to include the standard input output library
#include <math.h> //directive to include the math lib that we use for the sqrt and pow func

//macro defined func that we use to display the result of another function that takes one argunment and format its display for the user
#define DISP(f,x) printf(#f"(%g) = %g\n", (x),f((x))) 
//macro defined func that we use to display the result of another function that takes two argunments and format its display for the user
#define DISP2(f,x,y) printf(#f"(%g,%g) = %g\n", (x),(y),f((x),(y)))

int main(void)
{
    //two macro defined functions that display the retunred value from the sqrt and pow function
    DISP(sqrt,9.0);
    DISP2(pow,3.0,2.0);
    
    return 0;
}