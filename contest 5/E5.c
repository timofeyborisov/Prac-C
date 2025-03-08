#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum {SIZE = 82};

void
str_with_begin(const char *m[])
{
    const char *begin = "begin";
    while (*m) {
        if (strstr(*m, begin) != NULL) {
            printf("%s\n", *m);
        }
        m++;
    }
}

int
partition(char *str, char *m[])
{
    int c = 0;
    char *ptr = NULL;
    while (*str) {
        if (isalpha(*str)) {
            if (ptr == NULL) {
                ptr = str;
            }
        }
        else {
            if (ptr != NULL) {
                *str = '\0';
                // end of word
                m[c++] = ptr;
                ptr = NULL;
            }
        }
        ++str;
    }
    
    if (ptr != NULL) {
        m[c++] = ptr;
    }
    
    m[c] = NULL;
    
    return c;
}

int
main(void)
{
    char str[SIZE];
    char *m[SIZE];
    
    fgets(str, sizeof(str), stdin);
    partition(str, m);
    str_with_begin((const char **)m);
    
    return 0;
}
