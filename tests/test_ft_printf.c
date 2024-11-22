#include "../test.h"
#include "../lib/ft_printf.h"

extern char my_buff[1024];

int test_ft_printf(char *line_no, const char *format, void *arg, void *arg1, char *exp_sout, int exp);
int prints_a_single_char(void);
int prints_a_string(void);

void tests_ft_printf()
{
    puts(__func__);
    DESCRIBE("%c Prints a single character", prints_a_single_char);
    DESCRIBE("%s Prints a string (as defined by the common C convention)", prints_a_string);
    XDESCRIBE("%p The void * pointer argument has to be printed in hexadecimal format");
    XDESCRIBE("%d Prints a decimal (base 10) number");
    XDESCRIBE("%i Prints an integer in base 10");
    XDESCRIBE("%u Prints an unsigned decimal (base 10) number");
    XDESCRIBE("%x Prints a number in hexadecimal (base 16) lowercase format");
    XDESCRIBE("%X Prints a number in hexadecimal (base 16) uppercase format");
    XDESCRIBE("%% Prints a percent sign");
    return;
}

int prints_a_single_char(void)
{
    return (
        test_ft_printf("28", "This is a char: %c", (void *)'z', NULL, "This is a char: z", 17) &&
        test_ft_printf("29", "This is a char: %c", (void *)'%', NULL, "This is a char: %", 17) &&
        test_ft_printf("30", "This is \0a char: %c", (void *)'%', NULL, "This is ", 8) &&
        test_ft_printf("31", "[%c]", (void *)'\0', NULL, "[]", 3) &&
        test_ft_printf("32", "[%c]", (void *)'\n', NULL, "[\n]", 3)
    );
}
int prints_a_string(void)
{
    return (
        test_ft_printf("38", "This is a string: %s", (void *)"str", NULL, "This is a string: str", 21) &&
        test_ft_printf("39", "This is a string: %s", (void *)"st\0r", NULL, "This is a string: st", 20) &&
        test_ft_printf("40", "This is an empty string:%s", (void *)"", NULL, "This is an empty string:", 24) &&
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