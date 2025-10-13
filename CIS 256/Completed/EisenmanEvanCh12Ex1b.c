//Evan Eisenman 10/04/25
//CIS 265 12555
//Chapter 12 exercise 1B
//Takes the users input and displays it to them backwards


#include <stdio.h>//directive to include the standard input output library

#define Array_Len 50//macro that sets the max length the input of the char array

//func that takes an array pointer and the max length of the array and fills it with the users input
//returns the amount of characters the user entered as a int
int fill_array(char *inputArray,int arrayLength)
{
    char *arrayEnd = inputArray+(arrayLength-1);//declares and intializes a pointer to the end of the array
    char inputChar;//declares and char var we will use to work with the user input char
    int realLength = 1;//int var we use to increment based of the amount of characters the user entered
    
    printf("Enter a message: ");
    //loops until the user enters a line break or the array is filled
    while ((inputChar = getchar()) != '\n' && inputArray <= arrayEnd)
    {
        *inputArray = inputChar;//stores the users input char at the index the pointer is currently pointing to
        inputArray++;//increments the pointer
        realLength++;//increments our var for the input length
    }
    return realLength;//returns the length of the user input
}

//func that will take an char array pointer and a length and print the reverse
void print_reverse_array(char *inputArray,int arrayLength)
{
    char *arrayEnd = inputArray+(arrayLength-1);//sets a pointer to the end of the array

    printf("Reversal is: ");
    //loops and evalutes the postion of pointer that was pointing to the end of the array
    while(arrayEnd >= inputArray)
    {
        printf("%c",*arrayEnd);//prints the current character at the pointer that is moving backwards
        arrayEnd--;//decrements the end pointer
    }
}

int main(void)
{
    char inputArray[Array_Len] = {0};//declares our input array and intalizes all its values to 0
    int realArrayLength = 0;//var that will store the length of the user input char array
    
    realArrayLength = fill_array(&inputArray[0],Array_Len);//func call that is passed our array pointer and the constant we defined as the max length and returns the length of the users string
    print_reverse_array(&inputArray[0],realArrayLength);//func call that is passed our array pointer and our var that defines the users string length and prints the string in reverse
    
    
    return 0;
}