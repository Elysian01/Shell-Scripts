/*
============================================================================
Name : 23.c
Author : Abhishek Gupta
Description : Write a program to create a Zombie state of the running program.

Date: 5th Sept, 2023.
============================================================================
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
int main()
{
    // zombie process: every process has a exit status, suppose a child process has
    // finished its execution, but the parent is asleep, so the child can't update its
    // exit status, so he is waiting for parent, therefore during that time of waiting
    // that process is called zombie process
    if (fork() == 0)
    {
        printf("Child process id : %d\n", getpid());
        exit(0);
    }
    else
    {
        sleep(100);
    }
}