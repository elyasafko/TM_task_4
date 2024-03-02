#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compress.h"

void charToBinary(char ch, FILE *outputFile) 
{
    if (ch >= '0' && ch <= '9')
    {
        switch (ch) 
        {
            case '0':
                fwrite("1111", sizeof(char), 4, outputFile);
                break;
            case '1':
                fwrite("1110", sizeof(char), 4, outputFile);
                break;
            case '2':
                fwrite("1101", sizeof(char), 4, outputFile);
                break;
            case '3':
                fwrite("1100", sizeof(char), 4, outputFile);
                break;
            case '4':
                fwrite("1011", sizeof(char), 4, outputFile);
                break;
            case '5':
                fwrite("1010", sizeof(char), 4, outputFile);
                break;
            case '6':
                fwrite("1001", sizeof(char), 4, outputFile);
                break;
            case '7':
                fwrite("1000", sizeof(char), 4, outputFile);
                break;
            case '8':
                fwrite("0111", sizeof(char), 4, outputFile);
                break;
            case '9':
                fwrite("0110", sizeof(char), 4, outputFile);
                break;
            default:
                // code for default case
                break;
        }
    }
}

void BinaryToChar(char ch, FILE *outputFile) 
{
    char str[2];  // Create a string with enough space for the character and null terminator
    str[0] = ch;
    str[1] = '\0';  // Null-terminate the string

    if (strncmp(str, "1111", 4) == 0)
        fprintf(outputFile, "0");
    else if (strncmp(str, "1110", 4) == 0)
        fprintf(outputFile, "1");
    else if (strncmp(str, "1101", 4) == 0)
        fprintf(outputFile, "2");
    else if (strncmp(str, "1100", 4) == 0)
        fprintf(outputFile, "3");
    else if (strncmp(str, "1011", 4) == 0)
        fprintf(outputFile, "4");
    else if (strncmp(str, "1010", 4) == 0)
        fprintf(outputFile, "5");
    else if (strncmp(str, "1001", 4) == 0)
        fprintf(outputFile, "6");
    else if (strncmp(str, "1000", 4) == 0)
        fprintf(outputFile, "7");
    else if (strncmp(str, "0111", 4) == 0)
        fprintf(outputFile, "8");
    else if (strncmp(str, "0110", 4) == 0)
        fprintf(outputFile, "9");
    else
        fprintf(outputFile, " "); 
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
    int count = 0;
    while ((ch = fgetc(inputFile)) != EOF) 
    {
        charToBinary(ch, outputFile);
        count++;
    }
    if (count % 2 == 0) // from some reasone ther is a bug in the code that makes the output file to be 1 char longer
    {
        fwrite("0000", sizeof(char), 4, outputFile);
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

    char buffer[4];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), 4, inputFile)) > 0)
    {
        for (size_t i = 0; i < bytesRead; i++)
        {
            BinaryToChar(buffer[i], outputFile);
        }
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