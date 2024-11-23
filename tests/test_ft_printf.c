#include "../test.h"
#include "../lib/ft_printf.h"

extern char my_buff[1024];
int test_ft_printf(char *line_no, const char *format, void *arg, void *arg1, char *exp_sout, int exp);

int prints_a_single_char(void)
{
    return (
        test_ft_printf("10","This is a char: %c", (void *)'z', NULL, "This is a char: z", 17) &&
        test_ft_printf("11","This is a char: %c", (void *)'%', NULL, "This is a char: %", 17) &&
        test_ft_printf("12","This is \0a char: %c", (void *)'%', NULL, "This is ", 8) &&
        test_ft_printf("13","[%c]", (void *)'\0', NULL, "[]", 3) &&
        test_ft_printf("14","[%c]", (void *)'\n', NULL, "[\n]", 3)
    );
}
int prints_a_string(void)
{
    return (
        test_ft_printf("20","This is a string: %s", (void *)"str", NULL, "This is a string: str", 21) &&
        test_ft_printf("21","This is a string: %s", (void *)"st\0r", NULL, "This is a string: st", 20) &&
        test_ft_printf("22", "This is an empty string:%s", (void *)"", NULL, "This is an empty string:", 24) &&
        1
    );
}

int prints_a_percent_sign(void)
{
	return (
		test_ft_printf("30", "%%", (void *)NULL, NULL, "%", 1) &&
		test_ft_printf("31", "%%", (void *)"%", NULL, "%", 1) &&
		test_ft_printf("32", "%%", (void *)'%', NULL, "%", 1) &&
		test_ft_printf("33", "%z", (void *)"%", NULL, "", -1) &&
		test_ft_printf("34", "%", (void *)"%", NULL, "", -1) &&
        1
	);
}
int prints_a_decimal_or_an_integer(void)
{
	return (//2147483647
		test_ft_printf("41", "%d", (void *)23, NULL, "23", 2) &&
		test_ft_printf("42", "%d", (void *)2147483647, NULL, "2147483647", 10) &&
		test_ft_printf("43", "%d", (void *)2147483648, NULL, "2147483647", 10) &&
		1
	);
}


int test_ft_printf(char *line_no, const char *format, void *arg, void *arg1, char *exp_sout, int exp)
{
    char *act_sout;
    int act;
    int cond;
    bzero(my_buff, 1024);
    
    act = ft_printf(format, arg, arg1);
    act_sout = my_buff;
    cond = strcmp(act_sout, exp_sout) == 0 && act == exp;
    if (cond == 0 || DEBUG)
    {
        TEST(cond, line_no);
        printf("%s\n", "[expect]"); 
        printf("%s\n", "<actual>");
        printf("[%s]\n", exp_sout);
        printf("<%s>\n", act_sout);
        printf("[%i]\n", exp);
        printf("<%i>\n", act);
    }
    return (cond);
}

void tests_ft_printf()
{
    puts(__func__);
    DESCRIBE("%c Prints a single character", prints_a_single_char);
    DESCRIBE("%s Prints a string (as defined by the common C convention)", prints_a_string);
    XDESCRIBE("%p The void * pointer argument has to be printed in hexadecimal format");
    DESCRIBE("%d Prints a decimal (base 10) number", prints_a_decimal_or_an_integer);
    XDESCRIBE("%i Prints an integer in base 10");
    XDESCRIBE("%u Prints an unsigned decimal (base 10) number");
    XDESCRIBE("%x Prints a number in hexadecimal (base 16) lowercase format");
    XDESCRIBE("%X Prints a number in hexadecimal (base 16) uppercase format");
    DESCRIBE("%% Prints a percent sign", prints_a_percent_sign);
    return;
}