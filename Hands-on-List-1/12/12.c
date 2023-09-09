/*
============================================================================
Name : 12.c
Author : Abhishek Gupta
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 28th Aug, 2023.
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd = open("temp.txt", O_WRONLY);
    if (fd == -1)
    {
        printf("Error opening first file\n");
        close(fd);
        return 0;
    }
    int mode = fcntl(fd, F_GETFL); // returns the mode number of the opened file
    mode = mode & O_ACCMODE;       // now we are mapping number to r/w flags
    if (mode == O_RDONLY)
    {
        printf("Opened in read mode\n");
    }
    else if (mode == O_WRONLY)
    {
        printf("Opened in write mode\n");
    }
    else
    {
        printf("Opened in read write mode\n");
    }
    close(fd);
}