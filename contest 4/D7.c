#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
symb_perm (char *str) {
    char digits[82] = {0};
    char symbols[82] = {0};
    char *i_dig = digits;
    char *i_sym = symbols;
    char *s = str;
    
    while (*s) {
        if (isdigit(*s)) {
            *i_dig++ = *s;
        }
        else {
            *i_sym++ = *s;
        }
        ++s;
    }
    
    // Reversing symbols
    
    char *l = symbols;
    char *r = i_sym - 1;
    while (l <= r) {
        char temp = *l;
        *l++ = *r;
        *r-- = temp;
    }
    
    strcpy(str, digits);
    strcat(str, symbols);
}

int
main(void)
{
    char str[82];
    fgets(str, sizeof(str), stdin);
    *strchr(str, '\n') = '\0';
    symb_perm(str);
    printf("%s\n", str);
    return 0;
}
