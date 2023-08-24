#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROMPT "simple_shell$ "
#define READ_SIZE 1024
#define MAX_ALIASES 64
#define MAX_ARGS 64

// Function prototypes
char* read_input();
char** parse(char*); 
void print_prompt();
int execute_args(char** args);
int execute_cmd(char* cmd);
int cd_builtin(char**, char**);
int alias_builtin(char**);
int exit_builtin(char**);
char* replace_vars(char*);
char* search_path(char*, char*);

// External variables
extern int last_exit_code;
extern int num_vars;
extern char* input;
extern int exit_status;

#endif /* SIMPLE_SHELL_H */
