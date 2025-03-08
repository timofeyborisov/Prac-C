#include <stdio.h>

int main(void) {
    unsigned int N, M; 
    scanf("%u %u", &N, &M);
    int size = sizeof(long long) * 8;
    unsigned long long remaining = (N == size) ? ~0ULL : (1ULL << N) - 1;
    // 1111..(N)..11
    unsigned int i = 0;
    // Current pos (1ULL << i)
    unsigned int j = N; 
    // Num of remaining kids

    while (j > 0) {
        unsigned int c = 0; 
        // counter
        while (c < M) {
            if (remaining & (1ULL << i)) {
                c++;
            }       
            if (c == M) {
                remaining &= ~(1ULL << i);
                j--;
                printf("%u ", i);
            }
            i = (i + 1) % N;
        }
    }
    printf("\n");
    return 0;
}
