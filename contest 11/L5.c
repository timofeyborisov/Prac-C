#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

enum {BUF_SIZE = 64};

void
proc_A(int fd1[2], int fd2[2])
{
    close(fd1[1]);
    close(fd2[0]);
    // not used
    int a, b;
    while(read(fd1[0], &a, sizeof a) == sizeof a && 
    read(fd1[0], &b, sizeof b) == sizeof b) {
        int sum = a + b;
        int dif = a - b;
        write(fd2[1], &sum, sizeof sum);
        write(fd2[1], &dif, sizeof dif);
    }

    close(fd1[0]);
    close(fd2[1]);

    exit(0);
}

void
proc_son(int fd1[2], int fd2[2], int fd3[2], char lock, int a, int b)
{
    close(fd1[0]);
    close(fd2[1]);
    // not used
    read(fd3[0], &lock, sizeof lock);
    int pair[2] = {a, b};
    write(fd1[1], pair, sizeof pair);
    close(fd1[1]);

    read(fd2[0], pair, sizeof pair);
    close(fd2[0]);

    printf("%d %d %d %d\n", a, b, pair[0], pair[1]);
    write(fd3[1], &lock, sizeof lock);
    exit(0);
}

int
main(void)
{
    setbuf(stdin, NULL);

    int fd1[2];
    // send to process A
    int fd2[2];
    // receive from process A
    pipe(fd1);
    pipe(fd2);

    pid_t pid_A = fork();
    if (pid_A == 0) {
        proc_A(fd1, fd2);
    }

    int fd3[2];
    pipe(fd3);

    char lock = 0;
    write(fd3[1], &lock, sizeof lock);

    int a, b;
    while(scanf("%d%d", &a, &b) == 2) {
        pid_t pid = fork();
        if (pid == 0) {
            proc_son(fd1, fd2, fd3, lock, a, b);
        }
        while (waitpid(-1, NULL, WNOHANG) > 0) {};
    }

    close(fd1[0]);
    close(fd2[1]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd3[0]);
    close(fd3[1]);

    while(wait(NULL) > 0) {};
    return 0;
}