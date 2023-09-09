/*
============================================================================
Name : 14.c
Author : Abhishek Gupta
Description : Write a program to find the type of a file.
				a. Input should be taken from command line.
				b. program should be able to identify any type of a file.
Date: 28th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

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

	// TO PRINT FILE TYPE INFO
	printf("File Type: ");
	switch (sb.st_mode & S_IFMT)
	{
	case S_IFBLK:
		printf("Block device\n");
		break;
	case S_IFCHR:
		printf("Character device\n");
		break;
	case S_IFDIR:
		printf("Directory\n");
		break;
	case S_IFIFO:
		printf("FIFO/pipe\n");
		break;
	case S_IFLNK:
		printf("Symlink\n");
		break;
	case S_IFREG:
		printf("regular file\n");
		break;
	case S_IFSOCK:
		printf("socket\n");
		break;
	default:
		printf("unknown?\n");
		break;
	}

	return 0;
}
