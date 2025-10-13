//Evan Eisenman 10/04/25
//CIS 265 12555
//Chapter 12 exercise 9
//This program generates two arrays based of the constant array length and for each element at the same index multiples and then adds them to the total sum

#include <stdio.h> //directive to include the standard input output library
#include <stdlib.h> //directive to include the standard library used for its rand func

#define Array_Length 10 //macro that is used to set the size of both arrays
#define Max_Val 100 //macro that sets the max value that the filled array items can be

double inner_product(const double *a,const double *b, int n)//Function to get the product of the same index of both arrays and adds them
{
    double sum = 0;//initalizes and declares our sum var
    const double *flag = a+(n-1);//initalizes and declares a pointer to the last item in our array used as sentinal value for our loop
    
    while (a <= flag)//loop as long as the pointer is within range of the array
    {
        sum += *a * *b; // adds the product of the two items at the current index of the array using pointers to our sum var
        a++; //increments the a pointer
        b++; //increments the b pointer
    }
    return sum;//returns our sum var to func call
}

void fill_arrays(double *a,double *b,int n)//fills the array with random values using the rand func
{
    printf("A      B  \n");//prints col headers
    const double *flag = a+(n-1);//initalizes and declares a pointer to the last item in our array used as sentinal value for our loop
    while (a <= flag)//loop as long as the pointer is within range of the array
    {
        *a = rand()%Max_Val;//sets the current index of a to a random val and uses mod operator to restrict the max val
        *b = rand()%Max_Val;//sets the current index of b to a random val and uses mod operator to restrict the max val
        printf("%5.2f  %5.2f  \n",*a,*b);//displays the value of the values at the current index in a and b and formats it
        a++; //increments the a pointer
        b++; //increments the b pointer
    }
}

int main(void)
{
    double arrayA[Array_Length];//declares the A array with a size defined by our Array_length const
    double arrayB[Array_Length];//declares the B array with a size defined by our Array_length const
    double sum = 0;//declars and intializes our sum var that will store the total calculated value
    
    fill_arrays(&arrayA[0],&arrayB[0],Array_Length);//function call to our fillArrays func
    sum = inner_product(&arrayA[0],&arrayB[0],Array_Length);//function call to our inner_product func
    printf("\n%.2f",sum);//displays the total sum to the user

    return 0;
}