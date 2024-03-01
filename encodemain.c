#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"



int main(int argc, char *argv[]) 
{
    const char *inputFileName = argv[2];
    char outputFileName[256];

    if ((strstr(argv[2], ".txt") != NULL) && (strstr(argv[1], "-c") != NULL))
    {
        changeFileExtension(inputFileName, outputFileName, ".bin");
        convertFileToBinary(inputFileName, outputFileName);

    } else if ((strstr(argv[2], ".bin") != NULL) && (strstr(argv[1], "-d") != NULL))
    {
        changeFileExtension(inputFileName, outputFileName, ".txt");
        convertBinaryToText(inputFileName, outputFileName);
    } else 
    {
        printf("Invalid file type or commnad\n");
        return 1;  // Return an error code
    }
    
    /*
        if (strstr(argv[1], "-c") != NULL) 
        {
            // Convert the file and write binary representation to another file
            convertFileToBinary(inputFileName, outputFileName);
        } else if (strstr(argv[1], "-d") != NULL) 
        {
            // Convert the file and write binary representation to another file
            convertBinaryToText(inputFileName, outputFileName);
        } else 
        {
            printf("Invalid command\n");
            return 1;  // Return an error code
        }
    */


    printf("Conversion completed.\n");

    return 0;
}
