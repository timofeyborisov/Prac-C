
#include <stdio.h>

static void output(const char buf[])
{
    printf("%s", buf);
    fflush(stdout);
}


int
main(void)
{
    output("TEST1\n"); // TEST1\n
    print("123\n"); // 123\n

    output("TEST2\n"); // TEST2\n
    print("%+%\n", 'A', 'B'); // A+B\n

    output("TEST3\n"); // TEST3\n
    print("12");
    print("34\n"); // 1234\n

    output("TEST4\n"); // TEST4\n
    print("12\n"); // 12\n
    print("34");
    print("\n"); // 34\n

    output("TEST5\n"); // TEST5\n
    print("qqqqqqqq"); // (no output) buffer is not overloaded

    output("TEST6\n"); // TEST6\n
    print("\n"); // qqqqqqqq\n
    print("rrrrrrrr"); // (no output)
    output("x"); // x
    print("w"); // rrrrrrrr
    output("u"); // u
    print("\n"); // w\n

    output("TEST7\n"); // TEST7\n
    print("12");
    printf("$$"); fflush(stdout);
    print("34\n"); // $$1234\n

    output("TEST8\n"); // TEST8\n
    print("12\n34\n"); // 12\n34\n

    output("TEST9\n"); // TEST9\n
    print("12\n3"); // 12\n
    printf("!!"); fflush(stdout);
    print("45\n"); // !!345\n

    output("TEST10\n"); // TEST10\n
    print("1234\nABCDE"); // 1234\n
    printf("@@"); fflush(stdout); //@@
    print("X\n"); // ABCDEX\n

    output("TEST11\n"); // TEST11\n
    print("%%", 'q', '\n'); // q\n
    
    output("TEST12\n"); // TEST12\n
    print("01234567890123456789"); // 0123456789012345
    printf("**"); fflush(stdout); // **

    output("FIN\n"); // FIN\n
}
