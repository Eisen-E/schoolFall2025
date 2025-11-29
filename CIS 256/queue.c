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
    else if (last == 0)
    {
        printf("No item has been entered into the queue yet, no action was taken!");
    }
    else
    {
        while(queueCounter < last)
        {
            queue[queueCounter-1]= queue[queueCounter];
            queueCounter++;
        }
        queue[last] = 0;
    }
}

void queue_insert(int inputInt)
{
    if(last < QUEUE_SIZE)
    {
        queue[last] = inputInt;
        last++;
    }
    else
    {
        printf("Queue is full item could not be entered");
    }
}

int queue_remove(void)
{
    int removedItem = queue[0];
    queue_shift();
    last--;
    return removedItem;
}

int queue_count(void)
{
    return last;
}

int get_queue_item(int index)
{
    return queue[index];
}