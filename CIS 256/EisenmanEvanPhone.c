//Evan Eisenman 09/02/25
//CIS 265 12555
//Chapter 7 exercise 4

//This program prompts a user to enter an phone number and iterates through it to see if there are any alphabetic characters. 
// and replaces them with the appropriate number
// this program does not take into consideration for lowercase characters as the book allows us to assume all characters are upper

#include <stdio.h> //directive to include the standard input output libary

char ConvertCharToNum(char phoneChar)// function that is passed a char and returns a char converting any alphabetic characters to numbers
{
    //evaluates if the character is alphavetic by checking a range
    if (phoneChar >= 'A' && phoneChar <= 'Z')
    {
        // these if statements check if they are within a range and returns the appropriate number for that letter on a dial pad 
        if(phoneChar <='C')
        {   
            return '2';
        }
        else if(phoneChar <= 'F')
        {
            return '3';
        }
        else if (phoneChar <= 'I')
        {
            return '4';
        }
        else if (phoneChar <= 'L')
        {
            return '5';
        }
        else if (phoneChar <= 'O')
        {
            return '6';
        }
        else if (phoneChar <= 'S')
        {
            return '7';
        }
        else if (phoneChar <= 'V')
        {
            return '8';
        }
        else //at this point we know the alphavetic character can only be 9 so we just return 9 if everything else is false
        {
            return '9';
        }

    }
    return phoneChar;//just returns the orginal character if it was not a alphavetic
}

int main(void)
{
    char ch;//declares our ch variable that will store our current character
    printf("Please enter a phone number to convert(All alphabetics must be capital!): ");//ask the user for a phone number
    while((ch = getchar()) != '\n')// goes through the input characters until there is a line break
    {
        ch = ConvertCharToNum(ch);// stores the returned value of our ConvertCharToNum func to the ch var
        putchar(ch);//prints the current chart to the screen
    }
    return 0;
}