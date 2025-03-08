#include <stdio.h>

int
main(void)
{
    short s1, s2;
    if (scanf("%hX%hX", &s1, &s2) != 2) {
        printf("Incorrect input\n");
        return 0;
    }
    printf("%X\n", (
        ((unsigned int)s2 << 16) |
        ((int)s1 & 0xFFFF)
        /* WRITE EXPRESSION HERE */
    ));
}
