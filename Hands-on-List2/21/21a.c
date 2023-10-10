/*
============================================================================
Name : 21a.c
Author : Abhishek Gupta
Description : Write two programs so that both can communicate by FIFO
                - Use two way communications.
Date: 10th Oct, 2023
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int buff[80];
    int fd1 = open("fifo", O_WRONLY);

    printf("Enter the text: ");
    scanf("%[^\n]", buff);
    write(fd1, buff, sizeof(buff));

    int fd2 = open("fifo2", O_RDONLY);
    read(fd2, buff, sizeof(buff));
    printf("The text: %s\n", buff);

    return 0;
}