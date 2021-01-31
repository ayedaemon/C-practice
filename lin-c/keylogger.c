#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char* get_keyboards()
{
  char *kbd[5];
  FILE *fp;
  char *dev_path = "/dev/input/by-path/";
  char buff[255];
  printf("**** Getting Attached Keyboards ****\n");
  fp = fopen(dev_path, "r");
  fscanf(fp, "%s", buff);
   printf("1 : %s\n", buff );


}









int main(int argc, char **argv)
{
  get_keyboards();

  // int fd;
  // if(argc < 2) {
  //   printf("usage: %s <device>\n", argv[0]);
  //   return 1;
  // }
  //
  // fd = open(argv[1], O_RDONLY);
  // struct input_event ev;
  //
  // while (1)
  // {
  //   read(fd, &ev, sizeof(struct input_event));
  //
  //   if(ev.type == 1)
  //     printf("key %i state %i\n", ev.code, ev.value);
  //
  // }
}
