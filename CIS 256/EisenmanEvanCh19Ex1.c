//Evan Eisenman 11/28/25
//CIS 265 12555
//Chapter 19 exercise 1
//Displays a menu to the user and uses an interface to manipulate a queue
#include <stdio.h>
#include "C:\Users\monke\OneDrive\Desktop\GitHub\schoolFall2025\CIS 256\queue.h"

//macro for user prompt
#define PROMPT "Press (1) to insert an integer item to the end of the queue\nPress (2) to remove an integer item from the beginning of the queue\nPress (3) to display the first item in the queue\nPress (4) to display the last item in the queue\nPress (5) to display the count of items in the queue\nPress (6) to quit\n"

int main(void)
{
    int userChoice;//holds the int of the current user selection
    int userVal;
    printf(PROMPT);//prints a prompt
    scanf(" %d",&userChoice);//gets userchoice
    while (userChoice !=6)//exits loop if user enters 6
    {
        //if else stament to control user selection
        if(userChoice == 1)
        {
            printf("Please enter a number to insert into the queue!:");
            scanf(" %d",&userVal);//gets value to pass to our insert func
            queue_insert(userVal);//calls the queue insert func and passes the users value
        }
        else if (userChoice == 2)
        {
            printf("%d was removed from the queue!\n",queue_remove());
        }
        else if (userChoice == 3)
        {
            printf("%d is the first item in the queue!\n",get_queue_item(0));
        }
        else if (userChoice == 4)
        {
            printf("%d is the last item in the queue!\n",get_queue_item(queue_count()-1));
        }
        else if (userChoice == 5)
        {
            printf("There are a total of %d items in the queue!\n",queue_count());
        }
        else{printf("Incorrect selection please retry");}
        printf(PROMPT);
        scanf(" %d",&userChoice);
    }

    return 0;
}