#include <stdio.h>
#include <string.h>

enum {MAX_SIZE = 257};

int
main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    FILE *t = tmpfile();
    
    char s_haystack[MAX_SIZE];
    char *s_needle = argv[2];
    char *ptr = strchr(s_needle, '\n');
    if (ptr != NULL) {
        *ptr = '\0';
    }
    
    while (fgets(s_haystack, sizeof s_haystack, f) != NULL) {
        if (strstr(s_haystack, s_needle) != NULL) {
            fputs(s_haystack, t);
        }
    }
    
    fseek(t, 0, SEEK_SET);
    fclose(f);
    f = fopen(argv[1], "w");
    
    char s[MAX_SIZE];
    while (fgets(s, sizeof s, t) != NULL) {
        fputs(s, f);
    }

    fclose(f);
    fclose(t);
    return 0;
}
