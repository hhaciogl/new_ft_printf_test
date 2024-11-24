#include "../test.h"
#include "../lib/ft_printf.h"
#include <stdio.h>
#include <limits.h>

extern char my_buff[1024];
int test_ft_printf(char *line_no, const char *format, void *arg, char *arg1, char *exp_sout, int exp);

int prints_a_single_char(void)
{
    return (
        test_ft_printf("10","This is a char: %c", (void *)'z', "z", "This is a char: z", 17) &&
        test_ft_printf("11","This is a char: %c", (void *)'%', "%", "This is a char: %", 17) &&
        test_ft_printf("12","This is \0a char: %c", (void *)'%', "%", "This is ", 8) &&
        test_ft_printf("13","[%c]", (void *)'\0', "\\0", "[]", 3) &&
        test_ft_printf("14","[%c]", (void *)'\n', "\\n", "[\n]", 3)
    );
}
int prints_a_string(void)
{
    return (
        test_ft_printf("20","This is a string: %s", (void *)"str", "str", "This is a string: str", 21) &&
        test_ft_printf("21","This is a string: %s", (void *)"st\0r", "st\\0r", "This is a string: st", 20) &&
        test_ft_printf("22", "This is an empty string:%s", (void *)"", "", "This is an empty string:", 24)
    );
}
int prints_a_percent_sign(void)
{
	return (
		test_ft_printf("30", "%%", (void *)NULL, "NULL", "%", 1) &&
		test_ft_printf("31", "%%", (void *)"%", "%", "%", 1) &&
		test_ft_printf("32", "%%", (void *)'%', "%", "%", 1) &&
		test_ft_printf("33", "%z", (void *)"%", "%", "", -1) &&
		test_ft_printf("34", "%", (void *)"%", "%", "", -1) &&
        1
	);
}
int prints_a_decimal_or_an_integer(void)
{
	return (
		test_ft_printf("41", "%d", (void *)23, "23", "23", 2) &&
		test_ft_printf("42", "%d", (void *)2147483647, "2147483647", "2147483647", 10) &&
		test_ft_printf("43", "%d", (void *)INT_MIN, "INT_MIN", "-2147483648", 11) &&
		1
	);
}

int prints_an_unsigned_decimal(void)
{
    return (
		test_ft_printf("51", "%u", (void *)INT_MIN, "INT_MIN", "2147483648", 10) &&
        test_ft_printf("52", "%u", (void *)INT_MAX, "INT_MAX", "2147483647", 10) &&
        test_ft_printf("53", "%u", (void *)0, "0", "0", 1) &&
        test_ft_printf("54", "%u", (void *)45, "45", "45", 2) &&
		1
    );
}

int prints_a_low_hex(void)
{
    return (
        test_ft_printf("62", "%x", (void *)-45, "-45", "ffffffd3", 8) &&
        test_ft_printf("63", "%x", (void *)INT_MAX, "INT_MAX", "7fffffff", 8) &&
        test_ft_printf("64", "%x", (void *)UINT_MAX, "UINT_MAX", "ffffffff", 8) &&
        test_ft_printf("65", "%x", (void *)UINT_MAX+1, "UINT_MAX+1", "0", 1) &&
        test_ft_printf("66", "%x", (void *)0, "0", "0", 1) &&
		1
    );
}



int prints_a_up_hex(void)
{
    return (
        test_ft_printf("76", "%X", (void *)-45, "-45", "FFFFFFD3", 8) &&
        test_ft_printf("77", "%X", (void *)INT_MAX, "INT_MAX", "7FFFFFFF", 8) &&
        test_ft_printf("78", "%X", (void *)UINT_MAX, "UINT_MAX", "FFFFFFFF", 8) &&
        test_ft_printf("79", "%X", (void *)UINT_MAX+1, "UINT_MAX+1", "0", 1) &&
        test_ft_printf("80", "%X", (void *)0, "0", "0", 1) &&
		1
    );
}

int prints_a_ptr(void)
{   int a = 4; char buf[30]; int size = sprintf(buf, "%p", &a);
    return (
        test_ft_printf("88", "%p", (void *)0, "0", "(nil)", 5) &&
        test_ft_printf("89", "%p", (void *)ULONG_MAX, "ULONG_MAX", "0xffffffffffffffff", 18) &&
        test_ft_printf("90", "%p", (void *)LONG_MIN, "LONG_MIN", "0x8000000000000000", 18) &&
        test_ft_printf("91", "%p", (void *)&a, buf, buf, size) &&
		1
    );
}


int test_ft_printf(char *line_no, const char *format, void *arg, char *arg1, char *exp_sout, int exp)
{
    char *act_sout;
    int act;
    int cond;
    bzero(my_buff, 1024);
    
    act = ft_printf(format, arg);
    act_sout = my_buff;
    cond = strcmp(act_sout, exp_sout) == 0 && act == exp;
    if (cond == 0 || DEBUG)
    {
        TEST(cond, line_no);
		printf("ft_printf(");printf("%s",format); printf(", %s);\n", arg1);
        printf("%s", "[expect] ");printf("standard output:[%s]", exp_sout); printf(" returns [%i]\n", exp);
        printf("%s", "<actual> ");printf("standard output:<%s>", act_sout); printf(" returns <%i>\n", act);
        

    }
    return (cond);
}

void tests_ft_printf()
{
    puts(__func__);
    DESCRIBE("%c Prints a single character", prints_a_single_char);
    DESCRIBE("%s Prints a string (as defined by the common C convention)", prints_a_string);
    DESCRIBE("%p The void * pointer argument has to be printed in hexadecimal format", prints_a_ptr);
    DESCRIBE("%d Prints a decimal (base 10) number", prints_a_decimal_or_an_integer);
    DESCRIBE("%i Prints an integer in base 10", prints_a_decimal_or_an_integer);
    DESCRIBE("%u Prints an unsigned decimal (base 10) number", prints_an_unsigned_decimal);
    DESCRIBE("%x Prints a number in hexadecimal (base 16) lowercase format", prints_a_low_hex);
    DESCRIBE("%X Prints a number in hexadecimal (base 16) uppercase format", prints_a_up_hex);
    DESCRIBE("%% Prints a percent sign", prints_a_percent_sign);
    return;
}