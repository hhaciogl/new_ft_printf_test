#include "../test.h"
#include "../lib/ft_printf.h"
#include <string.h>

extern char my_buff[1024];


void test_ft_printf_with_arg_hello()
{
    strcpy(my_buff, "");
    ft_printf("hello");
    char *actual = my_buff;
    TEST(strcmp(actual, "hello") == 0, __func__);
    printf("Actual:%s\n", actual);
    printf("Expect:");
    printf("hello");
    printf("\n");
}


void test_ft_printf_with_arg_hello_Fs_world()
{
    strcpy(my_buff, "");
    ft_printf("hello %s", "world");
    char *actual = my_buff;
    TEST(strcmp(actual, "hello world") == 0, __func__);
    printf("Actual:%s\n", actual);
    printf("Expect:");
    printf("hello %s", "world");
    printf("\n");
}

void test_ft_printf_with_arg_num_Fi_25()
{
    strcpy(my_buff, "");
    ft_printf("num %i", 25);
    char *actual = my_buff;
    TEST(strcmp(actual, "num 25") == 0, __func__);
    printf("Actual:%s\n", actual);
    printf("Expect:");
    printf("num %i", 25);
    printf("\n");
}







void test_ft_printf()
{
    puts(__func__);
    test_ft_printf_with_arg_hello();
    test_ft_printf_with_arg_hello_Fs_world();
    test_ft_printf_with_arg_num_Fi_25();
}