#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int fd = open("doc.txt",O_RDWR);
        if(fd==-1){
        printf("Error opening file\n");
		close(fd);
		return 0;
    }
    char buf[11];
    struct flock lock;
    lock.l_type    = F_WRLCK;   
    lock.l_start   = 0;
    lock.l_whence  = SEEK_SET;
    lock.l_len     = sizeof(buf); 
    lock.l_pid = getpid();
    printf("Before entering the critical section\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Inside the critical section....\n");
    printf("Enter to unlock..\n");
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    printf("Finish..\n");

}
