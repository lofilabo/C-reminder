#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* myFunc(char *line) {
	printf("%s\n", line);
  	char *name = "Born myFunc";
  	return name;
}

int main(void) {

	char line[] = "Born main";
	printf("%s", myFunc(line));
	/*
	capture the val returned, assign it to a variable, and print the variable
	*/
}
