#include <stdbool.h>
#include <stdio.h>

static char input[2048];

int main() {
  puts("Lispy Version 0.1");
  puts("Press Ctrl+c to Exit\n");

  while (true) {
    fputs("lispy> ", stdout);
    fgets(input, 2048, stdin);
    printf("No you're a %s", input);
  }
}
