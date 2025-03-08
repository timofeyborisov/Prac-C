#include <stdio.h>
int
main(void)
{
    unsigned long long a;
    int ans = 0;
    scanf("%llu", &a);
    for (int i = 0; i < (sizeof(a) * 8); i++) {
        ans += (a % 2);
        a = (a >> 1);
    }
    printf("%d\n", ans);
    return 0;
}
