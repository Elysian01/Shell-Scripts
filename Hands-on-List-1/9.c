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

	// TO PRINT FILE TYPE INFO
	printf("File Type: ");
	switch (sb.st_mode & S_IFMT)
	{
	case S_IFBLK:
		printf("block device\n");
		break;
	case S_IFCHR:
		printf("character device\n");
		break;
	case S_IFDIR:
		printf("directory\n");
		break;
	case S_IFIFO:
		printf("FIFO/pipe\n");
		break;
	case S_IFLNK:
		printf("symlink\n");
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
}
