/*
============================================================================
Name : 22.c
Author : Abhishek Gupta
Description : Write a program to wait for data to be written into FIFO within 10
                seconds, use select system call with FIFO.
Date: 10th Oct, 2023
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

int main(void)
{
    int buff[80];
    fd_set readfds;
    struct timeval tv;
    int fd = open("fifo", O_RDONLY);

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    int available = select(fd + 1, &readfds, NULL, NULL, &tv);

    if (!available)
        printf("Data not available\n");
    else
    {
        printf("Data is available now\n");
        read(fd, buff, sizeof(buff));
        printf("The text : %s\n", buff);
    }

    return 0;
}