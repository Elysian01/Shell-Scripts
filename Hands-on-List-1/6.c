#include <unistd.h>
#include <fcntl.h>

int main()
{
    char buf[1024];
    // 0 means STDIN, 1 means STDOUT
    // STDIN_FILENO macro for stdin
    read(STDIN_FILENO, buf, sizeof(buf));
    write(STDOUT_FILENO, buf, sizeof(buf));
    return 0;
}
