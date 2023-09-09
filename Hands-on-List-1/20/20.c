/*
============================================================================
Name : 20.c
Author : Abhishek Gupta
Description : Find out the priority of your running program. Modify the priority with nice command.

Date: 1st Sept, 2023.
============================================================================
*/

#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Priority of current running process: %d\n", getpriority(PRIO_PROCESS, 0));
    nice(-2);
    printf("Modified priority of current running process: %d\n", getpriority(PRIO_PROCESS, 0));
}
