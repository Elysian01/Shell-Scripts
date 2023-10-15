/*
============================================================================
Name : 16.c
Author : Abhishek Gupta
Description : Write a program to send and receive data from parent to child
                vice versa. Use two way communication.
Date: 16th Sept, 2023.
============================================================================
*/

#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd1[2], fd2[2], count;
    char buff[80];
    pipe(fd1);
    pipe(fd2);
    if (fork())
    {
        char *msg = "Message from parent\n";
        close(fd1[0]);
        write(fd1[1], msg, strlen(msg));

        close(fd2[1]);
        count = read(fd2[0], buff, sizeof(buff));
        write(STDOUT_FILENO, buff, count);
    }
    else
    {
        char *msg = "Message from child\n";
        close(fd1[1]);
        count = read(fd1[0], buff, sizeof(buff));
        write(STDOUT_FILENO, buff, count);

        close(fd2[0]);
        write(fd2[1], msg, strlen(msg));
    }

    return 0;
}