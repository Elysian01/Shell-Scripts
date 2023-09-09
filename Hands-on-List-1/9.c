/*
============================================================================
Name : 9.c
Author : Abhishek Gupta
Description : Write a program to print the following information about a given file.
				a. inode
				b. number of hard links
				c. uid
				d. gid
				e. size
				f. block size
				g. number of blocks
				h. time of last access
				i. time of last modification
				j. time of last change
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		printf("Enter filename");
		return -1;
	}

	// predefined structure
	struct stat sb;
	// stat(filename, struct variable);
	stat(argv[1], &sb);

	printf("inode no: %ld \n", sb.st_ino);
	printf("no. of hard links: %ld \n", sb.st_nlink);
	printf("uid: %u \n", sb.st_uid);
	printf("gid: %u \n", sb.st_gid);
	printf("block size: %ld\n", sb.st_blksize);
	printf("No. of blocks: %ld\n", sb.st_blocks);

	// ctime function will print time in standard unit, otherwise time will be printed in seconds
	printf("Last access time: %s", ctime(&sb.st_atime));
	printf("last modification time: %s", ctime(&sb.st_mtime));
	printf("last change time: %s", ctime(&sb.st_ctime));
}
