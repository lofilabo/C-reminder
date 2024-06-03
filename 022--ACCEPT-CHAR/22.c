#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Within this function, `line` is initially a pointer to the first
// char in a string (Null terminated char array).
void f(char *line)
{
	printf("%s\n", line);
}


int main()
{
	char line[] = "gdgegryt";
	f(line);
	return 0;
}


/*
ORIGINAL:


void f(char *line)
{
printf("%s\n", line);
  // Continue if the value pointed at by `line` is not NUL
  while (*line) {
    // Dereference `line` and assign a new value '0'
    // then advance the pointer
    *(line++) = '0';
  }
}


int main()
{
	char line[] = "gdgegryt";
	f(line);
	printf("%s\n", line);
	return 0;
}

*/
