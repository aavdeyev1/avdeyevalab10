#ifndef LAB10_H
#define LAB10_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int menu();
char * readString();
char * readFileName(char * type);
char * cleanUp(char* theString);
char * binaryToText(char * fileName);
void textToBinary(char * theString, char * fileName);

void stripCarriageReturn(char* str);

#endif
