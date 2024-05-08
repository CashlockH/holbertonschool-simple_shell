#include <unistd.h>
#include <stdio.h>
extern char** environ;
int main(void)
{
	char *args[] = { "bin", NULL, 0};
	if (isatty(STDIN_FILENO)) 
	{
		fprintf(stderr, "Connected to a terminal");
    	} 
    	else 
	{
		
	        execve("/bin/ls", &args[0], environ);
                fprintf(stderr, "Oops!\n");
                return -1;
	}
	return 0;
}
