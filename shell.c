#include <unistd.h>
#include <stdio.h>
extern char** environ;
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", 0};
	if (isatty(STDIN_FILENO)) 
	{
		fprintf(stderr, "Connected to a terminal");
    	} 
    	else 
	{
	        execve(argv[0], &argv[0], environ);
                fprintf(stderr, "Oops!\n");
                return -1;
	}
	return 0;
}
