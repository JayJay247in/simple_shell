#include "shell.h"

int main(int argc, char *argv[]) {
  char *line = NULL;
  size_t bufsize = 0;

  while (1) {
    printf("%s", PROMPT);

    getline(&line, &bufsize, stdin);

    char *token, *saveptr;
    char *args[64];
    int arg_count = 0;

    for (token = strtok_r(line, " \n", &saveptr); token != NULL; 
         token = strtok_r(NULL, " \n", &saveptr)) {

      args[arg_count++] = token;

    }

    args[arg_count] = NULL; // null terminate args

    if (strcmp(args[0], "exit") == 0) {
      break;
    }

    if (execvp(args[0], args) == -1) {
      perror("execvp");
    }

  }

  free(line);

  return 0;
}
