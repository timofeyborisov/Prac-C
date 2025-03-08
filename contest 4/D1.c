#include <stdio.h>
int
main(void)
{
    char str[82];
    char *p;
    p = fgets(str, sizeof(str), stdin);
    if (p == NULL) {
        printf("EMPTY INPUT\n");
    }
    else {
        printf("%s", str);
    }
    return 0;
}
