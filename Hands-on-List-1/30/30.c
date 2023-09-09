/*
============================================================================
Name : 30.c
Author : Abhishek Gupta
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 8th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int hour, min;
	printf("Enter time to run a process (HH:MM) ");
	scanf("%d:%d", &hour, &min);

	if (fork())
		exit(0);
	setsid();
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	while (1)
	{
		struct tm *tm;
		time_t current_time;
		time(&current_time);
		tm = localtime(&current_time);
		if (tm->tm_hour == hour && tm->tm_min == min)
		{
			system("bash 30_script.sh");
			break;
		}
		sleep(5);
	}

	return 0;
}
