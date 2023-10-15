/*
============================================================================
Name : 32a.c
Author : Abhishek Gupta
Description :Write a program to implement semaphore to protect any critical section.
                a. rewrite the ticket number creation program using semaphore
Date: 13th Oct, 2023.
============================================================================
*/

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("train", O_RDWR);
    struct train
    {
        int train_no;
        int ticket_no;
    } record;

    union semun
    {
        int val;
    } arg;

    key_t key = ftok(".", 1);
    int semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0600);

    if (semid != -1)
    {
        arg.val = 1;
        semctl(semid, 0, SETVAL, arg);
    }
    else
    {
        semid = semget(key, 1, 0600);
    }

    printf("Before critical section\n");
    struct sembuf buff = {0, -1, 0};
    semop(semid, &buff, 1);
    printf("Inside critical section\n");

    read(fd, &record, sizeof(record));
    lseek(fd, -sizeof(record), SEEK_CUR);
    record.ticket_no++;
    printf("Ticket number: %d\n", record.ticket_no);
    write(fd, &record, sizeof(record));
    close(fd);

    buff.sem_op = 1;
    printf("Press any key to exit critical section");
    getchar();
    semop(semid, &buff, 1);

    printf("Outside critical section\n");

    return 0;
}