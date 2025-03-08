#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <wait.h>
#include <stdlib.h>
#include <signal.h>

enum {MEM_SIZE = 1024, EVEN = 0, ODD = 1};
// int cleanup = 0;

char *key_arg = NULL;

union semun {
    int val;
    // values for semaphores (SETVAL)
    struct semid_ds *buf; 
    // buffer for IPC_STAT, IPC_SET
    unsigned short *array;
    // array for GETALL, SETAL
};

void
res_cleanup(int semid, int shmid, int msqid)
{
    semctl(semid, 0, IPC_RMID);
    // removing semaphores
    shmctl(shmid, IPC_RMID, NULL);
    // removing shared memory
    msgctl(msqid, IPC_RMID, NULL);
    // removing message queue
}

void
child_process(int semid, int parity, int n)
{
    key_t key = ftok(key_arg, 'a');

    semget(key, 2, IPC_CREAT | 0666);
    shmget(key, MEM_SIZE, IPC_CREAT | 0666);
    msgget(key, IPC_CREAT | 0666);
    // opening resources (semaphores, shared memory, message queue)

    unsigned short arr1 = {semid, 1, 0};
    unsigned short arr2 = {semid, 1, 0};

    for(int i = parity; i < n; i + 2) {
        semop(semid, &arr1, 1);
        printf("%d\n", i);
        semop(semid, &arr2, 1);
    }

    exit(0);
}

int
main(int argc, char **argv)
{
    int n;
    key_arg = argv[0];
    key_t key = ftok(key_arg, 'a');
    // creating a key 
    int semid = semget(key, 2, IPC_CREAT | 0666);
    // getting access to semaphores.
    // semaphore is a process synchronization tool

    //unsigned short arr[2] = {0};
    // union semun sem = {.array = arr};

    int shmid = shmget(key, MEM_SIZE, IPC_CREAT | 0666);
    // creating a MEM_SIZE shared memory using key (size: 1024 bytes or 1 KB)

    int msqid = msgget(key, IPC_CREAT | 0666);
    // creating a message queue using key

    scanf("%d\n", &n);

    pid_t pid1 = fork();
    if (pid1 == 0) {
        child_process(semid, EVEN, n);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {
        child_process(semid, EVEN, n);
    }

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    res_cleanup(semid, shmid, msqid);

    return 0;
}