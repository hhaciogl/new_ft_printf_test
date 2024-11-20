#include <aio.h>
#include <stdio.h>
#include <string.h>

extern char my_buff[100];

ssize_t __wrap_write(int fd, const void *buf, size_t count)
{
    (void)fd;
    strncat(my_buff, (char *)buf, count);
    return (count);
}