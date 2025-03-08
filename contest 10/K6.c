#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

enum {BUF_SIZE = 32, WAITING = 100};

void
write_byte(int fd, int ptrs_fd, int w_pos)
{
    char byte;
    int r_pos; 

    while (1) {
        lseek(ptrs_fd, sizeof r_pos, SEEK_SET);
        read(ptrs_fd, &r_pos, sizeof r_pos);

        if ((w_pos + 1) % BUF_SIZE == r_pos) {
            usleep(WAITING);
            continue;
        }
        else if (read(1, &byte, 1) != 1) {
            break;
        }
        else {
            write(fd, &byte, 1);
            w_pos = (w_pos + 1);
            lseek(ptrs_fd, 0, SEEK_SET);
            write(ptrs_fd, &w_pos, sizeof w_pos);
        }
    }
}

void 
read_byte(int fd, int ptrs_fd, int r_pos)
{
    char byte;
    int w_pos; 

    while (1) {
        lseek(ptrs_fd, 0, SEEK_SET);
        read(ptrs_fd, &w_pos, sizeof w_pos);

        if (w_pos != r_pos) {
            usleep(WAITING);
            continue;
        }
        else if (read(1, &byte, 1) != 1) {
            break;
        }
        else {
            write(fd, &byte, 1);
            w_pos = (w_pos + 1);
            lseek(ptrs_fd, 0, SEEK_SET);
            write(ptrs_fd, &w_pos, sizeof w_pos);
        }
    }
}

int
main(void)
{
    char buf1[] = "./tmp_XXXXXX";
    char buf2[] = "./ptrs_XXXXXX";

    int tmp_fd = mkstemp(buf1);
    unlink(buf1);

    int ptrs_fd = mkstemp(buf2);
    unlink(buf2);

    int i = 0;
    int j = 0;

    pid_t pid = fork();

    if (pid == 0) {
        // writer
        write_byte(tmp_fd, ptrs_fd, j);

        close(tmp_fd);
        close(ptrs_fd);
        return 0;
    }
    // reader

    read_byte();

    waitpid(pid, NULL, 0);
    close(tmp_fd);
    close(ptrs_fd);

    return 0;
}