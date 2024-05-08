#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int ac, char** av) {
    char *buffer = NULL;
    char *argv[] = {NULL, NULL};
    char *envp[] = {
        "HOME=/",
        "PATH=/bin:/usr/bin",
        "TZ=UTC0",
        "USER=beelzebub",
        "LOGNAME=tarzan",
        NULL};
    size_t bufsize = 32; 
    pid_t my_pid;
    int blabla;
    buffer = (char*)malloc(bufsize*sizeof(char));
    if (buffer == NULL) { 
	perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (isatty(STDIN_FILENO) && ac > 0) { 
	    while (1) {
            printf("#cisfun$ ");
            if (getline(&buffer, &bufsize, stdin) == -1) {
                free(buffer);
                exit(EXIT_FAILURE); 
	    }
            if (buffer[strlen(buffer) - 1] == '\n') {
                buffer[strlen(buffer) - 1] = '\0';
            }
            argv[0] = buffer;
            my_pid = fork();
            if (my_pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            if (my_pid != 0) {
                wait(&blabla);
            }
            if (my_pid == 0) {
                if (execve(argv[0], argv, envp) == -1) { 
                    perror(av[0]); 
                    exit(EXIT_FAILURE);
                }
            }
        }
    } else {
        if (getline(&buffer, &bufsize, stdin) == -1) {
            free(buffer);
            exit(EXIT_FAILURE);
        }
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }
        argv[0] = buffer;
        printf("%s\n", argv[0]);
	if (execve(argv[0], argv, envp) == -1)
	{ 
		perror(av[0]); 
		exit(EXIT_FAILURE);
        }
    }
    free(buffer); 
    return 0;
}

