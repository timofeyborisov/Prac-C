#include <stdio.h>

int
main(int argc, char *argv[])
{
    int c;
    int output_flag = 0;
    FILE *f = fopen(argv[1], "r");
    while ((c = fgetc(f)) != EOF)
    {
        if (output_flag) {
            putchar(c);
        }
        
        if (c == '\n') {
            output_flag = !output_flag;
        }
    }
    
    fclose(f);
    return 0;
}
