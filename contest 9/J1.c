#include <stdio.h>

void
output_1(int n)
{
    switch (n) {
        case 0: {
            printf("A\nB\nB\nC\nC\n");
            break;
        }
        case 1: {
            printf("A\nB\nC\nB\nC\n");
            break;
        }
        default: {
            printf("UNKNOWN\n");
            break;
        }
    }
}

void
output_2(int n)
{
    switch (n) {
        case 0: {
            printf("1\n2\n2\n");
            break;
        }
        case 1: {
            printf("2\n1\n2\n");
            break;
        }
        case 2: {
            printf("2\n2\n1\n");
            break;
        }
        default: {
            printf("UNKNOWN\n");
            break;
        }
    }
}

int
main(void)
{
    int n;

    scanf("%d", &n);
    output_1(n);

    scanf("%d", &n);
    output_2(n);

    return 0;
}