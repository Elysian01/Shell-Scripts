/*
============================================================================
Name : data.c
Author : Abhishek Gupta
Description : Write a program to perform Record locking.
				a. Implement write lock
				b. Implement read lock
				Create three records in a file. Whenever you access a particular
				record, first lock it then modify/access to avoid race condition.
Date: 28th Aug, 2023.
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("18Record", O_RDWR | O_CREAT, 0600);
	struct student
	{
		char *name;
		int roll_no;
	} a;

	for (int i = 1; i <= 3; i++)
	{
		a.name = "A";
		a.roll_no = i;
		write(fd, &a, sizeof(a));
	}

	return 0;
}
