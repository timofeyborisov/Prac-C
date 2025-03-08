#include <stdio.h>

size_t
strlen(const char *s) {
    int len = 0;
    while (*s != '\0') {
        len++;
        s++;
    }
    return len;
}

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
contain(const char *s1, const char *s2) {
    // s1 - address of first string 
    // s2 - address of second string 
    
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    
    if (len1 > len2) {
        return 0;
    }
    char const *s2_start = s2 + len2 - len1;
    // offset
    
    for (int i = 0; i < len1; i++) {
        if (*s1 != *s2_start) {
            return 0;
        }
        s1++;
        s2_start++;
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
    
    if (contain(str1, str2) == 1) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    
    return 0;
}
