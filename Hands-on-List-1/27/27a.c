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
	// cmd (KAHA SE USKO UTHANA HAI), arg1, arg2, ... (arguments kitne bhi hosakte hai, isliye to denote its end we use NULL)
	printf("start\n");
	execl("/bin/ls", "ls", "-R", "-l", NULL);
	printf("Mai bhi execute hoga"); // ye execute nhi hogas

	return 0;
}
