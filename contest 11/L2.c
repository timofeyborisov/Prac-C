#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int
main(int argc, char **argv)
{
    char *p1 = argv[1];
    char *p2 = argv[2];
    char *p3 = argv[3];

    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        close(fd[0]);
        dup2(fd[1], 1);
        close(fd[1]);

        pid_t pid1 = fork();

        if (pid1 == 0) {
            execlp(p1, p1, (char *)NULL);
            return 1;
        }

        int status1;
        waitpid(pid1, &status1, 0);

        if (WIFEXITED(status1) && WEXITSTATUS(status1) == 0) {
            return 0;
        }

        pid_t pid2 = fork();

        if (pid2 == 0) {
            execlp(p2, p2, (char *)NULL);
            return 1;
        }

        int status2;
        waitpid(pid2, &status2, 0);
        return 0;
    }

    pid_t pid3 = fork();
    if (pid3 == 0) {
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);

        execvp(p3, argv + 3);
        return 1;
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid, NULL, 0);
    waitpid(pid3, NULL, 0);
    
    return 0;
}