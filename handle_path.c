#include "shell.h"

int main(int argc, char *argv[], char** envp) {
  char* line = NULL;
  size_t bufsize = 0;

  while (1) {

    // Print prompt
    printf("%s", PROMPT);

    // Read input
    getline(&line, &bufsize, stdin);
    
    // Tokenize input
    char* token;
    char* args[64];
    int arg_count = 0;
    char* saveptr;
    
    for (token = strtok_r(line, " \n", &saveptr); token != NULL; 
         token = strtok_r(NULL, " \n", &saveptr)) {
      args[arg_count++] = token;
    }

    // Check if command exists in PATH
    char* path = getenv("PATH");
    char prog[4096];
    
    if (args[0][0] == '/' || access(args[0], X_OK) == 0) {
      // Command with absolute path or in current directory
      strcpy(prog, args[0]);  
    } else {
      // Search PATH directories
      strcpy(prog, search_path(path, args[0])); 
    }

    if (strlen(prog) == 0) {
      perror("Command not found");
      continue;
    }

    // Execute command
    execve(prog, args, envp); 

  }
  return 0;
}

// Searches PATH for command
// Returns full path if found, empty string otherwise

char* search_path(char* path, char* cmd) {
  // Implementation left as exercise
}
