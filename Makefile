all:
	gcc -Wall -std=c99 -pedantic src/a2.c src/functions.c -Iinclude -o bin/runMe -lncurses

