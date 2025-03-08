#include <stdio.h>

void
zeroing(char *p) {
    while (*p != '\0') {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
        p++;
    }
}
        
int
equal(const char *s1, const char *s2) {
    // s1 - address of first string 
    // s2 - address of second string 
    
    while ((*s1 != '\0') || (*s2 != '\0')) {
        while (*s1 == ' ') {
            s1++;
        }
        while (*s2 == ' ') {
            s2++;
        }
        if (*s1 != *s2) {
            return 0;
        }
        s1++;
        s2++;
    }
    if ((*s1 != '\0') || (*s2 != '\0')) {
        return 0;
    }
    
    return 1;
}

int 
main(void) {
    char str1[82];
    char str2[82];
    // 80 + \n + \0
    
    zeroing(fgets(str1, sizeof(str1), stdin));
    zeroing(fgets(str2, sizeof(str2), stdin));
    
    if (equal(str1, str2) == 1) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    
    return 0;
}
