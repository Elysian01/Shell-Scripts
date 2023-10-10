/*
============================================================================
Name : 18.c
Author : Abhishek Gupta
Description : Write a program to find out total number of directories on the pwd.
                execute ls -l | grep ^d | wc ? Use only dup2.
Date: 16th Sept, 2023.
============================================================================
*/

#include <unistd.h>
#include <wait.h>

int main(void)
{
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
    if (fork())
    {
        if (!fork())
        {
            close(fd2[0]);
            close(fd2[1]);
            close(fd1[0]);
            dup2(fd1[1], STDOUT_FILENO);
            execlp("ls", "ls", "-l", NULL);
        }
        if (!fork())
        {
            close(fd1[1]);
            dup2(fd1[0], STDIN_FILENO);
            close(fd2[0]);
            dup2(fd2[1], STDOUT_FILENO);
            execlp("grep", "grep", "^-", NULL);
        }
        wait(0);
    }
    else
    {
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[1]);
        dup2(fd2[0], STDIN_FILENO);
        execlp("wc", "wc", NULL);
    }
    return 0;
}