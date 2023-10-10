/*
============================================================================
Name : 15.c
Author : Abhishek Gupta
Description : Write a simple program to send some data from parent to the child process.
Date: 16th Sept, 2023.
============================================================================
*/

#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd[2];
    pipe(fd);
    if (fork())
    {
        char *str = "Message from parent\n";
        close(fd[0]);
        write(fd[1], str, strlen(str));
    }
    else
    {
        int count;
        char buff[80];
        close(fd[1]);
        count = read(fd[0], buff, sizeof(buff));
        write(1, buff, count);
    }

    return 0;
}