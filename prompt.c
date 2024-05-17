#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char *readline(char *prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char *cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy) - 1] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char *unused) {}

#else
#include <editline.h>
#endif

int main() {
  puts("Lispy Version 0.1");
  puts("Press Ctrl+c to Exit\n");

  while (true) {
    char *input = readline("lispy> ");
    add_history(input);

    printf("No you're a %s\n", input);
    free(input);
  }
  return 0;
}
