#include <stdio.h>

enum {MAX_SIZE = 10000};


// finding maximum from array
const double
*find_max(const double *arr, size_t len)
{
    if (len == 0) {
        return NULL;
    }
    
    const double *max = arr;
    for (int i = 1; i < len; i++) {
        if (*(arr + i) > *max) {
            max = arr + i;
        }
    }
    return max;
}

// swap 2 elemnts of array
void
exchange(double *n1, double *n2)
{
    double temp = *n2;
    *n2 = *n1;
    *n1 = temp;
}

// sorting
void
arr_selection_sort(double *arr, size_t len)
{
    for (size_t i = 0; i < len - 1; i++) {
        double *max_num = (double *)find_max(arr + i, len - i);
        exchange(max_num, arr + i);
    }
}

int
main(void)
{
    // init
    static double arr[MAX_SIZE];
    size_t len;
    scanf("%zu", &len);
    
    if (len == 0) {
        return 1;
    }
    
    // reading array
    for (size_t i = 0; i < len; i++) {
        scanf("%lf", arr + i);
    }
    
    if (len >= 18) {
        double *max_num = (double *)find_max(&arr[4], 14);
        printf("%.1lf ", *max_num);
    }
    
    // sorting
    arr_selection_sort(arr, len);
    
    // output
    for (size_t i = 0; i < len; i++) {
        printf("%.1lf ", *(arr + i));
    }
    printf("\n");
    
    return 0;
}
