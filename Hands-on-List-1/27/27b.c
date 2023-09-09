/*
============================================================================
Name : 27.c
Author : Abhishek Gupta
Description : Write a program to execute ls -Rl by the following system calls
				a. execl
				b. execlp
				c. execle
				d. execv
				e. execvp
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	execlp("ls", "ls", "-R", "-l", NULL);

	return 0;
}
