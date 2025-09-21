//Evan Eisenman 09/21/25
//CIS 265 12555
//Chapter 9 exercise 6
//This program takes a user int a user enter and computes it into a predefined polynomial

#include <stdio.h>//directive to include the standard input output library
#include <math.h>//directive to include the math library used for the pow func in this program

//directive for macros that act as the coeficents and the constant for the polynomial
#define FITH_DEG_CO 3
#define FOURTH_DEG_CO 2
#define THIRD_DEG_CO -5
#define SECOND_DEG_CO -1
#define FIRST_DEG_CO 7
#define POLY_CONST -6


//takes the x value,coeficents, and constant of a 5th degree polynomial and calculates it returns the value as a double
double calc_fith_poly(int polyXval,int Coef5,int Coef4,int Coef3,int Coef2,int Coef1,int poylConst)
{
    //this expresion evlautes the polynomial given the passed in numbers rasing the x value to the correct power
    return ((Coef5*pow(polyXval,5))+(Coef4*pow(polyXval,4))+(Coef3*pow(polyXval,3))+(Coef2*pow(polyXval,2))+(Coef1*polyXval)+poylConst);
}

int main(void)
{
    int userXVal;//var that will store the users input for the x val
    double calculatedVal;//var that will store the calculated value as a double

    printf("Please enter the value of X: ");//ask the user to input the x value
    scanf("%d",&userXVal);//stores the entered value into the correct var
    //function call to our defined fucntion that stores the returned value in the correct var
    calculatedVal = calc_fith_poly(userXVal,FITH_DEG_CO,FOURTH_DEG_CO,THIRD_DEG_CO,SECOND_DEG_CO,FIRST_DEG_CO,POLY_CONST);
    printf("%f \n",calculatedVal);//displays the calculated value to the user
    return 0;
}