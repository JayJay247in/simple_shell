#include "shell.h"

int execute(char** args) {
  // Execute command
  return exit_status; 
}

char* replace_vars(char* input) {

  char *replaced = malloc(strlen(input) + 1);
  strcpy(replaced, input);

  char *var, *val, *pos;

  // Handle $?
  if((pos = strstr(replaced, "$?")) != NULL) {
    sprintf(val, "%d", last_exit_code); 
    *pos = '\0';
    replaced = realloc(replaced, strlen(replaced) + strlen(val) + 1);
    strcat(replaced, val);
    strcat(replaced, pos+2);
  }

  // Handle $$
  if((pos = strstr(replaced, "$$")) != NULL) {
    sprintf(val, "%d", getpid());
    *pos = '\0';
    replaced = realloc(replaced, strlen(replaced) + strlen(val) + 1);
    strcat(replaced, val);
    strcat(replaced, pos+2);
  }

  return replaced;

}

int main() {

  while (1) {
    char* input = read_input();
    
    input = replace_vars(input);
    
    char** args = parse(input);
    execute(args);
  }  

}
