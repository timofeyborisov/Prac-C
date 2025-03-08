#include <stdio.h>
#include <string.h>

const char
*my_strstr(const char *haystack, const char *needle)
{
    if (*needle == '\0') {
        return haystack;
    }
    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;
        while ((*h == *n) && (*h != '\0')) {
            ++n;
            ++h;
        }
        
        if (*n == '\0') {
            return haystack;
        }
        
        ++haystack;
    }
    return NULL;
}

int
main(void)
{
    char str[82];
    fgets(str, sizeof(str), stdin);
    const char *end = "end";
    const char *curr = my_strstr(str, end);;
    const char *ans = curr;
    
    while (curr != NULL) {
        ans = curr + strlen(end);
        curr = my_strstr(curr + 1, end);
    }
    
    ans = (ans != NULL) ? ans : str;
    printf("%s", ans);
    
    return 0;
}
