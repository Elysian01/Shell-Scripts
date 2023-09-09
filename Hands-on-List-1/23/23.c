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
    if (fork() == 0)
    {
        exit(0);
    }
    else
    {
        sleep(300);
    }
}