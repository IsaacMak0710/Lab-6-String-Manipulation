#ifndef MAKI_LAB6_H
#define MAKI_LAB6_H

#include <string.h>
#include <stdio.h>

// Macros
#define DIVIDER_LENGTH 110
#define STAR '*'
#define DASH '-'
#define SCHOOL "Binghamton University\n"
#define LAB "Lab 6 - String Manipulation\n"
#define PROGRAMMER "Program Written by: Isaac Mak\n"

#define ARR_SIZE 60

// Function Prototypes
void PrintHeader(FILE *outputFile, char school[], char lab[], char programmer[]);

void PrintDivider(FILE *outputFile, char symbol, int numberOf);

void CenterString(FILE *outputFile, char string[], int lengthToCenterAcross);

void DecryptPoem(FILE* pInputFile, FILE* pOutputFile, char string[]);

void EncryptPoem(FILE* pInputFile, FILE* pOutputFile, char string[]);

#endif