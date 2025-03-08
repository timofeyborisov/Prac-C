#include <stdio.h>

int
main(void)
{
    unsigned n;
    if (scanf("%x", &n) != 1) {
        printf("Incorrect input\n");
        return 0;
    }
    printf("%X\n", (
        (n & (unsigned)4294967281) ^ 2031616
    ));
}
