//Evan Eisenman 11/28/25
//CIS 265 12555
//Chapter 19 exercise 1
//Displays a menu to the user and uses an interface to manipulate a queue
//this file contains the implementations of the interface
#include <stdio.h>
#include "C:\Users\monke\OneDrive\Desktop\GitHub\schoolFall2025\CIS 256\queue.h"
#define QUEUE_SIZE 100

static int last=0;
static int queue[QUEUE_SIZE]={0};

static void queue_shift(void)
{
    int queueCounter = 1;
    if(last == 1)
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