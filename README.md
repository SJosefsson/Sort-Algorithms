# Sort Algorithms
As I'm currently working through Harvard CS50 course, I decided to try and create some sorting algorithms in C.

## Bubble Sort
Bubble sort iterates through an array of n values from 0 to n - 1. On each iteration Bubble sort compares the current value with the next value in the array.
If the current value is bigger than the next value they switch place in the array. Meaning that the biggest value will "Bubble up" to the highest place in the array.
Once the algorithm iterates through the full array without doing any swap the array is considered sorted.
Big O for Bubble sort is O(n^2)

## Selection Sort
Selection sort iterates through an array of n values from 0 to n - 1 searching for the lowest value in the array.  Once done it swaps place with the lowest value and the value on the first position in the array. 
Selection sort then iterates through the array again, from from 1 to n - 1, since the lowest value is now secured in the first position of the array. Once done it swaps the new lowest value with the value in the second position in the array. Securing the second lowest value to the second place in the array.
This is repeated up until n - 1 times before the array is considered sorted.
Big O for Selection sort is O(n^2)

## Merge Sort
Merge sort takes an array of n values and splits it evenly into two arrays, left and right. Then Merge sort recursively calls itself on first the left array, then the right array, then it merges and sorts the the sorted halves.
Meaning that the initial array of n values, will first be split into n arrays of one values. Once done Merge sort will merge and sort these n arrays from left to right until we have a new array of n values that is sorted.
Big O for Merge sort is (n log n)
