#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>

unsigned long long n;
time_t last_output;
int n1 = 0;
int n2 = 0;

void
print_num(int s) {
    n1 = 1;
}

void
print_time(int s) {
    n2 = 1;
}

int
main(void)
{
    signal(SIGALRM, print_num);
    signal(SIGINT, print_time);

    scanf("%llu", &n);
    
    alarm(5);

    while (n > 0) {
        --n;
        if (n1 == 1) {
            printf("%llu\n", n);
            last_output = time(NULL);
            n1 = 0;
            alarm(5);
        }
        if (n2 == 1) {
            printf("%d", 5 - (int)(time(NULL) - last_output));
            n2 = 0;
        }
    }
    
    return 0;
}