//Evan Eisenman 09/02/25
//CIS 265 12555
//Chapter 3 exercise 3
//This program takes a formated IBSN number and "decodes" it.

#include <stdio.h> //directive to include the standard input output libary

int main(void)
{
    int gs1Pre,groupId,publisherId,itemNum,checkDigit;//decleration for the 5 variables that will hold the diffrent sections of the IBSN
    printf("Please enter your IBSN number: ");//prompts the user to input an IBSN and reads the input acording to the formated string
    scanf("%d-%d-%d-%d-%d",&gs1Pre,&groupId,&publisherId,&itemNum,&checkDigit);
    //displays the IBSN the user input into the format seen in the textbook
    printf("GS1 prefix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d",gs1Pre,groupId,publisherId,itemNum,checkDigit);
    return 0;
}