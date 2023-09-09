/*
============================================================================
Name : 3.c
Author : Abhishek Gupta
Description : Write a program to create a file and print the file descriptor value.
              Use creat ( ) system call
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    // S_IRUSR and S_IWUSR means create file with read and write permission respectivily
    // if the file doesn't exist then creat function will create the file
    int fd = creat("temp.txt", S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        printf("Error creating file");
        exit(0);
    }
    printf("file descriptor: %d\n", fd);
    // Close the file descriptor
    close(fd);
    return 0;
}
