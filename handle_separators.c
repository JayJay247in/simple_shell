#include "shell.h"

int main() {

  char* line = NULL;
  size_t len = 0;

  while(1) {

    // Print prompt
    printf("shell$ ");

    // Read input
    getline(&line, &len, stdin);

    // Tokenize on ';'
    char* tok = strtok(line, ";");
    
    while(tok != NULL) {
    
      // Execute command
      char* args[] = {tok, NULL};
      execvp(args[0], args);

      // Next command 
      tok = strtok(NULL, ";");

    }

  }

  return 0;

}
