#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum {SIZE = 82};

void
first_three(const char *m[])
{
    while (*m) {
        if (strlen(*m) >= 3) {
            
            printf("%.*s\n", 3, *m);
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
    char str[82];
    char *m[SIZE];
    
    fgets(str, sizeof(str), stdin);
    
    partition(str, m);
    first_three((const char **)m);
    
    return 0;
}
