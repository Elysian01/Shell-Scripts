/*
============================================================================
Name : 17b.c
Author : Abhishek Gupta
Description : Write a program to execute ls -l | wc.
                a. use dup2
Date: 16th Sept, 2023.
============================================================================
*/

#include <unistd.h>

int main(void)
{
    int fd[2];
    pipe(fd);
    if (fork())
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execl("/bin/ls", "ls", "-l", NULL);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("wc", "wc", NULL);
    }

    return 0;
}