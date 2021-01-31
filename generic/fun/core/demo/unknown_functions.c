#include <stdio.h>

/*
void fini() {
 printf("%s\n", __FUNCTION__);

}*/

void preinit(int argc, char **argv, char **envp) {
 printf("%s\n", __FUNCTION__);
 printf("%d , %s , %s\n", argc, *argv, *envp);
 printf("CLI arg : %s\n", argv[1]);
}

// void init(int argc, char **argv, char **envp) {
//  printf("%s\n", __FUNCTION__);
//  printf("%d , %s , %s\n", argc, *argv, *envp);
//  printf("CLI arg : %s\n", argv[1]);
// }


// void  __attribute__ ((constructor)) constructor() {
//  printf("%s\n", __FUNCTION__);
// }
// 
// void __attribute__ ((destructor)) destructor() {
//  printf("%s\n", __FUNCTION__);
// }
// int main2() {
//   printf(" This is another main");
// }


// __attribute__((section(".init_array"))) typeof(init) *__init = init;
__attribute__((section(".preinit_array"))) typeof(preinit) *__preinit = preinit;
// __attribute__((section(".fini_array"))) typeof(fini) *__fini = fini;



int main(int argc, char **argv, char **envp) {
    printf("This is %s\n",__FUNCTION__);
    printf("%d , %s , %s\n", argc, *argv, *envp);
    printf("CLI arg : %s\n", argv[1]);
    return 0;
}
