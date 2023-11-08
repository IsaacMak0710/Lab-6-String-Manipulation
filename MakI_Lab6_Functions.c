#include "MakI_Lab6.h"

//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   Prints the Header to the screen
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE *outputFile, char school[], char lab[], char programmer[]) {
  PrintDivider(outputFile, STAR, DIVIDER_LENGTH);
  
  CenterString(outputFile, school, DIVIDER_LENGTH);
  CenterString(outputFile, lab, DIVIDER_LENGTH);
  CenterString(outputFile, programmer, DIVIDER_LENGTH);

  PrintDivider(outputFile, STAR, DIVIDER_LENGTH);
}

//-----------------------------------------------------------------------------
// Function Name: PrintDivider
// Description:
//   Symbols will be printed to the screen.
//
//-----------------------------------------------------------------------------
void PrintDivider(FILE *outputFile, char symbol, int numberOf) {
  // Print a bunch of symbols across the screen
  for (int counter = 0; counter < numberOf; counter++) {
    // Print one character to the screen
    fprintf(outputFile, "%c", symbol);
  }

  // Move the cursor down to the next line
  fprintf(outputFile, "\n");
}

//-----------------------------------------------------------------------------
// Function Name: CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void CenterString(FILE *outputFile, char string[], int lengthToCenterAcross) {
  // Capture how long the string is
  // Cast to an integer because strlen technically returns size_t
  int stringLength = (int)strlen(string);

  // Calculate the width to print the string in
  int width = (lengthToCenterAcross + stringLength) / 2;

  // Calculate how many blank spaces are needed before printing the string
  int numberOfBlankSpaces = width - stringLength;

  // Print the spaces needed to center the string
  for (int counter = 0; counter < numberOfBlankSpaces; counter++) {
    // Print one space
    fprintf(outputFile, " ");
  }

  // Print the string
  fprintf(outputFile, "%s", string);
}

//-----------------------------------------------------------------------------
// Function Name: DecryptPoem
// Description:
//    To decrypt, subtract 25 from the ascii value from each character that isn't the enter key and put the output into the output file
//
//-----------------------------------------------------------------------------
void DecryptPoem(FILE* pInputFile, FILE* pOutputFile, char string[])
{
  int character;

  // Loop through whole file
  while ((character = fgetc(pInputFile)) != EOF)
  {
    // If the character isn't the enter key, subtract 25, otherwise add the enter key
    if (character != '\n') 
    {
      character -= 25;
      
      if (character >= 'a' && character <= 'z') 
      {
        character -= 'a' - 'A';
      }

      fputc(character, pOutputFile);
    } 
    else 
    {
      fputc('\n', pOutputFile);
    }
  }
}

//-----------------------------------------------------------------------------
// Function Name: EncryptPoem
// Description:
//   To encrypt, add 16 to the ascii value to each character that isn't the enter key and put the output into the output file
//
//-----------------------------------------------------------------------------
void EncryptPoem(FILE* pInputFile, FILE* pOutputFile, char string[])
{
  int character;

  // Loop through whole file
  while ((character = fgetc(pInputFile)) != EOF)
  {
    // If the character isn't the enter key, add 16, otherwise add the enter key
    if (character != '\n') 
    {
      character += 16;

      fputc(character, pOutputFile);
    } 
    else 
    {
      fputc('\n', pOutputFile);
    }
  }
}
