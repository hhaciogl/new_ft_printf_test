SOURCE=$(wildcard ./tests/*.c)

all: run

run: $(SOURCE) lib/libftprintf.a
	@cc main.c $^ -o $@ -Werror -Wextra -Wall
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

push:
	git add .
	git commit -m "$(M)"
	git push origin master
	cd ./lib && $(MAKE) push

.PHONY: push fclean clean copy alls