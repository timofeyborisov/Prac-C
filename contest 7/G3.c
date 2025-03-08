#include <stdio.h>

int
main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        return 0;
    }
    
    FILE *t = tmpfile();
    
    // scanning numbers;
    int n;
    while (fscanf(f, "%d", &n) == 1) {
        fwrite(&n, sizeof n, 1, t);
    }
    
    // reopening file
    fclose(f);
    fseek(t, 0, SEEK_END);
    f = fopen(argv[1], "w");
    
    // rewriting file
    long len = ftell(t);
    while (len > 0) {
        fread(&n, sizeof n, 1, t);
        fseek(t, -2 * sizeof n, SEEK_CUR);
        // addr - sizeof n;
        
        fprintf(f, "%d ", n);
        len -= sizeof n;
    }
    
    fclose(f);
    fclose(t);
    return 0;
}
