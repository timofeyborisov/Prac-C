#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define FILENAME "temp_file.tmp"

void
process(int n)
{
    if (n == 2) {
        FILE *f = fopen(FILENAME, "w");
        if (f != NULL) {
            fclose(f);
        }
        
        printf("%d\n", n);
    }
    else {
        while (access(FILENAME, F_OK) != 0) {
            usleep(10000);
        }
        printf("%d\n", n);
        remove(FILENAME);
    }
}

int
main(void)
{
    pid_t pid1, pid2;
    
    pid1 = fork();
    if (pid1 == 0) {
        // first process
        process(1);
        return 0;
    }

    pid2 = fork();
    if (pid2 == 0) {
        // second process
        process(2);
        return 0;
    }

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}