main: ./built/main.o ./built/game.o ./built/board_print_plain.o
	gcc -o ./bin/main ./built/main.o ./built/game.o ./built/board_print_plain.o

./built/main.o: ./src/main.c
	gcc -o ./built/main.o -c ./src/main.c 

./built/game.o: ./src/game.c
	gcc -o ./built/game.o -c ./src/game.c

./built/board_print_plain.o: ./src/board_print_plain.c
	gcc -o ./built/board_print_plain.o -c ./src/board_print_plain.c

run:
	./bin/main

clean:
	rm ./bin/main
	rm ./built/*

