#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void
write_str(FILE *f) {
    int c;
    while ((c = fgetc(f)) != EOF || (char)c != '\n') {
        fputc(c, f);
        printf("AAAA\n");
    }
}

void
eq_str_proc(FILE *f, long len, const char *ndl, long offset, FILE *t)
{
    char *str = malloc(len * sizeof *str);
    fgets(str, len + 1, f);
    printf("%s\n", str);
    printf("%s\n", ndl);
    if (strstr(str, ndl) != NULL) {
        fseek(f, offset * sizeof *str, SEEK_CUR);
        write_str(f);
    }

    free(str);
}

int
main(int argc, char **argv)
{
    long needle_len = strlen(argv[2]);
    if (needle_len == 0) {
        return 0;
    }

    FILE *f = fopen(argv[1], "r");
    FILE *t = tmpfile();

    int c;
    long offset = 0;
    char *str = malloc(needle_len * sizeof *str); 

    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            offset = 0;
        }
        // if the first symbol is encountered
        else if ((char)c == argv[2][0]) {
            eq_str_proc(f, needle_len, argv[2], offset, t);
        }
        else {
            offset++;
        }
    }

    // preparing files
    fclose(f);
    f = fopen(argv[1], "w");
    fseek(t, 0, SEEK_SET);

    // writing result
    while ((c = fgetc(t)) != EOF) {
        fputc(c, f);
    }

    fclose(f);
    fclose(t);
    return 0;
}