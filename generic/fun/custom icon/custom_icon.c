/*
This is a demo for how to create a custom icon for your c program
Here, I have used MinGW to compile my program

*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  FILE * fPtr;
  fPtr = fopen("Hell-O.txt", "w");
  if(fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    fputs("hell-O there!", fPtr);

  return 0;
}
