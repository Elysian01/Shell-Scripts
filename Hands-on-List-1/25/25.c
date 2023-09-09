/*
============================================================================
Name : 25.c
Author : Abhishek Gupta
Description : Write a program to create three child processes. The parent should wait
                for a particular child (use waitpid system call).
Date: 7th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int pid = fork();
    if (pid)
    {

        if (fork())
        {
            if (!fork())
            {
                printf("Child#3 process id: %d\n", getpid());
                printf("Child#3 parent process id: %d\n", getppid());
                sleep(1);
                printf("Child#3 wokeup\n");
            }
        }
        else
        {
            printf("Child#2 process id: %d\n", getpid());
            printf("Child#2 parent process id: %d\n", getppid());
            sleep(5);
            printf("Child#2 wokeup\n");
        }
    }
    else
    {
        printf("Child#1 process id: %d\n", getpid());
        printf("Child#1 parent process id: %d\n", getppid());
        sleep(3);
        printf("Child#1 wokeup\n");
    }
    // pid, status varaible (int), options
    waitpid(pid, NULL, 0);

    // wait(0) => process grp mai se koi bhi ek process terminate hogi, fir woo age execute hona chalu hoga
    // wait(-1) => koi bhi ek child terminate hoga tho, parent wapas execution start karega
    // wait(pid) => ussi pid ka child terminate hoga tho, parent wapas execution start karegachild terminate hoga tho, parent wapas execution start karega

    return 0;
}