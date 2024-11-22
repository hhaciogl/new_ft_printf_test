#include "../test.h"
#include "../lib/ft_printf.h"

extern char my_buff[1024];

int test_ft_printf(int line_no, const char *format, void *arg, void *exp_sout, void *exp);
int prints_a_single_char(void);

void tests_ft_printf()
{
    puts(__func__);
    XDESCRIBE("%c Prints a single character");
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

int test_ft_printf(int line_no, const char *format, void *arg, void *exp_sout, void *exp)
{
    char *act_sout;
    int act;
    int cond;

    
    
    puts("[expected] <-> [actual]");
    printf("[%s] <-> [%s]\n", exp_sout, act_sout);
    printf("[%i] <-> [%i]\n", exp, act);
    puts("");
    



    return (1);
}