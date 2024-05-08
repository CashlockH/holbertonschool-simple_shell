#include "main.h"
int main ()
{
        char *buffer;
        size_t bufsize = 5;
        int nese;
        buffer = malloc(bufsize*sizeof(char));
        if(isatty(0))
        {
                nese = getline(&buffer, &bufsize, stdin);
                printf("%d", nese);
        }
        else
        {
                if (getline(&buffer,&bufsize,stdin) == -1)
                        free(buffer);
                printf("asdf");
        }
        return 0;
}
