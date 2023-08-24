#include "shell.h"

char* get_env_value(char** envp, char* var);

int cd_builtin(char** args, char** envp) {

  char* dir;
  if (args[1] == NULL) {
    // cd with no args - go home
    dir = get_env_value(envp, "HOME"); 
  } else if (strcmp(args[1], "-") == 0) {  
    // cd - 
    dir = get_env_value(envp, "OLDPWD");
  } else {
    // cd to specified dir
    dir = args[1]; 
  }

  if (chdir(dir) != 0) {
    perror("chdir");
    return 1;
  }

  // Update PWD env variable
  set_env_value(envp, "PWD", getcwd(NULL, 0));  

  return 0;
}

int main(int argc, char** argv, char** envp) {

  // Shell loop
  while (1) {

    char** args = handle_input();

    if (args[0] && strcmp(args[0], "cd") == 0) {
      cd_builtin(args, envp);
    }
  }
}
