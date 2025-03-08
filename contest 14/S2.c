#include <sys/wait.h>
#include <sys/types.h>

typedef enum Command_kind {
    KIND_SIMPLE,
    KIND_REDIRECT,
    KIND_PIPELINE,
    KIND_SEQ1, 
    KIND_SEQ2
} Command_kind;

typedef enum Operations {
    OP_CONJUNCT,
    OP_DISJUNCT,
    OP_BACKGROUND,
    OP_SEQ,
} Operations;

typedef enum Modes {
    RD_INPUT,
    RD_OUTPUT,
    RD_APPEND,
} Modes;

typedef struct Command {
    Command_kind kind;

    // KIND_SIMPLE
    int argc;
    char **argv;

    // KIND_REDIRECT
    int rd_mode;
    char *rd_path;
    struct Command *rd_command;

    // KIND_PIPELINE
    int pipeline_size;
    struct Command *pipeline_commands;

    // KIND_SEQ1, KIND_SEQ2
    int seq_size;
    struct Command *seq_commands;
    int *seq_operations;
} Command;

int
command_simple(Command *command)
{
    pid_t pid = fork();
    if (pid == 0) {
        execvp(command.argv[1], command.argv + 1);
        return 1;
    }
    waitpid(pid, NULL, 0);
    return 0;
}

int
run_command(Command *command)
{
    switch (command->kind) {
        case KIND_SIMPLE: {
            // command_simple
            break;
        }
        case KIND_REDIRECT: {
            // command_redirect
            break;
        }
        case KIND_PIPELINE: {
            // command_pipeline
            break;
        }
        case KIND_SEQ1: {
            // command_seq1
            break;
        }
        case KIND_SEQ2: {
            // command_seq2
            break;
        }
        default:
    }
    return 0;
}

int 
main(void)
{
    return 0;
}