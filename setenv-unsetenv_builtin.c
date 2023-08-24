#include "shell.h"

/* Set environment variable */
int setenv_builtin(char** args, char** envp) {
  if (!args[1] || !args[2]) {
    fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
    return 1;
  }

  char* name = args[1];
  char* value = args[2];

  char* entry = malloc(strlen(name) + strlen(value) + 2);
  sprintf(entry, "%s=%s", name, value);

  // Add to envp array
  envp = realloc(envp, sizeof(char*) * (num_vars + 2));
  envp[num_vars++] = entry;
  envp[num_vars] = NULL;

  return 0;  
}

/* Unset environment variable */
int unsetenv_builtin(char** args, char** envp) {
  if (!args[1]) {
    fprintf(stderr, "Usage: unsetenv VARIABLE\n");
    return 1;
  }

  char* name = args[1];
  int pos = find_var(name, envp);

  if (pos == -1) {
    fprintf(stderr, "Variable %s not found\n", name);
    return 1; 
  }

  // Remove variable from envp
  memmove(&envp[pos], &envp[pos + 1], sizeof(char*) * (num_vars - pos));
  envp = realloc(envp, sizeof(char*) * (--num_vars + 1));
  envp[num_vars] = NULL;

  return 0;
}
