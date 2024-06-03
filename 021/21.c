#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* concat(const char *str1, const char *str2)
{
    char *res;
    const char del[] = ", ";
    res = malloc(strlen(str1) + strlen(str2) + strlen(del) + 1);
    if (!res) {
        fprintf(stderr, "malloc() failed: insufficient memory!\n");
    }

    strcpy(res, str1);
    strcat(res, del);
    strcat(res, str2);

    printf("Result: (From Func.) '%s'\n", res);
    return res;
}

int main() {
   // printf() displays the string inside quotation
   // printf("Hello, World!");
   // return 0;

    const char str1[] = "First";
    const char str2[] = "Second";
    char* s = concat(str1, str2);
    printf("Result: (From Main.) '%s'\n", s);
    free(s);


}
