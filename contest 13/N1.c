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

enum {MEM_SIZE = 1024};
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
handler_cleanup(int s)
{
    key_t key =  ftok(key_arg, 'a');
    int semid = semget(key, 2, IPC_CREAT | 0666);
    int shmid = shmget(key, MEM_SIZE, IPC_CREAT | 0666);
    int msqid = msgget(key, IPC_CREAT | 0666);

    res_cleanup(semid, shmid, msqid);
    exit(0);
}

void
child_proc(char *arg)
{
    key_t key = ftok(arg, 'a');

    semget(key, 2, IPC_CREAT | 0666);
    shmget(key, MEM_SIZE, IPC_CREAT | 0666);
    msgget(key, IPC_CREAT | 0666);
    // opening resources (semaphores, shared memory, message queue)

    exit(0);
}

int
main(int argc, char **argv)
{
    key_arg = argv[0];
    key_t key = ftok(key_arg, 'a');
    // creating a key 
    int semid = semget(key, 2, IPC_CREAT | 0666);
    // getting access to semaphores.
    // semaphore is a process synchronization tool

    //unsigned short arr[2] = {0};
    // union semun sem = {.array = arr};

    semctl(semid, 0, SETVAL, 0);
    // set the 1st semaphore to 0
    semctl(semid, 1, SETVAL, 0);
    // set the 2nd semaphore to 0
    // semctl(semid, SETALL, sem) - set values for all semaphores 
    // taking the values from arr in sem

    int shmid = shmget(key, MEM_SIZE, IPC_CREAT | 0666);
    // creating a MEM_SIZE shared memory using key (size: 1024 bytes or 1 KB)

    int msqid = msgget(key, IPC_CREAT | 0666);
    // creating a message queue using key

    signal(SIGINT, handler_cleanup);
    // SIGINT handler (cleaning data)
    /*
    while (1) {
        pause();
    }
    */
    // for debugging

    if (fork() == 0) {
        child_proc(key_arg);
    }

    wait(NULL);
    res_cleanup(semid, shmid, msqid);

    return 0;
}