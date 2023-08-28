#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int fd = open("ticket_number.txt",O_CREAT|O_WRONLY, 0777);
        if(fd==-1){
        printf("Error opening file\n(or)Try deleteing the ticket_number file\n");
		close(fd);
		return 0;
    }
    write(1,"Enter the number of tickets to allot: ",39);
    char buf[11];
    read(0, buf, 10);
    write(fd,buf,strlen(buf));
    close(fd);
}