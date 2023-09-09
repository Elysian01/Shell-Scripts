/*
============================================================================
Name : 18b.c
Author : Abhishek Gupta
Description : Write a program to perform Record locking.
				a. Implement write lock
				b. Implement read lock
				Create three records in a file. Whenever you access a particular
				record, first lock it then modify/access to avoid race condition.
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	struct student
	{
		char *name;
		int roll_no;
	} a;
	struct flock fl;

	int fd = open("18Record", O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		return 0;
	}
	printf("Enter record number to read ");
	int num;
	scanf("%d", &num);
	fl.l_type = F_RDLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = (num - 1) * sizeof(a);
	fl.l_len = sizeof(a);
	fl.l_pid = getpid();

	printf("Before lock\n");

	fcntl(fd, F_SETLKW, &fl);
	printf("Inside critical section\n");

	lseek(fd, (num - 1) * sizeof(a), SEEK_CUR);
	read(fd, &a, sizeof(a));
	printf("Current roll number = %d\n", a.roll_no);

	fl.l_type = F_UNLCK;
	printf("Press any key to unlock\n");
	getchar();
	getchar();
	fcntl(fd, F_SETLK, &fl);

	return 0;
}
