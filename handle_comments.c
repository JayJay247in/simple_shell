#include "shell.h"

char* read_input() {
  char* line = NULL;
  size_t bufsize = 0;

  getline(&line, &bufsize, stdin);
  
  return line;
}

char** parse(char* line) {

  char** tokens = malloc(64 * sizeof(char*));
  char* token;
  int i = 0;

  token = strtok(line, " \t\n");

  while (token != NULL) {
    if (token[0] == '#') {
      // Rest of line is comment
      break;
    }

    tokens[i] = token;
    i++;

    token = strtok(NULL, " \t\n");
  }

  tokens[i] = NULL; // Null terminate args

  return tokens;

}

int main() {

  while (1) {
    char* line = read_input();
    char** args = parse(line);

    // Execute args

  }

}
