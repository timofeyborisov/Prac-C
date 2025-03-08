#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void write_even(void)
{
    char buf;
    int c = 1;

    while (read(0, &buf, 1) > 0) {
        if (c == 0) {
            write(1, &buf, 1);
        }
        c = c^1;
    }
    exit(0);
}

int
main(void)
{
    int fd[2];
    pipe(fd);

    pid_t pid1 = fork();

    if (pid1 == 0) {
        // child
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);

        write_even();
    }

    pid_t pid2 = fork();

    if (pid2 == 0) {
        // grand child
        pid_t subpid = fork();
        if (subpid == 0) {
            close(fd[0]);
            dup2(fd[1], 1);
            close(fd[1]);
            
            write_even();
        }

        close(fd[0]);
        close(fd[1]);

        waitpid(subpid, NULL, 0);
        
        return 0;
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}