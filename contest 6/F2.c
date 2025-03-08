#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    int N;
    scanf("%d", &N);
    int *m = malloc(N * sizeof(*m));
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &m[i]);
    }
    
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", m[i]);
    }
    
    printf("\n");
    
    free(m);
    return 0;
}
