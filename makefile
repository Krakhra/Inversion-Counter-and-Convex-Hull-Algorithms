BIN = ./bin/
SRC =./src/

all:
	gcc -Wall -g -std=c99 ./src/P11.c ./src/P12.c ./src/P21.c ./src/P22.c ./src/main.c   -Iinclude -o./bin/run
clean:
	rm -f *.o
	rm -f run
	rm ./bin/run

