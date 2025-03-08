#include <stdio.h>

enum {SIZE = 100};

int
matrix_multiplication(double m[SIZE][SIZE], 
const double m1[SIZE][SIZE], size_t m1_m, size_t m1_n,
const double m2[SIZE][SIZE], size_t m2_m, size_t m2_n) 
{
    if (m1_n != m2_m) {
        return 1;
        // error
    }
    
    for (size_t i = 0; i < m1_m; i++) {
        for (size_t j = 0; j < m2_n; j++) {
            m[i][j] = 0;
            for (size_t k = 0; k < m1_n; k++) {
                m[i][j] += (double)m1[i][k] * (double)m2[k][j];
            }
        }
    }
    return 0;

}

int
main(void)
{
    static double m1[SIZE][SIZE];
    static double m2[SIZE][SIZE];
    static double m[SIZE][SIZE];
    
    size_t m1_m, m1_n, m2_m, m2_n;
    
    scanf("%zu%zu", &m1_m, &m1_n);
    for (size_t i = 0; i < m1_m; i++) {
        for (size_t j = 0; j < m1_n; j++) {
            scanf("%lf", &m1[i][j]);
        }
    }

    scanf("%zu%zu", &m2_m, &m2_n);
    for (size_t i = 0; i < m2_m; i++) {
        for (size_t j = 0; j < m2_n; j++) {
            scanf("%lf", &m2[i][j]);
        }
    }

    if(!matrix_multiplication(m, m1, m1_m, m1_n, m2, m2_m, m2_n)) {
        for (size_t i = 0; i < m1_m; i++) {
            for (size_t j = 0; j < m2_n; j++) {
                printf("%.1lf ", m[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}
