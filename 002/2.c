#include <stdio.h>  
#include <string.h>  
int main() {  
   char str[] = "Delhi,Hyderabad,Noida";  
   char *token;  
   /* get the first token */  
   token = strtok(str, ",");  
   /* loop through the string to extract all other tokens */  
   while(token != NULL) {  
      printf("%s\n", token);  
      token = strtok(NULL, ",");  
   }  
  
   return 0;  
}  
