// Program with an array that has three functions: to calculate sum, min and max

#include <stdio.h>
#define SIZE 10

// Function signatures
void sumArray(int array[]);
void maxArray(int array[]);
void minArray(int array[]);

// main 
int main()
{
    int array[SIZE];
    int i;


    // User input into array
    printf("Please enter 10 values\n");
    for ( i = 0; i < SIZE; i++)
    {
        scanf("%d", &array[i]);
    } // end for
    
    // call 3 functions for array
    sumArray(array);
    maxArray(array);
    minArray(array);

    return 0;
} // end main()

void sumArray(int array[])
{
    int sum = 0;
    int i;


    // calculate sum
    for ( i = 0; i < SIZE; i++)
    {
        sum = sum + array[i];
    } // end for
    
    // print sum
    printf("\nsum: %d", sum);

} // end sumArray()


void maxArray(int array[])
{
    int i;
    int max = array[0];


    for ( i = 0; i < SIZE; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        } // end if
        
    } // end for
    
    // Print max element
    printf("\nMax element: %d", max);

} // end maxArray()

void minArray(int array[])
{
int i;
int min = array[0];


    for ( i = 0; i < SIZE; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        } // end if
        
    } // end for
    
    // Print min element
    printf("\nMin Element: %d", min);
} // end minArray()
