# 1.$@ - берет из цели
# 2.$^ - $^ берет из зависимости
COMPILATION = gcc -Wall -Werror
OBJECTS = ./built/src/main.o ./built/src/board_read.o ./built/src/game.o ./built/src/board_print_plain.o

bin/chessviz: $(OBJECTS)
	$(COMPILATION) -o $@ $(OBJECTS)

./built/src/main.o: ./src/main.c
	$(COMPILATION) -o $@ -c $^

./built/src/board_read.o: ./src/board_read.c
	$(COMPILATION) -o $@ -c $^

./built/src/game.o: ./src/game.c
	$(COMPILATION) -o $@ -c $^

./built/src/board_print_plain.o: ./src/board_print_plain.c
	$(COMPILATION) -o $@ -c $^

run:
	./bin/chessviz

clean:
	rm ./built/src/*.o
	rm ./bin/*

