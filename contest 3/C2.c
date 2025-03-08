#include <stdio.h>

unsigned gcd(unsigned a, unsigned b);

int
main(void)
{
    unsigned a, b;
    scanf("%u%u", &a, &b);
    printf("%u\n", gcd(a, b));
    return 0;
}

unsigned 
gcd(unsigned a, unsigned b) {
    if (a < b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    // a, b := b, a
    if (b == 0) {
        return a;
    // ans
    }
    else {
        return gcd(a % b, b);
    }
}
