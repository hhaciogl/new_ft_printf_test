// simple code for repeated commands
// while sleep 2; do clear; make&&make test; done


#ifndef TEST_H
# define TEST_H
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"
#define DEBUG 0
#define TEST(condition, msg) \
    do { \
        if (condition) \
            printf(GREEN "** [OK] line =>%s from %s\n" RESET, msg,  __FILE__); \
        else \
            printf(RED "xx FAIL line =>%s from %s\n" RESET, msg, __FILE__); \
    } while (0)
#define log_int(var) printf(#var " = %d\n", var)
#define log_char(var) printf(#var " = %c\n", var)
#define log_float(var) printf(#var " = %f\n", var)
#define log_string(var) printf(#var " = %s\n", var)
#define log_pointer(var) printf(#var " = %p\n", var)
#define log_size_t(var) printf(#var " = %zu\n", var)
#define log_uint(var) printf(#var " = %u\n", var)
#define DESCRIBE(message, func) ({ \
    int result = func(); \
    if (result == 0) { \
        printf("\033[38;5;196m%s\033[0m\n", message);\
    } else { \
        printf("\033[38;5;46m%s\033[0m\n", message);\
    } \
})
#define XDESCRIBE(message, func) do { \
    (void)func; \
    printf("\033[38;5;214m%s\033[0m\n", message); \
} while(0)

void tests_ft_printf(void);

#endif
