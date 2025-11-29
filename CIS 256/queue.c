//Evan Eisenman 11/28/25
//CIS 265 12555
//Chapter 19 exercise 1
//Displays a menu to the user and uses an interface to manipulate a queue
//this file contains the implementations of the interface

#include <stdio.h>//includes the stio lib for the printf func
#include "queue.h"//inlcudes our header with the func prototypes

#define QUEUE_SIZE 100 //macro to set queue size

static int last=0;//var that will store the total amount of items in the stack
static int queue[QUEUE_SIZE]={0};//creates our stack as an array of ints

static void queue_shift(void)//private function that will shift the stack over one
{
    int queueCounter = 1;//sets counter to one
    if(last == 1)//checks if there is only one item in the stack if it is it just sets it to zero
    {
        queue[0]=0;
    }
    else if (last == 0)//checks if no items are in the queue and lest the user know
    {
        printf("No item has been entered into the queue yet, no action was taken!");
    }
    else
    {
        while(queueCounter < last)//loops through the queue and moves each item over one and sets the last to 0
        {
            queue[queueCounter-1]= queue[queueCounter];
            queueCounter++;
        }
        queue[last] = 0;
    }
}

void queue_insert(int inputInt)//inputs the argument passed to the function into the the last postion in the queue
{
    if(last < QUEUE_SIZE)//makes sure we are not going out of bounds of the array inserts the number into the correct index and itterates last
    {
        queue[last] = inputInt;
        last++;
    }
    else// if we are trying to go out of  bounds func does nothing and tells the user
    {
        printf("Queue is full item could not be entered");
    }
}

int queue_remove(void)//removes the first item in the array and calls queue shift to shift all items over one returns the val of the removed item
{
    int removedItem = queue[0];//stores the item to be removed
    queue_shift();//shifts array over to the "left" by one
    last--;//decrements last
    return removedItem;
}

int queue_count(void)//we are keeping track of the items stored in the queue through the private var last so we just return its value
{
    return last;
}

int get_queue_item(int index)//returns the value of an item and a index passed as an argument
{
    return queue[index];
}