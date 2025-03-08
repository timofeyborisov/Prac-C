#include <stdio.h>

int
main(void)
{
    int seconds;
    if (scanf("%d", &seconds) != 1) {
        printf("Incorrect input\n");
        return 0;
    }

    printf("%d %d %d\n", (
        /// EXPRESSION-1 HERE
            seconds / 3600
        ///
        ), (
        /// EXPRESSION-2 HERE
            (seconds % 3600) / 60
        ///
        ), (
        /// EXPRESSION-3 HERE
            seconds % 60
        ///
        ));
}
