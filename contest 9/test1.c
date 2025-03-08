#include <stdio.h>

int
main(int argc, char **argv)
{
    printf("Output1\n");
    for (int i = 0; i < argc; ++i) {
        printf("%s\n", argv[i]);
    }
    
    return 0;
}