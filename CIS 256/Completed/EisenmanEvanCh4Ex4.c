//Evan Eisenman 09/09/25
//CIS 265 12555
//Chapter 4 exercise 4
//This program prompts a user to enter a number base 10 and converts it to base 8

#include <stdio.h>//directive to include the standard input output library
#include <ctype.h>//directive to include the ctype library that is used for its toupper func

// this function is passed the user decimal value and converts it to a octal
// this function is not optimal and is only included because it uses only the info given to us in chapters 1-4
void ConvertToOctal(int decNum)
{
    int digit0 = 0,digit1 = 0,digit2 = 0,digit3 = 0,digit4 = 0; //declares and intializes variables for each postion of the octal number
    //does 5 evaluations to calculate the each postional value and 5 evaluations that divide the input number by 8 for the next step
    digit4 = decNum % 8;
    decNum /= 8;
    digit3 = decNum % 8;
    decNum /= 8;
    digit2 = decNum % 8;
    decNum /= 8;
    digit1 = decNum % 8;
    decNum /= 8;
    digit0 = decNum % 8;
    decNum /= 8;
    printf("%d%d%d%d%d",digit0,digit1,digit2,digit3,digit4);//displays the number in octal format by placing each var in the correct order
}

int main(void)
{
    int userInput;//var that will store the users input decimal number
    char userSelection;//var that will be used to determine how the octal number is converted

    printf("Please enter a number to convert between 0 and 32767:");//prompts a user to enter a decimal number at stores the input in a var
    scanf("%d",&userInput);
    printf("Would you like to use the chapter 7 solution(Y|N):");//prompts the user to enter Y or N if they want to use the easy solution this has no real effect on the end user
    scanf("\n%c",&userSelection);
    if(toupper(userSelection)== 'Y')//depending on users last input the program will pick how to convert the decimal number to an octal
    {
        printf("This might not looking any diffrent but trust me it is:%.5o",userInput);//displays a little message to the user and outputs their number converted using printf built in functionality
    }
    else
    {
        ConvertToOctal(userInput);//calls our created function that will return nothing put will display the proper conversion
    }
    return 0;
}