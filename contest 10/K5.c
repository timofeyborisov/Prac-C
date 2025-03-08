#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

enum {BUFF_SIZE = 1024};

int
main(int argc, char **argv)
{
    char buf[BUFF_SIZE];
    int n;
    long i = 1;

    int fd = open(argv[1], O_RDONLY);
    char name_buf[] = "./tmp_XXXXXX";
    int t_fd = mkstemp(name_buf);
    unlink(name_buf);

    while ((n = read(fd, buf, BUFF_SIZE)) > 0) {
        int pos = 0;
        for (int j = 0; j < n; ++j) {
            char ch = buf[j];
            if (i != 2) {
                buf[pos++] = ch;
            }
            if (ch == '\n') {
                i++;
            }
        }
        write(t_fd, buf, pos);
    }

    close(fd);
    fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0666);
    lseek(t_fd, 0, SEEK_SET);

    while ((n = read(t_fd, buf, sizeof buf)) > 0) {
        write(fd, buf, n);
    }

    close(fd);
    close(t_fd);
    return 0;
}