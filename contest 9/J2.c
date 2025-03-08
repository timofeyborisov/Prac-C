#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int
main(int argc, char **argv)
{
    pid_t pid = fork();

    if (pid == 0) {
        // child process
        execvp(argv[1], argv + 1);
    }

    int status;
    waitpid(pid, &status, 0);

    if (WIFEXITED(status) != 0) {
        printf("%d\n", WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status) != 0) {
        printf("%d\n", WTERMSIG(status));
    }

    return 0;
}