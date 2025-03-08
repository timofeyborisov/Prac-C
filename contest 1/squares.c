#include <stdio.h>

int
main(void)
{
    double x1, y1, w1, x2, y2, w2;
    if (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &w1, &x2, &y2, &w2) != 6) {
        printf("Incorrect input\n");
        return 0;
    }

    printf((
        /// WRITE HERE
            (((x1 <= x2) && (x2 <= x1 + w1)) || ((x1 <= x2 + w2) && (x2 + w2 <= x1 + w1)) ||
            ((x2 <= x1) && (x1 <= x2 + w2))) &&
            (((y1 <= y2) && (y2 <= y1 + w1)) || ((y1 <= y2 + w2) && (y2 + w2 <= y1 + w1)) ||
            ((y2 <= y1) && (y1 <= y2 + w2)))
        ///
        ) ? "YES\n" : "NO\n");
}
