/*
============================================================================
Name : 14.c
Author : Abhishek Gupta
Description : Write a simple program to create a pipe, write to the pipe,
                read from pipe and display on the monitor.
Date: 16th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd[2];
    pipe(fd);
    char buff[10];
    int count = write(fd[1], "abcdef\n", 7);
    read(fd[0], buff, count);
    write(1, buff, count); // write in stdout
    return 0;
}