#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
extern char** environ;
int main(void)
{
    char *argv[] = { "ls", NULL };
    if (isatty(STDIN_FILENO))
    {
        fprintf(stderr, "Connected to a terminal\n");
    }
    else
    {
        execve(argv[0], argv, environ);
        perror("execve");
        return -1;
    }

    return 0;
}

