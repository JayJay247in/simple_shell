#include "shell.h"

int exit_builtin(char** args) {
  return -1;
}

int main(int argc, char* argv[]) {

  while (1) {

    printf("%s", PROMPT);

    char* input = NULL;
    size_t bufsize = 0;
    getline(&input, &bufsize, stdin);

    char* token;
    char* args[2];
    int arg_count = 0;

    token = strtok(input, " \n");
    while (token != NULL) {
      args[arg_count++] = token;
      token = strtok(NULL, " \n");
    }
    args[arg_count] = NULL;

    if (strcmp(args[0], "exit") == 0) {
      return exit_builtin(args);
    }
  }
}
