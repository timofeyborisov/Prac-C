#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int
main(int argc, char **argv)
{
    char *p2 = argv[argc - 1];
    argv[argc - 1] = NULL;

    pid_t pid1 = fork();   
    if (pid1 == 0) {
        // child process
        execvp(argv[1], argv + 1);
    }

    int status1;
    waitpid(pid1, &status1, 0);

    if (WIFEXITED(status1) && WEXITSTATUS(status1) == 0) {
        int status2;
        pid_t pid2 = fork();
        if (pid2 == 0) {
            execlp(p2, p2, NULL);
        }

        waitpid(pid2, &status2, 0);
    }
    
    return 0;
}