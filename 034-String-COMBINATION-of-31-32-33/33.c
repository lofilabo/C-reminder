#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
char* getString(char *str) { 
	printf("%s\n", str);
	char* return_string = "This was made in the Function"; 
	return strdup(return_string);
} 
 
int main() { 
	char myString[] = "This was made in Main";
	char* comeback = getString(myString); 
	printf("%s\n", comeback); 
	return 0; 
}
