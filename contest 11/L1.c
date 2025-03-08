#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int call(int fd, int i, char *p, char **args)
{
    dup2(fd, i);
    close(fd);

    execvp(p, args);
    return 1;
}

int
main(int argc, char **argv)
{
    int j = 0;
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == '\0') {
            j = i;
        }
    }

    char *p1 = argv[1];
    char *p2 = argv[j + 1];
    argv[j] = NULL;

    int fd[2];
    pipe(fd);

    pid_t pid1 = fork();
    if (pid1 == 0) {
        close(fd[0]);
        call(fd[1], 1, p1, argv + 1);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        close(fd[1]);
        call(fd[0], 0, p2, argv + j + 1);
    }

    close(fd[0]);
    close(fd[1]);
    
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}