#include <stdio.h>
#include <stdarg.h>

enum {BUF_SIZE = 8};
static void output(const char buf[]);

void
print(const char format[], ...) {
    va_list args;
    va_start(args, format);
    static char buffer[BUF_SIZE + 1];
    static int b_index = 0;
    for (int i = 0; format[i] != '\0'; i++) {
        if (b_index == BUF_SIZE) {
            buffer[b_index] = '\0';
            output(buffer);
            b_index = 0;
        }
        if (format[i] == '%') {
            char ch = va_arg(args, int);
            buffer[b_index++] = ch;
        }
        else {
            buffer[b_index++] = format[i];
        }
        if (format[i] == '\n') {
            buffer[b_index] = '\0';
            output(buffer);
            b_index = 0;
        }
    }
    va_end(args);
}
