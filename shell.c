#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int ac, char **av) {
    if (isatty(0) && ac > 0) {
        printf("interactive mode\n");
    } else {
        if (execve("/bin/ls", av, av) == -1) {
            perror("execve");
            return errno;
        }
    }
    return 0;
}

