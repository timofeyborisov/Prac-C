#include <stdio.h>
#include <limits.h>
enum {SIZE = 100};
// const
int
main(void)
{
    char buf[SIZE] = {0};
    // array
    long long n;
    scanf("%lld", &n);
    int i = 0;
    int of = 0;
    // if n = LLONG_MIN 
    // we increase the number by 1 so that 
    // we can take the modulus and not go 
    // beyond the range
    
    // flags
    int first = 1;
    // least significant digit of a number
    int negative = 0;
    // if n is negative
    
    if (n == LLONG_MIN) {
        n += 1;
        of = 1;
    }
    
    // if n is negative
    if (n < 0) {
        negative = 1;
        n = -n;
    }
    
    // write array
    do {
        buf[i] = (n % 10) + '0';
        if (first) {
            buf[i] += of;
            first = 0;
        }
        i++;
        n /= 10;
    } while (n != 0);
    // "do" to check case 0
    
    // if n is negative
    if (negative) {
        buf[i++] = '-';
    }
    
    // flipping array
    buf[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        // temporary value
        char t = buf[j];
        buf[j] = buf[i - j - 1];
        buf[i - j - 1] = t;
    }
    
    printf("%s\n", buf);
    return 0;
}
