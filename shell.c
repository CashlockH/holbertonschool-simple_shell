#include "main.h"
int main (int ac, char ** av, char** env)
{
        char *buffer;
        size_t bufsize = 5;
        pid_t my_pid;
        int blabla;
        char *args[] = { "bin", NULL, NULL};
        buffer = malloc(bufsize*sizeof(char));
        if(isatty(0) && ac > 0)
        {
               	printf("interactive mode\n");
        }
        else
        {
                if (getline(&buffer,&bufsize,stdin) == -1)
                        free(buffer);
                if (buffer[strlen(buffer) - 1] == '\n')
                        buffer[strlen(buffer) - 1] = '\0';
                args[2] = buffer;
                if (execve(buffer, args, env) == -1)
                        perror(av[0]);
        }
        return 0;
}


