main: ./built/main.o ./built/board_read.o ./built/game.o ./built/board_print_plain.o
	gcc -Werror -Wall -o ./bin/main ./built/main.o ./built/board_read.o ./built/game.o ./built/board_print_plain.o

./built/main.o: ./src/main.c
	gcc -Werror -Wall -o ./built/main.o -c ./src/main.c 

./built/board_read.o: ./src/board_read.c
	gcc -Werror -Wall -o ./built/board_read.o -c ./src/board_read.c 

./built/game.o: ./src/game.c
	gcc -Werror -Wall -o ./built/game.o -c ./src/game.c

./built/board_print_plain.o: ./src/board_print_plain.c
	gcc -Werror -Wall -o ./built/board_print_plain.o -c ./src/board_print_plain.c

run:
	./bin/main

clean:
	rm ./built/*
	rm ./bin/*

