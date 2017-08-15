#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include <editline/history.h>

int main(int argc, char **argv) {
  puts("MyLISP v. 0.0.2-SNAPSHOT");
  puts("Press Ctrl-c to exit.\n");

  while (1) {
    char *input = readline("ml> ");
    add_history(input);
    printf("Echo: %s\n", input);
    free(input);
  }

  return 0;
}
