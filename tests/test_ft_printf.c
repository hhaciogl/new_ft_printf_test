#include "../test.h"
#include "../lib/ft_printf.h"
#include <string.h>

extern char my_buff[1024];


void test_ft_printf_with_arg_F()
{
    bzero(my_buff, 100);
    int actual_return;
    //int expect_return;
    actual_return = ft_printf("%");
    char *actual = my_buff;
    if (actual_return < 0)
         TEST(strcmp(actual, "%") == 0, __func__);
    else
        TEST(0, __func__);
    printf("Actual:%s\n", actual);
    printf("Expect:");
    //expect_return = printf("%");
    printf("\n");
}

void test_ft_printf_with_arg_FF()
{
    bzero(my_buff, 100);
    ft_printf("%%");
    char *actual = my_buff;
    TEST(strcmp(actual, "%") == 0, __func__);
    printf("Actual:%s\n", actual);
    printf("Expect:");
    printf("%%");
    printf("\n");
}

void test_ft_printf_with_arg_FFF()
{
    bzero(my_buff, 100);
    ft_printf("%%%");
    char *actual = my_buff;
    TEST(strcmp(actual, "%") == 0, __func__);
    printf("Actual:%s\n", actual);
    printf("Expect:");
    //printf("%%%");
    printf("\n");
}

void test_ft_printf_with_arg_hello()
{
    bzero(my_buff, 100);
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
    bzero(my_buff, 100);
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
    bzero(my_buff, 100);
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
    test_ft_printf_with_arg_F();
    test_ft_printf_with_arg_FF();
    test_ft_printf_with_arg_FFF();
    test_ft_printf_with_arg_hello();
    test_ft_printf_with_arg_hello_Fs_world();
    test_ft_printf_with_arg_num_Fi_25();
}