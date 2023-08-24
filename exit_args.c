#include "shell.h"

int exit_builtin(char **args) {
  int status = 0;

  if (args[1]) {
    status = atoi(args[1]);
  }

  exit(status);
}

int main(int argc, char* argv[]) {

  while (1) {
    // Read input

    int main() {
      char **args = parse_input(input);

      if (args[0] && strcmp(args[0], "exit") == 0) {
        exit_builtin(args);
      }
      handle_input(args);
    }
  }
  return 0;
}
