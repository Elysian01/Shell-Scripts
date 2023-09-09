/*
============================================================================
Name : 13.c
Author : Abhishek Gupta
Description : Write a program to wait for a STDIN for 10 seconds using select.
                Write a proper print statement to verify whether the data is
                available within 10 seconds or not (check in $man 2 select).
Date: 28th Aug, 2023.
============================================================================
*/

#include <sys/select.h>
#include <sys/time.h>
#include <stdio.h>

int main()
{
    fd_set fd;
    struct timeval t;
    FD_ZERO(&fd);
    FD_SET(0, &fd);
    t.tv_sec = 10;
    t.tv_usec = 0; // microsec
    // count, read, write, exceptional, time
    int f = select(1, &fd, NULL, NULL, &t);
    if (f)
    {
        getchar();
        printf("Data Available\n");
    }
    else
    {
        printf("Timeout\n");
    }
}