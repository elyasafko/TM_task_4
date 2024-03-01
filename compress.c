#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"

void charToBinary(char ch, FILE *outputFile) 
{
    if (ch >= '0' && ch <= '9')
    {
        for (int i = 3; i >= 0; i--) 
        {
            int bit = ((ch >> i) & 1) ^ 1;  // XOR with 1 to invert the bit
            fprintf(outputFile, "%d", bit);
        }
    }
}

void BinaryToChar(char ch, FILE *outputFile) 
{
    int bit = 0;
    for (int i = 0; i < 4; i++) 
    {
        bit = (bit << 1) | (ch - '0');
        ch = fgetc(outputFile);
    }
    fprintf(outputFile, "%c", bit);
}

void convertFileToBinary(const char *inputFileName, const char *outputFileName)
{
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) 
    {
        perror("Error opening files");
        return;
    }

    int ch;
    while ((ch = fgetc(inputFile)) != EOF) 
    {
        charToBinary(ch, outputFile);
    }

    if (fclose(inputFile) == EOF || fclose(outputFile) == EOF) 
    {
        perror("Error closing files");
        return;
    }
}

void convertBinaryToText(const char *inputFileName, const char *outputFileName)
{
    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) 
    {
        perror("Error opening files");
        return;
    }

    int ch;
    int count = 0;
    while ((ch = fgetc(inputFile)) != EOF) 
    {
        BinaryToChar(ch, outputFile);
        count++;
    }
    if (count % 2 != 0) 
    {
        fputc('0000', outputFile);
    }

    if (fclose(inputFile) == EOF || fclose(outputFile) == EOF) 
    {
        perror("Error closing files");
        return;
    }
}

void changeFileExtension(const char *inputFileName, char *outputFileName, const char *newExtension) 
{
    strcpy(outputFileName, inputFileName);
    char *dot = strrchr(outputFileName, '.');
    if (dot != NULL) 
    {
        strcpy(dot, newExtension);
    } else 
    {
        strcat(outputFileName, newExtension);
    }
}