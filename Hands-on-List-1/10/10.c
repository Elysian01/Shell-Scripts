/*
============================================================================
Name : 10.c
Author : Abhishek Gupta
Description : Write a program to open a file with read write mode, write 10 bytes,
				move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
				a. check the return value of lseek
				b. open the file with od and check the empty spaces in between the data.
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("1 arguments are required\n");
		return 0;
	}
	int f1 = open(argv[1], O_CREAT | O_EXCL | O_WRONLY, 0777);
	if (f1 == -1)
	{
		printf("Error opening file\n");
		close(f1);
		return 0;
	}
	// greetings is 9 letter, 10th letter is '\0'
	char buff[] = "Greetings";
	write(f1, buff, sizeof(buff));
	int x = lseek(f1, 10, SEEK_CUR);
	if (x)
		printf("Lseek return value: %d\n", x);
	else
		printf("Lseek: ");
	write(f1, buff, sizeof(buff));
}