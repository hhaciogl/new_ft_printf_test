SOURCE=$(wildcard ./tests/*.c)
LIB_SOURCE = lib/libftprintf.a lib/ft_printf.c lib/ft_printf.h

all: fclean run

run: $(SOURCE) $(LIB_SOURCE)
	@gcc main.c $(SOURCE) lib/libftprintf.a -o $@ -Werror -Wextra -Wall -Wl,--wrap=write
	./run
copy:
	rm -fr ./lib
	cp -r ../$(LIB) .
	mv ./$(LIB) ./lib

lib/libftprintf.a:
	cd ./lib && $(MAKE)

clean:
	cd ./lib && $(MAKE) clean;
	rm -f ./tests/*.o

fclean: clean
	cd ./lib && $(MAKE) fclean;
	rm -f run 

norm:
	cd ./lib && $(MAKE) norm;

push:
	git add .
	git commit -m "$(M)"
	git push origin master
	cd ./lib && $(MAKE) push

.PHONY: push fclean clean copy all test norm