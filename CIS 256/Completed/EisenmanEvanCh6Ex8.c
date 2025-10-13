//Evan Eisenman 09/18/25
//CIS 265 12555
//Chapter 6 exercise 8
//This program displays a calendar based off user input

#include <stdio.h>//directive to include the standard input output library

void main(void)
{
    int totalDays,startDay,counter; //declares 3 int vars that will be used for our counters
    
    //prompts the user to enter the number of days in the month and what day of the week the month starts on and stores both in 2 vars
    printf("Enter number of days in month: ");
    scanf("%d",&totalDays);
    printf("Enter starting day of the week (l=Sun, 7=Sat): ");
    scanf("%d",&startDay);
    startDay = startDay - 1;//sets sunday =0 through sat =6 helps me track the itterations better while still being user friendly to non technical users

    //loops through an increments the counter by 1 as long as the conter is smaller or equal to the total days
    //totaldays+ startday allows us to easily insert balnk spaces like in the example problem
    for(counter=0;counter <= totalDays + startDay;counter = counter+1)
    {
        //if the counter is less than or equal to the start day we print 2 empty spaces
        if(counter <= startDay)
        {
            printf("  ");
        }
        else if(startDay+totalDays>=counter)//if our counter is euqal to the startday + the totaldays we print the counter without the startday offset
        {
            printf("%2.d ",counter-startDay);
            if(!(counter%7))//checks if the current itteration of the loop is the end of the week using the mod opperator if 0 is returned we know its equaly divisable by 7
            {
                printf("\n");
            }
        }
    }
}
