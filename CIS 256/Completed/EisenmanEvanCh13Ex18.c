//Evan Eisenman 10/12/25
//CIS 265 12555
//Chapter 13 exercise 18
//Takes the users input in the form mm/dd/yyyy and returns it as Month dd, yyyy

//directives to inclued the stdio and string standard c libraries 
#include <stdio.h>
#include <string.h>

int main(void)
{
    //declares and intializes 3 vars to hold our day month and year as ints
    int monthInt = 0 ,dayInt = 0,yearInt = 0;
    //jagged array that stores the months as null terminated strings months are indexed according to gregorian calendar minus 1
    char *monthStr[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};    
    
    //ask user to enter their input date and stores the info as ints
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&monthInt,&dayInt,&yearInt);
    
    // returns the users date expanded using their month the inupt as the index in the jagged array
    printf("You entered the date %s %d, %d",monthStr[monthInt-1],dayInt,yearInt);
    
    
    return 0;
}