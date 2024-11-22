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
    strcpy(my_buff, "");
    int actual_return;
	int expect_return;
	char *actual;
	char *expect;
	int condition;
	

	actual_return = ft_printf("hello");
    actual = my_buff;
    printf("Actual:%s writes: %i bytes\n", actual, actual_return);
    printf("Expect:");
    expect_return = printf("hello");
	printf(" writes: %i bytes", expect_return);
    printf("\n");
	expect = "hello";
	condition = strcmp(actual, expect) == 0 && expect_return == actual_return;
	TEST(condition, __func__);
}

void test_ft_printf_with_arg_hello0Fs_world()
{
    strcpy(my_buff, "");
    int actual_return;
	int expect_return;
	char *actual;
	char *expect;
	int condition;
	

	actual_return = ft_printf("hello %s", "world");
    actual = my_buff;
    printf("Actual:%s writes: %i bytes\n", actual, actual_return);
    printf("Expect:");
    expect_return = printf("hello %s", "world");
	printf(" writes: %i bytes", expect_return);
    printf("\n");
	expect = "hello world";
	condition = strcmp(actual, expect) == 0 && expect_return == actual_return;
	TEST(condition, __func__);
}

void test_ft_printf_with_arg_num0Fi_42()
{
    strcpy(my_buff, "");
    int actual_return;
	int expect_return;
	char *actual;
	char *expect;
	int condition;
	

	actual_return = ft_printf("num %i", 42);
    actual = my_buff;
    printf("Actual:%s writes: %i bytes\n", actual, actual_return);
    printf("Expect:");
    expect_return = printf("num %i", 42);
	printf(" writes: %i bytes", expect_return);
    printf("\n");
	expect = "num 42";
	condition = strcmp(actual, expect) == 0 && expect_return == actual_return;
	TEST(condition, __func__);
}

void test_ft_printf_with_arg_FF()
{
    strcpy(my_buff, "");
    int actual_return;
	int expect_return;
	char *actual;
	char *expect;
	int condition;
	

	actual_return = ft_printf("%%");
    actual = my_buff;
    printf("Actual:%s writes: %i bytes\n", actual, actual_return);
    printf("Expect:");
    expect_return = printf("%%");
	printf(" writes: %i bytes", expect_return);
    printf("\n");
	expect = "%";
	condition = strcmp(actual, expect) == 0 && expect_return == actual_return;
	TEST(condition, __func__);
}

void test_ft_printf_with_arg_FcFc_A_B()
{
    strcpy(my_buff, "");
    int actual_return;
	int expect_return;
	char *actual;
	char *expect;
	int condition;
	

	actual_return = ft_printf("%c%c", 'A','B');
    actual = my_buff;
    printf("Actual:%s writes: %i bytes\n", actual, actual_return);
    printf("Expect:");
    expect_return = printf("%c%c", 'A','B');
	printf(" writes: %i bytes", expect_return);
    printf("\n");
	expect = "AB";
	condition = strcmp(actual, expect) == 0 && expect_return == actual_return;
	TEST(condition, __func__);
}

void test_ft_printf_with_arg_Fp_voidP()
{
    strcpy(my_buff, "");
    int actual_return;
	int expect_return;
	char *actual;
	char expect[50];
	int condition;
	int	voidP;
	
	voidP = 5;
	actual_return = ft_printf("%p", (void *)&voidP );
    actual = my_buff;
    printf("Actual:%s writes: %i bytes\n", actual, actual_return);
    printf("Expect:");
    expect_return = printf("%llu", (long long unsigned)&voidP);
	printf(" writes: %i bytes", expect_return);
    printf("\n");
	sprintf(expect, "%p", (void *)&voidP );
	condition = strcmp(actual, expect) == 0 && expect_return == actual_return;
	TEST(condition, __func__);
}

void test_ft_printf()
{
    puts(__func__);
    test_ft_printf_with_arg_F();
    test_ft_printf_with_arg_FF();
    test_ft_printf_with_arg_FFF();
    test_ft_printf_with_arg_hello();
	test_ft_printf_with_arg_hello0Fs_world();
	test_ft_printf_with_arg_num0Fi_42();
	test_ft_printf_with_arg_FF();
	test_ft_printf_with_arg_FcFc_A_B();
	test_ft_printf_with_arg_Fp_voidP();
}