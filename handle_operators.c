#include "shell.h"

int execute(char** args) {
  // Fork and execute command
  return exit_status; 
}

int main() {

  while (1) {

    char* input = NULL;
    size_t bufsize = 0;
    getline(&input, &bufsize, stdin);

    char* tok = strtok(input, ";&|");
    char* commands[100];
    int i = 0;

    while (tok != NULL) {
      commands[i++] = tok;
      tok = strtok(NULL, ";&|");
    }

    commands[i] = NULL;

    // Parse and execute each command 
    i = 0;
    int prev_status = EXIT_SUCCESS;
    while (commands[i] != NULL) {
      
      if (strcmp(commands[i], "&&") == 0) {
        // Only execute next if prev succeeded
        if (prev_status == EXIT_SUCCESS) {
          prev_status = execute(commands[++i]);
        } else {
          i++; // Skip next command
        }
      } else if (strcmp(commands[i], "||") == 0) { 
        // Only execute next if prev failed
        if (prev_status != EXIT_SUCCESS) {
          prev_status = execute(commands[++i]);
        } else {
          i++; // Skip next command
        }
      } else {
        prev_status = execute(commands[i++]);
      }
      
    }

  }

}
