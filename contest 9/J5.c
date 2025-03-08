#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int
main(void)
{
    setbuf(stdin, 0);
    
    char first_ch = getchar();
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        pid_t pid = fork();

        if (pid == -1) {
            wait(NULL);
            if (fork() == 0) {
                if ((char)ch == first_ch) {
                    printf("%c%c", ch, ch);
                }
                return 0;
            }
        }
        else if (pid == 0) {
            if ((char)ch == first_ch) {
                printf("%c%c", ch, ch);
            }
            return 0;
        }

        while (waitpid(-1, NULL, WNOHANG) > 0) {};
    }
    
    while (wait(NULL) > 0) {};
    printf("\n");

    return 0;
}