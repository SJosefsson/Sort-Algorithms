/* Merge Sort
Merge sort splits an array of n values in half, recursively, 
until we have n arrays with 1 value in each. Afterwards 
Merge sort merges the left and right side of each arrays from
left side to right side, sorting them while merging.
*/

#include <stdio.h>
#include <string.h>

int mergesort(int nmbrarray[], int size);

int main(void)
{
    // Get user input
    int size;
    printf("How many values do you want in the array? ");
    scanf("%d", &size);

    int nmbrarray[size];

    for (int i = 0; i < size; i++)
    {
        printf("Please enter value %d: ", i + 1);
        scanf("%d", &nmbrarray[i]);
    }

    // Call mergesort on the initial array
    *nmbrarray = mergesort(nmbrarray, size);

    // Print the sorted list
    printf("This is your sorted list:\n");
    for (int j = 0; j < size - 1; j++)
    {
        printf("%d, ", nmbrarray[j]);
    }
    printf("%d", nmbrarray[size - 1]);
}

// Merge sort function that takes an array of ints.
int mergesort(int *nmbrarray, int size)
{
    // If the array only contain one value, return the array
    // As there's nothing to sort and we're done with the splitting
    if (size == 1)
    {
        return *nmbrarray;
    }
    // Otherwise split the array in the middle
    // Then call merge sort on the left half, and the right half
    else
    {
        int leftsize;
        int rightsize = size / 2;
        
        // If the original array have even values, set left array to half the size
        if (size % 2 == 0)
        {
            leftsize = size / 2;
        }
        // Otherwise set the left array to half the size + 1
        // (This is a personal choice, right array can be the bigger one as well)
        else
        {
            leftsize = (size / 2) + 1;
        }

        // Initiate empty left and right array with the correct size
        int leftarray[leftsize];
        int rightarray[rightsize];

        // Copy the left and right half from the original array into left and right array
        memcpy(leftarray, nmbrarray, leftsize * sizeof(int));
        memcpy(rightarray, &nmbrarray[leftsize], rightsize * sizeof(int));

        // Call merge sort on the left and right array
        // Merge sort will return them sorted, and they will be saved over the old left and right array
        *leftarray = mergesort(leftarray, leftsize);
        *rightarray = mergesort(rightarray, rightsize);

        // Initiate iteration values for sorting the left and right array
        int leftiter = 0;
        int rightiter = 0;

        // Iterating from 0 to size - 1
        // Size meaning the size of the array that was previously split
        for (int i = 0; i < size; i++)
        {
            // If left array is empty
            if (leftiter == leftsize)
            {
                nmbrarray[i] = rightarray[rightiter];
                rightiter++;
            }
            // If right array is empty
            else if (rightiter == rightsize)
            {
                nmbrarray[i] = leftarray[leftiter];
                leftiter++;
            }
            else
            {   
                // If current value from left array is smaller than current value from right array
                if(leftarray[leftiter] < rightarray[rightiter])
                {
                    // Save the left value in the full array and add one to the left iteration
                    nmbrarray[i] = leftarray[leftiter];
                    leftiter++;
                }
                // Otherwise if left value is bigger than right value
                else if(leftarray[leftiter] > rightarray[rightiter])
                {
                    // Save the right value in the full array and add one to the right iterator
                    nmbrarray[i] = rightarray[rightiter];
                    rightiter++;
                }
                // If the values are the same size
                else if(leftarray[leftiter] == rightarray[rightiter])
                {
                    // Save the left value and add one to the left iteration
                    // (This is a personal choice, any of the two values can be chosen)
                    nmbrarray[i] = leftarray[leftiter];
                    leftiter++;
                }
            }
        }
        // Return the sorted array that was passed as argument to this function
        return *nmbrarray;
    }
}