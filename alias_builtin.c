#include "shell.h"

char* aliases[MAX_ALIASES];

void print_aliases() {
  for (int i = 0; i < MAX_ALIASES; i++) {
    if (aliases[i]) {
      printf("%s\n", aliases[i]);
    }
  }
}

void set_alias(char* name, char* value) {

  int i;
  for (i = 0; i < MAX_ALIASES; i++) {
    if (aliases[i] == NULL) {
      aliases[i] = malloc(strlen(name) + strlen(value) + 2);
      sprintf(aliases[i], "%s=%s", name, value);
      break;
    } else if (strcmp(name, strtok(aliases[i], "=")) == 0) {
      // Reassign existing alias
      free(aliases[i]);
      aliases[i] = malloc(strlen(name) + strlen(value) + 2); 
      sprintf(aliases[i], "%s=%s", name, value);
      break;
    }
  }

  if (i == MAX_ALIASES) {
    printf("Alias limit reached\n");
  }

}

int alias_builtin(char** args) {

  if (args[1] == NULL) {
    print_aliases();
  } else {
    char* name = strtok(args[1], "=");
    if (args[2]) {
      // Set alias
      char* value = args[2];
      set_alias(name, value); 
    } else {
      // Print single alias
      printf("%s\n", find_alias(name));
    }
  }

  return 0;
}
