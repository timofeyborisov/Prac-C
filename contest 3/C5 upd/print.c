#include <stdio.h>
#include <stdarg.h>
#include "print.h"

static char buffer[BUF_SIZE + 1];
static int b_index = 0;

static void output(const char buf[])
{
    printf("%s", buf);
    fflush(stdout);
}

void
flush(void) {
    if (b_index > 0) {
        buffer[b_index] = '\0';
        output(buffer);
        b_index = 0; 
        // Очистка буфера
    }
}

void 
clear(void) {
    b_index = 0;
}

void
print(const char format[], ...) {
    va_list args;
    va_start(args, format);
    clear();
    for (int i = 0; format[i] != '\0'; i++) {
        if (b_index == BUF_SIZE) {
            flush();
        }
        if (format[i] == '%') {
            char ch = va_arg(args, int);
            buffer[b_index++] = ch;
        }
        else {
            buffer[b_index++] = format[i];
        }
        if (buffer[b_index - 1] == '\n') {
            flush();
        }
    }
    va_end(args);
}

