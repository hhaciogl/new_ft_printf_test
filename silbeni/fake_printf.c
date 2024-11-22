#define _GNU_SOURCE
#include <aio.h>
#include <stdio.h>
#include <string.h>


extern char my_buff[1024];

ssize_t __wrap_write(int fd, const void *buf, size_t count)
{
    (void)fd;
    printf("[%s]", (char *)buf);
    strcat(my_buff, (char *)buf);
    return (count);
}