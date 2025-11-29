//Evan Eisenman 11/28/25
//CIS 265 12555
//Chapter 19 exercise 1
//Displays a menu to the user and uses an interface to manipulate a queue
#include <stdio.h>
#include "queue.h"

//macro for user prompt
#define PROMPT "Press (1) to insert an integer item to the end of the queue\nPress (2) to remove an integer item from the beginning of the queue\nPress (3) to display the first item in the queue\nPress (4) to display the last item in the queue\nPress (5) to display the count of items in the queue\nPress (6) to quit\n"

int main(void)
{
    int userChoice;//holds the int of the current user selection
    int userVal;//holds the int of the current user input into the queue
    printf(PROMPT);//prints a prompt
    scanf(" %d",&userChoice);//gets the users menu choice
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
            //calls the printf with a call to the queue_remove func as the 2nd argument that will return the value removed from the queue
            printf("%d was removed from the queue!\n",queue_remove());
        }
        else if (userChoice == 3)
        {
            //calls the printf with a call to the get_queue_item func as the 2nd argument that will return the value of the item at the current index in this case 0
            printf("%d is the first item in the queue!\n",get_queue_item(0));
        }
        else if (userChoice == 4)
        {
            //calls the printf with a call to the get_queue_item func as the 2nd argument that will return the value of the item at the current index in this case we call queue_count to get the toatal amount of items and subtract 1 to get its index
            printf("%d is the last item in the queue!\n",get_queue_item(queue_count()-1));
        }
        else if (userChoice == 5)
        {
            //calls the printf with a call to the queue_count func as the 2nd argument that will return the value of the total amount of items stored in the queue
            printf("There are a total of %d items in the queue!\n",queue_count());
        }
        else{printf("Incorrect selection please retry");}
        printf(PROMPT);
        scanf(" %d",&userChoice);
    }

    return 0;
}