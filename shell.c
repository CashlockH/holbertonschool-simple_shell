#include "main.h"
int main (int ac, char ** av, char** env)
{
        if(isatty(0) && ac > 0)
        {
                printf("interactive mode\n");
        }
        else
        {
                if (execve("/bin/ls", av, env) == -1)
                        perror(av[0]);
        }
        return 0;
}
