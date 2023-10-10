/*
============================================================================
Name : 30b.c
Author : Anurag Babal
Description : Write a program to create a shared memory.
c. detach the shared memory
Date: 19th Sept, 2023.
============================================================================
*/

#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

int main(void) {
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);

    char *data = shmat(shmid, 0, 0);
    shmdt(data);

    return 0;
}