#include <stdio.h>

#include "print.h"

int main(void)
{
    printf("TEST1\n"); fflush(stdout); // TEST1\n
    print("123\n"); // 123\n

    printf("TEST2\n"); fflush(stdout); // TEST2\n
    print("%+%\n", 'A', 'B'); // A+B\n

    printf("TEST3\n"); fflush(stdout); // TEST3\n
    print("12");
    print("34\n"); // 1234\n

    printf("TEST4\n"); fflush(stdout); // TEST4\n
    print("12\n"); // 12\n
    print("34");
    clear();

    printf("TEST5\n"); fflush(stdout); // TEST5\n
    char buf4[9] = {0};
    for (size_t i = 0; i < 8; ++i) {
        buf4[i] = 'q';
    }
    print(&buf4[0]);

    printf("TEST6\n"); fflush(stdout); // TEST6\n
    char buf5[9] = {0};
    for (size_t i = 0; i < 8; ++i) {
        buf5[i] = 'r';
    }
    print(&buf5[0]); // qqqqqqqq
    clear();

    printf("TEST7\n"); fflush(stdout); // TEST7\n
    print("12");
    printf("$$"); fflush(stdout); // $$
    print("34\n"); // 1234\n

    printf("TEST8\n"); fflush(stdout); // TEST8\n
    print("12\n34\n"); // 12\n34\n

    printf("TEST9\n"); fflush(stdout); // TEST9\n
    print("12\n3"); // 12\n
    printf("!!"); fflush(stdout); // !!
    print("45\n"); // 345\n

    printf("TEST10\n"); fflush(stdout); // TEST10\n
    print("1234\nABCDE"); // 1234\n
    printf("@@"); fflush(stdout); // @@
    print("X\n"); // ABCDEX\n
    
    printf("TEST11\n"); fflush(stdout); // TEST11\n
    print("01234567890123456789"); // 012345679012345
    printf("**"); fflush(stdout); // **
    clear();

    printf("TEST12\n"); fflush(stdout); // TEST12\n
    print("123");
    flush(); // 123
    printf("()\n"); fflush(stdout); // ()\n
}
