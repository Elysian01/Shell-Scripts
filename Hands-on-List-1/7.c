#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>

int main(int argc, char* argv[]) {
        if(argc!=3)
        {
                printf("You are useless\n");
                return -1;
        }
        int fd_read = open(argv[1], O_RDONLY);
        // give permission otherwise, it will randomly assign it anything
        int fd_write = open(argv[2], O_WRONLY|O_CREAT, 0600);

        if(fd_read==-1 || fd_write==-1)
                printf("Your system is useless\n");

        // Logic
        while(1){
                char buf;
                int read_byte = read(fd_read, &buf, 1);

                if(read_byte==0)
                        break;

                int write_bytes = write(fd_write, &buf, 1);
        }
        int close_fd_read = close(fd_read);
        int close_fd_write = close(fd_write);

        if(close_fd_read==-1 || close_fd_write==-1)
                printf("Your system is useless, coz it can't even close a file\n");

        return 0;

}

