#include <unistd.h>
#include <string.h>

void my_print(char *str)
{
    write(1,str, strlen(str));
}