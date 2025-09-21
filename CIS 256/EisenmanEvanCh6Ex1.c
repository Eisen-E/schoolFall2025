//Evan Eisenman 09/17/25
//CIS 265 12555
//Chapter 6 exercise 1
//This program loops until the user enters 0 and display the highest user value entered

#include <stdio.h>//directive to include the standard input output library
#include <stdbool.h>//directive to include the standard bool library

bool loopContinue = true; //bool that will be used to contol our input loop
float userInput = 0,highestNum = 0; //two floats that are intialized and declared used for storing the user input and  the largest entered number
int main(void)
{
    while(loopContinue) //loop will continue if the bool is true
    {
        printf("Enter a number: ");//prompts user to enter a number and stores the value entered into the userInput var
        scanf("%f",&userInput);
        
        if(userInput > 0)//checks if the user entered a value greater than 0
        {
            if (highestNum < userInput) //checks if the last input number is larger than the last stored and stores or discards the value appropriatly
            {
                highestNum = userInput;
            }
        }
        else if (userInput == 0) //checks if the user input is 0 if it is loop flag is changed and the program will exit the loop
        {
            loopContinue = false;
        }
        else // if the user did not enter a number bigger than zero or zero we know the entered a neg and we ask them to not do that and repeat the loop
        {
            printf("Please only enter non-negative numbers\n");
        }
    }
    //displays the largest number entered to the user
    printf("The highest number entered was : %f",highestNum);
}