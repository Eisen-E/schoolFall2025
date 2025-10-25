//Evan Eisenman 10/19/25
//CIS 265 12555
//C programming IO File project- Assignment
//This program prompts a user with a menu to select from 3 diffrent actions to preform

//directives to inclued the stdio and string standard c libraries 
#include <stdio.h>
#include <string.h>

//two macros that will be used for our file path and max length constants
#define FILE_PATH "CIS265.txt"
#define MAX_WORD_LEN 200


int search_file()//this function searches the file designated file for a user selected word
{
    FILE *fp; //declarations of our filepath pointer for the text file stream
    char searchWord[MAX_WORD_LEN+1],inputString[MAX_WORD_LEN+1];//declaration for two strings one the user will input to find the other will be the current string in the file buffer
    int wordCounter = 0;//declaration and initalization of a var that will store the ammount of instances of a word we find
    
    //opens the file stream in read only mode and checks if it oppend properaly if it did not it this func returns -1
    fp = fopen(FILE_PATH,"r");
    if (fp == NULL)
    {
        return -1;
    }
    
    //ask the user to enter a word they want to search for and stores it in the searchWord array
    printf("Please enter a word to search for: ");
    scanf(" %s",searchWord);
    
    //loops through the file stream and compares our string to the current word in the file stream
    while(fscanf(fp," %s",inputString)==1)
    {
        if (strcmp(inputString,searchWord)==0)//if we find a match we itterate our word counter and print the current word with brackets around it
        {
            wordCounter ++;
            printf("[%s] ",inputString);
        }
        else
        {
            printf("%s ",inputString);//if there is no match in the current word we just print it as is with a space after it
        }
    }
    printf("\nNumber of occurrences of the word %s is %d\n",searchWord,wordCounter);//displays how many times we found the requested word
    fclose(fp);//closes the file stream
    return 0;
}

int display_lines()//this function takes a user requested amount of lines to print from the designated file
{
    FILE *fp;//declarations of our filepath pointer for the text file stream
    int lineCount = 0,printedLines = 0;//declarations for two ints that we use to iterate through the file line
    char currentLine[MAX_WORD_LEN+1];//declartion of a string that will hold the whole current line in the file

    //opens the file stream in read only mode and checks if it oppend properaly if it did not it this func returns -1
    fp = fopen(FILE_PATH,"r");
    if (fp == NULL)
    {
        return -1;
    }
    
    //ask the user how many lines of the file they would like to display and stores it in the line counter var
    printf("Please enter how many lines you would like to display: ");
    scanf("%d",&lineCount);

    //loops through file and prints the current line if the it has not reached the EOF flag and the printed lines are less than the requested lines to be printed
    //and prints the current line of the file
    while(fgets(currentLine,MAX_WORD_LEN,fp)!= NULL && printedLines < lineCount)
    {
        fputs(currentLine,stdout);
        printedLines++;
    }
    fclose(fp);//closes the file stream
    return 0;
}

int append_file()
{
    char userLineInput[MAX_WORD_LEN+1];//string that will store the users input they would like to add to the file
    FILE *fp;//declarations of our filepath pointer for the text file stream
    
    //opens the file stream in read only mode and checks if it oppend properaly if it did not it this func returns -1
    fp = fopen(FILE_PATH,"a");
    if (fp == NULL)
    {
        return -1;
    }

    //ask the user to enter a new line into the file and stores it in the userLineInput string
    printf("Please enter a new line you would like to add to the file: ");
    
    //scanf finds the first "word" in the string stores it to the userline input then prints it the file stream
    //this was a work around to get around a left behind new line char from our menu input I am sure there is a better way for this
    scanf(" %s",userLineInput);
    fprintf(fp,userLineInput);
    //after the first word the whole line is put into the userLineInput string then stored to file
    fgets(userLineInput,MAX_WORD_LEN,stdin);
    fputs(userLineInput,fp);
    
    fclose(fp);//closes the file stream
    return 0;
}

int main(void)
{
    char userSelection;//declartion of a var that will store the users input char

    //ask the user to enter a selction from the menu and stores their choice in the userSelection var
    printf("1- Press (S) to search for a word\n2- Press (L) to display specified number of text lines to the screen\n3- Press (A) to append new content to the file\n4- Press (Q) to quit\n");
    scanf(" %c",&userSelection);
    //loops through the menu selection as long as the user does not select Q or q
    while (userSelection != 'Q'&& userSelection != 'q')
    {
        //if else statments control what function is called based upon the users input
        if (userSelection == 's' || userSelection == 'S')
        {
            printf("selected S\n");
            search_file();
        }
        else if (userSelection == 'l' || userSelection == 'L')
        {
            printf("selected L\n");
            display_lines();
        }
        else if (userSelection == 'a' || userSelection == 'A')
        {
            printf("selected A\n");
            append_file();
        }
        else
        {
            //if no of the above are true it must have been a wrong choice and prompts the user to try again and repeats the loop
            printf("Invalid option please re-enter a valid selection\n");
        }
        
        //ask the user to enter a selction from the menu and stores their choice in the userSelection var
        printf("1- Press (S) to search for a word\n2- Press (L) to display specified number of text lines to the screen\n3- Press (A) to append new content to the file\n4- Press (Q) to quit\n");
        scanf(" %c",&userSelection);
    }
    printf("quitting program");
    return 0;
}