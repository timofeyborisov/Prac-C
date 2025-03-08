#include <stdio.h>
int
main(void) {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n < 0) {
            continue;
        }
        else {
            while (n >= 10) {
                int a;
                scanf("%d", &a);
                if (a >= 0) {
                    n -= a;
                }
            }
            if (n < 0) {
                printf("%d\n", n);
            }
            else if (n < 5) {
                int m;
                scanf("%d", &m);
                printf("%d\n", n + m);
                if (m < 0) {
                    break;
                }
            }
        }
    }
    return 0;
}
