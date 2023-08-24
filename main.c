#include "shell.h"

int main(int argc, char* argv[]) {

  char* line = NULL;
  size_t bufsize = 0;

  while(1) {

    printf(PROMPT);

    getline(&line, &bufsize, stdin);

    if (feof(stdin)) {
      exit(EXIT_SUCCESS);
    }

    char* token = strtok(line, " \n\t");

    if (token == NULL) {
      continue;
    }

    char* args[] = {token, NULL};

    if (execve(token, args, NULL) == -1) {
      perror("simple_shell");
    }

  }

  free(line);
  return EXIT_SUCCESS;

}
