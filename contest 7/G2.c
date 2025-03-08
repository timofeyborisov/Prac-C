#include <stdio.h>

int
main(int argc, char *argv[])
{
    unsigned char elem;
    FILE *f = fopen(argv[1], "r+");
    
    fread(&elem, sizeof(elem), 1, f);
    
    if (fgetc(f) != EOF) {
        fseek(f, 1, SEEK_SET);
        fwrite(&elem, sizeof(elem), 1, f);
    }
    
    fclose(f);
    return 0;
}
