/* Bubble Sort
Bubble sort iterates through an array of n values, n - 1 times.
For each iteration it compares the current value with the next value in the array.
If current value is bigger than next value Bubble swaps the order of the values.
This repeats n - 1 times, or until a complete iteration of the array is done without any swap.
*/

#include <stdio.h>

int main(void)
{
    // Take input from user
    int size;
    printf("How large do you want the array of numbers to be?: ");
    scanf("%d", &size);

    int nmbrarray[size];
    
    for (int i = 0; i < size; i++)
    {
        printf("Enter number %i: ", i + 1);
        scanf("%d", &nmbrarray[i]);
    }
    
    // Initiates done to 0 as the array is not done being sorted
    int done = 0;
    // Do the iteration of the array until done is 0
    do
    {
        // Change done to 1, so we will exit in case no swap is done
        done = 1;
        
        // Iterating through the array
        for (int j = 0; j < size; j++)
        {
            // Storing current value and next value
            int current = nmbrarray[j];
            int next = nmbrarray[j + 1];

            // If current value is bigger than next
            if (current > next)
            {
                // Swap them and set done to 0 to indicate that the array is not done
                done = 0;
                nmbrarray[j] = next;
                nmbrarray[j + 1] = current;
            }
        }
    }
    while (done == 0);

    // Print sorted array
    for (int k = 0; k < size - 1; k++)
    {
        printf("%i, ", nmbrarray[k]);
    }
    printf("%d", nmbrarray[size - 1]);
}