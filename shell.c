#include "main.h"
int main (int ac, char ** av, char** env)
{
        if(isatty(0) && ac > 0)
        {
                printf("interactive mode\n");
        }
        else
        {
                execve("/bin/ls", av, env);
        }
        return 0;
}
