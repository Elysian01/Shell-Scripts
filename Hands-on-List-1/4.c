#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
    // use O600 means user has read and write permission
    int fd = open("temp.txt", O_EXCL, 0600);
    if (fd == -1)
    {
        perror("Failed to open file");
    }
    return 0;
}
