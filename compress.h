#include <stdio.h>


void charToBinary(char ch, FILE *outputFile);
void BinaryToChar(char ch, FILE *outputFile);


void convertFileToBinary(const char *inputFileName, const char *outputFileName);
void convertBinaryToText(const char *inputFileName, const char *outputFileName);

void changeFileExtension(const char *inputFileName, char *outputFileName, const char *newExtension);
