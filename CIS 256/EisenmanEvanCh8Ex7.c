//Evan Eisenman 09/21/25
//CIS 265 12555
//Chapter 7 exercise 7
//This program loops through a 2d array and dsiplays the sum of the row and the columns
 
#include <stdio.h>//directive to include the standard input output library

#define ROWS_CONST 5
#define COLUMNS_CONST 5

void sum_rows(int twoDimArray[ROWS_CONST][COLUMNS_CONST])
{
    int rowCounter,colCounter,sum;
    
    printf("Row totals: ");
    for(rowCounter=0;rowCounter<ROWS_CONST;rowCounter++)
    {
        sum = 0;
        for(colCounter=0;colCounter < ROWS_CONST;++colCounter)
        {
            sum += twoDimArray[rowCounter][colCounter];
        }
        printf("%d ",sum);
    }
    printf("\n");
}

void sum_cols(int twoDimArray[ROWS_CONST][COLUMNS_CONST])
{
    int rowCounter,colCounter,sum;
    
    printf("Column totals: ");
    for(colCounter=0;colCounter<ROWS_CONST;colCounter++)
    {
        sum = 0;
        for(rowCounter=0;rowCounter < ROWS_CONST;++rowCounter)
        {
            sum += twoDimArray[rowCounter][colCounter];
        }
        printf("%d ",sum);
    }
    printf("\n");
}

int main(void)
{
    int multiDArray[ROWS_CONST] [COLUMNS_CONST];
    int rowCounter,colCounter;

    for(rowCounter=0;rowCounter < ROWS_CONST;++rowCounter)
    {
        printf("Enter the %d digits for row %d: ",COLUMNS_CONST,rowCounter+1);
        for(colCounter=0;colCounter < ROWS_CONST;++colCounter)
        {
            scanf("%d",multiDArray[rowCounter][colCounter]);
        }
    }
    return 0;
}