#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() 
{
        char *argv[] = {"/bin/ls", "-l", 0};
        char *envp[] = {
            "HOME=/",
            "PATH=/bin:/usr/bin",
            "TZ=UTC0",
            "USER=beelzebub",
            "LOGNAME=tarzan",
            0};
    if (isatty(0))
    {
        printf("interactive mode\n");
    } 
    else
    {
        execve(argv[0], &argv[0], envp);
        fprintf(stderr, "Oops!\n");
        return -1;
    }
    return 0;
}

