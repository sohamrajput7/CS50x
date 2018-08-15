/**
 * Problem Set 1
 * water.c
 * Outputs the number of bottles
 * Made by Soham Rajput
 */
   
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Asks the user to input the number of minutes
    printf("minutes: ");
    int min = GetInt();
    
    // Outputs the number of bottles required
    printf("\nbottles: %d\n", min * 12);
    return 0;
}