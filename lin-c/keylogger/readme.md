## Basic keylogger for linux

> This program reads all the keyboard events.

#### Code Flow

1. Scan `INPUT_EVENT_DIR` folder (from `main.h` file) for all the files and search for the first file which has `kbd` (keyboard) mentioned in it.

2. Open the keyboard event file (a char file) and read all the events.

3. Go undercover by `daemonizing` the process.

4. read for all the key events and log them to `LOG_FILE` (from `main.h`) file.


#### TO-DO

- [ ] Monitor all the keyboards.
- [ ] Monitor mouse clicks.
- [ ] Send logs to remote server.
