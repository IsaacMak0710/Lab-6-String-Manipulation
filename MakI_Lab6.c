/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Isaac Mak
| Course:           CS-211: Introduction to Programming for Engineers
| Program  Name:    Lab #6
| Date:             11/07/2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   Part 1:
|     Take a input file with decrypted text and create a function to decrypt each string
|   Then print the characters to the output file
|   Part 2:
|     Take a poem from the internet and encrypt it
|     Then output it into an output file
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   The inputs will be the two data files, the encrypted poem in part 1, and the decrypted poem in part 2
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   To decrypt, subtract each character that isn't the enter key by 25 from the ascii value
|   To encrypt, add 16 to the ascii value to each character that isn't the enter key
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   The decrypted poem from the "Encrypted_Poem.txt" and the encrypted poem from the part 2 "Part2DecryptedPoem.txt"
|
|--------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "MakI_Lab6.h"

int main(void) {

  // Declare Input and Output arrays
  char inputString[ARR_SIZE] = "";
  char outputString[ARR_SIZE] = "";

  // Declare Input and Output Files
  FILE* pInputFile = fopen("Encrypted_Poem.txt", "r");
  FILE* pInputFile1 = fopen("Part2DecryptedPoem.txt", "r");
  FILE* pOutputFile = fopen("Decrypted_Poem.txt", "w");
  FILE* pOutputFile1 = fopen("New_Encrypted_Poem.txt", "w");

  // Failsafe
  if (pInputFile == NULL || pOutputFile == NULL) 
  {
    perror("File opening failed");
    return 1;
  }

  // Print Header
  PrintHeader(pOutputFile, SCHOOL, LAB, PROGRAMMER);
  PrintHeader(pOutputFile1, SCHOOL, LAB, PROGRAMMER);

  //Main Code
  DecryptPoem(pInputFile, pOutputFile, inputString);
  EncryptPoem(pInputFile1, pOutputFile1, outputString);

  fclose(pInputFile);
  fclose(pOutputFile);

  return 0;
}