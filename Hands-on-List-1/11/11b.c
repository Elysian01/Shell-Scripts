#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
     
int main(){
//using dup to automatically assign duplicate file discriptor to old file.
int fd=open("8.c",O_RDONLY);
int new_fd_ki_val;


printf("old file discriptor is %d \n", fd);
printf("enter new file discriptor is value");
scanf("%d",&new_fd_ki_val);


int new_fd=dup2(fd,new_fd_ki_val);
printf("new file discriptor is %d \n", new_fd);


struct stat sb1,sb2;
fstat(fd, &sb1);
fstat(new_fd, &sb2);

printf("Inode of old fd=%ld\n",sb1.st_ino);
printf("Inode of new fd=%ld\n",sb2.st_ino);


return 0;
}
