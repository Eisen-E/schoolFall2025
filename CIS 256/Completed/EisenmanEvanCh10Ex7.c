//Evan Eisenman 11/09/25
//CIS 265 12555
//Chapter 10 exercise 7
//This program converts a users input into a simulated 7 segment display

#include <stdio.h>//directive to include the standard input output library

#define MAX_DIGITS 10 //macro that defines the max digits the program can process
#define ASCII_0_OFFSET 48 //macro for the int value of the ascii 0
#define ASCII_9_OFFSET 57 //macro for the int value of the ascii 9

//two global arrays the segment array represents which segments will be on or off digits holds the actual character array that will be printed
const int segments[10][7] = {{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
char digits [4][MAX_DIGITS*4];

//This function loops through the digits arrays and stores blank space characters in each index
void clear_digits_array(void)
{
    int row,col;//vars that will be used to iterate through the array
    for(row = 0;row<4;row++)
    {
        for(col=0;col<(MAX_DIGITS*4);col++)
        {
            digits[row][col]=' ';//inputs blank space at the current index of the loop
        }
    }
}
//function takes a digit and postion and inserts the 7 digit segegment representation into that postion
void process_digit(int digit,int position)
{
    int positionOffset = position*4;//var for the offset to format the array correctly
    int item;//var that will control the loop through the segemnts gloabal array
    for(item=0;item<7;item++)//loop that will itterate the item var
    {
        if (segments[digit][item])//checks if the current "item" in the array is not 0 if it is not nothing happens
        {
            //switch statment inputs the correct char into the correct postion using an offset of the postion
            switch (item)
            {
            case 0:
                digits[0][(positionOffset+1)] = '_';
                break;
            case 1:
                digits[1][(positionOffset+2)] = '|';
                break;
            case 2:
                digits[2][(positionOffset+2)] = '|';
                break;
            case 3:
                digits[2][(positionOffset+1)] ='_';
                break;
            case 4:
                digits[2][positionOffset]='|';
                break;
            case 5:
                digits[1][positionOffset]='|';
                break;
            case 6:
                digits[1][(positionOffset+1)]='_';
                break;
            }

        }
    }
}
//loops therough the array and prints the char value at the current index
void print_digits_array(void)
{
    int row,col;//vars that will be used to iterate through the array
    for(row = 0;row<4;row++)
    {
        for(col=0;col<(MAX_DIGITS*4);col++)
        {
            printf("%c",digits[row][col]);//prints char value at the current index
        }
        printf("\n");//prints new line char at the end of the row of the array
    }
}

int main(void)
{
    char inputChar;//var that will hold the users input
    int inputCount=0,userIntInput;//input count will store the current ammount of numbers convereted, userIntInput holds the converted char to correct int value
    clear_digits_array();//calls the clear digits function
    printf("Enter a number: ");//ask the user to input a number
    while ((inputChar = getchar()) != '\n')//gets the user input until a new line char is found
    {
        //checks if the currrent index is in range of the array if it is it will itterate through it and store the current char if it a number
        if (inputCount<MAX_DIGITS && inputChar>=ASCII_0_OFFSET && inputChar<=ASCII_9_OFFSET)
        {
            userIntInput = inputChar-ASCII_0_OFFSET;//converts the users input to a int by subtracting the ascii '0' value as an offset
            process_digit(userIntInput,inputCount);//calls the process_digit function
            inputCount++;//increments the inputCount by one
        }
    }
    print_digits_array();//prints the array of chars
    return 0;
}