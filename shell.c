#include <unistd.h>
#include <stdio.h>
extern char** environ;
int main(void)
{
	char *args[] = { "bin", NULL, NULL};
	if (isatty(STDIN_FILENO)) 
	{
		fprintf(stderr, "Connected to a terminal");
    	} 
    	else 
	{
		
	        execve("/bin/ls", args, environ);
                fprintf(stderr, "Oops!\n");
                return -1;
	}
	return 0;
}
