#include "lab10.h"

int main(void)
{
  int choice;
  char * filename = NULL, *theString=NULL;

  filename = readFileName("Text to Binary");
  theString = readString();
  textToBinary(theString, filename);
    
  do
  {
    choice = menu();

    switch(choice)
    {
      case 1: filename = cleanUp(filename); 
              filename = readFileName("Text to Binary");
              theString = cleanUp(theString);
              theString = readString();
              textToBinary(theString, filename);
              break;
      
      case 2: filename = cleanUp(filename); 
              filename = readFileName("Binary to Text"); 
              theString = cleanUp(theString);
              theString = binaryToText(filename);
              printf("The original string was: %s\n", theString);
              break;

      case 3: printf("Ending\n");
    }// end switch

  }while(choice != 3);

  filename = cleanUp(filename); 
  theString = cleanUp(theString);

  return 0;
}