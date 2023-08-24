#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int main(){

	int fd=open("10data.txt",O_RDWR|O_CREAT, 0666);
	if(fd==-1)
		printf("file not created");

	char buff[30];

	read(STDIN_FILENO,buff,10);
	write(fd,buff,10);
	fflush(stdin);
	lseek(fd,10,SEEK_CUR);

	int c;
	while ((c = getchar()) != '\n' && c != EOF);

	read(STDIN_FILENO,buff,10);
	write(fd,buff,10);

	lseek(fd, 0, SEEK_SET);

	ssize_t bytesRead = read(fd, buff, 30);
	if (bytesRead > 0) {
		write(STDOUT_FILENO, buff, bytesRead);
	} else {
		printf("Error reading from file.\n");
	}

       close(fd);
       return 0;
}
