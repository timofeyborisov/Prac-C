#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    for (int i = 1; argv[i] != NULL; i++) {
        printf("%s\n", argv[i]);
    }
    
    for (int i = 1; argv[i] != NULL; i++) {
        char *ptr = strstr(argv[i], "end");
        int c = 0;
        while (1) {
            if (ptr == NULL) {
                break;
            }
            c++;
            if (c == 2) {
                printf("%s\n", ptr + 3);
                break;
            }
            ptr = strstr(++ptr, "end");
        }
    }
    
    return 0;
}
