#include<stdio.h>
#include<stdlib.h> // For declaration of exit()

void hello()
{
    printf("hello");
}

int main()
{
  printf("This is main function\n");
  
  return 0;
}

// void _start()
// {
//     int x = my_fun(); //calling custom main function
//     exit(x);
// }
// 
// int my_fun() // our custom main function
// {
//     printf("Surprise!!\n");
//     at_exit(main);
//     return 0;
// }

