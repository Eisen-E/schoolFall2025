//Evan Eisenman 08/27/25
//CIS 265 12555
//This application takes a user subtotal and calculates their total including tax

#include <stdio.h> //directive to include the standard input output libary
#define TAX_RATE 0.05f // directive for a macro containing our tax constant

int main(void)
{
    float subTotal, total;//declaration of the subtotal and total variables
    
    printf("This tool will evaluate your total including tax. Please enter your subtotal in this format 100.00.\nSubtotal:");
    scanf("%f",&subTotal);//takes user input and stores it in subtotal
    total = (subTotal * TAX_RATE)+subTotal;//calculates the total and stores it in the total variable
    printf("Total with tax:%.2f",total);// calls printf and displays the calculated total
    
    return 0;
}