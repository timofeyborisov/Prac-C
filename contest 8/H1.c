#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
cmp_non_inc(const void *elem1, const void *elem2)
{
    return strcmp(*(char **)elem1, *(char **)elem2);
}

int
cmp_even_odd(const void *elem1, const void *elem2)
{
    size_t len1 = strlen(elem1);
    size_t len2 = strlen(elem2);

    if ((len1 % 2 == 0) && (len2 % 2 != 0)) {
        return -1;
    }
    if ((len1 % 2 != 0) && (len2 % 2 == 0)) {
        return 1;
    }
    if ((len1 % 2 == 0) && (len2 % 2 == 0)) {
        return strcmp(*(char **)elem1, *(char **)elem2);
    }

    return strcmp(*(char **)elem2, *(char **)elem1);
}

void
output(int len, char **arr)
{
    for (int i = 1; i < len; i++) {
        printf("%s\n", arr[i]);
    }
}

int
main(int argc, char **argv)
{
    qsort(argv[2], argc - 1, sizeof *argv, cmp_non_inc);
    output(argc, argv);
    qsort(argv[2], argc - 1, sizeof *argv, cmp_even_odd);
    output(argc, argv);

    return 0;
}

