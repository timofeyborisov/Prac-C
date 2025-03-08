#include <stdio.h>

unsigned 
gcd(unsigned a, unsigned b) {
    while ((a != 0) && (b != 0)) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    return a + b;
}

int
main(void)
{
    unsigned a, b;
    scanf("%u%u", &a, &b);
    printf("%u\n", gcd(a, b));
    return 0;
}
