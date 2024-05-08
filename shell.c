#include "main.h"
extern char** environ;
int main (int ac, char **av)
{
        size_t bufsize = 5;
        pid_t my_pid;
        int status;
        char *buffer = malloc(sizeof(char) * bufsize);
        char *args[65];
        if(isatty(0) && ac > 0)
        {
                while (1)
                {
                printf("#cisfun$ ");
                        if (getline(&buffer,&bufsize,stdin) == -1)
                        {
                                free(buffer);
                                perror("getline");
                                exit(EXIT_FAILURE);
                        }
                        if (buffer[strlen(buffer) - 1] == '\n')
                                buffer[strlen(buffer) - 1] = '\0';
                        my_pid = fork();
                        if (my_pid == -1) {
                            perror("fork");
                            exit(EXIT_FAILURE);
                        }
                        if (my_pid == 0)
                        {
                                if (execve(buffer, args, environ) == -1)
                                {
                                        perror(av[0]);
                                        exit(EXIT_FAILURE);
                                }
                         
                        }
                        else
                        {
                                    waitpid(my_pid, &status, 0);
                                    if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
                                        printf("OK\n");
                        }
                }
        }
        else
        {
                if (getline(&buffer,&bufsize,stdin) == -1)
                {
                        free(buffer);
                        perror("getline");
                        exit(EXIT_FAILURE);
                }
                if (buffer[strlen(buffer) - 1] == '\n')
                        buffer[strlen(buffer) - 1] = '\0';
                if (execve(buffer, args, environ) == -1)
                {
                        perror(av[0]);
                        exit(EXIT_FAILURE);
                }
        }
        free(buffer);
        return(status);
}

