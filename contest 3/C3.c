#include <stdio.h>
#include <stdarg.h>
enum Type {INT, DOUBLE};
void
vmax(enum Type t, size_t n, ...) {
    va_list args;
    // Список аргументов
    va_start(args, n);
    // Начинаем заполнять со 2 аргумента
    if (t == INT) {
        int max = va_arg(args, int);
        for (size_t i = 1; i < n; ++i) {
            int curr = va_arg(args, int);
            // Получаем текущий элемент
            if (curr > max) {
                max = curr;
            }
        }
        printf("%d\n", max);
    }
    else {
        double max = va_arg(args, double);
        for (size_t i = 1; i < n; ++i) {
            double curr = va_arg(args, double);
            // Текущий элемент (уже double)
            if (curr > max) {
                max = curr;
            }
        }
        printf("%g\n", max);
    }
    va_end(args);
}
int
main(void) {
    vmax(INT, 5, 3, 4, -5, 10, 9);
    vmax(INT, 3, 10, 10, -10000);
    vmax(INT, 3, 0, 0, 10);
    vmax(INT, 7, 2, 3, 6, 7, 10, 10, -1000000);
    // Тесты, тип INT
    vmax(DOUBLE, 3.0, 1.0, 2.0, 100.0);
    vmax(DOUBLE, 5, -1.2, 1.34, 3.455, 100.0, 100.0);
    vmax(DOUBLE, 3, 100.0, 100.00, 100.0);
    vmax(DOUBLE, 6, 100.000, -1000.2332, 32.3, 43.3, -4234.3, 0.000);
    // Тесты, тип DOUBLE
    return 0;
}
