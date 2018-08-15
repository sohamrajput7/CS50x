/**
 * Problem Set 2
 * vigenere.c
 * Vigenere cipher
 * Made by Soham Rajput
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Prompts the user if argc is not 2
    if (argc != 2)
    {
        printf("Please try again!\n");
        return 1;
    }
    
    // Checks whether command line argument entered is alphabetic
    else if (argv[1])
    {
        int length = strlen(argv[1]);
        for (int i = 0; i < length; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Please try again!\n");
                return 1;
            }
        }
    }
    
    string secret_text = GetString();
    
    int mloop = 0;
    int k = 0;
    string key = argv[1];
    
    // Iterates over all characters in the secret text string
    for (int i = 0, n = strlen(secret_text); i < n; i++)
    {
        if (isalpha(secret_text[i]))
        {
            // Iterates over all characters in the key
            k = mloop % strlen(key);
            
            if (islower(secret_text[i]))
            {
                if (islower(key[k]))
                {
                    int x = ((secret_text[i] - 97 + key[k] - 97) % 26) + 97;  
                    printf("%c", x);
                }
                
                else if (isupper(key[k]))
                {
                    int x = ((secret_text[i] - 97 + key[k] - 65) % 26) + 97;  
                    printf("%c", x);
                }
            }
            
            if (isupper(secret_text[i]))
            {
                if (islower(key[k]))
                {
                    int y = ((secret_text[i] - 65 + key[k] - 97) % 26) + 65;  
                    printf("%c", y);
                }
                
                else if (isupper(key[k]))
                {
                    int y = ((secret_text[i] - 65 + key[k] - 65) % 26) + 65;  
                    printf("%c", y);
                }
            }
            
            mloop++;
        }
        
        else
            printf("%c", secret_text[i]);
    }
    printf("\n");
}