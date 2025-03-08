#include <stdio.h>
#include <ctype.h>

int
left_unsigned(const char *string, const char **n_start, int *length)
{
    int len = 0;
    const char *start = NULL;
    while (*string) {
        if (isdigit(*string)) {
            if (start == NULL) {
                // skipping insignificant zeros 
                while ((*string == '0') && (isdigit(*(string + 1)))) {
                    ++string;
                }
                start = string;
            }
            ++len;
        }
        else {
            if (start != NULL) {
                *n_start = start;
                *length = len;
                return 1;
            }
            start = NULL;
            len = 0;
        }
        ++string;
    }
    return 0;
}

int
cmp_num(const char *num1, int len1, const char *num2, int len2)
{
    // 1 - 1st num is bigger than 2nd
    // -1 - 2nd num is bigger than 1st
    // 0 - equal
    if (len1 > len2) {
        return 1;
    }
    if (len1 < len2) {
        return -1;
    }
    else {
        while (*num1) {
            if (*num1 > *num2) {
                return 1;
            }
            if (*num1 < *num2) {
                return -1;
            }
            ++num1;
        }
    }
    return 0;
}


int
main(void)
{
    char str[82];
    fgets(str, sizeof(str), stdin);
    
    const char *ptr = str;
    const char *num_max = NULL;
    int len = 0;
    
    while (1) {
        const char *num_curr;
        int len_curr;
        if (!left_unsigned(ptr, &num_curr, &len_curr)) {
            break;
        }
        if (cmp_num(num_curr, len_curr, num_max, len) == 1) {
            num_max = num_curr;
            len = len_curr;
        }
        ptr = num_curr + len_curr;
    }
    if (num_max != NULL) {
        printf("%.*s\n", len, num_max);
    }
        
    return 0;
}
