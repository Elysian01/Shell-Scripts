/*
============================================================================
Name : 22.c
Author : Abhishek Gupta
Description : Write a program, open a file, call fork, and then write to the file by
              both the child as well as the parent processes. Check output of the
              file.

Date: 1st Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main()
{

    int fd = open("abc.txt", O_RDWR | O_TRUNC);
    char *str;

    if (fork())
    {
        str = "Parent write\n";
        write(fd, str, strlen(str));
    }
    else
    {
        str = "Child write\n";
        write(fd, str, strlen(str));
    }

    return 0;
}