/**
 * Problem Set 2
 * initials.c
 * Outputs the initials in capitals
 * Made by Soham Rajput
 */
 
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = GetString();
    
    printf("%c", toupper(name[0]));
    
    // Iterates over every character in the string
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        
        if (name[i] == ' ')
        {
            // Prints in capitals, the characters after space
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}