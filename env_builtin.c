#include "shell.h"

int print_env(char** args, char** envp) {
  for (int i = 0; envp[i] != NULL; i++) {
    printf("%s\n", envp[i]);
  }
  return 0;
}

int main(int argc, char* argv[], char** envp) {

  while (1) {
    
    print_prompt();
    
    char* input = NULL;
    size_t bufsize = 0;
    getline(&input, &bufsize, stdin);
    
    char** args = parse_input(input);

    if (strcmp(args[0], "env") == 0) {
      print_env(args, envp);
    }   
  }
}
