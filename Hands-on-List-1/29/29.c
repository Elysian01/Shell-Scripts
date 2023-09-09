/*
============================================================================
Name : 29.c
Author : Abhishek Gupta
Description : Write a program to get scheduling policy and modify the scheduling
                policy (SCHED_FIFO, SCHED_RR).
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
    int policy = sched_getscheduler(0); // 0 means current process

    switch (policy)
    {
    case SCHED_OTHER:
        printf("Policy is normal\n");
        break;
    case SCHED_RR:
        printf("Policy is round-robin\n");
        break;
    case SCHED_FIFO:
        printf("Policy is first-in, first-out\n");
        break;
    default:
        printf("Unknown policy!\n");
    }

    struct sched_param sp;
    sp.sched_priority = 50; // this priority should always be b/w 1 and 99 (real-time priority range), otherwise it would not change the schd policy
    sched_setscheduler(0, SCHED_RR, &sp);
    policy = sched_getscheduler(0);

    switch (policy)
    {
    case SCHED_OTHER:
        printf("Policy is normal\n");
        break;
    case SCHED_RR:
        printf("Policy is round-robin\n");
        break;
    case SCHED_FIFO:
        printf("Policy is first-in-first-out\n");
        break;
    default:
        printf("Unknown policy!\n");
    }
    return 0;
}