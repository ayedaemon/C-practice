#include <stdio.h>


void fini() {
 printf("%s\n", __FUNCTION__);

}

void __attribute__ ((destructor)) destructor() {
 printf("%s\n", __FUNCTION__);
}
__attribute__((section(".fini_array"))) typeof(fini) *__fini = fini;

void do_something_at_end()
{
    printf("Bye bye\n");
}

int main()
{
    atexit(do_something_at_end);
    printf("Hello main\n");
    return 0;
}


