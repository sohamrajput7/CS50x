/**
 * Problem Set 1
 * mario.c
 * Outputs the pattern of Mario stairs 
 * Made by Soham Rajput
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{   
    int height;
    printf("Height: ");
    
    // Loop asking for input again if the value > 23
    do
    {
        height = GetInt();
        if (height < 0 || height > 23)
        {
            printf("Retry: \n");
        }
    }
    while (height < 0 || height > 23);
    
    // Nested 'for' loops for printing spaces, hashes, and new lines
    for (int i = 0 ; i < height ; i++)
    {
        int j = (height - 1);
        
        // Loop to output the spaces
        for ( ; j > i ; j--)
        {
            printf(" ");
        }
        
        // Loop to output the hashes
        for (int k = 0 ; k < i + 2 ; k++)
        {
            printf("#");
        }
        // To output a new line
        printf("\n");
    }
    return 0;
}