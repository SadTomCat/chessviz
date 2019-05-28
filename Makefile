# 1.$@ - берет из цели
# 2.$^ - $^ берет из зависимости
CC = gcc
CFLAGS = -Wall -Werror
CFLAGS_TEST = -I thirdparty -Wall -Werror
OBJECTS = ./built/src/main.o ./built/src/board_read.o ./built/src/game.o ./built/src/board_print_plain.o
OBJECTS-TEST = ./built/test/main.o ./built/test/board_read_test.o ./built/src/board_read.o ./built/src/game.o ./built/src/board_print_plain.o
EXETEST = ./bin/chessviz-test

all: bin/chessviz $(EXETEST)

bin/chessviz: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

./built/src/main.o: ./src/main.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/src/board_read.o: ./src/board_read.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/src/game.o: ./src/game.c
	$(CC) $(CFLAGS) -o $@ -c $^

./built/src/board_print_plain.o: ./src/board_print_plain.c
	$(CC) $(CFLAGS) -o $@ -c $^

$(EXETEST): $(OBJECTS-TEST)
	$(CC) $(CFLAGS) -o $@ $^

./built/test/main.o: ./test/main.c
	$(CC) $(CFLAGS_TEST) -o $@ -c $^

./built/test/board_read_test.o: ./test/board_read_test.c
	$(CC) $(CFLAGS_TEST) -o $@ -c $^

run:
	./bin/chessviz

run_test:
	$(EXETEST)

clean:
	rm ./built/src/*.o
	rm ./built/test/*.o
	rm ./bin/*

