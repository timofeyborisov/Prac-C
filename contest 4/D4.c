#include <stdio.h>

int
main(void)
{
    static double arr1[10000];
    static double arr2[10000];
    
    double *p1 = NULL;
    double *p2 = NULL;
    
    int n1, n2;
    scanf("%d", &n1);
    
    for (double *pt = arr1; pt < arr1 + n1; pt++) {
        scanf("%lf", pt);
        // read first array
        if ((p1 == NULL) && (*pt < 0)) {
            p1 = pt;
        }
    }
    
    scanf("%d", &n2);
    
    for (double *pt = arr2; pt < arr2 + n2; pt++) {
        scanf("%lf", pt);
        // read second array
        if (*pt > 0) {
            p2 = pt;
        }
    }

    if ((p1 != NULL) && (p2 != NULL)) {
        double temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        
        for (double *pt = arr1; pt < arr1 + n1; pt++) {
            printf("%.1lf ", *pt);
            // output first array
        }
        printf("\n");
            
        for (double *pt = arr2; pt < arr2 + n2; pt++) {
            printf("%.1lf ", *pt);
            // output second array
        }
        printf("\n");
    }
    
    return 0;
}

