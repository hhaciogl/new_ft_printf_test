#include "../test.h"
#include "../lib/ft_printf.h"

extern char my_buff[1024];

int test_ft_printf(char *line_no, const char *format, void *arg, char *exp_sout, int exp);
int prints_a_single_char(void);

void tests_ft_printf()
{
    puts(__func__);
    DESCRIBE("%c Prints a single character", prints_a_single_char);
    XDESCRIBE("%s Prints a string (as defined by the common C convention)");
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
        test_ft_printf("28", "This is a char: %c", (void *)'z', "This is a char: z", 17) &&
        test_ft_printf("29", "This is a char: %c", (void *)'%', "This is a char: %", 17) &&
        test_ft_printf("30", "This is \0a char: %c", (void *)'%', "This is ", 8) &&
        test_ft_printf("31", "[%c]", (void *)'\0', "[]", 3) &&
        test_ft_printf("32", "[%c]", (void *)'\n', "[\n]", 3) &&
        1
    );
}


int test_ft_printf(char *line_no, const char *format, void *arg, char *exp_sout, int exp)
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
        printf("%s\n", "[expect]"); 
        printf("%s\n", "<actual>");
        printf("[%s]\n", exp_sout);
        printf("<%s>\n", act_sout);
        printf("[%i]\n", exp);
        printf("<%i>\n", act);
    }
    return (cond);
}