/*
============================================================================
Name : 21.c
Author : Abhishek Gupta
Description : Write a program, call fork and print the parent and child process id.

Date: 1st Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    if (fork() == 0)
    {
        printf("Child process id: %d\n", getpid());
    }
    else
    {
        printf("Parent process id: %d\n", getpid());
    }
}