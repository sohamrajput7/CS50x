/**
 * Problem Set 2
 * caesar.c
 * Caesar cipher
 * Made by Soham Rajput
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please try again!\n");
        return 1;
    }
    
    // Executes the program if argc is 2
    else if (argc == 2)
    {
        int i, n;
        
        // Converts the given string numerical values to integers
        int key = atoi(argv[1]);
        
        string secret_text = GetString();
        
        for (i = 0, n = strlen(secret_text); i < n; i++)
        {
            // Checks whether the characters of the message are alphabetic
            if (isalpha(secret_text[i]))
            {
                if (isupper(secret_text[i]))
                {
                    int upperchar = ((secret_text[i] - 65 + key) % 26) + 65;
                    printf("%c", upperchar);
                }
                else if (islower(secret_text[i]))
                {
                    int lowerchar = ((secret_text[i] - 97 + key) % 26) + 97;
                    printf("%c", lowerchar);
                }
            }
            else
                printf("%c", secret_text[i]);
        }
    }
    printf("\n");
    return 0;
}