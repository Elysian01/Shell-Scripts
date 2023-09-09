/*
============================================================================
Name : 29.c
Author : Abhishek Gupta
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
                SCHED_RR).
Date: 8th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/resource.h>

int main()
{
    struct sched_param new_param;
    pid_t pid = getpid();
    int get_policy = sched_getscheduler(pid);
    if (get_policy == -1)
    {
        perror("sched_getscheduler");
        exit(1);
    }
    printf("Current scheduling policy: ");
    switch (get_policy)
    {
    case SCHED_FIFO:
        printf("FIFO\n");
        break;
    case SCHED_RR:
        printf("RR\n");
        break;
    case SCHED_OTHER:
        printf("OTHER\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }

    printf("Current priority: %d\n", getpriority(PRIO_PROCESS, 0));
    new_param.sched_priority = 99;
    if (sched_setscheduler(pid, SCHED_FIFO, &new_param) == -1)
    {
        perror("sched_getscheduler");
        exit(1);
    }
    get_policy = sched_getscheduler(pid);
    if (get_policy == -1)
    {
        perror("sched_getscheduler");
        exit(1);
    }
    printf("New scheduling policy: ");
    switch (get_policy)
    {
    case SCHED_FIFO:
        printf("FIFO\n");
        break;
    case SCHED_RR:
        printf("RR\n");
        break;
    case SCHED_OTHER:
        printf("OTHER\n");
        break;
    default:
        printf("Unknown\n");
        break;
    }
}