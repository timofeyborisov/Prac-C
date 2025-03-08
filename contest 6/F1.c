#include <stdio.h>

enum {ARR_INODE_SIZE = 13, ARR_FILE_SIZE = (1 << 20)};

struct inode
{
    size_t size;
    long nums[ARR_INODE_SIZE];
};

struct Filesystem
{
    size_t root;
    struct inode inodes[ARR_FILE_SIZE];
};

struct Filesystem f;

int
main(void)
{
    f.inodes[10].size = 2;
    f.inodes[10].nums[0] = 1038;
    f.inodes[10].nums[1] = 37465;
    
    size_t struct_size = sizeof(struct inode);
    size_t fields_size = sizeof(f.inodes[10].size) + sizeof(f.inodes[10].nums);
    size_t ans = fields_size - struct_size;
    
    printf("%zu\n", ans);
    return 0;
}
