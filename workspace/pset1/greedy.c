/**
 * Problem Set 1
 * greedy.c
 * Outputs the minimum number of coins required in change
 * Made by Soham Rajput
 */
 
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float input_change;
    int coin_counter = 0;
    printf("O hai! How much change is owed? ");
    
    // Retry if a negative number or 0 is entered
    do
    {
        input_change = GetFloat();
        if (input_change <= 0)
        {
            printf("\nRetry: ");
        }
    }
    while (input_change <= 0);
    
    // Conversion of dollars to cents
    int change_cents = roundf((input_change * 100));
    
    // Loop to count quarters
    while (change_cents >= 25)
    {
        change_cents -= 25;
        coin_counter++;
    }
    
    // Loop to count dimes
    while (change_cents >= 10)
    {
        change_cents -= 10;
        coin_counter++;
    }
    
    // Loop to count nickels
    while (change_cents >= 5)
    {
        change_cents -= 5;
        coin_counter++;
    }
    
    // Loop to count pennies
    while (change_cents >= 1)
    {
        change_cents -= 1;
        coin_counter++;
    }
    
    // Outputs the number of coins
    printf("%d\n",coin_counter);
    return 0;
}