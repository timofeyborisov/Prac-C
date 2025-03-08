#include <stdio.h>
#define MAX_LEN 100
int
main(void)
{
    int len;
    int a[MAX_LEN];
    
    scanf("%d", &len);
    
    if (len < 0 || len > MAX_LEN) {
        printf("Invalid len value\n");
        return 1;
    }
    
    // Read array
    for (int i = 0; i < len; i++) {
        scanf("%d", &a[i]);
    }
    
    // Even elements
    for (int i = 0; i < len; i++) {
        if (a[i] % 2 == 0) {
            printf("%d ", a[i]);
        }
    }
    
    // Odd elements
    for (int i = len - 1; i > -1; i--) {
        if (a[i] % 2 != 0) {
            printf("%d", a[i]);
            if (i > 0) {
                printf(" ");
            }
        }
    }
    
    printf("\n");
    
    return 0;
}
