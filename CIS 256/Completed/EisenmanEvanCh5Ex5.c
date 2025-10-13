//Evan Eisenman 09/09/25
//CIS 265 12555
//Chapter 5 exercise 5
//calculates a users taxable income and displays it to them

#include <stdio.h>//directive to include the standard input output library

float calculateTax(float totalIncome)//function that takes a users income and returns their duetaxes as a float
{
    float taxDue;//declares a taxDue var that holds how much tax is owed 
    //if else statment that checks if a useres taxable income is within a range indicated in the textbook
    //if the users income falls within a givin range their due taxes is calculated given the variables in the text
    if(totalIncome < 750.00)
    {
        taxDue = totalIncome * 0.01;//if user makes less than 750 bucks they only owe 1% of their total income
    }
    else if (totalIncome <= 2250.00)
    {
        taxDue = ((totalIncome - 750.00)*0.02)+7.50;//if they make 750 - to 2250 then a flat rate plus 2% is owed this pattern repeats with increasing percentage and flat rate for the rest
    }
    else if (totalIncome <= 3750.00)
    {
        taxDue = ((totalIncome - 2250.00)*0.03)+37.50;
    }
    else if (totalIncome <= 5250.00)
    {
        taxDue = ((totalIncome - 3750.00)*0.04)+82.50;
    }
    else if (totalIncome <= 7000.00)
    {
        taxDue = ((totalIncome - 5250.00)*0.05)+142.50;
    }
    else
    {
        taxDue = ((totalIncome - 7000)*0.06)+230.00;
    }
    return taxDue;//at the end returns the final ammount due
    
}
int main(void)
{
    float userIncome,dueTaxes;//declares two variables one that will hold the users income the other will hold the users total taxes due
    printf("Please enter your total income(ex 1024.50):");//prompts the user to enter their income and stores their input into the userIncome var
    scanf("%f",&userIncome);
    dueTaxes = calculateTax(userIncome);//calls the calculateTax func and passes the userIncome var and stores the returned value in dueTaxes var
    printf("You owe $%.2f in taxes",dueTaxes);//displays the taxes the user owes
    return 0;
}