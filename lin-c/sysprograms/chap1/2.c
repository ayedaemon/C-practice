/*
get pid and ppid of the program
*/


#include <stdio.h>

int main()
{
  printf("Process ID : %d \n", getpid());
  printf("Parent Process ID : %d \n", getppid());  
}
