#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* myName() {
  char *name = "Flavio";
  return name;
}

int main(void) {
  printf("%s", myName());
}
