#include <fcntl.h>
#include <unistd.h>

int
main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDWR);
    unsigned char buf[2];
    if (read(fd, &buf, 2) == 2) {
        lseek(fd, 1, SEEK_SET);
        write(fd, &buf[0], 1);
    }
    
    return 0;
}