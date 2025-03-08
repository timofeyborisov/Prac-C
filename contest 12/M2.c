#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int c = 0;

void
handler(int s) {
    ++c;
    printf("%d\n", c);
    if (c == 5) {
        exit(0);
    }
}

int
main(void)
{
    pid_t pid = fork();
    if (pid == 0) {
        // child process
        signal(SIGINT, handler);

        while (1) {
            pause();
        }
    }
    // parent process
    usleep(50);
    for (int i = 0; i < 5; ++i) {
        kill(pid, SIGINT);
        usleep(50);
    }
    waitpid(pid, NULL, 0);
    return 0;
}