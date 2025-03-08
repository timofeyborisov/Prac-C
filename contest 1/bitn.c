#include <stdio.h>

int
main(void)
{
    unsigned n;
    int i;
    if (scanf("%x%d", &n, &i) != 2) {
        printf("Incorrect input\n");
        return 0;
    }
    printf("%u\n", ( 
        (n << (31 - i)) >> 31
                /* WRITE EXPRESSION HERE */
    ));
}
