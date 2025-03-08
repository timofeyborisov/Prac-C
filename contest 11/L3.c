#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int
main(int argc, char **argv)
{
    int fd1[2];
    pipe(fd1);

    pid_t pid1 = fork();

    if (pid1 == 0) {
        close(fd1[0]);

        dup2(fd1[1], 1);
        close(fd1[1]);

        execlp("grep", "grep", "^[[:alnum:]_]*(", (char *)NULL);
        return 1;
    }

    int fd2[2];
    pipe(fd2);

    pid_t pid2 = fork();
    if (pid2 == 0) {
        close(fd1[1]);
        close(fd2[0]);

        dup2(fd1[0], 0);
        close(fd1[0]);
        dup2(fd2[1], 1);
        close(fd2[1]);

        execlp("cut", "cut", "-d(", "-f1", (char *)NULL);
        return 1;
    }

    close(fd1[0]);
    close(fd1[1]);

    pid_t pid3 = fork();
    if (pid3 == 0) {
        close(fd2[1]);

        dup2(fd2[0], 0);
        close(fd2[0]);

        execlp("sort", "sort", (char *)NULL);
        return 1;
    }

    close(fd2[0]);
    close(fd2[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    return 0;
}