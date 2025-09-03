//Evan Eisenman 08/27/25
//CIS 265 12555
//This application takes a users loan, intrest rate and monthly payment and calculates their next 3months balances

#include <stdio.h> //directive to include the standard input output libary

//this function takes 3 arguments one the current loan balance the already converted monthly intrest rate and monthly payment
//this retuns a float value of the calculated balance
//I know functions were not covered yet in class but I did not want to write this equation three times
float CalculateLoan(float loanBal,float monthlyIntrestRate,float monthlyPayment)
{
    loanBal = ((loanBal*monthlyIntrestRate)+loanBal)-monthlyPayment;
    return loanBal;
}

int main(void)
{
    float loanBal,intrestRate,monthlyPayment;//decleration of three float variables that will be used for user input
    //ask the user their loan balance and stores it into the loanbal var
    printf("This app will display the balance of your loan for the next three months.\nPlease enter your balance(ex $10,000=10000):");
    scanf("%f",&loanBal);
    //ask the users intrest rate and stores it into the intrestRate var
    printf("Please enter your intrest rate.(ex 50%%=50):");
    scanf("%f",&intrestRate);
    //ask the users monthly payment and stores it into the monly payment var
    printf("Please enter your monthly payments.(ex $125=125):");
    scanf("%f",&monthlyPayment);
    //calculates the monlthy intrest rate by dividing it by the months in a year and converting it to a precentage by dividing by 100
    intrestRate = (intrestRate/12)/100;
    
    //calls the the calculate loab function 3 times and displays stores the returned value into the loanBal var and displays the balance to the user 3 times
    loanBal = CalculateLoan(loanBal,intrestRate,monthlyPayment);
    printf("Balance remaining after first payment:$%.2f\n",loanBal);
    loanBal = CalculateLoan(loanBal,intrestRate,monthlyPayment);
    printf("Balance remaining after second payment:$%.2f\n",loanBal);
    loanBal = CalculateLoan(loanBal,intrestRate,monthlyPayment);
    printf("Balance remaining after third payment:$%.2f\n",loanBal);
    return 0;
}