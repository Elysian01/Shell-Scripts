/*
============================================================================
Name : 5.c
Author : Abhishek Gupta
Description : Write a program to create five new files with infinite loop.
              Execute the program in the background and check the file descriptor
              table at /proc/pid/fd.
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int f1 = open("temp1.txt", O_CREAT, 0777);
    int f2 = open("temp2.txt", O_CREAT, 0777);
    int f3 = open("temp3.txt", O_CREAT, 0777);
    int f4 = open("temp4.txt", O_CREAT, 0777);
    int f5 = open("temp5.txt", O_CREAT, 0777);
    while (1)
        ;
    return 0;
}
