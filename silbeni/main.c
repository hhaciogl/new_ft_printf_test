#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "original_printf.h"

char my_buff[1024];

int main()
{
    my_print("test");
    my_print("hello");
    printf("%s", my_buff);
    return 0;
}