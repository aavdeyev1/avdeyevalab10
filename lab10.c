#include "lab10.h"

const int MAX = 100;
const int MAX_FIX = 150;

void textToBinary(char * theString, char * filename)
{
  int fd, result1, result2, result3, len, i, integer;
  len = strlen(theString);
  fd = open(filename, O_CREAT|O_RDWR);
  result1 = write(fd, &len, sizeof(int));
  int result4 = read(fd, &integer, sizeof(int));
  result2 = write(fd, theString, (len)*sizeof(char));
  result3 = close(fd);
  
}

char * binaryToText(char * filename)
{
  // don't modify this code
  char fix[MAX_FIX];
  strcpy(fix, "chmod 777 ");
  strcpy((fix+10), filename);
  printf("fix %s\n", fix);
  system(fix);
  
  // Your code goes below
  int fd, result1, result2, len;
  char * string = NULL;
  fd = open(filename, O_RDONLY);
  result1 = read(fd, &len, sizeof(int));
  string = (char *)calloc(len + 1, sizeof(char));
  result2 = read(fd, string, (len)*sizeof(char));
  close(fd);

  return string;
}

char * readString()
{
    char strtemp[100], *str = NULL;
    printf("Enter a string: ");
    fgets(strtemp, 100, stdin);
    stripCarriageReturn(strtemp);
    str = (char *)calloc(strlen(strtemp), sizeof(char *));
    strcpy(str, strtemp);
  return str;
}

int menu()
{
  int choice;
  do
  {
    printf("Please choose from the following\n");
    printf("1) Convert Text to Binary\n");
    printf("2) Convert Binary back to Text\n");
    printf("3) Quit\n");
    printf("Choice --> ");
    scanf("%d", &choice);
     while(fgetc(stdin) != '\n'){}

  }while(choice < 1 || choice > 3);
  return choice;
}

char * cleanUp(char* theString)
{
  free(theString);
  return NULL;
}

char * readFileName(char * type)
{
  char strtemp[100], *name = NULL;
  printf("%s\nfilename: ", type);
  fgets(strtemp, 100, stdin);
  stripCarriageReturn(strtemp);
  name = (char *)calloc(strlen(strtemp) + 1, sizeof(char));
  strcpy(name, strtemp);
  
  return name;
}

void stripCarriageReturn(char* str)
{
  int len = strlen(str);
  int x = 0;

  while(str[x] != '\0' && x < len)
  {
    if(str[x] == '\r')
      str[x] = '\0';

    else if(str[x] == '\n')
      str[x] = '\0';

    x++;
  }// end while
}// end function
