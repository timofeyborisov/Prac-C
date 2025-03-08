#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char
*read_str(void)
{
    size_t cap = 8;
    size_t size = 0;
    char *arr = malloc(cap * (sizeof(*arr)));
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (size == cap) {
            cap *= 2;
            arr = realloc(arr, cap * sizeof(*arr));
        }
        arr[size++] = ch;    
    }
    
    if (size == 0) {
        free(arr);
        return NULL;
    }
    else {
        arr[size] = '\0';
        return arr;
    }
}

int
main(void)
{
    char *ptr_max = NULL;
    size_t len_max = 0;
    
    char *ptr_curr;
    while ((ptr_curr = read_str()) != NULL) {
        size_t len_curr = strlen(ptr_curr);
        if (len_curr >= len_max) {
            if (ptr_max != NULL) {
                free(ptr_max);
            }
            ptr_max = ptr_curr;
            len_max = len_curr;
        }
        else {
            free(ptr_curr);
        }
    }
    
    if (ptr_max != NULL) {
        printf("%s\n", ptr_max);
    }
    
    free(ptr_max);
    
    return 0;
}
