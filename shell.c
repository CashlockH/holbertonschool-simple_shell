#include "main.h"
int main (int ac, char ** av)
{
        if(isatty(0) && ac > 0)
        {
                printf("interactive mode\n");
        }
        else
        {
                execve("/bin/ls", av, NULL);
        }
        return 0;
}
