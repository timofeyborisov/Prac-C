#include <stdio.h>

int
main(int argc, char **argv)
{
    printf("Output2\n");
    for (int i = 0; i < argc; ++i) {
        printf("%s\n", argv[i]);
    }
    printf("End of 2nd program\n");
    return 0;
}