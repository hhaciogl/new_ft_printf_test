#include "../test.h"
#define ft_strlen ft_strlen_mocked
size_t ft_strlen_mocked(char *str); 
#include "../lib/ft_printf.h"
#undef ft_strlen


void test_libftprintf()
{
    printf("size: %zu\n", ft_strlen("hello"));
}