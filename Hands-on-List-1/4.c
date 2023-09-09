/*
============================================================================
Name : 4.c
Author : Abhishek Gupta
Description : Write a program to open an existing file with read write mode.
              Try O_EXCL flag also.
Date: 28th Aug, 2023.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
    // use O600 means user has read and write permission
    // EXCLUSIVE means file should be created by this process, if it is already present it will give out error. (since its exclusive)
    // exclusive akele kabhi work nhi karega uske sath creat hona chahiye
    int fd = open("temp.txt", O_CREAT | O_EXCL, 0600);
    if (fd == -1)
    {
        perror("Failed to open file");
    }
    return 0;
}
