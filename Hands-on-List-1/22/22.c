/*
============================================================================
Name : 22.c
Author : Abhishek Gupta
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
              parent processes. Check output of the file.

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

    int f1 = open("file.txt", O_CREAT | O_RDWR, 0777);
    if (f1 == -1)
    {
        printf("Error opening first file\n");
        close(f1);
        return 0;
    }
    if (fork() == 0)
    {
        write(f1, "Hello from child process\n", 25);
    }
    else
    {
        write(f1, "Hello from parent process\n", 26);

        wait(NULL);
        char buff[50];
        close(f1);
        f1 = open("file.txt", O_RDONLY, 0777);
        read(f1, buff, sizeof(buff));
        write(1, buff, sizeof(buff));
    }
}