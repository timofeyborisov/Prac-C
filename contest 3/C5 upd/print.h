#ifndef PRINT_H
#define PRINT_H

enum {BUF_SIZE = 8};

void flush(void);
void clear(void);
void print(const char format[], ...);

#endif

