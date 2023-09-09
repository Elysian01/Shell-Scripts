/*
============================================================================
Name : 24.c
Author : Abhishek Gupta
Description : Write a program to create an orphan process.
Date: 7th Sept, 2023.
============================================================================
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
int main()
{
    int id = fork();
    if (id == 0)
    {
        printf("Child process, my ID: %d and parent process ID: %d\n", id, getppid());
        sleep(10);
        printf("After sleep of child process, Parent process ID: %d\n", getppid());
    }
    else
    {
        printf("Parent process, my ID: %d and child process ID: %d\n", getpid(), id);
        printf("Parent process exiting......\n");
        exit(0);
    }
}
