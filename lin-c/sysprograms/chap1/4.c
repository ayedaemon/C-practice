/*
get thread id
*/

#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
  printf("Thread id %ld\n", syscall(SYS_gettid));
  printf("Thread id %ld\n", syscall(__NR_gettid));
  printf("Process Id %ld \n", getpid());
  return 0;
}
