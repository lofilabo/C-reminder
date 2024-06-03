#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
char* getString() { 
    char* str = "This was made in the Function"; 
    return strdup(str); // Duplicate the string to ensure safety 
} 
 
int main() { 
    char* comeback = getString(); 
    printf("%s\n", comeback); 
    return 0; 
}
