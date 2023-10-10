/*
============================================================================
Name : 30a.c
Author : Anurag Babal
Description : Write a program to create a shared memory.
a. write some data to the shared memory
Date: 19th Sept, 2023.
============================================================================
*/

#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

int main(void) {
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0600);

    char *data = shmat(shmid, 0, 0);
    printf("Enter the text: ");
    scanf("%[^\n]", data);

    return 0;
}