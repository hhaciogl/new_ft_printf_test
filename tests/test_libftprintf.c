#include "../test.h"
#include "../lib/ft_printf.h"

void test_libftprintf(void)
{
    ft_printf("hello");
    TEST(0, __func__);
}
