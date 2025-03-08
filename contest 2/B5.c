#include <stdio.h>
#include <limits.h>

int main(void) 
{
    int ans = INT_MAX;
    int is_empty = 1;
    
    while (1) {
		
		int n = 1;
		int max = INT_MIN;
		
        while (1) {
            scanf("%d", &n);
            if (n == 0) {
                break;
            }
            if (n > max) {
                max = n;
            }
            if (n > 0) {
		        is_empty = 0;
		    }
        }
        if (max < 0) {
            break;
        }
        if (max < ans) {
            ans = max;
        }
    }
    
    if (is_empty) {
        printf("%s\n", "EMPTY");
    }
    else {
        printf("%d\n", ans);
    }
    
    return 0;
}
