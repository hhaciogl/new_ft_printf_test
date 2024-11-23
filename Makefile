SOURCE= main.c ./tests/test_ft_printf.c ./tests/my_write.c
LIB_SOURCE = lib/libftprintf.a lib/ft_printf.c lib/ft_printf.h

all: run

run: $(SOURCE) $(LIB_SOURCE) test.h
	gcc $(SOURCE) lib/libftprintf.a -o $@ -Werror -Wextra -Wall -Wl,--wrap=write

lib/libftprintf.a: lib/ft_printf.c lib/ft_printf.h
	cd ./lib && $(MAKE)

clean:
	cd ./lib && $(MAKE) clean;
	rm -f ./tests/*.o

fclean: clean
	cd ./lib && $(MAKE) fclean;
	rm -f run 

test:
	./run

.PHONY: fclean clean copy all test