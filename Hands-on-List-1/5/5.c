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
