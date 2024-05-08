#include <unistd.h>
#include <stdio.h>
int main(void)
{
	char *argv[] = { "/bin/ls", NULL, 0};
	char *envp[] = 
	{
		"HOME=/",
		"PATH=/bin:/usr/bin",
		"TZ=UTC0",
		"USER=beelzebub",
		"LOGNAME=tarzan",
		0
	};
	if (isatty(STDIN_FILENO)) 
	{
		fprintf(stderr, "Connected to a terminal");
    	} 
    	else 
	{
		
	        execve(argv[0], &argv[0], envp);
                fprintf(stderr, "Oops!\n");
                return -1;
	}
	return 0;
}
