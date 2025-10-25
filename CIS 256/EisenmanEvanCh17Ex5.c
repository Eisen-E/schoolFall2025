//Evan Eisenman 10/04/25
//CIS 265 12555
//Chapter 17 exercise 5
//Ask a user to enter a series of words and stops when the user enters an empty string then sorts the enterend words alphabetically

//directives to include the standard input output, standard libary,and string libary so we can use functions from them
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//two macros that define both the max length of a string and the max strings we can store
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
//comparison function to pass to q sort
int compare_strings(const void *element1, const void *element2)
{
    return strcmp(*(char **)element1,*(char **)element2);//derefrences the pointer to a pointer and calls and string comparison function and passes that value back to qsort
}

int main(void)
{
    char inputString[MAX_STR_LEN+1];//string that will hold the users input
    char * wordList[MAX_WORDS]={NULL};//array that will store pointers to strings
    char * dynaString;//character pointer that will hold the dynamic string
    int wordCount = 0,inputCharCount=0;//int var that will hold the ammount of characters entered by the user and the ammount of total words
    
    //prompts user to enter a word and loops until they hit the max # of words or enter a empty string
    printf("Enter a word: ");
    while (wordCount < MAX_WORDS && (inputCharCount = read_string(&inputString[0],MAX_STR_LEN+1)))
    {
        if((dynaString = malloc(inputCharCount+1))==NULL)//checks if malloc returned null and exist if it did
        {
            printf("Error:malloc returned a null pointer");
            exit(EXIT_FAILURE);
        }
        strcpy(dynaString,inputString);//copys the string from the user into the dynamic string
        
        wordList[wordCount]=dynaString;//stores the pointer of the dynamic stromg into our word list array
        
        wordCount ++;//itterates the word count one more
        
        if (wordCount<MAX_WORDS)//checks if we are on the last item of the array if we arent we ask the user to enter another word
        {
            printf("Enter a word: ");
        }
    }
    qsort(wordList,wordCount,sizeof(char*),compare_strings);//calls qsort passing our array and the ammount of words we entred into it with the size of the char pointer and pass the pointer to our compare_strings func
    wordCount = 0;//sets word count back to zero so we can loop throug it
    printf("Sorted Order\n");
    while (wordCount < MAX_WORDS && wordList[wordCount] != NULL)//loops through the range of the array until the first null pointer prints the value at each index which are now sorted
    {
        printf("%d: %s\n",wordCount+1,wordList[wordCount]);
        wordCount ++;
    }
    
    return 0;
}