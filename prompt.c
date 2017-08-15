#include <stdio.h>

static char input[2048];

int main(int argc, char **argv) {
  puts("MyLISP v. 0.0.1-SNAPSHOT");
  puts("Press Ctrl-c to exit.\n");

  while (1) {
    fputs("ml> ", stdout);
    fgets(input, 2048, stdin);
    printf("Echo: %s", input);
  }

  return 0;
}
