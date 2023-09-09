/*
============================================================================
Name : 8.c
Author : Abhishek Gupta
Description : Write a program to open a file in read only mode, read line by line
			  and display each line as it is read. Close the file when end of file is
			  reached.
Date: 28th Aug, 2023.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	char buffer[10000];
	int fd = open("3.c", O_RDONLY);
	char c;
	int i = 0;
	while (read(fd, &c, 1))
	{
		buffer[i++] = c;
		if (c == '\n')
		{
			// printf("\n ---------------\n");
			write(STDOUT_FILENO, buffer, i);
			i = 0;
		}
	}
}
