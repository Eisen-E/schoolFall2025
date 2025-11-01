//Evan Eisenman 10/31/25
//CIS 265 12555
//Chapter 14 exercise 9
//This program uses macros to display the value of a funtion call

#include <stdio.h> //directive to include the standard input output library
#include <math.h> //directive to include the math lib that we use for pow func

#define PROMPT "[3]Check\n[2]Median\n[1]Polynomial[0]Exit program\nPlease enter selection number: " //macro for our prompt string that will display to the user each loop

#define CHECK(x,y,n) (((x) >= 0 && x <= (n-1))&&((y) >= 0 && y <= (n-1))) //macro defined function that checks that x and y are between 0 and n-1

#define MEDIAN(x,y,z) ((((x)>(y))!= ((x)>(z)))?(x):(((y)<(x))!=((y)<(z)))?(y):(z)) //macro defined function that finds the median value

#define POLYNOMIAL(x) ((3.0*pow(x,5.0))+(2.0*pow(x,4.0))-(5.0*pow(x,3.0))-(pow(x,2.0))+(7.0*(x))-6)//macro defined function that evaluates a set polynomial for x

#define EASTEREGG ((('e')+('g')+('g')+29)/8) //little macro that evaluates to 42 for a little easter egg

int main(void)
{
   int userSelection,userIntX,userIntY,userIntZ,userIntN;//declares 5 variables to store the users input 
   double userDoubleVal;//declares a var that will will store the users input as a double so we dont have to cast for the pow function
    
   printf(PROMPT);//displays macro prompt to user
   scanf(" %d",&userSelection);//stores user input into the selection var
   
   while(userSelection!=0)
   {
    if(userSelection == 3)//if user input is three we prompt the user to enter for 3 vars and evlaute the CHECK macro function
    {
        printf("Checks if your x and y inputs are in the range 0-(n input-1)\nPlease enter you X value: ");
        scanf(" %d",&userIntX);
        printf("Please enter you Y value: ");
        scanf(" %d",&userIntY);
        printf("Please enter you N value: ");
        scanf(" %d",&userIntN);
        printf("%d\n",CHECK(userIntX,userIntY,userIntN));
    }
    else if (userSelection== 2)//if user input is two we prompt the user to enter for 3 vars and evlaute the MEDIAN macro function
    {
        printf("Finds the median of your three inputs\nPlease enter you first value: ");
        scanf(" %d",&userIntX);
        printf("Please enter you second value: ");
        scanf(" %d",&userIntY);
        printf("Please enter you final value: ");
        scanf(" %d",&userIntZ);
        printf("%d\n",MEDIAN(userIntX,userIntY,userIntZ));
    }
    else if (userSelection == 1)//if user input is 1 we prompt the user to enter for 1 var and evlaute the Polynomial macro function
    {
        printf("Evaluates the polynomial 3x^5+2x^4-5x^3-x^2+7x-6 where x is an user input\nPlease enter the value of x: ");
        scanf(" %lf",&userDoubleVal);
        printf("%g\n",POLYNOMIAL(userDoubleVal));
    }
    else if (userSelection == (EASTEREGG))//if the user input is equal to the easter egg (42) we display a quote
    {
        printf("The Answer to the Great Question... Of Life, the Universe and Everything... Is... Forty-two,' said Deep Thought, with infinite majesty and calm.\n");
    }
    else//the value the user entered was not in the list so we ask for them to enter it agian 
    {
        printf("Not a valid selction please try again");
    }
    printf(PROMPT);//displays macro prompt to user
    scanf(" %d",&userSelection);//stores user input into the selection var
   }
   //when the user enter 0 for their selection the loop will exit and we display exciting and return 0
    printf("Exiting");
    return 0;
}