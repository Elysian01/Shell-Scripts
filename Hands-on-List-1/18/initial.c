#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd = open("db.txt", O_CREAT | O_WRONLY, 0777);
    if (fd == -1)
    {
        printf("Error opening file\n(or)Try deleteing the ticket_number file\n");
        close(fd);
        return 0;
    }
    char buf[11];
    for (int i = 0; i < 3; i++)
    {
        lseek(fd, i * sizeof(buf), SEEK_SET);
        write(1, "Enter the integer:  ", 21);
        read(0, &buf, sizeof(buf));
        write(fd, &buf, sizeof(buf));
    }
    close(fd);
}