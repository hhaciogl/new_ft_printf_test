#include "test.h"

size_t ft_strlen_mocked(char *str)
{
    printf("%s", str);
    return 42;
}

int main()
{
    test_libftprintf();
}
