#include "main.h"
extern char **environ; 

int main(int ac, char **av)
{
    if (isatty(0) && ac > 0)
    {
        printf("interactive mode\n");
    }
    else
    {
        execve("/bin/ls", av, environ);
        perror(av[0]); 
    }
    return 0;
}

