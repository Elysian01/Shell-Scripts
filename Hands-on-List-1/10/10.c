#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("2 arguments are required\n");
		return 0;
	}
	int f1 = open(argv[1], O_CREAT | O_EXCL | O_WRONLY, 0777);
	if (f1 == -1)
	{
		printf("Error opening file\n");
		close(f1);
		return 0;
	}
	// greetings is 9 letter, 10th letter is '\0'
	char buff[] = "Greetings";
	write(f1, buff, sizeof(buff));
	int x = lseek(f1, 10, SEEK_CUR);
	if (x)
		printf("Lseek return value: %d\n", x);
	else
		perror("Lseek: ");
	write(f1, buff, sizeof(buff));
}