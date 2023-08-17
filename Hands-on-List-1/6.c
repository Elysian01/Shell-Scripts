#include <unistd.h>
#include <fcntl.h>

int main()
{
    char buf[1024];
    // 0 means STDIN, 1 means STDOUT
    read(0, buf, sizeof(buf));
    write(1, buf, sizeof(buf));
    return 0;
}