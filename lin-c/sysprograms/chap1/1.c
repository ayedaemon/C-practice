/*
Prog to read from terminal and printing it on screen.
*/
#include <stdio.h>

int main()
{
  int c;
  while( (c = getchar()) != EOF )
  {
    putchar(c);
  }
  return 0;
}
