//Evan Eisenman 10/12/25
//CIS 265 12555
//Chapter 13 exercise 1
//This program loops through a user input and compares the string entered and finds the smallest and largest string the user entered
//terminates when the user enters a 4 letter word

//directives to inclued the stdio and string standard c libraries 
#include <stdio.h>
#include <string.h>

// macro for the max character length of our strings
#define MAX_STR_LEN 20

//function to read the users input and store into an array based of the books example and my previous work
//takes an array pointer and an length argument
read_string(char *inputArray,int arrayLength)
{
    //declars a var to store the current input and declares and intializes a var to store the length of the useres strig
    char inputChar;
    int charCount = 0;
    
    //loops until the users enters a new line
    while ((inputChar = getchar()) != '\n')
    {
        if (charCount<arrayLength)//checks if the currrent index is in range of the array if it is it will itterate through it and store the current char
        {
            *inputArray = inputChar;
            inputArray ++;
            charCount++;
        }
    }
    //sets the last char in the array to null
    *inputArray = '\0';
    //returns the length of the array
    return charCount;
}

int main(void)
{
    //declares 3 arrays one to store the current input one to store the largest and one to store the smallest
    char inputStr[MAX_STR_LEN+1],smallestStr[MAX_STR_LEN+1],largestStr[MAX_STR_LEN+1];
    int strLen = 0; // var to store the current length of the string
    
    //ask the users to enter a word and stores the length in our var
    //automatically stores it as the largest and smallest as it os the only enterd value
    printf("Enter word: ");
    strLen = read_string(inputStr,MAX_STR_LEN);
    strcpy(smallestStr,inputStr);
    strcpy(largestStr,inputStr);
    
    //if the length of the entered string is not 4 enter an infinte loop that will loop until the user enters a 4 letter word
    if(strLen != 4)
    {
        while (1)
        {
            //ask the users to enter a word and stores the length in our var
            printf("Enter word: ");
            strLen = read_string(inputStr,MAX_STR_LEN);
            //checks if the current input is smaller or larger than the current smallest and largest string
            if(strcmp(inputStr,smallestStr) < 0)
            {
                strcpy(smallestStr,inputStr);
            }
            else if (strcmp(inputStr,largestStr) > 0)
            {   
                strcpy(largestStr,inputStr);
            }
            //checks if the last input length was 4 if it was it breaks the loop
            if(strLen == 4)
            {
                break;
            }
        }       
    }
    //prints the smallest and largest word
    printf("Smallest word: %s\n",smallestStr);
    printf("Largest word : %s\n",largestStr);
    return 0;
}