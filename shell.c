#include "main.h"
int main (int ac, char **av)
{
        char *buffer;
        size_t bufsize = 5;
        pid_t my_pid;
        int blabla;
        char *args[] = { "bin", NULL, NULL};
        buffer = malloc(bufsize*sizeof(char));
	printf("%s", av[0]);
        if(isatty(0) && ac > 0)
        {
                while (1)
                {
                        printf("#cisfun$ ");
                        if (getline(&buffer,&bufsize,stdin) == -1)
                                free(buffer);
                        if (buffer[strlen(buffer) - 1] == '\n')
                                buffer[strlen(buffer) - 1] = '\0';
                        args[2] = buffer;
			printf("%s", args[2]);
                        my_pid = fork();
                        if (my_pid != 0)
                                wait(&blabla);
                        if (my_pid == 0)
                        {
                                printf("ah");
                        }
                }
        }
        else
        {
                if (getline(&buffer,&bufsize,stdin) == -1)
                        free(buffer);
                if (buffer[strlen(buffer) - 1] == '\n')
                        buffer[strlen(buffer) - 1] = '\0';
                args[2] = buffer;
        }
        return 0;
}
