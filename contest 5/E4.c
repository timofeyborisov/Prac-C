#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum {SIZE = 82};

size_t
def_len(const char *m[]) {
    size_t len = 0;
    while (*m) {
        if (strlen(*m) > len) {
            len = strlen(*m);
        }
        m++;
    }
    return len;
}

void
long_str(const char *m[], size_t len)
{
    while (*m) {
        if (strlen(*m) == len) {
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
    
    size_t len = def_len((const char **)m);
    long_str((const char **)m, len);
    
    return 0;
}
