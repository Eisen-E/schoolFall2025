//Evan Eisenman 09/21/25
//CIS 265 12555
//Chapter 8 exercise 7
//This program loops through a 2d array and dsiplays the sum of the row and the columns
 
#include <stdio.h>//directive to include the standard input output library

#define ROWS_CONST 5 // directive that will be used as a const for our row length
#define COLUMNS_CONST 5 //directive that will be used as a const for our col length

//this function sums all the rows in the array and prints it out takes just one 2d array whos size is defined by the constants above
void sum_rows(int twoDimArray[ROWS_CONST][COLUMNS_CONST])
{
    int rowCounter=0,colCounter=0,sum;//declares and intializes loop counters to iterate through the list and declares the var that will hold the sum of the rows
    
    printf("Row totals: ");//display message to users
    for(rowCounter=0;rowCounter<ROWS_CONST;rowCounter++)//loops through each row
    {
        sum = 0;//sets the sum to zero for each new row
        
        for(colCounter=0;colCounter < ROWS_CONST;++colCounter)//goes through each col in each row and adds the value to the current rows sum
        {
            sum += twoDimArray[rowCounter][colCounter];
        }
        printf("%d ",sum);//displays the current rows sum
    }
    printf("\n");//goes to the next line when the function ends
}
//identical to the sum rows func but inverts the cols and rows so it calculates for each col
void sum_cols(int twoDimArray[ROWS_CONST][COLUMNS_CONST])
{
    int rowCounter=0,colCounter=0,sum;//declares and intializes loop counters to iterate through the list and declares the var that will hold the sum of the col
    
    printf("Column totals: ");
    for(colCounter=0;colCounter<ROWS_CONST;colCounter++)//loops through each col
    {
        sum = 0;//sets the sum to zero for each new row
        
        for(rowCounter=0;rowCounter < ROWS_CONST;++rowCounter)//goes through each row in each col and adds the value to the current col sum
        {
            sum += twoDimArray[rowCounter][colCounter];
        }
        printf("%d ",sum);//displays the current cols sum
    }
    printf("\n");//goes to the next line when the function ends
}

int main(void)
{
    int multiDArray[ROWS_CONST] [COLUMNS_CONST];//declares a 2d array whos size is defined by the macros set earlier
    int rowCounter=0,colCounter=0;//intializes and declares our counters for the loop in the main function

    for(rowCounter=0;rowCounter < ROWS_CONST;++rowCounter)//loops through each row to get the 5 digit array that will be stored there
    {
        printf("Enter the %d digits for row %d: ",COLUMNS_CONST,rowCounter+1);//ask the user to enter the correct amount of digts for the specfic row of the array
        for(colCounter=0;colCounter < ROWS_CONST;++colCounter)
        {
            scanf("%d",&multiDArray[rowCounter][colCounter]);//stores each digit into the current row at the index of the current itterations counter
        }
    }
    //calls our two custom functions that will diplay the sums of the cols and rows
    sum_rows(multiDArray);
    sum_cols(multiDArray);
    return 0;
}