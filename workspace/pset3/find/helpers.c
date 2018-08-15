/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n < 0)
    {
        return false;
    }    

    // Binary search
    int min = 0;
    int max = n;
    int mid;

    // Checks as long as there is a list
    while (min <= max)
    {      
        mid = (min + max) / 2;
    
        if (values[mid] == value)
        {
            return true;
        }     
        else if (value < values[mid])
        {
            max = mid - 1;
        }    
        else
        {
            min = mid + 1;
        }
    }
    return false;
}

// Swaps 2 values
void swap(int values[], int i)
{
    int temp_swap;
    temp_swap = values[i];
    values[i] = values[i + 1];
    values[i + 1] = temp_swap;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for (int steps = 0; steps < n - 1; steps++)
    {
        for (int i = 0; i < n - 1 - steps; i++)
        {
            if (values[i] > values[i + 1])
            {
                swap(values, i);
            }
        }
    }
    return;
}
