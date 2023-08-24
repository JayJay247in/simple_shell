#include "shell.h"

char* custom_getline() {

  static char* buffer = NULL;
  static size_t bufsize = 0;

  int bytes_read = 0;
  char* cursor = buffer;

  while (1) {
    // Read up to READ_SIZE chars at a time
    bytes_read = read(STDIN_FILENO, cursor, READ_SIZE);  

    if (bytes_read == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    }

    if (bytes_read == 0) {
      // EOF
      return NULL; 
    }

    // Null terminate
    cursor[bytes_read] = '\0';

    // Break at newline
    if (cursor[bytes_read-1] == '\n') {
      return buffer;
    }

    // Increase buffer size 
    bufsize += bytes_read;
    buffer = realloc(buffer, bufsize);

    cursor = buffer + bufsize - READ_SIZE;
  }
}
