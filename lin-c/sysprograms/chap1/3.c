/*
Prog to get environment variable
*/

#include <stdio.h>
#include <stdlib.h>

int ask_to_set(char*);

int main(int argc, char** argv)
{
  if(argc<2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    exit(0);
  }

  char* value = getenv(argv[1]);
  if( !value )
  {
    printf("%s variable is not set\n", argv[1]);
    ask_to_set(argv[1]);
  }
  else
  {
    printf("%s : %s\n", argv[1], value);
  }

  return 0;
}
