/* Selection Sort
Selection sort iterates through an array of n values searching for the lowest value
Once found it swaps the value with the value in the first position, 
locking the first position as sorted
Selection sort iterates through the shorter array again, with the same procedure as before.
When Selection sort has iterated through the array n - 1 times the array is sorted.
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

    // Initiating holders, lowest value, pos of lowest value and a temp storage
    int lowval;
    int lowpos;
    int tempstrg;

    // Iterating through the array n -1 times
    // Holding the first unsorted pos, where the lowest found value will be placed
    for (int j = 0; j < size - 1; j++)
    {
        // Sets lowest value to the first value so we have a starting value
        lowval = nmbrarray[j];
        // Sets pos to first 
        lowpos = j;

        // Iterating through the array
        for (int k = j + 1; k < size; k++)
        {
            // If we find a lower value than the currenty stored one
            if (nmbrarray[k] < lowval)
            {
                // Store value and position
                lowval = nmbrarray[k];
                lowpos = k;
            }
        }
        // Save the first unsorted value
        tempstrg = nmbrarray[j];
        // Save the lowest value to the first unsorted pos
        nmbrarray[j] = lowval;
        // Save the temp value on the pos where low value was found
        nmbrarray[lowpos] = tempstrg;
    }

    // Print the sorted array
    for (int x = 0; x < size - 1; x++)
    {
        printf("%d, ", nmbrarray[x]);
    }
    printf("%d", nmbrarray[size - 1]);
}