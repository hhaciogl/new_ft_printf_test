SOURCE=$(wildcard ./tests/*.c)

run: $(SOURCE) lib/libftprintf.a
	@cc $^ -o $@ -L./test -lft -Werror -Wextra -Wall
	./run

copy:
	rm -fr ./lib
	cp -r ../$(LIB) .
	mv ./$(LIB) ./lib

lib/libftprintf.a:
	cd ./lib && $(MAKE)

clean:
	cd ./lib && $(MAKE) clean;

fclean:
	cd ./lib && $(MAKE) fclean;

norm:
	norminette ./test/*.c
	cd ./lib && $(MAKE) norm

push:
	git add .
	git commit -m "$(M)"
	git push origin master
	cd ./lib && $(MAKE) push