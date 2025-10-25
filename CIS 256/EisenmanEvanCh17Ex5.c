//Evan Eisenman 10/04/25
//CIS 265 12555
//Chapter 17 exercise 5
//Ask a user to enter a series of words and stops when the user enters an empty string then sorts the enterend words alphabetically

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20
#define MAX_WORDS 50

//function to read the users input and store into an array(strign) based of the books example and my previous work
//takes an array pointer and an length argument
int read_string(char *inputArray,int arrayLength)
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
int compare_strings(const void *element1, const void *element2)
{
    return strcmp(*(char **)element1,*(char **)element2);
}

int main(void)
{
    char inputString[MAX_STR_LEN+1];
    char * wordList[MAX_WORDS]={NULL};
    char * dynaString;
    int wordCount = 0,inputCharCount=0;
    
    printf("Enter a word: ");
    while (wordCount < MAX_WORDS && (inputCharCount = read_string(&inputString[0],MAX_STR_LEN+1)))
    {
        if((dynaString = malloc(inputCharCount+1))==NULL)
        {
            printf("Error:malloc returned a null pointer");
            exit(EXIT_FAILURE);
        }
        strcpy(dynaString,inputString);
        
        wordList[wordCount]=dynaString;
        
        wordCount ++;
        
        if (wordCount<MAX_WORDS)
        {
            printf("Enter a word: ");
        }
    }
    qsort(wordList,wordCount,sizeof(char*),compare_strings);
    wordCount = 0;
    printf("Sorted Order\n");
    while (wordCount < MAX_WORDS && wordList[wordCount] != NULL)
    {
        printf("%d: %s\n",wordCount+1,wordList[wordCount]);
        wordCount ++;
    }
    
    return 0;
}