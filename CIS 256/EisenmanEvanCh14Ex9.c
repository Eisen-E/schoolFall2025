//Evan Eisenman 10/31/25
//CIS 265 12555
//Chapter 14 exercise 9
//This program uses macros to display the value of a funtion call

#include <stdio.h> //directive to include the standard input output library
#include <math.h> //directive to include the math lib that we use for pow func

#define PROMPT "[3]Check\n[2]Median\n[1]Polynomial[0]\nPlease enter selection number: "

#define CHECK(x,y,n) (((x) >= 0 && x <= (n-1))&&((y) >= 0 && y <= (n-1)))

#define MEDIAN(x,y,z) ((((x)>(y))!= ((x)>(z)))?(x):(((y)<(x))!=((y)<(z)))?(y):(z))

#define POLYNOMIAL(x) ((3.0*pow(x,5.0))+(2.0*pow(x,4.0))-(5.0*pow(x,3.0))-(pow(x,2.0))+(7.0*(x))-6)

int main(void)
{
   int userSelection,UserIntX,userIntY,userIntN;
   double userDoubleVal;
    
   printf(PROMPT);
   scanf(" %d",&userSelection);
   
   while(userSelection!=0)
   {
    if(userSelection == 3)
    {
        
        printf("%d\n",CHECK(70,45,46));
    }
    else if (userSelection== 2)
    {
        /* code */
    }
    else if (userSelection == 1)
    {
        /* code */
    }
    else
    {
        printf("Not a valid selction please try again");
    }
    printf(PROMPT);
    scanf(" %d",&userSelection);
   }
    
    
    
    
    
    //printf("%d\n",CHECK(70,45,46));
    //printf("%d\n",MEDIAN(74,35,36));
    //printf("%g\n",POLYNOMIAL(10.00));
    return 0;
}