#include <stdio.h>

void myFunction(char *str) {
	printf("%s\n", str);
}

int main() {
	char myString[] = "This was made in Main";
	myFunction(myString);
	return 0;
}
