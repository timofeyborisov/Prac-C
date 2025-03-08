#include <stdio.h>
char
*my_strcat(char *s1, const char *s2) {
    char *i = s1;
    while (*s1 != '\0') {
        s1++;
    }
    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return i;
}
int
main(void)
{
    char st1[164];
    char st2[82];
    char *p1, *p2;
    
    p1 = fgets(st1, sizeof(st1), stdin);
    p2 = fgets(st2, sizeof(st2), stdin);
    
    while (*p1 != '\0') {
        if (*p1 == '\n') {
            *p1 = '\0';
            break;
        }
        p1++;
    }
    while (*p2 != '\0') {
        if (*p2 == '\n') {
            *p2 = '\0';
            break;
        }
        p2++;
    }
    my_strcat(st1, st2);
    printf("%s\n", st1);
    return 0;
}






#include <stdio.h>

int
contain(const char *s1, const char *s2) {
    int len1 = 0;
    int len2 = 0;
    
    while (*s1 != '\0') {
        s1++;
        len1++;
        // until the end of str1
    }
    while (*s2 != '\0') {
        s2++;
        len2++;
    }
    
    if (len1 > len2) {
        return 0;
    }
    
    for (int c = 0; c < len1; c++) {
        if (*s1 != *s2) {
            return 0;
        }
        s1--;
        s2--;
    }
    return 1;
}

int main(void)
{
    char st1[82];
    char st2[82];
    char *p1, *p2;
    
    p1 = fgets(st1, sizeof(st1), stdin);
    p2 = fgets(st2, sizeof(st2), stdin);
    
    while (*p1 != '\0') {
        if (*p1 == '\n') {
            *p1 = '\0';
            break;
        }
        p1++;
    }
    while (*p2 != '\0') {
        if (*p2 == '\n') {
            *p2 = '\0';
            break;
        }
        p2++;
    }
    
    if (contain(st1, st2) == 1) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
