#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int
main(int argc, char **argv)
{
    char *p1 = argv[1];
    char *p2 = argv[2];
    char *f = argv[3];
    char *p3 = argv[4];

    pid_t pid = fork();
    if (pid == 0) {
        int fd = open(f, O_CREAT | O_WRONLY | O_APPEND, 0666);
        dup2(fd, 1);
        // doing this in child process because we need to redirect output 
        // only in child process to p1 and p2.

        pid_t pid1 = fork();

        if (pid1 == 0) {
            // child process to p1.
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
            // child process to p2.
            execlp(p2, p2, (char *)NULL);
            return 1;
        }

        int status2;
        waitpid(pid2, &status2, 0);
        return (WIFEXITED(status2) && WEXITSTATUS(status2) == 0) ? 0 : 1;
    }

    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
        pid_t pid3 = fork();

        if (pid3 == 0) {
            // child process to p3.
            execlp(p3, p3, (char *)NULL);
            return 1;
        }

        waitpid(pid3, NULL, 0);
    }

    return 0;
}