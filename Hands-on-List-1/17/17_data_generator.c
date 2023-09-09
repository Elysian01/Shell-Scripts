/*
============================================================================
Name : 17_data_generator.c
Author : Abhishek Gupta
Description : Write a program to simulate online ticket reservation.
				Implement write lock Write a program to open a file, store a ticket
				number and exit. Write a separate program, to open the file,
				implement write lock, read the ticket number, increment the number
				and print the new ticket number then close the file.
Date: 28th Aug, 2023.
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	struct train
	{
		int train_no;
		int ticket_no;
	} record;

	int fd = open("train", O_CREAT | O_RDWR, 0600);
	record.train_no = 123;
	record.ticket_no = 56;

	write(fd, &record, sizeof(record));

	return 0;
}
