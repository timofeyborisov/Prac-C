#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char **argv)
{
    // program path
    char *p = argv[1];
    // file path
    char *f = argv[2];

    if (fork() == 0) {
        int fd = open(f, O_CREAT | O_TRUNC | O_WRONLY, 0666);
        dup2(fd, 1);
        execlp(p, p, (char *)NULL);
        return 1;
    }
    wait(NULL);
    return 0;
}