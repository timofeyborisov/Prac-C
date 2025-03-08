// 1. Since the number needs to be printed immediately 
// after receiving the signal, it needs to be printed 
// inside the signal handler.

// 2. Since the SIGALRM signal can arrive 
// while the dec function is running, it is necessary
// to save the value of the current number before the 
// calculations, so that in this case it can be output.

#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *n;
char *buf;
long size;

void
handler_num(int s)
{
    char *loc_buf = malloc(size + 1);
    strcpy(loc_buf, buf);
    char sym = '\n';
    write(1, loc_buf, strlen(n));
    write(1, &sym, sizeof sym);
    free(loc_buf);
    alarm(5);
}

void
handler_time(int s)
{
    char sym = '\n';
    int time = alarm(0);
    alarm(time);

    char time_str = '0' + time;
    write(1, &time_str, 1);
    write(1, &sym, 1);
}

int
main(int argc, char **argv)
{
    n = argv[1];
    size = strlen(n);
    buf = malloc(size + 1);
    strcpy(buf, n);

    signal(SIGALRM, handler_num);
    signal(SIGINT, handler_time);

    alarm(5);
     
    while(strtol(n, NULL, 10) > 0) {
        n = dec(n);
        strcpy(buf, n);
    }

    free(buf);
    return 0;
}

