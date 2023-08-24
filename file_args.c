#include "shell.h"

int execute(char* cmd) {
  // tokenize and execute command
  return 0; 
}

int main(int argc, char** argv) {

  if (argc > 1) {
    // Batch mode from file
    
    FILE* batch_file = fopen(argv[1], "r");
    if (!batch_file) {
      fprintf(stderr, "Error opening file\n");
      exit(1);
    }

    char* line = NULL;
    size_t len = 0;
    while (getline(&line, &len, batch_file) != -1) {
      execute(line);
    }

    fclose(batch_file);

  } 
    else {  
      // Interactive mode
  
      // Print prompt
      // Get input
      // Execute input
    }
}
