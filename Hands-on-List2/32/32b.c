/*
============================================================================
Name : 32b.c
Author : Abhishek Gupta
Description :Write a program to implement semaphore to protect any critical section.
                b. protect shared memory from concurrent write access
Date: 13th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<stdio.h>

int main(void) {
    union semun {
        int val;
    } arg;
    
    key_t key = ftok(".", 1);
    int semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0600);
    if(semid != -1) {
        arg.val = 1;
        semctl(semid, 0, SETVAL, arg);
    } else {
        semid = semget(key, 1, 0600);
    }

    int shmid = shmget(key, 1024, IPC_CREAT | 0600);
    char *data = (char *)shmat(shmid, (void *)0, 0);

    printf("Before critical section\n");
    struct sembuf buff = {0, -1, 0};
    semop(semid, &buff, 1);
    printf("Inside critical section\n");

    printf("Enter the text: ");
    scanf("%[^\n]", data);

    buff.sem_op = 1;
    printf("Press any key to exit critical section");
    getchar();
    getchar();
    semop(semid, &buff, 1);

    printf("Outside critical section\n");
    return 0;
}