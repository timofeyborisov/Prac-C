#include <stdio.h>

enum {MAX_SIZE = 10000, GETVAL = 2, SETVAL = 1};

struct Elem
{
    int id;
    int value;
};

static struct Elem data[MAX_SIZE];

union Argument
{
    int a;
    int *b;
};

int
command(const int id, const int cmd, union Argument arg)
{
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (data[i].id == id) {
            if (cmd == GETVAL) {
                *arg.b = data[i].value;
                return 0;
            }
            else if (cmd == SETVAL) {
                data[i].value = arg.a;
                return 0;
            }
            else {
                return 2;
            }
        }
    }
    
    return 1;
}

void
elem_proc(void)
{
    int i, id, value;
    scanf("%d%d%d", &i, &id, &value);
    data[i].id = id;
    data[i].value = value;
}

int 
main(void)
{
    union Argument arg;
    
    elem_proc();
    elem_proc();
    
    int ans = 0;
    arg.b = &ans;

    int d;
    scanf("%d", &d);
    if (command(d, GETVAL, arg) == 0) {
        arg.a = ans + 1;
        command(d, SETVAL, arg);
        arg.b = &ans;
        command(d, GETVAL, arg);
        printf("%d\n", ans);
    }
    else {
        printf("NONE\n");
    }

    return 0;
}
