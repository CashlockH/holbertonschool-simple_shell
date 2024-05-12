#include "main.h"
/**
 * custom_getenv - Gets the value of a specific environment variable.
 * @name: The name of the environment variable to retrieve.
 * @args: An array used to store the retrieved value, limited to a maximum size of 64 characters.
 * Return: Returns either the value, 1 if there's an issue, or 0 if successful.
 */
int custom_getenv(const char* name, char *args[64])
{
    extern char** environ;
    int j = 0, a = 0;
    size_t i;
        char *env_var;
        char *token, *zoken;
    for (i = 0; environ[i] != NULL; i++)
    {
        env_var = strdup(environ[i]);
        token = strtok(env_var, "=");
        if (token != NULL && strcmp(token, name) == 0)
        {
              a = 0;   
            token = strtok(NULL, "=");
                if(token == NULL)
                {
                        free(env_var);
                        a = 1;
                        break;
                }
                zoken = strtok(token, ":");        
            while (token != NULL && zoken != NULL)
            {
                args[j] = strdup(token), j++;
                token = strtok(NULL, ":");
            }
            args[j] = NULL;
                free(env_var);
            break;
        }
        else
                a = 1;
        free(env_var);
    }
        return a;
}

/**
 * _printenv - Displays the contents of environment variables.
 * @envi: Pointer to an array of strings representing environment variables.
 */
void _printenv(char **envi)
{
        int i = 0;
        while(envi[i] != NULL)
                {
                        printf("%s\n", envi[i]);
                        i++;
                }
}


/**
 * args_writer - Writes the contents of an array of strings to a buffer.
 * @arv: An array of strings to write to the buffer.
 * @code_holder: Pointer to the buffer where the contents will be written.
 * Return: Returns 1 upon completion.
 */
int args_writer(char *arv[64], char *code_holder)
{
    char *args[64];
    char *nese = strdup(code_holder);
    int i = 0, j = 0, geti = 0;
        args[0] = NULL;
        geti = custom_getenv("PATH", args);

    while (args[i])
    {        
        strcat(args[i], "/");
        strcat(args[i], nese);
        if (access(args[i], X_OK) == 0)
        {
            arv[j] = strdup(args[i]);
            break;
            j++;
        }
        i++;
    }
    free(nese);
    return geti;
}


/**
 * main - Program entry point.
 * @ac: Number of command-line arguments received.
 * @av: Array of strings representing the command-line arguments.
 * Return: Returns 0 or 1.
 */
int main(int ac, char **av)
{
        pid_t my_pid;
        size_t bufsize = 64;
        int status, status_tutan = 5, nese = 0;
        char *args[64];
        char *buffer = malloc(bufsize * sizeof(char));
        char *token;
        int i = 0, j, writer = 0;
        if (!buffer)
        {
                perror("malloc");
                exit(EXIT_FAILURE);
        }

        while (ac > 0 && nese != EOF)
        {
                nese = getline(&buffer, &bufsize, stdin);
                if (nese == 1)
                        continue;
                else if (nese == -1)
                        break;
                else
                {
                        args[0] = NULL;
                        args[1] = NULL;
                        i = 0;
                        if (buffer[strlen(buffer) - 1] == '\n')
                                buffer[strlen(buffer) - 1] = '\0';
                        token = strtok(buffer, " \n\t");
                        if (token == NULL)
                        {
                                free(buffer);
                                exit(EXIT_SUCCESS);
                        }
                        while (token != NULL)
                        {
                                args[i] = strdup(token);
                                if (!args[i])
                                {
                                        perror("strdup");
                                        exit(EXIT_FAILURE);
                                }
                                token = strtok(NULL, " \n\t");
                                i++;
                        }
                        args[i] = NULL;
                        if (strcmp(args[0], "exit") == 0)
                        {
                                free(buffer);
                                for (j = 0; j < i; j++)
                                        free(args[j]);
                                if (status_tutan == 5)
                                        exit(0);
                                else if (status_tutan == 512)
                                        exit(2);
                                else
                                        exit(EXIT_SUCCESS);
                        }
                        if (strcmp(args[0], "env") == 0)
                        {        

                                free(buffer);
                                for(j = 0; j < i; j++)
                                        free(args[j]);

                                _printenv(environ);
                                exit(EXIT_SUCCESS);

                        }
                        my_pid = fork();
                        if (my_pid == -1)
                        {
                                perror("fork");
                                exit(EXIT_FAILURE);
                        }
                        else if (my_pid == 0)
                        {

                                if (strchr(args[0], '/') == 0)
                                {
                                        writer = args_writer(args, args[0]);
                                }
                                if (writer == 1)
                                {
                                        fprintf(stderr, "%s: 1: %s: not found\n", av[0], buffer);
                                        free(buffer);
                                        for (j = 0; j < i; j++)
                                        free(args[j]);
                                        exit(127);
                                }
                                else if (execve(args[0], args, environ) == -1)
                                {
                                        fprintf(stderr, "%s: 1: %s: not found\n", av[0], buffer);
                                        free(buffer);
                                        for (j = 0; j < i; j++)
                                        free(args[j]);
                                        exit(127);
                                }
                        }
                        else
                        wait(&status);
                        status_tutan = status;
                        for (j = 0; j < i; j++)
                        free(args[j]);
                } 
        }
        free(buffer);
        if (status_tutan == 32512)
                return(127);
        return (0);
}
