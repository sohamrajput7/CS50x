/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BLOCKSIZE 512

typedef uint8_t BYTE;

int main(void)
{
    // open "card.raw"
    FILE* inptr = fopen("card.raw", "r");
    
    // error checking
    if (inptr == NULL)
    {
        printf("Could not open file. \n");
        return 1;
    }
    
    // initializing buffer of 512 bytes
    BYTE buffer[BLOCKSIZE];
    
    // initializing file pointer
    FILE* temp = NULL;
    
    // JPEG counter
    int jpgcount = 0;
    
    // filename in format "###.jpg"
    char filename [10];
    
    // checks whether EOF is reached
    while (!feof(inptr))
    {
        // reads data into buffer
        int no_read = fread(&buffer, 1, 512, inptr);
        
        // checks for new jpg signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            // error checking
            if (temp != NULL)
            {
                fclose(temp);
            }
            
            // outfile labelling
            sprintf(filename, "%03d.jpg", jpgcount++);
            
            // opening the outfile with label
            temp = fopen(filename, "w");
            
            // writing data to the outfile
            fwrite(buffer, sizeof(buffer), 1, temp);
        }
        
        // writing data
        else if (jpgcount > 0)
        {
            fwrite(&buffer, 1, no_read, temp);
        }
    }
    
    // closing the file pointer
    fclose(inptr);
    
    return 0;
}
