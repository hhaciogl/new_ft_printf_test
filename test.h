#ifndef TEST_H
# define TEST_H
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"
#define TEST(condition, msg) \
    do { \
        if (condition) \
            printf(GREEN "** [OK] %s\n" RESET, msg); \
        else \
            printf(RED "xx FAIL %s: \n" RESET, msg); \
    } while (0)
#define log_int(var) printf(#var " = %d\n", var)
#define log_char(var) printf(#var " = %c\n", var)
#define log_float(var) printf(#var " = %f\n", var)
#define log_string(var) printf(#var " = %s\n", var)
#define log_pointer(var) printf(#var " = %p\n", var)
#define log_size_t(var) printf(#var " = %zu\n", var)
#define log_uint(var) printf(#var " = %u\n", var)

void test_libftprintf(void);

#endif
