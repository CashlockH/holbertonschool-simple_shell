#include "main.h"
int main ()
{
        if(isatty(0))
        {
                printf("interactive mode'dayiq\n");
        }
        else
        {
                printf("non-interactive mode'dayiq\n");
        }
        return 0;
}
